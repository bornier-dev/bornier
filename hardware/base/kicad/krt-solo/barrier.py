"""The Modbus isolation barrier in the form KiCadRoutingTools reads, as a step of a KRT chain.

KRT skips the clearance rule between net lists ('Modbus isolation barrier' of the .kicad_dru), but honours a
rule area named in a 'disallow track via' rule filtered by net: the GNDISO pour on In1.Cu (written by
route_planes.py) becomes a rule area on every layer, and the other nets are kept out of it.
Run with the Python shipped with KiCad:  python.exe barrier.py IN.kicad_pcb OUT.kicad_pcb
"""
import os
import re
import shutil
import sys

import pcbnew

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pcb", ".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
dru = dst[:-len(".kicad_pcb")] + ".kicad_dru"
text = open(dru, encoding="utf-8").read()
rule = re.search(r'\(rule "Modbus isolation barrier".*?\n\t\(constraint', text, re.S).group(0)
iso = sorted(set(re.findall(r"A\.NetName == '([^']+)'", rule)))
b = pcbnew.LoadBoard(dst)
if any(z.GetIsRuleArea() and z.GetZoneName() == "modbus barrier" for z in b.Zones()):
    raise SystemExit("barrier: already there")
islands = [z for z in b.Zones() if not z.GetIsRuleArea() and z.GetNetname() == "GNDISO"]
if not islands:
    raise SystemExit("barrier: no GNDISO pour to draw it from (run route_planes.py with GNDISO first)")
area = pcbnew.ZONE(b)
area.SetIsRuleArea(True)
area.SetZoneName("modbus barrier")
area.SetLayerSet(pcbnew.LSET.AllCuMask())
for keep in (area.SetDoNotAllowTracks, area.SetDoNotAllowVias, area.SetDoNotAllowPads,
             area.SetDoNotAllowZoneFills, area.SetDoNotAllowFootprints):
    keep(False)
area.Outline().AddOutline(islands[0].Outline().Outline(0))
b.Add(area)
b.Save(dst)
names = " || ".join(f"A.NetName == '{n}'" for n in iso)
open(dru, "a", encoding="utf-8").write(
    '\n(rule "modbus barrier: the other nets out of the isolated island"\n'
    f"\t(condition \"A.intersectsArea('modbus barrier') && !({names})\")\n"
    "\t(constraint disallow track via))\n")
print(f"barrier: rule area on the GNDISO island, {len(iso)} net(s) allowed in -> {dst}")
