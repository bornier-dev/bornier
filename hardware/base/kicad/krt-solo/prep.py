"""The input of the KRT-only run: the board of the branch without any copper laid by our passes.

Tracks, vias and copper zones go (the planes are drawn from our placement); the rule areas of the profile and
the C-LOCK stay. Run with the Python shipped with KiCad:
    python.exe prep.py ../base.kicad_pcb input.kicad_pcb
"""
import shutil
import sys

import pcbnew

src, dst = sys.argv[1], sys.argv[2]
b = pcbnew.LoadBoard(src)
# everything read before the first removal: a board that has lost items breaks the next calls of the API
for f in b.GetFootprints():
    f.SetLocked(False)
tracks = list(b.GetTracks())
zones = list(b.Zones())
kept = [z.GetZoneName() for z in zones if z.GetIsRuleArea()]
copper = [z for z in zones if not z.GetIsRuleArea()]
dropped = [f"{z.GetNetname()} on {z.GetLayerName()}" for z in copper]
for item in tracks + copper:
    b.Remove(item)
pcbnew.SaveBoard(dst, b)
for ext in (".kicad_pro", ".kicad_dru"):
    shutil.copyfile(src.replace(".kicad_pcb", ext), dst.replace(".kicad_pcb", ext))
print(f"{len(tracks)} tracks and vias removed; zones dropped: {dropped}; rule areas kept: {kept}")
