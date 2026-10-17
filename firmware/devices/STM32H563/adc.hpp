#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Analog to digital converter
 */
class adc1_p {
public:

/**
 * ADC interrupt and status register
 */
class adc_isr_r {
public:

/**
 * ADC ready 
 */
class adrdy_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr adrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of sampling flag 
 */
class eosmp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eosmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of conversion flag 
 */
class eoc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eoc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular sequence flag 
 */
class eos_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eos_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC overrun 
 */
class ovr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected channel end of conversion flag 
 */
class jeoc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeoc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected channel end of sequence flag 
 */
class jeos_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeos_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 flag 
 */
class awd1_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr awd1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 2 flag 
 */
class awd2_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 3 flag 
 */
class awd3_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected context queue overflow 
 */
class jqovf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr jqovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_isr_r>() const {return opsy::utility::clear_set<adc_isr_r>(mask, *this);}
	constexpr auto operator|(adc_isr_r other) const -> adc_isr_r { return static_cast<adc_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_isr_r> other) const -> opsy::utility::clear_set<adc_isr_r> {return opsy::utility::clear_set<adc_isr_r>(adc_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto adrdy() const -> adrdy_f {return adrdy_f((value_ & adrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto eosmp() const -> eosmp_f {return eosmp_f((value_ & eosmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto eoc() const -> eoc_f {return eoc_f((value_ & eoc_f::mask) != 0);}
	[[nodiscard]] constexpr auto eos() const -> eos_f {return eos_f((value_ & eos_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr() const -> ovr_f {return ovr_f((value_ & ovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeoc() const -> jeoc_f {return jeoc_f((value_ & jeoc_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeos() const -> jeos_f {return jeos_f((value_ & jeos_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1() const -> awd1_f {return awd1_f((value_ & awd1_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd2() const -> awd2_f {return awd2_f((value_ & awd2_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd3() const -> awd3_f {return awd3_f((value_ & awd3_f::mask) != 0);}
	[[nodiscard]] constexpr auto jqovf() const -> jqovf_f {return jqovf_f((value_ & jqovf_f::mask) != 0);}

	constexpr adc_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_isr_r other) const -> adc_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC interrupt enable register
 */
class adc_ier_r {
public:

/**
 * ADC ready interrupt enable 
 */
class adrdyie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr adrdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of sampling flag interrupt enable for regular conversions 
 */
class eosmpie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eosmpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular conversion interrupt enable 
 */
class eocie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eocie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular sequence of conversions interrupt enable 
 */
class eosie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eosie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun interrupt enable 
 */
class ovrie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected conversion interrupt enable 
 */
class jeocie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeocie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected sequence of conversions interrupt enable 
 */
class jeosie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeosie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 interrupt enable 
 */
class awd1ie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr awd1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 2 interrupt enable 
 */
class awd2ie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 3 interrupt enable 
 */
class awd3ie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected context queue overflow interrupt enable 
 */
class jqovfie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr jqovfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ier_r>() const {return opsy::utility::clear_set<adc_ier_r>(mask, *this);}
	constexpr auto operator|(adc_ier_r other) const -> adc_ier_r { return static_cast<adc_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ier_r> other) const -> opsy::utility::clear_set<adc_ier_r> {return opsy::utility::clear_set<adc_ier_r>(adc_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto adrdyie() const -> adrdyie_f {return adrdyie_f((value_ & adrdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eosmpie() const -> eosmpie_f {return eosmpie_f((value_ & eosmpie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eocie() const -> eocie_f {return eocie_f((value_ & eocie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eosie() const -> eosie_f {return eosie_f((value_ & eosie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrie() const -> ovrie_f {return ovrie_f((value_ & ovrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeocie() const -> jeocie_f {return jeocie_f((value_ & jeocie_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeosie() const -> jeosie_f {return jeosie_f((value_ & jeosie_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1ie() const -> awd1ie_f {return awd1ie_f((value_ & awd1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd2ie() const -> awd2ie_f {return awd2ie_f((value_ & awd2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd3ie() const -> awd3ie_f {return awd3ie_f((value_ & awd3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto jqovfie() const -> jqovfie_f {return jqovfie_f((value_ & jqovfie_f::mask) != 0);}

	constexpr adc_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_ier_r other) const -> adc_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC control register
 */
class adc_cr_r {
public:

/**
 * ADC enable control 
 */
class aden_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr aden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC disable command 
 */
class addis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC start of regular conversion 
 */
class adstart_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr adstart_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC start of injected conversion 
 */
class jadstart_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jadstart_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC stop of regular conversion command 
 */
class adstp_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr adstp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC stop of injected conversion command 
 */
class jadstp_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jadstp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC voltage regulator enable 
 */
class advregen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr advregen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Deep-power-down enable 
 */
class deeppwd_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr deeppwd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Differential mode for calibration 
 */
class adcaldif_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr adcaldif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC calibration 
 */
class adcal_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr adcal_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cr_r>() const {return opsy::utility::clear_set<adc_cr_r>(mask, *this);}
	constexpr auto operator|(adc_cr_r other) const -> adc_cr_r { return static_cast<adc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cr_r> other) const -> opsy::utility::clear_set<adc_cr_r> {return opsy::utility::clear_set<adc_cr_r>(adc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto aden() const -> aden_f {return aden_f((value_ & aden_f::mask) != 0);}
	[[nodiscard]] constexpr auto addis() const -> addis_f {return addis_f((value_ & addis_f::mask) != 0);}
	[[nodiscard]] constexpr auto adstart() const -> adstart_f {return adstart_f((value_ & adstart_f::mask) != 0);}
	[[nodiscard]] constexpr auto jadstart() const -> jadstart_f {return jadstart_f((value_ & jadstart_f::mask) != 0);}
	[[nodiscard]] constexpr auto adstp() const -> adstp_f {return adstp_f((value_ & adstp_f::mask) != 0);}
	[[nodiscard]] constexpr auto jadstp() const -> jadstp_f {return jadstp_f((value_ & jadstp_f::mask) != 0);}
	[[nodiscard]] constexpr auto advregen() const -> advregen_f {return advregen_f((value_ & advregen_f::mask) != 0);}
	[[nodiscard]] constexpr auto deeppwd() const -> deeppwd_f {return deeppwd_f((value_ & deeppwd_f::mask) != 0);}
	[[nodiscard]] constexpr auto adcaldif() const -> adcaldif_f {return adcaldif_f((value_ & adcaldif_f::mask) != 0);}
	[[nodiscard]] constexpr auto adcal() const -> adcal_f {return adcal_f((value_ & adcal_f::mask) != 0);}

	constexpr adc_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_cr_r other) const -> adc_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000000000000000000000000; // 536870912 0x20000000

private:
	uint32_t value_;
};

/**
 * ADC configuration register
 */
class adc_cfgr_r {
public:

/**
 * Direct memory access enable 
 */
class dmaen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direct memory access configuration 
 */
class dmacfg_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmacfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data resolution 
 */
class res_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr res_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External trigger selection for regular group These bits select the external event used to trigger the start of conversion of a regular group: ... Note: The software is allowed to write these bits only when ADSTART = 0 (which ensures that no regular conversion is ongoing).
 */
class extsel_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr extsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External trigger enable and polarity selection for regular channels 
 */
class exten_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr exten_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Overrun mode 
 */
class ovrmod_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrmod_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Single / continuous conversion mode for regular conversions 
 */
class cont_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cont_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Delayed conversion mode 
 */
class autdly_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr autdly_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data alignment 
 */
class align_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr align_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Discontinuous mode for regular channels 
 */
class discen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr discen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Discontinuous mode channel count 
 */
class discnum_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr discnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Discontinuous mode on injected channels 
 */
class jdiscen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jdiscen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * JSQR queue mode 
 */
class jqm_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jqm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable the watchdog 1 on a single channel or on all channels 
 */
class awd1sgl_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr awd1sgl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 enable on regular channels 
 */
class awd1en_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr awd1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 enable on injected channels 
 */
class jawd1en_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jawd1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic injected group conversion 
 */
class jauto_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jauto_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 channel selection 
 */
class awd1ch_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr awd1ch_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Injected queue disable 
 */
class jqdis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jqdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr_r>() const {return opsy::utility::clear_set<adc_cfgr_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr_r other) const -> adc_cfgr_r { return static_cast<adc_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr_r> other) const -> opsy::utility::clear_set<adc_cfgr_r> {return opsy::utility::clear_set<adc_cfgr_r>(adc_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dmaen() const -> dmaen_f {return dmaen_f((value_ & dmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmacfg() const -> dmacfg_f {return dmacfg_f((value_ & dmacfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto res() const -> res_f {return res_f(static_cast<uint8_t>(value_ >> res_f::offset));}
	[[nodiscard]] constexpr auto extsel() const -> extsel_f {return extsel_f(static_cast<uint8_t>(value_ >> extsel_f::offset));}
	[[nodiscard]] constexpr auto exten() const -> exten_f {return exten_f(static_cast<uint8_t>(value_ >> exten_f::offset));}
	[[nodiscard]] constexpr auto ovrmod() const -> ovrmod_f {return ovrmod_f((value_ & ovrmod_f::mask) != 0);}
	[[nodiscard]] constexpr auto cont() const -> cont_f {return cont_f((value_ & cont_f::mask) != 0);}
	[[nodiscard]] constexpr auto autdly() const -> autdly_f {return autdly_f((value_ & autdly_f::mask) != 0);}
	[[nodiscard]] constexpr auto align() const -> align_f {return align_f((value_ & align_f::mask) != 0);}
	[[nodiscard]] constexpr auto discen() const -> discen_f {return discen_f((value_ & discen_f::mask) != 0);}
	[[nodiscard]] constexpr auto discnum() const -> discnum_f {return discnum_f(static_cast<uint8_t>(value_ >> discnum_f::offset));}
	[[nodiscard]] constexpr auto jdiscen() const -> jdiscen_f {return jdiscen_f((value_ & jdiscen_f::mask) != 0);}
	[[nodiscard]] constexpr auto jqm() const -> jqm_f {return jqm_f((value_ & jqm_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1sgl() const -> awd1sgl_f {return awd1sgl_f((value_ & awd1sgl_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1en() const -> awd1en_f {return awd1en_f((value_ & awd1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto jawd1en() const -> jawd1en_f {return jawd1en_f((value_ & jawd1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto jauto() const -> jauto_f {return jauto_f((value_ & jauto_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1ch() const -> awd1ch_f {return awd1ch_f(static_cast<uint8_t>(value_ >> awd1ch_f::offset));}
	[[nodiscard]] constexpr auto jqdis() const -> jqdis_f {return jqdis_f((value_ & jqdis_f::mask) != 0);}

	constexpr adc_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_cfgr_r other) const -> adc_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000000000000000000000; // 2147483648 0x80000000

private:
	uint32_t value_;
};

/**
 * ADC configuration register 2
 */
class adc_cfgr2_r {
public:

/**
 * Regular oversampling Enable 
 */
class rovse_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rovse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected oversampling Enable 
 */
class jovse_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jovse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Oversampling ratio 
 */
class ovsr_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ovsr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Oversampling shift 
 */
class ovss_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ovss_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Triggered Regular oversampling 
 */
class trovs_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr trovs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Regular oversampling mode 
 */
class rovsm_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rovsm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software trigger bit for sampling time control trigger mode 
 */
class swtrig_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swtrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bulb sampling mode 
 */
class bulb_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bulb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Sampling time control trigger mode 
 */
class smptrig_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smptrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_cfgr2_r>() const {return opsy::utility::clear_set<adc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(adc_cfgr2_r other) const -> adc_cfgr2_r { return static_cast<adc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cfgr2_r> other) const -> opsy::utility::clear_set<adc_cfgr2_r> {return opsy::utility::clear_set<adc_cfgr2_r>(adc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rovse() const -> rovse_f {return rovse_f((value_ & rovse_f::mask) != 0);}
	[[nodiscard]] constexpr auto jovse() const -> jovse_f {return jovse_f((value_ & jovse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovsr() const -> ovsr_f {return ovsr_f(static_cast<uint8_t>(value_ >> ovsr_f::offset));}
	[[nodiscard]] constexpr auto ovss() const -> ovss_f {return ovss_f(static_cast<uint8_t>(value_ >> ovss_f::offset));}
	[[nodiscard]] constexpr auto trovs() const -> trovs_f {return trovs_f((value_ & trovs_f::mask) != 0);}
	[[nodiscard]] constexpr auto rovsm() const -> rovsm_f {return rovsm_f((value_ & rovsm_f::mask) != 0);}
	[[nodiscard]] constexpr auto swtrig() const -> swtrig_f {return swtrig_f((value_ & swtrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto bulb() const -> bulb_f {return bulb_f((value_ & bulb_f::mask) != 0);}
	[[nodiscard]] constexpr auto smptrig() const -> smptrig_f {return smptrig_f((value_ & smptrig_f::mask) != 0);}

	constexpr adc_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_cfgr2_r other) const -> adc_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC sample time register 1
 */
class adc_smpr1_r {
public:

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr smp0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp1_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr smp1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp2_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp3_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp4_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp5_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp5_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp6_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp6_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp7_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp7_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp8_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp8_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=9 to 0) 
 */
class smp9_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp9_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Addition of one clock cycle to the sampling time.
 */
class smpplus_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smpplus_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_smpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_smpr1_r>() const {return opsy::utility::clear_set<adc_smpr1_r>(mask, *this);}
	constexpr auto operator|(adc_smpr1_r other) const -> adc_smpr1_r { return static_cast<adc_smpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr1_r> other) const -> opsy::utility::clear_set<adc_smpr1_r> {return opsy::utility::clear_set<adc_smpr1_r>(adc_smpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto smp0() const -> smp0_f {return smp0_f(static_cast<uint8_t>(value_ >> smp0_f::offset));}
	[[nodiscard]] constexpr auto smp1() const -> smp1_f {return smp1_f(static_cast<uint8_t>(value_ >> smp1_f::offset));}
	[[nodiscard]] constexpr auto smp2() const -> smp2_f {return smp2_f(static_cast<uint8_t>(value_ >> smp2_f::offset));}
	[[nodiscard]] constexpr auto smp3() const -> smp3_f {return smp3_f(static_cast<uint8_t>(value_ >> smp3_f::offset));}
	[[nodiscard]] constexpr auto smp4() const -> smp4_f {return smp4_f(static_cast<uint8_t>(value_ >> smp4_f::offset));}
	[[nodiscard]] constexpr auto smp5() const -> smp5_f {return smp5_f(static_cast<uint8_t>(value_ >> smp5_f::offset));}
	[[nodiscard]] constexpr auto smp6() const -> smp6_f {return smp6_f(static_cast<uint8_t>(value_ >> smp6_f::offset));}
	[[nodiscard]] constexpr auto smp7() const -> smp7_f {return smp7_f(static_cast<uint8_t>(value_ >> smp7_f::offset));}
	[[nodiscard]] constexpr auto smp8() const -> smp8_f {return smp8_f(static_cast<uint8_t>(value_ >> smp8_f::offset));}
	[[nodiscard]] constexpr auto smp9() const -> smp9_f {return smp9_f(static_cast<uint8_t>(value_ >> smp9_f::offset));}
	[[nodiscard]] constexpr auto smpplus() const -> smpplus_f {return smpplus_f((value_ & smpplus_f::mask) != 0);}

	constexpr adc_smpr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_smpr1_r other) const -> adc_smpr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_smpr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC sample time register 2
 */
class adc_smpr2_r {
public:

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp10_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr smp10_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp11_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr smp11_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp12_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp12_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp13_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp13_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp14_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr smp14_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp15_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp16_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp16_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp17_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp17_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp18_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp18_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Channel x sampling time selection (x=19 to 10) 
 */
class smp19_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr smp19_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_smpr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_smpr2_r>() const {return opsy::utility::clear_set<adc_smpr2_r>(mask, *this);}
	constexpr auto operator|(adc_smpr2_r other) const -> adc_smpr2_r { return static_cast<adc_smpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_smpr2_r> other) const -> opsy::utility::clear_set<adc_smpr2_r> {return opsy::utility::clear_set<adc_smpr2_r>(adc_smpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto smp10() const -> smp10_f {return smp10_f(static_cast<uint8_t>(value_ >> smp10_f::offset));}
	[[nodiscard]] constexpr auto smp11() const -> smp11_f {return smp11_f(static_cast<uint8_t>(value_ >> smp11_f::offset));}
	[[nodiscard]] constexpr auto smp12() const -> smp12_f {return smp12_f(static_cast<uint8_t>(value_ >> smp12_f::offset));}
	[[nodiscard]] constexpr auto smp13() const -> smp13_f {return smp13_f(static_cast<uint8_t>(value_ >> smp13_f::offset));}
	[[nodiscard]] constexpr auto smp14() const -> smp14_f {return smp14_f(static_cast<uint8_t>(value_ >> smp14_f::offset));}
	[[nodiscard]] constexpr auto smp15() const -> smp15_f {return smp15_f(static_cast<uint8_t>(value_ >> smp15_f::offset));}
	[[nodiscard]] constexpr auto smp16() const -> smp16_f {return smp16_f(static_cast<uint8_t>(value_ >> smp16_f::offset));}
	[[nodiscard]] constexpr auto smp17() const -> smp17_f {return smp17_f(static_cast<uint8_t>(value_ >> smp17_f::offset));}
	[[nodiscard]] constexpr auto smp18() const -> smp18_f {return smp18_f(static_cast<uint8_t>(value_ >> smp18_f::offset));}
	[[nodiscard]] constexpr auto smp19() const -> smp19_f {return smp19_f(static_cast<uint8_t>(value_ >> smp19_f::offset));}

	constexpr adc_smpr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_smpr2_r other) const -> adc_smpr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_smpr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC watchdog threshold register 1
 */
class adc_tr1_r {
public:

/**
 * Analog watchdog 1 lower threshold 
 */
class lt1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lt1_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_tr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr1_r>() const {return opsy::utility::clear_set<adc_tr1_r>(mask, *this);}
	constexpr auto operator|(adc_tr1_r other) const -> adc_tr1_r { return static_cast<adc_tr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr1_r> other) const -> opsy::utility::clear_set<adc_tr1_r> {return opsy::utility::clear_set<adc_tr1_r>(adc_tr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Analog watchdog filtering parameter 
 */
class awdfilt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr awdfilt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_tr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr1_r>() const {return opsy::utility::clear_set<adc_tr1_r>(mask, *this);}
	constexpr auto operator|(adc_tr1_r other) const -> adc_tr1_r { return static_cast<adc_tr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr1_r> other) const -> opsy::utility::clear_set<adc_tr1_r> {return opsy::utility::clear_set<adc_tr1_r>(adc_tr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Analog watchdog 1 higher threshold 
 */
class ht1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht1_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_tr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr1_r>() const {return opsy::utility::clear_set<adc_tr1_r>(mask, *this);}
	constexpr auto operator|(adc_tr1_r other) const -> adc_tr1_r { return static_cast<adc_tr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr1_r> other) const -> opsy::utility::clear_set<adc_tr1_r> {return opsy::utility::clear_set<adc_tr1_r>(adc_tr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto lt1() const -> lt1_f {return lt1_f(static_cast<uint16_t>(value_ >> lt1_f::offset));}
	[[nodiscard]] constexpr auto awdfilt() const -> awdfilt_f {return awdfilt_f(static_cast<uint8_t>(value_ >> awdfilt_f::offset));}
	[[nodiscard]] constexpr auto ht1() const -> ht1_f {return ht1_f(static_cast<uint16_t>(value_ >> ht1_f::offset));}

	constexpr adc_tr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_tr1_r other) const -> adc_tr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_tr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111110000000000000000; // 268369920 0xFFF0000

private:
	uint32_t value_;
};

/**
 * ADC watchdog threshold register 2
 */
class adc_tr2_r {
public:

/**
 * Analog watchdog 2 lower threshold 
 */
class lt2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr lt2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_tr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr2_r>() const {return opsy::utility::clear_set<adc_tr2_r>(mask, *this);}
	constexpr auto operator|(adc_tr2_r other) const -> adc_tr2_r { return static_cast<adc_tr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr2_r> other) const -> opsy::utility::clear_set<adc_tr2_r> {return opsy::utility::clear_set<adc_tr2_r>(adc_tr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Analog watchdog 2 higher threshold 
 */
class ht2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_tr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr2_r>() const {return opsy::utility::clear_set<adc_tr2_r>(mask, *this);}
	constexpr auto operator|(adc_tr2_r other) const -> adc_tr2_r { return static_cast<adc_tr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr2_r> other) const -> opsy::utility::clear_set<adc_tr2_r> {return opsy::utility::clear_set<adc_tr2_r>(adc_tr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lt2() const -> lt2_f {return lt2_f(static_cast<uint8_t>(value_ >> lt2_f::offset));}
	[[nodiscard]] constexpr auto ht2() const -> ht2_f {return ht2_f(static_cast<uint8_t>(value_ >> ht2_f::offset));}

	constexpr adc_tr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_tr2_r other) const -> adc_tr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_tr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111111110000000000000000; // 16711680 0xFF0000

private:
	uint32_t value_;
};

/**
 * ADC watchdog threshold register 3
 */
class adc_tr3_r {
public:

/**
 * Analog watchdog 3 lower threshold 
 */
class lt3_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr lt3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_tr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr3_r>() const {return opsy::utility::clear_set<adc_tr3_r>(mask, *this);}
	constexpr auto operator|(adc_tr3_r other) const -> adc_tr3_r { return static_cast<adc_tr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr3_r> other) const -> opsy::utility::clear_set<adc_tr3_r> {return opsy::utility::clear_set<adc_tr3_r>(adc_tr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Analog watchdog 3 higher threshold 
 */
class ht3_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_tr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_tr3_r>() const {return opsy::utility::clear_set<adc_tr3_r>(mask, *this);}
	constexpr auto operator|(adc_tr3_r other) const -> adc_tr3_r { return static_cast<adc_tr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_tr3_r> other) const -> opsy::utility::clear_set<adc_tr3_r> {return opsy::utility::clear_set<adc_tr3_r>(adc_tr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lt3() const -> lt3_f {return lt3_f(static_cast<uint8_t>(value_ >> lt3_f::offset));}
	[[nodiscard]] constexpr auto ht3() const -> ht3_f {return ht3_f(static_cast<uint8_t>(value_ >> ht3_f::offset));}

	constexpr adc_tr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_tr3_r other) const -> adc_tr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_tr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111111110000000000000000; // 16711680 0xFF0000

private:
	uint32_t value_;
};

/**
 * ADC regular sequence register 1
 */
class adc_sqr1_r {
public:

/**
 * Regular channel sequence length 
 */
class l_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr l_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr1_r>() const {return opsy::utility::clear_set<adc_sqr1_r>(mask, *this);}
	constexpr auto operator|(adc_sqr1_r other) const -> adc_sqr1_r { return static_cast<adc_sqr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr1_r> other) const -> opsy::utility::clear_set<adc_sqr1_r> {return opsy::utility::clear_set<adc_sqr1_r>(adc_sqr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 1st conversion in regular sequence 
 */
class sq1_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sq1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr1_r>() const {return opsy::utility::clear_set<adc_sqr1_r>(mask, *this);}
	constexpr auto operator|(adc_sqr1_r other) const -> adc_sqr1_r { return static_cast<adc_sqr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr1_r> other) const -> opsy::utility::clear_set<adc_sqr1_r> {return opsy::utility::clear_set<adc_sqr1_r>(adc_sqr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 2nd conversion in regular sequence 
 */
class sq2_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr1_r>() const {return opsy::utility::clear_set<adc_sqr1_r>(mask, *this);}
	constexpr auto operator|(adc_sqr1_r other) const -> adc_sqr1_r { return static_cast<adc_sqr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr1_r> other) const -> opsy::utility::clear_set<adc_sqr1_r> {return opsy::utility::clear_set<adc_sqr1_r>(adc_sqr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 3rd conversion in regular sequence 
 */
class sq3_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr1_r>() const {return opsy::utility::clear_set<adc_sqr1_r>(mask, *this);}
	constexpr auto operator|(adc_sqr1_r other) const -> adc_sqr1_r { return static_cast<adc_sqr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr1_r> other) const -> opsy::utility::clear_set<adc_sqr1_r> {return opsy::utility::clear_set<adc_sqr1_r>(adc_sqr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 4th conversion in regular sequence 
 */
class sq4_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr1_r>() const {return opsy::utility::clear_set<adc_sqr1_r>(mask, *this);}
	constexpr auto operator|(adc_sqr1_r other) const -> adc_sqr1_r { return static_cast<adc_sqr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr1_r> other) const -> opsy::utility::clear_set<adc_sqr1_r> {return opsy::utility::clear_set<adc_sqr1_r>(adc_sqr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto l() const -> l_f {return l_f(static_cast<uint8_t>(value_ >> l_f::offset));}
	[[nodiscard]] constexpr auto sq1() const -> sq1_f {return sq1_f(static_cast<uint8_t>(value_ >> sq1_f::offset));}
	[[nodiscard]] constexpr auto sq2() const -> sq2_f {return sq2_f(static_cast<uint8_t>(value_ >> sq2_f::offset));}
	[[nodiscard]] constexpr auto sq3() const -> sq3_f {return sq3_f(static_cast<uint8_t>(value_ >> sq3_f::offset));}
	[[nodiscard]] constexpr auto sq4() const -> sq4_f {return sq4_f(static_cast<uint8_t>(value_ >> sq4_f::offset));}

	constexpr adc_sqr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_sqr1_r other) const -> adc_sqr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_sqr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC regular sequence register 2
 */
class adc_sqr2_r {
public:

/**
 * 5th conversion in regular sequence 
 */
class sq5_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sq5_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr2_r>() const {return opsy::utility::clear_set<adc_sqr2_r>(mask, *this);}
	constexpr auto operator|(adc_sqr2_r other) const -> adc_sqr2_r { return static_cast<adc_sqr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr2_r> other) const -> opsy::utility::clear_set<adc_sqr2_r> {return opsy::utility::clear_set<adc_sqr2_r>(adc_sqr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 6th conversion in regular sequence 
 */
class sq6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sq6_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr2_r>() const {return opsy::utility::clear_set<adc_sqr2_r>(mask, *this);}
	constexpr auto operator|(adc_sqr2_r other) const -> adc_sqr2_r { return static_cast<adc_sqr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr2_r> other) const -> opsy::utility::clear_set<adc_sqr2_r> {return opsy::utility::clear_set<adc_sqr2_r>(adc_sqr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 7th conversion in regular sequence 
 */
class sq7_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq7_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr2_r>() const {return opsy::utility::clear_set<adc_sqr2_r>(mask, *this);}
	constexpr auto operator|(adc_sqr2_r other) const -> adc_sqr2_r { return static_cast<adc_sqr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr2_r> other) const -> opsy::utility::clear_set<adc_sqr2_r> {return opsy::utility::clear_set<adc_sqr2_r>(adc_sqr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8th conversion in regular sequence 
 */
class sq8_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq8_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr2_r>() const {return opsy::utility::clear_set<adc_sqr2_r>(mask, *this);}
	constexpr auto operator|(adc_sqr2_r other) const -> adc_sqr2_r { return static_cast<adc_sqr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr2_r> other) const -> opsy::utility::clear_set<adc_sqr2_r> {return opsy::utility::clear_set<adc_sqr2_r>(adc_sqr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 9th conversion in regular sequence 
 */
class sq9_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq9_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr2_r>() const {return opsy::utility::clear_set<adc_sqr2_r>(mask, *this);}
	constexpr auto operator|(adc_sqr2_r other) const -> adc_sqr2_r { return static_cast<adc_sqr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr2_r> other) const -> opsy::utility::clear_set<adc_sqr2_r> {return opsy::utility::clear_set<adc_sqr2_r>(adc_sqr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sq5() const -> sq5_f {return sq5_f(static_cast<uint8_t>(value_ >> sq5_f::offset));}
	[[nodiscard]] constexpr auto sq6() const -> sq6_f {return sq6_f(static_cast<uint8_t>(value_ >> sq6_f::offset));}
	[[nodiscard]] constexpr auto sq7() const -> sq7_f {return sq7_f(static_cast<uint8_t>(value_ >> sq7_f::offset));}
	[[nodiscard]] constexpr auto sq8() const -> sq8_f {return sq8_f(static_cast<uint8_t>(value_ >> sq8_f::offset));}
	[[nodiscard]] constexpr auto sq9() const -> sq9_f {return sq9_f(static_cast<uint8_t>(value_ >> sq9_f::offset));}

	constexpr adc_sqr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_sqr2_r other) const -> adc_sqr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_sqr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC regular sequence register 3
 */
class adc_sqr3_r {
public:

/**
 * 10th conversion in regular sequence 
 */
class sq10_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sq10_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr3_r>() const {return opsy::utility::clear_set<adc_sqr3_r>(mask, *this);}
	constexpr auto operator|(adc_sqr3_r other) const -> adc_sqr3_r { return static_cast<adc_sqr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr3_r> other) const -> opsy::utility::clear_set<adc_sqr3_r> {return opsy::utility::clear_set<adc_sqr3_r>(adc_sqr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 11th conversion in regular sequence 
 */
class sq11_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sq11_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr3_r>() const {return opsy::utility::clear_set<adc_sqr3_r>(mask, *this);}
	constexpr auto operator|(adc_sqr3_r other) const -> adc_sqr3_r { return static_cast<adc_sqr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr3_r> other) const -> opsy::utility::clear_set<adc_sqr3_r> {return opsy::utility::clear_set<adc_sqr3_r>(adc_sqr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 12th conversion in regular sequence 
 */
class sq12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq12_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr3_r>() const {return opsy::utility::clear_set<adc_sqr3_r>(mask, *this);}
	constexpr auto operator|(adc_sqr3_r other) const -> adc_sqr3_r { return static_cast<adc_sqr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr3_r> other) const -> opsy::utility::clear_set<adc_sqr3_r> {return opsy::utility::clear_set<adc_sqr3_r>(adc_sqr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 13th conversion in regular sequence 
 */
class sq13_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq13_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr3_r>() const {return opsy::utility::clear_set<adc_sqr3_r>(mask, *this);}
	constexpr auto operator|(adc_sqr3_r other) const -> adc_sqr3_r { return static_cast<adc_sqr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr3_r> other) const -> opsy::utility::clear_set<adc_sqr3_r> {return opsy::utility::clear_set<adc_sqr3_r>(adc_sqr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 14th conversion in regular sequence 
 */
class sq14_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sq14_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr3_r>() const {return opsy::utility::clear_set<adc_sqr3_r>(mask, *this);}
	constexpr auto operator|(adc_sqr3_r other) const -> adc_sqr3_r { return static_cast<adc_sqr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr3_r> other) const -> opsy::utility::clear_set<adc_sqr3_r> {return opsy::utility::clear_set<adc_sqr3_r>(adc_sqr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sq10() const -> sq10_f {return sq10_f(static_cast<uint8_t>(value_ >> sq10_f::offset));}
	[[nodiscard]] constexpr auto sq11() const -> sq11_f {return sq11_f(static_cast<uint8_t>(value_ >> sq11_f::offset));}
	[[nodiscard]] constexpr auto sq12() const -> sq12_f {return sq12_f(static_cast<uint8_t>(value_ >> sq12_f::offset));}
	[[nodiscard]] constexpr auto sq13() const -> sq13_f {return sq13_f(static_cast<uint8_t>(value_ >> sq13_f::offset));}
	[[nodiscard]] constexpr auto sq14() const -> sq14_f {return sq14_f(static_cast<uint8_t>(value_ >> sq14_f::offset));}

	constexpr adc_sqr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_sqr3_r other) const -> adc_sqr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_sqr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC regular sequence register 4
 */
class adc_sqr4_r {
public:

/**
 * 15th conversion in regular sequence 
 */
class sq15_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sq15_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr4_r>() const {return opsy::utility::clear_set<adc_sqr4_r>(mask, *this);}
	constexpr auto operator|(adc_sqr4_r other) const -> adc_sqr4_r { return static_cast<adc_sqr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr4_r> other) const -> opsy::utility::clear_set<adc_sqr4_r> {return opsy::utility::clear_set<adc_sqr4_r>(adc_sqr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 16th conversion in regular sequence 
 */
class sq16_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sq16_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_sqr4_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sqr4_r>() const {return opsy::utility::clear_set<adc_sqr4_r>(mask, *this);}
	constexpr auto operator|(adc_sqr4_r other) const -> adc_sqr4_r { return static_cast<adc_sqr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sqr4_r> other) const -> opsy::utility::clear_set<adc_sqr4_r> {return opsy::utility::clear_set<adc_sqr4_r>(adc_sqr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sq15() const -> sq15_f {return sq15_f(static_cast<uint8_t>(value_ >> sq15_f::offset));}
	[[nodiscard]] constexpr auto sq16() const -> sq16_f {return sq16_f(static_cast<uint8_t>(value_ >> sq16_f::offset));}

	constexpr adc_sqr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_sqr4_r other) const -> adc_sqr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_sqr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC regular data register
 */
class adc_dr_r {
public:

/**
 * Regular data converted 
 */
class rdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdata_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_dr_r>() const {return opsy::utility::clear_set<adc_dr_r>(mask, *this);}
	constexpr auto operator|(adc_dr_r other) const -> adc_dr_r { return static_cast<adc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_dr_r> other) const -> opsy::utility::clear_set<adc_dr_r> {return opsy::utility::clear_set<adc_dr_r>(adc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdata() const -> rdata_f {return rdata_f(static_cast<uint16_t>(value_ >> rdata_f::offset));}

	constexpr adc_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_dr_r other) const -> adc_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC injected sequence register
 */
class adc_jsqr_r {
public:

/**
 * Injected channel sequence length 
 */
class jl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr jl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External Trigger Selection for injected group 
 */
class jextsel_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr jextsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External trigger enable and polarity selection for injected channels 
 */
class jexten_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr jexten_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 1st conversion in the injected sequence 
 */
class jsq1_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr jsq1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 2nd conversion in the injected sequence 
 */
class jsq2_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr jsq2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 3rd conversion in the injected sequence 
 */
class jsq3_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr jsq3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 4th conversion in the injected sequence 
 */
class jsq4_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr jsq4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_jsqr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jsqr_r>() const {return opsy::utility::clear_set<adc_jsqr_r>(mask, *this);}
	constexpr auto operator|(adc_jsqr_r other) const -> adc_jsqr_r { return static_cast<adc_jsqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jsqr_r> other) const -> opsy::utility::clear_set<adc_jsqr_r> {return opsy::utility::clear_set<adc_jsqr_r>(adc_jsqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto jl() const -> jl_f {return jl_f(static_cast<uint8_t>(value_ >> jl_f::offset));}
	[[nodiscard]] constexpr auto jextsel() const -> jextsel_f {return jextsel_f(static_cast<uint8_t>(value_ >> jextsel_f::offset));}
	[[nodiscard]] constexpr auto jexten() const -> jexten_f {return jexten_f(static_cast<uint8_t>(value_ >> jexten_f::offset));}
	[[nodiscard]] constexpr auto jsq1() const -> jsq1_f {return jsq1_f(static_cast<uint8_t>(value_ >> jsq1_f::offset));}
	[[nodiscard]] constexpr auto jsq2() const -> jsq2_f {return jsq2_f(static_cast<uint8_t>(value_ >> jsq2_f::offset));}
	[[nodiscard]] constexpr auto jsq3() const -> jsq3_f {return jsq3_f(static_cast<uint8_t>(value_ >> jsq3_f::offset));}
	[[nodiscard]] constexpr auto jsq4() const -> jsq4_f {return jsq4_f(static_cast<uint8_t>(value_ >> jsq4_f::offset));}

	constexpr adc_jsqr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_jsqr_r other) const -> adc_jsqr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_jsqr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC offset X register
 */
class adc_ofrx_r {
public:

/**
 * Data offset y for the channel programmed into bits OFFSET_CH[4:0] 
 */
class offset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr offset_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_ofrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ofrx_r>() const {return opsy::utility::clear_set<adc_ofrx_r>(mask, *this);}
	constexpr auto operator|(adc_ofrx_r other) const -> adc_ofrx_r { return static_cast<adc_ofrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ofrx_r> other) const -> opsy::utility::clear_set<adc_ofrx_r> {return opsy::utility::clear_set<adc_ofrx_r>(adc_ofrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Positive offset 
 */
class offsetpos_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr offsetpos_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ofrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ofrx_r>() const {return opsy::utility::clear_set<adc_ofrx_r>(mask, *this);}
	constexpr auto operator|(adc_ofrx_r other) const -> adc_ofrx_r { return static_cast<adc_ofrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ofrx_r> other) const -> opsy::utility::clear_set<adc_ofrx_r> {return opsy::utility::clear_set<adc_ofrx_r>(adc_ofrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Saturation enable 
 */
class saten_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr saten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ofrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ofrx_r>() const {return opsy::utility::clear_set<adc_ofrx_r>(mask, *this);}
	constexpr auto operator|(adc_ofrx_r other) const -> adc_ofrx_r { return static_cast<adc_ofrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ofrx_r> other) const -> opsy::utility::clear_set<adc_ofrx_r> {return opsy::utility::clear_set<adc_ofrx_r>(adc_ofrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Channel selection for the data offset y 
 */
class offset_ch_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr offset_ch_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ofrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ofrx_r>() const {return opsy::utility::clear_set<adc_ofrx_r>(mask, *this);}
	constexpr auto operator|(adc_ofrx_r other) const -> adc_ofrx_r { return static_cast<adc_ofrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ofrx_r> other) const -> opsy::utility::clear_set<adc_ofrx_r> {return opsy::utility::clear_set<adc_ofrx_r>(adc_ofrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Offset y enable 
 */
class offset_en_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr offset_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ofrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ofrx_r>() const {return opsy::utility::clear_set<adc_ofrx_r>(mask, *this);}
	constexpr auto operator|(adc_ofrx_r other) const -> adc_ofrx_r { return static_cast<adc_ofrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ofrx_r> other) const -> opsy::utility::clear_set<adc_ofrx_r> {return opsy::utility::clear_set<adc_ofrx_r>(adc_ofrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto offset() const -> offset_f {return offset_f(static_cast<uint16_t>(value_ >> offset_f::offset));}
	[[nodiscard]] constexpr auto offsetpos() const -> offsetpos_f {return offsetpos_f((value_ & offsetpos_f::mask) != 0);}
	[[nodiscard]] constexpr auto saten() const -> saten_f {return saten_f((value_ & saten_f::mask) != 0);}
	[[nodiscard]] constexpr auto offset_ch() const -> offset_ch_f {return offset_ch_f(static_cast<uint8_t>(value_ >> offset_ch_f::offset));}
	[[nodiscard]] constexpr auto offset_en() const -> offset_en_f {return offset_en_f((value_ & offset_en_f::mask) != 0);}

	constexpr adc_ofrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_ofrx_r other) const -> adc_ofrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_ofrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC injected channel X data register
 */
class adc_jdrx_r {
public:

/**
 * Injected data 
 */
class jdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr jdata_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_jdrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_jdrx_r>() const {return opsy::utility::clear_set<adc_jdrx_r>(mask, *this);}
	constexpr auto operator|(adc_jdrx_r other) const -> adc_jdrx_r { return static_cast<adc_jdrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_jdrx_r> other) const -> opsy::utility::clear_set<adc_jdrx_r> {return opsy::utility::clear_set<adc_jdrx_r>(adc_jdrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto jdata() const -> jdata_f {return jdata_f(static_cast<uint16_t>(value_ >> jdata_f::offset));}

	constexpr adc_jdrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_jdrx_r other) const -> adc_jdrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_jdrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC analog watchdog 2 configuration register
 */
class adc_awd2cr_r {
public:

/**
 * Analog watchdog 2 channel selection 
 */
class awd2ch_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr awd2ch_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator adc_awd2cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_awd2cr_r>() const {return opsy::utility::clear_set<adc_awd2cr_r>(mask, *this);}
	constexpr auto operator|(adc_awd2cr_r other) const -> adc_awd2cr_r { return static_cast<adc_awd2cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_awd2cr_r> other) const -> opsy::utility::clear_set<adc_awd2cr_r> {return opsy::utility::clear_set<adc_awd2cr_r>(adc_awd2cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto awd2ch() const -> awd2ch_f {return awd2ch_f(static_cast<uint32_t>(value_ >> awd2ch_f::offset));}

	constexpr adc_awd2cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_awd2cr_r other) const -> adc_awd2cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_awd2cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC analog watchdog 3 configuration register
 */
class adc_awd3cr_r {
public:

/**
 * Analog watchdog 3 channel selection 
 */
class awd3ch_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr awd3ch_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator adc_awd3cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_awd3cr_r>() const {return opsy::utility::clear_set<adc_awd3cr_r>(mask, *this);}
	constexpr auto operator|(adc_awd3cr_r other) const -> adc_awd3cr_r { return static_cast<adc_awd3cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_awd3cr_r> other) const -> opsy::utility::clear_set<adc_awd3cr_r> {return opsy::utility::clear_set<adc_awd3cr_r>(adc_awd3cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto awd3ch() const -> awd3ch_f {return awd3ch_f(static_cast<uint32_t>(value_ >> awd3ch_f::offset));}

	constexpr adc_awd3cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_awd3cr_r other) const -> adc_awd3cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_awd3cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC Differential mode selection register
 */
class adc_difsel_r {
public:

/**
 * Differential mode for channels 19 to 0.
 */
class difsel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr difsel_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator adc_difsel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_difsel_r>() const {return opsy::utility::clear_set<adc_difsel_r>(mask, *this);}
	constexpr auto operator|(adc_difsel_r other) const -> adc_difsel_r { return static_cast<adc_difsel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_difsel_r> other) const -> opsy::utility::clear_set<adc_difsel_r> {return opsy::utility::clear_set<adc_difsel_r>(adc_difsel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto difsel() const -> difsel_f {return difsel_f(static_cast<uint32_t>(value_ >> difsel_f::offset));}

	constexpr adc_difsel_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_difsel_r other) const -> adc_difsel_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_difsel_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC calibration factors
 */
class adc_calfact_r {
public:

/**
 * Calibration Factors In single-ended mode 
 */
class calfact_s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr calfact_s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_calfact_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_calfact_r>() const {return opsy::utility::clear_set<adc_calfact_r>(mask, *this);}
	constexpr auto operator|(adc_calfact_r other) const -> adc_calfact_r { return static_cast<adc_calfact_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_calfact_r> other) const -> opsy::utility::clear_set<adc_calfact_r> {return opsy::utility::clear_set<adc_calfact_r>(adc_calfact_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Calibration Factors in differential mode 
 */
class calfact_d_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr calfact_d_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_calfact_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_calfact_r>() const {return opsy::utility::clear_set<adc_calfact_r>(mask, *this);}
	constexpr auto operator|(adc_calfact_r other) const -> adc_calfact_r { return static_cast<adc_calfact_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_calfact_r> other) const -> opsy::utility::clear_set<adc_calfact_r> {return opsy::utility::clear_set<adc_calfact_r>(adc_calfact_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto calfact_s() const -> calfact_s_f {return calfact_s_f(static_cast<uint8_t>(value_ >> calfact_s_f::offset));}
	[[nodiscard]] constexpr auto calfact_d() const -> calfact_d_f {return calfact_d_f(static_cast<uint8_t>(value_ >> calfact_d_f::offset));}

	constexpr adc_calfact_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_calfact_r other) const -> adc_calfact_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_calfact_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC option register
 */
class adc_or_r {
public:

/**
 * Option bit 0 
 */
class op0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr op0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_or_r>() const {return opsy::utility::clear_set<adc_or_r>(mask, *this);}
	constexpr auto operator|(adc_or_r other) const -> adc_or_r { return static_cast<adc_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_or_r> other) const -> opsy::utility::clear_set<adc_or_r> {return opsy::utility::clear_set<adc_or_r>(adc_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto op0() const -> op0_f {return op0_f((value_ & op0_f::mask) != 0);}

	constexpr adc_or_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_or_r other) const -> adc_or_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_or_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,adc_isr_r> adc_isr;
	opsy::utility::memory<uint32_t,adc_ier_r> adc_ier;
	opsy::utility::memory<uint32_t,adc_cr_r> adc_cr;
	opsy::utility::memory<uint32_t,adc_cfgr_r> adc_cfgr;
	opsy::utility::memory<uint32_t,adc_cfgr2_r> adc_cfgr2;
	opsy::utility::memory<uint32_t,adc_smpr1_r> adc_smpr1;
	opsy::utility::memory<uint32_t,adc_smpr2_r> adc_smpr2;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,adc_tr1_r> adc_tr1;
	opsy::utility::memory<uint32_t,adc_tr2_r> adc_tr2;
	opsy::utility::memory<uint32_t,adc_tr3_r> adc_tr3;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,adc_sqr1_r> adc_sqr1;
	opsy::utility::memory<uint32_t,adc_sqr2_r> adc_sqr2;
	opsy::utility::memory<uint32_t,adc_sqr3_r> adc_sqr3;
	opsy::utility::memory<uint32_t,adc_sqr4_r> adc_sqr4;
	opsy::utility::read_only_memory<uint32_t,adc_dr_r> adc_dr;
	opsy::utility::padding<8> _p2;
	opsy::utility::memory<uint32_t,adc_jsqr_r> adc_jsqr;
	opsy::utility::padding<16> _p3;
	opsy::utility::memory<uint32_t,adc_ofrx_r> adc_ofr1;
	opsy::utility::memory<uint32_t,adc_ofrx_r> adc_ofr2;
	opsy::utility::memory<uint32_t,adc_ofrx_r> adc_ofr3;
	opsy::utility::memory<uint32_t,adc_ofrx_r> adc_ofr4;
	opsy::utility::padding<16> _p4;
	opsy::utility::read_only_memory<uint32_t,adc_jdrx_r> adc_jdr1;
	opsy::utility::read_only_memory<uint32_t,adc_jdrx_r> adc_jdr2;
	opsy::utility::read_only_memory<uint32_t,adc_jdrx_r> adc_jdr3;
	opsy::utility::read_only_memory<uint32_t,adc_jdrx_r> adc_jdr4;
	opsy::utility::padding<16> _p5;
	opsy::utility::memory<uint32_t,adc_awd2cr_r> adc_awd2cr;
	opsy::utility::memory<uint32_t,adc_awd3cr_r> adc_awd3cr;
	opsy::utility::padding<8> _p6;
	opsy::utility::memory<uint32_t,adc_difsel_r> adc_difsel;
	opsy::utility::memory<uint32_t,adc_calfact_r> adc_calfact;
	opsy::utility::padding<16> _p7;
	opsy::utility::memory<uint32_t,adc_or_r> adc_or;
};

static_assert(std::is_standard_layout_v<adc1_p>);
static_assert(offsetof(adc1_p, adc_isr) == 0);
static_assert(offsetof(adc1_p, adc_ier) == 4);
static_assert(offsetof(adc1_p, adc_cr) == 8);
static_assert(offsetof(adc1_p, adc_cfgr) == 12);
static_assert(offsetof(adc1_p, adc_cfgr2) == 16);
static_assert(offsetof(adc1_p, adc_smpr1) == 20);
static_assert(offsetof(adc1_p, adc_smpr2) == 24);
static_assert(offsetof(adc1_p, adc_tr1) == 32);
static_assert(offsetof(adc1_p, adc_tr2) == 36);
static_assert(offsetof(adc1_p, adc_tr3) == 40);
static_assert(offsetof(adc1_p, adc_sqr1) == 48);
static_assert(offsetof(adc1_p, adc_sqr2) == 52);
static_assert(offsetof(adc1_p, adc_sqr3) == 56);
static_assert(offsetof(adc1_p, adc_sqr4) == 60);
static_assert(offsetof(adc1_p, adc_dr) == 64);
static_assert(offsetof(adc1_p, adc_jsqr) == 76);
static_assert(offsetof(adc1_p, adc_ofr1) == 96);
static_assert(offsetof(adc1_p, adc_ofr2) == 100);
static_assert(offsetof(adc1_p, adc_ofr3) == 104);
static_assert(offsetof(adc1_p, adc_ofr4) == 108);
static_assert(offsetof(adc1_p, adc_jdr1) == 128);
static_assert(offsetof(adc1_p, adc_jdr2) == 132);
static_assert(offsetof(adc1_p, adc_jdr3) == 136);
static_assert(offsetof(adc1_p, adc_jdr4) == 140);
static_assert(offsetof(adc1_p, adc_awd2cr) == 160);
static_assert(offsetof(adc1_p, adc_awd3cr) == 164);
static_assert(offsetof(adc1_p, adc_difsel) == 176);
static_assert(offsetof(adc1_p, adc_calfact) == 180);
static_assert(offsetof(adc1_p, adc_or) == 200);

/**
 * ADC common registers block
 */
class adcc_p {
public:

/**
 * ADC common status register
 */
class adc_csr_r {
public:

/**
 * Master ADC ready 
 */
class adrdy_mst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr adrdy_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of Sampling phase flag of the master ADC 
 */
class eosmp_mst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eosmp_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular conversion of the master ADC 
 */
class eoc_mst_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eoc_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular sequence flag of the master ADC 
 */
class eos_mst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eos_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun flag of the master ADC 
 */
class ovr_mst_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected conversion flag of the master ADC 
 */
class jeoc_mst_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeoc_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected sequence flag of the master ADC 
 */
class jeos_mst_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jeos_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 flag of the master ADC 
 */
class awd1_mst_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr awd1_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 2 flag of the master ADC 
 */
class awd2_mst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd2_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 3 flag of the master ADC 
 */
class awd3_mst_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr awd3_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected Context Queue Overflow flag of the master ADC 
 */
class jqovf_mst_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr jqovf_mst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Slave ADC ready 
 */
class adrdy_slv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr adrdy_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of Sampling phase flag of the slave ADC 
 */
class eosmp_slv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eosmp_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular conversion of the slave ADC 
 */
class eoc_slv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eoc_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of regular sequence flag of the slave ADC.
 */
class eos_slv_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eos_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun flag of the slave ADC 
 */
class ovr_slv_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ovr_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected conversion flag of the slave ADC 
 */
class jeoc_slv_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jeoc_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of injected sequence flag of the slave ADC 
 */
class jeos_slv_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jeos_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 1 flag of the slave ADC 
 */
class awd1_slv_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr awd1_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 2 flag of the slave ADC 
 */
class awd2_slv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr awd2_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog watchdog 3 flag of the slave ADC 
 */
class awd3_slv_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr awd3_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Injected Context Queue Overflow flag of the slave ADC 
 */
class jqovf_slv_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jqovf_slv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_csr_r>() const {return opsy::utility::clear_set<adc_csr_r>(mask, *this);}
	constexpr auto operator|(adc_csr_r other) const -> adc_csr_r { return static_cast<adc_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_csr_r> other) const -> opsy::utility::clear_set<adc_csr_r> {return opsy::utility::clear_set<adc_csr_r>(adc_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto adrdy_mst() const -> adrdy_mst_f {return adrdy_mst_f((value_ & adrdy_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto eosmp_mst() const -> eosmp_mst_f {return eosmp_mst_f((value_ & eosmp_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto eoc_mst() const -> eoc_mst_f {return eoc_mst_f((value_ & eoc_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto eos_mst() const -> eos_mst_f {return eos_mst_f((value_ & eos_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_mst() const -> ovr_mst_f {return ovr_mst_f((value_ & ovr_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeoc_mst() const -> jeoc_mst_f {return jeoc_mst_f((value_ & jeoc_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeos_mst() const -> jeos_mst_f {return jeos_mst_f((value_ & jeos_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1_mst() const -> awd1_mst_f {return awd1_mst_f((value_ & awd1_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd2_mst() const -> awd2_mst_f {return awd2_mst_f((value_ & awd2_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd3_mst() const -> awd3_mst_f {return awd3_mst_f((value_ & awd3_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto jqovf_mst() const -> jqovf_mst_f {return jqovf_mst_f((value_ & jqovf_mst_f::mask) != 0);}
	[[nodiscard]] constexpr auto adrdy_slv() const -> adrdy_slv_f {return adrdy_slv_f((value_ & adrdy_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto eosmp_slv() const -> eosmp_slv_f {return eosmp_slv_f((value_ & eosmp_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto eoc_slv() const -> eoc_slv_f {return eoc_slv_f((value_ & eoc_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto eos_slv() const -> eos_slv_f {return eos_slv_f((value_ & eos_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_slv() const -> ovr_slv_f {return ovr_slv_f((value_ & ovr_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeoc_slv() const -> jeoc_slv_f {return jeoc_slv_f((value_ & jeoc_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto jeos_slv() const -> jeos_slv_f {return jeos_slv_f((value_ & jeos_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd1_slv() const -> awd1_slv_f {return awd1_slv_f((value_ & awd1_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd2_slv() const -> awd2_slv_f {return awd2_slv_f((value_ & awd2_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto awd3_slv() const -> awd3_slv_f {return awd3_slv_f((value_ & awd3_slv_f::mask) != 0);}
	[[nodiscard]] constexpr auto jqovf_slv() const -> jqovf_slv_f {return jqovf_slv_f((value_ & jqovf_slv_f::mask) != 0);}

	constexpr adc_csr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_csr_r other) const -> adc_csr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_csr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC common control register
 */
class adc_ccr_r {
public:

/**
 * Dual ADC mode selection 
 */
class dual_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dual_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay between 2 sampling phases 
 */
class delay_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr delay_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA configuration (for dual ADC mode) 
 */
class dmacfg_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmacfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direct memory access mode for dual ADC mode 
 */
class mdma_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mdma_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ADC clock mode 
 */
class ckmode_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ckmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ADC prescaler 
 */
class presc_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr presc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Vless thansub>REFINTless than/sub> enable 
 */
class vrefen_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vrefen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>SENSEless than/sub> enable 
 */
class tsen_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VBAT enable 
 */
class vbaten_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vbaten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator adc_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<adc_ccr_r>() const {return opsy::utility::clear_set<adc_ccr_r>(mask, *this);}
	constexpr auto operator|(adc_ccr_r other) const -> adc_ccr_r { return static_cast<adc_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ccr_r> other) const -> opsy::utility::clear_set<adc_ccr_r> {return opsy::utility::clear_set<adc_ccr_r>(adc_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dual() const -> dual_f {return dual_f(static_cast<uint8_t>(value_ >> dual_f::offset));}
	[[nodiscard]] constexpr auto delay() const -> delay_f {return delay_f(static_cast<uint8_t>(value_ >> delay_f::offset));}
	[[nodiscard]] constexpr auto dmacfg() const -> dmacfg_f {return dmacfg_f((value_ & dmacfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto mdma() const -> mdma_f {return mdma_f(static_cast<uint8_t>(value_ >> mdma_f::offset));}
	[[nodiscard]] constexpr auto ckmode() const -> ckmode_f {return ckmode_f(static_cast<uint8_t>(value_ >> ckmode_f::offset));}
	[[nodiscard]] constexpr auto presc() const -> presc_f {return presc_f(static_cast<uint8_t>(value_ >> presc_f::offset));}
	[[nodiscard]] constexpr auto vrefen() const -> vrefen_f {return vrefen_f((value_ & vrefen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsen() const -> tsen_f {return tsen_f((value_ & tsen_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbaten() const -> vbaten_f {return vbaten_f((value_ & vbaten_f::mask) != 0);}

	constexpr adc_ccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_ccr_r other) const -> adc_ccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_ccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC common regular data register for dual mode
 */
class adc_cdr_r {
public:

/**
 * Regular data of the master ADC.
 */
class rdata_mst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdata_mst_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_cdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cdr_r>() const {return opsy::utility::clear_set<adc_cdr_r>(mask, *this);}
	constexpr auto operator|(adc_cdr_r other) const -> adc_cdr_r { return static_cast<adc_cdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cdr_r> other) const -> opsy::utility::clear_set<adc_cdr_r> {return opsy::utility::clear_set<adc_cdr_r>(adc_cdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Regular data of the slave ADC 
 */
class rdata_slv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdata_slv_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator adc_cdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_cdr_r>() const {return opsy::utility::clear_set<adc_cdr_r>(mask, *this);}
	constexpr auto operator|(adc_cdr_r other) const -> adc_cdr_r { return static_cast<adc_cdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_cdr_r> other) const -> opsy::utility::clear_set<adc_cdr_r> {return opsy::utility::clear_set<adc_cdr_r>(adc_cdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdata_mst() const -> rdata_mst_f {return rdata_mst_f(static_cast<uint16_t>(value_ >> rdata_mst_f::offset));}
	[[nodiscard]] constexpr auto rdata_slv() const -> rdata_slv_f {return rdata_slv_f(static_cast<uint16_t>(value_ >> rdata_slv_f::offset));}

	constexpr adc_cdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_cdr_r other) const -> adc_cdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_cdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ADC hardware configuration register
 */
class adc_hwcfgr0_r {
public:

/**
 * Number of ADCs implemented
 */
class adcnum_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr adcnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_hwcfgr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_hwcfgr0_r>() const {return opsy::utility::clear_set<adc_hwcfgr0_r>(mask, *this);}
	constexpr auto operator|(adc_hwcfgr0_r other) const -> adc_hwcfgr0_r { return static_cast<adc_hwcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_hwcfgr0_r> other) const -> opsy::utility::clear_set<adc_hwcfgr0_r> {return opsy::utility::clear_set<adc_hwcfgr0_r>(adc_hwcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of pipeline stages
 */
class mulpipe_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mulpipe_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_hwcfgr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_hwcfgr0_r>() const {return opsy::utility::clear_set<adc_hwcfgr0_r>(mask, *this);}
	constexpr auto operator|(adc_hwcfgr0_r other) const -> adc_hwcfgr0_r { return static_cast<adc_hwcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_hwcfgr0_r> other) const -> opsy::utility::clear_set<adc_hwcfgr0_r> {return opsy::utility::clear_set<adc_hwcfgr0_r>(adc_hwcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of option bits
 */
class opbits_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr opbits_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_hwcfgr0_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_hwcfgr0_r>() const {return opsy::utility::clear_set<adc_hwcfgr0_r>(mask, *this);}
	constexpr auto operator|(adc_hwcfgr0_r other) const -> adc_hwcfgr0_r { return static_cast<adc_hwcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_hwcfgr0_r> other) const -> opsy::utility::clear_set<adc_hwcfgr0_r> {return opsy::utility::clear_set<adc_hwcfgr0_r>(adc_hwcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Idle value for non-selected channels
 */
class idlevalue_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr idlevalue_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_hwcfgr0_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_hwcfgr0_r>() const {return opsy::utility::clear_set<adc_hwcfgr0_r>(mask, *this);}
	constexpr auto operator|(adc_hwcfgr0_r other) const -> adc_hwcfgr0_r { return static_cast<adc_hwcfgr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_hwcfgr0_r> other) const -> opsy::utility::clear_set<adc_hwcfgr0_r> {return opsy::utility::clear_set<adc_hwcfgr0_r>(adc_hwcfgr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto adcnum() const -> adcnum_f {return adcnum_f(static_cast<uint8_t>(value_ >> adcnum_f::offset));}
	[[nodiscard]] constexpr auto mulpipe() const -> mulpipe_f {return mulpipe_f(static_cast<uint8_t>(value_ >> mulpipe_f::offset));}
	[[nodiscard]] constexpr auto opbits() const -> opbits_f {return opbits_f(static_cast<uint8_t>(value_ >> opbits_f::offset));}
	[[nodiscard]] constexpr auto idlevalue() const -> idlevalue_f {return idlevalue_f(static_cast<uint8_t>(value_ >> idlevalue_f::offset));}

	constexpr adc_hwcfgr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_hwcfgr0_r other) const -> adc_hwcfgr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_hwcfgr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1001000010010; // 4626 0x1212

private:
	uint32_t value_;
};

/**
 * ADC version register
 */
class adc_verr_r {
public:

/**
 * Minor revision 
 */
class minrev_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr minrev_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_verr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_verr_r>() const {return opsy::utility::clear_set<adc_verr_r>(mask, *this);}
	constexpr auto operator|(adc_verr_r other) const -> adc_verr_r { return static_cast<adc_verr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_verr_r> other) const -> opsy::utility::clear_set<adc_verr_r> {return opsy::utility::clear_set<adc_verr_r>(adc_verr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Major revision 
 */
class majrev_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr majrev_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator adc_verr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_verr_r>() const {return opsy::utility::clear_set<adc_verr_r>(mask, *this);}
	constexpr auto operator|(adc_verr_r other) const -> adc_verr_r { return static_cast<adc_verr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_verr_r> other) const -> opsy::utility::clear_set<adc_verr_r> {return opsy::utility::clear_set<adc_verr_r>(adc_verr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto minrev() const -> minrev_f {return minrev_f(static_cast<uint8_t>(value_ >> minrev_f::offset));}
	[[nodiscard]] constexpr auto majrev() const -> majrev_f {return majrev_f(static_cast<uint8_t>(value_ >> majrev_f::offset));}

	constexpr adc_verr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_verr_r other) const -> adc_verr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_verr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10010; // 18 0x12

private:
	uint32_t value_;
};

/**
 * ADC identification register
 */
class adc_ipdr_r {
public:

/**
 * Peripheral identifier 
 */
class id_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr id_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator adc_ipdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_ipdr_r>() const {return opsy::utility::clear_set<adc_ipdr_r>(mask, *this);}
	constexpr auto operator|(adc_ipdr_r other) const -> adc_ipdr_r { return static_cast<adc_ipdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_ipdr_r> other) const -> opsy::utility::clear_set<adc_ipdr_r> {return opsy::utility::clear_set<adc_ipdr_r>(adc_ipdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto id() const -> id_f {return id_f(static_cast<uint32_t>(value_ >> id_f::offset));}

	constexpr adc_ipdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_ipdr_r other) const -> adc_ipdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_ipdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100010000000000000110; // 1114118 0x110006

private:
	uint32_t value_;
};

/**
 * ADC size identification register
 */
class adc_sidr_r {
public:

/**
 * Size Identification 
 */
class sid_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sid_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator adc_sidr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<adc_sidr_r>() const {return opsy::utility::clear_set<adc_sidr_r>(mask, *this);}
	constexpr auto operator|(adc_sidr_r other) const -> adc_sidr_r { return static_cast<adc_sidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<adc_sidr_r> other) const -> opsy::utility::clear_set<adc_sidr_r> {return opsy::utility::clear_set<adc_sidr_r>(adc_sidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto sid() const -> sid_f {return sid_f(static_cast<uint32_t>(value_ >> sid_f::offset));}

	constexpr adc_sidr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(adc_sidr_r other) const -> adc_sidr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> adc_sidr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10100011110001011101110100000001; // 2747653377 0xA3C5DD01

private:
	uint32_t value_;
};

	opsy::utility::read_only_memory<uint32_t,adc_csr_r> adc_csr;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,adc_ccr_r> adc_ccr;
	opsy::utility::read_only_memory<uint32_t,adc_cdr_r> adc_cdr;
	opsy::utility::padding<224> _p1;
	opsy::utility::read_only_memory<uint32_t,adc_hwcfgr0_r> adc_hwcfgr0;
	opsy::utility::read_only_memory<uint32_t,adc_verr_r> adc_verr;
	opsy::utility::read_only_memory<uint32_t,adc_ipdr_r> adc_ipdr;
	opsy::utility::read_only_memory<uint32_t,adc_sidr_r> adc_sidr;
};

static_assert(std::is_standard_layout_v<adcc_p>);
static_assert(offsetof(adcc_p, adc_csr) == 0);
static_assert(offsetof(adcc_p, adc_ccr) == 8);
static_assert(offsetof(adcc_p, adc_cdr) == 12);
static_assert(offsetof(adcc_p, adc_hwcfgr0) == 240);
static_assert(offsetof(adcc_p, adc_verr) == 244);
static_assert(offsetof(adcc_p, adc_ipdr) == 248);
static_assert(offsetof(adcc_p, adc_sidr) == 252);

inline adc1_p& adc1 = *reinterpret_cast<adc1_p*>(0x42028000);
inline adc1_p& adc2 = *reinterpret_cast<adc1_p*>(0x42028100);
inline adc1_p& sec_adc1 = *reinterpret_cast<adc1_p*>(0x52028000);
inline adc1_p& sec_adc2 = *reinterpret_cast<adc1_p*>(0x52028100);
inline adcc_p& adcc = *reinterpret_cast<adcc_p*>(0x42028300);
inline adcc_p& sec_adcc = *reinterpret_cast<adcc_p*>(0x52028300);

} // STM32H563

