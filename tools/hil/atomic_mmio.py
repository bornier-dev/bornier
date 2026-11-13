#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `atomic_mmio` test on the Bornier base board.

Listens to SWO through a J-Link and checks the verdict of the report. The firmware runs the test
once at boot, which takes a few seconds, then prints its report every two seconds. Run it against
both the debug and the release image.

The board must already be flashed and running. The script needs the SEGGER J-Link software:
it runs J-Link SWO Viewer, found on the PATH or given with --viewer.

    python tools/hil/atomic_mmio.py

Exit status: 0 on PASS, 1 on FAIL or when no complete report arrives.
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
    parser.add_argument("--seconds", type=float, default=12.0, help="listening time")
    args = parser.parse_args()

    viewer = find_viewer(args.viewer)
    if viewer is None:
        print("J-Link SWO Viewer not found: install the SEGGER J-Link software, or give --viewer", file=sys.stderr)
        return 1

    lines = [text for _, text in listen(viewer, args.device, args.cpu_hz, args.swo_hz, args.seconds)]

    # Keep the last complete report: the listening may start in the middle of one.
    ends = [index for index, text in enumerate(lines) if text == "end"]
    report: list[str] = []
    if ends:
        start = ends[-2] + 1 if len(ends) >= 2 else 0
        report = lines[start:ends[-1]]
    for text in report:
        print(text)

    verdicts = [text.split()[1] for text in report if text.startswith("verdict ")]
    complete = len(ends) >= 2 and len(verdicts) == 1
    if not complete:
        print("FAIL  no complete report received; check that the atomic_mmio image is flashed and "
              "running (not halted by the debugger), and that the probe cable carries SWO",
              file=sys.stderr)
        return 1
    if verdicts[0] != "PASS":
        print("hint: see the header of firmware/tests/atomic_mmio/main.cpp for what each line must show",
              file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
