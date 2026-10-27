# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Net classes of the base board, and saving the board without losing the project settings.

Outside KiCad, SaveBoard rewrites base.kicad_pro from the board alone: the schematic settings (ERC pin
map, severities, sheets) go, and the net classes fall back to the default one. save() puts both back.

Widths from the currents of the rails (IPC-2221, outer copper 1 oz, 10 degC rise); the bulk of the
current flows in the planes of layers 2 (GND) and 3 (supplies), so the rail tracks are short stubs.
Tracks and clearances at the JLCPCB multilayer minimum, 0.09 mm (IPC-2221 B2 asks 0.1 mm for uncoated
external conductors up to 30 V: under solder mask, 0.09 mm holds); 1 mm between the chassis and everything
else (ESD on the connector shields). Vias of VIA, the smallest at no extra cost. Freerouting reads the
classes, not the .kicad_dru: every clearance it must keep is here.
"""
import copy
import json
import os

import pcbnew

MM = pcbnew.FromMM

# Signal via, diameter and drill, mm: JLCPCB charges extra below a 0.3 mm hole unless the diameter is 0.45 mm
# or more ("Min via hole size/diameter" of the quote); 0.45/0.3 is the size it recommends at no extra cost.
VIA = (0.45, 0.3)
CLASSES = {
    # name: (track width, clearance, via diameter, via drill), mm
    "Default": (0.09, 0.09, *VIA),       # 0.4 A
    "Input": (1.5, 0.2, 0.8, 0.4),       # 3.5 A, fuse rating: plug to fuse, fuse to reverse diode
    "Rail": (0.25, 0.09, *VIA),          # +VIN, +5V, +3V3 stubs to their plane, 0.9 A
    "Buck": (0.4, 0.15, *VIA),           # buck nodes, 1 A: 1.2 A
    "Limited": (0.25, 0.09, *VIA),       # current-limited supplies, 0.6 A at most: 0.9 A
    "Ground": (0.25, 0.09, *VIA),        # stubs to the layer 2 plane, 0.9 A
    "Chassis": (0.5, 1.0, 0.8, 0.4),     # connector shields, FE, plated hole H1
    # differential pairs, gap 0.15 mm (PAIR_GAP), layer 1 over the ground plane: sim/impedance.py
    "Ethernet": (0.2, 0.15, *VIA),       # 100 ohm (100.8 computed)
    "USB": (0.265, 0.15, *VIA),          # 90 ohm (90.4 computed)
}
PAIR_GAP = 0.15
PAIR_KEEP = 0.3     # pair router: other copper this far from a pair, about 3 W (the DRC keeps the class clearance)
# Board minimums, mm: the JLCPCB multilayer capabilities (jlcpcb.com/capabilities/pcb-capabilities), the
# through-hole leads (0.28 mm to a track) and the cost of small vias in base.kicad_dru (pcb.py)
RULES = {"min_track_width": 0.09, "min_clearance": 0.09, "min_via_diameter": 0.25, "min_through_hole_diameter": 0.15,
         "min_via_annular_width": 0.05, "min_hole_clearance": 0.2, "min_hole_to_hole": 0.2,
         "min_copper_edge_clearance": 0.2}
PATTERNS = {
    "Input": ["/Power/VIN_RAW", "/Power/VIN_F"],
    "Rail": ["+VIN", "+5V", "+3V3"],
    "Buck": ["/Power/V3IN", "/Power/SW5", "/Power/SW3"],
    # VBUS: 0.5 A at most from a USB host
    "Limited": ["VBUS", "+VIN_OUT", "*/VSD", "*/VENC", "*/VSEL", "/Local bus/+3V3_BUS", "/Modbus/VISO"],
    "Ground": ["GND", "GNDISO"],
    "Chassis": ["CHASSIS"],
    "Ethernet": [f"/ESC/{d}{p}{port}" for d in ("TX", "RX") for p in "PN" for port in "AB"],
    "USB": ["USB_DP", "USB_DM"],
}


def class_of(net):
    """Class of a net name, from PATTERNS (a leading * matches any sheet path)."""
    for name, pats in PATTERNS.items():
        for p in pats:
            if net == p or (p.startswith("*") and net.endswith(p[1:])):
                return name
    return "Default"


def apply_netclasses(board):
    """The standalone KiCad Python does not apply the classes of the project file: set them on the board."""
    ns = board.GetDesignSettings().m_NetSettings
    for k, (name, (w, cl, vd, vdr)) in enumerate(CLASSES.items()):
        nc = ns.GetDefaultNetclass() if name == "Default" else pcbnew.NETCLASS(name)
        nc.SetTrackWidth(MM(w))
        nc.SetClearance(MM(cl))
        nc.SetViaDiameter(MM(vd))
        nc.SetViaDrill(MM(vdr))
        if name != "Default":
            nc.SetPriority(k)
            ns.SetNetclass(name, nc)
    for name, pats in PATTERNS.items():
        for p in pats:
            ns.SetNetclassPatternAssignment(p, name)
    ns.RecomputeEffectiveNetclasses()
    board.SynchronizeNetsAndNetClasses(True)


def save(board, path):
    """SaveBoard, then the project file gets back its schematic settings and the net classes."""
    pro = path.replace(".kicad_pcb", ".kicad_pro")
    before = json.load(open(pro, encoding="utf-8")) if os.path.exists(pro) else {}
    pcbnew.SaveBoard(path, board)
    after = json.load(open(pro, encoding="utf-8"))
    for key in ("erc", "schematic", "sheets"):
        if key in before:
            after[key] = before[key]
    after["board"]["design_settings"]["rules"].update(RULES)
    ns = after["net_settings"]
    default = next(c for c in ns["classes"] if c["name"] == "Default")
    classes = []
    for k, (name, (w, cl, vd, vdr)) in enumerate(CLASSES.items()):
        c = copy.deepcopy(default)
        c.update(name=name, track_width=w, clearance=cl, via_diameter=vd, via_drill=vdr)
        if name != "Default":
            c["priority"] = k
        classes.append(c)
    ns["classes"] = sorted(classes, key=lambda c: (c["name"] != "Default", c["name"]))   # KiCad's order
    ns["netclass_patterns"] = [{"netclass": name, "pattern": p} for name, pats in PATTERNS.items() for p in pats]
    with open(pro, "w", encoding="utf-8", newline="\n") as f:
        json.dump(after, f, indent=2, sort_keys=True, ensure_ascii=False)   # as KiCad writes it
        f.write("\n")
