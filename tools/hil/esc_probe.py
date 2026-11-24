#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `esc_probe` test on the Bornier base board.

Records the trace of the board and checks its report: the identification registers of the
LAN9253 and a write and read back in its EtherCAT core, through the OCTOSPI, in single then in
quad bus mode. Run it against both the debug and the release image.

The board must already be flashed with the image of --preset (or --elf) and running.

    python tools/hil/esc_probe.py --preset release
"""

import argparse
import sys

import kymo_trace


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    kymo_trace.add_arguments(parser, seconds=5.0)
    args = parser.parse_args()

    recording = kymo_trace.record(args, kymo_trace.image(args, "tests/esc_probe/esc_probe"))
    if not kymo_trace.report(recording):
        return 1
    registers = recording.named("registers")
    byte_tests = {event.number("byte_test") for event in registers}
    id_revs = {event.number("id_rev") for event in registers}
    results = recording.named("mode_result")
    modes = {mode: (sum(1 for event in results if event.fields["mode"] == mode and event.flag("pass")),
                    sum(1 for event in results if event.fields["mode"] == mode and not event.flag("pass")))
             for mode in ("spi", "sqi")}
    verdicts = recording.named("verdict")
    passed = sum(1 for event in verdicts if event.flag("pass"))
    failures = {event.fields["bus_failure"] for event in verdicts} - {"none"}
    timings = recording.named("timing")

    def show(found: set[int]) -> str:
        return ", ".join(f"0x{value:08x}" for value in sorted(found)) or "nothing"

    byte_test_ok = byte_tests == {0x87654321}
    id_ok = bool(id_revs) and all(value >> 16 == 0x9253 for value in id_revs)
    modes_ok = all(good >= 2 and bad == 0 for good, bad in modes.values())
    verdict_ok = len(verdicts) >= 2 and passed == len(verdicts) and not failures
    reset_ok = not recording.named("reset_failed")

    print(f"{'PASS' if byte_test_ok else 'FAIL'}  BYTE_TEST reads {show(byte_tests)}, 0x87654321 expected")
    print(f"{'PASS' if id_ok else 'FAIL'}  ID_REV reads {show(id_revs)}, 0x9253 expected in the upper half")
    for mode, (good, bad) in modes.items():
        print(f"{'PASS' if good >= 2 and bad == 0 else 'FAIL'}  {mode.upper()} mode: {good} passed, {bad} failed")
    print(f"{'PASS' if verdict_ok else 'FAIL'}  {len(verdicts)} verdicts, {passed} passed, bus failures: "
          f"{sorted(failures) or 'none'}")
    print(f"{'PASS' if reset_ok else 'FAIL'}  the LAN9253 came out of its reset")
    if timings:
        last = timings[-1]
        print(f"info  register read {last.number('read_cycles')} cycles, "
              f"core read {last.number('core_read_cycles')} cycles")

    if byte_test_ok and id_ok and modes_ok and verdict_ok and reset_ok:
        return 0
    if not registers:
        print("hint: no register traced; the image reports only once its first read has ended: "
              "check that esc_probe is flashed and running, then the OCTOSPI clock and pins",
              file=sys.stderr)
    elif modes["spi"][1] == 0 and modes["sqi"][1] > 0:
        print("hint: SPI (single) mode works and SQI (quad) mode fails; check SIO2 and SIO3", file=sys.stderr)
    elif byte_tests <= {0x00000000, 0xFFFFFFFF}:
        print("hint: the LAN9253 does not answer; check its supply, its 25 MHz clock and that its "
              "reset line is high", file=sys.stderr)
    else:
        print("hint: wrong values; check the SPI mode, the byte order and the bit rate (READ is "
              "limited to 30 MHz)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
