# SPDX-License-Identifier: CERN-OHL-W-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Minimal access to the ngspice library shipped with KiCad ("shared ngspice" API)."""
import ctypes
import os
from ctypes import c_int, c_char_p, c_void_p, c_bool, c_double, POINTER, CFUNCTYPE, Structure

KICAD_BIN = next(p for p in (r"C:\Program Files\KiCad\10.0\bin",
                             os.path.expandvars(r"%LOCALAPPDATA%\Programs\KiCad\10.0\bin")) if os.path.isdir(p))
os.add_dll_directory(KICAD_BIN)
_lib = ctypes.CDLL(os.path.join(KICAD_BIN, "ngspice.dll"))


class _Complex(Structure):
    _fields_ = [("real", c_double), ("imag", c_double)]


class _VecInfo(Structure):
    _fields_ = [("v_name", c_char_p), ("v_type", c_int), ("v_flags", ctypes.c_short),
                ("v_realdata", POINTER(c_double)), ("v_compdata", POINTER(_Complex)), ("v_length", c_int)]


_log = []
_SendChar = CFUNCTYPE(c_int, c_char_p, c_int, c_void_p)
_SendStat = CFUNCTYPE(c_int, c_char_p, c_int, c_void_p)
_Exit = CFUNCTYPE(c_int, c_int, c_bool, c_bool, c_int, c_void_p)
_cb = [_SendChar(lambda s, i, p: (_log.append(s.decode(errors="replace")), 0)[1]),
       _SendStat(lambda s, i, p: 0), _Exit(lambda *a: 0)]
_lib.ngSpice_Init(_cb[0], _cb[1], _cb[2], None, None, None, None)
_lib.ngGet_Vec_Info.restype = POINTER(_VecInfo)
_lib.ngSpice_Command.argtypes = [c_char_p]


def cmd(c):
    _lib.ngSpice_Command(c.encode())


def run(netlist):
    """Load and run a netlist; return the ngspice log."""
    _log.clear()
    cmd("destroy all")
    lines = netlist.strip().splitlines()
    arr = (c_char_p * (len(lines) + 1))(*[ln.encode() for ln in lines], None)
    _lib.ngSpice_Circ(arr)
    cmd("run")
    return "\n".join(_log)


def vec(name):
    """Vector of the last analysis: list of floats, or of complex numbers for an AC analysis."""
    p = _lib.ngGet_Vec_Info(name.encode())
    if not p:
        raise KeyError(name)
    v = p.contents
    if v.v_realdata:
        return [v.v_realdata[i] for i in range(v.v_length)]
    return [complex(v.v_compdata[i].real, v.v_compdata[i].imag) for i in range(v.v_length)]
