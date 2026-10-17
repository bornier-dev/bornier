#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Data cache
 */
class dcache_p {
public:

/**
 * DCACHE control register 
 */
class dcache_cr_r {
public:

/**
 * enable
 */
class en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * full cache invalidation Can be set by software, only when EN = 1. Cleared by hardware when the BUSYF flag is set (during full cache invalidation operation). Writing 0 has no effect.
 */
class cacheinv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cacheinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * cache command maintenance operation (cleans and/or invalidates an address range) Can be set and cleared by software, only when no maintenance command is ongoing (BUSYCMDF = 0). others: reserved
 */
class cachecmd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cachecmd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcache_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * starts maintenance command (maintenance operation defined in CACHECMD). Can be set by software, only when EN = 1, BUSYCMDF = 0, BUSYF = 0 and CACHECMD = 0b001, 0b010 or 0b011. Cleared by hardware when the BUSYCMDF flag is set (during cache maintenance operation). Writing 0 has no effect.
 */
class startcmd_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr startcmd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * read-hit monitor enable
 */
class rhitmen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rhitmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * read-miss monitor enable
 */
class rmissmen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rmissmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * read-hit monitor reset
 */
class rhitmrst_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rhitmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * read-miss monitor reset
 */
class rmissmrst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rmissmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write-hit monitor enable
 */
class whitmen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr whitmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write-miss monitor enable
 */
class wmissmen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wmissmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write-hit monitor reset
 */
class whitmrst_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr whitmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write-miss monitor reset
 */
class wmissmrst_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wmissmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * output burst type for cache master port read accesses Write access is always done in INCR burst type.
 */
class hburst_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hburst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_cr_r>() const {return opsy::utility::clear_set<dcache_cr_r>(mask, *this);}
	constexpr auto operator|(dcache_cr_r other) const -> dcache_cr_r { return static_cast<dcache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cr_r> other) const -> opsy::utility::clear_set<dcache_cr_r> {return opsy::utility::clear_set<dcache_cr_r>(dcache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cacheinv() const -> cacheinv_f {return cacheinv_f((value_ & cacheinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto cachecmd() const -> cachecmd_f {return cachecmd_f(static_cast<uint8_t>(value_ >> cachecmd_f::offset));}
	[[nodiscard]] constexpr auto startcmd() const -> startcmd_f {return startcmd_f((value_ & startcmd_f::mask) != 0);}
	[[nodiscard]] constexpr auto rhitmen() const -> rhitmen_f {return rhitmen_f((value_ & rhitmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rmissmen() const -> rmissmen_f {return rmissmen_f((value_ & rmissmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rhitmrst() const -> rhitmrst_f {return rhitmrst_f((value_ & rhitmrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rmissmrst() const -> rmissmrst_f {return rmissmrst_f((value_ & rmissmrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto whitmen() const -> whitmen_f {return whitmen_f((value_ & whitmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto wmissmen() const -> wmissmen_f {return wmissmen_f((value_ & wmissmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto whitmrst() const -> whitmrst_f {return whitmrst_f((value_ & whitmrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto wmissmrst() const -> wmissmrst_f {return wmissmrst_f((value_ & wmissmrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto hburst() const -> hburst_f {return hburst_f((value_ & hburst_f::mask) != 0);}

	constexpr dcache_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_cr_r other) const -> dcache_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE status register 
 */
class dcache_sr_r {
public:

/**
 * full invalidate busy flag
 */
class busyf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_sr_r>() const {return opsy::utility::clear_set<dcache_sr_r>(mask, *this);}
	constexpr auto operator|(dcache_sr_r other) const -> dcache_sr_r { return static_cast<dcache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_sr_r> other) const -> opsy::utility::clear_set<dcache_sr_r> {return opsy::utility::clear_set<dcache_sr_r>(dcache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * full invalidate busy end flag Cleared by writing DCACHE_FCR.CBSYENDF = 1.
 */
class bsyendf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsyendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_sr_r>() const {return opsy::utility::clear_set<dcache_sr_r>(mask, *this);}
	constexpr auto operator|(dcache_sr_r other) const -> dcache_sr_r { return static_cast<dcache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_sr_r> other) const -> opsy::utility::clear_set<dcache_sr_r> {return opsy::utility::clear_set<dcache_sr_r>(dcache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * cache error flag Cleared by writing DCACHE_FCR.CERRF = 1.
 */
class errf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_sr_r>() const {return opsy::utility::clear_set<dcache_sr_r>(mask, *this);}
	constexpr auto operator|(dcache_sr_r other) const -> dcache_sr_r { return static_cast<dcache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_sr_r> other) const -> opsy::utility::clear_set<dcache_sr_r> {return opsy::utility::clear_set<dcache_sr_r>(dcache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * command busy flag
 */
class busycmdf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busycmdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_sr_r>() const {return opsy::utility::clear_set<dcache_sr_r>(mask, *this);}
	constexpr auto operator|(dcache_sr_r other) const -> dcache_sr_r { return static_cast<dcache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_sr_r> other) const -> opsy::utility::clear_set<dcache_sr_r> {return opsy::utility::clear_set<dcache_sr_r>(dcache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * command end flag Cleared by writing DCACHE_FCR.CCMDENDF = 1.
 */
class cmdendf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_sr_r>() const {return opsy::utility::clear_set<dcache_sr_r>(mask, *this);}
	constexpr auto operator|(dcache_sr_r other) const -> dcache_sr_r { return static_cast<dcache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_sr_r> other) const -> opsy::utility::clear_set<dcache_sr_r> {return opsy::utility::clear_set<dcache_sr_r>(dcache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto busyf() const -> busyf_f {return busyf_f((value_ & busyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto bsyendf() const -> bsyendf_f {return bsyendf_f((value_ & bsyendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto errf() const -> errf_f {return errf_f((value_ & errf_f::mask) != 0);}
	[[nodiscard]] constexpr auto busycmdf() const -> busycmdf_f {return busycmdf_f((value_ & busycmdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdendf() const -> cmdendf_f {return cmdendf_f((value_ & cmdendf_f::mask) != 0);}

	constexpr dcache_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_sr_r other) const -> dcache_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * DCACHE interrupt enable register 
 */
class dcache_ier_r {
public:

/**
 * interrupt enable on busy end Set by SW to enable an interrupt generation at the end of a cache full invalidate operation.
 */
class bsyendie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsyendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_ier_r>() const {return opsy::utility::clear_set<dcache_ier_r>(mask, *this);}
	constexpr auto operator|(dcache_ier_r other) const -> dcache_ier_r { return static_cast<dcache_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_ier_r> other) const -> opsy::utility::clear_set<dcache_ier_r> {return opsy::utility::clear_set<dcache_ier_r>(dcache_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * interrupt enable on cache error Set by software to enable an interrupt generation in case of cache functional error (eviction or clean operation write-back error)
 */
class errie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_ier_r>() const {return opsy::utility::clear_set<dcache_ier_r>(mask, *this);}
	constexpr auto operator|(dcache_ier_r other) const -> dcache_ier_r { return static_cast<dcache_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_ier_r> other) const -> opsy::utility::clear_set<dcache_ier_r> {return opsy::utility::clear_set<dcache_ier_r>(dcache_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * interrupt enable on command end Set by software to enable an interrupt generation at the end of a cache command (clean and/or invalidate an address range)
 */
class cmdendie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_ier_r>() const {return opsy::utility::clear_set<dcache_ier_r>(mask, *this);}
	constexpr auto operator|(dcache_ier_r other) const -> dcache_ier_r { return static_cast<dcache_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_ier_r> other) const -> opsy::utility::clear_set<dcache_ier_r> {return opsy::utility::clear_set<dcache_ier_r>(dcache_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bsyendie() const -> bsyendie_f {return bsyendie_f((value_ & bsyendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdendie() const -> cmdendie_f {return cmdendie_f((value_ & cmdendie_f::mask) != 0);}

	constexpr dcache_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_ier_r other) const -> dcache_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE flag clear register 
 */
class dcache_fcr_r {
public:

/**
 * clear full invalidate busy end flag Set by software.
 */
class cbsyendf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cbsyendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_fcr_r>() const {return opsy::utility::clear_set<dcache_fcr_r>(mask, *this);}
	constexpr auto operator|(dcache_fcr_r other) const -> dcache_fcr_r { return static_cast<dcache_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_fcr_r> other) const -> opsy::utility::clear_set<dcache_fcr_r> {return opsy::utility::clear_set<dcache_fcr_r>(dcache_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear cache error flag Set by software.
 */
class cerrf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cerrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_fcr_r>() const {return opsy::utility::clear_set<dcache_fcr_r>(mask, *this);}
	constexpr auto operator|(dcache_fcr_r other) const -> dcache_fcr_r { return static_cast<dcache_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_fcr_r> other) const -> opsy::utility::clear_set<dcache_fcr_r> {return opsy::utility::clear_set<dcache_fcr_r>(dcache_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear command end flag Set by software.
 */
class ccmdendf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccmdendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcache_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcache_fcr_r>() const {return opsy::utility::clear_set<dcache_fcr_r>(mask, *this);}
	constexpr auto operator|(dcache_fcr_r other) const -> dcache_fcr_r { return static_cast<dcache_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_fcr_r> other) const -> opsy::utility::clear_set<dcache_fcr_r> {return opsy::utility::clear_set<dcache_fcr_r>(dcache_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cbsyendf() const -> cbsyendf_f {return cbsyendf_f((value_ & cbsyendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cerrf() const -> cerrf_f {return cerrf_f((value_ & cerrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccmdendf() const -> ccmdendf_f {return ccmdendf_f((value_ & ccmdendf_f::mask) != 0);}

	constexpr dcache_fcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_fcr_r other) const -> dcache_fcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_fcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE read-hit monitor register 
 */
class dcache_rhmonr_r {
public:

/**
 * cache read-hit monitor counter
 */
class rhitmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rhitmon_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dcache_rhmonr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_rhmonr_r>() const {return opsy::utility::clear_set<dcache_rhmonr_r>(mask, *this);}
	constexpr auto operator|(dcache_rhmonr_r other) const -> dcache_rhmonr_r { return static_cast<dcache_rhmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_rhmonr_r> other) const -> opsy::utility::clear_set<dcache_rhmonr_r> {return opsy::utility::clear_set<dcache_rhmonr_r>(dcache_rhmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rhitmon() const -> rhitmon_f {return rhitmon_f(static_cast<uint32_t>(value_ >> rhitmon_f::offset));}

	constexpr dcache_rhmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_rhmonr_r other) const -> dcache_rhmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_rhmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE read-miss monitor register 
 */
class dcache_rmmonr_r {
public:

/**
 * cache read-miss monitor counter
 */
class rmissmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rmissmon_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcache_rmmonr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_rmmonr_r>() const {return opsy::utility::clear_set<dcache_rmmonr_r>(mask, *this);}
	constexpr auto operator|(dcache_rmmonr_r other) const -> dcache_rmmonr_r { return static_cast<dcache_rmmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_rmmonr_r> other) const -> opsy::utility::clear_set<dcache_rmmonr_r> {return opsy::utility::clear_set<dcache_rmmonr_r>(dcache_rmmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rmissmon() const -> rmissmon_f {return rmissmon_f(static_cast<uint16_t>(value_ >> rmissmon_f::offset));}

	constexpr dcache_rmmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_rmmonr_r other) const -> dcache_rmmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_rmmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE write-hit monitor register 
 */
class dcache_whmonr_r {
public:

/**
 * cache write-hit monitor counter
 */
class whitmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr whitmon_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dcache_whmonr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_whmonr_r>() const {return opsy::utility::clear_set<dcache_whmonr_r>(mask, *this);}
	constexpr auto operator|(dcache_whmonr_r other) const -> dcache_whmonr_r { return static_cast<dcache_whmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_whmonr_r> other) const -> opsy::utility::clear_set<dcache_whmonr_r> {return opsy::utility::clear_set<dcache_whmonr_r>(dcache_whmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto whitmon() const -> whitmon_f {return whitmon_f(static_cast<uint32_t>(value_ >> whitmon_f::offset));}

	constexpr dcache_whmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_whmonr_r other) const -> dcache_whmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_whmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE write-miss monitor register 
 */
class dcache_wmmonr_r {
public:

/**
 * cache write-miss monitor counter
 */
class wmissmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wmissmon_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcache_wmmonr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_wmmonr_r>() const {return opsy::utility::clear_set<dcache_wmmonr_r>(mask, *this);}
	constexpr auto operator|(dcache_wmmonr_r other) const -> dcache_wmmonr_r { return static_cast<dcache_wmmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_wmmonr_r> other) const -> opsy::utility::clear_set<dcache_wmmonr_r> {return opsy::utility::clear_set<dcache_wmmonr_r>(dcache_wmmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto wmissmon() const -> wmissmon_f {return wmissmon_f(static_cast<uint16_t>(value_ >> wmissmon_f::offset));}

	constexpr dcache_wmmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_wmmonr_r other) const -> dcache_wmmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_wmmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE command range start address register 
 */
class dcache_cmdrsaddrr_r {
public:

/**
 * start address of range to which the cache maintenance command specified in DCACHE_CR.CACHECMD field applies This register must be set before DCACHE_CR.CACHECMD is written. .
 */
class cmdstartaddr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 28;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cmdstartaddr_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dcache_cmdrsaddrr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_cmdrsaddrr_r>() const {return opsy::utility::clear_set<dcache_cmdrsaddrr_r>(mask, *this);}
	constexpr auto operator|(dcache_cmdrsaddrr_r other) const -> dcache_cmdrsaddrr_r { return static_cast<dcache_cmdrsaddrr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cmdrsaddrr_r> other) const -> opsy::utility::clear_set<dcache_cmdrsaddrr_r> {return opsy::utility::clear_set<dcache_cmdrsaddrr_r>(dcache_cmdrsaddrr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cmdstartaddr() const -> cmdstartaddr_f {return cmdstartaddr_f(static_cast<uint32_t>(value_ >> cmdstartaddr_f::offset));}

	constexpr dcache_cmdrsaddrr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_cmdrsaddrr_r other) const -> dcache_cmdrsaddrr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_cmdrsaddrr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCACHE command range end address register 
 */
class dcache_cmdreaddrr_r {
public:

/**
 * end address of range to which the cache maintenance command specified in DCACHE_CR.CACHECMD field applies This register must be set before DCACHE_CR.CACHECMD is written.
 */
class cmdendaddr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 28;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cmdendaddr_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator dcache_cmdreaddrr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcache_cmdreaddrr_r>() const {return opsy::utility::clear_set<dcache_cmdreaddrr_r>(mask, *this);}
	constexpr auto operator|(dcache_cmdreaddrr_r other) const -> dcache_cmdreaddrr_r { return static_cast<dcache_cmdreaddrr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcache_cmdreaddrr_r> other) const -> opsy::utility::clear_set<dcache_cmdreaddrr_r> {return opsy::utility::clear_set<dcache_cmdreaddrr_r>(dcache_cmdreaddrr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cmdendaddr() const -> cmdendaddr_f {return cmdendaddr_f(static_cast<uint32_t>(value_ >> cmdendaddr_f::offset));}

	constexpr dcache_cmdreaddrr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcache_cmdreaddrr_r other) const -> dcache_cmdreaddrr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcache_cmdreaddrr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dcache_cr_r> dcache_cr;
	opsy::utility::memory<uint32_t,dcache_sr_r> dcache_sr;
	opsy::utility::memory<uint32_t,dcache_ier_r> dcache_ier;
	opsy::utility::memory<uint32_t,dcache_fcr_r> dcache_fcr;
	opsy::utility::memory<uint32_t,dcache_rhmonr_r> dcache_rhmonr;
	opsy::utility::memory<uint32_t,dcache_rmmonr_r> dcache_rmmonr;
	opsy::utility::padding<8> _p0;
	opsy::utility::memory<uint32_t,dcache_whmonr_r> dcache_whmonr;
	opsy::utility::memory<uint32_t,dcache_wmmonr_r> dcache_wmmonr;
	opsy::utility::memory<uint32_t,dcache_cmdrsaddrr_r> dcache_cmdrsaddrr;
	opsy::utility::memory<uint32_t,dcache_cmdreaddrr_r> dcache_cmdreaddrr;
};

static_assert(std::is_standard_layout_v<dcache_p>);
static_assert(offsetof(dcache_p, dcache_cr) == 0);
static_assert(offsetof(dcache_p, dcache_sr) == 4);
static_assert(offsetof(dcache_p, dcache_ier) == 8);
static_assert(offsetof(dcache_p, dcache_fcr) == 12);
static_assert(offsetof(dcache_p, dcache_rhmonr) == 16);
static_assert(offsetof(dcache_p, dcache_rmmonr) == 20);
static_assert(offsetof(dcache_p, dcache_whmonr) == 32);
static_assert(offsetof(dcache_p, dcache_wmmonr) == 36);
static_assert(offsetof(dcache_p, dcache_cmdrsaddrr) == 40);
static_assert(offsetof(dcache_p, dcache_cmdreaddrr) == 44);

inline dcache_p& dcache = *reinterpret_cast<dcache_p*>(0x40031400);
inline dcache_p& sec_dcache = *reinterpret_cast<dcache_p*>(0x50031400);

} // STM32H563

