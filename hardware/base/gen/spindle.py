# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Spindle / laser sheet: 0-10 V speed reference, 5 V PWM, enable and direction open drain.

Called by schematic.py; the parts and their connections come from circuit.py.
"""
from circuit import c
from motion import on, stub, vr, hr


def spindle(prj):
    s = prj.sheet("Spindle", "spindle.kicad_sch", "Spindle or laser: 0-10 V, PWM, enable, direction")
    s.text("SPINDLE / LASER", 20.32, 17.78, 2.54, True)
    s.text("A machine has a spindle or a laser: the outputs are shared.\n"
           "0-10 V: VFD speed reference. PWM: 5 V push-pull (laser TTL input or PWM spindle).\n"
           "EN, DIR: 55 V open drain to 0 V, for a VFD input to its common or a laser gate with its own pull-up;\n"
           "a TVS clamps the kick of a relay coil driven without a flyback diode.\n"
           "Each digital output has a LED that shows its real state.", 20.32, 25.4)

    # --- 0-10 V ------------------------------------------------------------------------------------
    u = next(r for r in on("SP_DAC", "U"))
    cx, cy = 132.08, 83.82
    s.place(u, cx, cy, ref_at=(cx - 5.08, cy - 15.24), val_at=(cx - 5.08, cy - 17.78))
    P = lambda n: s.P(u, n)  # noqa: E731
    rin = next(r for r in on("SP_DAC", "R") if "SPINDLE_AOUT" in c.by_ref()[r]["pins"].values())
    rpd = next(r for r in on("SP_DAC", "R") if r != rin)
    cin = on("SP_DAC", "C")[0]
    ax, ay = P(3)
    hr(s, rin, ax - 27.94, ay, rot=90 if c.by_ref()[rin]["pins"]["1"] == "SPINDLE_AOUT" else 270)
    a, b = sorted((s.P(rin, 1), s.P(rin, 2)))
    s.w("SPINDLE_AOUT", a, (a[0] - 10.16, ay))
    s.glabel("SPINDLE_AOUT", a[0] - 10.16, ay, 180, "input")
    s.w("SP_DAC", b, (ax, ay))
    vr(s, cin, ax - 17.78, ay)
    s.rail("GND", *s.P(cin, 2))
    vr(s, rpd, ax - 10.16, ay)
    s.rail("GND", *s.P(rpd, 2))
    # feedback under the body
    nx, ny = P(2)
    ox, oy = P(1)
    rf = next(r for r in on("SP_FB", "R") if c.by_ref()[r]["value"] == "10k")
    rg = next(r for r in on("SP_FB", "R") if c.by_ref()[r]["value"] == "4.7k")
    yf = cy + 17.78
    s.w("SP_FB", (nx, ny), (nx - 2.54, ny), (nx - 2.54, yf))
    hr(s, rf, cx, yf, rot=270 if c.by_ref()[rf]["pins"]["1"] == "SP_AOUT" else 90,
       ref_at=(cx - 3.81, yf - 2.54), val_at=(cx - 2.54, yf + 3.81))
    fa, fb = sorted((s.P(rf, 1), s.P(rf, 2)))
    s.w("SP_FB", (nx - 2.54, yf), fa)
    s.label("SP_FB", nx, yf)
    vr(s, rg, nx - 2.54, yf, dx=-5.08)
    s.rail("GND", *s.P(rg, 2))
    gx4, gy4 = P(4)
    s.w("GND", (gx4, gy4), (gx4, gy4 + 2.54))
    s.power("GND", gx4, gy4 + 2.54, show=False)
    # unused half: grounded follower
    (mx, my), (px, py), (bx, by) = P(6), P(5), P(7)
    s.w("SP_UNUSED", (mx, my), (mx - 2.54, my), (mx - 2.54, my - 7.62), (bx + 2.54, my - 7.62), (bx + 2.54, by), (bx, by))
    s.w("GND", (px, py), (px - 5.08, py))
    s.power("GND", px - 5.08, py, 270, show=False)
    s.quiet.update({"SP_UNUSED", "SP_FB", "SP_OA", "SP_DAC"})
    # output
    rout = next(r for r in on("SP_AOUT", "R") if c.by_ref()[r]["value"] == "120")
    tvs = on("SP_AOUT", "D")[0]
    hr(s, rout, ox + 15.24, oy, rot=90 if c.by_ref()[rout]["pins"]["1"] == "SP_OA" else 270,
       ref_at=(ox + 12.7, oy - 2.54), val_at=(ox + 12.7, oy - 5.08))
    s.w("SP_OA", (ox, oy), sorted((s.P(rout, 1), s.P(rout, 2)))[0])
    ro = sorted((s.P(rout, 1), s.P(rout, 2)))[1]
    # gain set from SP_AOUT, after the 120 ohm; 470 pF from the op amp output closes the loop at HF
    s.w("SP_AOUT", fb, (ro[0] + 2.54, yf), (ro[0] + 2.54, oy))
    cf = on("SP_OA", "C")[0]
    vr(s, cf, ox + 3.81, oy)
    cfb = s.P(cf, 2)
    s.w("SP_FB", cfb, (cfb[0] + 2.54, cfb[1]))
    s.label("SP_FB", cfb[0] + 2.54, cfb[1])
    s.w("SP_AOUT", ro, (ro[0] + 15.24, oy))
    s.label("SP_AOUT", ro[0] + 15.24, oy)
    s.place(tvs, ro[0] + 7.62, oy + 3.81, rot=270, ref_at=(ro[0] + 10.16, oy + 3.81), val_at=(ro[0] + 10.16, oy + 6.35))
    s.rail("GND", *(sorted((s.P(tvs, 1), s.P(tvs, 2)), key=lambda p: p[1])[1]))
    # current limit: PNP across the 120 ohm, collector into SP_FB
    q = on("SP_OA", "Q")[0]
    lo = sorted((s.P(rout, 1), s.P(rout, 2)))[0]
    xq, yq = ro[0], oy - 7.62                   # base down, emitter left, collector right
    s.place(q, xq, yq, rot=90, mirror="y", ref_at=(xq + 2.54, yq - 8.89), val_at=(xq + 2.54, yq - 11.43))
    s.w("SP_AOUT", s.P(q, 1), ro)
    ex_, ey_ = s.P(q, 2)
    s.w("SP_OA", (ex_, ey_), (lo[0], ey_), lo)
    kx_, ky_ = s.P(q, 3)
    s.w("SP_FB", (kx_, ky_), (kx_ + 5.08, ky_))
    s.label("SP_FB", kx_ + 5.08, ky_)
    # supply of the op amp: +VIN, decoupled at the pin, routed over the follower of the unused half
    vx, vy = P(8)
    xv, yr = vx + 5.08, cy - 33.02
    c1, c2 = (r for r in on("+VIN", "C") if c.by_ref()[r]["block"].startswith("Spindle"))
    s.w("+VIN", (vx, vy), (xv, vy), (xv, yr), (xv - 22.86, yr))
    s.rail("+VIN", xv, yr, drop=2.54)
    vr(s, c1, xv - 7.62, yr, dx=-8.89)
    s.rail("GND", *s.P(c1, 2))
    vr(s, c2, xv - 22.86, yr, dx=-11.43)
    s.rail("GND", *s.P(c2, 2))
    s.text("0-10 V: DAC x 3.13, gain taken after the 120 ohm; load 5 k or more.\n"
           "Op amp supplied by +VIN (42 V absolute maximum): 10 V into 10 k from 10.9 V of supply,\n"
           "into 5 k from 11.2 V. The PNP limits the output current to about 5 mA.", cx - 38.1, cy + 35.56)

    # --- PWM 5 V ------------------------------------------------------------------------------------
    ub = next(r for r in on("SP_PWM_B", "U"))
    bx_, by_ = 132.08, 162.56
    s.place(ub, bx_, by_, ref_at=(bx_ + 5.08, by_ - 12.7), val_at=(bx_ + 5.08, by_ - 15.24))
    Pb = lambda n: s.P(ub, n)  # noqa: E731
    ix, iy = Pb(2)
    rpd = next(r for r in on("SPINDLE_PWM", "R"))
    s.w("SPINDLE_PWM", (ix, iy), (ix - 25.4, iy))
    s.glabel("SPINDLE_PWM", ix - 25.4, iy, 180, "input")
    vr(s, rpd, ix - 10.16, iy, dx=-5.08)
    s.rail("GND", *s.P(rpd, 2))
    ex, ey = Pb(1)
    s.w("GND", (ex, ey), (ex, ey - 2.54))
    s.power("GND", ex, ey - 2.54, 180, show=False)
    s.rail("+5V", *Pb(5))
    s.rail("GND", *Pb(3))
    cb = next(r for r in on("+5V", "C") if c.by_ref()[r]["block"].startswith("Spindle"))
    vr(s, cb, bx_ - 17.78, by_ - 22.86)
    s.power("+5V", *s.P(cb, 1))
    s.rail("GND", *s.P(cb, 2))
    yx, yy = Pb(4)
    rs = next(r for r in on("SP_PWM_B", "R") if c.by_ref()[r]["value"] == "120")
    rs2 = next(r for r in on("SP_PWM_C", "R") if r != rs)
    hr(s, rs, yx + 13.97, yy, rot=90 if c.by_ref()[rs]["pins"]["1"] == "SP_PWM_B" else 270)
    s.w("SP_PWM_B", (yx, yy), sorted((s.P(rs, 1), s.P(rs, 2)))[0])
    hr(s, rs2, yx + 21.59, yy, rot=90 if c.by_ref()[rs2]["pins"]["1"] == "SP_PWM_C" else 270)
    s.quiet.add("SP_PWM_C")
    # ESD between the two 120 ohm
    tp = next(d for d in on("SP_PWM_C", "D"))
    jx_ = sorted((s.P(rs, 1), s.P(rs, 2)))[1][0]
    s.place(tp, jx_, yy + 3.81, rot=270, ref_at=(jx_ + 2.54, yy + 3.81), val_at=(jx_ + 2.54, yy + 6.35))
    s.rail("GND", *sorted((s.P(tp, 1), s.P(tp, 2)), key=lambda p: p[1])[1])
    re = sorted((s.P(rs2, 1), s.P(rs2, 2)))[1]
    s.w("SP_PWM", re, (re[0] + 20.32, yy))
    s.label("SP_PWM", re[0] + 20.32, yy)
    rl = next(r for r in on("SP_PWM_LA", "R"))
    dl = on("SP_PWM_LA", "D")[0]
    vr(s, rl, yx + 5.08, yy)
    s.place(dl, yx + 5.08, yy + 11.43, rot=90, ref_at=(yx + 7.62, yy + 10.16), val_at=(yx + 7.62, yy + 12.7))
    s.w("SP_PWM_LA", s.P(rl, 2), s.P(dl, 2))
    s.rail("GND", *s.P(dl, 1))
    s.quiet.update({"SP_PWM_B", "SP_PWM_LA"})

    # --- EN and DIR -------------------------------------------------------------------------------
    for k, (sig, net) in enumerate((("SPINDLE_EN", "SP_EN"), ("SPINDLE_DIR", "SP_DIR"))):
        q = on(net, "Q")[0]
        qx, qy = 241.3 + 76.2 * k, 165.1
        s.place(q, qx, qy, ref_at=(qx + 5.08, qy - 1.27), val_at=(qx + 5.08, qy + 1.27))
        gx, gy = s.P(q, 1)
        rg_ = next(r for r in on(sig, "R") if c.by_ref()[r]["value"] == "100k")
        s.w(sig, (gx, gy), (gx - 27.94, gy))
        s.glabel(sig, gx - 27.94, gy, 180, "input")
        vr(s, rg_, gx - 7.62, gy, dx=-5.08)
        s.rail("GND", *s.P(rg_, 2))
        # indicator on the gate side: nothing reaches the field line
        rl = on(f"{net}_LA", "R")[0]
        led = on(f"{net}_LA", "D")[0]
        vr(s, rl, gx - 17.78, gy, dx=-5.08)
        s.place(led, gx - 17.78, s.P(rl, 2)[1] + 3.81, rot=90, ref_at=(gx - 25.4, s.P(rl, 2)[1] + 2.54),
                val_at=(gx - 25.4, s.P(rl, 2)[1] + 5.08))
        s.w(f"{net}_LA", s.P(rl, 2), s.P(led, 2))
        s.rail("GND", *s.P(led, 1))
        s.quiet.add(f"{net}_LA")
        s.rail("GND", *s.P(q, 2))
        dx_, dy_ = s.P(q, 3)
        s.w(net, (dx_, dy_), (dx_ + 20.32, dy_))
        s.label(net, dx_ + 20.32, dy_)
        tv = next(d for d in on(net, "D") if c.by_ref()[d]["sym"] == "Device:D_TVS")
        s.place(tv, dx_ + 15.24, dy_ + 3.81, rot=270, ref_at=(dx_ + 17.78, dy_ + 3.81), val_at=(dx_ + 17.78, dy_ + 6.35))
        s.rail("GND", *sorted((s.P(tv, 1), s.P(tv, 2)), key=lambda p: p[1])[1])

    # --- connector --------------------------------------------------------------------------------
    for j, jy in ((on("SP_AOUT", "J")[0], 106.68), (on("SP_PWM", "J")[0], 132.08)):
        jx = 375.92
        s.place(j, jx, jy, ref_at=(jx - 2.54, jy - 7.62), val_at=(jx - 2.54, jy + 10.16))
        for k, net in c.by_ref()[j]["pins"].items():
            pt = s.P(j, k)
            if net == "GND":
                stub(s, pt, net, -5.08, "GND")
            else:
                stub(s, pt, net, -7.62)
