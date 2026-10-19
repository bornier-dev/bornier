# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Write bornier.kicad_sym: symbols of the parts that KiCad does not ship.

Usage: python gen_symbols.py
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, ".."))
from kicadgen.symgen import switch_units, symbol, symbol_units, write_library  # noqa: E402

PI, PO, IN, OUT, BI, PAS, OC = "power_in", "power_out", "input", "output", "bidirectional", "passive", "open_collector"

# Microchip LAN9253 (DS00003421B, Figure 3-1 and Table 3-1). Pin names follow the SPI with GPIO
# mode; the other functions of each pin are in the datasheet.
LAN9253_PINS = [
    # left: clock, reset, configuration, PDI, Distributed Clocks, straps. Pins that take a pull
    # resistor are spaced so that the resistor fits between them on the schematic.
    ("1", "OSCI", IN, "L", 0), ("2", "OSCO", OUT, "L", 1),
    ("11", "~{RST}", BI, "L", 3), ("7", "REG_EN", IN, "L", 4), ("41", "TESTMODE", IN, "L", 5),
    ("50", "~{SCS}", IN, "L", 7), ("19", "SCK", IN, "L", 8), ("17", "SI/SIO0", BI, "L", 9),
    ("13", "SO/SIO1", BI, "L", 10), ("12", "SIO2", BI, "L", 11), ("35", "SIO3", BI, "L", 12),
    ("44", "IRQ", OUT, "L", 14), ("34", "SYNC0/LATCH0", BI, "L", 16), ("18", "SYNC1/LATCH1", BI, "L", 22),
    ("10", "WAIT_ACK", BI, "L", 28),
    ("42", "EESDA/EE_EMUL1", BI, "L", 34), ("43", "EESCL/EE_EMUL2", BI, "L", 40),
    ("8", "CLK_25/XTAL_MODE", BI, "L", 46), ("57", "RBIAS", PAS, "L", 49),
    # right: ports, LEDs
    ("53", "TXPA", BI, "R", 0), ("52", "TXNA", BI, "R", 1), ("55", "RXPA", BI, "R", 2), ("54", "RXNA", BI, "R", 3),
    ("62", "TXPB", BI, "R", 24), ("63", "TXNB", BI, "R", 25), ("60", "RXPB", BI, "R", 26), ("61", "RXNB", BI, "R", 27),
    ("48", "LINKACTLED0/CHIP_MODE0", BI, "R", 38), ("46", "LINKACTLED1/CHIP_MODE1", BI, "R", 44),
    ("45", "RUNLED/EE_EMUL0", BI, "R", 50), ("9", "ERRLED/100FD_B", BI, "R", 56),
    # top: supplies, grouped by rail
    ("5", "VDD33", PI, "T", 0), ("14", "VDDIO", PI, "T", 1), ("20", "VDDIO", PI, "T", 2),
    ("32", "VDDIO", PI, "T", 3), ("37", "VDDIO", PI, "T", 4), ("47", "VDDIO", PI, "T", 5),
    ("58", "VDD33BIAS", PI, "T", 7), ("51", "VDD33TXRX1", PI, "T", 9), ("64", "VDD33TXRX2", PI, "T", 11),
    ("6", "VDDCR", PO, "T", 13), ("24", "VDDCR", PI, "T", 14), ("38", "VDDCR", PI, "T", 15),
    ("56", "VDD12TX1", PI, "T", 17), ("59", "VDD12TX2", PI, "T", 18), ("3", "OSCVDD12", PO, "T", 20),
    # bottom: grounds and the GPIO of the SPI with GPIO mode (unused)
    ("4", "OSCVSS", PI, "B", 0), ("65", "VSS", PI, "B", 1),
    ("36", "GPIO0", BI, "B", 3), ("39", "GPIO1", BI, "B", 4), ("40", "GPIO2", BI, "B", 5),
    ("49", "GPIO3", BI, "B", 6), ("23", "GPIO4", BI, "B", 7), ("22", "GPIO5", BI, "B", 8),
    ("21", "GPIO6", BI, "B", 9), ("16", "GPIO7", BI, "B", 10), ("15", "GPIO8", BI, "B", 11),
    ("33", "GPIO9", BI, "B", 12), ("29", "GPIO10", BI, "B", 13), ("26", "GPIO11", BI, "B", 14),
    ("27", "GPIO12", BI, "B", 15), ("28", "GPIO13", BI, "B", 16), ("30", "GPIO14", BI, "B", 17),
    ("31", "GPIO15", BI, "B", 18), ("25", "A1/EE_EMUL_SPI2", BI, "B", 19),
]


