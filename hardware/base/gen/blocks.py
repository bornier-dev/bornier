# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Functional blocks of the base board, the first step of the placement: the parts of a schematic sheet laid
out together around their main chip, then placed on the board as a whole.

Blocks follow the sheets, with two exceptions: an axis is one block, its drive and encoder sheets in the
column of its dual RJ45 (no part serves two axes: a part shared by two blocks has a place in neither); the
parts of a sheet of slow signals (SPREAD) are no block, each goes next to what it serves.

Inside a block, the main chip stands at the origin; the other chips and connectors (satellites) are placed
one at a time where the block costs least (score: weighted ratsnest and its crossings, the fast signals
count most, a short link straight out of a pin almost nothing); the passives then go against the pin they
serve (pcb.auto_place).

Run with the Python shipped with KiCad:
    "C:/Program Files/KiCad/10.0/bin/python.exe" blocks.py                    the blocks and their members
    ... blocks.py show BLOCK board.kicad_pcb                                  one block laid out alone
"""
import collections
import math
import os
import re
import sys

import numpy as np
import pcbnew

import pcb

SPREAD = {"/Safety/"}
AXIS = re.compile(r"/(Drive|Encoder) (\d)/")    # the two sheets of an axis
# Signal weights for the ratsnest: fast edges count most, slow ones (reset, boot, LEDs, sense) least
WEIGHTS = [
    (r".*(SWDIO|SWCLK|SWO)$", 4.0),
    (r"USB_D[PM]|/ESC/(TX|RX)[PN][AB]", 4.0),
    (r"ESC_S(CK|CS|IO[0-3])|.*CLK25.*", 4.0),
    (r"NRST|.*BOOT0|.*LED.*|.*_LA$|VBUS_SENSE|VIN_SENSE", 0.25),
]
CROSSING = 5.0      # mm of weighted ratsnest a crossing is worth
SHORT = 3.0         # mm: a link this short, straight out of the side of the larger of its two parts...
SHORT_FACE = 0.8    # ...within this cosine of the side's normal...
SHORT_COST = 0.1    # ...costs this part of its length, and no crossing
POWER = pcb.POWER_NETS | {"/Modbus/GNDISO", "VBUS"}
RING = 12.0         # satellites within this distance of the courtyard of the main chip
STEP = 0.5
END = {"J10"}       # the local bus header: vertical, centred across the board, at the end of the board
SPLIT = {"Drive supply and probe": ("U29", "Probe")}   # block: (chip, name of its own block)
COMPACT = 1.0      # cost of one mm of the half perimeter of the block
EDGE_WIDE = 4.0     # edge B: its connectors take 125 of its 144 mm, the blocks grow inward
# Parts laid out after a data sheet (pcb.KEY): they move as one, first part leading
TEMPLATES = [("U1", "L1", "C1", "C5"),                                          # 5 V buck
             ("U3", "L2", "C9", "C10", "C300", "R10", "R9", "D4", "TP7"),       # 3.3 V buck, TPS62A02 fig. 8-24
             ("F1", "D1", "D2")]                                                # power entry


def weight(net):
    return next((w for pat, w in WEIGHTS if re.fullmatch(pat, net)), 1.0)


def blocks():
    """{block name: (main reference, [members])}, the parts spread, the components."""
    comps, pins = pcb.load_netlist()
    by_sheet = collections.defaultdict(list)
    for r, c in comps.items():
        if not r.startswith("H"):
            by_sheet[c["sheetname"]].append(r)
    out, spread = {}, []
    for sheet, refs in sorted(by_sheet.items()):
        if sheet in SPREAD:
            spread += refs
            continue
        m = AXIS.fullmatch(sheet)
        if m:                   # an axis: its drive and encoder sheets, around its dual RJ45
            out.setdefault(f"Axis {m.group(2)}", []).extend(refs)
            continue
        out[sheet.strip("/")] = refs
    # a sheet holding two functions joined by supplies only: the parts reached from the chip by signal nets
    for name, (chip, part) in SPLIT.items():
        refs = out[name]
        on_net = collections.defaultdict(set)
        for r in refs:
            for n in pins.get(r, {}).values():
                if n and n not in POWER:
                    on_net[n].add(r)
        mine, todo = {chip}, [chip]
        while todo:
            r = todo.pop()
            for n in pins.get(r, {}).values():
                for q in on_net.get(n, ()):
                    if q not in mine and not q.startswith("U"):
                        mine.add(q)
                        todo.append(q)

        # its decoupling capacitors: the circuit lists each one after its chip
        from circuit import c
        last = None
        for p in c.parts:
            r = p["ref"]
            if r.startswith("U"):
                last = r
            elif r in refs and r.startswith("C") and last == chip and set(pins.get(r, {}).values()) <= POWER:
                mine.add(r)
        out[name] = [r for r in refs if r not in mine]
        out[part] = [r for r in refs if r in mine]
    result = {}
    for name, refs in out.items():
        chips = [r for r in refs if r[0] in "UJX"]
        if not chips:               # loose parts of the root sheet: chassis capacitors, test points
            spread += refs
            continue
        main = max(chips, key=lambda r: (len(pins.get(r, {})), r[0] == "U"))
        result[name] = (main, sorted((r for r in refs if r != main), key=pcb.rank))
    return result, spread, comps, pins


def make_board(refs, comps, pins):
    board = pcbnew.CreateEmptyBoard()
    board.SetCopperLayerCount(4)
    nets, fps = {}, {}
    for r in refs:
        c = comps[r]
        fp = pcb.load_fp(c["fp"])
        fp.SetReference(r)
        fp.SetValue(c["value"])
        fp.SetSheetname(c["sheetname"])
        board.Add(fp)
        for pad in fp.Pads():
            n = pins.get(r, {}).get(pad.GetNumber())
            if n:
                if n not in nets:
                    nets[n] = pcbnew.NETINFO_ITEM(board, n)
                    board.Add(nets[n])
                pad.SetNet(nets[n])
        fps[r] = fp
    return board, fps


def mst(points):
    if len(points) < 2:
        return []
    best = {i: (math.dist(points[0], points[i]), 0) for i in range(1, len(points))}
    edges = []
    while best:
        i = min(best, key=lambda k: best[k][0])
        j = best.pop(i)[1]
        edges.append((points[j], points[i]))
        for k in best:
            d = math.dist(points[i], points[k])
            if d < best[k][0]:
                best[k] = (d, i)
    return edges


def pad_points(fps, tag=None):
    """The signal pads [(net, x, y, nx, ny, area, tag)]: (nx, ny) the side of its part the pad stands on (0, 0
    under the body), area that of the courtyard of its part."""
    out = []
    for fp in fps:
        cy = fp.GetCourtyard(pcbnew.F_CrtYd)
        x0, y0, x1, y1 = pcb.mm_rect(cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False))
        cx, cy, hx, hy = (x0 + x1) / 2, (y0 + y1) / 2, max((x1 - x0) / 2, 1e-3), max((y1 - y0) / 2, 1e-3)
        for p in fp.Pads():
            n = p.GetNetname()
            if not n or n in POWER or n.startswith("unconnected-"):
                continue
            x, y = pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y)
            u, v = (x - cx) / hx, (y - cy) / hy
            if max(abs(u), abs(v)) < 0.3:
                nx = ny = 0.0
            elif abs(u) >= abs(v):
                nx, ny = math.copysign(1.0, u), 0.0
            else:
                nx, ny = 0.0, math.copysign(1.0, v)
            out.append((n, x, y, nx, ny, 4 * hx * hy, fp.GetReference() if tag is None else tag))
    return out


def links(points):
    """The ratsnest of the pads (pad_points): MST of each net. Returns the segments (k, 4), their weights, whether
    each is a short (SHORT), their nets and the tags of their two ends."""
    by_net = collections.defaultdict(list)
    for q in points:
        by_net[q[0]].append(q)
    segs, ws, short, nets, ends = [], [], [], [], []
    for n, pts in by_net.items():
        w = weight(n)
        at = {(q[1], q[2]): q for q in pts}
        for a, e in mst([(q[1], q[2]) for q in pts]):
            p, q = at[a], at[e]
            big, small = (p, q) if p[5] >= q[5] else (q, p)
            dx, dy = small[1] - big[1], small[2] - big[2]
            d = math.hypot(dx, dy)
            segs.append((*a, *e))
            ws.append(w)
            short.append(d <= SHORT and (d < 1e-6 or (dx * big[3] + dy * big[4]) >= SHORT_FACE * d))
            nets.append(n)
            ends.append((p[6], q[6]))
    return np.array(segs).reshape(-1, 4), np.array(ws), np.array(short, bool), nets, ends


def crossings(S, W, nets, rows=None):
    """Weighted crossings between the segments of different nets; with rows (a mask), only the crossings of
    those segments, each pair of them counted once."""
    if not len(S):
        return 0.0

    def side(o, p, q):
        return (p[..., 0] - o[..., 0]) * (q[..., 1] - o[..., 1]) - (p[..., 1] - o[..., 1]) * (q[..., 0] - o[..., 0])
    rows = np.ones(len(S), bool) if rows is None else rows
    A, Wa = S[rows], W[rows]
    a, b = A[:, None, 0:2], A[:, None, 2:4]
    c, d = S[None, :, 0:2], S[None, :, 2:4]
    x = (side(c, d, a) * side(c, d, b) < 0) & (side(a, b, c) * side(a, b, d) < 0)
    ids = {n: i for i, n in enumerate(dict.fromkeys(nets))}
    k = np.array([ids[n] for n in nets])
    x &= k[rows][:, None] != k[None, :]
    wmax = np.maximum(Wa[:, None], W[None, :])
    both = rows[None, :]          # a pair within the rows is seen twice
    return float((x * wmax * np.where(both, 0.5, 1.0)).sum())


def score(points):
    """The cost of a placement: weighted MST length plus CROSSING per weighted crossing, over the signal nets of
    the pads (pad_points). A short link straight out of the side of the larger part costs SHORT_COST of its
    length and crosses nothing: it routes on its own."""
    S, W, short, nets, _ = links(points)
    if not len(S):
        return 0.0
    L = np.hypot(S[:, 2] - S[:, 0], S[:, 3] - S[:, 1])
    length = float((W * L * np.where(short, SHORT_COST, 1.0)).sum())
    keep = ~short
    return length + CROSSING * crossings(S[keep], W[keep], [n for n, s in zip(nets, short) if not s])


def ratsnest_cost(fps, placed):
    """score() of the placed parts."""
    return score(pad_points(fps[r] for r in placed))


class Ratsnest:
    """The ratsnest of a set of parts, kept per net so that the cost of a move is found from the nets of the
    parts it moves."""

    def __init__(self, fps, refs):
        self.fps = fps
        self.pts = {r: pad_points([fps[r]]) for r in refs}
        self.by_net = collections.defaultdict(set)
        for r, pts in self.pts.items():
            for q in pts:
                self.by_net[q[0]].add(r)
        self.seg = {}
        for n in self.by_net:
            self.relink(n)

    def relink(self, n):
        S, W, short, _, _ = links([q for r in self.by_net[n] for q in self.pts[r] if q[0] == n])
        L = np.hypot(S[:, 2] - S[:, 0], S[:, 3] - S[:, 1])
        self.seg[n] = (S[~short], W[~short], float((W * L * np.where(short, SHORT_COST, 1.0)).sum()))

    def moved(self, refs):
        nets = set()
        for r in refs:
            self.pts[r] = pad_points([self.fps[r]])
            nets |= {q[0] for q in self.pts[r]}
        for n in nets:
            self.relink(n)
        return nets

    def local(self, nets):
        """Length of these nets and their crossings with every net (the score they take part in)."""
        mine = [n for n in nets if len(self.seg[n][0])]
        rest = [n for n in self.seg if n not in nets and len(self.seg[n][0])]
        length = sum(self.seg[n][2] for n in nets)
        if not mine:
            return length
        order = mine + rest
        S = np.concatenate([self.seg[n][0] for n in order])
        W = np.concatenate([self.seg[n][1] for n in order])
        names = [n for n in order for _ in range(len(self.seg[n][0]))]
        rows = np.zeros(len(S), bool)
        rows[:sum(len(self.seg[n][0]) for n in mine)] = True
        return length + CROSSING * crossings(S, W, names, rows)

    def total(self):
        return self.local(set(self.seg))


def refine(fps, movable, others=(), walls=(), twins=None, reach=3.0, step=0.5, rounds=4):
    """Detailed placement: each movable part tried at the free spots within reach and its four quarter turns,
    and in the place of each other movable part of the same footprint (swap), kept where the score falls.
    others: placed parts that stay; twins: {part: (copy, dx)}, a copy that follows its part, dx to the right.
    Returns the score before and after."""
    twins = twins or {}
    refs = list(movable) + [r for r in others if r not in movable] + [t for t, _ in twins.values()]
    net = Ratsnest(fps, refs)
    occ = {r: pcb.occupied(fps[r]) for r in refs}
    walls = list(walls)
    lead = set(movable)
    start = net.total()

    def state(r):
        return fps[r].GetPosition(), fps[r].GetOrientation()

    def set_state(r, s):
        fps[r].SetOrientation(s[1])
        fps[r].SetPosition(s[0])

    def follow(r):
        """The copy of r at its place; the parts moved."""
        if r not in twins:
            return [r]
        t, dx = twins[r]
        fps[t].SetOrientation(fps[r].GetOrientation())
        fps[t].SetPosition(fps[r].GetPosition() + pcb.vec(dx, 0))
        return [r, t]

    order = list(occ)
    index = {r: i for i, r in enumerate(order)}
    box = np.array([o for r in order for o in occ[r]]).reshape(-1, 4)
    who = np.array([index[r] for r in order for _ in occ[r]])
    wall = np.array(walls, float).reshape(-1, 4)

    def hits(rects, against):
        R = np.asarray(rects, float).reshape(-1, 4)
        return ((R[:, None, 0] < against[None, :, 2]) & (against[None, :, 0] < R[:, None, 2])
                & (R[:, None, 1] < against[None, :, 3]) & (against[None, :, 1] < R[:, None, 3])).any()

    def fits(moved):
        """Clear of the other parts and of the board limits; the walls hold the movable parts, not their
        copies."""
        mask = ~np.isin(who, [index[q] for q in moved])
        others, mine = box[mask], []
        for q in moved:
            rects = pcb.occupied(fps[q])
            if not pcb.free(rects, []) or hits(rects, others) or (q in lead and len(wall) and hits(rects, wall)):
                return False
            # the parts moved together must not overlap one another
            if mine and hits(rects, np.array(mine)):
                return False
            mine += rects
        return True

    def commit(moved):
        nonlocal box, who
        for q in moved:
            occ[q] = pcb.occupied(fps[q])
        keep = ~np.isin(who, [index[q] for q in moved])
        box = np.concatenate([box[keep], np.array([o for q in moved for o in occ[q]])])
        who = np.concatenate([who[keep], np.array([index[q] for q in moved for _ in occ[q]])])

    fpid = {r: fps[r].GetFPIDAsString() for r in movable}
    for _ in range(rounds):
        gained = 0.0
        for r in movable:
            nets = {q[0] for q in net.pts[r]} | ({q[0] for q in net.pts[twins[r][0]]} if r in twins else set())
            # swaps with the parts of the same footprint
            for o in movable:
                if o == r or fpid[o] != fpid[r]:
                    continue
                pair = [r, o]
                both = nets | {q[0] for q in net.pts[o]} | ({q[0] for q in net.pts[twins[o][0]]} if o in twins else set())
                before = net.local(both)
                sr, so = state(r), state(o)
                set_state(r, so)
                set_state(o, sr)
                moved = follow(r) + follow(o)
                net.moved(moved)
                after = net.local(both)
                if after < before - 1e-6 and fits(moved):
                    commit(moved)
                    gained += before - after
                    nets = {q[0] for q in net.pts[r]} | ({q[0] for q in net.pts[twins[r][0]]} if r in twins else set())
                else:
                    set_state(r, sr)
                    set_state(o, so)
                    net.moved(follow(r) + follow(o))
            # moves and quarter turns within reach
            s0 = state(r)
            before = net.local(nets)
            best = (before, None)
            x0, y0 = pcbnew.ToMM(s0[0].x), pcbnew.ToMM(s0[0].y)
            k = int(round(reach / step))
            for rot in (0, 90, 180, 270):
                for i in range(-k, k + 1):
                    for j in range(-k, k + 1):
                        fps[r].SetOrientationDegrees(rot)
                        fps[r].SetPosition(pcb.vec(x0 + i * step, y0 + j * step))
                        moved = follow(r)
                        if not fits(moved):
                            continue
                        net.moved(moved)
                        c = net.local(nets)
                        if c < best[0] - 1e-6:
                            best = (c, (fps[r].GetPosition(), fps[r].GetOrientation()))
            set_state(r, best[1] or s0)
            moved = follow(r)
            net.moved(moved)
            if best[1]:
                commit(moved)
                gained += before - best[0]
        if gained < 1.0:
            break
    return start, net.total()


def place_satellites(fps, anchors, satellites, occ, walls=(), wide=1.0):
    """Each satellite (heaviest ratsnest first) at the free spot of least cost around the parts already placed,
    out of the walls; the width of the block costs `wide` times its height."""
    placed = list(anchors)
    walls = list(walls)
    units = [(r,) for r in satellites if not any(r in t for t in TEMPLATES)]
    units += [tuple(r for r in t if r in fps) for t in TEMPLATES if any(r in satellites for r in t)]

    def heft(unit):
        mine = {p.GetNetname() for r in unit for p in fps[r].Pads()}
        return -sum(weight(n) for n in mine if n and n not in POWER)

    def put(unit, x, y, rot):
        """The first part centred at (x, y); the others of a template at their places relative to it."""
        lx, ly, _ = pcb.KEY.get(unit[0], (0.0, 0.0, 0))
        for r in unit:
            kx, ky, krot = pcb.KEY.get(r, (lx, ly, rot))
            pcb.place_centred(fps[r], x + kx - lx, y + ky - ly, krot if len(unit) > 1 else rot)
        return [o for r in unit for o in pcb.occupied(fps[r])]
    for unit in sorted(units, key=heft):
        best = None
        x0, y0 = min(o[0] for o in occ), min(o[1] for o in occ)
        x1, y1 = max(o[2] for o in occ), max(o[3] for o in occ)
        for rot in (0, 90, 180, 270) if len(unit) == 1 else (0,):
            y = y0 - RING
            while y <= y1 + RING:
                x = x0 - RING
                while x <= x1 + RING:
                    rects = put(unit, x, y, rot)
                    if pcb.free(rects, occ + walls):
                        span = (wide * (max(x1, max(o[2] for o in rects)) - min(x0, min(o[0] for o in rects)))
                                + max(y1, max(o[3] for o in rects)) - min(y0, min(o[1] for o in rects)))
                        c = ratsnest_cost(fps, placed + list(unit)) + COMPACT * span
                        if best is None or c < best[0]:
                            best = (c, x, y, rot)
                    x += STEP
                y += STEP
        if best is None:
            raise SystemExit(f"no room for {unit} around {placed[0]}")
        occ += put(unit, *best[1:])
        placed += list(unit)
    return placed


def edge_connectors(fps, refs):
    """Place the connectors of the block that belong on a long edge, side by side in the edge order, centred
    across the board: edge A (axis jacks) toward y = 0, edge B toward y = H. Returns their references."""
    a = sorted((r for r in refs if fps[r].GetValue() == pcb.AXIS_JACK), key=lambda r: int(r[1:]))
    b = sorted((r for r in refs if fps[r].GetValue() in pcb.EDGE_B), key=lambda r: pcb.EDGE_B.index(fps[r].GetValue()))
    for row, rot in ((a, 180), (b, 0)):
        ext = {r: pcb.courtyard(fps[r]) for r in row}
        widths = [ext[r][2] - ext[r][0] for r in row]
        x = (pcb.W - sum(widths) - pcb.GAP_B * (len(row) - 1)) / 2
        for r, w in zip(row, widths):
            left, _, right, bottom = ext[r]
            if rot == 180:      # the courtyard turns with the part
                pcb.place(fps[r], x + right, pcb.front(fps[r], bottom), 180)
            else:
                pcb.place(fps[r], x - left, pcb.H - pcb.front(fps[r], bottom), 0)
            x += w + pcb.GAP_B
    return a + b


def edge_refs(fps):
    """Where the block stands: 'A' or 'B', a long edge, 'end' (the local bus header), None (inside)."""
    values = {f.GetValue() for f in fps}
    refs = {f.GetReference() for f in fps}
    if pcb.AXIS_JACK in values:
        return "A"
    if values & set(pcb.EDGE_B):
        return "B"
    return "end" if refs & END else None


def arrange(fps, anchors, refs, walls=(), wide=1.0):
    """Lay out refs around the anchors (placed): the satellites first, then the passives against their pins; no
    part in the walls (rectangles). The C-LOCK is ignored: the block is placed on the board after. Returns the
    parts not placed."""
    occ = [o for r in anchors for o in pcb.occupied(fps[r])]
    satellites = [r for r in refs if r not in anchors and (r[0] in "UJX" or r.startswith("SW")
                                                            or any(r in t for t in TEMPLATES))]
    zones, lanes, clock = pcb.ZONES, pcb.LANES, pcb.CLOCK
    # the walls are the lanes of auto_place: no part but those of the pairs (none in these blocks) in them
    pcb.ZONES, pcb.LANES, pcb.CLOCK = {"/Modbus/ bus side": [(0, 0, 0, 0)]}, list(walls), (-1000.0, -1000.0)
    try:
        placed = place_satellites(fps, list(anchors), satellites, occ, list(walls), wide)
        mine = dict.fromkeys(list(anchors) + list(refs))
        return pcb.auto_place({r: fps[r] for r in mine}, {r: fps[r] for r in placed}, set())
    finally:
        pcb.ZONES, pcb.LANES, pcb.CLOCK = zones, lanes, clock


def layout(name, main, members, comps, pins, walls=()):
    """A board with the block alone, in board coordinates: the connectors of a long edge on their edge, the
    others around the main part, at mid-length; no part in the walls (rectangles). An axis stays in the
    column of its jack. The parts are then refined in place (refine).
    Returns (board, footprints, parts not placed)."""
    refs = [main] + members
    board, fps = make_board(refs, comps, pins)
    anchors = edge_connectors(fps, refs)
    edge = edge_refs(fps.values())
    if edge == "A":
        jack = next(r for r in anchors if fps[r].GetValue() == pcb.AXIS_JACK)
        x = pcb.JACK_X[int(name.split()[1])]
        pcb.place(fps[jack], x, pcb.front(fps[jack], pcb.courtyard(fps[jack])[3]), 180)
        walls = list(walls) + [(-1000.0, -1000.0, x - pcb.PITCH_A / 2, 1000.0), (x + pcb.PITCH_A / 2, -1000.0, 1000.0, 1000.0)]
    if not anchors:
        # the local bus header at its place, vertical, near the end: its parts stay on the board
        pcb.place_centred(fps[main], *(pcb.KEY[main] if main in END else (pcb.W / 2, pcb.H / 2, 0)))
        anchors = [main]
    failed = arrange(fps, anchors, refs, walls, EDGE_WIDE if edge == "B" else 1.0)
    # parts of a data sheet layout move as one: they stay
    fixed = set(anchors) | set(failed) | {r for t in TEMPLATES for r in t}
    clock, pcb.CLOCK = pcb.CLOCK, (-1000.0, -1000.0)
    try:
        before, after = refine(fps, [r for r in refs if r not in fixed], [r for r in refs if r in fixed], walls)
    finally:
        pcb.CLOCK = clock
    print(f"  {name}: refined {before:.0f} -> {after:.0f}", flush=True)
    return board, fps, failed


def instance(refs):
    """The parts of an axis or drive block in the creation order of their repeated sheets: the n-th parts of
    two instances play the same role."""
    from circuit import c
    groups = []
    for p in c.parts:
        for g in (p["group"], p["also"]):
            if g and g not in groups and re.fullmatch(r"(drv|enc)\d+", g):
                groups.append(g)
    order = [r for g in groups for r in c.members(g)]
    mine = set(refs)
    return list(dict.fromkeys(r for r in order if r in mine))


def copy_layout(src, dst_refs, comps, pins, dx=0.0):
    """A board with the parts of dst_refs at the places of their matches in src (a laid-out board of another
    instance), moved by dx."""
    s = instance([fp.GetReference() for fp in src.GetFootprints()])
    d = instance(dst_refs)
    if len(s) != len(d) or any(comps[a]["value"] != comps[b]["value"] for a, b in zip(s, d)):
        raise SystemExit(f"instances differ: {s} / {d}")
    board, fps = make_board(d, comps, pins)
    for a, b in zip(s, d):
        f = src.FindFootprintByReference(a)
        fps[b].SetOrientation(f.GetOrientation())
        fps[b].SetPosition(f.GetPosition() + pcb.vec(dx, 0))
    return board, fps


def main():
    bl, spread, comps, pins = blocks()
    if len(sys.argv) > 2 and sys.argv[1] in ("show", "all"):
        # the axes first: the local bus header stands in the corner of axis 0, out of its parts
        names = sorted(bl, key=lambda n: not n.startswith("Axis"))
        if sys.argv[1] == "show":
            needs = END & ({bl[sys.argv[2]][0]} | set(bl[sys.argv[2]][1]))
            names = [n for n in names if (n == "Axis 0" and needs) or n == sys.argv[2]]
        first, axis0 = None, []
        # the parts with a fixed place (the local bus header) are walls for every other block
        board, fps = make_board(sorted(END), comps, pins)
        for r in END:
            pcb.place_centred(fps[r], *pcb.KEY[r])
        fixed = {r: pcb.occupied(fps[r]) for r in END}
        for name in names:
            main_ref, members = bl[name]
            out = sys.argv[3] if sys.argv[1] == "show" else os.path.join(sys.argv[2], name.replace(" ", "_") + ".kicad_pcb")
            if name.startswith("Axis") and first:
                dx = pcb.JACK_X[int(name.split()[1])] - pcb.JACK_X[int(first[0].split()[1])]
                board, _ = copy_layout(first[1], [main_ref] + members, comps, pins, dx)
                failed = []
            else:
                mine = END & ({main_ref} | set(members))
                walls = axis0 if mine else [o for r, rects in fixed.items() for o in rects]
                board, fps, failed = layout(name, main_ref, members, comps, pins, walls)
                if name.startswith("Axis"):
                    first = (name, board)
                    axis0 = [o for f in fps.values() for o in pcb.occupied(f)]
            if sys.argv[1] == "show" and name != sys.argv[2]:
                continue
            board.SetFileName(out)
            pcbnew.SaveBoard(out, board)
            print(f"{name}: {main_ref} and {len(members)} member(s) -> {out}" + (f", not placed: {failed}" if failed else ""),
                  flush=True)
        return
    for name, (m, members) in bl.items():
        print(f"{name:20} {m:5} {comps[m]['value'][:20]:20} {len(members):3}  {' '.join(members)}")
    print("spread:", " ".join(sorted(spread)))


if __name__ == "__main__":
    main()
