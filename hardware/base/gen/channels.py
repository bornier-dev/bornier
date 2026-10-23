# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Channel assignment check, between placement and routing: in a part made of identical independent
channels (ESD array, quad line driver or receiver, dual op amp), any signal may take any channel. Every
reordering of the channels is scored by the crossings of the ratsnest (minimum spanning tree of each net)
and its length; a better one than the schematic's is reported, to be carried over to circuit.py. The two
lines of a differential pair stay on channels side by side. The instances of a repeated sheet share one
drawing, so one reordering, scored over all of them.

Run with the Python shipped with KiCad, after pcb.py:
    "C:/Program Files/KiCad/10.0/bin/python.exe" channels.py [board]
Exit status 1 when a part has a better assignment.
"""
import itertools
import math
import os
import re
import sys

import pcbnew

import pcb

# Channels of each part, by value: the pins of one channel in a fixed order (input first, then the outputs;
# for a flow-through ESD array, the pin and the NC pin opposite it, which carries the line)
CHANNELS = {
    "TPD4E05U06DQAR": [(1, 10), (2, 9), (4, 7), (5, 6)],
    "ST26C31BDR": [(1, 2, 3), (7, 6, 5), (9, 10, 11), (15, 14, 13)],
    "AM26LV32EIDR": [(2, 1, 3), (6, 7, 5), (10, 9, 11), (14, 15, 13)],
    "OPA2990IDR": [(3, 2, 1), (5, 6, 7)],
}
# Channels side by side, by index: the two lines of a pair stay on one of these couples
ADJACENT = {"TPD4E05U06DQAR": [(0, 1), (2, 3)]}
# Nets left out of the ratsnest: planes, joined by vias wherever the pads are
PLANES = {"GND", "GNDISO", "+3V3", "+5V", "+VIN", "CHASSIS"}
CROSSING = 5.0      # mm of ratsnest a crossing is worth: two vias and a detour
GAIN = 1.0          # least gain, in mm, for a change of assignment


def xy(v):
    return pcbnew.ToMM(v.x), pcbnew.ToMM(v.y)


def mst(points):
    """Edges (a, b) of the minimum spanning tree of the points (Prim)."""
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


def cross(a, b, c, d):
    """Segments ab and cd cross (a shared end does not count)."""
    def side(o, p, q):
        return (p[0] - o[0]) * (q[1] - o[1]) - (p[1] - o[1]) * (q[0] - o[0])
    d1, d2, d3, d4 = side(c, d, a), side(c, d, b), side(a, b, c), side(a, b, d)
    return d1 * d2 < 0 and d3 * d4 < 0


def score(pads, nets):
    """(crossings, length) of the ratsnest of `nets`, pads {net: [points]}."""
    edges = [(n, e) for n in nets for e in mst(pads[n])]
    crossings = sum(1 for (n1, (a, b)), (n2, (c, d)) in itertools.combinations(edges, 2) if n1 != n2 and cross(a, b, c, d))
    return crossings, sum(math.dist(a, b) for _, (a, b) in edges)


def cost(s):
    return s[0] * CROSSING + s[1]


def twins(a, b):
    """The two lines of a differential pair: names alike but for P against N (or M) at one place."""
    diff = [(x, y) for x, y in zip(a, b) if x != y]
    return len(a) == len(b) and len(diff) == 1 and {*diff[0]} in ({"P", "N"}, {"P", "M"})


class Part:
    """One part with channels on the board: its signals per channel, and the scoring of a reordering."""

    def __init__(self, fp, net_pads):
        self.ref, self.chans = fp.GetReference(), CHANNELS[fp.GetValue()]
        self.pos = {int(p.GetNumber()): xy(p.GetPosition()) for p in fp.Pads() if p.GetNumber().isdigit()}
        net = {int(p.GetNumber()): p.GetNetname() for p in fp.Pads() if p.GetNumber().isdigit()}
        # the signals of each channel, in pin order; an unused channel carries none
        self.signals = [tuple(net[q] if net[q] not in PLANES and not net[q].startswith("unconnected-") else ""
                              for q in ch) for ch in self.chans]
        self.nets = sorted({n for s in self.signals for n in s if n})
        self.pairs = [(a, b) for a, b in itertools.combinations(self.nets, 2) if twins(a, b)]
        self.adjacent = ADJACENT.get(fp.GetValue())
        # the pads of these nets off this part stay put
        self.fixed = {n: [q for r, q in net_pads[n] if r != self.ref] for n in self.nets}

    def order(self, perm):
        """The signals per channel once channel k takes the signals of channel perm[k]."""
        return [self.signals[k] for k in perm]

    def allowed(self, perm):
        if not self.adjacent:
            return True
        where = {n: k for k, sig in enumerate(self.order(perm)) for n in sig if n}
        return all(tuple(sorted((where[a], where[b]))) in self.adjacent for a, b in self.pairs if where[a] != where[b])

    def score(self, perm):
        pads = {n: list(self.fixed[n]) for n in self.nets}
        for ch, sig in zip(self.chans, self.order(perm)):
            for q, n in zip(ch, sig):
                if n:
                    pads[n].append(self.pos[q])
        return score(pads, self.nets)

    def pins(self, perm):
        return {q: n for ch, sig in zip(self.chans, self.order(perm)) for q, n in zip(ch, sig) if n}


def roles():
    """{reference: role}: the parts of the instances of a repeated sheet match by rank in their group. A part
    outside any repeated sheet is a role of its own."""
    from circuit import c
    return {p["ref"]: (re.sub(r"\d+$", "", p["group"]), c.members(p["group"]).index(p["ref"])) if p["group"]
            else p["ref"] for p in c.parts}


def check(board):
    """[([parts], (crossings, length) now, best, perm)] for the roles with a better assignment."""
    net_pads = {}
    for fp in board.GetFootprints():
        for p in fp.Pads():
            if p.GetNetname():
                net_pads.setdefault(p.GetNetname(), []).append((fp.GetReference(), xy(p.GetPosition())))
    role = roles()
    groups = {}
    for fp in sorted(board.GetFootprints(), key=lambda f: f.GetReference()):
        if fp.GetValue() in CHANNELS:
            part = Part(fp, net_pads)
            if part.nets:
                groups.setdefault(role[part.ref], []).append(part)
    better = []
    for parts in groups.values():
        same = tuple(range(len(parts[0].chans)))

        def total(perm):
            s = [p.score(perm) for p in parts]
            return sum(k for k, _ in s), sum(length for _, length in s)

        now = best = total(same)
        best_perm = same
        for perm in itertools.permutations(same):
            if all(p.allowed(perm) for p in parts):
                s = total(perm)
                if cost(s) < cost(best) - 1e-6:
                    best, best_perm = s, perm
        if best_perm != same and cost(best) <= cost(now) - GAIN:
            better.append((parts, now, best, best_perm))
    return better


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(pcb.STAGES, "0-placed.kicad_pcb")
    better = check(pcbnew.LoadBoard(path))
    for parts, now, best, perm in better:
        print(f"{'/'.join(p.ref for p in parts)}: {now[0]} crossing(s) {now[1]:.1f} mm -> {best[0]} crossing(s) "
              f"{best[1]:.1f} mm, channel k takes the signals of channel {[k + 1 for k in perm]}")
        for p in parts:
            print(f"   {p.ref}:", ", ".join(f"{q}: {n}" for q, n in sorted(p.pins(perm).items())))
    print(f"channels: {len(better)} role(s) with a better assignment")
    sys.exit(1 if better else 0)


if __name__ == "__main__":
    main()
