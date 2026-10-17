#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * System window watchdog
 */
class wwdg_p {
public:

/**
 * WWDG control register 
 */
class wwdg_cr_r {
public:

/**
 * 7-bit counter (MSB to LSB) These bits contain the value of the watchdog counter, decremented every (4096 x 2WDGTB[2:0]) PCLK cycles. A reset is produced when it is decremented from 0x40 to 0x3F (T6 becomes cleared).
 */
class t_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr t_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator wwdg_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<wwdg_cr_r>() const {return opsy::utility::clear_set<wwdg_cr_r>(mask, *this);}
	constexpr auto operator|(wwdg_cr_r other) const -> wwdg_cr_r { return static_cast<wwdg_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_cr_r> other) const -> opsy::utility::clear_set<wwdg_cr_r> {return opsy::utility::clear_set<wwdg_cr_r>(wwdg_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Activation bit This bit is set by software and only cleared by hardware after a reset. When WDGA = 1, the watchdog can generate a reset.
 */
class wdga_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wdga_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator wwdg_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<wwdg_cr_r>() const {return opsy::utility::clear_set<wwdg_cr_r>(mask, *this);}
	constexpr auto operator|(wwdg_cr_r other) const -> wwdg_cr_r { return static_cast<wwdg_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_cr_r> other) const -> opsy::utility::clear_set<wwdg_cr_r> {return opsy::utility::clear_set<wwdg_cr_r>(wwdg_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto t() const -> t_f {return t_f(static_cast<uint8_t>(value_ >> t_f::offset));}
	[[nodiscard]] constexpr auto wdga() const -> wdga_f {return wdga_f((value_ & wdga_f::mask) != 0);}

	constexpr wwdg_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(wwdg_cr_r other) const -> wwdg_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> wwdg_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111; // 127 0x7F

private:
	uint32_t value_;
};

/**
 * WWDG configuration register 
 */
class wwdg_cfr_r {
public:

/**
 * 7-bit window value These bits contain the window value to be compared with the down-counter.
 */
class w_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr w_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator wwdg_cfr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<wwdg_cfr_r>() const {return opsy::utility::clear_set<wwdg_cfr_r>(mask, *this);}
	constexpr auto operator|(wwdg_cfr_r other) const -> wwdg_cfr_r { return static_cast<wwdg_cfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_cfr_r> other) const -> opsy::utility::clear_set<wwdg_cfr_r> {return opsy::utility::clear_set<wwdg_cfr_r>(wwdg_cfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Early wakeup interrupt When set, an interrupt occurs whenever the counter reaches the value 0x40. This interrupt is only cleared by hardware after a reset.
 */
class ewi_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ewi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator wwdg_cfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<wwdg_cfr_r>() const {return opsy::utility::clear_set<wwdg_cfr_r>(mask, *this);}
	constexpr auto operator|(wwdg_cfr_r other) const -> wwdg_cfr_r { return static_cast<wwdg_cfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_cfr_r> other) const -> opsy::utility::clear_set<wwdg_cfr_r> {return opsy::utility::clear_set<wwdg_cfr_r>(wwdg_cfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timer base The timebase of the prescaler can be modified as follows:
 */
class wdgtb_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wdgtb_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator wwdg_cfr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<wwdg_cfr_r>() const {return opsy::utility::clear_set<wwdg_cfr_r>(mask, *this);}
	constexpr auto operator|(wwdg_cfr_r other) const -> wwdg_cfr_r { return static_cast<wwdg_cfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_cfr_r> other) const -> opsy::utility::clear_set<wwdg_cfr_r> {return opsy::utility::clear_set<wwdg_cfr_r>(wwdg_cfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto w() const -> w_f {return w_f(static_cast<uint8_t>(value_ >> w_f::offset));}
	[[nodiscard]] constexpr auto ewi() const -> ewi_f {return ewi_f((value_ & ewi_f::mask) != 0);}
	[[nodiscard]] constexpr auto wdgtb() const -> wdgtb_f {return wdgtb_f(static_cast<uint8_t>(value_ >> wdgtb_f::offset));}

	constexpr wwdg_cfr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(wwdg_cfr_r other) const -> wwdg_cfr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> wwdg_cfr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111; // 127 0x7F

private:
	uint32_t value_;
};

/**
 * WWDG status register 
 */
class wwdg_sr_r {
public:

/**
 * Early wakeup interrupt flag This bit is set by hardware when the counter has reached the value 0x40. It must be cleared by software by writing '0'. Writing '1' has no effect. This bit is also set if the interrupt is not enabled.
 */
class ewif_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ewif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator wwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<wwdg_sr_r>() const {return opsy::utility::clear_set<wwdg_sr_r>(mask, *this);}
	constexpr auto operator|(wwdg_sr_r other) const -> wwdg_sr_r { return static_cast<wwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<wwdg_sr_r> other) const -> opsy::utility::clear_set<wwdg_sr_r> {return opsy::utility::clear_set<wwdg_sr_r>(wwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ewif() const -> ewif_f {return ewif_f((value_ & ewif_f::mask) != 0);}

	constexpr wwdg_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(wwdg_sr_r other) const -> wwdg_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> wwdg_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,wwdg_cr_r> wwdg_cr;
	opsy::utility::memory<uint32_t,wwdg_cfr_r> wwdg_cfr;
	opsy::utility::memory<uint32_t,wwdg_sr_r> wwdg_sr;
};

static_assert(std::is_standard_layout_v<wwdg_p>);
static_assert(offsetof(wwdg_p, wwdg_cr) == 0);
static_assert(offsetof(wwdg_p, wwdg_cfr) == 4);
static_assert(offsetof(wwdg_p, wwdg_sr) == 8);

inline wwdg_p& sec_wwdg = *reinterpret_cast<wwdg_p*>(0x50002C00);
inline wwdg_p& wwdg = *reinterpret_cast<wwdg_p*>(0x40002C00);

} // STM32H563

