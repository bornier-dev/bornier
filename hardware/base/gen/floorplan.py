# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Second step of the placement: the functional blocks, each laid out alone by blocks.py, placed on the board
as rigid groups.

- Axis blocks: their dual RJ45 at its place on edge A (the pitch is set by the shield legs).
- Edge B blocks, and the edge B connectors of the spread sheets: in the order of least cost among all, POWER
  at the end next to the PE contact, spread evenly along the edge.
- The local bus: its header is already at its place, at the end of the board (blocks.py).
- Interior blocks: one at a time, the most connected first, at the free spot and quarter turn of least cost.

Cost: the weighted ratsnest of the nets between blocks (blocks.WEIGHTS): half perimeter while scanning,
then MST length plus crossings (blocks.CROSSING) for the best spots.

Run with the Python shipped with KiCad, after `blocks.py all BLOCKDIR`:
    "C:/Program Files/KiCad/10.0/bin/python.exe" floorplan.py BLOCKDIR out.kicad_pcb
"""
import collections
import glob
import itertools
import math
import os
import sys

import numpy as np
import pcbnew

import blocks
import pcb

CELL = 0.25         # occupancy raster
COARSE = 4          # cells between two candidate spots while scanning (1 mm)
BEST = 12           # candidates per block evaluated with MST and crossings
TIE = 50.0          # per mm between an edge B body and its connectors
WIDE = 40          # candidates per quarter turn while improving
RESERVE = 2.0      # room kept around each part of a block skeleton for its passives
EDGE_VALUES = set(pcb.EDGE_B) | {pcb.AXIS_JACK}


class Block:
    """A laid-out block: courtyard and pad rectangles, signal pads, footprints (positions in board coordinates)."""

    def __init__(self, name, board, refs=None, reserve=0.0, pad_refs=None):
        """refs: the parts that move with the block (None: all); pad_refs: those whose pads count in the cost
        (None: all the parts of the board, the passives at their places in the block layout)."""
        self.name, self.board = name, board
        every = list(board.GetFootprints())
        self.fps = [f for f in board.GetFootprints() if refs is None or f.GetReference() in refs]
        self.refs = [f.GetReference() for f in self.fps]
        self.rects = np.array([(x0 - g, y0 - g, x1 + g, y1 + g) for f in self.fps
                               for g in [0.0 if f.GetValue() in EDGE_VALUES else reserve]
                               for x0, y0, x1, y1 in pcb.occupied(f)])
        self.pads = blocks.pad_points([f for f in every if pad_refs is None or f.GetReference() in pad_refs], name)
        self.centre = ((self.rects[:, 0].min() + self.rects[:, 2].max()) / 2,
                       (self.rects[:, 1].min() + self.rects[:, 3].max()) / 2)
        self.edge = blocks.edge_refs(self.fps)
        if self.edge in ("A", "B"):     # the jack faces stand at the edge, their courtyards beyond it
            self.rects[:, 1] = np.clip(self.rects[:, 1], 0.3, pcb.H - 0.3)
            self.rects[:, 3] = np.clip(self.rects[:, 3], 0.3, pcb.H - 0.3)

    def point(self, rot, x, y):
        """A point of the block turned by rot degrees (KiCad sense) about the centre."""
        cx, cy = self.centre
        c, s = round(math.cos(math.radians(rot))), round(math.sin(math.radians(rot)))
        return cx + (x - cx) * c + (y - cy) * s, cy - (x - cx) * s + (y - cy) * c

    def turned(self, rot):
        """Rectangles and pads turned by rot degrees (KiCad sense) about the centre."""
        cx, cy = self.centre
        c, s = round(math.cos(math.radians(rot))), round(math.sin(math.radians(rot)))

        def tp(x, y):
            x, y = x - cx, y - cy
            return cx + x * c + y * s, cy - x * s + y * c
        rects = []
        for x0, y0, x1, y1 in self.rects:
            (ax, ay), (bx, by) = tp(x0, y0), tp(x1, y1)
            rects.append((min(ax, bx), min(ay, by), max(ax, bx), max(ay, by)))
        return np.array(rects), [(n, *tp(x, y), nx * c + ny * s, -nx * s + ny * c, a, t)
                                 for n, x, y, nx, ny, a, t in self.pads]


class Raster:
    """Occupied cells of the board: outside the part area, the C-LOCK, the placed blocks."""

    def __init__(self):
        self.nx, self.ny = int(math.ceil(pcb.W / CELL)), int(math.ceil(pcb.H / CELL))
        self.occ = np.zeros((self.ny, self.nx), bool)
        xs = (np.arange(self.nx) + 0.5) * CELL
        ys = (np.arange(self.ny) + 0.5) * CELL
        X, Y = np.meshgrid(xs, ys)
        self.occ |= (X < pcb.END_KEEP) | (X > pcb.W - pcb.END_KEEP) | (Y < 0.3) | (Y > pcb.H - 0.3)
        self.occ |= np.hypot(X - pcb.CLOCK[0], Y - pcb.CLOCK[1]) < pcb.CLOCK_KEEP + CELL

    def cells(self, rects):
        r = np.asarray(rects)
        return (np.floor(r[:, 0] / CELL).astype(int), np.floor(r[:, 1] / CELL).astype(int),
                np.ceil(r[:, 2] / CELL).astype(int), np.ceil(r[:, 3] / CELL).astype(int))

    def add(self, rects):
        for x0, y0, x1, y1 in zip(*self.cells(rects)):
            self.occ[max(y0, 0):max(y1, 0), max(x0, 0):max(x1, 0)] = True

    def free(self, rects, dxs, dys):
        """For each translation (in cells), whether the rectangles stay clear of the occupied cells."""
        S = np.zeros((self.ny + 1, self.nx + 1), int)
        S[1:, 1:] = self.occ.cumsum(0).cumsum(1)
        ok = np.ones(len(dxs), bool)
        for x0, y0, x1, y1 in zip(*self.cells(rects)):
            a, b, c, d = x0 + dxs, y0 + dys, x1 + dxs, y1 + dys
            inside = (a >= 0) & (b >= 0) & (c <= self.nx) & (d <= self.ny)
            a, b, c, d = (np.clip(v, 0, n) for v, n in ((a, self.nx), (b, self.ny), (c, self.nx), (d, self.ny)))
            ok &= inside & ((S[d, c] - S[b, c] - S[d, a] + S[b, a]) == 0)
        return ok


def hpwl(pads, fixed, dx, dy):
    """Weighted half perimeter of the nets of the moved pads joined to fixed pads, for arrays of translations."""
    by_net = collections.defaultdict(list)
    for n, x, y, *_ in pads:
        by_net[n].append((x, y))
    total = np.zeros(len(dx))
    for n, pts in by_net.items():
        f = fixed.get(n)
        if not f:
            continue
        p = np.array(pts)
        fx, fy = [q[0] for q in f], [q[1] for q in f]
        lo_x = np.minimum(min(fx), p[:, 0].min() + dx)
        hi_x = np.maximum(max(fx), p[:, 0].max() + dx)
        lo_y = np.minimum(min(fy), p[:, 1].min() + dy)
        hi_y = np.maximum(max(fy), p[:, 1].max() + dy)
        total += blocks.weight(n) * (hi_x - lo_x + hi_y - lo_y)
    return total


def full_cost(placed_pads):
    """The cost of the placed pads (blocks.score): the same measure as every other step of the placement."""
    return blocks.score(placed_pads)


class Plan:
    def __init__(self, fixed_blocks):
        self.raster = Raster()
        self.placed = {}            # name: (block, rot, dx, dy)
        self.pads = []              # blocks.pad_points, tagged with the block name
        self.clashes = []           # (block, rectangles on occupied cells)
        self.extent = {}            # name: (x0, x1)
        for b in fixed_blocks:
            self.put(b, 0, 0.0, 0.0)

    def put(self, b, rot, dx, dy):
        rects, pads = b.turned(rot)
        rects = rects + np.array([dx, dy, dx, dy])
        occ = self.raster.occ
        clash = [i for i, (x0, y0, x1, y1) in enumerate(zip(*self.raster.cells(rects)))
                 if x0 < 0 or y0 < 0 or occ[y0:y1, x0:x1].any()]
        if clash:
            self.clashes.append((b.name, len(clash)))
        self.raster.add(rects)
        self.placed[b.name] = (b, rot, dx, dy)
        self.extent[b.name] = (rects[:, 0].min(), rects[:, 2].max())
        self.pads += [(n, x + dx, y + dy, *rest) for n, x, y, *rest in pads]

    def fixed(self):
        f = collections.defaultdict(list)
        for n, x, y, *_ in self.pads:
            f[n].append((x, y))
        return f

    def scan(self, b, rots=(0, 90, 180, 270), xs=None, ys=None, best=BEST):
        """Candidate spots (cost, rot, dx, dy) of least half perimeter, free of the placed blocks."""
        fixed = self.fixed()
        out = []
        for rot in rots:
            rects, pads = b.turned(rot)
            gx = np.arange(-self.raster.nx, self.raster.nx, COARSE) if xs is None else np.array(xs)
            gy = np.arange(-self.raster.ny, self.raster.ny, COARSE) if ys is None else np.array(ys)
            DX, DY = (v.ravel() for v in np.meshgrid(gx, gy))
            ok = self.raster.free(rects, DX, DY)
            DX, DY = DX[ok], DY[ok]
            if not len(DX):
                continue
            cost = hpwl(pads, fixed, DX * CELL, DY * CELL) + self.tie(b, rects, DX * CELL)
            for k in np.argsort(cost)[:best]:
                out.append((cost[k], rot, DX[k] * CELL, DY[k] * CELL))
        return sorted(out)[:best * 2]

    def best(self, b, candidates):
        """The candidate of least MST length plus crossings."""
        scored = []
        for _, rot, dx, dy in candidates:
            rects, pads = b.turned(rot)
            trial = self.pads + [(n, x + dx, y + dy, *rest) for n, x, y, *rest in pads]
            scored.append((full_cost(trial) + float(self.tie(b, rects, np.array([dx]))[0]), rot, dx, dy))
        return min(scored) if scored else None

    def tie(self, b, rects, dxs):
        """The body of an edge B block stands above its connectors: TIE per mm of horizontal gap between them."""
        conn = self.extent.get(b.name[:-len(" body")]) if b.name.endswith(" body") else None
        if conn is None:
            return np.zeros(len(dxs))
        lo, hi = rects[:, 0].min() + dxs, rects[:, 2].max() + dxs
        return TIE * (np.maximum(0, conn[0] - hi) + np.maximum(0, lo - conn[1]))


def core(fp):
    """A part of the skeleton of a block: chip, connector, switch, part of a data sheet layout."""
    r = fp.GetReference()
    return r[0] in "UJX" or r.startswith("SW") or any(r in t for t in blocks.TEMPLATES)


def total(plan):
    """MST length, crossings and the ties of the bodies to their connectors."""
    ties = 0.0
    for name, (x0, x1) in plan.extent.items():
        conn = plan.extent.get(name[:-len(" body")]) if name.endswith(" body") else None
        if conn:
            ties += TIE * (max(0.0, conn[0] - x1) + max(0.0, x0 - conn[1]))
    return full_cost(plan.pads) + ties


def load(blockdir):
    """The axes and the local bus whole; the other blocks as their skeleton, each part grown by RESERVE for the
    passives that go back against their pins once the blocks are placed."""
    out = {}
    for f in sorted(glob.glob(os.path.join(blockdir, "*.kicad_pcb"))):
        name = os.path.basename(f)[:-len(".kicad_pcb")].replace("_", " ")
        board = pcbnew.LoadBoard(f)
        whole = Block(name, board)
        if whole.edge in ("A", "end"):
            out[name] = whole
        else:
            out[name] = Block(name, board, {fp.GetReference() for fp in board.GetFootprints() if core(fp)}, RESERVE)
    return out


def edge_b_rows(plan, row):
    """x translations of the edge B blocks in this order, spread evenly between their leftmost and rightmost
    packings; None if they do not fit."""
    def pack(order, right):
        trial = Raster()
        trial.occ = plan.raster.occ.copy()
        out = {}
        for b in order:
            rects, _ = b.turned(0)
            span = np.arange(-trial.nx, trial.nx)
            if right:
                span = span[::-1]
            ok = trial.free(rects, span, np.zeros(len(span), int))
            if not ok.any():
                return None
            dx = span[np.argmax(ok)] * CELL
            out[b.name] = dx
            trial.add(rects + np.array([dx, 0, dx, 0]))
        return out
    left, right = pack(row, False), pack(row[::-1], True)
    if left is None or right is None:
        return None
    return {n: round((left[n] + right[n]) / 2 / CELL) * CELL for n in left}


def main():
    blockdir, out = sys.argv[1], sys.argv[2]
    bl, spread, comps, pins = blocks.blocks()
    seed = {}
    loaded = load(blockdir)
    # the edge connectors of the spread sheets, alone
    for r in spread:
        if comps[r]["value"] in pcb.EDGE_B:
            board, fps = blocks.make_board([r], comps, pins)
            blocks.edge_connectors(fps, [r])
            loaded[r] = Block(r, board)
    holes = blocks.make_board(list(pcb.HOLES), comps, pins)[0]
    for f in holes.GetFootprints():
        pcb.place(f, *pcb.HOLES[f.GetReference()], 0)
    hole_block = Block("holes", holes)

    axes = [b for b in loaded.values() if b.name.startswith("Axis")]
    end = [b for b in loaded.values() if b.edge == "end"]
    interior = [b for b in loaded.values() if b.edge is None]
    # edge B: the connectors fill 138 of the 144 mm. A block stands there as its connectors in the row and its
    # body above them, placed like an inner block: it may reach over a shallower neighbour.
    row_b = []
    for b in [b for b in loaded.values() if b.edge == "B"]:
        conn = [f.GetReference() for f in b.fps if f.GetValue() in pcb.EDGE_B]
        row_b.append(Block(b.name, b.board, conn, pad_refs=conn))
        if len(conn) < len(b.fps):
            rest = {f.GetReference() for f in b.board.GetFootprints()} - set(conn)
            interior.append(Block(b.name + " body", b.board, set(b.refs) - set(conn), RESERVE, rest))
    power = [b for b in row_b if any(r.GetValue() == "POWER" for r in b.fps)]
    others = [b for b in row_b if b not in power]

    # axes: the jack at its place on edge A
    for b in axes:
        jack = next(f for f in b.fps if f.GetValue() == pcb.AXIS_JACK)
        k = int(b.name.split()[1])
        b.shift = pcb.JACK_X[k] - pcbnew.ToMM(jack.GetPosition().x)

    def links(b):
        """Weighted signal nets shared with the other blocks: the most connected first."""
        other = collections.Counter(q[0] for c in loaded.values() if c is not b for q in c.pads)
        return -sum(blocks.weight(n) for n in {q[0] for q in b.pads} if other[n])
    sequence = sorted(interior, key=links)
    if os.environ.get("FLOOR_SEED"):
        # a placed board to start from: each block where its main part stood there
        old = pcbnew.LoadBoard(os.environ["FLOOR_SEED"])
        for b in interior:
            main_ref = bl[b.name[:-len(" body")] if b.name.endswith(" body") else b.name][0]
            mine, there = b.board.FindFootprintByReference(main_ref), old.FindFootprintByReference(main_ref)
            rot = 0 if b.name.endswith(" body") else \
                round((there.GetOrientationDegrees() - mine.GetOrientationDegrees()) / 90) % 4 * 90
            x, y = b.point(rot, pcbnew.ToMM(mine.GetPosition().x), pcbnew.ToMM(mine.GetPosition().y))
            seed[b.name] = (rot, pcbnew.ToMM(there.GetPosition().x) - x, pcbnew.ToMM(there.GetPosition().y) - y)

    def run(order):
        """Place the blocks; a block without room goes first and the placement starts again."""
        for _ in range(6):
            r = attempt(order)
            if not isinstance(r, Block):
                return r
            sequence.remove(r)
            sequence.insert(0, r)
            print(f"  {r.name} first", flush=True)
        return None

    def attempt(order):
        plan = Plan([hole_block] + end)
        for b in axes:
            plan.put(b, 0, b.shift, 0.0)
        xs = edge_b_rows(plan, order + power)
        if xs is None:
            return None
        for b in order + power:
            plan.put(b, 0, xs[b.name], 0.0)
        if plan.clashes:
            print("  clashes:", plan.clashes)
        fixed = plan.fixed()

        for b in sequence:
            cands = []
            if b.name in seed:      # near the place of its main part on the seed board, first
                rot, tx, ty = seed[b.name]
                span = np.arange(-40, 41, COARSE)
                xs, ys = round(tx / CELL) + span, round(ty / CELL) + span
                cands = plan.scan(b, (rot,), xs=xs, ys=ys, best=WIDE)
            if not cands:
                cands = plan.scan(b, (0,) if b.name.endswith(" body") else (0, 90, 180, 270))
            pick = plan.best(b, cands)
            if pick is None:
                print(f"  no room for {b.name}; placed: {', '.join(plan.placed)}")
                if os.environ.get("FLOOR_DEBUG"):
                    import matplotlib
                    matplotlib.use("Agg")
                    import matplotlib.pyplot as plt
                    plt.imsave(os.environ["FLOOR_DEBUG"], plan.raster.occ, cmap="gray")
                return b
            plan.put(b, *pick[1:])
        return total(plan), plan

    def improve(cost, plan):
        """Each inner block taken out and placed again where it costs least, until no move gains."""
        movable = [b.name for b in sequence]
        gained = True
        while gained:
            gained = False
            for name in movable:
                b = plan.placed[name][0]
                rest = Plan([])
                for other, rot, dx, dy in plan.placed.values():
                    if other is not b:
                        rest.put(other, rot, dx, dy)
                pick = rest.best(b, rest.scan(b, (0,) if name.endswith(" body") else (0, 90, 180, 270), best=WIDE))
                if pick is None:
                    continue
                rest.put(b, *pick[1:])
                c = total(rest)
                if c < cost - 1:
                    print(f"    {name}: {cost:.0f} -> {c:.0f}", flush=True)
                    cost, plan, gained = c, rest, True
            # two inner blocks exchange their places: a block hemmed in by the others gets out
            inner = [n for n in movable if not n.endswith(" body")]
            for n1, n2 in itertools.combinations(inner, 2):
                b1, b2 = plan.placed[n1][0], plan.placed[n2][0]
                rest = Plan([])
                for other, rot, dx, dy in plan.placed.values():
                    if other is not b1 and other is not b2:
                        rest.put(other, rot, dx, dy)
                ok = True
                for b, there in ((b1, b2), (b2, b1)):
                    _, rot, dx, dy = plan.placed[there.name]
                    tx = there.centre[0] + dx - b.centre[0]
                    ty = there.centre[1] + dy - b.centre[1]
                    span = np.arange(-40, 41, COARSE)
                    xs = np.round(tx / CELL).astype(int) + span
                    ys = np.round(ty / CELL).astype(int) + span
                    pick = rest.best(b, rest.scan(b, xs=xs, ys=ys, best=WIDE))
                    if pick is None:
                        ok = False
                        break
                    rest.put(b, *pick[1:])
                if ok:
                    c = total(rest)
                    if c < cost - 1:
                        print(f"    {n1} <-> {n2}: {cost:.0f} -> {c:.0f}", flush=True)
                        cost, plan, gained = c, rest, True
        return cost, plan

    results = []
    orders = list(itertools.permutations(others))
    if len(sys.argv) > 3:       # an order given: "Modbus|J14|ESC|Spindle"
        by_name = {b.name: b for b in others}
        orders = [[by_name[n] for n in sys.argv[3].split("|")]]
    for order in orders:
        r = run(list(order))
        names = " | ".join(b.name for b in list(order) + power)
        print(f"{names:70} " + ("does not fit" if r is None else f"{r[0]:8.0f}"), flush=True)
        if r:
            results.append((r[0], names, r[1]))
    if not results:
        raise SystemExit("no order of edge B fits")
    improved = []
    for cost, names, plan in sorted(results, key=lambda t: t[0])[:3]:
        print(f"improve {names}  {cost:.0f}", flush=True)
        improved.append((*improve(cost, plan), names))
    cost, plan, names = min(improved, key=lambda t: t[0])
    print(f"best: {names}  {cost:.0f}")
    for name, (b, rot, dx, dy) in plan.placed.items():
        print(f"  {name:24} rot {rot:3}  dx {dx:7.2f}  dy {dy:7.2f}")
    assemble(plan, comps, pins, spread, out, cost)


def assemble(plan, comps, pins, spread, out, plan_cost):
    """The board: every block at its place; the passives of a block at their places in its layout where they
    are free, the others and the parts of the spread sheets next to the pin they serve."""
    refs = [r for b, *_ in plan.placed.values() for r in b.refs]
    rest = [r for r in comps if r not in refs]
    board, fps = blocks.make_board(refs + rest, comps, pins)
    names = set(plan.placed)

    def move(f, rot, cx, cy, dx, dy):
        g = fps[f.GetReference()]
        g.SetOrientation(f.GetOrientation())
        g.SetPosition(f.GetPosition())
        if rot:
            g.Rotate(pcb.vec(cx, cy), pcbnew.EDA_ANGLE(rot, pcbnew.DEGREES_T))
        g.Move(pcb.vec(dx, dy))
        return g
    followers = []
    for b, rot, dx, dy in plan.placed.values():
        t = (rot, float(b.centre[0]), float(b.centre[1]), float(dx), float(dy))
        for f in b.fps:
            move(f, *t)
        if b.name + " body" in names:       # the passives follow the body
            continue
        followers += [(f, t) for f in b.board.GetFootprints() if f.GetReference() not in refs]
    placed = {r: fps[r] for r in refs}
    occ = [o for g in placed.values() for o in pcb.occupied(g)]
    for f, t in followers:
        g = move(f, *t)
        rects = pcb.occupied(g)
        if pcb.free(rects, occ):
            occ += rects
            placed[g.GetReference()] = g
    print(f"{len(placed) - len(refs)} of {len(followers)} passives kept at their places in their blocks")
    pcb.outline(board)
    pcb.keepouts(board)
    zones, lanes = pcb.ZONES, pcb.LANES
    pcb.ZONES, pcb.LANES = {"/Modbus/ bus side": [(0, 0, 0, 0)]}, []
    try:
        failed = pcb.auto_place(fps, placed, set())
    finally:
        pcb.ZONES, pcb.LANES = zones, lanes
    # the passives moved by the assembly, and their neighbours, refined on the whole board
    on_board = [r for r in fps if r not in failed and not r.startswith("H")]
    movable = [r for r in on_board if not core(fps[r]) and fps[r].GetValue() not in EDGE_VALUES]
    before, after = blocks.refine(fps, movable, [r for r in on_board if r not in movable], rounds=2)
    print(f"plan {plan_cost:.0f}, assembled {before:.0f}, refined {after:.0f}")
    board.SetFileName(out)
    pcbnew.SaveBoard(out, board)
    print(f"-> {out}" + (f"; not placed: {failed}" if failed else ""))


if __name__ == "__main__":
    main()
