# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Locate the KiCad installation and read symbols from its libraries.

KiCad 10 is required. The symbol directory comes from KICAD10_SYMBOL_DIR when it is set,
otherwise from the usual install locations on Windows and Linux. kicad-cli is taken from PATH,
then from the same install locations.
"""
import copy
import os
import shutil

from .sexpr import Sym, parse, find, first

_ROOTS = [
    os.path.join(os.environ.get("LOCALAPPDATA", ""), "Programs", "KiCad", "10.0"),
    r"C:\Program Files\KiCad\10.0",
    "/usr",
]


def symbol_dir():
    env = os.environ.get("KICAD10_SYMBOL_DIR")
    if env:
        return env
    for root in _ROOTS:
        d = os.path.join(root, "share", "kicad", "symbols")
        if os.path.isdir(d):
            return d
    raise SystemExit("KiCad 10 symbol libraries not found: set KICAD10_SYMBOL_DIR")


def footprint_dir():
    env = os.environ.get("KICAD10_FOOTPRINT_DIR")
    if env:
        return env
    for root in _ROOTS:
        d = os.path.join(root, "share", "kicad", "footprints")
        if os.path.isdir(d):
            return d
    raise SystemExit("KiCad 10 footprint libraries not found: set KICAD10_FOOTPRINT_DIR")


def cli():
    exe = shutil.which("kicad-cli")
    if exe:
        return exe
    for root in _ROOTS:
        for name in ("kicad-cli.exe", "kicad-cli"):
            p = os.path.join(root, "bin", name)
            if os.path.isfile(p):
                return p
    raise SystemExit("kicad-cli not found: add the KiCad 10 bin directory to PATH")


class Libraries:
    """Standard KiCad symbol libraries plus project libraries {nickname: path}."""

    def __init__(self, extra=None):
        self.extra = extra or {}
        self._cache = {}

    def _symbols(self, lib):
        if lib not in self._cache:
            path = self.extra.get(lib) or os.path.join(symbol_dir(), lib + ".kicad_sym")
            tree = parse(open(path, encoding="utf-8").read())
            self._cache[lib] = {s[1]: s for s in find(tree, "symbol")}
        return self._cache[lib]

    def resolve(self, lib_id):
        """Flattened symbol (inheritance resolved), renamed to its lib_id to embed it."""
        lib, name = lib_id.split(":", 1)
        syms = self._symbols(lib)
        node = copy.deepcopy(syms[name])
        ext = first(node, "extends")
        if ext:
            base = self.resolve(f"{lib}:{ext[1]}")
            base_name = base[1].split(":", 1)[1]
            props = {p[1]: p for p in find(node, "property")}
            out = [Sym("symbol"), name]
            for c in base[2:]:
                if isinstance(c, list) and c[0] == "property" and c[1] in props:
                    out.append(props[c[1]])
                elif isinstance(c, list) and c[0] == "symbol":
                    c = copy.deepcopy(c)
                    c[1] = c[1].replace(base_name, name, 1)
                    out.append(c)
                else:
                    out.append(c)
            for k, p in props.items():
                if not any(isinstance(c, list) and c[0] == "property" and c[1] == k for c in out):
                    out.append(p)
            node = out
        node[1] = lib_id
        return node


def pin_geometry(sym, unit=1):
    """Pins of one unit as (number, x, y, angle) in library coordinates (Y up); unit 0 pins are common."""
    pins = []
    for node in find(sym, "symbol"):
        tag = node[1].rsplit("_", 2)
        u, style = int(tag[-2]), int(tag[-1])
        if u not in (0, unit) or style not in (0, 1):
            continue
        for p in find(node, "pin"):
            at, number = first(p, "at"), first(p, "number")
            if at is None or number is None:
                raise ValueError(f"malformed pin in {sym[1]}")
            pins.append((number[1], float(at[1]), float(at[2]), int(float(at[3])) if len(at) > 3 else 0))
    return pins


def prop_value(sym, key):
    for p in find(sym, "property"):
        if p[1] == key:
            return p[2]
    return ""
