"""What the emitted intent cannot read off the board: the isolated side of the Modbus port, the decap limit,
the legality budget. Run after every --emit-intent:  python edit_intent.py intent.json"""
import json
import sys

path = sys.argv[1]
d = json.load(open(path, encoding="utf-8"))
BUS = ["J13", "D66", "JP5", "R242", "R243", "R244", "R245", "R246", "C84", "C85", "C86"]
modbus = next(b for b in d["blocks"] if "U38" in b["refs"])
d["blocks"].remove(modbus)
d["blocks"].append({"name": "modbus logic side", "refs": [r for r in modbus["refs"] if r not in BUS],
                    "why": "the logic side of the isolated RS-485 transceiver U38 (its pins 1 to 8)"})
d["blocks"].append({"name": "modbus bus side", "refs": BUS, "zone": [26.0, 84.0, 47.5, 107.5], "exclusive": True,
                    "why": "functional isolation of the Modbus port (ground loop break): the bus side of U38 (pins 9 to 16) "
                           "with its terminal block, protection, termination and isolated supply caps, in a region of "
                           "its own; 1 mm between its copper and the rest (DRC rule 'Modbus isolation barrier')"})
d["decaps"] = {"max_distance_mm": 3.0}
d["legality_budget"] = {"overlap_area": 0.0, "oob_count": 0}
json.dump(d, open(path, "w", encoding="utf-8"), indent=1, ensure_ascii=False)
print("intent edited:", path)
