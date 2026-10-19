# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Minimal reader and writer for KiCad S-expressions."""
import re

_TOKEN = re.compile(r'\s*(?:(\()|(\))|"((?:[^"\\]|\\.)*)"|([^\s()"]+))')


class Sym(str):
    """Unquoted atom (keyword, number)."""


def parse(text):
    stack, cur = [], []
    pos = 0
    n = len(text)
    while pos < n:
        m = _TOKEN.match(text, pos)
        if not m:
            if text[pos:].strip() == "":
                break
            raise ValueError(f"unreadable S-expression at {pos}: {text[pos:pos + 40]!r}")
        pos = m.end()
        op, cl, qs, at = m.groups()
        if op:
            stack.append(cur)
            cur = []
        elif cl:
            done = cur
            cur = stack.pop()
            cur.append(done)
        elif qs is not None:
            cur.append(qs.replace('\\"', '"').replace("\\\\", "\\"))
        elif at is not None:
            cur.append(Sym(at))
    return cur[0] if len(cur) == 1 else cur


def _atom(x):
    if isinstance(x, Sym):
        return str(x)
    if isinstance(x, (int, float)):
        s = f"{x:.4f}".rstrip("0").rstrip(".")
        return s if s not in ("-0", "") else "0"
    s = str(x).replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n")
    return f'"{s}"'


def dump(node, indent=0):
    if not isinstance(node, list):
        return _atom(node)
    pad = "\t" * indent
    if all(not isinstance(c, list) for c in node):
        return "(" + " ".join(_atom(c) for c in node) + ")"
    head = []
    for c in node:
        if isinstance(c, list):
            break
        head.append(_atom(c))
    out = "(" + " ".join(head)
    for c in node[len(head):]:
        out += "\n" + pad + "\t" + dump(c, indent + 1)
    return out + "\n" + pad + ")"


def find(node, key):
    return [c for c in node if isinstance(c, list) and c and c[0] == key]


def first(node, key):
    r = find(node, key)
    return r[0] if r else None
