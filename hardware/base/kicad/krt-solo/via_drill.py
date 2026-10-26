"""Drill the 0.45/0.3 mm vias at 0.2 mm, same pad: the track-to-hole gap grows from 0.165 to 0.215 mm when
the router lays tracks at the 0.09 mm floor, over JLCPCB's 0.2 mm (a via 0.45 mm across costs nothing extra
under a 0.3 mm hole). The Default class is drilled the same way so a later step lays the same via.
   "C:/Program Files/KiCad/10.0/bin/python.exe" via_drill.py IN.kicad_pcb OUT.kicad_pcb"""
import json
import os
import shutil
import sys

import pcbnew

src, dst = sys.argv[1:3]
for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
    if os.path.exists(src[:-10] + ext) and src != dst:
        shutil.copy(src[:-10] + ext, dst[:-10] + ext)
b = pcbnew.LoadBoard(src)
mm = pcbnew.FromMM
n = 0
for t in b.GetTracks():
    if t.GetClass() == "PCB_VIA" and t.GetWidth(pcbnew.F_Cu) == mm(0.45) and t.GetDrill() == mm(0.3):
        t.SetDrill(mm(0.2))
        n += 1
b.Save(dst)
pro = dst[:-10] + ".kicad_pro"
d = json.load(open(pro, encoding="utf-8"))
for c in d["net_settings"]["classes"]:
    if c.get("via_diameter") == 0.45 and c.get("via_drill") == 0.3:
        c["via_drill"] = 0.2
json.dump(d, open(pro, "w", encoding="utf-8"), indent=2)
print(f"via_drill: {n} via(s) 0.45/0.3 -> 0.45/0.2 -> {dst}")
