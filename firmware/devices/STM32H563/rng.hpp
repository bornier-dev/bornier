#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * True random number generator
 */
class rng_p {
public:

/**
 * RNG control register 
 */
class rng_cr_r {
public:

/**
 * True random number generator enable
 */
class rngen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rngen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt Enable
 */
class ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock error detection The clock error detection cannot be enabled nor disabled on-the-fly when the RNG is enabled, i.e. to enable or disable CED the RNG must be disabled. Writing this bit is taken into account only if CONDRST bit is set to 1 in the same access, while CONFIGLOCK remains at 0. Writing to this bit is ignored if CONFIGLOCK=1.
 */
class ced_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ced_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto reset disable When auto-reset is enabled application still need to clear SEIS bit after a noise source error. Writing this bit is taken into account only if CONDRST bit is set to 1 in the same access, while CONFIGLOCK remains at 0. Writing to this bit is ignored if CONFIGLOCK=1.
 */
class ardis_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ardis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG configuration 3 Reserved to the RNG configuration (bitfield 3). Refer to RNG_CONFIG1 bitfield for details. If NISTC bit is cleared in this register RNG_CONFIG3 bitfield values are ignored by RNG.
 */
class rng_config3_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rng_config3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Non NIST compliant four conditioning loops are performed and 512 bits of noise source are used. Writing this bit is taken into account only if CONDRST bit is set to 1 in the same access, while CONFIGLOCK remains at 0. Writing to this bit is ignored if CONFIGLOCK=1.
 */
class nistc_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr nistc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG configuration 2 Reserved to the RNG configuration (bitfield 2). Refer to RNG_CONFIG1 bitfield for details.
 */
class rng_config2_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rng_config2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clock divider factor This value used to configure an internal programmable divider (from 1 to 16) acting on the incoming RNG clock. These bits can be written only when the core is disabled (RNGEN=0). ... Writing these bits is taken into account only if CONDRST bit is set to 1 in the same access, while CONFIGLOCK remains at 0. Writing to this bit is ignored if CONFIGLOCK=1.
 */
class clkdiv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr clkdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RNG configuration 1 Reserved to the RNG configuration (bitfield 1). Must be initialized using the recommended value documented in . Writing any bit of RNG_CONFIG1 is taken into account only if CONDRST bit is set to 1 in the same access, while CONFIGLOCK remains at 0. Writing to this bit is ignored if CONFIGLOCK=1.
 */
class rng_config1_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rng_config1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Conditioning soft reset Write 1 and then write 0 to reset the conditioning logic, clear all the FIFOs and start a new RNG initialization process, with RNG_SR cleared. Registers RNG_CR and RNG_NSCR are not changed by CONDRST. This bit must be set to 1 in the same access that set any configuration bits [29:4]. In other words, when CONDRST bit is set to 1 correct configuration in bits [29:4] must also be written. When CONDRST is set to 0 by software its value goes to 0 when the reset process is done. It takes about 2 AHB clock cycles + 2 RNG clock cycles.
 */
class condrst_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr condrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG Config Lock This bitfield is set once: if this bit is set it can only be reset to 0 if RNG is reset.
 */
class configlock_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr configlock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_cr_r>() const {return opsy::utility::clear_set<rng_cr_r>(mask, *this);}
	constexpr auto operator|(rng_cr_r other) const -> rng_cr_r { return static_cast<rng_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_cr_r> other) const -> opsy::utility::clear_set<rng_cr_r> {return opsy::utility::clear_set<rng_cr_r>(rng_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rngen() const -> rngen_f {return rngen_f((value_ & rngen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ie() const -> ie_f {return ie_f((value_ & ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ced() const -> ced_f {return ced_f((value_ & ced_f::mask) != 0);}
	[[nodiscard]] constexpr auto ardis() const -> ardis_f {return ardis_f((value_ & ardis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rng_config3() const -> rng_config3_f {return rng_config3_f(static_cast<uint8_t>(value_ >> rng_config3_f::offset));}
	[[nodiscard]] constexpr auto nistc() const -> nistc_f {return nistc_f((value_ & nistc_f::mask) != 0);}
	[[nodiscard]] constexpr auto rng_config2() const -> rng_config2_f {return rng_config2_f(static_cast<uint8_t>(value_ >> rng_config2_f::offset));}
	[[nodiscard]] constexpr auto clkdiv() const -> clkdiv_f {return clkdiv_f(static_cast<uint8_t>(value_ >> clkdiv_f::offset));}
	[[nodiscard]] constexpr auto rng_config1() const -> rng_config1_f {return rng_config1_f(static_cast<uint8_t>(value_ >> rng_config1_f::offset));}
	[[nodiscard]] constexpr auto condrst() const -> condrst_f {return condrst_f((value_ & condrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto configlock() const -> configlock_f {return configlock_f((value_ & configlock_f::mask) != 0);}

	constexpr rng_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rng_cr_r other) const -> rng_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rng_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100001110001111100000000; // 8855296 0x871F00

private:
	uint32_t value_;
};

/**
 * RNG status register 
 */
class rng_sr_r {
public:

/**
 * Data Ready Once the output buffer becomes empty (after reading the RNG_DR register), this bit returns to 0 until a new random value is generated. Note: The DRDY bit can rise when the peripheral is disabled (RNGEN=0 in the RNG_CR register). If IE=1 in the RNG_CR register, an interrupt is generated when DRDY=1.
 */
class drdy_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr drdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_sr_r>() const {return opsy::utility::clear_set<rng_sr_r>(mask, *this);}
	constexpr auto operator|(rng_sr_r other) const -> rng_sr_r { return static_cast<rng_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_sr_r> other) const -> opsy::utility::clear_set<rng_sr_r> {return opsy::utility::clear_set<rng_sr_r>(rng_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock error current status Note: CECS bit is valid only if the CED bit in the RNG_CR register is set to 0.
 */
class cecs_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cecs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_sr_r>() const {return opsy::utility::clear_set<rng_sr_r>(mask, *this);}
	constexpr auto operator|(rng_sr_r other) const -> rng_sr_r { return static_cast<rng_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_sr_r> other) const -> opsy::utility::clear_set<rng_sr_r> {return opsy::utility::clear_set<rng_sr_r>(rng_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Seed error current status Run-time repetition count test failed (noise source has provided more than 24 consecutive bits at a constant value 0' or 1', or more than 32 consecutive occurrence of two bits patterns 01' or 10') Start-up or continuous adaptive proportion test on noise source failed. Start-up post-processing/conditioning sanity check failed.
 */
class secs_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr secs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_sr_r>() const {return opsy::utility::clear_set<rng_sr_r>(mask, *this);}
	constexpr auto operator|(rng_sr_r other) const -> rng_sr_r { return static_cast<rng_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_sr_r> other) const -> opsy::utility::clear_set<rng_sr_r> {return opsy::utility::clear_set<rng_sr_r>(rng_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock error interrupt status This bit is set at the same time as CECS. It is cleared by writing 0. Writing 1 has no effect. An interrupt is pending if IE = 1 in the RNG_CR register.
 */
class ceis_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ceis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_sr_r>() const {return opsy::utility::clear_set<rng_sr_r>(mask, *this);}
	constexpr auto operator|(rng_sr_r other) const -> rng_sr_r { return static_cast<rng_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_sr_r> other) const -> opsy::utility::clear_set<rng_sr_r> {return opsy::utility::clear_set<rng_sr_r>(rng_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Seed error interrupt status This bit is set at the same time as SECS. It is cleared by writing 0 (unless CONDRST is used). Writing 1 has no effect. An interrupt is pending if IE = 1 in the RNG_CR register.
 */
class seis_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr seis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rng_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rng_sr_r>() const {return opsy::utility::clear_set<rng_sr_r>(mask, *this);}
	constexpr auto operator|(rng_sr_r other) const -> rng_sr_r { return static_cast<rng_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_sr_r> other) const -> opsy::utility::clear_set<rng_sr_r> {return opsy::utility::clear_set<rng_sr_r>(rng_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto drdy() const -> drdy_f {return drdy_f((value_ & drdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cecs() const -> cecs_f {return cecs_f((value_ & cecs_f::mask) != 0);}
	[[nodiscard]] constexpr auto secs() const -> secs_f {return secs_f((value_ & secs_f::mask) != 0);}
	[[nodiscard]] constexpr auto ceis() const -> ceis_f {return ceis_f((value_ & ceis_f::mask) != 0);}
	[[nodiscard]] constexpr auto seis() const -> seis_f {return seis_f((value_ & seis_f::mask) != 0);}

	constexpr rng_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rng_sr_r other) const -> rng_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rng_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RNG data register 
 */
class rng_dr_r {
public:

/**
 * Random data 32-bit random data which are valid when DRDY=1. When DRDY=0 RNDATA value is zero. It is recommended to always verify that RNG_DR is different from zero. Because when it is the case a seed error occurred between RNG_SR polling and RND_DR output reading (rare event).
 */
class rndata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rndata_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator rng_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_dr_r>() const {return opsy::utility::clear_set<rng_dr_r>(mask, *this);}
	constexpr auto operator|(rng_dr_r other) const -> rng_dr_r { return static_cast<rng_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_dr_r> other) const -> opsy::utility::clear_set<rng_dr_r> {return opsy::utility::clear_set<rng_dr_r>(rng_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rndata() const -> rndata_f {return rndata_f(static_cast<uint32_t>(value_ >> rndata_f::offset));}

	constexpr rng_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rng_dr_r other) const -> rng_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rng_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RNG noise source control register
 */
class rng_nscr_r {
public:

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 1. 
 */
class en_osc1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr en_osc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 2.
 */
class en_osc2_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr en_osc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 3.
 */
class en_osc3_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr en_osc3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 4.
 */
class en_osc4_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr en_osc4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 5.
 */
class en_osc5_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr en_osc5_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * When the RNG is enabled (RNGEN bit set), each bit of this bitfield enables one of the three inputs from the oscillator instance number 6.
 */
class en_osc6_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr en_osc6_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rng_nscr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_nscr_r>() const {return opsy::utility::clear_set<rng_nscr_r>(mask, *this);}
	constexpr auto operator|(rng_nscr_r other) const -> rng_nscr_r { return static_cast<rng_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_nscr_r> other) const -> opsy::utility::clear_set<rng_nscr_r> {return opsy::utility::clear_set<rng_nscr_r>(rng_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto en_osc1() const -> en_osc1_f {return en_osc1_f(static_cast<uint8_t>(value_ >> en_osc1_f::offset));}
	[[nodiscard]] constexpr auto en_osc2() const -> en_osc2_f {return en_osc2_f(static_cast<uint8_t>(value_ >> en_osc2_f::offset));}
	[[nodiscard]] constexpr auto en_osc3() const -> en_osc3_f {return en_osc3_f(static_cast<uint8_t>(value_ >> en_osc3_f::offset));}
	[[nodiscard]] constexpr auto en_osc4() const -> en_osc4_f {return en_osc4_f(static_cast<uint8_t>(value_ >> en_osc4_f::offset));}
	[[nodiscard]] constexpr auto en_osc5() const -> en_osc5_f {return en_osc5_f(static_cast<uint8_t>(value_ >> en_osc5_f::offset));}
	[[nodiscard]] constexpr auto en_osc6() const -> en_osc6_f {return en_osc6_f(static_cast<uint8_t>(value_ >> en_osc6_f::offset));}

	constexpr rng_nscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rng_nscr_r other) const -> rng_nscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rng_nscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111111111111111111; // 262143 0x3FFFF

private:
	uint32_t value_;
};

/**
 * RNG health test control register 
 */
class rng_htcr_r {
public:

/**
 * health test configuration This configuration is used by RNG to configure the health tests. See entropy source validation for the recommended value. Note: The RNG behavior, including the read to this register, is not guaranteed if a different value from the recommended value is written.
 */
class htcfg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr htcfg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator rng_htcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rng_htcr_r>() const {return opsy::utility::clear_set<rng_htcr_r>(mask, *this);}
	constexpr auto operator|(rng_htcr_r other) const -> rng_htcr_r { return static_cast<rng_htcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rng_htcr_r> other) const -> opsy::utility::clear_set<rng_htcr_r> {return opsy::utility::clear_set<rng_htcr_r>(rng_htcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto htcfg() const -> htcfg_f {return htcfg_f(static_cast<uint32_t>(value_ >> htcfg_f::offset));}

	constexpr rng_htcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rng_htcr_r other) const -> rng_htcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rng_htcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111001010101100; // 29356 0x72AC

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,rng_cr_r> rng_cr;
	opsy::utility::memory<uint32_t,rng_sr_r> rng_sr;
	opsy::utility::memory<uint32_t,rng_dr_r> rng_dr;
	opsy::utility::memory<uint32_t,rng_nscr_r> rng_nscr;
	opsy::utility::memory<uint32_t,rng_htcr_r> rng_htcr;
};

static_assert(std::is_standard_layout_v<rng_p>);
static_assert(offsetof(rng_p, rng_cr) == 0);
static_assert(offsetof(rng_p, rng_sr) == 4);
static_assert(offsetof(rng_p, rng_dr) == 8);
static_assert(offsetof(rng_p, rng_nscr) == 12);
static_assert(offsetof(rng_p, rng_htcr) == 16);

inline rng_p& rng = *reinterpret_cast<rng_p*>(0x420C0800);
inline rng_p& sec_rng = *reinterpret_cast<rng_p*>(0x520C0800);

} // STM32H563

