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
# A pad farther than REACH from its plane gets a finger of it FINGER wide: the supply passes of route.py link a
# via to its plane on layer 4 only up to RAIL_LINK_MAX (12 mm, in an L), a longer link walls the signals off.
# IPC-2221, inner layer, 0.5 oz, 10 degC rise: 2.5 mm carries 1.4 A
REACH = 8.0
FINGER = 2.5


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
    """{supply: SHAPE_POLY_SET} on layer 3, within inside (x0, y0, x1, y1), out of the keep_out rectangles
    (x0, y0, x1, y1) and polygons [(x, y), ...]."""
    from matplotlib.path import Path
    xs, ys = grid(inside)
    X, Y = np.meshgrid(xs, ys)
    blocked = np.zeros(X.shape, bool)
    for k in keep_out:
        if len(k) == 4 and not isinstance(k[0], tuple):
            x0, y0, x1, y1 = k
            blocked |= (X >= x0) & (X <= x1) & (Y >= y0) & (Y <= y1)
        else:
            blocked |= Path(k).contains_points(np.column_stack([X.ravel(), Y.ravel()])).reshape(X.shape)
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
    locked = np.zeros(X.shape, bool)     # corridors, fingers and sources: no later corridor of another supply cuts them

    def pads_of(n):
        return [(f"{fp.GetReference()}.{p.GetNumber()}", pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y))
                for fp in fps.values() for p in fp.Pads() if p.GetNetname() == n]
    src = {n: [(x, y) for name, x, y in pads_of(n) if name.split(".")[0] == SOURCES[n]] for n in nets}
    bridges = []        # (supply, (x, y) in a piece, (x, y) in its main body): joined by a track, not by the plane

    def pieces(n):
        """Labels of the pieces of n, and the label of each piece's group (pieces joined by bridges): the group
        of the source is 0."""
        lab, k = components(owner == n)
        group = list(range(k + 1))

        def root(p):
            while group[p] != p:
                p = group[p]
            return p
        for m, a, b in bridges:
            if m == n and lab[cell(*a)] and lab[cell(*b)]:
                group[root(lab[cell(*a)])] = root(lab[cell(*b)])
        main = root(lab[cell(*src[n][0])]) if lab[cell(*src[n][0])] else None
        return lab, {p: (0 if root(p) == main else root(p)) for p in range(1, k + 1)}

    def groups(n):
        return len(set(pieces(n)[1].values()))

    def paint(n, path, width):
        """The cells of the path, width wide, to n, unless that splits another supply: then nothing changes and
        False is returned."""
        keep = owner.copy(), locked.copy()
        before = {m: groups(m) for m in nets if m != n}
        half = int(round(width / 2 / CELL))
        for a, b in path:
            win = (slice(max(a - half, 0), a + half + 1), slice(max(b - half, 0), b + half + 1))
            free = ~locked[win] | (owner[win] == n)
            owner[win] = np.where(free, n, owner[win])
            locked[win] |= free
        owner[blocked] = ""
        if any(groups(m) > before[m] for m in before):
            owner[...], locked[...] = keep
            return False
        return True

    def where(mask):
        ii, jj = np.nonzero(mask)
        return float(xs[jj].mean()), float(ys[ii].mean())

    # the source on its plane, first: every supply is fed from where it is made
    for n in nets:
        paint(n, [cell(x, y) for x, y in src[n]], NECK)

    def join():
        for _ in range(4 * len(nets)):
            done = True
            for n in nets:
                for _ in range(64):
                    lab, grp = pieces(n)
                    apart = [p for p, g in grp.items() if g != 0]
                    if not apart:
                        break
                    done = False
                    piece = min(apart, key=lambda p: (lab == p).sum())
                    main = np.isin(lab, [p for p, g in grp.items() if g == 0])
                    held = sum(1 for x, y in seed[n] if lab[cell(x, y)] == piece)
                    mask = lab == piece
                    if held < SEED_MIN and not locked[mask].any():
                        # a piece with few pads of its supply goes to the supply around it: its pads get a finger
                        around = [owner[a, b] for a, b in border(mask) if owner[a, b] not in ("", n)]
                        owner[mask] = collections.Counter(around).most_common(1)[0][0] if around else ""
                        continue
                    path = corridor(owner, n, mask, main, blocked | (locked & (owner != n)))
                    if path is None or not paint(n, path, NECK):
                        # no way on this layer without cutting another supply: a track joins it (route.py)
                        a, b = shortest(mask, main)
                        bridges.append((n, a, b))
            if done:
                return True
        return False

    def shortest(frm, to):
        """The nearest pair of cells of two masks, as points (mm)."""
        fi, fj = np.nonzero(frm)
        ti, tj = np.nonzero(to)
        step = max(1, len(ti) // 4000)
        ti, tj = ti[::step], tj[::step]
        best = None
        for k in range(0, len(fi), 256):
            d = np.hypot(xs[fj[k:k + 256], None] - xs[tj], ys[fi[k:k + 256], None] - ys[ti])
            a, b = np.unravel_index(d.argmin(), d.shape)
            if best is None or d[a, b] < best[0]:
                best = (d[a, b], (float(xs[fj[k + a]]), float(ys[fi[k + a]])), (float(xs[tj[b]]), float(ys[ti[b]])))
        return best[1], best[2]

    def far(skip=()):
        """[(distance, supply, pad, x, y)] of the pads farther than REACH from their plane."""
        out = []
        for n in nets:
            ii, jj = np.nonzero(owner == n)
            px, py = xs[jj], ys[ii]
            for name, x, y in pads_of(n):
                d = np.hypot(px - x, py - y).min() if len(px) else math.inf
                if d > REACH and name not in skip:
                    out.append((d, n, name, x, y))
        return sorted(out)
    settled = join()
    tried = set()
    for _ in range(64):
        left = far(tried)
        if not left:
            break
        # the nearest first: its finger may serve the next ones
        _, n, name, x, y = left[0]
        tried.add(name)
        frm = np.zeros(X.shape, bool)
        frm[cell(x, y)] = True
        path = corridor(owner, n, frm, owner == n, blocked | (locked & (owner != n)))
        if path is not None and paint(n, path, FINGER):
            # NECK wide around the pad: a through-hole pad needs room for its thermal spokes
            paint(n, [cell(x, y)], NECK)
            settled = join()
    left = far()
    if not settled:
        if strict:
            raise SystemExit("planes: the supplies do not settle in one piece each")
        print("planes: the supplies do not settle in one piece each")
    for n, a, b in bridges:
        print(f"planes: {n} bridge from ({a[0]:.1f}, {a[1]:.1f}) to ({b[0]:.1f}, {b[1]:.1f}), {math.dist(a, b):.1f} mm")
    if left:
        # a finger would cut another supply: the supply pass links them by a track (route.py)
        print("planes: pads out of reach of their plane, linked by their pass: "
              + " ".join(f"{name} ({n}, {d:.1f} mm)" for d, n, name, _, _ in left))
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
    return out, owner, (xs, ys), bridges


def main():
    import sys
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    board = pcbnew.LoadBoard(sys.argv[1])
    import route
    _, owner, (xs, ys), bridges = route.supply_planes(board, strict=False)
    colours = {"": 0, "+5V": 1, "+3V3": 2, "+VIN": 3}
    img = np.vectorize(colours.get)(owner)
    plt.figure(figsize=(15, 11))
    plt.imshow(img, extent=(xs[0], xs[-1], ys[-1], ys[0]), cmap="Set1", vmin=0, vmax=8)
    for fp in board.GetFootprints():
        p = fp.GetPosition()
        plt.text(pcbnew.ToMM(p.x), pcbnew.ToMM(p.y), fp.GetReference(), fontsize=4, ha="center")
    for n, a, b in bridges:
        plt.plot([a[0], b[0]], [a[1], b[1]], "k-", lw=2)
    plt.title("+5V blue / +3V3 green / +VIN purple, bridges black")
    plt.savefig(sys.argv[2], dpi=120)
    print(sys.argv[2], {n: int((owner == n).sum() * CELL * CELL) for n in SUPPLIES})


if __name__ == "__main__":
    main()
