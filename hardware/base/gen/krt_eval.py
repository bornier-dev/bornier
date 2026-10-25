# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Trial of KiCadRoutingTools (https://github.com/drandyhaas/KiCadRoutingTools) on a routing stage.

Each run copies a stage of ../kicad/stages/ with the project files into ../kicad/stages/krt/<run>/, runs one
or more KiCadRoutingTools commands on it, then the KiCad DRC, and prints the same summary as route.py report,
next to the summary of the stage it started from:
    python krt_eval.py <run> <stage> -- <tool> [args] [-- <tool> [args] ...]
    python krt_eval.py <run> report          DRC summary of a run again
<stage> is a file name of ../kicad/stages/ without extension (8-short) or a path. <tool> is a script of
py_router/ without .py (route, route_diff, route_planes, ...); the board path is passed first, the output
overwrites it; route and route_diff get STRICT (exact sizes and clearances, standard fab floor, project
left as it is) unless --loose is among their args. A <tool> @name is a step of this script instead
(@barrier: the Modbus isolation barrier as a keep-out). Each command's output and time go to <run>/log.txt.
KiCadRoutingTools is not in the repository: KRT_DIR, or hardware/tools/KiCadRoutingTools, with the Python
of KRT_PYTHON, or hardware/tools/krt-venv.
"""

import collections
import glob
import json
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
KICAD = os.path.normpath(os.path.join(HERE, "..", "kicad"))
STAGES = os.path.join(KICAD, "stages")
RUNS = os.path.join(STAGES, "krt")
TOOLS = os.path.normpath(os.path.join(HERE, "..", "..", "tools"))
LIB = os.path.normpath(os.path.join(HERE, "..", "..", "lib")).replace("\\", "/")
KRT = os.environ.get("KRT_DIR", os.path.join(TOOLS, "KiCadRoutingTools"))
PY = os.environ.get("KRT_PYTHON", os.path.join(TOOLS, "krt-venv", "Scripts", "python.exe"))
CLI = "C:/Program Files/KiCad/10.0/bin/kicad-cli.exe"
KICAD_PY = "C:/Program Files/KiCad/10.0/bin/python.exe"
SUPPLIES = ["GND", "GNDISO", "+3V3", "+5V", "+VIN", "+VIN_OUT", "CHASSIS"]
# KiCadRoutingTools flags of every routing command: sizes and clearances exact, standard JLC floor, project untouched
STRICT = ["--escalation", "off", "--fab-tier", "standard", "--no-fix-drc-settings"]


def setup(run, stage):
    """A run directory, and the stage it starts from in <run>/start/ for its own DRC."""
    src = stage if os.path.isfile(stage) else os.path.join(STAGES, stage + ".kicad_pcb")
    d = os.path.join(RUNS, run)
    if os.path.exists(d):
        raise SystemExit(f"{d} exists: remove it or name another run")
    project(d, src)
    project(os.path.join(d, "start"), src)
    return d


def project(d, src):
    """The board as base.kicad_pcb, the project, its rules and schematic, libraries by absolute path."""
    os.makedirs(d)
    shutil.copyfile(src, os.path.join(d, "base.kicad_pcb"))
    for f in ["base.kicad_pro", "base.kicad_dru"] + [os.path.basename(s) for s in glob.glob(os.path.join(KICAD, "*.kicad_sch"))]:
        shutil.copyfile(os.path.join(KICAD, f), os.path.join(d, f))
    for table in ("fp-lib-table", "sym-lib-table"):
        text = open(os.path.join(KICAD, table), encoding="utf-8").read().replace("${KIPRJMOD}/../../lib", LIB)
        open(os.path.join(d, table), "w", encoding="utf-8").write(text)


def drc(pcb, refill=True):
    """DRC report of a board (json path), against our rules: KiCadRoutingTools rewrites the rules of the project
    beside the board it routes to the values it used, so the project and its rules are copied again first."""
    for f in ("base.kicad_pro", "base.kicad_dru"):
        shutil.copyfile(os.path.join(KICAD, f), os.path.join(os.path.dirname(pcb), f))
    rpt = pcb.replace(".kicad_pcb", "-drc.json")
    args = [CLI, "pcb", "drc", "--schematic-parity", "--severity-all", "--format", "json", "-o", rpt]
    if refill:
        args += ["--refill-zones"]
    subprocess.run(args + [pcb], capture_output=True)
    return rpt


def summary(rpt):
    """Violations by type, unconnected items, nets left unrouted."""
    d = json.load(open(rpt, encoding="utf-8"))
    nets = collections.Counter(re.sub(r"^.*\[(.*?)\].*$", r"\1", u["items"][0]["description"])
                               for u in d["unconnected_items"])
    types = collections.Counter(v["type"] for v in d["violations"])
    copper = sum(k for t, k in types.items() if not t.startswith("silk") and t not in ("lib_footprint_mismatch",))
    return {"violations": len(d["violations"]), "copper": copper, "unconnected": len(d["unconnected_items"]),
            "parity": len(d["schematic_parity"]), "types": types, "nets": nets}


def show(name, pcb):
    """The DRC summary, then the connections left open counted by pcbnew: the DRC report stops at 499."""
    s = summary(drc(pcb))
    print(f"{name}: violations {s['violations']} (non-silk {s['copper']}), parity {s['parity']}")
    print("   by type:", ", ".join(f"{t} {k}" for t, k in s["types"].most_common()))
    print(subprocess.run([KICAD_PY, os.path.abspath(__file__), "-", "count", pcb], capture_output=True,
                         text=True).stdout.rstrip())


def count(pcb):
    """Connections left open per net (islands of pads less one), zones filled, nothing saved; tracks and vias.
    Run with the Python shipped with KiCad."""
    import pcbnew
    b = pcbnew.LoadBoard(pcb)
    pcbnew.ZONE_FILLER(b).Fill(b.Zones())
    b.BuildConnectivity()
    c = b.GetConnectivity()
    parent = {}

    def root(k):
        while parent.setdefault(k, k) != k:
            parent[k] = parent[parent[k]]
            k = parent[k]
        return k
    for it in list(b.GetPads()) + list(b.GetTracks()) + list(b.Zones()):
        if it.GetNetCode() > 0:
            for o in c.GetConnectedItems(it):
                parent[root(it.m_Uuid.AsString())] = root(o.m_Uuid.AsString())
    islands = collections.defaultdict(set)
    for p in b.GetPads():
        if p.GetNetCode() > 0:
            islands[p.GetNetname()].add(root(p.m_Uuid.AsString()))
    nets = collections.Counter({n: len(v) - 1 for n, v in islands.items() if len(v) > 1})
    tracks = list(b.GetTracks())
    vias = sum(1 for t in tracks if t.GetClass() == "PCB_VIA")
    print(f"   open: {sum(nets.values())} connection(s) over {len(nets)} net(s); {len(tracks) - vias} track(s), {vias} via(s)")
    print("   supplies:", ", ".join(f"{n} {nets.get(n, 0)}" for n in SUPPLIES))
    print("   nets open:", ", ".join(f"{n} {k}" for n, k in nets.most_common(40)))


def barrier(pcb):
    """The Modbus isolation barrier in the form KiCadRoutingTools reads: it skips the clearance rule between net
    lists, so a rule area on the isolated ground island, and a rule of the run's .kicad_dru that keeps the tracks
    and vias of the other nets out of it. Run with the Python shipped with KiCad."""
    import pcbnew
    dru = os.path.join(os.path.dirname(pcb), "base.kicad_dru")
    text = open(dru, encoding="utf-8").read()
    rule = re.search(r'\(rule "Modbus isolation barrier".*?\n\t\(constraint', text, re.S).group(0)
    iso = sorted(set(re.findall(r"A\.NetName == '([^']+)'", rule)))
    b = pcbnew.LoadBoard(pcb)
    island = next(z for z in b.Zones() if not z.GetIsRuleArea() and z.GetNetname() == "GNDISO")
    area = pcbnew.ZONE(b)
    area.SetIsRuleArea(True)
    area.SetZoneName("modbus barrier")
    area.SetLayerSet(pcbnew.LSET.AllCuMask())
    for keep in (area.SetDoNotAllowTracks, area.SetDoNotAllowVias, area.SetDoNotAllowPads,
                 area.SetDoNotAllowZoneFills, area.SetDoNotAllowFootprints):
        keep(False)
    area.Outline().AddOutline(island.Outline().Outline(0))
    b.Add(area)
    b.Save(pcb)
    names = " || ".join(f"A.NetName == '{n}'" for n in iso)
    open(dru, "a", encoding="utf-8").write(
        '\n(rule "modbus barrier: the other nets out of the isolated island"\n'
        f"\t(condition \"A.intersectsArea('modbus barrier') && !({names})\")\n"
        "\t(constraint disallow track via))\n")
    print(f"barrier: rule area on the GNDISO island, {len(iso)} net(s) allowed in")


def run_tools(d, commands):
    pcb = os.path.join(d, "base.kicad_pcb")
    log = open(os.path.join(d, "log.txt"), "a", encoding="utf-8")
    for tool, *args in commands:
        if tool.startswith("@"):            # a step of this script on the run's board, with the Python of KiCad
            r = subprocess.run([KICAD_PY, os.path.abspath(__file__), "-", tool[1:], pcb], capture_output=True, text=True)
            log.write(f"$ {tool}\n{r.stdout}{r.stderr}")
            print(r.stdout.rstrip() or r.stderr.rstrip(), flush=True)
            if r.returncode:
                break
            continue
        cmd = [PY, os.path.join(KRT, "py_router", tool + ".py"), pcb] + args
        if tool in ("route", "route_diff", "route_planes", "repair_planes"):
            cmd += ["--overwrite"]
        if tool in ("route", "route_diff") and "--loose" not in args:
            cmd += STRICT
        cmd = [a for a in cmd if a != "--loose"]
        log.write("$ " + " ".join(cmd) + "\n")
        log.flush()
        t = time.time()
        r = subprocess.run(cmd, cwd=d, stdout=log, stderr=subprocess.STDOUT)
        dt = time.time() - t
        log.write(f"# exit {r.returncode}, {dt:.0f} s\n")
        log.flush()
        print(f"{tool} {' '.join(args)}: exit {r.returncode}, {dt:.0f} s", flush=True)
        if r.returncode:
            print(f"   see {os.path.join(d, 'log.txt')}")
            break


def main():
    argv = sys.argv[1:]
    if argv[:1] == ["-"]:
        return {"count": count, "barrier": barrier}[argv[1]](argv[2])
    if len(argv) < 2:
        raise SystemExit(__doc__)
    run, stage = argv[0], argv[1]
    d = os.path.join(RUNS, run)
    if stage == "report":
        return show(run, os.path.join(d, "base.kicad_pcb"))
    commands, cur = [], None
    for a in argv[2:]:
        if a == "--":
            cur = []
            commands.append(cur)
        else:
            cur.append(a)
    commands = [c for c in commands if c]
    d = setup(run, stage)
    run_tools(d, commands)
    show("start", os.path.join(d, "start", "base.kicad_pcb"))
    show(run, os.path.join(d, "base.kicad_pcb"))


if __name__ == "__main__":
    main()
