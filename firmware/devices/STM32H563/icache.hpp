#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Instruction cache
 */
class icache_p {
public:

/**
 * ICACHE control register 
 */
class icache_cr_r {
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
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * cache invalidation Set by software and cleared by hardware when the BUSYF flag is set (during cache maintenance operation). Writing 0 has no effect.
 */
class cacheinv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cacheinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * cache associativity mode selection This bit allows user to choose ICACHE set-associativity. It can be written by software only when cache is disabled (EN = 0).
 */
class waysel_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr waysel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * hit monitor enable
 */
class hitmen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hitmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * miss monitor enable
 */
class missmen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr missmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * hit monitor reset
 */
class hitmrst_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hitmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * miss monitor reset
 */
class missmrst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr missmrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_cr_r>() const {return opsy::utility::clear_set<icache_cr_r>(mask, *this);}
	constexpr auto operator|(icache_cr_r other) const -> icache_cr_r { return static_cast<icache_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_cr_r> other) const -> opsy::utility::clear_set<icache_cr_r> {return opsy::utility::clear_set<icache_cr_r>(icache_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cacheinv() const -> cacheinv_f {return cacheinv_f((value_ & cacheinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto waysel() const -> waysel_f {return waysel_f((value_ & waysel_f::mask) != 0);}
	[[nodiscard]] constexpr auto hitmen() const -> hitmen_f {return hitmen_f((value_ & hitmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto missmen() const -> missmen_f {return missmen_f((value_ & missmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto hitmrst() const -> hitmrst_f {return hitmrst_f((value_ & hitmrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto missmrst() const -> missmrst_f {return missmrst_f((value_ & missmrst_f::mask) != 0);}

	constexpr icache_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_cr_r other) const -> icache_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100; // 4 0x4

private:
	uint32_t value_;
};

/**
 * ICACHE status register 
 */
class icache_sr_r {
public:

/**
 * busy flag
 */
class busyf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_sr_r>() const {return opsy::utility::clear_set<icache_sr_r>(mask, *this);}
	constexpr auto operator|(icache_sr_r other) const -> icache_sr_r { return static_cast<icache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_sr_r> other) const -> opsy::utility::clear_set<icache_sr_r> {return opsy::utility::clear_set<icache_sr_r>(icache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * busy end flag
 */
class bsyendf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsyendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_sr_r>() const {return opsy::utility::clear_set<icache_sr_r>(mask, *this);}
	constexpr auto operator|(icache_sr_r other) const -> icache_sr_r { return static_cast<icache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_sr_r> other) const -> opsy::utility::clear_set<icache_sr_r> {return opsy::utility::clear_set<icache_sr_r>(icache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * cache error flag
 */
class errf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_sr_r>() const {return opsy::utility::clear_set<icache_sr_r>(mask, *this);}
	constexpr auto operator|(icache_sr_r other) const -> icache_sr_r { return static_cast<icache_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_sr_r> other) const -> opsy::utility::clear_set<icache_sr_r> {return opsy::utility::clear_set<icache_sr_r>(icache_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto busyf() const -> busyf_f {return busyf_f((value_ & busyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto bsyendf() const -> bsyendf_f {return bsyendf_f((value_ & bsyendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto errf() const -> errf_f {return errf_f((value_ & errf_f::mask) != 0);}

	constexpr icache_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_sr_r other) const -> icache_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * ICACHE interrupt enable register 
 */
class icache_ier_r {
public:

/**
 * interrupt enable on busy end Set by software to enable an interrupt generation at the end of a cache invalidate operation.
 */
class bsyendie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsyendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_ier_r>() const {return opsy::utility::clear_set<icache_ier_r>(mask, *this);}
	constexpr auto operator|(icache_ier_r other) const -> icache_ier_r { return static_cast<icache_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_ier_r> other) const -> opsy::utility::clear_set<icache_ier_r> {return opsy::utility::clear_set<icache_ier_r>(icache_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * interrupt enable on cache error Set by software to enable an interrupt generation in case of cache functional error (cacheable write access)
 */
class errie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_ier_r>() const {return opsy::utility::clear_set<icache_ier_r>(mask, *this);}
	constexpr auto operator|(icache_ier_r other) const -> icache_ier_r { return static_cast<icache_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_ier_r> other) const -> opsy::utility::clear_set<icache_ier_r> {return opsy::utility::clear_set<icache_ier_r>(icache_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bsyendie() const -> bsyendie_f {return bsyendie_f((value_ & bsyendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}

	constexpr icache_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_ier_r other) const -> icache_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ICACHE flag clear register 
 */
class icache_fcr_r {
public:

/**
 * clear busy end flag Set by software.
 */
class cbsyendf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cbsyendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_fcr_r>() const {return opsy::utility::clear_set<icache_fcr_r>(mask, *this);}
	constexpr auto operator|(icache_fcr_r other) const -> icache_fcr_r { return static_cast<icache_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_fcr_r> other) const -> opsy::utility::clear_set<icache_fcr_r> {return opsy::utility::clear_set<icache_fcr_r>(icache_fcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator icache_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_fcr_r>() const {return opsy::utility::clear_set<icache_fcr_r>(mask, *this);}
	constexpr auto operator|(icache_fcr_r other) const -> icache_fcr_r { return static_cast<icache_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_fcr_r> other) const -> opsy::utility::clear_set<icache_fcr_r> {return opsy::utility::clear_set<icache_fcr_r>(icache_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cbsyendf() const -> cbsyendf_f {return cbsyendf_f((value_ & cbsyendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cerrf() const -> cerrf_f {return cerrf_f((value_ & cerrf_f::mask) != 0);}

	constexpr icache_fcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_fcr_r other) const -> icache_fcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_fcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ICACHE hit monitor register 
 */
class icache_hmonr_r {
public:

/**
 * cache hit monitor counter
 */
class hitmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hitmon_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator icache_hmonr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<icache_hmonr_r>() const {return opsy::utility::clear_set<icache_hmonr_r>(mask, *this);}
	constexpr auto operator|(icache_hmonr_r other) const -> icache_hmonr_r { return static_cast<icache_hmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_hmonr_r> other) const -> opsy::utility::clear_set<icache_hmonr_r> {return opsy::utility::clear_set<icache_hmonr_r>(icache_hmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto hitmon() const -> hitmon_f {return hitmon_f(static_cast<uint32_t>(value_ >> hitmon_f::offset));}

	constexpr icache_hmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_hmonr_r other) const -> icache_hmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_hmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ICACHE miss monitor register 
 */
class icache_mmonr_r {
public:

/**
 * cache miss monitor counter
 */
class missmon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr missmon_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator icache_mmonr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<icache_mmonr_r>() const {return opsy::utility::clear_set<icache_mmonr_r>(mask, *this);}
	constexpr auto operator|(icache_mmonr_r other) const -> icache_mmonr_r { return static_cast<icache_mmonr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_mmonr_r> other) const -> opsy::utility::clear_set<icache_mmonr_r> {return opsy::utility::clear_set<icache_mmonr_r>(icache_mmonr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto missmon() const -> missmon_f {return missmon_f(static_cast<uint16_t>(value_ >> missmon_f::offset));}

	constexpr icache_mmonr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_mmonr_r other) const -> icache_mmonr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_mmonr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ICACHE region X configuration register
 */
class icache_crrx_r {
public:

/**
 * base address for region x This alias address is replaced by REMAPADDR field. The only useful bits are [28:RI], where 21 less than or equal RI less than or equal 27 is the number of bits of RSIZE (see ). If the programmed value has more LSBs, the useless bits are ignored.
 */
class baseaddr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr baseaddr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator icache_crrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * size for region x
 */
class rsize_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator icache_crrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * enable for region x
 */
class ren_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_crrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * remapped address for region x This field replaces the alias address defined by BASEADDR field. The only useful bits are [31:RI], where 21 less than or equal RI less than or equal 27 is the number of bits of RSIZE (see ). If the programmed value has more LSBs, the useless bits are ignored.
 */
class remapaddr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr remapaddr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator icache_crrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * AHB cache master selection for region x
 */
class mstsel_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mstsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_crrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * output burst type for region x
 */
class hburst_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hburst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator icache_crrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<icache_crrx_r>() const {return opsy::utility::clear_set<icache_crrx_r>(mask, *this);}
	constexpr auto operator|(icache_crrx_r other) const -> icache_crrx_r { return static_cast<icache_crrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<icache_crrx_r> other) const -> opsy::utility::clear_set<icache_crrx_r> {return opsy::utility::clear_set<icache_crrx_r>(icache_crrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto baseaddr() const -> baseaddr_f {return baseaddr_f(static_cast<uint8_t>(value_ >> baseaddr_f::offset));}
	[[nodiscard]] constexpr auto rsize() const -> rsize_f {return rsize_f(static_cast<uint8_t>(value_ >> rsize_f::offset));}
	[[nodiscard]] constexpr auto ren() const -> ren_f {return ren_f((value_ & ren_f::mask) != 0);}
	[[nodiscard]] constexpr auto remapaddr() const -> remapaddr_f {return remapaddr_f(static_cast<uint16_t>(value_ >> remapaddr_f::offset));}
	[[nodiscard]] constexpr auto mstsel() const -> mstsel_f {return mstsel_f((value_ & mstsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto hburst() const -> hburst_f {return hburst_f((value_ & hburst_f::mask) != 0);}

	constexpr icache_crrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(icache_crrx_r other) const -> icache_crrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> icache_crrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000000; // 512 0x200

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,icache_cr_r> icache_cr;
	opsy::utility::memory<uint32_t,icache_sr_r> icache_sr;
	opsy::utility::memory<uint32_t,icache_ier_r> icache_ier;
	opsy::utility::memory<uint32_t,icache_fcr_r> icache_fcr;
	opsy::utility::memory<uint32_t,icache_hmonr_r> icache_hmonr;
	opsy::utility::memory<uint32_t,icache_mmonr_r> icache_mmonr;
	opsy::utility::padding<8> _p0;
	opsy::utility::memory<uint32_t,icache_crrx_r> icache_crr0;
	opsy::utility::memory<uint32_t,icache_crrx_r> icache_crr1;
	opsy::utility::memory<uint32_t,icache_crrx_r> icache_crr2;
	opsy::utility::memory<uint32_t,icache_crrx_r> icache_crr3;
};

static_assert(std::is_standard_layout_v<icache_p>);
static_assert(offsetof(icache_p, icache_cr) == 0);
static_assert(offsetof(icache_p, icache_sr) == 4);
static_assert(offsetof(icache_p, icache_ier) == 8);
static_assert(offsetof(icache_p, icache_fcr) == 12);
static_assert(offsetof(icache_p, icache_hmonr) == 16);
static_assert(offsetof(icache_p, icache_mmonr) == 20);
static_assert(offsetof(icache_p, icache_crr0) == 32);
static_assert(offsetof(icache_p, icache_crr1) == 36);
static_assert(offsetof(icache_p, icache_crr2) == 40);
static_assert(offsetof(icache_p, icache_crr3) == 44);

inline icache_p& icache = *reinterpret_cast<icache_p*>(0x40030400);
inline icache_p& sec_icache = *reinterpret_cast<icache_p*>(0x50030400);

} // STM32H563

