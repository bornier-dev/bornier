# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Bornier base board: reference circuit (parts, values, footprints, LCSC codes, connections).

Single source of the schematic: schematic.py draws it, check.py proves the drawing matches.
"""
import os
import sys

sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "lib"))
from kicadgen.circuit import Circuit, C0402, C0603, C0805, R0402, R0603  # noqa: E402

C1210 = "Capacitor_SMD:C_1210_3225Metric"
C1206 = "Capacitor_SMD:C_1206_3216Metric"
SMB = "Diode_SMD:D_SMB"
LED0603 = "LED_SMD:LED_0603_1608Metric"
# Indicator LEDs: yellow-green KT-0603YG (VF 2.0-2.2 V) rather than an emerald green (VF 3.1 V), which
# would stay dark on 3.3 V through 1 k; red KT-0603R (VF 1.8-2.4 V).
LED_G, LED_R = "C2289", "C2286"
R1206 = "Resistor_SMD:R_1206_3216Metric"
# The only terminal block of the board: pluggable 3.81 mm, 4 poles, 8 A (KF2EDGR-3.81-4P; plug KF2EDGK-3.81-4P).
# Pinout rule of every terminal block: pole 1 withstands the supply voltage, pole 2 is 0 V. The plugs are all
# alike: the POWER plug (+VIN, 0 V, FE) damages nothing whichever header it is plugged into.
TB4 = ("Connector:Screw_Terminal_01x04", "Connector_Phoenix_MC:PhoenixContact_MC_1,5_4-G-3.81_1x04_P3.81mm_Horizontal",
       "C441184")

# Passive palette: every resistor and capacitor of the board is one of these lines (one feeder each
# on a pick-and-place). 0402 by default; 0603 for 1 uF 50 V and for the 120 ohm terminations
# (75 mW under RS-422, above the 62.5 mW of an 0402); 1206 where the supply voltage is dropped.
PALETTE = {
    ("R", "49.9", R0603): "C23185",     # 0603: an Ethernet termination straddles the other line of its pair
    ("R", "1k", R0402): "C11702",
    ("R", "2.2k", R0402): "C25879",
    ("R", "4.7k", R0402): "C25900",
    ("R", "10k", R0402): "C25744",
    ("R", "12.1k", R0402): "C25852",
    ("R", "47k", R0402): "C25792",
    ("R", "100k", R0402): "C25741",
    ("R", "120", R0603): "C22787",
    ("R", "3.3k", R1206): "C26032",
    ("R", "4.7k", R1206): "C17936",
    ("C", "470pF", C0402): "C1537",
    ("C", "100nF", C0402): "C307331",
    ("C", "1µF 50V", C0603): "C15849",
    ("C", "10µF 25V", C0805): "C15850",
    ("C", "1nF 2kV", C1206): "C9196",
    ("C", "2.2µF 100V", C1210): "C153036",
    ("C", "100µF 10V", C1210): "C84455",
}

c = Circuit(PALETTE, r_fp=R0402, c_fp=C0402)

# --------------------------------------------------------------------------------------------
c.block("Supply input protection: 12 V or 24 V, 10.8 to 30 V")
# Logic supply only: the field supply of the modules never comes through here.
c.part("J1", TB4[0], "POWER", TB4[1], TB4[2], {1: "VIN_RAW", 2: "GND", 3: "CHASSIS"},
       "+VIN (12 or 24 V), 0 V, functional earth (the shields meet earth here, wired with the supply), pole 4 unused")
c.part("F1", "Device:Fuse", "3.5A 63V", "Fuse:Fuse_1206_3216Metric", "C182975", {1: "VIN_RAW", 2: "VIN_F"},
       "12H1350C, 3.5 A 63 V fast acting, 50 A breaking; worst case load 1.9 A at 19.2 V, 2.4 A at 10.8 V (68 %); "
       "a sustained overvoltage kills the TVS (short) before the fuse opens")
c.part("D1", "Device:D_TVS", "SMBJ33CA", SMB, "C78420", {1: "VIN_F", 2: "GND"},
       "Bidirectional TVS: 33 V standoff, 53.3 V clamp; also clamps negative surges")
c.part("D2", "Device:D_Schottky", "SS56B", SMB, "C14651", {1: "+VIN", 2: "VIN_F"},
       "Reverse polarity: 60 V, 5 A; 1.2 W at 2.4 A, needs copper")
c.part("C1", "Device:C_Polarized", "47µF 63V", "Capacitor_SMD:CP_Elec_6.3x7.7", "C46550423",
       {1: "+VIN", 2: "GND"}, "Damps the hot-plug ringing of the ceramics and the cable")

# --------------------------------------------------------------------------------------------
c.block("5 V buck (TI TPS54360B, 658 kHz, passive palette values, simulated)")
c.C("C2", "2.2µF 100V", "+VIN", "GND", fp=C1210)
c.C("C3", "2.2µF 100V", "+VIN", "GND", fp=C1210)
# UVLO: 200 k over 32.0 k: start 8.47 V (9.48 V worst case: EN 1.3 V, Ip min, 1 % resistors), stop 7.79 V,
# hysteresis 0.68 V. The lowest supply, 10.8 V, gives about 10.5 V on +VIN before the buck starts.
c.R("R1", "100k", "+VIN", "EN1", note="UVLO top: R1 + R300 = 200 k (hysteresis 200 k x 3.4 uA = 0.68 V)")
c.R("R300", "100k", "EN1", "EN")
c.R("R2", "47k", "EN", "GND", note="UVLO bottom: R2 // R308 = 32.0 k: start 8.47 V (9.48 V worst case), stop 7.79 V")
c.R("R308", "100k", "EN", "GND")
c.part("U1", "Regulator_Switching:TPS54360DDA", "TPS54360BDDAR", None, "C524806",
       {2: "+VIN", 3: "EN", 4: "RT", 1: "BOOT", 8: "SW5", 6: "COMP", 5: "FB5", 7: "GND", 9: "GND"},
       "60 V, 3.5 A buck, current mode")
c.R("R3", "100k", "RT", "RT1", note="With R301: 147 k, f(SW) = 92417 / 147^0.991 = 658 kHz")
c.R("R301", "47k", "RT1", "GND")
c.C("C4", "100nF", "BOOT", "SW5")
c.part("D3", "Device:D_Schottky", "SS56B", SMB, "C14651", {1: "SW5", 2: "GND"}, "Catch diode: 60 V, 5 A")
c.part("L1", "Device:L", "8.2µH", "Inductor_SMD:L_Sunlord_MWSA1004S", "C408486", {1: "SW5", 2: "+5V"},
       "Sunlord MWSA1004S-8R2MT, 8 A saturation: above the 6.8 A worst-case current limit")
c.C("C5", "100µF 10V", "+5V", "GND", fp=C1210,
    note="Murata GRM32ER61A107ME20L X5R: about 55 uF at 5 V, 38 uF at 85 °C and -20 %, inside the simulated 34-80 uF")
c.R("R4", "47k", "+5V", "FB5A", note="Top R4 + R302 = 59.1 k, bottom R5 + R303 = 11 k: Vout = 0.8 x (1 + 59.1/11) = 5.10 V, above VBUS")
c.R("R302", "12.1k", "FB5A", "FB5")
c.R("R5", "10k", "FB5", "FB5B")
c.R("R303", "1k", "FB5B", "GND")
c.R("R6", "12.1k", "COMP", "COMPZ")
c.C("C7", "100nF", "COMPZ", "COMPY", note="C7 + C312 in series = 50 nF: zero at 263 Hz, settles in 5 ms; no HF pole capacitor (ceramic output)")
c.C("C312", "100nF", "COMPY", "GND")

# --------------------------------------------------------------------------------------------
c.block("USB micro-B: bench power and DFU")
c.part("J2", "Connector:USB_B_Micro", "USB micro-B",
       "Connector_USB:USB_Micro-B_Molex-105133-0001", "C782257",
       {1: "VBUS", 2: "USB_DM", 3: "USB_DP", 5: "GND", "SH": "GND"},
       "Molex 105133-0001, vertical: the plug comes from above, so the jack sits next to the MCU, away from the "
       "edges that the DIN rail profile holds")
c.part("U2", "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714",
       {1: "USB_DP", 2: "USB_DM", 5: "VBUS", 10: "USB_DP", 9: "USB_DM", 6: "VBUS", 3: "GND", 8: "GND"},
       "ESD of the USB lines and VBUS (5.5 V working voltage); same part as on the PHY lines. DP on the channel "
       "nearer the MCU pin of DP, so the pair flows through without crossing. VBUS on the outer channel (5, "
       "through 6), which faces R7: on the inner one (4, through 7) the USB pair and the ground via boxed it in")
c.R("R7", "1k", "VBUS", "VBUS_SENSE", note="VBUS_SENSE on PD9 (USART3_RX input in the bootloader)")
c.R("R8", "2.2k", "VBUS_SENSE", "GND", note="3.44 V at 5 V (PD9 is 5 V tolerant); low impedance: a leakage of D5 cannot fake VBUS")

# --------------------------------------------------------------------------------------------
c.block("3.3 V buck, fed by the 5 V rail or by USB")
# Each source reaches the buck through its own Schottky: neither feeds the other.
# SS56B, the part of the 24 V input, rather than a smaller Schottky: one BOM line less
c.part("D4", "Device:D_Schottky", "SS56B", SMB, "C14651", {1: "V3IN", 2: "+5V"})
c.part("D5", "Device:D_Schottky", "SS56B", SMB, "C14651", {1: "VUSB_D", 2: "VBUS"})
# USB path switched off while +5V is present: +5V (4.96-5.24 V) is not guaranteed above VBUS (up to 5.25 V)
c.part("Q11", "Transistor_FET:AO3401A", "AO3401A", "Package_TO_SOT_SMD:SOT-23", "C15127",
       {1: "QU_G", 2: "VUSB_D", 3: "V3IN"}, "P-MOS: on (VGS -4.6 V) on USB alone, off (VGS > -0.3 V) with +5V present")
c.R("R310", "1k", "+5V", "QU_G", note="+5V present: gate at 0.99 x +5V, VGS > -0.25 V worst case: USB path off")
c.R("R311", "100k", "QU_G", "GND", note="+5V absent: gate low, USB path on")
c.C("C9", "10µF 25V", "V3IN", "GND", fp=C0805, note="Buck input capacitor")
c.part("U3", "Regulator_Switching:TPS62A02ADRL", "TPS62A02ADRLR", None, "C5820994",
       {3: "V3IN", 4: "V3IN", 1: "GND", 2: "SW3", 5: "FB3"}, "2 A buck, forced PWM 2.4 MHz")
c.part("L2", "Device:L", "1µH", "Inductor_SMD:L_1008_2520Metric", "C435392", {1: "SW3", 2: "+3V3"},
       "Murata DFE252012F-1R0M")
c.R("R9", "10k", "+3V3", "FB3", note="Vout = 0.6 x (1 + 10/2.2) = 3.33 V")
c.R("R10", "2.2k", "FB3", "GND")
c.C("C10", "10µF 25V", "+3V3", "GND", fp=C0805, note="Buck output: 2 x 10 uF")
c.C("C300", "10µF 25V", "+3V3", "GND", fp=C0805)

# --------------------------------------------------------------------------------------------
c.block("Supply monitoring and power LEDs")
c.R("R11", "100k", "+VIN", "VIN_SENSE", note="Full scale 73.5 V: no current injected, even in a surge")
c.R("R12", "4.7k", "VIN_SENSE", "GND")
c.C("C11", "100nF", "VIN_SENSE", "GND")
c.R("R13", "4.7k", "+VIN", "LEDVIN", fp=R1206, note="1.7 mA at 10.8 V, 5.9 mA and 0.17 W at 30 V")
c.part("D6", "Device:LED", "green", LED0603, LED_G, {2: "LEDVIN", 1: "GND"}, "Supply present")
c.R("R14", "1k", "+3V3", "LED3V3")
c.part("D7", "Device:LED", "green", LED0603, LED_G, {2: "LED3V3", 1: "GND"}, "3.3 V present")
c.R("R306", "4.7k", "+VIN_OUT", "LEDVOUT", fp=R1206, note="1.7 mA at 10.8 V, 5.9 mA and 0.17 W at 30 V")
c.part("D300", "Device:LED", "green", LED0603, LED_G, {2: "LEDVOUT", 1: "GND"},
       "VIN OUT present:off while a short on a drive port, ESTOP, PROBE or SPINDLE holds +VIN_OUT in current limit")
c.block("Test points of the rails")
for tp, net in (("TP4", "+VIN"), ("TP5", "+VIN_OUT"), ("TP6", "+5V"), ("TP7", "+3V3")):
    c.part(tp, "Connector:TestPoint", net, "TestPoint:TestPoint_Pad_D1.5mm", "", {1: net}, "Pad")

# --------------------------------------------------------------------------------------------
c.block("25 MHz clock shared by the ESC and the MCU")
c.part("X1", "Oscillator:SiT8008xx-7x-xxE", "SiT8008BI-71-33E-25.000000", None, "C806295",
       {1: "+3V3", 2: "GND", 3: "CLK25", 4: "+3V3"}, "25 MHz, ±20 ppm all-inclusive, -40 to +85 °C")
c.C("C12", "100nF", "+3V3", "GND")
c.R("R15", "49.9", "CLK25", "CLK25_ESC", fp=R0603, note="Source series termination")
c.R("R16", "49.9", "CLK25", "CLK25_MCU", fp=R0603, note="Source series termination")

# --------------------------------------------------------------------------------------------
c.block("EtherCAT slave controller (LAN9253), reset, configuration straps")
# Pin numbers: Microchip DS00003421B Table 3-1. Design rules: docs of the LAN9253 checklist
# DS00003644B, as cited in the notes.
ESC_PINS = {
    1: "CLK25_ESC", 4: "GND", 65: "GND", 41: "GND",          # oscillator input; OSCO, OSCVDD12 open
    5: "+3V3", 7: "+3V3", 14: "+3V3", 20: "+3V3", 32: "+3V3", 37: "+3V3", 47: "+3V3",
    6: "VDDCR", 24: "VDDCR", 38: "VDDCR", 56: "VDD12TX", 59: "VDD12TX",
    58: "VDD33BIAS", 51: "VDD33TXRX1", 64: "VDD33TXRX2", 57: "RBIAS", 8: "CLK25_OFF",
    11: "ESC_RST", 50: "ESC_SCS", 19: "ESC_SCK", 17: "ESC_SIO0", 13: "ESC_SIO1", 12: "ESC_SIO2", 35: "ESC_SIO3",
    44: "ESC_IRQ", 34: "ESC_SYNC0", 18: "ESC_SYNC1", 10: "ESC_WAIT_ACK", 42: "EESDA", 43: "EESCL",
    53: "TXPA", 52: "TXNA", 55: "RXPA", 54: "RXNA", 62: "TXPB", 63: "TXNB", 60: "RXPB", 61: "RXNB",
    48: "LINK0", 46: "LINK1", 45: "RUN", 9: "ERR",
}
c.part("U4", "Bornier:LAN9253", "LAN9253-I/R4X", None, "C5745149", ESC_PINS,
       "SPI with GPIO mode; GPIO pins unused, left open")
c.C("C13", "100nF", "+3V3", "GND", note="VDD33 (5)")
for i, pin in enumerate((14, 20, 32, 37, 47)):
    c.C(f"C{14 + i}", "100nF", "+3V3", "GND", note=f"VDDIO ({pin})")
c.C("C19", "10µF 25V", "+3V3", "GND", fp=C0805, note="Bulk of the 3.3 V plane at the ESC")
c.C("C20", "1µF 50V", "VDDCR", "GND", note="VDDCR (6): 1 µF, ESR 0.1 ohm, at the pin (checklist p.3)")
c.C("C21", "470pF", "VDDCR", "GND", note="VDDCR (6)")
c.C("C22", "100nF", "VDDCR", "GND", note="VDDCR (24)")
c.C("C23", "100nF", "VDDCR", "GND", note="VDDCR (38)")
FB = "Inductor_SMD:L_0603_1608Metric"
for i, (fb, rail, cs) in enumerate((("FB1", "VDD33BIAS", ("C24", "C25")), ("FB2", "VDD33TXRX1", ("C26", "C27")),
                                    ("FB3", "VDD33TXRX2", ("C28", "C29")))):
    c.part(fb, "Device:FerriteBead_Small", "220R@100MHz", FB, "C80165", {1: "+3V3", 2: rail},
           "Murata BLM18PG221SN1D, as on the Microchip boards")
    c.C(cs[0], "100nF", rail, "GND")
    c.C(cs[1], "1µF 50V", rail, "GND")
c.part("FB4", "Device:FerriteBead_Small", "220R@100MHz", FB, "C80165", {1: "VDDCR", 2: "VDD12TX"},
       "Murata BLM18PG221SN1D")
c.C("C30", "100nF", "VDD12TX", "GND", note="VDD12TX1 (56)")
c.C("C31", "100nF", "VDD12TX", "GND", note="VDD12TX2 (59)")
c.C("C32", "1µF 50V", "VDD12TX", "GND")
c.R("R17", "12.1k", "RBIAS", "GND", note="1 %, at pin 57, nothing routed under it")
c.R("R18", "1k", "CLK25_OFF", "GND", note="Strap: CLK_25 output off (the SiT8008 clocks ESC and MCU)")
# Reset: supervisor on RST# only; the MCU drives RST# open drain and reads it back (EtherCAT reset).
c.part("U5", "Power_Supervisor:TPS3808DBV", "TPS3808G33DBVR", None, "C43698",
       {6: "+3V3", 5: "+3V3", 4: "SUP_CT", 2: "GND", 1: "ESC_RST"}, "3.07 V threshold, 300 ms; MR open")
c.R("R19", "100k", "SUP_CT", "+3V3", note="CT to VDD through 40-200 k: 300 ms delay")
c.C("C33", "100nF", "+3V3", "GND")
c.R("R20", "10k", "ESC_RST", "+3V3")
# PDI and Distributed Clocks: defined levels while the ESC is not configured (Hi-Z).
c.R("R21", "10k", "ESC_IRQ", "+3V3", note="IRQ: open drain, active low by default")
c.R("R22", "10k", "ESC_SYNC0", "GND")
c.R("R23", "10k", "ESC_SYNC1", "GND")
c.R("R24", "10k", "ESC_WAIT_ACK", "GND", note="Resistive pull-down, never a direct ground")
# SII EEPROM emulation by the MCU, PDI SPI (EE_EMUL[2:0] = 000): 42, 43 and 45 pulled down.
# Fallback EEPROM: fit U6 and R27, R28, remove R25, R26. 16 Kbit keeps E2PSIZE = 0, so the RUN
# LED keeps its polarity in both variants.
c.R("R25", "1k", "EESDA", "GND", note="EE_EMUL1 = 0 (emulation)")
c.R("R26", "1k", "EESCL", "GND", note="EE_EMUL2 = 0 (emulation)")
c.R("R27", "4.7k", "EESDA", "+3V3", note="EEPROM variant only", dnp=True)
c.R("R28", "4.7k", "EESCL", "+3V3", note="EEPROM variant only", dnp=True)
c.part("U6", "Memory_EEPROM:24LC16", "M24C16-RMN6TP", "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm", "C79946",
       {8: "+3V3", 4: "GND", 5: "EESDA", 6: "EESCL", 7: "GND"}, "Fallback SII EEPROM, not fitted", dnp=True)
c.C("C34", "100nF", "+3V3", "GND", note="EEPROM variant only", dnp=True)

# --------------------------------------------------------------------------------------------
c.block("EtherCAT LEDs")
c.R("R29", "1k", "RUN", "GND", note="Strap EE_EMUL0 = 0: RUN LED to ground, active high")
c.R("R30", "1k", "RUN", "RUN_A")
c.part("D8", "Device:LED", "green RUN", LED0603, LED_G, {2: "RUN_A", 1: "GND"})
c.R("R31", "1k", "ERR", "GND", note="Strap 100FD_B = 0: port B keeps auto-negotiation")
c.R("R32", "1k", "ERR", "ERR_A")
c.part("D9", "Device:LED", "red ERR", LED0603, LED_R, {2: "ERR_A", 1: "GND"})
c.R("R33", "1k", "LINK0", "GND", note="Strap CHIP_MODE0 = 0 (2 ports)")
c.R("R34", "1k", "LINK0", "LINK0_A")
c.R("R35", "1k", "LINK1", "GND", note="Strap CHIP_MODE1 = 0 (2 ports)")
c.R("R36", "1k", "LINK1", "LINK1_A")

# --------------------------------------------------------------------------------------------
c.block("EtherCAT ports: IN = port 0 (PHY A), OUT = port 1 (PHY B)")
RJ = "Connector_RJ:RJ45_Hanrun_HR911105A_Horizontal"
# The lines on jack pins 1, 2, 3, 6, and on ESD channels 1, 2, 4, 5, in the orders the block layout found
# for the pairs to route through their arrays (blocks.py, pair_lanes; they change with the placement, and
# pcb.py stops on a board wired otherwise). The PHYs correct the polarity and have HP Auto-MDIX (data sheet,
# key benefits; 100FD straps low): any order is right.
# The terminations keep their lines whatever the orders (rs on terms).
for j, port, jack, chans, terms, rail, led, rs, ccap, esd in (
        ("J3", "IN", ("TXNA", "TXPA", "RXNA", "RXPA"), ("RXPA", "RXNA", "TXPA", "TXNA"),
         ("TXNA", "TXPA", "RXNA", "RXPA"), "VDD33TXRX1", "LINK0_A", ("R37", "R38", "R39", "R40"), "C35", "U7"),
        ("J4", "OUT", ("RXPB", "RXNB", "TXPB", "TXNB"), ("RXPB", "RXNB", "TXPB", "TXNB"),
         ("RXPB", "RXNB", "TXPB", "TXNB"), "VDD33TXRX2", "LINK1_A", ("R41", "R42", "R43", "R44"), "C36", "U8")):
    j1, j2, j3, j6 = jack
    tp, tn, rp, rn = chans
    c.part(j, "Connector:RJ45_Hanrun_HR911105A_Horizontal", f"HY911105AE {port}", RJ, "C69427",
           {1: j1, 2: j2, 3: j3, 6: j6, 4: rail, 5: rail, 8: "CHASSIS", "SH": "CHASSIS", 9: led, 10: "GND"},
           "HanRun HY911105AE, -40/+85 °C; same footprint as HR911105A. Yellow LED unused")
    for r, n in zip(rs, terms):
        c.R(r, "49.9", n, rail, fp=R0603, note="1 %, at the ESC")
    c.C(ccap, "100nF", rail, "GND", note="Centre taps, at the magjack (checklist: 22 nF; any value from 22 nF up)")
    c.part(esd, "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714",
           {1: tp, 2: tn, 4: rp, 5: rn, 10: tp, 9: tn, 7: rp, 6: rn, 3: "GND", 8: "GND"},
           "ESD of the PHY lines, flow-through: the NC pins opposite each line carry it (TI: straight-through routing)")
c.C("C37", "1nF 2kV", "CHASSIS", "GND", fp=C1206, note="Chassis to ground, away from the ESC (checklist)")
c.C("C301", "1nF 2kV", "CHASSIS", "GND", fp=C1206, note="At the drive and encoder RJ45 row")
c.C("C302", "1nF 2kV", "CHASSIS", "GND", fp=C1206, note="At the terminal block row")
# Screw mounting, for a panel instead of the DIN rail profile: four M3 holes at the corners, clear of the
# profile grooves along the long edges. H1 is plated and on CHASSIS: the screw earths the board to the panel.
c.part("H1", "Mechanical:MountingHole_Pad", "M3 CHASSIS", "MountingHole:MountingHole_3.2mm_M3_Pad", "",
       {1: "CHASSIS"}, "Plated M3 hole, nearest corner to the POWER terminal block (FE pole)")
for h in ("H2", "H3", "H4"):
    c.part(h, "Mechanical:MountingHole", "M3", "MountingHole:MountingHole_3.2mm_M3", "", {}, "Non-plated M3 hole")
c.part("H5", "Mechanical:MountingHole_Pad", "PE CONTACT", "MountingHole:MountingHole_3.2mm_M3_Pad", "",
       {1: "CHASSIS"}, "Plated hole for the Phoenix UM-BASIC/PRO PE CONTACT L1 (2202025), screwed under the board: "
       "earths CHASSIS to the DIN rail")

# --------------------------------------------------------------------------------------------
c.block("Test points")
TPFP = "TestPoint:TestPoint_Pad_D1.5mm"
c.part("TP1", "Connector:TestPoint", "ESC_IRQ", TPFP, "", {1: "ESC_IRQ"}, "Pad, also used to measure the clock")
c.part("TP2", "Connector:TestPoint", "SYNC0", TPFP, "", {1: "ESC_SYNC0"}, "Pad")
c.part("TP3", "Connector:TestPoint", "GND", TPFP, "", {1: "GND"}, "Pad")

# --------------------------------------------------------------------------------------------
c.block("MCU STM32H523VET6 (any H5 in LQFP-100 fits the same footprint)")
# Pin assignment: private design notes, H523 pin table. Series terminations of the OCTOSPI at the
# MCU: Q_* is the MCU side, ESC_* the ESC side.
MCU_PINS = {
    1: "ENA0", 2: "ENA1", 3: "ENA2", 4: "BUS_LATCH", 5: "ENA3", 7: "LED_MCU", 8: "ALM2", 9: "ESTOP_IN",
    12: "CLK25_MCU", 13: "SPINDLE_DIR", 14: "NRST", 15: "VIN_SENSE", 16: "BUS_IRQ", 17: "BUS_OE", 18: "ALM3",
    23: "ENC0_A", 24: "ENC0_B", 25: "PROBE", 26: "ESC_SYNC1", 29: "ESC_SYNC0", 30: "SPINDLE_AOUT",
    31: "Q_SIO3", 32: "Q_SIO2", 33: "ESC_WAIT_ACK", 34: "ESC_IRQ", 35: "Q_SIO1", 36: "Q_SIO0", 37: "Q_SCK",
    38: "ESC_RST", 39: "DIR0", 40: "STEP0", 41: "DIR1", 42: "STEP1", 43: "DIR2", 44: "STEP2", 45: "STEP3",
    46: "DIR3", 47: "Q_SCS", 51: "BUS_CS7", 52: "BUS_CS8", 53: "BUS_CS9", 54: "SPINDLE_PWM", 55: "BUS_CS6",
    56: "VBUS_SENSE",
    57: "BUS_CS4", 58: "BUS_CS5", 59: "ENC3_A", 60: "ENC3_B", 61: "SPINDLE_EN", 62: "WDI",
    63: "ENC2_A", 64: "ENC2_B", 65: "ENC2_Z", 66: "PC9_GND", 67: "ALM0", 68: "PA9_GND", 69: "BUS_CS11",
    70: "USB_DM", 71: "USB_DP", 72: "SWDIO", 76: "SWCLK", 77: "ENC0_Z", 78: "BUS_SCK", 79: "BUS_MISO",
    80: "BUS_MOSI", 81: "BUS_CS0", 82: "BUS_CS1", 83: "ENC1_Z", 84: "BUS_CS2", 85: "MB_DE", 86: "MB_TX",
    87: "MB_RX", 88: "BUS_CS3", 89: "SWO", 90: "ENC1_A", 91: "ENC1_B", 92: "BUS_SCL", 93: "BUS_SDA",
    95: "BUS_CS10", 96: "ALM1", 97: "ENC3_Z",
    6: "+3V3", 11: "+3V3", 28: "+3V3", 50: "+3V3", 75: "+3V3", 100: "+3V3", 73: "+3V3",
    22: "VDDA", 21: "VDDA", 20: "GND", 19: "GND", 10: "GND", 27: "GND", 49: "GND", 74: "GND", 99: "GND",
    48: "VCAP", 98: "VCAP", 94: "BOOT0",
}
c.part("U9", "MCU_ST_STM32H5:STM32H523VETx", "STM32H523VET6", None, "C27338462", MCU_PINS,
       "Revision X or W required for H562/H563; any revision for H523/H533")
# PA9 and PC9 drive the UCPD dead-battery pull-downs of PB13 and PB14 (DS14540 Table 13: UCPD1_DB1,
# UCPD1_DB2) from every reset until the firmware sets UCPD_DBDIS; PC9 is also pulled up by the
# bootloader (I2C3_SDA). Both are tied low and carry no signal.
c.R("R304", "1k", "PA9_GND", "GND", note="UCPD1_DB1 held low: no pull-down on BUS_CS8 (PB13)")
c.R("R305", "1k", "PC9_GND", "GND", note="UCPD1_DB2 held low: no pull-down on BUS_CS9 (PB14)")
for i, pin in enumerate((11, 28, 50, 75, 100)):
    c.C(f"C{38 + i}", "100nF", "+3V3", "GND", note=f"VDD ({pin})")
c.C("C43", "10µF 25V", "+3V3", "GND", fp=C0805, note="Common VDD bulk (AN5711 §7.4)")
c.C("C44", "100nF", "+3V3", "GND", note="VBAT (6): no battery, tied to VDD (AN5711 §2.1.4)")
c.C("C45", "100nF", "+3V3", "GND", note="VDDUSB (73)")
c.C("C46", "1µF 50V", "VCAP", "GND", note="VCAP (48): 2 x 1 uF = 2.0 uF per pin (2.2 uF +-20 %), ESR < 100 mohm")
c.C("C310", "1µF 50V", "VCAP", "GND", note="VCAP (48)")
c.C("C47", "1µF 50V", "VCAP", "GND", note="VCAP (98)")
c.C("C311", "1µF 50V", "VCAP", "GND", note="VCAP (98)")
c.part("FB5", "Device:FerriteBead_Small", "220R@100MHz", FB, "C80165", {1: "+3V3", 2: "VDDA"},
       "VDDA separate path from VDD (AN5711 §2.1.1)")
c.C("C48", "1µF 50V", "VDDA", "GND", note="VDDA (22)")
c.C("C49", "100nF", "VDDA", "GND", note="VDDA (22)")
c.C("C50", "1µF 50V", "VDDA", "GND", note="VREF+ (21)")
c.C("C51", "100nF", "VDDA", "GND", note="VREF+ (21)")
c.C("C52", "100nF", "NRST", "GND", note="At the NRST pin")
c.part("D10", "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714", {1: "NRST", 3: "GND", 8: "GND"},
       "ESD of NRST, which reaches the debug connector: one channel of the array of the PHY lines (one BOM line less)")
c.R("R45", "10k", "BOOT0", "GND", note="BOOT0 low: boot from flash")
c.part("SW1", "Switch:SW_Push", "BOOT", "Bornier:SW_XKB_TS-1187A", "C318884", {1: "+3V3", 2: "BOOT0"},
       "XKB TS-1187A-B-A-B, 5.1 x 5.1 mm: hold it during a reset or power-up to start the system bootloader. "
       "Footprint to draw from the datasheet")
c.R("R46", "1k", "+3V3", "LED_A")
c.part("D11", "Device:LED", "green MCU", LED0603, LED_G, {2: "LED_A", 1: "LED_MCU"},
       "PC13 sinks the current (VBAT domain: no source)")
for ref, a, b in (("R47", "Q_SCK", "ESC_SCK"), ("R48", "Q_SCS", "ESC_SCS"), ("R49", "Q_SIO0", "ESC_SIO0"),
                  ("R50", "Q_SIO1", "ESC_SIO1"), ("R51", "Q_SIO2", "ESC_SIO2"), ("R52", "Q_SIO3", "ESC_SIO3")):
    c.R(ref, "49.9", a, b, note="Series termination of the OCTOSPI, at the MCU")

c.block("Debug: Tag-Connect TC2030 (legged footprint), SWD + SWO + reset")
c.part("J5", "Connector:Conn_ARM_SWD_TagConnect_TC2030", "TC2030", "Connector:Tag-Connect_TC2030-IDC-FP_2x03_P1.27mm_Vertical",
       "", {1: "+3V3", 2: "SWDIO", 3: "NRST", 4: "SWCLK", 5: "GND", 6: "SWO"},
       "Footprint only, nothing to buy: J-Link through the TC2030-CTX cable; debug only")

# --------------------------------------------------------------------------------------------
# Motion: 4 drive ports and 4 encoder ports on shielded RJ45 without magnetics, probe input.
# One dual RJ45 per axis: port A (unit A, drive sheet) is the drive, port B (unit B, encoder sheet) the
# encoder. Eight single jacks did not fit on the 150 mm edge with room between their shield legs.
RJ45X2 = ("Bornier:RJ45x2_Shielded", "HC-WK88-H132-1X2-55B", "Bornier:RJ45x2_HongCheng_HC-WK88-H132-1X2-55B",
          "C7501828")
SOD323 = "Diode_SMD:D_SOD-323"


class Refs:
    """Next free reference per prefix, for the repeated blocks below."""
    def __init__(self, **start):
        self.n = dict(start)

    def __call__(self, prefix):
        self.n[prefix] += 1
        return f"{prefix}{self.n[prefix] - 1}"


ref = Refs(R=54, C=53, D=12, U=10, J=6, Q=1, JP=1, SW=2)
# 1x3 through-hole header (PZ254V-11-03P, C2937625; 3.6 x 8.7 mm against 7.5 x 8.3 for the SMD one):
# encoder supply selector, exclusive by construction, and Modbus termination (third position parks the shunt)
HDR3 = "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical"
HDR3_LCSC = "C2937625"
# 4-position half-pitch DIP switch for the encoder terminations: CTS 218-4LPSTR (C358628), rated 100 mA /
# 50 VDC non-switching (25 mA / 24 VDC switching: set it with the encoder off); a terminated RS-422 pair
# carries 20 to 42 mA. KiCad footprint: rows 7.62 mm and pitch 1.27 mm as the CTS land pattern, pads
# 0.76 mm wide instead of 0.51 (0.51 mm left between pads).
DIP4 = "Button_Switch_SMD:SW_DIP_SPSTx04_Slide_KingTek_DSHP04TS_W7.62mm_P1.27mm"


def limited_supply(vs, out, rcl, note):
    """TPS1H000 high-side switch: always on, current limit by rcl, auto-retry.

    DIAG_EN low: open-load detection off (it lit the fault output on an empty port); the current
    limit and thermal protections stay active (TPS1H000-Q1 Table 6-3). FAULT left open."""
    u = ref("U")
    c.part(u, "Bornier:TPS1H000", "TPS1H000AQDGNRQ1", None, "C2653764",
           {8: vs, 7: out, 1: "+3V3", 2: "GND", 5: f"{u}_DLY", 4: f"{u}_CL", 6: "GND", 9: "GND"},
           note)
    c.R(ref("R"), "10k", f"{u}_DLY", "+3V3", note="DELAY pulled up: auto-retry in current limit")
    c.R(ref("R"), rcl, f"{u}_CL", "GND", note="I(limit) = 0.8 V x 600 / R(CL)")
    c.C(ref("C"), "100nF", vs, "GND")
    c.C(ref("C"), "1µF 50V", vs, "GND", note="Local reserve for the fast trip (< 1 us)")
    c.C(ref("C"), "1µF 50V", out, "GND", fp=C0603)
    return u


c.block("Drives: STEP/DIR RS-422, ENA open drain, ALM optocoupler, VIN OUT for the drive I/O")
U_DRV24 = limited_supply("+VIN", "+VIN_OUT", "1k", "VIN OUT: supply of the drive I/O, probe and relay coil, 480 mA limit")
# One repeated sheet per axis: no part serves two axes (a part shared by two blocks has a place in neither).
# The references of the quad driver and its capacitor that served two axes before go to the driver of the
# first axis of each pair; the others take numbers of their own, so that no other reference moves.
DRIVER_REFS = [("U11", "C56"), ("U300", "C320"), ("U16", "C57"), ("U301", "C321")]
for k in range(2):
    ref("U"), ref("C")          # U11/C56, U16/C57: taken by DRIVER_REFS
    a0, a1 = 2 * k, 2 * k + 1
    for n in (a0, a1):
        c.group(f"drv{n}")
        u, cap = DRIVER_REFS[n]
        c.part(u, "Bornier:SN75ALS191", "SN75ALS191DR", None, "C2871261",
               {2: f"STEP{n}", 8: f"STEP{n}_P", 7: f"STEP{n}_N", 3: f"DIR{n}", 6: f"DIR{n}_P", 5: f"DIR{n}_N",
                1: "+5V", 4: "GND"},
               "Dual RS-422 driver, 5 V, 0/+70 °C (no dual driver for -40/+85 °C in stock): STEP and DIR of "
               "this axis only")
        c.C(cap, "100nF", "+5V", "GND")
        for sig in (f"STEP{n}", f"DIR{n}"):
            c.R(ref("R"), "10k", sig, "GND", note="Low while the MCU pin is not configured: no step at reset")
        q = ref("Q")
        c.part(q, "Transistor_FET:AO3400A", "AO3422", "Package_TO_SOT_SMD:SOT-23", "C37130",
               {1: f"ENA{n}", 2: "GND", 3: f"ENA{n}_OUT"},
               "55 V, 2 A, 0.2 ohm: sinks the servo-on input; survives ENA shorted to +VIN_OUT (480 mA)")
        c.R(ref("R"), "100k", f"ENA{n}", "GND", note="Drive disabled at reset")
        c.R(ref("R"), "1k", f"ENA{n}", f"ENA{n}_LA")
        c.part(ref("D"), "Device:LED", "green ENA", LED0603, LED_G, {2: f"ENA{n}_LA", 1: "GND"},
               "On while the MCU commands ENA; nothing on the drive line")
        c.part(ref("D"), "Device:D_TVS", "SMBJ33CA", SMB, "C78420", {1: f"ENA{n}_OUT", 2: "GND"},
               "Clamps the inductive kick of a relay-type drive input (36.7-53.3 V, below the 55 V of the FET) "
               "and ESD; to GND, so that nothing can feed the drive input when the board is off")
        u = ref("U")
        c.part(u, "Isolator:LTV-357T", "LTV-357T-C", "Package_SO:SO-4_4.4x3.6mm_P2.54mm", "C119091",
               {1: f"ALM{n}_LED", 2: f"ALM{n}_IN", 4: f"ALM{n}", 3: "GND"})
        c.R(ref("R"), "4.7k", "+VIN_OUT", f"ALM{n}_R", fp=R1206,
            note="4.5 mA at 24 V; 1.1 mA at 10 V with 1 V across the drive output (opto CTR 50 %: 0.55 mA, 0.33 mA needed)")
        c.part(ref("D"), "Device:LED", "red ALM", LED0603, LED_R, {2: f"ALM{n}_R", 1: f"ALM{n}_LED"},
               "On while current flows in the alarm input")
        c.part(ref("D"), "Device:D", "1N4148WS", SOD323, "C2128", {1: f"ALM{n}_R", 2: f"ALM{n}_IN"},
               "Reverse protection of both LEDs")
        c.R(ref("R"), "10k", f"ALM{n}", "+3V3")
        sym, val, fp, lcsc = RJ45X2
        c.part(ref("J"), sym, val, fp, lcsc,
               {"A1": f"STEP{n}_P", "A2": f"STEP{n}_N", "A3": f"DIR{n}_P", "A6": f"DIR{n}_N", "A4": f"ENA{n}_OUT",
                "A5": f"ALM{n}_IN", "A7": "+VIN_OUT", "A8": "GND", "SH": "CHASSIS",
                "B1": f"ENC{n}_AP", "B2": f"ENC{n}_AN", "B3": f"ENC{n}_BP", "B6": f"ENC{n}_BN", "B4": f"ENC{n}_ZP",
                "B5": f"ENC{n}_ZN", "B7": f"VENC{n}", "B8": "GND"},
               "Axis port pair. A, drive: 1-2 STEP, 3-6 DIR, 4-5 ENA/ALM, 7-8 VIN OUT/0 V. B, encoder: 1-2 A, "
               "3-6 B, 4-5 Z, 7-8 supply/0 V. Supply always on 7-8: an Ethernet or encoder cable plugged by "
               "mistake shorts 7-8 into the current limit", also=f"enc{n}")
        c.part(ref("U"), "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714",
               {1: f"STEP{n}_P", 2: f"STEP{n}_N", 4: f"DIR{n}_P", 5: f"DIR{n}_N", 3: "GND", 8: "GND"},
               "ESD of STEP and DIR at the RJ45, flow-through")

c.block("Encoders: RS-422, TTL or HTL, differential or single-ended, 5 V or VIN supply")
# Each line: series 3.3 k (HTL current into the clamp), Schottky clamp to +5V and GND, symmetric
# bias 4.7 k / 4.7 k to +5V at the receiver input. + lines pulled up to the encoder supply
# (open-collector encoders). 120 ohm termination per pair through a DIP switch (RS-422 only).
for n in range(4):
    c.group(f"enc{n}")          # one repeated sheet per encoder port
    venc, vsel = f"VENC{n}", f"VSEL{n}"
    jp = ref("JP")
    c.part(jp, "Connector_Generic:Conn_01x03", "ENC 5V|VIN", HDR3,
           HDR3_LCSC, {1: "+5V", 2: vsel, 3: "+VIN"}, "Shunt on 1-2: 5 V encoder, on 2-3: VIN (12 or 24 V); none: no supply")
    c.part(ref("D"), "Device:D_Schottky", "SS56B", SMB, "C14651", {1: f"VSD{n}", 2: vsel},
           "Blocks an external voltage on the encoder supply from flowing back through the TPS1H000, "
           "whichever the jumper position")
    limited_supply(f"VSD{n}", venc, "2.2k", "Encoder supply, 218 mA limit")
    u = ref("U")
    rx = {}
    pins = {16: "+3V3", 8: "GND", 4: "+3V3", 12: "GND"}
    for ch, (p, m, y) in zip("ABZ", ((2, 1, 3), (6, 7, 5), (10, 9, 11))):
        pins.update({p: f"ENC{n}_{ch}P_R", m: f"ENC{n}_{ch}N_R", y: f"ENC{n}_{ch}"})
    c.part(u, "Interface:AM26LV32xD", "AM26LV32EIDR", "Package_SO:SOIC-16_3.9x9.9mm_P1.27mm", "C527448", pins,
           "Pin for pin AM26LV32 with +-15 kV IEC ESD; 3.3 V supply, 5 V tolerant inputs, common mode -0.3 to 5.5 V; channel 4 unused")
    c.C(ref("C"), "100nF", "+3V3", "GND")
    for ch in "ABZ":
        for pol in "PN":
            line, node = f"ENC{n}_{ch}{pol}", f"ENC{n}_{ch}{pol}_R"
            if pol == "P":
                c.R(ref("R"), "4.7k", line, venc, fp=R1206, note="Pull-up for open-collector encoders")
            c.R(ref("R"), "3.3k", line, node, fp=R1206)
            c.R(ref("R"), "4.7k", node, "+5V")
            c.R(ref("R"), "4.7k", node, "GND")
            c.part(ref("D"), "Diode:BAT54S", "BAT54S", "Package_TO_SOT_SMD:SOT-23", "C12765",
                   {1: "GND", 2: "+5V", 3: node}, "Clamp to 0..5 V and ESD")
        c.R(ref("R"), "120", f"ENC{n}_{ch}T", f"ENC{n}_{ch}N", fp=R0603)
    # switch k joins pins k and 9 - k; position 4 unused
    c.part(ref("SW"), "Bornier:SW_DIP_x04_Split", "TERM A B Z", DIP4, "C358628",
           {k + 1: f"ENC{n}_{ch}P" for k, ch in enumerate("ABZ")} | {8 - k: f"ENC{n}_{ch}T" for k, ch in enumerate("ABZ")},
           "On: 120 ohm termination of the pair (RS-422 only). Set with the encoder supply off")
    # the encoder port is port B of the axis dual RJ45, created with the drive port above

c.block("Probe: NPN or dry contact, fast optocoupler to the timer capture")
u = ref("U")
c.part(u, "Bornier:TLP2361", "TLP2361", None, "C107626", {1: "PROBE_LED", 3: "PROBE_IN", 6: "+3V3", 5: "PROBE", 4: "GND"},
       "Inverting: PROBE low while the probe conducts")
c.C(ref("C"), "100nF", "+3V3", "GND")
c.R(ref("R"), "4.7k", "+VIN_OUT", "PROBE_R", fp=R1206,
    note="With the next one, 2.35 k: 1.4 mA in the opto at 10 V with a 2 V NPN drop (TLP2361: 1.3 mA max threshold)")
c.R(ref("R"), "4.7k", "+VIN_OUT", "PROBE_R", fp=R1206, note="11.3 mA at 30 V, 0.15 W each")
c.R(ref("R"), "4.7k", "PROBE_LED", "PROBE_IN", note="Shunt: a leakage below about 0.3 mA (two-wire sensor) stays below the threshold")
c.part(ref("D"), "Device:LED", "green PROBE", LED0603, LED_G, {2: "PROBE_R", 1: "PROBE_LED"},
       "On while the probe conducts")
c.part(ref("D"), "Device:D", "1N4148WS", SOD323, "C2128", {1: "PROBE_R", 2: "PROBE_IN"},
       "Reverse protection of both LEDs")

# --------------------------------------------------------------------------------------------
c.block("Local bus: HE10 2x17 ribbon to the extension modules")
# Pinout of the ribbon (conductor order = pin number): a ground next to SCK and between groups.
BUS_PINOUT = {1: "GND", 2: "RB_SCK", 3: "GND", 4: "RB_MOSI", 5: "BUS_MISO", 6: "GND", 7: "RB_LATCH",
              8: "RB_OE", 9: "GND", 10: "BUS_IRQ", 11: "BUS_SDA", 12: "BUS_SCL", 13: "GND",
              14: "RB_CS0", 15: "RB_CS1", 16: "RB_CS2", 17: "GND", 18: "RB_CS3", 19: "RB_CS4", 20: "RB_CS5",
              21: "GND", 22: "RB_CS6", 23: "RB_CS7", 24: "RB_CS8", 25: "GND", 26: "RB_CS9", 27: "RB_CS10",
              28: "RB_CS11", 29: "GND", 30: "+3V3_BUS", 31: "+3V3_BUS", 32: "GND", 33: "GND", 34: "GND"}
c.part(ref("J"), "Connector_Generic:Conn_02x17_Odd_Even", "LOCAL BUS", "Connector_IDC:IDC-Header_2x17_P2.54mm_Vertical",
       "C20920", BUS_PINOUT, "Shrouded, keyed IDC header (no ejector in stock at JLC)")
u = ref("U")
c.part(u, "Bornier:TPS2553", "TPS2553DBVR", None, "C55266",
       {1: "+3V3", 3: "+5V", 5: f"{u}_ILIM", 6: "+3V3_BUS", 4: f"{u}_FLT", 2: "GND"},
       "3.3 V of the ribbon, 505-616 mA limit; EN on +5V: the ribbon is off on USB alone")
c.R(ref("R"), "47k", f"{u}_ILIM", "GND", note="I(OS) = 23950 / R(kohm)^0.977 = 556 mA")
c.C(ref("C"), "100nF", "+3V3", "GND")
c.C(ref("C"), "10µF 25V", "+3V3_BUS", "GND", fp=C0805)
c.R(ref("R"), "1k", "+3V3", f"{u}_LED")
c.part(ref("D"), "Device:LED", "red FAULT", LED0603, "C2286", {2: f"{u}_LED", 1: f"{u}_FLT"},
       "On when the ribbon supply is in current limit")
for sig in [f"CS{i}" for i in range(12)] + ["LATCH", "OE"]:
    c.R(ref("R"), "10k", f"BUS_{sig}", "+3V3", note="Inactive (high) while the MCU pin is not configured")
for sig in [f"CS{i}" for i in range(12)] + ["SCK", "MOSI", "LATCH", "OE"]:
    c.R(ref("R"), "49.9", f"BUS_{sig}", f"RB_{sig}", note="Series termination at the source")
for sig in ("SCK", "MOSI", "LATCH"):     # multipoint edges: 2 x 49.9 in parallel = 25 ohm
    c.R(ref("R"), "49.9", f"BUS_{sig}", f"RB_{sig}", note="In parallel with the first: 25 ohm, first step above 2 V")
c.R(ref("R"), "10k", "BUS_IRQ", "+3V3", note="IRQ: wired-OR of open-drain outputs")
c.R(ref("R"), "100k", "BUS_MISO", "GND", note="MISO is tri-stated when no module is selected")
c.R(ref("R"), "100k", "BUS_SCK", "GND", note="SCK low while the MCU pin is not configured (reset, bootloader): mode 0 idle")
c.R(ref("R"), "100k", "BUS_MOSI", "GND", note="MOSI defined while the MCU pin is not configured")
c.R(ref("R"), "2.2k", "BUS_SDA", "+3V3", note="I2C at 100 kHz, ribbon and 12 modules: rise < 1 us")
c.R(ref("R"), "2.2k", "BUS_SCL", "+3V3")
# ESD of every ribbon signal, at the header: the board has no enclosure and the ribbon is plugged by hand
for group in (("RB_SCK", "RB_MOSI", "BUS_MISO", "RB_LATCH"), ("RB_OE", "BUS_IRQ", "BUS_SDA", "BUS_SCL"),
              ("RB_CS0", "RB_CS1", "RB_CS2", "RB_CS3"), ("RB_CS4", "RB_CS5", "RB_CS6", "RB_CS7"),
              ("RB_CS8", "RB_CS9", "RB_CS10", "RB_CS11")):
    c.part(ref("U"), "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714",
           dict(zip((1, 2, 4, 5), group)) | {3: "GND", 8: "GND"}, "ESD of the ribbon lines, at the HE10, flow-through")

# --------------------------------------------------------------------------------------------
c.block("Spindle / laser: 0-10 V, PWM 5 V, enable and direction open drain")
c.part(ref("J"), TB4[0], "SPINDLE A", TB4[1], TB4[2], {1: "SP_EN", 2: "GND", 3: "SP_AOUT", 4: "SP_DIR"},
       "EN, 0 V, 0-10 V, DIR: the whole wiring of a VFD on one plug")
c.part(ref("J"), TB4[0], "SPINDLE B", TB4[1], TB4[2], {1: "+VIN_OUT", 2: "GND", 3: "SP_PWM"},
       "VIN OUT (supply of a relay coil switched by EN or DIR), 0 V, PWM, pole 4 unused")
# 0-10 V: DAC (0-3.3 V) x 3.13, rail-to-rail op amp supplied by +VIN: 10 V into 10 k from 10.9 V of supply,
# into 5 k from 11.2 V. 42 V absolute maximum, the limit already accepted for the TPS1H000.
u = ref("U")
c.part(u, "Bornier:OPAMP_DUAL", "OPA2990IDR", None, "C2058283",
       {3: "SP_DAC", 2: "SP_FB", 1: "SP_OA", 5: "GND", 6: "SP_UNUSED", 7: "SP_UNUSED", 8: "+VIN", 4: "GND"},
       "40 V (42 V absolute), rail-to-rail input and output, 0.3 V headroom at 5 mA; "
       "second half wired as a grounded follower")
c.C(ref("C"), "100nF", "+VIN", "GND")
c.C(ref("C"), "1µF 50V", "+VIN", "GND", fp=C0603)
c.R(ref("R"), "1k", "SPINDLE_AOUT", "SP_DAC", note="DAC output filter with the next capacitor")
c.C(ref("C"), "100nF", "SP_DAC", "GND")
c.R(ref("R"), "100k", "SP_DAC", "GND", note="0 V while the DAC pin is not configured (reset, bootloader)")
c.R(ref("R"), "10k", "SP_AOUT", "SP_FB", note="Gain 1 + 10/4.7 = 3.13, fed back after the 120 ohm; 0.7 mA at 10 V")
c.C(ref("C"), "470pF", "SP_OA", "SP_FB", note="Closes the loop at high frequency: stable with the cable capacitance")
c.R(ref("R"), "4.7k", "SP_FB", "GND")
c.R(ref("R"), "120", "SP_OA", "SP_AOUT", fp=R0603, note="Isolates the cable capacitance; current sense of the next PNP")
c.part(ref("Q"), "Transistor_BJT:SS8550", "SS8550", "Package_TO_SOT_SMD:SOT-23", "C8542",
       {2: "SP_OA", 1: "SP_AOUT", 3: "SP_FB"},
       "25 V VCEO, 40 V VCBO: with 120 ohm from base to emitter it holds the 30 V supply. "
       "Current limit: above 0.6 V across the 120 ohm (5 mA, 4 mA hot) it feeds SP_FB and pulls the output down; "
       "an output shorted to 0 V draws 5 mA (op amp: 80 mA unlimited). Off below 3 mA (load 5 k and more)")
c.part(ref("D"), "Device:D_TVS", "SMF15A", "Diode_SMD:D_SOD-123F", "C123802", {1: "SP_AOUT", 2: "GND"},
       "ESD and surge on the 0-10 V output")
# PWM 5 V push-pull, TTL input threshold so the 3.3 V MCU drives it
u = ref("U")
c.part(u, "74xGxx:74AHCT1G125", "SN74AHCT1G125DBVR", "Package_TO_SOT_SMD:SOT-23-5", "C7484",
       {1: "GND", 2: "SPINDLE_PWM", 3: "GND", 4: "SP_PWM_B", 5: "+5V"}, "5 V buffer for laser TTL inputs")
c.C(ref("C"), "100nF", "+5V", "GND")
c.R(ref("R"), "100k", "SPINDLE_PWM", "GND", note="Laser off while PB15 is not configured")
c.R(ref("R"), "120", "SP_PWM_B", "SP_PWM_C", fp=R0603, note="With the next one, 240 ohm: 20 mA into a short (74AHCT: 25 mA)")
c.R(ref("R"), "120", "SP_PWM_C", "SP_PWM", fp=R0603)
c.part(ref("D"), "Power_Protection:TPD4E05U06DQA", "TPD4E05U06DQAR", None, "C138714",
       {1: "SP_PWM_C", 3: "GND", 8: "GND"},
       "ESD between the two 120 ohm (one channel of the array of the PHY lines); a miswire to VIN burns the outer "
       "120 ohm (fuse) and may short the array, not the buffer")
c.R(ref("R"), "2.2k", "SP_PWM_B", "SP_PWM_LA", note="1.3 mA: the buffer stays below 25 mA into a shorted output")
c.part(ref("D"), "Device:LED", "green PWM", LED0603, LED_G, {2: "SP_PWM_LA", 1: "GND"},
       "Brightness follows the duty cycle")
# EN and DIR: open drain; LED on the gate side, so that nothing reaches the field line
for sig, net in (("SPINDLE_EN", "SP_EN"), ("SPINDLE_DIR", "SP_DIR")):
    c.part(ref("Q"), "Transistor_FET:AO3400A", "AO3422", "Package_TO_SOT_SMD:SOT-23", "C37130",
           {1: sig, 2: "GND", 3: net}, "55 V open drain: VFD input to its common, or laser gate with its pull-up")
    c.R(ref("R"), "100k", sig, "GND", note="Off at reset")
    c.R(ref("R"), "1k", sig, f"{net}_LA")
    c.part(ref("D"), "Device:LED", f"green {sig[8:]}", LED0603, LED_G, {2: f"{net}_LA", 1: "GND"},
           "On while the MCU commands the output")
    c.part(ref("D"), "Device:D_TVS", "SMBJ33CA", SMB, "C78420", {1: net, 2: "GND"},
           "Clamps the kick of a relay or solenoid coil driven without a flyback diode (36.7-53.3 V, "
           "below the 55 V of the FET) and ESD")

# --------------------------------------------------------------------------------------------
c.block("Modbus RS-485, isolated: Bornier is the master of the line")
u = ref("U")
c.part(u, "Bornier:CA-IS3092W", "CA-IS3092W", None, "C2890051",
       {1: "+3V3", 2: "GND", 7: "GND", 8: "GND", 3: "MB_RX", 4: "GND", 5: "MB_DE", 6: "MB_TX",
        16: "VISO", 10: "GNDISO", 9: "GNDISO", 15: "GNDISO", 12: "MB_A", 13: "MB_B"},
       "Isolated RS-485 with its own DC-DC; VCC 3.3 V so VISO = 3.3 V (SEL to GNDB). Functional isolation (breaks ground loops): the 1 nF 2 kV to the chassis voids the 5 kV rating")
c.C(ref("C"), "100nF", "+3V3", "GND")
c.C(ref("C"), "10µF 25V", "+3V3", "GND", fp=C0805)
c.C(ref("C"), "100nF", "VISO", "GNDISO")
c.C(ref("C"), "10µF 25V", "VISO", "GNDISO", fp=C0805)
c.C(ref("C"), "1nF 2kV", "GNDISO", "CHASSIS", fp=C1206, note="Gives the PSM712 an HF return to the chassis")
c.R(ref("R"), "10k", "MB_DE", "GND", note="Driver off while the MCU pin is not configured")
c.R(ref("R"), "120", "VISO", "MB_BA", fp=R0603, note="Line bias, 2 x 120 per side: 370 mV idle with both terminations")
c.R(ref("R"), "120", "MB_BA", "MB_A", fp=R0603)
c.R(ref("R"), "120", "MB_B", "MB_BB", fp=R0603)
c.R(ref("R"), "120", "MB_BB", "GNDISO", fp=R0603)
c.part(ref("JP"), "Jumper:Jumper_3_Open", "TERM", HDR3, HDR3_LCSC, {1: "MB_T", 2: "MB_B"},
       "Shunt on 1-2 when Bornier is at an end of the line; on 2-3: parked")
c.R(ref("R"), "120", "MB_A", "MB_T", fp=R0603)
c.part(ref("D"), "Diode:SM712_SOT23", "PSM712-LF-T7", "Package_TO_SOT_SMD:SOT-23", "C32677",
       {1: "MB_A", 2: "MB_B", 3: "GNDISO"}, "-7/+12 V clamp, the RS-485 common-mode range")
c.part(ref("J"), TB4[0], "MODBUS", TB4[1], TB4[2], {1: "CHASSIS", 2: "GNDISO", 3: "MB_A", 4: "MB_B"},
       "Shield, common, D1 (A, positive at idle), D0 (B)")
for sig, colour in (("MB_TX", "TX"), ("MB_RX", "RX")):
    c.R(ref("R"), "1k", "+3V3", f"{sig}_LA")
    c.part(ref("D"), "Device:LED", f"green {colour}", LED0603, LED_G, {2: f"{sig}_LA", 1: sig},
           "Flashes with the start and zero bits")

# --------------------------------------------------------------------------------------------
c.block("Safety: emergency stop state, external watchdog")
# The emergency stop chain is wired outside Bornier; this input only reads its state.
u = ref("U")
c.part(u, "Isolator:LTV-357T", "LTV-357T-C", "Package_SO:SO-4_4.4x3.6mm_P2.54mm", "C119091",
       {1: "ESTOP_LED", 2: "GND", 4: "ESTOP_IN", 3: "GND"},
       "ESTOP_IN low while the chain is closed: a broken wire reads as a stop")
c.R(ref("R"), "4.7k", "ESTOP_V", "ESTOP_R", fp=R1206, note="With the next one, 2.35 k: 8.7 mA at 24 V, 11.3 mA at 30 V")
c.R(ref("R"), "4.7k", "ESTOP_V", "ESTOP_R", fp=R1206, note="0.15 W each at 30 V")
c.part(ref("D"), "Device:LED", "green ESTOP OK", LED0603, LED_G, {2: "ESTOP_R", 1: "ESTOP_LED"},
       "On while the chain is closed")
c.R(ref("R"), "1k", "ESTOP_LED", "GND",
    note="Shunts 1.0-1.4 mA: off below 5 V, 1.1 mA in the opto from 9.5 V (12 V supply); "
         "at 24 V, IEC 61131-2 type 3 (3.1 mA at 11 V)")
c.part(ref("D"), "Device:D", "1N4148WS", SOD323, "C2128", {1: "ESTOP_R", 2: "GND"},
       "Reverse protection of both LEDs")
c.R(ref("R"), "10k", "ESTOP_IN", "+3V3")
c.part(ref("J"), TB4[0], "ESTOP | PROBE", TB4[1], TB4[2], {1: "+VIN_OUT", 2: "GND", 3: "ESTOP_V", 4: "PROBE_IN"},
       "VIN OUT (dry contact of the chain, probe supply), 0 V, chain state (VIN = run), probe input")
# External watchdog: resets the MCU, whose reset state turns every output off through its pull resistor.
u = ref("U")
c.part(u, "Power_Supervisor:TPS3823-xxDBV", "TPS3828-33DBVR", "Package_TO_SOT_SMD:SOT-23-5", "C20032",
       {5: "+3V3", 2: "GND", 4: "WDI", 1: "NRST"},
       "Timeout 0.9-2.5 s, 200 ms open-drain reset; WDI left floating (pin not configured) disables it")
c.C(ref("C"), "100nF", "+3V3", "GND")
c.R(ref("R"), "1k", "+3V3", "RST_LA")
c.part(ref("D"), "Device:LED", "red RESET", LED0603, LED_R, {2: "RST_LA", 1: "NRST"},
       "On during any reset: watchdog, supervisor, debugger")
