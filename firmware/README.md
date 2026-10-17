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
- `stm32h563` (in `devices/`) and `board_nucleo_h563zi` (in `boards/`).

An image links its board target and `project_warnings`; see `examples/hello/CMakeLists.txt`.

## Adding a board

Create `boards/<board>/` with an INTERFACE target that links the device target, provides the
startup code as a source and adds the board directory to the include path. Then add it to this
directory's `CMakeLists.txt`.
