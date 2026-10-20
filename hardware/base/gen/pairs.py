# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Differential pairs of the base board, on layer 1 over the ground plane: route.py pass "pairs", the first
one after the planes and trunks, so that the fanouts route around the pairs.

A pair runs from its IC (the part with the most pads among those on both nets), straight through its ESD
array (flow-through: the NC pins opposite each line carry it), to its connector. Between these stops, its
centre line is found by A* on a 0.1 mm grid (8 directions, bends cost extra), clear of the other copper of
layer 1 by PAIR_KEEP (about 3 W), by the clearance alone near the pads; the two lines are that centre line
offset by half the pair pitch, joined to the IC and connector pads by short escapes. Each line keeps its net
from end to end: the jack pins and ESD channels are assigned in circuit.py so that it does.

The terminations (parts on one line only) are lifted off the board while the pairs are routed, then put back
against their line, signal pad on it, on the side away from the other line, nearest the IC: the LAN9253
checklist wants them at the PHY, and in the way of the lines they left no room to get out of it. Everything
is checked against the clearances before it is laid; what does not pass is reported and left out.
"""
import heapq
import math
import os

import numpy as np
import pcbnew

import pcb
import project
import route

G = 0.1                     # grid, mm
VERBOSE = os.environ.get("PAIRS_VERBOSE")
MARGIN = 5.0                # search area: the box of the pads grown by this much
TURN = 0.6                  # cost of a 45 degree bend, in grid steps
ESCAPE = 3.0                # how far from its pads a pair may start, mm
ESCAPE_THT = 2.5            # from the middle of two through-hole connector pins
ESCAPE_LEAD = 0.75          # the straight run out of the IC pads, from their middle
ESCAPE_MIN = 1.2            # and no nearer: past the pad ends, the lines leave each pad straight and converge
MARGIN_GAP = 0.005          # over the pair gap: a gap equal to the clearance fails the DRC by rounding
RELAX = 3.0                 # around its pads, the pair keeps the clearance only, not PAIR_KEEP
RESERVE = 1.5               # the run of a pair through its ESD array, kept clear by the others, grown by this
THROUGH = 1.0               # straight run of a pair before and after an ESD array it flows through
TERM_TRIES = 6
TERM_FROM, TERM_TO = 0.6, 20.0     # where a termination may stand along its line, from the IC pad
# In this order: from the PHY to its ESD array, then on to its jack, the RX pair of port A takes the inside of
# both bends, the TX pair goes round it
PAIRS = [("/ESC/RXPA", "/ESC/RXNA"), ("/ESC/TXPA", "/ESC/TXNA"), ("/ESC/TXPB", "/ESC/TXNB"),
         ("/ESC/RXPB", "/ESC/RXNB"), ("USB_DP", "USB_DM")]
WHY = {"courtyard": 0, "pads": 0}     # why the terminations did not fit, for the report
DIRS = [(1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)]


class Grid:
    """Distance from each cell of the search area to the copper of layer 1 and to the holes, the nets of
    the pair left out; a cell is free when the centre line of the pair keeps its distance there."""

    def __init__(self, board, nets, box, half, extra=lambda net: 0.0, through=()):
        self.x0, self.y0 = box[0], box[1]
        self.nx, self.ny = int((box[2] - box[0]) / G) + 1, int((box[3] - box[1]) / G) + 1
        self.X, self.Y = np.meshgrid(self.x0 + G * np.arange(self.nx), self.y0 + G * np.arange(self.ny))
        self.dist = np.full((self.ny, self.nx), np.inf)
        T = pcbnew.ToMM
        for fp in board.GetFootprints():
            for p in fp.Pads():
                if not (p.IsOnLayer(pcbnew.F_Cu) or p.GetDrillSize().x):
                    continue
                if p.GetNetname() in nets and (not through or fp.GetReference() in through):
                    continue            # the pads the pair leaves from or flows through; its connector pins stay in the way
                bb = p.GetBoundingBox()
                e = extra(p.GetNetname())       # a wider clearance to that net than the pair's own
                self.rect(T(bb.GetLeft()) - e, T(bb.GetTop()) - e, T(bb.GetRight()) + e, T(bb.GetBottom()) + e)
        for t in board.GetTracks():
            if t.GetNetname() in nets:
                continue
            e = extra(t.GetNetname())
            if t.GetClass() == "PCB_VIA":
                self.circle(T(t.GetPosition().x), T(t.GetPosition().y), T(t.GetWidth(pcbnew.F_Cu)) / 2 + e)
            elif t.GetLayer() == pcbnew.F_Cu:
                self.segment(T(t.GetStart().x), T(t.GetStart().y), T(t.GetEnd().x), T(t.GetEnd().y), T(t.GetWidth()) / 2 + e)
        e = route.COPPER_EDGE
        self.dist = np.minimum(self.dist, np.minimum.reduce([self.X - e, pcb.W - e - self.X, self.Y - e, pcb.H - e - self.Y]))
        self.circle(*pcb.CLOCK, pcb.CLOCK_CUT + e)     # the C-LOCK cutout
        self.half = half
        self.near = np.zeros(self.dist.shape, bool)
        self.clear = 0.0

    def window(self, x0, y0, x1, y1, reach):
        i0 = max(int((x0 - reach - self.x0) / G), 0)
        i1 = min(int((x1 + reach - self.x0) / G) + 2, self.nx)
        j0 = max(int((y0 - reach - self.y0) / G), 0)
        j1 = min(int((y1 + reach - self.y0) / G) + 2, self.ny)
        return slice(j0, j1), slice(i0, i1)

    def rect(self, x0, y0, x1, y1):
        w = self.window(x0, y0, x1, y1, 3.0)
        X, Y = self.X[w], self.Y[w]
        d = np.hypot(np.maximum(np.maximum(x0 - X, X - x1), 0), np.maximum(np.maximum(y0 - Y, Y - y1), 0))
        self.dist[w] = np.minimum(self.dist[w], d)

    def circle(self, x, y, r):
        w = self.window(x, y, x, y, 3.0 + r)
        self.dist[w] = np.minimum(self.dist[w], np.hypot(self.X[w] - x, self.Y[w] - y) - r)

    def segment(self, ax, ay, bx, by, r):
        w = self.window(min(ax, bx), min(ay, by), max(ax, bx), max(ay, by), 3.0 + r)
        X, Y = self.X[w], self.Y[w]
        dx, dy = bx - ax, by - ay
        k = np.clip(((X - ax) * dx + (Y - ay) * dy) / ((dx * dx + dy * dy) or 1.0), 0, 1)
        self.dist[w] = np.minimum(self.dist[w], np.hypot(X - ax - k * dx, Y - ay - k * dy) - r)

    def relax(self, points, radius, clear):
        """Near these points (the pads where the pair starts, flows through and ends), the clearance alone,
        not the keep: the way out of a fine pitch package."""
        for x, y in points:
            self.near |= np.hypot(self.X - x, self.Y - y) < radius
        self.clear = clear

    def cell(self, p):
        return int(round((p[1] - self.y0) / G)), int(round((p[0] - self.x0) / G))

    def point(self, c):
        return self.x0 + c[1] * G, self.y0 + c[0] * G

    def free(self, c, keep):
        j, i = c
        if not (0 <= j < self.ny and 0 <= i < self.nx):
            return False
        return self.dist[j, i] >= self.half + (self.clear if self.near[j, i] else keep)

    def astar(self, a, b, keep):
        """Cells of the centre line from cell a to cell b, or None."""
        heap = [(math.dist(a, b), 0.0, a, d) for d in range(8)]
        seen, prev = {}, {}
        while heap:
            _, g, c, d = heapq.heappop(heap)
            if c == b:
                path = [c]
                while (c, d) in prev:
                    c, d = prev[(c, d)]
                    path.append(c)
                return path[::-1]
            if seen.get((c, d), math.inf) <= g:
                continue
            seen[(c, d)] = g
            for nd in (d, (d + 1) % 8, (d - 1) % 8, (d + 2) % 8, (d - 2) % 8):
                n = (c[0] + DIRS[nd][1], c[1] + DIRS[nd][0])
                if n != b and not self.free(n, keep):
                    continue
                ng = g + math.hypot(*DIRS[nd]) + TURN * min((nd - d) % 8, (d - nd) % 8)
                if ng < seen.get((n, nd), math.inf):
                    prev[(n, nd)] = (c, d)
                    heapq.heappush(heap, (ng + math.dist(n, b), ng, n, nd))
        return None


def simplify(points):
    """Drop the points where the line goes straight on, and repeated points."""
    pts = [p for k, p in enumerate(points) if k == 0 or math.dist(p, points[k - 1]) > 1e-6]
    out = [pts[0]]
    for p, q in zip(pts[1:], pts[2:]):
        a = out[-1]
        if abs((p[0] - a[0]) * (q[1] - p[1]) - (p[1] - a[1]) * (q[0] - p[0])) > 1e-6:
            out.append(p)
    out.append(pts[-1])
    return out


def offset(line, h):
    """The polyline moved sideways by h (to the left of the way, y down), corners where the moved segments
    cross."""
    segs = []
    for a, b in zip(line, line[1:]):
        L = math.dist(a, b)
        nx, ny = (b[1] - a[1]) / L, -(b[0] - a[0]) / L
        segs.append(((a[0] + h * nx, a[1] + h * ny), (b[0] + h * nx, b[1] + h * ny)))
    pts = [segs[0][0]]
    for (a, b), (c, d) in zip(segs, segs[1:]):
        r, s = (b[0] - a[0], b[1] - a[1]), (d[0] - c[0], d[1] - c[1])
        den = r[0] * s[1] - r[1] * s[0]
        if abs(den) < 1e-12:
            pts.append(b)
        else:
            t = ((c[0] - a[0]) * s[1] - (c[1] - a[1]) * s[0]) / den
            pts.append((a[0] + t * r[0], a[1] + t * r[1]))
    pts.append(segs[-1][1])
    return pts


def ends(fp, two, grid, toward, keep, near=None, axis=None):
    """Where the pair may leave a pair of pads: for each of the 8 directions (only `axis`, a unit vector,
    when given), the first free cell, best first (near, away from the part, toward the other end).
    Returns [cell]."""
    m = ((two[0][0] + two[1][0]) / 2, (two[0][1] + two[1][1]) / 2)
    out = (m[0] - pcbnew.ToMM(fp.GetPosition().x), m[1] - pcbnew.ToMM(fp.GetPosition().y))
    to = (toward[0] - m[0], toward[1] - m[1])
    found = []
    for dx, dy in DIRS:
        u = (dx / math.hypot(dx, dy), dy / math.hypot(dx, dy))
        if axis and u[0] * axis[0] + u[1] * axis[1] < 0.99:
            continue
        for k in range(int((near or ESCAPE_MIN) / G), int((near or ESCAPE_MIN) / G + ESCAPE / G) + 1):
            c = grid.cell((m[0] + k * G * u[0], m[1] + k * G * u[1]))
            if grid.free(c, keep):
                found.append((k * G - 0.3 * (u[0] * out[0] + u[1] * out[1]) / (math.hypot(*out) or 1)
                              - 0.3 * (u[0] * to[0] + u[1] * to[1]) / (math.hypot(*to) or 1), c))
                break
    return [c for _, c in sorted(found)]


def pad_axis(fp, net):
    """Outward along the long side of the pad of `net`: the way out of a package with its pins on its sides."""
    p = next(p for p in fp.Pads() if p.GetNetname() == net)
    bb = p.GetBoundingBox()
    d = (pcbnew.ToMM(p.GetPosition().x - fp.GetPosition().x), pcbnew.ToMM(p.GetPosition().y - fp.GetPosition().y))
    if bb.GetWidth() > bb.GetHeight():
        return (math.copysign(1.0, d[0]), 0.0)
    return (0.0, math.copysign(1.0, d[1]))


def left_net(two, left, right, pnet, nnet):
    """The net the left line must carry at a pair of pads (P pad first): the pad lying further toward the
    left line, across the pair (from the right line end to the left one)."""
    side = ((two[0][0] - two[1][0]) * (left[0] - right[0]) + (two[0][1] - two[1][1]) * (left[1] - right[1]))
    return pnet if side > 0 else nnet


def through(pads, pnet, nnet, before):
    """An ESD array the pair flows through: the rows of its pads (P, N) on both nets, the one nearer the
    stop before first; returns (entry point, exit point, entry row)."""
    (p1, p2), (n1, n2) = pads[pnet], pads[nnet]
    if math.dist(p1, n2) < math.dist(p1, n1):
        n1, n2 = n2, n1             # rows: p1 with n1, p2 with n2
    rows = [(p1, n1), (p2, n2)]
    mids = [((p[0] + n[0]) / 2, (p[1] + n[1]) / 2) for p, n in rows]
    if math.dist(mids[1], before) < math.dist(mids[0], before):
        rows, mids = rows[::-1], mids[::-1]
    u = (mids[1][0] - mids[0][0], mids[1][1] - mids[0][1])
    L = math.hypot(*u)
    u = (u[0] / L, u[1] / L)
    return ((mids[0][0] - THROUGH * u[0], mids[0][1] - THROUGH * u[1]),
            (mids[1][0] + THROUGH * u[0], mids[1][1] + THROUGH * u[1]), rows[0])


def route_pair(board, cu, pnet, nnet, keep, reserved=()):
    """Lay one pair, clear of the reserved runs of the other pairs ([(a, b, half width)]). Returns (report,
    {net: line}) with the lines laid, or (report, None)."""
    width = project.CLASSES[project.class_of(pnet)][0]
    pitch = width + project.PAIR_GAP + MARGIN_GAP
    pads = {}
    for fp in board.GetFootprints():
        for p in fp.Pads():
            if p.GetNetname() in (pnet, nnet) and pcbnew.ToMM(p.GetPosition().x) < pcb.W:
                pads.setdefault(fp.GetReference(), {}).setdefault(p.GetNetname(), []).append(route.xy(p.GetPosition()))
    both = [r for r, d in pads.items() if len(d) == 2]
    ic = max((r for r in both if r[0] == "U"), key=lambda r: board.FindFootprintByReference(r).GetPadCount())
    conn = next(r for r in both if r[0] == "J")
    middle = sorted((r for r in both if r not in (ic, conn)), key=lambda r: math.dist(pads[r][pnet][0], pads[ic][pnet][0]))

    def two(r):
        return pads[r][pnet][0], pads[r][nnet][0]

    pts = [p for d in pads.values() for ps in d.values() for p in ps]
    box = [min(x for x, _ in pts) - MARGIN, min(y for _, y in pts) - MARGIN,
           max(x for x, _ in pts) + MARGIN, max(y for _, y in pts) + MARGIN]
    if middle:
        # the grid through the axis of the ESD array: the pair flows through it on its channels, not off by a cell
        e = through(pads[middle[0]], pnet, nnet, two(ic)[0])[0]
        box[0] = e[0] - math.ceil((e[0] - box[0]) / G) * G
        box[1] = e[1] - math.ceil((e[1] - box[1]) / G) * G
    clear = project.CLASSES[project.class_of(pnet)][1]
    grid = Grid(board, {pnet, nnet}, box, pitch / 2 + width / 2, lambda n: max(cu.gap(pnet, n) - clear, 0.0),
                [ic] + middle)
    grid.relax([p for r in [ic, conn] + middle for ps in pads[r].values() for p in ps], RELAX, clear)
    for a, b, h in reserved:
        grid.segment(a[0], a[1], b[0], b[1], h + keep)
    fixed = []                      # the straight runs through the ESD arrays: (entry, exit, entry row)
    before = two(ic)[0]
    for r in middle:
        e = through(pads[r], pnet, nnet, before)
        # on the grid: a point off it leaves a stub of a few microns, and its offset a corner far off
        e = (grid.point(grid.cell(e[0])), grid.point(grid.cell(e[1])), e[2])
        fixed.append(e)
        before = e[1]
    axis = pad_axis(board.FindFootprintByReference(ic), pnet)
    starts = ends(board.FindFootprintByReference(ic), two(ic), grid, fixed[0][0] if fixed else two(conn)[0], keep,
                  axis=axis)        # straight out of a fine pitch package
    # and a straight run along the pads first: both lines start level, their escapes converge evenly
    mid = ((two(ic)[0][0] + two(ic)[1][0]) / 2, (two(ic)[0][1] + two(ic)[1][1]) / 2)
    lead = (mid[0] + axis[0] * ESCAPE_LEAD, mid[1] + axis[1] * ESCAPE_LEAD)
    if not starts:
        return f"{pnet}: no way out of {ic}", None
    # a connector with through-hole pins in two rows: the pair stops short of them, each line goes on alone
    tht = all(p.GetDrillSize().x for p in board.FindFootprintByReference(conn).Pads() if p.GetNetname() in (pnet, nnet))
    lasts = ends(board.FindFootprintByReference(conn), two(conn), grid, fixed[-1][1] if fixed else two(ic)[0], keep,
                 ESCAPE_THT if tht else None)
    why = f"no way into {conn}"
    for last in lasts:
        # A* from the IC to each ESD entry, straight through it, on to the connector
        line = [lead, grid.point(starts[0])]
        ok = True
        for entry, exit_, _ in fixed:
            cells = grid.astar(grid.cell(line[-1]), grid.cell(entry), keep)
            if not cells:
                ok, why = False, f"no way to the ESD at ({entry[0]:.1f}, {entry[1]:.1f})"
                break
            line += [grid.point(c) for c in cells[1:-1]] + [entry, exit_]
        if not ok:
            break
        cells = grid.astar(grid.cell(line[-1]), last, keep)
        if not cells:
            why = f"no way from ({line[-1][0]:.1f}, {line[-1][1]:.1f}) to {conn}"
            continue
        line = simplify(line + [grid.point(c) for c in cells[1:]])
        left, right = offset(line, pitch / 2), offset(line, -pitch / 2)
        lnet = left_net(two(ic), left[0], right[0], pnet, nnet)
        if left_net(two(conn), left[-1], right[-1], pnet, nnet) != lnet:
            why = "the polarity crosses at every way into the connector"
            if VERBOSE:
                print("      polarity: left at the IC", lnet, "at the connector", left_net(two(conn), left[-1], right[-1], pnet, nnet),
                      "end", [round(v, 2) for v in line[-1]], "from", [round(v, 2) for v in line[-2]])
            continue
        # through the ESD arrays: the left line over the pads of its net
        if any(left_net(row, left[k], right[k], pnet, nnet) != lnet
               for entry, _, row in fixed
               for k in [min(range(len(line) - 1), key=lambda i: route.seg_dist(entry, line[i], line[i + 1]))]):
            why = "the polarity crosses at an ESD array"
            continue
        lines = {lnet: left, ({pnet, nnet} - {lnet}).pop(): right}
        tracks = []
        for net in (pnet, nnet):
            ln = lines[net]
            tracks += [(net, a, b) for a, b in zip(ln, ln[1:])]
            tracks += [(net, pads[ic][net][0], ln[0])]
        base = tracks
        for order in ((pnet, nnet), (nnet, pnet)):      # each line on to its pin, then the other
            tracks = list(base)
            joined = True
            for net in order:
                path = join(cu, board, net, lines[net][-1], pads[conn][net][0], width, [t for t in tracks if t[0] != net])
                if not path:
                    joined = False
                    why = f"{net} cannot reach its pin of {conn}"
                    break
                tracks += [(net, a, b) for a, b in zip(path, path[1:])]
            if not joined:
                continue
            bad = next(((net, a, b) for net, a, b in tracks
                        if not cu.track_ok(net, a, b, width, cu.near(a, b, width + 1.0), True)
                        or any(seg_gap((a, b), (c, d)) < width + clear - 0.002 for m, c, d in tracks if m != net)), None)
            if not bad:
                break
        if not joined:
            continue
        if bad and VERBOSE:
            print("     ", f"({bad[1][0]:.2f}, {bad[1][1]:.2f})-({bad[2][0]:.2f}, {bad[2][1]:.2f}) [{bad[0]}]",
                  blocker(cu, bad[0], bad[1], bad[2], width) if not cu.track_ok(bad[0], bad[1], bad[2], width, cu.near(bad[1], bad[2], width + 1.0), True) else
                  min((seg_gap((bad[1], bad[2]), (c, d)), c, d) for m, c, d in tracks if m != bad[0]))
        if bad:
            why = (f"blocked at ({bad[1][0]:.2f}, {bad[1][1]:.2f})-({bad[2][0]:.2f}, {bad[2][1]:.2f}) [{bad[0]}] by "
                   + blocker(cu, bad[0], bad[1], bad[2], width))
            continue
        for net, a, b in tracks:
            if math.dist(a, b) > 1e-3:
                cu.add_track(net, a, b, width, pcbnew.F_Cu)
        length = sum(math.dist(a, b) for a, b in zip(line, line[1:]))
        return f"{pnet}/{nnet}: {length:.1f} mm, {len(line) - 2} bend(s)", lines
    return f"{pnet}: {why}", None


def seg_gap(s, t):
    """Distance between two segments (centre lines)."""
    (a, b), (c, d) = s, t
    if segments_cross(a, b, c, d):
        return 0.0
    return min(route.seg_dist(a, c, d), route.seg_dist(b, c, d), route.seg_dist(c, a, b), route.seg_dist(d, a, b))


def segments_cross(a, b, c, d):
    def side(p, q, r):
        return (q[0] - p[0]) * (r[1] - p[1]) - (q[1] - p[1]) * (r[0] - p[0])
    return side(a, b, c) * side(a, b, d) < 0 and side(c, d, a) * side(c, d, b) < 0


def join(cu, board, net, a, pad, width, others):
    """A single line from a to its pad: straight or with one bend when it clears everything, the other line
    of the pair (others: [(net, a, b)]) included; else by A* on a grid of its own. A list of points, or None."""
    clear = project.CLASSES[project.class_of(net)][1]

    def ok(path):
        return all(cu.track_ok(net, u, v, width, cu.near(u, v, width + 1.0), True)
                   and all(seg_gap((u, v), (c, d)) >= width + clear - 0.002 for _, c, d in others) for u, v in zip(path, path[1:]))

    path = next((p for p in route.bends(a, pad) if ok(p)), None)
    if path:
        return path
    box = (min(a[0], pad[0]) - MARGIN, min(a[1], pad[1]) - MARGIN, max(a[0], pad[0]) + MARGIN, max(a[1], pad[1]) + MARGIN)
    grid = Grid(board, {net}, box, width / 2, lambda n: max(cu.gap(net, n) - clear, 0.0))
    for _, c, d in others:
        grid.segment(c[0], c[1], d[0], d[1], width / 2)
    grid.relax([pad], 1.0, clear)
    cells = grid.astar(grid.cell(a), grid.cell(pad), clear)
    if not cells:
        return None
    path = simplify([a] + [grid.point(c) for c in cells[1:-1]] + [pad])
    return path if ok(path) else None


def blocker(cu, net, a, b, width):
    """What stops a track on layer 1, for the report."""
    seg = pcbnew.SHAPE_SEGMENT(route.vec(a), route.vec(b), pcbnew.FromMM(width))
    for o in cu.near(a, b, width + 1.0):
        if o.net == net:
            continue
        if o.drill and route.seg_dist(o.centre, a, b) < o.drill + width / 2 + route.HOLE_GAP:
            return f"a hole of {o.net} at ({o.centre[0]:.2f}, {o.centre[1]:.2f})"
        if o.top and o.shape.Collide(seg, pcbnew.FromMM(cu.gap(net, o.net))):
            kind = "pad" if o.pad else "track or via"
            return f"a {kind} of {o.net} at ({o.centre[0]:.2f}, {o.centre[1]:.2f})"
    return "the edge or the C-LOCK"


def esd_runs(board, pnet, nnet):
    """{ESD reference: (entry, exit)} of a pair, before routing."""
    pads = {}
    for fp in board.GetFootprints():
        for p in fp.Pads():
            if p.GetNetname() in (pnet, nnet) and pcbnew.ToMM(p.GetPosition().x) < pcb.W:
                pads.setdefault(fp.GetReference(), {}).setdefault(p.GetNetname(), []).append(route.xy(p.GetPosition()))
    both = [r for r, d in pads.items() if len(d) == 2]
    ic = max((r for r in both if r[0] == "U"), key=lambda r: board.FindFootprintByReference(r).GetPadCount())
    out = {}
    for r in both:
        if r != ic and r[0] == "U":
            e = through(pads[r], pnet, nnet, pads[ic][pnet][0])
            out[r] = (e[0], e[1])
    return out


def terminations(board):
    """Parts on one line of a pair only (the Ethernet terminations): {ref: (footprint, net)}."""
    pair = {n for p in PAIRS for n in p}
    out = {}
    for fp in board.GetFootprints():
        nets = {p.GetNetname() for p in fp.Pads()}
        if fp.GetReference()[0] == "R" and len(nets & pair) == 1:
            out[fp.GetReference()] = (fp, (nets & pair).pop())
    return out


def pad_ok(cu, fp):
    """The pads of a placed part clear of the copper of the other nets on layer 1 and of the holes."""
    for p in fp.Pads():
        poly = p.GetEffectivePolygon(pcbnew.F_Cu, pcbnew.ERROR_INSIDE)
        c = route.xy(p.GetPosition())
        for o in cu.near(c, c, 2.0):
            if o.net == p.GetNetname():
                continue
            if o.drill and math.dist(c, o.centre) < o.drill + 0.6 + route.HOLE_GAP:
                return False
            if o.top and poly.Collide(o.shape, pcbnew.FromMM(cu.gap(p.GetNetname(), o.net) + 0.01)):
                return False        # 10 um over: both polygons are drawn inside the true shapes
    return True


def place_termination(cu, fp, net, lines, occ, gap):
    """Against its line, nearest the IC end, its axis across the pair: either on the side away from the
    other line, signal pad just over its line; or, when that side is taken (the line inside a port, facing
    the other pair), straddling the other line of its pair, which runs between the two pads."""
    ln = lines[net]
    other = next(l for n, l in lines.items() if n != net)
    width = project.CLASSES[project.class_of(net)][0]
    pitch = width + gap
    clear = project.CLASSES[project.class_of(net)][1]
    sig = next(p for p in fp.Pads() if p.GetNetname() == net)
    vdd = next(p for p in fp.Pads() if p.GetNetname() != net)
    half = pcbnew.ToMM(sig.GetSize().x) / 2          # the pads lie along the footprint x axis
    s0 = 0.0
    for a, b in zip(ln, ln[1:]):
        L = math.dist(a, b)
        t = ((b[0] - a[0]) / L, (b[1] - a[1]) / L)
        for k in range(int(L / 0.1) + 1):
            s = s0 + k * 0.1
            if s < TERM_FROM:
                continue
            if s > TERM_TO:
                return False
            p = (a[0] + t[0] * k * 0.1, a[1] + t[1] * k * 0.1)
            nrm = (-t[1], t[0])
            q = min(((route.seg_dist(p, u, v), u, v) for u, v in zip(other, other[1:])), key=lambda e: e[0])
            near = nearest(p, q[1], q[2])
            toward = -1.0 if nrm[0] * (p[0] - near[0]) + nrm[1] * (p[1] - near[1]) > 0 else 1.0
            m = 0.02                # over the clearance, above the 10 um of pad_ok
            for sign, c in ((-toward, half - pitch + width / 2 + clear + m),        # away, over its line
                            (toward, pitch - width / 2 - clear - m - half)):       # straddling the other
                out = (sign * nrm[0], sign * nrm[1])
                ang = math.degrees(math.atan2(out[1], out[0]))
                for rot in (0, 45, 90, 135, 180, 225, 270, 315):
                    fp.SetOrientationDegrees(rot)
                    fp.SetPosition(pcbnew.VECTOR2I(0, 0))
                    d = (pcbnew.ToMM(vdd.GetPosition().x - sig.GetPosition().x), pcbnew.ToMM(vdd.GetPosition().y - sig.GetPosition().y))
                    if abs((math.degrees(math.atan2(d[1], d[0])) - ang + 180) % 360 - 180) > 1:
                        continue
                    target = (p[0] + out[0] * c, p[1] + out[1] * c)
                    sp = route.xy(sig.GetPosition())
                    fp.SetPosition(route.vec((target[0] - sp[0], target[1] - sp[1])))
                    cy = fp.GetCourtyard(pcbnew.F_CrtYd)
                    r = pcb.mm_rect(cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False))
                    hit = next((ref for (x0, y0, x1, y1), ref in occ if x0 < r[2] and r[0] < x1 and y0 < r[3] and r[1] < y1), None)
                    if hit:
                        WHY["courtyard"] += 1
                        WHY.setdefault(fp.GetReference(), set()).add(hit)
                        continue
                    WHY["pads"] += 1
                    if pad_ok(cu, fp):
                        occ.append((r, fp.GetReference()))
                        for x in fp.Pads():
                            bb = x.GetBoundingBox()
                            cu.items.append(route.Item(x.GetNetname(), route.xy(x.GetPosition()),
                                                       pcbnew.ToMM(max(bb.GetWidth(), bb.GetHeight())) / 2,
                                                       x.GetEffectivePolygon(pcbnew.F_Cu, pcbnew.ERROR_INSIDE), 0.0,
                                                       True, False, True))
                        return True
        s0 += L
    return False


def nearest(c, a, b):
    dx, dy = b[0] - a[0], b[1] - a[1]
    k = min(max(((c[0] - a[0]) * dx + (c[1] - a[1]) * dy) / ((dx * dx + dy * dy) or 1.0), 0.0), 1.0)
    return a[0] + k * dx, a[1] + k * dy


def run(board):
    terms = terminations(board)
    home = {r: (fp.GetPosition(), fp.GetOrientationDegrees()) for r, (fp, _) in terms.items()}
    for k, (fp, _) in enumerate(terms.values()):        # lifted off the board while the pairs are routed
        fp.SetPosition(route.vec((pcb.W + 20 + 3 * k, 10.0)))
    cu = route.Copper(board)
    # the runs of the pairs through their ESD arrays, known before any routing: each pair keeps clear of the
    # others' (else the first one routed may pass where the next one must enter its array)
    runs = {}
    for p, n in PAIRS:
        width = project.CLASSES[project.class_of(p)][0]
        for r, (a, b) in esd_runs(board, p, n).items():
            L = math.dist(a, b)
            u = ((b[0] - a[0]) / L, (b[1] - a[1]) / L)
            # with room to turn on both sides: a pair routed first does not hug the way in or out of another
            a = (a[0] - RESERVE * u[0], a[1] - RESERVE * u[1])
            b = (b[0] + RESERVE * u[0], b[1] + RESERVE * u[1])
            runs.setdefault((p, n), []).append((a, b, (width + project.PAIR_GAP) / 2 + width / 2))
    laid = {}
    for p, n in PAIRS:
        reserved = [x for k, v in runs.items() if k != (p, n) for x in v]
        report, lines = route_pair(board, cu, p, n, project.PAIR_KEEP, reserved)
        print("pairs pass:", report, flush=True)
        if lines:
            laid.update({net: lines for net in lines})
    occ = []
    for fp in board.GetFootprints():
        if fp.GetReference() not in terms:
            cy = fp.GetCourtyard(pcbnew.F_CrtYd)
            occ.append((pcb.mm_rect(cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False)), fp.GetReference()))
    # the ones that did not fit go first next time, up to TERM_TRIES times: the first placed take the spots
    order, base_items, base_occ = sorted(terms), len(cu.items), list(occ)
    for _ in range(TERM_TRIES):
        del cu.items[base_items:]
        occ = list(base_occ)
        back = []
        for r in order:
            fp, net = terms[r]
            if not (net in laid and place_termination(cu, fp, net, laid[net], occ, project.PAIR_GAP + MARGIN_GAP)):
                back.append(r)
        if not back:
            break
        order = back + [r for r in order if r not in back]
    for r in back:
        fp = terms[r][0]
        fp.SetOrientationDegrees(home[r][1])
        fp.SetPosition(home[r][0])
    print(f"pairs pass: {len(terms) - len(back)} termination(s) against their line"
          + (f", {len(back)} back where they were: {' '.join(back)} (spots refused: {WHY})" if back else ""), flush=True)
