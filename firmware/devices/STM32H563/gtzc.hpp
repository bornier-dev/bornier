#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * GTZC1_MPCBB1
 */
class gtzc1_mpcbb1_p {
public:

/**
 * GTZC1 SRAM1 MPCBB control register
 */
class gtzc1_mpcbb1_cr_r {
public:

/**
 * lock the control register of the MPCBB until next reset This bit is cleared by default and once set, it can not be reset until system reset.
 */
class glock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr glock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cr_r other) const -> gtzc1_mpcbb1_cr_r { return static_cast<gtzc1_mpcbb1_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(gtzc1_mpcbb1_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAMx clocks security state This bit is used to define the internal SRAMs clocks control in RCC as secure or not.
 */
class invsecstate_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr invsecstate_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cr_r other) const -> gtzc1_mpcbb1_cr_r { return static_cast<gtzc1_mpcbb1_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(gtzc1_mpcbb1_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure read/write illegal access disable This bit disables the detection of an illegal access when a secure read/write transaction access a non-secure blocks of the block-based SRAM (secure fetch on non-secure block is always considered illegal).
 */
class srwiladis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr srwiladis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cr_r other) const -> gtzc1_mpcbb1_cr_r { return static_cast<gtzc1_mpcbb1_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cr_r>(gtzc1_mpcbb1_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto glock() const -> glock_f {return glock_f((value_ & glock_f::mask) != 0);}
	[[nodiscard]] constexpr auto invsecstate() const -> invsecstate_f {return invsecstate_f((value_ & invsecstate_f::mask) != 0);}
	[[nodiscard]] constexpr auto srwiladis() const -> srwiladis_f {return srwiladis_f((value_ & srwiladis_f::mask) != 0);}

	constexpr gtzc1_mpcbb1_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb1_cr_r other) const -> gtzc1_mpcbb1_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb1_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM1 MPCBB configuration lock register 1
 */
class gtzc1_mpcbb1_cfglock1_r {
public:

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return static_cast<gtzc1_mpcbb1_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_cfglock1_r>(gtzc1_mpcbb1_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto splck0() const -> splck0_f {return splck0_f((value_ & splck0_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck1() const -> splck1_f {return splck1_f((value_ & splck1_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck2() const -> splck2_f {return splck2_f((value_ & splck2_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck3() const -> splck3_f {return splck3_f((value_ & splck3_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck4() const -> splck4_f {return splck4_f((value_ & splck4_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck5() const -> splck5_f {return splck5_f((value_ & splck5_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck6() const -> splck6_f {return splck6_f((value_ & splck6_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck7() const -> splck7_f {return splck7_f((value_ & splck7_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck8() const -> splck8_f {return splck8_f((value_ & splck8_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck9() const -> splck9_f {return splck9_f((value_ & splck9_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck10() const -> splck10_f {return splck10_f((value_ & splck10_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck11() const -> splck11_f {return splck11_f((value_ & splck11_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck12() const -> splck12_f {return splck12_f((value_ & splck12_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck13() const -> splck13_f {return splck13_f((value_ & splck13_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck14() const -> splck14_f {return splck14_f((value_ & splck14_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck15() const -> splck15_f {return splck15_f((value_ & splck15_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck16() const -> splck16_f {return splck16_f((value_ & splck16_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck17() const -> splck17_f {return splck17_f((value_ & splck17_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck18() const -> splck18_f {return splck18_f((value_ & splck18_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck19() const -> splck19_f {return splck19_f((value_ & splck19_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck20() const -> splck20_f {return splck20_f((value_ & splck20_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck21() const -> splck21_f {return splck21_f((value_ & splck21_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck22() const -> splck22_f {return splck22_f((value_ & splck22_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck23() const -> splck23_f {return splck23_f((value_ & splck23_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck24() const -> splck24_f {return splck24_f((value_ & splck24_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck25() const -> splck25_f {return splck25_f((value_ & splck25_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck26() const -> splck26_f {return splck26_f((value_ & splck26_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck27() const -> splck27_f {return splck27_f((value_ & splck27_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck28() const -> splck28_f {return splck28_f((value_ & splck28_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck29() const -> splck29_f {return splck29_f((value_ & splck29_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck30() const -> splck30_f {return splck30_f((value_ & splck30_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck31() const -> splck31_f {return splck31_f((value_ & splck31_f::mask) != 0);}

	constexpr gtzc1_mpcbb1_cfglock1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb1_cfglock1_r other) const -> gtzc1_mpcbb1_cfglock1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb1_cfglock1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM1 MPCBB security configuration for super-block 0 register
 */
class gtzc1_mpcbb1_seccfgr0_r {
public:

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return static_cast<gtzc1_mpcbb1_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_seccfgr0_r>(gtzc1_mpcbb1_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sec0() const -> sec0_f {return sec0_f((value_ & sec0_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec1() const -> sec1_f {return sec1_f((value_ & sec1_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec2() const -> sec2_f {return sec2_f((value_ & sec2_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec3() const -> sec3_f {return sec3_f((value_ & sec3_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec4() const -> sec4_f {return sec4_f((value_ & sec4_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec5() const -> sec5_f {return sec5_f((value_ & sec5_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec6() const -> sec6_f {return sec6_f((value_ & sec6_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec7() const -> sec7_f {return sec7_f((value_ & sec7_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec8() const -> sec8_f {return sec8_f((value_ & sec8_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec9() const -> sec9_f {return sec9_f((value_ & sec9_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec10() const -> sec10_f {return sec10_f((value_ & sec10_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec11() const -> sec11_f {return sec11_f((value_ & sec11_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec12() const -> sec12_f {return sec12_f((value_ & sec12_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec13() const -> sec13_f {return sec13_f((value_ & sec13_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec14() const -> sec14_f {return sec14_f((value_ & sec14_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec15() const -> sec15_f {return sec15_f((value_ & sec15_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec16() const -> sec16_f {return sec16_f((value_ & sec16_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec17() const -> sec17_f {return sec17_f((value_ & sec17_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec18() const -> sec18_f {return sec18_f((value_ & sec18_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec19() const -> sec19_f {return sec19_f((value_ & sec19_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec20() const -> sec20_f {return sec20_f((value_ & sec20_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec21() const -> sec21_f {return sec21_f((value_ & sec21_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec22() const -> sec22_f {return sec22_f((value_ & sec22_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec23() const -> sec23_f {return sec23_f((value_ & sec23_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec24() const -> sec24_f {return sec24_f((value_ & sec24_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec25() const -> sec25_f {return sec25_f((value_ & sec25_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec26() const -> sec26_f {return sec26_f((value_ & sec26_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec27() const -> sec27_f {return sec27_f((value_ & sec27_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec28() const -> sec28_f {return sec28_f((value_ & sec28_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec29() const -> sec29_f {return sec29_f((value_ & sec29_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec30() const -> sec30_f {return sec30_f((value_ & sec30_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec31() const -> sec31_f {return sec31_f((value_ & sec31_f::mask) != 0);}

	constexpr gtzc1_mpcbb1_seccfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb1_seccfgr0_r other) const -> gtzc1_mpcbb1_seccfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb1_seccfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM1 MPCBB privileged configuration for super-block 0 register
 */
class gtzc1_mpcbb1_privcfgr0_r {
public:

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb1_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return static_cast<gtzc1_mpcbb1_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb1_privcfgr0_r>(gtzc1_mpcbb1_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto priv0() const -> priv0_f {return priv0_f((value_ & priv0_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv1() const -> priv1_f {return priv1_f((value_ & priv1_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv2() const -> priv2_f {return priv2_f((value_ & priv2_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv3() const -> priv3_f {return priv3_f((value_ & priv3_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv4() const -> priv4_f {return priv4_f((value_ & priv4_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv5() const -> priv5_f {return priv5_f((value_ & priv5_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv6() const -> priv6_f {return priv6_f((value_ & priv6_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv7() const -> priv7_f {return priv7_f((value_ & priv7_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv8() const -> priv8_f {return priv8_f((value_ & priv8_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv9() const -> priv9_f {return priv9_f((value_ & priv9_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv10() const -> priv10_f {return priv10_f((value_ & priv10_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv11() const -> priv11_f {return priv11_f((value_ & priv11_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv12() const -> priv12_f {return priv12_f((value_ & priv12_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv13() const -> priv13_f {return priv13_f((value_ & priv13_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv14() const -> priv14_f {return priv14_f((value_ & priv14_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv15() const -> priv15_f {return priv15_f((value_ & priv15_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv16() const -> priv16_f {return priv16_f((value_ & priv16_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv17() const -> priv17_f {return priv17_f((value_ & priv17_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv18() const -> priv18_f {return priv18_f((value_ & priv18_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv19() const -> priv19_f {return priv19_f((value_ & priv19_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv20() const -> priv20_f {return priv20_f((value_ & priv20_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv21() const -> priv21_f {return priv21_f((value_ & priv21_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv22() const -> priv22_f {return priv22_f((value_ & priv22_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv23() const -> priv23_f {return priv23_f((value_ & priv23_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv24() const -> priv24_f {return priv24_f((value_ & priv24_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv25() const -> priv25_f {return priv25_f((value_ & priv25_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv26() const -> priv26_f {return priv26_f((value_ & priv26_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv27() const -> priv27_f {return priv27_f((value_ & priv27_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv28() const -> priv28_f {return priv28_f((value_ & priv28_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv29() const -> priv29_f {return priv29_f((value_ & priv29_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv30() const -> priv30_f {return priv30_f((value_ & priv30_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv31() const -> priv31_f {return priv31_f((value_ & priv31_f::mask) != 0);}

	constexpr gtzc1_mpcbb1_privcfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb1_privcfgr0_r other) const -> gtzc1_mpcbb1_privcfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb1_privcfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_cr_r> gtzc1_mpcbb1_cr;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_cfglock1_r> gtzc1_mpcbb1_cfglock1;
	opsy::utility::padding<236> _p1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_seccfgr0_r> gtzc1_mpcbb1_seccfgr31;
	opsy::utility::padding<128> _p2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb1_privcfgr0_r> gtzc1_mpcbb1_privcfgr31;
};

static_assert(std::is_standard_layout_v<gtzc1_mpcbb1_p>);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_cr) == 0);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_cfglock1) == 16);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr0) == 256);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr1) == 260);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr2) == 264);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr3) == 268);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr4) == 272);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr5) == 276);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr6) == 280);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr7) == 284);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr8) == 288);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr9) == 292);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr10) == 296);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr11) == 300);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr12) == 304);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr13) == 308);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr14) == 312);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr15) == 316);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr16) == 320);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr17) == 324);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr18) == 328);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr19) == 332);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr20) == 336);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr21) == 340);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr22) == 344);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr23) == 348);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr24) == 352);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr25) == 356);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr26) == 360);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr27) == 364);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr28) == 368);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr29) == 372);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr30) == 376);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_seccfgr31) == 380);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr0) == 512);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr1) == 516);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr2) == 520);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr3) == 524);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr4) == 528);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr5) == 532);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr6) == 536);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr7) == 540);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr8) == 544);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr9) == 548);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr10) == 552);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr11) == 556);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr12) == 560);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr13) == 564);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr14) == 568);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr15) == 572);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr16) == 576);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr17) == 580);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr18) == 584);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr19) == 588);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr20) == 592);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr21) == 596);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr22) == 600);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr23) == 604);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr24) == 608);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr25) == 612);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr26) == 616);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr27) == 620);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr28) == 624);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr29) == 628);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr30) == 632);
static_assert(offsetof(gtzc1_mpcbb1_p, gtzc1_mpcbb1_privcfgr31) == 636);

/**
 * GTZC1_MPCBB2
 */
class gtzc1_mpcbb2_p {
public:

/**
 * GTZC1 SRAM2 MPCBB control register
 */
class gtzc1_mpcbb2_cr_r {
public:

/**
 * lock the control register of the MPCBB until next reset This bit is cleared by default and once set, it can not be reset until system reset.
 */
class glock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr glock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cr_r other) const -> gtzc1_mpcbb2_cr_r { return static_cast<gtzc1_mpcbb2_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(gtzc1_mpcbb2_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAMx clocks security state This bit is used to define the internal SRAMs clocks control in RCC as secure or not.
 */
class invsecstate_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr invsecstate_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cr_r other) const -> gtzc1_mpcbb2_cr_r { return static_cast<gtzc1_mpcbb2_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(gtzc1_mpcbb2_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure read/write illegal access disable This bit disables the detection of an illegal access when a secure read/write transaction access a non-secure blocks of the block-based SRAM (secure fetch on non-secure block is always considered illegal).
 */
class srwiladis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr srwiladis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cr_r other) const -> gtzc1_mpcbb2_cr_r { return static_cast<gtzc1_mpcbb2_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cr_r>(gtzc1_mpcbb2_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto glock() const -> glock_f {return glock_f((value_ & glock_f::mask) != 0);}
	[[nodiscard]] constexpr auto invsecstate() const -> invsecstate_f {return invsecstate_f((value_ & invsecstate_f::mask) != 0);}
	[[nodiscard]] constexpr auto srwiladis() const -> srwiladis_f {return srwiladis_f((value_ & srwiladis_f::mask) != 0);}

	constexpr gtzc1_mpcbb2_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb2_cr_r other) const -> gtzc1_mpcbb2_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb2_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM2 MPCBB configuration lock register 1
 */
class gtzc1_mpcbb2_cfglock1_r {
public:

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return static_cast<gtzc1_mpcbb2_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_cfglock1_r>(gtzc1_mpcbb2_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto splck0() const -> splck0_f {return splck0_f((value_ & splck0_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck1() const -> splck1_f {return splck1_f((value_ & splck1_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck2() const -> splck2_f {return splck2_f((value_ & splck2_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck3() const -> splck3_f {return splck3_f((value_ & splck3_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck4() const -> splck4_f {return splck4_f((value_ & splck4_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck5() const -> splck5_f {return splck5_f((value_ & splck5_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck6() const -> splck6_f {return splck6_f((value_ & splck6_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck7() const -> splck7_f {return splck7_f((value_ & splck7_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck8() const -> splck8_f {return splck8_f((value_ & splck8_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck9() const -> splck9_f {return splck9_f((value_ & splck9_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck10() const -> splck10_f {return splck10_f((value_ & splck10_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck11() const -> splck11_f {return splck11_f((value_ & splck11_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck12() const -> splck12_f {return splck12_f((value_ & splck12_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck13() const -> splck13_f {return splck13_f((value_ & splck13_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck14() const -> splck14_f {return splck14_f((value_ & splck14_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck15() const -> splck15_f {return splck15_f((value_ & splck15_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck16() const -> splck16_f {return splck16_f((value_ & splck16_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck17() const -> splck17_f {return splck17_f((value_ & splck17_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck18() const -> splck18_f {return splck18_f((value_ & splck18_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck19() const -> splck19_f {return splck19_f((value_ & splck19_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck20() const -> splck20_f {return splck20_f((value_ & splck20_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck21() const -> splck21_f {return splck21_f((value_ & splck21_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck22() const -> splck22_f {return splck22_f((value_ & splck22_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck23() const -> splck23_f {return splck23_f((value_ & splck23_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck24() const -> splck24_f {return splck24_f((value_ & splck24_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck25() const -> splck25_f {return splck25_f((value_ & splck25_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck26() const -> splck26_f {return splck26_f((value_ & splck26_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck27() const -> splck27_f {return splck27_f((value_ & splck27_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck28() const -> splck28_f {return splck28_f((value_ & splck28_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck29() const -> splck29_f {return splck29_f((value_ & splck29_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck30() const -> splck30_f {return splck30_f((value_ & splck30_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck31() const -> splck31_f {return splck31_f((value_ & splck31_f::mask) != 0);}

	constexpr gtzc1_mpcbb2_cfglock1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb2_cfglock1_r other) const -> gtzc1_mpcbb2_cfglock1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb2_cfglock1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM2 MPCBB security configuration for super-block 0 register
 */
class gtzc1_mpcbb2_seccfgr0_r {
public:

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return static_cast<gtzc1_mpcbb2_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_seccfgr0_r>(gtzc1_mpcbb2_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sec0() const -> sec0_f {return sec0_f((value_ & sec0_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec1() const -> sec1_f {return sec1_f((value_ & sec1_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec2() const -> sec2_f {return sec2_f((value_ & sec2_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec3() const -> sec3_f {return sec3_f((value_ & sec3_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec4() const -> sec4_f {return sec4_f((value_ & sec4_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec5() const -> sec5_f {return sec5_f((value_ & sec5_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec6() const -> sec6_f {return sec6_f((value_ & sec6_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec7() const -> sec7_f {return sec7_f((value_ & sec7_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec8() const -> sec8_f {return sec8_f((value_ & sec8_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec9() const -> sec9_f {return sec9_f((value_ & sec9_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec10() const -> sec10_f {return sec10_f((value_ & sec10_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec11() const -> sec11_f {return sec11_f((value_ & sec11_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec12() const -> sec12_f {return sec12_f((value_ & sec12_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec13() const -> sec13_f {return sec13_f((value_ & sec13_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec14() const -> sec14_f {return sec14_f((value_ & sec14_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec15() const -> sec15_f {return sec15_f((value_ & sec15_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec16() const -> sec16_f {return sec16_f((value_ & sec16_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec17() const -> sec17_f {return sec17_f((value_ & sec17_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec18() const -> sec18_f {return sec18_f((value_ & sec18_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec19() const -> sec19_f {return sec19_f((value_ & sec19_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec20() const -> sec20_f {return sec20_f((value_ & sec20_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec21() const -> sec21_f {return sec21_f((value_ & sec21_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec22() const -> sec22_f {return sec22_f((value_ & sec22_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec23() const -> sec23_f {return sec23_f((value_ & sec23_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec24() const -> sec24_f {return sec24_f((value_ & sec24_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec25() const -> sec25_f {return sec25_f((value_ & sec25_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec26() const -> sec26_f {return sec26_f((value_ & sec26_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec27() const -> sec27_f {return sec27_f((value_ & sec27_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec28() const -> sec28_f {return sec28_f((value_ & sec28_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec29() const -> sec29_f {return sec29_f((value_ & sec29_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec30() const -> sec30_f {return sec30_f((value_ & sec30_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec31() const -> sec31_f {return sec31_f((value_ & sec31_f::mask) != 0);}

	constexpr gtzc1_mpcbb2_seccfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb2_seccfgr0_r other) const -> gtzc1_mpcbb2_seccfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb2_seccfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM2 MPCBB privileged configuration for super-block 0 register
 */
class gtzc1_mpcbb2_privcfgr0_r {
public:

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb2_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return static_cast<gtzc1_mpcbb2_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb2_privcfgr0_r>(gtzc1_mpcbb2_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto priv0() const -> priv0_f {return priv0_f((value_ & priv0_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv1() const -> priv1_f {return priv1_f((value_ & priv1_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv2() const -> priv2_f {return priv2_f((value_ & priv2_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv3() const -> priv3_f {return priv3_f((value_ & priv3_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv4() const -> priv4_f {return priv4_f((value_ & priv4_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv5() const -> priv5_f {return priv5_f((value_ & priv5_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv6() const -> priv6_f {return priv6_f((value_ & priv6_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv7() const -> priv7_f {return priv7_f((value_ & priv7_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv8() const -> priv8_f {return priv8_f((value_ & priv8_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv9() const -> priv9_f {return priv9_f((value_ & priv9_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv10() const -> priv10_f {return priv10_f((value_ & priv10_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv11() const -> priv11_f {return priv11_f((value_ & priv11_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv12() const -> priv12_f {return priv12_f((value_ & priv12_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv13() const -> priv13_f {return priv13_f((value_ & priv13_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv14() const -> priv14_f {return priv14_f((value_ & priv14_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv15() const -> priv15_f {return priv15_f((value_ & priv15_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv16() const -> priv16_f {return priv16_f((value_ & priv16_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv17() const -> priv17_f {return priv17_f((value_ & priv17_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv18() const -> priv18_f {return priv18_f((value_ & priv18_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv19() const -> priv19_f {return priv19_f((value_ & priv19_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv20() const -> priv20_f {return priv20_f((value_ & priv20_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv21() const -> priv21_f {return priv21_f((value_ & priv21_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv22() const -> priv22_f {return priv22_f((value_ & priv22_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv23() const -> priv23_f {return priv23_f((value_ & priv23_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv24() const -> priv24_f {return priv24_f((value_ & priv24_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv25() const -> priv25_f {return priv25_f((value_ & priv25_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv26() const -> priv26_f {return priv26_f((value_ & priv26_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv27() const -> priv27_f {return priv27_f((value_ & priv27_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv28() const -> priv28_f {return priv28_f((value_ & priv28_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv29() const -> priv29_f {return priv29_f((value_ & priv29_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv30() const -> priv30_f {return priv30_f((value_ & priv30_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv31() const -> priv31_f {return priv31_f((value_ & priv31_f::mask) != 0);}

	constexpr gtzc1_mpcbb2_privcfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb2_privcfgr0_r other) const -> gtzc1_mpcbb2_privcfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb2_privcfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_cr_r> gtzc1_mpcbb2_cr;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_cfglock1_r> gtzc1_mpcbb2_cfglock1;
	opsy::utility::padding<236> _p1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_seccfgr0_r> gtzc1_mpcbb2_seccfgr31;
	opsy::utility::padding<128> _p2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb2_privcfgr0_r> gtzc1_mpcbb2_privcfgr31;
};

static_assert(std::is_standard_layout_v<gtzc1_mpcbb2_p>);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_cr) == 0);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_cfglock1) == 16);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr0) == 256);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr1) == 260);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr2) == 264);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr3) == 268);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr4) == 272);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr5) == 276);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr6) == 280);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr7) == 284);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr8) == 288);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr9) == 292);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr10) == 296);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr11) == 300);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr12) == 304);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr13) == 308);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr14) == 312);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr15) == 316);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr16) == 320);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr17) == 324);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr18) == 328);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr19) == 332);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr20) == 336);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr21) == 340);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr22) == 344);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr23) == 348);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr24) == 352);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr25) == 356);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr26) == 360);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr27) == 364);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr28) == 368);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr29) == 372);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr30) == 376);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_seccfgr31) == 380);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr0) == 512);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr1) == 516);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr2) == 520);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr3) == 524);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr4) == 528);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr5) == 532);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr6) == 536);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr7) == 540);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr8) == 544);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr9) == 548);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr10) == 552);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr11) == 556);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr12) == 560);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr13) == 564);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr14) == 568);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr15) == 572);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr16) == 576);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr17) == 580);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr18) == 584);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr19) == 588);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr20) == 592);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr21) == 596);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr22) == 600);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr23) == 604);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr24) == 608);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr25) == 612);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr26) == 616);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr27) == 620);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr28) == 624);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr29) == 628);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr30) == 632);
static_assert(offsetof(gtzc1_mpcbb2_p, gtzc1_mpcbb2_privcfgr31) == 636);

/**
 * GTZC1_MPCBB3
 */
class gtzc1_mpcbb3_p {
public:

/**
 * GTZC1 SRAM3 MPCBB control register
 */
class gtzc1_mpcbb3_cr_r {
public:

/**
 * lock the control register of the MPCBB until next reset This bit is cleared by default and once set, it can not be reset until system reset.
 */
class glock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr glock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cr_r other) const -> gtzc1_mpcbb3_cr_r { return static_cast<gtzc1_mpcbb3_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(gtzc1_mpcbb3_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAMx clocks security state This bit is used to define the internal SRAMs clocks control in RCC as secure or not.
 */
class invsecstate_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr invsecstate_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cr_r other) const -> gtzc1_mpcbb3_cr_r { return static_cast<gtzc1_mpcbb3_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(gtzc1_mpcbb3_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure read/write illegal access disable This bit disables the detection of an illegal access when a secure read/write transaction access a non-secure blocks of the block-based SRAM (secure fetch on non-secure block is always considered illegal).
 */
class srwiladis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr srwiladis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cr_r other) const -> gtzc1_mpcbb3_cr_r { return static_cast<gtzc1_mpcbb3_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cr_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cr_r>(gtzc1_mpcbb3_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto glock() const -> glock_f {return glock_f((value_ & glock_f::mask) != 0);}
	[[nodiscard]] constexpr auto invsecstate() const -> invsecstate_f {return invsecstate_f((value_ & invsecstate_f::mask) != 0);}
	[[nodiscard]] constexpr auto srwiladis() const -> srwiladis_f {return srwiladis_f((value_ & srwiladis_f::mask) != 0);}

	constexpr gtzc1_mpcbb3_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb3_cr_r other) const -> gtzc1_mpcbb3_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb3_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM3 MPCBB configuration lock register 1
 */
class gtzc1_mpcbb3_cfglock1_r {
public:

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr splck7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr splck15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security/privilege configuration lock for super-block This bit is set by software and can be cleared only by system reset.
 */
class splck31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr splck31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_cfglock1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return static_cast<gtzc1_mpcbb3_cfglock1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_cfglock1_r>(gtzc1_mpcbb3_cfglock1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto splck0() const -> splck0_f {return splck0_f((value_ & splck0_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck1() const -> splck1_f {return splck1_f((value_ & splck1_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck2() const -> splck2_f {return splck2_f((value_ & splck2_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck3() const -> splck3_f {return splck3_f((value_ & splck3_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck4() const -> splck4_f {return splck4_f((value_ & splck4_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck5() const -> splck5_f {return splck5_f((value_ & splck5_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck6() const -> splck6_f {return splck6_f((value_ & splck6_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck7() const -> splck7_f {return splck7_f((value_ & splck7_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck8() const -> splck8_f {return splck8_f((value_ & splck8_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck9() const -> splck9_f {return splck9_f((value_ & splck9_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck10() const -> splck10_f {return splck10_f((value_ & splck10_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck11() const -> splck11_f {return splck11_f((value_ & splck11_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck12() const -> splck12_f {return splck12_f((value_ & splck12_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck13() const -> splck13_f {return splck13_f((value_ & splck13_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck14() const -> splck14_f {return splck14_f((value_ & splck14_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck15() const -> splck15_f {return splck15_f((value_ & splck15_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck16() const -> splck16_f {return splck16_f((value_ & splck16_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck17() const -> splck17_f {return splck17_f((value_ & splck17_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck18() const -> splck18_f {return splck18_f((value_ & splck18_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck19() const -> splck19_f {return splck19_f((value_ & splck19_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck20() const -> splck20_f {return splck20_f((value_ & splck20_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck21() const -> splck21_f {return splck21_f((value_ & splck21_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck22() const -> splck22_f {return splck22_f((value_ & splck22_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck23() const -> splck23_f {return splck23_f((value_ & splck23_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck24() const -> splck24_f {return splck24_f((value_ & splck24_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck25() const -> splck25_f {return splck25_f((value_ & splck25_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck26() const -> splck26_f {return splck26_f((value_ & splck26_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck27() const -> splck27_f {return splck27_f((value_ & splck27_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck28() const -> splck28_f {return splck28_f((value_ & splck28_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck29() const -> splck29_f {return splck29_f((value_ & splck29_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck30() const -> splck30_f {return splck30_f((value_ & splck30_f::mask) != 0);}
	[[nodiscard]] constexpr auto splck31() const -> splck31_f {return splck31_f((value_ & splck31_f::mask) != 0);}

	constexpr gtzc1_mpcbb3_cfglock1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb3_cfglock1_r other) const -> gtzc1_mpcbb3_cfglock1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb3_cfglock1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM3 MPCBB security configuration for super-block 0 register
 */
class gtzc1_mpcbb3_seccfgr0_r {
public:

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security configuration for block y Unprivileged write to this bit is ignored if PRIVy bit is set in GTZC1_MPCBBz_PRIVCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class sec31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_seccfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return static_cast<gtzc1_mpcbb3_seccfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_seccfgr0_r>(gtzc1_mpcbb3_seccfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sec0() const -> sec0_f {return sec0_f((value_ & sec0_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec1() const -> sec1_f {return sec1_f((value_ & sec1_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec2() const -> sec2_f {return sec2_f((value_ & sec2_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec3() const -> sec3_f {return sec3_f((value_ & sec3_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec4() const -> sec4_f {return sec4_f((value_ & sec4_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec5() const -> sec5_f {return sec5_f((value_ & sec5_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec6() const -> sec6_f {return sec6_f((value_ & sec6_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec7() const -> sec7_f {return sec7_f((value_ & sec7_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec8() const -> sec8_f {return sec8_f((value_ & sec8_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec9() const -> sec9_f {return sec9_f((value_ & sec9_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec10() const -> sec10_f {return sec10_f((value_ & sec10_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec11() const -> sec11_f {return sec11_f((value_ & sec11_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec12() const -> sec12_f {return sec12_f((value_ & sec12_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec13() const -> sec13_f {return sec13_f((value_ & sec13_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec14() const -> sec14_f {return sec14_f((value_ & sec14_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec15() const -> sec15_f {return sec15_f((value_ & sec15_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec16() const -> sec16_f {return sec16_f((value_ & sec16_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec17() const -> sec17_f {return sec17_f((value_ & sec17_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec18() const -> sec18_f {return sec18_f((value_ & sec18_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec19() const -> sec19_f {return sec19_f((value_ & sec19_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec20() const -> sec20_f {return sec20_f((value_ & sec20_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec21() const -> sec21_f {return sec21_f((value_ & sec21_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec22() const -> sec22_f {return sec22_f((value_ & sec22_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec23() const -> sec23_f {return sec23_f((value_ & sec23_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec24() const -> sec24_f {return sec24_f((value_ & sec24_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec25() const -> sec25_f {return sec25_f((value_ & sec25_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec26() const -> sec26_f {return sec26_f((value_ & sec26_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec27() const -> sec27_f {return sec27_f((value_ & sec27_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec28() const -> sec28_f {return sec28_f((value_ & sec28_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec29() const -> sec29_f {return sec29_f((value_ & sec29_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec30() const -> sec30_f {return sec30_f((value_ & sec30_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec31() const -> sec31_f {return sec31_f((value_ & sec31_f::mask) != 0);}

	constexpr gtzc1_mpcbb3_seccfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb3_seccfgr0_r other) const -> gtzc1_mpcbb3_seccfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb3_seccfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

/**
 * GTZC1 SRAM3 MPCBB privileged configuration for super-block 0 register
 */
class gtzc1_mpcbb3_privcfgr0_r {
public:

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged configuration for block y, belonging to super-block x (y = 31 to 0). Non-secure write to this bit is ignored if SECy bit is set in GTZC1_MPCBBz_SECCFGRx. Writes are ignored if SPLCKx bit is set in GTZC1_MPCBBz_CFGLOCK.
 */
class priv31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_mpcbb3_privcfgr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>() const {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(mask, *this);}
	constexpr auto operator|(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return static_cast<gtzc1_mpcbb3_privcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> other) const -> opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r> {return opsy::utility::clear_set<gtzc1_mpcbb3_privcfgr0_r>(gtzc1_mpcbb3_privcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto priv0() const -> priv0_f {return priv0_f((value_ & priv0_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv1() const -> priv1_f {return priv1_f((value_ & priv1_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv2() const -> priv2_f {return priv2_f((value_ & priv2_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv3() const -> priv3_f {return priv3_f((value_ & priv3_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv4() const -> priv4_f {return priv4_f((value_ & priv4_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv5() const -> priv5_f {return priv5_f((value_ & priv5_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv6() const -> priv6_f {return priv6_f((value_ & priv6_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv7() const -> priv7_f {return priv7_f((value_ & priv7_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv8() const -> priv8_f {return priv8_f((value_ & priv8_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv9() const -> priv9_f {return priv9_f((value_ & priv9_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv10() const -> priv10_f {return priv10_f((value_ & priv10_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv11() const -> priv11_f {return priv11_f((value_ & priv11_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv12() const -> priv12_f {return priv12_f((value_ & priv12_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv13() const -> priv13_f {return priv13_f((value_ & priv13_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv14() const -> priv14_f {return priv14_f((value_ & priv14_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv15() const -> priv15_f {return priv15_f((value_ & priv15_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv16() const -> priv16_f {return priv16_f((value_ & priv16_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv17() const -> priv17_f {return priv17_f((value_ & priv17_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv18() const -> priv18_f {return priv18_f((value_ & priv18_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv19() const -> priv19_f {return priv19_f((value_ & priv19_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv20() const -> priv20_f {return priv20_f((value_ & priv20_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv21() const -> priv21_f {return priv21_f((value_ & priv21_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv22() const -> priv22_f {return priv22_f((value_ & priv22_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv23() const -> priv23_f {return priv23_f((value_ & priv23_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv24() const -> priv24_f {return priv24_f((value_ & priv24_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv25() const -> priv25_f {return priv25_f((value_ & priv25_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv26() const -> priv26_f {return priv26_f((value_ & priv26_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv27() const -> priv27_f {return priv27_f((value_ & priv27_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv28() const -> priv28_f {return priv28_f((value_ & priv28_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv29() const -> priv29_f {return priv29_f((value_ & priv29_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv30() const -> priv30_f {return priv30_f((value_ & priv30_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv31() const -> priv31_f {return priv31_f((value_ & priv31_f::mask) != 0);}

	constexpr gtzc1_mpcbb3_privcfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_mpcbb3_privcfgr0_r other) const -> gtzc1_mpcbb3_privcfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_mpcbb3_privcfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_cr_r> gtzc1_mpcbb3_cr;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_cfglock1_r> gtzc1_mpcbb3_cfglock1;
	opsy::utility::padding<236> _p1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_seccfgr0_r> gtzc1_mpcbb3_seccfgr31;
	opsy::utility::padding<128> _p2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr0;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr1;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr2;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr3;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr4;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr5;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr6;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr7;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr8;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr9;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr10;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr11;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr12;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr13;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr14;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr15;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr16;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr17;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr18;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr19;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr20;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr21;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr22;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr23;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr24;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr25;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr26;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr27;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr28;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr29;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr30;
	opsy::utility::memory<uint32_t,gtzc1_mpcbb3_privcfgr0_r> gtzc1_mpcbb3_privcfgr31;
};

static_assert(std::is_standard_layout_v<gtzc1_mpcbb3_p>);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_cr) == 0);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_cfglock1) == 16);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr0) == 256);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr1) == 260);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr2) == 264);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr3) == 268);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr4) == 272);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr5) == 276);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr6) == 280);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr7) == 284);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr8) == 288);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr9) == 292);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr10) == 296);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr11) == 300);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr12) == 304);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr13) == 308);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr14) == 312);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr15) == 316);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr16) == 320);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr17) == 324);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr18) == 328);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr19) == 332);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr20) == 336);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr21) == 340);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr22) == 344);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr23) == 348);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr24) == 352);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr25) == 356);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr26) == 360);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr27) == 364);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr28) == 368);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr29) == 372);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr30) == 376);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_seccfgr31) == 380);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr0) == 512);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr1) == 516);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr2) == 520);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr3) == 524);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr4) == 528);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr5) == 532);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr6) == 536);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr7) == 540);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr8) == 544);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr9) == 548);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr10) == 552);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr11) == 556);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr12) == 560);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr13) == 564);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr14) == 568);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr15) == 572);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr16) == 576);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr17) == 580);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr18) == 584);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr19) == 588);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr20) == 592);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr21) == 596);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr22) == 600);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr23) == 604);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr24) == 608);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr25) == 612);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr26) == 616);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr27) == 620);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr28) == 624);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr29) == 628);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr30) == 632);
static_assert(offsetof(gtzc1_mpcbb3_p, gtzc1_mpcbb3_privcfgr31) == 636);

/**
 * GTZC1_TZIC
 */
class gtzc1_tzic_p {
public:

/**
 * TZIC interrupt enable register 1
 */
class gtzc1_tzic_ier1_r {
public:

/**
 * illegal access interrupt enable for TIM2
 */
class tim2ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM3
 */
class tim3ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM4
 */
class tim4ie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM5
 */
class tim5ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM6
 */
class tim6ie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM7
 */
class tim7ie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM12
 */
class tim12ie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM13
 */
class tim13ie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM14
 */
class tim14ie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for WWDG
 */
class wwdgie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdgie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for IWDG
 */
class iwdgie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr iwdgie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI2
 */
class spi2ie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI3
 */
class spi3ie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART2
 */
class usart2ie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART3
 */
class usart3ie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART4
 */
class uart4ie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uart4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART5
 */
class uart5ie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for I2C1
 */
class i2c1ie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for I2C2
 */
class i2c2ie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for I3C1
 */
class i3c1ie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for CRS
 */
class crsie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART6
 */
class usart6ie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART10
 */
class usart10ie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART11
 */
class usart11ie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for HDMICEC
 */
class hdmicecie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hdmicecie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for DAC1
 */
class dac1ie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dac1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART7
 */
class uart7ie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART8
 */
class uart8ie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART9
 */
class uart9ie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart9ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UART12
 */
class uart12ie_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart12ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for DTS
 */
class dtsie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPTIM2
 */
class lptim2ie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return static_cast<gtzc1_tzic_ier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier1_r> {return opsy::utility::clear_set<gtzc1_tzic_ier1_r>(gtzc1_tzic_ier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2ie() const -> tim2ie_f {return tim2ie_f((value_ & tim2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3ie() const -> tim3ie_f {return tim3ie_f((value_ & tim3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4ie() const -> tim4ie_f {return tim4ie_f((value_ & tim4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5ie() const -> tim5ie_f {return tim5ie_f((value_ & tim5ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6ie() const -> tim6ie_f {return tim6ie_f((value_ & tim6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7ie() const -> tim7ie_f {return tim7ie_f((value_ & tim7ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12ie() const -> tim12ie_f {return tim12ie_f((value_ & tim12ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13ie() const -> tim13ie_f {return tim13ie_f((value_ & tim13ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14ie() const -> tim14ie_f {return tim14ie_f((value_ & tim14ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgie() const -> wwdgie_f {return wwdgie_f((value_ & wwdgie_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdgie() const -> iwdgie_f {return iwdgie_f((value_ & iwdgie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2ie() const -> spi2ie_f {return spi2ie_f((value_ & spi2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3ie() const -> spi3ie_f {return spi3ie_f((value_ & spi3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2ie() const -> usart2ie_f {return usart2ie_f((value_ & usart2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3ie() const -> usart3ie_f {return usart3ie_f((value_ & usart3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4ie() const -> uart4ie_f {return uart4ie_f((value_ & uart4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5ie() const -> uart5ie_f {return uart5ie_f((value_ & uart5ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1ie() const -> i2c1ie_f {return i2c1ie_f((value_ & i2c1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2ie() const -> i2c2ie_f {return i2c2ie_f((value_ & i2c2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1ie() const -> i3c1ie_f {return i3c1ie_f((value_ & i3c1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto crsie() const -> crsie_f {return crsie_f((value_ & crsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6ie() const -> usart6ie_f {return usart6ie_f((value_ & usart6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10ie() const -> usart10ie_f {return usart10ie_f((value_ & usart10ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11ie() const -> usart11ie_f {return usart11ie_f((value_ & usart11ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdmicecie() const -> hdmicecie_f {return hdmicecie_f((value_ & hdmicecie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac1ie() const -> dac1ie_f {return dac1ie_f((value_ & dac1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7ie() const -> uart7ie_f {return uart7ie_f((value_ & uart7ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8ie() const -> uart8ie_f {return uart8ie_f((value_ & uart8ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart9ie() const -> uart9ie_f {return uart9ie_f((value_ & uart9ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12ie() const -> uart12ie_f {return uart12ie_f((value_ & uart12ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtsie() const -> dtsie_f {return dtsie_f((value_ & dtsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2ie() const -> lptim2ie_f {return lptim2ie_f((value_ & lptim2ie_f::mask) != 0);}

	constexpr gtzc1_tzic_ier1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_ier1_r other) const -> gtzc1_tzic_ier1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_ier1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZIC interrupt enable register 2
 */
class gtzc1_tzic_ier2_r {
public:

/**
 * illegal access interrupt enable for FDCAN1
 */
class fdcan1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for FDCAN2
 */
class fdcan2ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for UCPD
 */
class ucpdie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM1
 */
class tim1ie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI1
 */
class spi1ie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM8
 */
class tim8ie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USART1
 */
class usart1ie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM15
 */
class tim15ie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim15ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM16
 */
class tim16ie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim16ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TIM17
 */
class tim17ie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim17ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI4
 */
class spi4ie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI6
 */
class spi6ie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SAI1
 */
class sai1ie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SAI2
 */
class sai2ie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for USB
 */
class usbie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SPI5
 */
class spi5ie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPUART
 */
class lpuart1ie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpuart1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for I2C3
 */
class i2c3ie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for I2C4
 */
class i2c4ie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPTIM1
 */
class lptim1ie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPTIM3
 */
class lptim3ie_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPTIM4
 */
class lptim4ie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for LPTIM5
 */
class lptim5ie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return static_cast<gtzc1_tzic_ier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier2_r> {return opsy::utility::clear_set<gtzc1_tzic_ier2_r>(gtzc1_tzic_ier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fdcan1ie() const -> fdcan1ie_f {return fdcan1ie_f((value_ & fdcan1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan2ie() const -> fdcan2ie_f {return fdcan2ie_f((value_ & fdcan2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdie() const -> ucpdie_f {return ucpdie_f((value_ & ucpdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim1ie() const -> tim1ie_f {return tim1ie_f((value_ & tim1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1ie() const -> spi1ie_f {return spi1ie_f((value_ & spi1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8ie() const -> tim8ie_f {return tim8ie_f((value_ & tim8ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1ie() const -> usart1ie_f {return usart1ie_f((value_ & usart1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15ie() const -> tim15ie_f {return tim15ie_f((value_ & tim15ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16ie() const -> tim16ie_f {return tim16ie_f((value_ & tim16ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17ie() const -> tim17ie_f {return tim17ie_f((value_ & tim17ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4ie() const -> spi4ie_f {return spi4ie_f((value_ & spi4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6ie() const -> spi6ie_f {return spi6ie_f((value_ & spi6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1ie() const -> sai1ie_f {return sai1ie_f((value_ & sai1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2ie() const -> sai2ie_f {return sai2ie_f((value_ & sai2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbie() const -> usbie_f {return usbie_f((value_ & usbie_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5ie() const -> spi5ie_f {return spi5ie_f((value_ & spi5ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1ie() const -> lpuart1ie_f {return lpuart1ie_f((value_ & lpuart1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3ie() const -> i2c3ie_f {return i2c3ie_f((value_ & i2c3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4ie() const -> i2c4ie_f {return i2c4ie_f((value_ & i2c4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1ie() const -> lptim1ie_f {return lptim1ie_f((value_ & lptim1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3ie() const -> lptim3ie_f {return lptim3ie_f((value_ & lptim3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4ie() const -> lptim4ie_f {return lptim4ie_f((value_ & lptim4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5ie() const -> lptim5ie_f {return lptim5ie_f((value_ & lptim5ie_f::mask) != 0);}

	constexpr gtzc1_tzic_ier2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_ier2_r other) const -> gtzc1_tzic_ier2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_ier2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZIC interrupt enable register 3
 */
class gtzc1_tzic_ier3_r {
public:

/**
 * illegal access interrupt enable for LPTIM6
 */
class lptim6ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for VREFBUF
 */
class vrefbufie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vrefbufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for CRC
 */
class crcie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for CORDIC
 */
class cordicie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for FMAC
 */
class fmacie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for register of ETH
 */
class ethie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ethie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for ICACHE
 */
class icacheie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr icacheie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for DCACHE
 */
class dcacheie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcacheie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for ADC1 and ADC2
 */
class adc12ie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for DCMI
 */
class dcmiie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmiie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for HASH
 */
class hashie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for RNG
 */
class rngie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SDMMC2
 */
class sdmmc2ie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SDMMC1
 */
class sdmmc1ie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for FMC
 */
class fmcie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for OCTOSPI1
 */
class octospi1ie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for RAMSCFG
 */
class ramcfgie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return static_cast<gtzc1_tzic_ier3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier3_r> {return opsy::utility::clear_set<gtzc1_tzic_ier3_r>(gtzc1_tzic_ier3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lptim6ie() const -> lptim6ie_f {return lptim6ie_f((value_ & lptim6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefbufie() const -> vrefbufie_f {return vrefbufie_f((value_ & vrefbufie_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcie() const -> crcie_f {return crcie_f((value_ & crcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicie() const -> cordicie_f {return cordicie_f((value_ & cordicie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacie() const -> fmacie_f {return fmacie_f((value_ & fmacie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethie() const -> ethie_f {return ethie_f((value_ & ethie_f::mask) != 0);}
	[[nodiscard]] constexpr auto icacheie() const -> icacheie_f {return icacheie_f((value_ & icacheie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcacheie() const -> dcacheie_f {return dcacheie_f((value_ & dcacheie_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12ie() const -> adc12ie_f {return adc12ie_f((value_ & adc12ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmiie() const -> dcmiie_f {return dcmiie_f((value_ & dcmiie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashie() const -> hashie_f {return hashie_f((value_ & hashie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngie() const -> rngie_f {return rngie_f((value_ & rngie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2ie() const -> sdmmc2ie_f {return sdmmc2ie_f((value_ & sdmmc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc1ie() const -> sdmmc1ie_f {return sdmmc1ie_f((value_ & sdmmc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcie() const -> fmcie_f {return fmcie_f((value_ & fmcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1ie() const -> octospi1ie_f {return octospi1ie_f((value_ & octospi1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgie() const -> ramcfgie_f {return ramcfgie_f((value_ & ramcfgie_f::mask) != 0);}

	constexpr gtzc1_tzic_ier3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_ier3_r other) const -> gtzc1_tzic_ier3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_ier3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZIC interrupt enable register 4
 */
class gtzc1_tzic_ier4_r {
public:

/**
 * illegal access interrupt enable for GPDMA1
 */
class gpdma1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for GPDMA2
 */
class gpdma2ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for FLASH registers
 */
class flash_regie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr flash_regie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for FLASH memory
 */
class flashie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr flashie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SBS
 */
class sbsie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for RTC
 */
class rtcie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rtcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for TAMP
 */
class tampie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tampie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for PWR
 */
class pwrie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pwrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for RCC
 */
class rccie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rccie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for EXTI
 */
class extiie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr extiie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for GTZC1 TZSC registers
 */
class tzsc1ie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzsc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for GTZC1 TZIC registers
 */
class tzic1ie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzic1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCWM1 (OCTOSPI1) memory bank
 */
class octospi1_memie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1_memie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCWM2 (FMC_NOR bank), MPCWM3 (FMC_NAND bank and FMC_SDRAM bank 1), and MPCWM4 (FMC_SDRAMbank 2)
 */
class fmc_memie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmc_memie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCWM4 (BKPSRAM) memory bank
 */
class bkpsramie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkpsramie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SRAM1
 */
class sram1ie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCBB1 registers
 */
class mpcbb1_regie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb1_regie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SRAM2
 */
class sram2ie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCBB2 registers
 */
class mpcbb2_regie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb2_regie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for SRAM3
 */
class sram3ie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access interrupt enable for MPCBB3 registers
 */
class mpcbb3_regie_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb3_regie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_ier4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_ier4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return static_cast<gtzc1_tzic_ier4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_ier4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_ier4_r> {return opsy::utility::clear_set<gtzc1_tzic_ier4_r>(gtzc1_tzic_ier4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpdma1ie() const -> gpdma1ie_f {return gpdma1ie_f((value_ & gpdma1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpdma2ie() const -> gpdma2ie_f {return gpdma2ie_f((value_ & gpdma2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto flash_regie() const -> flash_regie_f {return flash_regie_f((value_ & flash_regie_f::mask) != 0);}
	[[nodiscard]] constexpr auto flashie() const -> flashie_f {return flashie_f((value_ & flashie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbsie() const -> sbsie_f {return sbsie_f((value_ & sbsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcie() const -> rtcie_f {return rtcie_f((value_ & rtcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampie() const -> tampie_f {return tampie_f((value_ & tampie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pwrie() const -> pwrie_f {return pwrie_f((value_ & pwrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rccie() const -> rccie_f {return rccie_f((value_ & rccie_f::mask) != 0);}
	[[nodiscard]] constexpr auto extiie() const -> extiie_f {return extiie_f((value_ & extiie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzsc1ie() const -> tzsc1ie_f {return tzsc1ie_f((value_ & tzsc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzic1ie() const -> tzic1ie_f {return tzic1ie_f((value_ & tzic1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1_memie() const -> octospi1_memie_f {return octospi1_memie_f((value_ & octospi1_memie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmc_memie() const -> fmc_memie_f {return fmc_memie_f((value_ & fmc_memie_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpsramie() const -> bkpsramie_f {return bkpsramie_f((value_ & bkpsramie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1ie() const -> sram1ie_f {return sram1ie_f((value_ & sram1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb1_regie() const -> mpcbb1_regie_f {return mpcbb1_regie_f((value_ & mpcbb1_regie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2ie() const -> sram2ie_f {return sram2ie_f((value_ & sram2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb2_regie() const -> mpcbb2_regie_f {return mpcbb2_regie_f((value_ & mpcbb2_regie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3ie() const -> sram3ie_f {return sram3ie_f((value_ & sram3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb3_regie() const -> mpcbb3_regie_f {return mpcbb3_regie_f((value_ & mpcbb3_regie_f::mask) != 0);}

	constexpr gtzc1_tzic_ier4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_ier4_r other) const -> gtzc1_tzic_ier4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_ier4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC status register 1
 */
class gtzc1_tzic_sr1_r {
public:

/**
 * illegal access flag for TIM2
 */
class tim2f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM3
 */
class tim3f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM4
 */
class tim4f_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM5
 */
class tim5f_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM6
 */
class tim6f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM7
 */
class tim7f_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM12
 */
class tim12f_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM13
 */
class tim13f_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM14
 */
class tim14f_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for WWDG
 */
class wwdgf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for IWDG
 */
class iwdgf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr iwdgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI2
 */
class spi2f_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI3
 */
class spi3f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART2
 */
class usart2f_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART3
 */
class usart3f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART4
 */
class uart4f_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uart4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART5
 */
class uart5f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for I2C1
 */
class i2c1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for I2C2
 */
class i2c2f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for I3C1
 */
class i3c1f_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for CRS
 */
class crsf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART6
 */
class usart6f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART10
 */
class usart10f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART11
 */
class usart11f_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for HDMICEC
 */
class hdmicecf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hdmicecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for DAC1
 */
class dac1f_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dac1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART7
 */
class uart7f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART8
 */
class uart8f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART9
 */
class uart9f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart9f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UART12
 */
class uart12f_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for DTS
 */
class dtsf_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPTIM2
 */
class lptim2f_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return static_cast<gtzc1_tzic_sr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr1_r> {return opsy::utility::clear_set<gtzc1_tzic_sr1_r>(gtzc1_tzic_sr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2f() const -> tim2f_f {return tim2f_f((value_ & tim2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3f() const -> tim3f_f {return tim3f_f((value_ & tim3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4f() const -> tim4f_f {return tim4f_f((value_ & tim4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5f() const -> tim5f_f {return tim5f_f((value_ & tim5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6f() const -> tim6f_f {return tim6f_f((value_ & tim6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7f() const -> tim7f_f {return tim7f_f((value_ & tim7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12f() const -> tim12f_f {return tim12f_f((value_ & tim12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13f() const -> tim13f_f {return tim13f_f((value_ & tim13f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14f() const -> tim14f_f {return tim14f_f((value_ & tim14f_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgf() const -> wwdgf_f {return wwdgf_f((value_ & wwdgf_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdgf() const -> iwdgf_f {return iwdgf_f((value_ & iwdgf_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2f() const -> spi2f_f {return spi2f_f((value_ & spi2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3f() const -> spi3f_f {return spi3f_f((value_ & spi3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2f() const -> usart2f_f {return usart2f_f((value_ & usart2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3f() const -> usart3f_f {return usart3f_f((value_ & usart3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4f() const -> uart4f_f {return uart4f_f((value_ & uart4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5f() const -> uart5f_f {return uart5f_f((value_ & uart5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1f() const -> i2c1f_f {return i2c1f_f((value_ & i2c1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2f() const -> i2c2f_f {return i2c2f_f((value_ & i2c2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1f() const -> i3c1f_f {return i3c1f_f((value_ & i3c1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto crsf() const -> crsf_f {return crsf_f((value_ & crsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6f() const -> usart6f_f {return usart6f_f((value_ & usart6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10f() const -> usart10f_f {return usart10f_f((value_ & usart10f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11f() const -> usart11f_f {return usart11f_f((value_ & usart11f_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdmicecf() const -> hdmicecf_f {return hdmicecf_f((value_ & hdmicecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac1f() const -> dac1f_f {return dac1f_f((value_ & dac1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7f() const -> uart7f_f {return uart7f_f((value_ & uart7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8f() const -> uart8f_f {return uart8f_f((value_ & uart8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart9f() const -> uart9f_f {return uart9f_f((value_ & uart9f_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12f() const -> uart12f_f {return uart12f_f((value_ & uart12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtsf() const -> dtsf_f {return dtsf_f((value_ & dtsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2f() const -> lptim2f_f {return lptim2f_f((value_ & lptim2f_f::mask) != 0);}

	constexpr gtzc1_tzic_sr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_sr1_r other) const -> gtzc1_tzic_sr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_sr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC status register 2
 */
class gtzc1_tzic_sr2_r {
public:

/**
 * illegal access flag for FDCAN1
 */
class fdcan1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for FDCAN2
 */
class fdcan2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for UCPD
 */
class ucpdf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM1
 */
class tim1f_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI1
 */
class spi1f_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM8
 */
class tim8f_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USART1
 */
class usart1f_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM15
 */
class tim15f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim15f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM16
 */
class tim16f_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim16f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TIM17
 */
class tim17f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim17f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI4
 */
class spi4f_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI6
 */
class spi6f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SAI1
 */
class sai1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SAI2
 */
class sai2f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for USB
 */
class usbf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SPI5
 */
class spi5f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPUART
 */
class lpuart1f_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpuart1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for I2C3
 */
class i2c3f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for I2C4
 */
class i2c4f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPTIM1
 */
class lptim1f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPTIM3
 */
class lptim3f_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPTIM4
 */
class lptim4f_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for LPTIM5
 */
class lptim5f_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return static_cast<gtzc1_tzic_sr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr2_r> {return opsy::utility::clear_set<gtzc1_tzic_sr2_r>(gtzc1_tzic_sr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fdcan1f() const -> fdcan1f_f {return fdcan1f_f((value_ & fdcan1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan2f() const -> fdcan2f_f {return fdcan2f_f((value_ & fdcan2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdf() const -> ucpdf_f {return ucpdf_f((value_ & ucpdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim1f() const -> tim1f_f {return tim1f_f((value_ & tim1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1f() const -> spi1f_f {return spi1f_f((value_ & spi1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8f() const -> tim8f_f {return tim8f_f((value_ & tim8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1f() const -> usart1f_f {return usart1f_f((value_ & usart1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15f() const -> tim15f_f {return tim15f_f((value_ & tim15f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16f() const -> tim16f_f {return tim16f_f((value_ & tim16f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17f() const -> tim17f_f {return tim17f_f((value_ & tim17f_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4f() const -> spi4f_f {return spi4f_f((value_ & spi4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6f() const -> spi6f_f {return spi6f_f((value_ & spi6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1f() const -> sai1f_f {return sai1f_f((value_ & sai1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2f() const -> sai2f_f {return sai2f_f((value_ & sai2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbf() const -> usbf_f {return usbf_f((value_ & usbf_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5f() const -> spi5f_f {return spi5f_f((value_ & spi5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1f() const -> lpuart1f_f {return lpuart1f_f((value_ & lpuart1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3f() const -> i2c3f_f {return i2c3f_f((value_ & i2c3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4f() const -> i2c4f_f {return i2c4f_f((value_ & i2c4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1f() const -> lptim1f_f {return lptim1f_f((value_ & lptim1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3f() const -> lptim3f_f {return lptim3f_f((value_ & lptim3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4f() const -> lptim4f_f {return lptim4f_f((value_ & lptim4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5f() const -> lptim5f_f {return lptim5f_f((value_ & lptim5f_f::mask) != 0);}

	constexpr gtzc1_tzic_sr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_sr2_r other) const -> gtzc1_tzic_sr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_sr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC status register 3
 */
class gtzc1_tzic_sr3_r {
public:

/**
 * illegal access flag for LPTIM6
 */
class lptim6f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for VREFBUF
 */
class vrefbuff_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vrefbuff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for CRC
 */
class crcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for CORDIC
 */
class cordicf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for FMAC
 */
class fmacf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for register of ETH
 */
class ethf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ethf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for ICACHE
 */
class icachef_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr icachef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for DCACHE
 */
class dcachef_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcachef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for ADC1 and ADC2
 */
class adc12f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for DCMI
 */
class dcmif_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for HASH
 */
class hashf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for RNG
 */
class rngf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SDMMC2
 */
class sdmmc2f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SDMMC1
 */
class sdmmc1f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for FMC
 */
class fmcf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for OCTOSPI1
 */
class octospi1f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for RAMSCFG
 */
class ramcfgf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return static_cast<gtzc1_tzic_sr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr3_r> {return opsy::utility::clear_set<gtzc1_tzic_sr3_r>(gtzc1_tzic_sr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lptim6f() const -> lptim6f_f {return lptim6f_f((value_ & lptim6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefbuff() const -> vrefbuff_f {return vrefbuff_f((value_ & vrefbuff_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcf() const -> crcf_f {return crcf_f((value_ & crcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicf() const -> cordicf_f {return cordicf_f((value_ & cordicf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacf() const -> fmacf_f {return fmacf_f((value_ & fmacf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethf() const -> ethf_f {return ethf_f((value_ & ethf_f::mask) != 0);}
	[[nodiscard]] constexpr auto icachef() const -> icachef_f {return icachef_f((value_ & icachef_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcachef() const -> dcachef_f {return dcachef_f((value_ & dcachef_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12f() const -> adc12f_f {return adc12f_f((value_ & adc12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmif() const -> dcmif_f {return dcmif_f((value_ & dcmif_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashf() const -> hashf_f {return hashf_f((value_ & hashf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngf() const -> rngf_f {return rngf_f((value_ & rngf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2f() const -> sdmmc2f_f {return sdmmc2f_f((value_ & sdmmc2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc1f() const -> sdmmc1f_f {return sdmmc1f_f((value_ & sdmmc1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcf() const -> fmcf_f {return fmcf_f((value_ & fmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1f() const -> octospi1f_f {return octospi1f_f((value_ & octospi1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgf() const -> ramcfgf_f {return ramcfgf_f((value_ & ramcfgf_f::mask) != 0);}

	constexpr gtzc1_tzic_sr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_sr3_r other) const -> gtzc1_tzic_sr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_sr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZIC status register 4
 */
class gtzc1_tzic_sr4_r {
public:

/**
 * illegal access flag for GPDMA1
 */
class gpdma1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for GPDMA2
 */
class gpdma2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for FLASH registers
 */
class flash_regf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr flash_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for FLASH memory
 */
class flashf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr flashf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SBS
 */
class sbsf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for RTC
 */
class rtcf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rtcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for TAMP
 */
class tampf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tampf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for PWR
 */
class pwrf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pwrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for RCC
 */
class rccf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for EXTI
 */
class extif_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr extif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for GTZC1 TZSC registers
 */
class tzsc1f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzsc1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for GTZC1 TZIC registers
 */
class tzic1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzic1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCWM1 (OCTOSPI1) memory bank
 */
class octospi1_memf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1_memf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCWM2 (FMC_NOR bank), MPCWM3 (FMC_NAND bank and FMC_SDRAM bank 1), and MPCWM4 (FMC_SDRAMbank 2)
 */
class fmc_memf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmc_memf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCWM4 (BKPSRAM) memory bank
 */
class bkpsramf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkpsramf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SRAM1
 */
class sram1f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCBB1 registers
 */
class mpcbb1_regf_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb1_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SRAM2
 */
class sram2f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCBB2 registers
 */
class mpcbb2_regf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb2_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for SRAM3
 */
class sram3f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * illegal access flag for MPCBB3 registers
 */
class mpcbb3_regf_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mpcbb3_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_sr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_sr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return static_cast<gtzc1_tzic_sr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_sr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_sr4_r> {return opsy::utility::clear_set<gtzc1_tzic_sr4_r>(gtzc1_tzic_sr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpdma1f() const -> gpdma1f_f {return gpdma1f_f((value_ & gpdma1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpdma2f() const -> gpdma2f_f {return gpdma2f_f((value_ & gpdma2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto flash_regf() const -> flash_regf_f {return flash_regf_f((value_ & flash_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto flashf() const -> flashf_f {return flashf_f((value_ & flashf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbsf() const -> sbsf_f {return sbsf_f((value_ & sbsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcf() const -> rtcf_f {return rtcf_f((value_ & rtcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampf() const -> tampf_f {return tampf_f((value_ & tampf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pwrf() const -> pwrf_f {return pwrf_f((value_ & pwrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rccf() const -> rccf_f {return rccf_f((value_ & rccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto extif() const -> extif_f {return extif_f((value_ & extif_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzsc1f() const -> tzsc1f_f {return tzsc1f_f((value_ & tzsc1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzic1f() const -> tzic1f_f {return tzic1f_f((value_ & tzic1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1_memf() const -> octospi1_memf_f {return octospi1_memf_f((value_ & octospi1_memf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmc_memf() const -> fmc_memf_f {return fmc_memf_f((value_ & fmc_memf_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpsramf() const -> bkpsramf_f {return bkpsramf_f((value_ & bkpsramf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1f() const -> sram1f_f {return sram1f_f((value_ & sram1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb1_regf() const -> mpcbb1_regf_f {return mpcbb1_regf_f((value_ & mpcbb1_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2f() const -> sram2f_f {return sram2f_f((value_ & sram2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb2_regf() const -> mpcbb2_regf_f {return mpcbb2_regf_f((value_ & mpcbb2_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3f() const -> sram3f_f {return sram3f_f((value_ & sram3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto mpcbb3_regf() const -> mpcbb3_regf_f {return mpcbb3_regf_f((value_ & mpcbb3_regf_f::mask) != 0);}

	constexpr gtzc1_tzic_sr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_sr4_r other) const -> gtzc1_tzic_sr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_sr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC flag clear register 1
 */
class gtzc1_tzic_fcr1_r {
public:

/**
 * clear the illegal access flag for TIM2
 */
class ctim2f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM3
 */
class ctim3f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM4
 */
class ctim4f_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM5
 */
class ctim5f_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM6
 */
class ctim6f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM7
 */
class ctim7f_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM12
 */
class ctim12f_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM13
 */
class ctim13f_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctim13f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM14
 */
class ctim14f_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim14f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for WWDG
 */
class cwwdgf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cwwdgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for IWDG
 */
class ciwdgf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ciwdgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI2
 */
class cspi2f_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cspi2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI3
 */
class cspi3f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cspi3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART2
 */
class cusart2f_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cusart2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART3
 */
class cusart3f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cusart3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART4
 */
class cuart4f_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cuart4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART5
 */
class cuart5f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cuart5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for I2C1
 */
class ci2c1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ci2c1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for I2C2
 */
class ci2c2f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ci2c2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for I3C1
 */
class ci3c1f_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ci3c1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for CRS
 */
class ccrsf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ccrsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART6
 */
class cusart6f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cusart6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART10
 */
class cusart10f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cusart10f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART11
 */
class cusart11f_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cusart11f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for HDMICEC
 */
class chdmicecf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr chdmicecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for DAC1
 */
class cdac1f_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cdac1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART7
 */
class cuart7f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cuart7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART8
 */
class cuart8f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cuart8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART9
 */
class cuart9f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cuart9f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UART12
 */
class cuart12f_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cuart12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for DTS
 */
class cdtsf_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cdtsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPTIM2
 */
class clptim2f_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clptim2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr1_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return static_cast<gtzc1_tzic_fcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr1_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr1_r>(gtzc1_tzic_fcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ctim2f() const -> ctim2f_f {return ctim2f_f((value_ & ctim2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim3f() const -> ctim3f_f {return ctim3f_f((value_ & ctim3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim4f() const -> ctim4f_f {return ctim4f_f((value_ & ctim4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim5f() const -> ctim5f_f {return ctim5f_f((value_ & ctim5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim6f() const -> ctim6f_f {return ctim6f_f((value_ & ctim6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim7f() const -> ctim7f_f {return ctim7f_f((value_ & ctim7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim12f() const -> ctim12f_f {return ctim12f_f((value_ & ctim12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim13f() const -> ctim13f_f {return ctim13f_f((value_ & ctim13f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim14f() const -> ctim14f_f {return ctim14f_f((value_ & ctim14f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwwdgf() const -> cwwdgf_f {return cwwdgf_f((value_ & cwwdgf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ciwdgf() const -> ciwdgf_f {return ciwdgf_f((value_ & ciwdgf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi2f() const -> cspi2f_f {return cspi2f_f((value_ & cspi2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi3f() const -> cspi3f_f {return cspi3f_f((value_ & cspi3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart2f() const -> cusart2f_f {return cusart2f_f((value_ & cusart2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart3f() const -> cusart3f_f {return cusart3f_f((value_ & cusart3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart4f() const -> cuart4f_f {return cuart4f_f((value_ & cuart4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart5f() const -> cuart5f_f {return cuart5f_f((value_ & cuart5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ci2c1f() const -> ci2c1f_f {return ci2c1f_f((value_ & ci2c1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ci2c2f() const -> ci2c2f_f {return ci2c2f_f((value_ & ci2c2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ci3c1f() const -> ci3c1f_f {return ci3c1f_f((value_ & ci3c1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccrsf() const -> ccrsf_f {return ccrsf_f((value_ & ccrsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart6f() const -> cusart6f_f {return cusart6f_f((value_ & cusart6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart10f() const -> cusart10f_f {return cusart10f_f((value_ & cusart10f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart11f() const -> cusart11f_f {return cusart11f_f((value_ & cusart11f_f::mask) != 0);}
	[[nodiscard]] constexpr auto chdmicecf() const -> chdmicecf_f {return chdmicecf_f((value_ & chdmicecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdac1f() const -> cdac1f_f {return cdac1f_f((value_ & cdac1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart7f() const -> cuart7f_f {return cuart7f_f((value_ & cuart7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart8f() const -> cuart8f_f {return cuart8f_f((value_ & cuart8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart9f() const -> cuart9f_f {return cuart9f_f((value_ & cuart9f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cuart12f() const -> cuart12f_f {return cuart12f_f((value_ & cuart12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdtsf() const -> cdtsf_f {return cdtsf_f((value_ & cdtsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto clptim2f() const -> clptim2f_f {return clptim2f_f((value_ & clptim2f_f::mask) != 0);}

	constexpr gtzc1_tzic_fcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_fcr1_r other) const -> gtzc1_tzic_fcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_fcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC flag clear register 2
 */
class gtzc1_tzic_fcr2_r {
public:

/**
 * clear the illegal access flag for FDCAN1
 */
class cfdcan1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cfdcan1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for FDCAN2
 */
class cfdcan2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cfdcan2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for UCPD
 */
class cucpdf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cucpdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM1
 */
class ctim1f_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI1
 */
class cspi1f_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cspi1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM8
 */
class ctim8f_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USART1
 */
class cusart1f_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cusart1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM15
 */
class ctim15f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim15f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM16
 */
class ctim16f_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim16f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TIM17
 */
class ctim17f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctim17f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI4
 */
class cspi4f_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cspi4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI6
 */
class cspi6f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cspi6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SAI1
 */
class csai1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csai1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SAI2
 */
class csai2f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csai2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for USB
 */
class cusbf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cusbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SPI5
 */
class cspi5f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cspi5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPUART
 */
class clpuart1f_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clpuart1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for I2C3
 */
class ci2c3f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ci2c3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for I2C4
 */
class ci2c4f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ci2c4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPTIM1
 */
class clptim1f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clptim1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPTIM3
 */
class clptim3f_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clptim3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPTIM4
 */
class clptim4f_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clptim4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for LPTIM5
 */
class clptim5f_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clptim5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr2_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return static_cast<gtzc1_tzic_fcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr2_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr2_r>(gtzc1_tzic_fcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cfdcan1f() const -> cfdcan1f_f {return cfdcan1f_f((value_ & cfdcan1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cfdcan2f() const -> cfdcan2f_f {return cfdcan2f_f((value_ & cfdcan2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cucpdf() const -> cucpdf_f {return cucpdf_f((value_ & cucpdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim1f() const -> ctim1f_f {return ctim1f_f((value_ & ctim1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi1f() const -> cspi1f_f {return cspi1f_f((value_ & cspi1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim8f() const -> ctim8f_f {return ctim8f_f((value_ & ctim8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusart1f() const -> cusart1f_f {return cusart1f_f((value_ & cusart1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim15f() const -> ctim15f_f {return ctim15f_f((value_ & ctim15f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim16f() const -> ctim16f_f {return ctim16f_f((value_ & ctim16f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctim17f() const -> ctim17f_f {return ctim17f_f((value_ & ctim17f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi4f() const -> cspi4f_f {return cspi4f_f((value_ & cspi4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi6f() const -> cspi6f_f {return cspi6f_f((value_ & cspi6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto csai1f() const -> csai1f_f {return csai1f_f((value_ & csai1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto csai2f() const -> csai2f_f {return csai2f_f((value_ & csai2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cusbf() const -> cusbf_f {return cusbf_f((value_ & cusbf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cspi5f() const -> cspi5f_f {return cspi5f_f((value_ & cspi5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto clpuart1f() const -> clpuart1f_f {return clpuart1f_f((value_ & clpuart1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ci2c3f() const -> ci2c3f_f {return ci2c3f_f((value_ & ci2c3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ci2c4f() const -> ci2c4f_f {return ci2c4f_f((value_ & ci2c4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto clptim1f() const -> clptim1f_f {return clptim1f_f((value_ & clptim1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto clptim3f() const -> clptim3f_f {return clptim3f_f((value_ & clptim3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto clptim4f() const -> clptim4f_f {return clptim4f_f((value_ & clptim4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto clptim5f() const -> clptim5f_f {return clptim5f_f((value_ & clptim5f_f::mask) != 0);}

	constexpr gtzc1_tzic_fcr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_fcr2_r other) const -> gtzc1_tzic_fcr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_fcr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TZIC flag clear register 3
 */
class gtzc1_tzic_fcr3_r {
public:

/**
 * clear illegal access flag for LPTIM6
 */
class clptim6f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr clptim6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for VREFBUF
 */
class cvrefbuff_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cvrefbuff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for CRC
 */
class ccrcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ccrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for CORDIC
 */
class ccordicf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ccordicf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for FMAC
 */
class cfmacf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cfmacf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for register of ETH
 */
class cethf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cethf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for ICACHE
 */
class cicachef_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cicachef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for DCACHE
 */
class cdcachef_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cdcachef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for ADC1 and ADC2
 */
class cadc12f_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cadc12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for DCMI
 */
class cdcmif_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cdcmif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for HASH
 */
class chashf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr chashf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for RNG
 */
class crngf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crngf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for SDMMC2
 */
class csdmmc2f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csdmmc2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for SDMMC1
 */
class csdmmc1f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csdmmc1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for FMC
 */
class cfmcf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cfmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for OCTOSPI1
 */
class coctospi1f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr coctospi1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear illegal access flag for RAMSCFG
 */
class cramcfgf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cramcfgf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr3_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return static_cast<gtzc1_tzic_fcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr3_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr3_r>(gtzc1_tzic_fcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto clptim6f() const -> clptim6f_f {return clptim6f_f((value_ & clptim6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cvrefbuff() const -> cvrefbuff_f {return cvrefbuff_f((value_ & cvrefbuff_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccrcf() const -> ccrcf_f {return ccrcf_f((value_ & ccrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccordicf() const -> ccordicf_f {return ccordicf_f((value_ & ccordicf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cfmacf() const -> cfmacf_f {return cfmacf_f((value_ & cfmacf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cethf() const -> cethf_f {return cethf_f((value_ & cethf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cicachef() const -> cicachef_f {return cicachef_f((value_ & cicachef_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdcachef() const -> cdcachef_f {return cdcachef_f((value_ & cdcachef_f::mask) != 0);}
	[[nodiscard]] constexpr auto cadc12f() const -> cadc12f_f {return cadc12f_f((value_ & cadc12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdcmif() const -> cdcmif_f {return cdcmif_f((value_ & cdcmif_f::mask) != 0);}
	[[nodiscard]] constexpr auto chashf() const -> chashf_f {return chashf_f((value_ & chashf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crngf() const -> crngf_f {return crngf_f((value_ & crngf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csdmmc2f() const -> csdmmc2f_f {return csdmmc2f_f((value_ & csdmmc2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto csdmmc1f() const -> csdmmc1f_f {return csdmmc1f_f((value_ & csdmmc1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cfmcf() const -> cfmcf_f {return cfmcf_f((value_ & cfmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto coctospi1f() const -> coctospi1f_f {return coctospi1f_f((value_ & coctospi1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cramcfgf() const -> cramcfgf_f {return cramcfgf_f((value_ & cramcfgf_f::mask) != 0);}

	constexpr gtzc1_tzic_fcr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_fcr3_r other) const -> gtzc1_tzic_fcr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_fcr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZIC flag clear register 4
 */
class gtzc1_tzic_fcr4_r {
public:

/**
 * clear the illegal access flag for GPDMA1
 */
class cgpdma1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cgpdma1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for GPDMA2
 */
class cgpdma2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cgpdma2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for FLASH registers
 */
class cflash_regf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cflash_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for FLASH memory
 */
class cflashf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cflashf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SBS
 */
class csbsf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csbsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for RTC
 */
class crtcf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crtcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for TAMP
 */
class ctampf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctampf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for PWR
 */
class cpwrf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpwrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for RCC
 */
class crccf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for EXTI
 */
class cextif_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cextif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for GTZC1 TZSC registers
 */
class ctzsc1f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ctzsc1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for GTZC1 TZIC registers
 */
class ctzic1f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ctzic1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCWM1 (OCTOSPI1) memory bank
 */
class coctospi1_memf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr coctospi1_memf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCWM2 (FMC_NOR bank), MPCWM3 (FMC_NAND bank and FMC_SDRAM bank 1), and MPCWM4 (FMC_SDRAMbank 2)
 */
class cfmc_memf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cfmc_memf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCWM4 (BKPSRAM) memory bank
 */
class cbkpsramf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cbkpsramf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SRAM1
 */
class csram1f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csram1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCBB1 registers
 */
class cmpcbb1_regf_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmpcbb1_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SRAM2
 */
class csram2f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csram2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCBB2 registers
 */
class cmpcbb2_regf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmpcbb2_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for SRAM3
 */
class csram3f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csram3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear the illegal access flag for MPCBB3 registers
 */
class cmpcbb3_regf_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmpcbb3_regf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzic_fcr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzic_fcr4_r>() const {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return static_cast<gtzc1_tzic_fcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzic_fcr4_r> other) const -> opsy::utility::clear_set<gtzc1_tzic_fcr4_r> {return opsy::utility::clear_set<gtzc1_tzic_fcr4_r>(gtzc1_tzic_fcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cgpdma1f() const -> cgpdma1f_f {return cgpdma1f_f((value_ & cgpdma1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cgpdma2f() const -> cgpdma2f_f {return cgpdma2f_f((value_ & cgpdma2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cflash_regf() const -> cflash_regf_f {return cflash_regf_f((value_ & cflash_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cflashf() const -> cflashf_f {return cflashf_f((value_ & cflashf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csbsf() const -> csbsf_f {return csbsf_f((value_ & csbsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crtcf() const -> crtcf_f {return crtcf_f((value_ & crtcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctampf() const -> ctampf_f {return ctampf_f((value_ & ctampf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpwrf() const -> cpwrf_f {return cpwrf_f((value_ & cpwrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crccf() const -> crccf_f {return crccf_f((value_ & crccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cextif() const -> cextif_f {return cextif_f((value_ & cextif_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctzsc1f() const -> ctzsc1f_f {return ctzsc1f_f((value_ & ctzsc1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctzic1f() const -> ctzic1f_f {return ctzic1f_f((value_ & ctzic1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto coctospi1_memf() const -> coctospi1_memf_f {return coctospi1_memf_f((value_ & coctospi1_memf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cfmc_memf() const -> cfmc_memf_f {return cfmc_memf_f((value_ & cfmc_memf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cbkpsramf() const -> cbkpsramf_f {return cbkpsramf_f((value_ & cbkpsramf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csram1f() const -> csram1f_f {return csram1f_f((value_ & csram1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmpcbb1_regf() const -> cmpcbb1_regf_f {return cmpcbb1_regf_f((value_ & cmpcbb1_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csram2f() const -> csram2f_f {return csram2f_f((value_ & csram2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmpcbb2_regf() const -> cmpcbb2_regf_f {return cmpcbb2_regf_f((value_ & cmpcbb2_regf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csram3f() const -> csram3f_f {return csram3f_f((value_ & csram3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmpcbb3_regf() const -> cmpcbb3_regf_f {return cmpcbb3_regf_f((value_ & cmpcbb3_regf_f::mask) != 0);}

	constexpr gtzc1_tzic_fcr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzic_fcr4_r other) const -> gtzc1_tzic_fcr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzic_fcr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gtzc1_tzic_ier1_r> gtzc1_tzic_ier1;
	opsy::utility::memory<uint32_t,gtzc1_tzic_ier2_r> gtzc1_tzic_ier2;
	opsy::utility::memory<uint32_t,gtzc1_tzic_ier3_r> gtzc1_tzic_ier3;
	opsy::utility::memory<uint32_t,gtzc1_tzic_ier4_r> gtzc1_tzic_ier4;
	opsy::utility::memory<uint32_t,gtzc1_tzic_sr1_r> gtzc1_tzic_sr1;
	opsy::utility::memory<uint32_t,gtzc1_tzic_sr2_r> gtzc1_tzic_sr2;
	opsy::utility::memory<uint32_t,gtzc1_tzic_sr3_r> gtzc1_tzic_sr3;
	opsy::utility::memory<uint32_t,gtzc1_tzic_sr4_r> gtzc1_tzic_sr4;
	opsy::utility::memory<uint32_t,gtzc1_tzic_fcr1_r> gtzc1_tzic_fcr1;
	opsy::utility::memory<uint32_t,gtzc1_tzic_fcr2_r> gtzc1_tzic_fcr2;
	opsy::utility::memory<uint32_t,gtzc1_tzic_fcr3_r> gtzc1_tzic_fcr3;
	opsy::utility::memory<uint32_t,gtzc1_tzic_fcr4_r> gtzc1_tzic_fcr4;
};

static_assert(std::is_standard_layout_v<gtzc1_tzic_p>);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_ier1) == 0);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_ier2) == 4);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_ier3) == 8);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_ier4) == 12);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_sr1) == 16);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_sr2) == 20);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_sr3) == 24);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_sr4) == 28);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_fcr1) == 32);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_fcr2) == 36);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_fcr3) == 40);
static_assert(offsetof(gtzc1_tzic_p, gtzc1_tzic_fcr4) == 44);

/**
 * Global TrustZone controller
 */
class gtzc1_tzsc_p {
public:

/**
 * GTZC1 TZSC control register
 */
class gtzc1_tzsc_cr_r {
public:

/**
 * lock the configuration of GTZC1_TZSC_SECCFGRx and GTZC1_TZSC_PRIVCFGRx until next reset This bit is cleared by default and once set, it can not be reset until system reset.
 */
class lck_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_cr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_cr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_cr_r other) const -> gtzc1_tzsc_cr_r { return static_cast<gtzc1_tzsc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_cr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_cr_r> {return opsy::utility::clear_set<gtzc1_tzsc_cr_r>(gtzc1_tzsc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lck() const -> lck_f {return lck_f((value_ & lck_f::mask) != 0);}

	constexpr gtzc1_tzsc_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_cr_r other) const -> gtzc1_tzsc_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC secure configuration register 1
 */
class gtzc1_tzsc_seccfgr1_r {
public:

/**
 * secure access mode for TIM2
 */
class tim2sec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM3
 */
class tim3sec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM4
 */
class tim4sec_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM5
 */
class tim5sec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM6
 */
class tim6sec_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM7
 */
class tim7sec_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM12
 */
class tim12sec_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM13
 */
class tim13sec_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM14
 */
class tim14sec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for WWDG
 */
class wwdgsec_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdgsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for IWDG
 */
class iwdgsec_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr iwdgsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI2
 */
class spi2sec_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI3
 */
class spi3sec_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART2
 */
class usart2sec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART3
 */
class usart3sec_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART4
 */
class uart4sec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uart4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART5
 */
class uart5sec_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for I2C1
 */
class i2c1sec_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for I2C2
 */
class i2c2sec_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for I3C1
 */
class i3c1sec_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for CRS
 */
class crssec_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crssec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART6
 */
class usart6sec_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART10
 */
class usart10sec_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART11
 */
class usart11sec_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for HDMICEC
 */
class hdmicecsec_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hdmicecsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for DAC1
 */
class dac1sec_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dac1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART7
 */
class uart7sec_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART8
 */
class uart8sec_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART9
 */
class uart9sec_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart9sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UART12
 */
class uart12sec_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart12sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for DTS
 */
class dtssec_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtssec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPTIM2
 */
class lptim2sec_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return static_cast<gtzc1_tzsc_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr1_r>(gtzc1_tzsc_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2sec() const -> tim2sec_f {return tim2sec_f((value_ & tim2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3sec() const -> tim3sec_f {return tim3sec_f((value_ & tim3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4sec() const -> tim4sec_f {return tim4sec_f((value_ & tim4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5sec() const -> tim5sec_f {return tim5sec_f((value_ & tim5sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6sec() const -> tim6sec_f {return tim6sec_f((value_ & tim6sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7sec() const -> tim7sec_f {return tim7sec_f((value_ & tim7sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12sec() const -> tim12sec_f {return tim12sec_f((value_ & tim12sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13sec() const -> tim13sec_f {return tim13sec_f((value_ & tim13sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14sec() const -> tim14sec_f {return tim14sec_f((value_ & tim14sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgsec() const -> wwdgsec_f {return wwdgsec_f((value_ & wwdgsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdgsec() const -> iwdgsec_f {return iwdgsec_f((value_ & iwdgsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2sec() const -> spi2sec_f {return spi2sec_f((value_ & spi2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3sec() const -> spi3sec_f {return spi3sec_f((value_ & spi3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2sec() const -> usart2sec_f {return usart2sec_f((value_ & usart2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3sec() const -> usart3sec_f {return usart3sec_f((value_ & usart3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4sec() const -> uart4sec_f {return uart4sec_f((value_ & uart4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5sec() const -> uart5sec_f {return uart5sec_f((value_ & uart5sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1sec() const -> i2c1sec_f {return i2c1sec_f((value_ & i2c1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2sec() const -> i2c2sec_f {return i2c2sec_f((value_ & i2c2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1sec() const -> i3c1sec_f {return i3c1sec_f((value_ & i3c1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto crssec() const -> crssec_f {return crssec_f((value_ & crssec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6sec() const -> usart6sec_f {return usart6sec_f((value_ & usart6sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10sec() const -> usart10sec_f {return usart10sec_f((value_ & usart10sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11sec() const -> usart11sec_f {return usart11sec_f((value_ & usart11sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdmicecsec() const -> hdmicecsec_f {return hdmicecsec_f((value_ & hdmicecsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac1sec() const -> dac1sec_f {return dac1sec_f((value_ & dac1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7sec() const -> uart7sec_f {return uart7sec_f((value_ & uart7sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8sec() const -> uart8sec_f {return uart8sec_f((value_ & uart8sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart9sec() const -> uart9sec_f {return uart9sec_f((value_ & uart9sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12sec() const -> uart12sec_f {return uart12sec_f((value_ & uart12sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtssec() const -> dtssec_f {return dtssec_f((value_ & dtssec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2sec() const -> lptim2sec_f {return lptim2sec_f((value_ & lptim2sec_f::mask) != 0);}

	constexpr gtzc1_tzsc_seccfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_seccfgr1_r other) const -> gtzc1_tzsc_seccfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_seccfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC secure configuration register 2
 */
class gtzc1_tzsc_seccfgr2_r {
public:

/**
 * secure access mode for FDCAN1
 */
class fdcan1sec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for FDCAN2
 */
class fdcan2sec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for UCPD
 */
class ucpdsec_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpdsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM1
 */
class tim1sec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI1
 */
class spi1sec_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM8
 */
class tim8sec_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USART1
 */
class usart1sec_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM15
 */
class tim15sec_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim15sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM16
 */
class tim16sec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim16sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for TIM17
 */
class tim17sec_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim17sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI4
 */
class spi4sec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI6
 */
class spi6sec_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SAI1
 */
class sai1sec_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SAI2
 */
class sai2sec_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for USB
 */
class usbsec_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SPI5
 */
class spi5sec_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi5sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPUART
 */
class lpuart1sec_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpuart1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for I2C3
 */
class i2c3sec_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for I2C4
 */
class i2c4sec_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPTIM1
 */
class lptim1sec_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPTIM3
 */
class lptim3sec_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPTIM4
 */
class lptim4sec_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for LPTIM5
 */
class lptim5sec_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim5sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return static_cast<gtzc1_tzsc_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr2_r>(gtzc1_tzsc_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fdcan1sec() const -> fdcan1sec_f {return fdcan1sec_f((value_ & fdcan1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan2sec() const -> fdcan2sec_f {return fdcan2sec_f((value_ & fdcan2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdsec() const -> ucpdsec_f {return ucpdsec_f((value_ & ucpdsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim1sec() const -> tim1sec_f {return tim1sec_f((value_ & tim1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1sec() const -> spi1sec_f {return spi1sec_f((value_ & spi1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8sec() const -> tim8sec_f {return tim8sec_f((value_ & tim8sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1sec() const -> usart1sec_f {return usart1sec_f((value_ & usart1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15sec() const -> tim15sec_f {return tim15sec_f((value_ & tim15sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16sec() const -> tim16sec_f {return tim16sec_f((value_ & tim16sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17sec() const -> tim17sec_f {return tim17sec_f((value_ & tim17sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4sec() const -> spi4sec_f {return spi4sec_f((value_ & spi4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6sec() const -> spi6sec_f {return spi6sec_f((value_ & spi6sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1sec() const -> sai1sec_f {return sai1sec_f((value_ & sai1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2sec() const -> sai2sec_f {return sai2sec_f((value_ & sai2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbsec() const -> usbsec_f {return usbsec_f((value_ & usbsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5sec() const -> spi5sec_f {return spi5sec_f((value_ & spi5sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1sec() const -> lpuart1sec_f {return lpuart1sec_f((value_ & lpuart1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3sec() const -> i2c3sec_f {return i2c3sec_f((value_ & i2c3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4sec() const -> i2c4sec_f {return i2c4sec_f((value_ & i2c4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1sec() const -> lptim1sec_f {return lptim1sec_f((value_ & lptim1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3sec() const -> lptim3sec_f {return lptim3sec_f((value_ & lptim3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4sec() const -> lptim4sec_f {return lptim4sec_f((value_ & lptim4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5sec() const -> lptim5sec_f {return lptim5sec_f((value_ & lptim5sec_f::mask) != 0);}

	constexpr gtzc1_tzsc_seccfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_seccfgr2_r other) const -> gtzc1_tzsc_seccfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_seccfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC secure configuration register 3
 */
class gtzc1_tzsc_seccfgr3_r {
public:

/**
 * secure access mode for LPTIM6
 */
class lptim6sec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim6sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for VREFBUF
 */
class vrefbufsec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vrefbufsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for CRC
 */
class crcsec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for CORDIC
 */
class cordicsec_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for FMAC
 */
class fmacsec_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for register of ETH
 */
class ethsec_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ethsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for ICACHE
 */
class icachesec_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr icachesec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for DCACHE
 */
class dcachesec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcachesec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for ADC1 and ADC2
 */
class adc12sec_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for DCMI
 */
class dcmisec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmisec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for HASH
 */
class hashsec_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for RNG
 */
class rngsec_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SAES
 */
class saessec_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr saessec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for PKA
 */
class pkasec_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pkasec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SDMMC2
 */
class sdmmc1sec_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for SDMMC1
 */
class sdmmc2sec_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for FMC
 */
class fmcsec_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for OCTOSPI1
 */
class octospi1sec_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure access mode for RAMSCFG
 */
class ramcfgsec_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_seccfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return static_cast<gtzc1_tzsc_seccfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_seccfgr3_r>(gtzc1_tzsc_seccfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lptim6sec() const -> lptim6sec_f {return lptim6sec_f((value_ & lptim6sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefbufsec() const -> vrefbufsec_f {return vrefbufsec_f((value_ & vrefbufsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcsec() const -> crcsec_f {return crcsec_f((value_ & crcsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicsec() const -> cordicsec_f {return cordicsec_f((value_ & cordicsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacsec() const -> fmacsec_f {return fmacsec_f((value_ & fmacsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethsec() const -> ethsec_f {return ethsec_f((value_ & ethsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto icachesec() const -> icachesec_f {return icachesec_f((value_ & icachesec_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcachesec() const -> dcachesec_f {return dcachesec_f((value_ & dcachesec_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12sec() const -> adc12sec_f {return adc12sec_f((value_ & adc12sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmisec() const -> dcmisec_f {return dcmisec_f((value_ & dcmisec_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashsec() const -> hashsec_f {return hashsec_f((value_ & hashsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngsec() const -> rngsec_f {return rngsec_f((value_ & rngsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto saessec() const -> saessec_f {return saessec_f((value_ & saessec_f::mask) != 0);}
	[[nodiscard]] constexpr auto pkasec() const -> pkasec_f {return pkasec_f((value_ & pkasec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc1sec() const -> sdmmc1sec_f {return sdmmc1sec_f((value_ & sdmmc1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2sec() const -> sdmmc2sec_f {return sdmmc2sec_f((value_ & sdmmc2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcsec() const -> fmcsec_f {return fmcsec_f((value_ & fmcsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1sec() const -> octospi1sec_f {return octospi1sec_f((value_ & octospi1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgsec() const -> ramcfgsec_f {return ramcfgsec_f((value_ & ramcfgsec_f::mask) != 0);}

	constexpr gtzc1_tzsc_seccfgr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_seccfgr3_r other) const -> gtzc1_tzsc_seccfgr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_seccfgr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC privilege configuration register 1
 */
class gtzc1_tzsc_privcfgr1_r {
public:

/**
 * privileged access mode for TIM2
 */
class tim2priv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM3
 */
class tim3priv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM4
 */
class tim4priv_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM5
 */
class tim5priv_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM6
 */
class tim6priv_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM7
 */
class tim7priv_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM12
 */
class tim12priv_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM13
 */
class tim13priv_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM14
 */
class tim14priv_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for WWDG
 */
class wwdgpriv_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdgpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for IWDG
 */
class iwdgpriv_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr iwdgpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI2
 */
class spi2priv_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI3
 */
class spi3priv_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART2
 */
class usart2priv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART3
 */
class usart3priv_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart3priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART4
 */
class uart4priv_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uart4priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART5
 */
class uart5priv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for I2C1
 */
class i2c1priv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for I2C2
 */
class i2c2priv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for I3C1
 */
class i3c1priv_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for CRS
 */
class crspriv_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART6
 */
class usart6priv_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART10
 */
class usart10priv_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART11
 */
class usart11priv_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for HDMICEC
 */
class hdmicecpriv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hdmicecpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for DAC1
 */
class dac1priv_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dac1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART7
 */
class uart7priv_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART8
 */
class uart8priv_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART9
 */
class uart9priv_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart9priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UART12
 */
class uart12priv_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart12priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for DTS
 */
class dtspriv_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPTIM2
 */
class lptim2priv_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return static_cast<gtzc1_tzsc_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr1_r>(gtzc1_tzsc_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2priv() const -> tim2priv_f {return tim2priv_f((value_ & tim2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3priv() const -> tim3priv_f {return tim3priv_f((value_ & tim3priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4priv() const -> tim4priv_f {return tim4priv_f((value_ & tim4priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5priv() const -> tim5priv_f {return tim5priv_f((value_ & tim5priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6priv() const -> tim6priv_f {return tim6priv_f((value_ & tim6priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7priv() const -> tim7priv_f {return tim7priv_f((value_ & tim7priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12priv() const -> tim12priv_f {return tim12priv_f((value_ & tim12priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13priv() const -> tim13priv_f {return tim13priv_f((value_ & tim13priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14priv() const -> tim14priv_f {return tim14priv_f((value_ & tim14priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgpriv() const -> wwdgpriv_f {return wwdgpriv_f((value_ & wwdgpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdgpriv() const -> iwdgpriv_f {return iwdgpriv_f((value_ & iwdgpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2priv() const -> spi2priv_f {return spi2priv_f((value_ & spi2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3priv() const -> spi3priv_f {return spi3priv_f((value_ & spi3priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2priv() const -> usart2priv_f {return usart2priv_f((value_ & usart2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3priv() const -> usart3priv_f {return usart3priv_f((value_ & usart3priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4priv() const -> uart4priv_f {return uart4priv_f((value_ & uart4priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5priv() const -> uart5priv_f {return uart5priv_f((value_ & uart5priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1priv() const -> i2c1priv_f {return i2c1priv_f((value_ & i2c1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2priv() const -> i2c2priv_f {return i2c2priv_f((value_ & i2c2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1priv() const -> i3c1priv_f {return i3c1priv_f((value_ & i3c1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto crspriv() const -> crspriv_f {return crspriv_f((value_ & crspriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6priv() const -> usart6priv_f {return usart6priv_f((value_ & usart6priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10priv() const -> usart10priv_f {return usart10priv_f((value_ & usart10priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11priv() const -> usart11priv_f {return usart11priv_f((value_ & usart11priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdmicecpriv() const -> hdmicecpriv_f {return hdmicecpriv_f((value_ & hdmicecpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac1priv() const -> dac1priv_f {return dac1priv_f((value_ & dac1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7priv() const -> uart7priv_f {return uart7priv_f((value_ & uart7priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8priv() const -> uart8priv_f {return uart8priv_f((value_ & uart8priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart9priv() const -> uart9priv_f {return uart9priv_f((value_ & uart9priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12priv() const -> uart12priv_f {return uart12priv_f((value_ & uart12priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtspriv() const -> dtspriv_f {return dtspriv_f((value_ & dtspriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2priv() const -> lptim2priv_f {return lptim2priv_f((value_ & lptim2priv_f::mask) != 0);}

	constexpr gtzc1_tzsc_privcfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_privcfgr1_r other) const -> gtzc1_tzsc_privcfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_privcfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC privilege configuration register 2
 */
class gtzc1_tzsc_privcfgr2_r {
public:

/**
 * privileged access mode for FDCAN1
 */
class fdcan1priv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for FDCAN2
 */
class fdcan2priv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fdcan2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for UCPD
 */
class ucpdpriv_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpdpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM1
 */
class tim1priv_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI1
 */
class spi1priv_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM8
 */
class tim8priv_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USART1
 */
class usart1priv_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM15
 */
class tim15priv_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim15priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM16
 */
class tim16priv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim16priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for TIM17
 */
class tim17priv_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim17priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI4
 */
class spi4priv_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi4priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI6
 */
class spi6priv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SAI1
 */
class sai1priv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SAI2
 */
class sai2priv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for USB
 */
class usbpriv_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SPI5
 */
class spi5priv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi5priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPUART
 */
class lpuart1priv_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpuart1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for I2C3
 */
class i2c3priv_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c3priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for I2C4
 */
class i2c4priv_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c4priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPTIM1
 */
class lptim1priv_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPTIM3
 */
class lptim3priv_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim3priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPTIM4
 */
class lptim4priv_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim4priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for LPTIM5
 */
class lptim5priv_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lptim5priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return static_cast<gtzc1_tzsc_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr2_r>(gtzc1_tzsc_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fdcan1priv() const -> fdcan1priv_f {return fdcan1priv_f((value_ & fdcan1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan2priv() const -> fdcan2priv_f {return fdcan2priv_f((value_ & fdcan2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdpriv() const -> ucpdpriv_f {return ucpdpriv_f((value_ & ucpdpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim1priv() const -> tim1priv_f {return tim1priv_f((value_ & tim1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1priv() const -> spi1priv_f {return spi1priv_f((value_ & spi1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8priv() const -> tim8priv_f {return tim8priv_f((value_ & tim8priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1priv() const -> usart1priv_f {return usart1priv_f((value_ & usart1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15priv() const -> tim15priv_f {return tim15priv_f((value_ & tim15priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16priv() const -> tim16priv_f {return tim16priv_f((value_ & tim16priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17priv() const -> tim17priv_f {return tim17priv_f((value_ & tim17priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4priv() const -> spi4priv_f {return spi4priv_f((value_ & spi4priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6priv() const -> spi6priv_f {return spi6priv_f((value_ & spi6priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1priv() const -> sai1priv_f {return sai1priv_f((value_ & sai1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2priv() const -> sai2priv_f {return sai2priv_f((value_ & sai2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbpriv() const -> usbpriv_f {return usbpriv_f((value_ & usbpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5priv() const -> spi5priv_f {return spi5priv_f((value_ & spi5priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1priv() const -> lpuart1priv_f {return lpuart1priv_f((value_ & lpuart1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3priv() const -> i2c3priv_f {return i2c3priv_f((value_ & i2c3priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4priv() const -> i2c4priv_f {return i2c4priv_f((value_ & i2c4priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1priv() const -> lptim1priv_f {return lptim1priv_f((value_ & lptim1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3priv() const -> lptim3priv_f {return lptim3priv_f((value_ & lptim3priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4priv() const -> lptim4priv_f {return lptim4priv_f((value_ & lptim4priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5priv() const -> lptim5priv_f {return lptim5priv_f((value_ & lptim5priv_f::mask) != 0);}

	constexpr gtzc1_tzsc_privcfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_privcfgr2_r other) const -> gtzc1_tzsc_privcfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_privcfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC privilege configuration register 3
 */
class gtzc1_tzsc_privcfgr3_r {
public:

/**
 * privileged access mode for LPTIM6
 */
class lptim6priv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim6priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for VREFBUF
 */
class vrefbufpriv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vrefbufpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for CRC
 */
class crcpriv_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for CORDIC
 */
class cordicpriv_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for FMAC
 */
class fmacpriv_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for register of ETH
 */
class ethpriv_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ethpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for ICACHE
 */
class icachepriv_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr icachepriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for DCACHE
 */
class dcachepriv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcachepriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for ADC1 and ADC2
 */
class adc12priv_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for DCMI
 */
class dcmipriv_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmipriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for HASH
 */
class hashpriv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for RNG
 */
class rngpriv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SDMMC2
 */
class sdmmc2priv_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc2priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for SDMMC1
 */
class sdmmc1priv_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmmc1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for FMC
 */
class fmcpriv_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for OCTOSPI1
 */
class octospi1priv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged access mode for RAMSCFG
 */
class ramcfgpriv_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_privcfgr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return static_cast<gtzc1_tzsc_privcfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r> {return opsy::utility::clear_set<gtzc1_tzsc_privcfgr3_r>(gtzc1_tzsc_privcfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lptim6priv() const -> lptim6priv_f {return lptim6priv_f((value_ & lptim6priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefbufpriv() const -> vrefbufpriv_f {return vrefbufpriv_f((value_ & vrefbufpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcpriv() const -> crcpriv_f {return crcpriv_f((value_ & crcpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicpriv() const -> cordicpriv_f {return cordicpriv_f((value_ & cordicpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacpriv() const -> fmacpriv_f {return fmacpriv_f((value_ & fmacpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethpriv() const -> ethpriv_f {return ethpriv_f((value_ & ethpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto icachepriv() const -> icachepriv_f {return icachepriv_f((value_ & icachepriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcachepriv() const -> dcachepriv_f {return dcachepriv_f((value_ & dcachepriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12priv() const -> adc12priv_f {return adc12priv_f((value_ & adc12priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmipriv() const -> dcmipriv_f {return dcmipriv_f((value_ & dcmipriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashpriv() const -> hashpriv_f {return hashpriv_f((value_ & hashpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngpriv() const -> rngpriv_f {return rngpriv_f((value_ & rngpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2priv() const -> sdmmc2priv_f {return sdmmc2priv_f((value_ & sdmmc2priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc1priv() const -> sdmmc1priv_f {return sdmmc1priv_f((value_ & sdmmc1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcpriv() const -> fmcpriv_f {return fmcpriv_f((value_ & fmcpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1priv() const -> octospi1priv_f {return octospi1priv_f((value_ & octospi1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgpriv() const -> ramcfgpriv_f {return ramcfgpriv_f((value_ & ramcfgpriv_f::mask) != 0);}

	constexpr gtzc1_tzsc_privcfgr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_privcfgr3_r other) const -> gtzc1_tzsc_privcfgr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_privcfgr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC memory 1 sub-region A watermark configuration register
 */
class gtzc1_tzsc_mpcwm1acfgr_r {
public:

/**
 * Sub-region z enable Note: External memories that are watermark controlled start fully non-secure/unprivileged at reset when TZEN = 0xC3. When TZEN = 0xB4, external memories start fully secure/fully privileged (inverted reset-value).
 */
class sren_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwm1acfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwm1acfgr_r other) const -> gtzc1_tzsc_mpcwm1acfgr_r { return static_cast<gtzc1_tzsc_mpcwm1acfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(gtzc1_tzsc_mpcwm1acfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Sub-region A lock This bit, once set, can be cleared only by a system reset.
 */
class srlock_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr srlock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwm1acfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwm1acfgr_r other) const -> gtzc1_tzsc_mpcwm1acfgr_r { return static_cast<gtzc1_tzsc_mpcwm1acfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(gtzc1_tzsc_mpcwm1acfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Secure sub-region A of base region x This bit is taken into account only if SREN is set.
 */
class sec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwm1acfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwm1acfgr_r other) const -> gtzc1_tzsc_mpcwm1acfgr_r { return static_cast<gtzc1_tzsc_mpcwm1acfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(gtzc1_tzsc_mpcwm1acfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Privileged sub-region A of base region x This bit is taken into account only if SREN is set.
 */
class priv_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwm1acfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwm1acfgr_r other) const -> gtzc1_tzsc_mpcwm1acfgr_r { return static_cast<gtzc1_tzsc_mpcwm1acfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwm1acfgr_r>(gtzc1_tzsc_mpcwm1acfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sren() const -> sren_f {return sren_f((value_ & sren_f::mask) != 0);}
	[[nodiscard]] constexpr auto srlock() const -> srlock_f {return srlock_f((value_ & srlock_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec() const -> sec_f {return sec_f((value_ & sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv() const -> priv_f {return priv_f((value_ & priv_f::mask) != 0);}

	constexpr gtzc1_tzsc_mpcwm1acfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_mpcwm1acfgr_r other) const -> gtzc1_tzsc_mpcwm1acfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_mpcwm1acfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC memory X sub-region A watermark register
 */
class gtzc1_tzsc_mpcwmxar_r {
public:

/**
 * Start of sub-region A in region x This field defines the address offset of the sub-region A, to be multiplied by the granularity defined in Table30, versus the start of the region x. External memories that are watermark controlled, start fully non-secure at reset when TZEN=0xC3. When TZEN=0xB4, external memories start fully secure (inverted reset value).
 */
class suba_start_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr suba_start_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwmxar_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwmxar_r other) const -> gtzc1_tzsc_mpcwmxar_r { return static_cast<gtzc1_tzsc_mpcwmxar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>(gtzc1_tzsc_mpcwmxar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Length of sub-region A in region x This field defines the length of the sub-region A, to be multiplied by the granularity defined in Table30. When SUBA_START + SUBA_LENGTH is higher than the maximum size allowed for the memory, a saturation of SUBA_LENGTH is applied automatically. If SUBA_LENGTH = 0, the sub-region A is disabled.(SREN bit in GTZC1_TZSC_MPCMWxACFGR is cleared).
 */
class suba_length_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr suba_length_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwmxar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwmxar_r other) const -> gtzc1_tzsc_mpcwmxar_r { return static_cast<gtzc1_tzsc_mpcwmxar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxar_r>(gtzc1_tzsc_mpcwmxar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto suba_start() const -> suba_start_f {return suba_start_f(static_cast<uint16_t>(value_ >> suba_start_f::offset));}
	[[nodiscard]] constexpr auto suba_length() const -> suba_length_f {return suba_length_f(static_cast<uint16_t>(value_ >> suba_length_f::offset));}

	constexpr gtzc1_tzsc_mpcwmxar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_mpcwmxar_r other) const -> gtzc1_tzsc_mpcwmxar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_mpcwmxar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GTZC1 TZSC memory X sub-region B watermark register
 */
class gtzc1_tzsc_mpcwmxbr_r {
public:

/**
 * Start of sub-region B in region x This field defines the address offset of the sub-region B, to be multiplied by the granularity defined in Table30, versus the start of the region x. External memories that are watermark controlled, start fully non-secure at reset when TZEN=0xC3. When TZEN=0xB4, external memories start fully secure (inverted reset value).
 */
class subb_start_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr subb_start_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwmxbr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwmxbr_r other) const -> gtzc1_tzsc_mpcwmxbr_r { return static_cast<gtzc1_tzsc_mpcwmxbr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>(gtzc1_tzsc_mpcwmxbr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Length of sub-region B in region x This field defines the length of the sub-region B, to be multiplied by the granularity defined in Table30. When SUBB_START + SUBB_LENGTH is higher than the maximum size allowed for the memory, a saturation of SUBB_LENGTH is applied automatically. If SUBB_LENGTH = 0, the sub-region B is disabled.(SREN bit in GTZC1_TZSC_MPCMWxBCFGR is cleared).
 */
class subb_length_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr subb_length_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gtzc1_tzsc_mpcwmxbr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>() const {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>(mask, *this);}
	constexpr auto operator|(gtzc1_tzsc_mpcwmxbr_r other) const -> gtzc1_tzsc_mpcwmxbr_r { return static_cast<gtzc1_tzsc_mpcwmxbr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r> other) const -> opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r> {return opsy::utility::clear_set<gtzc1_tzsc_mpcwmxbr_r>(gtzc1_tzsc_mpcwmxbr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto subb_start() const -> subb_start_f {return subb_start_f(static_cast<uint16_t>(value_ >> subb_start_f::offset));}
	[[nodiscard]] constexpr auto subb_length() const -> subb_length_f {return subb_length_f(static_cast<uint16_t>(value_ >> subb_length_f::offset));}

	constexpr gtzc1_tzsc_mpcwmxbr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gtzc1_tzsc_mpcwmxbr_r other) const -> gtzc1_tzsc_mpcwmxbr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gtzc1_tzsc_mpcwmxbr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gtzc1_tzsc_cr_r> gtzc1_tzsc_cr;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_seccfgr1_r> gtzc1_tzsc_seccfgr1;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_seccfgr2_r> gtzc1_tzsc_seccfgr2;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_seccfgr3_r> gtzc1_tzsc_seccfgr3;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_privcfgr1_r> gtzc1_tzsc_privcfgr1;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_privcfgr2_r> gtzc1_tzsc_privcfgr2;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_privcfgr3_r> gtzc1_tzsc_privcfgr3;
	opsy::utility::padding<20> _p2;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm1acfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxar_r> gtzc1_tzsc_mpcwm1ar;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm1bcfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxbr_r> gtzc1_tzsc_mpcwm1br;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm2acfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxar_r> gtzc1_tzsc_mpcwm2ar;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm2bcfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxbr_r> gtzc1_tzsc_mpcwm2br;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm3acfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxar_r> gtzc1_tzsc_mpcwm3ar;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm3bcfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxbr_r> gtzc1_tzsc_mpcwm3br;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm4acfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxar_r> gtzc1_tzsc_mpcwm4ar;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwm1acfgr_r> gtzc1_tzsc_mpcwm4bcfgr;
	opsy::utility::memory<uint32_t,gtzc1_tzsc_mpcwmxbr_r> gtzc1_tzsc_mpcwm4br;
};

static_assert(std::is_standard_layout_v<gtzc1_tzsc_p>);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_cr) == 0);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_seccfgr1) == 16);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_seccfgr2) == 20);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_seccfgr3) == 24);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_privcfgr1) == 32);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_privcfgr2) == 36);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_privcfgr3) == 40);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm1acfgr) == 64);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm1ar) == 68);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm1bcfgr) == 72);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm1br) == 76);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm2acfgr) == 80);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm2ar) == 84);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm2bcfgr) == 88);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm2br) == 92);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm3acfgr) == 96);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm3ar) == 100);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm3bcfgr) == 104);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm3br) == 108);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm4acfgr) == 112);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm4ar) == 116);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm4bcfgr) == 120);
static_assert(offsetof(gtzc1_tzsc_p, gtzc1_tzsc_mpcwm4br) == 124);

inline gtzc1_mpcbb1_p& gtzc1_mpcbb1 = *reinterpret_cast<gtzc1_mpcbb1_p*>(0x40032C00);
inline gtzc1_mpcbb1_p& sec_gtzc1_mpcbb1 = *reinterpret_cast<gtzc1_mpcbb1_p*>(0x50032C00);
inline gtzc1_mpcbb2_p& gtzc1_mpcbb2 = *reinterpret_cast<gtzc1_mpcbb2_p*>(0x40033000);
inline gtzc1_mpcbb2_p& sec_gtzc1_mpcbb2 = *reinterpret_cast<gtzc1_mpcbb2_p*>(0x50033000);
inline gtzc1_mpcbb3_p& gtzc1_mpcbb3 = *reinterpret_cast<gtzc1_mpcbb3_p*>(0x40033400);
inline gtzc1_mpcbb3_p& sec_gtzc1_mpcbb3 = *reinterpret_cast<gtzc1_mpcbb3_p*>(0x50033400);
inline gtzc1_tzic_p& gtzc1_tzic = *reinterpret_cast<gtzc1_tzic_p*>(0x40032800);
inline gtzc1_tzic_p& sec_gtzc1_tzic = *reinterpret_cast<gtzc1_tzic_p*>(0x50032800);
inline gtzc1_tzsc_p& gtzc1_tzsc = *reinterpret_cast<gtzc1_tzsc_p*>(0x40032400);
inline gtzc1_tzsc_p& sec_gtzc1_tzsc = *reinterpret_cast<gtzc1_tzsc_p*>(0x50032400);

} // STM32H563

