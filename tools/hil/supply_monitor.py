#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `supply_monitor` test on the Bornier base board.

Listens to SWO through a J-Link and checks the supply voltages the board reads with its ADC:
VDDA, the 3.3 V rail, from VREFINT and its factory calibration, and +VIN from VIN_SENSE. The
board must be supplied through its terminal block; give the voltage of that supply with
--vin. Run it against both the debug and the release image.

The board must already be flashed and running. The script needs the SEGGER J-Link software:
it runs J-Link SWO Viewer, found on the PATH or given with --viewer.

    python tools/hil/supply_monitor.py --vin 24
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
    parser.add_argument("--vin", type=float, default=24.0, help="voltage of the supply on the terminal block")
    parser.add_argument("--tolerance", type=float, default=5.0, help="accepted error on +VIN, in percent")
    args = parser.parse_args()

    viewer = find_viewer(args.viewer)
    if viewer is None:
        print("J-Link SWO Viewer not found: install the SEGGER J-Link software, or give --viewer", file=sys.stderr)
        return 1

    lines = [text for _, text in listen(viewer, args.device, args.cpu_hz, args.swo_hz, args.seconds)]
    reports = {name: [text.split(" ", 1)[1] for text in lines if text.startswith(name + " ")]
               for name in ("vrefint_cal", "vdda_mv", "vin_mv", "verdict")}

    def numbers(name: str) -> list[int]:
        return [int(value) for value in reports[name] if value.isdigit()]

    vdda = numbers("vdda_mv")
    vin = numbers("vin_mv")
    cal = numbers("vrefint_cal")
    low, high = args.vin * (1 - args.tolerance / 100) * 1000, args.vin * (1 + args.tolerance / 100) * 1000

    checks = [
        ("VREFINT calibration read, 12 bits", len(cal) >= 2 and all(0 < value < 4096 for value in cal), cal),
        ("VDDA within 3.3 V +-5 %", len(vdda) >= 2 and all(3135 <= value <= 3465 for value in vdda), vdda),
        (f"+VIN within {args.vin:g} V +-{args.tolerance:g} %", len(vin) >= 2 and all(low <= value <= high for value in vin), vin),
        ("verdicts of the board", len(reports["verdict"]) >= 2 and all(value == "PASS" for value in reports["verdict"]),
         reports["verdict"]),
    ]
    for label, ok, values in checks:
        print(f"{'PASS' if ok else 'FAIL'}  {label}: {values}")

    if all(ok for _, ok, _ in checks):
        return 0
    if not lines:
        print("hint: nothing received; check that the supply_monitor image is flashed and running",
              file=sys.stderr)
    elif vin and max(vin) < 1000:
        print("hint: +VIN is absent; the board must be supplied through its terminal block, not USB alone",
              file=sys.stderr)
    else:
        print("hint: check the supply voltage given with --vin, then R11 and R12 (VIN_SENSE divider); "
              "if only one build type fails, look for undefined behavior", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
