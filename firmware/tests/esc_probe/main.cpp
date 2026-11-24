// SPDX-License-Identifier: MPL-2.0
// SPDX-FileCopyrightText: 2026 Thomas Legrand
//
// On-target test for the Bornier base board: talks to the LAN9253 through the OCTOSPI and reports
// in the trace (bornier/trace.hpp), once per second. The same checks run in both bus modes,
// single then quad:
//
//   byte_test   must read 0x87654321: the bus works and the byte order is right.
//   id_rev      must read 0x9253 in its upper half: the chip is a LAN9253.
//   user_ram    two patterns written to the user RAM of the EtherCAT core (0x0F80) must read
//               back, as 32 bits then as 16 and 8 bits: register writes and core accesses work.
//
// Single mode passing and quad mode failing points at SIO2 or SIO3.
//
// Traced for information:
//   hw_cfg         READY (bit 27) stays 0 until the configuration has been loaded from the SII
//                  EEPROM, which this board emulates: the firmware has to serve it.
//   core_type      first registers of the EtherCAT core: type, revision, build.
//   core_product   product ID of the EtherCAT core.
//   core_al_event  AL event request; bit 5 is a pending request to the EEPROM emulation.
//   core_eeprom    EEPROM configuration (low half) and status (high half); in the status,
//                  bit 5 tells that the EEPROM is emulated and bit 15 that a request waits.
//   timing         CPU cycles at 250 MHz of a register read and of a core read.

#include <application.hpp>
#include <app.hpp>
#include <board.hpp>
#include <bornier/trace.hpp>
#include <opsy.hpp>
#include <cortex_m.hpp>
#include <scheduler.hpp>
#include <clock.hpp>
#include <esc_bus.hpp>
#include <led.hpp>

#include <chrono>
#include <cstdint>

using namespace std::chrono_literals;
using namespace STM32H523;

namespace
{

/// Nothing to put in a safe state in this test: a failure of the bus shows in its verdict.
struct no_outputs
{
	static void fault() {}
};
using bus = esc_bus<no_outputs>;

} // namespace

/// The events of the test, as `kymo record` prints them: esc_probe::<name>.
namespace esc_probe
{

enum class bus_mode : uint8_t { single, quad };

/** @brief A new round of checks starts in @p mode. */
struct mode_start { bus_mode mode; };

/** @brief The registers of the bus itself, read first. */
struct registers { uint32_t byte_test; uint32_t id_rev; uint32_t hw_cfg; };

/** @brief The first registers of the EtherCAT core, read once the bus is proven. */
struct core { uint32_t type; uint32_t product; uint32_t al_event; uint32_t eeprom; };

/** @brief A pattern written to the user RAM of the core, and what read back in 32, 16, 8 bits. */
struct user_ram { uint32_t pattern; uint32_t whole; uint32_t upper; uint32_t byte1; };

/** @brief Mean CPU cycles of a register read and of a core read, upper bounds. */
struct timing { uint32_t read_cycles; uint32_t core_read_cycles; };

/** @brief The result of the checks in one mode. */
struct mode_result { bus_mode mode; bool pass; };

/** @brief The result of a round, both modes. */
struct verdict { bool pass; bus::failure bus_failure; };

/** @brief The LAN9253 did not come out of its reset. */
struct reset_failed {};

} // namespace esc_probe

namespace
{

using trace = bornier::trace;

constexpr uint16_t core_type     = 0x0000; // type, revision, build (2 bytes)
constexpr uint16_t core_al_event = 0x0220;
constexpr uint16_t core_eeprom   = 0x0500;
constexpr uint16_t core_product  = 0x0E00;
constexpr uint16_t core_user_ram = 0x0F80;

// Writes a pattern to the user RAM and reads it back in the three access sizes.
bool user_ram_holds(uint32_t pattern)
{
	bus::core_write(core_user_ram, pattern, 4);
	const esc_probe::user_ram read{
		.pattern = pattern,
		.whole   = bus::core_read(core_user_ram, 4),
		.upper   = bus::core_read(static_cast<uint16_t>(core_user_ram + 2), 2),
		.byte1   = bus::core_read(static_cast<uint16_t>(core_user_ram + 1), 1),
	};
	trace::emit(read);
	return read.whole == pattern && read.upper == pattern >> 16 && read.byte1 == ((pattern >> 8) & 0xFFu);
}

// Runs all the checks in the current bus mode.
bool bus_works()
{
	const esc_probe::registers registers{
		.byte_test = bus::read(bus::byte_test),
		.id_rev    = bus::read(bus::id_rev),
		.hw_cfg    = bus::read(bus::hw_cfg),
	};
	trace::emit(registers);

	// The core is only reached once the bus itself is proven: a core access polls the chip,
	// and would never end on a dead bus.
	if (registers.byte_test != 0x87654321u || (registers.id_rev >> 16) != 0x9253u)
		return false;

	trace::emit(esc_probe::core{
		.type     = bus::core_read(core_type, 4),
		.product  = bus::core_read(core_product, 4),
		.al_event = bus::core_read(core_al_event, 4),
		.eeprom   = bus::core_read(core_eeprom, 4),
	});
	const bool first  = user_ram_holds(0xA5C33C5Au);
	const bool second = user_ram_holds(0x5A3CC3A5u);
	return first && second;
}

// Traces the mean duration, in CPU cycles at 250 MHz, of a register read and of a read of the
// EtherCAT core (CSR command, polling until done, data). Measured over 100 accesses with the
// DWT cycle counter; the task may be preempted meanwhile, so these are upper bounds.
void trace_timing()
{
	constexpr uint32_t count = 100;

	uint32_t start = opsy::cortex_m::cycle_count();
	for (uint32_t i = 0; i < count; ++i)
		(void)bus::read(bus::byte_test);
	const uint32_t read_cycles = (opsy::cortex_m::cycle_count() - start) / count;

	start = opsy::cortex_m::cycle_count();
	for (uint32_t i = 0; i < count; ++i)
		(void)bus::core_read(core_type, 4);
	const uint32_t core_read_cycles = (opsy::cortex_m::cycle_count() - start) / count;

	trace::emit(esc_probe::timing{read_cycles, core_read_cycles});
}

// The checks in one mode, traced.
bool check(bus::mode mode, esc_probe::bus_mode name)
{
	bus::set_mode(mode);
	trace::emit(esc_probe::mode_start{name});
	const bool pass = bus_works();
	if (pass)
		trace_timing();
	trace::emit(esc_probe::mode_result{name, pass});
	return pass;
}

} // namespace

/** @brief The test, as a module: one task that runs the checks and reports in the trace. */
class esc_probe_test
{
public:
	static bool start()
	{
		return task_.start([]{
			// Back to compatibility mode, the one this test checks, whatever PDI an earlier
			// image left the LAN9253 in: without the stack, nothing loads its configuration.
			if (!bus::reset())
				trace::emit(esc_probe::reset_failed{});
			while (true)
			{
				const bool single = check(bus::mode::single, esc_probe::bus_mode::single);
				const bool quad   = check(bus::mode::quad, esc_probe::bus_mode::quad);
				const bool pass   = single && quad;
				trace::emit(esc_probe::verdict{pass, bus::failed()});

				if (pass)
					mcu_led::on();
				else
					mcu_led::off();
				opsy::sleep_for(1s);
			}
		});
	}

private:
	static inline opsy::task<1024> task_;
};

using status_led = mcu_led;
using esc        = bus;

using app = bornier::app<board, status_led, esc, esc_probe_test>;

void application()
{
	app::run();
}
