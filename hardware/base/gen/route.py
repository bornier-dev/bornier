# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Base board routing, in passes: power first, then fast signals, then slow signals.

Run with the Python shipped with KiCad, after pcb.py:
    "C:/Program Files/KiCad/10.0/bin/python.exe" route.py <pass>      gnd, rails, power [Freerouting passes]
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
to layer 2. Pass "rails": the same for +3V3, +5V and +VIN down to their plane of layer 3, where the pad
lies over it. Pass "power": Freerouting on the supply, ground and chassis nets left.
"""
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
W, H, EDGE = pcb.W, pcb.H, pcb.END_KEEP

# Layer 3 supply planes, (x0, y0, x1, y1): 0.5 mm between planes of different nets.
SUPPLY_PLANES = {
    "+5V": [(EDGE, 14.0, W - EDGE, 47.0), (88.5, 47.0, W - EDGE, 58.0)],
    "+3V3": [(EDGE, 47.5, 88.0, H - EDGE), (88.0, 58.5, 104.0, H - EDGE)],
    "+VIN": [(104.5, 58.5, W - EDGE, H - EDGE)],
}
CHASSIS_BAND = 3.0          # layer 4, along the edges: the part-free rim where the board rests on the profile
ISO_MARGIN = 1.0            # around the bus side of the Modbus port: the isolation barrier
POWER_CLASSES = {"Input", "Rail", "Buck", "Limited", "Ground", "Chassis"}
# Passes, in order: each starts from the stage written by the one before (pcb.py writes "placed")
PASSES = ["placed", "gnd", "rails", "power"]
SURFACE = (pcbnew.PAD_ATTRIB_SMD, pcbnew.PAD_ATTRIB_CONN)   # surface pads, with or without paste
PLANE_INSET = 0.3           # a via stays this far inside the outline of its plane
FANOUT_REACH = 2.5          # longest stub from a pad centre to its via
FANOUT_EDGE = CHASSIS_BAND + 1.0    # vias stay off the chassis band and its clearance
HOLE_GAP = 0.25             # copper to hole and hole to hole, JLCPCB


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


def fanout(board, nets):
    """A stub on layer 1 and a via of its own for every SMD pad of `nets`, down to the plane of layer 2 or
    3: the shortest of 16 directions, outward from the part when it costs nothing. Returns the pads left
    without one."""
    T = pcbnew.ToMM
    fps = list(board.GetFootprints())
    gap = gap_of(set(pcb.iso_nets({fp.GetReference(): fp for fp in fps})))
    plane = {}                      # net: outlines of its zones on layers 2 and 3
    for z in board.Zones():
        if not z.GetIsRuleArea() and z.GetLayer() in (pcbnew.In1_Cu, pcbnew.In2_Cu):
            plane.setdefault(z.GetNetname(), []).append(z.Outline())
    copper = []                     # (net, centre, reach, shape, hole radius, on layer 1, pad)
    for fp in fps:
        for p in fp.Pads():
            layer = pcbnew.F_Cu if p.IsOnLayer(pcbnew.F_Cu) else pcbnew.B_Cu
            bb = p.GetBoundingBox()
            copper.append((p.GetNetname(), (T(p.GetPosition().x), T(p.GetPosition().y)),
                           T(max(bb.GetWidth(), bb.GetHeight())) / 2, p.GetEffectivePolygon(layer, pcbnew.ERROR_INSIDE),
                           T(p.GetDrillSize().x) / 2, layer == pcbnew.F_Cu, True))
    todo = []
    for fp in sorted(fps, key=lambda f: pcb.rank(f.GetReference())):
        through = [q for q in fp.Pads() if q.GetDrillSize().x and q.GetNetname() in nets]
        for p in fp.Pads():
            if p.GetNetname() not in nets or p.GetAttribute() not in SURFACE or not p.IsOnLayer(pcbnew.F_Cu):
                continue
            poly = p.GetEffectivePolygon(pcbnew.F_Cu, pcbnew.ERROR_INSIDE)
            if any(poly.Contains(q.GetPosition()) for q in through):
                continue            # exposed pad with its own thermal vias
            todo.append((fp, p, poly))
    left = []
    for fp, p, poly in todo:
        net = p.GetNetname()
        width, _, via_d, via_drill = project.CLASSES[project.class_of(net)]
        r = via_d / 2
        c = (T(p.GetPosition().x), T(p.GetPosition().y))
        out = (c[0] - T(fp.GetPosition().x), c[1] - T(fp.GetPosition().y))
        n = math.hypot(*out) or 1.0
        near = [o for o in copper if math.dist(o[1], c) < o[2] + FANOUT_REACH + 1.0]
        best = None
        for k in range(16):
            a = 2 * math.pi * k / 16
            u = (math.cos(a), math.sin(a))
            for step in range(4, int(FANOUT_REACH / 0.05) + 1):
                d = step * 0.05
                v = (c[0] + d * u[0], c[1] + d * u[1])
                if fanout_ok(net, c, v, r, width, near, gap, plane.get(net, [])):
                    cost = d - 0.3 * (u[0] * out[0] + u[1] * out[1]) / n
                    if best is None or cost < best[0]:
                        best = (cost, v)
                    break
        if best is None:
            left.append(f"{fp.GetReference()}.{p.GetNumber()} [{net}]")
            continue
        v = best[1]
        t = pcbnew.PCB_TRACK(board)
        t.SetStart(p.GetPosition())
        t.SetEnd(vec(v))
        t.SetWidth(MM(width))
        t.SetLayer(pcbnew.F_Cu)
        t.SetNet(p.GetNet())
        t.SetLocked(True)
        board.Add(t)
        via = pcbnew.PCB_VIA(board)
        via.SetPosition(vec(v))
        via.SetWidth(MM(via_d))
        via.SetDrill(MM(via_drill))
        via.SetNet(p.GetNet())
        via.SetLocked(True)
        board.Add(via)
        copper.append((net, v, r, polygon(pcbnew.SHAPE_CIRCLE(vec(v), MM(r))), via_drill / 2, True, False))
        copper.append((net, ((c[0] + v[0]) / 2, (c[1] + v[1]) / 2), math.dist(c, v) / 2 + width,
                       polygon(pcbnew.SHAPE_SEGMENT(vec(c), vec(v), MM(width))), 0.0, True, False))
    return left


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


def fanout_ok(net, c, v, r, width, near, gap, outlines):
    """A via of radius r at v, with its stub from the pad centre c, inside a plane of its net, clear of the
    board edge, the C-LOCK, the copper of the other nets, and every hole."""
    ring = [vec((v[0] + (r + PLANE_INSET) * math.cos(a), v[1] + (r + PLANE_INSET) * math.sin(a)))
            for a in (k * math.pi / 4 for k in range(8))]
    if not any(all(o.Contains(q) for q in ring) for o in outlines):
        return False
    if not (FANOUT_EDGE + r <= v[0] <= W - FANOUT_EDGE - r and FANOUT_EDGE + r <= v[1] <= H - FANOUT_EDGE - r):
        return False
    if math.dist(v, pcb.CLOCK) < pcb.CLOCK_KEEP + r:
        return False
    via = pcbnew.SHAPE_CIRCLE(vec(v), MM(r))
    stub = pcbnew.SHAPE_SEGMENT(vec(c), vec(v), MM(width))
    for other, centre, reach, shape, drill, top, pad in near:
        # copper to hole, which also keeps the holes apart (the via is wider than its hole)
        if drill and (math.dist(v, centre) < drill + r + HOLE_GAP
                      or seg_dist(centre, c, v) < drill + width / 2 + HOLE_GAP):
            return False
        if other == net:
            if pad and shape.Collide(via, MM(0.1)):
                return False        # no via in a pad: the solder would flow down it
            continue
        g = MM(gap(net, other))
        if shape.Collide(via, g) or (top and shape.Collide(stub, g)):
            return False
    return True


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
    left = fanout(board, nets)
    print(f"{name} pass: {len(left)} pad(s) without a via", flush=True)
    for s in left:
        print("  ", s)
    project.save(board, PCB)


def gnd():
    board = start("gnd")
    for layer in (pcbnew.In1_Cu, pcbnew.In2_Cu):
        board.SetLayerType(layer, pcbnew.LT_POWER)     # planes: Freerouting connects to them, never routes on them
    planes(board)
    fanout_pass(board, "gnd", {"GND", "GNDISO"})


def rails():
    fanout_pass(start("rails"), "rails", set(SUPPLY_PLANES))


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
    elif step == "rails":
        rails()
    elif step == "power":
        power(int(sys.argv[2]) if len(sys.argv) > 2 else 4)
    else:
        raise SystemExit(f"unknown pass: {step}")
    # a second LoadBoard fails in a process that has removed items: report from a fresh one
    subprocess.run([sys.executable, os.path.abspath(__file__), "report"], check=True)
    shutil.copyfile(PCB, stage(step))     # zones filled by the report


if __name__ == "__main__":
    main()
