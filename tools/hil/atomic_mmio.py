#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Read the report of the atomic_mmio on-target test and check its verdict.

Flash firmware/tests/atomic_mmio first. The firmware runs the test at boot and prints the
report every time it receives a byte.

Exit status: 0 on PASS, 1 on FAIL or when no complete report arrives.
"""

import argparse
import sys
import time

import serial


def main() -> int:
    parser = argparse.ArgumentParser(description="Check the report of the atomic_mmio on-target test.")
    parser.add_argument("--port", required=True, help="serial port of the ST-LINK VCP (e.g. /dev/ttyACM0, COM5)")
    parser.add_argument("--timeout", type=float, default=30.0, help="seconds to wait for the report")
    args = parser.parse_args()

    with serial.Serial(args.port, 115200, timeout=0.5) as port:
        port.reset_input_buffer()
        deadline = time.monotonic() + args.timeout
        verdict = None
        started = False
        while time.monotonic() < deadline:
            if not started:
                # The test runs for a few seconds after reset and drops what arrives meanwhile:
                # ask again until the report starts.
                port.write(b"\n")
            line = port.readline().decode("ascii", errors="replace").rstrip()
            if not line:
                continue
            started = True
            print(line)
            if line.startswith("verdict "):
                verdict = line.split()[1]
            if line == "end":
                break

    if verdict is None:
        print("FAIL  no complete report received; check that the atomic_mmio image is flashed and "
              "running (not halted by the debugger), and that --port is the probe's virtual COM port",
              file=sys.stderr)
        return 1
    if verdict != "PASS":
        print("hint: see the header of firmware/tests/atomic_mmio/main.cpp for what each line must show",
              file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