# TI TPS1H000-Q1 (SLVSDO6E, Table 4-1), DGN HVSSOP-8 with thermal pad.
TPS1H000_PINS = [
    ("8", "VS", PI, "L", 0), ("1", "IN", IN, "L", 2), ("2", "DIAG_EN", IN, "L", 3), ("5", "DELAY", IN, "L", 4),
    ("4", "CL", PAS, "L", 5),
    ("7", "OUT", "power_out", "R", 0), ("3", "~{FAULT}", OC, "R", 3),
    ("6", "GND", PI, "B", 3), ("9", "EP", PAS, "B", 5),
]
# Toshiba TLP2361 (SO6, 5 leads): 1 anode, 3 cathode, 4 GND, 5 VO (totem pole, inverting), 6 VCC.
TLP2361_PINS = [
    ("1", "A", PAS, "L", 0), ("3", "K", PAS, "L", 2),
    ("6", "VCC", PI, "R", 0), ("5", "VO", OUT, "R", 1), ("4", "GND", PI, "R", 2),
]


# TI TPS2553 (SLVS841F, DBV SOT-23-6): 1 IN, 2 GND, 3 EN (active high), 4 FAULT, 5 ILIM, 6 OUT.
TPS2553_PINS = [
    ("1", "IN", PI, "L", 0), ("3", "EN", IN, "L", 2), ("5", "ILIM", PAS, "L", 3),
    ("6", "OUT", "power_out", "R", 0), ("4", "~{FAULT}", OC, "R", 2),
    ("2", "GND", PI, "B", 3),
]


# Dual op amp in one unit (SOIC-8 standard pinout), so that both halves and the supply are drawn.
# Half B on top, half A below (feedback drawn under the body), V+ on the right, V- bottom left.
DUAL_OPAMP_PINS = [
    ("6", "-INB", IN, "L", 0), ("5", "+INB", IN, "L", 1), ("3", "+INA", IN, "L", 3), ("2", "-INA", IN, "L", 4),
    ("7", "OUTB", OUT, "R", 0), ("8", "V+", PI, "R", 2), ("1", "OUTA", OUT, "R", 4),
    ("4", "V-", PI, "B", 0),
]


# Chipanalog CA-IS3092W (datasheet v1.02, table 6-3), SOIC-16 wide body: logic side on the left,
# isolated bus side on the right, each ground on its own side of the bottom edge.
CA_IS3092W_PINS = [
    ("1", "VCC", PI, "L", 0), ("6", "DI", IN, "L", 2), ("5", "DE", IN, "L", 3), ("4", "~{RE}", IN, "L", 4),
    ("3", "RO", OUT, "L", 5),
    ("16", "VISO", "power_out", "R", 0), ("10", "SEL", IN, "R", 1), ("12", "A", BI, "R", 3), ("13", "B", BI, "R", 4),
    ("11", "NC", "no_connect", "R", 6), ("14", "NC", "no_connect", "R", 7),
    ("2", "GNDA", PI, "B", 0), ("7", "GNDA", PI, "B", 1), ("8", "GNDA", PI, "B", 2),
    ("9", "GNDB", PI, "B", 6), ("15", "GNDB", PI, "B", 7),
]


