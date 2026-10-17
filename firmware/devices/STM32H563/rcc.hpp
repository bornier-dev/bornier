#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Reset and clock controller
 */
class rcc_p {
public:

/**
 * RCC clock control register 
 */
class rcc_cr_r {
public:

/**
 * HSI clock enable Set and cleared by software. Set by hardware to force the HSI to ON when the product leaves Stop mode, if STOPWUCK = 1 or STOPKERWUCK = 1. Set by hardware to force the HSI to ON when the product leaves Standby mode or in case of a failure of the HSE which is used as the system clock source. This bit cannot be cleared if the HSI is used directly (via SW mux) as system clock, or if the HSI is selected as reference clock for PLL1 with PLL1 enabled (PLL1ON bit set to 1).
 */
class hsion_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsion_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI clock ready flag Set by hardware to indicate that the HSI oscillator is stable.
 */
class hsirdy_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsirdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI clock enable in Stop mode Set and reset by software to force the HSI to ON, even in Stop mode, in order to be quickly available as kernel clock for peripherals. This bit has no effect on the value of HSION.
 */
class hsikeron_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsikeron_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI clock divider Set and reset by software. These bits allow selecting a division ratio in order to configure the wanted HSI clock frequency. The HSIDIV cannot be changed if the HSI is selected as reference clock for at least one enabled PLL (PLLxON bit set to 1). In that case, the new HSIDIV value is ignored.
 */
class hsidiv_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hsidiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HSI divider flag Set and reset by hardware. As a write operation to HSIDIV has not an immediate effect on the frequency, this flag indicates the current status of the HSI divider. HSIDIVF goes immediately to 0 when HSIDIV value is changed, and is set back to 1 when the output frequency matches the value programmed into HSIDIV.
 */
class hsidivf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsidivf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI clock enable Set and reset by software to enable/disable CSI clock for system and/or peripheral. Set by hardware to force the CSI to ON when the system leaves Stop mode, if STOPWUCK = 1 or STOPKERWUCK = 1. This bit cannot be cleared if the CSI is used directly (via SW mux) as system clock, or if the CSI is selected as reference clock for PLL1 with PLL1 enabled (PLL1ON bit set to 1).
 */
class csion_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr csion_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI clock ready flag Set by hardware to indicate that the CSI oscillator is stable. This bit is activated only if the RC is enabled by CSION (it is not activated if the CSI is enabled by CSIKERON or by a peripheral request).
 */
class csirdy_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr csirdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI clock enable in Stop mode Set and reset by software to force the CSI to ON, even in Stop mode, in order to be quickly available as kernel clock for some peripherals. This bit has no effect on the value of CSION.
 */
class csikeron_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr csikeron_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 clock enable Set by software and cleared by software or by the hardware when the system enters to Stop or Standby mode.
 */
class hsi48on_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hsi48on_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 clock ready flag Set by hardware to indicate that the HSI48 oscillator is stable.
 */
class hsi48rdy_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hsi48rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock enable Set and cleared by software. Cleared by hardware to stop the HSE when entering Stop or Standby mode. This bit cannot be cleared if the HSE is used directly (via SW mux) as system clock, or if the HSE is selected as reference clock for PLL1 with PLL1 enabled (PLL1ON bit set to 1).
 */
class hseon_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hseon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock ready flag Set by hardware to indicate that the HSE oscillator is stable.
 */
class hserdy_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hserdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock bypass Set and cleared by software to bypass the oscillator with an external clock. The external clock must be enabled with the HSEON bit to be used by the device. The HSEBYP bit can be written only if the HSE oscillator is disabled.
 */
class hsebyp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hsebyp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock security system enable Set by software to enable clock security system on HSE. This bit is 'set only' (disabled by a system reset or when the system enters in Standby mode). When HSECSSON is set, the clock detector is enabled by hardware when the HSE is ready and disabled by hardware if an oscillator failure is detected.
 */
class hsecsson_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hsecsson_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * external high speed clock type in Bypass mode Set and reset by software to select the external clock type (analog or digital). The external clock must be enabled with the HSEON bit to be used by the device. The HSEEXT bit can be written only if the HSE oscillator is disabled.
 */
class hseext_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hseext_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 enable Set and cleared by software to enable PLL1. Cleared by hardware when entering Stop or Standby mode. Note that the hardware prevents writing this bit to 0, if the PLL1 output is used as the system clock.
 */
class pll1on_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll1on_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 clock ready flag Set by hardware to indicate that the PLL1 is locked.
 */
class pll1rdy_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll1rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 enable Set and cleared by software to enable PLL2. Cleared by hardware when entering Stop or Standby mode.
 */
class pll2on_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll2on_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 clock ready flag Set by hardware to indicate that the PLL is locked.
 */
class pll2rdy_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll2rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 enable Set and cleared by software to enable PLL3. Cleared by hardware when entering Stop or Standby mode.
 */
class pll3on_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll3on_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 clock ready flag Set by hardware to indicate that the PLL3 is locked.
 */
class pll3rdy_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll3rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cr_r>() const {return opsy::utility::clear_set<rcc_cr_r>(mask, *this);}
	constexpr auto operator|(rcc_cr_r other) const -> rcc_cr_r { return static_cast<rcc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cr_r> other) const -> opsy::utility::clear_set<rcc_cr_r> {return opsy::utility::clear_set<rcc_cr_r>(rcc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hsion() const -> hsion_f {return hsion_f((value_ & hsion_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsirdy() const -> hsirdy_f {return hsirdy_f((value_ & hsirdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsikeron() const -> hsikeron_f {return hsikeron_f((value_ & hsikeron_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsidiv() const -> hsidiv_f {return hsidiv_f(static_cast<uint8_t>(value_ >> hsidiv_f::offset));}
	[[nodiscard]] constexpr auto hsidivf() const -> hsidivf_f {return hsidivf_f((value_ & hsidivf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csion() const -> csion_f {return csion_f((value_ & csion_f::mask) != 0);}
	[[nodiscard]] constexpr auto csirdy() const -> csirdy_f {return csirdy_f((value_ & csirdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto csikeron() const -> csikeron_f {return csikeron_f((value_ & csikeron_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48on() const -> hsi48on_f {return hsi48on_f((value_ & hsi48on_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48rdy() const -> hsi48rdy_f {return hsi48rdy_f((value_ & hsi48rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto hseon() const -> hseon_f {return hseon_f((value_ & hseon_f::mask) != 0);}
	[[nodiscard]] constexpr auto hserdy() const -> hserdy_f {return hserdy_f((value_ & hserdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsebyp() const -> hsebyp_f {return hsebyp_f((value_ & hsebyp_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsecsson() const -> hsecsson_f {return hsecsson_f((value_ & hsecsson_f::mask) != 0);}
	[[nodiscard]] constexpr auto hseext() const -> hseext_f {return hseext_f((value_ & hseext_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1on() const -> pll1on_f {return pll1on_f((value_ & pll1on_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1rdy() const -> pll1rdy_f {return pll1rdy_f((value_ & pll1rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2on() const -> pll2on_f {return pll2on_f((value_ & pll2on_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2rdy() const -> pll2rdy_f {return pll2rdy_f((value_ & pll2rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3on() const -> pll3on_f {return pll3on_f((value_ & pll3on_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3rdy() const -> pll3rdy_f {return pll3rdy_f((value_ & pll3rdy_f::mask) != 0);}

	constexpr rcc_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cr_r other) const -> rcc_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100011; // 35 0x23

private:
	uint32_t value_;
};

/**
 * RCC HSI calibration register 
 */
class rcc_hsicfgr_r {
public:

/**
 * HSI clock calibration Set by hardware by option byte loading during system reset nreset. Adjusted by software through trimming bits HSITRIM. This field represents the sum of engineering option byte calibration value and HSITRIM bits value.
 */
class hsical_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr hsical_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_hsicfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_hsicfgr_r>() const {return opsy::utility::clear_set<rcc_hsicfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_hsicfgr_r other) const -> rcc_hsicfgr_r { return static_cast<rcc_hsicfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_hsicfgr_r> other) const -> opsy::utility::clear_set<rcc_hsicfgr_r> {return opsy::utility::clear_set<rcc_hsicfgr_r>(rcc_hsicfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * HSI clock trimming Set by software to adjust calibration. HSITRIM field is added to the engineering option bytes loaded during reset phase (FLASH_HSI_OPT) in order to form the calibration trimming value. HSICAL = HSITRIM + FLASH_HSI_OPT. After a change of HSITRIM it takes one system clock cycle before the new HSITRIM value is updated Note: The reset value of the field is 0x40.
 */
class hsitrim_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hsitrim_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_hsicfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_hsicfgr_r>() const {return opsy::utility::clear_set<rcc_hsicfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_hsicfgr_r other) const -> rcc_hsicfgr_r { return static_cast<rcc_hsicfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_hsicfgr_r> other) const -> opsy::utility::clear_set<rcc_hsicfgr_r> {return opsy::utility::clear_set<rcc_hsicfgr_r>(rcc_hsicfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hsical() const -> hsical_f {return hsical_f(static_cast<uint16_t>(value_ >> hsical_f::offset));}
	[[nodiscard]] constexpr auto hsitrim() const -> hsitrim_f {return hsitrim_f(static_cast<uint8_t>(value_ >> hsitrim_f::offset));}

	constexpr rcc_hsicfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_hsicfgr_r other) const -> rcc_hsicfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_hsicfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000000000000; // 4194304 0x400000

private:
	uint32_t value_;
};

/**
 * RCC clock recovery RC register 
 */
class rcc_crrcr_r {
public:

/**
 * Internal RC 48 MHz clock calibration Set by hardware by option-byte loading during system reset NRESET. Read-only.
 */
class hsi48cal_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr hsi48cal_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_crrcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_crrcr_r>() const {return opsy::utility::clear_set<rcc_crrcr_r>(mask, *this);}
	constexpr auto operator|(rcc_crrcr_r other) const -> rcc_crrcr_r { return static_cast<rcc_crrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_crrcr_r> other) const -> opsy::utility::clear_set<rcc_crrcr_r> {return opsy::utility::clear_set<rcc_crrcr_r>(rcc_crrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto hsi48cal() const -> hsi48cal_f {return hsi48cal_f(static_cast<uint16_t>(value_ >> hsi48cal_f::offset));}

	constexpr rcc_crrcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_crrcr_r other) const -> rcc_crrcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_crrcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC CSI calibration register 
 */
class rcc_csicfgr_r {
public:

/**
 * CSI clock calibration Set by hardware by option byte loading during system reset NRESET. Adjusted by software through trimming bits CSITRIM. This field represents the sum of engineering option byte calibration value and CSITRIM bits value.
 */
class csical_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr csical_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_csicfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_csicfgr_r>() const {return opsy::utility::clear_set<rcc_csicfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_csicfgr_r other) const -> rcc_csicfgr_r { return static_cast<rcc_csicfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_csicfgr_r> other) const -> opsy::utility::clear_set<rcc_csicfgr_r> {return opsy::utility::clear_set<rcc_csicfgr_r>(rcc_csicfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * CSI clock trimming Set by software to adjust calibration. CSITRIM field is added to the engineering option bytes loaded during reset phase (FLASH_CSI_OPT) in order to form the calibration trimming value. CSICAL = CSITRIM + FLASH_CSI_OPT. Note: The reset value of the field is 0x20.
 */
class csitrim_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr csitrim_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_csicfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_csicfgr_r>() const {return opsy::utility::clear_set<rcc_csicfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_csicfgr_r other) const -> rcc_csicfgr_r { return static_cast<rcc_csicfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_csicfgr_r> other) const -> opsy::utility::clear_set<rcc_csicfgr_r> {return opsy::utility::clear_set<rcc_csicfgr_r>(rcc_csicfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto csical() const -> csical_f {return csical_f(static_cast<uint8_t>(value_ >> csical_f::offset));}
	[[nodiscard]] constexpr auto csitrim() const -> csitrim_f {return csitrim_f(static_cast<uint8_t>(value_ >> csitrim_f::offset));}

	constexpr rcc_csicfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_csicfgr_r other) const -> rcc_csicfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_csicfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000000000000000000; // 2097152 0x200000

private:
	uint32_t value_;
};

/**
 * RCC clock configuration register 
 */
class rcc_cfgr1_r {
public:

/**
 * system clock and trace clock switch Set and reset by software to select system clock and trace clock sources (sys_ck). Set by hardware in order to: - force the selection of the HSI or CSI (depending on STOPWUCK selection) when leaving a system Stop mode - force the selection of the HSI in case of failure of the HSE when used directly or indirectly as system clock others: reserved
 */
class sw_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sw_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * system clock switch status Set and reset by hardware to indicate which clock source is used as system clock. 000: HSI used as system clock (hsi_ck) (default after reset). others: reserved
 */
class sws_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sws_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * system clock selection after a wakeup from system Stop Set and reset by software to select the system wakeup clock from system Stop. The selected clock is also used as emergency clock for the clock security system (CSS) on HSE. 0: HSI selected as wakeup clock from system Stop (default after reset) STOPWUCK must not be modified when CSS is enabled (by HSECSSON bit) and the system clock is HSE (SWS = 10) or a switch on HSE is requested (SW =10).
 */
class stopwuck_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopwuck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * kernel clock selection after a wakeup from system Stop Set and reset by software to select the kernel wakeup clock from system Stop.
 */
class stopkerwuck_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopkerwuck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE division factor for RTC clock Set and cleared by software to divide the HSE to generate a clock for RTC. Caution: The software must set these bits correctly to ensure that the clock supplied to the RTC is lower than 1 MHz. These bits must be configured if needed before selecting the RTC clock source. ...
 */
class rtcpre_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rtcpre_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * timers clocks prescaler selection This bit is set and reset by software to control the clock frequency of all the timers connected to APB1 and APB2 domains.
 */
class timpre_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr timpre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MCO1 prescaler Set and cleared by software to configure the prescaler of the MCO1. Modification of this prescaler may generate glitches on MCO1. It is highly recommended to change this prescaler only after reset, before enabling the external oscillators and the PLLs. ...
 */
class mco1pre_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mco1pre_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Microcontroller clock output 1 Set and cleared by software. Clock source selection may generate glitches on MCO1. It is highly recommended to configure these bits only after reset, before enabling the external oscillators and the PLLs. others: reserved
 */
class mco1sel_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mco1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MCO2 prescaler Set and cleared by software to configure the prescaler of the MCO2. Modification of this prescaler may generate glitches on MCO2. It is highly recommended to change this prescaler only after reset, before enabling the external oscillators and the PLLs. ...
 */
class mco2pre_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mco2pre_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * microcontroller clock output 2 Set and cleared by software. Clock source selection may generate glitches on MCO2. It is highly recommended to configure these bits only after reset, before enabling the external oscillators and the PLLs. others: reserved
 */
class mco2sel_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mco2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr1_r>() const {return opsy::utility::clear_set<rcc_cfgr1_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return static_cast<rcc_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr1_r> other) const -> opsy::utility::clear_set<rcc_cfgr1_r> {return opsy::utility::clear_set<rcc_cfgr1_r>(rcc_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sw() const -> sw_f {return sw_f(static_cast<uint8_t>(value_ >> sw_f::offset));}
	[[nodiscard]] constexpr auto sws() const -> sws_f {return sws_f(static_cast<uint8_t>(value_ >> sws_f::offset));}
	[[nodiscard]] constexpr auto stopwuck() const -> stopwuck_f {return stopwuck_f((value_ & stopwuck_f::mask) != 0);}
	[[nodiscard]] constexpr auto stopkerwuck() const -> stopkerwuck_f {return stopkerwuck_f((value_ & stopkerwuck_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcpre() const -> rtcpre_f {return rtcpre_f(static_cast<uint8_t>(value_ >> rtcpre_f::offset));}
	[[nodiscard]] constexpr auto timpre() const -> timpre_f {return timpre_f((value_ & timpre_f::mask) != 0);}
	[[nodiscard]] constexpr auto mco1pre() const -> mco1pre_f {return mco1pre_f(static_cast<uint8_t>(value_ >> mco1pre_f::offset));}
	[[nodiscard]] constexpr auto mco1sel() const -> mco1sel_f {return mco1sel_f(static_cast<uint8_t>(value_ >> mco1sel_f::offset));}
	[[nodiscard]] constexpr auto mco2pre() const -> mco2pre_f {return mco2pre_f(static_cast<uint8_t>(value_ >> mco2pre_f::offset));}
	[[nodiscard]] constexpr auto mco2sel() const -> mco2sel_f {return mco2sel_f(static_cast<uint8_t>(value_ >> mco2sel_f::offset));}

	constexpr rcc_cfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cfgr1_r other) const -> rcc_cfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC CPU domain clock configuration register 2 
 */
class rcc_cfgr2_r {
public:

/**
 * AHB prescaler Set and reset by software to control the division factor of rcc_hclk. Changing this division ratio has an impact on the frequency of all bus matrix clocks 0xxx: rcc_hclk = sys_ck (default after reset)
 */
class hpre_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hpre_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * APB low-speed prescaler (APB1) Set and reset by software to control the division factor of rcc_pclk1. The clock is divided by the new prescaler factor from 1 to 16 cycles of rcc_hclk after PPRE write. 0xx: rcc_pclk1 = rcc_hclk1 (default after reset)
 */
class ppre1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ppre1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * APB high-speed prescaler (APB2) Set and reset by software to control APB high-speed clocks division factor. The clocks are divided with the new prescaler factor from 1 to 16 APB cycles after PPRE2 write. 0xx: rcc_pclk2 = rcc_hclk1
 */
class ppre2_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ppre2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * APB low-speed prescaler (APB3) Set and reset by software to control APB low-speed clocks division factor. The clocks are divided with the new prescaler factor from 1 to 16 APB cycles after PPRE3 write. 0xx: rcc_pclk3 = rcc_hclk1
 */
class ppre3_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ppre3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * AHB1 clock disable This bit can be set in order to further reduce power consumption, when none of the AHB1 peripherals from RCC_AHB1ENR are used and when their clocks are disabled in RCC_AHB1ENR. When this bit is set, all the AHB1 peripherals clocks from RCC_AHB1ENR are off. enable control bits
 */
class ahb1dis_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ahb1dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB2 clock disable This bit can be set in order to further reduce power consumption, when none of the AHB2 peripherals from RCC_AHB2ENR are used and when their clocks are disabled in RCC_AHB2ENR. When this bit is set, all the AHB2 peripherals clocks from RCC_AHB2ENR are off. enable control bits
 */
class ahb2dis_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ahb2dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB4 clock disable This bit can be set in order to further reduce power consumption, when none of the AHB4 peripherals from RCC_AHB4ENR are used and when their clocks are disabled in RCC_AHB4ENR. When this bit is set, all the AHB4 peripherals clocks from RCC_AHB4ENR are off. enable control bits
 */
class ahb4dis_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ahb4dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * APB1 clock disable value This bit can be set in order to further reduce power consumption, when none of the APB1 peripherals (except IWDG) are used and when their clocks are disabled in RCC_APB1ENR. When this bit is set, all the APB1 peripherals clocks are off, except for IWDG. control bits
 */
class apb1dis_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr apb1dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * APB2 clock disable value This bit can be set in order to further reduce power consumption, when none of the APB2 peripherals are used and when their clocks are disabled in RCC_APB2ENR. When this bit is set, all the APB2 peripherals clocks are off. control bits
 */
class apb2dis_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr apb2dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * APB3 clock disable value.Set and cleared by software This bit can be set in order to further reduce power consumption, when none of the APB3 peripherals are used and when their clocks are disabled in RCC_APB3ENR. When this bit is set, all the APB3 peripherals clocks are off. control bits
 */
class apb3dis_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr apb3dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cfgr2_r>() const {return opsy::utility::clear_set<rcc_cfgr2_r>(mask, *this);}
	constexpr auto operator|(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return static_cast<rcc_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cfgr2_r> other) const -> opsy::utility::clear_set<rcc_cfgr2_r> {return opsy::utility::clear_set<rcc_cfgr2_r>(rcc_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hpre() const -> hpre_f {return hpre_f(static_cast<uint8_t>(value_ >> hpre_f::offset));}
	[[nodiscard]] constexpr auto ppre1() const -> ppre1_f {return ppre1_f(static_cast<uint8_t>(value_ >> ppre1_f::offset));}
	[[nodiscard]] constexpr auto ppre2() const -> ppre2_f {return ppre2_f(static_cast<uint8_t>(value_ >> ppre2_f::offset));}
	[[nodiscard]] constexpr auto ppre3() const -> ppre3_f {return ppre3_f(static_cast<uint8_t>(value_ >> ppre3_f::offset));}
	[[nodiscard]] constexpr auto ahb1dis() const -> ahb1dis_f {return ahb1dis_f((value_ & ahb1dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ahb2dis() const -> ahb2dis_f {return ahb2dis_f((value_ & ahb2dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ahb4dis() const -> ahb4dis_f {return ahb4dis_f((value_ & ahb4dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto apb1dis() const -> apb1dis_f {return apb1dis_f((value_ & apb1dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto apb2dis() const -> apb2dis_f {return apb2dis_f((value_ & apb2dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto apb3dis() const -> apb3dis_f {return apb3dis_f((value_ & apb3dis_f::mask) != 0);}

	constexpr rcc_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cfgr2_r other) const -> rcc_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL clock source selection register 
 */
class rcc_pll1cfgr_r {
public:

/**
 * DIVMx and PLLs clock source selection Set and reset by software to select the PLL clock source. These bits can be written only when all PLLs are disabled. In order to save power, when no PLL is used, the value of PLL1SRC must be set to '00'. 00: no clock send to DIVMx divider and PLLs (default after reset).
 */
class pll1src_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll1src_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL1 input frequency range Set and reset by software to select the proper reference frequency range used for PLL1. This bit must be written before enabling the PLL1.
 */
class pll1rge_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll1rge_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL1 fractional latch enable Set and reset by software to latch the content of FRACN1 into the sigma-delta modulator. In order to latch the FRACN1 value into the sigma-delta modulator, PLL1FRACEN must be set to 0, then set to 1. The transition 0 to 1 transfers the content of FRACN1 into the modulator.
 */
class pll1fracen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1fracen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 VCO selection Set and reset by software to select the proper VCO frequency range used for PLL1. This bit must be written before enabling the PLL1.
 */
class pll1vcosel_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1vcosel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * prescaler for PLL1 Set and cleared by software to configure the prescaler of the PLL1. The hardware does not allow any modification of this prescaler when PLL1 is enabled (PLL1ON = 1 or PLL1RDY = 1). In order to save power when PLL1 is not used, the value of DIVM1 must be set to 0. ... ...
 */
class divm1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr divm1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL1 DIVP divider output enable Set and reset by software to enable the pll1_p_ck output of the PLL1. This bit can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0). In order to save power, when the pll1_p_ck output of the PLL1 is not used, the pll1_p_ck must be disabled.
 */
class pll1pen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll1pen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 DIVQ divider output enable Set and reset by software to enable the pll1_q_ck output of the PLL1. In order to save power, when the pll1_q_ck output of the PLL1 is not used, the pll1_q_ck must be disabled. This bit can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0).
 */
class pll1qen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll1qen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 DIVR divider output enable Set and reset by software to enable the pll1_r_ck output of the PLL1. To save power, DIVR1EN and DIVR1 bits must be set to 0 when the pll1_r_ck is not used. This bit can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0).
 */
class pll1ren_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll1ren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll1cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll1cfgr_r>() const {return opsy::utility::clear_set<rcc_pll1cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return static_cast<rcc_pll1cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll1cfgr_r> {return opsy::utility::clear_set<rcc_pll1cfgr_r>(rcc_pll1cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pll1src() const -> pll1src_f {return pll1src_f(static_cast<uint8_t>(value_ >> pll1src_f::offset));}
	[[nodiscard]] constexpr auto pll1rge() const -> pll1rge_f {return pll1rge_f(static_cast<uint8_t>(value_ >> pll1rge_f::offset));}
	[[nodiscard]] constexpr auto pll1fracen() const -> pll1fracen_f {return pll1fracen_f((value_ & pll1fracen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1vcosel() const -> pll1vcosel_f {return pll1vcosel_f((value_ & pll1vcosel_f::mask) != 0);}
	[[nodiscard]] constexpr auto divm1() const -> divm1_f {return divm1_f(static_cast<uint8_t>(value_ >> divm1_f::offset));}
	[[nodiscard]] constexpr auto pll1pen() const -> pll1pen_f {return pll1pen_f((value_ & pll1pen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1qen() const -> pll1qen_f {return pll1qen_f((value_ & pll1qen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1ren() const -> pll1ren_f {return pll1ren_f((value_ & pll1ren_f::mask) != 0);}

	constexpr rcc_pll1cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll1cfgr_r other) const -> rcc_pll1cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll1cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL clock source selection register 
 */
class rcc_pll2cfgr_r {
public:

/**
 * DIVMx and PLLs clock source selection Set and reset by software to select the PLL clock source. These bits can be written only when all PLLs are disabled. In order to save power, when no PLL is used, the value of PLL2SRC must be set to '00'.
 */
class pll2src_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll2src_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL2 input frequency range Set and reset by software to select the proper reference frequency range used for PLL2. These bits must be written before enabling the PLL2.
 */
class pll2rge_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll2rge_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL2 fractional latch enable Set and reset by software to enable the pll2_p_ck output of the PLL2. To save power, when the pll2_p_ck output of the PLL2 is not used, the pll2_p_ck must be disabled.
 */
class pll2fracen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll2fracen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 VCO selection Set and reset by software to select the proper VCO frequency range used for PLL2. This bit must be written before enabling the PLL2.
 */
class pll2vcosel_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll2vcosel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * prescaler for PLL2 Set and cleared by software to configure the prescaler of the PLL2. The hardware does not allow any modification of this prescaler when PLL2 is enabled (PLL2ON = 1 or PLL2RDY = 1). In order to save power when PLL2 is not used, the value of DIVM2 must be set to 0. ... ...
 */
class divm2_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr divm2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL2 DIVP divider output enable Set and reset by software to enable the pll2_p_ck output of the PLL2. To save power, when the pll2_p_ck output of the PLL2 is not used, the pll2_p_ck must be disabled.
 */
class pll2pen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll2pen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 DIVQ divider output enable Set and reset by software to enable the pll2_q_ck output of the PLL2. To save power, when the pll2_q_ck output of the PLL2 is not used, the pll2_q_ck must be disabled.
 */
class pll2qen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll2qen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 DIVR divider output enable Set and reset by software to enable the pll2_r_ck output of the PLL2. To save power, DIVR2EN and DIVR2 bits must be set to 0 when the pll2_r_ck is not used.
 */
class pll2ren_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll2ren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll2cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll2cfgr_r>() const {return opsy::utility::clear_set<rcc_pll2cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return static_cast<rcc_pll2cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll2cfgr_r> {return opsy::utility::clear_set<rcc_pll2cfgr_r>(rcc_pll2cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pll2src() const -> pll2src_f {return pll2src_f(static_cast<uint8_t>(value_ >> pll2src_f::offset));}
	[[nodiscard]] constexpr auto pll2rge() const -> pll2rge_f {return pll2rge_f(static_cast<uint8_t>(value_ >> pll2rge_f::offset));}
	[[nodiscard]] constexpr auto pll2fracen() const -> pll2fracen_f {return pll2fracen_f((value_ & pll2fracen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2vcosel() const -> pll2vcosel_f {return pll2vcosel_f((value_ & pll2vcosel_f::mask) != 0);}
	[[nodiscard]] constexpr auto divm2() const -> divm2_f {return divm2_f(static_cast<uint8_t>(value_ >> divm2_f::offset));}
	[[nodiscard]] constexpr auto pll2pen() const -> pll2pen_f {return pll2pen_f((value_ & pll2pen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2qen() const -> pll2qen_f {return pll2qen_f((value_ & pll2qen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2ren() const -> pll2ren_f {return pll2ren_f((value_ & pll2ren_f::mask) != 0);}

	constexpr rcc_pll2cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll2cfgr_r other) const -> rcc_pll2cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll2cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL clock source selection register 
 */
class rcc_pll3cfgr_r {
public:

/**
 * DIVMx and PLLs clock source selection Set and reset by software to select the PLL clock source. These bits can be written only when all PLLs are disabled. In order to save power, when no PLL is used, the value of PLL3SRC must be set to '00'.
 */
class pll3src_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll3src_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL3 input frequency range Set and reset by software to select the proper reference frequency range used for PLL3. This bit must be written before enabling the PLL3.
 */
class pll3rge_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pll3rge_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL3 fractional latch enable Set and reset by software to latch the content of FRACN3 into the sigma-delta modulator. In order to latch the FRACN3 value into the sigma-delta modulator, PLL3FRACEN must be set to 0, then set to 1. The transition 0 to 1 transfers the content of FRACN3 into the modulator.
 */
class pll3fracen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll3fracen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 VCO selection Set and reset by software to select the proper VCO frequency range used for PLL3. This bit must be written before enabling the PLL3.
 */
class pll3vcosel_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll3vcosel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * prescaler for PLL3 Set and cleared by software to configure the prescaler of the PLL3. The hardware does not allow any modification of this prescaler when PLL3 is enabled (PLL3ON = 1 or PLL3RDY = 1). In order to save power when PLL3 is not used, the value of DIVM2 must be set to 0. ... ...
 */
class divm3_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr divm3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL3 DIVP divider output enable Set and reset by software to enable the pll3_p_ck output of the PLL3. To save power, when the pll3_p_ck output of the PLL3 is not used, the pll3_p_ck must be disabled.
 */
class pll3pen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll3pen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 DIVQ divider output enable Set and reset by software to enable the pll3_q_ck output of the PLL3. To save power, when the pll3_q_ck output of the PLL3 is not used, the pll3_q_ck must be disabled.
 */
class pll3qen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll3qen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 DIVR divider output enable Set and reset by software to enable the pll3_r_ck output of the PLL3. To save power, DIVR2EN and DIVR2 bits must be set to 0 when the pll3_r_ck is not used.
 */
class pll3ren_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pll3ren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_pll3cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_pll3cfgr_r>() const {return opsy::utility::clear_set<rcc_pll3cfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return static_cast<rcc_pll3cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3cfgr_r> other) const -> opsy::utility::clear_set<rcc_pll3cfgr_r> {return opsy::utility::clear_set<rcc_pll3cfgr_r>(rcc_pll3cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pll3src() const -> pll3src_f {return pll3src_f(static_cast<uint8_t>(value_ >> pll3src_f::offset));}
	[[nodiscard]] constexpr auto pll3rge() const -> pll3rge_f {return pll3rge_f(static_cast<uint8_t>(value_ >> pll3rge_f::offset));}
	[[nodiscard]] constexpr auto pll3fracen() const -> pll3fracen_f {return pll3fracen_f((value_ & pll3fracen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3vcosel() const -> pll3vcosel_f {return pll3vcosel_f((value_ & pll3vcosel_f::mask) != 0);}
	[[nodiscard]] constexpr auto divm3() const -> divm3_f {return divm3_f(static_cast<uint8_t>(value_ >> divm3_f::offset));}
	[[nodiscard]] constexpr auto pll3pen() const -> pll3pen_f {return pll3pen_f((value_ & pll3pen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3qen() const -> pll3qen_f {return pll3qen_f((value_ & pll3qen_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3ren() const -> pll3ren_f {return pll3ren_f((value_ & pll3ren_f::mask) != 0);}

	constexpr rcc_pll3cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll3cfgr_r other) const -> rcc_pll3cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll3cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL1 dividers register 
 */
class rcc_pll1divr_r {
public:

/**
 * Multiplication factor for PLL1VCO Set and reset by software to control the multiplication factor of the VCO. These bits can be written only when the PLL is disabled (PLL1ON = 0 and PLL1RDY = 0). ... ... Others: reserved
 */
class pll1n_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll1n_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll1divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1divr_r>() const {return opsy::utility::clear_set<rcc_pll1divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1divr_r other) const -> rcc_pll1divr_r { return static_cast<rcc_pll1divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1divr_r> other) const -> opsy::utility::clear_set<rcc_pll1divr_r> {return opsy::utility::clear_set<rcc_pll1divr_r>(rcc_pll1divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * PLL1 DIVP division factor Set and reset by software to control the frequency of the pll1_p_ck clock. These bits can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0). Note that odd division factors are not allowed. ...
 */
class pll1p_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll1p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1divr_r>() const {return opsy::utility::clear_set<rcc_pll1divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1divr_r other) const -> rcc_pll1divr_r { return static_cast<rcc_pll1divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1divr_r> other) const -> opsy::utility::clear_set<rcc_pll1divr_r> {return opsy::utility::clear_set<rcc_pll1divr_r>(rcc_pll1divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL1 DIVQ division factor Set and reset by software to control the frequency of the pll1_q_ck clock. These bits can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0). ...
 */
class pll1q_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll1q_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1divr_r>() const {return opsy::utility::clear_set<rcc_pll1divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1divr_r other) const -> rcc_pll1divr_r { return static_cast<rcc_pll1divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1divr_r> other) const -> opsy::utility::clear_set<rcc_pll1divr_r> {return opsy::utility::clear_set<rcc_pll1divr_r>(rcc_pll1divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL1 DIVR division factor Set and reset by software to control the frequency of the pll1_r_ck clock. These bits can be written only when the PLL1 is disabled (PLL1ON = 0 and PLL1RDY = 0). ...
 */
class pll1r_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll1r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll1divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1divr_r>() const {return opsy::utility::clear_set<rcc_pll1divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1divr_r other) const -> rcc_pll1divr_r { return static_cast<rcc_pll1divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1divr_r> other) const -> opsy::utility::clear_set<rcc_pll1divr_r> {return opsy::utility::clear_set<rcc_pll1divr_r>(rcc_pll1divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pll1n() const -> pll1n_f {return pll1n_f(static_cast<uint16_t>(value_ >> pll1n_f::offset));}
	[[nodiscard]] constexpr auto pll1p() const -> pll1p_f {return pll1p_f(static_cast<uint8_t>(value_ >> pll1p_f::offset));}
	[[nodiscard]] constexpr auto pll1q() const -> pll1q_f {return pll1q_f(static_cast<uint8_t>(value_ >> pll1q_f::offset));}
	[[nodiscard]] constexpr auto pll1r() const -> pll1r_f {return pll1r_f(static_cast<uint8_t>(value_ >> pll1r_f::offset));}

	constexpr rcc_pll1divr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll1divr_r other) const -> rcc_pll1divr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll1divr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000010000001010000000; // 16843392 0x1010280

private:
	uint32_t value_;
};

/**
 * RCC PLL1 fractional divider register 
 */
class rcc_pll1fracr_r {
public:

/**
 * fractional part of the multiplication factor for PLL1 VCO Set and reset by software to control the fractional part of the multiplication factor of the VCO. These bits can be written at any time, allowing dynamic fine-tuning of the PLL1 VCO. The software must set correctly these bits to insure that the VCO output frequency is between its valid frequency range, that is: * 128 to 560 MHz if PLL1VCOSEL = 0 * 150 to 420 MHz if PLL1VCOSEL = 1 VCO output frequency = Fref1_ck x (PLL1N + (PLL1FRACN / 213)), with * PLL1N between 8 and 420 * PLL1FRACN can be between 0 and 213- 1 * The input frequency Fref1_ck must be between 1 and 16 MHz. To change the PLL1FRACN value on-the-fly even if the PLL is enabled, the application must proceed as follows: * Set the bit PLL1FRACEN to 0 * Write the new fractional value into PLL1FRACN * Set the bit PLL1FRACEN to 1
 */
class pll1fracn_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll1fracn_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll1fracr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll1fracr_r>() const {return opsy::utility::clear_set<rcc_pll1fracr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll1fracr_r other) const -> rcc_pll1fracr_r { return static_cast<rcc_pll1fracr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll1fracr_r> other) const -> opsy::utility::clear_set<rcc_pll1fracr_r> {return opsy::utility::clear_set<rcc_pll1fracr_r>(rcc_pll1fracr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto pll1fracn() const -> pll1fracn_f {return pll1fracn_f(static_cast<uint16_t>(value_ >> pll1fracn_f::offset));}

	constexpr rcc_pll1fracr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll1fracr_r other) const -> rcc_pll1fracr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll1fracr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL1 dividers register 
 */
class rcc_pll2divr_r {
public:

/**
 * Multiplication factor for PLL2VCO Set and reset by software to control the multiplication factor of the VCO. These bits can be written only when the PLL is disabled (PLL2ON = 0 and PLL2RDY = 0). ... ... Others: reserved
 */
class pll2n_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll2n_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll2divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2divr_r>() const {return opsy::utility::clear_set<rcc_pll2divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2divr_r other) const -> rcc_pll2divr_r { return static_cast<rcc_pll2divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2divr_r> other) const -> opsy::utility::clear_set<rcc_pll2divr_r> {return opsy::utility::clear_set<rcc_pll2divr_r>(rcc_pll2divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * PLL2 DIVP division factor Set and reset by software to control the frequency of the pll2_p_ck clock. These bits can be written only when the PLL2 is disabled (PLL2ON = 0 and PLL2RDY = 0). ...
 */
class pll2p_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll2p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2divr_r>() const {return opsy::utility::clear_set<rcc_pll2divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2divr_r other) const -> rcc_pll2divr_r { return static_cast<rcc_pll2divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2divr_r> other) const -> opsy::utility::clear_set<rcc_pll2divr_r> {return opsy::utility::clear_set<rcc_pll2divr_r>(rcc_pll2divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL2 DIVQ division factor Set and reset by software to control the frequency of the pll2_q_ck clock. These bits can be written only when the PLL2 is disabled (PLL2ON = 0 and PLL2RDY = 0). ...
 */
class pll2q_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll2q_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2divr_r>() const {return opsy::utility::clear_set<rcc_pll2divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2divr_r other) const -> rcc_pll2divr_r { return static_cast<rcc_pll2divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2divr_r> other) const -> opsy::utility::clear_set<rcc_pll2divr_r> {return opsy::utility::clear_set<rcc_pll2divr_r>(rcc_pll2divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL2 DIVR division factor Set and reset by software to control the frequency of the pll2_r_ck clock. These bits can be written only when the PLL1 is disabled (PLL2ON = 0 and PLL2RDY = 0). ...
 */
class pll2r_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll2r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll2divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2divr_r>() const {return opsy::utility::clear_set<rcc_pll2divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2divr_r other) const -> rcc_pll2divr_r { return static_cast<rcc_pll2divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2divr_r> other) const -> opsy::utility::clear_set<rcc_pll2divr_r> {return opsy::utility::clear_set<rcc_pll2divr_r>(rcc_pll2divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pll2n() const -> pll2n_f {return pll2n_f(static_cast<uint16_t>(value_ >> pll2n_f::offset));}
	[[nodiscard]] constexpr auto pll2p() const -> pll2p_f {return pll2p_f(static_cast<uint8_t>(value_ >> pll2p_f::offset));}
	[[nodiscard]] constexpr auto pll2q() const -> pll2q_f {return pll2q_f(static_cast<uint8_t>(value_ >> pll2q_f::offset));}
	[[nodiscard]] constexpr auto pll2r() const -> pll2r_f {return pll2r_f(static_cast<uint8_t>(value_ >> pll2r_f::offset));}

	constexpr rcc_pll2divr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll2divr_r other) const -> rcc_pll2divr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll2divr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000010000001010000000; // 16843392 0x1010280

private:
	uint32_t value_;
};

/**
 * RCC PLL2 fractional divider register 
 */
class rcc_pll2fracr_r {
public:

/**
 * fractional part of the multiplication factor for PLL2 VCO Set and reset by software to control the fractional part of the multiplication factor of the VCO. These bits can be written at any time, allowing dynamic fine-tuning of the PLL2 VCO. The software must set correctly these bits to insure that the VCO output frequency is between its valid frequency range, that is: * 128 to 560 MHz if PLL2VCOSEL = 0 * 150 to 420 MHz if PLL2VCOSEL = 1 VCO output frequency = Fref2_ck x (PLL2N + (PLL2FRACN / 213)), with * PLL2N between 8 and 420 * PLL2FRACN can be between 0 and 213- 1 * The input frequency Fref2_ck must be between 1 and 16 MHz. To change the PLL2FRACN value on-the-fly even if the PLL is enabled, the application must proceed as follows: * Set the bit PLL2FRACEN to 0 * Write the new fractional value into PLL2FRACN * Set the bit PLL2FRACEN to 1
 */
class pll2fracn_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll2fracn_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll2fracr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll2fracr_r>() const {return opsy::utility::clear_set<rcc_pll2fracr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll2fracr_r other) const -> rcc_pll2fracr_r { return static_cast<rcc_pll2fracr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll2fracr_r> other) const -> opsy::utility::clear_set<rcc_pll2fracr_r> {return opsy::utility::clear_set<rcc_pll2fracr_r>(rcc_pll2fracr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto pll2fracn() const -> pll2fracn_f {return pll2fracn_f(static_cast<uint16_t>(value_ >> pll2fracn_f::offset));}

	constexpr rcc_pll2fracr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll2fracr_r other) const -> rcc_pll2fracr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll2fracr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC PLL3 dividers register 
 */
class rcc_pll3divr_r {
public:

/**
 * Multiplication factor for PLL3VCO Set and reset by software to control the multiplication factor of the VCO. These bits can be written only when the PLL is disabled (PLL3ON = 0 and PLL3RDY = 0). ... ... Others: reserved
 */
class pll3n_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll3n_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll3divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3divr_r>() const {return opsy::utility::clear_set<rcc_pll3divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3divr_r other) const -> rcc_pll3divr_r { return static_cast<rcc_pll3divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3divr_r> other) const -> opsy::utility::clear_set<rcc_pll3divr_r> {return opsy::utility::clear_set<rcc_pll3divr_r>(rcc_pll3divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * PLL3 DIVP division factor Set and reset by software to control the frequency of the pll3_p_ck clock. These bits can be written only when the PLL3 is disabled (PLL3ON = 0 and PLL3RDY = 0). ...
 */
class pll3p_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll3p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3divr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3divr_r>() const {return opsy::utility::clear_set<rcc_pll3divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3divr_r other) const -> rcc_pll3divr_r { return static_cast<rcc_pll3divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3divr_r> other) const -> opsy::utility::clear_set<rcc_pll3divr_r> {return opsy::utility::clear_set<rcc_pll3divr_r>(rcc_pll3divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL3 DIVQ division factor Set and reset by software to control the frequency of the pll3_q_ck clock. These bits can be written only when the PLL3 is disabled (PLL3ON = 0 and PLL3RDY = 0). ...
 */
class pll3q_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll3q_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3divr_r>() const {return opsy::utility::clear_set<rcc_pll3divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3divr_r other) const -> rcc_pll3divr_r { return static_cast<rcc_pll3divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3divr_r> other) const -> opsy::utility::clear_set<rcc_pll3divr_r> {return opsy::utility::clear_set<rcc_pll3divr_r>(rcc_pll3divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PLL3 DIVR division factor Set and reset by software to control the frequency of the pll3_r_ck clock. These bits can be written only when the PLL1 is disabled (PLL3ON = 0 and PLL3RDY = 0). ...
 */
class pll3r_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pll3r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_pll3divr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3divr_r>() const {return opsy::utility::clear_set<rcc_pll3divr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3divr_r other) const -> rcc_pll3divr_r { return static_cast<rcc_pll3divr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3divr_r> other) const -> opsy::utility::clear_set<rcc_pll3divr_r> {return opsy::utility::clear_set<rcc_pll3divr_r>(rcc_pll3divr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pll3n() const -> pll3n_f {return pll3n_f(static_cast<uint16_t>(value_ >> pll3n_f::offset));}
	[[nodiscard]] constexpr auto pll3p() const -> pll3p_f {return pll3p_f(static_cast<uint8_t>(value_ >> pll3p_f::offset));}
	[[nodiscard]] constexpr auto pll3q() const -> pll3q_f {return pll3q_f(static_cast<uint8_t>(value_ >> pll3q_f::offset));}
	[[nodiscard]] constexpr auto pll3r() const -> pll3r_f {return pll3r_f(static_cast<uint8_t>(value_ >> pll3r_f::offset));}

	constexpr rcc_pll3divr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll3divr_r other) const -> rcc_pll3divr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll3divr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000010000001010000000; // 16843392 0x1010280

private:
	uint32_t value_;
};

/**
 * RCC PLL3 fractional divider register 
 */
class rcc_pll3fracr_r {
public:

/**
 * fractional part of the multiplication factor for PLL3 VCO Set and reset by software to control the fractional part of the multiplication factor of the VCO. These bits can be written at any time, allowing dynamic fine-tuning of the PLL3 VCO. The software must set correctly these bits to insure that the VCO output frequency is between its valid frequency range, that is: * 128 to 560 MHz if PLL3VCOSEL = 0 * 150 to 420 MHz if PLL3VCOSEL = 1 VCO output frequency = Fref3_ck x (PLL3N + (PLL3FRACN / 213)), with * PLL3N between 8 and 420 * PLL3FRACN can be between 0 and 213- 1 * The input frequency Fref3_ck must be between 1 and 16 MHz. To change the PLL3FRACN value on-the-fly even if the PLL is enabled, the application must proceed as follows: * Set the bit PLL3FRACEN to 0 * Write the new fractional value into PLL3FRACN * Set the bit PLL3FRACEN to 1.
 */
class pll3fracn_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pll3fracn_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rcc_pll3fracr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_pll3fracr_r>() const {return opsy::utility::clear_set<rcc_pll3fracr_r>(mask, *this);}
	constexpr auto operator|(rcc_pll3fracr_r other) const -> rcc_pll3fracr_r { return static_cast<rcc_pll3fracr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_pll3fracr_r> other) const -> opsy::utility::clear_set<rcc_pll3fracr_r> {return opsy::utility::clear_set<rcc_pll3fracr_r>(rcc_pll3fracr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto pll3fracn() const -> pll3fracn_f {return pll3fracn_f(static_cast<uint16_t>(value_ >> pll3fracn_f::offset));}

	constexpr rcc_pll3fracr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_pll3fracr_r other) const -> rcc_pll3fracr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_pll3fracr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC clock source interrupt enable register 
 */
class rcc_cier_r {
public:

/**
 * LSI ready interrupt enable Set and reset by software to enable/disable interrupt caused by the LSI oscillator stabilization.
 */
class lsirdyie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsirdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE ready interrupt enable Set and reset by software to enable/disable interrupt caused by the LSE oscillator stabilization.
 */
class lserdyie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lserdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI ready interrupt enable Set and reset by software to enable/disable interrupt caused by the CSI oscillator stabilization.
 */
class csirdyie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csirdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI ready interrupt enable Set and reset by software to enable/disable interrupt caused by the HSI oscillator stabilization.
 */
class hsirdyie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsirdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE ready interrupt enable Set and reset by software to enable/disable interrupt caused by the HSE oscillator stabilization.
 */
class hserdyie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hserdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 ready interrupt enable Set and reset by software to enable/disable interrupt caused by the HSI48 oscillator stabilization.
 */
class hsi48rdyie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsi48rdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 ready interrupt enable Set and reset by software to enable/disable interrupt caused by PLL1 lock.
 */
class pll1rdyie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1rdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 ready interrupt enable Set and reset by software to enable/disable interrupt caused by PLL2 lock.
 */
class pll2rdyie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll2rdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 ready interrupt enable Set and reset by software to enable/disable interrupt caused by PLL3 lock.
 */
class pll3rdyie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pll3rdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cier_r>() const {return opsy::utility::clear_set<rcc_cier_r>(mask, *this);}
	constexpr auto operator|(rcc_cier_r other) const -> rcc_cier_r { return static_cast<rcc_cier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cier_r> other) const -> opsy::utility::clear_set<rcc_cier_r> {return opsy::utility::clear_set<rcc_cier_r>(rcc_cier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lsirdyie() const -> lsirdyie_f {return lsirdyie_f((value_ & lsirdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lserdyie() const -> lserdyie_f {return lserdyie_f((value_ & lserdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto csirdyie() const -> csirdyie_f {return csirdyie_f((value_ & csirdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsirdyie() const -> hsirdyie_f {return hsirdyie_f((value_ & hsirdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hserdyie() const -> hserdyie_f {return hserdyie_f((value_ & hserdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48rdyie() const -> hsi48rdyie_f {return hsi48rdyie_f((value_ & hsi48rdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1rdyie() const -> pll1rdyie_f {return pll1rdyie_f((value_ & pll1rdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2rdyie() const -> pll2rdyie_f {return pll2rdyie_f((value_ & pll2rdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3rdyie() const -> pll3rdyie_f {return pll3rdyie_f((value_ & pll3rdyie_f::mask) != 0);}

	constexpr rcc_cier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cier_r other) const -> rcc_cier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC clock source interrupt flag register 
 */
class rcc_cifr_r {
public:

/**
 * LSI ready interrupt flag Reset by software by writing LSIRDYC bit. Set by hardware when the LSI clock becomes stable and LSIRDYIE is set.
 */
class lsirdyf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsirdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE ready interrupt flag Reset by software by writing LSERDYC bit. Set by hardware when the LSE clock becomes stable and LSERDYIE is set.
 */
class lserdyf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lserdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI ready interrupt flag Reset by software by writing CSIRDYC bit. Set by hardware when the CSI clock becomes stable and CSIRDYIE is set.
 */
class csirdyf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csirdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI ready interrupt flag Reset by software by writing HSIRDYC bit. Set by hardware when the HSI clock becomes stable and HSIRDYIE is set.
 */
class hsirdyf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsirdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE ready interrupt flag Reset by software by writing HSERDYC bit. Set by hardware when the HSE clock becomes stable and HSERDYIE is set.
 */
class hserdyf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hserdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 ready interrupt flag Reset by software by writing HSI48RDYC bit. Set by hardware when the HSI48 clock becomes stable and HSI48RDYIE is set.
 */
class hsi48rdyf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsi48rdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 ready interrupt flag Reset by software by writing PLL1RDYC bit. Set by hardware when the PLL1 locks and PLL1RDYIE is set.
 */
class pll1rdyf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1rdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 ready interrupt flag Reset by software by writing PLL2RDYC bit. Set by hardware when the PLL2 locks and PLL2RDYIE is set.
 */
class pll2rdyf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll2rdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 ready interrupt flag Reset by software by writing PLL3RDYC bit. Set by hardware when the PLL3 locks and PLL3RDYIE is set.
 */
class pll3rdyf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pll3rdyf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock security system interrupt flag Reset by software by writing HSECSSC bit. Set by hardware in case of HSE clock failure.
 */
class hsecssf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hsecssf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cifr_r>() const {return opsy::utility::clear_set<rcc_cifr_r>(mask, *this);}
	constexpr auto operator|(rcc_cifr_r other) const -> rcc_cifr_r { return static_cast<rcc_cifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cifr_r> other) const -> opsy::utility::clear_set<rcc_cifr_r> {return opsy::utility::clear_set<rcc_cifr_r>(rcc_cifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lsirdyf() const -> lsirdyf_f {return lsirdyf_f((value_ & lsirdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto lserdyf() const -> lserdyf_f {return lserdyf_f((value_ & lserdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csirdyf() const -> csirdyf_f {return csirdyf_f((value_ & csirdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsirdyf() const -> hsirdyf_f {return hsirdyf_f((value_ & hsirdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hserdyf() const -> hserdyf_f {return hserdyf_f((value_ & hserdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48rdyf() const -> hsi48rdyf_f {return hsi48rdyf_f((value_ & hsi48rdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1rdyf() const -> pll1rdyf_f {return pll1rdyf_f((value_ & pll1rdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2rdyf() const -> pll2rdyf_f {return pll2rdyf_f((value_ & pll2rdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3rdyf() const -> pll3rdyf_f {return pll3rdyf_f((value_ & pll3rdyf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsecssf() const -> hsecssf_f {return hsecssf_f((value_ & hsecssf_f::mask) != 0);}

	constexpr rcc_cifr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cifr_r other) const -> rcc_cifr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cifr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC clock source interrupt clear register 
 */
class rcc_cicr_r {
public:

/**
 * LSI ready interrupt clear Set by software to clear LSIRDYF. Reset by hardware when clear done.
 */
class lsirdyc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsirdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE ready interrupt clear Set by software to clear LSERDYF. Reset by hardware when clear done.
 */
class lserdyc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lserdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI ready interrupt clear Set by software to clear CSIRDYF. Reset by hardware when clear done.
 */
class csirdyc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csirdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI ready interrupt clear Set by software to clear HSIRDYF. Reset by hardware when clear done.
 */
class hsirdyc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsirdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE ready interrupt clear Set by software to clear HSERDYF. Reset by hardware when clear done.
 */
class hserdyc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hserdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 ready interrupt clear Set by software to clear HSI48RDYF. Reset by hardware when clear done.
 */
class hsi48rdyc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsi48rdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 ready interrupt clear Set by software to clear PLL1RDYF. Reset by hardware when clear done.
 */
class pll1rdyc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1rdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 ready interrupt clear Set by software to clear PLL2RDYF. Reset by hardware when clear done.
 */
class pll2rdyc_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll2rdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 ready interrupt clear Set by software to clear PLL3RDYF. Reset by hardware when clear done.
 */
class pll3rdyc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pll3rdyc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock security system interrupt clear Set by software to clear HSECSSF. Reset by hardware when clear done.
 */
class hsecssc_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hsecssc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_cicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_cicr_r>() const {return opsy::utility::clear_set<rcc_cicr_r>(mask, *this);}
	constexpr auto operator|(rcc_cicr_r other) const -> rcc_cicr_r { return static_cast<rcc_cicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_cicr_r> other) const -> opsy::utility::clear_set<rcc_cicr_r> {return opsy::utility::clear_set<rcc_cicr_r>(rcc_cicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lsirdyc() const -> lsirdyc_f {return lsirdyc_f((value_ & lsirdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto lserdyc() const -> lserdyc_f {return lserdyc_f((value_ & lserdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto csirdyc() const -> csirdyc_f {return csirdyc_f((value_ & csirdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsirdyc() const -> hsirdyc_f {return hsirdyc_f((value_ & hsirdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hserdyc() const -> hserdyc_f {return hserdyc_f((value_ & hserdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48rdyc() const -> hsi48rdyc_f {return hsi48rdyc_f((value_ & hsi48rdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1rdyc() const -> pll1rdyc_f {return pll1rdyc_f((value_ & pll1rdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2rdyc() const -> pll2rdyc_f {return pll2rdyc_f((value_ & pll2rdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3rdyc() const -> pll3rdyc_f {return pll3rdyc_f((value_ & pll3rdyc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsecssc() const -> hsecssc_f {return hsecssc_f((value_ & hsecssc_f::mask) != 0);}

	constexpr rcc_cicr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_cicr_r other) const -> rcc_cicr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_cicr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC AHB1 reset register 
 */
class rcc_ahb1rstr_r {
public:

/**
 * GPDMA1 block reset Set and reset by software.
 */
class gpdma1rst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 block reset Set and reset by software.
 */
class gpdma2rst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC block reset Set and reset by software.
 */
class crcrst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CORDIC block reset Set and reset by software.
 */
class cordicrst_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMAC block reset Set and reset by software.
 */
class fmacrst_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RAMCFG block reset Set and reset by software.
 */
class ramcfgrst_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHRST block reset Set and reset by software
 */
class ethrst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TZSC1 reset Set and reset by software
 */
class tzsc1rst_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzsc1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1rstr_r>() const {return opsy::utility::clear_set<rcc_ahb1rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return static_cast<rcc_ahb1rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb1rstr_r> {return opsy::utility::clear_set<rcc_ahb1rstr_r>(rcc_ahb1rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpdma1rst() const -> gpdma1rst_f {return gpdma1rst_f((value_ & gpdma1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpdma2rst() const -> gpdma2rst_f {return gpdma2rst_f((value_ & gpdma2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcrst() const -> crcrst_f {return crcrst_f((value_ & crcrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicrst() const -> cordicrst_f {return cordicrst_f((value_ & cordicrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacrst() const -> fmacrst_f {return fmacrst_f((value_ & fmacrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgrst() const -> ramcfgrst_f {return ramcfgrst_f((value_ & ramcfgrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethrst() const -> ethrst_f {return ethrst_f((value_ & ethrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzsc1rst() const -> tzsc1rst_f {return tzsc1rst_f((value_ & tzsc1rst_f::mask) != 0);}

	constexpr rcc_ahb1rstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb1rstr_r other) const -> rcc_ahb1rstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb1rstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC AHB2 peripheral reset register 
 */
class rcc_ahb2rstr_r {
public:

/**
 * GPIOA block reset Set and reset by software.
 */
class gpioarst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioarst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOB block reset Set and reset by software.
 */
class gpiobrst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiobrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOC block reset Set and reset by software.
 */
class gpiocrst_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiocrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOD block reset Set and reset by software.
 */
class gpiodrst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiodrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOE block reset Set and reset by software.
 */
class gpioerst_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioerst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOF block reset Set and reset by software.
 */
class gpiofrst_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiofrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOG block reset Set and reset by software.
 */
class gpiogrst_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiogrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOH block reset Set and reset by software.
 */
class gpiohrst_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiohrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOI block reset Set and reset by software.
 */
class gpioirst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr gpioirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC1 and 2 blocks reset Set and reset by software.
 */
class adc12rst_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC block reset Set and reset by software.
 */
class dac12rst_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dac12rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * digital camera interface block reset (DCMI or PSSI depending which interface is active) Set and reset by software.
 */
class dcmi_pssirst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmi_pssirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HASH block reset Set and reset by software.
 */
class hashrst_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG block reset Set and reset by software.
 */
class rngrst_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2rstr_r>() const {return opsy::utility::clear_set<rcc_ahb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return static_cast<rcc_ahb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb2rstr_r> {return opsy::utility::clear_set<rcc_ahb2rstr_r>(rcc_ahb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpioarst() const -> gpioarst_f {return gpioarst_f((value_ & gpioarst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiobrst() const -> gpiobrst_f {return gpiobrst_f((value_ & gpiobrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiocrst() const -> gpiocrst_f {return gpiocrst_f((value_ & gpiocrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiodrst() const -> gpiodrst_f {return gpiodrst_f((value_ & gpiodrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioerst() const -> gpioerst_f {return gpioerst_f((value_ & gpioerst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiofrst() const -> gpiofrst_f {return gpiofrst_f((value_ & gpiofrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiogrst() const -> gpiogrst_f {return gpiogrst_f((value_ & gpiogrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiohrst() const -> gpiohrst_f {return gpiohrst_f((value_ & gpiohrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioirst() const -> gpioirst_f {return gpioirst_f((value_ & gpioirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12rst() const -> adc12rst_f {return adc12rst_f((value_ & adc12rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac12rst() const -> dac12rst_f {return dac12rst_f((value_ & dac12rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmi_pssirst() const -> dcmi_pssirst_f {return dcmi_pssirst_f((value_ & dcmi_pssirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashrst() const -> hashrst_f {return hashrst_f((value_ & hashrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngrst() const -> rngrst_f {return rngrst_f((value_ & rngrst_f::mask) != 0);}

	constexpr rcc_ahb2rstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb2rstr_r other) const -> rcc_ahb2rstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb2rstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC AHB4 peripheral reset register 
 */
class rcc_ahb4rstr_r {
public:

/**
 * SDMMC1 and SDMMC1 delay blocks reset Set and reset by software.
 */
class sdmmc1rst_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4rstr_r>() const {return opsy::utility::clear_set<rcc_ahb4rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4rstr_r other) const -> rcc_ahb4rstr_r { return static_cast<rcc_ahb4rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb4rstr_r> {return opsy::utility::clear_set<rcc_ahb4rstr_r>(rcc_ahb4rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDMMC2 and SDMMC2 delay blocks reset Set and reset by software.
 */
class sdmmc2rst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4rstr_r>() const {return opsy::utility::clear_set<rcc_ahb4rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4rstr_r other) const -> rcc_ahb4rstr_r { return static_cast<rcc_ahb4rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb4rstr_r> {return opsy::utility::clear_set<rcc_ahb4rstr_r>(rcc_ahb4rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMC block reset Set and reset by software.
 */
class fmcrst_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4rstr_r>() const {return opsy::utility::clear_set<rcc_ahb4rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4rstr_r other) const -> rcc_ahb4rstr_r { return static_cast<rcc_ahb4rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb4rstr_r> {return opsy::utility::clear_set<rcc_ahb4rstr_r>(rcc_ahb4rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OCTOSPI1 block reset Set and reset by software.
 */
class octospi1rst_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4rstr_r>() const {return opsy::utility::clear_set<rcc_ahb4rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4rstr_r other) const -> rcc_ahb4rstr_r { return static_cast<rcc_ahb4rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4rstr_r> other) const -> opsy::utility::clear_set<rcc_ahb4rstr_r> {return opsy::utility::clear_set<rcc_ahb4rstr_r>(rcc_ahb4rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sdmmc1rst() const -> sdmmc1rst_f {return sdmmc1rst_f((value_ & sdmmc1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2rst() const -> sdmmc2rst_f {return sdmmc2rst_f((value_ & sdmmc2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcrst() const -> fmcrst_f {return fmcrst_f((value_ & fmcrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1rst() const -> octospi1rst_f {return octospi1rst_f((value_ & octospi1rst_f::mask) != 0);}

	constexpr rcc_ahb4rstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb4rstr_r other) const -> rcc_ahb4rstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb4rstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB1 peripheral low reset register 
 */
class rcc_apb1lrstr_r {
public:

/**
 * TIM2 block reset Set and reset by software.
 */
class tim2rst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM3 block reset Set and reset by software.
 */
class tim3rst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM4 block reset Set and reset by software.
 */
class tim4rst_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM5 block reset Set and reset by software.
 */
class tim5rst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM6 block reset Set and reset by software.
 */
class tim6rst_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM7 block reset Set and reset by software.
 */
class tim7rst_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM12 block reset Set and reset by software.
 */
class tim12rst_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM13 block reset t Set and reset by software.
 */
class tim13rst_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM14 block reset Set and reset by software.
 */
class tim14rst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI2 block reset Set and reset by software.
 */
class spi2rst_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI3 block reset Set and reset by software.
 */
class spi3rst_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART2 block reset Set and reset by software.
 */
class usart2rst_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART3 block reset Set and reset by software.
 */
class usart3rst_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart3rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART4 block reset Set and reset by software.
 */
class uart4rst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart4rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART5 block reset Set and reset by software.
 */
class uart5rst_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C1 block reset Set and reset by software.
 */
class i2c1rst_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C2 block reset Set and reset by software.
 */
class i2c2rst_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I3C1 block reset Set and reset by software.
 */
class i3c1rst_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRS block reset Set and reset by software.
 */
class crsrst_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crsrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART6 block reset Set and reset by software.
 */
class usart6rst_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART10 block reset Set and reset by software.
 */
class usart10rst_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART11 block reset Set and reset by software.
 */
class usart11rst_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HDMI-CEC block reset Set and reset by software.
 */
class cecrst_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cecrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART7 block reset Set and reset by software.
 */
class uart7rst_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART8 block reset Set and reset by software.
 */
class uart8rst_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lrstr_r>() const {return opsy::utility::clear_set<rcc_apb1lrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return static_cast<rcc_apb1lrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1lrstr_r> {return opsy::utility::clear_set<rcc_apb1lrstr_r>(rcc_apb1lrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2rst() const -> tim2rst_f {return tim2rst_f((value_ & tim2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3rst() const -> tim3rst_f {return tim3rst_f((value_ & tim3rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4rst() const -> tim4rst_f {return tim4rst_f((value_ & tim4rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5rst() const -> tim5rst_f {return tim5rst_f((value_ & tim5rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6rst() const -> tim6rst_f {return tim6rst_f((value_ & tim6rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7rst() const -> tim7rst_f {return tim7rst_f((value_ & tim7rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12rst() const -> tim12rst_f {return tim12rst_f((value_ & tim12rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13rst() const -> tim13rst_f {return tim13rst_f((value_ & tim13rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14rst() const -> tim14rst_f {return tim14rst_f((value_ & tim14rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2rst() const -> spi2rst_f {return spi2rst_f((value_ & spi2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3rst() const -> spi3rst_f {return spi3rst_f((value_ & spi3rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2rst() const -> usart2rst_f {return usart2rst_f((value_ & usart2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3rst() const -> usart3rst_f {return usart3rst_f((value_ & usart3rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4rst() const -> uart4rst_f {return uart4rst_f((value_ & uart4rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5rst() const -> uart5rst_f {return uart5rst_f((value_ & uart5rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1rst() const -> i2c1rst_f {return i2c1rst_f((value_ & i2c1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2rst() const -> i2c2rst_f {return i2c2rst_f((value_ & i2c2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1rst() const -> i3c1rst_f {return i3c1rst_f((value_ & i3c1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto crsrst() const -> crsrst_f {return crsrst_f((value_ & crsrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6rst() const -> usart6rst_f {return usart6rst_f((value_ & usart6rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10rst() const -> usart10rst_f {return usart10rst_f((value_ & usart10rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11rst() const -> usart11rst_f {return usart11rst_f((value_ & usart11rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cecrst() const -> cecrst_f {return cecrst_f((value_ & cecrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7rst() const -> uart7rst_f {return uart7rst_f((value_ & uart7rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8rst() const -> uart8rst_f {return uart8rst_f((value_ & uart8rst_f::mask) != 0);}

	constexpr rcc_apb1lrstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1lrstr_r other) const -> rcc_apb1lrstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1lrstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB1 peripheral high reset register 
 */
class rcc_apb1hrstr_r {
public:

/**
 * UART9 block reset Set and reset by software.
 */
class uart9rst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart9rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART12 block reset Set and reset by software.
 */
class uart12rst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart12rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DTS block reset Set and reset by software.
 */
class dtsrst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtsrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM2 block reset Set and reset by software.
 */
class lptim2rst_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FDCAN1 and FDCAN2 blocks reset Set and reset by software.
 */
class fdcan12rst_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fdcan12rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UCPD block reset Set and reset by software.
 */
class ucpdrst_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ucpdrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hrstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hrstr_r>() const {return opsy::utility::clear_set<rcc_apb1hrstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return static_cast<rcc_apb1hrstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hrstr_r> other) const -> opsy::utility::clear_set<rcc_apb1hrstr_r> {return opsy::utility::clear_set<rcc_apb1hrstr_r>(rcc_apb1hrstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uart9rst() const -> uart9rst_f {return uart9rst_f((value_ & uart9rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12rst() const -> uart12rst_f {return uart12rst_f((value_ & uart12rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtsrst() const -> dtsrst_f {return dtsrst_f((value_ & dtsrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2rst() const -> lptim2rst_f {return lptim2rst_f((value_ & lptim2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan12rst() const -> fdcan12rst_f {return fdcan12rst_f((value_ & fdcan12rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdrst() const -> ucpdrst_f {return ucpdrst_f((value_ & ucpdrst_f::mask) != 0);}

	constexpr rcc_apb1hrstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1hrstr_r other) const -> rcc_apb1hrstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1hrstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB2 peripheral reset register 
 */
class rcc_apb2rstr_r {
public:

/**
 * TIM1 block reset Set and reset by software.
 */
class tim1rst_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI1 block reset Set and reset by software.
 */
class spi1rst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM8 block reset Set and reset by software.
 */
class tim8rst_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART1 block reset Set and reset by software.
 */
class usart1rst_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM15 block reset Set and reset by software.
 */
class tim15rst_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim15rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM16 block reset Set and reset by software.
 */
class tim16rst_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim16rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM17 block reset Set and reset by software.
 */
class tim17rst_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim17rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI4 block reset Set and reset by software.
 */
class spi4rst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi4rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI6 block reset Set and reset by software.
 */
class spi6rst_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI1 block reset Set and reset by software.
 */
class sai1rst_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI2 block reset Set and reset by software.
 */
class sai2rst_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USBFS block reset Set and reset by software.
 */
class usbfsrst_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbfsrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2rstr_r>() const {return opsy::utility::clear_set<rcc_apb2rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return static_cast<rcc_apb2rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2rstr_r> other) const -> opsy::utility::clear_set<rcc_apb2rstr_r> {return opsy::utility::clear_set<rcc_apb2rstr_r>(rcc_apb2rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim1rst() const -> tim1rst_f {return tim1rst_f((value_ & tim1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1rst() const -> spi1rst_f {return spi1rst_f((value_ & spi1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8rst() const -> tim8rst_f {return tim8rst_f((value_ & tim8rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1rst() const -> usart1rst_f {return usart1rst_f((value_ & usart1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15rst() const -> tim15rst_f {return tim15rst_f((value_ & tim15rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16rst() const -> tim16rst_f {return tim16rst_f((value_ & tim16rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17rst() const -> tim17rst_f {return tim17rst_f((value_ & tim17rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4rst() const -> spi4rst_f {return spi4rst_f((value_ & spi4rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6rst() const -> spi6rst_f {return spi6rst_f((value_ & spi6rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1rst() const -> sai1rst_f {return sai1rst_f((value_ & sai1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2rst() const -> sai2rst_f {return sai2rst_f((value_ & sai2rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbfsrst() const -> usbfsrst_f {return usbfsrst_f((value_ & usbfsrst_f::mask) != 0);}

	constexpr rcc_apb2rstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb2rstr_r other) const -> rcc_apb2rstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb2rstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB4 peripheral reset register 
 */
class rcc_apb3rstr_r {
public:

/**
 * SBS block reset Set and reset by software.
 */
class sbsrst_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbsrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI5 block reset Set and reset by software.
 */
class spi5rst_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spi5rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART1 block reset Set and reset by software.
 */
class lpuart1rst_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpuart1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C3 block reset Set and reset by software.
 */
class i2c3rst_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr i2c3rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C4 block reset Set and reset by software.
 */
class i2c4rst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr i2c4rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM1 block reset Set and reset by software.
 */
class lptim1rst_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim1rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM3 block reset Set and reset by software.
 */
class lptim3rst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim3rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM4 block reset Set and reset by software.
 */
class lptim4rst_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim4rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM5 block reset Set and reset by software.
 */
class lptim5rst_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim5rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM6 block reset Set and reset by software.
 */
class lptim6rst_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim6rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VREF block reset Set and reset by software.
 */
class vrefrst_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vrefrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3rstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3rstr_r>() const {return opsy::utility::clear_set<rcc_apb3rstr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return static_cast<rcc_apb3rstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3rstr_r> other) const -> opsy::utility::clear_set<rcc_apb3rstr_r> {return opsy::utility::clear_set<rcc_apb3rstr_r>(rcc_apb3rstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbsrst() const -> sbsrst_f {return sbsrst_f((value_ & sbsrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5rst() const -> spi5rst_f {return spi5rst_f((value_ & spi5rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1rst() const -> lpuart1rst_f {return lpuart1rst_f((value_ & lpuart1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3rst() const -> i2c3rst_f {return i2c3rst_f((value_ & i2c3rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4rst() const -> i2c4rst_f {return i2c4rst_f((value_ & i2c4rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1rst() const -> lptim1rst_f {return lptim1rst_f((value_ & lptim1rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3rst() const -> lptim3rst_f {return lptim3rst_f((value_ & lptim3rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4rst() const -> lptim4rst_f {return lptim4rst_f((value_ & lptim4rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5rst() const -> lptim5rst_f {return lptim5rst_f((value_ & lptim5rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim6rst() const -> lptim6rst_f {return lptim6rst_f((value_ & lptim6rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefrst() const -> vrefrst_f {return vrefrst_f((value_ & vrefrst_f::mask) != 0);}

	constexpr rcc_apb3rstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb3rstr_r other) const -> rcc_apb3rstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb3rstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC AHB1 peripherals clock register 
 */
class rcc_ahb1enr_r {
public:

/**
 * GPDMA1 clock enable Set and reset by software.
 */
class gpdma1en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 clock enable Set and reset by software.
 */
class gpdma2en_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Flash interface clock enable Set and reset by software.
 */
class flitfen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr flitfen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC clock enable Set and reset by software.
 */
class crcen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CORDIC clock enable Set and reset by software.
 */
class cordicen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordicen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMAC clock enable Set and reset by software.
 */
class fmacen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmacen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RAMCFG clock enable Set and reset by software.
 */
class ramcfgen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfgen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETH clock enable Set and reset by software
 */
class ethen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHTX clock enable Set and reset by software
 */
class ethtxen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethtxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHRX clock enable Set and reset by software
 */
class ethrxen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethrxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TZSC1 clock enable Set and reset by software
 */
class tzsc1en_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzsc1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BKPRAM clock enable Set and reset by software
 */
class bkpramen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkpramen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DCACHE clock enable Set and reset by software
 */
class dcacheen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcacheen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM1 clock enable Set and reset by software.
 */
class sram1en_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1enr_r>() const {return opsy::utility::clear_set<rcc_ahb1enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return static_cast<rcc_ahb1enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1enr_r> other) const -> opsy::utility::clear_set<rcc_ahb1enr_r> {return opsy::utility::clear_set<rcc_ahb1enr_r>(rcc_ahb1enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpdma1en() const -> gpdma1en_f {return gpdma1en_f((value_ & gpdma1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpdma2en() const -> gpdma2en_f {return gpdma2en_f((value_ & gpdma2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto flitfen() const -> flitfen_f {return flitfen_f((value_ & flitfen_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcen() const -> crcen_f {return crcen_f((value_ & crcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordicen() const -> cordicen_f {return cordicen_f((value_ & cordicen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmacen() const -> fmacen_f {return fmacen_f((value_ & fmacen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfgen() const -> ramcfgen_f {return ramcfgen_f((value_ & ramcfgen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethen() const -> ethen_f {return ethen_f((value_ & ethen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethtxen() const -> ethtxen_f {return ethtxen_f((value_ & ethtxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethrxen() const -> ethrxen_f {return ethrxen_f((value_ & ethrxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzsc1en() const -> tzsc1en_f {return tzsc1en_f((value_ & tzsc1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpramen() const -> bkpramen_f {return bkpramen_f((value_ & bkpramen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcacheen() const -> dcacheen_f {return dcacheen_f((value_ & dcacheen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1en() const -> sram1en_f {return sram1en_f((value_ & sram1en_f::mask) != 0);}

	constexpr rcc_ahb1enr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb1enr_r other) const -> rcc_ahb1enr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb1enr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11010000000000000000000100000000; // 3489661184 0xD0000100

private:
	uint32_t value_;
};

/**
 * RCC AHB2 peripheral clock register 
 */
class rcc_ahb2enr_r {
public:

/**
 * GPIOA clock enable Set and reset by software.
 */
class gpioaen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOB clock enable Set and reset by software.
 */
class gpioben_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioben_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOC clock enable Set and reset by software.
 */
class gpiocen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiocen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOD clock enable Set and reset by software.
 */
class gpioden_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOE clock enable Set and reset by software.
 */
class gpioeen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioeen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOF clock enable Set and reset by software.
 */
class gpiofen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiofen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOG clock enable Set and reset by software.
 */
class gpiogen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiogen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOH clock enable Set and reset by software.
 */
class gpiohen_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiohen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOI clock enable Set and reset by software.
 */
class gpioien_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr gpioien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC1 and 2 peripherals clock enabled Set and reset by software.
 */
class adc12en_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC clock enable Set and reset by software.
 */
class dac12en_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dac12en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * digital camera interface clock enable (DCMI or PSSI depending which interface is active) Set and reset by software.
 */
class dcmi_pssien_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmi_pssien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HASH clock enable Set and reset by software.
 */
class hashen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG clock enable Set and reset by software.
 */
class rngen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rngen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM3 clock enable Set and reset by software.
 */
class sram3en_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 clock enable Set and reset by software.
 */
class sram2en_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2enr_r>() const {return opsy::utility::clear_set<rcc_ahb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return static_cast<rcc_ahb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2enr_r> other) const -> opsy::utility::clear_set<rcc_ahb2enr_r> {return opsy::utility::clear_set<rcc_ahb2enr_r>(rcc_ahb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpioaen() const -> gpioaen_f {return gpioaen_f((value_ & gpioaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioben() const -> gpioben_f {return gpioben_f((value_ & gpioben_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiocen() const -> gpiocen_f {return gpiocen_f((value_ & gpiocen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioden() const -> gpioden_f {return gpioden_f((value_ & gpioden_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioeen() const -> gpioeen_f {return gpioeen_f((value_ & gpioeen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiofen() const -> gpiofen_f {return gpiofen_f((value_ & gpiofen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiogen() const -> gpiogen_f {return gpiogen_f((value_ & gpiogen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiohen() const -> gpiohen_f {return gpiohen_f((value_ & gpiohen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioien() const -> gpioien_f {return gpioien_f((value_ & gpioien_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12en() const -> adc12en_f {return adc12en_f((value_ & adc12en_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac12en() const -> dac12en_f {return dac12en_f((value_ & dac12en_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmi_pssien() const -> dcmi_pssien_f {return dcmi_pssien_f((value_ & dcmi_pssien_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashen() const -> hashen_f {return hashen_f((value_ & hashen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngen() const -> rngen_f {return rngen_f((value_ & rngen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3en() const -> sram3en_f {return sram3en_f((value_ & sram3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2en() const -> sram2en_f {return sram2en_f((value_ & sram2en_f::mask) != 0);}

	constexpr rcc_ahb2enr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb2enr_r other) const -> rcc_ahb2enr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb2enr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000000000000000000000000000; // 3221225472 0xC0000000

private:
	uint32_t value_;
};

/**
 * RCC AHB4 peripheral clock register 
 */
class rcc_ahb4enr_r {
public:

/**
 * SDMMC1 and SDMMC1 delay peripheral clock enable reset
 */
class sdmmc1en_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4enr_r>() const {return opsy::utility::clear_set<rcc_ahb4enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4enr_r other) const -> rcc_ahb4enr_r { return static_cast<rcc_ahb4enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4enr_r> other) const -> opsy::utility::clear_set<rcc_ahb4enr_r> {return opsy::utility::clear_set<rcc_ahb4enr_r>(rcc_ahb4enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDMMC2 and SDMMC2 delay peripheral clock enabled Set and reset by software.
 */
class sdmmc2en_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4enr_r>() const {return opsy::utility::clear_set<rcc_ahb4enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4enr_r other) const -> rcc_ahb4enr_r { return static_cast<rcc_ahb4enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4enr_r> other) const -> opsy::utility::clear_set<rcc_ahb4enr_r> {return opsy::utility::clear_set<rcc_ahb4enr_r>(rcc_ahb4enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMC clock enable Set and reset by software.
 */
class fmcen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4enr_r>() const {return opsy::utility::clear_set<rcc_ahb4enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4enr_r other) const -> rcc_ahb4enr_r { return static_cast<rcc_ahb4enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4enr_r> other) const -> opsy::utility::clear_set<rcc_ahb4enr_r> {return opsy::utility::clear_set<rcc_ahb4enr_r>(rcc_ahb4enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OCTOSPI1 clock enable Set and reset by software.
 */
class octospi1en_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4enr_r>() const {return opsy::utility::clear_set<rcc_ahb4enr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4enr_r other) const -> rcc_ahb4enr_r { return static_cast<rcc_ahb4enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4enr_r> other) const -> opsy::utility::clear_set<rcc_ahb4enr_r> {return opsy::utility::clear_set<rcc_ahb4enr_r>(rcc_ahb4enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sdmmc1en() const -> sdmmc1en_f {return sdmmc1en_f((value_ & sdmmc1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2en() const -> sdmmc2en_f {return sdmmc2en_f((value_ & sdmmc2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmcen() const -> fmcen_f {return fmcen_f((value_ & fmcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1en() const -> octospi1en_f {return octospi1en_f((value_ & octospi1en_f::mask) != 0);}

	constexpr rcc_ahb4enr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb4enr_r other) const -> rcc_ahb4enr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb4enr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB1 peripheral clock register 
 */
class rcc_apb1lenr_r {
public:

/**
 * TIM2 clock enable Set and reset by software.
 */
class tim2en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM3 clock enable Set and reset by software.
 */
class tim3en_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM4 clock enable Set and reset by software.
 */
class tim4en_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM5 clock enable Set and reset by software.
 */
class tim5en_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM6 clock enable Set and reset by software.
 */
class tim6en_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM7 clock enable Set and reset by software.
 */
class tim7en_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM12 clock enable Set and reset by software.
 */
class tim12en_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM13 clock enable Set and reset by software.
 */
class tim13en_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM14 clock enable Set and reset by software.
 */
class tim14en_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WWDG clock enable Set and reset by software.
 */
class wwdgen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdgen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI2 clock enable Set and reset by software.
 */
class spi2en_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI3 clock enable Set and reset by software.
 */
class spi3en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART2 clock enable Set and reset by software.
 */
class usart2en_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART3 clock enable Set and reset by software.
 */
class usart3en_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART4 clock enable Set and reset by software.
 */
class uart4en_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART5 clock enable Set and reset by software.
 */
class uart5en_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C1 clock enable Set and reset by software.
 */
class i2c1en_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C2 clock enable Set and reset by software.
 */
class i2c2en_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I3C1 clock enable Set and reset by software.
 */
class i3c1en_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRS clock enable Set and reset by software.
 */
class crsen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART6 clock enable Set and reset by software.
 */
class usart6en_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART10 clock enable Set and reset by software.
 */
class usart10en_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART11 clock enable
 */
class usart11en_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HDMI-CEC clock enable Set and reset by software.
 */
class cecen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cecen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART7 clock enable Set and reset by software.
 */
class uart7en_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART8 clock enable Set and reset by software.
 */
class uart8en_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1lenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1lenr_r>() const {return opsy::utility::clear_set<rcc_apb1lenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return static_cast<rcc_apb1lenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1lenr_r> other) const -> opsy::utility::clear_set<rcc_apb1lenr_r> {return opsy::utility::clear_set<rcc_apb1lenr_r>(rcc_apb1lenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2en() const -> tim2en_f {return tim2en_f((value_ & tim2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3en() const -> tim3en_f {return tim3en_f((value_ & tim3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4en() const -> tim4en_f {return tim4en_f((value_ & tim4en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5en() const -> tim5en_f {return tim5en_f((value_ & tim5en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6en() const -> tim6en_f {return tim6en_f((value_ & tim6en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7en() const -> tim7en_f {return tim7en_f((value_ & tim7en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12en() const -> tim12en_f {return tim12en_f((value_ & tim12en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13en() const -> tim13en_f {return tim13en_f((value_ & tim13en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14en() const -> tim14en_f {return tim14en_f((value_ & tim14en_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgen() const -> wwdgen_f {return wwdgen_f((value_ & wwdgen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2en() const -> spi2en_f {return spi2en_f((value_ & spi2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3en() const -> spi3en_f {return spi3en_f((value_ & spi3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2en() const -> usart2en_f {return usart2en_f((value_ & usart2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3en() const -> usart3en_f {return usart3en_f((value_ & usart3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4en() const -> uart4en_f {return uart4en_f((value_ & uart4en_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5en() const -> uart5en_f {return uart5en_f((value_ & uart5en_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1en() const -> i2c1en_f {return i2c1en_f((value_ & i2c1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2en() const -> i2c2en_f {return i2c2en_f((value_ & i2c2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1en() const -> i3c1en_f {return i3c1en_f((value_ & i3c1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto crsen() const -> crsen_f {return crsen_f((value_ & crsen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6en() const -> usart6en_f {return usart6en_f((value_ & usart6en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10en() const -> usart10en_f {return usart10en_f((value_ & usart10en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11en() const -> usart11en_f {return usart11en_f((value_ & usart11en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cecen() const -> cecen_f {return cecen_f((value_ & cecen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7en() const -> uart7en_f {return uart7en_f((value_ & uart7en_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8en() const -> uart8en_f {return uart8en_f((value_ & uart8en_f::mask) != 0);}

	constexpr rcc_apb1lenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1lenr_r other) const -> rcc_apb1lenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1lenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB1 peripheral clock register 
 */
class rcc_apb1henr_r {
public:

/**
 * UART9 clock enable Set and reset by software.
 */
class uart9en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart9en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART12 clock enable Set and reset by software.
 */
class uart12en_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart12en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DTS clock enable Set and reset by software.
 */
class dtsen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM2 clock enable Set and reset by software.
 */
class lptim2en_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FDCAN1 and FDCAN2 peripheral clock enable Set and reset by software.
 */
class fdcan12en_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fdcan12en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UCPD clock enable Set and reset by software.
 */
class ucpden_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ucpden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1henr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1henr_r>() const {return opsy::utility::clear_set<rcc_apb1henr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return static_cast<rcc_apb1henr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1henr_r> other) const -> opsy::utility::clear_set<rcc_apb1henr_r> {return opsy::utility::clear_set<rcc_apb1henr_r>(rcc_apb1henr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uart9en() const -> uart9en_f {return uart9en_f((value_ & uart9en_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12en() const -> uart12en_f {return uart12en_f((value_ & uart12en_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtsen() const -> dtsen_f {return dtsen_f((value_ & dtsen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2en() const -> lptim2en_f {return lptim2en_f((value_ & lptim2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan12en() const -> fdcan12en_f {return fdcan12en_f((value_ & fdcan12en_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpden() const -> ucpden_f {return ucpden_f((value_ & ucpden_f::mask) != 0);}

	constexpr rcc_apb1henr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1henr_r other) const -> rcc_apb1henr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1henr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB2 peripheral clock register 
 */
class rcc_apb2enr_r {
public:

/**
 * TIM1 clock enable Set and reset by software.
 */
class tim1en_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI1 clock enable Set and reset by software.
 */
class spi1en_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM8 clock enable Set and reset by software.
 */
class tim8en_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART1 clock enable Set and reset by software.
 */
class usart1en_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM15 clock enable Set and reset by software.
 */
class tim15en_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim15en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM16 clock enable Set and reset by software.
 */
class tim16en_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim16en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM17 clock enable Set and reset by software.
 */
class tim17en_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim17en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI4 clock enable Set and reset by software.
 */
class spi4en_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI6 clock enable Set and reset by software.
 */
class spi6en_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI1 clock enable Set and reset by software.
 */
class sai1en_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI2 clock enable Set and cleared by software.
 */
class sai2en_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USBFS clock enable Set and reset by software.
 */
class usbfsen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbfsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2enr_r>() const {return opsy::utility::clear_set<rcc_apb2enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return static_cast<rcc_apb2enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2enr_r> other) const -> opsy::utility::clear_set<rcc_apb2enr_r> {return opsy::utility::clear_set<rcc_apb2enr_r>(rcc_apb2enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim1en() const -> tim1en_f {return tim1en_f((value_ & tim1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1en() const -> spi1en_f {return spi1en_f((value_ & spi1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8en() const -> tim8en_f {return tim8en_f((value_ & tim8en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1en() const -> usart1en_f {return usart1en_f((value_ & usart1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15en() const -> tim15en_f {return tim15en_f((value_ & tim15en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16en() const -> tim16en_f {return tim16en_f((value_ & tim16en_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17en() const -> tim17en_f {return tim17en_f((value_ & tim17en_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4en() const -> spi4en_f {return spi4en_f((value_ & spi4en_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6en() const -> spi6en_f {return spi6en_f((value_ & spi6en_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1en() const -> sai1en_f {return sai1en_f((value_ & sai1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2en() const -> sai2en_f {return sai2en_f((value_ & sai2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbfsen() const -> usbfsen_f {return usbfsen_f((value_ & usbfsen_f::mask) != 0);}

	constexpr rcc_apb2enr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb2enr_r other) const -> rcc_apb2enr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb2enr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC APB4 peripheral clock register 
 */
class rcc_apb3enr_r {
public:

/**
 * SBS clock enable Set and reset by software.
 */
class sbsen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI5 clock enable Set and reset by software.
 */
class spi5en_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spi5en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART1 clock enable Set and reset by software.
 */
class lpuart1en_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpuart1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C3 clock enable Set and reset by software.
 */
class i2c3en_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr i2c3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C4 clock enable Set and reset by software.
 */
class i2c4en_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr i2c4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM1 clock enable Set and reset by software.
 */
class lptim1en_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM3 clock enable Set and reset by software.
 */
class lptim3en_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM4 clock enable Set and reset by software.
 */
class lptim4en_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM5 clock enable Set and reset by software.
 */
class lptim5en_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim5en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM6 clock enable Set and reset by software.
 */
class lptim6en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim6en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VREF clock enable Set and reset by software.
 */
class vrefen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vrefen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC APB interface clock enable Set and reset by software.
 */
class rtcapben_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtcapben_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3enr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3enr_r>() const {return opsy::utility::clear_set<rcc_apb3enr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return static_cast<rcc_apb3enr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3enr_r> other) const -> opsy::utility::clear_set<rcc_apb3enr_r> {return opsy::utility::clear_set<rcc_apb3enr_r>(rcc_apb3enr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbsen() const -> sbsen_f {return sbsen_f((value_ & sbsen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5en() const -> spi5en_f {return spi5en_f((value_ & spi5en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1en() const -> lpuart1en_f {return lpuart1en_f((value_ & lpuart1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3en() const -> i2c3en_f {return i2c3en_f((value_ & i2c3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4en() const -> i2c4en_f {return i2c4en_f((value_ & i2c4en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1en() const -> lptim1en_f {return lptim1en_f((value_ & lptim1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3en() const -> lptim3en_f {return lptim3en_f((value_ & lptim3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4en() const -> lptim4en_f {return lptim4en_f((value_ & lptim4en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5en() const -> lptim5en_f {return lptim5en_f((value_ & lptim5en_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim6en() const -> lptim6en_f {return lptim6en_f((value_ & lptim6en_f::mask) != 0);}
	[[nodiscard]] constexpr auto vrefen() const -> vrefen_f {return vrefen_f((value_ & vrefen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcapben() const -> rtcapben_f {return rtcapben_f((value_ & rtcapben_f::mask) != 0);}

	constexpr rcc_apb3enr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb3enr_r other) const -> rcc_apb3enr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb3enr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC AHB1 sleep clock register 
 */
class rcc_ahb1lpenr_r {
public:

/**
 * GPDMA1 clock enable during sleep mode Set and reset by software.
 */
class gpdma1lpen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPDMA2 clock enable during sleep mode Set and reset by software.
 */
class gpdma2lpen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpdma2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Flash interface (FLITF) clock enable during sleep mode Set and reset by software.
 */
class flitflpen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr flitflpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC clock enable during sleep mode Set and reset by software.
 */
class crclpen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CORDIC clock enable during sleep mode Set and reset by software.
 */
class cordiclpen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cordiclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMAC clock enable during sleep mode Set and reset by software.
 */
class fmaclpen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fmaclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RAMCFG clock enable during sleep mode Set and reset by software.
 */
class ramcfglpen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ramcfglpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETH clock enable during Sleep mode Set and reset by software
 */
class ethlpen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHTX clock enable during sleep mode Set and reset by software
 */
class ethtxlpen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethtxlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHRX clock enable during sleep mode Set and reset by software
 */
class ethrxlpen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethrxlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TZSC1 clock enable during sleep mode Set and reset by software
 */
class tzsc1lpen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tzsc1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BKPRAM clock enable during sleep mode Set and reset by software
 */
class bkpramlpen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkpramlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ICACHE clock enable during sleep mode Set and reset by software
 */
class icachelpen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr icachelpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DCACHE clock enable during sleep mode Set and reset by software
 */
class dcachelpen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcachelpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM1 clock enable during sleep mode Set and reset by software
 */
class sram1lpen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb1lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb1lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return static_cast<rcc_ahb1lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb1lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb1lpenr_r> {return opsy::utility::clear_set<rcc_ahb1lpenr_r>(rcc_ahb1lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpdma1lpen() const -> gpdma1lpen_f {return gpdma1lpen_f((value_ & gpdma1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpdma2lpen() const -> gpdma2lpen_f {return gpdma2lpen_f((value_ & gpdma2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto flitflpen() const -> flitflpen_f {return flitflpen_f((value_ & flitflpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto crclpen() const -> crclpen_f {return crclpen_f((value_ & crclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto cordiclpen() const -> cordiclpen_f {return cordiclpen_f((value_ & cordiclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmaclpen() const -> fmaclpen_f {return fmaclpen_f((value_ & fmaclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ramcfglpen() const -> ramcfglpen_f {return ramcfglpen_f((value_ & ramcfglpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethlpen() const -> ethlpen_f {return ethlpen_f((value_ & ethlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethtxlpen() const -> ethtxlpen_f {return ethtxlpen_f((value_ & ethtxlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethrxlpen() const -> ethrxlpen_f {return ethrxlpen_f((value_ & ethrxlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzsc1lpen() const -> tzsc1lpen_f {return tzsc1lpen_f((value_ & tzsc1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpramlpen() const -> bkpramlpen_f {return bkpramlpen_f((value_ & bkpramlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto icachelpen() const -> icachelpen_f {return icachelpen_f((value_ & icachelpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcachelpen() const -> dcachelpen_f {return dcachelpen_f((value_ & dcachelpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1lpen() const -> sram1lpen_f {return sram1lpen_f((value_ & sram1lpen_f::mask) != 0);}

	constexpr rcc_ahb1lpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb1lpenr_r other) const -> rcc_ahb1lpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb1lpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11110001001110101101000100000011; // 4047163651 0xF13AD103

private:
	uint32_t value_;
};

/**
 * RCC AHB2 sleep clock register 
 */
class rcc_ahb2lpenr_r {
public:

/**
 * GPIOA clock enable during sleep mode Set and reset by software.
 */
class gpioalpen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioalpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOB clock enable during sleep mode Set and reset by software.
 */
class gpioblpen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioblpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOC clock enable during sleep mode Set and reset by software.
 */
class gpioclpen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOD clock enable during sleep mode Set and reset by software.
 */
class gpiodlpen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiodlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOE clock enable during sleep mode Set and reset by software.
 */
class gpioelpen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioelpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOF clock enable during sleep mode Set and reset by software.
 */
class gpioflpen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioflpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOG clock enable during sleep mode Set and reset by software.
 */
class gpioglpen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpioglpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOH clock enable during sleep mode Set and reset by software.
 */
class gpiohlpen_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gpiohlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GPIOI clock enable during sleep mode Set and reset by software.
 */
class gpioilpen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr gpioilpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ADC1 and 2 peripherals clock enable during sleep mode Set and reset by software.
 */
class adc12lpen_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr adc12lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC clock enable during sleep mode Set and reset by software.
 */
class dac12lpen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dac12lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * digital camera interface clock enable during sleep mode (DCMI or PSSI depending which interface is active) Set and reset by software.
 */
class dcmi_pssilpen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcmi_pssilpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HASH clock enable during sleep mode Set and reset by software.
 */
class hashlpen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hashlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG clock enable during sleep mode Set and reset by software.
 */
class rnglpen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rnglpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 clock enable during sleep mode Set and reset by software.
 */
class sram2lpen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM3 clock enable during sleep mode Set and reset by software.
 */
class sram3lpen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb2lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return static_cast<rcc_ahb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb2lpenr_r> {return opsy::utility::clear_set<rcc_ahb2lpenr_r>(rcc_ahb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto gpioalpen() const -> gpioalpen_f {return gpioalpen_f((value_ & gpioalpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioblpen() const -> gpioblpen_f {return gpioblpen_f((value_ & gpioblpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioclpen() const -> gpioclpen_f {return gpioclpen_f((value_ & gpioclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiodlpen() const -> gpiodlpen_f {return gpiodlpen_f((value_ & gpiodlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioelpen() const -> gpioelpen_f {return gpioelpen_f((value_ & gpioelpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioflpen() const -> gpioflpen_f {return gpioflpen_f((value_ & gpioflpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioglpen() const -> gpioglpen_f {return gpioglpen_f((value_ & gpioglpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpiohlpen() const -> gpiohlpen_f {return gpiohlpen_f((value_ & gpiohlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpioilpen() const -> gpioilpen_f {return gpioilpen_f((value_ & gpioilpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto adc12lpen() const -> adc12lpen_f {return adc12lpen_f((value_ & adc12lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac12lpen() const -> dac12lpen_f {return dac12lpen_f((value_ & dac12lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcmi_pssilpen() const -> dcmi_pssilpen_f {return dcmi_pssilpen_f((value_ & dcmi_pssilpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashlpen() const -> hashlpen_f {return hashlpen_f((value_ & hashlpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rnglpen() const -> rnglpen_f {return rnglpen_f((value_ & rnglpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2lpen() const -> sram2lpen_f {return sram2lpen_f((value_ & sram2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3lpen() const -> sram3lpen_f {return sram3lpen_f((value_ & sram3lpen_f::mask) != 0);}

	constexpr rcc_ahb2lpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb2lpenr_r other) const -> rcc_ahb2lpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb2lpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000000111110001110111111111; // 3223264767 0xC01F1DFF

private:
	uint32_t value_;
};

/**
 * RCC AHB4 sleep clock register 
 */
class rcc_ahb4lpenr_r {
public:

/**
 * SDMMC1 and SDMMC1 delay peripheral clock enable during sleep mode Set and reset by software
 */
class sdmmc1lpen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4lpenr_r other) const -> rcc_ahb4lpenr_r { return static_cast<rcc_ahb4lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb4lpenr_r> {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(rcc_ahb4lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDMMC2 and SDMMC2 delay peripheral clock enable during sleep mode Set and reset by software.
 */
class sdmmc2lpen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdmmc2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4lpenr_r other) const -> rcc_ahb4lpenr_r { return static_cast<rcc_ahb4lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb4lpenr_r> {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(rcc_ahb4lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FMC clock enable during sleep mode Set and reset by software.
 */
class fmclpen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4lpenr_r other) const -> rcc_ahb4lpenr_r { return static_cast<rcc_ahb4lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb4lpenr_r> {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(rcc_ahb4lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OCTOSPI1 clock enable during sleep mode Set and reset by software.
 */
class octospi1lpen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr octospi1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ahb4lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ahb4lpenr_r>() const {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_ahb4lpenr_r other) const -> rcc_ahb4lpenr_r { return static_cast<rcc_ahb4lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ahb4lpenr_r> other) const -> opsy::utility::clear_set<rcc_ahb4lpenr_r> {return opsy::utility::clear_set<rcc_ahb4lpenr_r>(rcc_ahb4lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sdmmc1lpen() const -> sdmmc1lpen_f {return sdmmc1lpen_f((value_ & sdmmc1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2lpen() const -> sdmmc2lpen_f {return sdmmc2lpen_f((value_ & sdmmc2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmclpen() const -> fmclpen_f {return fmclpen_f((value_ & fmclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto octospi1lpen() const -> octospi1lpen_f {return octospi1lpen_f((value_ & octospi1lpen_f::mask) != 0);}

	constexpr rcc_ahb4lpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ahb4lpenr_r other) const -> rcc_ahb4lpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ahb4lpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100010001100010000000; // 1120384 0x111880

private:
	uint32_t value_;
};

/**
 * RCC APB1 sleep clock register 
 */
class rcc_apb1llpenr_r {
public:

/**
 * TIM2 clock enable during sleep mode Set and reset by software.
 */
class tim2lpen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM3 clock enable during sleep mode Set and reset by software.
 */
class tim3lpen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM4 clock enable during sleep mode Set and reset by software.
 */
class tim4lpen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim4lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM5 clock enable during sleep mode Set and reset by software.
 */
class tim5lpen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim5lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM6 clock enable during sleep mode Set and reset by software.
 */
class tim6lpen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim6lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM7 clock enable during sleep mode Set and reset by software.
 */
class tim7lpen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim7lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM12 clock enable during sleep mode Set and reset by software.
 */
class tim12lpen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim12lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM13 clock enable during sleep mode Set and reset by software.
 */
class tim13lpen_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tim13lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM14 clock enable during sleep mode Set and reset by software.
 */
class tim14lpen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim14lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WWDG clock enable during sleep mode Set and reset by software.
 */
class wwdglpen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wwdglpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI2 clock enable during sleep mode Set and reset by software.
 */
class spi2lpen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI3 clock enable during sleep mode Set and reset by software.
 */
class spi3lpen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART2 clock enable during sleep mode Set and reset by software.
 */
class usart2lpen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART3 clock enable during sleep mode Set and reset by software.
 */
class usart3lpen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART4 clock enable during sleep mode Set and reset by software.
 */
class uart4lpen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart4lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART5 clock enable during sleep mode Set and reset by software.
 */
class uart5lpen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart5lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C1 clock enable during sleep mode Set and reset by software.
 */
class i2c1lpen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C2 clock enable during sleep mode Set and reset by software.
 */
class i2c2lpen_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i2c2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I3C1 clock enable during sleep mode Set and reset by software.
 */
class i3c1lpen_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr i3c1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRS clock enable during sleep mode Set and reset by software.
 */
class crslpen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crslpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART6 clock enable during sleep mode Set and reset by software.
 */
class usart6lpen_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart6lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART10 clock enable during sleep mode Set and reset by software.
 */
class usart10lpen_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart10lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART11 clock enable during sleep mode Set and reset by software.
 */
class usart11lpen_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usart11lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HDMI-CEC clock enable during sleep mode Set and reset by software.
 */
class ceclpen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ceclpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART7 clock enable during sleep mode Set and reset by software.
 */
class uart7lpen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart7lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART8 clock enable during sleep mode Set and reset by software.
 */
class uart8lpen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uart8lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1llpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1llpenr_r>() const {return opsy::utility::clear_set<rcc_apb1llpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return static_cast<rcc_apb1llpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1llpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1llpenr_r> {return opsy::utility::clear_set<rcc_apb1llpenr_r>(rcc_apb1llpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim2lpen() const -> tim2lpen_f {return tim2lpen_f((value_ & tim2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim3lpen() const -> tim3lpen_f {return tim3lpen_f((value_ & tim3lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim4lpen() const -> tim4lpen_f {return tim4lpen_f((value_ & tim4lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim5lpen() const -> tim5lpen_f {return tim5lpen_f((value_ & tim5lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim6lpen() const -> tim6lpen_f {return tim6lpen_f((value_ & tim6lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim7lpen() const -> tim7lpen_f {return tim7lpen_f((value_ & tim7lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim12lpen() const -> tim12lpen_f {return tim12lpen_f((value_ & tim12lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim13lpen() const -> tim13lpen_f {return tim13lpen_f((value_ & tim13lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim14lpen() const -> tim14lpen_f {return tim14lpen_f((value_ & tim14lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdglpen() const -> wwdglpen_f {return wwdglpen_f((value_ & wwdglpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi2lpen() const -> spi2lpen_f {return spi2lpen_f((value_ & spi2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi3lpen() const -> spi3lpen_f {return spi3lpen_f((value_ & spi3lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart2lpen() const -> usart2lpen_f {return usart2lpen_f((value_ & usart2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart3lpen() const -> usart3lpen_f {return usart3lpen_f((value_ & usart3lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart4lpen() const -> uart4lpen_f {return uart4lpen_f((value_ & uart4lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart5lpen() const -> uart5lpen_f {return uart5lpen_f((value_ & uart5lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1lpen() const -> i2c1lpen_f {return i2c1lpen_f((value_ & i2c1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c2lpen() const -> i2c2lpen_f {return i2c2lpen_f((value_ & i2c2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto i3c1lpen() const -> i3c1lpen_f {return i3c1lpen_f((value_ & i3c1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto crslpen() const -> crslpen_f {return crslpen_f((value_ & crslpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart6lpen() const -> usart6lpen_f {return usart6lpen_f((value_ & usart6lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart10lpen() const -> usart10lpen_f {return usart10lpen_f((value_ & usart10lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart11lpen() const -> usart11lpen_f {return usart11lpen_f((value_ & usart11lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ceclpen() const -> ceclpen_f {return ceclpen_f((value_ & ceclpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart7lpen() const -> uart7lpen_f {return uart7lpen_f((value_ & uart7lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart8lpen() const -> uart8lpen_f {return uart8lpen_f((value_ & uart8lpen_f::mask) != 0);}

	constexpr rcc_apb1llpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1llpenr_r other) const -> rcc_apb1llpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1llpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11011111111111101100100111111111; // 3758017023 0xDFFEC9FF

private:
	uint32_t value_;
};

/**
 * RCC APB1 sleep clock register 
 */
class rcc_apb1hlpenr_r {
public:

/**
 * UART9 clock enable during sleep mode Set and reset by software.
 */
class uart9lpen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart9lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UART12 clock enable during sleep mode Set and reset by software.
 */
class uart12lpen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uart12lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DTS clock enable during sleep mode Set and reset by software.
 */
class dtslpen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtslpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM2 clock enable during sleep mode Set and reset by software.
 */
class lptim2lpen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lptim2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FDCAN1 and FDCAN2 peripheral clock enable during sleep mode Set and reset by software.
 */
class fdcan12lpen_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fdcan12lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UCPD clock enable during sleep mode Set and reset by software.
 */
class ucpdlpen_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ucpdlpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb1hlpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb1hlpenr_r>() const {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return static_cast<rcc_apb1hlpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb1hlpenr_r> other) const -> opsy::utility::clear_set<rcc_apb1hlpenr_r> {return opsy::utility::clear_set<rcc_apb1hlpenr_r>(rcc_apb1hlpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uart9lpen() const -> uart9lpen_f {return uart9lpen_f((value_ & uart9lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto uart12lpen() const -> uart12lpen_f {return uart12lpen_f((value_ & uart12lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtslpen() const -> dtslpen_f {return dtslpen_f((value_ & dtslpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim2lpen() const -> lptim2lpen_f {return lptim2lpen_f((value_ & lptim2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdcan12lpen() const -> fdcan12lpen_f {return fdcan12lpen_f((value_ & fdcan12lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpdlpen() const -> ucpdlpen_f {return ucpdlpen_f((value_ & ucpdlpen_f::mask) != 0);}

	constexpr rcc_apb1hlpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb1hlpenr_r other) const -> rcc_apb1hlpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb1hlpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000100000000000001000101011; // 1082130987 0x4080022B

private:
	uint32_t value_;
};

/**
 * RCC APB2 sleep clock register 
 */
class rcc_apb2lpenr_r {
public:

/**
 * TIM1 clock enable during sleep mode Set and reset by software.
 */
class tim1lpen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI1 clock enable during sleep mode Set and reset by software.
 */
class spi1lpen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr spi1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM8 clock enable during sleep mode Set and reset by software.
 */
class tim8lpen_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tim8lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART1 clock enable during sleep mode Set and reset by software.
 */
class usart1lpen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usart1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM15 clock enable during sleep mode Set and reset by software.
 */
class tim15lpen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim15lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM16 clock enable during sleep mode Set and reset by software.
 */
class tim16lpen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim16lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIM17 clock enable during sleep mode Set and reset by software.
 */
class tim17lpen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tim17lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI4 clock enable during sleep mode Set and reset by software.
 */
class spi4lpen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi4lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI6 clock enable during sleep mode Set and reset by software.
 */
class spi6lpen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spi6lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI1 clock enable during sleep mode Set and reset by software.
 */
class sai1lpen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAI2 clock enable during sleep mode Set and reset by software.
 */
class sai2lpen_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sai2lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USBFS clock enable during sleep mode Set and reset by software.
 */
class usbfslpen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usbfslpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb2lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb2lpenr_r>() const {return opsy::utility::clear_set<rcc_apb2lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return static_cast<rcc_apb2lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb2lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb2lpenr_r> {return opsy::utility::clear_set<rcc_apb2lpenr_r>(rcc_apb2lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tim1lpen() const -> tim1lpen_f {return tim1lpen_f((value_ & tim1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi1lpen() const -> spi1lpen_f {return spi1lpen_f((value_ & spi1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim8lpen() const -> tim8lpen_f {return tim8lpen_f((value_ & tim8lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usart1lpen() const -> usart1lpen_f {return usart1lpen_f((value_ & usart1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim15lpen() const -> tim15lpen_f {return tim15lpen_f((value_ & tim15lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim16lpen() const -> tim16lpen_f {return tim16lpen_f((value_ & tim16lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tim17lpen() const -> tim17lpen_f {return tim17lpen_f((value_ & tim17lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi4lpen() const -> spi4lpen_f {return spi4lpen_f((value_ & spi4lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi6lpen() const -> spi6lpen_f {return spi6lpen_f((value_ & spi6lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai1lpen() const -> sai1lpen_f {return sai1lpen_f((value_ & sai1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sai2lpen() const -> sai2lpen_f {return sai2lpen_f((value_ & sai2lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbfslpen() const -> usbfslpen_f {return usbfslpen_f((value_ & usbfslpen_f::mask) != 0);}

	constexpr rcc_apb2lpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb2lpenr_r other) const -> rcc_apb2lpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb2lpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1011111110111100000000000; // 25131008 0x17F7800

private:
	uint32_t value_;
};

/**
 * RCC APB4 sleep clock register 
 */
class rcc_apb3lpenr_r {
public:

/**
 * SBS clock enable during sleep mode Set and reset by software.
 */
class sbslpen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbslpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI5 clock enable during Slsleepeep mode Set and reset by software.
 */
class spi5lpen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spi5lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART1 clock enable during sleep mode Set and reset by software.
 */
class lpuart1lpen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpuart1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C3 clock enable during sleep mode Set and reset by software.
 */
class i2c3lpen_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr i2c3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C4 clock enable during sleep mode Set and reset by software.
 */
class i2c4lpen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr i2c4lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM1 clock enable during sleep mode Set and reset by software.
 */
class lptim1lpen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim1lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM3 clock enable during sleep mode Set and reset by software.
 */
class lptim3lpen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim3lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM4 clock enable during sleep mode Set and reset by software.
 */
class lptim4lpen_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim4lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM5 clock enable during sleep mode Set and reset by software.
 */
class lptim5lpen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim5lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM6 clock enable during sleep mode Set and reset by software.
 */
class lptim6lpen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lptim6lpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VREF clock enable during sleep mode Set and reset by software.
 */
class vreflpen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vreflpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC APB interface clock enable during sleep mode Set and reset by software.
 */
class rtcapblpen_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtcapblpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_apb3lpenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_apb3lpenr_r>() const {return opsy::utility::clear_set<rcc_apb3lpenr_r>(mask, *this);}
	constexpr auto operator|(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return static_cast<rcc_apb3lpenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_apb3lpenr_r> other) const -> opsy::utility::clear_set<rcc_apb3lpenr_r> {return opsy::utility::clear_set<rcc_apb3lpenr_r>(rcc_apb3lpenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbslpen() const -> sbslpen_f {return sbslpen_f((value_ & sbslpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto spi5lpen() const -> spi5lpen_f {return spi5lpen_f((value_ & spi5lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpuart1lpen() const -> lpuart1lpen_f {return lpuart1lpen_f((value_ & lpuart1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c3lpen() const -> i2c3lpen_f {return i2c3lpen_f((value_ & i2c3lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c4lpen() const -> i2c4lpen_f {return i2c4lpen_f((value_ & i2c4lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim1lpen() const -> lptim1lpen_f {return lptim1lpen_f((value_ & lptim1lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim3lpen() const -> lptim3lpen_f {return lptim3lpen_f((value_ & lptim3lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim4lpen() const -> lptim4lpen_f {return lptim4lpen_f((value_ & lptim4lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim5lpen() const -> lptim5lpen_f {return lptim5lpen_f((value_ & lptim5lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lptim6lpen() const -> lptim6lpen_f {return lptim6lpen_f((value_ & lptim6lpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto vreflpen() const -> vreflpen_f {return vreflpen_f((value_ & vreflpen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcapblpen() const -> rtcapblpen_f {return rtcapblpen_f((value_ & rtcapblpen_f::mask) != 0);}

	constexpr rcc_apb3lpenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_apb3lpenr_r other) const -> rcc_apb3lpenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_apb3lpenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1100001111100111100010; // 3209698 0x30F9E2

private:
	uint32_t value_;
};

/**
 * RCC kernel clock configuration register 
 */
class rcc_ccipr1_r {
public:

/**
 * USART1 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class usart1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr usart1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USART2 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class usart2sel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr usart2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USART3 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class usart3sel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr usart3sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UART4 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class uart4sel_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr uart4sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UART5 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class uart5sel_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr uart5sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USART6 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class usart6sel_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr usart6sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UART7 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class uart7sel_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr uart7sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UART8 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class uart8sel_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr uart8sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * UART9 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class uart9sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr uart9sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USART10 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class usart10sel_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr usart10sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * TIM12, TIM15 and LPTIM2 input capture source selection Set and reset by software.
 */
class timicsel_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr timicsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ccipr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ccipr1_r>() const {return opsy::utility::clear_set<rcc_ccipr1_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return static_cast<rcc_ccipr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr1_r> other) const -> opsy::utility::clear_set<rcc_ccipr1_r> {return opsy::utility::clear_set<rcc_ccipr1_r>(rcc_ccipr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto usart1sel() const -> usart1sel_f {return usart1sel_f(static_cast<uint8_t>(value_ >> usart1sel_f::offset));}
	[[nodiscard]] constexpr auto usart2sel() const -> usart2sel_f {return usart2sel_f(static_cast<uint8_t>(value_ >> usart2sel_f::offset));}
	[[nodiscard]] constexpr auto usart3sel() const -> usart3sel_f {return usart3sel_f(static_cast<uint8_t>(value_ >> usart3sel_f::offset));}
	[[nodiscard]] constexpr auto uart4sel() const -> uart4sel_f {return uart4sel_f(static_cast<uint8_t>(value_ >> uart4sel_f::offset));}
	[[nodiscard]] constexpr auto uart5sel() const -> uart5sel_f {return uart5sel_f(static_cast<uint8_t>(value_ >> uart5sel_f::offset));}
	[[nodiscard]] constexpr auto usart6sel() const -> usart6sel_f {return usart6sel_f(static_cast<uint8_t>(value_ >> usart6sel_f::offset));}
	[[nodiscard]] constexpr auto uart7sel() const -> uart7sel_f {return uart7sel_f(static_cast<uint8_t>(value_ >> uart7sel_f::offset));}
	[[nodiscard]] constexpr auto uart8sel() const -> uart8sel_f {return uart8sel_f(static_cast<uint8_t>(value_ >> uart8sel_f::offset));}
	[[nodiscard]] constexpr auto uart9sel() const -> uart9sel_f {return uart9sel_f(static_cast<uint8_t>(value_ >> uart9sel_f::offset));}
	[[nodiscard]] constexpr auto usart10sel() const -> usart10sel_f {return usart10sel_f(static_cast<uint8_t>(value_ >> usart10sel_f::offset));}
	[[nodiscard]] constexpr auto timicsel() const -> timicsel_f {return timicsel_f((value_ & timicsel_f::mask) != 0);}

	constexpr rcc_ccipr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ccipr1_r other) const -> rcc_ccipr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ccipr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC kernel clock configuration register 
 */
class rcc_ccipr2_r {
public:

/**
 * USART11 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class usart11sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr usart11sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USART12 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class usart12sel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr usart12sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM1 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim1sel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lptim1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM2 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim2sel_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lptim2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM3 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim3sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lptim3sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM4 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim4sel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lptim4sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM5 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim5sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lptim5sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM6 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lptim6sel_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lptim6sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr2_r>() const {return opsy::utility::clear_set<rcc_ccipr2_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return static_cast<rcc_ccipr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr2_r> other) const -> opsy::utility::clear_set<rcc_ccipr2_r> {return opsy::utility::clear_set<rcc_ccipr2_r>(rcc_ccipr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto usart11sel() const -> usart11sel_f {return usart11sel_f(static_cast<uint8_t>(value_ >> usart11sel_f::offset));}
	[[nodiscard]] constexpr auto usart12sel() const -> usart12sel_f {return usart12sel_f(static_cast<uint8_t>(value_ >> usart12sel_f::offset));}
	[[nodiscard]] constexpr auto lptim1sel() const -> lptim1sel_f {return lptim1sel_f(static_cast<uint8_t>(value_ >> lptim1sel_f::offset));}
	[[nodiscard]] constexpr auto lptim2sel() const -> lptim2sel_f {return lptim2sel_f(static_cast<uint8_t>(value_ >> lptim2sel_f::offset));}
	[[nodiscard]] constexpr auto lptim3sel() const -> lptim3sel_f {return lptim3sel_f(static_cast<uint8_t>(value_ >> lptim3sel_f::offset));}
	[[nodiscard]] constexpr auto lptim4sel() const -> lptim4sel_f {return lptim4sel_f(static_cast<uint8_t>(value_ >> lptim4sel_f::offset));}
	[[nodiscard]] constexpr auto lptim5sel() const -> lptim5sel_f {return lptim5sel_f(static_cast<uint8_t>(value_ >> lptim5sel_f::offset));}
	[[nodiscard]] constexpr auto lptim6sel() const -> lptim6sel_f {return lptim6sel_f(static_cast<uint8_t>(value_ >> lptim6sel_f::offset));}

	constexpr rcc_ccipr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ccipr2_r other) const -> rcc_ccipr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ccipr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC kernel clock configuration register 
 */
class rcc_ccipr3_r {
public:

/**
 * SPI1 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class spi1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr spi1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI2 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class spi2sel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr spi2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI3 kernel clock source selection Set and reset by software. others: reserved, the kernel clock is disabled
 */
class spi3sel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr spi3sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI4 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class spi4sel_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr spi4sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI5 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class spi5sel_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr spi5sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI6 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class spi6sel_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr spi6sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPUART1 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class lpuart1sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lpuart1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr3_r>() const {return opsy::utility::clear_set<rcc_ccipr3_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return static_cast<rcc_ccipr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr3_r> other) const -> opsy::utility::clear_set<rcc_ccipr3_r> {return opsy::utility::clear_set<rcc_ccipr3_r>(rcc_ccipr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto spi1sel() const -> spi1sel_f {return spi1sel_f(static_cast<uint8_t>(value_ >> spi1sel_f::offset));}
	[[nodiscard]] constexpr auto spi2sel() const -> spi2sel_f {return spi2sel_f(static_cast<uint8_t>(value_ >> spi2sel_f::offset));}
	[[nodiscard]] constexpr auto spi3sel() const -> spi3sel_f {return spi3sel_f(static_cast<uint8_t>(value_ >> spi3sel_f::offset));}
	[[nodiscard]] constexpr auto spi4sel() const -> spi4sel_f {return spi4sel_f(static_cast<uint8_t>(value_ >> spi4sel_f::offset));}
	[[nodiscard]] constexpr auto spi5sel() const -> spi5sel_f {return spi5sel_f(static_cast<uint8_t>(value_ >> spi5sel_f::offset));}
	[[nodiscard]] constexpr auto spi6sel() const -> spi6sel_f {return spi6sel_f(static_cast<uint8_t>(value_ >> spi6sel_f::offset));}
	[[nodiscard]] constexpr auto lpuart1sel() const -> lpuart1sel_f {return lpuart1sel_f(static_cast<uint8_t>(value_ >> lpuart1sel_f::offset));}

	constexpr rcc_ccipr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ccipr3_r other) const -> rcc_ccipr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ccipr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC kernel clock configuration register 
 */
class rcc_ccipr4_r {
public:

/**
 * OCTOSPI1 kernel clock source selection Set and reset by software.
 */
class octospi1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr octospi1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYSTICK clock source selection Note: rcc_hclk frequency must be four times higher than lsi_ker_ck/lse_ck (period (LSI/LSE) greater than or equal 4 * period (HCLK).
 */
class systicksel_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr systicksel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * USBFS kernel clock source selection
 */
class usbfssel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr usbfssel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SDMMC1 kernel clock source selection
 */
class sdmmc1sel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sdmmc1sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDMMC2 kernel clock source selection
 */
class sdmmc2sel_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sdmmc2sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2C1 kernel clock source selection
 */
class i2c1sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i2c1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * I2C2 kernel clock source selection
 */
class i2c2sel_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i2c2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * I2C3 kernel clock source selection
 */
class i2c3sel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i2c3sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * I2C4 kernel clock source selection
 */
class i2c4sel_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i2c4sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * I3C1 kernel clock source selection
 */
class i3c1sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i3c1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr4_r>() const {return opsy::utility::clear_set<rcc_ccipr4_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return static_cast<rcc_ccipr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr4_r> other) const -> opsy::utility::clear_set<rcc_ccipr4_r> {return opsy::utility::clear_set<rcc_ccipr4_r>(rcc_ccipr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto octospi1sel() const -> octospi1sel_f {return octospi1sel_f(static_cast<uint8_t>(value_ >> octospi1sel_f::offset));}
	[[nodiscard]] constexpr auto systicksel() const -> systicksel_f {return systicksel_f(static_cast<uint8_t>(value_ >> systicksel_f::offset));}
	[[nodiscard]] constexpr auto usbfssel() const -> usbfssel_f {return usbfssel_f(static_cast<uint8_t>(value_ >> usbfssel_f::offset));}
	[[nodiscard]] constexpr auto sdmmc1sel() const -> sdmmc1sel_f {return sdmmc1sel_f((value_ & sdmmc1sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmmc2sel() const -> sdmmc2sel_f {return sdmmc2sel_f((value_ & sdmmc2sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2c1sel() const -> i2c1sel_f {return i2c1sel_f(static_cast<uint8_t>(value_ >> i2c1sel_f::offset));}
	[[nodiscard]] constexpr auto i2c2sel() const -> i2c2sel_f {return i2c2sel_f(static_cast<uint8_t>(value_ >> i2c2sel_f::offset));}
	[[nodiscard]] constexpr auto i2c3sel() const -> i2c3sel_f {return i2c3sel_f(static_cast<uint8_t>(value_ >> i2c3sel_f::offset));}
	[[nodiscard]] constexpr auto i2c4sel() const -> i2c4sel_f {return i2c4sel_f(static_cast<uint8_t>(value_ >> i2c4sel_f::offset));}
	[[nodiscard]] constexpr auto i3c1sel() const -> i3c1sel_f {return i3c1sel_f(static_cast<uint8_t>(value_ >> i3c1sel_f::offset));}

	constexpr rcc_ccipr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ccipr4_r other) const -> rcc_ccipr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ccipr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC kernel clock configuration register 
 */
class rcc_ccipr5_r {
public:

/**
 * ADC and DAC kernel clock source selection others: reserved, the kernel clock is disabled
 */
class adcdacsel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr adcdacsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC hold clock
 */
class dacsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dacsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RNG kernel clock source selection
 */
class rngsel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rngsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HSMI-CEC kernel clock source selection
 */
class cecsel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cecsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FDCAN1 and FDCAN2 kernel clock source selection
 */
class fdcan12sel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fdcan12sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SAI1 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class sai1sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sai1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SAI2 kernel clock source selection others: reserved, the kernel clock is disabled
 */
class sai2sel_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sai2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * per_ck clock source selection
 */
class ckpersel_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ckpersel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_ccipr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_ccipr5_r>() const {return opsy::utility::clear_set<rcc_ccipr5_r>(mask, *this);}
	constexpr auto operator|(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return static_cast<rcc_ccipr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_ccipr5_r> other) const -> opsy::utility::clear_set<rcc_ccipr5_r> {return opsy::utility::clear_set<rcc_ccipr5_r>(rcc_ccipr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto adcdacsel() const -> adcdacsel_f {return adcdacsel_f(static_cast<uint8_t>(value_ >> adcdacsel_f::offset));}
	[[nodiscard]] constexpr auto dacsel() const -> dacsel_f {return dacsel_f((value_ & dacsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto rngsel() const -> rngsel_f {return rngsel_f(static_cast<uint8_t>(value_ >> rngsel_f::offset));}
	[[nodiscard]] constexpr auto cecsel() const -> cecsel_f {return cecsel_f(static_cast<uint8_t>(value_ >> cecsel_f::offset));}
	[[nodiscard]] constexpr auto fdcan12sel() const -> fdcan12sel_f {return fdcan12sel_f(static_cast<uint8_t>(value_ >> fdcan12sel_f::offset));}
	[[nodiscard]] constexpr auto sai1sel() const -> sai1sel_f {return sai1sel_f(static_cast<uint8_t>(value_ >> sai1sel_f::offset));}
	[[nodiscard]] constexpr auto sai2sel() const -> sai2sel_f {return sai2sel_f(static_cast<uint8_t>(value_ >> sai2sel_f::offset));}
	[[nodiscard]] constexpr auto ckpersel() const -> ckpersel_f {return ckpersel_f(static_cast<uint8_t>(value_ >> ckpersel_f::offset));}

	constexpr rcc_ccipr5_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_ccipr5_r other) const -> rcc_ccipr5_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_ccipr5_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC Backup domain control register 
 */
class rcc_bdcr_r {
public:

/**
 * LSE oscillator enabled Set and reset by software.
 */
class lseon_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lseon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE oscillator ready Set and reset by hardware to indicate when the LSE is stable. This bit needs 6 cycles of lse_ck clock to fall down after LSEON has been set to 0.
 */
class lserdy_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lserdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE oscillator bypass Set and reset by software to bypass oscillator in debug mode. This bit must not be written when the LSE is enabled (by LSEON) or ready (LSERDY = 1)
 */
class lsebyp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsebyp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE oscillator driving capability Set by software to select the driving capability of the LSE oscillator. These bit can be written only if LSE oscillator is disabled (LSEON = 0 and LSERDY = 0).
 */
class lsedrv_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr lsedrv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LSE clock security system enable Set by software to enable the clock security system on 32 kHz oscillator. LSECSSON must be enabled after LSE is enabled (LSEON enabled) and ready (LSERDY set by hardware) and after RTCSEL is selected. Once enabled, this bit cannot be disabled, except after a LSE failure detection (LSECSSD = 1). In that case the software must disable LSECSSON.
 */
class lsecsson_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsecsson_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE clock security system failure detection Set by hardware to indicate when a failure has been detected by the clock security system on the external 32 kHz oscillator.
 */
class lsecssd_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsecssd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * low-speed external clock type in bypass mode Set and reset by software to select the external clock type (analog or digital). The external clock must be enabled with the LSEON bit, to be used by the device. The LSEEXT bit can be written only if the LSE oscillator is disabled.
 */
class lseext_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lseext_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC clock source selection Set by software to select the clock source for the RTC. These bits can be written only one time (except in case of failure detection on LSE). These bits must be written before LSECSSON is enabled. The VSWRST bit can be used to reset them, then it can be written one time again. If HSE is selected as RTC clock, this clock is lost when the system is in Stop mode or in case of a pin reset (NRST).
 */
class rtcsel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rtcsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RTC clock enable Set and reset by software.
 */
class rtcen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VSwitch domain software reset Set and reset by software.
 */
class vswrst_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vswrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low-speed clock output (LSCO) enable Set and cleared by software.
 */
class lscoen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lscoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low-speed clock output selection Set and cleared by software.
 */
class lscosel_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lscosel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSI oscillator enable Set and cleared by software.
 */
class lsion_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lsion_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSI oscillator ready Set and cleared by hardware to indicate when the LSI oscillator is stable. After the LSION bit is cleared, LSIRDY goes low after three internal low-speed oscillator clock cycles. This bit is set when the LSI is used by IWDG or RTC, even if LSION = 0.
 */
class lsirdy_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lsirdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_bdcr_r>() const {return opsy::utility::clear_set<rcc_bdcr_r>(mask, *this);}
	constexpr auto operator|(rcc_bdcr_r other) const -> rcc_bdcr_r { return static_cast<rcc_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_bdcr_r> other) const -> opsy::utility::clear_set<rcc_bdcr_r> {return opsy::utility::clear_set<rcc_bdcr_r>(rcc_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lseon() const -> lseon_f {return lseon_f((value_ & lseon_f::mask) != 0);}
	[[nodiscard]] constexpr auto lserdy() const -> lserdy_f {return lserdy_f((value_ & lserdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsebyp() const -> lsebyp_f {return lsebyp_f((value_ & lsebyp_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsedrv() const -> lsedrv_f {return lsedrv_f(static_cast<uint8_t>(value_ >> lsedrv_f::offset));}
	[[nodiscard]] constexpr auto lsecsson() const -> lsecsson_f {return lsecsson_f((value_ & lsecsson_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsecssd() const -> lsecssd_f {return lsecssd_f((value_ & lsecssd_f::mask) != 0);}
	[[nodiscard]] constexpr auto lseext() const -> lseext_f {return lseext_f((value_ & lseext_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtcsel() const -> rtcsel_f {return rtcsel_f(static_cast<uint8_t>(value_ >> rtcsel_f::offset));}
	[[nodiscard]] constexpr auto rtcen() const -> rtcen_f {return rtcen_f((value_ & rtcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto vswrst() const -> vswrst_f {return vswrst_f((value_ & vswrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto lscoen() const -> lscoen_f {return lscoen_f((value_ & lscoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lscosel() const -> lscosel_f {return lscosel_f((value_ & lscosel_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsion() const -> lsion_f {return lsion_f((value_ & lsion_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsirdy() const -> lsirdy_f {return lsirdy_f((value_ & lsirdy_f::mask) != 0);}

	constexpr rcc_bdcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_bdcr_r other) const -> rcc_bdcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_bdcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC reset status register 
 */
class rcc_rsr_r {
public:

/**
 * remove reset flag Set and reset by software to reset the value of the reset flags.
 */
class rmvf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rmvf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * pin reset flag (NRST) Reset by software by writing the RMVF bit. Set by hardware when a reset from pin occurs.
 */
class pinrstf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pinrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BOR reset flag Reset by software by writing the RMVF bit. Set by hardware when a BOR reset occurs (pwr_bor_rst).
 */
class borrstf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr borrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * system reset from CPU reset flag Reset by software by writing the RMVF bit. Set by hardware when the system reset is due to CPU.The CPU can generate a system reset by writing SYSRESETREQ bit of AIRCR register of the core M33.
 */
class sftrstf_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sftrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * independent watchdog reset flag Reset by software by writing the RMVF bit. Set by hardware when an independent watchdog reset occurs.
 */
class iwdgrstf_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iwdgrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * window watchdog reset flag Reset by software by writing the RMVF bit. Set by hardware when a window watchdog reset occurs.
 */
class wwdgrstf_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wwdgrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low-power reset flag Set by hardware when a reset occurs due to Stop or Standby mode entry, whereas the corresponding nRST_STOP, nRST_STBY option bit is cleared. Cleared by writing to the RMVF bit.
 */
class lpwrrstf_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpwrrstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_rsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_rsr_r>() const {return opsy::utility::clear_set<rcc_rsr_r>(mask, *this);}
	constexpr auto operator|(rcc_rsr_r other) const -> rcc_rsr_r { return static_cast<rcc_rsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_rsr_r> other) const -> opsy::utility::clear_set<rcc_rsr_r> {return opsy::utility::clear_set<rcc_rsr_r>(rcc_rsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rmvf() const -> rmvf_f {return rmvf_f((value_ & rmvf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pinrstf() const -> pinrstf_f {return pinrstf_f((value_ & pinrstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto borrstf() const -> borrstf_f {return borrstf_f((value_ & borrstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sftrstf() const -> sftrstf_f {return sftrstf_f((value_ & sftrstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdgrstf() const -> iwdgrstf_f {return iwdgrstf_f((value_ & iwdgrstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdgrstf() const -> wwdgrstf_f {return wwdgrstf_f((value_ & wwdgrstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpwrrstf() const -> lpwrrstf_f {return lpwrrstf_f((value_ & lpwrrstf_f::mask) != 0);}

	constexpr rcc_rsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_rsr_r other) const -> rcc_rsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_rsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1100000000000000000000000000; // 201326592 0xC000000

private:
	uint32_t value_;
};

/**
 * RCC secure configuration register 
 */
class rcc_seccfgr_r {
public:

/**
 * HSI clock configuration and status bits security Set and reset by software.
 */
class hsisec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsisec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSE clock configuration bits, status bits and HSE_CSS security Set and reset by software.
 */
class hsesec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsesec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSI clock configuration and status bits security Set and reset by software.
 */
class csisec_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csisec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSI clock configuration and status bits security Set and reset by software.
 */
class lsisec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsisec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LSE clock configuration and status bits security Set and reset by software.
 */
class lsesec_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lsesec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYSCLK clock selection, STOPWUCK bit, clock output on MCO configuration security Set and reset by software.
 */
class sysclksec_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sysclksec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHBx/APBx prescaler configuration bits security Set and reset by software.
 */
class prescsec_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr prescsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL1 clock configuration and status bits security Set and reset by software.
 */
class pll1sec_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pll1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL2 clock configuration and status bits security Set and reset by software.
 */
class pll2sec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pll2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PLL3 clock configuration and status bits security Set and reset by software.
 */
class pll3sec_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pll3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 clock configuration and status bits security Set and reset by software.
 */
class hsi48sec_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hsi48sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Remove reset flag security Set and reset by software.
 */
class rmvfsec_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rmvfsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * per_ck selection security Set and reset by software.
 */
class ckperselsec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ckperselsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_seccfgr_r>() const {return opsy::utility::clear_set<rcc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return static_cast<rcc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_seccfgr_r> other) const -> opsy::utility::clear_set<rcc_seccfgr_r> {return opsy::utility::clear_set<rcc_seccfgr_r>(rcc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hsisec() const -> hsisec_f {return hsisec_f((value_ & hsisec_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsesec() const -> hsesec_f {return hsesec_f((value_ & hsesec_f::mask) != 0);}
	[[nodiscard]] constexpr auto csisec() const -> csisec_f {return csisec_f((value_ & csisec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsisec() const -> lsisec_f {return lsisec_f((value_ & lsisec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsesec() const -> lsesec_f {return lsesec_f((value_ & lsesec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sysclksec() const -> sysclksec_f {return sysclksec_f((value_ & sysclksec_f::mask) != 0);}
	[[nodiscard]] constexpr auto prescsec() const -> prescsec_f {return prescsec_f((value_ & prescsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll1sec() const -> pll1sec_f {return pll1sec_f((value_ & pll1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll2sec() const -> pll2sec_f {return pll2sec_f((value_ & pll2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto pll3sec() const -> pll3sec_f {return pll3sec_f((value_ & pll3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsi48sec() const -> hsi48sec_f {return hsi48sec_f((value_ & hsi48sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto rmvfsec() const -> rmvfsec_f {return rmvfsec_f((value_ & rmvfsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckperselsec() const -> ckperselsec_f {return ckperselsec_f((value_ & ckperselsec_f::mask) != 0);}

	constexpr rcc_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_seccfgr_r other) const -> rcc_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RCC privilege configuration register 
 */
class rcc_privcfgr_r {
public:

/**
 * RCC secure functions privilege configuration Set and reset by software. This bit can be written only by a secure privileged access.
 */
class spriv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_privcfgr_r>() const {return opsy::utility::clear_set<rcc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_privcfgr_r other) const -> rcc_privcfgr_r { return static_cast<rcc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_privcfgr_r> other) const -> opsy::utility::clear_set<rcc_privcfgr_r> {return opsy::utility::clear_set<rcc_privcfgr_r>(rcc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RCC non-secure functions privilege configuration Set and reset by software. This bit can be written only by privileged access, secure or non-secure.
 */
class nspriv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rcc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rcc_privcfgr_r>() const {return opsy::utility::clear_set<rcc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rcc_privcfgr_r other) const -> rcc_privcfgr_r { return static_cast<rcc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rcc_privcfgr_r> other) const -> opsy::utility::clear_set<rcc_privcfgr_r> {return opsy::utility::clear_set<rcc_privcfgr_r>(rcc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto spriv() const -> spriv_f {return spriv_f((value_ & spriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto nspriv() const -> nspriv_f {return nspriv_f((value_ & nspriv_f::mask) != 0);}

	constexpr rcc_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rcc_privcfgr_r other) const -> rcc_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rcc_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,rcc_cr_r> rcc_cr;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,rcc_hsicfgr_r> rcc_hsicfgr;
	opsy::utility::memory<uint32_t,rcc_crrcr_r> rcc_crrcr;
	opsy::utility::memory<uint32_t,rcc_csicfgr_r> rcc_csicfgr;
	opsy::utility::memory<uint32_t,rcc_cfgr1_r> rcc_cfgr1;
	opsy::utility::memory<uint32_t,rcc_cfgr2_r> rcc_cfgr2;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,rcc_pll1cfgr_r> rcc_pll1cfgr;
	opsy::utility::memory<uint32_t,rcc_pll2cfgr_r> rcc_pll2cfgr;
	opsy::utility::memory<uint32_t,rcc_pll3cfgr_r> rcc_pll3cfgr;
	opsy::utility::memory<uint32_t,rcc_pll1divr_r> rcc_pll1divr;
	opsy::utility::memory<uint32_t,rcc_pll1fracr_r> rcc_pll1fracr;
	opsy::utility::memory<uint32_t,rcc_pll2divr_r> rcc_pll2divr;
	opsy::utility::memory<uint32_t,rcc_pll2fracr_r> rcc_pll2fracr;
	opsy::utility::memory<uint32_t,rcc_pll3divr_r> rcc_pll3divr;
	opsy::utility::memory<uint32_t,rcc_pll3fracr_r> rcc_pll3fracr;
	opsy::utility::padding<4> _p2;
	opsy::utility::memory<uint32_t,rcc_cier_r> rcc_cier;
	opsy::utility::memory<uint32_t,rcc_cifr_r> rcc_cifr;
	opsy::utility::memory<uint32_t,rcc_cicr_r> rcc_cicr;
	opsy::utility::padding<4> _p3;
	opsy::utility::memory<uint32_t,rcc_ahb1rstr_r> rcc_ahb1rstr;
	opsy::utility::memory<uint32_t,rcc_ahb2rstr_r> rcc_ahb2rstr;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,rcc_ahb4rstr_r> rcc_ahb4rstr;
	opsy::utility::padding<4> _p5;
	opsy::utility::memory<uint32_t,rcc_apb1lrstr_r> rcc_apb1lrstr;
	opsy::utility::memory<uint32_t,rcc_apb1hrstr_r> rcc_apb1hrstr;
	opsy::utility::memory<uint32_t,rcc_apb2rstr_r> rcc_apb2rstr;
	opsy::utility::memory<uint32_t,rcc_apb3rstr_r> rcc_apb3rstr;
	opsy::utility::padding<4> _p6;
	opsy::utility::memory<uint32_t,rcc_ahb1enr_r> rcc_ahb1enr;
	opsy::utility::memory<uint32_t,rcc_ahb2enr_r> rcc_ahb2enr;
	opsy::utility::padding<4> _p7;
	opsy::utility::memory<uint32_t,rcc_ahb4enr_r> rcc_ahb4enr;
	opsy::utility::padding<4> _p8;
	opsy::utility::memory<uint32_t,rcc_apb1lenr_r> rcc_apb1lenr;
	opsy::utility::memory<uint32_t,rcc_apb1henr_r> rcc_apb1henr;
	opsy::utility::memory<uint32_t,rcc_apb2enr_r> rcc_apb2enr;
	opsy::utility::memory<uint32_t,rcc_apb3enr_r> rcc_apb3enr;
	opsy::utility::padding<4> _p9;
	opsy::utility::memory<uint32_t,rcc_ahb1lpenr_r> rcc_ahb1lpenr;
	opsy::utility::memory<uint32_t,rcc_ahb2lpenr_r> rcc_ahb2lpenr;
	opsy::utility::padding<4> _p10;
	opsy::utility::memory<uint32_t,rcc_ahb4lpenr_r> rcc_ahb4lpenr;
	opsy::utility::padding<4> _p11;
	opsy::utility::memory<uint32_t,rcc_apb1llpenr_r> rcc_apb1llpenr;
	opsy::utility::memory<uint32_t,rcc_apb1hlpenr_r> rcc_apb1hlpenr;
	opsy::utility::memory<uint32_t,rcc_apb2lpenr_r> rcc_apb2lpenr;
	opsy::utility::memory<uint32_t,rcc_apb3lpenr_r> rcc_apb3lpenr;
	opsy::utility::padding<4> _p12;
	opsy::utility::memory<uint32_t,rcc_ccipr1_r> rcc_ccipr1;
	opsy::utility::memory<uint32_t,rcc_ccipr2_r> rcc_ccipr2;
	opsy::utility::memory<uint32_t,rcc_ccipr3_r> rcc_ccipr3;
	opsy::utility::memory<uint32_t,rcc_ccipr4_r> rcc_ccipr4;
	opsy::utility::memory<uint32_t,rcc_ccipr5_r> rcc_ccipr5;
	opsy::utility::padding<4> _p13;
	opsy::utility::memory<uint32_t,rcc_bdcr_r> rcc_bdcr;
	opsy::utility::memory<uint32_t,rcc_rsr_r> rcc_rsr;
	opsy::utility::padding<24> _p14;
	opsy::utility::memory<uint32_t,rcc_seccfgr_r> rcc_seccfgr;
	opsy::utility::memory<uint32_t,rcc_privcfgr_r> rcc_privcfgr;
};

static_assert(std::is_standard_layout_v<rcc_p>);
static_assert(offsetof(rcc_p, rcc_cr) == 0);
static_assert(offsetof(rcc_p, rcc_hsicfgr) == 16);
static_assert(offsetof(rcc_p, rcc_crrcr) == 20);
static_assert(offsetof(rcc_p, rcc_csicfgr) == 24);
static_assert(offsetof(rcc_p, rcc_cfgr1) == 28);
static_assert(offsetof(rcc_p, rcc_cfgr2) == 32);
static_assert(offsetof(rcc_p, rcc_pll1cfgr) == 40);
static_assert(offsetof(rcc_p, rcc_pll2cfgr) == 44);
static_assert(offsetof(rcc_p, rcc_pll3cfgr) == 48);
static_assert(offsetof(rcc_p, rcc_pll1divr) == 52);
static_assert(offsetof(rcc_p, rcc_pll1fracr) == 56);
static_assert(offsetof(rcc_p, rcc_pll2divr) == 60);
static_assert(offsetof(rcc_p, rcc_pll2fracr) == 64);
static_assert(offsetof(rcc_p, rcc_pll3divr) == 68);
static_assert(offsetof(rcc_p, rcc_pll3fracr) == 72);
static_assert(offsetof(rcc_p, rcc_cier) == 80);
static_assert(offsetof(rcc_p, rcc_cifr) == 84);
static_assert(offsetof(rcc_p, rcc_cicr) == 88);
static_assert(offsetof(rcc_p, rcc_ahb1rstr) == 96);
static_assert(offsetof(rcc_p, rcc_ahb2rstr) == 100);
static_assert(offsetof(rcc_p, rcc_ahb4rstr) == 108);
static_assert(offsetof(rcc_p, rcc_apb1lrstr) == 116);
static_assert(offsetof(rcc_p, rcc_apb1hrstr) == 120);
static_assert(offsetof(rcc_p, rcc_apb2rstr) == 124);
static_assert(offsetof(rcc_p, rcc_apb3rstr) == 128);
static_assert(offsetof(rcc_p, rcc_ahb1enr) == 136);
static_assert(offsetof(rcc_p, rcc_ahb2enr) == 140);
static_assert(offsetof(rcc_p, rcc_ahb4enr) == 148);
static_assert(offsetof(rcc_p, rcc_apb1lenr) == 156);
static_assert(offsetof(rcc_p, rcc_apb1henr) == 160);
static_assert(offsetof(rcc_p, rcc_apb2enr) == 164);
static_assert(offsetof(rcc_p, rcc_apb3enr) == 168);
static_assert(offsetof(rcc_p, rcc_ahb1lpenr) == 176);
static_assert(offsetof(rcc_p, rcc_ahb2lpenr) == 180);
static_assert(offsetof(rcc_p, rcc_ahb4lpenr) == 188);
static_assert(offsetof(rcc_p, rcc_apb1llpenr) == 196);
static_assert(offsetof(rcc_p, rcc_apb1hlpenr) == 200);
static_assert(offsetof(rcc_p, rcc_apb2lpenr) == 204);
static_assert(offsetof(rcc_p, rcc_apb3lpenr) == 208);
static_assert(offsetof(rcc_p, rcc_ccipr1) == 216);
static_assert(offsetof(rcc_p, rcc_ccipr2) == 220);
static_assert(offsetof(rcc_p, rcc_ccipr3) == 224);
static_assert(offsetof(rcc_p, rcc_ccipr4) == 228);
static_assert(offsetof(rcc_p, rcc_ccipr5) == 232);
static_assert(offsetof(rcc_p, rcc_bdcr) == 240);
static_assert(offsetof(rcc_p, rcc_rsr) == 244);
static_assert(offsetof(rcc_p, rcc_seccfgr) == 272);
static_assert(offsetof(rcc_p, rcc_privcfgr) == 276);

inline rcc_p& rcc = *reinterpret_cast<rcc_p*>(0x44020C00);
inline rcc_p& sec_rcc = *reinterpret_cast<rcc_p*>(0x54020C00);

} // STM32H563

