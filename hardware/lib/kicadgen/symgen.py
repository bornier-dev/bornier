# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Generate rectangular schematic symbols for parts that KiCad does not ship.

A symbol is described by its pins, each placed on a side of the body at a slot (in units of
2.54 mm from the top for left/right, from the left for top/bottom). Gaps between slots group
the pins by function.
"""
from .sexpr import Sym, dump

G = 2.54
PIN_LEN = 2.54


def _font(size=1.27):
    return [Sym("effects"), [Sym("font"), [Sym("size"), size, size]]]


def _prop(key, value, x, y, hide=False, just=None):
    eff = _font()
    if just:
        eff.append([Sym("justify"), Sym(just)])
    if hide:
        eff.append([Sym("hide"), Sym("yes")])
    return [Sym("property"), key, value, [Sym("at"), x, y, 0], eff]


def symbol(name, pins, width, height, ref="U", footprint="", datasheet="", description=""):
    """pins: (number, name, electrical type, side 'L'|'R'|'T'|'B', slot).

    Body corners at (-width/2, height/2) and (width/2, -height/2), in multiples of 2.54 mm.
    Left and right slots count down from the top edge, top and bottom slots from the left edge.
    """
    w, h = width * G, height * G
    x0, y0 = -w / 2, h / 2
    gfx = [Sym("symbol"), f"{name}_0_1",
           [Sym("rectangle"), [Sym("start"), x0, y0], [Sym("end"), -x0, -y0],
            [Sym("stroke"), [Sym("width"), 0.254], [Sym("type"), Sym("default")]],
            [Sym("fill"), [Sym("type"), Sym("background")]]]]
    pin_nodes = [Sym("symbol"), f"{name}_1_1"]
    seen = set()
    for num, pname, etype, side, slot in pins:
        if num in seen:
            raise ValueError(f"{name}: duplicate pin {num}")
        seen.add(num)
        if side == "L":
            x, y, ang = x0 - PIN_LEN, y0 - (slot + 1) * G, 0
        elif side == "R":
            x, y, ang = -x0 + PIN_LEN, y0 - (slot + 1) * G, 180
        elif side == "T":
            x, y, ang = x0 + (slot + 1) * G, y0 + PIN_LEN, 270
        else:
            x, y, ang = x0 + (slot + 1) * G, -y0 - PIN_LEN, 90
        pin_nodes.append([Sym("pin"), Sym(etype), Sym("line"), [Sym("at"), x, y, ang], [Sym("length"), PIN_LEN],
                          [Sym("name"), pname, _font()], [Sym("number"), num, _font()]])
    return [Sym("symbol"), name, [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")],
            [Sym("on_board"), Sym("yes")],
            _prop("Reference", ref, x0, y0 + 1.27, just="left"),
            _prop("Value", name, x0, -y0 - 1.27, just="left"),
            _prop("Footprint", footprint, 0, 0, hide=True),
            _prop("Datasheet", datasheet, 0, 0, hide=True),
            _prop("Description", description, 0, 0, hide=True),
            gfx, pin_nodes, [Sym("embedded_fonts"), Sym("no")]]


def symbol_units(name, units, box, ref="J", footprint="", datasheet="", description=""):
    """Multi-unit symbol with the same body in every unit. units: one list per unit of
    (number, name, electrical type, x, y, angle), pins at explicit library coordinates (Y up).
    box: (x0, y0, x1, y1) of the body."""
    x0, y0, x1, y1 = box
    gfx = [Sym("symbol"), f"{name}_0_1",
           [Sym("rectangle"), [Sym("start"), x0, y0], [Sym("end"), x1, y1],
            [Sym("stroke"), [Sym("width"), 0.254], [Sym("type"), Sym("default")]],
            [Sym("fill"), [Sym("type"), Sym("background")]]]]
    nodes = [gfx]
    for u, pins in enumerate(units, 1):
        node = [Sym("symbol"), f"{name}_{u}_1"]
        for num, pname, etype, x, y, ang in pins:
            node.append([Sym("pin"), Sym(etype), Sym("line"), [Sym("at"), x, y, ang], [Sym("length"), PIN_LEN],
                         [Sym("name"), pname, _font()], [Sym("number"), num, _font()]])
        nodes.append(node)
    return [Sym("symbol"), name, [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")],
            [Sym("on_board"), Sym("yes")],
            _prop("Reference", ref, x0, y1 + 1.27, just="left"),
            _prop("Value", name, x0, y0 - 1.27, just="left"),
            _prop("Footprint", footprint, 0, 0, hide=True),
            _prop("Datasheet", datasheet, 0, 0, hide=True),
            _prop("Description", description, 0, 0, hide=True)] + nodes + [[Sym("embedded_fonts"), Sym("no")]]


def switch_units(name, n, ref="SW", footprint="", datasheet="", description=""):
    """DIP switch drawn one unit per switch, so that each switch sits on the line it serves. Unit k is an
    SPST between pins k and 2n + 1 - k (the numbering of DIP switch footprints)."""
    spst = [[Sym("circle"), [Sym("center"), -2.032, 0], [Sym("radius"), 0.508],
             [Sym("stroke"), [Sym("width"), 0], [Sym("type"), Sym("default")]], [Sym("fill"), [Sym("type"), Sym("none")]]],
            [Sym("circle"), [Sym("center"), 2.032, 0], [Sym("radius"), 0.508],
             [Sym("stroke"), [Sym("width"), 0], [Sym("type"), Sym("default")]], [Sym("fill"), [Sym("type"), Sym("none")]]],
            [Sym("polyline"), [Sym("pts"), [Sym("xy"), -1.524, 0.254], [Sym("xy"), 1.524, 1.778]],
             [Sym("stroke"), [Sym("width"), 0], [Sym("type"), Sym("default")]], [Sym("fill"), [Sym("type"), Sym("none")]]]]
    nodes = [[Sym("symbol"), f"{name}_0_1"] + spst]
    for u in range(1, n + 1):
        nodes.append([Sym("symbol"), f"{name}_{u}_1"] + [
            [Sym("pin"), Sym("passive"), Sym("line"), [Sym("at"), x, 0, ang], [Sym("length"), PIN_LEN],
             [Sym("name"), "~", _font()], [Sym("number"), str(num), _font()]]
            for num, x, ang in ((u, -5.08, 0), (2 * n + 1 - u, 5.08, 180))])
    return [Sym("symbol"), name, [Sym("pin_names"), [Sym("offset"), 0], [Sym("hide"), Sym("yes")]],
            [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")], [Sym("on_board"), Sym("yes")],
            _prop("Reference", ref, 0, 3.175),
            _prop("Value", name, 0, -2.54),
            _prop("Footprint", footprint, 0, 0, hide=True),
            _prop("Datasheet", datasheet, 0, 0, hide=True),
            _prop("Description", description, 0, 0, hide=True)] + nodes + [[Sym("embedded_fonts"), Sym("no")]]


def write_library(path, symbols):
    lib = [Sym("kicad_symbol_lib"), [Sym("version"), Sym("20241209")], [Sym("generator"), "kicadgen"],
           [Sym("generator_version"), "10.0"]] + symbols
    with open(path, "w", encoding="utf-8", newline="\n") as f:
        f.write(dump(lib) + "\n")
