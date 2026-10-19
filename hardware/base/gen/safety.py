# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Safety sheet: emergency stop state input, external watchdog on the MCU reset.

Called by schematic.py; the parts and their connections come from circuit.py.
"""
from circuit import c
from motion import on, stub, vr, hr, parallel


def safety(prj):
    s = prj.sheet("Safety", "safety.kicad_sch", "Emergency stop state, external watchdog")
    s.text("SAFETY", 20.32, 17.78, 2.54, True)
    s.text("The emergency stop chain and the STO stay hard-wired outside Bornier: this sheet only reads their state\n"
           "and makes sure a stuck firmware cannot keep an output active.", 20.32, 25.4)
    B = c.by_ref()

    # --- emergency stop state ---------------------------------------------------------------------
    u = on("ESTOP_LED", "U")[0]
    ux, uy = 152.4, 86.36
    s.place(u, ux, uy, ref_at=(ux - 2.54, uy - 7.62), val_at=(ux - 2.54, uy - 10.16))
    ax, ay = s.P(u, 1)
    kx, ky = s.P(u, 2)
    rs = next(r for r in on("ESTOP_LED", "R"))
    led = on("ESTOP_LED", "D")[0]
    dio = on("ESTOP_R", "D")
    dio = next(d for d in dio if B[d]["sym"] == "Device:D")
    rin, rin2 = on("ESTOP_V", "R")
    # cathode of the opto LED to ground
    s.w("GND", (kx, ky), (kx - 2.54, ky), (kx - 2.54, ky + 2.54))
    s.power("GND", kx - 2.54, ky + 2.54, show=False)
    # shunt across the opto LED
    xs = ax - 7.62
    vr(s, rs, xs, ay, dx=1.905)
    s.rail("GND", *s.P(rs, 2))
    # indicator LED, cathode toward the opto
    xl = ax - 15.24
    s.place(led, xl, ay, rot=180, ref_at=(xl - 2.54, ay - 5.08), val_at=(xl - 2.54, ay - 2.54))
    s.w("ESTOP_LED", s.P(led, 1), (ax, ay))
    # reverse protection across both LEDs, then the series resistor
    xd = ax - 25.4
    s.place(dio, xd, ay + 3.81, rot=270, ref_at=(xd - 6.35, ay + 3.81), show_value=False)
    s.rail("GND", *s.P(dio, 2))
    hr(s, rin, ax - 35.56, ay, rot=90 if B[rin]["pins"]["1"] == "ESTOP_V" else 270,
       ref_at=(ax - 41.91, ay - 2.54), val_at=(ax - 34.29, ay - 2.54))
    parallel(s, rin, rin2)
    r_in, r_out = sorted((s.P(rin, 1), s.P(rin, 2)))
    s.w("ESTOP_R", r_out, (xd, ay), s.P(led, 2))
    s.quiet.update({"ESTOP_R", "ESTOP_LED", "ESTOP_V"})
    # connector
    j = on("ESTOP_V", "J")[0]
    jx = ax - 78.74
    s.place(j, jx, ay - 2.54, mirror="y", ref_at=(jx - 5.08, ay - 8.89), val_at=(jx - 5.08, ay + 7.62))  # pole 3 in line
    j1, j2, j3, j4 = (s.P(j, k) for k in (1, 2, 3, 4))
    s.w("ESTOP_V", j3, r_in)
    stub(s, j1, "+VIN_OUT", 5.08)
    s.w("GND", j2, (j2[0] + 1.27, j2[1]))
    s.power("GND", j2[0] + 1.27, j2[1], 90, show=False)
    s.w("PROBE_IN", j4, (j4[0] + 7.62, j4[1]))
    s.glabel("PROBE_IN", j4[0] + 7.62, j4[1], 0, "output")
    # output side: collector pulled up, low while the chain is closed
    cx_, cy_ = s.P(u, 4)
    ex, ey = s.P(u, 3)
    ru = on("ESTOP_IN", "R")[0]
    s.w("ESTOP_IN", (cx_, cy_), (cx_ + 25.4, cy_))
    s.glabel("ESTOP_IN", cx_ + 25.4, cy_, 0, "output")
    vr(s, ru, cx_ + 10.16, cy_ - 10.16, rot=180, dx=2.54)
    s.power("+3V3", *s.P(ru, 2))
    s.w("ESTOP_IN", s.P(ru, 1), (cx_ + 10.16, cy_))
    s.w("GND", (ex, ey), (ex + 2.54, ey), (ex + 2.54, ey + 2.54))
    s.power("GND", ex + 2.54, ey + 2.54, show=False)
    s.text("ESTOP: VIN from the safety relay contact (or a dry contact to VIN OUT) = run.\n"
           "ESTOP_IN low while the chain is closed: a broken wire reads as a stop.\n"
           "2 x 4.7 k series and 1 k shunt: off below 5 V, on from 9.5 V (12 V supply);\n"
           "on a 24 V supply, IEC 61131-2 type 3. 0.15 W per resistor at 30 V.",
           jx - 7.62, ay + 20.32)

    # --- external watchdog ----------------------------------------------------------------------
    u = next(r for r in on("WDI", "U") if B[r]["value"].startswith("TPS3828"))
    wx, wy = 284.48, 86.36
    s.place(u, wx, wy, ref_at=(wx - 12.7, wy - 10.16), val_at=(wx - 12.7, wy - 12.7))
    stub(s, s.P(u, 4), "WDI", -15.24, "glabel_in")
    s.rail("GND", *s.P(u, 2))
    vx, vy = s.P(u, 5)
    s.w("+3V3", (vx, vy), (vx, vy - 15.24), (vx + 22.86, vy - 15.24))
    s.power("+3V3", vx, vy - 15.24)
    cw = next(r for r in on("+3V3", "C") if B[r]["block"].startswith("Safety"))
    vr(s, cw, vx + 22.86, vy - 15.24)
    s.rail("GND", *s.P(cw, 2))
    rx, ry = s.P(u, 1)
    s.w("NRST", (rx, ry), (rx + 50.8, ry))
    s.glabel("NRST", rx + 50.8, ry, 0, "bidirectional")
    rl = on("RST_LA", "R")[0]
    dl = on("RST_LA", "D")[0]
    xr = rx + 35.56
    vr(s, rl, xr, ry - 22.86)
    s.power("+3V3", *s.P(rl, 1))
    s.place(dl, xr, ry - 7.62, rot=90, ref_at=(xr + 3.81, ry - 8.89), val_at=(xr + 3.81, ry - 6.35))
    s.w("RST_LA", s.P(rl, 2), s.P(dl, 2))
    s.w("NRST", s.P(dl, 1), (xr, ry))
    s.quiet.add("RST_LA")
    s.text("Watchdog: the firmware toggles WDI every 0.5 s or less (timeout 0.9-2.5 s); WDI left floating\n"
           "(pin not configured: reset, bootloader, debug) disables it. On a timeout it resets the MCU\n"
           "for 200 ms: every output pin goes high impedance and its pull resistor turns the output off.\n"
           "It also holds the reset while +3V3 is below 2.93 V. RESET LED: any reset (watchdog, debugger).",
           wx - 50.8, wy + 20.32)

    # --- chassis and functional earth ------------------------------------------------------------
    s.text("CHASSIS: shields of the RJ45 and of the Modbus cable. Functional earth on pin 3 (FE) of the supply\n"
           "terminal block J1; 1 nF 2 kV to 0 V at each connector row (C37 at the EtherCAT ports).", 30.48, 165.1)
    xs, ys = 50.8, 190.5
    s.w("CHASSIS", (xs, ys), (xs + 50.8, ys))
    s.glabel("CHASSIS", xs, ys, 180, "passive")
    for k, ref in enumerate(("C301", "C302")):
        x = xs + 25.4 + 12.7 * k
        vr(s, ref, x, ys)
        s.rail("GND", *s.P(ref, 2))
    # mounting holes: H1 plated on CHASSIS, H2-H4 bare
    s.place("H1", xs + 50.8, ys - 2.54, ref_at=(xs + 53.34, ys - 6.35), val_at=(xs + 53.34, ys - 3.81))
    for k, h in enumerate(("H2", "H3", "H4")):
        x = xs + 71.12 + 12.7 * k
        s.place(h, x, ys - 2.54, ref_at=(x + 2.54, ys - 6.35), val_at=(x + 2.54, ys - 3.81))
    s.text("H1-H4: M3 holes at the corners, for screws and standoffs on a panel instead of the DIN rail\n"
           "profile; clear of the profile grooves along the long edges. H1 is plated: the screw earths\n"
           "CHASSIS to the panel. Place it at the corner nearest to J1.", xs + 25.4, ys + 17.78)
