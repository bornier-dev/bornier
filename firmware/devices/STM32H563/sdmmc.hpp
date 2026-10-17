#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Secure digital input/output MultiMediaCard interface
 */
class sdmmc_p {
public:

/**
 * SDMMC_POWER
 */
class sdmmc_power_r {
public:

/**
 * SDMMC state control bits These bits can only be written when the SDMMC is not in the power-on state (PWRCTRL different 11). These bits are used to define the functional state of the SDMMC signals: stopped, SDMMC_D[7:0], SDMMC_CMD and SDMMC_CK are driven high. Any further write is ignored, PWRCTRL value keeps 11.
 */
class pwrctrl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pwrctrl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_power_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_power_r>() const {return opsy::utility::clear_set<sdmmc_power_r>(mask, *this);}
	constexpr auto operator|(sdmmc_power_r other) const -> sdmmc_power_r { return static_cast<sdmmc_power_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_power_r> other) const -> opsy::utility::clear_set<sdmmc_power_r> {return opsy::utility::clear_set<sdmmc_power_r>(sdmmc_power_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Voltage switch sequence start This bit is used to start the timing critical section of the voltage switch sequence:
 */
class vswitch_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vswitch_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_power_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_power_r>() const {return opsy::utility::clear_set<sdmmc_power_r>(mask, *this);}
	constexpr auto operator|(sdmmc_power_r other) const -> sdmmc_power_r { return static_cast<sdmmc_power_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_power_r> other) const -> opsy::utility::clear_set<sdmmc_power_r> {return opsy::utility::clear_set<sdmmc_power_r>(sdmmc_power_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Voltage switch procedure enable This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). This bit is used to stop the SDMMC_CK after the voltage switch command response:
 */
class vswitchen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vswitchen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_power_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_power_r>() const {return opsy::utility::clear_set<sdmmc_power_r>(mask, *this);}
	constexpr auto operator|(sdmmc_power_r other) const -> sdmmc_power_r { return static_cast<sdmmc_power_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_power_r> other) const -> opsy::utility::clear_set<sdmmc_power_r> {return opsy::utility::clear_set<sdmmc_power_r>(sdmmc_power_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data and command direction signals polarity selection This bit can only be written when the SDMMC is in the power-off state (PWRCTRL = 00).
 */
class dirpol_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dirpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_power_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_power_r>() const {return opsy::utility::clear_set<sdmmc_power_r>(mask, *this);}
	constexpr auto operator|(sdmmc_power_r other) const -> sdmmc_power_r { return static_cast<sdmmc_power_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_power_r> other) const -> opsy::utility::clear_set<sdmmc_power_r> {return opsy::utility::clear_set<sdmmc_power_r>(sdmmc_power_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pwrctrl() const -> pwrctrl_f {return pwrctrl_f(static_cast<uint8_t>(value_ >> pwrctrl_f::offset));}
	[[nodiscard]] constexpr auto vswitch() const -> vswitch_f {return vswitch_f((value_ & vswitch_f::mask) != 0);}
	[[nodiscard]] constexpr auto vswitchen() const -> vswitchen_f {return vswitchen_f((value_ & vswitchen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dirpol() const -> dirpol_f {return dirpol_f((value_ & dirpol_f::mask) != 0);}

	constexpr sdmmc_power_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_power_r other) const -> sdmmc_power_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_power_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC clock control register 
 */
class sdmmc_clkcr_r {
public:

/**
 * Clock divide factor This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0). This field defines the divide factor between the input clock (sdmmc_ker_ck) and the output clock (SDMMC_CK): SDMMC_CK frequency = sdmmc_ker_ck / [2 * CLKDIV]. 0x0XX: etc.. 0xXXX: etc..
 */
class clkdiv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr clkdiv_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Power saving configuration bit This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0) For power saving, the SDMMC_CK clock output can be disabled when the bus is idle by setting PWRSAV:
 */
class pwrsav_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pwrsav_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wide bus mode enable bit This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0)
 */
class widbus_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr widbus_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SDMMC_CK dephasing selection bit for data and command This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0). When clock division = 1 (CLKDIV = 0), this bit has no effect. Data and Command change on SDMMC_CK falling edge. Command and data changed on the sdmmc_ker_ck falling edge succeeding the rising edge of SDMMC_CK. SDMMC_CK edge occurs on sdmmc_ker_ck rising edge. When clock division 1 (CLKDIV 0) & DDR = 1: Command changed on the sdmmc_ker_ck falling edge succeeding the rising edge of SDMMC_CK. Data changed on the sdmmc_ker_ck falling edge succeeding a SDMMC_CK edge. SDMMC_CK edge occurs on sdmmc_ker_ck rising edge. Command and data changed on the same sdmmc_ker_ck rising edge generating the SDMMC_CK falling edge. When clock division 1 (CLKDIV 0) & DDR = 1: Command changed on the same sdmmc_ker_ck rising edge generating the SDMMC_CK falling edge. Data changed on the SDMMC_CK falling edge succeeding a SDMMC_CK edge. SDMMC_CK edge occurs on sdmmc_ker_ck rising edge.
 */
class negedge_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr negedge_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hardware flow control enable This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0) When Hardware flow control is enabled, the meaning of the TXFIFOE and RXFIFOF flags change, please see SDMMC status register definition in .
 */
class hwfc_en_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hwfc_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data rate signaling selection This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0) DDR rate must only be selected with 4-bit or 8-bit wide bus mode. (WIDBUS 00). DDR = 1 has no effect when WIDBUS = 00 (1-bit wide bus). DDR rate must only be selected with clock division 1. (CLKDIV 0)
 */
class ddr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus speed for selection of SDMMC operating modes This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0)
 */
class busspeed_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busspeed_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive clock selection These bits can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0)
 */
class selclkrx_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr selclkrx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_clkcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_clkcr_r>() const {return opsy::utility::clear_set<sdmmc_clkcr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return static_cast<sdmmc_clkcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_clkcr_r> other) const -> opsy::utility::clear_set<sdmmc_clkcr_r> {return opsy::utility::clear_set<sdmmc_clkcr_r>(sdmmc_clkcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto clkdiv() const -> clkdiv_f {return clkdiv_f(static_cast<uint16_t>(value_ >> clkdiv_f::offset));}
	[[nodiscard]] constexpr auto pwrsav() const -> pwrsav_f {return pwrsav_f((value_ & pwrsav_f::mask) != 0);}
	[[nodiscard]] constexpr auto widbus() const -> widbus_f {return widbus_f(static_cast<uint8_t>(value_ >> widbus_f::offset));}
	[[nodiscard]] constexpr auto negedge() const -> negedge_f {return negedge_f((value_ & negedge_f::mask) != 0);}
	[[nodiscard]] constexpr auto hwfc_en() const -> hwfc_en_f {return hwfc_en_f((value_ & hwfc_en_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddr() const -> ddr_f {return ddr_f((value_ & ddr_f::mask) != 0);}
	[[nodiscard]] constexpr auto busspeed() const -> busspeed_f {return busspeed_f((value_ & busspeed_f::mask) != 0);}
	[[nodiscard]] constexpr auto selclkrx() const -> selclkrx_f {return selclkrx_f(static_cast<uint8_t>(value_ >> selclkrx_f::offset));}

	constexpr sdmmc_clkcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_clkcr_r other) const -> sdmmc_clkcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_clkcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC argument register 
 */
class sdmmc_argr_r {
public:

/**
 * Command argument These bits can only be written by firmware when CPSM is disabled (CPSMEN = 0). Command argument sent to a card as part of a command message. If a command contains an argument, it must be loaded into this register before writing a command to the command register.
 */
class cmdarg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cmdarg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_argr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_argr_r>() const {return opsy::utility::clear_set<sdmmc_argr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_argr_r other) const -> sdmmc_argr_r { return static_cast<sdmmc_argr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_argr_r> other) const -> opsy::utility::clear_set<sdmmc_argr_r> {return opsy::utility::clear_set<sdmmc_argr_r>(sdmmc_argr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cmdarg() const -> cmdarg_f {return cmdarg_f(static_cast<uint32_t>(value_ >> cmdarg_f::offset));}

	constexpr sdmmc_argr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_argr_r other) const -> sdmmc_argr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_argr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC command register 
 */
class sdmmc_cmdr_r {
public:

/**
 * Command index This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). The command index is sent to the card as part of a command message.
 */
class cmdindex_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cmdindex_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * The CPSM treats the command as a data transfer command, stops the interrupt period, and signals DataEnable to the DPSM This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). If this bit is set, the CPSM issues an end of interrupt period and issues DataEnable signal to the DPSM when the command is sent.
 */
class cmdtrans_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdtrans_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * The CPSM treats the command as a Stop Transmission command and signals abort to the DPSM This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). If this bit is set, the CPSM issues the abort signal to the DPSM when the command is sent.
 */
class cmdstop_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdstop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait for response bits This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). They are used to configure whether the CPSM is to wait for a response, and if yes, which kind of response.
 */
class waitresp_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr waitresp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * CPSM waits for interrupt request If this bit is set, the CPSM disables command timeout and waits for an card interrupt request (Response). If this bit is cleared in the CPSM Wait state, it causes the abort of the interrupt mode.
 */
class waitint_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitint_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPSM waits for end of data transfer (CmdPend internal signal) from DPSM This bit when set, the CPSM waits for the end of data transfer trigger before it starts sending a command. WAITPEND is only taken into account when DTMODE = eMMC stream data transfer, WIDBUS = 1-bit wide bus mode, DPSMACT = 1 and DTDIR = from host to card.
 */
class waitpend_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitpend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command path state machine (CPSM) enable bit This bit is written 1 by firmware, and cleared by hardware when the CPSM enters the Idle state. If this bit is set, the CPSM is enabled. When DTEN = 1, no command is transfered nor boot procedure is started. CPSMEN is cleared to 0. During Read Wait with SDMMC_CK stopped no command is sent and CPSMEN is kept 0.
 */
class cpsmen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpsmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hold new data block transmission and reception in the DPSM If this bit is set, the DPSM does not move from the Wait_S state to the Send state or from the Wait_R state to the Receive state.
 */
class dthold_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dthold_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Select the boot mode procedure to be used This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0)
 */
class bootmode_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bootmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable boot mode procedure
 */
class booten_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr booten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * The CPSM treats the command as a Suspend or Resume command and signals interrupt period start/end This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). CMDSUSPEND = 1 and CMDTRANS = 0 Suspend command, start interrupt period when response bit BS=0. CMDSUSPEND = 1 and CMDTRANS = 1 Resume command with data, end interrupt period when response bit DF=1.
 */
class cmdsuspend_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmdsuspend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_cmdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_cmdr_r>() const {return opsy::utility::clear_set<sdmmc_cmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return static_cast<sdmmc_cmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_cmdr_r> other) const -> opsy::utility::clear_set<sdmmc_cmdr_r> {return opsy::utility::clear_set<sdmmc_cmdr_r>(sdmmc_cmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cmdindex() const -> cmdindex_f {return cmdindex_f(static_cast<uint8_t>(value_ >> cmdindex_f::offset));}
	[[nodiscard]] constexpr auto cmdtrans() const -> cmdtrans_f {return cmdtrans_f((value_ & cmdtrans_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdstop() const -> cmdstop_f {return cmdstop_f((value_ & cmdstop_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitresp() const -> waitresp_f {return waitresp_f(static_cast<uint8_t>(value_ >> waitresp_f::offset));}
	[[nodiscard]] constexpr auto waitint() const -> waitint_f {return waitint_f((value_ & waitint_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitpend() const -> waitpend_f {return waitpend_f((value_ & waitpend_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpsmen() const -> cpsmen_f {return cpsmen_f((value_ & cpsmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dthold() const -> dthold_f {return dthold_f((value_ & dthold_f::mask) != 0);}
	[[nodiscard]] constexpr auto bootmode() const -> bootmode_f {return bootmode_f((value_ & bootmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto booten() const -> booten_f {return booten_f((value_ & booten_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdsuspend() const -> cmdsuspend_f {return cmdsuspend_f((value_ & cmdsuspend_f::mask) != 0);}

	constexpr sdmmc_cmdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_cmdr_r other) const -> sdmmc_cmdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_cmdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC command response register 
 */
class sdmmc_respcmdr_r {
public:

/**
 * Response command index Read-only bit field. Contains the command index of the last command response received.
 */
class respcmd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr respcmd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_respcmdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_respcmdr_r>() const {return opsy::utility::clear_set<sdmmc_respcmdr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_respcmdr_r other) const -> sdmmc_respcmdr_r { return static_cast<sdmmc_respcmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_respcmdr_r> other) const -> opsy::utility::clear_set<sdmmc_respcmdr_r> {return opsy::utility::clear_set<sdmmc_respcmdr_r>(sdmmc_respcmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto respcmd() const -> respcmd_f {return respcmd_f(static_cast<uint8_t>(value_ >> respcmd_f::offset));}

	constexpr sdmmc_respcmdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_respcmdr_r other) const -> sdmmc_respcmdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_respcmdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC response X register
 */
class sdmmc_respxr_r {
public:

/**
 * Card status x See .
 */
class cardstatusx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cardstatusx_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_respxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_respxr_r>() const {return opsy::utility::clear_set<sdmmc_respxr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_respxr_r other) const -> sdmmc_respxr_r { return static_cast<sdmmc_respxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_respxr_r> other) const -> opsy::utility::clear_set<sdmmc_respxr_r> {return opsy::utility::clear_set<sdmmc_respxr_r>(sdmmc_respxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cardstatusx() const -> cardstatusx_f {return cardstatusx_f(static_cast<uint32_t>(value_ >> cardstatusx_f::offset));}

	constexpr sdmmc_respxr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_respxr_r other) const -> sdmmc_respxr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_respxr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC data timer register 
 */
class sdmmc_dtimer_r {
public:

/**
 * Data and R1b busy timeout period This bit can only be written when the CPSM and DPSM are not active (CPSMACT = 0 and DPSMACT = 0). Data and R1b busy timeout period expressed in card bus clock periods.
 */
class datatime_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datatime_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_dtimer_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_dtimer_r>() const {return opsy::utility::clear_set<sdmmc_dtimer_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dtimer_r other) const -> sdmmc_dtimer_r { return static_cast<sdmmc_dtimer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dtimer_r> other) const -> opsy::utility::clear_set<sdmmc_dtimer_r> {return opsy::utility::clear_set<sdmmc_dtimer_r>(sdmmc_dtimer_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto datatime() const -> datatime_f {return datatime_f(static_cast<uint32_t>(value_ >> datatime_f::offset));}

	constexpr sdmmc_dtimer_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_dtimer_r other) const -> sdmmc_dtimer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_dtimer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC data length register 
 */
class sdmmc_dlenr_r {
public:

/**
 * Data length value This register can only be written by firmware when DPSM is inactive (DPSMACT = 0). Number of data bytes to be transferred. When DDR = 1 DATALENGTH is truncated to a multiple of 2. (The last odd byte is not transfered) When DATALENGTH = 0 no data are transfered, when requested by a CPSMEN and CMDTRANS = 1 also no command is transfered. DTEN and CPSMEN are cleared to 0.
 */
class datalength_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 25;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datalength_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_dlenr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_dlenr_r>() const {return opsy::utility::clear_set<sdmmc_dlenr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dlenr_r other) const -> sdmmc_dlenr_r { return static_cast<sdmmc_dlenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dlenr_r> other) const -> opsy::utility::clear_set<sdmmc_dlenr_r> {return opsy::utility::clear_set<sdmmc_dlenr_r>(sdmmc_dlenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto datalength() const -> datalength_f {return datalength_f(static_cast<uint32_t>(value_ >> datalength_f::offset));}

	constexpr sdmmc_dlenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_dlenr_r other) const -> sdmmc_dlenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_dlenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC data control register 
 */
class sdmmc_dctrl_r {
public:

/**
 * Data transfer enable bit This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0). This bit is cleared by Hardware when data transfer completes. This bit must only be used to transfer data when no associated data transfer command is used, i.e. must not be used with SD or eMMC cards.
 */
class dten_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer direction selection This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class dtdir_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtdir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer mode selection This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class dtmode_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dtmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data block size This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0). Define the data block length when the block data transfer mode is selected: When DATALENGTH is not a multiple of DBLOCKSIZE, the transfered data is truncated at a multiple of DBLOCKSIZE. (None of the remaining data are transfered.) When DDR = 1, DBLOCKSIZE = 0000 must not be used. (No data are transfered)
 */
class dblocksize_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dblocksize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Read Wait start If this bit is set, Read Wait operation starts.
 */
class rwstart_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwstart_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read Wait stop This bit is written by firmware and auto cleared by hardware when the DPSM moves from the R_W state to the Wait_R or Idle state.
 */
class rwstop_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwstop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read Wait mode This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class rwmod_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwmod_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SD I/O interrupt enable functions This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0). If this bit is set, the DPSM enables the SD I/O card specific interrupt operation.
 */
class sdioen_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sdioen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable the reception of the boot acknowledgment This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class bootacken_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bootacken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO reset, flushes any remaining data This bit can only be written by firmware when IDMAEN= 0 and DPSM is active (DPSMACT = 1). This bit only takes effect when a transfer error or transfer hold occurs.
 */
class fiforst_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fiforst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_dctrl_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_dctrl_r>() const {return opsy::utility::clear_set<sdmmc_dctrl_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return static_cast<sdmmc_dctrl_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dctrl_r> other) const -> opsy::utility::clear_set<sdmmc_dctrl_r> {return opsy::utility::clear_set<sdmmc_dctrl_r>(sdmmc_dctrl_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dten() const -> dten_f {return dten_f((value_ & dten_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtdir() const -> dtdir_f {return dtdir_f((value_ & dtdir_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtmode() const -> dtmode_f {return dtmode_f(static_cast<uint8_t>(value_ >> dtmode_f::offset));}
	[[nodiscard]] constexpr auto dblocksize() const -> dblocksize_f {return dblocksize_f(static_cast<uint8_t>(value_ >> dblocksize_f::offset));}
	[[nodiscard]] constexpr auto rwstart() const -> rwstart_f {return rwstart_f((value_ & rwstart_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwstop() const -> rwstop_f {return rwstop_f((value_ & rwstop_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwmod() const -> rwmod_f {return rwmod_f((value_ & rwmod_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdioen() const -> sdioen_f {return sdioen_f((value_ & sdioen_f::mask) != 0);}
	[[nodiscard]] constexpr auto bootacken() const -> bootacken_f {return bootacken_f((value_ & bootacken_f::mask) != 0);}
	[[nodiscard]] constexpr auto fiforst() const -> fiforst_f {return fiforst_f((value_ & fiforst_f::mask) != 0);}

	constexpr sdmmc_dctrl_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_dctrl_r other) const -> sdmmc_dctrl_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_dctrl_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC data counter register 
 */
class sdmmc_dcntr_r {
public:

/**
 * Data count value When read, the number of remaining data bytes to be transferred is returned. Write has no effect.
 */
class datacount_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 25;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datacount_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_dcntr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_dcntr_r>() const {return opsy::utility::clear_set<sdmmc_dcntr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_dcntr_r other) const -> sdmmc_dcntr_r { return static_cast<sdmmc_dcntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_dcntr_r> other) const -> opsy::utility::clear_set<sdmmc_dcntr_r> {return opsy::utility::clear_set<sdmmc_dcntr_r>(sdmmc_dcntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto datacount() const -> datacount_f {return datacount_f(static_cast<uint32_t>(value_ >> datacount_f::offset));}

	constexpr sdmmc_dcntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_dcntr_r other) const -> sdmmc_dcntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_dcntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC status register 
 */
class sdmmc_star_r {
public:

/**
 * Command response received (CRC check failed) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class ccrcfail_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccrcfail_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data block sent/received (CRC check failed) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dcrcfail_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcrcfail_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command response timeout Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR. The Command Timeout period has a fixed value of 64 SDMMC_CK clock periods.
 */
class ctimeout_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctimeout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data timeout Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dtimeout_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtimeout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit FIFO underrun error (masked by hardware when IDMA is enabled) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class txunderr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txunderr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received FIFO overrun error (masked by hardware when IDMA is enabled) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class rxoverr_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxoverr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command response received (CRC check passed, or no CRC) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class cmdrend_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdrend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command sent (no response required) Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class cmdsent_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdsent_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer ended correctly DATAEND is set if data counter DATACOUNT is zero and no errors occur, and no transmit data transfer hold. Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dataend_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dataend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer Hold Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dhold_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dhold_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data block sent/received DBCKEND is set when: - CRC check passed and DPSM moves to the R_W state or - IDMAEN = 0 and transmit data transfer hold and DATACOUNT 0 and DPSM moves to Wait_S. Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dbckend_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbckend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer aborted by CMD12 Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class dabort_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dabort_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data path state machine active, i.e. not in Idle state This is a hardware status flag only, does not generate an interrupt.
 */
class dpsmact_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dpsmact_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command path state machine active, i.e. not in Idle state This is a hardware status flag only, does not generate an interrupt.
 */
class cpsmact_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpsmact_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit FIFO half empty At least half the number of words can be written into the FIFO. This bit is cleared when the FIFO becomes half+1 full.
 */
class txfifohe_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txfifohe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO half full There are at least half the number of words in the FIFO. This bit is cleared when the FIFO becomes half+1 empty.
 */
class rxfifohf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxfifohf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit FIFO full This is a hardware status flag only, does not generate an interrupt. This bit is cleared when one FIFO location becomes empty.
 */
class txfifof_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfifof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO full This bit is cleared when one FIFO location becomes empty.
 */
class rxfifof_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxfifof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit FIFO empty This bit is cleared when one FIFO location becomes full.
 */
class txfifoe_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfifoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO empty This is a hardware status flag only, does not generate an interrupt. This bit is cleared when one FIFO location becomes full.
 */
class rxfifoe_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxfifoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Inverted value of SDMMC_D0 line (Busy), sampled at the end of a CMD response and a second time 2 SDMMC_CK cycles after the CMD response This bit is reset to not busy when the SDMMCD0 line changes from busy to not busy. This bit does not signal busy due to data transfer. This is a hardware status flag only, it does not generate an interrupt.
 */
class busyd0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busyd0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of SDMMC_D0 Busy following a CMD response detected This indicates only end of busy following a CMD response. This bit does not signal busy due to data transfer. Interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class busyd0end_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busyd0end_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDIO interrupt received The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class sdioit_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdioit_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Boot acknowledgment received (boot acknowledgment check fail) The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class ackfail_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ackfail_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Boot acknowledgment timeout The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class acktimeout_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr acktimeout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Voltage switch critical timing section completion The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class vswend_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vswend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDMMC_CK stopped in Voltage switch procedure The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class ckstop_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ckstop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDMA transfer error The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class idmate_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idmate_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDMA buffer transfer complete The interrupt flag is cleared by writing corresponding interrupt clear bit in SDMMC_ICR.
 */
class idmabtc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idmabtc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_star_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_star_r>() const {return opsy::utility::clear_set<sdmmc_star_r>(mask, *this);}
	constexpr auto operator|(sdmmc_star_r other) const -> sdmmc_star_r { return static_cast<sdmmc_star_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_star_r> other) const -> opsy::utility::clear_set<sdmmc_star_r> {return opsy::utility::clear_set<sdmmc_star_r>(sdmmc_star_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccrcfail() const -> ccrcfail_f {return ccrcfail_f((value_ & ccrcfail_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcrcfail() const -> dcrcfail_f {return dcrcfail_f((value_ & dcrcfail_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctimeout() const -> ctimeout_f {return ctimeout_f((value_ & ctimeout_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtimeout() const -> dtimeout_f {return dtimeout_f((value_ & dtimeout_f::mask) != 0);}
	[[nodiscard]] constexpr auto txunderr() const -> txunderr_f {return txunderr_f((value_ & txunderr_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxoverr() const -> rxoverr_f {return rxoverr_f((value_ & rxoverr_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdrend() const -> cmdrend_f {return cmdrend_f((value_ & cmdrend_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdsent() const -> cmdsent_f {return cmdsent_f((value_ & cmdsent_f::mask) != 0);}
	[[nodiscard]] constexpr auto dataend() const -> dataend_f {return dataend_f((value_ & dataend_f::mask) != 0);}
	[[nodiscard]] constexpr auto dhold() const -> dhold_f {return dhold_f((value_ & dhold_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbckend() const -> dbckend_f {return dbckend_f((value_ & dbckend_f::mask) != 0);}
	[[nodiscard]] constexpr auto dabort() const -> dabort_f {return dabort_f((value_ & dabort_f::mask) != 0);}
	[[nodiscard]] constexpr auto dpsmact() const -> dpsmact_f {return dpsmact_f((value_ & dpsmact_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpsmact() const -> cpsmact_f {return cpsmact_f((value_ & cpsmact_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfifohe() const -> txfifohe_f {return txfifohe_f((value_ & txfifohe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifohf() const -> rxfifohf_f {return rxfifohf_f((value_ & rxfifohf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfifof() const -> txfifof_f {return txfifof_f((value_ & txfifof_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifof() const -> rxfifof_f {return rxfifof_f((value_ & rxfifof_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfifoe() const -> txfifoe_f {return txfifoe_f((value_ & txfifoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifoe() const -> rxfifoe_f {return rxfifoe_f((value_ & rxfifoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto busyd0() const -> busyd0_f {return busyd0_f((value_ & busyd0_f::mask) != 0);}
	[[nodiscard]] constexpr auto busyd0end() const -> busyd0end_f {return busyd0end_f((value_ & busyd0end_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdioit() const -> sdioit_f {return sdioit_f((value_ & sdioit_f::mask) != 0);}
	[[nodiscard]] constexpr auto ackfail() const -> ackfail_f {return ackfail_f((value_ & ackfail_f::mask) != 0);}
	[[nodiscard]] constexpr auto acktimeout() const -> acktimeout_f {return acktimeout_f((value_ & acktimeout_f::mask) != 0);}
	[[nodiscard]] constexpr auto vswend() const -> vswend_f {return vswend_f((value_ & vswend_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckstop() const -> ckstop_f {return ckstop_f((value_ & ckstop_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmate() const -> idmate_f {return idmate_f((value_ & idmate_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmabtc() const -> idmabtc_f {return idmabtc_f((value_ & idmabtc_f::mask) != 0);}

	constexpr sdmmc_star_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_star_r other) const -> sdmmc_star_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_star_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC interrupt clear register 
 */
class sdmmc_icr_r {
public:

/**
 * CCRCFAIL flag clear bit Set by software to clear the CCRCFAIL flag.
 */
class ccrcfailc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccrcfailc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DCRCFAIL flag clear bit Set by software to clear the DCRCFAIL flag.
 */
class dcrcfailc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcrcfailc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTIMEOUT flag clear bit Set by software to clear the CTIMEOUT flag.
 */
class ctimeoutc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctimeoutc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DTIMEOUT flag clear bit Set by software to clear the DTIMEOUT flag.
 */
class dtimeoutc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtimeoutc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXUNDERR flag clear bit Set by software to clear TXUNDERR flag.
 */
class txunderrc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txunderrc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXOVERR flag clear bit Set by software to clear the RXOVERR flag.
 */
class rxoverrc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxoverrc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CMDREND flag clear bit Set by software to clear the CMDREND flag.
 */
class cmdrendc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdrendc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CMDSENT flag clear bit Set by software to clear the CMDSENT flag.
 */
class cmdsentc_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdsentc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DATAEND flag clear bit Set by software to clear the DATAEND flag.
 */
class dataendc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dataendc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DHOLD flag clear bit Set by software to clear the DHOLD flag.
 */
class dholdc_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dholdc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DBCKEND flag clear bit Set by software to clear the DBCKEND flag.
 */
class dbckendc_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbckendc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DABORT flag clear bit Set by software to clear the DABORT flag.
 */
class dabortc_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dabortc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BUSYD0END flag clear bit Set by software to clear the BUSYD0END flag.
 */
class busyd0endc_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busyd0endc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDIOIT flag clear bit Set by software to clear the SDIOIT flag.
 */
class sdioitc_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdioitc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ACKFAIL flag clear bit Set by software to clear the ACKFAIL flag.
 */
class ackfailc_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ackfailc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ACKTIMEOUT flag clear bit Set by software to clear the ACKTIMEOUT flag.
 */
class acktimeoutc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr acktimeoutc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VSWEND flag clear bit Set by software to clear the VSWEND flag.
 */
class vswendc_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vswendc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CKSTOP flag clear bit Set by software to clear the CKSTOP flag.
 */
class ckstopc_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ckstopc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDMA transfer error clear bit Set by software to clear the IDMATE flag.
 */
class idmatec_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idmatec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDMA buffer transfer complete clear bit Set by software to clear the IDMABTC flag.
 */
class idmabtcc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idmabtcc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_icr_r>() const {return opsy::utility::clear_set<sdmmc_icr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_icr_r other) const -> sdmmc_icr_r { return static_cast<sdmmc_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_icr_r> other) const -> opsy::utility::clear_set<sdmmc_icr_r> {return opsy::utility::clear_set<sdmmc_icr_r>(sdmmc_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccrcfailc() const -> ccrcfailc_f {return ccrcfailc_f((value_ & ccrcfailc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcrcfailc() const -> dcrcfailc_f {return dcrcfailc_f((value_ & dcrcfailc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctimeoutc() const -> ctimeoutc_f {return ctimeoutc_f((value_ & ctimeoutc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtimeoutc() const -> dtimeoutc_f {return dtimeoutc_f((value_ & dtimeoutc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txunderrc() const -> txunderrc_f {return txunderrc_f((value_ & txunderrc_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxoverrc() const -> rxoverrc_f {return rxoverrc_f((value_ & rxoverrc_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdrendc() const -> cmdrendc_f {return cmdrendc_f((value_ & cmdrendc_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdsentc() const -> cmdsentc_f {return cmdsentc_f((value_ & cmdsentc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dataendc() const -> dataendc_f {return dataendc_f((value_ & dataendc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dholdc() const -> dholdc_f {return dholdc_f((value_ & dholdc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbckendc() const -> dbckendc_f {return dbckendc_f((value_ & dbckendc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dabortc() const -> dabortc_f {return dabortc_f((value_ & dabortc_f::mask) != 0);}
	[[nodiscard]] constexpr auto busyd0endc() const -> busyd0endc_f {return busyd0endc_f((value_ & busyd0endc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdioitc() const -> sdioitc_f {return sdioitc_f((value_ & sdioitc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ackfailc() const -> ackfailc_f {return ackfailc_f((value_ & ackfailc_f::mask) != 0);}
	[[nodiscard]] constexpr auto acktimeoutc() const -> acktimeoutc_f {return acktimeoutc_f((value_ & acktimeoutc_f::mask) != 0);}
	[[nodiscard]] constexpr auto vswendc() const -> vswendc_f {return vswendc_f((value_ & vswendc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckstopc() const -> ckstopc_f {return ckstopc_f((value_ & ckstopc_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmatec() const -> idmatec_f {return idmatec_f((value_ & idmatec_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmabtcc() const -> idmabtcc_f {return idmabtcc_f((value_ & idmabtcc_f::mask) != 0);}

	constexpr sdmmc_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_icr_r other) const -> sdmmc_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC mask register 
 */
class sdmmc_maskr_r {
public:

/**
 * Command CRC fail interrupt enable Set and cleared by software to enable/disable interrupt caused by command CRC failure.
 */
class ccrcfailie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccrcfailie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data CRC fail interrupt enable Set and cleared by software to enable/disable interrupt caused by data CRC failure.
 */
class dcrcfailie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcrcfailie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command timeout interrupt enable Set and cleared by software to enable/disable interrupt caused by command timeout.
 */
class ctimeoutie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctimeoutie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data timeout interrupt enable Set and cleared by software to enable/disable interrupt caused by data timeout.
 */
class dtimeoutie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtimeoutie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO underrun error interrupt enable Set and cleared by software to enable/disable interrupt caused by Tx FIFO underrun error.
 */
class txunderrie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txunderrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO overrun error interrupt enable Set and cleared by software to enable/disable interrupt caused by Rx FIFO overrun error.
 */
class rxoverrie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxoverrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command response received interrupt enable Set and cleared by software to enable/disable interrupt caused by receiving command response.
 */
class cmdrendie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdrendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command sent interrupt enable Set and cleared by software to enable/disable interrupt caused by sending command.
 */
class cmdsentie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmdsentie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data end interrupt enable Set and cleared by software to enable/disable interrupt caused by data end.
 */
class dataendie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dataendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data hold interrupt enable Set and cleared by software to enable/disable the interrupt generated when sending new data is hold in the DPSM Wait_S state.
 */
class dholdie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dholdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data block end interrupt enable Set and cleared by software to enable/disable interrupt caused by data block end.
 */
class dbckendie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dbckendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data transfer aborted interrupt enable Set and cleared by software to enable/disable interrupt caused by a data transfer being aborted.
 */
class dabortie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dabortie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO half empty interrupt enable Set and cleared by software to enable/disable interrupt caused by Tx FIFO half empty.
 */
class txfifoheie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txfifoheie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO half full interrupt enable Set and cleared by software to enable/disable interrupt caused by Rx FIFO half full.
 */
class rxfifohfie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxfifohfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO full interrupt enable Set and cleared by software to enable/disable interrupt caused by Rx FIFO full.
 */
class rxfifofie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxfifofie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO empty interrupt enable Set and cleared by software to enable/disable interrupt caused by Tx FIFO empty.
 */
class txfifoeie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfifoeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BUSYD0END interrupt enable Set and cleared by software to enable/disable the interrupt generated when SDMMC_D0 signal changes from busy to NOT busy following a CMD response.
 */
class busyd0endie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busyd0endie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDIO mode interrupt received interrupt enable Set and cleared by software to enable/disable the interrupt generated when receiving the SDIO mode interrupt.
 */
class sdioitie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdioitie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Acknowledgment Fail interrupt enable Set and cleared by software to enable/disable interrupt caused by acknowledgment Fail.
 */
class ackfailie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ackfailie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Acknowledgment timeout interrupt enable Set and cleared by software to enable/disable interrupt caused by acknowledgment timeout.
 */
class acktimeoutie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr acktimeoutie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Voltage switch critical timing section completion interrupt enable Set and cleared by software to enable/disable the interrupt generated when voltage switch critical timing section completion.
 */
class vswendie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vswendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Voltage Switch clock stopped interrupt enable Set and cleared by software to enable/disable interrupt caused by Voltage Switch clock stopped.
 */
class ckstopie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ckstopie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDMA buffer transfer complete interrupt enable Set and cleared by software to enable/disable the interrupt generated when the IDMA has transferred all data belonging to a memory buffer.
 */
class idmabtcie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idmabtcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_maskr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_maskr_r>() const {return opsy::utility::clear_set<sdmmc_maskr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return static_cast<sdmmc_maskr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_maskr_r> other) const -> opsy::utility::clear_set<sdmmc_maskr_r> {return opsy::utility::clear_set<sdmmc_maskr_r>(sdmmc_maskr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccrcfailie() const -> ccrcfailie_f {return ccrcfailie_f((value_ & ccrcfailie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcrcfailie() const -> dcrcfailie_f {return dcrcfailie_f((value_ & dcrcfailie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctimeoutie() const -> ctimeoutie_f {return ctimeoutie_f((value_ & ctimeoutie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtimeoutie() const -> dtimeoutie_f {return dtimeoutie_f((value_ & dtimeoutie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txunderrie() const -> txunderrie_f {return txunderrie_f((value_ & txunderrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxoverrie() const -> rxoverrie_f {return rxoverrie_f((value_ & rxoverrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdrendie() const -> cmdrendie_f {return cmdrendie_f((value_ & cmdrendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmdsentie() const -> cmdsentie_f {return cmdsentie_f((value_ & cmdsentie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dataendie() const -> dataendie_f {return dataendie_f((value_ & dataendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dholdie() const -> dholdie_f {return dholdie_f((value_ & dholdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbckendie() const -> dbckendie_f {return dbckendie_f((value_ & dbckendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dabortie() const -> dabortie_f {return dabortie_f((value_ & dabortie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfifoheie() const -> txfifoheie_f {return txfifoheie_f((value_ & txfifoheie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifohfie() const -> rxfifohfie_f {return rxfifohfie_f((value_ & rxfifohfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifofie() const -> rxfifofie_f {return rxfifofie_f((value_ & rxfifofie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfifoeie() const -> txfifoeie_f {return txfifoeie_f((value_ & txfifoeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto busyd0endie() const -> busyd0endie_f {return busyd0endie_f((value_ & busyd0endie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdioitie() const -> sdioitie_f {return sdioitie_f((value_ & sdioitie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ackfailie() const -> ackfailie_f {return ackfailie_f((value_ & ackfailie_f::mask) != 0);}
	[[nodiscard]] constexpr auto acktimeoutie() const -> acktimeoutie_f {return acktimeoutie_f((value_ & acktimeoutie_f::mask) != 0);}
	[[nodiscard]] constexpr auto vswendie() const -> vswendie_f {return vswendie_f((value_ & vswendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckstopie() const -> ckstopie_f {return ckstopie_f((value_ & ckstopie_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmabtcie() const -> idmabtcie_f {return idmabtcie_f((value_ & idmabtcie_f::mask) != 0);}

	constexpr sdmmc_maskr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_maskr_r other) const -> sdmmc_maskr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_maskr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC acknowledgment timer register 
 */
class sdmmc_acktimer_r {
public:

/**
 * Boot acknowledgment timeout period This bit can only be written by firmware when CPSM is disabled (CPSMEN = 0). Boot acknowledgment timeout period expressed in card bus clock periods.
 */
class acktime_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 25;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr acktime_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_acktimer_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_acktimer_r>() const {return opsy::utility::clear_set<sdmmc_acktimer_r>(mask, *this);}
	constexpr auto operator|(sdmmc_acktimer_r other) const -> sdmmc_acktimer_r { return static_cast<sdmmc_acktimer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_acktimer_r> other) const -> opsy::utility::clear_set<sdmmc_acktimer_r> {return opsy::utility::clear_set<sdmmc_acktimer_r>(sdmmc_acktimer_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto acktime() const -> acktime_f {return acktime_f(static_cast<uint32_t>(value_ >> acktime_f::offset));}

	constexpr sdmmc_acktimer_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_acktimer_r other) const -> sdmmc_acktimer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_acktimer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC DMA control register 
 */
class sdmmc_idmactrlr_r {
public:

/**
 * IDMA enable This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class idmaen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_idmactrlr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_idmactrlr_r>() const {return opsy::utility::clear_set<sdmmc_idmactrlr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmactrlr_r other) const -> sdmmc_idmactrlr_r { return static_cast<sdmmc_idmactrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmactrlr_r> other) const -> opsy::utility::clear_set<sdmmc_idmactrlr_r> {return opsy::utility::clear_set<sdmmc_idmactrlr_r>(sdmmc_idmactrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Buffer mode selection This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class idmabmode_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idmabmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_idmactrlr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_idmactrlr_r>() const {return opsy::utility::clear_set<sdmmc_idmactrlr_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmactrlr_r other) const -> sdmmc_idmactrlr_r { return static_cast<sdmmc_idmactrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmactrlr_r> other) const -> opsy::utility::clear_set<sdmmc_idmactrlr_r> {return opsy::utility::clear_set<sdmmc_idmactrlr_r>(sdmmc_idmactrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto idmaen() const -> idmaen_f {return idmaen_f((value_ & idmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto idmabmode() const -> idmabmode_f {return idmabmode_f((value_ & idmabmode_f::mask) != 0);}

	constexpr sdmmc_idmactrlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_idmactrlr_r other) const -> sdmmc_idmactrlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_idmactrlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC IDMA buffer size register 
 */
class sdmmc_idmabsizer_r {
public:

/**
 * Number of bytes per buffer This 12-bit value must be multiplied by 8 to get the size of the buffer in 32-bit words and by 32 to get the size of the buffer in bytes. Example: IDMABNDT = 0x001: buffer size = 8 words = 32 bytes. Example: IDMABNDT = 0x800: buffer size = 16384 words = 64 Kbyte. These bits can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class idmabndt_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr idmabndt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator sdmmc_idmabsizer_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_idmabsizer_r>() const {return opsy::utility::clear_set<sdmmc_idmabsizer_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmabsizer_r other) const -> sdmmc_idmabsizer_r { return static_cast<sdmmc_idmabsizer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmabsizer_r> other) const -> opsy::utility::clear_set<sdmmc_idmabsizer_r> {return opsy::utility::clear_set<sdmmc_idmabsizer_r>(sdmmc_idmabsizer_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto idmabndt() const -> idmabndt_f {return idmabndt_f(static_cast<uint16_t>(value_ >> idmabndt_f::offset));}

	constexpr sdmmc_idmabsizer_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_idmabsizer_r other) const -> sdmmc_idmabsizer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_idmabsizer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC IDMA buffer base address register 
 */
class sdmmc_idmabaser_r {
public:

/**
 * Buffer memory base address bits [31:2], must be word aligned (bit [1:0] are always 0 and read only) This register can be written by firmware when DPSM is inactive (DPSMACT = 0), and can dynamically be written by firmware when DPSM active (DPSMACT = 1).
 */
class idmabase_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr idmabase_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_idmabaser_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_idmabaser_r>() const {return opsy::utility::clear_set<sdmmc_idmabaser_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmabaser_r other) const -> sdmmc_idmabaser_r { return static_cast<sdmmc_idmabaser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmabaser_r> other) const -> opsy::utility::clear_set<sdmmc_idmabaser_r> {return opsy::utility::clear_set<sdmmc_idmabaser_r>(sdmmc_idmabaser_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto idmabase() const -> idmabase_f {return idmabase_f(static_cast<uint32_t>(value_ >> idmabase_f::offset));}

	constexpr sdmmc_idmabaser_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_idmabaser_r other) const -> sdmmc_idmabaser_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_idmabaser_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC_IDMALAR
 */
class sdmmc_idmalar_r {
public:

/**
 * Word aligned linked list item address offset Linked list item offset pointer to the base of the next linked list item structure. Linked list item base address is IDMABA + IDMALA. These bits can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class idmala_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr idmala_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator sdmmc_idmalar_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_idmalar_r>() const {return opsy::utility::clear_set<sdmmc_idmalar_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmalar_r other) const -> sdmmc_idmalar_r { return static_cast<sdmmc_idmalar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmalar_r> other) const -> opsy::utility::clear_set<sdmmc_idmalar_r> {return opsy::utility::clear_set<sdmmc_idmalar_r>(sdmmc_idmalar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Acknowledge linked list buffer ready This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0). This bit is not taken into account when starting the first linked list buffer from the software programmed register information. ABR is only taken into account on subsequent loaded linked list items.
 */
class abr_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_idmalar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_idmalar_r>() const {return opsy::utility::clear_set<sdmmc_idmalar_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmalar_r other) const -> sdmmc_idmalar_r { return static_cast<sdmmc_idmalar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmalar_r> other) const -> opsy::utility::clear_set<sdmmc_idmalar_r> {return opsy::utility::clear_set<sdmmc_idmalar_r>(sdmmc_idmalar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update SDMMC_IDMABSIZE from the next linked list when in linked list mode (SDMMC_IDMACTRLR.IDMABMODE select linked list mode and ULA = 1) This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class uls_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uls_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_idmalar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_idmalar_r>() const {return opsy::utility::clear_set<sdmmc_idmalar_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmalar_r other) const -> sdmmc_idmalar_r { return static_cast<sdmmc_idmalar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmalar_r> other) const -> opsy::utility::clear_set<sdmmc_idmalar_r> {return opsy::utility::clear_set<sdmmc_idmalar_r>(sdmmc_idmalar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update SDMMC_IDMALAR from linked list when in linked list mode (SDMMC_IDMACTRLR.IDMABMODE select linked list mode) This bit can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class ula_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ula_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sdmmc_idmalar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sdmmc_idmalar_r>() const {return opsy::utility::clear_set<sdmmc_idmalar_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmalar_r other) const -> sdmmc_idmalar_r { return static_cast<sdmmc_idmalar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmalar_r> other) const -> opsy::utility::clear_set<sdmmc_idmalar_r> {return opsy::utility::clear_set<sdmmc_idmalar_r>(sdmmc_idmalar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto idmala() const -> idmala_f {return idmala_f(static_cast<uint16_t>(value_ >> idmala_f::offset));}
	[[nodiscard]] constexpr auto abr() const -> abr_f {return abr_f((value_ & abr_f::mask) != 0);}
	[[nodiscard]] constexpr auto uls() const -> uls_f {return uls_f((value_ & uls_f::mask) != 0);}
	[[nodiscard]] constexpr auto ula() const -> ula_f {return ula_f((value_ & ula_f::mask) != 0);}

	constexpr sdmmc_idmalar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_idmalar_r other) const -> sdmmc_idmalar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_idmalar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC_IDMABAR
 */
class sdmmc_idmabar_r {
public:

/**
 * Word aligned Linked list memory base address Linked list memory base pointer. These bits can only be written by firmware when DPSM is inactive (DPSMACT = 0).
 */
class idmaba_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 30;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr idmaba_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_idmabar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_idmabar_r>() const {return opsy::utility::clear_set<sdmmc_idmabar_r>(mask, *this);}
	constexpr auto operator|(sdmmc_idmabar_r other) const -> sdmmc_idmabar_r { return static_cast<sdmmc_idmabar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_idmabar_r> other) const -> opsy::utility::clear_set<sdmmc_idmabar_r> {return opsy::utility::clear_set<sdmmc_idmabar_r>(sdmmc_idmabar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto idmaba() const -> idmaba_f {return idmaba_f(static_cast<uint32_t>(value_ >> idmaba_f::offset));}

	constexpr sdmmc_idmabar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_idmabar_r other) const -> sdmmc_idmabar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_idmabar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDMMC data FIFO registers 0
 */
class sdmmc_fifor0_r {
public:

/**
 * Receive and transmit FIFO data This register can only be read or written by firmware when the DPSM is active (DPSMACT = 1). The FIFO data occupies 16 entries of 32-bit words.
 */
class fifodata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fifodata_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sdmmc_fifor0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sdmmc_fifor0_r>() const {return opsy::utility::clear_set<sdmmc_fifor0_r>(mask, *this);}
	constexpr auto operator|(sdmmc_fifor0_r other) const -> sdmmc_fifor0_r { return static_cast<sdmmc_fifor0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sdmmc_fifor0_r> other) const -> opsy::utility::clear_set<sdmmc_fifor0_r> {return opsy::utility::clear_set<sdmmc_fifor0_r>(sdmmc_fifor0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto fifodata() const -> fifodata_f {return fifodata_f(static_cast<uint32_t>(value_ >> fifodata_f::offset));}

	constexpr sdmmc_fifor0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sdmmc_fifor0_r other) const -> sdmmc_fifor0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sdmmc_fifor0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,sdmmc_power_r> sdmmc_power;
	opsy::utility::memory<uint32_t,sdmmc_clkcr_r> sdmmc_clkcr;
	opsy::utility::memory<uint32_t,sdmmc_argr_r> sdmmc_argr;
	opsy::utility::memory<uint32_t,sdmmc_cmdr_r> sdmmc_cmdr;
	opsy::utility::memory<uint32_t,sdmmc_respcmdr_r> sdmmc_respcmdr;
	opsy::utility::memory<uint32_t,sdmmc_respxr_r> sdmmc_resp1r;
	opsy::utility::memory<uint32_t,sdmmc_respxr_r> sdmmc_resp2r;
	opsy::utility::memory<uint32_t,sdmmc_respxr_r> sdmmc_resp3r;
	opsy::utility::memory<uint32_t,sdmmc_respxr_r> sdmmc_resp4r;
	opsy::utility::memory<uint32_t,sdmmc_dtimer_r> sdmmc_dtimer;
	opsy::utility::memory<uint32_t,sdmmc_dlenr_r> sdmmc_dlenr;
	opsy::utility::memory<uint32_t,sdmmc_dctrl_r> sdmmc_dctrl;
	opsy::utility::memory<uint32_t,sdmmc_dcntr_r> sdmmc_dcntr;
	opsy::utility::memory<uint32_t,sdmmc_star_r> sdmmc_star;
	opsy::utility::memory<uint32_t,sdmmc_icr_r> sdmmc_icr;
	opsy::utility::memory<uint32_t,sdmmc_maskr_r> sdmmc_maskr;
	opsy::utility::memory<uint32_t,sdmmc_acktimer_r> sdmmc_acktimer;
	opsy::utility::padding<12> _p0;
	opsy::utility::memory<uint32_t,sdmmc_idmactrlr_r> sdmmc_idmactrlr;
	opsy::utility::memory<uint32_t,sdmmc_idmabsizer_r> sdmmc_idmabsizer;
	opsy::utility::memory<uint32_t,sdmmc_idmabaser_r> sdmmc_idmabaser;
	opsy::utility::padding<8> _p1;
	opsy::utility::memory<uint32_t,sdmmc_idmalar_r> sdmmc_idmalar;
	opsy::utility::memory<uint32_t,sdmmc_idmabar_r> sdmmc_idmabar;
	opsy::utility::padding<20> _p2;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor0;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor1;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor2;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor3;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor4;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor5;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor6;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor7;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor8;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor9;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor10;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor11;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor12;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor13;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor14;
	opsy::utility::memory<uint32_t,sdmmc_fifor0_r> sdmmc_fifor15;
};

static_assert(std::is_standard_layout_v<sdmmc_p>);
static_assert(offsetof(sdmmc_p, sdmmc_power) == 0);
static_assert(offsetof(sdmmc_p, sdmmc_clkcr) == 4);
static_assert(offsetof(sdmmc_p, sdmmc_argr) == 8);
static_assert(offsetof(sdmmc_p, sdmmc_cmdr) == 12);
static_assert(offsetof(sdmmc_p, sdmmc_respcmdr) == 16);
static_assert(offsetof(sdmmc_p, sdmmc_resp1r) == 20);
static_assert(offsetof(sdmmc_p, sdmmc_resp2r) == 24);
static_assert(offsetof(sdmmc_p, sdmmc_resp3r) == 28);
static_assert(offsetof(sdmmc_p, sdmmc_resp4r) == 32);
static_assert(offsetof(sdmmc_p, sdmmc_dtimer) == 36);
static_assert(offsetof(sdmmc_p, sdmmc_dlenr) == 40);
static_assert(offsetof(sdmmc_p, sdmmc_dctrl) == 44);
static_assert(offsetof(sdmmc_p, sdmmc_dcntr) == 48);
static_assert(offsetof(sdmmc_p, sdmmc_star) == 52);
static_assert(offsetof(sdmmc_p, sdmmc_icr) == 56);
static_assert(offsetof(sdmmc_p, sdmmc_maskr) == 60);
static_assert(offsetof(sdmmc_p, sdmmc_acktimer) == 64);
static_assert(offsetof(sdmmc_p, sdmmc_idmactrlr) == 80);
static_assert(offsetof(sdmmc_p, sdmmc_idmabsizer) == 84);
static_assert(offsetof(sdmmc_p, sdmmc_idmabaser) == 88);
static_assert(offsetof(sdmmc_p, sdmmc_idmalar) == 100);
static_assert(offsetof(sdmmc_p, sdmmc_idmabar) == 104);
static_assert(offsetof(sdmmc_p, sdmmc_fifor0) == 128);
static_assert(offsetof(sdmmc_p, sdmmc_fifor1) == 132);
static_assert(offsetof(sdmmc_p, sdmmc_fifor2) == 136);
static_assert(offsetof(sdmmc_p, sdmmc_fifor3) == 140);
static_assert(offsetof(sdmmc_p, sdmmc_fifor4) == 144);
static_assert(offsetof(sdmmc_p, sdmmc_fifor5) == 148);
static_assert(offsetof(sdmmc_p, sdmmc_fifor6) == 152);
static_assert(offsetof(sdmmc_p, sdmmc_fifor7) == 156);
static_assert(offsetof(sdmmc_p, sdmmc_fifor8) == 160);
static_assert(offsetof(sdmmc_p, sdmmc_fifor9) == 164);
static_assert(offsetof(sdmmc_p, sdmmc_fifor10) == 168);
static_assert(offsetof(sdmmc_p, sdmmc_fifor11) == 172);
static_assert(offsetof(sdmmc_p, sdmmc_fifor12) == 176);
static_assert(offsetof(sdmmc_p, sdmmc_fifor13) == 180);
static_assert(offsetof(sdmmc_p, sdmmc_fifor14) == 184);
static_assert(offsetof(sdmmc_p, sdmmc_fifor15) == 188);

inline sdmmc_p& sdmmc1 = *reinterpret_cast<sdmmc_p*>(0x46008000);
inline sdmmc_p& sdmmc2 = *reinterpret_cast<sdmmc_p*>(0x46008C00);
inline sdmmc_p& sec_sdmmc1 = *reinterpret_cast<sdmmc_p*>(0x56008000);
inline sdmmc_p& sec_sdmmc2 = *reinterpret_cast<sdmmc_p*>(0x56008C00);

} // STM32H563

