# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Base board routing, in passes: power first, then fast signals, then slow signals.

Run with the Python shipped with KiCad, after pcb.py:
    "C:/Program Files/KiCad/10.0/bin/python.exe" route.py power [passes]
Works on ../kicad/base.kicad_pcb. Freerouting 2.4.1 (https://github.com/freerouting/freerouting/releases)
is not in the repository: FREEROUTING_JAR, or hardware/tools/freerouting-2.4.1.jar; Java 21.

Stack-up (JLC04161H-7628, 1.6 mm): L1 parts and signals, L2 ground plane (one island of GNDISO under
the Modbus port), L3 supply planes (+5V under the axes, +3V3 under the MCU, ESC and bus, +VIN at the
power entry), L4 signals and a chassis band along the edges.

Pass "power": planes, then Freerouting on the supply, ground and chassis nets only, connecting every
pad to its plane or rail. Each later pass starts from the result of the previous one.
"""
import os
import re
import subprocess
import sys

import pcbnew

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import pcb  # noqa: E402
import project  # noqa: E402
from kicadgen.kicad import cli  # noqa: E402

PCB = os.path.join(pcb.KICAD, "base.kicad_pcb")
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
POWER_CLASSES = {"Input", "Rail", "Limited", "Ground", "Chassis"}


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
    z.SetOutline(poly)
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
    """Ground on layer 2, supplies on layer 3, chassis band on layer 4; returns the locked tracks that
    stand for the chassis band while Freerouting runs (it does not see zones on signal layers)."""
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
    r = subprocess.run(["java", "-Xmx1g", "-XX:+UseSerialGC", "-jar", JAR, "-de", dsn, "-do", ses, "-mp", str(passes),
                        "--gui.enabled=false"], capture_output=True, text=True, timeout=3600, creationflags=flags)
    print("\n".join((r.stdout + r.stderr).strip().splitlines()[-6:]), flush=True)
    if not os.path.exists(ses) or not pcbnew.ImportSpecctraSES(board, ses):
        raise SystemExit("Freerouting gave no result")


def refill():
    """Zone fill by kicad-cli: it loads the project, so the net classes and the custom rules."""
    rpt = PCB.replace(".kicad_pcb", "-drc.json")
    subprocess.run([cli(), "pcb", "drc", "--refill-zones", "--save-board", "--schematic-parity", "--severity-all",
                    "--format", "json", "-o", rpt, PCB], capture_output=True)
    return rpt


def power(passes):
    board = pcbnew.LoadBoard(PCB)
    for t in list(board.GetTracks()):
        board.Remove(t)
    for z in list(board.Zones()):
        if not z.GetIsRuleArea():
            board.Remove(z)
    project.apply_netclasses(board)
    for layer in (pcbnew.In1_Cu, pcbnew.In2_Cu):
        board.SetLayerType(layer, pcbnew.LT_POWER)     # planes: Freerouting connects to them, never routes on them
    stand_ins = planes(board)
    keep = {str(n) for n in board.GetNetsByName().keys() if project.class_of(str(n)) != "Default"}
    print(f"power pass: {len(keep)} nets", flush=True)
    freerouting(board, keep, passes)
    for t in list(board.GetTracks()):
        if t.m_Uuid.AsString() in stand_ins:
            board.Remove(t)
    project.save(board, PCB)


def report(rpt):
    """Unrouted connections of the power nets, and supply planes cut into islands."""
    import json
    d = json.load(open(rpt, encoding="utf-8"))
    left = [u for u in d["unconnected_items"]
            if project.class_of(re.sub(r"^.*\[(.*?)\].*$", r"\1", u["items"][0]["description"])) != "Default"]
    print(f"violations: {len(d['violations'])}, unconnected: {len(d['unconnected_items'])} "
          f"(power: {len(left)}), parity: {len(d['schematic_parity'])}")
    for u in left[:30]:
        print("  ", " / ".join(i["description"][:60] for i in u["items"]))
    board = pcbnew.LoadBoard(PCB)
    for z in board.Zones():
        if z.GetIsRuleArea():
            continue
        for layer in z.GetLayerSet().Seq():
            n = z.GetFilledPolysList(layer).OutlineCount() if z.HasFilledPolysForLayer(layer) else 0
            print(f"   zone {z.GetZoneName():16} {board.GetLayerName(layer):6} {n} island(s)")


def main():
    step = sys.argv[1] if len(sys.argv) > 1 else "power"
    passes = int(sys.argv[2]) if len(sys.argv) > 2 else 20
    if step != "power":
        raise SystemExit(f"unknown pass: {step}")
    power(passes)
    report(refill())


if __name__ == "__main__":
    main()
