#!/usr/bin/env bash
# Full route of one placed seed with a judge chain (no --quick), each step's board in OUT/.
#   bash full_route.sh SEED [RUN_DIR] [CHAIN] [OUT_DIR]      e.g.  bash full_route.sh 11 run judge_chain.txt final
set -e
export MSYS2_ARG_CONV_EXCL='*'
here=$(cd "$(dirname "$0")" && pwd -W)
seed=$1
run=$here/${2:-run}
chain=$here/${3:-judge_chain.txt}
out=$here/${4:-final}
krt=$here/../../../tools/KiCadRoutingTools
py=$here/../../../tools/krt-venv/Scripts/python.exe
mkdir -p "$out"
# FROM=<dir>/<n> starts from that step board instead of the placed seed (a resumed chain)
from=${FROM:-$run/s$seed}
for ext in kicad_pcb kicad_pro kicad_prl kicad_dru design-brief.json; do
    cp "$from.$ext" "$out/0_placed.$ext"
done
cd "$krt"
prev=$out/0_placed.kicad_pcb
n=0
while IFS= read -r line; do
    [ -z "$line" ] && continue
    n=$((n + 1))
    next=$out/$n.kicad_pcb
    cmd=${line//\{in\}/$prev}
    cmd=${cmd//\{out\}/$next}
    cmd=${cmd//\{dir\}/$out}
    cmd=${cmd//\{run\}/$run}
    cmd=${cmd/#python /\"$py\" }
    echo "# step $n: $cmd" | cut -c1-200
    start=$SECONDS
    eval "$cmd" > "$out/$n.log" 2>&1 || { echo "# step $n exit $? (see $out/$n.log)"; exit 1; }
    echo "# step $n done in $((SECONDS - start)) s"
    # the audit of every step: a neck or a size under the fab floor stops the chain before the next pass
    "C:/Program Files/KiCad/10.0/bin/python.exe" "$here/audit.py" "$next" 2>&1 | grep -v "memory leak" > "$out/$n.audit"
    grep -h "WARN\|FAIL" "$out/$n.audit" | grep -v "pads per" | sed "s/^/# step $n /" | cut -c1-200
    if grep -q "FAIL  necks\|FAIL  floor" "$out/$n.audit"; then echo "# step $n failed its audit"; exit 1; fi
    prev=$next
done < "$chain"
echo "# routed board: $prev"
