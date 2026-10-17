#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Delay block
 */
class dlyb_p {
public:

/**
 * control register
 */
class dlyb_cr_r {
public:

/**
 * Operational amplifier Enable
 */
class den_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr den_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dlyb_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dlyb_cr_r>() const {return opsy::utility::clear_set<dlyb_cr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cr_r other) const -> dlyb_cr_r { return static_cast<dlyb_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cr_r> other) const -> opsy::utility::clear_set<dlyb_cr_r> {return opsy::utility::clear_set<dlyb_cr_r>(dlyb_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OPALPM
 */
class sen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dlyb_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dlyb_cr_r>() const {return opsy::utility::clear_set<dlyb_cr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cr_r other) const -> dlyb_cr_r { return static_cast<dlyb_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cr_r> other) const -> opsy::utility::clear_set<dlyb_cr_r> {return opsy::utility::clear_set<dlyb_cr_r>(dlyb_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto den() const -> den_f {return den_f((value_ & den_f::mask) != 0);}
	[[nodiscard]] constexpr auto sen() const -> sen_f {return sen_f((value_ & sen_f::mask) != 0);}

	constexpr dlyb_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dlyb_cr_r other) const -> dlyb_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dlyb_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * configuration register
 */
class dlyb_cfgr_r {
public:

/**
 * SEL
 */
class sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dlyb_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dlyb_cfgr_r>() const {return opsy::utility::clear_set<dlyb_cfgr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cfgr_r other) const -> dlyb_cfgr_r { return static_cast<dlyb_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cfgr_r> other) const -> opsy::utility::clear_set<dlyb_cfgr_r> {return opsy::utility::clear_set<dlyb_cfgr_r>(dlyb_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UNIT
 */
class unit_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr unit_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dlyb_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dlyb_cfgr_r>() const {return opsy::utility::clear_set<dlyb_cfgr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cfgr_r other) const -> dlyb_cfgr_r { return static_cast<dlyb_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cfgr_r> other) const -> opsy::utility::clear_set<dlyb_cfgr_r> {return opsy::utility::clear_set<dlyb_cfgr_r>(dlyb_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LNG
 */
class lng_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lng_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dlyb_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dlyb_cfgr_r>() const {return opsy::utility::clear_set<dlyb_cfgr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cfgr_r other) const -> dlyb_cfgr_r { return static_cast<dlyb_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cfgr_r> other) const -> opsy::utility::clear_set<dlyb_cfgr_r> {return opsy::utility::clear_set<dlyb_cfgr_r>(dlyb_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * LNGF
 */
class lngf_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lngf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dlyb_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dlyb_cfgr_r>() const {return opsy::utility::clear_set<dlyb_cfgr_r>(mask, *this);}
	constexpr auto operator|(dlyb_cfgr_r other) const -> dlyb_cfgr_r { return static_cast<dlyb_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dlyb_cfgr_r> other) const -> opsy::utility::clear_set<dlyb_cfgr_r> {return opsy::utility::clear_set<dlyb_cfgr_r>(dlyb_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sel() const -> sel_f {return sel_f(static_cast<uint8_t>(value_ >> sel_f::offset));}
	[[nodiscard]] constexpr auto unit() const -> unit_f {return unit_f(static_cast<uint8_t>(value_ >> unit_f::offset));}
	[[nodiscard]] constexpr auto lng() const -> lng_f {return lng_f(static_cast<uint16_t>(value_ >> lng_f::offset));}
	[[nodiscard]] constexpr auto lngf() const -> lngf_f {return lngf_f((value_ & lngf_f::mask) != 0);}

	constexpr dlyb_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dlyb_cfgr_r other) const -> dlyb_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dlyb_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dlyb_cr_r> dlyb_cr;
	opsy::utility::memory<uint32_t,dlyb_cfgr_r> dlyb_cfgr;
};

static_assert(std::is_standard_layout_v<dlyb_p>);
static_assert(offsetof(dlyb_p, dlyb_cr) == 0);
static_assert(offsetof(dlyb_p, dlyb_cfgr) == 4);

inline dlyb_p& dlybos1 = *reinterpret_cast<dlyb_p*>(0x4600F000);
inline dlyb_p& dlybsd1 = *reinterpret_cast<dlyb_p*>(0x46008400);
inline dlyb_p& dlybsd2 = *reinterpret_cast<dlyb_p*>(0x46008800);
inline dlyb_p& sec_dlybos1 = *reinterpret_cast<dlyb_p*>(0x5600F000);
inline dlyb_p& sec_dlybsd1 = *reinterpret_cast<dlyb_p*>(0x56008400);
inline dlyb_p& sec_dlybsd2 = *reinterpret_cast<dlyb_p*>(0x56008800);

} // STM32H563

