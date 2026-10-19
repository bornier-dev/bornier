# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Write the footprints of Bornier.pretty that KiCad does not ship, from the dimensions of their
datasheets (cited next to each value).

Usage: python gen_footprints.py
"""
import os

HERE = os.path.dirname(os.path.abspath(__file__))
LIB = os.path.join(HERE, "Bornier.pretty")


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
    ] + pads + [")"]) + "\n"


def tht(num, x, y, drill, size, shape="circle"):
    return (f'\t(pad "{num}" thru_hole {shape} (at {x:g} {y:g}) (size {size:g} {size:g}) (drill {drill:g}) '
            f'(layers "*.Cu" "*.Mask"))')


def rj45_hycw48():
    """HOAUC HYCW48-RJ45-163B, shielded RJ45 without magnetics or LEDs (drawing HYC-RJ16011509).

    PC board layout, component side: 8 pins drill 0.89 on a 1.02 mm pitch (1.02 x 7 = 7.14), in two
    rows 1.78 mm apart: pin 1 on the right of the front row, pin 8 on the left of the back row, so
    odd pins at y = 1.78 and even pins at y = 0. Two shield pins drill 1.8, 16.26 mm apart, 3.56 mm
    behind the locating pegs; two locating holes 3.25 mm, 12.7 mm apart, 4.32 mm in front of the
    back row. Body 16.26 wide, 15.75 deep, back face 5.4 mm behind the shield pins.
    Origin: centre of the back row; +y toward the opening (board edge).
    """
    out = []
    for n in range(1, 9):
        x = 3.57 - (n - 1) * 1.02
        y = 1.78 if n % 2 else 0.0
        out.append(tht(n, x, y, 0.89, 1.4, "rect" if n == 1 else "circle"))
    for x in (-8.13, 8.13):
        out.append(tht("SH", x, 0.76, 1.8, 2.6))
    for x in (-6.35, 6.35):
        out.append(f'\t(pad "" np_thru_hole circle (at {x:g} 4.32) (size 3.25 3.25) (drill 3.25) (layers "*.Cu" "*.Mask"))')
    back, front = 0.76 - 5.4, 0.76 - 5.4 + 15.75
    return "\n".join([
        '(footprint "RJ45_HOAUC_HYCW48-RJ45-163B"',
        '\t(version 20241229) (generator "gen_footprints") (layer "F.Cu")',
        '\t(descr "Shielded RJ45 without magnetics, HOAUC HYCW48-RJ45-163B; drawing HYC-RJ16011509")',
        '\t(attr through_hole)',
        f'\t(property "Reference" "REF**" (at 0 {back - 1.5:g} 0) (layer "F.SilkS") (effects (font (size 1 1) (thickness 0.15))))',
        f'\t(property "Value" "RJ45" (at 0 {front + 1.5:g} 0) (layer "F.Fab") (effects (font (size 1 1) (thickness 0.15))))',
        rect("F.Fab", -8.13, back, 8.13, front, 0.1),
        # silkscreen clear of the shield pads: back edge and the sides from y = 2.2 to the front
        f'\t(fp_line (start -6.8 {back - 0.12:g}) (end 6.8 {back - 0.12:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        f'\t(fp_line (start -8.25 2.2) (end -8.25 {front + 0.12:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        f'\t(fp_line (start 8.25 2.2) (end 8.25 {front + 0.12:g}) (stroke (width 0.12) (type solid)) (layer "F.SilkS"))',
        rect("F.CrtYd", -8.65, back - 0.5, 8.65, front + 0.5, 0.05),
    ] + out + [")"]) + "\n"


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
    ] + pads + [")"]) + "\n"


def main():
    os.makedirs(LIB, exist_ok=True)
    for name, text in (("SW_XKB_TS-1187A", sw_ts1187a()), ("RJ45_HOAUC_HYCW48-RJ45-163B", rj45_hycw48()),
                       ("PinHeader_1x03_P2.54mm_Vertical_SMD_HX_PZ254", hdr_1x3_smd())):
        with open(os.path.join(LIB, name + ".kicad_mod"), "w", encoding="utf-8", newline="\n") as f:
            f.write(text)


if __name__ == "__main__":
    main()
