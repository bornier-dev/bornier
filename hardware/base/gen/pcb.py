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
import subprocess
import sys

import pcbnew

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, os.path.join(HERE, "..", "..", "lib"))
from kicadgen.kicad import cli  # noqa: E402
from kicadgen.sexpr import parse  # noqa: E402

KICAD = os.path.join(HERE, "..", "kicad")
STD_FP = r"C:/Program Files/KiCad/10.0/share/kicad/footprints"
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
        comps[ref] = dict(fp=str(first(c, "footprint")[1]), value=str(first(c, "value")[1]),
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
"""


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
    # Not placed yet: parked in a grid to the right of the board
    for k, ref in enumerate(r for r in sorted(fps) if r not in fixed):
        place(fps[ref], W + 20 + 8 * (k % 40), 5 + 8 * (k // 40), 0)

    out = os.path.join(KICAD, "base.kicad_pcb")
    board.SetFileName(out)
    pcbnew.SaveBoard(out, board)
    with open(os.path.join(KICAD, "base.kicad_dru"), "w", encoding="utf-8", newline="\n") as f:
        f.write(DRC_RULES)
    print(f"{len(fps)} footprints, {len(nets)} nets -> {out}")


if __name__ == "__main__":
    main()
