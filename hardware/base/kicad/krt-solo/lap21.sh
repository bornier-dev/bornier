#!/usr/bin/env bash
# Laps 21-23 on final3b/20: USB_DM ripped so USB_DP gets out of U9.71 first, then USB_DM, then the plane drops.
set -e
export MSYS2_ARG_CONV_EXCL='*'
here=$(cd "$(dirname "$0")" && pwd -W)
d=$here/final3b
k="C:/Program Files/KiCad/10.0/bin/python.exe"
py=$here/../../../tools/krt-venv/Scripts/python.exe
cd "$here/../../../tools/KiCadRoutingTools"
audit() {
    "$k" "$here/audit.py" "$1" 2>&1 | grep -v "memory leak" | grep -E "WARN|FAIL" | grep -v "pads per\|necks" || true
}
base=(--clearance 0.125 --grid-step 0.05 --layers F.Cu In1.Cu In2.Cu B.Cu --layer-costs 1.0 3.0 1.5 1.0
      --power-nets GND GNDISO +3V3 +5V +VIN +VIN_OUT --power-nets-widths 0.25 0.25 0.25 0.25 0.25 0.25
      --same-net-pad-clearance 0.1 --escalation off --fab-tier standard --no-fix-drc-settings)
step() {  # step N IN log-label route.py-args...
    local n=$1 in=$2; shift 2
    local s=$SECONDS
    "$py" py_router/route.py "$in" "$d/$n.kicad_pcb" "$@" "${base[@]}" --json-out "$d/route$n.json" \
        > "$d/$n.log" 2>&1 || echo "# $n exit $?"
    echo "# $n done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by" "$d/$n.log" | cut -c1-250
    audit "$d/$n.kicad_pcb"
}
"$k" "$here/rip.py" "$d/20.kicad_pcb" "$d/20r.kicad_pcb" net:USB_DM 2>&1 | grep -v leak
step 21 "$d/20r.kicad_pcb" --nets USB_DP /ESC/VDD33BIAS --rip-existing-nets /MCU/SWDIO ENC2_B BUS_CS11 ENC3_A \
    --max-probe-iterations 20000 --max-ripup 5
step 22 "$d/21.kicad_pcb" --nets USB_DM --rip-existing-nets /MCU/SWDIO ENC2_B BUS_CS11 ENC3_A WDI \
    --max-probe-iterations 20000 --max-ripup 5
step 23 "$d/22.kicad_pcb" --nets GND GNDISO +3V3 +5V +VIN
