"""Widen the classed nets' segments the router laid narrower than their netclass (a power net stepped down to the
0.09 mm floor to slip through), each to the widest width from its class width down that keeps every other net's
copper at the netclass clearance (and the board edge at EDGE_GAP).  Run it on the finished board, then DRC it.
Run with the Python shipped with KiCad:  python.exe widen.py IN.kicad_pcb OUT.kicad_pcb"""
import collections
import fnmatch
import json
import os
import shutil
import sys

import pcbnew

EDGE_GAP, MARGIN, STEP, CELL = 0.2, 0.01, 0.02, 1.0

src, dst = sys.argv[1], sys.argv[2]
if os.path.abspath(src) != os.path.abspath(dst):
    for ext in (".kicad_pro", ".kicad_prl", ".kicad_dru", ".design-brief.json"):
        if os.path.exists(src[:-len(".kicad_pcb")] + ext):
            shutil.copyfile(src[:-len(".kicad_pcb")] + ext, dst[:-len(".kicad_pcb")] + ext)
b = pcbnew.LoadBoard(src)
mm, to_mm = pcbnew.FromMM, pcbnew.ToMM
pro = json.load(open(src[:-len(".kicad_pcb")] + ".kicad_pro", encoding="utf-8"))["net_settings"]
classes = {c["name"]: c for c in pro["classes"]}
patterns = [(p["pattern"], p["netclass"]) for p in pro.get("netclass_patterns", [])]


def netclass(net):
    for pat, cls in patterns:
        if net == pat or fnmatch.fnmatchcase(net, pat):
            return cls
    return "Default"


def clearance(net):
    return classes.get(netclass(net), classes["Default"]).get("clearance", classes["Default"]["clearance"])


# every other-net obstacle, bucketed by layer and CELL mm square
grid = collections.defaultdict(list)


def cells(bb, grow):
    g = mm(grow)
    for i in range(int(to_mm(bb.GetLeft() - g) // CELL), int(to_mm(bb.GetRight() + g) // CELL) + 1):
        for j in range(int(to_mm(bb.GetTop() - g) // CELL), int(to_mm(bb.GetBottom() + g) // CELL) + 1):
            yield i, j


cu_layers = [l for l in range(pcbnew.PCB_LAYER_ID_COUNT) if pcbnew.IsCopperLayer(l) and b.IsLayerEnabled(l)]
items = []
for fp in b.GetFootprints():
    for p in fp.Pads():
        for l in cu_layers:
            if p.IsOnLayer(l):
                items.append((p, l, p.GetNetname()))
for t in b.GetTracks():
    if t.GetClass() == "PCB_VIA":
        for l in cu_layers:
            if t.IsOnLayer(l):
                items.append((t, l, t.GetNetname()))
    else:
        items.append((t, t.GetLayer(), t.GetNetname()))
for k, (it, l, net) in enumerate(items):
    for c in cells(it.GetBoundingBox(), 0):
        grid[(l, c)].append(k)
edges = [d for d in b.GetDrawings() if d.GetLayer() == pcbnew.Edge_Cuts]

targets = []
for t in b.GetTracks():
    if t.GetClass() == "PCB_VIA":
        continue
    cls = netclass(t.GetNetname())
    if cls != "Default" and to_mm(t.GetWidth()) < classes[cls]["track_width"] - 1e-6:
        targets.append(t)
done, gained = collections.Counter(), collections.Counter()
for t in targets:
    net, layer, old = t.GetNetname(), t.GetLayer(), t.GetWidth()
    want = classes[netclass(net)]["track_width"]
    w = want
    while w > to_mm(old) + 1e-6:
        t.SetWidth(mm(w))
        shape = t.GetEffectiveShape(layer)
        bb = t.GetBoundingBox()
        ok = True
        seen = set()
        for c in cells(bb, 1.0):
            for k in grid.get((layer, c), ()):
                if k in seen:
                    continue
                seen.add(k)
                it, _, other = items[k]
                if other == net or it is t:
                    continue
                gap = mm(max(clearance(net), clearance(other)) + MARGIN)
                if shape.Collide(it.GetEffectiveShape(layer), gap):
                    ok = False
                    break
            if not ok:
                break
        if ok:
            for d in edges:
                if shape.Collide(d.GetEffectiveShape(), mm(EDGE_GAP + MARGIN)):
                    ok = False
                    break
        if ok:
            done[net] += 1
            gained[net] += to_mm(t.GetLength())
            break
        w = round(w - STEP, 3)
    else:
        t.SetWidth(old)
b.Save(dst)
print(f"widen: {sum(done.values())}/{len(targets)} narrow classed segment(s) widened -> {dst}")
for net in sorted(done, key=lambda n: -gained[n])[:12]:
    print(f"  {net}: {done[net]} segment(s), {gained[net]:.1f} mm")
