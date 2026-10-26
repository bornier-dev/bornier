"""Version 2 of barrier.py: the Modbus island is a fixed rectangle (U38 locked across its north edge).

After route_planes.py: every pour of another net is cut 1 mm around the island, the GNDISO pour of the first
plane layer becomes the island itself, and a rule area keeps the other nets' tracks and vias out of it
('disallow track via' filtered by net, the form KiCadRoutingTools honours).
Run with the Python shipped with KiCad:  python.exe barrier2.py IN.kicad_pcb OUT.kicad_pcb
"""
import os
import re
import shutil
import sys

import pcbnew

ISLAND = (27.3, 86.0, 45.2, 107.5)
GAP = 1.0

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pcb", ".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
dru = dst[:-len(".kicad_pcb")] + ".kicad_dru"
text = open(dru, encoding="utf-8").read()
rule = re.search(r'\(rule "Modbus isolation barrier".*?\n\t\(constraint', text, re.S).group(0)
iso = sorted(set(re.findall(r"A\.NetName == '([^']+)'", rule)))


def rect(x0, y0, x1, y1):
    s = pcbnew.SHAPE_POLY_SET()
    s.NewOutline()
    for x, y in ((x0, y0), (x1, y0), (x1, y1), (x0, y1)):
        s.Append(pcbnew.FromMM(x), pcbnew.FromMM(y))
    return s


b = pcbnew.LoadBoard(dst)
if any(z.GetIsRuleArea() and z.GetZoneName() == "modbus barrier" for z in b.Zones()):
    raise SystemExit("barrier: already there")
x0, y0, x1, y1 = ISLAND
moat = rect(x0 - GAP, y0 - GAP, x1 + GAP, y1 + GAP)
cut = 0
iso_zone = None
for z in list(b.Zones()):
    if z.GetIsRuleArea():
        continue
    if z.GetNetname() == "GNDISO":
        if iso_zone is None:
            iso_zone = z
        continue
    if z.GetNetname() in iso:
        continue
    outline = z.Outline()
    outline.BooleanSubtract(moat)
    cut += 1
if iso_zone is None:
    raise SystemExit("barrier: no GNDISO pour (run route_planes.py with GNDISO first)")
iso_zone.Outline().RemoveAllContours()
iso_zone.Outline().Append(rect(*ISLAND))

area = pcbnew.ZONE(b)
area.SetIsRuleArea(True)
area.SetZoneName("modbus barrier")
area.SetLayerSet(pcbnew.LSET.AllCuMask())
for keep in (area.SetDoNotAllowTracks, area.SetDoNotAllowVias, area.SetDoNotAllowPads,
             area.SetDoNotAllowZoneFills, area.SetDoNotAllowFootprints):
    keep(False)
area.Outline().Append(rect(*ISLAND))
b.Add(area)
pcbnew.ZONE_FILLER(b).Fill(b.Zones())
b.Save(dst)
# CHASSIS crosses the barrier by design: J13's shield and the isolation cap C86 sit in the island
names = " || ".join(f"A.NetName == '{n}'" for n in iso + ["CHASSIS"])
open(dru, "a", encoding="utf-8").write(
    '\n(rule "modbus barrier: the other nets out of the isolated island"\n'
    f"\t(condition \"A.intersectsArea('modbus barrier') && !({names})\")\n"
    "\t(constraint disallow track via))\n")
print(f"barrier: island {ISLAND}, {cut} pour(s) cut by {GAP} mm, GNDISO pour = island on "
      f"{b.GetLayerName(iso_zone.GetFirstLayer())}, {len(iso)} net(s) allowed in -> {dst}")
