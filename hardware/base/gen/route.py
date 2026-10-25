# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Base board routing, in passes: planes and trunks, differential pairs, supplies, short links, fast signals,
then the rest.

Run with the Python shipped with KiCad, after pcb.py:
    "C:/Program Files/KiCad/10.0/bin/python.exe" route.py <pass> [Freerouting passes]      the passes of PASSES
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

Pass "trunk": the planes, and the wide tracks of TRUNKS. Pass "pairs": the differential pairs (pairs.py).
Pass "gnd": a stub and a via of its own from every surface pad of GND and GNDISO down to layer 2. Passes
"vin", "5v", "3v3", "phy": the same for each supply, one at a time, down to its plane of layer 3, the pads off
their plane linked on layer 4 up to RAIL_LINK_MAX, the farther ones left to the signals pass. Pass "short": pads
up to SHORT_MAX apart joined on layer 1. Passes "fast" and "signals": Freerouting on the clock and OCTOSPI, then
on every net left but the ground and the chassis.
"""
import collections
import glob
import hashlib
import json
import math
import os
import re
import shutil
import subprocess
import sys
import tempfile

import pcbnew

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import pcb  # noqa: E402
import planes as planes_mod  # noqa: E402
import project  # noqa: E402
from kicadgen.kicad import cli  # noqa: E402

PCB = os.path.join(pcb.KICAD, "base.kicad_pcb")
JAVA = os.environ.get("JAVA") or next(iter(sorted(glob.glob("C:/Program Files/Eclipse Adoptium/jre-2[5-9]*/bin/java.exe"))), "java")
JAR = os.environ.get("FREEROUTING_JAR") or os.path.join(HERE, "..", "..", "tools", "freerouting-2.4.1.jar")
MM = pcbnew.FromMM
mm = pcbnew.ToMM
W, H, EDGE = pcb.W, pcb.H, pcb.END_KEEP

# Layer 3 supply planes: drawn from the placement (planes.py), each in one piece from its regulator
SUPPLY_NETS = planes_mod.SUPPLIES
CHASSIS_BAND = 3.0          # layer 4, along the edges: the part-free rim where the board rests on the profile
ISO_MARGIN = 1.0            # around the bus side of the Modbus port: the isolation barrier
POWER_CLASSES = {"Input", "Rail", "Buck", "Limited", "Ground", "Chassis"}
# Passes, in order: each starts from the stage written by the one before (pcb.py writes "placed")
RAILS = {"3v3": "+3V3", "5v": "+5V", "vin": "+VIN"}
# The supplies that carry current first: the thin links of the later ones route around their tracks
PASSES = ["placed", "trunk", "pairs", "gnd", "vin", "5v", "3v3", "phy", "short", "fast", "signals", "chassis", "complete", "islands"]
SURFACE = (pcbnew.PAD_ATTRIB_SMD, pcbnew.PAD_ATTRIB_CONN)   # surface pads, with or without paste
# Mini-planes of the PHY supplies (LAN9253 checklist): net: the PHY; on layer 3, under the pads of the net on
# the jack side of the PHY, cut into the +3V3 plane
PHY_ISLANDS = {"/ESC/VDD33TXRX1": "U4", "/ESC/VDD33TXRX2": "U4"}
ISLAND_GROW = 2.0          # the PHY islands reach this far past their pads: their thermal spokes find copper
ISLAND_NECK = 2.5          # the corridor of a PHY island to its ferrite on the far side of the PHY (planes.FINGER)
ZONE_GAP = 0.5              # zone to zone clearance (the KiCad default zone clearance is 0.508)
PLANE_GAP = 0.2             # plane to the copper of the other nets (a hole keeps HOLE_GAP to it all the same)
PLANE_INSET = 0.3           # a via stays this far inside the outline of its plane
FANOUT_REACH = 2.5          # longest stub from a pad centre to its via
FANOUT_EDGE = CHASSIS_BAND + 1.0    # vias stay off the chassis band and its clearance
SIGNAL_VIA = f"Via[0-3]_{round(project.VIA[0] * 1000)}:{round(project.VIA[1] * 1000)}_um"   # its DSN padstack
VIA_GROW = 100             # um added to the vias in the DSN (Freerouting keeps no hole clearance)
# Freerouting runs side by side, one per set of costs (its defaults: via 50, first rip-up 100, trace off its
# preferred direction 2.5): one core and 1 GB each
VARIANTS = [{}, {"via_costs": 25}, {"via_costs": 100}, {"start_ripup_costs": 50}, {"start_ripup_costs": 200},
            {"default_undesired_direction_trace_cost": 1.5}, {"default_undesired_direction_trace_cost": 4.0},
            {"via_costs": 25, "start_ripup_costs": 50}]
HOLE_GAP = 0.2              # copper to a via hole and hole to hole, JLCPCB
LEAD_GAP = 0.28             # copper to the hole of a through-hole lead, JLCPCB
LINK_REACH = 40.0          # longest layer 4 link from a via off its plane
# longest layer 4 link of a supply pass: a longer one, laid straight before the signals, walls them off (the
# +5V of the laser buffer U37 ran 35 mm across the MCU); its via is left to Freerouting with the signals.
# Shorter ones stay: at 5 mm, Freerouting failed to finish a few of them (the input of U10, the +3V3 of the
# encoder receivers)
RAIL_LINK_MAX = 12.0
# A bridge between two pieces of a supply plane that layer 3 cannot join (planes.py), mm: track, via, drill.
# IPC-2221, outer layer 1 oz, 10 degC rise: 0.6 mm carries 1.6 A
BRIDGE = (0.6, 0.6, 0.3)
# The nets each pass must leave whole (DRC: no unconnected item): the chain stops otherwise
WHOLE = {"gnd": {"GND", "GNDISO"}, "vin": {"+VIN"}, "5v": {"+5V"}, "3v3": {"+3V3"}, "phy": set(PHY_ISLANDS)}
# Supplies whose links left to Freerouting carry little current, routed thinner than their class, mm. +5V:
# the laser buffer U37 and the feedback divider R4, under 10 mA (0.15 mm: above 0.45 A); at 0.25 mm the
# 35 mm link of U37 found no way
THIN = {"+5V": 0.15}
# The same in the pass complete, once the main paths are routed at the width of their class: V3IN, the
# cathode of D4 (the +5V into the 3.3 V buck, 0.75 A at most) to the input of U3, which the inductor and
# the feedback divider close in at 0.4 mm (0.3 mm: 1 A)
COMPLETE_THIN = {"/Power/V3IN": 0.3}
LINK_TRIES = 30            # vias of the plane tried per link, nearest first
LINK_SPOTS = pcb.spiral(0.5, LINK_REACH)     # offsets for a new via in the plane, nearest first
PAIRS = pcb.ETH_LINE + r"|USB_D[PM]"     # differential pairs: routed as pairs, left out of the short pass
# Pass "fast": the 25 MHz clock and the OCTOSPI between the ESC and the MCU, on both sides of their resistors
FAST = r"(/Clock/)?CLK25(_ESC|_MCU)?|ESC_S(CK|CS|IO[0-3])|Net-\(U9-P(B2|B10|B1|B0|A7|A6)\)"
SHORT_MAX = 3.0            # pass short: pads this close, centre to centre, joined on layer 1 without a via
ESCAPE_PAD = 0.5           # pass complete: IC pads narrower than this get a way out (fine pitch)
ESCAPE_GROW = 1.0          # the way out of such an IC: its outline grown by this, kept clear of long links
ESCAPE_STUB = 0.8          # a link may still reach a via that far into it
MAZE_GRID = 0.2            # a long link with no L way: A* grid, mm
MAZE_REACH = 20.0          # and search area, from the via linked
# pass complete: signal copper this close to an end of a missing connection ripped up; 0: none. At 3 mm it
# took 94 to 131 nets around the MCU, which Freerouting did not all route again (21 connections missing
# became 43, then 183)
RIP_REACH = 0.0
RIPPED = PCB.replace(".kicad_pcb", "-ripped.json")
COPPER_EDGE = 0.2          # layer 1 copper to a routed board edge, JLCPCB (the chassis band keeps layer 4 farther)
# Through-hole pads off their plane that carry current: (track width, via diameter, via drill), mm.
# +VIN to the supply jumpers of the four encoders: 4 x 0.6 A at most; 1 mm outer copper, 2.4 A at 10 degC
# rise (IPC-2221), into the plane by two 0.8/0.4 mm vias.
TRUNKS = {"+VIN": (1.0, 0.8, 0.4)}
TRUNK_Y = (11.5, 16.0)     # layer 4 corridor of the trunks, the first clear line: under the jack leads, above the axes
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
    # 0.2 mm to the copper of the other nets, not the 0.508 of KiCad: vias at a 1 mm pitch leave a 0.2 mm web
    # of plane between them instead of a wall that cuts pockets off the plane
    z.SetLocalClearance(MM(PLANE_GAP))
    z.SetMinThickness(MM(0.15))
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
    supply = supply_planes(board)[0]
    for net, p in supply.items():
        # a zone per piece: KiCad saves one outline of a zone (pieces joined by a bridge, planes.py)
        for i in range(p.OutlineCount()):
            piece = pcbnew.SHAPE_POLY_SET()
            piece.AddOutline(p.Outline(i))
            for h in range(p.HoleCount(i)):
                piece.AddHole(p.Hole(i, h))
            add_zone(board, net, pcbnew.In2_Cu, piece, 0, f"{net} plane" + (f" {i + 1}" if i else ""))
    band = rect_poly(0, 0, W, H)
    band.BooleanSubtract(rect_poly(CHASSIS_BAND, CHASSIS_BAND, W - CHASSIS_BAND, H - CHASSIS_BAND))
    # the shields joined solid: their leads are on the rim of the band, where thermal spokes find no room
    add_zone(board, "CHASSIS", pcbnew.B_Cu, band, 0, "chassis band").SetPadConnection(pcbnew.ZONE_CONNECTION_FULL)
    for k, (net, rim, necks) in enumerate(phy_islands(board)):
        poly = pcbnew.SHAPE_POLY_SET()
        poly.NewOutline()
        for x, y in rim:
            poly.Append(MM(x), MM(y))
        for a, b in necks:
            poly.BooleanAdd(polygon(pcbnew.SHAPE_SEGMENT(vec(a), vec(b), MM(ISLAND_NECK))))
        add_zone(board, net, pcbnew.In2_Cu, poly, k + 1, f"{net.split('/')[-1]} island")


def phy_islands(board, margin=0.0):
    """[(net, hull, necks)] of PHY_ISLANDS: the hull of the pads of the net on the jack side of the PHY, grown
    by ISLAND_GROW + margin; the necks (a, b), ISLAND_NECK wide, join it to its source, the ferrite, on the far
    side of the PHY: a track from there would wall the way out of its pins on layer 4. A later island takes
    the overlap (higher priority)."""
    fps = {fp.GetReference(): fp for fp in board.GetFootprints()}
    out = []
    for net, phy in PHY_ISLANDS.items():
        cy = mm(fps[phy].GetPosition().y)
        pts = [xy(p.GetPosition()) for fp in fps.values() for p in fp.Pads() if p.GetNetname() == net]
        g = ISLAND_GROW + margin
        rim = hull([(x + g * math.cos(a), y + g * math.sin(a))
                    for x, y in pts if y > cy for a in (i * math.pi / 8 for i in range(16))])
        necks = []
        for fp in fps.values():
            for p in fp.Pads():
                if fp.GetReference().startswith("FB") and p.GetNetname() == net and xy(p.GetPosition())[1] <= cy:
                    a = xy(p.GetPosition())
                    necks.append((a, min(rim, key=lambda q: math.dist(a, q))))
        out.append((net, rim, necks))
    return out


def island_keep_out(board):
    """The PHY islands and their necks as polygons, grown by ZONE_GAP: the supply planes keep off them."""
    out = []
    for _, rim, necks in phy_islands(board, ZONE_GAP):
        out.append(rim)
        h = ISLAND_NECK / 2 + ZONE_GAP
        for a, b in necks:
            d = math.dist(a, b) or 1.0
            ux, uy = (b[0] - a[0]) / d, (b[1] - a[1]) / d
            a, b = (a[0] - ux * h, a[1] - uy * h), (b[0] + ux * h, b[1] + uy * h)
            out.append([(a[0] - uy * h, a[1] + ux * h), (b[0] - uy * h, b[1] + ux * h),
                        (b[0] + uy * h, b[1] - ux * h), (a[0] + uy * h, a[1] - ux * h)])
    return out


def supply_planes(board, strict=True):
    """planes.supply_planes on this board: inside the fanout edge, off the isolated island and the PHY islands."""
    return planes_mod.supply_planes(board, (EDGE, EDGE, W - EDGE, H - EDGE),
                                    [grow(iso_island(board), ISO_MARGIN)] + island_keep_out(board), strict)


def hull(pts):
    """Convex hull, counter-clockwise (monotone chain)."""
    pts = sorted(set(pts))

    def half(seq):
        h = []
        for p in seq:
            while len(h) > 1 and (h[-1][0] - h[-2][0]) * (p[1] - h[-2][1]) - (h[-1][1] - h[-2][1]) * (p[0] - h[-2][0]) <= 0:
                h.pop()
            h.append(p)
        return h[:-1]
    return half(pts) + half(pts[::-1])


def grow(r, d):
    return r[0] - d, r[1] - d, r[2] + d, r[3] + d


def split_export(path, keep_file, dsn):
    """The DSN of the board at `path` with each net outside `keep` that still has open connections split into
    one net per connected piece, of the same class: its copper stays an obstacle, Freerouting has nothing to
    join on it. The piece with the most items keeps the name (with a plane, the plane's piece)."""
    board = pcbnew.LoadBoard(path)
    project.apply_netclasses(board)
    keep = set(json.load(open(keep_file, encoding="utf-8")))
    nets = sorted(n for n in cut_nets(board) if n not in keep)
    conn = board.GetConnectivity()          # built by cut_nets
    items = collections.defaultdict(list)
    for p in board.GetPads():
        items[p.GetNetname()].append(p)
    for t in board.GetTracks():
        items[t.GetNetname()].append(t)
    ns = board.GetDesignSettings().m_NetSettings
    moves = []
    for net in nets:
        seen, pieces = set(), []
        for it in items[net]:
            if it.m_Uuid.AsString() in seen:
                continue
            piece = [it] + [i for i in conn.GetConnectedItems(it)
                            if i.GetClass() in ("PAD", "PCB_TRACK", "PCB_ARC", "PCB_VIA") and i.GetNetname() == net]
            piece = [i for i in piece if i.m_Uuid.AsString() not in seen]
            seen.update(i.m_Uuid.AsString() for i in piece)
            pieces.append(piece)
        pieces.sort(key=len, reverse=True)
        cls = board.FindNet(net).GetNetClassName()
        for k, piece in enumerate(pieces[1:], 1):
            name = f"{net}~{k}"
            moves.append((name, cls, piece))
    for name, cls, piece in moves:
        ni = pcbnew.NETINFO_ITEM(board, name)
        board.Add(ni)
        ns.SetNetclassPatternAssignment(name, cls)
        for i in piece:
            i.SetNet(ni)
    ns.RecomputeEffectiveNetclasses()
    board.SynchronizeNetsAndNetClasses(True)
    if not pcbnew.ExportSpecctraDSN(board, dsn):
        raise SystemExit("DSN export failed")
    print(f"   DSN: {len(nets)} net(s) outside the pass split in {len(moves)} piece(s) more", flush=True)


def freerouting(board, keep, passes, band_keepout=True, widths=None):
    """Freerouting on the nets of `keep`, everything already on the board fixed; the new tracks and vias of
    these nets added to the board, locked. Not ImportSpecctraSES: it clears every track of the board first,
    and the nets left out of the DSN would lose theirs. Returns (tracks, vias) added, less the copper of
    nets that clash."""
    dsn, ses = PCB.replace(".kicad_pcb", ".dsn"), PCB.replace(".kicad_pcb", ".ses")
    # every net stays in the network: Freerouting drops the tracks of a net it does not know, and would cross
    # them. But it routes every open connection of the network, at every pass (a pass on 15 nets took 2 h, its
    # -inc option to ignore classes does nothing): the export splits the other nets (split_export)
    tmp = tempfile.mkdtemp()
    copy, kept_file = os.path.join(tmp, "board.kicad_pcb"), os.path.join(tmp, "keep.json")
    pcbnew.SaveBoard(copy, board)
    json.dump(sorted(keep), open(kept_file, "w", encoding="utf-8"))
    subprocess.run([sys.executable, os.path.abspath(__file__), "dsn", copy, kept_file, dsn], check=True)
    shutil.rmtree(tmp, ignore_errors=True)
    text = open(dsn, encoding="utf-8").read()
    # the chassis band of layer 4 is a zone, which Freerouting does not see on a signal layer: keepouts
    # (the chassis pass gives it as locked tracks instead, for the chassis to reach)
    u = 1000.0                      # DSN units: um, y up
    band = "".join(f"    (keepout (rect B.Cu {x0 * u:.0f} {-y1 * u:.0f} {x1 * u:.0f} {-y0 * u:.0f}))\n"
                   for x0, y0, x1, y1 in ((0, 0, W, CHASSIS_BAND + 0.5), (0, H - CHASSIS_BAND - 0.5, W, H),
                                          (0, 0, CHASSIS_BAND + 0.5, H), (W - CHASSIS_BAND - 0.5, 0, W, H))
                   ) if band_keepout else ""
    if "  (structure\n" not in text:
        raise SystemExit("DSN without a structure section")
    text = text.replace("  (structure\n", "  (structure\n" + band, 1)
    # Freerouting keeps copper to copper only; the board wants 0.25 mm from a hole to copper, 0.15 mm from the
    # copper of a 0.4/0.2 via: its vias drawn 0.1 mm wider in the DSN, the real size kept in their name
    text = re.sub(r'(\(padstack "Via\[0-3\]_\d+:\d+_um".*?\(attach)',
                  lambda m: re.sub(r'\(circle (\S+) (\d+)', lambda c: f"(circle {c.group(1)} {int(c.group(2)) + VIA_GROW}",
                                   m.group(1)), text, flags=re.S)
    text = widen_pads(text, board)
    text = isolate(text, board)
    text = thin(text, THIN if widths is None else widths)
    text = pad_contacts(text, board)
    text = barrier(text)
    open(dsn, "w", encoding="utf-8", newline="\n").write(text)
    # Freerouting gives the same result for the same input: a pass replayed on the same board takes the
    # session kept from its first run instead of routing again (the signals pass routes for hours)
    key = hashlib.sha1((text + repr(passes) + repr(VARIANTS)).encode("utf-8")).hexdigest()[:16]
    kept = os.path.join(os.path.dirname(PCB), "sessions", key + ".ses")
    if os.path.exists(kept):
        print(f"   session {key} reused", flush=True)
        shutil.copyfile(kept, ses)
        return take_session(board, ses, keep)
    # the variants run side by side with other costs, each into a session of its own; the one that leaves
    # the fewest connections unrouted is taken
    # -Xmx1g and SerialGC: one core and 1 GB per JVM; low priority, the machine stays usable
    flags = subprocess.BELOW_NORMAL_PRIORITY_CLASS if os.name == "nt" else 0
    runs = []
    for k, costs in enumerate(VARIANTS):
        out = ses.replace(".ses", f"-{k}.ses")
        if os.path.exists(out):
            os.remove(out)
        log = open(out.replace(".ses", ".log"), "w", encoding="utf-8")
        runs.append((k, out, log, subprocess.Popen(
            [JAVA, "-Xmx1g", "-XX:+UseSerialGC", "-jar", JAR, "-de", dsn, "-do", out, "-mp", str(passes),
             "--router.fanout.enabled=false", "--router.optimizer.enabled=false", "--gui.enabled=false"]
            + [f"--router.scoring.{name}={value}" for name, value in costs.items()],
            stdout=log, stderr=subprocess.STDOUT, creationflags=flags)))
    results = []
    for k, out, log, p in runs:
        p.wait(timeout=6 * 3600)
        log.close()
        text = open(log.name, encoding="utf-8", errors="replace").read()
        # "... final score: 859.46 (61 unrouted and 607 violations)"
        score = re.findall(r"final score: [\d.]+ \((\d+) unrouted and (\d+) violations\)", text)
        unrouted, violations = map(int, score[-1]) if score else (math.inf, math.inf)
        print(f"   variant {k} {VARIANTS[k]}: {unrouted} unrouted, {violations} violations", flush=True)
        if os.path.exists(out):
            results.append((unrouted, violations, k, out))
    if not results:
        raise SystemExit("Freerouting gave no result")
    best = min(results)
    print(f"   variant {best[2]} taken, kept as session {key}", flush=True)
    shutil.copyfile(best[3], ses)
    os.makedirs(os.path.dirname(kept), exist_ok=True)
    shutil.copyfile(best[3], kept)
    return take_session(board, ses, keep)


def take_session(board, ses, keep):
    """The new copper of a Freerouting session added to the board, less what clashes or ends nowhere."""
    tracks, vias, new = import_ses(board, ses, keep)
    # a pass that fails midway can leave two nets crossing: the new copper of one of them taken back
    bad = clashes(board, new)
    for t in new:
        if t.GetNetname() in bad:
            board.Remove(t)
            if t.GetClass() == "PCB_VIA":
                vias -= 1
            else:
                tracks -= 1
    if bad:
        print("   clashing new copper taken back, net(s) left unrouted: " + " ".join(sorted(bad)), flush=True)
    # a connection Freerouting gives up on can leave the wires it had laid toward it, ending nowhere
    gone, nets = prune_stubs(board, [t for t in new if t.GetNetname() not in bad])
    for t in gone:
        if t.GetClass() == "PCB_VIA":
            vias -= 1
        else:
            tracks -= 1
    if gone:
        print(f"   {len(gone)} dead-end item(s) of unfinished routes taken back: " + " ".join(sorted(nets)), flush=True)
    return tracks, vias


def prune_stubs(board, new):
    """The items of `new` that end nowhere (a track end on nothing, a via joining less than two layers),
    taken off the board until none is left. Returns (the items removed, their nets)."""
    def layers(conn, via):
        seen = set()
        for i in conn.GetConnectedItems(via):
            if i.GetClass() == "PAD" and i.HasHole():
                return 2
            seen.add(i.GetLayer())
        return len(seen)

    new = {t.m_Uuid.AsString(): t for t in new}
    gone = []
    while True:
        board.BuildConnectivity()
        conn = board.GetConnectivity()
        dead = [t for t in new.values() if (conn.TestTrackEndpointDangling(t, True) if t.GetClass() != "PCB_VIA"
                                            else layers(conn, t) < 2)]
        if not dead:
            return gone, {t.GetNetname() for t in gone}
        for t in dead:
            board.Remove(t)
            del new[t.m_Uuid.AsString()]
            gone.append(t)


def seg_seg(a, b, c, d):
    """Distance between the segments ab and cd."""
    def cross(o, p, q):
        return (p[0] - o[0]) * (q[1] - o[1]) - (p[1] - o[1]) * (q[0] - o[0])
    d1, d2, d3, d4 = cross(c, d, a), cross(c, d, b), cross(a, b, c), cross(a, b, d)
    if (d1 > 0) != (d2 > 0) and (d3 > 0) != (d4 > 0) and d1 and d2 and d3 and d4:
        return 0.0
    return min(seg_dist(a, c, d), seg_dist(b, c, d), seg_dist(c, a, b), seg_dist(d, a, b))


def clashes(board, new):
    """The nets of `new` (tracks and vias just added) closer than their clearance to a track or via of
    another net: of two clashing nets, the one with less new copper."""
    gap = gap_of(set(pcb.iso_nets({fp.GetReference(): fp for fp in board.GetFootprints()})))
    ids = {t.m_Uuid.AsString() for t in new}
    items, grid = [], collections.defaultdict(list)     # grid: 1 mm cells
    for t in board.GetTracks():
        if t.GetClass() == "PCB_VIA":
            a = b = xy(t.GetPosition())
            layers, r = {pcbnew.F_Cu, pcbnew.B_Cu}, mm(t.GetWidth(pcbnew.F_Cu)) / 2
        else:
            a, b = xy(t.GetStart()), xy(t.GetEnd())
            layers, r = {t.GetLayer()}, mm(t.GetWidth()) / 2
        k = len(items)
        items.append((t.GetNetname(), layers, a, b, r, t.m_Uuid.AsString() in ids))
        for i in range(math.floor(min(a[0], b[0]) - r), math.floor(max(a[0], b[0]) + r) + 1):
            for j in range(math.floor(min(a[1], b[1]) - r), math.floor(max(a[1], b[1]) + r) + 1):
                grid[i, j].append(k)
    count = collections.Counter(n for n, *_, fresh in items if fresh)
    bad = set()
    for cell in grid.values():
        for x in range(len(cell)):
            n1, l1, a1, b1, r1, f1 = items[cell[x]]
            for y in range(x + 1, len(cell)):
                n2, l2, a2, b2, r2, f2 = items[cell[y]]
                if n1 != n2 and (f1 or f2) and l1 & l2 and seg_seg(a1, b1, a2, b2) - r1 - r2 < gap(n1, n2) - 0.005:
                    bad.add(n1 if f1 and (not f2 or count[n1] <= count[n2]) else n2)
    return bad


def pad_contacts(text, board):
    """Freerouting joins a wire to a pad only by an end of the wire at the pad: the pairs run straight
    across the pads of their ESD arrays and terminations, which it then takes for unrouted and routes again
    at every pass, in the way of the others. In the DSN only, the wires of the pairs are split at the point
    nearest each pad centre, with a stub from there to the centre."""
    u = 1000.0                      # DSN units: um, y up
    pads = collections.defaultdict(list)
    for fp in board.GetFootprints():
        for p in fp.Pads():
            if re.fullmatch(PAIRS, p.GetNetname()) and p.IsOnLayer(pcbnew.F_Cu):
                pads[p.GetNetname()].append(p)
    names = {}

    def drop(m):
        net = m.group(2) if m.group(2) is not None else m.group(3)
        if not re.fullmatch(PAIRS, net):
            return m.group(0)
        names[net] = m.group(1)
        return ""
    text = re.sub(r'\s*\(wire \(path [^()]*\)\(net ("([^"]*)"|([^\s()]+))\)\(type \w+\)\)', drop, text)
    wires = []
    for t in board.GetTracks():
        net = t.GetNetname()
        if t.GetClass() == "PCB_VIA" or net not in pads:
            continue
        a, b = xy(t.GetStart()), xy(t.GetEnd())
        cuts = [a, b]
        for pad in pads[net]:
            c = xy(pad.GetPosition())
            if t.GetLayer() != pcbnew.F_Cu or min(math.dist(c, a), math.dist(c, b)) < 1e-3:
                continue
            dx, dy = b[0] - a[0], b[1] - a[1]
            k = min(max(((c[0] - a[0]) * dx + (c[1] - a[1]) * dy) / ((dx * dx + dy * dy) or 1.0), 0.0), 1.0)
            q = (a[0] + k * dx, a[1] + k * dy)
            if not pad.HitTest(vec(q), MM(mm(t.GetWidth()) / 2)):     # the track does not run over the pad
                continue
            cuts.append(q)
            wires.append((t.GetLayer(), t.GetWidth(), net, q, c))
        cuts.sort(key=lambda p: math.dist(a, p))
        wires += [(t.GetLayer(), t.GetWidth(), net, p, q) for p, q in zip(cuts, cuts[1:])]
    k = text.index("  (wiring") + len("  (wiring")
    return text[:k] + "".join(
        f"\n    (wire (path {board.GetLayerName(layer)} {round(mm(w) * u)}  {p[0] * u:.1f} {-p[1] * u:.1f}  "
        f"{q[0] * u:.1f} {-q[1] * u:.1f})(net {names.get(net, net)})(type fix))"
        for layer, w, net, p, q in wires if math.dist(p, q) > 1e-4) + text[k:]


def widen_pads(text, board):
    """Footprints with a clearance of their own (the SO-4 optocouplers: 0.2 mm), which Freerouting does not
    read: their pads drawn wider by the difference with the default clearance, in their image only."""
    default = project.CLASSES["Default"][1]
    wide = {}
    for fp in board.GetFootprints():
        c = fp.GetLocalClearance()
        if c and mm(c) > default + 1e-6:
            wide[fp.GetFPIDAsString()] = round((mm(c) - default) * 1000)
    extra = []
    # an image per footprint, and one more (name::1, ::2) for each instance whose pads differ
    images = [(m.group(1), wide[m.group(2)]) for m in re.finditer(r'\(image "?(([^"\n]+?)(?:::\d+)?)"?\n', text)
              if m.group(2) in wide]
    for image, d in images:
        m = re.search(r'\(image "?' + re.escape(image) + r'"?\n(.*?)\n    \)', text, re.S)
        names = set(re.findall(r'\(pin (\S+)', m.group(1)))
        body = m.group(1)
        for n in names:
            w = f"{n}_wide{d}"
            body = re.sub(r'\(pin ' + re.escape(n) + r'(\s)', f"(pin {w}\\1", body)
            pad = re.search(r'\(padstack ' + re.escape(n) + r'\n(.*?)\n    \)', text, re.S)
            if pad and w not in "".join(extra):
                shape = re.sub(r'\(rect (\S+) (-?\d+) (-?\d+) (-?\d+) (-?\d+)\)',
                               lambda r: f"(rect {r.group(1)} {int(r.group(2)) - d} {int(r.group(3)) - d} "
                                         f"{int(r.group(4)) + d} {int(r.group(5)) + d})", pad.group(1))
                shape = re.sub(r'\(circle (\S+) (\d+)', lambda c: f"(circle {c.group(1)} {int(c.group(2)) + 2 * d}", shape)
                extra.append(f"    (padstack {w}\n{shape}\n    )\n")
        text = text[:m.start(1)] + body + text[m.end(1):]
    if extra:
        k = text.index("    (padstack ")
        text = text[:k] + "".join(extra) + text[k:]
    return text


def thin(text, widths):
    """The nets of `widths` in a class of their own, with its width: the tracks Freerouting lays for them."""
    found = []

    def strip(m):
        names = [a or b for a, b in re.findall(r'"([^"]*)"|([^\s"]+)', m.group(2))]
        found.extend(n for n in names if n in widths)
        return f"(class {m.group(1)} " + " ".join(f'"{n}"' for n in names if n not in widths)

    text = re.sub(r'\(class\s+(\S+)((?:\s+(?:"[^"]*"|[^\s()]+))*)', strip, text)
    rules = "".join(f'    (class Thin{k} "{n}"\n      (circuit\n        (use_via "{SIGNAL_VIA}")\n      )\n'
                    f'      (rule\n        (width {round(widths[n] * 1000)})\n'
                    f'        (clearance {round(project.CLASSES[project.class_of(n)][1] * 1000)})\n      )\n    )\n'
                    for k, n in enumerate(sorted(set(found))))
    k = text.index("\n  (wiring")
    end = text.rindex("  )", 0, k)
    return text[:end] + rules + text[end:]


def isolate(text, board):
    """The Modbus isolation barrier, which Freerouting does not read from the .kicad_dru: the nets of the bus
    side in a class of their own, 1 mm from every other class (barrier)."""
    iso = set(pcb.iso_nets({fp.GetReference(): fp for fp in board.GetFootprints()}))
    found = []

    def strip(m):
        names = [a or b for a, b in re.findall(r'"([^"]*)"|([^\s"]+)', m.group(2))]
        found.extend(n for n in names if n in iso)
        rest = [n for n in names if n not in iso]
        return f"(class {m.group(1)} " + " ".join(f'"{n}"' for n in rest)

    text = re.sub(r'\(class\s+(\S+)((?:\s+(?:"[^"]*"|[^\s()]+))*)', strip, text)
    if not found:
        return text
    rules = f'    (class Isolated {" ".join(chr(34) + n + chr(34) for n in sorted(set(found)))}\n' \
            f'      (circuit\n        (use_via "{SIGNAL_VIA}")\n      )\n' \
            f'      (rule\n        (width 250)\n        (clearance {round(project.CLASSES["Default"][1] * 1000)})\n      )\n    )\n'
    k = text.index("\n  (wiring")
    end = text.rindex("  )", 0, k)
    return text[:end] + rules + text[end:]


def barrier(text):
    """The isolation barrier between the Isolated classes and every other class of the DSN, once the classes
    are final (thin adds classes)."""
    names = re.findall(r'\(class\s+(\S+)', text)
    iso = [n for n in names if n.startswith("Isolated")]
    rules = "".join(f"    (class_class\n      (classes {a} {b})\n      (rule\n        (clearance {round(ISO_MARGIN * 1000)})\n"
                    f"      )\n    )\n" for a in iso for b in names if b not in iso)
    k = text.index("\n  (wiring")
    end = text.rindex("  )", 0, k)
    return text[:end] + rules + text[end:]


def import_ses(board, ses, keep):
    """The wires and vias of a Freerouting session for the nets of `keep` that the board does not have yet,
    added locked. Returns (tracks, vias, the items) added."""
    text = open(ses, encoding="utf-8").read()
    have = set()
    for t in board.GetTracks():
        a, b = (round(mm(t.GetStart().x), 3), round(mm(t.GetStart().y), 3)), (round(mm(t.GetEnd().x), 3), round(mm(t.GetEnd().y), 3))
        have |= {(t.GetNetname(), a, b), (t.GetNetname(), b, a)}
    k = 1e-4                        # session units: (resolution um 10), y up
    added, new = [0, 0], []
    i = text.index("(network_out")
    for m in re.finditer(r'\(net\s+("([^"]*)"|([^\s()]+))', text[i:]):
        net = m.group(2) if m.group(2) is not None else m.group(3)
        start = i + m.start()
        end = text.find("\n      (net ", start + 5)
        body = text[start:end if end > 0 else len(text)]
        if net not in keep:
            continue
        ni = board.FindNet(net)
        for w in re.finditer(r'\(path\s+(\S+)\s+(\d+)\s+([-\d\s]+)\)', body):
            layer = board.GetLayerID(w.group(1))
            width = int(w.group(2)) * k
            xy_ = [int(v) for v in w.group(3).split()]
            pts = [(xy_[n] * k, -xy_[n + 1] * k) for n in range(0, len(xy_), 2)]
            for a, b in zip(pts, pts[1:]):
                key = (net, (round(a[0], 3), round(a[1], 3)), (round(b[0], 3), round(b[1], 3)))
                if key in have or math.dist(a, b) < 1e-4:
                    continue
                t = pcbnew.PCB_TRACK(board)
                t.SetStart(vec(a))
                t.SetEnd(vec(b))
                t.SetWidth(MM(width))
                t.SetLayer(layer)
                t.SetNet(ni)
                t.SetLocked(True)
                board.Add(t)
                new.append(t)
                added[0] += 1
        for v in re.finditer(r'\(via\s+"Via\[0-3\]_(\d+):(\d+)_um"\s+(-?\d+)\s+(-?\d+)', body):
            p = (int(v.group(3)) * k, -int(v.group(4)) * k)
            key = (net, (round(p[0], 3), round(p[1], 3)), (round(p[0], 3), round(p[1], 3)))
            if key in have:
                continue
            via = pcbnew.PCB_VIA(board)
            via.SetPosition(vec(p))
            via.SetWidth(MM(int(v.group(1)) / 1000))
            via.SetDrill(MM(int(v.group(2)) / 1000))
            via.SetNet(ni)
            via.SetLocked(True)
            board.Add(via)
            new.append(via)
            added[1] += 1
    return added[0], added[1], new


def refill():
    """Zone fill by kicad-cli: it loads the project, so the net classes and the custom rules."""
    rpt = PCB.replace(".kicad_pcb", "-drc.json")
    subprocess.run([cli(), "pcb", "drc", "--refill-zones", "--save-board", "--schematic-parity", "--severity-all",
                    "--format", "json", "-o", rpt, PCB], capture_output=True)
    return rpt


def unconnected_nets(rpt):
    """The nets of the unconnected items of a DRC report: at most 499 of them are listed."""
    d = json.load(open(rpt, encoding="utf-8"))
    return {net_of(i["description"]) for u in d["unconnected_items"] for i in u["items"]}


def cut_nets(board):
    """{net: connections missing} from the connectivity of the board, zones as filled: all of them, unlike the
    DRC report."""
    board.BuildConnectivity()
    conn = board.GetConnectivity()
    pads = collections.defaultdict(list)
    for p in board.GetPads():
        if p.GetNetname() and not p.GetNetname().startswith("unconnected-"):
            pads[p.GetNetname()].append(p)
    cut = {}
    for n, ps in pads.items():
        seen, groups = set(), 0
        for p in ps:
            if p.m_Uuid.AsString() in seen:
                continue
            groups += 1
            seen.add(p.m_Uuid.AsString())
            seen.update(i.m_Uuid.AsString() for i in conn.GetConnectedItems(p) if i.GetClass() == "PAD")
        if groups > 1:
            cut[n] = groups - 1
    return cut


def net_of(description):
    """The net of a DRC item description: 'Pad 3 [GND] of U1', 'Track [+3V3] on F.Cu'."""
    return re.sub(r"^.*\[(.*?)\].*$", r"\1", description)


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
        self.plane = {}             # net: (outline, outlines of the zones of other nets cut into it) per zone
        zones = [z for z in board.Zones() if not z.GetIsRuleArea() and z.GetLayer() in (pcbnew.In1_Cu, pcbnew.In2_Cu)]
        for z in zones:
            above = [o.Outline() for o in zones if o.GetLayer() == z.GetLayer() and o.GetNetname() != z.GetNetname()
                     and o.GetAssignedPriority() > z.GetAssignedPriority()]
            self.plane.setdefault(z.GetNetname(), []).append((z.Outline(), above))
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
        """Inside a zone of the net, and off the zones of other nets cut into it, with their clearance."""
        def ring(d):
            return [vec((v[0] + d * math.cos(a), v[1] + d * math.sin(a))) for a in (k * math.pi / 4 for k in range(8))]
        inner, outer = ring(r + PLANE_INSET), ring(r + PLANE_INSET + ZONE_GAP)
        return any(all(o.Contains(q) for q in inner) and not any(c.Contains(q) for c in above for q in outer + [vec(v)])
                   for o, above in self.plane.get(net, []))

    def via_ok(self, net, v, r, drill, near):
        """A via of radius r and hole `drill` at v clear of the board edge, the C-LOCK, the copper of the other
        nets on every layer, every hole and every pad."""
        if not (FANOUT_EDGE + r <= v[0] <= W - FANOUT_EDGE - r and FANOUT_EDGE + r <= v[1] <= H - FANOUT_EDGE - r):
            return False
        if math.dist(v, pcb.CLOCK) < pcb.CLOCK_CUT + COPPER_EDGE + r:
            return False
        via = pcbnew.SHAPE_CIRCLE(vec(v), MM(r))
        for o in near:
            # copper to hole, which also keeps the holes apart (the via is wider than its hole)
            if o.drill and math.dist(v, o.centre) < o.drill + r + (LEAD_GAP if o.pad else HOLE_GAP):
                return False
            if o.net == net:
                if o.pad and o.shape.Collide(via, MM(0.1)):
                    return False    # no via in a pad: the solder would flow down it
                continue
            if o.drill and not o.pad and math.dist(v, o.centre) < VIA_PITCH:
                return False        # the planes would not reach it, or the other one
            if o.shape.Collide(via, MM(self.gap(net, o.net))):
                return False
            if o.shape.Collide(pcbnew.SHAPE_CIRCLE(vec(v), MM(drill / 2)), MM(HOLE_GAP)):
                return False        # its hole against the copper of the other nets, pads included
        return True

    def track_ok(self, net, a, b, width, near, top):
        """A track from a to b on layer 1 (top) or 4, clear of the copper of the other nets on that layer and
        of the holes of the other nets."""
        e = COPPER_EDGE + width / 2 if top else FANOUT_EDGE
        for p in (a, b):
            if not (e <= p[0] <= W - e and e <= p[1] <= H - e):
                return False
        if seg_dist(pcb.CLOCK, a, b) < pcb.CLOCK_CUT + COPPER_EDGE + width / 2:
            return False
        seg = pcbnew.SHAPE_SEGMENT(vec(a), vec(b), MM(width))
        for o in near:
            if o.net == net:
                continue
            if o.drill and seg_dist(o.centre, a, b) < o.drill + width / 2 + (LEAD_GAP if o.pad else HOLE_GAP):
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


def fanout(cu, nets, only=lambda fp, p: True):
    """A stub on layer 1 and a via of its own for every surface pad of `nets` (those that `only` keeps): the
    shortest of 16 directions, outward from the part when it costs nothing, the via inside the plane of its
    net when the pad lies over it. Returns the pads left without a via, and the vias off their plane."""
    todo = []
    for fp in sorted(cu.board.GetFootprints(), key=lambda f: pcb.rank(f.GetReference())):
        through = [q for q in fp.Pads() if q.GetDrillSize().x and q.GetNetname() in nets]
        for p in fp.Pads():
            if (p.GetNetname() not in nets or p.GetAttribute() not in SURFACE or not p.IsOnLayer(pcbnew.F_Cu)
                    or not only(fp, p)):
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
                    if ((not planed or cu.in_plane(net, v, r)) and cu.via_ok(net, v, r, via_drill, near)
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


def complete():
    """The nets the passes before left incomplete: the fine-pitch pads of their ICs get a way out (a stub
    and a via, the fanout); the copper of the other signals around both ends of each missing connection is
    ripped up (RIP_REACH); then Freerouting on all these nets, everything else fixed. The ways out it leaves
    unused and the ends of ripped tracks that lead nowhere are taken back."""
    start("complete")
    rpt = refill()
    # the rip-up in a process of its own: a board that has lost items breaks the next calls of the API
    ripped = set()
    if RIP_REACH > 0:
        subprocess.run([sys.executable, os.path.abspath(__file__), "rip", rpt], check=True)
        ripped = set(json.load(open(RIPPED, encoding="utf-8")))
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    nets = (set(cut_nets(board)) & (signal_nets(board) | {"CHASSIS"})) | ripped
    cu = Copper(board)
    before = {t.m_Uuid.AsString() for t in board.GetTracks()}
    left, _ = fanout(cu, nets - {"CHASSIS"}, lambda fp, p: fp.GetReference().startswith("U")
                     and mm(min(p.GetSize(pcbnew.F_Cu).x, p.GetSize(pcbnew.F_Cu).y)) < ESCAPE_PAD)
    ways = {t.m_Uuid.AsString() for t in board.GetTracks()} - before
    tracks, vias = freerouting(board, nets, int(sys.argv[2]) if len(sys.argv) > 2 else 4,
                               widths={**THIN, **COMPLETE_THIN})
    # a way out stays when some copper other than its own stub meets its via
    unused, drop = 0, []
    items = list(board.GetTracks())
    for v in [t for t in items if t.m_Uuid.AsString() in ways and t.GetClass() == "PCB_VIA"]:
        c = xy(v.GetPosition())
        meet = [t for t in items if t.GetNetname() == v.GetNetname() and t.GetClass() != "PCB_VIA"
                and c in (xy(t.GetStart()), xy(t.GetEnd()))]
        if all(t.m_Uuid.AsString() in ways for t in meet):
            drop += meet + [v]
            unused += 1
    for t in drop:
        board.Remove(t)
    pruned = prune(board, ripped)
    print(f"complete pass: {len(nets)} nets ({len(ripped)} ripped), {len(ways) // 2} "
          f"way(s) out ({len(left)} without room), {unused} unused taken back; {tracks} track(s) and {vias} via(s) "
          f"added, {pruned} dead end(s) taken back", flush=True)
    project.save(board, PCB)


def rip(rpt):
    """The working board without the copper of the signals around both ends of each missing connection of
    the DRC report `rpt`; the nets ripped written to RIPPED."""
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    nets = unconnected_nets(rpt) & signal_nets(board)
    # the windows: both ends of each missing connection but the chassis (its band is the pass islands)
    windows = [(i["pos"]["x"] - RIP_REACH, i["pos"]["y"] - RIP_REACH, i["pos"]["x"] + RIP_REACH, i["pos"]["y"] + RIP_REACH)
               for u in json.load(open(rpt, encoding="utf-8"))["unconnected_items"]
               if net_of(u["items"][0]["description"]) in nets for i in u["items"]]
    # ripped: the signals routed by Freerouting or the short pass, not the supplies, the clock and the OCTOSPI
    supplies = set(RAILS.values()) | set(PHY_ISLANDS)     # their vias into the planes meet a single track
    rippable = {n for n in signal_nets(board) - supplies if not re.fullmatch(FAST, n)} | (nets - supplies)
    ripped = set()
    for t in list(board.GetTracks()):
        a, b = (xy(t.GetPosition()),) * 2 if t.GetClass() == "PCB_VIA" else (xy(t.GetStart()), xy(t.GetEnd()))
        if t.GetNetname() in rippable and any(
                max(a[0], b[0]) >= w[0] and min(a[0], b[0]) <= w[2] and max(a[1], b[1]) >= w[1] and min(a[1], b[1]) <= w[3]
                for w in windows):
            ripped.add(t.GetNetname())
            board.Remove(t)
    print(f"   rip-up: {len(ripped)} net(s) around {len(windows)} end(s)", flush=True)
    json.dump(sorted(ripped), open(RIPPED, "w", encoding="utf-8"))
    project.save(board, PCB)


def prune(board, nets):
    """Tracks of `nets` with an end that meets nothing of their net (track, via, pad), and vias that meet
    fewer than two tracks, taken back until none is left. Returns how many."""
    removed = 0
    while True:
        tracks = [t for t in board.GetTracks() if t.GetNetname() in nets]
        segs = [t for t in tracks if t.GetClass() != "PCB_VIA"]
        vias = [t for t in tracks if t.GetClass() == "PCB_VIA"]
        pads = [p for fp in board.GetFootprints() for p in fp.Pads() if p.GetNetname() in nets]

        def met(t, e):
            layer, net = t.GetLayer(), t.GetNetname()
            if any(v.GetNetname() == net and math.dist(xy(v.GetPosition()), e) < mm(v.GetWidth(pcbnew.F_Cu)) / 2
                   for v in vias):
                return True
            if any(p.GetNetname() == net and p.IsOnLayer(layer) and p.HitTest(vec(e)) for p in pads):
                return True
            return any(o is not t and o.GetNetname() == net and o.GetLayer() == layer
                       and seg_dist(e, xy(o.GetStart()), xy(o.GetEnd())) < mm(o.GetWidth()) / 2 for o in segs)
        dead = [t for t in segs if not (met(t, xy(t.GetStart())) and met(t, xy(t.GetEnd())))]
        dead += [v for v in vias if sum(1 for t in segs if t.GetNetname() == v.GetNetname()
                                        and min(math.dist(xy(t.GetStart()), xy(v.GetPosition())),
                                                math.dist(xy(t.GetEnd()), xy(v.GetPosition()))) < mm(v.GetWidth(pcbnew.F_Cu)) / 2) < 2]
        if not dead:
            return removed
        for t in dead:
            board.Remove(t)
        removed += len(dead)


def link(cu, net, off, inside=None, top=False, reach=LINK_REACH, size=None, clear=()):
    """Tracks on layer 4 from each via off its plane to a via of the net in the plane, an existing one or a
    new one, in an L or straight; the vias linked serve the next ones. Returns the vias left unlinked.
    inside(point, radius): where a via is in the plane, its outline by default; top: on layer 1 instead;
    reach: the longest link; size: (track width, via diameter, via drill), those of its class by default;
    clear: boxes (x0, y0, x1, y1) no track crosses nor new via sits in, but within ESCAPE_STUB of its ends; a
    box around the via linked is its own way out and does not count."""
    inside = inside or (lambda p, r: cu.in_plane(net, p, r))
    width, _, via_d, via_drill = project.CLASSES[project.class_of(net)]
    if size:
        width, via_d, via_drill = size
    targets = [o.centre for o in cu.items if o.net == net and o.drill and not o.pad and inside(o.centre, o.reach)]
    r = via_d / 2

    def paths(a, b):
        # horizontal and vertical first: a diagonal across layer 4 would block its signals
        return ([a, (a[0], b[1]), b], [a, (b[0], a[1]), b], [a, b])

    active = list(clear)

    def boxed(p):
        return any(x0 <= p[0] <= x1 and y0 <= p[1] <= y1 for x0, y0, x1, y1 in active)

    def path_ok(path):
        if active:
            for p, q in zip(path, path[1:]):
                k = max(1, int(math.dist(p, q) / 0.2))
                for i in range(k + 1):
                    c = (p[0] + (q[0] - p[0]) * i / k, p[1] + (q[1] - p[1]) * i / k)
                    if boxed(c) and min(math.dist(c, path[0]), math.dist(c, path[-1])) > ESCAPE_STUB:
                        return False
        return all(cu.track_ok(net, p, q, width, cu.near(p, q, width + 1.0), top) for p, q in zip(path, path[1:]))

    def length(path):
        return sum(math.dist(p, q) for p, q in zip(path, path[1:]))

    def lay(path):
        for p, q in zip(path, path[1:]):
            if math.dist(p, q) > 1e-3:
                cu.add_track(net, p, q, width, pcbnew.F_Cu if top else pcbnew.B_Cu)

    todo, progress = list(off), True
    while todo and progress:
        progress = False
        todo.sort(key=lambda s: min((math.dist(s[1], t) for t in targets), default=math.inf))
        for name, a in list(todo):
            active[:] = [(x0, y0, x1, y1) for x0, y0, x1, y1 in clear if not (x0 <= a[0] <= x1 and y0 <= a[1] <= y1)]
            best = None             # (track length, path, new via or None)
            for t in sorted(targets, key=lambda t: math.dist(a, t))[:LINK_TRIES]:
                if math.dist(a, t) > reach:
                    break
                p = next((p for p in paths(a, t) if length(p) <= reach and path_ok(p)), None)
                if p:
                    best = (length(p), p, None)
                    break
            # a new via in the plane, the nearest reachable, when it makes the track shorter
            for ox, oy in LINK_SPOTS:
                if math.hypot(ox, oy) + NEW_VIA_COST >= (best[0] if best else reach):
                    break
                b = (a[0] + ox, a[1] + oy)
                if not inside(b, r) or boxed(b) or not cu.via_ok(net, b, r, via_drill, cu.near(b, b, r + 1.0)):
                    continue
                p = next((p for p in paths(a, b) if path_ok(p)), None)
                if p and length(p) + NEW_VIA_COST < (best[0] if best else math.inf):
                    best = (length(p) + NEW_VIA_COST, p, b)
                    break
            if not best and clear:
                # no L: round what is in the way
                found = maze(cu, net, a, inside, width, via_d, via_drill, top, active)
                if found:
                    best = (length(found[0]), found[0], found[1])
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


def maze(cu, net, a, inside, width, via_d, via_drill, top, clear):
    """A way for a track from the via at a to a new via in the plane, round what is in the way: A* on a MAZE_GRID
    grid within MAZE_REACH of a, off the clear boxes, the corners checked as tracks. Returns (path, via) or
    None."""
    import heapq
    r = via_d / 2
    x0, y0 = a[0] - MAZE_REACH, a[1] - MAZE_REACH
    n = int(2 * MAZE_REACH / MAZE_GRID) + 1
    local = [o for o in cu.items if abs(o.centre[0] - a[0]) < MAZE_REACH + o.reach + 1.0
             and abs(o.centre[1] - a[1]) < MAZE_REACH + o.reach + 1.0]

    def near(p, q, m):
        return [o for o in local if seg_dist(o.centre, p, q) < o.reach + m]

    def pt(c):
        return x0 + c[1] * MAZE_GRID, y0 + c[0] * MAZE_GRID
    free = {}

    def ok(c):
        if c not in free:
            p = pt(c)
            free[c] = (0 <= c[0] < n and 0 <= c[1] < n and not any(bx0 <= p[0] <= bx1 and by0 <= p[1] <= by1 for bx0, by0, bx1, by1 in clear)
                       and cu.track_ok(net, p, p, width, near(p, p, width + 1.0), top))
        return free[c]
    start = (int(round((a[1] - y0) / MAZE_GRID)), int(round((a[0] - x0) / MAZE_GRID)))
    heap, seen, prev = [(0.0, start)], {start: 0.0}, {}
    while heap:
        g, c = heapq.heappop(heap)
        if g > seen.get(c, math.inf):
            continue
        p = pt(c)
        if c != start and inside(p, r) and cu.via_ok(net, p, r, via_drill, near(p, p, r + 1.0)):
            cells = [c]
            while cells[-1] in prev:
                cells.append(prev[cells[-1]])
            path = [a] + [pt(k) for k in cells[::-1][1:]]
            # straight runs merged, every segment checked as a track
            out = [path[0]]
            for k in range(1, len(path) - 1):
                u, v, w = out[-1], path[k], path[k + 1]
                if abs((v[0] - u[0]) * (w[1] - v[1]) - (v[1] - u[1]) * (w[0] - v[0])) > 1e-9:
                    out.append(v)
            out.append(path[-1])
            if all(cu.track_ok(net, u, v, width, near(u, v, width + 1.0), top) for u, v in zip(out, out[1:])):
                return out, p
            return None
        for dj, di in ((0, 1), (1, 0), (0, -1), (-1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)):
            m = (c[0] + dj, c[1] + di)
            ng = g + math.hypot(dj, di) * MAZE_GRID
            if ng < seen.get(m, math.inf) and ok(m):
                seen[m], prev[m] = ng, c
                heapq.heappush(heap, (ng, m))
    return None


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


def escape_boxes(board):
    """(x0, y0, x1, y1) of the ICs with pads narrower than ESCAPE_PAD, grown by ESCAPE_GROW: their way out."""
    out = []
    for fp in board.GetFootprints():
        if fp.GetReference().startswith("U") and any(
                mm(min(p.GetSize(pcbnew.F_Cu).x, p.GetSize(pcbnew.F_Cu).y)) < ESCAPE_PAD for p in fp.Pads()):
            bb = fp.GetBoundingBox(False)
            out.append((mm(bb.GetLeft()) - ESCAPE_GROW, mm(bb.GetTop()) - ESCAPE_GROW,
                        mm(bb.GetRight()) + ESCAPE_GROW, mm(bb.GetBottom()) + ESCAPE_GROW))
    return out


def fanout_pass(board, name, nets, reach=LINK_REACH, far=False, size=None):
    """Fanout of `nets`, then the vias off their plane linked on layer 4, up to `reach`; far: those beyond, by a
    track of `size` (that of their class by default). Returns the copper."""
    cu = Copper(board)
    left, off = fanout(cu, nets)
    unlinked = [s for net in sorted(nets) for s in link(cu, net, [(n, v) for m, n, v in off if m == net], reach=reach)]
    if far:
        # the pads out of reach of their plane (planes.py, or a block placed apart): a track up to LINK_REACH, layer 4 then 1
        # they keep off the way out of the fine-pitch ICs: a long track along a pin row walls its escape vias
        clear = escape_boxes(board)
        for top in (False, True):
            unlinked = [s for net in sorted(nets) for s in link(cu, net, [(n, v) for m, n, v in off if m == net and n in unlinked],
                                                                  None, top, LINK_REACH, size, clear)]
    # an unlinked via and its stub taken back: Freerouting starts from the pad, the planes keep their copper
    for net, n, v in off:
        if n in unlinked:
            for t in list(board.GetTracks()):
                if t.GetNetname() == net and (math.dist(xy(t.GetPosition()), v) < 1e-3 if t.GetClass() == "PCB_VIA"
                                              else min(math.dist(xy(t.GetStart()), v), math.dist(xy(t.GetEnd()), v)) < 1e-3):
                    board.Remove(t)
    print(f"{name} pass: {len(left)} pad(s) without a via, {len(off)} via(s) off the plane linked on layer 4, "
          f"{len(unlinked)} left unlinked, for the signals pass", flush=True)
    for s in left + unlinked:
        print("  ", s)
    cu.unlinked = left + unlinked
    return cu


def trunks():
    """The planes, then the wide tracks of TRUNKS, before any via: the fanouts route around them."""
    board = start("trunk")
    for layer in (pcbnew.In1_Cu, pcbnew.In2_Cu):
        board.SetLayerType(layer, pcbnew.LT_POWER)     # planes: Freerouting connects to them, never routes on them
    planes(board)
    cu = Copper(board)
    for net, spec in TRUNKS.items():
        # through-hole pads off the plane
        pads = [(f"{fp.GetReference()}.{p.GetNumber()}", xy(p.GetPosition())) for fp in board.GetFootprints()
                for p in fp.Pads() if p.GetNetname() == net and p.GetDrillSize().x
                and not cu.in_plane(net, xy(p.GetPosition()), mm(p.GetDrillSize().x))]
        blocked = trunk(cu, net, pads, *spec)
        print(f"trunk pass, {net}: {len(pads)} through-hole pad(s) off the plane " + " ".join(n for n, _ in pads) +
              (f", blocked, nothing laid: {blocked}" if blocked else ", laid"), flush=True)
    project.save(board, PCB)


def gnd():
    board = start("gnd")
    fanout_pass(board, "gnd", {"GND", "GNDISO"})
    project.save(board, PCB)


def trunk(cu, net, pads, width, via_d, via_drill):
    """A wide track on layer 4 for through-hole pads off their plane: along the first clear corridor of
    TRUNK_Y, a drop to each pad, down the clear line of the shortest trunk to two vias in the plane. All or
    nothing; returns the blocked segments."""
    r = via_d / 2

    def clear(a, b):
        return cu.track_ok(net, a, b, width, cu.near(a, b, width + 1.0), False)

    def steps(lo, hi):
        return [lo + 0.25 * i for i in range(int((hi - lo) / 0.25) + 1)]

    xs = [a[0] for _, a in pads]
    y = next((y for y in steps(*TRUNK_Y) if clear((min(xs), y), (max(xs), y))), None)
    if y is None:
        return [f"no clear corridor between y = {TRUNK_Y[0]} and {TRUNK_Y[1]}"]
    # the drop to the plane: any line across the board where two vias fit in the plane, the shortest trunk
    # (along the corridor beyond the pads, then down) first; the plane is drawn from the placement (planes.py)
    best = None
    for x in steps(FANOUT_EDGE + r, W - FANOUT_EDGE - r):
        along = max(0.0, min(xs) - x, x - max(xs))
        if best and along >= best[0]:
            continue
        foot = next(((x, v) for v in steps(y, H) if cu.in_plane(net, (x, v), r)
                     and cu.via_ok(net, (x, v), r, via_drill, cu.near((x, v), (x, v), r + 1.0))), None)
        if not foot or (best and along + foot[1] - y >= best[0]):
            continue
        twin = (x, foot[1] + max(VIA_PITCH, via_d + HOLE_GAP))
        if (clear((x, y), twin) and cu.in_plane(net, twin, r)
                and cu.via_ok(net, twin, r, via_drill, cu.near(twin, twin, r + 1.0))):
            best = (along + foot[1] - y, x, foot, twin)
    if best is None:
        return ["no clear way down to the plane"]
    _, x, foot, twin = best
    xs = sorted(set(xs) | {x})
    segs = list(zip([(u, y) for u in xs], [(u, y) for u in xs[1:]]))     # cut at every drop
    segs += [((x, y), foot), (foot, twin)] + [((a[0], y), a) for _, a in pads]
    blocked = [f"({a[0]:.1f}, {a[1]:.1f})-({b[0]:.1f}, {b[1]:.1f})" for a, b in segs if not clear(a, b)]
    if blocked:
        return blocked
    for v in (foot, twin):
        cu.add_via(net, v, via_d, via_drill)
    for a, b in segs:
        cu.add_track(net, a, b, width, pcbnew.B_Cu)
    return []


def mst(points):
    """Edges (i, j, length) of the minimum spanning tree of the points (Prim)."""
    if len(points) < 2:
        return []
    best = {i: (math.dist(points[0], points[i]), 0) for i in range(1, len(points))}
    edges = []
    while best:
        i = min(best, key=lambda k: best[k][0])
        d, j = best.pop(i)
        edges.append((j, i, d))
        for k in best:
            dk = math.dist(points[i], points[k])
            if dk < best[k][0]:
                best[k] = (dk, i)
    return edges


def bends(a, b):
    """Ways from a to b on one layer: straight, then an L, then a 45 degree bend at either end."""
    dx, dy = b[0] - a[0], b[1] - a[1]
    k = min(abs(dx), abs(dy))
    sx, sy = math.copysign(k, dx), math.copysign(k, dy)
    return [[a, b], [a, (a[0], b[1]), b], [a, (b[0], a[1]), b],
            [a, (a[0] + sx, a[1] + sy), b], [a, (b[0] - sx, b[1] - sy), b]]


def short():
    """Pads facing each other: every edge of the spanning tree of a net without a plane, up to SHORT_MAX
    long, as a track on layer 1 (straight, else with one bend) when it clears everything else."""
    board = start("short")
    cu = Copper(board)
    planed = {"GND", "GNDISO", *SUPPLY_NETS, *PHY_ISLANDS}
    pads = collections.defaultdict(list)
    narrow = {}
    for fp in board.GetFootprints():
        for p in fp.Pads():
            n = p.GetNetname()
            if (n and not n.startswith("unconnected-") and n not in planed and p.IsOnLayer(pcbnew.F_Cu)
                    and not re.fullmatch(PAIRS, n)):
                pads[n].append(xy(p.GetPosition()))
                narrow[n, xy(p.GetPosition())] = mm(min(p.GetSize(pcbnew.F_Cu).x, p.GetSize(pcbnew.F_Cu).y))
    edges = sorted((d, n, pts[i], pts[j]) for n, pts in pads.items() for i, j, d in mst(pts))
    laid, bent, blocked = 0, 0, []
    for d, n, a, b in edges:
        if d > SHORT_MAX:
            break
        # no wider than the narrower pad: a wide class necks down to the pins of a fine-pitch part
        width = min(project.CLASSES[project.class_of(n)][0], math.floor(min(narrow[n, a], narrow[n, b]) * 100) / 100 - 0.01)
        path = next((p for p in bends(a, b) if all(cu.track_ok(n, u, v, width, cu.near(u, v, width + 1.0), True)
                                                   for u, v in zip(p, p[1:]))), None)
        if not path:
            blocked.append(n)
            continue
        for u, v in zip(path, path[1:]):
            if math.dist(u, v) > 1e-3:
                cu.add_track(n, u, v, width, pcbnew.F_Cu)
        laid += 1
        bent += len(path) > 2
    print("short pass: spanning tree edges up to " + ", ".join(
        f"{m} mm {sum(1 for e in edges if e[0] <= m)}" for m in (1, 2, 3, 4, 5)) + f" (of {len(edges)})", flush=True)
    print(f"   up to {SHORT_MAX} mm: {laid} laid ({bent} with a bend), {len(blocked)} blocked: {' '.join(blocked)}",
          flush=True)
    project.save(board, PCB)


def islands():
    """The vias of the later passes cut pieces off the planes: a via of the net left on such a piece is linked
    on layer 4, else 1, to the main body of its plane (the fill of the stage before, saved by its report)."""
    start("islands")
    refill()
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    cut = set(cut_nets(board))      # only the plane nets found cut
    cu = Copper(board)
    planed = {"GND", "GNDISO", *SUPPLY_NETS, *PHY_ISLANDS} & cut
    linked, left = 0, []
    for z in board.Zones():
        net = z.GetNetname()
        if z.GetIsRuleArea() or net not in planed:
            continue
        for layer in z.GetLayerSet().Seq():
            fill = z.GetFilledPolysList(layer)
            if fill.OutlineCount() < 2:
                continue
            main = max(range(fill.OutlineCount()), key=lambda i: fill.Outline(i).Area())
            body = pcbnew.SHAPE_POLY_SET()
            body.AddOutline(fill.Outline(main))
            for h in range(fill.HoleCount(main)):
                body.AddHole(fill.Hole(main, h))

            def inside(p, r, body=body):
                return all(body.Contains(vec((p[0] + r * math.cos(a), p[1] + r * math.sin(a))))
                           for a in (k * math.pi / 4 for k in range(8))) and body.Contains(vec(p))
            # the copper of the net in groups joined by its tracks and pads: a group without a via or a
            # through-hole pad in the main body is linked once, by the first of its vias that reaches it
            for vias, holes in track_groups(board, net):
                # a via of the plane sits in a hole of its fill when it has a thermal relief: its ring counts
                if not vias or any(body.Contains(vec((p[0] + 0.3 * math.cos(k * math.pi / 4), p[1] + 0.3 * math.sin(k * math.pi / 4))))
                                   for p in vias + holes for k in range(8)) or any(body.Contains(vec(p)) for p in vias + holes):
                    continue
                name = f"{net} via {vias[0][0]:.2f},{vias[0][1]:.2f}"
                if (any(not link(cu, net, [(name, p)], inside, top) for top in (False, True) for p in vias)
                        or any(free_link(cu, net, p, inside) for p in vias)):
                    linked += 1
                else:
                    left.append(name)
    print(f"islands pass: {linked} via(s) linked to the main body of their plane, {len(left)} left: {' '.join(left)}",
          flush=True)
    project.save(board, PCB)


def free_link(cu, net, a, inside, tries=5, reach=6.0):
    """A track on layer 1 of any shape (the A* of the pair router) from the via at a to one of the nearest
    vias of the net in the plane. Returns True when laid."""
    import pairs
    width, clear = project.CLASSES[project.class_of(net)][:2]
    targets = sorted((o.centre for o in cu.items if o.net == net and o.drill and not o.pad
                      and math.dist(o.centre, a) <= reach and inside(o.centre, o.reach)), key=lambda t: math.dist(a, t))
    for t in targets[:tries]:
        box = (min(a[0], t[0]) - 3.0, min(a[1], t[1]) - 3.0, max(a[0], t[0]) + 3.0, max(a[1], t[1]) + 3.0)
        g = pairs.Grid(cu.board, {net}, box, width / 2,
                       extra=lambda n: max(project.CLASSES[project.class_of(n)][1] - clear, 0.0) if n else 0.0)
        cells = g.astar(g.cell(a), g.cell(t), clear + 0.05)     # the grid knows no holes: their clearance kept
        if cells:
            pts = pairs.simplify([a] + [g.point(c) for c in cells[1:-1]] + [t])
            for p, q in zip(pts, pts[1:]):
                cu.add_track(net, p, q, width, pcbnew.F_Cu)
            return True
    return False


def track_groups(board, net):
    """The copper of a net in groups joined by its tracks (ends that meet, at 1 um) and its pads: (vias,
    through-hole pads) of each group."""
    parent, kind = {}, {}

    def find(k):
        parent.setdefault(k, k)
        while parent[k] != k:
            parent[k] = parent[parent[k]]
            k = parent[k]
        return k

    def key(v):
        return round(mm(v.x), 3), round(mm(v.y), 3)
    for t in board.GetTracks():
        if t.GetNetname() != net:
            continue
        if t.GetClass() == "PCB_VIA":
            kind[find(key(t.GetPosition()))] = "via"
        else:
            parent[find(key(t.GetStart()))] = find(key(t.GetEnd()))
    ends = list(parent)
    for fp in board.GetFootprints():
        for p in fp.Pads():
            if p.GetNetname() != net:
                continue
            c = key(p.GetPosition())
            find(c)
            if p.GetDrillSize().x:
                kind[c] = "hole"
            for layer in (pcbnew.F_Cu, pcbnew.B_Cu):
                if p.IsOnLayer(layer):
                    poly = p.GetEffectivePolygon(layer, pcbnew.ERROR_INSIDE)
                    for k in ends:
                        if poly.Contains(pcbnew.VECTOR2I(MM(k[0]), MM(k[1]))):
                            parent[find(k)] = find(c)
    groups = collections.defaultdict(lambda: ([], []))
    for k, what in kind.items():
        groups[find(k)][what == "hole"].append(k)
    return list(groups.values())


def signal_nets(board):
    """All the nets but the ground planes, the pairs and the chassis (its band is a zone of layer 4); the
    supplies are in, for the vias their passes left off the plane: Freerouting routes only what is unconnected,
    a pad or via in a plane counts as connected."""
    done = {"GND", "GNDISO", "CHASSIS"}
    return {n for n in (str(k) for k in board.GetNetsByName().keys())
            if n and n not in done and not n.startswith("unconnected-") and not re.fullmatch(PAIRS, n)}


def rail(name):
    """Fanout of the supply, its plane bridges, then Freerouting on it alone for the pads still unlinked: the
    gate of main wants it whole."""
    board = start(name)
    net = RAILS[name]
    cu = fanout_pass(board, name, {net}, RAIL_LINK_MAX, far=True, size=BRIDGE)
    left = bridge(board, cu, net)
    if left or cu.unlinked:
        tracks, vias = freerouting(board, {net}, 4)
        print(f"{name} pass: Freerouting on {net} alone, {tracks} track(s) and {vias} via(s)", flush=True)
    project.save(board, PCB)


def bridge(board, cu, net):
    """The bridges of planes.supply_planes for net: a via in the piece, a track of BRIDGE on layer 4 (else 1)
    to a via in the main body of the plane. Returns those left unlaid."""
    supply, _, _, found = supply_planes(board)
    w, via_d, via_drill = BRIDGE
    r = via_d / 2
    poly, left = supply.get(net), []

    def body_at(p):
        for i in range(poly.OutlineCount()):
            if poly.Outline(i).PointInside(vec(p)) or poly.Outline(i).Collide(vec(p), MM(1.0)):
                b = pcbnew.SHAPE_POLY_SET()
                b.AddOutline(poly.Outline(i))
                for h in range(poly.HoleCount(i)):
                    b.AddHole(poly.Hole(i, h))
                return b
        return None

    def within(b):
        def inside(p, rad):
            return b.Contains(vec(p)) and all(b.Contains(vec((p[0] + rad * math.cos(k * math.pi / 4),
                                                                 p[1] + rad * math.sin(k * math.pi / 4)))) for k in range(8))
        return inside
    for n, a, b in found:
        if n != net:
            continue
        name = f"{net} bridge ({a[0]:.1f}, {a[1]:.1f})"
        piece, body = body_at(a), body_at(b)
        if piece is None or body is None:
            left.append(name)
            continue
        in_piece, in_body = within(piece), within(body)
        spot = next(((a[0] + ox, a[1] + oy) for ox, oy in LINK_SPOTS
                     if in_piece((a[0] + ox, a[1] + oy), r + PLANE_GAP)
                     and cu.via_ok(net, (a[0] + ox, a[1] + oy), r, via_drill, cu.near((a[0] + ox, a[1] + oy), (a[0] + ox, a[1] + oy), r + 1.0))),
                    None)
        if spot is None:
            left.append(name)
            continue
        cu.add_via(net, spot, via_d, via_drill)
        if all(link(cu, net, [(name, spot)], in_body, top, LINK_REACH, BRIDGE) for top in (False, True)):
            left.append(name)
    print(f"{net}: {len([f for f in found if f[0] == net]) - len(left)} plane bridge(s) laid"
          + (f", left to Freerouting: {' '.join(left)}" if left else ""), flush=True)
    return left


def report(rpt):
    """Violations by type, unrouted connections of the power nets, and supply planes cut into islands."""
    import collections
    import json
    d = json.load(open(rpt, encoding="utf-8"))
    nets = collections.Counter(net_of(u["items"][0]["description"]) for u in d["unconnected_items"])
    print(f"violations: {len(d['violations'])}, unconnected: {len(d['unconnected_items'])}, "
          f"parity: {len(d['schematic_parity'])}")
    print("   by type:", ", ".join(f"{t} {k}" for t, k in collections.Counter(v["type"] for v in d["violations"]).most_common()))
    print("   power nets unrouted:", ", ".join(f"{n} {k}" for n, k in nets.most_common() if project.class_of(n) in POWER_CLASSES))
    for v in d["violations"]:
        if not v["type"].startswith("silk"):
            print("  ", v["type"], " / ".join(i["description"][:60] for i in v["items"]))
    board = pcbnew.LoadBoard(PCB)
    cut = cut_nets(board)
    json.dump(cut, open(PCB.replace(".kicad_pcb", "-cut.json"), "w", encoding="utf-8"), indent=0, sort_keys=True)
    print(f"   connections missing: {sum(cut.values())} on {len(cut)} nets")
    for z in board.Zones():
        if z.GetIsRuleArea():
            continue
        for layer in z.GetLayerSet().Seq():
            n = z.GetFilledPolysList(layer).OutlineCount() if z.HasFilledPolysForLayer(layer) else 0
            print(f"   zone {z.GetZoneName():16} {board.GetLayerName(layer):6} {n} island(s)")


def plane_at(board, net, v):
    """A zone of `net` on an inner layer under the point v (mm)."""
    return any(z.GetNetname() == net and not z.GetIsRuleArea() and z.GetLayer() in (pcbnew.In1_Cu, pcbnew.In2_Cu)
               and z.Outline().Contains(vec(v)) for z in board.Zones())


def connection(board, pads):
    """The copper of the connections of `pads`: from each pad, the tracks and vias that lead away from it,
    up to the next pad, a junction, or a via in its plane (taken too when nothing else meets it)."""
    def key(v):
        return round(mm(v.x), 3), round(mm(v.y), 3)
    segs, vias = collections.defaultdict(list), {}
    for t in board.GetTracks():
        if t.GetClass() == "PCB_VIA":
            vias[t.GetNetname(), key(t.GetPosition())] = t
        else:
            segs[t.GetNetname()].append(t)
    net_pads = collections.defaultdict(list)
    for fp in board.GetFootprints():
        for p in fp.Pads():
            net_pads[p.GetNetname()].append(p)

    def on_pad(net, e, layer):
        return any(p.IsOnLayer(layer) and p.HitTest(vec(e)) for p in net_pads[net])

    gone = {}
    for pad in pads:
        net = pad.GetNetname()
        if not net or net.startswith("unconnected-"):
            continue
        todo = [(t, k) for t in segs[net] for k, e in enumerate((xy(t.GetStart()), xy(t.GetEnd())))
                if pad.IsOnLayer(t.GetLayer()) and pad.HitTest(vec(e))]
        while todo:
            t, k = todo.pop()
            uid = t.m_Uuid.AsString()
            if uid in gone:
                continue
            gone[uid] = t
            e = key(t.GetEnd() if k == 0 else t.GetStart())         # the far end
            if on_pad(net, e, t.GetLayer()):
                continue
            via = vias.get((net, e))
            meet = [o for o in segs[net] if o.m_Uuid.AsString() not in gone
                    and (via or o.GetLayer() == t.GetLayer()) and e in (key(o.GetStart()), key(o.GetEnd()))]
            if via and plane_at(board, net, e):
                if not meet:
                    gone[via.m_Uuid.AsString()] = via
                continue
            if len(meet) == 1:
                if via:
                    gone[via.m_Uuid.AsString()] = via
                o = meet[0]
                todo.append((o, 0 if key(o.GetStart()) == e else 1))
            elif not meet and via:
                gone[via.m_Uuid.AsString()] = via
    return list(gone.values())


def renet():
    """The pin nets of the schematic on the working board: the copper of every pad whose net changes is
    taken back (its connections only), then the pad takes its new net."""
    comps, pinnets = pcb.load_netlist()
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    changed = []
    for fp in board.GetFootprints():
        c = comps.get(fp.GetReference())
        if c and c["description"] and fp.GetFieldText("Description") != c["description"]:
            fp.SetField("Description", c["description"])
        for p in fp.Pads():
            new = pinnets.get(fp.GetReference(), {}).get(p.GetNumber())
            if new and new != p.GetNetname():
                changed.append((fp.GetReference(), p, new))
    gone = connection(board, [p for _, p, _ in changed])
    for ref, p, new in changed:
        print(f"   {ref}.{p.GetNumber()}: {p.GetNetname()} -> {new}")
        n = board.FindNet(new)
        if n is None:
            n = pcbnew.NETINFO_ITEM(board, new)
            board.Add(n)
        p.SetNet(n)
    for t in gone:
        board.Remove(t)
    print(f"renet: {len(changed)} pad(s) on a new net, {len(gone)} track(s) and via(s) taken back", flush=True)
    project.save(board, PCB)


def unroute(refs):
    """The connections of parts (REF) or pads (REF.PIN) taken back."""
    board = pcbnew.LoadBoard(PCB)
    project.apply_netclasses(board)
    pads = []
    for r in refs:
        ref, _, pin = r.partition(".")
        fp = board.FindFootprintByReference(ref)
        if fp is None:
            raise SystemExit(f"no part {ref}")
        pads += [p for p in fp.Pads() if not pin or p.GetNumber() == pin]
    gone = connection(board, pads)
    for t in gone:
        board.Remove(t)
    print(f"unroute: {len(gone)} track(s) and via(s) taken back from {' '.join(refs)}", flush=True)
    project.save(board, PCB)


def main():
    pcb.deterministic()
    step = sys.argv[1] if len(sys.argv) > 1 else "gnd"
    if step == "renet":
        renet()
        return subprocess.run([sys.executable, os.path.abspath(__file__), "report"], check=True)
    if step == "unroute":
        unroute(sys.argv[2:])
        return subprocess.run([sys.executable, os.path.abspath(__file__), "report"], check=True)
    if step == "report":
        return report(refill())
    if step == "back":
        shutil.copyfile(stage(sys.argv[2]), PCB)
        return print(f"{PCB} <- {stage(sys.argv[2])}")
    whole = set(WHOLE.get(step, ()))      # the nets the pass must leave whole
    if step == "trunk":
        trunks()
    elif step == "gnd":
        gnd()
    elif step in RAILS:
        rail(step)
    elif step == "phy":
        board = start("phy")
        fanout_pass(board, "phy", set(PHY_ISLANDS), RAIL_LINK_MAX, far=True)
        project.save(board, PCB)
    elif step == "short":
        short()
    elif step == "islands":
        islands()
    elif step == "complete":
        complete()
    elif step == "rip":
        return rip(sys.argv[2])
    elif step == "dsn":
        return split_export(*sys.argv[2:5])
    elif step == "pairs":
        import pairs
        board = start("pairs")
        pairs.run(board)
        project.save(board, PCB)
    elif step in ("fast", "signals"):
        board = start(step)
        names = {str(n) for n in board.GetNetsByName().keys()}
        if step == "fast":
            nets = whole = {n for n in names if re.fullmatch(FAST, n)}
        else:
            nets = signal_nets(board)
        tracks, vias = freerouting(board, nets, int(sys.argv[2]) if len(sys.argv) > 2 else 4)
        print(f"{step} pass: {len(nets)} nets, {tracks} track(s) and {vias} via(s) added", flush=True)
        project.save(board, PCB)
    elif step == "chassis":
        # the band of layer 4 as locked tracks of the chassis while Freerouting runs, for its pads to reach;
        # the signals the pass before left unrouted get a second chance in the same run
        board = start(step)
        c, ids = CHASSIS_BAND / 2, []
        ring = [(c, c), (W - c, c), (W - c, H - c), (c, H - c), (c, c)]
        for a, b in zip(ring, ring[1:]):
            t = pcbnew.PCB_TRACK(board)
            t.SetStart(vec(a))
            t.SetEnd(vec(b))
            t.SetWidth(MM(CHASSIS_BAND))
            t.SetLayer(pcbnew.B_Cu)
            t.SetNet(board.FindNet("CHASSIS"))
            t.SetLocked(True)
            board.Add(t)
            ids.append(t.m_Uuid.AsString())
        tracks, vias = freerouting(board, {"CHASSIS"} | signal_nets(board), int(sys.argv[2]) if len(sys.argv) > 2 else 4,
                                   band_keepout=False)
        for t in [t for t in board.GetTracks() if t.m_Uuid.AsString() in ids]:
            board.Remove(t)
        print(f"chassis pass: {tracks} track(s) and {vias} via(s) added", flush=True)
        project.save(board, PCB)
    else:
        raise SystemExit(f"unknown pass: {step}")
    # a second LoadBoard fails in a process that has removed items: report from a fresh one
    subprocess.run([sys.executable, os.path.abspath(__file__), "report"], check=True)
    rpt = PCB.replace(".kicad_pcb", "-drc.json")
    cut = set(json.load(open(PCB.replace(".kicad_pcb", "-cut.json"), encoding="utf-8"))) & whole
    if cut:
        raise SystemExit(f"FAILED: {step} pass leaves {' '.join(sorted(cut))} unconnected; stage not saved")
    # silkscreen aside, no violation: copper cut off a plane waits for the pass of its net, then the islands pass
    bad = [v["type"] for v in json.load(open(rpt, encoding="utf-8"))["violations"]
           if not v["type"].startswith("silk") and not (v["type"] == "isolated_copper"
                                                        and net_of(v["items"][0]["description"]) not in whole)]
    if bad:
        raise SystemExit(f"FAILED: {step} pass leaves violations {' '.join(sorted(set(bad)))}; stage not saved")
    shutil.copyfile(PCB, stage(step))     # zones filled by the report


if __name__ == "__main__":
    main()
