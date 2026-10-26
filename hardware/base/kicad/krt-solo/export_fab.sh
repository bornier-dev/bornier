#!/usr/bin/env bash
# Gerbers + drill of a board, zipped for the JLCPCB quote:  bash export_fab.sh BOARD.kicad_pcb OUT_DIR
set -e
cli="C:/Program Files/KiCad/10.0/bin/kicad-cli.exe"
board=$1
out=$2
rm -rf "$out"
mkdir -p "$out/gerber"
"$cli" pcb export gerbers --layers F.Cu,In1.Cu,In2.Cu,B.Cu,F.Paste,B.Paste,F.Silkscreen,B.Silkscreen,F.Mask,B.Mask,Edge.Cuts \
    --subtract-soldermask --use-drill-file-origin -o "$out/gerber/" "$board"
"$cli" pcb export drill --format excellon --excellon-separate-th --excellon-units mm --drill-origin plot \
    --generate-map --map-format gerberx2 -o "$out/gerber/" "$board"
(cd "$out/gerber" && powershell -NoProfile -Command "Compress-Archive -Path * -DestinationPath ../gerber.zip -Force")
ls -la "$out"
