#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `supply_monitor` test on the Bornier base board.

Records the trace of the board and checks the supply voltages it reads with its ADC: VDDA, the
3.3 V rail, from VREFINT and its factory calibration, and +VIN from VIN_SENSE. The board must be
supplied through its terminal block; give the voltage of that supply with --vin. Run it against
both the debug and the release image.

The board must already be flashed with the image of --preset (or --elf) and running.

    python tools/hil/supply_monitor.py --vin 24 --preset release
"""

import argparse
import sys

import kymo_trace


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    kymo_trace.add_arguments(parser, seconds=5.0)
    parser.add_argument("--vin", type=float, default=24.0, help="voltage of the supply on the terminal block")
    parser.add_argument("--tolerance", type=float, default=5.0, help="accepted error on +VIN, in percent")
    args = parser.parse_args()

    recording = kymo_trace.record(args, kymo_trace.image(args, "tests/supply_monitor/supply_monitor"))
    if not kymo_trace.report(recording):
        return 1
    readings = recording.named("measured")
    missed = len(recording.named("no_reading"))

    def numbers(name: str) -> list[int]:
        return [event.number(name) for event in readings]

    vdda = numbers("vdda_mv")
    vin = numbers("vin_mv")
    cal = numbers("vrefint_cal")
    verdicts = [event.flag("pass") for event in readings]
    low, high = args.vin * (1 - args.tolerance / 100) * 1000, args.vin * (1 + args.tolerance / 100) * 1000
    enough = len(readings) >= 2

    checks = [
        ("VREFINT calibration read, 12 bits", enough and all(0 < value < 4096 for value in cal), cal),
        ("VDDA within 3.3 V +-5 %", enough and all(3135 <= value <= 3465 for value in vdda), vdda),
        (f"+VIN within {args.vin:g} V +-{args.tolerance:g} %", enough and all(low <= value <= high for value in vin), vin),
        ("verdicts of the board", enough and all(verdicts), verdicts),
        ("a reading every second", missed == 0, f"{missed} missed"),
    ]
    for label, ok, values in checks:
        print(f"{'PASS' if ok else 'FAIL'}  {label}: {values}")

    if all(ok for _, ok, _ in checks):
        return 0
    if not readings and not missed:
        print("hint: nothing traced; check that the supply_monitor image is flashed and running",
              file=sys.stderr)
    elif missed:
        print("hint: the ADC gives no reading; check its clock and its DMA channel", file=sys.stderr)
    elif vin and max(vin) < 1000:
        print("hint: +VIN is absent; the board must be supplied through its terminal block, not USB alone",
              file=sys.stderr)
    else:
        print("hint: check the supply voltage given with --vin, then R11 and R12 (VIN_SENSE divider); "
              "if only one build type fails, look for undefined behavior", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
