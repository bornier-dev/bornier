# Firmware

C++23 firmware on the OpSy RTOS (`third_party/opsy`), built with CMake and the GNU
Arm toolchain. Build, flashing and coding rules are in [CONTRIBUTING.md](../CONTRIBUTING.md).

| Directory | Contents |
|---|---|
| `devices/` | Per-MCU generated register headers, and the linker script |
| `boards/` | Board support: clock tree, pins, drivers of the on-board peripherals, startup and vector table |
| `examples/` | Minimal images for bring-up |
| `tests/` | Images for on-target tests, driven by the scripts in [`tools/hil/`](../tools/hil) |
| `third_party/` | OpSy, as a git submodule |

`CMakeLists.txt` here defines the targets every image builds on:

- `cortex_m33`: CPU, FPU and code generation options;
- `project_warnings`: the warning set, as errors (compiler and linker);
- `opsy`: the RTOS;
- `stm32h563` and `stm32h523` (in `devices/`);
- `board_nucleo_h563zi` and `board_base` (in `boards/`): the NUCLEO-H563ZI development board and
  the Bornier base board of [`hardware/base/`](../hardware/base).

An image links its board target and `project_warnings`; see `examples/hello/CMakeLists.txt`.
`examples/hello` runs on the NUCLEO-H563ZI, `examples/blink` on the base board.

## Adding a board

Create `boards/<board>/` with an INTERFACE target that links the device target, provides the
startup code as a source and adds the board directory to the include path. Then add it to this
directory's `CMakeLists.txt`.
