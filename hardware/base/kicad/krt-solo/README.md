# KiCadRoutingTools run on the base board

A full route of the base board (522 parts, 429 nets, 4 layers, 150 x 107.5 mm) with KiCadRoutingTools v0.23.7
alone, from placement to the fab files.  Only the scripts, the placed seed, the final board and its fab export are
kept; the step boards in between are not.

## Result

`final4/c33.kicad_pcb`: KiCad DRC with the board's own rules (JLCPCB floors 0.09/0.09, via 0.45/0.2, Modbus
isolation barrier, chassis clearance 1 mm): **0 errors, 0 unconnected items, nothing dangling** (silkscreen and
library warnings only).  `final4/fab/gerber.zip` is accepted by the JLCPCB quote (4 layers, 107.5 x 150 mm); it
needs the 0.2 mm via option (and with it the 4-wire Kelvin test and TG155) and epoxy filled and capped vias for the
two vias in pads (C310.2, U36.4).

## Flow

1. Placement: `run2n/s10` (py_placer seed judged best on floorplan errors, then blocking).
2. `full_route.sh` with `chain3.txt`: plane drops, isolation barrier, halos, via drill, the Ethernet and USB pairs,
   QFN fanouts, two `route.py '*'` passes.  `audit.py` runs after every step and stops the chain on a neck or a size
   under the fab floor.
3. Scoped retry laps on the open nets (`retry.py`, `lap*.sh`): the router's escalation only on Default-class nets
   (one board-wide floor would neck power, Ethernet and USB nets to 0.09 mm); neighbours ripped whole when a pin's
   escape is walled in; pair members laid single-ended where the pair router cannot (USB full speed, 6 mm on RXB).
4. `edge_halo.py`: keep-out around the inner board cutout (the router keeps its edge clearance off the outline only).
5. Finish: `widen.py` (classed nets laid narrower than their class widened to the widest width that keeps clearance),
   `strip_halos.py`, `check_board.sh` + `undangle.py` until nothing dangles, `export_fab.sh`.

## Lessons

* Audit every step before the next pass: router counts do not show necks, a packed side or planes fed by tracks.
* A neck is a run of joined segments, not one segment: the router lays a long thin track as many 0.05 mm steps.
* Ripping a pair whole also removes its QFN fanout, which the pair router does not lay again: rip only the leg.
* The placer's congestion model counts every copper layer as routing supply; here two of the four are planes.
* One routing process at a time: a 0.025 mm grid on this board runs out of memory.
