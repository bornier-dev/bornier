# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Base board PCB: outline, mechanical features of the DIN rail profile, connectors, then the other parts.

Run with the Python shipped with KiCad:
    "C:/Program Files/KiCad/10.0/bin/python.exe" pcb.py
Reads the netlist of ../kicad/base.kicad_sch (run schematic.py first), writes ../kicad/base.kicad_pcb and
the DRC rules of the profile, ../kicad/base.kicad_dru.

Mechanics: Phoenix UM-BASIC 108 profile, board 107.5 x 150 mm at the top level L1 (housing kit
UM-BASIC-KIT-B108-L150-7035), or screwed onto a panel through four M3 holes at the corners. The board rests
on the profile walls: nothing rises above its long edges, which carry every edge connector. The end
elements clamp the short edges: 3.1 mm without parts at each end on the top side, and 3.1 mm without parts
or leads all around on the bottom side, where the board rests on the walls. A C-LOCK L1 in the middle holds
the board down through a keyhole cutout. Coordinates in mm, origin at the top left corner, x along the
board, y across it; edge A (y = 0) and edge B (y = H) are the long edges.
"""
import math
import os
import shutil
import subprocess
import sys

import pcbnew

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "..", "..", "lib"))
from kicadgen.kicad import cli, footprint_dir  # noqa: E402
from kicadgen.sexpr import parse  # noqa: E402
sys.path.insert(0, HERE)
import project  # noqa: E402

KICAD = os.path.join(HERE, "..", "kicad")
STAGES = os.path.join(KICAD, "stages")      # one board per routing pass, not versioned (route.py)
STD_FP = footprint_dir()
LOCAL_FP = {"Bornier": os.path.join(HERE, "..", "..", "lib", "footprints", "Bornier.pretty")}
MM = pcbnew.FromMM

W, H = 150.0, 107.5           # UM-BASIC 108, kit L150
END_KEEP = 3.1                # top side, both short ends: clamped by the end elements
RIM_KEEP = 3.1                # bottom side, whole perimeter: rests on the profile walls
CLOCK = (W / 2, H / 2)        # C-LOCK L1: keyhole cutout, 11 mm without parts on both sides
CLOCK_KEEP = 5.5

# Connectors on the long edges, left to right, found by value. Edge A: one dual RJ45 per axis (drive
# port A, encoder port B), axes 0 to 3, at a pitch that keeps 0.8 mm between the shield leg holes of two
# jacks. Edge B: EtherCAT IN and OUT, terminal blocks, POWER at the right end. The USB jack is vertical
# and sits next to the MCU.
AXIS_JACK = "HC-WK88-H132-1X2-55B"
PITCH_A = 33.0
EDGE_B = ["HY911105AE IN", "HY911105AE OUT", "MODBUS", "SPINDLE A", "SPINDLE B", "ESTOP | PROBE", "POWER"]
GAP_B = 1.0                   # between groups on edge B
# M3 holes at the corners, 4.5 mm from both edges, clear of the connector rows; H1, plated on CHASSIS,
# next to POWER.
HOLES = {"H1": (W - 4.5, H - 4.5), "H2": (4.5, H - 4.5), "H3": (4.5, 4.5), "H4": (W - 4.5, 4.5)}
# PE contact (Phoenix UM-BASIC/PRO PE CONTACT L1): plated hole H5, 6.1 mm from the end and 30.2 mm from the
# centre line (position of the Phoenix sample board), at the POWER end on the edge B side. The contact runs
# under the board toward the DIN rail: no lead or bottom part over its body (12.4 to 33.2 mm from the centre
# line, 3.0 to 9.0 mm from the end).
PE_HOLE = (W - 6.1, H / 2 + 30.2)
PE_BODY = (W - 9.0, H / 2 + 12.4, W - 3.0, H / 2 + 33.2)
HOLES["H5"] = PE_HOLE


def vec(x, y):
    return pcbnew.VECTOR2I(MM(x), MM(y))


def load_netlist():
    """Components (footprint, value, fields, sheet) and pin nets, from a netlist exported from the schematic."""
    net = os.path.join(KICAD, "base.net")
    r = subprocess.run([cli(), "sch", "export", "netlist", "--format", "kicadsexpr", "-o", net,
                        os.path.join(KICAD, "base.kicad_sch")], capture_output=True, text=True)
    if r.returncode:
        raise SystemExit(f"netlist export failed: {r.stderr}")
    tree = parse(open(net, encoding="utf-8").read())
    os.remove(net)

    def find(node, name):
        return [c for c in node if isinstance(c, list) and c and str(c[0]) == name]

    def first(node, name):
        f = find(node, name)
        return f[0] if f else None

    comps = {}
    for c in find(first(tree, "components"), "comp"):
        ref = str(first(c, "ref")[1])
        fields = {str(first(f, "name")[1]): (str(f[2]) if len(f) > 2 and not isinstance(f[2], list) else "")
                  for f in find(first(c, "fields") or [], "field")}
        sp = first(c, "sheetpath")
        props = {str(first(p, "name")[1]) for p in find(c, "property")}
        comps[ref] = dict(fp=str(first(c, "footprint")[1]), value=str(first(c, "value")[1]),
                          dnp="dnp" in props, no_bom="exclude_from_bom" in props,
                          lcsc=fields.get("LCSC", ""), description=fields.get("Description", ""),
                          path=str(first(sp, "tstamps")[1]) + str(first(c, "tstamps")[1]),
                          sheetname=str(first(sp, "names")[1]))
    nets = {}
    for n in find(first(tree, "nets"), "net"):
        name = str(first(n, "name")[1])
        for node in find(n, "node"):
            nets.setdefault(str(first(node, "ref")[1]), {})[str(first(node, "pin")[1])] = name
    return comps, nets


# 3D models of KiCad library footprints whose model is missing from KiCad 10: the same package under
# another name, or a model written by hardware/lib/footprints/gen_3d.py from the part datasheet.
STD_3D = "${KICAD10_3DMODEL_DIR}"
OWN_3D = "${KIPRJMOD}/../../lib/footprints/Bornier.3dshapes"
MODEL_OVERRIDE = {
    "HVSSOP-8-1EP_3x3mm_P0.65mm_EP1.57x1.89mm": f"{STD_3D}/Package_SO.3dshapes/MSOP-8-1EP_3x3mm_P0.65mm_EP1.5x1.8mm.step",
    "TI_SO-PowerPAD-8_ThermalVias": f"{STD_3D}/Package_SO.3dshapes/TI_SO-PowerPAD-8.step",
    "Oscillator_SMD_SiT_PQFN-4Pin_2.0x1.6mm": f"{STD_3D}/Crystal.3dshapes/Crystal_SMD_2016-4Pin_2.0x1.6mm.step",
    "RJ45_Hanrun_HR911105A_Horizontal": f"{OWN_3D}/RJ45_HanRun_HY911105AE.step",
    "USB_Micro-B_Molex-105133-0001": f"{OWN_3D}/USB_Micro-B_Molex_105133-0001.step",
}


def load_fp(fpid):
    lib, name = fpid.split(":", 1)
    fp = pcbnew.FootprintLoad(LOCAL_FP.get(lib, os.path.join(STD_FP, lib + ".pretty")), name)
    if fp is None:
        raise SystemExit(f"footprint not found: {fpid}")
    fp.SetFPID(pcbnew.LIB_ID(lib, name))
    if name in MODEL_OVERRIDE:
        m = pcbnew.FP_3DMODEL()                     # the list hands out copies: replace it whole
        m.m_Filename = MODEL_OVERRIDE[name]
        fp.Models().clear()
        fp.Models().push_back(m)
    return fp


def courtyard(fp):
    """Courtyard extent (left, top, right, bottom) relative to the origin, at orientation 0."""
    fp.SetOrientationDegrees(0)
    fp.SetPosition(vec(0, 0))
    cy = fp.GetCourtyard(pcbnew.F_CrtYd)
    bb = cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False)
    T = pcbnew.ToMM
    return T(bb.GetLeft()), T(bb.GetTop()), T(bb.GetRight()), T(bb.GetBottom())


def place(fp, x, y, rot):
    fp.SetOrientationDegrees(rot)
    fp.SetPosition(vec(x, y))


def place_centred(fp, x, y, rot):
    """Courtyard centre at (x, y): the origin of a connector footprint is its pin 1."""
    place(fp, 0, 0, rot)
    cy = fp.GetCourtyard(pcbnew.F_CrtYd)
    c = (cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False)).GetCenter()
    place(fp, x - pcbnew.ToMM(c.x), y - pcbnew.ToMM(c.y), rot)


def segment(board, a, b, layer=pcbnew.Edge_Cuts):
    s = pcbnew.PCB_SHAPE(board, pcbnew.SHAPE_T_SEGMENT)
    s.SetStart(vec(*a))
    s.SetEnd(vec(*b))
    s.SetLayer(layer)
    s.SetWidth(MM(0.1))
    board.Add(s)


def arc(board, a, mid, b):
    s = pcbnew.PCB_SHAPE(board, pcbnew.SHAPE_T_ARC)
    s.SetArcGeometry(vec(*a), vec(*mid), vec(*b))
    s.SetLayer(pcbnew.Edge_Cuts)
    s.SetWidth(MM(0.1))
    board.Add(s)


def outline(board):
    """Rectangle, and the C-LOCK keyhole: an 8.6 x 2.4 mm slot with a 4.2 mm hole in its middle
    (Phoenix UM-BASIC data sheet 107666, figure 15; positions read on the Phoenix L1 sample board)."""
    pts = [(0, 0), (W, 0), (W, H), (0, H)]
    for a, b in zip(pts, pts[1:] + pts[:1]):
        segment(board, a, b)
    cx, cy = CLOCK
    x = math.sqrt(2.1 ** 2 - 1.2 ** 2)
    P = lambda dx, dy: (cx + dx, cy + dy)  # noqa: E731
    segment(board, P(-3.1, -1.2), P(-x, -1.2))
    arc(board, P(-x, -1.2), P(0, -2.1), P(x, -1.2))
    segment(board, P(x, -1.2), P(3.1, -1.2))
    arc(board, P(3.1, -1.2), P(4.3, 0), P(3.1, 1.2))
    segment(board, P(3.1, 1.2), P(x, 1.2))
    arc(board, P(x, 1.2), P(0, 2.1), P(-x, 1.2))
    segment(board, P(-x, 1.2), P(-3.1, 1.2))
    arc(board, P(-3.1, 1.2), P(-4.3, 0), P(-3.1, -1.2))


def rule_area(board, poly, layers, name, footprints=True, pads=False):
    z = pcbnew.ZONE(board)
    z.SetIsRuleArea(True)
    z.SetZoneName(name)
    ls = pcbnew.LSET()
    for layer in layers:
        ls.AddLayer(layer)
    z.SetLayerSet(ls)
    z.SetDoNotAllowZoneFills(False)
    z.SetDoNotAllowTracks(False)
    z.SetDoNotAllowVias(False)
    z.SetDoNotAllowPads(pads)
    z.SetDoNotAllowFootprints(footprints)
    o = z.Outline()
    o.NewOutline()
    for x, y in poly:
        o.Append(MM(x), MM(y))
    board.Add(z)


def circle(x, y, r, n=36):
    return [(x + r * math.cos(2 * math.pi * k / n), y + r * math.sin(2 * math.pi * k / n)) for k in range(n)]


DRC_RULES = """(version 1)
# Written by gen/pcb.py: Phoenix UM-BASIC 108 profile, board at level L1. The areas are drawn by pcb.py;
# the mounting holes H* are not parts and may sit in them.
(rule "end elements: no part on the top side at the short edges"
	(condition "A.Type == 'Footprint' && A.Layer == 'F.Cu' && A.intersectsArea('profile end element') && A.Reference != 'H*'")
	(constraint disallow footprint))
