#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `rs485_echo` test on the Bornier base board.

Records the trace of the board and checks its report: the 256 byte values sent on the isolated
RS-485 port must all come back, with the line idle beforehand and no line error. Nothing is
wired to the MODBUS terminal block. Run it against both the debug and the release image.

The board must already be flashed with the image of --preset (or --elf) and running.

    python tools/hil/rs485_echo.py --preset release
"""

import argparse
import sys

import kymo_trace

NO_ERROR = "{framing=false noise=false overrun=false}"


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    kymo_trace.add_arguments(parser, seconds=5.0)
    args = parser.parse_args()

    recording = kymo_trace.record(args, kymo_trace.image(args, "tests/rs485_echo/rs485_echo"))
    if not kymo_trace.report(recording):
        return 1
    runs = recording.named("run")

    def values(name: str) -> list[str]:
        return [event.fields[name] for event in runs]

    def all_are(name: str, expected: str) -> bool:
        return len(runs) >= 2 and all(value == expected for value in values(name))

    checks = [
        ("line idle before each run", all_are("idle", "true"), values("idle")),
        ("256 bytes echoed", all_are("echoed", "256"), values("echoed")),
        ("no byte missing", all_are("missing", "0"), values("missing")),
        ("no framing, noise or overrun error", all_are("errors", NO_ERROR), sorted(set(values("errors")))),
        ("port never failed", all_are("failed", "false"), values("failed")),
        ("verdicts of the board", all_are("pass", "true"), values("pass")),
    ]
    for label, ok, found in checks:
        print(f"{'PASS' if ok else 'FAIL'}  {label}: {found}")

    if all(ok for _, ok, _ in checks):
        return 0
    if not runs:
        print("hint: no run traced; check that the rs485_echo image is flashed and running", file=sys.stderr)
    elif all(value == "256" for value in values("missing")):
        print("hint: nothing comes back; check the 3.3 V of the transceiver and its isolated supply "
              "(VISO), then DE, TX and RX at the MCU", file=sys.stderr)
    elif "false" in values("idle"):
        print("hint: the line is not idle; check the bias resistors and that nothing drives the "
              "MODBUS terminal block", file=sys.stderr)
    else:
        print("hint: wrong or lost bytes; if only one build type fails, look for undefined "
              "behavior (missing volatile, data race, aliasing)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
