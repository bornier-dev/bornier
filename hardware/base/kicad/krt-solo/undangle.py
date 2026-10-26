"""Remove the tracks and vias a DRC report flags as dangling (router leftovers that end on nothing).
Run with the Python shipped with KiCad:  python.exe undangle.py IN.kicad_pcb DRC.json OUT.kicad_pcb
Run the DRC again after: a removal can leave the segment behind it dangling.  Nothing reads the board after the
removals (pcbnew segfaults)."""
import json
import os
import shutil
import sys

import pcbnew

src, report, dst = sys.argv[1:4]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
d = json.load(open(report, encoding="utf-8"))
ids = {i["uuid"] for v in d["violations"] if v["type"] in ("track_dangling", "via_dangling") for i in v["items"]}
b = pcbnew.LoadBoard(src)
doomed = [t for t in b.GetTracks() if t.m_Uuid.AsString() in ids]
for t in doomed:
    b.Remove(t)
b.Save(dst)
print(f"undangle: {len(doomed)}/{len(ids)} dangling track(s)/via(s) removed -> {dst}")
