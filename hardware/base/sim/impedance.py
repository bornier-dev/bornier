# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Impedance of the outer layer traces of the base board, by a 2D finite difference field solver.

Stack-up JLC04161H-7628 (JLCPCB): layer 1 copper 0.035 mm over 0.2104 mm of 7628 prepreg, er 4.4 (the
JLCPCB figure, at 1 GHz), then the layer 2 ground plane; solder mask 0.0152 mm, er 3.8, over the traces
and the dielectric. The solver finds the potential in the cross section (Laplace, variable permittivity,
grounded box far from the traces), the capacitance per length from the field energy, with the dielectrics
and in air, and Z = 1 / (c sqrt(C C_air)). Differential impedance: twice the odd mode impedance.

    python impedance.py                 the check against a single microstrip, then the pair table
"""
import math
import sys

import numpy as np
from scipy.sparse import coo_matrix
from scipy.sparse.linalg import spsolve

H = 0.2104          # prepreg, mm
T = 0.035           # outer copper
ER = 4.4
MASK, ER_MASK = 0.0152, 3.8
DX = 0.005          # grid, mm
C0 = 299792458.0
EPS0 = 8.8541878128e-12


def solve(widths_gaps, volts, er_on=True, box=(4.0, 2.0)):
    """Field energy per length (J/m, for the potentials in volts) of traces side by side on the dielectric.
    widths_gaps: [w0, g01, w1, ...] in mm, centred in the box."""
    nx, ny = int(box[0] / DX), int(box[1] / DX)
    eps = np.ones((ny, nx))
    fixed = np.zeros((ny, nx), bool)
    v = np.zeros((ny, nx))
    jh, jt = int(round(H / DX)), int(round((H + T) / DX))
    jm = int(round(MASK / DX))
    if er_on:
        eps[:jh, :] = ER
        eps[jh:jh + jm, :] = ER_MASK
    total = sum(widths_gaps)
    x = (box[0] - total) / 2
    for k, w in enumerate(widths_gaps):
        if k % 2 == 0:
            i0, i1 = int(round(x / DX)), int(round((x + w) / DX))
            fixed[jh:jt, i0:i1] = True
            v[jh:jt, i0:i1] = volts[k // 2]
            if er_on:      # the mask over the trace and down its sides
                eps[jt:jt + jm, i0 - jm:i1 + jm] = ER_MASK
                eps[jh:jt, i0 - jm:i0] = ER_MASK
                eps[jh:jt, i1:i1 + jm] = ER_MASK
        x += w
    fixed[0, :] = True              # the ground plane
    fixed[-1, :] = fixed[:, 0] = fixed[:, -1] = True   # the far box, grounded
    # Laplace with the permittivity on the cell faces: sum over the 4 neighbours of e_face (V_n - V) = 0
    idx = -np.ones((ny, nx), int)
    free = ~fixed
    idx[free] = np.arange(free.sum())
    rows, cols, vals = [], [], []
    rhs = np.zeros(free.sum())
    jj, ii = np.nonzero(free)
    diag = np.zeros(free.sum())
    for dj, di in ((0, 1), (0, -1), (1, 0), (-1, 0)):
        nj, ni = jj + dj, ii + di
        e = (eps[jj, ii] + eps[nj, ni]) / 2
        diag += e
        nb = idx[nj, ni]
        inner = nb >= 0
        rows.append(idx[jj, ii][inner])
        cols.append(nb[inner])
        vals.append(-e[inner])
        np.add.at(rhs, idx[jj, ii][~inner], e[~inner] * v[nj[~inner], ni[~inner]])
    rows.append(idx[jj, ii])
    cols.append(idx[jj, ii])
    vals.append(diag)
    n = free.sum()
    a = coo_matrix((np.concatenate(vals), (np.concatenate(rows), np.concatenate(cols))), shape=(n, n)).tocsr()
    v[free] = spsolve(a, rhs)
    ex = np.diff(v, axis=1) / (DX * 1e-3)
    ey = np.diff(v, axis=0) / (DX * 1e-3)
    ex_e = (eps[:, 1:] + eps[:, :-1]) / 2
    ey_e = (eps[1:, :] + eps[:-1, :]) / 2
    return 0.5 * EPS0 * (np.sum(ex_e * ex ** 2) + np.sum(ey_e * ey ** 2)) * (DX * 1e-3) ** 2


def single(w):
    c = 2 * solve([w], [1.0])
    ca = 2 * solve([w], [1.0], er_on=False)
    return 1 / (C0 * math.sqrt(c * ca))


def differential(w, s):
    """Odd mode: +1 V and -1 V; the energy is C_odd (per trace, to the virtual ground)."""
    c = solve([w, s, w], [1.0, -1.0])
    ca = solve([w, s, w], [1.0, -1.0], er_on=False)
    return 2 / (C0 * math.sqrt(c * ca))


def hammerstad(w):
    """Closed form for a single microstrip (Hammerstad and Jensen, zero thickness, no mask): the check."""
    u = w / H
    a = 1 + math.log((u ** 4 + (u / 52) ** 2) / (u ** 4 + 0.432)) / 49 + math.log(1 + (u / 18.1) ** 3) / 18.7
    b = 0.564 * ((ER - 0.9) / (ER + 3)) ** 0.053
    ee = (ER + 1) / 2 + (ER - 1) / 2 * (1 + 10 / u) ** (-a * b)
    f = 6 + (2 * math.pi - 6) * math.exp(-(30.666 / u) ** 0.7528)
    z = 60 * math.log(f / u + math.sqrt(1 + (2 / u) ** 2))
    return z / math.sqrt(ee)


if __name__ == "__main__":
    if "--check" in sys.argv or len(sys.argv) == 1:
        global_t, global_m = T, MASK
        for w in (0.2, 0.35):
            T, MASK = DX, 0.0     # one cell: the thinnest the grid holds
            print(f"single w {w}: solver, bare and thin {single(w):.1f} ohm, Hammerstad {hammerstad(w):.1f} ohm")
            T, MASK = global_t, global_m
            print(f"single w {w}: solver, 35 um copper and mask {single(w):.1f} ohm")
    for w, s in [(0.12, 0.15), (0.15, 0.15), (0.15, 0.2), (0.18, 0.2), (0.2, 0.2), (0.2, 0.25), (0.25, 0.25)]:
        print(f"pair w {w} s {s}: {differential(w, s):.1f} ohm differential")


def width_for(z, s, lo=0.08, hi=0.6):
    """Trace width for a differential impedance z at the gap s, by bisection (wider is lower)."""
    for _ in range(12):
        w = (lo + hi) / 2
        lo, hi = (lo, w) if differential(w, s) < z else (w, hi)
    return round((lo + hi) / 2, 3)
