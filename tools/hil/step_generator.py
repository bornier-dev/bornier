#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Run the step_generator on-target test and check its outputs with a Saleae logic analyzer.

Flash firmware/tests/step_generator first. The script starts a capture in Logic 2 (automation
API enabled), sends a `run` command to the board, waits for the end of the motion, stops the
capture and checks, for each axis:

- count: pulses seen = pulses reported by the board = pulses of the replayed motion, and net
  position (pulses signed by DIR) = final target;
- timing: high time >= steplen, low time between pulses >= stepspace, DIR stable dirsetup
  before a pulse and dirhold after one;
- SYNC0 boundary: no pulse shorter than steplen (a slot cut by the reset), none on the edge;
- jitter: within a cycle, the spread of the steps around an evenly spaced grid, in slots.

Logic analyzer channels: 0 STEP0, 1 DIR0, 2 STEP1, 3 DIR1, 4 STEP2, 5 DIR2, 6 STEP3, 7 DIR3,
8 SYNC0, threshold 3.3 V. Wiring on the NUCLEO-H563ZI is in firmware/tests/step_generator.

Needs Python 3, pyserial, numpy and logic2-automation.
Exit status: 0 when every check passes, 1 otherwise.
"""

import argparse
import struct
import sys
import tempfile
import time
from pathlib import Path

import numpy as np
import serial
from saleae import automation

AXES = 4
STEP_CHANNELS = [0, 2, 4, 6]
DIR_CHANNELS = [1, 3, 5, 7]
SYNC_CHANNEL = 8
TICK = 4e-9  # timer kernel tick

# ── Motion replay (same integer arithmetic as firmware/tests/step_generator/motion.hpp) ────

MIXED = [
    [(100, 1_000_000), (300, 1_000_000), (100, 0), (50, 0), (100, -1_000_000), (300, -1_000_000), (100, 0), (50, 0)],
    [(250, 500_000), (500, 500_000), (250, 0), (1, 0), (250, -700_000), (250, 0), (100, 0)],
    [(1, 200_000), (20, 200_000), (1, -200_000), (20, -200_000), (1, 0), (10, 0)],
    [(500, 400), (1000, 400), (500, 0), (200, 0), (300, -1500), (300, -1500), (300, 0), (100, 0)],
]
FULL = [
    [(1, 1_000_000), (1000, 1_000_000)],
    [(1, -1_000_000), (1000, -1_000_000)],
    [(1, 1_000_000), (1000, 1_000_000)],
    [(1, -1_000_000), (1000, -1_000_000)],
]


def tdiv(a: int, b: int) -> int:
    """Integer division truncating toward zero, as in C++."""
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b >= 0) else -q


def replay(segments, max_steps: int, finish_cycles: int):
    """Targets of one axis, cycle by cycle, until it is done."""
    vmax = max_steps << 16
    position = velocity = start_velocity = 0
    index = elapsed = 0
    cycle = 0
    targets = []
    while True:
        if cycle >= finish_cycles and index == 0 and elapsed == 0:
            return targets
        cycles, permille = segments[index]
        end_velocity = tdiv(vmax * permille, 1_000_000)
        elapsed += 1
        velocity = start_velocity + tdiv((end_velocity - start_velocity) * elapsed, cycles)
        position += velocity
        if elapsed == cycles:
            start_velocity = end_velocity
            elapsed = 0
            index = (index + 1) % len(segments)
        targets.append(position >> 16)
        cycle += 1


# ── Board ──────────────────────────────────────────────────────────────────────────────

def parse_fields(line: str) -> dict:
    out = {}
    for token in line.split()[1:]:
        if "=" in token:
            k, v = token.split("=", 1)
            out[k] = v
    return out


def command(port, text: str, timeout: float = 2.0) -> list:
    port.reset_input_buffer()
    port.write((text + "\n").encode())
    lines = []
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        line = port.readline().decode("ascii", errors="replace").rstrip()
        if not line:
            continue
        lines.append(line)
        if line in ("started", "end", "stopped") or line.startswith(("error", "busy")):
            break
    return lines


# ── Capture ────────────────────────────────────────────────────────────────────────────

def read_digital(path: Path):
    """Saleae binary export of one digital channel: initial state and transition times.

    The times are memory-mapped: a long capture does not have to fit in memory.
    """
    header = struct.calcsize("<8siiIddQ")
    with path.open("rb") as f:
        ident, version, kind, initial, begin, end, count = struct.unpack("<8siiIddQ", f.read(header))
    if ident != b"<SALEAE>" or kind != 0:
        raise ValueError(f"{path.name}: not a Saleae digital export")
    times = np.memmap(path, dtype="<f8", mode="r", offset=header, shape=(count,)) if count else np.zeros(0)
    return int(initial), times


def count_pulses(step_initial: int, step_times, dir_initial: int, dir_times, chunk: int = 1 << 24):
    """Pulses (rising edges) of a STEP channel, and their sum signed by DIR, chunk by chunk."""
    first_rising = 0 if step_initial == 0 else 1
    dir_times = np.asarray(dir_times)
    pulses = 0
    net = 0
    for start in range(first_rising, len(step_times), 2 * chunk):
        rise = np.asarray(step_times[start:start + 2 * chunk:2])
        forward = level_at(dir_initial, dir_times, rise) == 1
        pulses += len(rise)
        net += int(forward.sum()) - int((~forward).sum())
    return pulses, net


def edges(initial: int, times):
    """Rising and falling edge times."""
    first_rising = 0 if initial == 0 else 1
    return times[first_rising::2], times[1 - first_rising::2]


def level_at(initial: int, times, t):
    """Level of a channel just before each time in t."""
    n = np.searchsorted(times, t, side="left")
    return (initial + n) % 2


# ── Checks ─────────────────────────────────────────────────────────────────────────────

class Checker:
    def __init__(self):
        self.failures = []

    def check(self, ok: bool, text: str):
        print(("ok    " if ok else "FAIL  ") + text)
        if not ok:
            self.failures.append(text)


def analyze_counts(capture_dir: Path, config: dict, derived: dict, axes_report: list, run_args, c: Checker):
    """Counts and positions only, for long captures."""
    finish = int(int(run_args.seconds) * 1e9 // int(config["cycle"]))
    segments = MIXED if config["profile"] == "mixed" else FULL
    max_steps = int(derived["max_steps"])
    for a in range(AXES):
        rep = axes_report[a]
        i_step, t_step = read_digital(capture_dir / f"digital_{STEP_CHANNELS[a]}.bin")
        i_dir, t_dir = read_digital(capture_dir / f"digital_{DIR_CHANNELS[a]}.bin")
        pulses, net = count_pulses(i_step, t_step, i_dir, t_dir)
        targets = replay(segments[a], max_steps, finish)
        expected_pulses = int(np.abs(np.diff(np.concatenate(([0], targets)))).sum())
        final = targets[-1] if targets else 0
        c.check(pulses == int(rep["pulses"]) == expected_pulses,
                f"axis {a} pulses: seen {pulses}, board {rep['pulses']}, motion {expected_pulses}")
        c.check(net == int(rep["position"]) == final == int(rep["target"]),
                f"axis {a} position: seen {net}, board {rep['position']}, target {rep['target']}, motion {final}")


def analyze(capture_dir: Path, config: dict, derived: dict, axes_report: list, run_args, c: Checker,
            correction: int = 0):
    sample_rate = run_args.sample_rate
    resolution = 1.0 / sample_rate
    tol = 2 * resolution

    s_init, s_times = read_digital(capture_dir / f"digital_{SYNC_CHANNEL}.bin")
    sync, sync_fall = edges(s_init, s_times)
    # The simulated SYNC0 pulse lasts 1 us: shorter ones are crosstalk on the probe wire
    n = min(len(sync), len(sync_fall[sync_fall > sync[0]])) if len(sync) else 0
    width = sync_fall[sync_fall > sync[0]][:n] - sync[:n]
    glitches = int((width < 0.5e-6).sum())
    sync = sync[:n][width >= 0.5e-6]
    c.check(len(sync) > 10, f"SYNC0: {len(sync)} rising edges, {glitches} glitches under 500 ns ignored")
    if len(sync) < 2:
        return
    periods = np.diff(sync)
    expected_period = ((int(config["cycle"]) + int(config["detune"])) // 16) * 16e-9
    # The board runs on its own oscillator: express its times on the analyzer's time base
    scale = periods.mean() / expected_period
    print(f"      SYNC0 period {periods.mean() * 1e6:.4f} us (expected {expected_period * 1e6:.4f} on the board's clock, "
          f"which runs {(1 / scale - 1) * 1e6:+.0f} ppm), min {periods.min() * 1e6:.4f} max {periods.max() * 1e6:.4f}")
    slot = scale / int(config["rate"])
    steplen = int(config["steplen"]) * 1e-9 * scale
    stepspace = int(config["stepspace"]) * 1e-9 * scale
    dirsetup = int(config["dirsetup"]) * 1e-9 * scale
    dirhold = int(config["dirhold"]) * 1e-9 * scale
    cycle_slots = int(derived["cycle_slots"])
    guard = int(derived["guard_slots"])
    pulse_slots = int(derived["pulse_slots"])
    # Bresenham keeps each step within one slot of its ideal place; the phase lock may move the
    # grid by |correction| ticks within a cycle; plus the analyzer's sampling.
    slot_ticks = int(derived["slot_ticks"])
    jitter_limit = 1.0 + abs(correction) / slot_ticks + 2 * resolution / slot

    finish = int(int(run_args.seconds) * 1e9 // int(config["cycle"]))
    segments = MIXED if config["profile"] == "mixed" else FULL
    max_steps = int(derived["max_steps"])

    for a in range(AXES):
        rep = axes_report[a]
        i_step, t_step = read_digital(capture_dir / f"digital_{STEP_CHANNELS[a]}.bin")
        i_dir, t_dir = read_digital(capture_dir / f"digital_{DIR_CHANNELS[a]}.bin")
        rise, fall = edges(i_step, t_step)
        # Pulses: rising edge followed by its falling edge
        if len(fall) and len(rise) and fall[0] < rise[0]:
            fall = fall[1:]
        n = min(len(rise), len(fall))
        rise, fall = rise[:n], fall[:n]

        targets = replay(segments[a], max_steps, finish)
        expected_pulses = int(np.abs(np.diff(np.concatenate(([0], targets)))).sum())
        final = targets[-1] if targets else 0
        forward = level_at(i_dir, t_dir, rise) == 1
        net = int(forward.sum()) - int((~forward).sum())

        c.check(n == int(rep["pulses"]) == expected_pulses,
                f"axis {a} pulses: seen {n}, board {rep['pulses']}, motion {expected_pulses}")
        c.check(net == int(rep["position"]) == final == int(rep["target"]),
                f"axis {a} position: seen {net}, board {rep['position']}, target {rep['target']}, motion {final}")
        if n == 0:
            continue

        high = fall - rise
        low = rise[1:] - fall[:-1]
        c.check(high.min() >= steplen - tol,
                f"axis {a} steplen: min {high.min() * 1e9:.0f} ns, max {high.max() * 1e9:.0f} ns (>= {steplen * 1e9:.0f})")
        if len(low):
            c.check(low.min() >= stepspace - tol,
                    f"axis {a} stepspace: min {low.min() * 1e9:.0f} ns (>= {stepspace * 1e9:.0f})")

        # DIR changes after the first SYNC0 (the run sets DIR before it)
        dir_changes = t_dir[t_dir > sync[0]]
        if len(dir_changes):
            k = np.searchsorted(rise, dir_changes)
            after = rise[k[k < n]] - dir_changes[k < n]
            before_idx = k - 1
            before = dir_changes[before_idx >= 0] - fall[before_idx[before_idx >= 0]]
            c.check((len(after) == 0 or after.min() >= dirsetup - tol) and (len(before) == 0 or before.min() >= dirhold - tol),
                    f"axis {a} DIR: {len(dir_changes)} changes, setup min "
                    f"{(after.min() * 1e9 if len(after) else float('nan')):.0f} ns, hold min "
                    f"{(before.min() * 1e9 if len(before) else float('nan')):.0f} ns")

        # Position of each pulse in the slot grid of its cycle
        k = np.searchsorted(sync, rise, side="right") - 1
        inside = k >= 0
        offset = rise[inside] - sync[k[inside]]
        slots = offset / slot
        phase = slots - np.floor(slots)
        print(f"      axis {a} pulse start in slot (fraction): min {phase.min():.3f} max {phase.max():.3f}; "
              f"latest start {offset.max() * 1e6:.3f} us after SYNC0")

        # Jitter: within a cycle the steps follow the line acc + (i + 1) * N = j * usable; the
        # spread of (slot - j * usable / N) is the distance to the ideal evenly spaced position.
        reversal_cycles = set(np.searchsorted(sync, dir_changes, side="right") - 1) if len(dir_changes) else set()
        worst = 0.0
        worst_cycle = (0, 0)
        over = 0
        ks = k[inside]
        cuts = np.flatnonzero(np.diff(ks)) + 1
        for group in np.split(np.arange(len(ks)), cuts):
            m = len(group)
            cycle_index = int(ks[group[0]])
            # The first cycles bring the cycle boundary onto SYNC0 (phase lock)
            if m < 2 or cycle_index < 50:
                continue
            lead = guard if cycle_index in reversal_cycles else 0
            usable = cycle_slots - lead - (pulse_slots - 1)
            dev = slots[group] - np.arange(m) * (usable / m)
            spread = dev.max() - dev.min()
            if spread > worst:
                worst, worst_cycle = spread, (cycle_index, m)
            if spread > jitter_limit:
                over += 1
        c.check(over == 0, f"axis {a} jitter: worst spread {worst:.2f} slot (cycle {worst_cycle[0]}, "
                           f"{worst_cycle[1]} steps), {over} cycles above {jitter_limit:.2f}")


def main() -> int:
    parser = argparse.ArgumentParser(description="Run and check the step_generator on-target test.")
    parser.add_argument("--port", required=True, help="serial port of the ST-LINK VCP (e.g. /dev/ttyACM0, COM5)")
    parser.add_argument("--logic-port", type=int, default=10430, help="Logic 2 automation port")
    parser.add_argument("--keep", help="directory where to keep the capture (.sal and channel exports)")
    parser.add_argument("--sample-rate", type=int, default=125_000_000,
                        help="logic analyzer sample rate; 9 channels at 250 MS/s may overrun the host")
    for key, default in (("rate", 1_000_000), ("cycle", 1_000_000), ("steplen", 500), ("stepspace", 500),
                         ("dirsetup", 1000), ("dirhold", 1000), ("detune", 0), ("seconds", 10)):
        parser.add_argument(f"--{key}", type=int, default=default)
    parser.add_argument("--profile", choices=["mixed", "full"], default="mixed")
    parser.add_argument("--load", choices=["none", "gpdma2", "gpdma1"], default="none",
                        help="competing memory-to-memory DMA during the run (stands for the slave controller interface)")
    parser.add_argument("--counts-only", action="store_true",
                        help="check step counts and positions only, reading the capture in chunks (long runs)")
    args = parser.parse_args()

    run = (f"run rate={args.rate} cycle={args.cycle} steplen={args.steplen} stepspace={args.stepspace} "
           f"dirsetup={args.dirsetup} dirhold={args.dirhold} "
           f"detune={args.detune} profile={args.profile} seconds={args.seconds} load={args.load}")
    c = Checker()
    with serial.Serial(args.port, 115200, timeout=0.5) as port, \
            automation.Manager.connect(port=args.logic_port) as manager:
        command(port, "stop")
        device = automation.LogicDeviceConfiguration(
            enabled_digital_channels=STEP_CHANNELS + DIR_CHANNELS + [SYNC_CHANNEL],
            digital_sample_rate=args.sample_rate, digital_threshold_volts=3.3)
        capture = manager.start_capture(
            device_configuration=device,
            capture_configuration=automation.CaptureConfiguration(capture_mode=automation.ManualCaptureMode()))
        try:
            time.sleep(0.5)
            lines = command(port, run)
            for line in lines:
                print(line)
            if not lines or lines[-1] != "started":
                print("FAIL  the board did not start the run", file=sys.stderr)
                return 1
            deadline = time.monotonic() + args.seconds * 3 + 30
            report = []
            while time.monotonic() < deadline:
                time.sleep(1.0)
                report = command(port, "report", timeout=5.0)
                if report and not report[-1].startswith("busy"):
                    break
            time.sleep(0.2)
        finally:
            capture.stop()

        for line in report:
            print(line)
        if not report or report[-1] != "end":
            print("FAIL  no complete report from the board", file=sys.stderr)
            capture.close()
            return 1

        config = next(parse_fields(l) for l in report if l.startswith("config "))
        derived = next(parse_fields(l) for l in report if l.startswith("derived "))
        axes_report = [parse_fields(l) for l in report if l.startswith("axis ")]
        c.check(any(l == "verdict PASS" for l in report), "board verdict")

        with tempfile.TemporaryDirectory() as tmp:
            out = Path(args.keep) if args.keep else Path(tmp)
            out.mkdir(parents=True, exist_ok=True)
            capture.export_raw_data_binary(str(out), digital_channels=STEP_CHANNELS + DIR_CHANNELS + [SYNC_CHANNEL])
            if args.keep:
                capture.save_capture(str(out / "capture.sal"))
            capture.close()
            sync_line = next(parse_fields(l) for l in report if l.startswith("sync "))
            corrections = [int(v) for v in sync_line["correction"].split(",")]
            if args.counts_only:
                analyze_counts(out, config, derived, axes_report, args, c)
            else:
                analyze(out, config, derived, axes_report, args, c, max(abs(v) for v in corrections))

    if c.failures:
        print(f"{len(c.failures)} check(s) failed", file=sys.stderr)
        return 1
    print("all checks passed")
    return 0


if __name__ == "__main__":
    sys.exit(main())
