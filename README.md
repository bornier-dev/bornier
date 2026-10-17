# Bornier

Open source EtherCAT slaves for machine tools running LinuxCNC: hardware, firmware and tooling.

- Website: [bornier.dev](https://bornier.dev)

> **Status: design phase.** Nothing here is usable yet.

## Goals

- A family of standard-compliant EtherCAT slaves for CNC retrofits: motion (step/dir, encoders, probe), digital and analog I/O, operator panel.
- Works with any EtherCAT master; developed and tested against LinuxCNC with the IgH master (`lcec`).
- Firmware builds on the LinuxCNC PC itself with a free toolchain (`arm-none-eabi-gcc`, CMake) and updates over EtherCAT (FoE).
- Hardware designed in KiCad, published in full.

Out of scope: functional safety. E-stop and STO stay hardwired.

## Hardware platform

- EtherCAT slave controller: Microchip LAN9252.
- MCU: STM32H563.
- Firmware: C++23 on the [OpSy](https://github.com/Otatiaro/OpSy) RTOS.
- A common processor module (SoM) on application-specific carrier boards, extended by DIN-rail I/O modules over a local bus.

## Licensing

| Part | License |
|---|---|
| Hardware (KiCad projects) | [CERN-OHL-W-2.0](LICENSES/CERN-OHL-W-2.0.txt) |
| Firmware and tools | [MPL-2.0](LICENSES/MPL-2.0.txt) |
| Documentation | [CC-BY-4.0](LICENSES/CC-BY-4.0.txt) |

Each file carries an SPDX header naming its license.

## Official builds and forks

Official releases will carry the Bornier EtherCAT Vendor ID. Forks distributing hardware or firmware must use their own Vendor ID.

EtherCAT® is a registered trademark and patented technology, licensed by Beckhoff Automation GmbH, Germany.
