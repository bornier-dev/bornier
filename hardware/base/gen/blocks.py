# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Functional blocks of the base board, the first step of the placement: each main chip with the parts that
serve it (decoupling capacitors, terminations, pull resistors, its own passives), and each connector with
its protection. The blocks are then placed as a whole.

Membership, from the netlist: a part joined by a signal net to a single block goes to it; a decoupling
capacitor (supply nets only) goes to the chip of its sheet with a pin on its supply; a part between two
blocks goes to the block named in OWNER, else to the chip nearest by the chain of passives; the protection
parts (PROTECT) go to their connector.

Run with the Python shipped with KiCad:
    "C:/Program Files/KiCad/10.0/bin/python.exe" blocks.py       the blocks and their members
"""
import collections
import re
import sys

import pcbnew

import pcb

# Main parts: a block each. The ESD arrays and TVS are protection, they join their connector's block.
MAIN = re.compile(r"(U|X|J)\d+$")
PROTECT = pcb.PROTECT
POWER = pcb.POWER_NETS | {"GNDISO", "/Modbus/GNDISO"}
# Parts between two blocks, given to one: (reference, block)
OWNER = {
    "J5": "U9",         # the programming connector belongs to the MCU block
    "D10": "U9",        # ESD of NRST, at the MCU pin
}
# Hubs: chips wired to most blocks. A part between a hub and another block goes to the other block; a hub
# keeps the parts that serve it alone.
HUBS = {"U9"}


def blocks():
    """{main reference: [members]}, and the parts left without a block."""
    comps, pins = pcb.load_netlist()
    nets = {r: {n for n in pins.get(r, {}).values() if n and not n.startswith("unconnected-")} for r in comps}
    on_net = collections.defaultdict(set)
    for r, ns in nets.items():
        for n in ns:
            on_net[n].add(r)
    main = {r for r in comps if MAIN.match(r) and comps[r]["value"] not in PROTECT and r not in OWNER}
    owner = dict(OWNER)

    def signal(r):
        return nets[r] - POWER

    # protection parts: the connector they share a signal net with
    for r in comps:
        if r in main or r in owner or comps[r]["value"] not in PROTECT:
            continue
        js = {q for n in signal(r) for q in on_net[n] if q.startswith("J") and q in main}
        if js:
            owner[r] = min(js)
    # the others: breadth first from the main parts along the signal nets, through the parts not yet owned;
    # a part reached from two blocks at the same depth goes to the one with a chip (U, X) first
    # (the other blocks first, then the hubs: a part between them goes to the other block)
    for starts in (main - HUBS, main & HUBS):
        frontier = {r: r for r in starts}
        while frontier:
            reach = collections.defaultdict(set)
            for r, b in frontier.items():
                for n in signal(r):
                    for q in on_net[n]:
                        if q not in main and q not in owner:
                            reach[q].add(b)
            nxt = {}
            for q, bs in reach.items():
                b = sorted(bs, key=lambda b: (b[0] == "J", b))[0]
                owner[q] = b
                nxt[q] = b
            frontier = nxt
    # decoupling capacitors: supply nets only, to a chip of their sheet with a pin on that supply
    left = []
    for r in comps:
        if r in main or r in owner:
            continue
        supply = nets[r] - {"GND", "GNDISO", "/Modbus/GNDISO", "CHASSIS"}
        chips = sorted(q for n in supply for q in on_net[n] if q in main and q[0] in "UX"
                       and comps[q]["sheetname"] == comps[r]["sheetname"])
        if chips:
            owner[r] = chips[0]
        else:
            left.append(r)
    out = collections.defaultdict(list)
    for r, b in owner.items():
        out[b].append(r)
    return {b: sorted(out.get(b, []), key=pcb.rank) for b in sorted(main, key=lambda r: (r[0], int(re.sub(r"\D", "", r))))}, left, comps


def layout(block, members, comps, pins, at=(40.0, 50.0), rot=0):
    """A board with the block alone: its main part at `at`, the members against the pins they serve (the rules
    of pcb.auto_place, without the zones of the floor plan). Returns (board, footprints, parts not placed)."""
    board = pcbnew.CreateEmptyBoard()
    board.SetCopperLayerCount(4)
    nets, fps = {}, {}
    for r in [block] + members:
        c = comps[r]
        fp = pcb.load_fp(c["fp"])
        fp.SetReference(r)
        fp.SetValue(c["value"])
        fp.SetSheetname(c["sheetname"])
        board.Add(fp)
        for pad in fp.Pads():
            n = pins.get(r, {}).get(pad.GetNumber())
            if n:
                if n not in nets:
                    nets[n] = pcbnew.NETINFO_ITEM(board, n)
                    board.Add(nets[n])
                pad.SetNet(nets[n])
        fps[r] = fp
    pcb.place_centred(fps[block], *at, rot)
    zones, lanes = pcb.ZONES, pcb.LANES
    pcb.ZONES, pcb.LANES = {"/Modbus/ bus side": [(0, 0, 0, 0)]}, []
    try:
        failed = pcb.auto_place(fps, {block: fps[block]}, set())
    finally:
        pcb.ZONES, pcb.LANES = zones, lanes
    return board, fps, failed


def main():
    bl, left, comps = blocks()
    if len(sys.argv) > 2 and sys.argv[1] == "show":
        # show REF out.kicad_pcb: the block of REF laid out alone
        _, pins = pcb.load_netlist()
        ref = sys.argv[2]
        board, _, failed = layout(ref, bl[ref], comps, pins)
        board.SetFileName(sys.argv[3])
        pcbnew.SaveBoard(sys.argv[3], board)
        print(f"{ref}: {len(bl[ref])} member(s) -> {sys.argv[3]}" + (f", not placed: {failed}" if failed else ""))
        return
    for b, members in bl.items():
        print(f"{b:5} {comps[b]['value'][:22]:22} {comps[b]['sheetname'][:22]:22} {len(members):3}  {' '.join(members)}")
    print("without a block:", " ".join(left))


if __name__ == "__main__":
    main()
