# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""The cost of a placement (blocks.score) and where it comes from: within each functional block, and on the
links between blocks, by pair of blocks. Each step of the placement is checked with it: a step that makes
the board cost more than the plan it was given is not finished.

Run with the Python shipped with KiCad:
    "C:/Program Files/KiCad/10.0/bin/python.exe" measure.py board.kicad_pcb [board2 ...] [--pairs]
"""
import collections
import sys

import numpy as np
import pcbnew

import blocks


def owners():
    """{reference: block name}; the parts of the spread sheets under 'spread'."""
    bl, spread, _, _ = blocks.blocks()
    out = {r: name for name, (main, members) in bl.items() for r in [main] + members}
    out.update({r: "spread" for r in spread})
    return out


def split(board, owner, pairs=False):
    """{part of the cost: cost}: a block name for its own links and their crossings among themselves, 'between
    blocks' for the rest (by pair of blocks with pairs=True)."""
    fps = [fp for fp in board.GetFootprints() if not fp.GetReference().startswith("H")]
    points = [q[:6] + (owner.get(q[6], "?"),) for q in blocks.pad_points(fps)]
    S, W, short, nets, ends = blocks.links(points)
    L = np.hypot(S[:, 2] - S[:, 0], S[:, 3] - S[:, 1])
    cls = []
    for a, e in ends:
        if a == e:
            cls.append(a)
        else:
            cls.append(" > ".join(sorted((a, e))) if pairs else "between blocks")
    out = collections.Counter()
    for c, w, l, s in zip(cls, W, L, short):
        out[c] += w * l * (blocks.SHORT_COST if s else 1.0)
    keep = ~short
    C = np.array(cls)[keep]
    S, W, N = S[keep], W[keep], [n for n, s in zip(nets, short) if not s]
    for c in sorted(set(C)):
        rows = C == c
        mine = blocks.crossings(S[rows], W[rows], [n for n, r in zip(N, rows) if r])
        out[c] += blocks.CROSSING * mine
        rest = blocks.crossings(S, W, N, rows) - mine     # with segments of other parts, counted once below
        out["between blocks" if not pairs else f"x {c}"] += blocks.CROSSING * rest / 2
    return out


def main():
    pairs = "--pairs" in sys.argv
    files = [a for a in sys.argv[1:] if not a.startswith("--")]
    owner = owners()
    costs = [split(pcbnew.LoadBoard(f), owner, pairs) for f in files]
    keys = sorted(set().union(*costs), key=lambda k: -max(c[k] for c in costs))
    names = [f.replace("\\", "/").split("/")[-1].rsplit(".", 1)[0][:14] for f in files]
    print(f"{'':28}" + "".join(f"{n:>16}" for n in names))
    for k in keys:
        print(f"{k[:28]:28}" + "".join(f"{c[k]:16.0f}" for c in costs))
    print(f"{'= total':28}" + "".join(f"{sum(c.values()):16.0f}" for c in costs))


if __name__ == "__main__":
    main()
