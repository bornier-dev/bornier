# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Write simplified 3D models (STEP) of the Bornier.pretty footprints that have none, from the
dimensions of their datasheets. Needs CadQuery (pip install cadquery).

Usage: python gen_3d.py
Model frame: the footprint origin, x to the right, y toward the back (KiCad models have y up when the
footprint has y down), z up from the board surface, in mm.
"""
import os

import cadquery as cq

HERE = os.path.dirname(os.path.abspath(__file__))
OUT = os.path.join(HERE, "Bornier.3dshapes")


def rj45x2_hc_wk88():
    """Hong Cheng HC-WK88-H132-1X2-55B (drawing rev A): body 29.70 wide, 13.20 deep, 13.50 high,
    front face 8.74 mm in front of the origin (front row of contacts), ports 14.10 mm apart. Shield
    legs 1.20 wide at 29.50 mm, 4.00 mm behind the front face; locating pegs 3.20 at 25.60 mm, 6.30 mm
    behind it; contacts and legs 2.80 below the board. The port openings are not dimensioned on the
    drawing: standard RJ45 opening, 11.7 x 8.3 mm with its latch slot, bottom 1.0 mm above the board."""
    front, depth, width, height = 8.74, 13.2, 29.7, 13.5
    body = cq.Workplane("XY").box(width, depth, height, centered=(True, False, False)).translate((0, -front, 0))
    for cx in (-7.05, 7.05):
        # the XZ workplane looks along -y: offset to the front face, then cut back into the body
        mouth = (cq.Workplane("XZ").workplane(offset=front).center(cx, 1.0 + 8.3 / 2).rect(11.7, 8.3)
                 .extrude(-10.0))
        latch = cq.Workplane("XZ").workplane(offset=front).center(cx, 1.0 + 8.3 + 1.2).rect(6.0, 2.4).extrude(-10.0)
        body = body.cut(mouth).cut(latch)
    pins = cq.Workplane("XY")
    for port, cx in (("A", -7.05), ("B", 7.05)):
        for n in range(1, 9):
            y = 0.0 if n % 2 else 2.54                       # model y up: the back row is at +2.54
            pins = pins.union(cq.Workplane("XY").center(cx + 4.5 - n, y).circle(0.23).extrude(-2.8))
    for x in (-14.75, 14.75):
        pins = pins.union(cq.Workplane("XY").center(x, -(front - 4.0)).rect(1.2, 0.4).extrude(-2.8))
    for x in (-12.8, 12.8):
        pins = pins.union(cq.Workplane("XY").center(x, -(front - 6.3)).circle(1.5).extrude(-2.0))
    assy = cq.Assembly()
    assy.add(body, name="housing", color=cq.Color(0.1, 0.1, 0.1))
    assy.add(pins, name="contacts", color=cq.Color(0.85, 0.75, 0.3))
    return assy


def main():
    os.makedirs(OUT, exist_ok=True)
    for name, assy in (("RJ45x2_HongCheng_HC-WK88-H132-1X2-55B", rj45x2_hc_wk88()),):
        assy.export(os.path.join(OUT, name + ".step"))


if __name__ == "__main__":
    main()
