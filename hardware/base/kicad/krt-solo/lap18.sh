#!/usr/bin/env bash
# Laps 18-20 on final3b/17: the RXB members alone with no rip, then USB laid again single-ended (full speed, a 10 mm
# uncoupled run is harmless) with its walls rippable, then the plane drops; each step audited.
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
step 18 "$d/17.kicad_pcb" --nets /ESC/RXB_P /ESC/RXB_N --max-probe-iterations 20000
"$k" "$here/rip.py" "$d/18.kicad_pcb" "$d/18r.kicad_pcb" net:USB_DM net:USB_DP 2>&1 | grep -v leak
step 19 "$d/18r.kicad_pcb" --nets USB_DP USB_DM --rip-existing-nets ENC2_B BUS_CS11 ENC3_A WDI \
    --max-probe-iterations 20000 --max-ripup 5
step 20 "$d/19.kicad_pcb" --nets GND GNDISO +3V3 +5V +VIN
