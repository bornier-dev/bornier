#!/usr/bin/env bash
# The fab check of a routed step board: pair names back, KiCad DRC with the board's rules (zones refilled), tally.
#   bash check_board.sh STEP.kicad_pcb NAME      -> NAME.kicad_pcb (+ siblings) and NAME.drc.json beside STEP
set -e
here=$(cd "$(dirname "$0")" && pwd -W)
cli="C:/Program Files/KiCad/10.0/bin/kicad-cli.exe"
src=$1
dir=$(dirname "$src")
base=${src%.kicad_pcb}
for e in kicad_pcb kicad_pro kicad_prl kicad_dru; do cp "$base.$e" "$dir/$2.$e"; done
"$here/../../../tools/krt-venv/Scripts/python.exe" "$here/rename_pairs.py" from-krt "$dir/$2.kicad_pcb" > /dev/null
"$cli" pcb drc --refill-zones --save-board --format json --severity-all -o "$dir/$2.drc.json" "$dir/$2.kicad_pcb" > /dev/null 2>&1 || true
python - "$dir/$2.drc.json" <<'EOF'
import collections, json, re, sys
d = json.load(open(sys.argv[1], encoding="utf-8"))
c = collections.Counter((v["severity"], v["type"]) for v in d["violations"])
for (sev, typ), n in sorted(c.items()):
    print(f"  {sev:8} {typ:28} {n}")
u = d["unconnected_items"]
nets = sorted({m.group(1) for v in u for i in v["items"][:1] for m in [re.search(r"\[([^\]]+)\]", i["description"])] if m})
print(f"  unconnected {len(u)} over {len(nets)} net(s): {' '.join(nets)}")
print(f"  errors {sum(n for (s, _), n in c.items() if s == 'error')}")
EOF
