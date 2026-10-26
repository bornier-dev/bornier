#!/usr/bin/env bash
# Laps 15-17 on final3b/11: the RXB_N leg that walls U4.60 in and the +3V3 stubs ripped, the RX pair's open leg laid
# again, the pair members left open routed single-ended, then the plane drops; each step audited.
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
"$k" "$here/rip.py" "$d/11.kicad_pcb" "$d/11b.kicad_pcb" via:59.8,53.3 via:61.4,53.8 via:64,56.4 \
    via:34,56 via:34,56.25 2>&1 | grep -v leak
s=$SECONDS
"$py" -X utf8 py_router/route_diff.py "$d/11b.kicad_pcb" "$d/15.kicad_pcb" --nets "/ESC/RX*" --track-width 0.2 \
    --diff-pair-gap 0.15 --clearance-ceiling 0.15 --escalation off --fab-tier standard --no-fix-drc-settings \
    > "$d/15.log" 2>&1 || echo "# 15 exit $?"
echo "# 15 done in $((SECONDS - s)) s"; grep -E "JSON_SUMMARY" "$d/15.log" | tail -1 | cut -c1-300
audit "$d/15.kicad_pcb"
s=$SECONDS
"$py" py_router/route.py "$d/15.kicad_pcb" "$d/16.kicad_pcb" --nets USB_DP /ESC/RXB_P /ESC/RXB_N "${base[@]}" \
    --json-out "$d/route16.json" --rip-existing-nets WDI DIR3 /MCU/SWDIO ENC3_B SPINDLE_PWM \
    --max-probe-iterations 20000 --max-ripup 5 > "$d/16.log" 2>&1 || echo "# 16 exit $?"
echo "# 16 done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by" "$d/16.log" | cut -c1-250
audit "$d/16.kicad_pcb"
s=$SECONDS
"$py" py_router/route.py "$d/16.kicad_pcb" "$d/17.kicad_pcb" --nets GND GNDISO +3V3 +5V +VIN "${base[@]}" \
    --json-out "$d/route17.json" > "$d/17.log" 2>&1 || echo "# 17 exit $?"
echo "# 17 done in $((SECONDS - s)) s"; grep -E "IMPROVEMENT GATE|broken by|connected by" "$d/17.log" | cut -c1-250
audit "$d/17.kicad_pcb"
