"""Version 2 of edit_intent.py: the Modbus island fixed by U38 and a keep-out, and one zone per axis.
Run after every --emit-intent:  python edit_intent2.py intent2.json [--no-axis-zones]"""
import json
import sys

path = sys.argv[1]
d = json.load(open(path, encoding="utf-8"))
BUS = ["J13", "D66", "JP5", "R242", "R243", "R244", "R245", "R246", "C84", "C85", "C86"]
ISLAND = [27.3, 86.0, 45.2, 107.5]
# drive k and encoder k under the RJ45 J(6+k); strips overlapping their neighbours by 1 mm (non-exclusive)
AXIS = {0: ("J6", "U22", [3.1, 0.0, 42.5, 60.0]), 1: ("J7", "U24", [41.5, 0.0, 75.5, 56.0]),
        2: ("J8", "U26", [74.5, 0.0, 108.5, 56.0]), 3: ("J9", "U28", [107.5, 0.0, 146.9, 60.0])}

modbus = next(b for b in d["blocks"] if "U38" in b["refs"])
d["blocks"].remove(modbus)
d["blocks"].append({"name": "modbus logic side", "refs": [r for r in modbus["refs"] if r not in BUS],
                    "why": "the logic side of the isolated RS-485 transceiver U38 (its pins 1 to 8, north of the barrier)"})
d["blocks"].append({"name": "modbus bus side", "refs": BUS, "zone": ISLAND,
                    "why": "functional isolation of the Modbus port (ground loop break): the bus side of U38 (pins 9 to 16) "
                           "with its terminal block, protection, termination and isolated supply caps, in the island; "
                           "the keep-out 'modbus isolated island' keeps every other part 1 mm away"})
for k, (jack, receiver, zone) in (AXIS.items() if "--no-axis-zones" not in sys.argv else ()):
    for b in d["blocks"]:
        if jack in b["refs"] or receiver in b["refs"]:
            b["zone"] = zone
            b["why"] = f"axis {k}: drive port A and encoder port B of {jack}, in the strip under that jack"
            b.pop("note", None)
d["decaps"] = {"max_distance_mm": 3.0}
d["legality_budget"] = {"overlap_area": 0.0, "oob_count": 0}
json.dump(d, open(path, "w", encoding="utf-8"), indent=1, ensure_ascii=False)
print("intent edited:", path)
