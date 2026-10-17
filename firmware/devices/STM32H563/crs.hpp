#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Clock recovery system
 */
class crs_p {
public:

/**
 * CRS control register 
 */
class crs_cr_r {
public:

/**
 * SYNC event OK interrupt enable
 */
class syncokie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning interrupt enable
 */
class syncwarnie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization or trimming error interrupt enable
 */
class errie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC interrupt enable
 */
class esyncie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error counter enable This bit enables the oscillator clock for the frequency error counter. When this bit is set, the CRS_CFGR register is write-protected and cannot be modified.
 */
class cen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic trimming enable This bit enables the automatic hardware adjustment of TRIM bits according to the measured frequency error between two SYNC events. If this bit is set, the TRIM bits are read-only. The TRIM value can be adjusted by hardware by one or two steps at a time, depending on the measured frequency error value. Refer to for more details.
 */
class autotrimen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr autotrimen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Generate software SYNC event This bit is set by software in order to generate a software SYNC event. It is automatically cleared by hardware.
 */
class swsync_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swsync_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 oscillator smooth trimming These bits provide a user-programmable trimming value to the HSI48 oscillator. They can be programmed to adjust to variations in voltage and temperature that influence the frequency of the HSI48 oscillator. The default value is 32, which corresponds to the middle of the trimming interval. The trimming step is specified in the product datasheet. A higher TRIM value corresponds to a higher output frequency. When the AUTOTRIMEN bit is set, this field is controlled by hardware and is read-only.
 */
class trim_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trim_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto syncokie() const -> syncokie_f {return syncokie_f((value_ & syncokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnie() const -> syncwarnie_f {return syncwarnie_f((value_ & syncwarnie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncie() const -> esyncie_f {return esyncie_f((value_ & esyncie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cen() const -> cen_f {return cen_f((value_ & cen_f::mask) != 0);}
	[[nodiscard]] constexpr auto autotrimen() const -> autotrimen_f {return autotrimen_f((value_ & autotrimen_f::mask) != 0);}
	[[nodiscard]] constexpr auto swsync() const -> swsync_f {return swsync_f((value_ & swsync_f::mask) != 0);}
	[[nodiscard]] constexpr auto trim() const -> trim_f {return trim_f(static_cast<uint8_t>(value_ >> trim_f::offset));}

	constexpr crs_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_cr_r other) const -> crs_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000; // 8192 0x2000

private:
	uint32_t value_;
};

/**
 * CRS configuration register 
 */
class crs_cfgr_r {
public:

/**
 * Counter reload value RELOAD is the value to be loaded in the frequency error counter with each SYNC event. Refer to for more details about counter behavior.
 */
class reload_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr reload_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Frequency error limit FELIM contains the value to be used to evaluate the captured frequency error value latched in the FECAP[15:0] bits of the CRS_ISR register. Refer to for more details about FECAP evaluation.
 */
class felim_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr felim_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC divider These bits are set and cleared by software to control the division factor of the SYNC signal.
 */
class syncdiv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr syncdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC signal source selection These bits are set and cleared by software to select the SYNC signal source (see CRS internal input/output signals for STM32U575/585): Note: When using USB LPM (Link Power Management) and the device is in Sleep mode, the periodic USB SOF is not generated by the host. No SYNC signal is therefore provided to the CRS to calibrate the HSI48 oscillator on the run. To guarantee the required clock precision after waking up from Sleep mode, the LSE or reference clock on the GPIOs must be used as SYNC signal.
 */
class syncsrc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr syncsrc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC polarity selection This bit is set and cleared by software to select the input polarity for the SYNC signal source.
 */
class syncpol_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr syncpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto reload() const -> reload_f {return reload_f(static_cast<uint16_t>(value_ >> reload_f::offset));}
	[[nodiscard]] constexpr auto felim() const -> felim_f {return felim_f(static_cast<uint8_t>(value_ >> felim_f::offset));}
	[[nodiscard]] constexpr auto syncdiv() const -> syncdiv_f {return syncdiv_f(static_cast<uint8_t>(value_ >> syncdiv_f::offset));}
	[[nodiscard]] constexpr auto syncsrc() const -> syncsrc_f {return syncsrc_f(static_cast<uint8_t>(value_ >> syncsrc_f::offset));}
	[[nodiscard]] constexpr auto syncpol() const -> syncpol_f {return syncpol_f((value_ & syncpol_f::mask) != 0);}

	constexpr crs_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_cfgr_r other) const -> crs_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000001000101011101101111111; // 539147135 0x2022BB7F

private:
	uint32_t value_;
};

/**
 * CRS interrupt and status register 
 */
class crs_isr_r {
public:

/**
 * SYNC event OK flag This flag is set by hardware when the measured frequency error is smaller than FELIM * 3. This means that either no adjustment of the TRIM value is needed or that an adjustment by one trimming step is enough to compensate the frequency error. An interrupt is generated if the SYNCOKIE bit is set in the CRS_CR register. It is cleared by software by setting the SYNCOKC bit in the CRS_ICR register.
 */
class syncokf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning flag This flag is set by hardware when the measured frequency error is greater than or equal to FELIM * 3, but smaller than FELIM * 128. This means that to compensate the frequency error, the TRIM value must be adjusted by two steps or more. An interrupt is generated if the SYNCWARNIE bit is set in the CRS_CR register. It is cleared by software by setting the SYNCWARNC bit in the CRS_ICR register.
 */
class syncwarnf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error flag This flag is set by hardware in case of any synchronization or trimming error. It is the logical OR of the TRIMOVF, SYNCMISS and SYNCERR bits. An interrupt is generated if the ERRIE bit is set in the CRS_CR register. It is cleared by software in reaction to setting the ERRC bit in the CRS_ICR register, which clears the TRIMOVF, SYNCMISS and SYNCERR bits.
 */
class errf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC flag This flag is set by hardware when the frequency error counter reached a zero value. An interrupt is generated if the ESYNCIE bit is set in the CRS_CR register. It is cleared by software by setting the ESYNCC bit in the CRS_ICR register.
 */
class esyncf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC error This flag is set by hardware when the SYNC pulse arrives before the ESYNC event and the measured frequency error is greater than or equal to FELIM * 128. This means that the frequency error is too big (internal frequency too low) to be compensated by adjusting the TRIM value, and that some other action has to be taken. An interrupt is generated if the ERRIE bit is set in the CRS_CR register. It is cleared by software by setting the ERRC bit in the CRS_ICR register.
 */
class syncerr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr syncerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC missed This flag is set by hardware when the frequency error counter reached value FELIM * 128 and no SYNC was detected, meaning either that a SYNC pulse was missed or that the frequency error is too big (internal frequency too high) to be compensated by adjusting the TRIM value, and that some other action has to be taken. At this point, the frequency error counter is stopped (waiting for a next SYNC) and an interrupt is generated if the ERRIE bit is set in the CRS_CR register. It is cleared by software by setting the ERRC bit in the CRS_ICR register.
 */
class syncmiss_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr syncmiss_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trimming overflow or underflow This flag is set by hardware when the automatic trimming tries to over- or under-flow the TRIM value. An interrupt is generated if the ERRIE bit is set in the CRS_CR register. It is cleared by software by setting the ERRC bit in the CRS_ICR register.
 */
class trimovf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr trimovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error direction FEDIR is the counting direction of the frequency error counter latched in the time of the last SYNC event. It shows whether the actual frequency is below or above the target.
 */
class fedir_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fedir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error capture FECAP is the frequency error counter value latched in the time of the last SYNC event. Refer to for more details about FECAP usage.
 */
class fecap_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fecap_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator crs_isr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto syncokf() const -> syncokf_f {return syncokf_f((value_ & syncokf_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnf() const -> syncwarnf_f {return syncwarnf_f((value_ & syncwarnf_f::mask) != 0);}
	[[nodiscard]] constexpr auto errf() const -> errf_f {return errf_f((value_ & errf_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncf() const -> esyncf_f {return esyncf_f((value_ & esyncf_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncerr() const -> syncerr_f {return syncerr_f((value_ & syncerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncmiss() const -> syncmiss_f {return syncmiss_f((value_ & syncmiss_f::mask) != 0);}
	[[nodiscard]] constexpr auto trimovf() const -> trimovf_f {return trimovf_f((value_ & trimovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fedir() const -> fedir_f {return fedir_f((value_ & fedir_f::mask) != 0);}
	[[nodiscard]] constexpr auto fecap() const -> fecap_f {return fecap_f(static_cast<uint16_t>(value_ >> fecap_f::offset));}

	constexpr crs_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_isr_r other) const -> crs_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * CRS interrupt flag clear register 
 */
class crs_icr_r {
public:

/**
 * SYNC event OK clear flag Writing 1 to this bit clears the SYNCOKF flag in the CRS_ISR register.
 */
class syncokc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning clear flag Writing 1 to this bit clears the SYNCWARNF flag in the CRS_ISR register.
 */
class syncwarnc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error clear flag Writing 1 to this bit clears TRIMOVF, SYNCMISS and SYNCERR bits and consequently also the ERRF flag in the CRS_ISR register.
 */
class errc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC clear flag Writing 1 to this bit clears the ESYNCF flag in the CRS_ISR register.
 */
class esyncc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto syncokc() const -> syncokc_f {return syncokc_f((value_ & syncokc_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnc() const -> syncwarnc_f {return syncwarnc_f((value_ & syncwarnc_f::mask) != 0);}
	[[nodiscard]] constexpr auto errc() const -> errc_f {return errc_f((value_ & errc_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncc() const -> esyncc_f {return esyncc_f((value_ & esyncc_f::mask) != 0);}

	constexpr crs_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_icr_r other) const -> crs_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,crs_cr_r> crs_cr;
	opsy::utility::memory<uint32_t,crs_cfgr_r> crs_cfgr;
	opsy::utility::memory<uint32_t,crs_isr_r> crs_isr;
	opsy::utility::memory<uint32_t,crs_icr_r> crs_icr;
};

static_assert(std::is_standard_layout_v<crs_p>);
static_assert(offsetof(crs_p, crs_cr) == 0);
static_assert(offsetof(crs_p, crs_cfgr) == 4);
static_assert(offsetof(crs_p, crs_isr) == 8);
static_assert(offsetof(crs_p, crs_icr) == 12);

inline crs_p& crs = *reinterpret_cast<crs_p*>(0x40006000);
inline crs_p& sec_crs = *reinterpret_cast<crs_p*>(0x50006000);

} // STM32H563

