#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `blink` example on the Bornier base board.

Listens to SWO through a J-Link for a few seconds and checks that the board prints consecutive
numbered lines, one per second. Run it against both the debug and the release image: a failure
that only shows up in release points at undefined behaviour, never at the optimiser.

The board must already be flashed and running. The script needs the SEGGER J-Link software:
it runs J-Link SWO Viewer, found on the PATH or given with --viewer.

    python tools/hil/blink_swo.py
"""

import argparse
import re
import shutil
import subprocess
import sys
import tempfile
import time
from pathlib import Path

VIEWER_NAMES = ("JLinkSWOViewerCLExe", "JLinkSWOViewerCL")  # Linux and macOS, then Windows
LINE = re.compile(r"^Bornier base blink (\d+)$")


def find_viewer(given: str | None) -> str | None:
    if given:
        return given
    for name in VIEWER_NAMES:
        path = shutil.which(name)
        if path:
            return path
    return None


def listen(viewer: str, device: str, cpu_hz: int, swo_hz: int, seconds: float) -> list[tuple[float, str]]:
    """Runs the viewer for `seconds` and returns the lines it wrote, each with its arrival time."""
    with tempfile.TemporaryDirectory() as folder:
        output = Path(folder) / "swo.txt"
        command = [viewer, "-device", device, "-cpufreq", str(cpu_hz), "-swofreq", str(swo_hz),
                   "-itmport", "0", "-outputfile", str(output)]
        viewer_process = subprocess.Popen(command, stdin=subprocess.DEVNULL, stdout=subprocess.DEVNULL,
                                          stderr=subprocess.DEVNULL)
        lines: list[tuple[float, str]] = []
        seen = 0
        try:
            deadline = time.monotonic() + seconds
            while time.monotonic() < deadline:
                time.sleep(0.05)
                if viewer_process.poll() is not None:
                    break
                if not output.exists():
                    continue
                text = output.read_text(errors="replace")
                complete = text[:text.rfind("\n") + 1]
                now = time.monotonic()
                for line in complete[seen:].splitlines():
                    if line.strip():
                        lines.append((now, line.strip()))
                seen = len(complete)
        finally:
            viewer_process.kill()
            viewer_process.wait()
        return lines


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--viewer", help="path of J-Link SWO Viewer (command line version)")
    parser.add_argument("--device", default="STM32H523VE")
    parser.add_argument("--cpu-hz", type=int, default=250_000_000, help="core clock of the image")
    parser.add_argument("--swo-hz", type=int, default=2_000_000, help="bit rate asked on the SWO pin")
    parser.add_argument("--seconds", type=float, default=8.0, help="listening time")
    args = parser.parse_args()

    viewer = find_viewer(args.viewer)
    if viewer is None:
        print("J-Link SWO Viewer not found: install the SEGGER J-Link software, or give --viewer", file=sys.stderr)
        return 1

    lines = listen(viewer, args.device, args.cpu_hz, args.swo_hz, args.seconds)
    counts = [(when, int(match.group(1))) for when, text in lines if (match := LINE.match(text))]
    foreign = [text for _, text in lines if not LINE.match(text)]

    expected = int(args.seconds) - 3  # the viewer takes up to two seconds to connect
    enough = len(counts) >= expected
    consecutive = all(b[1] == a[1] + 1 for a, b in zip(counts, counts[1:]))
    periods = [b[0] - a[0] for a, b in zip(counts, counts[1:])]
    mean = sum(periods) / len(periods) if periods else 0.0
    steady = bool(periods) and abs(mean - 1.0) < 0.05

    print(f"{'PASS' if enough else 'FAIL'}  {len(counts)} lines received, at least {expected} expected")
    print(f"{'PASS' if consecutive else 'FAIL'}  line numbers consecutive: {[n for _, n in counts]}")
    print(f"{'PASS' if steady else 'FAIL'}  mean period {mean:.3f} s, 1.000 s expected within 5 %")
    print(f"{'PASS' if not foreign else 'FAIL'}  no other text: {foreign[:3]}")

    if enough and consecutive and steady and not foreign:
        return 0
    if not lines:
        print("hint: nothing received; check that the blink image is flashed and running, that the "
              "probe cable carries SWO (pin 6 of the debug connector), and --cpu-hz", file=sys.stderr)
    elif foreign:
        print("hint: garbled text; the bit rate depends on --cpu-hz, which must be the core clock "
              "of the image", file=sys.stderr)
    else:
        print("hint: lines lost or period off; if only one build type fails, look for undefined "
              "behavior (missing volatile, data race, aliasing)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
