"""Rip copper the next route step must lay again:  python.exe rip.py IN OUT ITEM...
  net:NAME   every track and via of that net
  via:X,Y    the via at X,Y (mm, within 0.05 mm), with the tracks that end on it
Run with the Python shipped with KiCad. Nothing reads the board after the removals (pcbnew segfaults)."""
import os
import shutil
import sys

import pcbnew

src, dst, *items = sys.argv[1:]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-10] + ext):
            shutil.copyfile(src[:-10] + ext, dst[:-10] + ext)
b = pcbnew.LoadBoard(src)
mm = pcbnew.FromMM
nets = {i[4:] for i in items if i.startswith("net:")}
spots = [tuple(mm(float(v)) for v in i[4:].split(",")) for i in items if i.startswith("via:")]
tol = mm(0.05)
doomed = []
for t in b.GetTracks():
    if t.GetNetname() in nets:
        doomed.append(t)
        continue
    for x, y in spots:
        ends = [t.GetPosition()] if t.GetClass() == "PCB_VIA" else [t.GetStart(), t.GetEnd()]
        if any(abs(e.x - x) <= tol and abs(e.y - y) <= tol for e in ends):
            doomed.append(t)
            break
n = len(doomed)
for t in doomed:
    b.Remove(t)
b.Save(dst)
print(f"rip: {n} track(s)/via(s) removed -> {dst}")