(rule "profile walls: no part on the bottom side at the edges"
	(condition "A.Type == 'Footprint' && A.Layer == 'B.Cu' && A.intersectsArea('profile wall')")
	(constraint disallow footprint))
(rule "profile walls: no through-hole lead at the edges, the board rests there"
	(condition "A.Type == 'Pad' && A.Pad_Type == 'Through-hole' && A.Hole_Size_X < 3mm && A.intersectsArea('profile wall')")
	(constraint disallow pad))
# JLCPCB multilayer boards: 0.2 mm holes and 0.1 mm spacing at no extra cost. The thermal vias of the ESC
# exposed pad (LAN9253 data sheet land pattern) are 0.2 mm; packages at a 0.65 mm pitch (TPS1H000 HVSSOP,
# TPS62A02 SOT-563) leave 0.15 mm between their own pads.
(rule "thermal vias in exposed pads"
	(condition "A.Type == 'Pad' && A.Pad_Type == 'Through-hole' && A.Hole_Size_X < 0.3mm")
	(constraint hole_size (min 0.2mm)))
"""
# An invalid expression silently disables every rule of the file: the package rule below is written per
# reference with memberOfFootprint(), the only form KiCad accepts, for the packages found by fine_pitch().
PACKAGE_RULE = """(rule "pads of one package: {ref}"
	(condition "A.Type == 'Pad' && B.Type == 'Pad' && A.memberOfFootprint('{ref}') && B.memberOfFootprint('{ref}')")
	(constraint clearance (min {gap:.2f}mm)))
