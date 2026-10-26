#!/usr/bin/env bash
# Laps 12-14 on final3b: the two pairs laid again whole, then the +3V3 and +VIN plane drops; each step audited.
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
"$k" "$here/rip.py" "$d/11.kicad_pcb" "$d/11r.kicad_pcb" net:USB_DP net:USB_DM net:/ESC/RXB_P net:/ESC/RXB_N \
    via:34,56 via:34,56.25 2>&1 | grep -v leak
s=$SECONDS
"$py" -X utf8 py_router/route_diff.py "$d/11r.kicad_pcb" "$d/12.kicad_pcb" --nets "/ESC/RX*" --track-width 0.2 \
    --diff-pair-gap 0.15 --clearance-ceiling 0.15 --escalation off --fab-tier standard --no-fix-drc-settings \
    > "$d/12.log" 2>&1 || echo "# 12 exit $?"
echo "# 12 done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by|routed .* pair|FAILED" "$d/12.log" | head -8 | cut -c1-250
audit "$d/12.kicad_pcb"
s=$SECONDS
"$py" -X utf8 py_router/route_diff.py "$d/12.kicad_pcb" "$d/13.kicad_pcb" --nets "USB_D*" --track-width 0.265 \
    --diff-pair-gap 0.15 --clearance-ceiling 0.15 --escalation off --fab-tier standard --no-fix-drc-settings \
    > "$d/13.log" 2>&1 || echo "# 13 exit $?"
echo "# 13 done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by|routed .* pair|FAILED" "$d/13.log" | head -8 | cut -c1-250
audit "$d/13.kicad_pcb"
s=$SECONDS
"$py" py_router/route.py "$d/13.kicad_pcb" "$d/14.kicad_pcb" --nets GND GNDISO +3V3 +5V +VIN \
    --clearance 0.125 --grid-step 0.05 --layers F.Cu In1.Cu In2.Cu B.Cu --layer-costs 1.0 3.0 1.5 1.0 \
    --power-nets GND GNDISO +3V3 +5V +VIN +VIN_OUT --power-nets-widths 0.25 0.25 0.25 0.25 0.25 0.25 \
    --same-net-pad-clearance 0.1 --escalation off --fab-tier standard --no-fix-drc-settings \
    --json-out "$d/route14.json" > "$d/14.log" 2>&1 || echo "# 14 exit $?"
echo "# 14 done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by" "$d/14.log" | cut -c1-250
audit "$d/14.kicad_pcb"
