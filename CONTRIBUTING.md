# Contributing to Bornier

## Ground rules

- **English only**: code, comments, documentation, file names, commit messages.
- **Licenses**: every file carries SPDX headers (`SPDX-License-Identifier`, `SPDX-FileCopyrightText`).
  Files that cannot hold a header are covered by [`REUSE.toml`](REUSE.toml).
  Hardware is CERN-OHL-W-2.0, firmware and tools MPL-2.0, documentation CC-BY-4.0.
- **CMake only.** The CMake files and the GNU Arm toolchain are the whole build; IDE project
  files are not committed.
- **Generated files are not edited by hand**: the register headers in
  [`firmware/devices/`](firmware/devices/STM32H563/README.md).

## Building the firmware

On Debian 13 (the reference platform, also used by CI):

```sh
sudo apt install cmake ninja-build gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
git clone --recurse-submodules https://github.com/bornier-dev/bornier.git
cd bornier
cmake --preset debug   && cmake --build --preset debug
cmake --preset release && cmake --build --preset release
```

On other systems, install CMake, Ninja and the Arm GNU Toolchain 14.2 (the version Debian 13
ships), with `arm-none-eabi-gcc` on the `PATH`.

Images land in `build/<preset>/firmware/...` as `.elf`, `.bin` and `.map`.

## Firmware rules

- **C++23 on the OpSy RTOS** ([`firmware/third_party/opsy`](firmware/third_party/opsy)), no HAL or CMSIS: peripherals are reached
  through the generated register headers.
- **Warnings are errors.** The warning set in [`firmware/CMakeLists.txt`](firmware/CMakeLists.txt)
  applies to all code, OpSy included, and linker warnings are fatal too. Fix a warning at its
  source; disable one only if it is pure noise, and say why next to the flag.
- **Debug and release are both tested on target.** A bug that shows only with optimization almost
  always means undefined behavior or approximate code, not a compiler problem.
- **Hardware and concurrency:**
  - memory-mapped registers are accessed through `volatile`, which the generated headers do;
  - data shared between an interrupt and a task is a `std::atomic` or is protected by a lock,
    never a plain variable;
  - a read-modify-write on a register that an interrupt may also modify uses the OpSy atomic
    operators (`reg |= value | atomic`, `reg <<= field || atomic`). They protect against
    interrupts and tasks on the same core, not against DMA or another bus master
    ([`firmware/tests/atomic_mmio`](firmware/tests/atomic_mmio/main.cpp)).
- **Style**: match the surrounding code (tabs in C++, four spaces in CMake, comment density,
  naming).

## Flashing and debugging

A debug probe is needed only for the first flash and for debugging; boards then update over
EtherCAT (FoE). Flashing and debugging use probe-rs, which drives ST-Link, J-Link and
CMSIS-DAP probes.

```sh
probe-rs download --chip STM32H563ZI --verify build/debug/firmware/examples/hello/hello.elf
probe-rs reset --chip STM32H563ZI
```

On Linux, install [`tools/udev/60-debug-probes.rules`](tools/udev/60-debug-probes.rules) so the
probe is usable without root:

```sh
sudo cp tools/udev/60-debug-probes.rules /etc/udev/rules.d/
sudo udevadm control --reload && sudo udevadm trigger
```

To debug, start the GDB server, then connect GDB:

```sh
probe-rs gdb --chip STM32H563ZI
arm-none-eabi-gdb build/debug/firmware/examples/hello/hello.elf \
    -ex "target extended-remote 127.0.0.1:1337" \
    -ex "set mem inaccessible-by-default off" \
    -ex "load"
```

- `set mem inaccessible-by-default off` is needed to read peripheral registers: the memory map
  probe-rs gives GDB does not include them.
- After `load` the program counter is already on the reset handler; avoid `monitor reset` in
  the session.
- The GDB server holds the probe until it exits: stop it before flashing with
  `probe-rs download`, which otherwise fails with a USB error.

## On-target tests

Hardware-in-the-loop scripts and the list of tests are in [`tools/hil/`](tools/hil/README.md).
Run them on the debug and the release image.

## Commits and pull requests

- One topic per pull request; commit messages in English, imperative mood.
- CI builds both presets and must pass.
- For a firmware change, state in the pull request which boards and which on-target tests were
  run, on which images.

## Vendor ID and forks

Official releases carry the Bornier EtherCAT Vendor ID. Forks that distribute hardware or
firmware must use their own Vendor ID.
