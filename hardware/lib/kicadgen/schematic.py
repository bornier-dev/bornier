# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Draw a hierarchical KiCad schematic by script: placed symbols joined by wires.

A board script places each part of its Circuit and draws the wires between pins. Every wire
declares the net it carries; lint() rejects a wire that touches a pin or a wire of another net,
and check.py then proves the drawn netlist equals the circuit. Junctions are added
automatically and identifiers are deterministic, so the symbol-to-footprint link survives
regeneration. Coordinates are in mm on the 1.27 mm grid, Y pointing down.
"""
import math
import os
import uuid

from .sexpr import Sym, dump
from .kicad import Libraries, pin_geometry, prop_value

POWER_KINDS = ("GND", "GNDISO", "+3V3", "+5V", "+24V", "PWR_FLAG")
GROUNDS = ("GND", "GNDISO")
# Power symbols drawn from another library symbol; the net takes the name in the Value field.
POWER_LIB = {"GNDISO": "power:GNDS"}


def g(v):
    """Snap to the 1.27 mm schematic grid."""
    return round(round(v / 1.27) * 1.27, 4)


def font(size=1.27, *extra):
    return [Sym("effects"), [Sym("font"), [Sym("size"), size, size]] + list(extra)]


def transform(x, y, rot, mirror):
    # KiCad rotates first, then mirrors: the order matters once both are combined.
    a = math.radians(rot)
    rx = x * math.cos(a) - y * math.sin(a)
    ry = x * math.sin(a) + y * math.cos(a)
    if mirror == "y":
        rx = -rx
    elif mirror == "x":
        ry = -ry
    return rx, ry


def on_seg(p, s):
    (x1, y1), (x2, y2) = s
    if p in s:
        return False
    if x1 == x2 == p[0]:
        return min(y1, y2) < p[1] < max(y1, y2)
    if y1 == y2 == p[1]:
        return min(x1, x2) < p[0] < max(x1, x2)
    return False


def collinear_overlap(s1, s2):
    (a1, b1), (a2, b2) = s1, s2
    if a1[0] == b1[0] == a2[0] == b2[0]:
        lo1, hi1 = sorted((a1[1], b1[1]))
        lo2, hi2 = sorted((a2[1], b2[1]))
        return min(hi1, hi2) - max(lo1, lo2) > 0
    if a1[1] == b1[1] == a2[1] == b2[1]:
        lo1, hi1 = sorted((a1[0], b1[0]))
        lo2, hi2 = sorted((a2[0], b2[0]))
        return min(hi1, hi2) - max(lo1, lo2) > 0
    return False


def split_wires(wires, extra=()):
    """Split wires where another wire ends (T), or where a power symbol or a pin sits:
    KiCad only connects at wire ends."""
    pts = {p for s in wires for p in s} | set(extra)
    out = []
    for a, b in wires:
        inner = sorted((p for p in pts if on_seg(p, (a, b))),
                       key=lambda p: (p[0] - a[0]) ** 2 + (p[1] - a[1]) ** 2)
        chain = [a] + inner + [b]
        out += list(zip(chain, chain[1:]))
    return out


class Project:
    def __init__(self, name, circuit, title, date, libs=None):
        self.name, self.circuit, self.title, self.date = name, circuit, title, date
        self.parts = circuit.by_ref()
        self.libs = Libraries(libs)
        self.ns = uuid.uuid5(uuid.NAMESPACE_URL, f"bornier/{name}/schematic")
        self._count = {}
        self._embedded = {}
        self.sheets = []

    def U(self, key):
        self._count[key] = self._count.get(key, 0) + 1
        return str(uuid.uuid5(self.ns, f"{key}#{self._count[key]}"))

    def sym_def(self, lib_id):
        if lib_id not in self._embedded:
            self._embedded[lib_id] = self.libs.resolve(lib_id)
        return self._embedded[lib_id]

    def sheet(self, name, filename, title, paper="A3"):
        s = Sheet(self, name, filename, title, paper)
        self.sheets.append(s)
        return s

    def title_block(self, title, comment):
        return [Sym("title_block"), [Sym("title"), title], [Sym("date"), self.date], [Sym("rev"), "A"],
                [Sym("company"), "Bornier"], [Sym("comment"), 1, comment]]

    def write(self, kicad_dir):
        os.makedirs(kicad_dir, exist_ok=True)
        root_uuid = self.U("root")
        sheet_nodes = []
        ok = True
        slot, page = 0, 2
        for sh in self.sheets:
            ok &= sh.finish()
            uuids = []
            for name, _, pinmap in sh.instances:
                su = self.U(f"sheet/{name}")
                uuids.append(su)
                x, y = 25.4 + (slot % 3) * 127.0, 38.1 + (slot // 3) * 50.8
                h = max(25.4, 7.62 + 2.54 * len(sh.hpins))
                node = [Sym("sheet"), [Sym("at"), x, y], [Sym("size"), 63.5, h],
                        [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")],
                        [Sym("on_board"), Sym("yes")], [Sym("dnp"), Sym("no")],
                        [Sym("fields_autoplaced"), Sym("yes")],
                        [Sym("stroke"), [Sym("width"), 0.1524], [Sym("type"), Sym("solid")]],
                        [Sym("fill"), [Sym("color"), 0, 0, 0, 0.0]], [Sym("uuid"), su],
                        [Sym("property"), "Sheetname", name, [Sym("at"), x, y - 0.7, 0],
                         font() + [[Sym("justify"), Sym("left"), Sym("bottom")]]],
                        [Sym("property"), "Sheetfile", sh.file, [Sym("at"), x, y + h + 0.6, 0],
                         font() + [[Sym("justify"), Sym("left"), Sym("top")]]]]
                # one pin per hierarchical label, wired to a global label of the parent net
                for k, (text, shape) in enumerate(sh.hpins):
                    px, py = g(x + 63.5), g(y + 5.08 + 2.54 * k)
                    kind = shape if shape in ("input", "output", "bidirectional", "passive") else "bidirectional"
                    node.append([Sym("pin"), text, Sym(kind), [Sym("at"), px, py, 0],
                                 font() + [[Sym("justify"), Sym("right")]], [Sym("uuid"), self.U(f"spin/{name}/{text}")]])
                    net = pinmap.get(text, text)
                    sheet_nodes.append([Sym("wire"), [Sym("pts"), [Sym("xy"), px, py], [Sym("xy"), g(px + 5.08), py]],
                                        [Sym("stroke"), [Sym("width"), 0], [Sym("type"), Sym("default")]],
                                        [Sym("uuid"), self.U(f"rootwire/{name}/{text}")]])
                    sheet_nodes.append([Sym("global_label"), net, [Sym("shape"), Sym(shape)],
                                        [Sym("at"), g(px + 5.08), py, 0], [Sym("fields_autoplaced"), Sym("yes")],
                                        font() + [[Sym("justify"), Sym("left")]],
                                        [Sym("uuid"), self.U(f"rootglabel/{name}/{text}")],
                                        [Sym("property"), "Intersheetrefs", "${INTERSHEET_REFS}",
                                         [Sym("at"), g(px + 5.08), py, 0], font() + [[Sym("hide"), Sym("yes")]]]])
                node.append([Sym("instances"), [Sym("project"), self.name,
                                                [Sym("path"), "/" + root_uuid, [Sym("page"), str(page)]]]])
                sheet_nodes.insert(0, node)
                slot += 1
                page += 1
            body = sh.build(root_uuid, uuids)
            doc = [Sym("kicad_sch"), [Sym("version"), Sym("20250114")], [Sym("generator"), "eeschema"],
                   [Sym("generator_version"), "10.0"], [Sym("uuid"), sh.uuid], [Sym("paper"), sh.paper],
                   self.title_block(sh.title, "Generated by gen/schematic.py, checked by gen/check.py"),
                   [Sym("lib_symbols")] + list(self._embedded.values())] + body
            with open(os.path.join(kicad_dir, sh.file), "w", encoding="utf-8", newline="\n") as f:
                f.write(dump(doc) + "\n")
        root = [Sym("kicad_sch"), [Sym("version"), Sym("20250114")], [Sym("generator"), "eeschema"],
                [Sym("generator_version"), "10.0"], [Sym("uuid"), root_uuid], [Sym("paper"), "A3"],
                self.title_block(self.title, "Generated by gen/schematic.py, do not edit by hand"),
                [Sym("lib_symbols")]] + sheet_nodes + [
            [Sym("sheet_instances"), [Sym("path"), "/", [Sym("page"), "1"]]], [Sym("embedded_fonts"), Sym("no")]]
        path = os.path.join(kicad_dir, self.name + ".kicad_sch")
        with open(path, "w", encoding="utf-8", newline="\n") as f:
            f.write(dump(root) + "\n")
        return path, ok


class Sheet:
    def __init__(self, project, name, filename, title, paper):
        self.prj = project
        self.name, self.file, self.title, self.paper = name, filename, title, paper
        self.uuid = project.U(f"sheetfile/{name}")
        self.items = []
        self.wires = []
        self.wnet = []
        self.pins = {}          # (ref, number) -> (x, y)
        self.placed = []
        self.pwr = 0
        self.pwr_pts = []
        self.quiet = set()      # nets left without a label (short links whose name adds nothing)
        self.alias = None       # net name -> text shown on labels (repeated sheets drop the instance prefix)
        self.hpins = []         # hierarchical labels: (text, shape), in drawing order
        # Instances of a repeated sheet: (name, {template ref: instance ref}, {pin text: parent net}).
        self.instances = [(name, {}, {})]

    def repeat(self, instances):
        """Use this drawing for several instances: [(name, refmap, pinmap)], the first one drawn."""
        self.instances = instances

    def shown(self, net):
        return self.alias(net) if self.alias else net

    # --- parts -----------------------------------------------------------------------------
    def place(self, ref, x, y, rot=0, mirror=None, ref_at=None, val_at=None, show_value=True, show_ref=True):
        part = self.prj.parts[ref]
        sd = self.prj.sym_def(part["sym"])
        x, y = g(x), g(y)
        for num, lx, ly, _ in pin_geometry(sd):
            rx, ry = transform(lx, ly, rot, mirror)
            self.pins[(ref, num)] = (g(x + rx), g(y - ry))
        unknown = set(part["pins"]) - {n for n, *_ in pin_geometry(sd)}
        if unknown:
            raise SystemExit(f"{ref} ({part['sym']}): unknown pins {sorted(unknown)}")
        self.placed.append(ref)
        fp = part["fp"] or prop_value(sd, "Footprint")
        node = [Sym("symbol"), [Sym("lib_id"), part["sym"]], [Sym("at"), x, y, rot]]
        if mirror:
            node.append([Sym("mirror"), Sym(mirror)])
        node += [[Sym("unit"), 1], [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")],
                 [Sym("on_board"), Sym("yes")], [Sym("dnp"), Sym("yes" if part["dnp"] else "no")],
                 [Sym("uuid"), self.prj.U(f"sym/{ref}")]]
        rx0, ry0 = ref_at or (x + 2.54, y - 1.27)
        vx0, vy0 = val_at or (rx0, ry0 + 2.54)
        props = [("Reference", ref, rx0, ry0, not show_ref), ("Value", part["value"], vx0, vy0, not show_value),
                 ("Footprint", fp, x, y, True), ("Datasheet", "~", x, y, True),
                 ("Description", part["note"], x, y, True), ("LCSC", part["lcsc"], x, y, True)]
        for k, v, px, py, hide in props:
            eff = font() + [[Sym("justify"), Sym("left")]]
            if hide:
                eff.append([Sym("hide"), Sym("yes")])
            node.append([Sym("property"), k, v, [Sym("at"), g(px), g(py), rot % 180], eff])
        for num in sorted({n for n, *_ in pin_geometry(sd)}, key=lambda s: (len(s), s)):
            node.append([Sym("pin"), num, [Sym("uuid"), self.prj.U(f"pin/{ref}/{num}")]])
        self.items.append(("symbol", ref, node))

    def P(self, ref, num):
        return self.pins[(ref, str(num))]

    # --- wires -----------------------------------------------------------------------------
    def w(self, net, *pts):
        """Polyline carrying `net` (a circuit net name, or GND / +3V3 / +5V)."""
        pts = [(g(x), g(y)) for x, y in pts]
        for a, b in zip(pts, pts[1:]):
            if a != b:
                self.wires.append((a, b))
                self.wnet.append(net)

    def lint(self):
        """Drawing errors: a wire touching a pin or a wire of another net."""
        err = []
        exp = {}
        for p in self.prj.circuit.parts:
            for num, n in p["pins"].items():
                exp[(p["ref"], num)] = n
        for (a, b), net in zip(self.wires, self.wnet):
            for key, pt in self.pins.items():
                if key[0] in self.placed and (pt in (a, b) or on_seg(pt, (a, b))):
                    want = exp.get(key)
                    if want != net:
                        err.append(f"wire {net} {a}-{b} touches {key[0]}.{key[1]} ({want})")
        segs = list(zip(self.wires, self.wnet))
        for i, (s1, n1) in enumerate(segs):
            for s2, n2 in segs[i + 1:]:
                if n1 == n2:
                    continue
                if set(s1) & set(s2) or any(on_seg(p, s2) for p in s1) or any(on_seg(p, s1) for p in s2):
                    err.append(f"wires {n1} and {n2} touch: {s1} / {s2}")
                if collinear_overlap(s1, s2):
                    err.append(f"wires {n1} and {n2} overlap: {s1} / {s2}")
        for pt, kind in self.pwr_pts:
            for (a, b), net in segs:
                if kind != "PWR_FLAG" and pt in (a, b) and net != kind:
                    err.append(f"power symbol {kind} on a {net} wire at {pt}")
        return err

    # --- labels, power symbols, text -------------------------------------------------------------
    def label(self, name, x, y, rot=0):
        """Net label anchored at (x, y); its text runs toward rot (0 right, 90 up, 180 left, 270 down)."""
        just = Sym("right") if rot in (180, 270) else Sym("left")
        self.items.append(("label", name, [Sym("label"), self.shown(name), [Sym("at"), g(x), g(y), rot],
                                           font() + [[Sym("justify"), just, Sym("bottom")]],
                                           [Sym("uuid"), self.prj.U(f"label/{self.name}/{name}")]]))

    def glabel(self, name, x, y, rot=0, shape="bidirectional"):
        just = Sym("right") if rot in (180, 270) else Sym("left")
        self.items.append(("glabel", name, [Sym("global_label"), name, [Sym("shape"), Sym(shape)],
                                            [Sym("at"), g(x), g(y), rot], [Sym("fields_autoplaced"), Sym("yes")],
                                            font() + [[Sym("justify"), just]],
                                            [Sym("uuid"), self.prj.U(f"glabel/{self.name}/{name}")],
                                            [Sym("property"), "Intersheetrefs", "${INTERSHEET_REFS}",
                                             [Sym("at"), g(x), g(y), 0], font() + [[Sym("hide"), Sym("yes")]]]]))

    def hlabel(self, net, x, y, rot=0, shape="bidirectional"):
        """Hierarchical label: connects `net` to the pin of the same text on the sheet symbol."""
        text = self.shown(net)
        just = Sym("right") if rot in (180, 270) else Sym("left")
        self.hpins.append((text, shape))
        self.items.append(("hlabel", net, [Sym("hierarchical_label"), text, [Sym("shape"), Sym(shape)],
                                           [Sym("at"), g(x), g(y), rot], [Sym("fields_autoplaced"), Sym("yes")],
                                           font() + [[Sym("justify"), just]],
                                           [Sym("uuid"), self.prj.U(f"hlabel/{self.name}/{text}")]]))

    def power(self, kind, x, y, rot=0, show=True):
        """Power symbol (GND, +3V3, +5V, +24V) or PWR_FLAG, set on the end of a wire."""
        if kind not in POWER_KINDS:
            raise ValueError(kind)
        self.pwr += 1
        lib = POWER_LIB.get(kind, f"power:{kind}")
        self.prj.sym_def(lib)
        prefix = "#FLG" if kind == "PWR_FLAG" else "#PWR"
        ref = f"{prefix}{self.name[:3].upper()}{self.pwr:02d}"
        x, y = g(x), g(y)
        above = kind not in GROUNDS
        node = [Sym("symbol"), [Sym("lib_id"), lib], [Sym("at"), x, y, rot], [Sym("unit"), 1],
                [Sym("exclude_from_sim"), Sym("no")], [Sym("in_bom"), Sym("yes")], [Sym("on_board"), Sym("yes")],
                [Sym("dnp"), Sym("no")], [Sym("uuid"), self.prj.U(f"pwr/{self.name}/{self.pwr}")],
                [Sym("property"), "Reference", ref, [Sym("at"), x, y, 0], font() + [[Sym("hide"), Sym("yes")]]],
                [Sym("property"), "Value", kind, [Sym("at"), x, g(y - 3.81 if above else y + 3.81), 0],
                 font() + ([[Sym("hide"), Sym("yes")]] if kind == "PWR_FLAG" or not show else [])],
                [Sym("property"), "Footprint", "", [Sym("at"), x, y, 0], font() + [[Sym("hide"), Sym("yes")]]],
                [Sym("pin"), "1", [Sym("uuid"), self.prj.U(f"pwrpin/{self.name}/{self.pwr}")]]]
        self.items.append(("power", ref, node))
        self.pwr_pts.append(((x, y), kind))

    def rail(self, kind, x, y, drop=2.54, up=None):
        """Short wire from (x, y) ending on a power symbol: down for GND, up otherwise."""
        up = kind not in GROUNDS if up is None else up
        y2 = y - drop if up else y + drop
        self.w(kind, (x, y), (x, y2))
        self.power(kind, x, y2, 0 if up == (kind not in GROUNDS) else 180)

    def text(self, s, x, y, size=1.27, bold=False):
        eff = font(size, [Sym("bold"), Sym("yes" if bold else "no")]) + [[Sym("justify"), Sym("left"), Sym("top")]]
        self.items.append(("text", s, [Sym("text"), s, [Sym("exclude_from_sim"), Sym("no")],
                                       [Sym("at"), g(x), g(y), 0], eff,
                                       [Sym("uuid"), self.prj.U(f"text/{self.name}/{s[:20]}")]]))

    # --- output ----------------------------------------------------------------------------
    def finish(self):
        """No-connect flags, one label per unnamed net, lint. Returns False on drawing errors."""
        for ref in self.placed:
            want = self.prj.parts[ref]["pins"]
            for (r, num), pt in list(self.pins.items()):
                if r == ref and num not in want:
                    self.items.append(("nc", ref, [Sym("no_connect"), [Sym("at"), *pt],
                                                   [Sym("uuid"), self.prj.U(f"nc/{ref}/{num}")]]))
        named = {key for kind, key, _ in self.items if kind in ("label", "glabel", "hlabel")} | set(POWER_KINDS)
        seen = set()
        for (a, b), net in zip(self.wires, self.wnet):
            if net in named or net in seen or net in self.quiet:
                continue
            seen.add(net)
            mx, my = g((a[0] + b[0]) / 2), g((a[1] + b[1]) / 2)
            if not on_seg((mx, my), (a, b)):
                mx, my = a
            self.label(net, mx, my)
        problems = self.lint()
        for p in problems[:40]:
            print(f"  sheet {self.name}: {p}")
        self.wires = split_wires(self.wires, [p for p, _ in self.pwr_pts] + list(self.pins.values()))
        return not problems

    def _junctions(self):
        """Junction where a wire end lands inside another wire, or where 3 ends meet."""
        ends = {}
        for a, b in self.wires:
            for p in (a, b):
                ends[p] = ends.get(p, 0) + 1
        pinpts = set(self.pins.values())
        out = set()
        for p, n in ends.items():
            if any(on_seg(p, s) for s in self.wires) or n >= 3 or (n >= 2 and p in pinpts):
                out.add(p)
        return out

    def build(self, root_uuid, sheet_uuids):
        """Body of the sheet file; symbols carry one reference per instance (sheet_uuids in order)."""
        body = []
        for kind, key, node in self.items:
            if kind in ("symbol", "power"):
                node = list(node)
                paths = []
                for k, ((_, refmap, _), su) in enumerate(zip(self.instances, sheet_uuids)):
                    ref = refmap.get(key, key) if kind == "symbol" else (key if k == 0 else f"{key}{k}")
                    paths.append([Sym("path"), f"/{root_uuid}/{su}", [Sym("reference"), ref], [Sym("unit"), 1]])
                node.append([Sym("instances"), [Sym("project"), self.prj.name, *paths]])
            body.append(node)
        for a, b in self.wires:
            body.append([Sym("wire"), [Sym("pts"), [Sym("xy"), *a], [Sym("xy"), *b]],
                         [Sym("stroke"), [Sym("width"), 0], [Sym("type"), Sym("default")]],
                         [Sym("uuid"), self.prj.U(f"wire/{self.name}/{a}/{b}")]])
        for p in sorted(self._junctions()):
            body.append([Sym("junction"), [Sym("at"), *p], [Sym("diameter"), 0],
                         [Sym("color"), 0, 0, 0, 0], [Sym("uuid"), self.prj.U(f"junc/{self.name}/{p}")]])
        return body
