# On-target tests

Hardware-in-the-loop scripts. Each one talks to a board that is already flashed and running
and exits with status 0 on success. They listen to the text the board prints on SWO, through a
J-Link, and need Python 3 and the SEGGER J-Link software.

| Image | Script | Checks |
|---|---|---|
| `firmware/examples/blink` | `blink_swo.py` | numbered lines on SWO, consecutive and one per second |
| `firmware/tests/atomic_mmio` | `atomic_mmio.py` | exclusive accesses (LDREX/STREX) to peripheral registers, against interrupts and DMA |
| `firmware/tests/esc_probe` | `esc_probe.py` | LAN9253 through the OCTOSPI: identification registers (BYTE_TEST, ID_REV), then write and read back in the user RAM of the EtherCAT core, in single then in quad (SQI) bus mode |
| `firmware/tests/rs485_echo` | `rs485_echo.py` | isolated RS-485 port, nothing wired: the 256 byte values come back through the transceiver, no line error |

Run each test on the debug and the release image. Flashing is described in
[CONTRIBUTING.md](../../CONTRIBUTING.md#flashing-and-debugging).

## Adding a test

- One firmware image per test under `firmware/tests/<name>/`, one script here with the same name.
- The script exits 0 on success and 1 otherwise, and on failure prints what to check.
- The firmware prints a report the script can parse, and ends it with a `verdict PASS` or
  `verdict FAIL` line when the check runs on the board.
