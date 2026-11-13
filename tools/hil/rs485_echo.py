#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `rs485_echo` test on the Bornier base board.

Listens to SWO through a J-Link and checks the report of the board: the 256 byte values sent on
the isolated RS-485 port must all come back, with the line idle beforehand and no line error.
Nothing is wired to the MODBUS terminal block. Run it against both the debug and the release
image.

The board must already be flashed and running. The script needs the SEGGER J-Link software:
it runs J-Link SWO Viewer, found on the PATH or given with --viewer.

    python tools/hil/rs485_echo.py
"""

import argparse
import sys

from blink_swo import find_viewer, listen


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--viewer", help="path of J-Link SWO Viewer (command line version)")
    parser.add_argument("--device", default="STM32H523VE")
    parser.add_argument("--cpu-hz", type=int, default=250_000_000, help="core clock of the image")
    parser.add_argument("--swo-hz", type=int, default=2_000_000, help="bit rate asked on the SWO pin")
    parser.add_argument("--seconds", type=float, default=7.0, help="listening time")
    args = parser.parse_args()

    viewer = find_viewer(args.viewer)
    if viewer is None:
        print("J-Link SWO Viewer not found: install the SEGGER J-Link software, or give --viewer", file=sys.stderr)
        return 1

    lines = [text for _, text in listen(viewer, args.device, args.cpu_hz, args.swo_hz, args.seconds)]
    reports = {name: [text.split(" ", 1)[1] for text in lines if text.startswith(name + " ")]
               for name in ("idle", "echoed", "missing", "errors", "verdict")}

    def all_are(name: str, expected: str) -> bool:
        return len(reports[name]) >= 2 and all(value == expected for value in reports[name])

    checks = [
        ("line idle before each run", all_are("idle", "1"), reports["idle"]),
        ("256 bytes echoed", all_are("echoed", "256"), reports["echoed"]),
        ("no byte missing", all_are("missing", "0"), reports["missing"]),
        ("no framing, noise or overrun error", all_are("errors", "000"), reports["errors"]),
        ("verdicts of the board", all_are("verdict", "PASS"), reports["verdict"]),
    ]
    for label, ok, values in checks:
        print(f"{'PASS' if ok else 'FAIL'}  {label}: {values}")

    if all(ok for _, ok, _ in checks):
        return 0
    if not lines:
        print("hint: nothing received; check that the rs485_echo image is flashed and running", file=sys.stderr)
    elif reports["missing"] and all(value == "256" for value in reports["missing"]):
        print("hint: nothing comes back; check the 3.3 V of the transceiver and its isolated supply "
              "(VISO), then DE, TX and RX at the MCU", file=sys.stderr)
    elif reports["idle"] and "0" in reports["idle"]:
        print("hint: the line is not idle; check the bias resistors and that nothing drives the "
              "MODBUS terminal block", file=sys.stderr)
    else:
        print("hint: wrong or lost bytes; if only one build type fails, look for undefined "
              "behavior (missing volatile, data race, aliasing)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
