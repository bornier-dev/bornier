# STM32H523 register headers

Typed C++ register definitions for the STM32H523: one header per peripheral, plus
`interrupts.hpp` for the interrupt numbers. They build on the register primitives of OpSy
(`firmware/third_party/opsy/utility/memory.hpp`).

The headers are generated: do not edit them by hand. They were produced by SvdGenerator from
the STMicroelectronics STM32H523 SVD file, version 1.2 (SHA-256
`b989e9e5972266fa4f88ddf1c6e88730eb561bb5fadd696d822d5329803a197e`), and are licensed
Apache-2.0 like that file.

This SVD file describes every GPIO port and every timer as a peripheral of its own, where the
STM32H563 file groups them: the headers are `gpioa.hpp` to `gpioi.hpp` and `tim1.hpp` to
`tim15.hpp`, and each port has its own register types (`gpioc_p::gpioc_moder_r`).

`stm32h523xe.ld` is the linker script for the 512 KB flash / 272 KB SRAM variant (MPL-2.0).
