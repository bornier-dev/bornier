"""Keep-outs for the clearances the router does not model, so it routes clear of them:
  * no via within 0.28 mm of a plated through-hole lead's hole (JLCPCB), 0.2 mm of a non-plated hole;
  * no track or via of another net within 1 mm of a CHASSIS pad (the Chassis class), except the nets
    with a pad of their own inside that halo (a connector's own pins next to its shield tab).
The CHASSIS net may also cross the Modbus barrier: J13's shield and the isolation cap C86 sit in the island.
Run with the Python shipped with KiCad:  python.exe halos.py IN.kicad_pcb OUT.kicad_pcb
"""
import os
import re
import shutil
import sys

import pcbnew

TH_GAP, NPTH_GAP, CHASSIS_GAP, MARGIN = 0.28, 0.2, 1.0, 0.02

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pcb", ".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
b = pcbnew.LoadBoard(dst)
mm, to_mm = pcbnew.FromMM, pcbnew.ToMM
if any(z.GetIsRuleArea() and z.GetZoneName().startswith("halo") for z in b.Zones()):
    raise SystemExit("halos: already there")


def area(name, poly, vias_only):
    z = pcbnew.ZONE(b)
    z.SetIsRuleArea(True)
    z.SetZoneName(name)
    z.SetLayerSet(pcbnew.LSET.AllCuMask())
    z.SetDoNotAllowVias(vias_only)
    for keep in (z.SetDoNotAllowTracks, z.SetDoNotAllowPads, z.SetDoNotAllowZoneFills, z.SetDoNotAllowFootprints):
        keep(False)
    z.Outline().Append(poly)
    b.Add(z)


def circle(x, y, r):
    s = pcbnew.SHAPE_POLY_SET()
    s.NewOutline()
    import math
    for k in range(24):
        a = 2 * math.pi * k / 24
        s.Append(int(x + r * math.cos(a) / math.cos(math.pi / 24)), int(y + r * math.sin(a) / math.cos(math.pi / 24)))
    return s


holes = chassis = 0
halo_boxes = []
for fp in b.GetFootprints():
    for p in fp.Pads():
        pos = p.GetPosition()
        if p.GetAttribute() in (pcbnew.PAD_ATTRIB_PTH, pcbnew.PAD_ATTRIB_NPTH) and p.GetDrillSizeX() >= mm(0.3):
            gap = TH_GAP if p.GetAttribute() == pcbnew.PAD_ATTRIB_PTH else NPTH_GAP
            r = max(p.GetDrillSizeX(), p.GetDrillSizeY()) / 2 + mm(gap + MARGIN)
            area(f"halo hole {fp.GetReference()}.{p.GetNumber()}", circle(pos.x, pos.y, r), True)
            holes += 1
        if p.GetNetname() == "CHASSIS" and p.IsOnCopperLayer():
            bb = p.GetBoundingBox()
            g = mm(CHASSIS_GAP + MARGIN)
            box = (bb.GetLeft() - g, bb.GetTop() - g, bb.GetRight() + g, bb.GetBottom() + g)
            s = pcbnew.SHAPE_POLY_SET()
            s.NewOutline()
            for x, y in ((box[0], box[1]), (box[2], box[1]), (box[2], box[3]), (box[0], box[3])):
                s.Append(x, y)
            area("halo chassis", s, False)
            halo_boxes.append(box)
            chassis += 1
# the nets that own a pad inside a chassis halo stay allowed in it
inside = {"CHASSIS"}
for fp in b.GetFootprints():
    for p in fp.Pads():
        q = p.GetPosition()
        if p.GetNetname() and any(x0 <= q.x <= x1 and y0 <= q.y <= y1 for x0, y0, x1, y1 in halo_boxes):
            inside.add(p.GetNetname())
b.Save(dst)

dru = dst[:-len(".kicad_pcb")] + ".kicad_dru"
text = open(dru, encoding="utf-8").read()
# CHASSIS crosses the Modbus barrier by design
text = re.sub(r"(\(condition \"A\.intersectsArea\('modbus barrier'\) && !\()([^\"]*?)(\)\")",
              lambda m: m.group(0) if "'CHASSIS'" in m.group(2)
              else f"{m.group(1)}{m.group(2)} || A.NetName == 'CHASSIS'{m.group(3)}", text)
names = " || ".join(f"A.NetName == '{n}'" for n in sorted(inside))
text += ('\n(rule "chassis halo: the other nets 1 mm off the CHASSIS pads"\n'
         f"\t(condition \"A.intersectsArea('halo chassis') && !({names})\")\n"
         "\t(constraint disallow track via))\n")
open(dru, "w", encoding="utf-8").write(text)
print(f"halos: {holes} hole halo(s), {chassis} chassis halo(s), {len(inside)} net(s) allowed near CHASSIS -> {dst}")
