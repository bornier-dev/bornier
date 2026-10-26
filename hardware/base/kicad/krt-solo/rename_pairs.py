"""Rename the Ethernet pairs into a form KiCadRoutingTools pairs, and back.

KRT pairs nets by a polarity suffix (_P/_N, P/N, +/-); the LAN9253 names put it inside (/ESC/TXPA, /ESC/TXNA).
Plain text substitution on the board and its project (net class patterns):
    python rename_pairs.py to-krt   BOARD.kicad_pcb ...
    python rename_pairs.py from-krt BOARD.kicad_pcb ...
"""
import sys

PAIRS = {f"/ESC/{d}{p}{c}": f"/ESC/{d}{c}_{p}" for d in ("TX", "RX") for p in ("P", "N") for c in ("A", "B")}

mode, boards = sys.argv[1], sys.argv[2:]
table = PAIRS if mode == "to-krt" else {v: k for k, v in PAIRS.items()}
for board in boards:
    for path in (board, board[:-len(".kicad_pcb")] + ".kicad_pro"):
        text = open(path, encoding="utf-8").read()
        for old, new in table.items():
            text = text.replace(f'"{old}"', f'"{new}"')
        open(path, "w", encoding="utf-8", newline="").write(text)
    print(f"{mode}: {board}")
