# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Base board routing, in passes: power first, then fast signals, then slow signals.

Run with the Python shipped with KiCad, after pcb.py:
    "C:/Program Files/KiCad/10.0/bin/python.exe" route.py <pass>      gnd, 3v3, 5v, vin, power [Freerouting passes]
    ... route.py back <pass>       the working board back to the end of that pass
    ... route.py report            zone fill and DRC of the working board
Each pass starts from the stage written by the one before (../kicad/stages/, not versioned; pcb.py writes
the first one), so a pass can be run again on its own; a part moved in pcb.py means running the passes
again from the first. The working board is ../kicad/base.kicad_pcb. Freerouting 2.4.1 (https://github.com/freerouting/freerouting/releases)
is not in the repository: FREEROUTING_JAR, or hardware/tools/freerouting-2.4.1.jar. It needs Java 25 or later:
JAVA, if the java on the path is older.

Stack-up (JLC04161H-7628, 1.6 mm): L1 parts and signals, L2 ground plane (one island of GNDISO under
the Modbus port), L3 supply planes (+5V under the axes, +3V3 under the MCU, ESC and bus, +VIN at the
power entry), L4 signals and a chassis band along the edges.

Pass "gnd": the planes, then a stub and a via of its own from every surface pad of GND and GNDISO down
to layer 2. Passes "3v3", "5v", "vin": the same for each supply, one at a time, down to its plane of layer 3, where
the pad lies over it. Pass "power": Freerouting on the supply, ground and chassis nets left.
"""
import collections
import math
import os
import re
import shutil
import subprocess
import sys

import pcbnew

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import pcb  # noqa: E402
import project  # noqa: E402
from kicadgen.kicad import cli  # noqa: E402

PCB = os.path.join(pcb.KICAD, "base.kicad_pcb")
JAVA = os.environ.get("JAVA", "java")
JAR = os.environ.get("FREEROUTING_JAR") or os.path.join(HERE, "..", "..", "tools", "freerouting-2.4.1.jar")
MM = pcbnew.FromMM
mm = pcbnew.ToMM
W, H, EDGE = pcb.W, pcb.H, pcb.END_KEEP

# Layer 3 supply planes, (x0, y0, x1, y1): 0.5 mm between planes of different nets.
# Each plane reaches the output of its regulator: +5V from L1 and C5 up the right edge to the axes, +3V3
# from just under the axes over the 3.3 V buck and the logic of the safety and drive supply blocks, +VIN
# around the 5 V buck input and down to the power entry.
SUPPLY_PLANES = {
    "+5V": [(EDGE, 14.0, W - EDGE, 47.0), (131.5, 47.0, W - EDGE, 70.0)],
    "+3V3": [(EDGE, 47.5, 131.0, 58.0), (EDGE, 58.0, 112.0, 71.0), (EDGE, 71.0, 123.0, H - EDGE)],
    "+VIN": [(112.5, 58.5, 131.0, 70.5), (123.5, 70.5, W - EDGE, H - EDGE)],
}
CHASSIS_BAND = 3.0          # layer 4, along the edges: the part-free rim where the board rests on the profile
ISO_MARGIN = 1.0            # around the bus side of the Modbus port: the isolation barrier
POWER_CLASSES = {"Input", "Rail", "Buck", "Limited", "Ground", "Chassis"}
# Passes, in order: each starts from the stage written by the one before (pcb.py writes "placed")
RAILS = {"3v3": "+3V3", "5v": "+5V", "vin": "+VIN"}
PASSES = ["placed", "gnd", *RAILS, "power"]
SURFACE = (pcbnew.PAD_ATTRIB_SMD, pcbnew.PAD_ATTRIB_CONN)   # surface pads, with or without paste
PLANE_INSET = 0.3           # a via stays this far inside the outline of its plane
FANOUT_REACH = 2.5          # longest stub from a pad centre to its via
FANOUT_EDGE = CHASSIS_BAND + 1.0    # vias stay off the chassis band and its clearance
HOLE_GAP = 0.25             # copper to hole and hole to hole, JLCPCB
LINK_REACH = 40.0          # longest layer 4 link from a via off its plane
LINK_TRIES = 30            # vias of the plane tried per link, nearest first
LINK_SPOTS = pcb.spiral(0.5, LINK_REACH)     # offsets for a new via in the plane, nearest first
NEW_VIA_COST = 1.0         # mm of track a new via is worth: an existing one is preferred at equal length
VIA_PITCH = 1.0            # between vias of different nets: plane copper left between them, or a via cut off


def rect_poly(x0, y0, x1, y1):
    p = pcbnew.SHAPE_POLY_SET()
    p.NewOutline()
    for x, y in ((x0, y0), (x1, y0), (x1, y1), (x0, y1)):
        p.Append(MM(x), MM(y))
    return p


def union(rects):
    p = pcbnew.SHAPE_POLY_SET()
    for r in rects:
        p.BooleanAdd(rect_poly(*r))
    return p


def add_zone(board, net, layer, poly, priority, name):
    z = pcbnew.ZONE(board)
    z.SetLayer(layer)
    z.SetNet(board.FindNet(net))
    z.SetZoneName(name)
    z.SetAssignedPriority(priority)
    z.SetMinThickness(MM(0.25))
    z.SetIslandRemovalMode(pcbnew.ISLAND_REMOVAL_MODE_ALWAYS)
    z.SetPadConnection(pcbnew.ZONE_CONNECTION_THT_THERMAL)   # SMD pads solid, through-hole leads relieved
    z.Outline().BooleanAdd(poly)     # a copy: SetOutline keeps the pointer that Python later frees
    board.Add(z)
    return z


def iso_island(board):
    """Rectangle around the pads of the bus side of the Modbus port, grown by the barrier margin."""
    fps = {fp.GetReference(): fp for fp in board.GetFootprints()}
    iso = set(pcb.iso_nets(fps))
    xs, ys = [], []
    for fp in fps.values():
        for p in fp.Pads():
            if p.GetNetname() in iso:
                bb = p.GetBoundingBox()
                xs += [pcbnew.ToMM(bb.GetLeft()), pcbnew.ToMM(bb.GetRight())]
                ys += [pcbnew.ToMM(bb.GetTop()), pcbnew.ToMM(bb.GetBottom())]
    return min(xs) - ISO_MARGIN, min(ys) - ISO_MARGIN, max(xs) + ISO_MARGIN, min(max(ys) + ISO_MARGIN, H)


def planes(board):
    """Ground on layer 2, supplies on layer 3, chassis band on layer 4."""
    island = rect_poly(*iso_island(board))
    gnd = rect_poly(0, 0, W, H)
    gnd.BooleanSubtract(rect_poly(*grow(iso_island(board), ISO_MARGIN)))
    add_zone(board, "GND", pcbnew.In1_Cu, gnd, 0, "ground plane")
    add_zone(board, "GNDISO", pcbnew.In1_Cu, island, 1, "isolated ground")
    for net, rects in SUPPLY_PLANES.items():
        p = union(rects)
        p.BooleanSubtract(rect_poly(*grow(iso_island(board), ISO_MARGIN)))
        add_zone(board, net, pcbnew.In2_Cu, p, 0, f"{net} plane")
    band = rect_poly(0, 0, W, H)
    band.BooleanSubtract(rect_poly(CHASSIS_BAND, CHASSIS_BAND, W - CHASSIS_BAND, H - CHASSIS_BAND))
    add_zone(board, "CHASSIS", pcbnew.B_Cu, band, 0, "chassis band")


def chassis_stand_ins(board):
    """Locked tracks that stand for the chassis band while Freerouting runs (it does not see zones on
    signal layers); returns their UUIDs."""
    stand_ins = []
    c = CHASSIS_BAND / 2
    for a, b in (((c, c), (W - c, c)), ((W - c, c), (W - c, H - c)), ((W - c, H - c), (c, H - c)), ((c, H - c), (c, c))):
        t = pcbnew.PCB_TRACK(board)
        t.SetStart(pcbnew.VECTOR2I(MM(a[0]), MM(a[1])))
        t.SetEnd(pcbnew.VECTOR2I(MM(b[0]), MM(b[1])))
        t.SetWidth(MM(CHASSIS_BAND))
        t.SetLayer(pcbnew.B_Cu)
        t.SetNet(board.FindNet("CHASSIS"))
        t.SetLocked(True)
        board.Add(t)
        stand_ins.append(t.m_Uuid.AsString())
    return stand_ins


def grow(r, d):
    return r[0] - d, r[1] - d, r[2] + d, r[3] + d


def keep_nets(dsn, keep):
    """DSN restricted to the nets of `keep`: the other nets are left out of the network, so Freerouting
    sees their pads as obstacles only."""
    out, i = [], 0
    pat = re.compile(r'\((net|class) ')
    while True:
        m = pat.search(dsn, i)
        if not m:
            out.append(dsn[i:])
            break
        start = m.start()
        depth, j = 0, start
        while True:
            ch = dsn[j]
            if ch == '"':
                j = dsn.index('"', j + 1)
            elif ch == "(":
                depth += 1
            elif ch == ")":
                depth -= 1
                if depth == 0:
                    break
            j += 1
        block = dsn[start:j + 1]
        out.append(dsn[i:start])
        if m.group(1) == "net":
            name = re.match(r'\(net\s+("([^"]*)"|(\S+))', block)
            name = name.group(2) if name.group(2) is not None else name.group(3)
            if name in keep:
                out.append(block)
        else:
            head = re.match(r'\(class\s+(\S+)', block).group(1)
            if head in POWER_CLASSES:
                out.append(block)
        i = j + 1
    return "".join(out)


def freerouting(board, keep, passes):
    dsn, ses = PCB.replace(".kicad_pcb", ".dsn"), PCB.replace(".kicad_pcb", ".ses")
    if not pcbnew.ExportSpecctraDSN(board, dsn):
        raise SystemExit("DSN export failed")
    text = open(dsn, encoding="utf-8").read()
    open(dsn, "w", encoding="utf-8", newline="\n").write(keep_nets(text, keep))
    if os.path.exists(ses):
        os.remove(ses)
    # -Xmx1g and SerialGC: one core and 1 GB per JVM; low priority, the machine stays usable
    flags = subprocess.BELOW_NORMAL_PRIORITY_CLASS if os.name == "nt" else 0
    # fanout: a via next to each SMD pad of a plane net, before the routing passes
    r = subprocess.run([JAVA, "-Xmx1g", "-XX:+UseSerialGC", "-jar", JAR, "-de", dsn, "-do", ses, "-mp", str(passes),
                        "--router.fanout.enabled=true", "--gui.enabled=false"],
                       capture_output=True, text=True, timeout=3600, creationflags=flags)
    log = (r.stdout + r.stderr).strip().splitlines()
    print("\n".join([s for s in log if "Applied CLI" in s or "anout" in s][:10] + log[-6:]), flush=True)
    if not os.path.exists(ses) or not pcbnew.ImportSpecctraSES(board, ses):
        raise SystemExit("Freerouting gave no result")


def refill():
    """Zone fill by kicad-cli: it loads the project, so the net classes and the custom rules."""
    rpt = PCB.replace(".kicad_pcb", "-drc.json")
    subprocess.run([cli(), "pcb", "drc", "--refill-zones", "--save-board", "--schematic-parity", "--severity-all",
                    "--format", "json", "-o", rpt, PCB], capture_output=True)
    return rpt


def gap_of(iso):
    """Clearance between two nets, mm: the larger of their classes, the barrier across the Modbus isolation."""
    def gap(a, b):
        live = a and b and not a.startswith("unconnected-") and not b.startswith("unconnected-")
        if live and (a in iso) != (b in iso):       # as the DRC barrier rule
            return ISO_MARGIN
        return max(project.CLASSES[project.class_of(n)][1] for n in (a, b))
    return gap


Item = collections.namedtuple("Item", "net centre reach shape drill top bottom pad")


class Copper:
    """The copper on the board, for the clearance checks of the stubs, vias and tracks added by a pass."""

    def __init__(self, board):
        fps = list(board.GetFootprints())
        self.board = board
        self.gap = gap_of(set(pcb.iso_nets({fp.GetReference(): fp for fp in fps})))
        self.plane = {}             # net: outlines of its zones on layers 2 and 3
        for z in board.Zones():
            if not z.GetIsRuleArea() and z.GetLayer() in (pcbnew.In1_Cu, pcbnew.In2_Cu):
                self.plane.setdefault(z.GetNetname(), []).append(z.Outline())
        self.items = []
        for fp in fps:
            for p in fp.Pads():
                layer = pcbnew.F_Cu if p.IsOnLayer(pcbnew.F_Cu) else pcbnew.B_Cu
                bb = p.GetBoundingBox()
                self.items.append(Item(p.GetNetname(), xy(p.GetPosition()), mm(max(bb.GetWidth(), bb.GetHeight())) / 2,
                                       p.GetEffectivePolygon(layer, pcbnew.ERROR_INSIDE), mm(p.GetDrillSize().x) / 2,
                                       p.IsOnLayer(pcbnew.F_Cu), p.IsOnLayer(pcbnew.B_Cu), True))
        for t in board.GetTracks():         # the stubs, vias and tracks of the passes before
            if t.GetClass() == "PCB_VIA":
                self.via_item(t.GetNetname(), xy(t.GetPosition()), mm(t.GetWidth(pcbnew.F_Cu)), mm(t.GetDrillValue()))
            else:
                self.track_item(t.GetNetname(), xy(t.GetStart()), xy(t.GetEnd()), mm(t.GetWidth()), t.GetLayer())

    def via_item(self, net, v, d, drill):
        self.items.append(Item(net, v, d / 2, polygon(pcbnew.SHAPE_CIRCLE(vec(v), MM(d / 2))), drill / 2, True, True, False))

    def track_item(self, net, a, b, width, layer):
        self.items.append(Item(net, ((a[0] + b[0]) / 2, (a[1] + b[1]) / 2), math.dist(a, b) / 2 + width,
                               polygon(pcbnew.SHAPE_SEGMENT(vec(a), vec(b), MM(width))), 0.0,
                               layer == pcbnew.F_Cu, layer == pcbnew.B_Cu, False))

    def near(self, a, b, margin):
        return [o for o in self.items if seg_dist(o.centre, a, b) < o.reach + margin]

    def in_plane(self, net, v, r):
        ring = [vec((v[0] + (r + PLANE_INSET) * math.cos(a), v[1] + (r + PLANE_INSET) * math.sin(a)))
                for a in (k * math.pi / 4 for k in range(8))]
        return any(all(o.Contains(q) for q in ring) for o in self.plane.get(net, []))

    def via_ok(self, net, v, r, near):
        """A via of radius r at v clear of the board edge, the C-LOCK, the copper of the other nets on every
        layer, every hole and every pad."""
        if not (FANOUT_EDGE + r <= v[0] <= W - FANOUT_EDGE - r and FANOUT_EDGE + r <= v[1] <= H - FANOUT_EDGE - r):
            return False
        if math.dist(v, pcb.CLOCK) < pcb.CLOCK_KEEP + r:
            return False
        via = pcbnew.SHAPE_CIRCLE(vec(v), MM(r))
        for o in near:
            # copper to hole, which also keeps the holes apart (the via is wider than its hole)
            if o.drill and math.dist(v, o.centre) < o.drill + r + HOLE_GAP:
                return False
            if o.net == net:
                if o.pad and o.shape.Collide(via, MM(0.1)):
                    return False    # no via in a pad: the solder would flow down it
                continue
            if o.drill and not o.pad and math.dist(v, o.centre) < VIA_PITCH:
                return False        # the planes would not reach it, or the other one
            if o.shape.Collide(via, MM(self.gap(net, o.net))):
                return False
        return True

    def track_ok(self, net, a, b, width, near, top):
        """A track from a to b on layer 1 (top) or 4, clear of the copper of the other nets on that layer and
        of the holes of the other nets."""
        for p in (a, b):
            if not (FANOUT_EDGE <= p[0] <= W - FANOUT_EDGE and FANOUT_EDGE <= p[1] <= H - FANOUT_EDGE):
                return False
        if seg_dist(pcb.CLOCK, a, b) < pcb.CLOCK_KEEP + width / 2:
            return False
        seg = pcbnew.SHAPE_SEGMENT(vec(a), vec(b), MM(width))
        for o in near:
            if o.net == net:
                continue
            if o.drill and seg_dist(o.centre, a, b) < o.drill + width / 2 + HOLE_GAP:
                return False
            if (o.top if top else o.bottom) and o.shape.Collide(seg, MM(self.gap(net, o.net))):
                return False
        return True

    def add_track(self, net, a, b, width, layer):
        t = pcbnew.PCB_TRACK(self.board)
        t.SetStart(vec(a))
        t.SetEnd(vec(b))
        t.SetWidth(MM(width))
        t.SetLayer(layer)
        t.SetNet(self.board.FindNet(net))
        t.SetLocked(True)
        self.board.Add(t)
        self.track_item(net, a, b, width, layer)

    def add_via(self, net, v, d, drill):
        via = pcbnew.PCB_VIA(self.board)
        via.SetPosition(vec(v))
        via.SetWidth(MM(d))
        via.SetDrill(MM(drill))
        via.SetNet(self.board.FindNet(net))
        via.SetLocked(True)
        self.board.Add(via)
        self.via_item(net, v, d, drill)


def fanout(cu, nets):
    """A stub on layer 1 and a via of its own for every surface pad of `nets`: the shortest of 16
    directions, outward from the part when it costs nothing, the via inside the plane of its net when the
    pad lies over it. Returns the pads left without a via, and the vias off their plane."""
    todo = []
    for fp in sorted(cu.board.GetFootprints(), key=lambda f: pcb.rank(f.GetReference())):
        through = [q for q in fp.Pads() if q.GetDrillSize().x and q.GetNetname() in nets]
        for p in fp.Pads():
            if p.GetNetname() not in nets or p.GetAttribute() not in SURFACE or not p.IsOnLayer(pcbnew.F_Cu):
                continue
            poly = p.GetEffectivePolygon(pcbnew.F_Cu, pcbnew.ERROR_INSIDE)
            if any(poly.Contains(q.GetPosition()) for q in through):
                continue            # exposed pad with its own thermal vias
            todo.append((fp, p))
    left, off = [], []
    for fp, p in todo:
        net = p.GetNetname()
        width, _, via_d, via_drill = project.CLASSES[project.class_of(net)]
        r = via_d / 2
        c = xy(p.GetPosition())
        out = (c[0] - mm(fp.GetPosition().x), c[1] - mm(fp.GetPosition().y))
        n = math.hypot(*out) or 1.0
        near = cu.near(c, c, FANOUT_REACH + 1.0)
        best = None
        for planed in (True, False):
            for k in range(16):
                a = 2 * math.pi * k / 16
                u = (math.cos(a), math.sin(a))
                for step in range(4, int(FANOUT_REACH / 0.05) + 1):
                    d = step * 0.05
                    v = (c[0] + d * u[0], c[1] + d * u[1])
                    if ((not planed or cu.in_plane(net, v, r)) and cu.via_ok(net, v, r, near)
                            and cu.track_ok(net, c, v, width, near, True)):
                        cost = d - 0.3 * (u[0] * out[0] + u[1] * out[1]) / n
                        if best is None or cost < best[0]:
                            best = (cost, v)
                        break
            if best:
                break
        if best is None:
            left.append(f"{fp.GetReference()}.{p.GetNumber()} [{net}]")
            continue
        v = best[1]
        cu.add_track(net, c, v, width, pcbnew.F_Cu)
        cu.add_via(net, v, via_d, via_drill)
        if not planed:
            off.append((net, f"{fp.GetReference()}.{p.GetNumber()}", v))
    return left, off


def link(cu, net, off):
    """Tracks on layer 4 from each via off its plane to a via of the net in the plane, an existing one or a
    new one, in an L or straight; the vias linked serve the next ones. Returns the vias left unlinked."""
    width, _, via_d, via_drill = project.CLASSES[project.class_of(net)]
    r = via_d / 2
    targets = [o.centre for o in cu.items if o.net == net and o.drill and not o.pad and cu.in_plane(net, o.centre, o.reach)]

    def paths(a, b):
        # horizontal and vertical first: a diagonal across layer 4 would block its signals
        return ([a, (a[0], b[1]), b], [a, (b[0], a[1]), b], [a, b])

    def path_ok(path):
        return all(cu.track_ok(net, p, q, width, cu.near(p, q, width + 1.0), False) for p, q in zip(path, path[1:]))

    def length(path):
        return sum(math.dist(p, q) for p, q in zip(path, path[1:]))

    def lay(path):
        for p, q in zip(path, path[1:]):
            if math.dist(p, q) > 1e-3:
                cu.add_track(net, p, q, width, pcbnew.B_Cu)

    todo, progress = list(off), True
    while todo and progress:
        progress = False
        todo.sort(key=lambda s: min((math.dist(s[1], t) for t in targets), default=math.inf))
        for name, a in list(todo):
            best = None             # (track length, path, new via or None)
            for t in sorted(targets, key=lambda t: math.dist(a, t))[:LINK_TRIES]:
                if math.dist(a, t) > LINK_REACH:
                    break
                p = next((p for p in paths(a, t) if path_ok(p)), None)
                if p:
                    best = (length(p), p, None)
                    break
            # a new via in the plane, the nearest reachable, when it makes the track shorter
            for ox, oy in LINK_SPOTS:
                if math.hypot(ox, oy) + NEW_VIA_COST >= (best[0] if best else LINK_REACH):
                    break
                b = (a[0] + ox, a[1] + oy)
                if not cu.in_plane(net, b, r) or not cu.via_ok(net, b, r, cu.near(b, b, r + 1.0)):
                    continue
                p = next((p for p in paths(a, b) if path_ok(p)), None)
                if p and length(p) + NEW_VIA_COST < (best[0] if best else math.inf):
                    best = (length(p) + NEW_VIA_COST, p, b)
                    break
            if best:
                if best[2]:
                    cu.add_via(net, best[2], via_d, via_drill)
                    targets.append(best[2])
                lay(best[1])
                targets.append(a)
                todo.remove((name, a))
                progress = True
    return [name for name, _ in todo]


def polygon(shape):
    p = pcbnew.SHAPE_POLY_SET()
    shape.TransformToPolygon(p, MM(0.005), pcbnew.ERROR_INSIDE)
    return p


def seg_dist(p, a, b):
    """Distance from the point p to the segment ab."""
    dx, dy = b[0] - a[0], b[1] - a[1]
    k = ((p[0] - a[0]) * dx + (p[1] - a[1]) * dy) / ((dx * dx + dy * dy) or 1.0)
    k = min(max(k, 0.0), 1.0)
    return math.dist(p, (a[0] + k * dx, a[1] + k * dy))


def vec(p):
    return pcbnew.VECTOR2I(MM(p[0]), MM(p[1]))


def xy(v):
    return mm(v.x), mm(v.y)


def stage(name):
    return os.path.join(pcb.STAGES, f"{PASSES.index(name)}-{name}.kicad_pcb")


def start(name):
    """The working board, back to the stage before the pass `name`."""
    before = stage(PASSES[PASSES.index(name) - 1])
    if not os.path.exists(before):
        raise SystemExit(f"{before} missing: run the pass before {name} first")
    shutil.copyfile(before, PCB)
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    return board


def fanout_pass(board, name, nets):
    """Fanout of `nets`, then the vias off their plane linked on layer 4."""
    cu = Copper(board)
    left, off = fanout(cu, nets)
    unlinked = [s for net in sorted(nets) for s in link(cu, net, [(n, v) for m, n, v in off if m == net])]
    print(f"{name} pass: {len(left)} pad(s) without a via, {len(off)} via(s) off the plane linked on layer 4, "
          f"{len(unlinked)} left unlinked", flush=True)
    for s in left + unlinked:
        print("  ", s)
    project.save(board, PCB)



def gnd():
    board = start("gnd")
    for layer in (pcbnew.In1_Cu, pcbnew.In2_Cu):
        board.SetLayerType(layer, pcbnew.LT_POWER)     # planes: Freerouting connects to them, never routes on them
    planes(board)
    fanout_pass(board, "gnd", {"GND", "GNDISO"})


def rail(name):
    fanout_pass(start(name), name, {RAILS[name]})


def power(passes):
    board = start("power")
    stand_ins = chassis_stand_ins(board)
    keep = {str(n) for n in board.GetNetsByName().keys() if project.class_of(str(n)) != "Default"}
    print(f"power pass: {len(keep)} nets", flush=True)
    freerouting(board, keep, passes)
    for t in list(board.GetTracks()):
        if t.m_Uuid.AsString() in stand_ins:
            board.Remove(t)
    project.save(board, PCB)


def report(rpt):
    """Violations by type, unrouted connections of the power nets, and supply planes cut into islands."""
    import collections
    import json
    d = json.load(open(rpt, encoding="utf-8"))
    nets = collections.Counter(re.sub(r"^.*\[(.*?)\].*$", r"\1", u["items"][0]["description"])
                               for u in d["unconnected_items"])
    print(f"violations: {len(d['violations'])}, unconnected: {len(d['unconnected_items'])}, "
          f"parity: {len(d['schematic_parity'])}")
    print("   by type:", ", ".join(f"{t} {k}" for t, k in collections.Counter(v["type"] for v in d["violations"]).most_common()))
    print("   power nets unrouted:", ", ".join(f"{n} {k}" for n, k in nets.most_common() if project.class_of(n) != "Default"))
    for v in d["violations"]:
        if not v["type"].startswith("silk"):
            print("  ", v["type"], " / ".join(i["description"][:60] for i in v["items"]))
    board = pcbnew.LoadBoard(PCB)
    for z in board.Zones():
        if z.GetIsRuleArea():
            continue
        for layer in z.GetLayerSet().Seq():
            n = z.GetFilledPolysList(layer).OutlineCount() if z.HasFilledPolysForLayer(layer) else 0
            print(f"   zone {z.GetZoneName():16} {board.GetLayerName(layer):6} {n} island(s)")


def main():
    step = sys.argv[1] if len(sys.argv) > 1 else "gnd"
    if step == "report":
        return report(refill())
    if step == "back":
        shutil.copyfile(stage(sys.argv[2]), PCB)
        return print(f"{PCB} <- {stage(sys.argv[2])}")
    if step == "gnd":
        gnd()
    elif step in RAILS:
        rail(step)
    elif step == "power":
        power(int(sys.argv[2]) if len(sys.argv) > 2 else 4)
    else:
        raise SystemExit(f"unknown pass: {step}")
    # a second LoadBoard fails in a process that has removed items: report from a fresh one
    subprocess.run([sys.executable, os.path.abspath(__file__), "report"], check=True)
    shutil.copyfile(PCB, stage(step))     # zones filled by the report


if __name__ == "__main__":
    main()
