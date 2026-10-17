#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Microcontroller debug unit
 */
class dbg_p {
public:

/**
 * DBGMCU identity code register
 */
class dbgmcu_idcode_r {
public:

/**
 * device identification
 */
class dev_id_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dev_id_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dbgmcu_idcode_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_idcode_r>() const {return opsy::utility::clear_set<dbgmcu_idcode_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_idcode_r other) const -> dbgmcu_idcode_r { return static_cast<dbgmcu_idcode_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_idcode_r> other) const -> opsy::utility::clear_set<dbgmcu_idcode_r> {return opsy::utility::clear_set<dbgmcu_idcode_r>(dbgmcu_idcode_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * revision
 */
class rev_id_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rev_id_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dbgmcu_idcode_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_idcode_r>() const {return opsy::utility::clear_set<dbgmcu_idcode_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_idcode_r other) const -> dbgmcu_idcode_r { return static_cast<dbgmcu_idcode_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_idcode_r> other) const -> opsy::utility::clear_set<dbgmcu_idcode_r> {return opsy::utility::clear_set<dbgmcu_idcode_r>(dbgmcu_idcode_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dev_id() const -> dev_id_f {return dev_id_f(static_cast<uint16_t>(value_ >> dev_id_f::offset));}
	[[nodiscard]] constexpr auto rev_id() const -> rev_id_f {return rev_id_f(static_cast<uint16_t>(value_ >> rev_id_f::offset));}

	constexpr dbgmcu_idcode_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_idcode_r other) const -> dbgmcu_idcode_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_idcode_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b110000000000000; // 24576 0x6000

private:
	uint32_t value_;
};

/**
 * DBGMCU configuration register
 */
class dbgmcu_cr_r {
public:

/**
 * Allows debug in Stop mode All clocks are disabled automatically in Stop mode. All active clocks and oscillators continue to run during Stop mode, allowing full debug capability. On exit from Stop mode, the clock settings are set to the Stop mode exit state.
 */
class dbg_stop_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Allows debug in Standby mode All clocks are disabled and the core powered down automatically in Standby mode. All active clocks and oscillators continue to run during Standby mode, and the core supply is maintained, allowing full debug capability. On exit from Standby mode, a system reset is performed.
 */
class dbg_standby_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_standby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trace pin enable
 */
class trace_ioen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr trace_ioen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trace port and clock enable. This bit enables the trace port clock, TRACECK.
 */
class trace_en_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr trace_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trace pin assignment
 */
class trace_mode_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trace_mode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Debug credentials reset type This bit selects which type of reset is used to revoke the debug authentication credentials
 */
class dcrt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_cr_r>() const {return opsy::utility::clear_set<dbgmcu_cr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return static_cast<dbgmcu_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cr_r> other) const -> opsy::utility::clear_set<dbgmcu_cr_r> {return opsy::utility::clear_set<dbgmcu_cr_r>(dbgmcu_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_stop() const -> dbg_stop_f {return dbg_stop_f((value_ & dbg_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_standby() const -> dbg_standby_f {return dbg_standby_f((value_ & dbg_standby_f::mask) != 0);}
	[[nodiscard]] constexpr auto trace_ioen() const -> trace_ioen_f {return trace_ioen_f((value_ & trace_ioen_f::mask) != 0);}
	[[nodiscard]] constexpr auto trace_en() const -> trace_en_f {return trace_en_f((value_ & trace_en_f::mask) != 0);}
	[[nodiscard]] constexpr auto trace_mode() const -> trace_mode_f {return trace_mode_f(static_cast<uint8_t>(value_ >> trace_mode_f::offset));}
	[[nodiscard]] constexpr auto dcrt() const -> dcrt_f {return dcrt_f((value_ & dcrt_f::mask) != 0);}

	constexpr dbgmcu_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_cr_r other) const -> dbgmcu_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU APB1L peripheral freeze register
 */
class dbgmcu_apb1lfzr_r {
public:

/**
 * TIM2 stop in debug
 */
class dbg_tim2_stop_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim2_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM3 stop in debug
 */
class dbg_tim3_stop_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim3_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM4 stop in debug
 */
class dbg_tim4_stop_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim4_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM5 stop in debug
 */
class dbg_tim5_stop_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim5_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM6 stop in debug
 */
class dbg_tim6_stop_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim6_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM7 stop in debug
 */
class dbg_tim7_stop_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim7_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM12 stop in debug
 */
class dbg_tim12_stop_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim12_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM13 stop in debug
 */
class dbg_tim13_stop_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_tim13_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM14 stop in debug
 */
class dbg_tim14_stop_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_tim14_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WWDG stop in debug
 */
class dbg_wwdg_stop_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_wwdg_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG stop in debug
 */
class dbg_iwdg_stop_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_iwdg_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C1 SMBUS timeout stop in debug
 */
class dbg_i2c1_stop_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_i2c1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C2 SMBUS timeout stop in debug
 */
class dbg_i2c2_stop_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_i2c2_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I3C1 SCL stall counter stop in debug
 */
class dbg_i3c1_stop_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_i3c1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1lfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1lfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return static_cast<dbgmcu_apb1lfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1lfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1lfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1lfzr_r>(dbgmcu_apb1lfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_tim2_stop() const -> dbg_tim2_stop_f {return dbg_tim2_stop_f((value_ & dbg_tim2_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim3_stop() const -> dbg_tim3_stop_f {return dbg_tim3_stop_f((value_ & dbg_tim3_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim4_stop() const -> dbg_tim4_stop_f {return dbg_tim4_stop_f((value_ & dbg_tim4_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim5_stop() const -> dbg_tim5_stop_f {return dbg_tim5_stop_f((value_ & dbg_tim5_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim6_stop() const -> dbg_tim6_stop_f {return dbg_tim6_stop_f((value_ & dbg_tim6_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim7_stop() const -> dbg_tim7_stop_f {return dbg_tim7_stop_f((value_ & dbg_tim7_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim12_stop() const -> dbg_tim12_stop_f {return dbg_tim12_stop_f((value_ & dbg_tim12_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim13_stop() const -> dbg_tim13_stop_f {return dbg_tim13_stop_f((value_ & dbg_tim13_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim14_stop() const -> dbg_tim14_stop_f {return dbg_tim14_stop_f((value_ & dbg_tim14_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_wwdg_stop() const -> dbg_wwdg_stop_f {return dbg_wwdg_stop_f((value_ & dbg_wwdg_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_iwdg_stop() const -> dbg_iwdg_stop_f {return dbg_iwdg_stop_f((value_ & dbg_iwdg_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_i2c1_stop() const -> dbg_i2c1_stop_f {return dbg_i2c1_stop_f((value_ & dbg_i2c1_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_i2c2_stop() const -> dbg_i2c2_stop_f {return dbg_i2c2_stop_f((value_ & dbg_i2c2_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_i3c1_stop() const -> dbg_i3c1_stop_f {return dbg_i3c1_stop_f((value_ & dbg_i3c1_stop_f::mask) != 0);}

	constexpr dbgmcu_apb1lfzr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_apb1lfzr_r other) const -> dbgmcu_apb1lfzr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_apb1lfzr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU APB1H peripheral freeze register
 */
class dbgmcu_apb1hfzr_r {
public:

/**
 * LPTIM2 stop in debug
 */
class dbg_lptim2_stop_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_lptim2_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb1hfzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb1hfzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb1hfzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb1hfzr_r other) const -> dbgmcu_apb1hfzr_r { return static_cast<dbgmcu_apb1hfzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb1hfzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb1hfzr_r> {return opsy::utility::clear_set<dbgmcu_apb1hfzr_r>(dbgmcu_apb1hfzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_lptim2_stop() const -> dbg_lptim2_stop_f {return dbg_lptim2_stop_f((value_ & dbg_lptim2_stop_f::mask) != 0);}

	constexpr dbgmcu_apb1hfzr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_apb1hfzr_r other) const -> dbgmcu_apb1hfzr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_apb1hfzr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU APB2 peripheral freeze register
 */
class dbgmcu_apb2fzr_r {
public:

/**
 * TIM1 stop in debug
 */
class dbg_tim1_stop_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_tim1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb2fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb2fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return static_cast<dbgmcu_apb2fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb2fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb2fzr_r> {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(dbgmcu_apb2fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM8 stop in debug
 */
class dbg_tim8_stop_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_tim8_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb2fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb2fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return static_cast<dbgmcu_apb2fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb2fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb2fzr_r> {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(dbgmcu_apb2fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM15 stop in debug
 */
class dbg_tim15_stop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_tim15_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb2fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb2fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return static_cast<dbgmcu_apb2fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb2fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb2fzr_r> {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(dbgmcu_apb2fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM16 stop in debug
 */
class dbg_tim16_stop_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_tim16_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb2fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb2fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return static_cast<dbgmcu_apb2fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb2fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb2fzr_r> {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(dbgmcu_apb2fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM17 stop in debug
 */
class dbg_tim17_stop_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_tim17_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb2fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb2fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return static_cast<dbgmcu_apb2fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb2fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb2fzr_r> {return opsy::utility::clear_set<dbgmcu_apb2fzr_r>(dbgmcu_apb2fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_tim1_stop() const -> dbg_tim1_stop_f {return dbg_tim1_stop_f((value_ & dbg_tim1_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim8_stop() const -> dbg_tim8_stop_f {return dbg_tim8_stop_f((value_ & dbg_tim8_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim15_stop() const -> dbg_tim15_stop_f {return dbg_tim15_stop_f((value_ & dbg_tim15_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim16_stop() const -> dbg_tim16_stop_f {return dbg_tim16_stop_f((value_ & dbg_tim16_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_tim17_stop() const -> dbg_tim17_stop_f {return dbg_tim17_stop_f((value_ & dbg_tim17_stop_f::mask) != 0);}

	constexpr dbgmcu_apb2fzr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_apb2fzr_r other) const -> dbgmcu_apb2fzr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_apb2fzr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU APB3 peripheral freeze register
 */
class dbgmcu_apb3fzr_r {
public:

/**
 * I2C3 SMBUS timeout stop in debug
 */
class dbg_i2c3_stop_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_i2c3_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C4 SMBUS timeout stop in debug
 */
class dbg_i2c4_stop_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_i2c4_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM1 stop in debug
 */
class dbg_lptim1_stop_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_lptim1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM3 stop in debug
 */
class dbg_lptim3_stop_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_lptim3_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM4 stop in debug
 */
class dbg_lptim4_stop_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_lptim4_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM5 stop in debug
 */
class dbg_lptim5_stop_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_lptim5_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM6 stop in debug
 */
class dbg_lptim6_stop_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_lptim6_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC stop in debug
 */
class dbg_rtc_stop_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_rtc_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_apb3fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_apb3fzr_r>() const {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return static_cast<dbgmcu_apb3fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_apb3fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_apb3fzr_r> {return opsy::utility::clear_set<dbgmcu_apb3fzr_r>(dbgmcu_apb3fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_i2c3_stop() const -> dbg_i2c3_stop_f {return dbg_i2c3_stop_f((value_ & dbg_i2c3_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_i2c4_stop() const -> dbg_i2c4_stop_f {return dbg_i2c4_stop_f((value_ & dbg_i2c4_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_lptim1_stop() const -> dbg_lptim1_stop_f {return dbg_lptim1_stop_f((value_ & dbg_lptim1_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_lptim3_stop() const -> dbg_lptim3_stop_f {return dbg_lptim3_stop_f((value_ & dbg_lptim3_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_lptim4_stop() const -> dbg_lptim4_stop_f {return dbg_lptim4_stop_f((value_ & dbg_lptim4_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_lptim5_stop() const -> dbg_lptim5_stop_f {return dbg_lptim5_stop_f((value_ & dbg_lptim5_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_lptim6_stop() const -> dbg_lptim6_stop_f {return dbg_lptim6_stop_f((value_ & dbg_lptim6_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_rtc_stop() const -> dbg_rtc_stop_f {return dbg_rtc_stop_f((value_ & dbg_rtc_stop_f::mask) != 0);}

	constexpr dbgmcu_apb3fzr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_apb3fzr_r other) const -> dbgmcu_apb3fzr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_apb3fzr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU AHB1 peripheral freeze register
 */
class dbgmcu_ahb1fzr_r {
public:

/**
 * GPDMA1 channel 0 stop in debug
 */
class dbg_gpdma1_0_stop_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_0_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 1 stop in debug
 */
class dbg_gpdma1_1_stop_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 2 stop in debug
 */
class dbg_gpdma1_2_stop_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_2_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 3 stop in debug
 */
class dbg_gpdma1_3_stop_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_3_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 4 stop in debug
 */
class dbg_gpdma1_4_stop_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_4_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 5 stop in debug
 */
class dbg_gpdma1_5_stop_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_5_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 6 stop in debug
 */
class dbg_gpdma1_6_stop_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_6_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 7 stop in debug
 */
class dbg_gpdma1_7_stop_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbg_gpdma1_7_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 8 stop in debug
 */
class dbg_gpdma1_8_stop_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_8_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 9 stop in debug
 */
class dbg_gpdma1_9_stop_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_9_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 10 stop in debug
 */
class dbg_gpdma1_10_stop_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_10_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 11 stop in debug
 */
class dbg_gpdma1_11_stop_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_11_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 12 stop in debug
 */
class dbg_gpdma1_12_stop_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_12_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 13 stop in debug
 */
class dbg_gpdma1_13_stop_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_13_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 14 stop in debug
 */
class dbg_gpdma1_14_stop_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_14_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA1 channel 15 stop in debug
 */
class dbg_gpdma1_15_stop_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbg_gpdma1_15_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 0 stop in debug
 */
class dbg_gpdma2_0_stop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_0_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 1 stop in debug
 */
class dbg_gpdma2_1_stop_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_1_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 2 stop in debug
 */
class dbg_gpdma2_2_stop_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_2_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 3 stop in debug
 */
class dbg_gpdma2_3_stop_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_3_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 4 stop in debug
 */
class dbg_gpdma2_4_stop_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_4_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 5 stop in debug
 */
class dbg_gpdma2_5_stop_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_5_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 6 stop in debug
 */
class dbg_gpdma2_6_stop_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_6_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 7 stop in debug
 */
class dbg_gpdma2_7_stop_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_7_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 8 stop in debug
 */
class dbg_gpdma2_8_stop_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_8_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 9 stop in debug
 */
class dbg_gpdma2_9_stop_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_9_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 10 stop in debug
 */
class dbg_gpdma2_10_stop_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_10_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 11 stop in debug
 */
class dbg_gpdma2_11_stop_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_11_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 12 stop in debug
 */
class dbg_gpdma2_12_stop_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_12_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 13 stop in debug
 */
class dbg_gpdma2_13_stop_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_13_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 14 stop in debug
 */
class dbg_gpdma2_14_stop_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_14_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 channel 15 stop in debug
 */
class dbg_gpdma2_15_stop_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbg_gpdma2_15_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_ahb1fzr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_ahb1fzr_r>() const {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return static_cast<dbgmcu_ahb1fzr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_ahb1fzr_r> other) const -> opsy::utility::clear_set<dbgmcu_ahb1fzr_r> {return opsy::utility::clear_set<dbgmcu_ahb1fzr_r>(dbgmcu_ahb1fzr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbg_gpdma1_0_stop() const -> dbg_gpdma1_0_stop_f {return dbg_gpdma1_0_stop_f((value_ & dbg_gpdma1_0_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_1_stop() const -> dbg_gpdma1_1_stop_f {return dbg_gpdma1_1_stop_f((value_ & dbg_gpdma1_1_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_2_stop() const -> dbg_gpdma1_2_stop_f {return dbg_gpdma1_2_stop_f((value_ & dbg_gpdma1_2_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_3_stop() const -> dbg_gpdma1_3_stop_f {return dbg_gpdma1_3_stop_f((value_ & dbg_gpdma1_3_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_4_stop() const -> dbg_gpdma1_4_stop_f {return dbg_gpdma1_4_stop_f((value_ & dbg_gpdma1_4_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_5_stop() const -> dbg_gpdma1_5_stop_f {return dbg_gpdma1_5_stop_f((value_ & dbg_gpdma1_5_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_6_stop() const -> dbg_gpdma1_6_stop_f {return dbg_gpdma1_6_stop_f((value_ & dbg_gpdma1_6_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_7_stop() const -> dbg_gpdma1_7_stop_f {return dbg_gpdma1_7_stop_f((value_ & dbg_gpdma1_7_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_8_stop() const -> dbg_gpdma1_8_stop_f {return dbg_gpdma1_8_stop_f((value_ & dbg_gpdma1_8_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_9_stop() const -> dbg_gpdma1_9_stop_f {return dbg_gpdma1_9_stop_f((value_ & dbg_gpdma1_9_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_10_stop() const -> dbg_gpdma1_10_stop_f {return dbg_gpdma1_10_stop_f((value_ & dbg_gpdma1_10_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_11_stop() const -> dbg_gpdma1_11_stop_f {return dbg_gpdma1_11_stop_f((value_ & dbg_gpdma1_11_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_12_stop() const -> dbg_gpdma1_12_stop_f {return dbg_gpdma1_12_stop_f((value_ & dbg_gpdma1_12_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_13_stop() const -> dbg_gpdma1_13_stop_f {return dbg_gpdma1_13_stop_f((value_ & dbg_gpdma1_13_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_14_stop() const -> dbg_gpdma1_14_stop_f {return dbg_gpdma1_14_stop_f((value_ & dbg_gpdma1_14_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma1_15_stop() const -> dbg_gpdma1_15_stop_f {return dbg_gpdma1_15_stop_f((value_ & dbg_gpdma1_15_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_0_stop() const -> dbg_gpdma2_0_stop_f {return dbg_gpdma2_0_stop_f((value_ & dbg_gpdma2_0_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_1_stop() const -> dbg_gpdma2_1_stop_f {return dbg_gpdma2_1_stop_f((value_ & dbg_gpdma2_1_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_2_stop() const -> dbg_gpdma2_2_stop_f {return dbg_gpdma2_2_stop_f((value_ & dbg_gpdma2_2_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_3_stop() const -> dbg_gpdma2_3_stop_f {return dbg_gpdma2_3_stop_f((value_ & dbg_gpdma2_3_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_4_stop() const -> dbg_gpdma2_4_stop_f {return dbg_gpdma2_4_stop_f((value_ & dbg_gpdma2_4_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_5_stop() const -> dbg_gpdma2_5_stop_f {return dbg_gpdma2_5_stop_f((value_ & dbg_gpdma2_5_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_6_stop() const -> dbg_gpdma2_6_stop_f {return dbg_gpdma2_6_stop_f((value_ & dbg_gpdma2_6_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_7_stop() const -> dbg_gpdma2_7_stop_f {return dbg_gpdma2_7_stop_f((value_ & dbg_gpdma2_7_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_8_stop() const -> dbg_gpdma2_8_stop_f {return dbg_gpdma2_8_stop_f((value_ & dbg_gpdma2_8_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_9_stop() const -> dbg_gpdma2_9_stop_f {return dbg_gpdma2_9_stop_f((value_ & dbg_gpdma2_9_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_10_stop() const -> dbg_gpdma2_10_stop_f {return dbg_gpdma2_10_stop_f((value_ & dbg_gpdma2_10_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_11_stop() const -> dbg_gpdma2_11_stop_f {return dbg_gpdma2_11_stop_f((value_ & dbg_gpdma2_11_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_12_stop() const -> dbg_gpdma2_12_stop_f {return dbg_gpdma2_12_stop_f((value_ & dbg_gpdma2_12_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_13_stop() const -> dbg_gpdma2_13_stop_f {return dbg_gpdma2_13_stop_f((value_ & dbg_gpdma2_13_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_14_stop() const -> dbg_gpdma2_14_stop_f {return dbg_gpdma2_14_stop_f((value_ & dbg_gpdma2_14_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbg_gpdma2_15_stop() const -> dbg_gpdma2_15_stop_f {return dbg_gpdma2_15_stop_f((value_ & dbg_gpdma2_15_stop_f::mask) != 0);}

	constexpr dbgmcu_ahb1fzr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_ahb1fzr_r other) const -> dbgmcu_ahb1fzr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_ahb1fzr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU status register
 */
class dbgmcu_sr_r {
public:

/**
 * Bit n identifies whether access port AP n is present in device Bit n = 0: APn absent Bit n = 1: APn present
 */
class ap_present_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ap_present_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dbgmcu_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_sr_r>() const {return opsy::utility::clear_set<dbgmcu_sr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_sr_r other) const -> dbgmcu_sr_r { return static_cast<dbgmcu_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_sr_r> other) const -> opsy::utility::clear_set<dbgmcu_sr_r> {return opsy::utility::clear_set<dbgmcu_sr_r>(dbgmcu_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Bit n identifies whether access port AP n is open (can be accessed via the debug port) or locked (debug access to the AP is blocked) Bit n = 0: APn locked Bit n = 1: APn enabled
 */
class ap_enabled_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ap_enabled_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dbgmcu_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_sr_r>() const {return opsy::utility::clear_set<dbgmcu_sr_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_sr_r other) const -> dbgmcu_sr_r { return static_cast<dbgmcu_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_sr_r> other) const -> opsy::utility::clear_set<dbgmcu_sr_r> {return opsy::utility::clear_set<dbgmcu_sr_r>(dbgmcu_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ap_present() const -> ap_present_f {return ap_present_f(static_cast<uint16_t>(value_ >> ap_present_f::offset));}
	[[nodiscard]] constexpr auto ap_enabled() const -> ap_enabled_f {return ap_enabled_f(static_cast<uint16_t>(value_ >> ap_enabled_f::offset));}

	constexpr dbgmcu_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_sr_r other) const -> dbgmcu_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000011; // 65539 0x10003

private:
	uint32_t value_;
};

/**
 * DBGMCU debug authentication mailbox host register
 */
class dbgmcu_dbg_auth_host_r {
public:

/**
 * Debug host to device mailbox message. During debug authentication the debug host communicates with the device via this register.
 */
class message_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr message_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dbgmcu_dbg_auth_host_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_dbg_auth_host_r>() const {return opsy::utility::clear_set<dbgmcu_dbg_auth_host_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_dbg_auth_host_r other) const -> dbgmcu_dbg_auth_host_r { return static_cast<dbgmcu_dbg_auth_host_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_dbg_auth_host_r> other) const -> opsy::utility::clear_set<dbgmcu_dbg_auth_host_r> {return opsy::utility::clear_set<dbgmcu_dbg_auth_host_r>(dbgmcu_dbg_auth_host_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto message() const -> message_f {return message_f(static_cast<uint32_t>(value_ >> message_f::offset));}

	constexpr dbgmcu_dbg_auth_host_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_dbg_auth_host_r other) const -> dbgmcu_dbg_auth_host_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_dbg_auth_host_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU debug authentication mailbox device register
 */
class dbgmcu_dbg_auth_device_r {
public:

/**
 * Device to debug host mailbox message. During debug authentication the device communicates with the debug host via this register.
 */
class message_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr message_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dbgmcu_dbg_auth_device_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_dbg_auth_device_r>() const {return opsy::utility::clear_set<dbgmcu_dbg_auth_device_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_dbg_auth_device_r other) const -> dbgmcu_dbg_auth_device_r { return static_cast<dbgmcu_dbg_auth_device_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_dbg_auth_device_r> other) const -> opsy::utility::clear_set<dbgmcu_dbg_auth_device_r> {return opsy::utility::clear_set<dbgmcu_dbg_auth_device_r>(dbgmcu_dbg_auth_device_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto message() const -> message_f {return message_f(static_cast<uint32_t>(value_ >> message_f::offset));}

	constexpr dbgmcu_dbg_auth_device_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_dbg_auth_device_r other) const -> dbgmcu_dbg_auth_device_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_dbg_auth_device_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU debug authentication mailbox acknowledge register
 */
class dbgmcu_dbg_auth_ack_r {
public:

/**
 * Host to device acknowledge. The device sets this bit to indicate that it has placed a message in the DBGMCU_DBG_AUTH_DEVICE register. It should be reset by the host after reading the message
 */
class host_ack_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr host_ack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_dbg_auth_ack_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>() const {return opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_dbg_auth_ack_r other) const -> dbgmcu_dbg_auth_ack_r { return static_cast<dbgmcu_dbg_auth_ack_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r> other) const -> opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r> {return opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>(dbgmcu_dbg_auth_ack_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device to device acknowledge. The host sets this bit to indicate that it has placed a message in the DBGMCU_DBG_AUTH_HOST register. It is reset by the device after reading the message
 */
class dev_ack_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dev_ack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_dbg_auth_ack_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>() const {return opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_dbg_auth_ack_r other) const -> dbgmcu_dbg_auth_ack_r { return static_cast<dbgmcu_dbg_auth_ack_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r> other) const -> opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r> {return opsy::utility::clear_set<dbgmcu_dbg_auth_ack_r>(dbgmcu_dbg_auth_ack_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto host_ack() const -> host_ack_f {return host_ack_f((value_ & host_ack_f::mask) != 0);}
	[[nodiscard]] constexpr auto dev_ack() const -> dev_ack_f {return dev_ack_f((value_ & dev_ack_f::mask) != 0);}

	constexpr dbgmcu_dbg_auth_ack_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_dbg_auth_ack_r other) const -> dbgmcu_dbg_auth_ack_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_dbg_auth_ack_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight peripheral identity register 4
 */
class dbgmcu_pidr4_r {
public:

/**
 * JEP106 continuation code
 */
class jep106con_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr jep106con_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr4_r>() const {return opsy::utility::clear_set<dbgmcu_pidr4_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr4_r other) const -> dbgmcu_pidr4_r { return static_cast<dbgmcu_pidr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr4_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr4_r> {return opsy::utility::clear_set<dbgmcu_pidr4_r>(dbgmcu_pidr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * register file size
 */
class size_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr size_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr4_r>() const {return opsy::utility::clear_set<dbgmcu_pidr4_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr4_r other) const -> dbgmcu_pidr4_r { return static_cast<dbgmcu_pidr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr4_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr4_r> {return opsy::utility::clear_set<dbgmcu_pidr4_r>(dbgmcu_pidr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto jep106con() const -> jep106con_f {return jep106con_f(static_cast<uint8_t>(value_ >> jep106con_f::offset));}
	[[nodiscard]] constexpr auto size() const -> size_f {return size_f(static_cast<uint8_t>(value_ >> size_f::offset));}

	constexpr dbgmcu_pidr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_pidr4_r other) const -> dbgmcu_pidr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_pidr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight peripheral identity register 0
 */
class dbgmcu_pidr0_r {
public:

/**
 * part number bits [7:0]
 */
class partnum_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr partnum_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr0_r>() const {return opsy::utility::clear_set<dbgmcu_pidr0_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr0_r other) const -> dbgmcu_pidr0_r { return static_cast<dbgmcu_pidr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr0_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr0_r> {return opsy::utility::clear_set<dbgmcu_pidr0_r>(dbgmcu_pidr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto partnum() const -> partnum_f {return partnum_f(static_cast<uint8_t>(value_ >> partnum_f::offset));}

	constexpr dbgmcu_pidr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_pidr0_r other) const -> dbgmcu_pidr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_pidr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight peripheral identity register 1
 */
class dbgmcu_pidr1_r {
public:

/**
 * part number bits [11:8]
 */
class partnum_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr partnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr1_r>() const {return opsy::utility::clear_set<dbgmcu_pidr1_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr1_r other) const -> dbgmcu_pidr1_r { return static_cast<dbgmcu_pidr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr1_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr1_r> {return opsy::utility::clear_set<dbgmcu_pidr1_r>(dbgmcu_pidr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * JEP106 identity code bits [3:0]
 */
class jep106id_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr jep106id_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr1_r>() const {return opsy::utility::clear_set<dbgmcu_pidr1_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr1_r other) const -> dbgmcu_pidr1_r { return static_cast<dbgmcu_pidr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr1_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr1_r> {return opsy::utility::clear_set<dbgmcu_pidr1_r>(dbgmcu_pidr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto partnum() const -> partnum_f {return partnum_f(static_cast<uint8_t>(value_ >> partnum_f::offset));}
	[[nodiscard]] constexpr auto jep106id() const -> jep106id_f {return jep106id_f(static_cast<uint8_t>(value_ >> jep106id_f::offset));}

	constexpr dbgmcu_pidr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_pidr1_r other) const -> dbgmcu_pidr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_pidr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight peripheral identity register 2
 */
class dbgmcu_pidr2_r {
public:

/**
 * JEP106 identity code bits [6:4]
 */
class jep106id_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr jep106id_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr2_r>() const {return opsy::utility::clear_set<dbgmcu_pidr2_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr2_r other) const -> dbgmcu_pidr2_r { return static_cast<dbgmcu_pidr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr2_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr2_r> {return opsy::utility::clear_set<dbgmcu_pidr2_r>(dbgmcu_pidr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * JEDEC assigned value
 */
class jedec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jedec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dbgmcu_pidr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr2_r>() const {return opsy::utility::clear_set<dbgmcu_pidr2_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr2_r other) const -> dbgmcu_pidr2_r { return static_cast<dbgmcu_pidr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr2_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr2_r> {return opsy::utility::clear_set<dbgmcu_pidr2_r>(dbgmcu_pidr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * component revision number
 */
class revision_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr revision_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr2_r>() const {return opsy::utility::clear_set<dbgmcu_pidr2_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr2_r other) const -> dbgmcu_pidr2_r { return static_cast<dbgmcu_pidr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr2_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr2_r> {return opsy::utility::clear_set<dbgmcu_pidr2_r>(dbgmcu_pidr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto jep106id() const -> jep106id_f {return jep106id_f(static_cast<uint8_t>(value_ >> jep106id_f::offset));}
	[[nodiscard]] constexpr auto jedec() const -> jedec_f {return jedec_f((value_ & jedec_f::mask) != 0);}
	[[nodiscard]] constexpr auto revision() const -> revision_f {return revision_f(static_cast<uint8_t>(value_ >> revision_f::offset));}

	constexpr dbgmcu_pidr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_pidr2_r other) const -> dbgmcu_pidr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_pidr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1010; // 10 0xA

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight peripheral identity register 3
 */
class dbgmcu_pidr3_r {
public:

/**
 * customer modified
 */
class cmod_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cmod_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr3_r>() const {return opsy::utility::clear_set<dbgmcu_pidr3_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr3_r other) const -> dbgmcu_pidr3_r { return static_cast<dbgmcu_pidr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr3_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr3_r> {return opsy::utility::clear_set<dbgmcu_pidr3_r>(dbgmcu_pidr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * metal fix version
 */
class revand_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr revand_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_pidr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_pidr3_r>() const {return opsy::utility::clear_set<dbgmcu_pidr3_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_pidr3_r other) const -> dbgmcu_pidr3_r { return static_cast<dbgmcu_pidr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_pidr3_r> other) const -> opsy::utility::clear_set<dbgmcu_pidr3_r> {return opsy::utility::clear_set<dbgmcu_pidr3_r>(dbgmcu_pidr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cmod() const -> cmod_f {return cmod_f(static_cast<uint8_t>(value_ >> cmod_f::offset));}
	[[nodiscard]] constexpr auto revand() const -> revand_f {return revand_f(static_cast<uint8_t>(value_ >> revand_f::offset));}

	constexpr dbgmcu_pidr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_pidr3_r other) const -> dbgmcu_pidr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_pidr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight component identity register 0
 */
class dbgmcu_cidr0_r {
public:

/**
 * component identification bits [7:0]
 */
class preamble_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr preamble_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cidr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cidr0_r>() const {return opsy::utility::clear_set<dbgmcu_cidr0_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cidr0_r other) const -> dbgmcu_cidr0_r { return static_cast<dbgmcu_cidr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cidr0_r> other) const -> opsy::utility::clear_set<dbgmcu_cidr0_r> {return opsy::utility::clear_set<dbgmcu_cidr0_r>(dbgmcu_cidr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto preamble() const -> preamble_f {return preamble_f(static_cast<uint8_t>(value_ >> preamble_f::offset));}

	constexpr dbgmcu_cidr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_cidr0_r other) const -> dbgmcu_cidr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_cidr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1101; // 13 0xD

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight component identity register 1
 */
class dbgmcu_cidr1_r {
public:

/**
 * component identification bits [11:8]
 */
class preamble_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr preamble_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cidr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cidr1_r>() const {return opsy::utility::clear_set<dbgmcu_cidr1_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cidr1_r other) const -> dbgmcu_cidr1_r { return static_cast<dbgmcu_cidr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cidr1_r> other) const -> opsy::utility::clear_set<dbgmcu_cidr1_r> {return opsy::utility::clear_set<dbgmcu_cidr1_r>(dbgmcu_cidr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * component identification bits [15:12]component class
 */
class class_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr class_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cidr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cidr1_r>() const {return opsy::utility::clear_set<dbgmcu_cidr1_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cidr1_r other) const -> dbgmcu_cidr1_r { return static_cast<dbgmcu_cidr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cidr1_r> other) const -> opsy::utility::clear_set<dbgmcu_cidr1_r> {return opsy::utility::clear_set<dbgmcu_cidr1_r>(dbgmcu_cidr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto preamble() const -> preamble_f {return preamble_f(static_cast<uint8_t>(value_ >> preamble_f::offset));}
	[[nodiscard]] constexpr auto _class() const -> class_f {return class_f(static_cast<uint8_t>(value_ >> class_f::offset));}

	constexpr dbgmcu_cidr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_cidr1_r other) const -> dbgmcu_cidr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_cidr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11110000; // 240 0xF0

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight component identity register 2
 */
class dbgmcu_cidr2_r {
public:

/**
 * component identification bits [23:16]
 */
class preamble_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr preamble_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cidr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cidr2_r>() const {return opsy::utility::clear_set<dbgmcu_cidr2_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cidr2_r other) const -> dbgmcu_cidr2_r { return static_cast<dbgmcu_cidr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cidr2_r> other) const -> opsy::utility::clear_set<dbgmcu_cidr2_r> {return opsy::utility::clear_set<dbgmcu_cidr2_r>(dbgmcu_cidr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto preamble() const -> preamble_f {return preamble_f(static_cast<uint8_t>(value_ >> preamble_f::offset));}

	constexpr dbgmcu_cidr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_cidr2_r other) const -> dbgmcu_cidr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_cidr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b101; // 5 0x5

private:
	uint32_t value_;
};

/**
 * DBGMCU CoreSight component identity register 3
 */
class dbgmcu_cidr3_r {
public:

/**
 * component identification bits [31:24]
 */
class preamble_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr preamble_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dbgmcu_cidr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dbgmcu_cidr3_r>() const {return opsy::utility::clear_set<dbgmcu_cidr3_r>(mask, *this);}
	constexpr auto operator|(dbgmcu_cidr3_r other) const -> dbgmcu_cidr3_r { return static_cast<dbgmcu_cidr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dbgmcu_cidr3_r> other) const -> opsy::utility::clear_set<dbgmcu_cidr3_r> {return opsy::utility::clear_set<dbgmcu_cidr3_r>(dbgmcu_cidr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto preamble() const -> preamble_f {return preamble_f(static_cast<uint8_t>(value_ >> preamble_f::offset));}

	constexpr dbgmcu_cidr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dbgmcu_cidr3_r other) const -> dbgmcu_cidr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dbgmcu_cidr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10110001; // 177 0xB1

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dbgmcu_idcode_r> dbgmcu_idcode;
	opsy::utility::memory<uint32_t,dbgmcu_cr_r> dbgmcu_cr;
	opsy::utility::memory<uint32_t,dbgmcu_apb1lfzr_r> dbgmcu_apb1lfzr;
	opsy::utility::memory<uint32_t,dbgmcu_apb1hfzr_r> dbgmcu_apb1hfzr;
	opsy::utility::memory<uint32_t,dbgmcu_apb2fzr_r> dbgmcu_apb2fzr;
	opsy::utility::memory<uint32_t,dbgmcu_apb3fzr_r> dbgmcu_apb3fzr;
	opsy::utility::padding<8> _p0;
	opsy::utility::memory<uint32_t,dbgmcu_ahb1fzr_r> dbgmcu_ahb1fzr;
	opsy::utility::padding<216> _p1;
	opsy::utility::memory<uint32_t,dbgmcu_sr_r> dbgmcu_sr;
	opsy::utility::memory<uint32_t,dbgmcu_dbg_auth_host_r> dbgmcu_dbg_auth_host;
	opsy::utility::memory<uint32_t,dbgmcu_dbg_auth_device_r> dbgmcu_dbg_auth_device;
	opsy::utility::memory<uint32_t,dbgmcu_dbg_auth_ack_r> dbgmcu_dbg_auth_ack;
	opsy::utility::padding<3780> _p2;
	opsy::utility::memory<uint32_t,dbgmcu_pidr4_r> dbgmcu_pidr4;
	opsy::utility::padding<12> _p3;
	opsy::utility::memory<uint32_t,dbgmcu_pidr0_r> dbgmcu_pidr0;
	opsy::utility::memory<uint32_t,dbgmcu_pidr1_r> dbgmcu_pidr1;
	opsy::utility::memory<uint32_t,dbgmcu_pidr2_r> dbgmcu_pidr2;
	opsy::utility::memory<uint32_t,dbgmcu_pidr3_r> dbgmcu_pidr3;
	opsy::utility::memory<uint32_t,dbgmcu_cidr0_r> dbgmcu_cidr0;
	opsy::utility::memory<uint32_t,dbgmcu_cidr1_r> dbgmcu_cidr1;
	opsy::utility::memory<uint32_t,dbgmcu_cidr2_r> dbgmcu_cidr2;
	opsy::utility::memory<uint32_t,dbgmcu_cidr3_r> dbgmcu_cidr3;
};

static_assert(std::is_standard_layout_v<dbg_p>);
static_assert(offsetof(dbg_p, dbgmcu_idcode) == 0);
static_assert(offsetof(dbg_p, dbgmcu_cr) == 4);
static_assert(offsetof(dbg_p, dbgmcu_apb1lfzr) == 8);
static_assert(offsetof(dbg_p, dbgmcu_apb1hfzr) == 12);
static_assert(offsetof(dbg_p, dbgmcu_apb2fzr) == 16);
static_assert(offsetof(dbg_p, dbgmcu_apb3fzr) == 20);
static_assert(offsetof(dbg_p, dbgmcu_ahb1fzr) == 32);
static_assert(offsetof(dbg_p, dbgmcu_sr) == 252);
static_assert(offsetof(dbg_p, dbgmcu_dbg_auth_host) == 256);
static_assert(offsetof(dbg_p, dbgmcu_dbg_auth_device) == 260);
static_assert(offsetof(dbg_p, dbgmcu_dbg_auth_ack) == 264);
static_assert(offsetof(dbg_p, dbgmcu_pidr4) == 4048);
static_assert(offsetof(dbg_p, dbgmcu_pidr0) == 4064);
static_assert(offsetof(dbg_p, dbgmcu_pidr1) == 4068);
static_assert(offsetof(dbg_p, dbgmcu_pidr2) == 4072);
static_assert(offsetof(dbg_p, dbgmcu_pidr3) == 4076);
static_assert(offsetof(dbg_p, dbgmcu_cidr0) == 4080);
static_assert(offsetof(dbg_p, dbgmcu_cidr1) == 4084);
static_assert(offsetof(dbg_p, dbgmcu_cidr2) == 4088);
static_assert(offsetof(dbg_p, dbgmcu_cidr3) == 4092);

inline dbg_p& dbgmcu = *reinterpret_cast<dbg_p*>(0x44024000);

} // STM32H563

