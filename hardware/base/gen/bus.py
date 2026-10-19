# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Local bus sheet: HE10 2x17 ribbon to the extension modules (SPI, 12 CS, I2C, IRQ, LATCH, OE).

Called by schematic.py; the parts and their connections come from circuit.py.
"""
from circuit import c
from motion import on, stub, vr, hr

SERIES = [f"CS{i}" for i in range(12)] + ["LATCH", "OE", "SCK", "MOSI"]
PULLED = {f"CS{i}" for i in range(12)} | {"LATCH", "OE", "IRQ", "SDA", "SCL", "SCK", "MOSI"}


def local_bus(prj):
    s = prj.sheet("Local bus", "bus.kicad_sch", "Local bus: HE10 2x17 ribbon to the extension modules")
    s.text("LOCAL BUS", 20.32, 17.78, 2.54, True)
    s.text("SPI at 8 MHz, mode 0; CS0-CS11 shifted by each module (barrel shift); LATCH on SYNC0; OE active low.\n"
           "Series 49.9 ohm at the source on everything the base drives; pull-ups keep CS, LATCH and OE inactive\n"
           "while the MCU pins are not configured. MISO is terminated on the module side.", 20.32, 25.4)
    y0, pitch = 55.88, 5.08
    rows = SERIES + ["IRQ", "SDA", "SCL", "MISO"]
    for k, sig in enumerate(rows):
        y = y0 + pitch * k
        net = f"BUS_{sig}"
        shape = "output" if sig in ("MISO", "IRQ") else "bidirectional" if sig == "SDA" else "input"
        end = 76.2 if sig in SERIES else 50.8
        s.w(net, (40.64, y), (end, y))
        s.glabel(net, 40.64, y, 180, shape)
        if sig in PULLED or sig == "MISO":
            r = next(x for x in on(net, "R") if c.by_ref()[x]["value"] != "49.9")
            kind = "GND" if sig in ("MISO", "SCK", "MOSI") else "+3V3"
            s.w(net, (50.8, y), (50.8, y + 2.54))
            s.place(r, 57.15, y + 2.54, rot=90 if c.by_ref()[r]["pins"]["1"] == net else 270,
                    show_ref=False, show_value=False)
            a, b = sorted((s.P(r, 1), s.P(r, 2)))
            s.w(net, (50.8, y + 2.54), a)
            s.power(kind, *b, 270 if kind == "+3V3" else 90, show=False)
        if sig in SERIES:
            rs_ = [x for x in on(net, "R") if c.by_ref()[x]["value"] == "49.9"]
            r = rs_[0]
            s.place(r, 80.01, y, rot=90, show_ref=False, show_value=False)
            s.w(f"RB_{sig}", s.P(r, 2), (93.98, y))
            if len(rs_) > 1:          # SCK, MOSI, LATCH: second 49.9 in parallel (25 ohm)
                r2 = rs_[1]
                s.place(r2, 80.01, y + 2.54, rot=90, show_ref=False, show_value=False)
                s.w(net, (76.2, y), s.P(r2, 1))
                s.w(f"RB_{sig}", s.P(r, 2), (83.82, y + 2.54))
            s.label(f"RB_{sig}", 93.98, y)
            s.quiet.add(net)
    s.text("Pull-ups 10 k on CS0-CS11, LATCH, OE and IRQ, 2.2 k on SDA and SCL; pull-down 100 k on MISO.\n"
           "Series 49.9 ohm on CS0-CS11, LATCH, OE, SCK, MOSI (values and references in the BOM).",
           20.32, y0 + pitch * len(rows) + 2.54)

    # connector
    j = on("RB_SCK", "J")[0]
    jx, jy = 190.5, 106.68
    s.place(j, jx, jy, ref_at=(jx - 2.54, jy - 24.13), val_at=(jx - 2.54, jy - 21.59))
    for k, net in c.by_ref()[j]["pins"].items():
        pt = s.P(j, k)
        d = -7.62 if pt[0] < jx else 7.62
        if net == "GND":
            s.w(net, pt, (pt[0] + d / 3, pt[1]))
            s.power("GND", pt[0] + d / 3, pt[1], 90 if d > 0 else 270, show=False)
        elif net.startswith("BUS_"):
            s.w(net, pt, (pt[0] + d, pt[1]))
            s.glabel(net, pt[0] + d, pt[1], 0 if d > 0 else 180, "bidirectional")
        else:
            stub(s, pt, net, d)
    s.text("Ribbon: conductor n = pin n; a ground next to SCK and between groups.", jx - 25.4, jy + 27.94)

    # ESD of the ribbon lines, placed at the header on the board
    esds = [u for u in c.by_ref() if c.by_ref()[u]["value"] == "TPD4E05U06DQAR"
            and c.by_ref()[u]["block"].startswith("Local bus")]
    s.text("ESD of every ribbon signal at the header (TPD4E05U06, flow-through).", 116.84, 48.26)
    for k, esd in enumerate(sorted(esds, key=lambda r: int(r[1:]))):
        ex0, ey0 = 132.08, 63.5 + 30.48 * k
        s.place(esd, ex0, ey0, ref_at=(ex0 + 3.81, ey0 - 8.89), val_at=(ex0 + 3.81, ey0 - 11.43))
        for pin in ("1", "2", "4", "5"):
            px_, py_ = s.P(esd, pin)
            net = c.by_ref()[esd]["pins"][pin]
            d = -5.08 if px_ < ex0 else 5.08
            if net.startswith("BUS_"):
                s.w(net, (px_, py_), (px_ + d, py_))
                s.glabel(net, px_ + d, py_, 0 if d > 0 else 180, "bidirectional")
            else:
                stub(s, (px_, py_), net, d)
        s.rail("GND", *s.P(esd, 3))

    # 3.3 V of the ribbon
    u = on("+3V3_BUS", "U")[0]
    ux, uy = 254.0, 76.2
    s.text("+3V3_BUS: 3.3 V of the ribbon, 505-616 mA limit, FAULT LED; EN on +5V: off on USB alone.", ux - 30.48, uy - 17.78)
    s.place(u, ux, uy, ref_at=(ux - 5.08, uy - 10.16), val_at=(ux - 5.08, uy - 7.62))
    ix, iy = s.P(u, 1)
    ex, ey = s.P(u, 3)
    cin = next(r for r in on("+3V3", "C") if c.by_ref()[r]["block"].startswith("Local bus"))
    s.w("+3V3", (ix, iy), (ix - 17.78, iy))
    s.w("+5V", (ex, ey), (ex - 5.08, ey))
    s.power("+5V", ex - 5.08, ey, 90)
    s.power("+3V3", ix - 17.78, iy)
    vr(s, cin, ix - 12.7, iy)
    s.rail("GND", *s.P(cin, 2))
    lx, ly = s.P(u, 5)
    rl = on(f"{u}_ILIM", "R")[0]
    s.w(f"{u}_ILIM", (lx, ly), (lx - 2.54, ly), (lx - 2.54, ly + 2.54))
    vr(s, rl, lx - 2.54, ly + 2.54, dx=-5.08)
    s.rail("GND", *s.P(rl, 2))
    s.rail("GND", *s.P(u, 2))
    ox, oy = s.P(u, 6)
    cout = on("+3V3_BUS", "C")[0]
    s.w("+3V3_BUS", (ox, oy), (ox + 35.56, oy))
    s.label("+3V3_BUS", ox + 35.56, oy)
    vr(s, cout, ox + 30.48, oy)
    s.rail("GND", *s.P(cout, 2))
    fx, fy = s.P(u, 4)
    d = on(f"{u}_LED", "D")[0]
    rr = on(f"{u}_LED", "R")[0]
    s.place(d, fx + 6.35, fy, ref_at=(fx + 3.81, fy + 3.81), val_at=(fx + 3.81, fy + 6.35))
    s.w(f"{u}_FLT", (fx, fy), s.P(d, 1))
    hr(s, rr, fx + 15.24, fy, rot=270, ref_at=(fx + 12.7, fy + 3.81), val_at=(fx + 16.51, fy + 3.81))
    s.w(f"{u}_LED", s.P(d, 2), s.P(rr, 2))
    s.power("+3V3", *s.P(rr, 1), 270)
    s.quiet.update({f"{u}_ILIM", f"{u}_FLT", f"{u}_LED"})
