# STM32H563 register headers

Typed C++ register definitions for the STM32H563: one header per group of peripherals
(`gpio.hpp`, `tim.hpp`, ...), plus:

- `interrupts.hpp`, the interrupt numbers;
- `device.hpp`, the name of the device and what the SVD file says of its core;
- `vectors.hpp`, the vector table of the device, built at compile time;
- `mmio.hpp`, the register building blocks the other headers are made of.

Everything is in the `STM32H563` namespace. The headers only need the standard library.

The headers are generated: do not edit them by hand. They were produced by
[SvdGenerator](https://github.com/Otatiaro/SvdGenerator) 1.0.0-pre.57111ab from the
STMicroelectronics STM32H563 SVD file, version 1.7 (SHA-256
`3daa2bdf5fab3e6995c050489e6033326628fb6471d81e922bd3639b579e740f`).
The first lines of each header name the generator, the SVD file and its checksum. The README of
SvdGenerator describes the generated API.

The headers derived from the SVD file are licensed Apache-2.0 like that file. `mmio.hpp` comes
from SvdGenerator and is licensed MIT.

Peripherals with the same registers share one type: `gpio_p` for every GPIO port, `tim1_p` for
`tim1` and `tim8`, `tim2_p` for `tim2` and `tim5`. A register does not repeat the name of its
peripheral: `rcc.ahb2enr`, of type `rcc_p::ahb2enr_r`. The GPDMA channels are an array:
`gpdma1.c[2].cr`.
`stm32h563xi.ld` is the linker script for the 2 MB flash / 640 KB SRAM variant (MPL-2.0).
