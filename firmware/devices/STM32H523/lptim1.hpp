#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * LPTIM1 address block description
 */
class lptim1_p {
public:

/**
 * LPTIM1 interrupt and status register [alternate]
 */
class lptim1_isr_r {
public:

/**
 * Compare 1 interrupt flag 
 */
class cc1if_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match 
 */
class arrm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger edge event 
 */
class exttrig_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK 
 */
class cmp1ok_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1ok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK 
 */
class arrok_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change down to up 
 */
class up_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr up_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change up to down 
 */
class down_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr down_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM update event occurred 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK 
 */
class repok_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare 2 interrupt flag 
 */
class cc2if_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 2 update OK 
 */
class cmp2ok_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmp2ok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK 
 */
class dierok_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_r>() const {return opsy::utility::clear_set<lptim1_isr_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_r other) const -> lptim1_isr_r { return static_cast<lptim1_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_r> other) const -> opsy::utility::clear_set<lptim1_isr_r> {return opsy::utility::clear_set<lptim1_isr_r>(lptim1_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrm() const -> arrm_f {return arrm_f((value_ & arrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrig() const -> exttrig_f {return exttrig_f((value_ & exttrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1ok() const -> cmp1ok_f {return cmp1ok_f((value_ & cmp1ok_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrok() const -> arrok_f {return arrok_f((value_ & arrok_f::mask) != 0);}
	[[nodiscard]] constexpr auto up() const -> up_f {return up_f((value_ & up_f::mask) != 0);}
	[[nodiscard]] constexpr auto down() const -> down_f {return down_f((value_ & down_f::mask) != 0);}
	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto repok() const -> repok_f {return repok_f((value_ & repok_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2if() const -> cc2if_f {return cc2if_f((value_ & cc2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp2ok() const -> cmp2ok_f {return cmp2ok_f((value_ & cmp2ok_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierok() const -> dierok_f {return dierok_f((value_ & dierok_f::mask) != 0);}

	constexpr lptim1_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_isr_r other) const -> lptim1_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM1 interrupt and status register
 */
class lptim1_isr_alternate1_r {
public:

/**
 * capture 1 interrupt flag 
 */
class cc1if_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match 
 */
class arrm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger edge event 
 */
class exttrig_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK 
 */
class arrok_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change down to up 
 */
class up_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr up_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change up to down 
 */
class down_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr down_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM update event occurred 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK 
 */
class repok_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 2 interrupt flag 
 */
class cc2if_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 1 over-capture flag 
 */
class cc1of_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 2 over-capture flag 
 */
class cc2of_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK 
 */
class dierok_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_isr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return static_cast<lptim1_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_isr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_isr_alternate1_r> {return opsy::utility::clear_set<lptim1_isr_alternate1_r>(lptim1_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrm() const -> arrm_f {return arrm_f((value_ & arrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrig() const -> exttrig_f {return exttrig_f((value_ & exttrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrok() const -> arrok_f {return arrok_f((value_ & arrok_f::mask) != 0);}
	[[nodiscard]] constexpr auto up() const -> up_f {return up_f((value_ & up_f::mask) != 0);}
	[[nodiscard]] constexpr auto down() const -> down_f {return down_f((value_ & down_f::mask) != 0);}
	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto repok() const -> repok_f {return repok_f((value_ & repok_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2if() const -> cc2if_f {return cc2if_f((value_ & cc2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1of() const -> cc1of_f {return cc1of_f((value_ & cc1of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2of() const -> cc2of_f {return cc2of_f((value_ & cc2of_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierok() const -> dierok_f {return dierok_f((value_ & dierok_f::mask) != 0);}

	constexpr lptim1_isr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_isr_alternate1_r other) const -> lptim1_isr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_isr_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM1 interrupt clear register [alternate]
 */
class lptim1_icr_r {
public:

/**
 * Capture/compare 1 clear flag 
 */
class cc1cf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match clear flag 
 */
class arrmcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge clear flag 
 */
class exttrigcf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK clear flag 
 */
class cmp1okcf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1okcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK clear flag 
 */
class arrokcf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP clear flag 
 */
class upcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down clear flag 
 */
class downcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event clear flag 
 */
class uecf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK clear flag 
 */
class repokcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 clear flag 
 */
class cc2cf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 2 update OK clear flag 
 */
class cmp2okcf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmp2okcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK clear flag 
 */
class dierokcf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_r>() const {return opsy::utility::clear_set<lptim1_icr_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_r other) const -> lptim1_icr_r { return static_cast<lptim1_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_r> other) const -> opsy::utility::clear_set<lptim1_icr_r> {return opsy::utility::clear_set<lptim1_icr_r>(lptim1_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1cf() const -> cc1cf_f {return cc1cf_f((value_ & cc1cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmcf() const -> arrmcf_f {return arrmcf_f((value_ & arrmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigcf() const -> exttrigcf_f {return exttrigcf_f((value_ & exttrigcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1okcf() const -> cmp1okcf_f {return cmp1okcf_f((value_ & cmp1okcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokcf() const -> arrokcf_f {return arrokcf_f((value_ & arrokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto upcf() const -> upcf_f {return upcf_f((value_ & upcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto downcf() const -> downcf_f {return downcf_f((value_ & downcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto uecf() const -> uecf_f {return uecf_f((value_ & uecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokcf() const -> repokcf_f {return repokcf_f((value_ & repokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2cf() const -> cc2cf_f {return cc2cf_f((value_ & cc2cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp2okcf() const -> cmp2okcf_f {return cmp2okcf_f((value_ & cmp2okcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierokcf() const -> dierokcf_f {return dierokcf_f((value_ & dierokcf_f::mask) != 0);}

	constexpr lptim1_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_icr_r other) const -> lptim1_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM1 interrupt clear register
 */
class lptim1_icr_alternate1_r {
public:

/**
 * Capture/compare 1 clear flag 
 */
class cc1cf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match clear flag 
 */
class arrmcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge clear flag 
 */
class exttrigcf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK clear flag 
 */
class arrokcf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP clear flag 
 */
class upcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down clear flag 
 */
class downcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event clear flag 
 */
class uecf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK clear flag 
 */
class repokcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 clear flag 
 */
class cc2cf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 over-capture clear flag 
 */
class cc1ocf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1ocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 over-capture clear flag 
 */
class cc2ocf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2ocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK clear flag 
 */
class dierokcf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_icr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_icr_alternate1_r>() const {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return static_cast<lptim1_icr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_icr_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_icr_alternate1_r> {return opsy::utility::clear_set<lptim1_icr_alternate1_r>(lptim1_icr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1cf() const -> cc1cf_f {return cc1cf_f((value_ & cc1cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmcf() const -> arrmcf_f {return arrmcf_f((value_ & arrmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigcf() const -> exttrigcf_f {return exttrigcf_f((value_ & exttrigcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokcf() const -> arrokcf_f {return arrokcf_f((value_ & arrokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto upcf() const -> upcf_f {return upcf_f((value_ & upcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto downcf() const -> downcf_f {return downcf_f((value_ & downcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto uecf() const -> uecf_f {return uecf_f((value_ & uecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokcf() const -> repokcf_f {return repokcf_f((value_ & repokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2cf() const -> cc2cf_f {return cc2cf_f((value_ & cc2cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1ocf() const -> cc1ocf_f {return cc1ocf_f((value_ & cc1ocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ocf() const -> cc2ocf_f {return cc2ocf_f((value_ & cc2ocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierokcf() const -> dierokcf_f {return dierokcf_f((value_ & dierokcf_f::mask) != 0);}

	constexpr lptim1_icr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_icr_alternate1_r other) const -> lptim1_icr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_icr_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM1 interrupt enable register [alternate]
 */
class lptim1_dier_r {
public:

/**
 * Capture/compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match Interrupt Enable
 */
class arrmie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge Interrupt Enable
 */
class exttrigie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK interrupt enable
 */
class cmp1okie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1okie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK Interrupt Enable
 */
class arrokie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP Interrupt Enable 
 */
class upie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down Interrupt Enable 
 */
class downie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event interrupt enable
 */
class ueie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ueie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK interrupt Enable
 */
class repokie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 interrupt enable 
 */
class cc2ie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 2 update OK interrupt enable 
 */
class cmp2okie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmp2okie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event DMA request enable 
 */
class uede_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uede_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_r>() const {return opsy::utility::clear_set<lptim1_dier_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_r other) const -> lptim1_dier_r { return static_cast<lptim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_r> other) const -> opsy::utility::clear_set<lptim1_dier_r> {return opsy::utility::clear_set<lptim1_dier_r>(lptim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmie() const -> arrmie_f {return arrmie_f((value_ & arrmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigie() const -> exttrigie_f {return exttrigie_f((value_ & exttrigie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1okie() const -> cmp1okie_f {return cmp1okie_f((value_ & cmp1okie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokie() const -> arrokie_f {return arrokie_f((value_ & arrokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto upie() const -> upie_f {return upie_f((value_ & upie_f::mask) != 0);}
	[[nodiscard]] constexpr auto downie() const -> downie_f {return downie_f((value_ & downie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ueie() const -> ueie_f {return ueie_f((value_ & ueie_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokie() const -> repokie_f {return repokie_f((value_ & repokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ie() const -> cc2ie_f {return cc2ie_f((value_ & cc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp2okie() const -> cmp2okie_f {return cmp2okie_f((value_ & cmp2okie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uede() const -> uede_f {return uede_f((value_ & uede_f::mask) != 0);}

	constexpr lptim1_dier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_dier_r other) const -> lptim1_dier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_dier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM1 interrupt enable register
 */
class lptim1_dier_alternate1_r {
public:

/**
 * Capture/compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match Interrupt Enable
 */
class arrmie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge Interrupt Enable
 */
class exttrigie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK Interrupt Enable
 */
class arrokie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP Interrupt Enable 
 */
class upie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down Interrupt Enable 
 */
class downie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event interrupt enable
 */
class ueie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ueie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK interrupt Enable
 */
class repokie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 interrupt enable 
 */
class cc2ie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 over-capture interrupt enable 
 */
class cc1oie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1oie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 over-capture interrupt enable 
 */
class cc2oie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2oie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 DMA request enable 
 */
class cc1de_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc1de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event DMA request enable 
 */
class uede_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uede_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 DMA request enable 
 */
class cc2de_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim1_dier_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim1_dier_alternate1_r>() const {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(mask, *this);}
	constexpr auto operator|(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return static_cast<lptim1_dier_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim1_dier_alternate1_r> other) const -> opsy::utility::clear_set<lptim1_dier_alternate1_r> {return opsy::utility::clear_set<lptim1_dier_alternate1_r>(lptim1_dier_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmie() const -> arrmie_f {return arrmie_f((value_ & arrmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigie() const -> exttrigie_f {return exttrigie_f((value_ & exttrigie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokie() const -> arrokie_f {return arrokie_f((value_ & arrokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto upie() const -> upie_f {return upie_f((value_ & upie_f::mask) != 0);}
	[[nodiscard]] constexpr auto downie() const -> downie_f {return downie_f((value_ & downie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ueie() const -> ueie_f {return ueie_f((value_ & ueie_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokie() const -> repokie_f {return repokie_f((value_ & repokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ie() const -> cc2ie_f {return cc2ie_f((value_ & cc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1oie() const -> cc1oie_f {return cc1oie_f((value_ & cc1oie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2oie() const -> cc2oie_f {return cc2oie_f((value_ & cc2oie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1de() const -> cc1de_f {return cc1de_f((value_ & cc1de_f::mask) != 0);}
	[[nodiscard]] constexpr auto uede() const -> uede_f {return uede_f((value_ & uede_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2de() const -> cc2de_f {return cc2de_f((value_ & cc2de_f::mask) != 0);}

	constexpr lptim1_dier_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim1_dier_alternate1_r other) const -> lptim1_dier_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim1_dier_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM configuration register
 */
class lptim_cfgr_r {
public:

/**
 * Clock selector 
 */
class cksel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock Polarity 
 */
class ckpol_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ckpol_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Configurable digital filter for external clock 
 */
class ckflt_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ckflt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Configurable digital filter for trigger 
 */
class trgflt_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trgflt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clock prescaler 
 */
class presc_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr presc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Trigger selector 
 */
class trigsel_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trigsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Trigger enable and polarity 
 */
class trigen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trigen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timeout enable 
 */
class timout_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr timout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Waveform shape 
 */
class wave_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wave_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Waveform shape polarity 
 */
class wavpol_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wavpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Registers update mode 
 */
class preload_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr preload_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * counter mode enabled 
 */
class countmode_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr countmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Encoder mode enable 
 */
class enc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr enc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cksel() const -> cksel_f {return cksel_f((value_ & cksel_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckpol() const -> ckpol_f {return ckpol_f(static_cast<uint8_t>(value_ >> ckpol_f::offset));}
	[[nodiscard]] constexpr auto ckflt() const -> ckflt_f {return ckflt_f(static_cast<uint8_t>(value_ >> ckflt_f::offset));}
	[[nodiscard]] constexpr auto trgflt() const -> trgflt_f {return trgflt_f(static_cast<uint8_t>(value_ >> trgflt_f::offset));}
	[[nodiscard]] constexpr auto presc() const -> presc_f {return presc_f(static_cast<uint8_t>(value_ >> presc_f::offset));}
	[[nodiscard]] constexpr auto trigsel() const -> trigsel_f {return trigsel_f(static_cast<uint8_t>(value_ >> trigsel_f::offset));}
	[[nodiscard]] constexpr auto trigen() const -> trigen_f {return trigen_f(static_cast<uint8_t>(value_ >> trigen_f::offset));}
	[[nodiscard]] constexpr auto timout() const -> timout_f {return timout_f((value_ & timout_f::mask) != 0);}
	[[nodiscard]] constexpr auto wave() const -> wave_f {return wave_f((value_ & wave_f::mask) != 0);}
	[[nodiscard]] constexpr auto wavpol() const -> wavpol_f {return wavpol_f((value_ & wavpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto preload() const -> preload_f {return preload_f((value_ & preload_f::mask) != 0);}
	[[nodiscard]] constexpr auto countmode() const -> countmode_f {return countmode_f((value_ & countmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto enc() const -> enc_f {return enc_f((value_ & enc_f::mask) != 0);}

	constexpr lptim_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cfgr_r other) const -> lptim_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM control register
 */
class lptim_cr_r {
public:

/**
 * LPTIM enable 
 */
class enable_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr enable_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM start in Single mode 
 */
class sngstrt_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sngstrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timer start in Continuous mode 
 */
class cntstrt_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntstrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter reset 
 */
class countrst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr countrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reset after read enable 
 */
class rstare_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rstare_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto enable() const -> enable_f {return enable_f((value_ & enable_f::mask) != 0);}
	[[nodiscard]] constexpr auto sngstrt() const -> sngstrt_f {return sngstrt_f((value_ & sngstrt_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntstrt() const -> cntstrt_f {return cntstrt_f((value_ & cntstrt_f::mask) != 0);}
	[[nodiscard]] constexpr auto countrst() const -> countrst_f {return countrst_f((value_ & countrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstare() const -> rstare_f {return rstare_f((value_ & rstare_f::mask) != 0);}

	constexpr lptim_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cr_r other) const -> lptim_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM compare register 1
 */
class lptim_ccr1_r {
public:

/**
 * Capture/compare 1 value 
 */
class ccr1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ccr1_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_ccr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccr1_r>() const {return opsy::utility::clear_set<lptim_ccr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccr1_r other) const -> lptim_ccr1_r { return static_cast<lptim_ccr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccr1_r> other) const -> opsy::utility::clear_set<lptim_ccr1_r> {return opsy::utility::clear_set<lptim_ccr1_r>(lptim_ccr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ccr1() const -> ccr1_f {return ccr1_f(static_cast<uint16_t>(value_ >> ccr1_f::offset));}

	constexpr lptim_ccr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccr1_r other) const -> lptim_ccr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM autoreload register
 */
class lptim_arr_r {
public:

/**
 * Auto reload value 
 */
class arr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr arr_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_arr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_arr_r>() const {return opsy::utility::clear_set<lptim_arr_r>(mask, *this);}
	constexpr auto operator|(lptim_arr_r other) const -> lptim_arr_r { return static_cast<lptim_arr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_arr_r> other) const -> opsy::utility::clear_set<lptim_arr_r> {return opsy::utility::clear_set<lptim_arr_r>(lptim_arr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto arr() const -> arr_f {return arr_f(static_cast<uint16_t>(value_ >> arr_f::offset));}

	constexpr lptim_arr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_arr_r other) const -> lptim_arr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_arr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * LPTIM counter register
 */
class lptim_cnt_r {
public:

/**
 * Counter value 
 */
class cnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_cnt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cnt_r>() const {return opsy::utility::clear_set<lptim_cnt_r>(mask, *this);}
	constexpr auto operator|(lptim_cnt_r other) const -> lptim_cnt_r { return static_cast<lptim_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cnt_r> other) const -> opsy::utility::clear_set<lptim_cnt_r> {return opsy::utility::clear_set<lptim_cnt_r>(lptim_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto cnt() const -> cnt_f {return cnt_f(static_cast<uint16_t>(value_ >> cnt_f::offset));}

	constexpr lptim_cnt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cnt_r other) const -> lptim_cnt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cnt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM configuration register 2
 */
class lptim_cfgr2_r {
public:

/**
 * LPTIM input 1 selection 
 */
class in1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr in1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input 2 selection 
 */
class in2sel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr in2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input capture 1 selection 
 */
class ic1sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input capture 2 selection 
 */
class ic2sel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto in1sel() const -> in1sel_f {return in1sel_f(static_cast<uint8_t>(value_ >> in1sel_f::offset));}
	[[nodiscard]] constexpr auto in2sel() const -> in2sel_f {return in2sel_f(static_cast<uint8_t>(value_ >> in2sel_f::offset));}
	[[nodiscard]] constexpr auto ic1sel() const -> ic1sel_f {return ic1sel_f(static_cast<uint8_t>(value_ >> ic1sel_f::offset));}
	[[nodiscard]] constexpr auto ic2sel() const -> ic2sel_f {return ic2sel_f(static_cast<uint8_t>(value_ >> ic2sel_f::offset));}

	constexpr lptim_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM repetition register
 */
class lptim_rcr_r {
public:

/**
 * Repetition register value 
 */
class rep_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rep_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_rcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_rcr_r>() const {return opsy::utility::clear_set<lptim_rcr_r>(mask, *this);}
	constexpr auto operator|(lptim_rcr_r other) const -> lptim_rcr_r { return static_cast<lptim_rcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_rcr_r> other) const -> opsy::utility::clear_set<lptim_rcr_r> {return opsy::utility::clear_set<lptim_rcr_r>(lptim_rcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rep() const -> rep_f {return rep_f(static_cast<uint8_t>(value_ >> rep_f::offset));}

	constexpr lptim_rcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_rcr_r other) const -> lptim_rcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_rcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM capture/compare mode register 1
 */
class lptim_ccmr1_r {
public:

/**
 * Capture/compare 1 selection 
 */
class cc1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 output enable.
 */
class cc1e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 output polarity.
 */
class cc1p_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 prescaler 
 */
class ic1psc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic1psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 filter 
 */
class ic1f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic1f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Capture/compare 2 selection 
 */
class cc2sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output enable.
 */
class cc2e_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output polarity.
 */
class cc2p_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cc2p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 prescaler 
 */
class ic2psc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 filter 
 */
class ic2f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc1sel() const -> cc1sel_f {return cc1sel_f((value_ & cc1sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1e() const -> cc1e_f {return cc1e_f((value_ & cc1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1p() const -> cc1p_f {return cc1p_f(static_cast<uint8_t>(value_ >> cc1p_f::offset));}
	[[nodiscard]] constexpr auto ic1psc() const -> ic1psc_f {return ic1psc_f(static_cast<uint8_t>(value_ >> ic1psc_f::offset));}
	[[nodiscard]] constexpr auto ic1f() const -> ic1f_f {return ic1f_f(static_cast<uint8_t>(value_ >> ic1f_f::offset));}
	[[nodiscard]] constexpr auto cc2sel() const -> cc2sel_f {return cc2sel_f((value_ & cc2sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2e() const -> cc2e_f {return cc2e_f((value_ & cc2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2p() const -> cc2p_f {return cc2p_f(static_cast<uint8_t>(value_ >> cc2p_f::offset));}
	[[nodiscard]] constexpr auto ic2psc() const -> ic2psc_f {return ic2psc_f(static_cast<uint8_t>(value_ >> ic2psc_f::offset));}
	[[nodiscard]] constexpr auto ic2f() const -> ic2f_f {return ic2f_f(static_cast<uint8_t>(value_ >> ic2f_f::offset));}

	constexpr lptim_ccmr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccmr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM compare register 2
 */
class lptim_ccr2_r {
public:

/**
 * Capture/compare 2 value 
 */
class ccr2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ccr2_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_ccr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccr2_r>() const {return opsy::utility::clear_set<lptim_ccr2_r>(mask, *this);}
	constexpr auto operator|(lptim_ccr2_r other) const -> lptim_ccr2_r { return static_cast<lptim_ccr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccr2_r> other) const -> opsy::utility::clear_set<lptim_ccr2_r> {return opsy::utility::clear_set<lptim_ccr2_r>(lptim_ccr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ccr2() const -> ccr2_f {return ccr2_f(static_cast<uint16_t>(value_ >> ccr2_f::offset));}

	constexpr lptim_ccr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccr2_r other) const -> lptim_ccr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::read_only_memory<uint32_t,lptim1_isr_r> lptim1_isr;
		opsy::utility::read_only_memory<uint32_t,lptim1_isr_alternate1_r> lptim1_isr_alternate1;
	};
	union {
		opsy::utility::write_only_memory<uint32_t,lptim1_icr_r> lptim1_icr;
		opsy::utility::write_only_memory<uint32_t,lptim1_icr_alternate1_r> lptim1_icr_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,lptim1_dier_r> lptim1_dier;
		opsy::utility::memory<uint32_t,lptim1_dier_alternate1_r> lptim1_dier_alternate1;
	};
	opsy::utility::memory<uint32_t,lptim_cfgr_r> lptim_cfgr;
	opsy::utility::memory<uint32_t,lptim_cr_r> lptim_cr;
	opsy::utility::memory<uint32_t,lptim_ccr1_r> lptim_ccr1;
	opsy::utility::memory<uint32_t,lptim_arr_r> lptim_arr;
	opsy::utility::read_only_memory<uint32_t,lptim_cnt_r> lptim_cnt;
	opsy::utility::padding<4> _p32;
	opsy::utility::memory<uint32_t,lptim_cfgr2_r> lptim_cfgr2;
	opsy::utility::memory<uint32_t,lptim_rcr_r> lptim_rcr;
	opsy::utility::memory<uint32_t,lptim_ccmr1_r> lptim_ccmr1;
	opsy::utility::padding<4> _p48;
	opsy::utility::memory<uint32_t,lptim_ccr2_r> lptim_ccr2;
};

static_assert(std::is_standard_layout_v<lptim1_p>);
static_assert(offsetof(lptim1_p, lptim1_isr) == 0);
static_assert(offsetof(lptim1_p, lptim1_isr_alternate1) == 0);
static_assert(offsetof(lptim1_p, lptim1_icr) == 4);
static_assert(offsetof(lptim1_p, lptim1_icr_alternate1) == 4);
static_assert(offsetof(lptim1_p, lptim1_dier) == 8);
static_assert(offsetof(lptim1_p, lptim1_dier_alternate1) == 8);
static_assert(offsetof(lptim1_p, lptim_cfgr) == 12);
static_assert(offsetof(lptim1_p, lptim_cr) == 16);
static_assert(offsetof(lptim1_p, lptim_ccr1) == 20);
static_assert(offsetof(lptim1_p, lptim_arr) == 24);
static_assert(offsetof(lptim1_p, lptim_cnt) == 28);
static_assert(offsetof(lptim1_p, lptim_cfgr2) == 36);
static_assert(offsetof(lptim1_p, lptim_rcr) == 40);
static_assert(offsetof(lptim1_p, lptim_ccmr1) == 44);
static_assert(offsetof(lptim1_p, lptim_ccr2) == 52);

inline lptim1_p& lptim1 = *reinterpret_cast<lptim1_p*>(0x44004400);
inline lptim1_p& lptim1_s = *reinterpret_cast<lptim1_p*>(0x54004400);

} // STM32H523

