# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Modbus sheet: isolated RS-485 transceiver, line bias, switchable termination, TX/RX LEDs.

Called by schematic.py; the parts and their connections come from circuit.py.
"""
from circuit import c
from motion import on, stub, vr


def iso_gnd(s, x, y, drop=2.54):
    """Isolated ground below (x, y)."""
    s.rail("GNDISO", x, y, drop=drop)


def tie_down(s, kind, pts, drop=2.54):
    """Ground pins on the bottom edge joined by one bar, a single ground symbol under the first."""
    y = pts[0][1] + drop
    for x, py in pts:
        s.w(kind, (x, py), (x, y))
    s.w(kind, (pts[0][0], y), (pts[-1][0], y))
    s.rail(kind, pts[0][0], y)


def modbus(prj):
    s = prj.sheet("Modbus", "modbus.kicad_sch", "Modbus RS-485, isolated, Bornier is the line master")
    s.text("MODBUS RS-485", 20.32, 17.78, 2.54, True)
    s.text("Isolated half-duplex RS-485: the bus side is powered by the DC-DC inside the transceiver (VISO = 3.3 V).\n"
           "Bornier is the master of the line, so it biases it: 370 mV at idle with a 120 ohm termination at each end.\n"
           "TERM: shunt on 1-2 when Bornier sits at an end of the line. Wiring: D1 (A), D0 (B), common, shield.", 20.32, 25.4)

    u = on("MB_A", "U")[0]
    cx, cy = 177.8, 116.84
    s.place(u, cx, cy, ref_at=(cx - 5.08, cy - 15.24), val_at=(cx - 5.08, cy - 12.7))
    P = lambda n: s.P(u, n)  # noqa: E731
    B = c.by_ref()

    # --- logic side ---------------------------------------------------------------------------
    vx, vy = P(1)
    yv = vy - 15.24
    s.w("+3V3", (vx, vy), (vx - 2.54, vy), (vx - 2.54, yv), (vx - 33.02, yv))
    s.power("+3V3", vx - 33.02, yv)
    caps = [r for r in on("+3V3", "C") if B[r]["block"].startswith("Modbus")]
    for k, cap in enumerate(sorted(caps, key=lambda r: B[r]["value"])):
        vr(s, cap, vx - 12.7 - 10.16 * k, yv)
        s.rail("GND", *s.P(cap, 2))
    stub(s, P(4), "GND", -5.08, "GND")
    # DI, DE and RO fan out downwards: the lowest pin turns first and takes the lowest row
    xg = vx - 66.04
    rows = {}
    for k, (pin, net, shape) in enumerate(((3, "MB_RX", "output"), (5, "MB_DE", "input"), (6, "MB_TX", "input"))):
        px, py = P(pin)
        xj = px - 10.16 - 5.08 * k
        yr = cy + 33.02 - 15.24 * k
        s.w(net, (px, py), (xj, py), (xj, yr), (xg, yr))
        s.glabel(net, xg, yr, 180, shape)
        rows[net] = yr
    rd = next(r for r in on("MB_DE", "R"))
    vr(s, rd, xg + 17.78, rows["MB_DE"])
    s.rail("GND", *s.P(rd, 2))
    # activity LEDs, on the signals through labels
    for k, net in enumerate(("MB_TX", "MB_RX")):
        lx = 50.8 + 15.24 * k
        r = on(f"{net}_LA", "R")[0]
        d = on(f"{net}_LA", "D")[0]
        vr(s, r, lx, 147.32)
        s.power("+3V3", *s.P(r, 1))
        s.place(d, lx, s.P(r, 2)[1] + 3.81, rot=90, ref_at=(lx + 3.81, s.P(r, 2)[1] + 2.54),
                val_at=(lx + 3.81, s.P(r, 2)[1] + 5.08))
        s.w(f"{net}_LA", s.P(r, 2), s.P(d, 2))
        dx_, dy_ = s.P(d, 1)
        s.w(net, (dx_, dy_), (dx_, dy_ + 5.08))
        s.glabel(net, dx_, dy_ + 5.08, 270, "input")
        s.quiet.add(f"{net}_LA")
    s.text("TX and RX activity", 45.72, 139.7)
    tie_down(s, "GND", sorted(P(k) for k in (2, 7, 8)))

    # --- bus side ------------------------------------------------------------------------------
    ox, oy = P(16)
    yi = oy - 15.24
    s.w("VISO", (ox, oy), (ox + 2.54, oy), (ox + 2.54, yi), (P(12)[0] + 33.02, yi))
    caps = [r for r in on("VISO", "C")]
    for k, cap in enumerate(sorted(caps, key=lambda r: B[r]["value"])):
        vr(s, cap, ox + 12.7 + 10.16 * k, yi)
        iso_gnd(s, *s.P(cap, 2))
    sx, sy = P(10)
    s.w("GNDISO", (sx, sy), (sx + 5.08, sy))
    s.power("GNDISO", sx + 5.08, sy, 90, show=False)
    gb = sorted(P(k) for k in (9, 15))
    tie_down(s, "GNDISO", gb)
    s.w("GNDISO", (gb[-1][0], gb[-1][1] + 2.54), (gb[-1][0] + 5.08, gb[-1][1] + 2.54))
    s.power("PWR_FLAG", gb[-1][0] + 5.08, gb[-1][1] + 2.54, 180)

    ax, ay = P(12)
    bx, by = P(13)
    xe = ax + 99.06
    s.w("MB_A", (ax, ay), (xe, ay))
    s.w("MB_B", (bx, by), (xe, by))
    # bias: VISO -> A, B -> GNDISO
    ra1, ra2 = on("MB_BA", "R")
    if B[ra1]["pins"]["1"] != "VISO":
        ra1, ra2 = ra2, ra1
    vr(s, ra1, ax + 33.02, yi)
    vr(s, ra2, ax + 33.02, yi + 7.62)
    s.w("MB_A", s.P(ra2, 2), (ax + 33.02, ay))
    rb1, rb2 = on("MB_BB", "R")
    if B[rb1]["pins"]["1"] != "MB_B":
        rb1, rb2 = rb2, rb1
    vr(s, rb1, ax + 40.64, by)
    vr(s, rb2, ax + 40.64, by + 7.62)
    iso_gnd(s, *s.P(rb2, 2))
    s.quiet.update({"MB_BA", "MB_BB"})
    # termination: A -> 120 ohm -> switch -> B
    rt = next(r for r in on("MB_A", "R") if "MB_T" in B[r]["pins"].values())
    sw = on("MB_T", "JP")[0]
    xt = ax + 55.88
    s.place(rt, xt, ay - 8.89, rot=180, ref_at=(xt - 6.35, ay - 10.16), val_at=(xt - 6.35, ay - 7.62))
    s.w("MB_A", (xt, ay), sorted((s.P(rt, 1), s.P(rt, 2)), key=lambda p: p[1])[1])
    s.place(sw, xt + 5.08, ay - 15.24, rot=0, ref_at=(xt + 2.54, ay - 20.32), val_at=(xt + 2.54, ay - 17.78))
    s.w("MB_T", sorted((s.P(rt, 1), s.P(rt, 2)), key=lambda p: p[1])[0], (xt, ay - 15.24), s.P(sw, 1))
    s2 = s.P(sw, 2)
    s.w("MB_B", s2, (s2[0], by))
    s.quiet.add("MB_T")
    # clamp
    tv = on("MB_A", "D")[0]
    xc = ax + 76.2
    s.place(tv, xc, by + 10.16, ref_at=(xc + 7.62, by + 12.7), val_at=(xc + 7.62, by + 15.24))
    t1, t2, t3 = s.P(tv, 1), s.P(tv, 2), s.P(tv, 3)
    s.w("MB_A", t1, (t1[0], ay)) if abs(t1[0] - t2[0]) > 0.1 else None
    s.w("MB_B", t2, (t2[0], by))
    iso_gnd(s, *t3)

    # connector
    j = next(r for r in on("MB_A", "J") if c.by_ref()[r]["value"] == "MODBUS")
    jx, jy = xe + 12.7, ay + 2.54
    s.place(j, jx, jy, ref_at=(jx - 2.54, jy - 8.89), val_at=(jx - 2.54, jy + 10.16))
    s.w("MB_A", (xe, ay), s.P(j, 1))
    s.w("MB_B", (xe, by), s.P(j, 2))
    g3 = s.P(j, 3)
    s.w("GNDISO", g3, (g3[0] - 5.08, g3[1]))
    s.power("GNDISO", g3[0] - 5.08, g3[1], 270, show=False)
    g4 = s.P(j, 4)
    s.w("CHASSIS", g4, (g4[0] - 7.62, g4[1]))
    s.glabel("CHASSIS", g4[0] - 7.62, g4[1], 180, "passive")
    # HF return of the isolated side to the chassis, for the PSM712
    ch = next(r for r in on("GNDISO", "C") if "CHASSIS" in c.by_ref()[r]["pins"].values())
    hx, hy = jx - 17.78, jy + 17.78
    s.place(ch, hx, hy, rot=90, ref_at=(hx, hy - 3.81), val_at=(hx, hy + 3.81))
    a1, b1 = sorted((s.P(ch, 1), s.P(ch, 2)))
    left_net = c.by_ref()[ch]["pins"]["1"] if s.P(ch, 1) == a1 else c.by_ref()[ch]["pins"]["2"]
    right_net = "CHASSIS" if left_net == "GNDISO" else "GNDISO"
    for pt, net, d in ((a1, left_net, -1), (b1, right_net, 1)):
        s.w(net, pt, (pt[0] + d * 5.08, pt[1]))
        if net == "CHASSIS":
            s.glabel(net, pt[0] + d * 5.08, pt[1], 0 if d > 0 else 180, "passive")
        else:
            s.power("GNDISO", pt[0] + d * 5.08, pt[1], 90 if d > 0 else 270, show=False)
