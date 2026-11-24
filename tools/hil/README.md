# On-target tests

Hardware-in-the-loop scripts. Each one talks to a board that is already flashed and running
and exits with status 0 on success. They record the trace of the board with
[Kymo](../../firmware/third_party/kymo) through the debug port (SWD), and need Python 3 and the
`kymo` host program (see [CONTRIBUTING.md](../../CONTRIBUTING.md#tracing)).

| Image | Script | Checks |
|---|---|---|
| `firmware/examples/blink` | `blink.py` | blink events, consecutive and one per second |
| `firmware/tests/atomic_mmio` | `atomic_mmio.py` | exclusive accesses (LDREX/STREX) to peripheral registers, against interrupts and DMA |
| `firmware/tests/esc_probe` | `esc_probe.py` | LAN9253 through the OCTOSPI: identification registers (BYTE_TEST, ID_REV), then write and read back in the user RAM of the EtherCAT core, in single then in quad (SQI) bus mode |
| `firmware/tests/rs485_echo` | `rs485_echo.py` | isolated RS-485 port, nothing wired: the 256 byte values come back through the transceiver, no line error |
| `firmware/tests/supply_monitor` | `supply_monitor.py` | supplies read by the ADC: VDDA (3.3 V rail) from VREFINT, +VIN from VIN_SENSE; the board is supplied through its terminal block, its voltage given with `--vin` |

Run each test on the debug and the release image, with `--preset debug` or `--preset release`:
the script decodes the trace with the ELF of that build, which must be the one flashed. Flashing
is described in [CONTRIBUTING.md](../../CONTRIBUTING.md#flashing-and-debugging).

`kymo_trace.py` holds what the scripts share: their options (preset or ELF, probe, chip, core
clock, recording time), the call to `kymo record` and the parsing of its output.

## Adding a test

- One firmware image per test under `firmware/tests/<name>/`, one script here with the same name.
- The image reports with events: plain structs in a namespace named after the test, written with
  `bornier::trace::emit()` (`firmware/trace/bornier/trace.hpp`). Kymo reads their layout from the
  ELF; enumerations print by name. When the check runs on the board, an event carries its
  verdict.
- The script exits 0 on success and 1 otherwise, and on failure prints what to check.