def rj45x2_units():
    """Dual RJ45, one unit per port (A on the left, B on the right, front view), drawn like the
    KiCad Connector:RJ45_Shielded symbol so that each unit sits where a single RJ45 did. The common
    shield is in unit A."""
    units = []
    for port in "AB":
        pins = [(f"{port}{k}", str(k), PAS, 10.16, -7.62 + 2.54 * (k - 1), 180) for k in range(1, 9)]
        if port == "A":
            pins.append(("SH", "SH", PAS, 0.0, -12.7, 90))
        units.append(pins)
    return units


def main():
    # Side pins start 5 slots down so that their names clear the vertical names of the top pins.
    pins = [(n, nm, t, side, slot + 5 if side in "LR" else slot) for n, nm, t, side, slot in LAN9253_PINS]
    syms = [symbol("LAN9253", pins, width=22, height=63,
                   footprint="Package_DFN_QFN:QFN-64-1EP_9x9mm_P0.5mm_EP6x6mm_ThermalVias",
                   datasheet="https://ww1.microchip.com/downloads/aemDocuments/documents/UNG/ProductDocuments/DataSheets/LAN9253-Data-Sheet-DS00003421.pdf",
                   description="EtherCAT slave controller, 2 integrated PHYs, SPI/SQI/HBI host interface")]
    syms.append(symbol("TPS1H000", TPS1H000_PINS, width=10, height=7,
                       footprint="Package_SO:HVSSOP-8-1EP_3x3mm_P0.65mm_EP1.57x1.89mm",
                       datasheet="https://www.ti.com/lit/ds/symlink/tps1h000-q1.pdf",
                       description="40 V, 1 ohm high-side switch with adjustable current limit"))
    syms.append(symbol("TLP2361", TLP2361_PINS, width=8, height=4,
                       footprint="Package_SO:SO-5-6_4.55x3.7mm_P1.27mm",
                       datasheet="https://toshiba.semicon-storage.com/info/TLP2361_datasheet_en_20190617.pdf",
                       description="15 Mbit/s optocoupler, totem-pole inverting output, 2.7-5.5 V"))
    syms.append(symbol("TPS2553", TPS2553_PINS, width=8, height=5,
                       footprint="Package_TO_SOT_SMD:SOT-23-6",
                       datasheet="https://www.ti.com/lit/ds/symlink/tps2553.pdf",
                       description="2.5-6.5 V load switch, adjustable current limit, fault output"))
    syms.append(symbol("OPAMP_DUAL", DUAL_OPAMP_PINS, width=6, height=6,
                       footprint="Package_SO:SOIC-8_3.9x4.9mm_P1.27mm",
                       description="Dual op amp, standard SOIC-8 pinout, both halves and supply in one unit"))
    syms.append(symbol("CA-IS3092W", CA_IS3092W_PINS, width=10, height=9,
                       footprint="Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm",
                       datasheet="https://datasheet.lcsc.com/datasheet/pdf/ee960fbdc33ef85219621c78fbff6cc1.pdf",
                       description="Isolated half-duplex RS-485 transceiver with integrated DC-DC, 5 kVrms"))
    syms.append(symbol_units("RJ45x2_Shielded", rj45x2_units(), (-7.62, -10.16, 7.62, 12.7),
                             footprint="Bornier:RJ45x2_HongCheng_HC-WK88-H132-1X2-55B",
                             datasheet="https://datasheet.lcsc.com/datasheet/pdf/dc2904e2d83d7d6c79679fa0f146db90.pdf",
                             description="Dual RJ45 jack, shielded, without magnetics or LEDs; unit A: port A and "
                                         "shield, unit B: port B"))
    syms.append(switch_units("SW_DIP_x04_Split", 4,
                             footprint="Button_Switch_SMD:SW_DIP_SPSTx04_Slide_KingTek_DSHP04TS_W7.62mm_P1.27mm",
                             datasheet="https://datasheet.lcsc.com/datasheet/pdf/b12889a146649629a94eee2aab5f121b.pdf",
                             description="4-position DIP switch, one unit per switch: unit k joins pins k and 9 - k"))
    write_library(os.path.join(HERE, "bornier.kicad_sym"), syms)


if __name__ == "__main__":
    main()
