# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Draw the base board schematic from circuit.py, one sheet per functional block, then check it.

Usage: python schematic.py   ->  ../kicad/base.kicad_sch, followed by ERC and netlist check.
"""
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "..", "..", "lib"))
sys.path.insert(0, HERE)
from kicadgen.schematic import Project  # noqa: E402
from kicadgen.check import check  # noqa: E402
from circuit import c  # noqa: E402

KICAD = os.path.join(HERE, "..", "kicad")
# Global labels that will find their other end once the remaining sheets are drawn.
PENDING_ERC = ()
# Accepted ERC violations, each with its reason.
WAIVED_ERC = (
    # The two VCAP pins of the STM32 are both regulator outputs and are tied together, as AN5711 asks.
    ("pin_to_pin", "Symbol U9 Pin 98 [VCAP, Power output"),
    # The library symbol of the TPS3823 family draws RESET push-pull; the TPS3828 fitted is open drain.
    ("pin_to_pin", "Pin 1 [~{RESET}, Output"),
)


def vpart(s, ref, x, top, label_dx=2.54, rot=0):
    """Vertical two-pin part whose upper pin sits at (x, top)."""
    s.place(ref, x, top + 3.81, rot=rot, ref_at=(x + label_dx, top + 2.54), val_at=(x + label_dx, top + 5.08))


def hpart(s, ref, x, y, rot=90):
    """Horizontal two-pin part centred on (x, y)."""
    s.place(ref, x, y, rot=rot, ref_at=(x - 2.54, y - 7.62), val_at=(x - 2.54, y - 5.08))


def power(prj):
    s = prj.sheet("Power", "power.kicad_sch", "12 or 24 V input, 5 V and 3.3 V bucks, USB")
    s.text("POWER", 20.32, 17.78, 2.54, True)
    y0 = 76.2                       # protected supply line (+VIN)
    y5 = y0 + 5.08                  # 5 V line

    # --- supply input and protection -----------------------------------------------------------
    s.text("Logic supply VIN: 12 V or 24 V, 10.8 to 30 V (24 V: IEC 61131-2, 19.2 to 30 V).\n"
           "Fuse, bidirectional TVS, reverse polarity diode.\n"
           "Condition of use: dedicated supply in the same cabinet, short wiring\n"
           "(no 0.5 kV / 2 ohm surge immunity, see ../sim/README.md).", 20.32, y0 - 25.4)
    s.place("J1", 30.48, y0 + 2.54, mirror="y", ref_at=(22.86, y0 - 5.08), val_at=(22.86, y0 - 2.54))
    jx, jy2 = s.P("J1", 2)
    s.w("GND", (jx, jy2), (jx + 10.16, jy2))
    s.rail("GND", jx + 10.16, jy2, drop=5.08)
    fx, fy = s.P("J1", 3)
    s.w("CHASSIS", (fx, fy), (fx + 2.54, fy), (fx + 2.54, fy + 12.7))
    s.glabel("CHASSIS", fx + 2.54, fy + 12.7, 0, "passive")
    hpart(s, "F1", 48.26, y0)
    s.w("VIN_RAW", s.P("J1", 1), s.P("F1", 1))
    s.label("VIN_RAW", 38.1, y0)
    s.place("D1", 60.96, y0 + 7.62, rot=270, ref_at=(63.5, y0 + 6.35), val_at=(63.5, y0 + 8.89))
    hpart(s, "D2", 73.66, y0, rot=180)
    s.w("VIN_F", s.P("F1", 2), (60.96, y0), s.P("D2", 2))
    s.w("VIN_F", (60.96, y0), s.P("D1", 1))
    s.label("VIN_F", 53.34, y0)
    s.rail("GND", *s.P("D1", 2))

    # --- +VIN node: bulk and input capacitors, UVLO divider, RT ---------------------------------
    s.rail("+VIN", 83.82, y0, drop=5.08)
    s.power("PWR_FLAG", 81.28, y0 - 5.08)
    s.w("+VIN", (81.28, y0 - 5.08), (83.82, y0 - 5.08))
    for ref, x in (("C1", 81.28), ("C2", 95.25), ("C3", 109.22)):
        vpart(s, ref, x, y0 + 2.54)
        s.w("+VIN", (x, y0), s.P(ref, 1))
        s.rail("GND", *s.P(ref, 2))
    cx = 167.64                     # U1 pins: VIN y0, RT y0+5.08, EN y0+12.7 (x-10.16)
    s.place("U1", cx, y0 + 5.08, ref_at=(cx - 5.08, y0 - 6.35), val_at=(cx - 5.08, y0 - 3.81))
    s.w("+VIN", s.P("D2", 1), s.P("U1", 2))
    # UVLO divider R1 + R300 over R2 // R308, EN taken at the junction
    for k, ref in enumerate(("R1", "R300")):
        vpart(s, ref, 124.46, y0 + 7.62 * k)
    vpart(s, "R2", 124.46, y0 + 17.78)
    vpart(s, "R308", 116.84, y0 + 17.78, label_dx=-6.35)
    en = s.P("U1", 3)
    ye = y0 + 16.51
    s.w("EN", s.P("R300", 2), s.P("R2", 1))
    s.w("EN", (124.46, ye), (116.84, ye), s.P("R308", 1))
    s.w("EN", (124.46, ye), (139.7, ye), (139.7, en[1]), en)
    s.label("EN", 144.78, en[1])
    s.rail("GND", *s.P("R2", 2))
    s.rail("GND", *s.P("R308", 2))
    s.quiet.add("EN1")
    # RT = R3 + R301, in line
    s.place("R3", 149.86, y0 + 5.08, rot=270, ref_at=(149.86, y0 + 1.27), val_at=(149.86, y0 + 8.89))
    s.place("R301", 142.24, y0 + 5.08, rot=270, ref_at=(142.24, y0 + 1.27), val_at=(142.24, y0 + 8.89))
    s.w("RT", s.P("R3", 1), s.P("U1", 4))
    s.label("RT", 154.305, y0 + 5.08)
    s.w("GND", s.P("R301", 2), (136.65, y0 + 5.08))
    s.power("GND", 136.65, y0 + 5.08, 270, show=False)
    s.quiet.add("RT1")
    gx, gy = s.P("U1", 7)
    s.rail("GND", gx, gy, drop=5.08)
    s.w("GND", s.P("U1", 9), (s.P("U1", 9)[0], gy + 2.54), (gx, gy + 2.54))

    # --- switching node, compensation, output ----------------------------------------------------
    boot, sw, comp, fb = s.P("U1", 1), s.P("U1", 8), s.P("U1", 6), s.P("U1", 5)
    s.place("C4", 186.69, y0 + 1.27, ref_at=(189.23, y0 - 3.81), val_at=(189.23, y0 - 1.27))
    s.w("BOOT", boot, (180.34, boot[1]), (180.34, s.P("C4", 1)[1]), s.P("C4", 1))
    vpart(s, "R6", 191.77, y0 + 10.16)
    vpart(s, "C7", 191.77, y0 + 22.86)
    s.w("COMP", comp, (191.77, comp[1]), s.P("R6", 1))
    s.label("COMP", 186.69, comp[1])
    s.label("BOOT", 180.34, boot[1] - 2.54)
    s.w("COMPZ", s.P("R6", 2), s.P("C7", 1))
    s.label("COMPZ", 191.77, y0 + 20.32)
    vpart(s, "C312", 191.77, y0 + 30.48)
    s.quiet.add("COMPY")
    s.rail("GND", *s.P("C312", 2))
    s.place("D3", 213.36, y5 + 3.81, rot=270, ref_at=(215.9, y5 + 2.54), val_at=(215.9, y5 + 5.08))
    hpart(s, "L1", 226.06, y5)
    s.w("SW5", sw, s.P("C4", 2), (213.36, y5), s.P("L1", 1))
    s.w("SW5", (213.36, y5), s.P("D3", 1))
    s.label("SW5", 203.2, y5)
    s.rail("GND", *s.P("D3", 2))
    for ref, x in (("C5", 241.3), ("C6", 256.54)):
        vpart(s, ref, x, y5 + 2.54)
        s.w("+5V", (x, y5), s.P(ref, 1))
        s.rail("GND", *s.P(ref, 2))
    vpart(s, "R4", 271.78, y5 + 2.54)
    vpart(s, "R302", 271.78, y5 + 10.16)
    vpart(s, "R5", 271.78, y5 + 20.32)
    vpart(s, "R303", 271.78, y5 + 27.94)
    s.w("+5V", (271.78, y5), s.P("R4", 1))
    s.w("FB5", s.P("R302", 2), s.P("R5", 1))
    s.quiet.update({"FB5A", "FB5B"})
    fbn = s.P("R302", 2)
    yr = y0 + 48.26
    s.w("FB5", fb, (180.34, fb[1]), (180.34, yr), (274.32, yr), (274.32, fbn[1] + 1.27), (271.78, fbn[1] + 1.27))
    s.label("FB5", 220.98, yr)
    s.rail("GND", *s.P("R303", 2))
    s.text("VOUT = 0.8 V x (1 + (R4 + R302)/(R5 + R303)) = 5.10 V, above VBUS; fsw = 658 kHz (R3 + R301 = 147 k).\n"
           "Compensation R6, C7 taken from the passive palette, simulated (sim/README.md).\n"
           "UVLO (R1 + R300 = 200 k, R2 // R308 = 32.0 k): start 8.47 V (9.48 V worst case), stop 7.79 V.\n"
           "60 V parts throughout: the TVS clamps at 53.3 V.", 129.54, yr + 7.62)

    # --- 5 V rail, OR-ing towards the 3.3 V buck --------------------------------------------------
    hpart(s, "D4", 292.1, y5, rot=180)
    s.w("+5V", s.P("L1", 2), s.P("D4", 2))
    s.rail("+5V", 279.4, y5, drop=5.08)
    s.power("PWR_FLAG", 276.86, y5 - 5.08)
    s.w("+5V", (276.86, y5 - 5.08), (279.4, y5 - 5.08))

    # --- USB micro-B ---------------------------------------------------------------------------
    yu = y0 + 63.5
    s.text("USB micro-B: bench power (logic only) and DFU programming.\n"
           "TPD4E05U06 next to the connector, lines flow through.", 20.32, yu - 17.78)
    s.place("J2", 30.48, yu + 5.08, ref_at=(22.86, yu - 5.08), val_at=(22.86, yu - 2.54))
    # ESD array under the lines, flow-through on the board
    xe, ye = 60.96, yu + 25.4
    s.place("U2", xe, ye, ref_at=(xe + 3.81, ye - 8.89), val_at=(xe + 3.81, ye - 11.43))
    for net, jpin, epin, xv in (("USB_DP", 3, 1, xe - 17.78), ("USB_DM", 2, 2, xe - 15.24)):
        jx_, jy_ = s.P("J2", jpin)
        s.w(net, (jx_, jy_), (xe + 7.62, jy_))
        s.glabel(net, xe + 7.62, jy_, 0, "bidirectional")
        ex, ey = s.P("U2", epin)
        s.w(net, (xv, jy_), (xv, ey), (ex, ey))
    ex, ey = s.P("U2", 4)
    s.w("VBUS", (xe + 15.24, s.P("J2", 1)[1]), (xe + 15.24, ey), (ex, ey))
    x, y = s.P("J2", "SH")
    s.w("GND", (x, y), (x, y + 2.54), (s.P("J2", 5)[0], y + 2.54))
    s.rail("GND", *s.P("J2", 5), drop=5.08)
    s.rail("GND", *s.P("U2", 3))
    vb = s.P("J2", 1)
    hpart(s, "D5", 271.78, vb[1], rot=180)
    s.w("VBUS", vb, (101.6, vb[1]), s.P("D5", 2))
    # USB path switch: Q11 off while +5V is present (gate pulled to +5V), on with USB alone
    qx, qy = 284.48, vb[1] + 2.54
    s.place("Q11", qx, qy, rot=90, mirror="y", ref_at=(qx - 2.54, qy - 7.62), val_at=(qx + 2.54, qy - 7.62))
    s.w("VUSB_D", s.P("D5", 1), s.P("Q11", 2))
    gq = s.P("Q11", 1)
    s.w("QU_G", gq, (gq[0], gq[1] + 2.54), (gq[0] + 10.16, gq[1] + 2.54))
    vpart(s, "R311", gq[0], gq[1] + 2.54)
    s.rail("GND", *s.P("R311", 2))
    vpart(s, "R310", gq[0] + 10.16, gq[1] + 2.54, rot=180)
    s.w("+5V", s.P("R310", 1), (s.P("R310", 1)[0], s.P("R310", 1)[1] + 2.54))
    s.power("+5V", s.P("R310", 1)[0], s.P("R310", 1)[1] + 2.54, 180)
    s.quiet.update({"VUSB_D", "QU_G"})
    s.label("VBUS", 40.64, vb[1])
    vpart(s, "R7", 101.6, vb[1] + 2.54)
    vpart(s, "R8", 101.6, vb[1] + 12.7)
    s.w("VBUS", (101.6, vb[1]), s.P("R7", 1))
    s.w("VBUS_SENSE", s.P("R7", 2), s.P("R8", 1))
    vs = s.P("R7", 2)
    s.w("VBUS_SENSE", vs, (109.22, vs[1]))
    s.glabel("VBUS_SENSE", 109.22, vs[1], 0, "output")
    s.rail("GND", *s.P("R8", 2))
    s.text("VBUS_SENSE on PD9: 3.4 V, 5 V tolerant pin;\nan input (USART3_RX) in the bootloader.", 104.14, vb[1] + 25.4)

    # --- 3.3 V buck ----------------------------------------------------------------------------
    xn = 298.45                     # V3IN node
    s.w("V3IN", s.P("Q11", 3), (xn, vb[1]), (xn, y5))
    s.power("PWR_FLAG", xn, y5 - 5.08)
    s.w("V3IN", (xn, y5 - 5.08), (xn, y5))
    ux = 327.66
    s.place("U3", ux, y5 + 2.54, ref_at=(ux - 3.81, y5 - 6.35), val_at=(ux - 3.81, y5 - 3.81))
    vin3, en3 = s.P("U3", 3), s.P("U3", 4)
    s.w("V3IN", s.P("D4", 1), vin3)
    s.label("V3IN", 309.88, y5)
    vpart(s, "C9", 306.07, y5 + 2.54)
    s.w("V3IN", (306.07, y5), s.P("C9", 1))
    s.rail("GND", *s.P("C9", 2))
    s.w("V3IN", en3, (317.5, en3[1]), (317.5, y5))
    s.rail("GND", *s.P("U3", 1))
    sw3, fb3 = s.P("U3", 2), s.P("U3", 5)
    hpart(s, "L2", 347.98, y5)
    s.w("SW3", sw3, s.P("L2", 1))
    s.label("SW3", 337.82, y5)
    vpart(s, "R9", 360.68, y5 + 3.81)
    vpart(s, "R10", 360.68, y5 + 13.97)
    vpart(s, "C10", 373.38, y5 + 3.81)
    vpart(s, "C300", 386.08, y5 + 3.81)
    s.w("+3V3", s.P("L2", 2), (396.24, y5))
    s.w("+3V3", (360.68, y5), s.P("R9", 1))
    for cref, cx_ in (("C10", 373.38), ("C300", 386.08)):
        s.w("+3V3", (cx_, y5), s.P(cref, 1))
        s.rail("GND", *s.P(cref, 2))
    fbm = s.P("R9", 2)
    s.w("FB3", fbm, s.P("R10", 1))
    s.w("FB3", fb3, (339.09, fb3[1]), (339.09, fbm[1] + 1.27), (360.68, fbm[1] + 1.27))
    s.label("FB3", 345.44, fbm[1] + 1.27)
    s.rail("GND", *s.P("R10", 2))
    s.power("+3V3", 396.24, y5)
    s.power("PWR_FLAG", 393.7, y5)
    s.text("VOUT = 0.6 V x (1 + R9/R10) = 3.33 V\n"
           "TPS62A02A: 2 A, forced PWM at 2.4 MHz.\n"
           "L2 1 µH, C10 + C300 = 2 x 10 µF (TI: 1 µH, 22 µF).\n"
           "PG (pin 6) left open.\n"
           "D4, D5: 5 V rail and USB VBUS OR-ed, no backfeed.", 299.72, yr + 7.62)

    # --- supply monitoring and LEDs --------------------------------------------------------------
    ym = yu + 58.42
    s.text("Supply monitoring and power LEDs", 20.32, ym - 12.7, 1.524, True)
    xm = 30.48
    s.rail("+VIN", xm, ym, drop=2.54)
    vpart(s, "R11", xm, ym)
    vpart(s, "R12", xm, ym + 10.16)
    s.w("VIN_SENSE", s.P("R11", 2), s.P("R12", 1))
    vm = s.P("R11", 2)
    vm = (vm[0], vm[1] + 1.27)
    vpart(s, "C11", xm + 10.16, vm[1] + 2.54)
    s.w("VIN_SENSE", vm, (xm + 10.16, vm[1]), (xm + 17.78, vm[1]))
    s.w("VIN_SENSE", (xm + 10.16, vm[1]), s.P("C11", 1))
    s.glabel("VIN_SENSE", xm + 17.78, vm[1], 0, "output")
    s.rail("GND", *s.P("R12", 2))
    s.rail("GND", *s.P("C11", 2))
    s.text("R11/R12: 73.5 V full scale on the 3.3 V ADC.", xm - 7.62, ym + 27.94)
    for rref, dref, net, kind, x in (("R13", "D6", "LEDVIN", "+VIN", 76.2), ("R14", "D7", "LED3V3", "+3V3", 93.98)):
        s.rail(kind, x, ym, drop=2.54)
        vpart(s, rref, x, ym)
        s.place(dref, x, s.P(rref, 2)[1] + 7.62, rot=90,
                ref_at=(x + 5.08, s.P(rref, 2)[1] + 6.35), val_at=(x + 7.62, s.P(rref, 2)[1] + 8.89))
        s.w(net, s.P(rref, 2), s.P(dref, 2))
        s.rail("GND", *s.P(dref, 1))
    # VIN OUT (+VIN_OUT, current limited on the drive supply sheet)
    x = 111.76
    vpart(s, "R306", x, ym)
    s.w("+VIN_OUT", (x, ym), (x, ym - 5.08))
    s.glabel("+VIN_OUT", x, ym - 5.08, 90, "passive")
    s.place("D300", x, s.P("R306", 2)[1] + 7.62, rot=90,
            ref_at=(x + 5.08, s.P("R306", 2)[1] + 6.35), val_at=(x + 7.62, s.P("R306", 2)[1] + 8.89))
    s.w("LEDVOUT", s.P("R306", 2), s.P("D300", 2))
    s.rail("GND", *s.P("D300", 1))
    # test points of the rails
    s.text("Test points of the rails.", 76.2, ym + 30.48)
    for k, (tp, net) in enumerate((("TP4", "+VIN"), ("TP5", "+VIN_OUT"), ("TP6", "+5V"), ("TP7", "+3V3"))):
        tx, ty = 78.74 + 12.7 * k, ym + 50.8
        s.place(tp, tx, ty, rot=180, ref_at=(tx - 1.27, ty + 5.08), show_value=False)
        px_, py_ = s.P(tp, 1)
        if net == "+VIN_OUT":
            s.w(net, (px_, py_), (px_, py_ - 5.08))
            s.glabel(net, px_, py_ - 5.08, 90, "passive")
        else:
            s.rail(net, px_, py_)


def clock(prj):
    s = prj.sheet("Clock", "clock.kicad_sch", "25 MHz clock shared by the ESC and the MCU")
    s.text("CLOCK", 20.32, 17.78, 2.54, True)
    s.place("C12", 96.52, 125.73, ref_at=(99.06, 124.46), val_at=(99.06, 127.0))
    s.rail("+3V3", *s.P("C12", 1))
    s.rail("GND", *s.P("C12", 2))
    s.place("X1", 116.84, 127.0, ref_at=(119.38, 116.84), val_at=(119.38, 139.7))
    s.rail("+3V3", *s.P("X1", 4))
    s.rail("GND", *s.P("X1", 2))
    ox, oy = s.P("X1", 1)
    s.w("+3V3", (ox, oy), (ox - 2.54, oy))
    s.rail("+3V3", ox - 2.54, oy, drop=7.62)
    s.place("R15", 137.16, 127.0, rot=90, ref_at=(134.62, 121.92), val_at=(134.62, 124.46))
    s.place("R16", 137.16, 134.62, rot=90, ref_at=(134.62, 129.54), val_at=(134.62, 132.08))
    s.w("CLK25", s.P("X1", 3), s.P("R15", 1))
    s.w("CLK25", (129.54, 127.0), (129.54, 134.62), s.P("R16", 1))
    for ref, net in (("R15", "CLK25_ESC"), ("R16", "CLK25_MCU")):
        x, y = s.P(ref, 2)
        s.w(net, (x, y), (x + 5.08, y))
        s.glabel(net, x + 5.08, y, 0, "output")
    s.text("One oscillator for both chips: ESC OSCI and MCU PH0 (HSE bypass).\n"
           "OE tied high (datasheet: pull-up of 10 kΩ or less when not driven).\n"
           "R15, R16: series termination at the source.", 93.98, 144.78)


def pull(s, ref, x, y, kind):
    """Pull resistor hanging from a horizontal net at (x, y): up to +3V3 or down to GND."""
    if kind == "GND":
        s.place(ref, x, y + 3.81, ref_at=(x + 1.905, y + 2.54), val_at=(x + 1.905, y + 5.08))
        s.power("GND", *s.P(ref, 2))
    else:
        s.place(ref, x, y - 3.81, rot=180, ref_at=(x + 1.905, y - 5.08), val_at=(x + 1.905, y - 2.54))
        s.power(kind, *s.P(ref, 2))


def esc(prj):
    s = prj.sheet("ESC", "esc.kicad_sch", "EtherCAT slave controller LAN9253, ports, LEDs")
    s.text("ETHERCAT SLAVE CONTROLLER", 20.32, 17.78, 2.54, True)
    cx, cy = 203.2, 154.94
    s.place("U4", cx, cy, ref_at=(cx - 27.94, cy - 71.12), val_at=(cx - 15.24, cy - 71.12))
    P = lambda n: s.P("U4", n)  # noqa: E731

    # --- supply pins: short stubs to the rails, decoupling drawn in its own block ----------------
    top = P(5)[1]
    xs = [P(n)[0] for n in (5, 14, 20, 32, 37, 47)]
    for x in xs:
        s.w("+3V3", (x, top), (x, top - 5.08))
    s.w("+3V3", (xs[0], top - 5.08), (xs[-1], top - 5.08))
    s.power("+3V3", xs[2], top - 5.08)
    for n, net in ((58, "VDD33BIAS"), (51, "VDD33TXRX1"), (64, "VDD33TXRX2")):
        x = P(n)[0]
        s.w(net, (x, top), (x, top - 5.08))
        s.label(net, x, top - 5.08, 90)
    for pins, net in (((6, 24, 38), "VDDCR"), ((56, 59), "VDD12TX")):
        xa, xb = P(pins[0])[0], P(pins[-1])[0]
        for n in pins:
            s.w(net, P(n), (P(n)[0], top - 5.08))
        s.w(net, (xa, top - 5.08), (xb, top - 5.08), (xb, top - 7.62))
        s.label(net, xb, top - 7.62, 90)
    s.w("GND", P(4), (P(4)[0], P(4)[1] + 2.54), (P(65)[0], P(65)[1] + 2.54), P(65))
    s.power("GND", P(4)[0], P(4)[1] + 2.54)

    yd = 40.64
    s.text("Decoupling: one 100 nF per supply pin, at the pin (checklist p.3, p.7).", 20.32, yd - 15.24)
    xd = 25.4
    s.rail("+3V3", xd, yd, drop=2.54)
    caps = ["C13", "C14", "C15", "C16", "C17", "C18", "C19"]
    s.w("+3V3", (xd, yd), (xd + 7.62 + 10.16 * (len(caps) - 1), yd))
    for i, ref in enumerate(caps):
        x = xd + 7.62 + 10.16 * i
        vpart(s, ref, x, yd, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    for i, (fb, net, cs) in enumerate((("FB1", "VDD33BIAS", ("C24", "C25")), ("FB2", "VDD33TXRX1", ("C26", "C27")),
                                       ("FB3", "VDD33TXRX2", ("C28", "C29")))):
        y = yd
        x0 = 236.22 + 55.88 * i
        s.place(fb, x0 + 7.62, y, rot=90, ref_at=(x0 + 3.81, y + 3.81), val_at=(x0 + 3.81, y + 6.35))
        s.w("+3V3", (x0, y), s.P(fb, 1))
        s.rail("+3V3", x0, y)
        xr = x0 + 43.18
        s.w(net, s.P(fb, 2), (xr, y), (xr + 2.54, y))
        s.label(net, x0 + 12.7, y)
        s.power("PWR_FLAG", xr + 2.54, y)
        for k, ref in enumerate(cs):
            vpart(s, ref, xr - 10.16 + 10.16 * k, y, label_dx=1.905)
            s.rail("GND", *s.P(ref, 2))
    xv = 116.84
    s.w("VDDCR", (xv, yd), (xv + 35.56, yd))
    s.label("VDDCR", xv, yd)
    for i, ref in enumerate(("C20", "C21", "C22", "C23")):
        vpart(s, ref, xv + 5.08 + 10.16 * i, yd, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    yv = yd + 15.24
    s.place("FB4", xv + 7.62, yv, rot=90, ref_at=(xv + 3.81, yv + 3.81), val_at=(xv + 3.81, yv + 6.35))
    s.w("VDDCR", (xv - 7.62, yv), s.P("FB4", 1))
    s.label("VDDCR", xv - 7.62, yv)
    s.w("VDD12TX", s.P("FB4", 2), (xv + 45.72, yv), (xv + 48.26, yv))
    s.label("VDD12TX", xv + 12.7, yv)
    s.power("PWR_FLAG", xv + 48.26, yv)
    for i, ref in enumerate(("C30", "C31", "C32")):
        vpart(s, ref, xv + 25.4 + 10.16 * i, yv, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    s.text("C20: 1 µF ESR 0.1 Ω + C21 470 pF at VDDCR pin 6.\nFerrites: BLM18PG221SN1D, bulk on both sides.",
           xv, yv + 17.78)

    # --- left: clock, reset, straps ------------------------------------------------------------
    xl = P(1)[0]
    s.w("CLK25_ESC", P(1), (xl - 15.24, P(1)[1]))
    s.glabel("CLK25_ESC", xl - 15.24, P(1)[1], 180, "input")
    yr = P(11)[1]
    ux = 101.6
    s.place("U5", ux, yr, ref_at=(ux + 2.54, yr - 13.97), val_at=(ux + 2.54, yr - 11.43))
    s.w("ESC_RST", s.P("U5", 1), P(11))
    s.w("ESC_RST", (152.4, yr), (152.4, yr - 5.08), (149.86, yr - 5.08))
    s.glabel("ESC_RST", 149.86, yr - 5.08, 180, "bidirectional")
    vpart(s, "R20", 124.46, yr - 10.16, rot=180)
    s.power("+3V3", *s.P("R20", 2))
    s.w("ESC_RST", s.P("R20", 1), (124.46, yr))
    yt = yr - 15.24
    s.w("+3V3", s.P("U5", 6), (ux, yt))
    s.power("+3V3", ux, yt)
    sx, sy = s.P("U5", 5)
    s.w("+3V3", (sx, sy), (sx - 2.54, sy), (sx - 2.54, yt), (ux, yt))
    cy4 = s.P("U5", 4)[1]
    s.place("R19", sx - 7.62, cy4, rot=270, ref_at=(sx - 10.16, cy4 + 3.81), val_at=(sx - 10.16, cy4 + 6.35))
    s.w("SUP_CT", s.P("U5", 4), s.P("R19", 1))
    rx, ry = s.P("R19", 2)
    s.w("+3V3", (rx, ry), (rx, yt), (sx - 2.54, yt))
    vpart(s, "C33", rx - 7.62, yt, label_dx=1.905)
    s.w("+3V3", (rx - 7.62, yt), (rx, yt))
    s.rail("GND", *s.P("C33", 2))
    s.rail("GND", *s.P("U5", 2))
    s.text("Supervisor on RST# only: 3.07 V, 300 ms.\nThe MCU drives RST# open drain and reads it back.",
           63.5, yr - 33.02)
    for n, kind, rot in ((7, "+3V3", 90), (41, "GND", 270)):
        x, y = P(n)
        s.w(kind, (x, y), (x - 5.08, y))
        s.power(kind, x - 5.08, y, rot)
    for n, net, shape in ((50, "ESC_SCS", "input"), (19, "ESC_SCK", "input"), (17, "ESC_SIO0", "bidirectional"),
                          (13, "ESC_SIO1", "bidirectional"), (12, "ESC_SIO2", "bidirectional"),
                          (35, "ESC_SIO3", "bidirectional")):
        x, y = P(n)
        s.w(net, (x, y), (x - 10.16, y))
        s.glabel(net, x - 10.16, y, 180, shape)
    for n, net, ref, kind, tp in ((44, "ESC_IRQ", "R21", "+3V3", "TP1"), (34, "ESC_SYNC0", "R22", "GND", "TP2"),
                                  (18, "ESC_SYNC1", "R23", "GND", None), (10, "ESC_WAIT_ACK", "R24", "GND", None)):
        x, y = P(n)
        s.w(net, (x, y), (127.0, y))
        s.glabel(net, 127.0, y, 180, "output")
        pull(s, ref, 142.24, y, kind)
        if tp:
            s.place(tp, 134.62, y, ref_at=(135.89, y - 2.54), show_value=False)
        if tp == "TP2":
            s.place("TP3", 132.08, y + 7.62, ref_at=(133.35, y + 3.81), show_value=False)
            s.power("GND", *s.P("TP3", 1))
    s.text("PDI: SPI, then SQI (OCTOSPI of the MCU).\nSYNC0/1 and WAIT_ACK pulled down: Hi-Z until the ESC is configured.",
           63.5, P(44)[1] - 7.62)
    ya, yc = P(42)[1], P(43)[1]
    s.place("U6", 101.6, ya + 2.54, ref_at=(104.14, ya - 7.62), val_at=(104.14, ya - 10.16))
    s.w("EESDA", P(42), s.P("U6", 5))
    s.w("EESCL", P(43), (116.84, yc), (116.84, s.P("U6", 6)[1]), s.P("U6", 6))
    wx, wy = s.P("U6", 7)
    s.w("GND", (wx, wy), (wx + 2.54, wy))
    s.power("GND", wx + 2.54, wy)
    s.power("+3V3", *s.P("U6", 8))
    s.power("GND", *s.P("U6", 4))
    vpart(s, "C34", 83.82, ya - 2.54, label_dx=1.905)
    s.power("+3V3", *s.P("C34", 1))
    s.power("GND", *s.P("C34", 2))
    pull(s, "R25", 142.24, ya, "GND")
    pull(s, "R27", 152.4, ya, "+3V3")
    pull(s, "R26", 142.24, yc, "GND")
    pull(s, "R28", 152.4, yc, "+3V3")
    s.text("SII EEPROM emulated by the MCU (EE_EMUL = 000, PDI SPI): R25, R26 fitted.\n"
           "Fallback EEPROM: fit U6, C34, R27, R28 and remove R25, R26.", 63.5, yc + 12.7)
    for n, ref, net in ((8, "R18", "CLK25_OFF"), (57, "R17", "RBIAS")):
        x, y = P(n)
        s.place(ref, x - 16.51, y, rot=270, ref_at=(x - 21.59, y - 1.905), val_at=(x - 16.51, y - 1.905))
        s.w(net, (x, y), s.P(ref, 1))
        s.power("GND", *s.P(ref, 2), 270)
    s.text("CLK_25 strapped low: output off.\nRBIAS: 12.1 kΩ 1 %.", 127.0, P(57)[1] + 5.08)

    # --- right: ports ----------------------------------------------------------------------------
    for j, pins, rail, rs, cct, esd in (
            ("J3", (53, 52, 55, 54), "VDD33TXRX1", ("R37", "R38", "R39", "R40"), "C35", "U7"),
            ("J4", (62, 63, 60, 61), "VDD33TXRX2", ("R41", "R42", "R43", "R44"), "C36", "U8")):
        tp, tn, rp, rn = [P(n) for n in pins]
        nets = [c.by_ref()["U4"]["pins"][str(n)] for n in pins]
        xr0 = tp[0]
        y0 = tp[1]
        xj = 345.44
        s.place(j, xj, y0 + 7.62, ref_at=(xj - 7.62, y0 - 6.35), val_at=(xj - 7.62, y0 - 3.81))
        jp = {k: s.P(j, k) for k in (1, 2, 3, 4, 5, 6, 8, 9, 10, "SH")}
        turns = (None, 317.5, 314.96, 312.42)
        s.w(nets[0], tp, jp[1])
        for k, (pin, jpin, xt) in enumerate(((tn, jp[2], turns[1]), (rp, jp[3], turns[2]), (rn, jp[6], turns[3]))):
            s.w(nets[k + 1], pin, (xt, pin[1]), (xt, jpin[1]), jpin)
        yrail = y0 - 15.24
        xs_r = [xr0 + 7.62 + 7.62 * k for k in range(4)]
        s.w(rail, (xs_r[0] - 5.08, yrail), (xs_r[-1], yrail))
        s.label(rail, xs_r[0] - 5.08, yrail)
        for k, (ref, pin) in enumerate(zip(rs, (tp, tn, rp, rn))):
            x = xs_r[k]
            vpart(s, ref, x, yrail, label_dx=1.905, rot=180)
            s.w(nets[k], s.P(ref, 1), (x, pin[1]))
        xc = jp[4][0] - 2.54
        s.w(rail, jp[4], (xc, jp[4][1]), (xc, jp[5][1]), jp[5])
        s.w(rail, (xc, jp[4][1]), (xc, yrail - 5.08), (xc - 5.08, yrail - 5.08))
        s.label(rail, xc - 20.32, yrail - 5.08)
        s.w(rail, (xc - 20.32, yrail - 5.08), (xc - 5.08, yrail - 5.08))
        vpart(s, cct, xc - 7.62, yrail - 5.08, label_dx=-6.35)
        s.rail("GND", *s.P(cct, 2))
        sx, sy = jp["SH"]
        s.w("CHASSIS", jp[8], (jp[8][0], jp[8][1] + 5.08), (sx, sy + 5.08), (sx, sy))
        s.glabel("CHASSIS", jp[8][0], jp[8][1] + 5.08, 0, "passive")
        s.w("GND", jp[10], (jp[10][0] + 5.08, jp[10][1]))
        s.power("GND", jp[10][0] + 5.08, jp[10][1], 270)
        ledn = "LINK0_A" if j == "J3" else "LINK1_A"
        s.w(ledn, jp[9], (jp[9][0] + 5.08, jp[9][1]))
        s.label(ledn, jp[9][0] + 5.08, jp[9][1])
        # ESD array below the lines, flow-through on the board
        xe, ye = 284.48, rn[1] + 20.32
        s.place(esd, xe, ye, ref_at=(xe + 3.81, ye - 8.89), val_at=(xe + 3.81, ye - 11.43))
        for pin_e, src, xv_ in ((1, tp, xe - 17.78), (2, tn, xe - 15.24)):
            ex, ey = s.P(esd, pin_e)
            s.w(c.by_ref()[esd]["pins"][str(pin_e)], (xv_, src[1]), (xv_, ey), (ex, ey))
        for pin_e, xv_ in ((4, xe + 15.24), (5, xe + 17.78)):
            ex, ey = s.P(esd, pin_e)
            net = c.by_ref()[esd]["pins"][str(pin_e)]
            src_y = rp[1] if pin_e == 4 else rn[1]
            s.w(net, (xv_, src_y), (xv_, ey), (ex, ey))
        gx, gy = s.P(esd, 3)
        s.rail("GND", gx, gy)
        s.text(f"{'IN: port 0 (PHY A)' if j == 'J3' else 'OUT: port 1 (PHY B)'}", xj + 7.62, y0 - 10.16, 1.524, True)
    s.place("C37", 378.46, 120.65, ref_at=(381.0, 119.38), val_at=(381.0, 121.92))
    s.w("CHASSIS", s.P("C37", 1), (378.46, 113.03))
    s.glabel("CHASSIS", 378.46, 113.03, 90, "passive")
    s.power("PWR_FLAG", 375.92, 113.03)
    s.w("CHASSIS", (375.92, 113.03), (378.46, 113.03))
    s.rail("GND", *s.P("C37", 2))

    # --- right: LEDs -----------------------------------------------------------------------------
    for n, net, rpd, rser, led, anode in ((48, "LINK0", "R33", "R34", None, "LINK0_A"),
                                          (46, "LINK1", "R35", "R36", None, "LINK1_A"),
                                          (45, "RUN", "R29", "R30", "D8", "RUN_A"),
                                          (9, "ERR", "R31", "R32", "D9", "ERR_A")):
        x, y = P(n)
        pull(s, rpd, x + 7.62, y, "GND")
        s.place(rser, x + 17.78, y, rot=90, ref_at=(x + 13.97, y - 2.54), val_at=(x + 19.05, y - 2.54))
        s.w(net, (x, y), s.P(rser, 1))
        if led:
            s.place(led, x + 33.02, y, rot=180, ref_at=(x + 30.48, y + 3.81), val_at=(x + 30.48, y + 6.35))
            s.w(anode, s.P(rser, 2), s.P(led, 2))
            s.power("GND", *s.P(led, 1), 90)
        else:
            s.w(anode, s.P(rser, 2), (x + 25.4, y))
            s.label(anode, x + 25.4, y)
    s.text("LED pins are straps: pulled down (2 ports, emulation, port B auto-negotiation).\n"
           "LINK/ACT on the green LED of each RJ45; yellow LEDs unused.", P(48)[0] + 2.54, P(9)[1] + 12.7)


MCU_INPUTS = {"ALM0", "ALM1", "ALM2", "ALM3", "PROBE", "ESC_SYNC0", "ESC_SYNC1", "ESC_IRQ", "ESC_WAIT_ACK",
              "BUS_IRQ", "BUS_MISO", "VIN_SENSE", "VBUS_SENSE", "ESTOP_IN", "MB_RX", "CLK25_MCU"} | {
    f"ENC{i}_{s}" for i in range(4) for s in "ABZ"}
MCU_BIDIR = {"ESC_RST", "USB_DM", "USB_DP", "BUS_SDA"}


def mcu(prj):
    s = prj.sheet("MCU", "mcu.kicad_sch", "MCU STM32H523VET6, decoupling, debug")
    s.text("MCU", 20.32, 17.78, 2.54, True)
    cx, cy = 210.82, 154.94
    s.place("U9", cx, cy, ref_at=(cx + 2.54, cy - 2.54), val_at=(cx + 2.54, cy))
    pins = c.by_ref()["U9"]["pins"]
    P = lambda n: s.P("U9", n)  # noqa: E731
    special = {14, 94, 21, 20, 48, 98, 66, 68, 72, 76, 89, 7, 31, 32, 35, 36, 37, 47,
               6, 11, 28, 50, 75, 100, 73, 22, 19, 10, 27, 49, 74, 99}
    for n, net in pins.items():
        n = int(n)
        if n in special:
            continue
        x, y = P(n)
        left = x < cx
        xe = x - 5.08 if left else x + 5.08
        s.w(net, (x, y), (xe, y))
        shape = "input" if net in MCU_INPUTS else "bidirectional" if net in MCU_BIDIR else "output"
        s.glabel(net, xe, y, 180 if left else 0, shape)
    # PA9, PC9: UCPD dead-battery controls, tied low (no signal)
    for n, ref in ((68, "R304"), (66, "R305")):
        x, y = P(n)
        d = -1 if x < cx else 1
        s.place(ref, x + d * 7.62, y, rot=90, ref_at=(x + d * 7.62, y - 2.54), val_at=(x + d * 7.62, y + 2.54))
        a, b = sorted((s.P(ref, 1), s.P(ref, 2)), key=lambda p: d * p[0])
        s.w(pins[str(n)], (x, y), a)
        s.w("GND", b, (b[0] + d * 2.54, b[1]))
        s.power("GND", b[0] + d * 2.54, b[1], 90 if d > 0 else 270, show=False)
        s.quiet.add(pins[str(n)])

    # --- supplies ------------------------------------------------------------------------------
    top = P(11)[1]
    xs = [P(n)[0] for n in (6, 11, 28, 50, 75, 100)]
    for x in xs:
        s.w("+3V3", (x, top), (x, top - 5.08))
    s.w("+3V3", (xs[0], top - 5.08), (xs[-1], top - 5.08))
    s.power("+3V3", xs[2], top - 5.08)
    x = P(73)[0]
    s.rail("+3V3", x, top, drop=7.62)
    x = P(22)[0]
    s.w("VDDA", (x, top), (x, top - 2.54))
    s.label("VDDA", x, top - 2.54, 90)
    bot = P(10)[1]
    s.w("GND", P(10), (P(10)[0], bot + 2.54), (P(19)[0], bot + 2.54), P(19))
    s.power("GND", P(10)[0], bot + 2.54)

    yd = 40.64
    s.text("Decoupling: one 100 nF per VDD pin plus 4.7 µF (AN5711 §7.4); VBAT and VDDUSB on VDD.",
           20.32, yd - 15.24)
    xd = 25.4
    caps = ["C38", "C39", "C40", "C41", "C42", "C43", "C44", "C45"]
    s.rail("+3V3", xd, yd, drop=2.54)
    s.w("+3V3", (xd, yd), (xd + 7.62 + 10.16 * (len(caps) - 1), yd))
    for i, ref in enumerate(caps):
        vpart(s, ref, xd + 7.62 + 10.16 * i, yd, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    # VDDA through its own ferrite; VREF+ tied to VDDA
    xa = 134.62
    s.place("FB5", xa + 7.62, yd, rot=90, ref_at=(xa + 3.81, yd + 3.81), val_at=(xa + 3.81, yd + 6.35))
    s.w("+3V3", (xa, yd), s.P("FB5", 1))
    s.rail("+3V3", xa, yd)
    s.w("VDDA", s.P("FB5", 2), (xa + 53.34, yd))
    s.label("VDDA", xa + 12.7, yd)
    s.power("PWR_FLAG", xa + 53.34, yd)
    for i, ref in enumerate(("C48", "C49", "C50", "C51")):
        vpart(s, ref, xa + 17.78 + 10.16 * i, yd, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    s.text("C48, C49 at VDDA (22); C50, C51 at VREF+ (21).", xa, yd + 17.78)

    # --- left: NRST, BOOT0, VREF, VCAP, VCP -------------------------------------------------------
    xl = P(14)[0]
    yn = P(14)[1]
    s.w("NRST", (xl, yn), (xl - 78.74, yn))
    s.glabel("NRST", xl - 78.74, yn, 180, "bidirectional")
    vpart(s, "C52", xl - 60.96, yn, label_dx=1.905)
    s.rail("GND", *s.P("C52", 2))
    s.place("D10", xl - 68.58, yn + 3.81, rot=270, ref_at=(xl - 67.31, yn + 2.54), val_at=(xl - 67.31, yn + 5.08),
            show_value=False)
    s.rail("GND", *s.P("D10", 2))
    yb = P(94)[1]
    s.w("BOOT0", (xl, yb), (xl - 35.56, yb))
    s.place("R45", xl - 27.94, yb + 3.81, ref_at=(xl - 26.035, yb + 2.54), val_at=(xl - 26.035, yb + 5.08))
    s.rail("GND", *s.P("R45", 2))
    s.place("SW1", xl - 40.64, yb, ref_at=(xl - 43.18, yb + 3.81), val_at=(xl - 43.18, yb + 6.35))
    s.power("+3V3", *s.P("SW1", 1), 90)
    x, y = P(21)
    s.w("VDDA", (x, y), (x - 5.08, y))
    s.label("VDDA", x - 5.08, y)
    x, y = P(20)
    s.w("GND", (x, y), (x - 5.08, y))
    s.power("GND", x - 5.08, y, 270, show=False)
    s.text("NRST: 100 nF + ESD at the pin, to the debug connector.\nBOOT0: hold SW1 during a reset or power-up for the system bootloader.",
           xl - 76.2, yn - 15.24)
    x1, y1 = P(48)
    x2, y2 = P(98)
    s.w("VCAP", (x1, y1), (x1 - 5.08, y1), (x1 - 5.08, y2 + 2.54), (x1 - 43.18, y2 + 2.54))
    s.w("VCAP", (x2, y2), (x2 - 5.08, y2))
    for k, ref in enumerate(("C46", "C310", "C47", "C311")):
        vpart(s, ref, x1 - 12.7 - 10.16 * k, y2 + 2.54, label_dx=1.905)
        s.rail("GND", *s.P(ref, 2))
    s.label("VCAP", x1 - 43.18, y2 + 2.54)

    # --- right: OCTOSPI series terminations, SWD, LED -----------------------------------------------
    for n, ref, esc_net in ((31, "R52", "ESC_SIO3"), (32, "R51", "ESC_SIO2"), (35, "R50", "ESC_SIO1"),
                            (36, "R49", "ESC_SIO0"), (37, "R47", "ESC_SCK"), (47, "R48", "ESC_SCS")):
        x, y = P(n)
        s.place(ref, x + 7.62, y, rot=90, show_ref=False, show_value=False)
        s.quiet.add(pins[str(n)])
        s.w(pins[str(n)], (x, y), s.P(ref, 1))
        s.w(esc_net, s.P(ref, 2), (x + 15.24, y))
        s.glabel(esc_net, x + 15.24, y, 0, "output" if esc_net in ("ESC_SCK", "ESC_SCS") else "bidirectional")
    s.text("R47 to R52: 49.9 Ω series terminations\n(SCK, SCS, SIO0, SIO1, SIO2, SIO3).", P(31)[0] + 38.1, P(31)[1] - 1.27)
    for n, net in ((72, "SWDIO"), (76, "SWCLK"), (89, "SWO")):
        x, y = P(n)
        s.w(net, (x, y), (x + 5.08, y))
        s.label(net, x + 5.08, y)
    x, y = P(7)
    s.place("D11", x + 35.56, y, ref_at=(x + 33.02, y - 3.81), val_at=(x + 33.02, y + 3.81))
    s.w("LED_MCU", (x, y), s.P("D11", 1))
    s.place("R46", x + 45.72, y, rot=270, ref_at=(x + 43.18, y - 3.81), val_at=(x + 46.99, y - 3.81))
    s.w("LED_A", s.P("D11", 2), s.P("R46", 2))
    s.power("+3V3", *s.P("R46", 1), 270)

    # --- debug connector ---------------------------------------------------------------------------
    jx, jy = 86.36, 228.6
    s.text("Debug: Tag-Connect TC2030 (legged), SWD + SWO + reset, for a J-Link through the TC2030-CTX cable.\n"
           "Debug only: users program through USB DFU, then FoE.", jx - 50.8, jy - 22.86)
    s.place("J5", jx, jy, ref_at=(jx + 2.54, jy - 12.7), val_at=(jx + 2.54, jy - 10.16))
    s.rail("+3V3", *s.P("J5", 1))
    s.rail("GND", *s.P("J5", 5))
    for k, net in ((2, "SWDIO"), (4, "SWCLK"), (6, "SWO"), (3, "NRST")):
        x, y = s.P("J5", k)
        s.w(net, (x, y), (x + 5.08, y))
        if net == "NRST":
            s.glabel(net, x + 5.08, y, 0, "bidirectional")
        else:
            s.label(net, x + 5.08, y)

def main():
    # Project symbol library, so that KiCad finds the LAN9253 when the schematic is edited.
    os.makedirs(KICAD, exist_ok=True)
    with open(os.path.join(KICAD, "sym-lib-table"), "w", encoding="utf-8", newline="\n") as f:
        f.write('(sym_lib_table\n  (version 7)\n  (lib (name "Bornier")(type "KiCad")'
                '(uri "${KIPRJMOD}/../../lib/symbols/bornier.kicad_sym")(options "")(descr "Bornier parts"))\n)\n')
    with open(os.path.join(KICAD, "fp-lib-table"), "w", encoding="utf-8", newline="\n") as f:
        f.write('(fp_lib_table\n  (version 7)\n  (lib (name "Bornier")(type "KiCad")'
                '(uri "${KIPRJMOD}/../../lib/footprints/Bornier.pretty")(options "")(descr "Bornier parts"))\n)\n')
    pro = os.path.join(KICAD, "base.kicad_pro")
    if not os.path.exists(pro):
        with open(pro, "w", encoding="utf-8", newline="\n") as f:
            f.write('{"meta": {"filename": "base.kicad_pro", "version": 3}}\n')
    prj = Project("base", c, "Bornier base board", "2026-10-18",
                  libs={"Bornier": os.path.join(HERE, "..", "..", "lib", "symbols", "bornier.kicad_sym")})
    power(prj)
    clock(prj)
    esc(prj)
    mcu(prj)
    import motion
    motion.drive_pair(prj)
    motion.drive_supply_probe(prj)
    motion.encoder(prj)
    import bus
    bus.local_bus(prj)
    import spindle
    spindle.spindle(prj)
    import modbus
    modbus.modbus(prj)
    import safety
    safety.safety(prj)
    sch, ok = prj.write(KICAD)
    print(f"{len(c.parts)} parts -> {sch}")
    if not ok:
        print("drawing errors: fix them before checking")
        return 1
    return check(c, sch, PENDING_ERC, WAIVED_ERC)


if __name__ == "__main__":
    sys.exit(main())
