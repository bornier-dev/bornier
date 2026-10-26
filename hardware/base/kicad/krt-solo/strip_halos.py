"""Take halos.py's routing aids off a routed board before its fab DRC: the "halo ..." rule areas and the chassis
halo rule (a same-net via would grade against them). The CHASSIS exemption of the Modbus barrier stays.
Run with the Python shipped with KiCad:  python.exe strip_halos.py IN.kicad_pcb OUT.kicad_pcb
Nothing reads the board after the removals (pcbnew segfaults)."""
import os
import re
import shutil
import sys

import pcbnew

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
b = pcbnew.LoadBoard(src)
halos = [z for z in b.Zones() if z.GetIsRuleArea() and z.GetZoneName().startswith("halo")]
n = len(halos)
for z in halos:
    b.Remove(z)
b.Save(dst)
dru = dst[:-len(".kicad_pcb")] + ".kicad_dru"
text = open(dru, encoding="utf-8").read()
text = re.sub(r'\n\(rule "chassis halo:[^\n]*\n\t\(condition [^\n]*\n\t\(constraint [^\n]*\n', "\n", text)
open(dru, "w", encoding="utf-8").write(text)
print(f"strip_halos: {n} halo area(s) removed -> {dst}")
