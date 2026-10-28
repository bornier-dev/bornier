# step_generator

On-target test of the step generator ([`step_generator.hpp`](step_generator.hpp)): four STEP/DIR
axes on TIM1 slots, refilled once per SYNC0 period. SYNC0 is simulated by TIM16 and the motion by
[`motion.hpp`](motion.hpp). The host side is
[`tools/hil/step_generator.py`](../../../tools/hil/step_generator.py), which drives a Saleae
logic analyzer through the Logic 2 automation API.

## Wiring on the NUCLEO-H563ZI

The step generator uses the pins of the Bornier base board. PA4 is only on the ST morpho
connector CN11, which is not fitted on a new board: solder at least pin 32. Leave the user USB-C
connector (CN13) unplugged: PA4 also reaches its VBUS sense divider.

| Signal | MCU pin | Nucleo connector | Logic channel |
|---|---|---|---|
| STEP0 | PE9 (TIM1_CH1) | CN10-4 (D6) | 0 |
| DIR0 | PE10 | CN10-24 (D40) | 1 |
| STEP1 | PE14 (TIM1_CH4) | CN10-8 (D4) | 2 |
| DIR1 | PE15 | CN10-30 (D37) | 3 |
| STEP2 | PE13 (TIM1_CH3) | CN10-10 (D3) | 4 |
| DIR2 | PE12 | CN10-26 (D39) | 5 |
| STEP3 | PE11 (TIM1_CH2) | CN10-6 (D5) | 6 |
| DIR3 | PE8 | CN10-18 (D42) | 7 |
| SYNC0 | PA4 (TIM5_ETR) | CN11-32 | 8 |
| ground | | CN10-5, CN10-17 | ground |

A wire takes the simulated SYNC0 from PB8 (TIM16_CH1, CN7-2, D15) to PA4 (CN11-32).

## Running

```sh
python3 tools/hil/step_generator.py --port /dev/ttyACM0 --seconds 10
python3 tools/hil/step_generator.py --port /dev/ttyACM0 --profile full --seconds 10
```

`--help` lists the generator settings (`--rate`, `--steplen`, `--dirsetup`, `--head`...) and
`--detune`, which shifts the SYNC0 period to play the drift of the distributed clock.

The board answers on the ST-LINK virtual COM port; the commands are described at the top of
[`main.cpp`](main.cpp).
