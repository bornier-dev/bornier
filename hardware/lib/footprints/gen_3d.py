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


def box(x0, y0, z0, x1, y1, z1):
    return cq.Workplane("XY").box(x1 - x0, y1 - y0, z1 - z0, centered=False).translate((x0, y0, z0))


def rj45_hy911105ae():
    """HanRun HY911105AE, RJ45 with magnetics and LEDs (datasheet page 2, rev A), for the KiCad footprint
    RJ45_Hanrun_HR911105A_Horizontal (origin: pin 1). Body 16.04 wide, 21.30 deep, 13.50 high; mounting
    pattern 15.49 mm across the shield pins, so the body is centred on x = 4.44. Front face 3.05 mm in front
    of the LED pins (footprint y = 11.26), so at y = 14.31; pins 3.05 below the board. Opening: standard
    RJ45, 11.7 x 8.3 mm, latch slot at the bottom (tab down); LEDs in the lower corners of the front."""
    cx, front, back = 4.44, -14.31, -14.31 + 21.3            # model y = -footprint y
    body = box(cx - 8.02, front, 0, cx + 8.02, back, 13.5)
    mouth = cq.Workplane("XZ").workplane(offset=-front).center(cx, 2.6 + 8.3 / 2).rect(11.7, 8.3).extrude(-15.0)
    latch = cq.Workplane("XZ").workplane(offset=-front).center(cx, 1.4).rect(6.0, 2.4).extrude(-15.0)
    body = body.cut(mouth).cut(latch)
    green = box(cx - 7.4, front - 0.1, 0.6, cx - 5.0, front + 0.4, 2.2)
    yellow = box(cx + 5.0, front - 0.1, 0.6, cx + 7.4, front + 0.4, 2.2)
    pins = cq.Workplane("XY")
    for k in range(8):
        pins = pins.union(cq.Workplane("XY").center(k * 1.27 - (0.01 if k % 2 else 0), 0 if k % 2 == 0 else 2.54)
                          .circle(0.25).extrude(-3.05))
    for x in (-2.19, 0.35, 8.53, 11.06):
        pins = pins.union(cq.Workplane("XY").center(x, -11.26).circle(0.3).extrude(-3.05))
    for x in (-3.31, 12.19):
        pins = pins.union(cq.Workplane("XY").center(x, -3.31).rect(1.2, 0.3).extrude(-3.05))
    assy = cq.Assembly()
    assy.add(body, name="shield", color=cq.Color(0.75, 0.75, 0.72))
    assy.add(green, name="led green", color=cq.Color(0.1, 0.8, 0.1))
    assy.add(yellow, name="led yellow", color=cq.Color(0.9, 0.8, 0.1))
    assy.add(pins, name="pins", color=cq.Color(0.85, 0.75, 0.3))
    return assy


def usb_molex_105133():
    """Molex 105133-0001, vertical micro-B (sales drawing SD-105133-001 rev G), for the KiCad footprint
    USB_Micro-B_Molex-105133-0001 (origin: centre of the pads). Shell 8.0 x 3.1 mm, 6.7 mm above the
    board, cover tab 4.05 wide on one side (4.45 across); opening on top 6.90 x 1.85; shield legs 0.80 wide,
    2.30 below the board (DIM A of the -0001)."""
    shell = box(-4.0, -1.55, 0, 4.0, 1.55, 6.7).union(box(-2.025, 1.55, 0, 2.025, 2.9, 6.7))
    shell = shell.cut(cq.Workplane("XY").workplane(offset=6.7).rect(6.9, 1.85).extrude(-5.5))
    legs = cq.Workplane("XY")
    for x, y in ((-2.8, 1.07), (0.0, -1.07), (2.8, 1.07)):
        legs = legs.union(cq.Workplane("XY").center(x, y).rect(0.8, 0.3).extrude(-2.3))
    assy = cq.Assembly()
    assy.add(shell, name="shell", color=cq.Color(0.75, 0.75, 0.72))
    assy.add(legs, name="legs", color=cq.Color(0.75, 0.75, 0.72))
    return assy


def hdr_1x3_hx_pz254():
    """Hanxia HX PZ2.54-1x3P TP-YQ, SMD 1 x 3 header, type A (drawing PZ2.54-1xNP TP-YQ): insulator
    2.50 x 2.50 per pin, 7.62 long; square pins 0.64, 6.00 above the insulator; feet 5.00 mm across,
    pins 1 and 3 on one side, pin 2 on the other. Footprint origin: pin 2, row along y."""
    body = box(-1.25, -3.81, 0, 1.25, 3.81, 2.5)
    pins = cq.Workplane("XY")
    for n, y in ((1, 2.54), (2, 0.0), (3, -2.54)):              # model y = -footprint y
        pins = pins.union(box(-0.32, y - 0.32, 0, 0.32, y + 0.32, 8.5))
        foot = (-2.5, -0.32) if n != 2 else (0.32, 2.5)
        pins = pins.union(box(foot[0], y - 0.32, 0, foot[1], y + 0.32, 0.3))
    assy = cq.Assembly()
    assy.add(body, name="insulator", color=cq.Color(0.1, 0.1, 0.1))
    assy.add(pins, name="pins", color=cq.Color(0.85, 0.75, 0.3))
    return assy


def sw_xkb_ts1187a():
    """XKB TS-1187A-B-A-B tact switch (drawing TS-1187A-X-X-X rev A0): body 5.1 x 5.1, height code A,
    so 1.5 mm overall with the 2.0 mm keystake; terminals 6.5 mm across, 0.30 thick, at y = +-1.875."""
    body = box(-2.55, -2.55, 0, 2.55, 2.55, 1.2)
    key = cq.Workplane("XY").workplane(offset=1.2).circle(1.0).extrude(0.3)
    legs = cq.Workplane("XY")
    for x0, x1 in ((-3.25, -2.55), (2.55, 3.25)):
        for y in (-1.875, 1.875):
            legs = legs.union(box(x0, y - 0.35, 0, x1, y + 0.35, 0.3))
    assy = cq.Assembly()
    assy.add(body, name="body", color=cq.Color(0.75, 0.75, 0.72))
    assy.add(key, name="keystake", color=cq.Color(0.1, 0.1, 0.1))
    assy.add(legs, name="terminals", color=cq.Color(0.85, 0.85, 0.85))
    return assy


MODELS = {
    "RJ45x2_HongCheng_HC-WK88-H132-1X2-55B": rj45x2_hc_wk88,
    "RJ45_HanRun_HY911105AE": rj45_hy911105ae,
    "USB_Micro-B_Molex_105133-0001": usb_molex_105133,
    "PinHeader_1x03_P2.54mm_Vertical_SMD_HX_PZ254": hdr_1x3_hx_pz254,
    "SW_XKB_TS-1187A": sw_xkb_ts1187a,
}


def main():
    os.makedirs(OUT, exist_ok=True)
    for name, make in MODELS.items():
        assy = make()
        assy.export(os.path.join(OUT, name + ".step"))


if __name__ == "__main__":
    main()
