# STM32H563 register headers

Typed C++ register definitions for the STM32H563: one header per peripheral, plus
`interrupts.hpp` for the interrupt numbers. They build on the register primitives of OpSy
(`firmware/third_party/opsy/utility/memory.hpp`).

The headers are generated: do not edit them by hand. They were produced by SvdGenerator from
the STMicroelectronics STM32H563 SVD file, version 1.7 (SHA-256
`3daa2bdf5fab3e6995c050489e6033326628fb6471d81e922bd3639b579e740f`), and are licensed
Apache-2.0 like that file.

`stm32h563xi.ld` is the linker script for the 2 MB flash / 640 KB SRAM variant (MPL-2.0).
