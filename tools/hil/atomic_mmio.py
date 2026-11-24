#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `atomic_mmio` test on the Bornier base board.

Records the trace of the board and checks the verdict of its report. The firmware runs the test
once at boot, which takes a few seconds, then traces its report every two seconds: one probe
event per register and kind of disturbance, one stress event per register and update, then the
verdict. Run it against both the debug and the release image.

The board must already be flashed with the image of --preset (or --elf) and running.

    python tools/hil/atomic_mmio.py --preset release

Exit status: 0 on PASS, 1 on FAIL or when no complete report arrives.
"""

import argparse
import sys

import kymo_trace


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    kymo_trace.add_arguments(parser, seconds=12.0)
    args = parser.parse_args()

    recording = kymo_trace.record(args, kymo_trace.image(args, "tests/atomic_mmio/atomic_mmio"))
    if not kymo_trace.report(recording):
        return 1

    # Keep the last complete report, between the last two verdicts: the recording may start in
    # the middle of one.
    events = recording.events
    ends = [index for index, event in enumerate(events) if event.short() == "verdict"]
    if len(ends) < 2:
        print("FAIL  no complete report recorded; check that the atomic_mmio image is flashed and "
              "running (not halted by the debugger)", file=sys.stderr)
        return 1
    for event in events[ends[-2] + 1:ends[-1] + 1]:
        print(event.short(), " ".join(f"{key}={value}" for key, value in event.fields.items()))

    if not events[ends[-1]].flag("pass"):
        print("hint: see the header of firmware/tests/atomic_mmio/main.cpp for what each event must show",
              file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
