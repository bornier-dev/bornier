# Firmware

C++23 firmware on the OpSy RTOS (`third_party/opsy`), built with CMake and the GNU
Arm toolchain. Build, flashing and coding rules are in [CONTRIBUTING.md](../CONTRIBUTING.md).

The firmware is made of **modules**, each developed and tested on its own, and **images**
composed from a list of modules: an application, the test of one module, or a combined test
that checks several modules together. The composition is plain C++, resolved by the compiler:
see [Writing a module](#writing-a-module).

| Directory | Contents |
|---|---|
| `core/` | `app.hpp`: composition of an image from modules |
| `devices/` | Per-MCU generated register headers, and the linker script |
| `boards/` | Board support: the board's module, clock tree, drivers of the on-board peripherals, startup |
| `examples/` | Minimal images; `blink` is the reference module and image |
| `tests/` | Images for on-target tests, driven by the scripts in [`tools/hil/`](../tools/hil) |
| `third_party/` | OpSy, as a git submodule |

`CMakeLists.txt` here defines the targets every image builds on:

- `cortex_m33`: CPU, FPU and code generation options;
- `project_warnings`: the warning set, as errors (compiler and linker);
- `opsy`: the RTOS;
- `bornier_core` (in `core/`): the composition of images;
- `stm32h523` (in `devices/`);
- `board_base` (in `boards/`): the Bornier base board of [`hardware/base/`](../hardware/base).

An image links its board target and `project_warnings`; see `examples/blink/CMakeLists.txt`.

## Writing a module

A module is a class whose members are all `static`. It owns one block of the board (the RS-485
port, the supplies, the bus of the EtherCAT controller…) or one piece of behaviour built on
others. Every member is optional; [`core/app.hpp`](core/app.hpp) calls those it finds:

| Member | Called | For |
|---|---|---|
| `static void init()` | once, before the scheduler starts, in the order of the image's list | setting up the hardware |
| `static constexpr isrs` | at compile time, when the image's vector table is built | installing the module's interrupt handlers |
| `static bool start()` | once, after every `init()` | starting the module's tasks; `false` stops the image |

### Dependencies

A module that needs another takes it as a template parameter, constrained by a concept that the
module declares itself: it states what it needs, not which driver provides it. This is
constructor injection as in C#, resolved at compile time: no virtual call, no registry, and a
debugger shows the concrete types. A test can pass any other type that satisfies the concept.

[`examples/blink/blinker.hpp`](examples/blink/blinker.hpp), the reference module, needs a LED and
somewhere to write text:

```cpp
template<typename T>
concept switchable = requires { T::on(); T::off(); };

template<typename T>
concept text_output = requires(std::string_view text) { T::write(text); };

template<switchable Led, text_output Output>
class blinker
{
public:
    static bool start() { return task_.start(run); }

private:
    static void run();                       // blinks Led, writes one line per blink on Output
    static inline opsy::task<1024> task_;
};
```

### Interrupts

A module with interrupt handlers gives an installer, `isrs`, the same way OpSy places its own
(`opsy::scheduler::isrs`): a callable that takes the vector table and returns it with the module's
handlers in their slots.

```cpp
static constexpr auto isrs = []<typename Table>(const Table& table) -> Table
{
    return table.template with<STM32H523::EXTI5_IRQn, isr>();
};
```

The table is built at compile time and stays in flash. Two modules that claim the same slot do
not compile.

### Composing an image

An image lists its board's module first, then its modules in the order they must be initialised,
and defines its entry point, `application()` (see
[`boards/base/application.hpp`](boards/base/application.hpp)):

```cpp
#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <led.hpp>
#include <trace.hpp>

#include "blinker.hpp"

using namespace STM32H523;

using status_led = mcu_led;
using console    = trace;
using heartbeat  = example::blinker<status_led, console>;

using app = bornier::app<board, status_led, console, heartbeat>;

void application()
{
    app::run();
}
```

Each module gets an alias named by its role in the image (`status_led`, `console`, `heartbeat`):
the list of the app then reads as a list of modules, and swapping a driver, or a test double,
changes one line. An alias is the same type: it costs nothing and the debugger shows the module.

`app::run()` initialises the board then each module, starts the tasks, then starts the scheduler.
The image's vector table is `app::vectors`: the board's, with the handlers of every module. The
image's `CMakeLists.txt` is a plain `add_executable` linking the board target, as in
[`examples/blink/CMakeLists.txt`](examples/blink/CMakeLists.txt).

### Testing a module

A module comes with a test: an image that composes it with what it needs, and a script in
[`tools/hil/`](../tools/hil) that checks the report the image prints on SWO. Test images and
scripts follow [`tools/hil/README.md`](../tools/hil/README.md). A combined test composes several
modules in one image, to check that they work together.

## Adding a board

Create `boards/<board>/` with an INTERFACE target that links the device target and
`bornier_core`, provides the startup code as a source and adds the board directory to the include
path. Its module, `board.hpp`, gives `init()` and the base vector table, `vectors` (see
[`boards/base/board.hpp`](boards/base/board.hpp)). Then add the target to this directory's
`CMakeLists.txt`.
