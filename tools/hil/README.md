# On-target tests

Hardware-in-the-loop scripts. Each one talks to a board that is already flashed and running,
through the probe's virtual COM port (`/dev/ttyACM0`, `COM5`...), and exits with status 0 on
success. They need Python 3 and pyserial; `step_generator.py` also needs numpy, logic2-automation
and Logic 2 running with its automation server enabled (port 10430).

| Image | Script | Checks |
|---|---|---|
| `firmware/examples/hello` | `hello_echo.py --port <port>` | UART echo, 1 to 200 bytes |
| `firmware/tests/atomic_mmio` | `atomic_mmio.py --port <port>` | exclusive accesses (LDREX/STREX) to peripheral registers, against interrupts and DMA |
| `firmware/tests/step_generator` | `step_generator.py --port <port>` | STEP/DIR outputs on a Saleae logic analyzer: step counts and positions, pulse and DIR timings, jitter, alignment on SYNC0 |

Run each test on the debug and the release image. Flashing is described in
[CONTRIBUTING.md](../../CONTRIBUTING.md#flashing-and-debugging).

## Adding a test

- One firmware image per test under `firmware/tests/<name>/`, one script here with the same name.
- The script exits 0 on success and 1 otherwise, and on failure prints what to check.
- The firmware prints a report the script can parse, and ends it with a `verdict PASS` or
  `verdict FAIL` line when the check runs on the board.
