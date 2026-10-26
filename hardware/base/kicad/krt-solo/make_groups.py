"""The groups file of the KRT run: the schematic sheets, split by function where a sheet holds several.
Run with the Python shipped with KiCad:  python.exe make_groups.py fixed.kicad_pcb groups.json"""
import collections
import json
import sys

import pcbnew

board = pcbnew.LoadBoard(sys.argv[1])
sheet = {f.GetReference(): f.GetSheetname() for f in board.GetFootprints()}
by_sheet = collections.defaultdict(list)
for r, s in sheet.items():
    if not r.startswith("H"):          # the holes are locked and serve no group
        by_sheet[s].append(r)

MODBUS_BUS = ["J13", "D66", "JP5", "R242", "R243", "R244", "R245", "R246", "C84", "C85", "C86"]
USB = ["J2", "U2"]
BUCK5 = ["U1", "C2", "C3", "C4", "D3", "L1", "C5", "R3", "R301", "R6", "C7", "C312", "R5", "R302", "R4", "R303",
         "R1", "R2", "R300", "R308"]
BUCK3 = ["U3", "L2", "C9", "C10", "C300", "R9", "R10", "D4", "TP7", "Q11", "D5", "R310", "R311"]
ENTRY = ["J1", "F1", "D1", "D2", "C1", "C301", "C302"]
PROBE = ["U29", "D56", "D57", "R184", "R185", "R186"]
DRIVE_SUPPLY = ["U10", "C53", "C54", "C55", "C74", "R54", "R55"]
JACK = {k: f"J{6 + k}" for k in range(4)}
RECEIVER = {0: "U22", 1: "U24", 2: "U26", 3: "U28"}

groups = []


def group(name, role, refs, anchor, near=(), why="", **extra):
    groups.append({"name": name, "role": role, "refs": sorted(refs), "anchor": anchor, "near": list(near),
                   "why": why, **extra})


for k in range(4):
    group(f"drive {k}", "interface", by_sheet[f"/Drive {k}/"], JACK[k], [f"encoder {k}", "mcu"],
          f"axis {k}: the step/dir line drivers, alarm input and enable output of drive port A of {JACK[k]}")
    group(f"encoder {k}", "interface", by_sheet[f"/Encoder {k}/"], RECEIVER[k], [f"drive {k}", "mcu"],
          f"axis {k}: the RS-422 receiver of encoder port B of {JACK[k]}, with its terminations, its switched "
          f"encoder supply and its jumper")
group("esc", "core", by_sheet["/ESC/"] + by_sheet["/Clock/"], "U4", ["mcu"],
      "the LAN9253 EtherCAT slave controller with its decaps, PHY terminations, ESD arrays and the two magjacks J3 "
      "(IN) and J4 (OUT); the 25 MHz oscillator X1 of the Clock sheet, which clocks it first")
RESET = ["U40", "D71", "R253"]
group("mcu", "core", [r for r in by_sheet["/MCU/"] if r not in USB] + RESET, "U9", ["esc", "usb", "local bus"],
      "the STM32H563 with its decaps, VCAP, VDDA filter, OCTOSPI series terminations, boot button, LEDs and the "
      "Tag-Connect J5; the reset supervisor U40 and its reset LED (NRST and WDI are MCU pins)")
group("usb", "interface", USB, "J2", ["mcu", "buck 3v3"],
      "the micro-B jack (bench power and DFU) with its ESD array, lines flowing through")
group("local bus", "interface", by_sheet["/Local bus/"], "J10", ["mcu"],
      "the 2x17 ribbon header with its ESD arrays, series resistors, buffers and the switched 3.3 V of the bus")
group("modbus logic side", "interface", [r for r in by_sheet["/Modbus/"] if r not in MODBUS_BUS], "U38",
      ["modbus bus side", "mcu"], "the isolated transceiver U38, its logic-side decaps, the DE pull-down and the "
      "TX/RX LEDs")
group("modbus bus side", "interface", MODBUS_BUS, "J13", ["modbus logic side"],
      "the isolated side of the RS-485 port: terminal block, line protection, termination jumper, fail-safe "
      "resistors and the isolated supply caps of U38 (its own zone in the intent)")
group("spindle", "interface", by_sheet["/Spindle/"], "U36", ["mcu"],
      "the 0-10 V output and the enable / direction / PWM outputs of the two spindle terminal blocks J11 and J12")
group("safety", "interface", [r for r in by_sheet["/Safety/"] if r not in ENTRY + RESET], "J14",
      ["mcu", "probe"], "the ESTOP input optocoupler and its LED; J14 carries ESTOP and PROBE")
group("probe", "interface", PROBE, "U29", ["safety"], "the probe input optocoupler and its LED, input of J14")
group("drive supply", "power", DRIVE_SUPPLY, "U10", ["power entry"],
      "the current-limited high-side switch of +VIN_OUT, the supply of the drives and terminal blocks")
group("power entry", "power", ENTRY, "J1", ["buck 5v", "drive supply"],
      "the POWER terminal block, fuse, TVS, reverse diode and bulk capacitor; the two GND-to-chassis capacitors "
      "of the chassis hole H1 and the PE contact H5, in this corner")
group("buck 5v", "power", BUCK5, "U1", ["power entry", "buck 3v3"],
      "the TPS54360B 24 V to 5 V buck with its input caps, boot cap, catch diode, inductor, output cap, RT, "
      "compensation and feedback parts", templates=[{"chip": "U1", "kind": "switching stage",
                                                      "why": "TPS54360B non-synchronous buck; datasheet layout figure"}])
group("buck 3v3", "power", BUCK3, "U3", ["buck 5v"],
      "the TPS62A02 5 V to 3.3 V buck with its input cap, inductor, output caps and divider; the VBUS ideal-diode "
      "path (Q11, D5) and the 5 V diode D4 that feed it", templates=[{"chip": "U3", "kind": "switching stage",
                                                                      "why": "TPS62A02 synchronous buck; datasheet layout example"}])
rest = [r for r in by_sheet["/Power/"] if r not in BUCK5 + BUCK3 + ENTRY]
group("power monitor", "power", rest, "R11", ["power entry"],
      "the supply monitoring divider, the rail test points and the power LEDs")

seen = collections.Counter(r for g in groups for r in g["refs"])
missing = [r for r in sheet if not r.startswith("H") and r not in seen]
twice = [r for r, n in seen.items() if n > 1]
if missing or twice:
    raise SystemExit(f"missing {missing}, twice {twice}")
json.dump({"schema": 1, "board": "fixed.kicad_pcb", "groups": groups}, open(sys.argv[2], "w", encoding="utf-8"),
          indent=1, ensure_ascii=False)
print(f"{len(groups)} groups, {sum(seen.values())} parts -> {sys.argv[2]}")
