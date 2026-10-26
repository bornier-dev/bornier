"""The sanity audit of a step board, run before the next pass is launched: it catches what the router's own
counts do not show.
  * placement: pad density per 15 mm column and row, against the board mean (a placer that packs one side);
  * necks: runs of joined segments longer than NECK_MM (a pad-entry neck is shorter) laid narrower than their netclass width (a power net
    escalated down to the 0.09 mm floor, a 2 mm trunk feeding 0.09 mm branches);
  * plane nets: track length laid on the nets that have a copper zone (they should only drop vias to it);
  * floor: anything under the JLCPCB floor (track 0.09 mm, via 0.45 mm across).
Exit 1 when a check fails.  Run with the Python shipped with KiCad:  python.exe audit.py BOARD.kicad_pcb
"""
import collections
import fnmatch
import json
import sys

import pcbnew

COLUMN, DENSITY_MAX, NECK_MM, NECK_NET_MM, PLANE_MM_PER_PAD = 15.0, 1.6, 2.0, 5.0, 2.5

path = sys.argv[1]
b = pcbnew.LoadBoard(path)
to_mm = pcbnew.ToMM
pro = json.load(open(path[:-len(".kicad_pcb")] + ".kicad_pro", encoding="utf-8"))["net_settings"]
width = {c["name"]: c["track_width"] for c in pro["classes"]}
patterns = [(p["pattern"], p["netclass"]) for p in pro.get("netclass_patterns", [])]


def netclass(net):
    for pat, cls in patterns:
        if net == pat or fnmatch.fnmatchcase(net, pat):
            return cls
    return "Default"


fails, warns = [], []

# placement balance
edge = b.GetBoardEdgesBoundingBox()
x0, y0, w, h = to_mm(edge.GetLeft()), to_mm(edge.GetTop()), to_mm(edge.GetWidth()), to_mm(edge.GetHeight())
cols, rows = collections.Counter(), collections.Counter()
pads = 0
for fp in b.GetFootprints():
    for p in fp.Pads():
        q = p.GetPosition()
        cols[min(int((to_mm(q.x) - x0) // COLUMN), int(w // COLUMN))] += 1
        rows[min(int((to_mm(q.y) - y0) // COLUMN), int(h // COLUMN))] += 1
        pads += 1
for name, bins, span in (("column", cols, w), ("row", rows, h)):
    mean = pads / (span / COLUMN)
    worst = max(bins.values()) / mean
    line = " ".join(f"{bins[k]}" for k in range(int(span // COLUMN) + 1))
    msg = f"pads per {COLUMN:g} mm {name}: {line} (densest {worst:.2f}x the mean)"
    if worst > DENSITY_MAX:
        fails.append(msg)
    else:
        print(f"  ok    {msg}")

# copper
zone_nets = {z.GetNetname() for z in b.Zones() if not z.GetIsRuleArea() and z.GetNetname()}
neck = collections.defaultdict(float)
narrow = []
plane_len = collections.Counter()
under_floor = 0
vias = 0
for t in b.GetTracks():
    net = t.GetNetname()
    if t.GetClass() == "PCB_VIA":
        vias += 1
        if to_mm(t.GetWidth(pcbnew.F_Cu)) < 0.45 - 1e-6:
            under_floor += 1
        continue
    wmm, lmm = to_mm(t.GetWidth()), to_mm(t.GetLength())
    if wmm < 0.09 - 1e-6:
        under_floor += 1
    if net in zone_nets:
        plane_len[net] += lmm
    if wmm < width.get(netclass(net), 0.09) - 1e-6:
        narrow.append((net, t.GetLayer(), (t.GetStart().x, t.GetStart().y), (t.GetEnd().x, t.GetEnd().y), lmm))
# a neck is a run of narrow segments joined end to end: the router lays a long one as many short steps
parent = {}


def root(k):
    while parent.setdefault(k, k) != k:
        parent[k] = parent[parent[k]]
        k = parent[k]
    return k


for net, layer, s, e, _ in narrow:
    parent[root((net, layer, s))] = root((net, layer, e))
runs = collections.Counter()
for net, layer, s, _, lmm in narrow:
    runs[root((net, layer, s))] += lmm
worst_runs = sorted(((v, k[0], b.GetLayerName(k[1]), k[2]) for k, v in runs.items() if v > NECK_MM), reverse=True)
for v, net, _, _ in worst_runs:
    neck[net] += v
neck = {n: v for n, v in neck.items() if v > NECK_NET_MM}  # one pad-entry neck at the limit is no fault
for v, net, layer, (px, py) in worst_runs[:12]:
    print(f"  info  neck run {net} {layer} {v:.1f} mm near {to_mm(px):.2f},{to_mm(py):.2f} ({netclass(net)} {width.get(netclass(net))})")
if neck:
    top = sorted(neck.items(), key=lambda kv: -kv[1])
    fails.append(f"necks: {sum(neck.values()):.0f} mm over {len(neck)} net(s) narrower than their class, "
                 + ", ".join(f"{n} {v:.0f} mm ({netclass(n)} {width.get(netclass(n))})" for n, v in top[:8]))
else:
    print("  ok    necks: no net carries over 5 mm of runs over 2 mm narrower than its netclass")
pad_count = collections.Counter(p.GetNetname() for fp in b.GetFootprints() for p in fp.Pads())
for net in sorted(zone_nets):
    per_pad = plane_len[net] / max(pad_count[net], 1)
    msg = f"plane net {net}: {plane_len[net]:.0f} mm of track for {pad_count[net]} pad(s) ({per_pad:.1f} mm/pad)"
    if per_pad > PLANE_MM_PER_PAD:
        warns.append(msg)
    else:
        print(f"  ok    {msg}")
if under_floor:
    fails.append(f"floor: {under_floor} track(s)/via(s) under 0.09 mm / 0.45 mm")
print(f"  info  {vias} via(s)")
for m in warns:
    print(f"  WARN  {m}")
for m in fails:
    print(f"  FAIL  {m}")
sys.exit(1 if fails else 0)
