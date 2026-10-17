# AGENTS.md

Entry point for AI coding agents. Everything an agent needs is in the human documentation:

1. [README.md](README.md): what Bornier is, licensing, Vendor ID.
2. [CONTRIBUTING.md](CONTRIBUTING.md): build, coding rules, flashing and debugging, pull requests.
3. The `README.md` of the directory you work in, for example
   [firmware/README.md](firmware/README.md) or [tools/hil/README.md](tools/hil/README.md).

Before reporting a change as done, check it the way CONTRIBUTING.md describes: both presets
build, and on-target tests pass on the debug and the release image when a board is connected.
