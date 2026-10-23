# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Functional blocks of the base board, the first step of the placement: the parts of a schematic sheet laid
out together around their main chip, then placed on the board as a whole.

Blocks follow the sheets, with two exceptions: an axis is one block around its dual RJ45 (its half of a
drive sheet and its encoder sheet), the quad driver shared by two axes a block of its own; the parts of a
sheet of slow signals (SPREAD) are no block, each goes next to what it serves.

Inside a block, the main chip stands at the origin; the other chips and connectors (satellites) are placed
one at a time where the weighted ratsnest of the block is shortest and crosses least (WEIGHTS: the fast
signals count most); the passives then go against the pin they serve (pcb.auto_place).

Run with the Python shipped with KiCad:
    "C:/Program Files/KiCad/10.0/bin/python.exe" blocks.py                    the blocks and their members
    ... blocks.py show BLOCK board.kicad_pcb                                  one block laid out alone
"""
import collections
import itertools
import math
import os
import re
import sys

import pcbnew

import pcb

SPREAD = {"/Safety/"}
AXIS_SHEETS = {"/Drives 0-1/": (0, 1), "/Drives 2-3/": (2, 3)}
# Signal weights for the ratsnest: fast edges count most, slow ones (reset, boot, LEDs, sense) least
WEIGHTS = [
    (r".*(SWDIO|SWCLK|SWO)$", 4.0),
    (r"USB_D[PM]|/ESC/(TX|RX)[PN][AB]", 4.0),
    (r"ESC_S(CK|CS|IO[0-3])|.*CLK25.*", 4.0),
    (r"NRST|.*BOOT0|.*LED.*|.*_LA$|VBUS_SENSE|VIN_SENSE", 0.25),
]
CROSSING = 5.0      # mm of weighted ratsnest a crossing is worth
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
        if sheet in AXIS_SHEETS or sheet.startswith("/Encoder "):
            continue
        out[sheet.strip("/")] = refs
    # axes: the dual RJ45 of axis n with the parts of its drive sheet that reach it alone, and encoder sheet n
    for sheet, axes in AXIS_SHEETS.items():
        refs = by_sheet[sheet]
        nets = {r: {n for n in pins.get(r, {}).values() if n and n not in POWER} for r in refs}
        jacks = sorted((r for r in refs if comps[r]["value"] == pcb.AXIS_JACK), key=lambda r: int(r[1:]))
        on_net = collections.defaultdict(set)
        for r in refs:
            for n in nets[r]:
                on_net[n].add(r)
        owner = {}
        for axis, jack in zip(axes, jacks):
            owner[jack] = axis
        frontier = {j: owner[j] for j in jacks}
        while frontier:
            reach = collections.defaultdict(set)
            for r, a in frontier.items():
                for n in nets[r]:
                    for q in on_net[n]:
                        if q not in owner and comps[q]["value"] != "ST26C31BDR":
                            reach[q].add(a)
            frontier = {}
            for q, axs in reach.items():
                if len(axs) == 1:
                    owner[q] = frontier[q] = axs.pop()
        for axis in axes:
            out[f"Axis {axis}"] = [r for r in refs if owner.get(r) == axis] + by_sheet[f"/Encoder {axis}/"]
        out[f"Drivers {axes[0]}-{axes[1]}"] = [r for r in refs if r not in owner]
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


def cross(a, b, c, d):
    def side(o, p, q):
        return (p[0] - o[0]) * (q[1] - o[1]) - (p[1] - o[1]) * (q[0] - o[0])
    return side(c, d, a) * side(c, d, b) < 0 and side(a, b, c) * side(a, b, d) < 0


def ratsnest_cost(fps, placed):
    """Weighted length and crossings of the ratsnest of the signal nets between the placed parts."""
    pads = collections.defaultdict(list)
    for r in placed:
        for p in fps[r].Pads():
            n = p.GetNetname()
            if n and n not in POWER and not n.startswith("unconnected-"):
                pads[n].append((pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y)))
    edges = [(n, e) for n, pts in pads.items() for e in mst(pts)]
    length = sum(weight(n) * math.dist(*e) for n, e in edges)
    crossings = sum(max(weight(n1), weight(n2)) for (n1, (a, b)), (n2, (c, d)) in itertools.combinations(edges, 2)
                    if n1 != n2 and cross(a, b, c, d))
    return length + CROSSING * crossings


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


def layout(name, main, members, comps, pins, walls=()):
    """A board with the block alone, in board coordinates: the connectors of a long edge on their edge, the
    others around the main part, at mid-length; no part in the walls (rectangles). An axis block stays in the
    column of its jack. The C-LOCK is ignored: the block is placed on the board after.
    Returns (board, footprints, parts not placed)."""
    board, fps = make_board([main] + members, comps, pins)
    anchors = edge_connectors(fps, [main] + members)
    if edge_refs(fps.values()) == "A":
        jack = next(r for r in anchors if fps[r].GetValue() == pcb.AXIS_JACK)
        x = pcbnew.ToMM(fps[jack].GetPosition().x)
        walls = list(walls) + [(-1000.0, -1000.0, x - pcb.PITCH_A / 2, 1000.0), (x + pcb.PITCH_A / 2, -1000.0, 1000.0, 1000.0)]
    if not anchors:
        # the local bus header at its place, vertical, near the end: its parts stay on the board
        pcb.place_centred(fps[main], *(pcb.KEY[main] if main in END else (pcb.W / 2, pcb.H / 2, 0)))
        anchors = [main]
    occ = [o for r in anchors for o in pcb.occupied(fps[r])]
    satellites = [r for r in [main] + members if r not in anchors and (r[0] in "UJX" or r.startswith("SW")
                                                                       or any(r in t for t in TEMPLATES))]
    zones, lanes, clock = pcb.ZONES, pcb.LANES, pcb.CLOCK
    # the walls are the lanes of auto_place: no part but those of the pairs (none in these blocks) in them
    pcb.ZONES, pcb.LANES, pcb.CLOCK = {"/Modbus/ bus side": [(0, 0, 0, 0)]}, list(walls), (-1000.0, -1000.0)
    try:
        placed = place_satellites(fps, anchors, satellites, occ, list(walls),
                                  EDGE_WIDE if edge_refs(fps.values()) == "B" else 1.0)
        failed = pcb.auto_place(fps, {r: fps[r] for r in placed}, set())
    finally:
        pcb.ZONES, pcb.LANES, pcb.CLOCK = zones, lanes, clock
    return board, fps, failed


def instance(refs):
    """The parts of an axis block in the creation order of their repeated sheets: the n-th parts of two axes
    play the same role."""
    from circuit import c
    groups = []
    for p in c.parts:
        for g in (p["group"], p["also"]):
            if g and g not in groups and re.fullmatch(r"(drv|enc)\d+", g):
                groups.append(g)
    order = [r for g in groups for r in c.members(g)]
    mine = set(refs)
    return list(dict.fromkeys(r for r in order if r in mine))


def copy_layout(src, dst_refs, comps, pins):
    """A board with the parts of dst_refs at the relative places of their matches in src (a laid-out board of
    another instance)."""
    s = instance([fp.GetReference() for fp in src.GetFootprints()])
    d = instance(dst_refs)
    if len(s) != len(d) or any(comps[a]["value"] != comps[b]["value"] for a, b in zip(s, d)):
        raise SystemExit(f"instances differ: {s} / {d}")
    board, fps = make_board(d, comps, pins)
    for a, b in zip(s, d):
        f = src.FindFootprintByReference(a)
        fps[b].SetOrientation(f.GetOrientation())
        fps[b].SetPosition(f.GetPosition())
    return board, fps


def main():
    bl, spread, comps, pins = blocks()
    if len(sys.argv) > 2 and sys.argv[1] in ("show", "all"):
        # the axes first: the local bus header stands in the corner of axis 0 and keeps out of its block
        names = sorted(bl, key=lambda n: not n.startswith("Axis"))
        if sys.argv[1] == "show":
            needs_axis0 = END & ({bl[sys.argv[2]][0]} | set(bl[sys.argv[2]][1]))
            names = [n for n in names if (n.startswith("Axis 0") and needs_axis0) or n == sys.argv[2]]
        first, axis0 = {}, []
        for name in names:
            main_ref, members = bl[name]
            out = sys.argv[3] if sys.argv[1] == "show" else os.path.join(sys.argv[2], name.replace(" ", "_") + ".kicad_pcb")
            kind = re.sub(r"\s*\d.*$", "", name)
            if kind == "Axis" and kind in first:
                board, _ = copy_layout(first[kind], [main_ref] + members, comps, pins)
                failed = []
            else:
                walls = axis0 if END & ({main_ref} | set(members)) else []
                board, fps, failed = layout(name, main_ref, members, comps, pins, walls)
                first[kind] = board
                if name == "Axis 0":
                    jack = fps[main_ref]
                    dx = pcb.JACK_X[0] - pcbnew.ToMM(jack.GetPosition().x)
                    axis0 = [(x0 + dx, y0, x1 + dx, y1) for f in fps.values() for x0, y0, x1, y1 in pcb.occupied(f)]
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
