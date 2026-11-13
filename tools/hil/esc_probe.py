#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `esc_probe` test on the Bornier base board.

Listens to SWO through a J-Link and checks the report of the board: the identification registers
of the LAN9253, read through the OCTOSPI. Run it against both the debug and the release image.

The board must already be flashed and running. The script needs the SEGGER J-Link software:
it runs J-Link SWO Viewer, found on the PATH or given with --viewer.

    python tools/hil/esc_probe.py
"""

import argparse
import re
import sys

from blink_swo import find_viewer, listen

REGISTER = re.compile(r"^(byte_test|id_rev) 0x([0-9a-f]{8})$")


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--viewer", help="path of J-Link SWO Viewer (command line version)")
    parser.add_argument("--device", default="STM32H523VE")
    parser.add_argument("--cpu-hz", type=int, default=250_000_000, help="core clock of the image")
    parser.add_argument("--swo-hz", type=int, default=2_000_000, help="bit rate asked on the SWO pin")
    parser.add_argument("--seconds", type=float, default=6.0, help="listening time")
    args = parser.parse_args()

    viewer = find_viewer(args.viewer)
    if viewer is None:
        print("J-Link SWO Viewer not found: install the SEGGER J-Link software, or give --viewer", file=sys.stderr)
        return 1

    lines = [text for _, text in listen(viewer, args.device, args.cpu_hz, args.swo_hz, args.seconds)]
    values: dict[str, set[int]] = {"byte_test": set(), "id_rev": set()}
    for text in lines:
        if match := REGISTER.match(text):
            values[match.group(1)].add(int(match.group(2), 16))
    verdicts = [text for text in lines if text.startswith("verdict ")]

    def show(found: set[int]) -> str:
        return ", ".join(f"0x{value:08x}" for value in sorted(found)) or "nothing"

    byte_test_ok = values["byte_test"] == {0x87654321}
    id_ok = bool(values["id_rev"]) and all(value >> 16 == 0x9253 for value in values["id_rev"])
    verdict_ok = len(verdicts) >= 2 and all(text == "verdict PASS" for text in verdicts)

    print(f"{'PASS' if byte_test_ok else 'FAIL'}  BYTE_TEST reads {show(values['byte_test'])}, 0x87654321 expected")
    print(f"{'PASS' if id_ok else 'FAIL'}  ID_REV reads {show(values['id_rev'])}, 0x9253 expected in the upper half")
    print(f"{'PASS' if verdict_ok else 'FAIL'}  {len(verdicts)} verdicts from the board, "
          f"{verdicts.count('verdict PASS')} PASS")

    if byte_test_ok and id_ok and verdict_ok:
        return 0
    if not lines:
        print("hint: nothing received; the image prints only once its first read has ended: check "
              "that esc_probe is flashed and running, then the OCTOSPI clock and pins", file=sys.stderr)
    elif values["byte_test"] <= {0x00000000, 0xFFFFFFFF}:
        print("hint: the LAN9253 does not answer; check its supply, its 25 MHz clock and that its "
              "reset line is high", file=sys.stderr)
    else:
        print("hint: wrong values; check the SPI mode, the byte order and the bit rate (READ is "
              "limited to 30 MHz)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
