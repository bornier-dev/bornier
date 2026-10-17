#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Controller area network
 */
class fdcan_p {
public:

/**
 * FDCAN core release register 
 */
class fdcan_crel_r {
public:

/**
 * 18
 */
class day_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr day_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 12
 */
class mon_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mon_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 4
 */
class year_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr year_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 1
 */
class substep_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr substep_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 2
 */
class step_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr step_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 3
 */
class rel_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_crel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_crel_r>() const {return opsy::utility::clear_set<fdcan_crel_r>(mask, *this);}
	constexpr auto operator|(fdcan_crel_r other) const -> fdcan_crel_r { return static_cast<fdcan_crel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_crel_r> other) const -> opsy::utility::clear_set<fdcan_crel_r> {return opsy::utility::clear_set<fdcan_crel_r>(fdcan_crel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto day() const -> day_f {return day_f(static_cast<uint8_t>(value_ >> day_f::offset));}
	[[nodiscard]] constexpr auto mon() const -> mon_f {return mon_f(static_cast<uint8_t>(value_ >> mon_f::offset));}
	[[nodiscard]] constexpr auto year() const -> year_f {return year_f(static_cast<uint8_t>(value_ >> year_f::offset));}
	[[nodiscard]] constexpr auto substep() const -> substep_f {return substep_f(static_cast<uint8_t>(value_ >> substep_f::offset));}
	[[nodiscard]] constexpr auto step() const -> step_f {return step_f(static_cast<uint8_t>(value_ >> step_f::offset));}
	[[nodiscard]] constexpr auto rel() const -> rel_f {return rel_f(static_cast<uint8_t>(value_ >> rel_f::offset));}

	constexpr fdcan_crel_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_crel_r other) const -> fdcan_crel_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_crel_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b110010000101000001001000011000; // 840176152 0x32141218

private:
	uint32_t value_;
};

/**
 * FDCAN endian register 
 */
class fdcan_endn_r {
public:

/**
 * Endianness test value The endianness test value is 0x8765 4321.
 */
class etv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr etv_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator fdcan_endn_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_endn_r>() const {return opsy::utility::clear_set<fdcan_endn_r>(mask, *this);}
	constexpr auto operator|(fdcan_endn_r other) const -> fdcan_endn_r { return static_cast<fdcan_endn_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_endn_r> other) const -> opsy::utility::clear_set<fdcan_endn_r> {return opsy::utility::clear_set<fdcan_endn_r>(fdcan_endn_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto etv() const -> etv_f {return etv_f(static_cast<uint32_t>(value_ >> etv_f::offset));}

	constexpr fdcan_endn_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_endn_r other) const -> fdcan_endn_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_endn_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000111011001010100001100100001; // 2271560481 0x87654321

private:
	uint32_t value_;
};

/**
 * FDCAN data bit timing and prescaler register 
 */
class fdcan_dbtp_r {
public:

/**
 * Synchronization jump width Must always be smaller than DTSEG2, valid values are 0 to 15. The value used by the hardware is the one programmed, incremented by 1: tSJW = (DSJW + 1) x tq.
 */
class dsjw_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dsjw_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_dbtp_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_dbtp_r>() const {return opsy::utility::clear_set<fdcan_dbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return static_cast<fdcan_dbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_dbtp_r> other) const -> opsy::utility::clear_set<fdcan_dbtp_r> {return opsy::utility::clear_set<fdcan_dbtp_r>(fdcan_dbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data time segment after sample point Valid values are 0 to 15. The value used by the hardware is the one programmed, incremented by 1, i.e. tBS2 = (DTSEG2 + 1) x tq.
 */
class dtseg2_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dtseg2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_dbtp_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_dbtp_r>() const {return opsy::utility::clear_set<fdcan_dbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return static_cast<fdcan_dbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_dbtp_r> other) const -> opsy::utility::clear_set<fdcan_dbtp_r> {return opsy::utility::clear_set<fdcan_dbtp_r>(fdcan_dbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data time segment before sample point Valid values are 0 to 31. The value used by the hardware is the one programmed, incremented by 1, i.e. tBS1 = (DTSEG1 + 1) x tq.
 */
class dtseg1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dtseg1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_dbtp_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_dbtp_r>() const {return opsy::utility::clear_set<fdcan_dbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return static_cast<fdcan_dbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_dbtp_r> other) const -> opsy::utility::clear_set<fdcan_dbtp_r> {return opsy::utility::clear_set<fdcan_dbtp_r>(fdcan_dbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data bit rate prescaler The value by which the oscillator frequency is divided to generate the bit time quanta. The bit time is built up from a multiple of this quanta. Valid values for the Baud Rate Prescaler are 0 to 31. The hardware interpreters this value as the value programmed plus 1.
 */
class dbrp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dbrp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_dbtp_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_dbtp_r>() const {return opsy::utility::clear_set<fdcan_dbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return static_cast<fdcan_dbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_dbtp_r> other) const -> opsy::utility::clear_set<fdcan_dbtp_r> {return opsy::utility::clear_set<fdcan_dbtp_r>(fdcan_dbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transceiver delay compensation
 */
class tdc_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tdc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_dbtp_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_dbtp_r>() const {return opsy::utility::clear_set<fdcan_dbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return static_cast<fdcan_dbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_dbtp_r> other) const -> opsy::utility::clear_set<fdcan_dbtp_r> {return opsy::utility::clear_set<fdcan_dbtp_r>(fdcan_dbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dsjw() const -> dsjw_f {return dsjw_f(static_cast<uint8_t>(value_ >> dsjw_f::offset));}
	[[nodiscard]] constexpr auto dtseg2() const -> dtseg2_f {return dtseg2_f(static_cast<uint8_t>(value_ >> dtseg2_f::offset));}
	[[nodiscard]] constexpr auto dtseg1() const -> dtseg1_f {return dtseg1_f(static_cast<uint8_t>(value_ >> dtseg1_f::offset));}
	[[nodiscard]] constexpr auto dbrp() const -> dbrp_f {return dbrp_f(static_cast<uint8_t>(value_ >> dbrp_f::offset));}
	[[nodiscard]] constexpr auto tdc() const -> tdc_f {return tdc_f((value_ & tdc_f::mask) != 0);}

	constexpr fdcan_dbtp_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_dbtp_r other) const -> fdcan_dbtp_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_dbtp_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b101000110011; // 2611 0xA33

private:
	uint32_t value_;
};

/**
 * FDCAN test register 
 */
class fdcan_test_r {
public:

/**
 * Loop back mode
 */
class lbck_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lbck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_test_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_test_r>() const {return opsy::utility::clear_set<fdcan_test_r>(mask, *this);}
	constexpr auto operator|(fdcan_test_r other) const -> fdcan_test_r { return static_cast<fdcan_test_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_test_r> other) const -> opsy::utility::clear_set<fdcan_test_r> {return opsy::utility::clear_set<fdcan_test_r>(fdcan_test_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Control of transmit pin
 */
class tx_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_test_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_test_r>() const {return opsy::utility::clear_set<fdcan_test_r>(mask, *this);}
	constexpr auto operator|(fdcan_test_r other) const -> fdcan_test_r { return static_cast<fdcan_test_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_test_r> other) const -> opsy::utility::clear_set<fdcan_test_r> {return opsy::utility::clear_set<fdcan_test_r>(fdcan_test_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receive pin Monitors the actual value of pin FDCANx_RX
 */
class rx_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_test_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_test_r>() const {return opsy::utility::clear_set<fdcan_test_r>(mask, *this);}
	constexpr auto operator|(fdcan_test_r other) const -> fdcan_test_r { return static_cast<fdcan_test_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_test_r> other) const -> opsy::utility::clear_set<fdcan_test_r> {return opsy::utility::clear_set<fdcan_test_r>(fdcan_test_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lbck() const -> lbck_f {return lbck_f((value_ & lbck_f::mask) != 0);}
	[[nodiscard]] constexpr auto tx() const -> tx_f {return tx_f(static_cast<uint8_t>(value_ >> tx_f::offset));}
	[[nodiscard]] constexpr auto rx() const -> rx_f {return rx_f((value_ & rx_f::mask) != 0);}

	constexpr fdcan_test_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_test_r other) const -> fdcan_test_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_test_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN RAM watchdog register 
 */
class fdcan_rwd_r {
public:

/**
 * Watchdog configuration Start value of the message RAM watchdog counter. With the reset value of 00, the counter is disabled. These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of FDCAN_CCCR register are set to 1.
 */
class wdc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr wdc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rwd_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rwd_r>() const {return opsy::utility::clear_set<fdcan_rwd_r>(mask, *this);}
	constexpr auto operator|(fdcan_rwd_r other) const -> fdcan_rwd_r { return static_cast<fdcan_rwd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rwd_r> other) const -> opsy::utility::clear_set<fdcan_rwd_r> {return opsy::utility::clear_set<fdcan_rwd_r>(fdcan_rwd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Watchdog value Actual message RAM watchdog counter value.
 */
class wdv_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wdv_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rwd_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rwd_r>() const {return opsy::utility::clear_set<fdcan_rwd_r>(mask, *this);}
	constexpr auto operator|(fdcan_rwd_r other) const -> fdcan_rwd_r { return static_cast<fdcan_rwd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rwd_r> other) const -> opsy::utility::clear_set<fdcan_rwd_r> {return opsy::utility::clear_set<fdcan_rwd_r>(fdcan_rwd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto wdc() const -> wdc_f {return wdc_f(static_cast<uint8_t>(value_ >> wdc_f::offset));}
	[[nodiscard]] constexpr auto wdv() const -> wdv_f {return wdv_f(static_cast<uint8_t>(value_ >> wdv_f::offset));}

	constexpr fdcan_rwd_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rwd_r other) const -> fdcan_rwd_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rwd_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN CC control register 
 */
class fdcan_cccr_r {
public:

/**
 * Initialization
 */
class init_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr init_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Configuration change enable
 */
class cce_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ASM restricted operation mode The restricted operation mode is intended for applications that adapt themselves to different CAN bit rates. The application tests different bit rates and leaves the Restricted operation Mode after it has received a valid frame. In the optional Restricted operation Mode the node is able to transmit and receive data and remote frames and it gives acknowledge to valid frames, but it does not send active error frames or overload frames. In case of an error condition or overload condition, it does not send dominant bits, instead it waits for the occurrence of bus idle condition to resynchronize itself to the CAN communication. The error counters are not incremented. Bit ASM can only be set by software when both CCE and INIT are set to 1. The bit can be reset by the software at any time.
 */
class asm_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr asm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock stop acknowledge
 */
class csa_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock stop request
 */
class csr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus monitoring mode Bit MON can only be set by software when both CCE and INIT are set to 1. The bit can be reset by the Host at any time.
 */
class mon_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable automatic retransmission
 */
class dar_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dar_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Test mode enable
 */
class test_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr test_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FD operation enable
 */
class fdoe_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fdoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FDCAN bit rate switching
 */
class brse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr brse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol exception handling disable
 */
class pxhd_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pxhd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Edge filtering during bus integration
 */
class efbi_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr efbi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * If this bit is set, the FDCAN pauses for two CAN bit times before starting the next transmission after successfully transmitting a frame.
 */
class txp_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Non ISO operation If this bit is set, the FDCAN uses the CAN FD frame format as specified by the Bosch CAN FD Specification V1.0.
 */
class niso_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr niso_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_cccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_cccr_r>() const {return opsy::utility::clear_set<fdcan_cccr_r>(mask, *this);}
	constexpr auto operator|(fdcan_cccr_r other) const -> fdcan_cccr_r { return static_cast<fdcan_cccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_cccr_r> other) const -> opsy::utility::clear_set<fdcan_cccr_r> {return opsy::utility::clear_set<fdcan_cccr_r>(fdcan_cccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto init() const -> init_f {return init_f((value_ & init_f::mask) != 0);}
	[[nodiscard]] constexpr auto cce() const -> cce_f {return cce_f((value_ & cce_f::mask) != 0);}
	[[nodiscard]] constexpr auto _asm() const -> asm_f {return asm_f((value_ & asm_f::mask) != 0);}
	[[nodiscard]] constexpr auto csa() const -> csa_f {return csa_f((value_ & csa_f::mask) != 0);}
	[[nodiscard]] constexpr auto csr() const -> csr_f {return csr_f((value_ & csr_f::mask) != 0);}
	[[nodiscard]] constexpr auto mon() const -> mon_f {return mon_f((value_ & mon_f::mask) != 0);}
	[[nodiscard]] constexpr auto dar() const -> dar_f {return dar_f((value_ & dar_f::mask) != 0);}
	[[nodiscard]] constexpr auto test() const -> test_f {return test_f((value_ & test_f::mask) != 0);}
	[[nodiscard]] constexpr auto fdoe() const -> fdoe_f {return fdoe_f((value_ & fdoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto brse() const -> brse_f {return brse_f((value_ & brse_f::mask) != 0);}
	[[nodiscard]] constexpr auto pxhd() const -> pxhd_f {return pxhd_f((value_ & pxhd_f::mask) != 0);}
	[[nodiscard]] constexpr auto efbi() const -> efbi_f {return efbi_f((value_ & efbi_f::mask) != 0);}
	[[nodiscard]] constexpr auto txp() const -> txp_f {return txp_f((value_ & txp_f::mask) != 0);}
	[[nodiscard]] constexpr auto niso() const -> niso_f {return niso_f((value_ & niso_f::mask) != 0);}

	constexpr fdcan_cccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_cccr_r other) const -> fdcan_cccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_cccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * FDCAN nominal bit timing and prescaler register 
 */
class fdcan_nbtp_r {
public:

/**
 * Nominal time segment after sample point Valid values are 0 to 127. The actual interpretation by the hardware of this value is such that one more than the programmed value is used.
 */
class ntseg2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ntseg2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_nbtp_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_nbtp_r>() const {return opsy::utility::clear_set<fdcan_nbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_nbtp_r other) const -> fdcan_nbtp_r { return static_cast<fdcan_nbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_nbtp_r> other) const -> opsy::utility::clear_set<fdcan_nbtp_r> {return opsy::utility::clear_set<fdcan_nbtp_r>(fdcan_nbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Nominal time segment before sample point Valid values are 0 to 255. The actual interpretation by the hardware of this value is such that one more than the programmed value is used. These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class ntseg1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ntseg1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_nbtp_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_nbtp_r>() const {return opsy::utility::clear_set<fdcan_nbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_nbtp_r other) const -> fdcan_nbtp_r { return static_cast<fdcan_nbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_nbtp_r> other) const -> opsy::utility::clear_set<fdcan_nbtp_r> {return opsy::utility::clear_set<fdcan_nbtp_r>(fdcan_nbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bit rate prescaler Value by which the oscillator frequency is divided for generating the bit time quanta. The bit time is built up from a multiple of this quanta. Valid values are 0 to 511. The actual interpretation by the hardware of this value is such that one more than the value programmed here is used. These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class nbrp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nbrp_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fdcan_nbtp_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_nbtp_r>() const {return opsy::utility::clear_set<fdcan_nbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_nbtp_r other) const -> fdcan_nbtp_r { return static_cast<fdcan_nbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_nbtp_r> other) const -> opsy::utility::clear_set<fdcan_nbtp_r> {return opsy::utility::clear_set<fdcan_nbtp_r>(fdcan_nbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Nominal (re)synchronization jump width Valid values are 0 to 127. The actual interpretation by the hardware of this value is such that the used value is the one programmed incremented by one. These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class nsjw_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nsjw_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_nbtp_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_nbtp_r>() const {return opsy::utility::clear_set<fdcan_nbtp_r>(mask, *this);}
	constexpr auto operator|(fdcan_nbtp_r other) const -> fdcan_nbtp_r { return static_cast<fdcan_nbtp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_nbtp_r> other) const -> opsy::utility::clear_set<fdcan_nbtp_r> {return opsy::utility::clear_set<fdcan_nbtp_r>(fdcan_nbtp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ntseg2() const -> ntseg2_f {return ntseg2_f(static_cast<uint8_t>(value_ >> ntseg2_f::offset));}
	[[nodiscard]] constexpr auto ntseg1() const -> ntseg1_f {return ntseg1_f(static_cast<uint8_t>(value_ >> ntseg1_f::offset));}
	[[nodiscard]] constexpr auto nbrp() const -> nbrp_f {return nbrp_f(static_cast<uint16_t>(value_ >> nbrp_f::offset));}
	[[nodiscard]] constexpr auto nsjw() const -> nsjw_f {return nsjw_f(static_cast<uint8_t>(value_ >> nsjw_f::offset));}

	constexpr fdcan_nbtp_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_nbtp_r other) const -> fdcan_nbtp_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_nbtp_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b110000000000000101000000011; // 100665859 0x6000A03

private:
	uint32_t value_;
};

/**
 * FDCAN timestamp counter configuration register 
 */
class fdcan_tscc_r {
public:

/**
 * Timestamp select These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tss_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_tscc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tscc_r>() const {return opsy::utility::clear_set<fdcan_tscc_r>(mask, *this);}
	constexpr auto operator|(fdcan_tscc_r other) const -> fdcan_tscc_r { return static_cast<fdcan_tscc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tscc_r> other) const -> opsy::utility::clear_set<fdcan_tscc_r> {return opsy::utility::clear_set<fdcan_tscc_r>(fdcan_tscc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timestamp counter prescaler Configures the timestamp and timeout counters time unit in multiples of CAN bit times [1 16]. The actual interpretation by the hardware of this value is such that one more than the value programmed here is used. In CAN FD mode the internal timestamp counter TCP does not provide a constant time base due to the different CAN bit times between arbitration phase and data phase. Thus CAN FD requires an external counter for timestamp generation (TSS = 10). These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tcp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tcp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_tscc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tscc_r>() const {return opsy::utility::clear_set<fdcan_tscc_r>(mask, *this);}
	constexpr auto operator|(fdcan_tscc_r other) const -> fdcan_tscc_r { return static_cast<fdcan_tscc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tscc_r> other) const -> opsy::utility::clear_set<fdcan_tscc_r> {return opsy::utility::clear_set<fdcan_tscc_r>(fdcan_tscc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tss() const -> tss_f {return tss_f(static_cast<uint8_t>(value_ >> tss_f::offset));}
	[[nodiscard]] constexpr auto tcp() const -> tcp_f {return tcp_f(static_cast<uint8_t>(value_ >> tcp_f::offset));}

	constexpr fdcan_tscc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_tscc_r other) const -> fdcan_tscc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_tscc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN timestamp counter value register 
 */
class fdcan_tscv_r {
public:

/**
 * Timestamp counter The internal/external timestamp counter value is captured on start of frame (both Rx and Tx). When TSCC[TSS] = 01, the timestamp counter is incremented in multiples of CAN bit times [1 16] depending on the configuration of TSCC[TCP]. A wrap around sets interrupt flag IR[TSW]. Write access resets the counter to 0. When TSCC.TSS = 10, TSC reflects the external timestamp counter value. A write access has no impact.
 */
class tsc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tsc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fdcan_tscv_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tscv_r>() const {return opsy::utility::clear_set<fdcan_tscv_r>(mask, *this);}
	constexpr auto operator|(fdcan_tscv_r other) const -> fdcan_tscv_r { return static_cast<fdcan_tscv_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tscv_r> other) const -> opsy::utility::clear_set<fdcan_tscv_r> {return opsy::utility::clear_set<fdcan_tscv_r>(fdcan_tscv_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tsc() const -> tsc_f {return tsc_f(static_cast<uint16_t>(value_ >> tsc_f::offset));}

	constexpr fdcan_tscv_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_tscv_r other) const -> fdcan_tscv_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_tscv_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN timeout counter configuration register 
 */
class fdcan_tocc_r {
public:

/**
 * Timeout counter enable This is a protected write (P) bit, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class etoc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr etoc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_tocc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_tocc_r>() const {return opsy::utility::clear_set<fdcan_tocc_r>(mask, *this);}
	constexpr auto operator|(fdcan_tocc_r other) const -> fdcan_tocc_r { return static_cast<fdcan_tocc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tocc_r> other) const -> opsy::utility::clear_set<fdcan_tocc_r> {return opsy::utility::clear_set<fdcan_tocc_r>(fdcan_tocc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout select When operating in Continuous mode, a write to TOCV presets the counter to the value configured by TOCC[TOP] and continues down-counting. When the timeout counter is controlled by one of the FIFOs, an empty FIFO presets the counter to the value configured by TOCC[TOP]. Down-counting is started when the first FIFO element is stored. These are protected write (P) bits, write access is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tos_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_tocc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tocc_r>() const {return opsy::utility::clear_set<fdcan_tocc_r>(mask, *this);}
	constexpr auto operator|(fdcan_tocc_r other) const -> fdcan_tocc_r { return static_cast<fdcan_tocc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tocc_r> other) const -> opsy::utility::clear_set<fdcan_tocc_r> {return opsy::utility::clear_set<fdcan_tocc_r>(fdcan_tocc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timeout period Start value of the timeout counter (down-counter). Configures the timeout period.
 */
class top_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr top_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fdcan_tocc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tocc_r>() const {return opsy::utility::clear_set<fdcan_tocc_r>(mask, *this);}
	constexpr auto operator|(fdcan_tocc_r other) const -> fdcan_tocc_r { return static_cast<fdcan_tocc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tocc_r> other) const -> opsy::utility::clear_set<fdcan_tocc_r> {return opsy::utility::clear_set<fdcan_tocc_r>(fdcan_tocc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto etoc() const -> etoc_f {return etoc_f((value_ & etoc_f::mask) != 0);}
	[[nodiscard]] constexpr auto tos() const -> tos_f {return tos_f(static_cast<uint8_t>(value_ >> tos_f::offset));}
	[[nodiscard]] constexpr auto top() const -> top_f {return top_f(static_cast<uint16_t>(value_ >> top_f::offset));}

	constexpr fdcan_tocc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_tocc_r other) const -> fdcan_tocc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_tocc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111110000000000000000; // 4294901760 0xFFFF0000

private:
	uint32_t value_;
};

/**
 * FDCAN timeout counter value register 
 */
class fdcan_tocv_r {
public:

/**
 * Timeout counter The timeout counter is decremented in multiples of CAN bit times [1 16] depending on the configuration of TSCC.TCP. When decremented to 0, interrupt flag IR.TOO is set and the timeout counter is stopped. Start and reset/restart conditions are configured via TOCC.TOS.
 */
class toc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr toc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fdcan_tocv_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tocv_r>() const {return opsy::utility::clear_set<fdcan_tocv_r>(mask, *this);}
	constexpr auto operator|(fdcan_tocv_r other) const -> fdcan_tocv_r { return static_cast<fdcan_tocv_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tocv_r> other) const -> opsy::utility::clear_set<fdcan_tocv_r> {return opsy::utility::clear_set<fdcan_tocv_r>(fdcan_tocv_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto toc() const -> toc_f {return toc_f(static_cast<uint16_t>(value_ >> toc_f::offset));}

	constexpr fdcan_tocv_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_tocv_r other) const -> fdcan_tocv_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_tocv_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111; // 65535 0xFFFF

private:
	uint32_t value_;
};

/**
 * FDCAN error counter register 
 */
class fdcan_ecr_r {
public:

/**
 * Transmit error counter Actual state of the transmit error counter, values between 0 and 255. When CCCR.ASM is set, the CAN protocol controller does not increment TEC and REC when a CAN protocol error is detected, but CEL is still incremented.
 */
class tec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_ecr_r>() const {return opsy::utility::clear_set<fdcan_ecr_r>(mask, *this);}
	constexpr auto operator|(fdcan_ecr_r other) const -> fdcan_ecr_r { return static_cast<fdcan_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ecr_r> other) const -> opsy::utility::clear_set<fdcan_ecr_r> {return opsy::utility::clear_set<fdcan_ecr_r>(fdcan_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receive error counter Actual state of the receive error counter, values between 0 and 127.
 */
class rec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rec_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_ecr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_ecr_r>() const {return opsy::utility::clear_set<fdcan_ecr_r>(mask, *this);}
	constexpr auto operator|(fdcan_ecr_r other) const -> fdcan_ecr_r { return static_cast<fdcan_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ecr_r> other) const -> opsy::utility::clear_set<fdcan_ecr_r> {return opsy::utility::clear_set<fdcan_ecr_r>(fdcan_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receive error passive
 */
class rp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ecr_r>() const {return opsy::utility::clear_set<fdcan_ecr_r>(mask, *this);}
	constexpr auto operator|(fdcan_ecr_r other) const -> fdcan_ecr_r { return static_cast<fdcan_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ecr_r> other) const -> opsy::utility::clear_set<fdcan_ecr_r> {return opsy::utility::clear_set<fdcan_ecr_r>(fdcan_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CAN error logging The counter is incremented each time when a CAN protocol error causes the transmit error counter or the receive error counter to be incremented. It is reset by read access to CEL. The counter stops at 0xFF; the next increment of TEC or REC sets interrupt flag IR[ELO]. Access type is RX: reset on read.
 */
class cel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cel_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_ecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_ecr_r>() const {return opsy::utility::clear_set<fdcan_ecr_r>(mask, *this);}
	constexpr auto operator|(fdcan_ecr_r other) const -> fdcan_ecr_r { return static_cast<fdcan_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ecr_r> other) const -> opsy::utility::clear_set<fdcan_ecr_r> {return opsy::utility::clear_set<fdcan_ecr_r>(fdcan_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tec() const -> tec_f {return tec_f(static_cast<uint8_t>(value_ >> tec_f::offset));}
	[[nodiscard]] constexpr auto rec() const -> rec_f {return rec_f(static_cast<uint8_t>(value_ >> rec_f::offset));}
	[[nodiscard]] constexpr auto rp() const -> rp_f {return rp_f((value_ & rp_f::mask) != 0);}
	[[nodiscard]] constexpr auto cel() const -> cel_f {return cel_f(static_cast<uint8_t>(value_ >> cel_f::offset));}

	constexpr fdcan_ecr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ecr_r other) const -> fdcan_ecr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ecr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN protocol status register 
 */
class fdcan_psr_r {
public:

/**
 * Last error code The LEC indicates the type of the last error to occur on the CAN bus. This field is cleared to 0 when a message has been transferred (reception or transmission) without error. Access type is RS: set on read.
 */
class lec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr lec_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_psr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Activity Monitors the module's CAN communication state.
 */
class act_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr act_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_psr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Error passive
 */
class ep_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Warning Sstatus
 */
class ew_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ew_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus_Off status
 */
class bo_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data last error code Type of last error that occurred in the data phase of a FDCAN format frame with its BRS flag set. Coding is the same as for LEC. This field is cleared to 0 when a FDCAN format frame with its BRS flag set has been transferred (reception or transmission) without error. Access type is RS: set on read.
 */
class dlec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dlec_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_psr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ESI flag of last received FDCAN message This bit is set together with REDL, independent of acceptance filtering. Access type is RX: reset on read.
 */
class resi_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr resi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BRS flag of last received FDCAN message This bit is set together with REDL, independent of acceptance filtering. Access type is RX: reset on read.
 */
class rbrs_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rbrs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received FDCAN message This bit is set independent of acceptance filtering. Access type is RX: reset on read.
 */
class redl_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr redl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol exception event
 */
class pxe_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pxe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_psr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter delay compensation value Position of the secondary sample point, defined by the sum of the measured delay from FDCAN_TX to FDCAN_RX and TDCR.TDCO. The SSP position is, in the data phase, the number of minimum time quanta (mtq) between the start of the transmitted bit and the secondary sample point. Valid values are 0 to 127 mtq.
 */
class tdcv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdcv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_psr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_psr_r>() const {return opsy::utility::clear_set<fdcan_psr_r>(mask, *this);}
	constexpr auto operator|(fdcan_psr_r other) const -> fdcan_psr_r { return static_cast<fdcan_psr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_psr_r> other) const -> opsy::utility::clear_set<fdcan_psr_r> {return opsy::utility::clear_set<fdcan_psr_r>(fdcan_psr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lec() const -> lec_f {return lec_f(static_cast<uint8_t>(value_ >> lec_f::offset));}
	[[nodiscard]] constexpr auto act() const -> act_f {return act_f(static_cast<uint8_t>(value_ >> act_f::offset));}
	[[nodiscard]] constexpr auto ep() const -> ep_f {return ep_f((value_ & ep_f::mask) != 0);}
	[[nodiscard]] constexpr auto ew() const -> ew_f {return ew_f((value_ & ew_f::mask) != 0);}
	[[nodiscard]] constexpr auto bo() const -> bo_f {return bo_f((value_ & bo_f::mask) != 0);}
	[[nodiscard]] constexpr auto dlec() const -> dlec_f {return dlec_f(static_cast<uint8_t>(value_ >> dlec_f::offset));}
	[[nodiscard]] constexpr auto resi() const -> resi_f {return resi_f((value_ & resi_f::mask) != 0);}
	[[nodiscard]] constexpr auto rbrs() const -> rbrs_f {return rbrs_f((value_ & rbrs_f::mask) != 0);}
	[[nodiscard]] constexpr auto redl() const -> redl_f {return redl_f((value_ & redl_f::mask) != 0);}
	[[nodiscard]] constexpr auto pxe() const -> pxe_f {return pxe_f((value_ & pxe_f::mask) != 0);}
	[[nodiscard]] constexpr auto tdcv() const -> tdcv_f {return tdcv_f(static_cast<uint8_t>(value_ >> tdcv_f::offset));}

	constexpr fdcan_psr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_psr_r other) const -> fdcan_psr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_psr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11100000111; // 1799 0x707

private:
	uint32_t value_;
};

/**
 * FDCAN transmitter delay compensation register 
 */
class fdcan_tdcr_r {
public:

/**
 * Transmitter delay compensation filter window length Defines the minimum value for the SSP position, dominant edges on FDCAN_RX that would result in an earlier SSP position are ignored for transmitter delay measurements. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tdcf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tdcf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_tdcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tdcr_r>() const {return opsy::utility::clear_set<fdcan_tdcr_r>(mask, *this);}
	constexpr auto operator|(fdcan_tdcr_r other) const -> fdcan_tdcr_r { return static_cast<fdcan_tdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tdcr_r> other) const -> opsy::utility::clear_set<fdcan_tdcr_r> {return opsy::utility::clear_set<fdcan_tdcr_r>(fdcan_tdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transmitter delay compensation offset Offset value defining the distance between the measured delay from FDCAN_TX to FDCAN_RX and the secondary sample point. Valid values are 0 to 127 mtq. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tdco_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdco_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_tdcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_tdcr_r>() const {return opsy::utility::clear_set<fdcan_tdcr_r>(mask, *this);}
	constexpr auto operator|(fdcan_tdcr_r other) const -> fdcan_tdcr_r { return static_cast<fdcan_tdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_tdcr_r> other) const -> opsy::utility::clear_set<fdcan_tdcr_r> {return opsy::utility::clear_set<fdcan_tdcr_r>(fdcan_tdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tdcf() const -> tdcf_f {return tdcf_f(static_cast<uint8_t>(value_ >> tdcf_f::offset));}
	[[nodiscard]] constexpr auto tdco() const -> tdco_f {return tdco_f(static_cast<uint8_t>(value_ >> tdco_f::offset));}

	constexpr fdcan_tdcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_tdcr_r other) const -> fdcan_tdcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_tdcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN interrupt register 
 */
class fdcan_ir_r {
public:

/**
 * Rx FIFO 0 new message
 */
class rf0n_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 0 full
 */
class rf0f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 0 message lost
 */
class rf0l_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0l_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 new message
 */
class rf1n_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 full
 */
class rf1f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 message lost
 */
class rf1l_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1l_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High-priority message
 */
class hpm_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hpm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission completed
 */
class tc_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission cancellation finished
 */
class tcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO empty
 */
class tfe_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO New Entry
 */
class tefn_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tefn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO full
 */
class teff_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr teff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO element lost
 */
class tefl_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tefl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp wraparound
 */
class tsw_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Message RAM access failure The flag is set when the Rx handler: has not completed acceptance filtering or storage of an accepted message until the arbitration field of the following message has been received. In this case acceptance filtering or message storage is aborted and the Rx handler starts processing of the following message. was unable to write a message to the message RAM. In this case message storage is aborted. In both cases the FIFO put index is not updated. The partly stored message is overwritten when the next message is stored to this location. The flag is also set when the Tx Handler was not able to read a message from the Message RAM in time. In this case message transmission is aborted. In case of a Tx Handler access failure the FDCAN is switched into Restricted operation Mode (see mode). To leave Restricted operation Mode, the Host CPU has to reset CCCR.ASM.
 */
class mraf_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mraf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout occurred
 */
class too_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr too_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error logging overflow
 */
class elo_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr elo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error passive
 */
class ep_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Warning status
 */
class ew_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ew_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus_Off status
 */
class bo_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog interrupt
 */
class wdi_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wdi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol error in arbitration phase (nominal bit time is used)
 */
class pea_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pea_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol error in data phase (data bit time is used)
 */
class ped_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ped_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Access to reserved address
 */
class ara_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ara_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ir_r>() const {return opsy::utility::clear_set<fdcan_ir_r>(mask, *this);}
	constexpr auto operator|(fdcan_ir_r other) const -> fdcan_ir_r { return static_cast<fdcan_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ir_r> other) const -> opsy::utility::clear_set<fdcan_ir_r> {return opsy::utility::clear_set<fdcan_ir_r>(fdcan_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rf0n() const -> rf0n_f {return rf0n_f((value_ & rf0n_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf0f() const -> rf0f_f {return rf0f_f((value_ & rf0f_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf0l() const -> rf0l_f {return rf0l_f((value_ & rf0l_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1n() const -> rf1n_f {return rf1n_f((value_ & rf1n_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1f() const -> rf1f_f {return rf1f_f((value_ & rf1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1l() const -> rf1l_f {return rf1l_f((value_ & rf1l_f::mask) != 0);}
	[[nodiscard]] constexpr auto hpm() const -> hpm_f {return hpm_f((value_ & hpm_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcf() const -> tcf_f {return tcf_f((value_ & tcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tfe() const -> tfe_f {return tfe_f((value_ & tfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto tefn() const -> tefn_f {return tefn_f((value_ & tefn_f::mask) != 0);}
	[[nodiscard]] constexpr auto teff() const -> teff_f {return teff_f((value_ & teff_f::mask) != 0);}
	[[nodiscard]] constexpr auto tefl() const -> tefl_f {return tefl_f((value_ & tefl_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsw() const -> tsw_f {return tsw_f((value_ & tsw_f::mask) != 0);}
	[[nodiscard]] constexpr auto mraf() const -> mraf_f {return mraf_f((value_ & mraf_f::mask) != 0);}
	[[nodiscard]] constexpr auto too() const -> too_f {return too_f((value_ & too_f::mask) != 0);}
	[[nodiscard]] constexpr auto elo() const -> elo_f {return elo_f((value_ & elo_f::mask) != 0);}
	[[nodiscard]] constexpr auto ep() const -> ep_f {return ep_f((value_ & ep_f::mask) != 0);}
	[[nodiscard]] constexpr auto ew() const -> ew_f {return ew_f((value_ & ew_f::mask) != 0);}
	[[nodiscard]] constexpr auto bo() const -> bo_f {return bo_f((value_ & bo_f::mask) != 0);}
	[[nodiscard]] constexpr auto wdi() const -> wdi_f {return wdi_f((value_ & wdi_f::mask) != 0);}
	[[nodiscard]] constexpr auto pea() const -> pea_f {return pea_f((value_ & pea_f::mask) != 0);}
	[[nodiscard]] constexpr auto ped() const -> ped_f {return ped_f((value_ & ped_f::mask) != 0);}
	[[nodiscard]] constexpr auto ara() const -> ara_f {return ara_f((value_ & ara_f::mask) != 0);}

	constexpr fdcan_ir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ir_r other) const -> fdcan_ir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN interrupt enable register 
 */
class fdcan_ie_r {
public:

/**
 * Rx FIFO 0 new message interrupt enable
 */
class rf0ne_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 0 full interrupt enable
 */
class rf0fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 0 message lost interrupt enable
 */
class rf0le_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf0le_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 new message interrupt enable
 */
class rf1ne_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 full interrupt enable
 */
class rf1fe_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 message lost interrupt enable
 */
class rf1le_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rf1le_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High-priority message interrupt enable
 */
class hpme_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hpme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission completed interrupt enable
 */
class tce_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission cancellation finished interrupt enable
 */
class tcfe_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO empty interrupt enable
 */
class tfee_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tfee_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO new entry interrupt enable
 */
class tefne_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tefne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO full interrupt enable
 */
class teffe_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr teffe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO element lost interrupt enable
 */
class tefle_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tefle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp wraparound interrupt enable
 */
class tswe_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tswe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Message RAM access failure interrupt enable
 */
class mrafe_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mrafe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout occurred interrupt enable
 */
class tooe_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tooe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error logging overflow interrupt enable
 */
class eloe_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eloe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error passive interrupt enable
 */
class epe_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr epe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Warning status interrupt enable
 */
class ewe_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ewe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus_Off status
 */
class boe_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr boe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog interrupt enable
 */
class wdie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol error in arbitration phase enable
 */
class peae_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr peae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol error in data phase enable
 */
class pede_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pede_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Access to reserved address enable
 */
class arae_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr arae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ie_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ie_r>() const {return opsy::utility::clear_set<fdcan_ie_r>(mask, *this);}
	constexpr auto operator|(fdcan_ie_r other) const -> fdcan_ie_r { return static_cast<fdcan_ie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ie_r> other) const -> opsy::utility::clear_set<fdcan_ie_r> {return opsy::utility::clear_set<fdcan_ie_r>(fdcan_ie_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rf0ne() const -> rf0ne_f {return rf0ne_f((value_ & rf0ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf0fe() const -> rf0fe_f {return rf0fe_f((value_ & rf0fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf0le() const -> rf0le_f {return rf0le_f((value_ & rf0le_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1ne() const -> rf1ne_f {return rf1ne_f((value_ & rf1ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1fe() const -> rf1fe_f {return rf1fe_f((value_ & rf1fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1le() const -> rf1le_f {return rf1le_f((value_ & rf1le_f::mask) != 0);}
	[[nodiscard]] constexpr auto hpme() const -> hpme_f {return hpme_f((value_ & hpme_f::mask) != 0);}
	[[nodiscard]] constexpr auto tce() const -> tce_f {return tce_f((value_ & tce_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcfe() const -> tcfe_f {return tcfe_f((value_ & tcfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto tfee() const -> tfee_f {return tfee_f((value_ & tfee_f::mask) != 0);}
	[[nodiscard]] constexpr auto tefne() const -> tefne_f {return tefne_f((value_ & tefne_f::mask) != 0);}
	[[nodiscard]] constexpr auto teffe() const -> teffe_f {return teffe_f((value_ & teffe_f::mask) != 0);}
	[[nodiscard]] constexpr auto tefle() const -> tefle_f {return tefle_f((value_ & tefle_f::mask) != 0);}
	[[nodiscard]] constexpr auto tswe() const -> tswe_f {return tswe_f((value_ & tswe_f::mask) != 0);}
	[[nodiscard]] constexpr auto mrafe() const -> mrafe_f {return mrafe_f((value_ & mrafe_f::mask) != 0);}
	[[nodiscard]] constexpr auto tooe() const -> tooe_f {return tooe_f((value_ & tooe_f::mask) != 0);}
	[[nodiscard]] constexpr auto eloe() const -> eloe_f {return eloe_f((value_ & eloe_f::mask) != 0);}
	[[nodiscard]] constexpr auto epe() const -> epe_f {return epe_f((value_ & epe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ewe() const -> ewe_f {return ewe_f((value_ & ewe_f::mask) != 0);}
	[[nodiscard]] constexpr auto boe() const -> boe_f {return boe_f((value_ & boe_f::mask) != 0);}
	[[nodiscard]] constexpr auto wdie() const -> wdie_f {return wdie_f((value_ & wdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto peae() const -> peae_f {return peae_f((value_ & peae_f::mask) != 0);}
	[[nodiscard]] constexpr auto pede() const -> pede_f {return pede_f((value_ & pede_f::mask) != 0);}
	[[nodiscard]] constexpr auto arae() const -> arae_f {return arae_f((value_ & arae_f::mask) != 0);}

	constexpr fdcan_ie_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ie_r other) const -> fdcan_ie_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ie_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN interrupt line select register 
 */
class fdcan_ils_r {
public:

/**
 * RX FIFO bit grouping the following interruption RF0LL: Rx FIFO 0 message lost interrupt line RF0FL: Rx FIFO 0 full interrupt line RF0NL: Rx FIFO 0 new message interrupt line
 */
class rxfifo0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfifo0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX FIFO bit grouping the following interruption RF1LL: Rx FIFO 1 message lost interrupt line RF1FL: Rx FIFO 1 full Interrupt line RF1NL: Rx FIFO 1 new message interrupt line
 */
class rxfifo1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfifo1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status message bit grouping the following interruption TCFL: Transmission cancellation finished interrupt line TCL: Transmission completed interrupt line HPML: High-priority message interrupt line
 */
class smsg_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr smsg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx FIFO ERROR grouping the following interruption TEFLL: Tx event FIFO element lost interrupt line TEFFL: Tx event FIFO full interrupt line TEFNL: Tx event FIFO new entry interrupt line TFEL: Tx FIFO empty interrupt line
 */
class tferr_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tferr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt regrouping the following interruption TOOL: Timeout occurred interrupt line MRAFL: Message RAM access failure interrupt line TSWL: Timestamp wraparound interrupt line
 */
class misc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr misc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bit and line error grouping the following interruption EPL Error passive interrupt line ELOL: Error logging overflow interrupt line
 */
class berr_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr berr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Protocol error grouping the following interruption ARAL: Access to reserved address line PEDL: Protocol error in data phase line PEAL: Protocol error in arbitration phase line WDIL: Watchdog interrupt line BOL: Bus_Off status EWL: Warning status interrupt line
 */
class perr_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr perr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ils_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ils_r>() const {return opsy::utility::clear_set<fdcan_ils_r>(mask, *this);}
	constexpr auto operator|(fdcan_ils_r other) const -> fdcan_ils_r { return static_cast<fdcan_ils_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ils_r> other) const -> opsy::utility::clear_set<fdcan_ils_r> {return opsy::utility::clear_set<fdcan_ils_r>(fdcan_ils_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rxfifo0() const -> rxfifo0_f {return rxfifo0_f((value_ & rxfifo0_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfifo1() const -> rxfifo1_f {return rxfifo1_f((value_ & rxfifo1_f::mask) != 0);}
	[[nodiscard]] constexpr auto smsg() const -> smsg_f {return smsg_f((value_ & smsg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tferr() const -> tferr_f {return tferr_f((value_ & tferr_f::mask) != 0);}
	[[nodiscard]] constexpr auto misc() const -> misc_f {return misc_f((value_ & misc_f::mask) != 0);}
	[[nodiscard]] constexpr auto berr() const -> berr_f {return berr_f((value_ & berr_f::mask) != 0);}
	[[nodiscard]] constexpr auto perr() const -> perr_f {return perr_f((value_ & perr_f::mask) != 0);}

	constexpr fdcan_ils_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ils_r other) const -> fdcan_ils_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ils_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN interrupt line enable register 
 */
class fdcan_ile_r {
public:

/**
 * Enable interrupt line 0
 */
class eint0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eint0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ile_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ile_r>() const {return opsy::utility::clear_set<fdcan_ile_r>(mask, *this);}
	constexpr auto operator|(fdcan_ile_r other) const -> fdcan_ile_r { return static_cast<fdcan_ile_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ile_r> other) const -> opsy::utility::clear_set<fdcan_ile_r> {return opsy::utility::clear_set<fdcan_ile_r>(fdcan_ile_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable interrupt line 1
 */
class eint1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eint1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_ile_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_ile_r>() const {return opsy::utility::clear_set<fdcan_ile_r>(mask, *this);}
	constexpr auto operator|(fdcan_ile_r other) const -> fdcan_ile_r { return static_cast<fdcan_ile_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ile_r> other) const -> opsy::utility::clear_set<fdcan_ile_r> {return opsy::utility::clear_set<fdcan_ile_r>(fdcan_ile_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto eint0() const -> eint0_f {return eint0_f((value_ & eint0_f::mask) != 0);}
	[[nodiscard]] constexpr auto eint1() const -> eint1_f {return eint1_f((value_ & eint1_f::mask) != 0);}

	constexpr fdcan_ile_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ile_r other) const -> fdcan_ile_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ile_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN global filter configuration register 
 */
class fdcan_rxgfc_r {
public:

/**
 * Reject remote frames extended These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class rrfe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rrfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reject remote frames standard These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class rrfs_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rrfs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Accept non-matching frames extended Defines how received messages with 29-bit IDs that do not match any element of the filter list are treated. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class anfe_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr anfe_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Accept Non-matching frames standard Defines how received messages with 11-bit IDs that do not match any element of the filter list are treated. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class anfs_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr anfs_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FIFO 1 operation mode (overwrite or blocking) This is a protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class f1om_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr f1om_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO 0 operation mode (overwrite or blocking) This is protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class f0om_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr f0om_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * List size standard 28: Values greater than 28 are interpreted as 28. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class lss_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lss_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * List size extended 8: Values greater than 8 are interpreted as 8. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class lse_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lse_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxgfc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxgfc_r>() const {return opsy::utility::clear_set<fdcan_rxgfc_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return static_cast<fdcan_rxgfc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxgfc_r> other) const -> opsy::utility::clear_set<fdcan_rxgfc_r> {return opsy::utility::clear_set<fdcan_rxgfc_r>(fdcan_rxgfc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rrfe() const -> rrfe_f {return rrfe_f((value_ & rrfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rrfs() const -> rrfs_f {return rrfs_f((value_ & rrfs_f::mask) != 0);}
	[[nodiscard]] constexpr auto anfe() const -> anfe_f {return anfe_f(static_cast<uint8_t>(value_ >> anfe_f::offset));}
	[[nodiscard]] constexpr auto anfs() const -> anfs_f {return anfs_f(static_cast<uint8_t>(value_ >> anfs_f::offset));}
	[[nodiscard]] constexpr auto f1om() const -> f1om_f {return f1om_f((value_ & f1om_f::mask) != 0);}
	[[nodiscard]] constexpr auto f0om() const -> f0om_f {return f0om_f((value_ & f0om_f::mask) != 0);}
	[[nodiscard]] constexpr auto lss() const -> lss_f {return lss_f(static_cast<uint8_t>(value_ >> lss_f::offset));}
	[[nodiscard]] constexpr auto lse() const -> lse_f {return lse_f(static_cast<uint8_t>(value_ >> lse_f::offset));}

	constexpr fdcan_rxgfc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rxgfc_r other) const -> fdcan_rxgfc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rxgfc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN extended ID and mask register 
 */
class fdcan_xidam_r {
public:

/**
 * Extended ID mask For acceptance filtering of extended frames the Extended ID AND Mask is AND-ed with the Message ID of a received frame. Intended for masking of 29-bit IDs in SAE J1939. With the reset value of all bits set to 1 the mask is not active. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class eidm_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 29;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr eidm_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator fdcan_xidam_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_xidam_r>() const {return opsy::utility::clear_set<fdcan_xidam_r>(mask, *this);}
	constexpr auto operator|(fdcan_xidam_r other) const -> fdcan_xidam_r { return static_cast<fdcan_xidam_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_xidam_r> other) const -> opsy::utility::clear_set<fdcan_xidam_r> {return opsy::utility::clear_set<fdcan_xidam_r>(fdcan_xidam_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto eidm() const -> eidm_f {return eidm_f(static_cast<uint32_t>(value_ >> eidm_f::offset));}

	constexpr fdcan_xidam_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_xidam_r other) const -> fdcan_xidam_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_xidam_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111; // 536870911 0x1FFFFFFF

private:
	uint32_t value_;
};

/**
 * FDCAN high-priority message status register 
 */
class fdcan_hpms_r {
public:

/**
 * Buffer index Index of Rx FIFO element to which the message was stored. Only valid when MSI[1] = 1.
 */
class bidx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr bidx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_hpms_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_hpms_r>() const {return opsy::utility::clear_set<fdcan_hpms_r>(mask, *this);}
	constexpr auto operator|(fdcan_hpms_r other) const -> fdcan_hpms_r { return static_cast<fdcan_hpms_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_hpms_r> other) const -> opsy::utility::clear_set<fdcan_hpms_r> {return opsy::utility::clear_set<fdcan_hpms_r>(fdcan_hpms_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Message storage indicator
 */
class msi_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr msi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_hpms_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_hpms_r>() const {return opsy::utility::clear_set<fdcan_hpms_r>(mask, *this);}
	constexpr auto operator|(fdcan_hpms_r other) const -> fdcan_hpms_r { return static_cast<fdcan_hpms_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_hpms_r> other) const -> opsy::utility::clear_set<fdcan_hpms_r> {return opsy::utility::clear_set<fdcan_hpms_r>(fdcan_hpms_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Filter index Index of matching filter element. Range is 0 to RXGFC[LSS]1 or RXGFC[LSE]1.
 */
class fidx_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fidx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_hpms_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_hpms_r>() const {return opsy::utility::clear_set<fdcan_hpms_r>(mask, *this);}
	constexpr auto operator|(fdcan_hpms_r other) const -> fdcan_hpms_r { return static_cast<fdcan_hpms_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_hpms_r> other) const -> opsy::utility::clear_set<fdcan_hpms_r> {return opsy::utility::clear_set<fdcan_hpms_r>(fdcan_hpms_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Filter list Indicates the filter list of the matching filter element.
 */
class flst_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr flst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_hpms_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_hpms_r>() const {return opsy::utility::clear_set<fdcan_hpms_r>(mask, *this);}
	constexpr auto operator|(fdcan_hpms_r other) const -> fdcan_hpms_r { return static_cast<fdcan_hpms_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_hpms_r> other) const -> opsy::utility::clear_set<fdcan_hpms_r> {return opsy::utility::clear_set<fdcan_hpms_r>(fdcan_hpms_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bidx() const -> bidx_f {return bidx_f(static_cast<uint8_t>(value_ >> bidx_f::offset));}
	[[nodiscard]] constexpr auto msi() const -> msi_f {return msi_f(static_cast<uint8_t>(value_ >> msi_f::offset));}
	[[nodiscard]] constexpr auto fidx() const -> fidx_f {return fidx_f(static_cast<uint8_t>(value_ >> fidx_f::offset));}
	[[nodiscard]] constexpr auto flst() const -> flst_f {return flst_f((value_ & flst_f::mask) != 0);}

	constexpr fdcan_hpms_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_hpms_r other) const -> fdcan_hpms_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_hpms_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Rx FIFO 0 status register 
 */
class fdcan_rxf0s_r {
public:

/**
 * Rx FIFO 0 fill level Number of elements stored in Rx FIFO 0, range 0 to 3.
 */
class f0fl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr f0fl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf0s_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0s_r>() const {return opsy::utility::clear_set<fdcan_rxf0s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return static_cast<fdcan_rxf0s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0s_r> other) const -> opsy::utility::clear_set<fdcan_rxf0s_r> {return opsy::utility::clear_set<fdcan_rxf0s_r>(fdcan_rxf0s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 0 get index Rx FIFO 0 read index pointer, range 0 to 2.
 */
class f0gi_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr f0gi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf0s_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0s_r>() const {return opsy::utility::clear_set<fdcan_rxf0s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return static_cast<fdcan_rxf0s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0s_r> other) const -> opsy::utility::clear_set<fdcan_rxf0s_r> {return opsy::utility::clear_set<fdcan_rxf0s_r>(fdcan_rxf0s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 0 put index Rx FIFO 0 write index pointer, range 0 to 2.
 */
class f0pi_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr f0pi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf0s_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0s_r>() const {return opsy::utility::clear_set<fdcan_rxf0s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return static_cast<fdcan_rxf0s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0s_r> other) const -> opsy::utility::clear_set<fdcan_rxf0s_r> {return opsy::utility::clear_set<fdcan_rxf0s_r>(fdcan_rxf0s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 0 full
 */
class f0f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr f0f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxf0s_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0s_r>() const {return opsy::utility::clear_set<fdcan_rxf0s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return static_cast<fdcan_rxf0s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0s_r> other) const -> opsy::utility::clear_set<fdcan_rxf0s_r> {return opsy::utility::clear_set<fdcan_rxf0s_r>(fdcan_rxf0s_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 0 message lost This bit is a copy of interrupt flag IR[RF0L]. When IR[RF0L] is reset, this bit is also reset.
 */
class rf0l_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rf0l_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxf0s_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0s_r>() const {return opsy::utility::clear_set<fdcan_rxf0s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return static_cast<fdcan_rxf0s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0s_r> other) const -> opsy::utility::clear_set<fdcan_rxf0s_r> {return opsy::utility::clear_set<fdcan_rxf0s_r>(fdcan_rxf0s_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto f0fl() const -> f0fl_f {return f0fl_f(static_cast<uint8_t>(value_ >> f0fl_f::offset));}
	[[nodiscard]] constexpr auto f0gi() const -> f0gi_f {return f0gi_f(static_cast<uint8_t>(value_ >> f0gi_f::offset));}
	[[nodiscard]] constexpr auto f0pi() const -> f0pi_f {return f0pi_f(static_cast<uint8_t>(value_ >> f0pi_f::offset));}
	[[nodiscard]] constexpr auto f0f() const -> f0f_f {return f0f_f((value_ & f0f_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf0l() const -> rf0l_f {return rf0l_f((value_ & rf0l_f::mask) != 0);}

	constexpr fdcan_rxf0s_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rxf0s_r other) const -> fdcan_rxf0s_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rxf0s_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * CAN Rx FIFO 0 acknowledge register 
 */
class fdcan_rxf0a_r {
public:

/**
 * Rx FIFO 0 acknowledge index After the Host has read a message or a sequence of messages from Rx FIFO 0 it has to write the buffer index of the last element read from Rx FIFO 0 to F0AI. This sets the Rx FIFO 0 get index RXF0S[F0GI] to F0AI + 1 and update the FIFO 0 fill level RXF0S[F0FL].
 */
class f0ai_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr f0ai_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf0a_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf0a_r>() const {return opsy::utility::clear_set<fdcan_rxf0a_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf0a_r other) const -> fdcan_rxf0a_r { return static_cast<fdcan_rxf0a_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf0a_r> other) const -> opsy::utility::clear_set<fdcan_rxf0a_r> {return opsy::utility::clear_set<fdcan_rxf0a_r>(fdcan_rxf0a_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto f0ai() const -> f0ai_f {return f0ai_f(static_cast<uint8_t>(value_ >> f0ai_f::offset));}

	constexpr fdcan_rxf0a_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rxf0a_r other) const -> fdcan_rxf0a_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rxf0a_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Rx FIFO 1 status register 
 */
class fdcan_rxf1s_r {
public:

/**
 * Rx FIFO 1 fill level Number of elements stored in Rx FIFO 1, range 0 to 3.
 */
class f1fl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr f1fl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf1s_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1s_r>() const {return opsy::utility::clear_set<fdcan_rxf1s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return static_cast<fdcan_rxf1s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1s_r> other) const -> opsy::utility::clear_set<fdcan_rxf1s_r> {return opsy::utility::clear_set<fdcan_rxf1s_r>(fdcan_rxf1s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 1 get index Rx FIFO 1 read index pointer, range 0 to 2.
 */
class f1gi_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr f1gi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf1s_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1s_r>() const {return opsy::utility::clear_set<fdcan_rxf1s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return static_cast<fdcan_rxf1s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1s_r> other) const -> opsy::utility::clear_set<fdcan_rxf1s_r> {return opsy::utility::clear_set<fdcan_rxf1s_r>(fdcan_rxf1s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 1 put index Rx FIFO 1 write index pointer, range 0 to 2.
 */
class f1pi_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr f1pi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf1s_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1s_r>() const {return opsy::utility::clear_set<fdcan_rxf1s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return static_cast<fdcan_rxf1s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1s_r> other) const -> opsy::utility::clear_set<fdcan_rxf1s_r> {return opsy::utility::clear_set<fdcan_rxf1s_r>(fdcan_rxf1s_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx FIFO 1 full
 */
class f1f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr f1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxf1s_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1s_r>() const {return opsy::utility::clear_set<fdcan_rxf1s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return static_cast<fdcan_rxf1s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1s_r> other) const -> opsy::utility::clear_set<fdcan_rxf1s_r> {return opsy::utility::clear_set<fdcan_rxf1s_r>(fdcan_rxf1s_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx FIFO 1 message lost This bit is a copy of interrupt flag IR[RF1L]. When IR[RF1L] is reset, this bit is also reset.
 */
class rf1l_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rf1l_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_rxf1s_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1s_r>() const {return opsy::utility::clear_set<fdcan_rxf1s_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return static_cast<fdcan_rxf1s_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1s_r> other) const -> opsy::utility::clear_set<fdcan_rxf1s_r> {return opsy::utility::clear_set<fdcan_rxf1s_r>(fdcan_rxf1s_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto f1fl() const -> f1fl_f {return f1fl_f(static_cast<uint8_t>(value_ >> f1fl_f::offset));}
	[[nodiscard]] constexpr auto f1gi() const -> f1gi_f {return f1gi_f(static_cast<uint8_t>(value_ >> f1gi_f::offset));}
	[[nodiscard]] constexpr auto f1pi() const -> f1pi_f {return f1pi_f(static_cast<uint8_t>(value_ >> f1pi_f::offset));}
	[[nodiscard]] constexpr auto f1f() const -> f1f_f {return f1f_f((value_ & f1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto rf1l() const -> rf1l_f {return rf1l_f((value_ & rf1l_f::mask) != 0);}

	constexpr fdcan_rxf1s_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rxf1s_r other) const -> fdcan_rxf1s_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rxf1s_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Rx FIFO 1 acknowledge register 
 */
class fdcan_rxf1a_r {
public:

/**
 * Rx FIFO 1 acknowledge index After the Host has read a message or a sequence of messages from Rx FIFO 1 it has to write the buffer index of the last element read from Rx FIFO 1 to F1AI. This sets the Rx FIFO 1 get index RXF1S[F1GI] to F1AI + 1 and update the FIFO 1 Fill Level RXF1S[F1FL].
 */
class f1ai_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr f1ai_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_rxf1a_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_rxf1a_r>() const {return opsy::utility::clear_set<fdcan_rxf1a_r>(mask, *this);}
	constexpr auto operator|(fdcan_rxf1a_r other) const -> fdcan_rxf1a_r { return static_cast<fdcan_rxf1a_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_rxf1a_r> other) const -> opsy::utility::clear_set<fdcan_rxf1a_r> {return opsy::utility::clear_set<fdcan_rxf1a_r>(fdcan_rxf1a_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto f1ai() const -> f1ai_f {return f1ai_f(static_cast<uint8_t>(value_ >> f1ai_f::offset));}

	constexpr fdcan_rxf1a_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_rxf1a_r other) const -> fdcan_rxf1a_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_rxf1a_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer configuration register 
 */
class fdcan_txbc_r {
public:

/**
 * Tx FIFO/queue mode This is a protected write (P) bit, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class tfqm_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tfqm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_txbc_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_txbc_r>() const {return opsy::utility::clear_set<fdcan_txbc_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbc_r other) const -> fdcan_txbc_r { return static_cast<fdcan_txbc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbc_r> other) const -> opsy::utility::clear_set<fdcan_txbc_r> {return opsy::utility::clear_set<fdcan_txbc_r>(fdcan_txbc_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tfqm() const -> tfqm_f {return tfqm_f((value_ & tfqm_f::mask) != 0);}

	constexpr fdcan_txbc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbc_r other) const -> fdcan_txbc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx FIFO/queue status register 
 */
class fdcan_txfqs_r {
public:

/**
 * Tx FIFO free level Number of consecutive free Tx FIFO elements starting from TFGI, range 0 to 3. Read as 0 when Tx queue operation is configured (TXBC[TFQM] = 1).
 */
class tffl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tffl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txfqs_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txfqs_r>() const {return opsy::utility::clear_set<fdcan_txfqs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txfqs_r other) const -> fdcan_txfqs_r { return static_cast<fdcan_txfqs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txfqs_r> other) const -> opsy::utility::clear_set<fdcan_txfqs_r> {return opsy::utility::clear_set<fdcan_txfqs_r>(fdcan_txfqs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Tx FIFO get index Tx FIFO read index pointer, range 0 to 3. Read as 0 when Tx queue operation is configured (TXBC.TFQM = 1)
 */
class tfgi_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tfgi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txfqs_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txfqs_r>() const {return opsy::utility::clear_set<fdcan_txfqs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txfqs_r other) const -> fdcan_txfqs_r { return static_cast<fdcan_txfqs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txfqs_r> other) const -> opsy::utility::clear_set<fdcan_txfqs_r> {return opsy::utility::clear_set<fdcan_txfqs_r>(fdcan_txfqs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Tx FIFO/queue put index Tx FIFO/queue write index pointer, range 0 to 3
 */
class tfqpi_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tfqpi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txfqs_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txfqs_r>() const {return opsy::utility::clear_set<fdcan_txfqs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txfqs_r other) const -> fdcan_txfqs_r { return static_cast<fdcan_txfqs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txfqs_r> other) const -> opsy::utility::clear_set<fdcan_txfqs_r> {return opsy::utility::clear_set<fdcan_txfqs_r>(fdcan_txfqs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Tx FIFO/queue full
 */
class tfqf_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tfqf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_txfqs_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_txfqs_r>() const {return opsy::utility::clear_set<fdcan_txfqs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txfqs_r other) const -> fdcan_txfqs_r { return static_cast<fdcan_txfqs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txfqs_r> other) const -> opsy::utility::clear_set<fdcan_txfqs_r> {return opsy::utility::clear_set<fdcan_txfqs_r>(fdcan_txfqs_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tffl() const -> tffl_f {return tffl_f(static_cast<uint8_t>(value_ >> tffl_f::offset));}
	[[nodiscard]] constexpr auto tfgi() const -> tfgi_f {return tfgi_f(static_cast<uint8_t>(value_ >> tfgi_f::offset));}
	[[nodiscard]] constexpr auto tfqpi() const -> tfqpi_f {return tfqpi_f(static_cast<uint8_t>(value_ >> tfqpi_f::offset));}
	[[nodiscard]] constexpr auto tfqf() const -> tfqf_f {return tfqf_f((value_ & tfqf_f::mask) != 0);}

	constexpr fdcan_txfqs_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txfqs_r other) const -> fdcan_txfqs_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txfqs_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11; // 3 0x3

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer request pending register 
 */
class fdcan_txbrp_r {
public:

/**
 * Transmission request pending Each Tx buffer has its own transmission request pending bit. The bits are set via register TXBAR. The bits are reset after a requested transmission has completed or has been canceled via register TXBCR. After a TXBRP bit has been set, a Tx scan is started to check for the pending Tx request with the highest priority (Tx buffer with lowest Message ID). A cancellation request resets the corresponding transmission request pending bit of register TXBRP. In case a transmission has already been started when a cancellation is requested, this is done at the end of the transmission, regardless whether the transmission was successful or not. The cancellation request bits are reset directly after the corresponding TXBRP bit has been reset. After a cancellation has been requested, a finished cancellation is signaled via TXBCF after successful transmission together with the corresponding TXBTO bit when the transmission has not yet been started at the point of cancellation when the transmission has been aborted due to lost arbitration when an error occurred during frame transmission In DAR mode all transmissions are automatically canceled if they are not successful. The corresponding TXBCF bit is set for all unsuccessful transmissions.
 */
class trp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbrp_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbrp_r>() const {return opsy::utility::clear_set<fdcan_txbrp_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbrp_r other) const -> fdcan_txbrp_r { return static_cast<fdcan_txbrp_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbrp_r> other) const -> opsy::utility::clear_set<fdcan_txbrp_r> {return opsy::utility::clear_set<fdcan_txbrp_r>(fdcan_txbrp_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto trp() const -> trp_f {return trp_f(static_cast<uint8_t>(value_ >> trp_f::offset));}

	constexpr fdcan_txbrp_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbrp_r other) const -> fdcan_txbrp_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbrp_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer add request register 
 */
class fdcan_txbar_r {
public:

/**
 * Add request Each Tx buffer has its own add request bit. Writing a 1 sets the corresponding add request bit; writing a 0 has no impact. This enables the Host to set transmission requests for multiple Tx buffers with one write to TXBAR. When no Tx scan is running, the bits are reset immediately, else the bits remain set until the Tx scan process has completed.
 */
class ar_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ar_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbar_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbar_r>() const {return opsy::utility::clear_set<fdcan_txbar_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbar_r other) const -> fdcan_txbar_r { return static_cast<fdcan_txbar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbar_r> other) const -> opsy::utility::clear_set<fdcan_txbar_r> {return opsy::utility::clear_set<fdcan_txbar_r>(fdcan_txbar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ar() const -> ar_f {return ar_f(static_cast<uint8_t>(value_ >> ar_f::offset));}

	constexpr fdcan_txbar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbar_r other) const -> fdcan_txbar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer cancellation request register 
 */
class fdcan_txbcr_r {
public:

/**
 * Cancellation request Each Tx buffer has its own cancellation request bit. Writing a 1 sets the corresponding CR bit; writing a 0 has no impact. This enables the Host to set cancellation requests for multiple Tx buffers with one write to TXBCR. The bits remain set until the corresponding TXBRP bit is reset.
 */
class cr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbcr_r>() const {return opsy::utility::clear_set<fdcan_txbcr_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbcr_r other) const -> fdcan_txbcr_r { return static_cast<fdcan_txbcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbcr_r> other) const -> opsy::utility::clear_set<fdcan_txbcr_r> {return opsy::utility::clear_set<fdcan_txbcr_r>(fdcan_txbcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cr() const -> cr_f {return cr_f(static_cast<uint8_t>(value_ >> cr_f::offset));}

	constexpr fdcan_txbcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbcr_r other) const -> fdcan_txbcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer transmission occurred register 
 */
class fdcan_txbto_r {
public:

/**
 * Transmission occurred. Each Tx buffer has its own TO bit. The bits are set when the corresponding TXBRP bit is cleared after a successful transmission. The bits are reset when a new transmission is requested by writing a 1 to the corresponding bit of register TXBAR.
 */
class to_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr to_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbto_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbto_r>() const {return opsy::utility::clear_set<fdcan_txbto_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbto_r other) const -> fdcan_txbto_r { return static_cast<fdcan_txbto_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbto_r> other) const -> opsy::utility::clear_set<fdcan_txbto_r> {return opsy::utility::clear_set<fdcan_txbto_r>(fdcan_txbto_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto to() const -> to_f {return to_f(static_cast<uint8_t>(value_ >> to_f::offset));}

	constexpr fdcan_txbto_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbto_r other) const -> fdcan_txbto_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbto_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer cancellation finished register 
 */
class fdcan_txbcf_r {
public:

/**
 * Cancellation finished Each Tx buffer has its own CF bit. The bits are set when the corresponding TXBRP bit is cleared after a cancellation was requested via TXBCR. In case the corresponding TXBRP bit was not set at the point of cancellation, CF is set immediately. The bits are reset when a new transmission is requested by writing a 1 to the corresponding bit of register TXBAR.
 */
class cf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbcf_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbcf_r>() const {return opsy::utility::clear_set<fdcan_txbcf_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbcf_r other) const -> fdcan_txbcf_r { return static_cast<fdcan_txbcf_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbcf_r> other) const -> opsy::utility::clear_set<fdcan_txbcf_r> {return opsy::utility::clear_set<fdcan_txbcf_r>(fdcan_txbcf_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cf() const -> cf_f {return cf_f(static_cast<uint8_t>(value_ >> cf_f::offset));}

	constexpr fdcan_txbcf_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbcf_r other) const -> fdcan_txbcf_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbcf_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer transmission interrupt enable register 
 */
class fdcan_txbtie_r {
public:

/**
 * Transmission interrupt enable Each Tx buffer has its own TIE bit.
 */
class tie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tie_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbtie_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbtie_r>() const {return opsy::utility::clear_set<fdcan_txbtie_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbtie_r other) const -> fdcan_txbtie_r { return static_cast<fdcan_txbtie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbtie_r> other) const -> opsy::utility::clear_set<fdcan_txbtie_r> {return opsy::utility::clear_set<fdcan_txbtie_r>(fdcan_txbtie_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tie() const -> tie_f {return tie_f(static_cast<uint8_t>(value_ >> tie_f::offset));}

	constexpr fdcan_txbtie_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbtie_r other) const -> fdcan_txbtie_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbtie_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx buffer cancellation finished interrupt enable register 
 */
class fdcan_txbcie_r {
public:

/**
 * Cancellation finished interrupt enable. Each Tx buffer has its own CFIE bit.
 */
class cfie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cfie_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txbcie_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txbcie_r>() const {return opsy::utility::clear_set<fdcan_txbcie_r>(mask, *this);}
	constexpr auto operator|(fdcan_txbcie_r other) const -> fdcan_txbcie_r { return static_cast<fdcan_txbcie_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txbcie_r> other) const -> opsy::utility::clear_set<fdcan_txbcie_r> {return opsy::utility::clear_set<fdcan_txbcie_r>(fdcan_txbcie_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cfie() const -> cfie_f {return cfie_f(static_cast<uint8_t>(value_ >> cfie_f::offset));}

	constexpr fdcan_txbcie_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txbcie_r other) const -> fdcan_txbcie_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txbcie_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx event FIFO status register 
 */
class fdcan_txefs_r {
public:

/**
 * Event FIFO fill level Number of elements stored in Tx event FIFO, range 0 to 3.
 */
class effl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr effl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txefs_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txefs_r>() const {return opsy::utility::clear_set<fdcan_txefs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefs_r other) const -> fdcan_txefs_r { return static_cast<fdcan_txefs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefs_r> other) const -> opsy::utility::clear_set<fdcan_txefs_r> {return opsy::utility::clear_set<fdcan_txefs_r>(fdcan_txefs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Event FIFO get index Tx event FIFO read index pointer, range 0 to 3.
 */
class efgi_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr efgi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txefs_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txefs_r>() const {return opsy::utility::clear_set<fdcan_txefs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefs_r other) const -> fdcan_txefs_r { return static_cast<fdcan_txefs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefs_r> other) const -> opsy::utility::clear_set<fdcan_txefs_r> {return opsy::utility::clear_set<fdcan_txefs_r>(fdcan_txefs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Event FIFO put index Tx event FIFO write index pointer, range 0 to 3.
 */
class efpi_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr efpi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txefs_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txefs_r>() const {return opsy::utility::clear_set<fdcan_txefs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefs_r other) const -> fdcan_txefs_r { return static_cast<fdcan_txefs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefs_r> other) const -> opsy::utility::clear_set<fdcan_txefs_r> {return opsy::utility::clear_set<fdcan_txefs_r>(fdcan_txefs_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Event FIFO full
 */
class eff_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_txefs_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_txefs_r>() const {return opsy::utility::clear_set<fdcan_txefs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefs_r other) const -> fdcan_txefs_r { return static_cast<fdcan_txefs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefs_r> other) const -> opsy::utility::clear_set<fdcan_txefs_r> {return opsy::utility::clear_set<fdcan_txefs_r>(fdcan_txefs_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx event FIFO element lost This bit is a copy of interrupt flag IR[TEFL]. When IR[TEFL] is reset, this bit is also reset. 0 No Tx event FIFO element lost 1 Tx event FIFO element lost, also set after write attempt to Tx event FIFO of size 0.
 */
class tefl_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tefl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fdcan_txefs_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fdcan_txefs_r>() const {return opsy::utility::clear_set<fdcan_txefs_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefs_r other) const -> fdcan_txefs_r { return static_cast<fdcan_txefs_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefs_r> other) const -> opsy::utility::clear_set<fdcan_txefs_r> {return opsy::utility::clear_set<fdcan_txefs_r>(fdcan_txefs_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto effl() const -> effl_f {return effl_f(static_cast<uint8_t>(value_ >> effl_f::offset));}
	[[nodiscard]] constexpr auto efgi() const -> efgi_f {return efgi_f(static_cast<uint8_t>(value_ >> efgi_f::offset));}
	[[nodiscard]] constexpr auto efpi() const -> efpi_f {return efpi_f(static_cast<uint8_t>(value_ >> efpi_f::offset));}
	[[nodiscard]] constexpr auto eff() const -> eff_f {return eff_f((value_ & eff_f::mask) != 0);}
	[[nodiscard]] constexpr auto tefl() const -> tefl_f {return tefl_f((value_ & tefl_f::mask) != 0);}

	constexpr fdcan_txefs_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txefs_r other) const -> fdcan_txefs_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txefs_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN Tx event FIFO acknowledge register 
 */
class fdcan_txefa_r {
public:

/**
 * Event FIFO acknowledge index After the Host has read an element or a sequence of elements from the Tx event FIFO, it has to write the index of the last element read from Tx event FIFO to EFAI. This sets the Tx event FIFO get index TXEFS[EFGI] to EFAI + 1 and updates the FIFO 0 fill level TXEFS[EFFL].
 */
class efai_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr efai_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_txefa_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_txefa_r>() const {return opsy::utility::clear_set<fdcan_txefa_r>(mask, *this);}
	constexpr auto operator|(fdcan_txefa_r other) const -> fdcan_txefa_r { return static_cast<fdcan_txefa_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_txefa_r> other) const -> opsy::utility::clear_set<fdcan_txefa_r> {return opsy::utility::clear_set<fdcan_txefa_r>(fdcan_txefa_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto efai() const -> efai_f {return efai_f(static_cast<uint8_t>(value_ >> efai_f::offset));}

	constexpr fdcan_txefa_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_txefa_r other) const -> fdcan_txefa_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_txefa_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FDCAN CFG clock divider register 
 */
class fdcan_ckdiv_r {
public:

/**
 * input clock divider The APB clock could be divided prior to be used by the CAN sub system. The rate must be computed using the divider output clock. These are protected write (P) bits, which means that write access by the bits is possible only when the bit 1 [CCE] and bit 0 [INIT] of CCCR register are set to 1.
 */
class pdiv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fdcan_ckdiv_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fdcan_ckdiv_r>() const {return opsy::utility::clear_set<fdcan_ckdiv_r>(mask, *this);}
	constexpr auto operator|(fdcan_ckdiv_r other) const -> fdcan_ckdiv_r { return static_cast<fdcan_ckdiv_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fdcan_ckdiv_r> other) const -> opsy::utility::clear_set<fdcan_ckdiv_r> {return opsy::utility::clear_set<fdcan_ckdiv_r>(fdcan_ckdiv_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pdiv() const -> pdiv_f {return pdiv_f(static_cast<uint8_t>(value_ >> pdiv_f::offset));}

	constexpr fdcan_ckdiv_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fdcan_ckdiv_r other) const -> fdcan_ckdiv_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fdcan_ckdiv_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,fdcan_crel_r> fdcan_crel;
	opsy::utility::memory<uint32_t,fdcan_endn_r> fdcan_endn;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,fdcan_dbtp_r> fdcan_dbtp;
	opsy::utility::memory<uint32_t,fdcan_test_r> fdcan_test;
	opsy::utility::memory<uint32_t,fdcan_rwd_r> fdcan_rwd;
	opsy::utility::memory<uint32_t,fdcan_cccr_r> fdcan_cccr;
	opsy::utility::memory<uint32_t,fdcan_nbtp_r> fdcan_nbtp;
	opsy::utility::memory<uint32_t,fdcan_tscc_r> fdcan_tscc;
	opsy::utility::memory<uint32_t,fdcan_tscv_r> fdcan_tscv;
	opsy::utility::memory<uint32_t,fdcan_tocc_r> fdcan_tocc;
	opsy::utility::memory<uint32_t,fdcan_tocv_r> fdcan_tocv;
	opsy::utility::padding<16> _p1;
	opsy::utility::memory<uint32_t,fdcan_ecr_r> fdcan_ecr;
	opsy::utility::memory<uint32_t,fdcan_psr_r> fdcan_psr;
	opsy::utility::memory<uint32_t,fdcan_tdcr_r> fdcan_tdcr;
	opsy::utility::padding<4> _p2;
	opsy::utility::memory<uint32_t,fdcan_ir_r> fdcan_ir;
	opsy::utility::memory<uint32_t,fdcan_ie_r> fdcan_ie;
	opsy::utility::memory<uint32_t,fdcan_ils_r> fdcan_ils;
	opsy::utility::memory<uint32_t,fdcan_ile_r> fdcan_ile;
	opsy::utility::padding<32> _p3;
	opsy::utility::memory<uint32_t,fdcan_rxgfc_r> fdcan_rxgfc;
	opsy::utility::memory<uint32_t,fdcan_xidam_r> fdcan_xidam;
	opsy::utility::memory<uint32_t,fdcan_hpms_r> fdcan_hpms;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,fdcan_rxf0s_r> fdcan_rxf0s;
	opsy::utility::memory<uint32_t,fdcan_rxf0a_r> fdcan_rxf0a;
	opsy::utility::memory<uint32_t,fdcan_rxf1s_r> fdcan_rxf1s;
	opsy::utility::memory<uint32_t,fdcan_rxf1a_r> fdcan_rxf1a;
	opsy::utility::padding<32> _p5;
	opsy::utility::memory<uint32_t,fdcan_txbc_r> fdcan_txbc;
	opsy::utility::memory<uint32_t,fdcan_txfqs_r> fdcan_txfqs;
	opsy::utility::memory<uint32_t,fdcan_txbrp_r> fdcan_txbrp;
	opsy::utility::memory<uint32_t,fdcan_txbar_r> fdcan_txbar;
	opsy::utility::memory<uint32_t,fdcan_txbcr_r> fdcan_txbcr;
	opsy::utility::memory<uint32_t,fdcan_txbto_r> fdcan_txbto;
	opsy::utility::memory<uint32_t,fdcan_txbcf_r> fdcan_txbcf;
	opsy::utility::memory<uint32_t,fdcan_txbtie_r> fdcan_txbtie;
	opsy::utility::memory<uint32_t,fdcan_txbcie_r> fdcan_txbcie;
	opsy::utility::memory<uint32_t,fdcan_txefs_r> fdcan_txefs;
	opsy::utility::memory<uint32_t,fdcan_txefa_r> fdcan_txefa;
	opsy::utility::padding<20> _p6;
	opsy::utility::memory<uint32_t,fdcan_ckdiv_r> fdcan_ckdiv;
};

static_assert(std::is_standard_layout_v<fdcan_p>);
static_assert(offsetof(fdcan_p, fdcan_crel) == 0);
static_assert(offsetof(fdcan_p, fdcan_endn) == 4);
static_assert(offsetof(fdcan_p, fdcan_dbtp) == 12);
static_assert(offsetof(fdcan_p, fdcan_test) == 16);
static_assert(offsetof(fdcan_p, fdcan_rwd) == 20);
static_assert(offsetof(fdcan_p, fdcan_cccr) == 24);
static_assert(offsetof(fdcan_p, fdcan_nbtp) == 28);
static_assert(offsetof(fdcan_p, fdcan_tscc) == 32);
static_assert(offsetof(fdcan_p, fdcan_tscv) == 36);
static_assert(offsetof(fdcan_p, fdcan_tocc) == 40);
static_assert(offsetof(fdcan_p, fdcan_tocv) == 44);
static_assert(offsetof(fdcan_p, fdcan_ecr) == 64);
static_assert(offsetof(fdcan_p, fdcan_psr) == 68);
static_assert(offsetof(fdcan_p, fdcan_tdcr) == 72);
static_assert(offsetof(fdcan_p, fdcan_ir) == 80);
static_assert(offsetof(fdcan_p, fdcan_ie) == 84);
static_assert(offsetof(fdcan_p, fdcan_ils) == 88);
static_assert(offsetof(fdcan_p, fdcan_ile) == 92);
static_assert(offsetof(fdcan_p, fdcan_rxgfc) == 128);
static_assert(offsetof(fdcan_p, fdcan_xidam) == 132);
static_assert(offsetof(fdcan_p, fdcan_hpms) == 136);
static_assert(offsetof(fdcan_p, fdcan_rxf0s) == 144);
static_assert(offsetof(fdcan_p, fdcan_rxf0a) == 148);
static_assert(offsetof(fdcan_p, fdcan_rxf1s) == 152);
static_assert(offsetof(fdcan_p, fdcan_rxf1a) == 156);
static_assert(offsetof(fdcan_p, fdcan_txbc) == 192);
static_assert(offsetof(fdcan_p, fdcan_txfqs) == 196);
static_assert(offsetof(fdcan_p, fdcan_txbrp) == 200);
static_assert(offsetof(fdcan_p, fdcan_txbar) == 204);
static_assert(offsetof(fdcan_p, fdcan_txbcr) == 208);
static_assert(offsetof(fdcan_p, fdcan_txbto) == 212);
static_assert(offsetof(fdcan_p, fdcan_txbcf) == 216);
static_assert(offsetof(fdcan_p, fdcan_txbtie) == 220);
static_assert(offsetof(fdcan_p, fdcan_txbcie) == 224);
static_assert(offsetof(fdcan_p, fdcan_txefs) == 228);
static_assert(offsetof(fdcan_p, fdcan_txefa) == 232);
static_assert(offsetof(fdcan_p, fdcan_ckdiv) == 256);

inline fdcan_p& fdcan1 = *reinterpret_cast<fdcan_p*>(0x4000A400);
inline fdcan_p& fdcan2 = *reinterpret_cast<fdcan_p*>(0x4000A800);
inline fdcan_p& sec_fdcan1 = *reinterpret_cast<fdcan_p*>(0x5000A400);
inline fdcan_p& sec_fdcan2 = *reinterpret_cast<fdcan_p*>(0x5000A800);

} // STM32H563

