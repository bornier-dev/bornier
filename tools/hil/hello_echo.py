#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Hardware-in-the-loop check for the `hello` example on a NUCLEO-H563ZI.

Run it against both the debug and the release image: a failure that only shows up in release
points at undefined behaviour (missing volatile, data race, aliasing), never at the optimiser.

The board must already be flashed and reset; this script only talks to the virtual COM port.

    python tools/hil/hello_echo.py --port /dev/ttyACM0
"""

import argparse
import sys
import time

import serial  # pyserial


def check(port: serial.Serial, payload: bytes, settle: float) -> bool:
    port.reset_input_buffer()
    port.write(payload)
    time.sleep(settle)
    echoed = port.read(port.in_waiting)
    ok = echoed == payload
    print(f"{'PASS' if ok else 'FAIL'}  sent {len(payload):3d} B, echoed {len(echoed):3d} B")
    return ok


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    parser.add_argument("--port", required=True, help="serial port of the ST-LINK virtual COM port")
    parser.add_argument("--baud", type=int, default=115200)
    args = parser.parse_args()

    with serial.Serial(args.port, args.baud, timeout=1) as port:
        cases = [b"a", b"bornier", bytes(range(32, 127)), b"x" * 200]
        results = [check(port, payload, settle=0.5) for payload in cases]

    if all(results):
        return 0
    if not any(results):
        print("hint: nothing echoed at all; check that the hello image is flashed and running, "
              "and that --port is the probe's virtual COM port", file=sys.stderr)
    else:
        print("hint: partial echo; if only one build type fails, look for undefined behavior "
              "(missing volatile, data race, aliasing)", file=sys.stderr)
    return 1


if __name__ == "__main__":
    sys.exit(main())
