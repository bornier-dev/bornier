# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Write the footprints of Bornier.pretty that KiCad does not ship, from the dimensions of their
datasheets (cited next to each value).

Usage: python gen_footprints.py
"""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
LIB = os.path.join(HERE, "Bornier.pretty")
# 3D models written by gen_3d.py, found from the KiCad project of a board (hardware/<board>/kicad)
MODEL_DIR = "${KIPRJMOD}/../../lib/footprints/Bornier.3dshapes"


def model(name):
    return f'\t(model "{MODEL_DIR}/{name}.step" (offset (xyz 0 0 0)) (scale (xyz 1 1 1)) (rotate (xyz 0 0 0)))'


def rect(layer, x0, y0, x1, y1, width):
    return "\n".join(
        f'\t(fp_line (start {a} {b}) (end {c} {d}) (stroke (width {width}) (type solid)) (layer "{layer}"))'
        for a, b, c, d in ((x0, y0, x1, y0), (x1, y0, x1, y1), (x1, y1, x0, y1), (x0, y1, x0, y0)))


def sw_ts1187a():
    """XKB TS-1187A-B-A-B tact switch (datasheet drawing TS-1187A-X-X-X, revision A0).

    PCB layout (top view): pads 7.0 mm outer and 5.0 mm inner across, so 1.0 mm wide on a 6.0 mm
    pitch; 4.5 mm outer and 3.0 mm inner down, so 0.75 mm high on a 3.75 mm pitch. Body 5.1 x 5.1.
    Terminals A-B are joined, and C-D: pad 1 = A, B; pad 2 = C, D (one contact each side).
    """
    pads = []
    for num, y in (("1", -1.875), ("2", 1.875)):
        for x in (-3.0, 3.0):
            pads.append(f'\t(pad "{num}" smd rect (at {x} {y}) (size 1.0 0.75) (layers "F.Cu" "F.Paste" "F.Mask"))')
    body = 2.55
    return "\n".join([
        '(footprint "SW_XKB_TS-1187A"',
        '\t(version 20241229) (generator "gen_footprints") (layer "F.Cu")',
        '\t(descr "XKB TS-1187A tact switch, 5.1 x 5.1 mm, SMD; datasheet drawing TS-1187A-X-X-X")',
        '\t(attr smd)',
        '\t(property "Reference" "REF**" (at 0 -3.6 0) (layer "F.SilkS") (effects (font (size 1 1) (thickness 0.15))))',
        '\t(property "Value" "SW_XKB_TS-1187A" (at 0 3.6 0) (layer "F.Fab") (effects (font (size 1 1) (thickness 0.15))))',
        rect("F.Fab", -body, -body, body, body, 0.1),
        f'\t(fp_circle (center 0 0) (end 1.0 0) (stroke (width 0.1) (type solid)) (fill no) (layer "F.Fab"))',
        rect("F.SilkS", -2.65, -1.2, 2.65, 1.2, 0.12).split("\n")[1],
        rect("F.SilkS", -2.65, -1.2, 2.65, 1.2, 0.12).split("\n")[3],
        '\t(fp_line (start -1.8 -2.65) (end 1.8 -2.65) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        '\t(fp_line (start -1.8 2.65) (end 1.8 2.65) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        rect("F.CrtYd", -3.75, -2.85, 3.75, 2.85, 0.05),
    ] + pads + [model("SW_XKB_TS-1187A"), ")"]) + "\n"


def tht(num, x, y, drill, size, shape="circle"):
    return (f'\t(pad "{num}" thru_hole {shape} (at {x:g} {y:g}) (size {size:g} {size:g}) (drill {drill:g}) '
            f'(layers "*.Cu" "*.Mask"))')




def rj45x2_hc_wk88():
    """Hong Cheng HC-WK88-H132-1X2-55B, dual RJ45, shielded, without magnetics or LEDs (drawing
    HC-WK88-H132-1X2-55B rev A, recommended PCB layout, top view).

    Ports 14.10 mm apart. Per port, 8 contacts drill 1.00 in two rows 2.54 mm apart, 2.00 mm pitch in
    a row, rows offset by 1.00 mm: pin n at 4.5 - n mm from the port centre, odd pins in the front row
    (8.74 mm behind the front face), even pins in the back row. Two locating holes 3.20 mm, 25.60 mm
    apart, 6.30 mm behind the front face; two shield legs drill 1.70, 29.50 mm apart, 4.00 mm behind
    it. Body 29.70 wide, 13.20 deep, 13.50 high. Port A on the left, port B on the right (top view,
    front face down). Pad names: A1-A8, B1-B8, SH.
    Origin: centre of the front row; +y toward the front face (board edge).
    """
    front = 8.74
    out = []
    for port, cx in (("A", -7.05), ("B", 7.05)):
        for n in range(1, 9):
            y = 0.0 if n % 2 else -2.54
            out.append(tht(f"{port}{n}", cx + 4.5 - n, y, 1.0, 1.5, "rect" if n == 1 else "circle"))
    for x in (-14.75, 14.75):
        out.append(tht("SH", x, front - 4.0, 1.7, 2.2))     # 0.25 mm ring: 0.3 mm to the locating hole
    for x in (-12.8, 12.8):
        out.append(f'\t(pad "" np_thru_hole circle (at {x:g} {front - 6.3:g}) (size 3.2 3.2) (drill 3.2) (layers "*.Cu" "*.Mask"))')
    back, half = front - 13.2, 29.7 / 2
    name = "RJ45x2_HongCheng_HC-WK88-H132-1X2-55B"
    return "\n".join([
        f'(footprint "{name}"',
        '\t(version 20241229) (generator "gen_footprints") (layer "F.Cu")',
        '\t(descr "Dual RJ45, shielded, without magnetics or LEDs, Hong Cheng HC-WK88-H132-1X2-55B; drawing rev A")',
        '\t(attr through_hole)',
        f'\t(property "Reference" "REF**" (at 0 {back - 1.5:g} 0) (layer "F.SilkS") (effects (font (size 1 1) (thickness 0.15))))',
        f'\t(property "Value" "RJ45x2" (at 0 {front + 1.5:g} 0) (layer "F.Fab") (effects (font (size 1 1) (thickness 0.15))))',
        rect("F.Fab", -half, back, half, front, 0.1),
        # silkscreen: back edge, and the sides behind the shield legs
        f'\t(fp_line (start {-half - 0.12:g} {back - 0.12:g}) (end {half + 0.12:g} {back - 0.12:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        f'\t(fp_line (start {-half - 0.12:g} {back - 0.12:g}) (end {-half - 0.12:g} {front - 5.6:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        f'\t(fp_line (start {half + 0.12:g} {back - 0.12:g}) (end {half + 0.12:g} {front - 5.6:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        rect("F.CrtYd", -half - 0.5, back - 0.5, half + 0.5, front + 0.5, 0.05),
    ] + out + [
        model(name),
        ")"]) + "\n"


def hdr_1x3_smd():
    """Hanxia HX PZ2.54-1x3P TP-YQ, 1 x 3 pin header, 2.54 mm, SMD, type A (drawing PZ2.54-1xNP TP-YQ).

    Recommended PCB layout: pads 1.02 x 3.20, staggered, 6.40 mm across the outer ends, so centred
    1.6 mm either side of the row; feet 5.00 mm across; insulator 2.50 wide. The feet are staggered:
    pins 1 and 3 on one side, pin 2 on the other, so the header fits one way only. A header turned
    180 degrees puts its feet on the empty side: check the rotation of the JLCPCB model in the CPL
    (end feet on the pin 1 side, x < 0 here).
    Origin: pin 2 row centre; the row runs along y.
    """
    pads = [f'\t(pad "{n}" smd rect (at {x:g} {y:g}) (size 3.2 1.02) (layers "F.Cu" "F.Paste" "F.Mask"))'
            for n, x, y in (("1", -1.6, -2.54), ("2", 1.6, 0), ("3", -1.6, 2.54))]
    return "\n".join([
        '(footprint "PinHeader_1x03_P2.54mm_Vertical_SMD_HX_PZ254"',
        '\t(version 20241229) (generator "gen_footprints") (layer "F.Cu")',
        '\t(descr "1 x 3 pin header 2.54 mm, SMD, staggered pads, Hanxia HX PZ2.54-1x3P TP-YQ (type A)")',
        '\t(attr smd)',
        '\t(property "Reference" "REF**" (at 0 -4.6 0) (layer "F.SilkS") (effects (font (size 1 1) (thickness 0.15))))',
        '\t(property "Value" "1x3 SMD" (at 0 4.6 0) (layer "F.Fab") (effects (font (size 1 1) (thickness 0.15))))',
        rect("F.Fab", -1.25, -3.81, 1.25, 3.81, 0.1),
        '\t(fp_line (start -3.4 -3.3) (end -3.4 -1.7) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        rect("F.CrtYd", -3.7, -4.1, 3.7, 4.1, 0.05),
    ] + pads + [model("PinHeader_1x03_P2.54mm_Vertical_SMD_HX_PZ254"), ")"]) + "\n"


def main():
    os.makedirs(LIB, exist_ok=True)
    for name, text in (("SW_XKB_TS-1187A", sw_ts1187a()),
                       ("PinHeader_1x03_P2.54mm_Vertical_SMD_HX_PZ254", hdr_1x3_smd()),
                       ("RJ45x2_HongCheng_HC-WK88-H132-1X2-55B", rj45x2_hc_wk88())):
        with open(os.path.join(LIB, name + ".kicad_mod"), "w", encoding="utf-8", newline="\n") as f:
            f.write(text)


if __name__ == "__main__":
    main()
