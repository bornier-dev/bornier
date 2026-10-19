# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Simulation of the 24 V -> 5 V buck (TPS54360B, power sheet of the base board).

TI publishes no SPICE model that ngspice can run, so the regulator is a behavioural model built
from the datasheet (SNVSB93): fixed-frequency peak-current-mode control, gm(EA) = 350 uA/V with
a DC gain of 10 000 and 2.5 MHz unity-gain bandwidth, +-30 uA output, COMP to switch current
12 A/V, 5.5 A current limit through the COMP clamp, 135 ns minimum on-time, frequency foldback
1/2/4/8 as FB falls, OVP, pulse skipping at COMP = 0.6 V, internal soft-start.

Usage: python buck_sim.py [scenario ...]   -> results.md and figures in this folder.
"""
import os
import sys

import numpy as np

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import ngs  # noqa: E402

# Component values of the power sheet (gen/circuit.py), from the passive palette
FSW = 658e3            # RT = 100k + 47k: 92417 / 147^0.991 kHz
R_TOP = "59.1k"        # R4 + R302 = 47k + 12.1k
R_BOT = "11k"          # R5 + R303 = 10k + 1k: Vout = 0.8 x (1 + 59.1/11) = 5.10 V
R_C, C_Z = "12.1k", "50n"   # R6, C7 + C312 (2 x 100 nF in series); no pole capacitor (ceramic output)

MS, US = 1e-3, 1e-6

# Board values (circuit.py) and the uncertain ones, which the scenarios sweep.
BASE = dict(
    vin=24.0,          # source voltage
    lcable=1.5e-6,     # 24 V wiring: about 2 m of pair
    rcable=0.04,
    rfuse=0.03,        # F1, 12H1300C 3 A cold resistance (order of magnitude)
    cin=6.1e-6,        # C2 + C3 (2 x 2.2 uF 100 V, 3.6 uF at 24 V) + ceramics on the TPS1H000 VS and outputs (about 2.5 uF at 24 V)
    cbulk=47e-6,       # C1, aluminium electrolytic
    rbulk=1.0,         # C1 ESR: small 63 V part, high ESR
    lout=8.2e-6,       # L1
    rl=0.027,          # L1 DCR (MWSA1004S-8R2MT)
    cout=56e-6,        # C5 + C6: 2 x 47 uF 10 V X7R, derated at 5 V (TI uses 58.3 uF)
    resr=1.5e-3,
    ron=0.092,         # high-side switch, typical; 0.19 ohm at the hot maximum
    v0=0.586,          # COMP voltage at zero peak current (gives the TI 24 mA Eco threshold)
    vref_ss=2.2 * MS,  # soft-start ramp of the reference (2.1 ms 10-90 % at 500 kHz)
    rload=2.5,         # resistive load: 2 A
    iload=None,        # extra current load as PWL points [(t, A), ...]
    vin_pwl=None,      # source voltage as PWL points, overrides vin
    short=None,        # (t_on, t_off) of a short on the output
    t_end=4 * MS,
    t_on_src=0.0,      # source steps from 0 to vin at this time (hot plug)
    rsrc=0.0,          # source impedance (2 ohm for the IEC 61000-4-5 surge generator)
    tvs_rs=0.66,       # per diode of the back-to-back pair: SMBJ33CA, 53.3 V at 11.3 A (10/1000 us)
)


def pwl(points):
    clean, last = [], -1.0
    for t, v in points:
        t = max(t, last + 1e-9)
        clean.append(f"{t:.9g} {v:.6g}")
        last = t
    return "PWL(" + " ".join(clean) + ")"


def netlist(p):
    src = pwl(p["vin_pwl"]) if p["vin_pwl"] else pwl([(0, 0), (p["t_on_src"], 0), (p["t_on_src"] + 1 * US, p["vin"])])
    vmax = p["v0"] + 5.5 / 12
    lines = [
        "* TPS54360B buck, behavioural",
        f"Vsrc src 0 {src}",
        f"Lc src n1 {p['lcable']}",
        f"Rc n1 n2 {p['rcable'] + p['rfuse'] + p['rsrc']}",
        # D1: bidirectional TVS (two zeners anode to anode), D2: reverse polarity Schottky
        "Vtvs n2 tv 0",
        "Dt1 tv t TVSZ",
        "Dt2 0 t TVSZ",
        "Dp n2 vin SS56",
        f"Cbulk vin b1 {p['cbulk']}",
        f"Rb b1 0 {p['rbulk']}",
        f"Cin vin c1 {p['cin']}",
        "Rcin c1 0 5m",
        # power stage
        "Vsense vin swi 0",
        "S1 swi sw q 0 SWM",
        "Dc 0 sw SS56",
        f"L1 sw lo {p['lout']}",
        f"Rl lo out {p['rl']}",
        f"Co out co {p['cout']}",
        f"Rco co 0 {p['resr']}",
        f"R4 out fb {R_TOP}",
        f"R5 fb 0 {R_BOT}",
        f"Rload out 0 {p['rload']}",
        # error amplifier, compensation, clamps
        f"Vref ref 0 {pwl([(0, 0), (p['t_on_src'] + 20 * US, 0), (p['t_on_src'] + 20 * US + p['vref_ss'], 0.8)])}",
        "Bea 0 comp I = max(-30u, min(30u, 350u*(V(ref)-V(fb))))",
        "Rea comp 0 28.6Meg",
        "Cea comp 0 22p",
        f"R6 comp cz {R_C}",
        f"C7 cz 0 {C_Z}",
        "Dcx comp cmx DCL",
        f"Vcmx cmx 0 {vmax}",
        "Dcn cmn comp DCL",
        f"Vcmn cmn 0 {p['v0']}",
        # oscillator with frequency foldback: phase counts the cycles
        "Bk kf 0 V = V(fb) > 0.6 ? 1 : (V(fb) > 0.4 ? 0.5 : (V(fb) > 0.2 ? 0.25 : 0.125))",
        f"Bph 0 ph I = {FSW:.0f}*V(kf)",
        "Cph ph 0 1",
        "Bfr fr 0 V = V(ph) - floor(V(ph))",
        # PWM latch: set by the clock, reset by the current comparator after the minimum on-time
        f"Bset st 0 V = u(30n - V(fr)/({FSW:.0f}*V(kf))) * u(V(comp) - 0.6) * u(0.848 - V(fb)) * u(V(vin) - 4.3)",
        f"Brst rs 0 V = max(u(I(Vsense) - 12*(min(V(comp), {vmax}) - {p['v0']})) * u(V(fr)/({FSW:.0f}*V(kf)) - 135n),"
        " u(V(fr) - 0.97))",
        "Bq qt 0 V = V(st) + (1 - V(st)) * (1 - V(rs)) * u(V(q) - 0.5)",
        "Rq qt q 1k",
        "Cq q 0 30p",
        ".model SWM SW(Ron={} Roff=1e7 Vt=0.5 Vh=0.05)".format(p["ron"]),
        ".model SS56 D(Is=5u N=1.3 Rs=0.04 Cjo=300p M=0.5 BV=60 IBV=1m)",
        ".model TVSZ D(Is=1e-12 N=1 BV=37.5 IBV=1m Rs={})".format(p["tvs_rs"]),
        ".model DCL D(Is=1e-12 N=0.3)",
    ]
    if p["iload"]:
        lines.append(f"Iload out 0 {pwl(p['iload'])}")
    if p["short"]:
        a, b = p["short"]
        lines += [f"Vsh shc 0 {pwl([(0, 0), (a, 0), (a + 10e-9, 1), (b, 1), (b + 10e-9, 0)])}",
                  "Ssh out 0 shc 0 SSH", ".model SSH SW(Ron=5m Roff=1e7 Vt=0.5 Vh=0.1)"]
    lines += [
        ".options method=gear reltol=1e-3 abstol=1e-9 vntol=1e-5 itl4=200",
        ".save v(out) v(vin) v(n2) v(sw) v(comp) v(fb) i(L1) i(Vsense) i(Lc) i(Vtvs) v(q)",
        f".tran 5n {p['t_end']} 0 10n",
        ".end",
    ]
    return "\n".join(lines)


def simulate(**kw):
    p = dict(BASE, **kw)
    log = ngs.run(netlist(p))
    try:
        t = np.array(ngs.vec("time"))
    except KeyError:
        raise SystemExit("simulation failed:\n" + log[-3000:])
    r = {k: np.array(ngs.vec(k)) for k in ("v(out)", "v(vin)", "v(n2)", "v(comp)", "v(fb)", "l1#branch",
                                           "vsense#branch", "lc#branch", "vtvs#branch", "v(q)")}
    r["t"] = t
    return p, r




def loop_gain(rload, cout, vin=24.0, resr=BASE["resr"], mc=1.0):
    """Small-signal loop gain: fc, phase margin, gain margin.

    TI model of the datasheet (Fig. 28), plus the sampling double pole of peak current mode at
    fsw/2 (Ridley), whose Q depends on the duty cycle and on the slope compensation mc (unknown:
    mc = 1, no compensation ramp, is the worst case).
    """
    d = 5.4 / vin
    wn = np.pi * FSW
    q = 1 / (np.pi * (mc * (1 - d) - 0.5))
    cf = 1e-9
    net = "\n".join([
        "* TPS54360B small-signal loop",
        "Ebuf cb 0 comp 0 1",
        f"Rf cb cl {1 / (wn * q * cf)}", f"Lf cl cf {1 / (wn * wn * cf)}", f"Cf cf 0 {cf}",
        "Gps 0 a cf 0 12",
        f"Co a co {cout}", f"Rco co 0 {resr}", f"RL a 0 {rload}",
        "Vinj b a AC 1",
        f"R4 b fb {R_TOP}", f"R5 fb 0 {R_BOT}",
        "Gea comp 0 fb 0 350u",
        "Rea comp 0 28.6Meg", "Cea comp 0 22p",
        f"R6 comp cz {R_C}", f"C7 cz 0 {C_Z}",
        ".ac dec 200 10 1Meg", ".end"])
    ngs.run(net)
    f = np.real(np.array(ngs.vec("frequency")))
    L = -np.array(ngs.vec("v(a)")) / np.array(ngs.vec("v(b)"))
    mag, ph = 20 * np.log10(np.abs(L)), np.degrees(np.unwrap(np.angle(L)))
    i = np.argmax(mag < 0)
    fc, pm = f[i], 180 + ph[i]
    j = np.argmax(ph < -180)
    gm = -mag[j] if j else float("inf")
    return fc, pm, gm, f, mag, ph


# --------------------------------------------------------------------------------------------
# Scenarios

def window(r, a, b):
    m = (r["t"] >= a) & (r["t"] <= b)
    return {k: v[m] for k, v in r.items()}


def i2t(t, i):
    return float(np.trapezoid(i * i, t))


def surge_pwl(v_dc, v_peak, t0):
    """1.2/50 us open-circuit surge (IEC 61000-4-5) added to the 24 V supply."""
    ts = np.concatenate([np.linspace(0, 1.2e-6, 7), np.linspace(1.5e-6, 400e-6, 120)])
    tau = 50e-6 / np.log(2)
    vs = np.where(ts <= 1.2e-6, ts / 1.2e-6, np.exp(-(ts - 1.2e-6) / tau))
    return [(0, v_dc)] + [(t0 + t, v_dc + v_peak * v) for t, v in zip(ts, vs)] + [(t0 + 1e-3, v_dc)]


def scenarios():
    out = []

    # 1. Start-up at 24 V and at 19.2 V, 2.5 A resistive load (sized load of the 5 V rail)
    for vin in (19.2, 24.0, 30.0):
        p, r = simulate(vin=vin, rload=2.0, t_end=4 * MS)
        w = window(r, 3.5 * MS, 4 * MS)
        vo = r["v(out)"]
        out.append(dict(name=f"start-up {vin} V, 2.5 A", vout=w["v(out)"].mean(), ripple=np.ptp(w["v(out)"]),
                        overshoot=vo.max(), il_max=r["l1#branch"].max(),
                        t_rise=r["t"][np.argmax(vo > 4.5)] - r["t"][np.argmax(vo > 0.5)],
                        iin_max=r["lc#branch"].max(), vin_max=r["v(vin)"].max()))

    # 2. Load steps 0.5 -> 2.5 -> 0.5 A, nominal and derated output capacitance
    for vin in (19.2, 24.0, 30.0):
        for cout in (56e-6, 34e-6):
            steps = [(0, 0), (3 * MS, 0), (3 * MS + 1 * US, 2.0), (3.5 * MS, 2.0), (3.5 * MS + 1 * US, 0)]
            p, r = simulate(vin=vin, rload=10.0, cout=cout, iload=steps, t_end=4 * MS)
            w = window(r, 2.9 * MS, 4 * MS)
            out.append(dict(name=f"load step 0.5-2.5-0.5 A, {vin} V, Cout {cout * 1e6:.0f} uF",
                            vmin=w["v(out)"].min(), vmax=w["v(out)"].max(), il_max=w["l1#branch"].max()))

    # 3. Hot switch (Ron 0.19 ohm) at the lowest running input, 2.5 A
    p, r = simulate(vin=14.6, rload=2.0, ron=0.19, t_end=4 * MS)
    w = window(r, 3.5 * MS, 4 * MS)
    out.append(dict(name="14.6 V input (UVLO stop 14.57 V), Ron hot 0.19 ohm, 2.5 A", vout=w["v(out)"].mean(),
                    ripple=np.ptp(w["v(out)"])))

    # 4. Light load: 20 mA (pulse skipping)
    p, r = simulate(vin=24.0, rload=250.0, t_end=4 * MS)
    w = window(r, 3 * MS, 4 * MS)
    out.append(dict(name="light load 20 mA, 24 V", vout=w["v(out)"].mean(), ripple=np.ptp(w["v(out)"]),
                    il_max=w["l1#branch"].max()))

    # 5. Output short circuit while running, at 30 V and at the 53 V clamp level
    for vin in (30.0, 53.0):
        p, r = simulate(vin=vin, rload=5.0, short=(3 * MS, 4 * MS), t_end=4.5 * MS)
        w = window(r, 3 * MS, 4 * MS)
        a = window(r, 4 * MS, 4.5 * MS)
        out.append(dict(name=f"output short 1 ms at {vin} V", il_max=w["l1#branch"].max(),
                        il_mean=w["l1#branch"].mean(), isw_max=w["vsense#branch"].max(),
                        recover_overshoot=a["v(out)"].max()))

    # 6. Hot plug onto 30 V through 2 m of wiring, with and without the bulk capacitor
    for cb, rb in ((47e-6, 1.0), (1e-12, 1.0)):
        p, r = simulate(vin=30.0, rload=2.0, cbulk=cb, rbulk=rb, t_on_src=50 * US, t_end=1 * MS)
        w = window(r, 0, 1 * MS)
        out.append(dict(name=f"hot plug 30 V, {'with' if cb > 1e-9 else 'without'} C1",
                        vin_max=w["v(vin)"].max(), iin_max=w["lc#branch"].max(),
                        i2t_fuse=i2t(w["t"], w["lc#branch"]), tvs_max=w["vtvs#branch"].max()))

    # 7. Surge 0.5 kV 1.2/50 us, 2 ohm generator, line to line on the 24 V input
    p, r = simulate(vin_pwl=surge_pwl(24.0, 500.0, 3 * MS), rsrc=2.0, rload=2.0, t_end=4 * MS)
    w = window(r, 2.9 * MS, 4 * MS)
    out.append(dict(name="surge 0.5 kV 1.2/50 us, 2 ohm", vin_max=w["v(vin)"].max(), vclamp=w["v(n2)"].max(),
                    tvs_max=w["vtvs#branch"].max(),
                    tvs_energy=float(np.trapezoid(w["v(n2)"] * np.maximum(w["vtvs#branch"], 0), w["t"])),
                    i2t_fuse=i2t(w["t"], w["lc#branch"]), vmin=w["v(out)"].min(), vmax=w["v(out)"].max()))
    return out


def report(rows, loops):
    lines = ["# 24 V -> 5 V buck (TPS54360B): simulation results", "",
             "Generated by `buck_sim.py`. Behavioural model of the regulator from its datasheet;"
             " see the module docstring for what it includes.", "",
             "## Loop gain", "",
             "| Vin | Load | Cout | Crossover | Phase margin | Gain margin |", "|---|---|---|---|---|---|"]
    for vin, rl, co, fc, pm, gm in loops:
        lines.append(f"| {vin:g} V | {5 / rl:.2f} A | {co * 1e6:.0f} uF | {fc / 1e3:.1f} kHz | {pm:.0f} deg | {gm:.1f} dB |")
    lines += ["", "## Transient scenarios", ""]
    for r in rows:
        lines.append(f"- **{r['name']}**: " + ", ".join(f"{k} = {v:.4g}" for k, v in r.items() if k != "name"))
    with open(os.path.join(HERE, "results.md"), "w", encoding="utf-8", newline="\n") as f:
        f.write("\n".join(lines) + "\n")


if __name__ == "__main__":
    loops = []
    for vin in (16.0, 24.0, 30.0):
        for rl in (20.0, 2.0, 5 / 3.5):
            for co in (34e-6, 56e-6, 80e-6):
                fc, pm, gm, *_ = loop_gain(rl, co, vin)
                loops.append((vin, rl, co, fc, pm, gm))
    rows = scenarios()
    report(rows, loops)
    for r in rows:
        print(r)
