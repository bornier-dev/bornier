# Simulation of the supply input and 5 V buck

`python buck_sim.py` (ngspice shipped with KiCad, a few minutes) writes `results.md`.

The board takes a 12 V or a 24 V supply: 10.8 to 30 V, simulated down to the UVLO stop (7.8 V).

## Model

TI publishes no SPICE model that ngspice can run, so the TPS54360B is a behavioural model built
from its datasheet (SNVSB93):

- fixed-frequency peak-current-mode control at 658 kHz (RT = 100 k + 47 k), COMP to switch current 12 A/V;
- error amplifier: 350 µA/V, DC gain 10 000, 2.5 MHz unity-gain bandwidth, ±30 µA output;
- 5.5 A current limit through the COMP clamp, 135 ns minimum on-time;
- frequency foldback 1/2/4/8 as FB falls, OVP at 106 %, pulse skipping at COMP = 0.6 V;
- soft-start as a 2.2 ms ramp of the reference;
- slope compensation: the datasheet (7.3.2) states that an internal ramp prevents sub-harmonic
  oscillation above 50 % duty cycle, without giving its value. The model uses Se = Vout / (2 L),
  the smallest ramp that keeps this promise up to 100 % duty with this inductor: the worst case.

The loop gain uses the small-signal model of the datasheet (Fig. 28) plus the sampling double
pole of current mode at fsw/2, with the ramp above. Below 50 % duty cycle the case without any
ramp is also computed, and the worst of the two is kept.

The values follow the 5 V design example of the datasheet, which is specified for a 12 V nominal,
8.5 to 60 V input.

Input side: 2 m of supply wiring (1.5 µH, 40 mΩ), F1 (12H1350C, 3.5 A), D1 (back-to-back zeners fitted to the
SMBJ33CA clamp: 53.3 V at 11.3 A), D2, C1 (47 µF, 1 Ω ESR), C2 + C3 and the ceramics of the five TPS1H000 (VS and outputs), 6.1 µF at 24 V.
Output: C5 + C6 derated to 56 µF, swept from 34 to 80 µF.

## Conclusions

| Check | Result | Limit | Verdict |
|---|---|---|---|
| Phase margin, 7.8-30 V, 0.25-3.5 A, Cout 34-80 µF | 79° minimum | ≥ 45° | pass |
| Gain margin, same sweep | 11.6 dB minimum (at 7.8 V) | ≥ 6 dB | pass |
| Regulation, start-up 10.8 to 30 V at 2.5 A | 5.09 V, no overshoot, ≤ 11 mV peak to peak 3.5 ms after start | — | pass |
| Load step 0.5 → 2.5 → 0.5 A, 10.8 to 30 V | 4.84 to 5.23 V | 4.5–5.5 V of the 5 V parts | pass |
| Lowest running input (7.8 V, UVLO stop), hot switch, 2.5 A | 5.09 V | — | pass |
| Inductor peak in an output short, up to 53 V in | 5.6 A | 8 A saturation (MWSA1004S) | pass |
| Hot plug at 30 V, with C1 | 35.9 V on VIN (below the 42 V of the TPS1H000 and of the 0-10 V op amp), TVS idle, fuse I²t 0.031 A²s | 42 V; 2.95 A²s melting (12H1350C) | pass |
| Hot plug at 30 V, without C1 | 47 V on VIN, TVS conducts | — | C1 is needed |
| Surge 0.5 kV 1.2/50 µs, 2 Ω, line to line | 118 V on VIN, fuse I²t 1.2 A²s | 65 V absolute maximum | **fail** |

- UVLO from the datasheet tolerances (EN 1.1-1.3 V, 0.58-1.8 µA pull-up, 2.2-4.5 µA hysteresis,
  1 % resistors): start 8.47 V nominal, 9.48 V at most, below the 10.5 V that the lowest supply
  (10.8 V) leaves on VIN; stop 7.79 V nominal, 6.71 V at least, above the 6.2 V the datasheet
  (equation 2) asks for a 2.5 A load.
- The inductor first chosen (MWSA0603S, 5.5 A) saturated below the 6.8 A worst-case current limit
  of the datasheet: replaced by the MWSA1004S-8R2MT (8 A).
- Values come from the passive palette of the board (one feeder per value, at most two parts per
  value): 5.10 V output (47k + 12.1k over 10k + 1k, above USB VBUS so that the 3.3 V buck does not
  draw from USB), compensation 12.1k with 2 x 100 nF in series (50 nF: one 100 nF alone settled in
  10 ms, 22 nF is no longer in the palette), RT 100k + 47k, without the 39 pF pole
  capacitor of the TI example, which a ceramic output does not need.
- After a short, the output overshoots to 5.55 V: the model does not restart the soft-start after
  an overload, which the datasheet says the device does. The real overshoot is lower.
- The switch current spikes of 100 A and more in `results.md` are an artefact: the ideal switch
  charges the diode capacitance in zero time. They are not used.
- Surge: no 33 V TVS keeps the 65 V rating of the regulator against a 2 Ω surge generator
  (65 A through the TVS). Meeting it would need a 100 V regulator, a larger TVS and a larger
  fuse. Not done: the board is meant to be fed by a dedicated supply in the same cabinet,
  over short wiring, the supply taking the mains surges. This is a condition of use.
