"""A scoped retry lap from a route.json, per the diagnose-routing-failures skill:
the open nets, the poured nets, a finer grid, and authority to rip the nets that wall them in.
   python retry.py ROUTE_JSON IN OUT DIR [extra route.py args...]   -> prints the command line
With `--escalation board` among the extra args the lap keeps to the Default class, for the nets it routes and the
ones it rips: the escalation has one floor for the whole board (0.09 mm), so a power, Ethernet or USB net in
scope would come out necked to it."""
import fnmatch
import json
import shlex
import sys

POURED = ["GND", "GNDISO", "+3V3", "+5V", "+VIN"]
src, inp, out, dirr, *extra = sys.argv[1:]
d = json.load(open(src, encoding="utf-8"))
opens = [r["net"] for r in d.get("pad_pairs_open", {}).get("nets", [])] if isinstance(d.get("pad_pairs_open"), dict) \
    else [r["net"] for r in d.get("pad_pairs_open", [])]
nets = sorted(set(opens) | set(d.get("failed_single", [])))
rip = sorted({b["net"] for r in d.get("blockers", []) for b in r["blocked_by"]} - set(nets) - set(POURED))
poured = POURED
if "board" in extra and extra[extra.index("board") - 1] == "--escalation":
    pro = json.load(open(inp[:-len(".kicad_pcb")] + ".kicad_pro", encoding="utf-8"))["net_settings"]
    patterns = [p["pattern"] for p in pro.get("netclass_patterns", [])]

    def classed(n):
        return n in POURED or any(n == p or fnmatch.fnmatchcase(n, p) for p in patterns)

    held = sorted(n for n in nets if classed(n) and n not in POURED)
    if held:
        print(f"# kept out of the escalation (not Default class): {' '.join(held)}", file=sys.stderr)
    nets = [n for n in nets if not classed(n)]
    rip = [n for n in rip if not classed(n)]
    poured = []
cmd = ["py_router/route.py", inp, out, "--nets", *nets, *poured,
       "--clearance", "0.125", "--grid-step", "0.05",
       "--layers", "F.Cu", "In1.Cu", "In2.Cu", "B.Cu", "--layer-costs", "1.0", "3.0", "1.5", "1.0",
       "--power-nets", "GND", "GNDISO", "+3V3", "+5V", "+VIN", "+VIN_OUT",
       "--power-nets-widths", "0.25", "0.25", "0.25", "0.25", "0.25", "0.25",
       "--same-net-pad-clearance", "0.1", "--escalation", "off", "--fab-tier", "standard", "--no-fix-drc-settings",
       "--json-out", f"{dirr}/route.json"]
if rip:
    cmd += ["--rip-existing-nets", *rip]
cmd += extra
print(f"# {len(nets)} open net(s), {len(rip)} rippable blocker(s)", file=sys.stderr)
print(" ".join(shlex.quote(c) for c in cmd))
