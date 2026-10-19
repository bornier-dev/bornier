# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Reference description of a circuit: parts, values, footprints, LCSC codes, connections.

The schematic is drawn from this description by a separate script, and the drawing is then
checked against it (check.py). Pins that a part does not list are marked "no connect".
"""

R0402 = "Resistor_SMD:R_0402_1005Metric"
R0603 = "Resistor_SMD:R_0603_1608Metric"
C0402 = "Capacitor_SMD:C_0402_1005Metric"
C0603 = "Capacitor_SMD:C_0603_1608Metric"
C0805 = "Capacitor_SMD:C_0805_2012Metric"


class Circuit:
    def __init__(self, palette=None, r_fp=R0603, c_fp=C0603):
        """palette: {(kind 'R'|'C', value, footprint): LCSC code}. When given, every resistor and
        capacitor must be one of its entries: a new value is a new feeder, so it is a decision."""
        self.palette = palette
        self.r_fp, self.c_fp = r_fp, c_fp
        self.parts = []
        self._block = "?"
        self._group = None

    def block(self, name):
        self._block = name
        self._group = None

    def group(self, name):
        """Parts that follow form one instance of a repeated sheet (None: no repetition)."""
        self._group = name

    def members(self, group):
        """References of a group, in creation order: the n-th part of two instances match."""
        return [p["ref"] for p in self.parts if group in (p["group"], p["also"])]

    def part(self, ref, sym, value, fp=None, lcsc="", pins=None, note="", dnp=False, also=None):
        """also: a second repeated-sheet group, for a multi-unit part whose units sit on two sheets."""
        if any(p["ref"] == ref for p in self.parts):
            raise ValueError(f"duplicate reference {ref}")
        self.parts.append(dict(ref=ref, sym=sym, value=value, fp=fp, lcsc=lcsc,
                               pins={str(k): v for k, v in (pins or {}).items()},
                               block=self._block, group=self._group, also=also, note=note, dnp=dnp))

    def _passive(self, kind, value, fp, lcsc):
        if fp is None and self.palette is not None:
            # a value offered in a single size takes that size
            sizes = [f for k, v, f in self.palette if (k, v) == (kind, value)]
            fp = sizes[0] if len(sizes) == 1 else None
        fp = fp or (self.r_fp if kind == "R" else self.c_fp)
        if self.palette is not None:
            key = (kind, value, fp)
            if key not in self.palette:
                raise ValueError(f"{kind} {value} {fp.split(':')[-1]} is not in the palette")
            if lcsc and lcsc != self.palette[key]:
                raise ValueError(f"{kind} {value}: {lcsc} differs from the palette ({self.palette[key]})")
            lcsc = self.palette[key]
        return fp, lcsc

    def R(self, ref, value, a, b, lcsc="", fp=None, note="", dnp=False):
        fp, lcsc = self._passive("R", value, fp, lcsc)
        self.part(ref, "Device:R", value, fp, lcsc, {1: a, 2: b}, note, dnp)

    def C(self, ref, value, a, b, lcsc="", fp=None, note="", dnp=False):
        fp, lcsc = self._passive("C", value, fp, lcsc)
        self.part(ref, "Device:C", value, fp, lcsc, {1: a, 2: b}, note, dnp)

    def by_ref(self):
        return {p["ref"]: p for p in self.parts}

    def nets(self):
        out = {}
        for p in self.parts:
            for pin, net in p["pins"].items():
                out.setdefault(net, set()).add((p["ref"], pin))
        return out
