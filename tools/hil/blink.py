#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `blink` example on the Bornier base board.

Records the trace of the board for a few seconds and checks that it emits consecutive numbered
`blink` events, one per second by the core's cycle counter. Run it against both the debug and
the release image: a failure that only shows up in release points at undefined behaviour, never
at the optimiser.

The board must already be flashed with the image of --preset (or --elf) and running.

    python tools/hil/blink.py --preset release
"""

import argparse
import sys

import kymo_trace


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    kymo_trace.add_arguments(parser, seconds=6.0)
    args = parser.parse_args()

    recording = kymo_trace.record(args, kymo_trace.image(args, "examples/blink/blink"))
    if not kymo_trace.report(recording):
        return 1
    blinks = [(event.seconds, int(event.fields["count"])) for event in recording.named("blink")]

    expected = int(args.seconds) - 1
    enough = len(blinks) >= expected
    consecutive = all(b[1] == a[1] + 1 for a, b in zip(blinks, blinks[1:]))
    periods = [b[0] - a[0] for a, b in zip(blinks, blinks[1:])]
    mean = sum(periods) / len(periods) if periods else 0.0
    steady = bool(periods) and abs(mean - 1.0) < 0.01

    print(f"{'PASS' if enough else 'FAIL'}  {len(blinks)} blinks traced, at least {expected} expected")
    print(f"{'PASS' if consecutive else 'FAIL'}  blink numbers consecutive: {[n for _, n in blinks]}")
    print(f"{'PASS' if steady else 'FAIL'}  mean period {mean:.4f} s, 1.0000 s expected within 1 %")

    if enough and consecutive and steady:
        return 0
    if not blinks:
        print("hint: no blink traced; check that the image is flashed and running, and that it is "
              "the one --preset or --elf names", file=sys.stderr)
    else:
        print("hint: blinks lost or period off; if only one build type fails, look for undefined "
              "behavior (missing volatile, data race, aliasing)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
