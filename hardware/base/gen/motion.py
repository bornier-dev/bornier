# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Motion sheets of the base board.

Two repeated sheets, drawn once and placed four times (KiCad hierarchical sheets): a drive port
with its own RS-422 drivers, and an encoder port. A flat sheet holds the supply of the drive ports (VIN OUT) and the probe input.
Called by schematic.py; the parts and their connections come from circuit.py, where each
instance is a group of parts created in the same order.
"""
import re

from circuit import c
from kicadgen.schematic import g

GLOBAL = {"+VIN_OUT", "CHASSIS", "PROBE_IN"}   # nets shared across sheets or instances: global labels


def on(net, prefix="", group=None):
    """References of the parts with a pin on `net`, optionally filtered by prefix and group."""
    return [p["ref"] for p in c.parts if net in p["pins"].values() and p["ref"].startswith(prefix)
            and (group is None or group in (p["group"], p["also"]))]


def put_label(s, net, x, y, rot):
    if net in GLOBAL:
        s.glabel(net, x, y, rot, "passive")
    else:
        s.label(net, x, y, rot)


def stub(s, pt, net, dx, kind="label"):
    """Short horizontal wire from a pin, ending on a label, a hierarchical label or a power symbol."""
    x, y = pt
    s.w(net, (x, y), (x + dx, y))
    rot = 0 if dx > 0 else 180
    if kind == "label":
        put_label(s, net, x + dx, y, rot)
    elif kind in ("input", "output", "bidirectional"):
        s.hlabel(net, x + dx, y, rot, kind)
    elif kind == "glabel_out":
        s.glabel(net, x + dx, y, rot, "output")
    elif kind == "glabel_in":
        s.glabel(net, x + dx, y, rot, "input")
    elif kind == "GND":
        s.power(kind, x + dx, y, 90 if dx > 0 else 270)
    else:
        s.power(kind, x + dx, y, 270 if dx > 0 else 90)


def vr(s, ref, x, top, rot=0, dx=1.905):
    """Vertical two-pin part, upper pin at (x, top)."""
    s.place(ref, x, top + 3.81, rot=rot, ref_at=(x + dx, top + 2.54), val_at=(x + dx, top + 5.08))


def hr(s, ref, x, y, rot=90, ref_at=None, val_at=None):
    """Horizontal two-pin part centred on (x, y); rot 90: pin 1 on the left, 270: on the right."""
    s.place(ref, x, y, rot=rot, ref_at=ref_at or (x - 3.81, y - 2.54), val_at=val_at or (x - 2.54, y + 3.81))


def parallel(s, first, second, dy=7.62, ref_at=None, val_at=None):
    """Place the horizontal resistor `second` dy below `first` (above if dy < 0), same orientation, and join
    their ends."""
    pins = c.by_ref()[first]["pins"]
    left, right = sorted(("1", "2"), key=lambda n: s.P(first, n)[0])
    (x1, y1), (x2, _) = s.P(first, left), s.P(first, right)
    xc, y = (x1 + x2) / 2, y1 + dy
    hr(s, second, xc, y, rot=90 if left == "1" else 270, ref_at=ref_at or (xc - 3.81, y - 2.54),
       val_at=val_at or (xc - 2.54, y + 3.81))
    s.w(pins[left], (x1, y1), s.P(second, left))
    s.w(pins[right], (x2, y1), s.P(second, right))


def instances(s, base, prefix, pinmaps):
    """Declare the instances of a repeated sheet drawn from group base + '0'."""
    first = c.members(f"{base}0")
    s.repeat([(f"{prefix} {k}", dict(zip(first, c.members(f"{base}{k}"))), pm) for k, pm in enumerate(pinmaps)])


def limited_supply(s, u, x, y, vs_draw, out_net, vs_caps=None):
    """TPS1H000 block. vs_draw(s, point) draws the supply side of the VS line ending at point.
    vs_caps: its two VS capacitors, when other switches share its VS net."""
    P = lambda n: s.P(u, n)  # noqa: E731
    s.place(u, x, y, ref_at=(x - 5.08, y - 13.97), val_at=(x - 5.08, y - 11.43))
    r_dly, r_cl = on(f"{u}_DLY", "R")[0], on(f"{u}_CL", "R")[0]
    vs = c.by_ref()[u]["pins"]["8"]
    c_vs, c_vs2 = vs_caps or (next(r for r in on(vs, "C") if c.by_ref()[r]["value"] == "100nF"),
                              next(r for r in on(vs, "C") if c.by_ref()[r]["value"] == "1µF 50V"))
    c_out = on(out_net, "C")[0]
    # VS with its decoupling
    vx, vy = P(8)
    s.w(vs, (vx, vy), (vx - 22.86, vy))
    vr(s, c_vs, vx - 22.86, vy)
    s.rail("GND", *s.P(c_vs, 2))
    vr(s, c_vs2, vx - 15.24, vy)
    s.rail("GND", *s.P(c_vs2, 2))
    vs_draw(s, (vx - 22.86, vy))
    # IN high: always on; DIAG_EN low: no open-load detection (protections stay active)
    (ix, iy), (dx_, dy) = P(1), P(2)
    s.w("+3V3", (ix, iy), (ix - 2.54, iy))
    s.power("+3V3", ix - 2.54, iy)
    s.w("GND", (dx_, dy), (dx_ - 5.08, dy))
    s.power("GND", dx_ - 5.08, dy, 270, show=False)
    # DELAY pulled up (auto-retry), CL resistor to ground
    lx, ly = P(5)
    hr(s, r_dly, lx - 7.62, ly, rot=270, ref_at=(lx - 11.43, ly + 3.81), val_at=(lx - 6.35, ly + 3.81))
    s.w(f"{u}_DLY", (lx, ly), s.P(r_dly, 1))
    s.power("+3V3", *s.P(r_dly, 2), 90)
    cx_, cy_ = P(4)
    s.w(f"{u}_CL", (cx_, cy_), (cx_ - 2.54, cy_), (cx_ - 2.54, cy_ + 2.54))
    vr(s, r_cl, cx_ - 2.54, cy_ + 2.54, dx=-5.08)
    s.rail("GND", *s.P(r_cl, 2))
    # thermal pad and ground
    gx, gy = P(6)
    s.w("GND", (gx, gy), (gx, gy + 2.54), (P(9)[0], gy + 2.54), P(9))
    s.power("GND", gx, gy + 2.54)
    # output with its decoupling
    ox, oy = P(7)
    s.w(out_net, (ox, oy), (ox + 30.48, oy))
    put_label(s, out_net, ox + 30.48, oy, 0)
    vr(s, c_out, ox + 25.4, oy)
    s.rail("GND", *s.P(c_out, 2))
    s.quiet.update({f"{u}_DLY", f"{u}_CL"})


def rj45(s, j, x, y, port, mirror=False):
    """One port (unit A or B) of a dual RJ45, with short stubs: labels on its signals, power symbols on GND.
    The shield is drawn with port A."""
    s.place(j, x, y, mirror="y" if mirror else None, ref_at=(x - 5.08, y - 15.24), val_at=(x - 5.08, y - 12.7),
            unit="AB".index(port) + 1)
    d = -5.08 if mirror else 5.08
    for k, net in c.by_ref()[j]["pins"].items():
        if not (k.startswith(port) or (k == "SH" and port == "A")):
            continue
        pt = s.P(j, k)
        if k == "SH":
            s.w(net, pt, (pt[0], pt[1] + 2.54))
            s.glabel(net, pt[0], pt[1] + 2.54, 270, "passive")
        elif net == "GND":
            stub(s, pt, net, d, "GND")
        else:
            stub(s, pt, net, d)


# ------------------------------------------------------------------------------------------------
def opto_input(s, u, a_pin, k_pin, r_net, led_net, in_net):
    """Input chain of an optocoupler: series R, indicator LED, opto LED, protection diode across both.

    Returns the free end of the series resistor (supply side) and the junction on the input line.
    """
    ax, ay = s.P(u, a_pin)
    kx, ky = s.P(u, k_pin)
    oy = (ay + ky) / 2
    led = next(d for d in on(r_net, "D") if c.by_ref()[d]["sym"] == "Device:LED")
    dio = next(d for d in on(r_net, "D") if c.by_ref()[d]["sym"] == "Device:D")
    res, *more = on(r_net, "R")
    s.place(led, ax - 6.35, ay, rot=180, ref_at=(ax - 8.89, ay - 5.08), val_at=(ax - 8.89, ay - 2.54))
    s.w(led_net, s.P(led, 1), (ax, ay))
    xn = ax - 13.97
    s.place(dio, xn, oy, rot=270, ref_at=(xn - 6.35, oy + 1.27), show_value=False)
    if more:                                    # series resistor split in two, in parallel, above the first
        hr(s, res, ax - 21.59, ay, rot=90, ref_at=(ax - 24.77, ay - 3.81), val_at=(ax - 24.77, ay - 6.35))
        for r in more:
            parallel(s, res, r, dy=-10.16, ref_at=(ax - 25.4, ay - 12.7), val_at=(ax - 20.32, ay - 12.7))
    else:
        hr(s, res, ax - 21.59, ay, rot=90, ref_at=(ax - 25.4, ay - 2.54), val_at=(ax - 21.59, ay - 2.54))
    s.w(r_net, s.P(res, 2), (xn, ay), s.P(led, 2))
    s.w(r_net, (xn, ay), s.P(dio, 1))
    s.w(in_net, (kx, ky), (xn, ky), s.P(dio, 2))
    s.quiet.update({r_net, led_net})
    return s.P(res, 1), (xn, ky)


def drive_port(prj):
    """One drive port and its two RS-422 drivers; drawn for axis 0, placed for the four axes."""
    s = prj.sheet("Drive 0", "drive.kicad_sch", "Drive port: STEP/DIR, ENA, ALM (4 instances)")
    s.alias = lambda net: re.sub(r"(STEP|DIR|ENA|ALM)0", r"\1", net)
    s.text("DRIVE PORT", 20.32, 17.78, 2.54, True)
    s.text("Placed four times: axes 0 to 3.\n"
           "RS-422 STEP/DIR (5 V), ENA open drain to 0 V, ALM through an optocoupler fed by +VIN_OUT.\n"
           "Wiring of a drive: COM+ of its inputs on +VIN_OUT (pin 7), servo-on on ENA (pin 4),\n"
           "its floating alarm output between ALM (pin 5) and 0 V (pin 8).", 20.32, 25.4)
    u = next(r for r in on("STEP0", "U", "drv0") if c.by_ref()[r]["value"] == "SN75ALS191DR")
    cx, cy = 106.68, 104.14
    s.place(u, cx, cy, ref_at=(cx + 2.54, cy - 12.7), val_at=(cx + 2.54, cy - 15.24))
    pins = c.by_ref()[u]["pins"]
    for n in ("2", "3"):                        # inputs with their pull-downs
        x, y = s.P(u, n)
        net = pins[n]
        rpd = next(r for r in on(net, "R", "drv0"))
        s.w(net, (x, y), (x - 25.4, y))
        s.hlabel(net, x - 25.4, y, 180, "input")
        s.w(net, (x - 7.62, y), (x - 7.62, y + 2.54), (x - 10.16, y + 2.54))
        hr(s, rpd, x - 13.97, y + 2.54, rot=270, ref_at=(x - 33.02, y + 3.81), val_at=(x - 27.94, y + 3.81))
        s.power("GND", *s.P(rpd, 2), 90, show=False)
    for n in ("8", "7", "6", "5"):
        stub(s, s.P(u, n), pins[n], 7.62)
    s.rail("+5V", *s.P(u, "1"))
    s.rail("GND", *s.P(u, "4"))
    cd = on("+5V", "C", "drv0")[0]
    vx, vy = s.P(u, "1")
    vr(s, cd, vx - 10.16, vy - 15.24)
    s.power("+5V", *s.P(cd, 1))
    s.rail("GND", *s.P(cd, 2))
    s.text("Pull-downs: STEP and DIR stay low\nwhile the MCU pins are not configured.", 40.64, 182.88)

    for n in (0,):
        yc = 127.0
        j = next(r for r in on(f"STEP{n}_P", "J"))
        rj45(s, j, 381.0, yc, "A", mirror=True)
        # ESD of STEP and DIR next to the jack (flow-through on the board)
        esd = next(r for r in on(f"STEP{n}_P", "U") if c.by_ref()[r]["value"] == "TPD4E05U06DQAR")
        ex0, ey0 = 345.44, yc + 30.48
        s.place(esd, ex0, ey0, ref_at=(ex0 + 3.81, ey0 - 8.89), val_at=(ex0 + 3.81, ey0 - 11.43))
        for pin in ("1", "2", "4", "5"):
            px_, py_ = s.P(esd, pin)
            d = -5.08 if px_ < ex0 else 5.08
            stub(s, (px_, py_), c.by_ref()[esd]["pins"][pin], d)
        for pin in ("10", "9", "7", "6"):     # flow-through: the NC pin opposite each line carries it
            s.label(c.by_ref()[esd]["pins"][pin], *s.P(esd, pin), tag=f"{esd}.{pin}")
        s.rail("GND", *s.P(esd, 3))
        # ENA: open drain
        q = on(f"ENA{n}_OUT", "Q")[0]
        qx, qy = 314.96, yc - 17.78
        s.place(q, qx, qy, ref_at=(qx + 5.08, qy - 1.27), val_at=(qx + 5.08, qy + 1.27))
        gx, gy = s.P(q, 1)
        rq = next(r for r in on(f"ENA{n}", "R"))
        s.w(f"ENA{n}", (gx, gy), (gx - 27.94, gy))
        s.hlabel(f"ENA{n}", gx - 27.94, gy, 180, "input")
        rq = next(r for r in on(f"ENA{n}", "R") if c.by_ref()[r]["value"] == "100k")
        vr(s, rq, gx - 7.62, gy, dx=-5.08)
        s.rail("GND", *s.P(rq, 2))
        # indicator on the gate side: nothing reaches the drive line
        led = next(d for d in on(f"ENA{n}_LA", "D"))
        rl = on(f"ENA{n}_LA", "R")[0]
        vr(s, rl, gx - 17.78, gy, dx=-5.08)
        s.place(led, gx - 17.78, s.P(rl, 2)[1] + 3.81, rot=90, ref_at=(gx - 25.4, s.P(rl, 2)[1] + 2.54),
                val_at=(gx - 25.4, s.P(rl, 2)[1] + 5.08))
        s.w(f"ENA{n}_LA", s.P(rl, 2), s.P(led, 2))
        s.rail("GND", *s.P(led, 1))
        s.quiet.add(f"ENA{n}_LA")
        dx_, dy_ = s.P(q, 3)
        s.w(f"ENA{n}_OUT", (dx_, dy_), (dx_ + 15.24, dy_))
        s.label(f"ENA{n}_OUT", dx_ + 15.24, dy_)
        # TVS to GND: clamps the inductive kick of a relay-type drive input, and ESD
        dc = next(d for d in on(f"ENA{n}_OUT", "D") if c.by_ref()[d]["sym"] == "Device:D_TVS")
        s.place(dc, dx_ + 7.62, dy_ + 3.81, rot=270, ref_at=(dx_ + 10.16, dy_ + 2.54), val_at=(dx_ + 10.16, dy_ + 5.08))
        s.rail("GND", *sorted((s.P(dc, 1), s.P(dc, 2)), key=lambda p: p[1])[1])
        s.rail("GND", *s.P(q, 2))
        # ALM: optocoupler
        uo = on(f"ALM{n}_IN", "U")[0]
        ox, oy = 256.54, yc + 12.7
        s.place(uo, ox, oy, ref_at=(ox - 2.54, oy - 6.35), val_at=(ox - 2.54, oy + 7.62))
        rend, jin = opto_input(s, uo, 1, 2, f"ALM{n}_R", f"ALM{n}_LED", f"ALM{n}_IN")
        stub(s, rend, "+VIN_OUT", -5.08)
        s.w(f"ALM{n}_IN", jin, (jin[0], jin[1] + 5.08), (jin[0] - 7.62, jin[1] + 5.08))
        s.label(f"ALM{n}_IN", jin[0] - 7.62, jin[1] + 5.08, 180)
        cx_, cy_ = s.P(uo, 4)
        rp = next(r for r in on(f"ALM{n}", "R"))
        s.w(f"ALM{n}", (cx_, cy_), (cx_ + 20.32, cy_))
        s.hlabel(f"ALM{n}", cx_ + 20.32, cy_, 0, "output")
        vr(s, rp, cx_ + 7.62, cy_ - 7.62, rot=180, dx=2.54)
        s.power("+3V3", *s.P(rp, 2))
        ex, ey = s.P(uo, 3)
        s.w("GND", (ex, ey), (ex + 2.54, ey))
        s.power("GND", ex + 2.54, ey)

    pinmap = lambda k: {sig: f"{sig}{k}" for sig in ("STEP", "DIR", "ENA", "ALM")}  # noqa: E731
    instances(s, "drv", "Drive", [pinmap(k) for k in range(4)])


def drive_supply_probe(prj):
    s = prj.sheet("Drive supply and probe", "drive_supply.kicad_sch", "VIN OUT of the drive ports; probe input")
    s.text("DRIVE SUPPLY AND PROBE", 20.32, 17.78, 2.54, True)
    u = on("+VIN_OUT", "U")[0]
    s.text("+VIN_OUT: the supply voltage (12 or 24 V) on the drive, probe, emergency stop and spindle\n"
           "connectors, 480 mA limit, auto-retry; no open-load detection (DIAG_EN low).", 25.4, 38.1)

    def from_24(s_, pt):
        s_.rail("+VIN", *pt, drop=2.54)
    limited_supply(s, u, 76.2, 66.04, from_24, "+VIN_OUT")

    up = on("PROBE_LED", "U")[0]
    px, py = 254.0, 66.04
    s.text("PROBE: NPN sensor or dry contact between PROBE and 0 V;\nPROBE goes low (inverting).\n"
           "Terminal block shared with the emergency stop (Safety sheet).", 190.5, 38.1)
    s.place(up, px, py, ref_at=(px - 5.08, py - 7.62), val_at=(px - 5.08, py - 10.16))
    rend, jin = opto_input(s, up, 1, 3, "PROBE_R", "PROBE_LED", "PROBE_IN")
    s.w("PROBE_IN", jin, (jin[0] - 15.24, jin[1]))
    s.glabel("PROBE_IN", jin[0] - 15.24, jin[1], 180, "input")
    stub(s, rend, "+VIN_OUT", -7.62)
    vx, vy = s.P(up, 6)
    s.w("+3V3", (vx, vy), (vx + 5.08, vy))
    s.power("+3V3", vx + 5.08, vy)
    cp = next(r for r in on("+3V3", "C") if c.by_ref()[r]["block"].startswith("Probe"))
    vr(s, cp, vx + 38.1, vy)
    s.w("+3V3", (vx + 5.08, vy), s.P(cp, 1))
    s.rail("GND", *s.P(cp, 2))
    stub(s, s.P(up, 5), "PROBE", 17.78, "glabel_out")
    # shunt across the opto LED: a leakage below about 0.3 mA does not trip the probe
    rsh = next(r for r in on("PROBE_LED", "R") if "PROBE_IN" in c.by_ref()[r]["pins"].values())
    sx, sy = px - 12.7, py + 15.24
    vr(s, rsh, sx, sy)
    top_net = c.by_ref()[rsh]["pins"]["1"]
    bot_net = c.by_ref()[rsh]["pins"]["2"]
    stub(s, s.P(rsh, 1), top_net, -5.08)
    stub(s, s.P(rsh, 2), bot_net, -5.08)
    s.label("PROBE_LED", *s.P(up, 1))
    gx, gy = s.P(up, 4)
    s.w("GND", (gx, gy), (gx + 2.54, gy), (gx + 2.54, gy + 2.54))
    s.power("GND", gx + 2.54, gy + 2.54)


# ------------------------------------------------------------------------------------------------
def encoder(prj):
    """One encoder port; drawn for encoder 0, placed for encoders 0 to 3."""
    n = 0
    s = prj.sheet("Encoder 0", "encoder.kicad_sch", "Encoder port: RS-422, TTL or HTL, 5 V or VIN (4 instances)")
    s.alias = lambda net: re.sub(r"^(ENC|VENC|VSEL|VSD)0_?", lambda m: "" if m.group(1) == "ENC" else m.group(1), net)
    s.text("ENCODER PORT", 20.32, 17.78, 2.54, True)
    s.text("Placed four times (encoders 0 to 3).\n"
           "Per line: 3.3 k series, Schottky clamp to 0..5 V, bias 4.7 k / 4.7 k at the receiver: an open\n"
           "line sits at 2.5 V, so a single-ended encoder (TTL, HTL, open collector) works with its - line\n"
           "unconnected. + lines pulled up to the encoder supply. TERM switches: on for RS-422 only, set with the encoder off.", 20.32, 25.4)
    venc, vsel = f"VENC{n}", f"VSEL{n}"
    # supply: jumper 5 V / VIN, current-limited switch
    jp = on(vsel, "JP")[0]
    u = next(r for r in on(f"VSD{n}", "U"))
    jx, jy = 33.02, 63.5
    s.place(jp, jx, jy, mirror="y", ref_at=(jx - 2.54, jy - 6.35), val_at=(jx - 7.62, jy + 6.35))
    p1, p2, p3 = s.P(jp, 1), s.P(jp, 2), s.P(jp, 3)
    s.w("+5V", p1, (p1[0] + 2.54, p1[1]), (p1[0] + 2.54, p1[1] - 2.54))
    s.power("+5V", p1[0] + 2.54, p1[1] - 2.54)
    s.w("+VIN", p3, (p3[0] + 2.54, p3[1]), (p3[0] + 2.54, p3[1] + 2.54))
    s.power("+VIN", p3[0] + 2.54, p3[1] + 2.54, 180)

    def from_jumper(s_, pt):
        # Schottky after the jumper: nothing flows back through the TPS1H000, whatever the position
        d = on(f"VSD{n}", "D")[0]
        s_.place(d, p2[0] + 10.16, p2[1], rot=180, ref_at=(p2[0] + 10.16, p2[1] - 3.81),
                 val_at=(p2[0] + 10.16, p2[1] + 3.81))
        a_, k_ = sorted((s_.P(d, 1), s_.P(d, 2)))
        s_.w(vsel, p2, a_)
        s_.w(f"VSD{n}", k_, (pt[0], p2[1]), pt)
        # VS is driven only when the shunt is fitted
        s_.power("PWR_FLAG", pt[0], p2[1])
    limited_supply(s, u, 101.6, p2[1] + 6.35, from_jumper, venc)
    s.text("Shunt 1-2: 5 V, 2-3: VIN (12 or 24 V),\nnone: no supply. 218 mA limit.", 20.32, 73.66)

    # connector
    j = next(r for r in on(f"ENC{n}_AP", "J"))
    rj45(s, j, 33.02, 165.1, "B")

    # receiver
    rx = next(r for r in on(f"ENC{n}_A", "U") if c.by_ref()[r]["value"] == "AM26LV32EIDR")
    rxx, rxy = 233.68, 165.1
    s.place(rx, rxx, rxy, ref_at=(rxx + 2.54, rxy - 27.94), val_at=(rxx + 2.54, rxy - 30.48))
    s.rail("+3V3", *s.P(rx, 16))
    s.rail("GND", *s.P(rx, 8))
    gx, gy = s.P(rx, 4)
    s.w("+3V3", (gx, gy), (gx - 5.08, gy))
    s.power("+3V3", gx - 5.08, gy, 90)
    gx, gy = s.P(rx, 12)
    s.w("GND", (gx, gy), (gx - 5.08, gy))
    s.power("GND", gx - 5.08, gy, 270, show=False)
    cd = next(r for r in on("+3V3", "C", "enc0"))
    vr(s, cd, rxx + 12.7, rxy - 33.02)
    s.power("+3V3", *s.P(cd, 1))
    s.rail("GND", *s.P(cd, 2))
    pins = c.by_ref()[rx]["pins"]
    # the channels of each line as wired in circuit.py
    chan = {ch: next((a, b, y) for a, b, y in (("2", "1", "3"), ("6", "7", "5"), ("10", "9", "11"), ("14", "15", "13"))
                     if pins.get(a) == f"ENC{n}_{ch}P_R") for ch in "ABZ"}
    for ch in "ABZ":
        k = chan[ch][2]
        stub(s, s.P(rx, k), pins[k], 7.62, "output")

    # channel networks: + line at y, - line at y + 25.4, channels 50.8 apart
    x0 = 66.04
    lines = []
    nx = x0 + 45.72
    for i, ch in enumerate("ABZ"):
        yp = 104.14 + 50.8 * i
        for pol, y in (("P", yp), ("N", yp + 25.4)):
            line, node = f"ENC{n}_{ch}{pol}", f"ENC{n}_{ch}{pol}_R"
            rs = next(r for r in on(node, "R") if c.by_ref()[r]["value"] == "3.3k")
            ru = next(r for r in on(node, "R") if "+5V" in c.by_ref()[r]["pins"].values())
            rd = next(r for r in on(node, "R") if "GND" in c.by_ref()[r]["pins"].values())
            d = on(node, "D")[0]
            s.w(line, (x0, y), (x0 + 30.48, y))
            s.label(line, x0, y, 180)
            if pol == "P":
                rpu = next(r for r in on(line, "R") if venc in c.by_ref()[r]["pins"].values())
                vr(s, rpu, x0 + 7.62, y - 7.62, rot=180)
                s.w(venc, s.P(rpu, 2), (x0 + 7.62, y - 10.16))
                s.label(venc, x0 + 7.62, y - 10.16, 90)
                sw = on(line, "SW")[0]
                rt = on(f"ENC{n}_{ch}T", "R")[0]
                # one switch of the DIP per pair, vertical: upper pin on the line, lower pin to the termination
                k = "ABZ".index(ch) + 1
                s.place(sw, x0 + 17.78, y + 5.08, rot=270, unit=k, ref_at=(x0 + 19.05, y + 3.81),
                        val_at=(x0 + 19.05, y + 6.35), show_value=k == 1)
                assert s.P(sw, k) == (g(x0 + 17.78), g(y)), "DIP switch: pin k expected on the line"
                vr(s, rt, x0 + 13.97, y + 10.16, dx=-5.08)
                s.w(f"ENC{n}_{ch}T", s.P(sw, 9 - k), s.P(rt, 1))
                s.w(f"ENC{n}_{ch}N", s.P(rt, 2), (x0 + 13.97, y + 25.4))
                s.quiet.add(f"ENC{n}_{ch}T")
            hr(s, rs, x0 + 34.29, y, rot=90 if c.by_ref()[rs]["pins"]["1"] == line else 270,
               ref_at=(x0 + 31.75, y - 2.54), val_at=(x0 + 31.75, y + 3.81))
            s.w(node, (x0 + 38.1, y), (nx + 33.02, y))
            s.quiet.add(node)
            vr(s, ru, nx, y - 7.62, rot=180 if c.by_ref()[ru]["pins"]["1"] == node else 0)
            s.power("+5V", *s.P(ru, 2 if c.by_ref()[ru]["pins"]["1"] == node else 1))
            vr(s, rd, nx + 5.08, y, rot=0 if c.by_ref()[rd]["pins"]["1"] == node else 180)
            s.power("GND", *s.P(rd, 2 if c.by_ref()[rd]["pins"]["1"] == node else 1))
            # clamp above the line: COM on the line, anode to GND (left), cathode to +5V (right)
            s.place(d, nx + 20.32, y - 5.08, ref_at=(nx + 24.13, y - 1.27), val_at=(nx + 17.78, y - 8.89),
                    show_value=False)
            s.power("+5V", *s.P(d, 2), 270)
            s.power("GND", *s.P(d, 1), 270)
            lines.append((node, y))
    # fourth switch of the DIP: spare, below the Z pair
    sw = on(f"ENC{n}_AP", "SW")[0]
    s.place(sw, x0 + 17.78, 104.14 + 50.8 * 3, rot=270, unit=4, ref_at=(x0 + 19.05, 104.14 + 50.8 * 3 - 1.27),
            show_value=False)
    s.text("Spare", x0 + 21.59, 104.14 + 50.8 * 3 + 1.27)
    # fan the six lines into the receiver without crossing: among the lines going down, the
    # lowest turns first; among those going up, the highest turns first.
    targets = {f"ENC{n}_{ch}{pol}_R": s.P(rx, k) for ch, ks in ((c_, chan[c_][:2]) for c_ in "ABZ")
               for pol, k in zip("PN", ks)}
    down = [(nd, y) for nd, y in lines if targets[nd][1] > y]
    up = [(nd, y) for nd, y in lines if targets[nd][1] <= y]
    xt0 = x0 + 91.44
    for rank, (nd, y) in enumerate(down):
        xt = xt0 + 2.54 * (len(down) - 1 - rank)
        tx, ty = targets[nd]
        s.w(nd, (x0 + 78.74, y), (xt, y), (xt, ty), (tx, ty))
    for rank, (nd, y) in enumerate(up):
        xt = xt0 + 2.54 * (len(down) + rank)     # columns of their own: the lines may cross, never touch
        tx, ty = targets[nd]
        s.w(nd, (x0 + 78.74, y), (xt, y), (xt, ty), (tx, ty))

    instances(s, "enc", "Encoder", [{ch: f"ENC{k}_{ch}" for ch in "ABZ"} for k in range(4)])
