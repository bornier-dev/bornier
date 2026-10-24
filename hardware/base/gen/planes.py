# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Supply planes of layer 3, drawn from the placement.

Seeds: the supply pads of each block mostly fed by one supply (MOSTLY of its supply pads and at least
SEED_MIN of them) seed that supply; the block holding the regulators (SOURCES) seeds all of its supply pads.
Each cell of the board goes to the supply of the nearest seed. A supply cut into pieces is joined to the piece
of its source by a corridor NECK wide (a piece holding fewer than SEED_MIN seeds goes to the supply around it instead), through the cells of the other supplies, cheapest first, never across
a corridor laid before; the other supplies are checked again, until every supply is in one piece. The pads of a supply off its plane are linked
by the supply passes of route.py.

Run alone to draw the planes of a board: planes.py board.kicad_pcb out.png
"""
import collections
import heapq
import math

import numpy as np
import pcbnew

import blocks
import pcb

SUPPLIES = ("+5V", "+3V3", "+VIN")
# The pads of a supply where it is made: its plane is grown from there
SOURCES = {"+5V": "L1", "+3V3": "L2", "+VIN": "D2"}
MOSTLY = 0.5
SEED_MIN = 4
CELL = 0.5          # grid, mm
# IPC-2221, inner layer, 0.5 oz (17.5 um), 10 degC rise: 2.4 A (four encoders at 0.6 A on +5V) needs 5.2 mm
NECK = 6.0
FOREIGN = 4.0       # cost of a cell of another supply taken by a corridor, against 1 for a cell of its own
GAP = 0.5           # between planes of different supplies (route.ZONE_GAP)


def seeds(board):
    """{supply: [(x, y)]}: the seed pads."""
    bl, _, comps, pins = blocks.blocks()
    owner = {r: name for name, (m, mem) in bl.items() for r in [m] + mem}
    count = collections.defaultdict(collections.Counter)
    for r, name in owner.items():
        for n in pins.get(r, {}).values():
            if n in SUPPLIES:
                count[name][n] += 1
    source_blocks = {owner[r] for r in SOURCES.values()}
    out = collections.defaultdict(list)
    for fp in board.GetFootprints():
        name = owner.get(fp.GetReference())
        if name is None:
            continue
        c = count[name]
        for p in fp.Pads():
            n = p.GetNetname()
            if n not in SUPPLIES:
                continue
            if name in source_blocks or (c[n] >= SEED_MIN and c[n] >= MOSTLY * sum(c.values())):
                out[n].append((pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y)))
    return out


def grid(inside):
    """Cell centres of the area (x0, y0, x1, y1)."""
    x0, y0, x1, y1 = inside
    xs = np.arange(x0 + CELL / 2, x1, CELL)
    ys = np.arange(y0 + CELL / 2, y1, CELL)
    return xs, ys


def components(mask):
    """Labels of the 4-connected pieces of the mask (0: outside), and their number."""
    lab = np.zeros(mask.shape, int)
    k = 0
    for start in zip(*np.nonzero(mask)):
        if lab[start]:
            continue
        k += 1
        lab[start] = k
        todo = [start]
        while todo:
            i, j = todo.pop()
            for a, b in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
                if 0 <= a < mask.shape[0] and 0 <= b < mask.shape[1] and mask[a, b] and not lab[a, b]:
                    lab[a, b] = k
                    todo.append((a, b))
    return lab, k


def corridor(owner, net, frm, to, blocked):
    """Cheapest path of cells from the piece frm (mask) to the piece to (mask), through cells of any supply
    (own cells cost 1, others FOREIGN), never through blocked cells. Returns the cells."""
    cost = np.where(owner == net, 1.0, FOREIGN)
    dist = np.full(owner.shape, np.inf)
    prev = {}
    heap = []
    for i, j in zip(*np.nonzero(frm)):
        dist[i, j] = 0.0
        heap.append((0.0, i, j))
    heapq.heapify(heap)
    while heap:
        d, i, j = heapq.heappop(heap)
        if d > dist[i, j]:
            continue
        if to[i, j]:
            path = [(i, j)]
            while (i, j) in prev:
                i, j = prev[(i, j)]
                path.append((i, j))
            return path
        for a, b in ((i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)):
            if 0 <= a < owner.shape[0] and 0 <= b < owner.shape[1] and not blocked[a, b]:
                nd = d + cost[a, b]
                if nd < dist[a, b]:
                    dist[a, b] = nd
                    prev[(a, b)] = (i, j)
                    heapq.heappush(heap, (nd, a, b))
    return None


def supply_planes(board, inside, keep_out=(), strict=True):
    """{supply: SHAPE_POLY_SET} on layer 3, within inside (x0, y0, x1, y1), out of the keep_out rectangles."""
    xs, ys = grid(inside)
    X, Y = np.meshgrid(xs, ys)
    blocked = np.zeros(X.shape, bool)
    for x0, y0, x1, y1 in keep_out:
        blocked |= (X >= x0) & (X <= x1) & (Y >= y0) & (Y <= y1)
    seed = seeds(board)

    def cell(x, y):
        return (int(np.clip(round((y - ys[0]) / CELL), 0, len(ys) - 1)),
                int(np.clip(round((x - xs[0]) / CELL), 0, len(xs) - 1)))

    def border(mask):
        out = set()
        for a, b in zip(*np.nonzero(mask)):
            for c, d in ((a + 1, b), (a - 1, b), (a, b + 1), (a, b - 1)):
                if 0 <= c < mask.shape[0] and 0 <= d < mask.shape[1] and not mask[c, d]:
                    out.add((c, d))
        return out
    nets = [n for n in SUPPLIES if seed.get(n)]
    best = np.full(X.shape, np.inf)
    owner = np.full(X.shape, "", dtype=object)
    for n in nets:
        P = np.array(seed[n])
        d = np.full(X.shape, np.inf)
        for k in range(0, len(P), 64):
            chunk = P[k:k + 64]
            d = np.minimum(d, np.hypot(X[..., None] - chunk[:, 0], Y[..., None] - chunk[:, 1]).min(-1))
        take = d < best
        best[take] = d[take]
        owner[take] = n
    owner[blocked] = ""
    fps = {fp.GetReference(): fp for fp in board.GetFootprints()}
    half = int(round(NECK / 2 / CELL))
    locked = np.zeros(X.shape, bool)     # the corridors laid: no later corridor of another supply cuts them
    for _ in range(4 * len(nets)):
        done = True
        for n in nets:
            lab, k = components(owner == n)
            if k <= 1:
                continue
            done = False
            src = [(pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y))
                   for p in fps[SOURCES[n]].Pads() if p.GetNetname() == n]
            i, j = cell(*src[0])
            while k > 1:
                main = lab[i, j] or np.bincount(lab.ravel())[1:].argmax() + 1
                piece = next(p for p in range(1, k + 1) if p != main)
                held = sum(1 for x, y in seed[n] if lab[cell(x, y)] == piece)
                if held < SEED_MIN:
                    # a piece with few pads of its supply goes to the supply around it: its pads are linked
                    around = [owner[a, b] for a, b in border(lab == piece) if owner[a, b] not in ("", n)]
                    owner[lab == piece] = collections.Counter(around).most_common(1)[0][0] if around else ""
                    lab, k = components(owner == n)
                    continue
                path = corridor(owner, n, lab == piece, lab == main, blocked | (locked & (owner != n)))
                if path is None:
                    raise SystemExit(f"planes: no way to join a piece of {n} to its source")
                for a, b in path:
                    win = (slice(max(a - half, 0), a + half + 1), slice(max(b - half, 0), b + half + 1))
                    free = ~locked[win] | (owner[win] == n)
                    owner[win] = np.where(free, n, owner[win])
                    locked[win] |= free
                owner[blocked] = ""
                lab, k = components(owner == n)
        if done:
            break
    else:
        if strict:
            raise SystemExit("planes: the supplies do not settle in one piece each")
        print("planes: the supplies do not settle in one piece each")
    out = {}
    for n in nets:
        poly = pcbnew.SHAPE_POLY_SET()
        mask = owner == n
        for r in range(mask.shape[0]):
            row = mask[r]
            c = 0
            while c < len(row):
                if row[c]:
                    e = c
                    while e < len(row) and row[e]:
                        e += 1
                    x0, x1 = xs[c] - CELL / 2, xs[e - 1] + CELL / 2
                    y0, y1 = ys[r] - CELL / 2, ys[r] + CELL / 2
                    poly.NewOutline()
                    for x, y in ((x0, y0), (x1, y0), (x1, y1), (x0, y1)):
                        poly.Append(pcbnew.FromMM(float(x)), pcbnew.FromMM(float(y)))
                    c = e
                else:
                    c += 1
        poly.Simplify()
        poly.Deflate(pcbnew.FromMM(GAP / 2), pcbnew.CORNER_STRATEGY_ALLOW_ACUTE_CORNERS, pcbnew.FromMM(0.01))
        poly.Simplify()
        out[n] = poly
    return out, owner, (xs, ys)


def main():
    import sys
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    board = pcbnew.LoadBoard(sys.argv[1])
    edge = pcb.END_KEEP
    _, owner, (xs, ys) = supply_planes(board, (edge, edge, pcb.W - edge, pcb.H - edge), strict=False)
    colours = {"": 0, "+5V": 1, "+3V3": 2, "+VIN": 3}
    img = np.vectorize(colours.get)(owner)
    plt.figure(figsize=(15, 11))
    plt.imshow(img, extent=(xs[0], xs[-1], ys[-1], ys[0]), cmap="Set1", vmin=0, vmax=8)
    for fp in board.GetFootprints():
        p = fp.GetPosition()
        plt.text(pcbnew.ToMM(p.x), pcbnew.ToMM(p.y), fp.GetReference(), fontsize=4, ha="center")
    plt.title("+5V red / +3V3 blue / +VIN green")
    plt.savefig(sys.argv[2], dpi=120)
    print(sys.argv[2], {n: int((owner == n).sum() * CELL * CELL) for n in SUPPLIES})


if __name__ == "__main__":
    main()