"""


ISO_SEED = {"GNDISO", "/Modbus/VISO", "/Modbus/MB_A", "/Modbus/MB_B"}
ISO_BARRIER = "U38"          # CA-IS3092W: its pins 9 to 16 are on the bus side
BARRIER_RULE = """# Functional isolation of the Modbus port (ground loop break): 1 mm between the bus side and the rest.
# KiCad evaluates one order of each pair only: the condition is written both ways.
(rule "Modbus isolation barrier"
	(condition "(({iso_a}) && !({iso_b}) && B.NetName != '' && B.NetName != 'unconnected-*') || (({iso_b}) && !({iso_a}) && A.NetName != '' && A.NetName != 'unconnected-*')")
	(constraint clearance (min 1mm)))
"""


def iso_nets(fps):
    """Nets on the bus side of the isolated transceiver: from the seed, through the parts of the sheet,
    stopping at the transceiver and at the chassis (the 1 nF to the chassis bridges on purpose)."""
    nets, grew = set(ISO_SEED), True
    while grew:
        grew = False
        for ref, fp in fps.items():
            if ref == ISO_BARRIER or fp.GetSheetname() != "/Modbus/":
                continue
            mine = {p.GetNetname() for p in fp.Pads()} - {"", "CHASSIS"}
            if mine & nets and not mine <= nets:
                nets |= mine
                grew = True
    return sorted(nets)


def fine_pitch(fps, limit=0.2):
    """{reference: smallest gap between two of its own pads} for the packages under the board clearance."""
    found = {}
    for ref, fp in fps.items():
        rects = [mm_rect(p.GetBoundingBox()) for p in fp.Pads() if p.GetAttribute() == pcbnew.PAD_ATTRIB_SMD]
        gaps = [max(x1 - c, a - z, y1 - d, b - w)
                for i, (a, b, c, d) in enumerate(rects) for (x1, y1, z, w) in rects[i + 1:]]
        g = min((g for g in gaps if g > 0), default=limit)
        if g < limit - 1e-6:
            found[ref] = math.floor(g * 100 + 1e-6) / 100
    return found


def keepouts(board):
    """Named areas of the profile, checked by DRC_RULES, and the C-LOCK keep-out."""
    F, B = pcbnew.F_Cu, pcbnew.B_Cu
    for x0 in (0, W - END_KEEP):
        rule_area(board, [(x0, 0), (x0 + END_KEEP, 0), (x0 + END_KEEP, H), (x0, H)], [F], "profile end element",
                  footprints=False)
    for poly in ([(0, 0), (W, 0), (W, RIM_KEEP), (0, RIM_KEEP)], [(0, H - RIM_KEEP), (W, H - RIM_KEEP), (W, H), (0, H)],
                 [(0, 0), (RIM_KEEP, 0), (RIM_KEEP, H), (0, H)], [(W - RIM_KEEP, 0), (W, 0), (W, H), (W - RIM_KEEP, H)]):
        rule_area(board, poly, [B], "profile wall", footprints=False)
    rule_area(board, circle(*CLOCK, CLOCK_KEEP), [F, B], "C-LOCK")
    x0, y0, x1, y1 = PE_BODY
    rule_area(board, [(x0, y0), (x1, y0), (x1, y1), (x0, y1)], [B], "profile wall", footprints=False)


# Distance from the footprint origin to the board edge, toward +y, when it is not the front of the
# courtyard: the jack face goes to the edge, set back just enough for the pads of its front leads to clear
# the 3.1 mm rim that rests on the profile walls.
FRONT = {
    # drawing rev A: face 8.74 mm in front of the front row; shield legs 4.0 behind the face, pad 2.2:
    # face 0.2 mm inside the edge
    "RJ45x2_HongCheng_HC-WK88-H132-1X2-55B": 8.74 + 0.2,
    # HY911105AE: face 3.05 mm in front of the LED pins, pads 1.6: face 0.9 mm inside the edge
    "RJ45_Hanrun_HR911105A_Horizontal": 14.31 + 0.9,
}


def front(fp, bottom):
    return FRONT.get(str(fp.GetFPID().GetLibItemName()), bottom)


def connectors(fps, comps):
    """Edge A: openings toward y = 0 (rotated 180); edge B: openings toward y = H. Returns the references."""
    by_value = {c["value"]: ref for ref, c in comps.items()}
    edge_a = sorted((r for r, c in comps.items() if c["value"] == AXIS_JACK), key=lambda r: int(r[1:]))
    edge_b = [by_value[v] for v in EDGE_B]
    ext = {ref: courtyard(fps[ref]) for ref in edge_a + edge_b}
    x0 = (W - PITCH_A * (len(edge_a) - 1)) / 2          # centre of the first jack
    for k, ref in enumerate(edge_a):
        # rotated 180: the front faces y = 0
        place(fps[ref], x0 + PITCH_A * k, front(fps[ref], ext[ref][3]), 180)
    widths = [ext[r][2] - ext[r][0] for r in edge_b]
    x = (W - sum(widths) - GAP_B * (len(EDGE_B) - 1)) / 2
    for ref, w in zip(edge_b, widths):
        left, _, right, bottom = ext[ref]
        place(fps[ref], x - left, H - front(fps[ref], bottom), 0)
        x += w + GAP_B
    return edge_a + edge_b


# --- Floor plan -------------------------------------------------------------------------------------
# Edge A carries one column per axis (encoder receiver, half of a step/dir driver), the MCU sits in the
# middle, the ESC above the EtherCAT jacks, the local bus header stands at the left end, centred across the
# board so that the ribbon faces the modules (72 mm boards centred on the same rail). Each block of the edge
# B sits above its connector. Zones are rectangles (x0, y0, x1, y1); the parts of a sheet stay inside the
# zones of that sheet.
HE10_Y = H / 2
AXIS_X = [21.5, 55.0, 88.5, 118.0, 146.5]           # column boundaries, axes 0 to 3: the first two are shallower
BARRIER_Y = 84.0            # Modbus isolation: the axis of U38, bus side below toward J13, 1 mm each side
AXIS = [[(AXIS_X[k], 15.0, AXIS_X[k + 1], 58.0 if k > 1 else 47.0)] for k in range(4)]
AXIS[0].append((END_KEEP, 15.0, AXIS_X[0], HE10_Y - 26.0))   # above the header
AXIS[1].append((80.5, 47.0, AXIS_X[2], 59.5))                # right of the C-LOCK
ZONES = {
    "/Encoder 0/": AXIS[0], "/Encoder 1/": AXIS[1], "/Encoder 2/": AXIS[2], "/Encoder 3/": AXIS[3],
    "/Drives 0-1/": AXIS[0] + AXIS[1], "/Drives 2-3/": AXIS[2] + AXIS[3],
    "/Local bus/": [(END_KEEP, HE10_Y - 26.0, 21.0, HE10_Y + 26.0), (21.0, 47.5, 27.0, HE10_Y + 26.0)],
    "/ESC/": [(21.0, 47.5, 44.0, 87.5)],
    "/Clock/": [(21.0, 47.5, 69.0, 87.5)],
    "/MCU/": [(44.0, 47.5, 69.5, 76.0), (69.5, 59.5, 81.0, 76.0)],
    "/Modbus/": [(36.0, 76.0, 67.0, BARRIER_Y - 1.0)],
    "/Modbus/ bus side": [(36.0, BARRIER_Y + 1.0, 67.0, 96.5)],
    "/Spindle/": [(67.0, 76.0, 98.0, 96.5)],
    "/Safety/": [(98.0, 76.0, 123.5, 96.5)],
    "/Drive supply and probe/": [(98.0, 76.0, 123.5, 96.5), (81.0, 59.5, 104.0, 76.0)],
    "/Power/": [(104.0, 58.5, W - END_KEEP, 76.0), (123.5, 76.0, W - END_KEEP, 96.5), (69.5, 59.5, 104.0, 76.0)],
}

# Parts placed by hand: (x, y, rotation). The others go next to the pin they serve.
JACK_X = [25.5 + PITCH_A * k for k in range(4)]     # centres of the dual RJ45, from connectors()
KEY = {
    "U9": (56.5, 61.5, 0),                          # MCU: ESC and step/dir side toward the ESC
    "U4": (33.0, 74.0, 180),                        # ESC: PHY pins toward the EtherCAT jacks, port A left
    "J10": (END_KEEP + 5.0, HE10_Y, 0),               # local bus header, centred across the board
    "J2": (78.5, 67.0, 0),                          # micro-B, next to the USB pins of the MCU
    "J5": (69.5, 73.0, 0),                          # Tag-Connect, at the SWD corner
    "SW1": (41.5, 51.5, 90),                        # BOOT
    "U38": (55.5, BARRIER_Y, 270),                  # Modbus: bus side toward J13
    "U36": (82.0, 86.0, 0),                         # spindle 0-10 V
    "U1": (128.0, 62.0, 0), "L1": (139.0, 62.0, 0), "C1": (139.0, 74.0, 0),   # 5 V buck
    "U11": (AXIS_X[1] - 5.5, 36.0, 90), "U16": (AXIS_X[3] - 5.5, 36.0, 90),   # step/dir drivers, two axes each
}
for k, ref in enumerate(["U22", "U24", "U26", "U28"]):  # encoder receivers
    KEY[ref] = (max(JACK_X[k] - 4.0, AXIS_X[k] + 6.0), 38.0, 90)
# Nets that do not locate a part: a capacitor on them goes to a power pin of an IC of its sheet.
POWER_NETS = {"GND", "+3V3", "+5V", "+VIN", "+VIN_OUT", "CHASSIS", "/Modbus/GNDISO"}
# Protection parts go against the connector, not against the circuit they protect.
PROTECT = {"TPD4E05U06DQAR", "SMBJ33CA", "SMF15A", "PSM712-LF-T7"}
RANK = {"U": 0, "Q": 1, "D": 2, "L": 2, "F": 2, "R": 3, "C": 3, "J": 4, "S": 5}
GAP = 0.5                                           # between courtyards: one track between two passives
AIR, AIR_SLACK = 1.0, 2.0                           # preferred gap, taken if at most 2 mm farther from the pin


def spiral(step, radius):
    """Offsets within the radius, nearest first."""
    n = int(radius / step)
    return sorted(((i * step, j * step) for i in range(-n, n + 1) for j in range(-n, n + 1)
                   if (i * i + j * j) * step * step <= radius * radius), key=lambda o: o[0] * o[0] + o[1] * o[1])


RADIUS = 25.0
OFFSETS = spiral(0.25, RADIUS)
OFFSETS_FAR = spiral(0.5, 40.0)


def rank(ref):
    return RANK.get(ref.rstrip("0123456789")[:1] if not ref.startswith("JP") else "R", 6)


def mm_rect(bb, grow=0.0):
    T = pcbnew.ToMM
    return (T(bb.GetLeft()) - grow, T(bb.GetTop()) - grow, T(bb.GetRight()) + grow, T(bb.GetBottom()) + grow)


def occupied(fp):
    """Courtyard and pads of a placed part (some pads stick out of the courtyard)."""
    cy = fp.GetCourtyard(pcbnew.F_CrtYd)
    rects = [mm_rect(cy.BBox() if cy.OutlineCount() else fp.GetBoundingBox(False), GAP / 2)]
    rects += [mm_rect(p.GetBoundingBox(), GAP / 2) for p in fp.Pads()]
    return rects


def shape_at_origin(fp, rot):
    """Extent and pad positions relative to the origin, for one orientation."""
    place(fp, 0, 0, rot)
    pads = {}
    for p in fp.Pads():
        pads.setdefault(p.GetNetname(), (pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y)))
    return occupied(fp), pads


def nets_of(fp):
    return {p.GetNetname() for p in fp.Pads()} - {""}


def anchor_of(ref, fp, placed, used):
    """(rank, net, x, y) of the pin the part serves, or None while that pin is not placed."""
    sheet = fp.GetSheetname()
    mine = nets_of(fp)
    signal = mine - POWER_NETS
    protect = fp.GetValue() in PROTECT
    supply = mine - {"GND", "/Modbus/GNDISO", "CHASSIS"}
    best = None
    # 1. a signal pin of the sheet (or of a connector); 2. without signal net, the least used supply pin
    # of the sheet, ICs first (decoupling); 3. a signal pin of another sheet, once the sheet has had its
    # turn; 4. any pin of the sheet.
    for step in (1, 2, 3, 4):
        for r, other in placed.items():
            same = other.GetSheetname() == sheet or (r.startswith("J") and step == 1)
            if step != 3 and not same:
                continue
            for p in other.Pads():
                n = p.GetNetname()
                if step in (1, 3) and n in signal:
                    # protections and ICs that serve a connector: first, before the passives take the room
                    rk = 0 if (protect or ref[0] == "U") and r.startswith("J") else rank(r) if step == 1 else 6
                    key = (rk, 0, r, p.GetNumber())
                elif step == 2 and not signal and n in supply:
                    key = (rank(r), used.get((r, p.GetNumber()), 0), r, p.GetNumber())
                elif step == 4 and n in mine:
                    key = (6, 0, r, p.GetNumber())
                else:
                    continue
                if best is None or key < best[0]:
                    best = (key, n, pcbnew.ToMM(p.GetPosition().x), pcbnew.ToMM(p.GetPosition().y), r, p.GetNumber())
        if best:
            break
    return best


def inside(rects, zones):
    return all(any(z[0] <= x0 and z[1] <= y0 and x1 <= z[2] and y1 <= z[3] for z in zones)
               for x0, y0, x1, y1 in rects[:1])


def free(rects, occ):
    for x0, y0, x1, y1 in rects:
        if x0 < END_KEEP or x1 > W - END_KEEP or y0 < 0.3 or y1 > H - 0.3:
            return False
        cx, cy = min(max(CLOCK[0], x0), x1), min(max(CLOCK[1], y0), y1)
        if (cx - CLOCK[0]) ** 2 + (cy - CLOCK[1]) ** 2 < CLOCK_KEEP ** 2:
            return False
        for a, b, c, d in occ:
            if x0 < c and a < x1 and y0 < d and b < y1:
                return False
    return True


def auto_place(fps, placed, iso):
    """Place each remaining part as close as possible to the pin it serves, inside its zone, without overlap."""
    occ = [r for fp in placed.values() for r in occupied(fp)]
    bus = ZONES["/Modbus/ bus side"][0]
    def area(r):
        x0, y0, x1, y1 = courtyard(fps[r])
        return (x1 - x0) * (y1 - y0)

    # bulky parts first: small passives fit in the gaps they leave
    todo = sorted((r for r in fps if r not in placed), key=lambda r: (-area(r), r))
    used, failed = {}, []
    for rk in range(7):
        progress = True
        while progress:
            progress = False
            for ref in list(todo):
                fp = fps[ref]
                a = anchor_of(ref, fp, placed, used)
                if a is None or a[0][0] > rk:
                    continue
                _, net, ax, ay, ar, apin = a
                shapes = [(rot, *shape_at_origin(fp, rot)) for rot in (0, 90, 180, 270)]
                # the isolation barrier: bus side parts below it, all the others off the bus side
                mine = nets_of(fp) - {"CHASSIS"}
                on_bus = fp.GetSheetname() == "/Modbus/" and mine and mine <= iso
                sheet = "/Modbus/ bus side" if on_bus else fp.GetSheetname()
                barred = [] if on_bus else [(bus[0], BARRIER_Y, bus[2], bus[3])]

                def find(offsets, zones, tx, ty, air=0.0, limit=math.inf):
                    """First free spot along the offsets, the part grown by `air` on every side."""
                    for ox, oy in offsets:
                        if math.hypot(ox, oy) > limit:
                            return None
                        for rot, rects, pads in shapes:
                            px, py = pads.get(net, (0.0, 0.0))
                            dx, dy = tx - px + ox, ty - py + oy
                            moved = [(x0 + dx, y0 + dy, x1 + dx, y1 + dy) for x0, y0, x1, y1 in rects]
                            if inside(moved, zones) and free([(x0 - air, y0 - air, x1 + air, y1 + air)
                                                              for x0, y0, x1, y1 in moved], occ + barred):
                                return dx, dy, rot, moved, math.hypot(ox, oy)
                    return None

                spot = None
                # the zone of the sheet, then the zone grown into its neighbours when it is full
                for grow, offsets in ((0.0, OFFSETS), (4.0, OFFSETS_FAR), (8.0, OFFSETS_FAR), (12.0, OFFSETS_FAR)):
                    zones = [(x0 - grow, max(y0 - grow, bus[1]) if on_bus else y0 - grow, x1 + grow, y1 + grow)
                             for x0, y0, x1, y1 in ZONES.get(sheet, [(0, 0, W, H)])]
                    # a pin of another block: aim at the nearest point of the zone
                    z = min(zones, key=lambda z: math.dist((ax, ay), (min(max(ax, z[0]), z[2]), min(max(ay, z[1]), z[3]))))
                    tx, ty = min(max(ax, z[0]), z[2]), min(max(ay, z[1]), z[3])
                    spot = find(offsets, zones, tx, ty)
                    if spot:
                        # spread the parts: a spot with routing room around the part, if it is barely farther
                        spot = find(offsets, zones, tx, ty, AIR - GAP, spot[4] + AIR_SLACK) or spot
                        break
                if not spot:
                    # parked to the right of the board, and reported
                    failed.append(f"{ref} ({fp.GetSheetname()}, near {ar} pin {apin})")
                    spot = (W + 10 + 8 * (len(failed) % 20), 8 * (len(failed) // 20 + 1), 0, [])
                place(fp, *spot[:3])
                occ += spot[3]
                used[(ar, apin)] = used.get((ar, apin), 0) + 1
                placed[ref] = fp
                todo.remove(ref)
                progress = True
    if todo:
        failed.append("no pin to serve: " + " ".join(todo))
    return failed


def main():
    comps, pinnets = load_netlist()
    board = pcbnew.CreateEmptyBoard()
    board.SetCopperLayerCount(4)
    nets, fps = {}, {}

    def net(name):
        if name not in nets:
            ni = pcbnew.NETINFO_ITEM(board, name)
            board.Add(ni)
            nets[name] = ni
        return nets[name]

    for ref, c in sorted(comps.items()):
        fp = load_fp(c["fp"])
        fp.SetPath(pcbnew.KIID_PATH(c["path"]))
        fp.SetSheetname(c["sheetname"])
        fp.SetReference(ref)
        fp.SetValue(c["value"])
        fp.SetField("LCSC", c["lcsc"])
        fp.SetDNP(c["dnp"])
        fp.SetExcludedFromBOM(c["no_bom"])
        if c["description"]:
            fp.SetField("Description", c["description"])
        for f in fp.GetFields():
            if f.GetName() != "Reference":
                f.SetVisible(False)
        board.Add(fp)
        for pad in fp.Pads():
            n = pinnets.get(ref, {}).get(pad.GetNumber())
            if n:
                pad.SetNet(net(n))
        fps[ref] = fp

    outline(board)
    keepouts(board)
    fixed = set(connectors(fps, comps)) | set(HOLES)
    for ref, (x, y) in HOLES.items():
        place(fps[ref], x, y, 0)
        fps[ref].Reference().SetVisible(False)          # no silkscreen: it would fall off the board edge
    for ref, (x, y, rot) in KEY.items():
        place_centred(fps[ref], x, y, rot)
    failed = auto_place(fps, {ref: fps[ref] for ref in fixed | set(KEY)}, set(iso_nets(fps)))

    out = os.path.join(KICAD, "base.kicad_pcb")
    board.SetFileName(out)
    project.apply_netclasses(board)
    project.save(board, out)
    with open(os.path.join(KICAD, "base.kicad_dru"), "w", encoding="utf-8", newline="\n") as f:
        f.write(DRC_RULES)
        for ref, gap in sorted(fine_pitch(fps).items()):
            f.write(PACKAGE_RULE.format(ref=ref, gap=gap))
        iso = iso_nets(fps)
        f.write(BARRIER_RULE.format(iso_a=" || ".join(f"A.NetName == '{n}'" for n in iso),
                                    iso_b=" || ".join(f"B.NetName == '{n}'" for n in iso)))
    os.makedirs(STAGES, exist_ok=True)
    shutil.copyfile(out, os.path.join(STAGES, "0-placed.kicad_pcb"))     # the start of the routing passes
    print(f"{len(fps)} footprints, {len(nets)} nets -> {out}")
    if failed:
        raise SystemExit(f"{len(failed)} parts not placed:\n  " + "\n  ".join(failed))


if __name__ == "__main__":
    main()
