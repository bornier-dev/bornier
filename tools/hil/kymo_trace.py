#!/usr/bin/env python3
# SPDX-License-Identifier: MPL-2.0
# SPDX-FileCopyrightText: 2026 Thomas Legrand
"""Records the trace of a running board with Kymo, for the hardware-in-the-loop scripts.

Every image writes its events to a ring in RAM (firmware/trace/bornier/trace.hpp); `kymo record`
reads it through the debug port (SWD) while the program runs, and decodes each event with the
image's ELF. The board must already be flashed with that ELF and running.

A script calls add_arguments() on its parser, then record() with the parsed arguments and the
image's path under build/<preset>/firmware/.
"""

import argparse
import shutil
import subprocess
from dataclasses import dataclass, field
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


@dataclass
class Event:
    index: int
    seconds: float  # since the first event recorded, from the cycle counter
    name: str       # qualified name of the event's struct, e.g. example::blink
    fields: dict[str, str]

    def short(self) -> str:
        """The name without its namespaces."""
        return self.name.rsplit("::", 1)[-1]

    def number(self, name: str) -> int:
        """An integer field: kymo prints them in decimal, pointers in hexadecimal."""
        return int(self.fields[name], 0)

    def flag(self, name: str) -> bool:
        """A boolean field."""
        return self.fields[name] == "true"


@dataclass
class Recording:
    events: list[Event] = field(default_factory=list)
    lost: int = 0       # events the ring overwrote before the probe read them
    suspect: int = 0    # lines saying events near them may be wrong
    error: str = ""     # what kymo said when it failed, empty otherwise

    def named(self, name: str) -> list[Event]:
        """The events whose name, without its namespaces, is `name`."""
        return [event for event in self.events if event.short() == name]


def add_arguments(parser: argparse.ArgumentParser, seconds: float) -> None:
    """The options every script shares: the image, the probe and the recording time."""
    parser.add_argument("--preset", choices=("debug", "release"), default="debug",
                        help="build of the image flashed on the board (default debug)")
    parser.add_argument("--elf", help="image flashed on the board, instead of the one of --preset")
    parser.add_argument("--kymo", help="path of the kymo host program, if it is not on the PATH")
    parser.add_argument("--probe", default="jlink", choices=("jlink", "probe-rs"),
                        help="probe to record with (not the ST-Link: on the STM32H5 it reads zeros)")
    parser.add_argument("--chip", default="STM32H523VE")
    parser.add_argument("--clock", type=int, default=250_000_000, help="core clock of the image, in Hz")
    parser.add_argument("--seconds", type=float, default=seconds, help="recording time")


def image(args: argparse.Namespace, name: str) -> Path:
    """The ELF of the image: --elf, or build/<preset>/firmware/<name>.elf."""
    return Path(args.elf) if args.elf else ROOT / "build" / args.preset / "firmware" / f"{name}.elf"


def split_fields(text: str) -> dict[str, str]:
    """`a=1 b=[1,2] c={x=1 y=2}` into its fields, values kept as text."""
    fields: dict[str, str] = {}
    depth = 0
    start = 0
    for position, character in enumerate(text + " "):
        if character in "[{":
            depth += 1
        elif character in "]}":
            depth -= 1
        elif character == " " and depth == 0:
            token = text[start:position]
            start = position + 1
            if "=" in token:
                key, value = token.split("=", 1)
                fields[key] = value
    return fields


def parse(output: str) -> Recording:
    """The lines `kymo record` prints: `event <index> <cycles> <seconds> <type> <fields>`,
    `lost <from> <to>`, `suspect <from> <to> <n>`, and `record`/`end` around them."""
    recording = Recording()
    for line in output.splitlines():
        words = line.split(" ", 5)
        if words[0] == "event" and len(words) >= 5:
            recording.events.append(Event(index=int(words[1]),
                                          seconds=float(words[3]) if words[3] != "-" else 0.0,
                                          name=words[4],
                                          fields=split_fields(words[5]) if len(words) > 5 else {}))
        elif words[0] == "lost" and len(words) == 3:
            recording.lost += int(words[2]) - int(words[1])
        elif words[0] == "suspect":
            recording.suspect += 1
    return recording


def record(args: argparse.Namespace, elf: Path) -> Recording:
    """Records the running board for --seconds and returns what it traced."""
    kymo = args.kymo or shutil.which("kymo")
    if kymo is None:
        return Recording(error="kymo not found: build it (host/ of firmware/third_party/kymo, "
                               "cargo build --release) and put it on the PATH, or give --kymo")
    if not elf.exists():
        return Recording(error=f"{elf} not found: build the image, or give --elf")
    command = [kymo, "record", "--probe", args.probe, "--elf", str(elf), "--duration", str(args.seconds),
               "--clock", str(args.clock), "--chip", args.chip]
    result = subprocess.run(command, stdin=subprocess.DEVNULL, capture_output=True, text=True,
                            timeout=args.seconds + 60)
    recording = parse(result.stdout)
    if result.returncode != 0:
        recording.error = result.stderr.strip() or f"kymo exited with {result.returncode}"
    return recording


def report(recording: Recording) -> bool:
    """Prints the losses and the error of a recording; True when it can be judged."""
    if recording.error:
        print(f"FAIL  recording: {recording.error}")
        return False
    if recording.lost or recording.suspect:
        print(f"note  {recording.lost} events lost, {recording.suspect} suspect lines while recording")
    return True
