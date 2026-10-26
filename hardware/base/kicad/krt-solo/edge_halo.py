"""A keep-out (tracks and vias) over each cutout inside the board, grown by the JLCPCB board-edge gap: the router
keeps its edge clearance off the outline but not off an inner slot.  Named "halo edge", strip_halos.py removes it.
Run with the Python shipped with KiCad:  python.exe edge_halo.py IN.kicad_pcb OUT.kicad_pcb"""
import os
import shutil
import sys

import pcbnew

EDGE_GAP, MARGIN = 0.2, 0.05

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
b = pcbnew.LoadBoard(src)
mm = pcbnew.FromMM
outline = b.GetBoardEdgesBoundingBox()
inner = []
for d in b.GetDrawings():
    if d.GetLayer() == pcbnew.Edge_Cuts:
        bb = d.GetBoundingBox()
        if bb.GetLeft() > outline.GetLeft() + mm(1) and bb.GetRight() < outline.GetRight() - mm(1) \
                and bb.GetTop() > outline.GetTop() + mm(1) and bb.GetBottom() < outline.GetBottom() - mm(1):
            inner.append([bb.GetLeft(), bb.GetTop(), bb.GetRight(), bb.GetBottom()])
# one box per cutout: merge the boxes of the segments that touch
boxes = []
for r in inner:
    for o in boxes:
        if r[0] <= o[2] and o[0] <= r[2] and r[1] <= o[3] and o[1] <= r[3]:
            o[:] = [min(o[0], r[0]), min(o[1], r[1]), max(o[2], r[2]), max(o[3], r[3])]
            break
    else:
        boxes.append(list(r))
g = mm(EDGE_GAP + MARGIN)
for x0, y0, x1, y1 in boxes:
    z = pcbnew.ZONE(b)
    z.SetIsRuleArea(True)
    z.SetZoneName("halo edge")
    z.SetLayerSet(pcbnew.LSET.AllCuMask())
    z.SetDoNotAllowTracks(True)
    z.SetDoNotAllowVias(True)
    for keep in (z.SetDoNotAllowPads, z.SetDoNotAllowZoneFills, z.SetDoNotAllowFootprints):
        keep(False)
    s = pcbnew.SHAPE_POLY_SET()
    s.NewOutline()
    for x, y in ((x0 - g, y0 - g), (x1 + g, y0 - g), (x1 + g, y1 + g), (x0 - g, y1 + g)):
        s.Append(int(x), int(y))
    z.Outline().Append(s)
    b.Add(z)
b.Save(dst)
print(f"edge_halo: {len(boxes)} inner cutout(s) kept out -> {dst}")
