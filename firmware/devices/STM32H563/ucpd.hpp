#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * USB Power Delivery interface
 */
class ucpd_p {
public:

/**
 * UCPD configuration register 1 
 */
class ucpd_cfgr1_r {
public:

/**
 * Division ratio for producing half-bit clock The bitfield determines the division ratio (the bitfield value plus one) of a ucpd_clk divider producing half-bit clock (hbit_clk).
 */
class hbitclkdiv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hbitclkdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Division ratio for producing inter-frame gap timer clock The bitfield determines the division ratio (the bitfield value minus one) of a ucpd_clk divider producing inter-frame gap timer clock (tInterFrameGap). The division ratio 15 is to apply for Tx clock at the USB PD 2.0 specification nominal value. The division ratios below 15 are to apply for Tx clock below nominal, and the division ratios above 15 for Tx clock above nominal.
 */
class ifrgap_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ifrgap_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transition window duration The bitfield determines the division ratio (the bitfield value minus one) of a hbit_clk divider producing tTransitionWindow interval. Set a value that produces an interval of 12 to 20 us, taking into account the ucpd_clk frequency and the HBITCLKDIV[5:0] bitfield setting.
 */
class transwin_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr transwin_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Pre-scaler division ratio for generating ucpd_clk The bitfield determines the division ratio of a kernel clock pre-scaler producing UCPD peripheral clock (ucpd_clk). It is recommended to use the pre-scaler so as to set the ucpd_clk frequency in the range from 6 to 9 MHz.
 */
class psc_usbpdclk_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr psc_usbpdclk_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver ordered set enable The bitfield determines the types of ordered sets that the receiver must detect. When set/cleared, each bit enables/disables a specific function: 0bxxxxxxxx1: SOP detect enabled 0bxxxxxxx1x: SOP' detect enabled 0bxxxxxx1xx: SOP'' detect enabled 0bxxxxx1xxx: Hard Reset detect enabled 0bxxxx1xxxx: Cable Detect reset enabled 0bxxx1xxxxx: SOP'_Debug enabled 0bxx1xxxxxx: SOP''_Debug enabled 0bx1xxxxxxx: SOP extension#1 enabled 0b1xxxxxxxx: SOP extension#2 enabled
 */
class rxordseten_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxordseten_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Transmission DMA mode enable When set, the bit enables DMA mode for transmission.
 */
class txdmaen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reception DMA mode enable When set, the bit enables DMA mode for reception.
 */
class rxdmaen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UCPD peripheral enable General enable of the UCPD peripheral. Upon disabling, the peripheral instantly quits any ongoing activity and all control bits and bitfields default to their reset values. They must be set to their desired values each time the peripheral transits from disabled to enabled state.
 */
class ucpden_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ucpden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr1_r>() const {return opsy::utility::clear_set<ucpd_cfgr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return static_cast<ucpd_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr1_r> other) const -> opsy::utility::clear_set<ucpd_cfgr1_r> {return opsy::utility::clear_set<ucpd_cfgr1_r>(ucpd_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hbitclkdiv() const -> hbitclkdiv_f {return hbitclkdiv_f(static_cast<uint8_t>(value_ >> hbitclkdiv_f::offset));}
	[[nodiscard]] constexpr auto ifrgap() const -> ifrgap_f {return ifrgap_f(static_cast<uint8_t>(value_ >> ifrgap_f::offset));}
	[[nodiscard]] constexpr auto transwin() const -> transwin_f {return transwin_f(static_cast<uint8_t>(value_ >> transwin_f::offset));}
	[[nodiscard]] constexpr auto psc_usbpdclk() const -> psc_usbpdclk_f {return psc_usbpdclk_f(static_cast<uint8_t>(value_ >> psc_usbpdclk_f::offset));}
	[[nodiscard]] constexpr auto rxordseten() const -> rxordseten_f {return rxordseten_f(static_cast<uint16_t>(value_ >> rxordseten_f::offset));}
	[[nodiscard]] constexpr auto txdmaen() const -> txdmaen_f {return txdmaen_f((value_ & txdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdmaen() const -> rxdmaen_f {return rxdmaen_f((value_ & rxdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpden() const -> ucpden_f {return ucpden_f((value_ & ucpden_f::mask) != 0);}

	constexpr ucpd_cfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_cfgr1_r other) const -> ucpd_cfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_cfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD configuration register 2 
 */
class ucpd_cfgr2_r {
public:

/**
 * BMC decoder Rx pre-filter enable The sampling clock is that of the receiver (that is, after pre-scaler).
 */
class rxfiltdis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfiltdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr2_r>() const {return opsy::utility::clear_set<ucpd_cfgr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return static_cast<ucpd_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr2_r> other) const -> opsy::utility::clear_set<ucpd_cfgr2_r> {return opsy::utility::clear_set<ucpd_cfgr2_r>(ucpd_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BMC decoder Rx pre-filter sampling method Number of consistent consecutive samples before confirming a new value.
 */
class rxfilt2n3_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfilt2n3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr2_r>() const {return opsy::utility::clear_set<ucpd_cfgr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return static_cast<ucpd_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr2_r> other) const -> opsy::utility::clear_set<ucpd_cfgr2_r> {return opsy::utility::clear_set<ucpd_cfgr2_r>(ucpd_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Force ClkReq clock request
 */
class forceclk_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr forceclk_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr2_r>() const {return opsy::utility::clear_set<ucpd_cfgr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return static_cast<ucpd_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr2_r> other) const -> opsy::utility::clear_set<ucpd_cfgr2_r> {return opsy::utility::clear_set<ucpd_cfgr2_r>(ucpd_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from Stop mode enable Setting the bit enables the UCPD_ASYNC_INT signal.
 */
class wupen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr2_r>() const {return opsy::utility::clear_set<ucpd_cfgr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return static_cast<ucpd_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr2_r> other) const -> opsy::utility::clear_set<ucpd_cfgr2_r> {return opsy::utility::clear_set<ucpd_cfgr2_r>(ucpd_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx analog filter enable Setting the bit enables the Rx analog filter required for optimum Power Delivery reception.
 */
class rxafilten_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxafilten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr2_r>() const {return opsy::utility::clear_set<ucpd_cfgr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return static_cast<ucpd_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr2_r> other) const -> opsy::utility::clear_set<ucpd_cfgr2_r> {return opsy::utility::clear_set<ucpd_cfgr2_r>(ucpd_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rxfiltdis() const -> rxfiltdis_f {return rxfiltdis_f((value_ & rxfiltdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfilt2n3() const -> rxfilt2n3_f {return rxfilt2n3_f((value_ & rxfilt2n3_f::mask) != 0);}
	[[nodiscard]] constexpr auto forceclk() const -> forceclk_f {return forceclk_f((value_ & forceclk_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen() const -> wupen_f {return wupen_f((value_ & wupen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxafilten() const -> rxafilten_f {return rxafilten_f((value_ & rxafilten_f::mask) != 0);}

	constexpr ucpd_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_cfgr2_r other) const -> ucpd_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD control register 
 */
class ucpd_cr_r {
public:

/**
 * Type of Tx packet Writing the bitfield triggers the action as follows, depending on the value: Others: invalid From V1.1 of the USB PD specification, there is a counter defined for the duration of the BIST Carrier Mode 2. To quit this mode correctly (after the 'tBISTContMode' delay), disable the peripheral (UCPDEN = 0).
 */
class txmode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr txmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Command to send a Tx packet The bit is cleared by hardware as soon as the packet transmission begins or is discarded.
 */
class txsend_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txsend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command to send a Tx Hard Reset The bit is cleared by hardware as soon as the message transmission begins or is discarded.
 */
class txhrst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txhrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver mode Determines the mode of the receiver. When the bit is set, RXORDSET behaves normally, RXDR no longer receives bytes yet the CRC checking still proceeds as for a normal message. As this mode prevents reception of the header (containing MessageID), software has to auto-increment a received MessageID counter for inclusion in the GoodCRC acknowledge that must still be transmitted during this test.
 */
class rxmode_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB Power Delivery receiver enable Both CC1 and CC2 receivers are disabled when the bit is cleared. Only the CC receiver selected via the PHYCCSEL bit is enabled when the bit is set.
 */
class phyrxen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr phyrxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CC1/CC2 line selector for USB Power Delivery signaling The selection depends on the cable orientation as discovered at attach.
 */
class phyccsel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr phyccsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Analog PHY sub-mode Refer to TYPEC_VSTATE_CCx for the effect of this bitfield.
 */
class anasubmode_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr anasubmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Analog PHY operating mode The use of CC1 and CC2 depends on CCENABLE. Refer to ANAMODE, ANASUBMODE and link with TYPEC_VSTATE_CCx for the effect of this bitfield in conjunction with ANASUBMODE[1:0].
 */
class anamode_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr anamode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CC line enable This bitfield enables CC1 and CC2 line analog PHYs (pull-ups and pull-downs) according to ANAMODE and ANASUBMODE[1:0] setting. A single line PHY can be enabled when, for example, the other line is driven by VCONN via an external VCONN switch. Enabling both PHYs is the normal usage for sink/source.
 */
class ccenable_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ccenable_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FRS event detection enable Setting the bit enables FRS Rx event (FRSEVT) detection on the CC line selected through the PHYCCSEL bit. 0: Disable Clear the bit when the device is attached to an FRS-incapable source/sink.
 */
class frsrxen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr frsrxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FRS Tx signaling enable. Setting the bit enables FRS Tx signaling. The bit is cleared by hardware after a delay respecting the USB Power Delivery specification Revision 3.0.
 */
class frstx_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr frstx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rdch condition drive The bit drives Rdch condition on the CC line selected through the PHYCCSEL bit (thus associated with VCONN), by remaining set during the source-only UnattachedWait.SRC state, to respect the Type-C state. Refer to 'USB Type-C ECN for Source VCONN Discharge'. The CCENABLE[1:0] bitfield must be set accordingly, too.
 */
class rdch_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rdch_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CC1 Type-C detector disable The bit disables the Type-C detector on the CC1 line. When enabled, the Type-C detector for CC1 is configured through ANAMODE and ANASUBMODE[1:0].
 */
class cc1tcdis_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc1tcdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CC2 Type-C detector disable The bit disables the Type-C detector on the CC2 line. When enabled, the Type-C detector for CC2 is configured through ANAMODE and ANASUBMODE[1:0].
 */
class cc2tcdis_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2tcdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_cr_r>() const {return opsy::utility::clear_set<ucpd_cr_r>(mask, *this);}
	constexpr auto operator|(ucpd_cr_r other) const -> ucpd_cr_r { return static_cast<ucpd_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cr_r> other) const -> opsy::utility::clear_set<ucpd_cr_r> {return opsy::utility::clear_set<ucpd_cr_r>(ucpd_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txmode() const -> txmode_f {return txmode_f(static_cast<uint8_t>(value_ >> txmode_f::offset));}
	[[nodiscard]] constexpr auto txsend() const -> txsend_f {return txsend_f((value_ & txsend_f::mask) != 0);}
	[[nodiscard]] constexpr auto txhrst() const -> txhrst_f {return txhrst_f((value_ & txhrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxmode() const -> rxmode_f {return rxmode_f((value_ & rxmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto phyrxen() const -> phyrxen_f {return phyrxen_f((value_ & phyrxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto phyccsel() const -> phyccsel_f {return phyccsel_f((value_ & phyccsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto anasubmode() const -> anasubmode_f {return anasubmode_f(static_cast<uint8_t>(value_ >> anasubmode_f::offset));}
	[[nodiscard]] constexpr auto anamode() const -> anamode_f {return anamode_f((value_ & anamode_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccenable() const -> ccenable_f {return ccenable_f(static_cast<uint8_t>(value_ >> ccenable_f::offset));}
	[[nodiscard]] constexpr auto frsrxen() const -> frsrxen_f {return frsrxen_f((value_ & frsrxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto frstx() const -> frstx_f {return frstx_f((value_ & frstx_f::mask) != 0);}
	[[nodiscard]] constexpr auto rdch() const -> rdch_f {return rdch_f((value_ & rdch_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1tcdis() const -> cc1tcdis_f {return cc1tcdis_f((value_ & cc1tcdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2tcdis() const -> cc2tcdis_f {return cc2tcdis_f((value_ & cc2tcdis_f::mask) != 0);}

	constexpr ucpd_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_cr_r other) const -> ucpd_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD interrupt mask register 
 */
class ucpd_imr_r {
public:

/**
 * TXIS interrupt enable
 */
class txisie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txisie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXMSGDISC interrupt enable
 */
class txmsgdiscie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgdiscie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXMSGSENT interrupt enable
 */
class txmsgsentie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgsentie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXMSGABT interrupt enable
 */
class txmsgabtie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgabtie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HRSTDISC interrupt enable
 */
class hrstdiscie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstdiscie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HRSTSENT interrupt enable
 */
class hrstsentie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstsentie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXUND interrupt enable
 */
class txundie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txundie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXNE interrupt enable
 */
class rxneie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXORDDET interrupt enable
 */
class rxorddetie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxorddetie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXHRSTDET interrupt enable
 */
class rxhrstdetie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxhrstdetie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXOVR interrupt enable
 */
class rxovrie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxovrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXMSGEND interrupt enable
 */
class rxmsgendie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxmsgendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TYPECEVT1 interrupt enable
 */
class typecevt1ie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TYPECEVT2 interrupt enable
 */
class typecevt2ie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FRSEVT interrupt enable
 */
class frsevtie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr frsevtie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_imr_r>() const {return opsy::utility::clear_set<ucpd_imr_r>(mask, *this);}
	constexpr auto operator|(ucpd_imr_r other) const -> ucpd_imr_r { return static_cast<ucpd_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_imr_r> other) const -> opsy::utility::clear_set<ucpd_imr_r> {return opsy::utility::clear_set<ucpd_imr_r>(ucpd_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txisie() const -> txisie_f {return txisie_f((value_ & txisie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgdiscie() const -> txmsgdiscie_f {return txmsgdiscie_f((value_ & txmsgdiscie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgsentie() const -> txmsgsentie_f {return txmsgsentie_f((value_ & txmsgsentie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgabtie() const -> txmsgabtie_f {return txmsgabtie_f((value_ & txmsgabtie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstdiscie() const -> hrstdiscie_f {return hrstdiscie_f((value_ & hrstdiscie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstsentie() const -> hrstsentie_f {return hrstsentie_f((value_ & hrstsentie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txundie() const -> txundie_f {return txundie_f((value_ & txundie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxneie() const -> rxneie_f {return rxneie_f((value_ & rxneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxorddetie() const -> rxorddetie_f {return rxorddetie_f((value_ & rxorddetie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxhrstdetie() const -> rxhrstdetie_f {return rxhrstdetie_f((value_ & rxhrstdetie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxovrie() const -> rxovrie_f {return rxovrie_f((value_ & rxovrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxmsgendie() const -> rxmsgendie_f {return rxmsgendie_f((value_ & rxmsgendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt1ie() const -> typecevt1ie_f {return typecevt1ie_f((value_ & typecevt1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt2ie() const -> typecevt2ie_f {return typecevt2ie_f((value_ & typecevt2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto frsevtie() const -> frsevtie_f {return frsevtie_f((value_ & frsevtie_f::mask) != 0);}

	constexpr ucpd_imr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_imr_r other) const -> ucpd_imr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_imr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD status register 
 */
class ucpd_sr_r {
public:

/**
 * Transmit interrupt status The flag indicates that the UCPD_TXDR register is empty and new data write is required (as the amount of data sent has not reached the payload size defined in the TXPAYSZ bitfield). The flag is cleared with the data write into the UCPD_TXDR register.
 */
class txis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Message transmission discarded The flag indicates that a message transmission was dropped. The flag is cleared by setting the TXMSGDISCCF bit. Transmission of a message can be dropped if there is a concurrent receive in progress or at excessive noise on the line. After a Tx message is discarded, the flag is only raised when the CC line becomes idle.
 */
class txmsgdisc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgdisc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Message transmission completed The flag indicates the completion of packet transmission. It is cleared by setting the TXMSGSENTCF bit. In the event of a message transmission interrupted by a Hard Reset, the flag is not raised.
 */
class txmsgsent_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgsent_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit message abort The flag indicates that a Tx message is aborted due to a subsequent Hard Reset message send request taking priority during transmit. It is cleared by setting the TXMSGABTCF bit.
 */
class txmsgabt_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgabt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hard Reset discarded The flag indicates that the Hard Reset message is discarded. The flag is cleared by setting the HRSTDISCCF bit.
 */
class hrstdisc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstdisc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hard Reset message sent The flag indicates that the Hard Reset message is sent. The flag is cleared by setting the HRSTSENTCF bit.
 */
class hrstsent_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstsent_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx data underrun detection The flag indicates that the Tx data register (UCPD_TXDR) was not written in time for a transmit message to execute normally. It is cleared by setting the TXUNDCF bit.
 */
class txund_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txund_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data register not empty detection The flag indicates that the UCPD_RXDR register is not empty. It is automatically cleared upon reading UCPD_RXDR.
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx ordered set (4 K-codes) detection The flag indicates the detection of an ordered set. The relevant information is stored in the RXORDSET[2:0] bitfield of the UCPD_RX_ORDSET register. It is cleared by setting the RXORDDETCF bit.
 */
class rxorddet_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxorddet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx Hard Reset receipt detection The flag indicates the receipt of valid Hard Reset message. It is cleared by setting the RXHRSTDETCF bit.
 */
class rxhrstdet_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxhrstdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx data overflow detection The flag indicates Rx data buffer overflow. It is cleared by setting the RXOVRCF bit. The buffer overflow can occur if the received data are not read fast enough.
 */
class rxovr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx message received The flag indicates whether a message (except Hard Reset message) has been received, regardless the CRC value. The flag is cleared by setting the RXMSGENDCF bit. The RXERR flag set when the RXMSGEND flag goes high indicates errors in the last-received message.
 */
class rxmsgend_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxmsgend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive message error The flag indicates errors of the last Rx message declared (via RXMSGEND), such as incorrect CRC or truncated message (a line becoming static before EOP is met). It is asserted whenever the RXMSGEND flag is set.
 */
class rxerr_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Type-C voltage level event on CC1 line The flag indicates a change of the TYPEC_VSTATE_CC1[1:0] bitfield value, which corresponds to a new Type-C event. It is cleared by setting the TYPECEVT2CF bit.
 */
class typecevt1_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Type-C voltage level event on CC2 line The flag indicates a change of the TYPEC_VSTATE_CC2[1:0] bitfield value, which corresponds to a new Type-C event. It is cleared by setting the TYPECEVT2CF bit.
 */
class typecevt2_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * The status bitfield indicates the voltage level on the CC1 line in its steady state. The voltage variation on the CC1 line during USB PD messages due to the BMC PHY modulation does not impact the bitfield value.
 */
class typec_vstate_cc1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr typec_vstate_cc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * CC2 line voltage level The status bitfield indicates the voltage level on the CC2 line in its steady state. The voltage variation on the CC2 line during USB PD messages due to the BMC PHY modulation does not impact the bitfield value.
 */
class typec_vstate_cc2_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr typec_vstate_cc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FRS detection event The flag is cleared by setting the FRSEVTCF bit.
 */
class frsevt_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr frsevt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_sr_r>() const {return opsy::utility::clear_set<ucpd_sr_r>(mask, *this);}
	constexpr auto operator|(ucpd_sr_r other) const -> ucpd_sr_r { return static_cast<ucpd_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_sr_r> other) const -> opsy::utility::clear_set<ucpd_sr_r> {return opsy::utility::clear_set<ucpd_sr_r>(ucpd_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txis() const -> txis_f {return txis_f((value_ & txis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgdisc() const -> txmsgdisc_f {return txmsgdisc_f((value_ & txmsgdisc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgsent() const -> txmsgsent_f {return txmsgsent_f((value_ & txmsgsent_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgabt() const -> txmsgabt_f {return txmsgabt_f((value_ & txmsgabt_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstdisc() const -> hrstdisc_f {return hrstdisc_f((value_ & hrstdisc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstsent() const -> hrstsent_f {return hrstsent_f((value_ & hrstsent_f::mask) != 0);}
	[[nodiscard]] constexpr auto txund() const -> txund_f {return txund_f((value_ & txund_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxne() const -> rxne_f {return rxne_f((value_ & rxne_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxorddet() const -> rxorddet_f {return rxorddet_f((value_ & rxorddet_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxhrstdet() const -> rxhrstdet_f {return rxhrstdet_f((value_ & rxhrstdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxovr() const -> rxovr_f {return rxovr_f((value_ & rxovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxmsgend() const -> rxmsgend_f {return rxmsgend_f((value_ & rxmsgend_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxerr() const -> rxerr_f {return rxerr_f((value_ & rxerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt1() const -> typecevt1_f {return typecevt1_f((value_ & typecevt1_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt2() const -> typecevt2_f {return typecevt2_f((value_ & typecevt2_f::mask) != 0);}
	[[nodiscard]] constexpr auto typec_vstate_cc1() const -> typec_vstate_cc1_f {return typec_vstate_cc1_f(static_cast<uint8_t>(value_ >> typec_vstate_cc1_f::offset));}
	[[nodiscard]] constexpr auto typec_vstate_cc2() const -> typec_vstate_cc2_f {return typec_vstate_cc2_f(static_cast<uint8_t>(value_ >> typec_vstate_cc2_f::offset));}
	[[nodiscard]] constexpr auto frsevt() const -> frsevt_f {return frsevt_f((value_ & frsevt_f::mask) != 0);}

	constexpr ucpd_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_sr_r other) const -> ucpd_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD interrupt clear register 
 */
class ucpd_icr_r {
public:

/**
 * Tx message discard flag (TXMSGDISC) clear Setting the bit clears the TXMSGDISC flag in the UCPD_SR register.
 */
class txmsgdisccf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgdisccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx message send flag (TXMSGSENT) clear Setting the bit clears the TXMSGSENT flag in the UCPD_SR register.
 */
class txmsgsentcf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgsentcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx message abort flag (TXMSGABT) clear Setting the bit clears the TXMSGABT flag in the UCPD_SR register.
 */
class txmsgabtcf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txmsgabtcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hard reset discard flag (HRSTDISC) clear Setting the bit clears the HRSTDISC flag in the UCPD_SR register.
 */
class hrstdisccf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstdisccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hard reset send flag (HRSTSENT) clear Setting the bit clears the HRSTSENT flag in the UCPD_SR register.
 */
class hrstsentcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hrstsentcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx underflow flag (TXUND) clear Setting the bit clears the TXUND flag in the UCPD_SR register.
 */
class txundcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txundcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx ordered set detect flag (RXORDDET) clear Setting the bit clears the RXORDDET flag in the UCPD_SR register.
 */
class rxorddetcf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxorddetcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx Hard Reset detect flag (RXHRSTDET) clear Setting the bit clears the RXHRSTDET flag in the UCPD_SR register.
 */
class rxhrstdetcf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxhrstdetcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx overflow flag (RXOVR) clear Setting the bit clears the RXOVR flag in the UCPD_SR register.
 */
class rxovrcf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxovrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx message received flag (RXMSGEND) clear Setting the bit clears the RXMSGEND flag in the UCPD_SR register.
 */
class rxmsgendcf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxmsgendcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Type-C CC1 event flag (TYPECEVT1) clear Setting the bit clears the TYPECEVT1 flag in the UCPD_SR register
 */
class typecevt1cf_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt1cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Type-C CC2 line event flag (TYPECEVT2) clear Setting the bit clears the TYPECEVT2 flag in the UCPD_SR register
 */
class typecevt2cf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr typecevt2cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FRS event flag (FRSEVT) clear Setting the bit clears the FRSEVT flag in the UCPD_SR register.
 */
class frsevtcf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr frsevtcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_icr_r>() const {return opsy::utility::clear_set<ucpd_icr_r>(mask, *this);}
	constexpr auto operator|(ucpd_icr_r other) const -> ucpd_icr_r { return static_cast<ucpd_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_icr_r> other) const -> opsy::utility::clear_set<ucpd_icr_r> {return opsy::utility::clear_set<ucpd_icr_r>(ucpd_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txmsgdisccf() const -> txmsgdisccf_f {return txmsgdisccf_f((value_ & txmsgdisccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgsentcf() const -> txmsgsentcf_f {return txmsgsentcf_f((value_ & txmsgsentcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmsgabtcf() const -> txmsgabtcf_f {return txmsgabtcf_f((value_ & txmsgabtcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstdisccf() const -> hrstdisccf_f {return hrstdisccf_f((value_ & hrstdisccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hrstsentcf() const -> hrstsentcf_f {return hrstsentcf_f((value_ & hrstsentcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txundcf() const -> txundcf_f {return txundcf_f((value_ & txundcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxorddetcf() const -> rxorddetcf_f {return rxorddetcf_f((value_ & rxorddetcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxhrstdetcf() const -> rxhrstdetcf_f {return rxhrstdetcf_f((value_ & rxhrstdetcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxovrcf() const -> rxovrcf_f {return rxovrcf_f((value_ & rxovrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxmsgendcf() const -> rxmsgendcf_f {return rxmsgendcf_f((value_ & rxmsgendcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt1cf() const -> typecevt1cf_f {return typecevt1cf_f((value_ & typecevt1cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto typecevt2cf() const -> typecevt2cf_f {return typecevt2cf_f((value_ & typecevt2cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto frsevtcf() const -> frsevtcf_f {return frsevtcf_f((value_ & frsevtcf_f::mask) != 0);}

	constexpr ucpd_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_icr_r other) const -> ucpd_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Tx ordered set type register 
 */
class ucpd_tx_ordsetr_r {
public:

/**
 * Ordered set to transmit The bitfield determines a full 20-bit sequence to transmit, consisting of four K-codes, each of five bits, defining the packet to transmit. The bit 0 (bit 0 of K-code1) is the first, the bit 19 (bit 4 of K-code4) the last.
 */
class txordset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txordset_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator ucpd_tx_ordsetr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_tx_ordsetr_r>() const {return opsy::utility::clear_set<ucpd_tx_ordsetr_r>(mask, *this);}
	constexpr auto operator|(ucpd_tx_ordsetr_r other) const -> ucpd_tx_ordsetr_r { return static_cast<ucpd_tx_ordsetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_tx_ordsetr_r> other) const -> opsy::utility::clear_set<ucpd_tx_ordsetr_r> {return opsy::utility::clear_set<ucpd_tx_ordsetr_r>(ucpd_tx_ordsetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txordset() const -> txordset_f {return txordset_f(static_cast<uint32_t>(value_ >> txordset_f::offset));}

	constexpr ucpd_tx_ordsetr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_tx_ordsetr_r other) const -> ucpd_tx_ordsetr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_tx_ordsetr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Tx payload size register 
 */
class ucpd_tx_payszr_r {
public:

/**
 * Payload size yet to transmit The bitfield is modified by software and by hardware. It contains the number of bytes of a payload (including header but excluding CRC) yet to transmit: each time a data byte is written into the UCPD_TXDR register, the bitfield value decrements and the TXIS bit is set, except when the bitfield value reaches zero. The enumerated values are standard payload sizes before the start of transmission.
 */
class txpaysz_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr txpaysz_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator ucpd_tx_payszr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_tx_payszr_r>() const {return opsy::utility::clear_set<ucpd_tx_payszr_r>(mask, *this);}
	constexpr auto operator|(ucpd_tx_payszr_r other) const -> ucpd_tx_payszr_r { return static_cast<ucpd_tx_payszr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_tx_payszr_r> other) const -> opsy::utility::clear_set<ucpd_tx_payszr_r> {return opsy::utility::clear_set<ucpd_tx_payszr_r>(ucpd_tx_payszr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto txpaysz() const -> txpaysz_f {return txpaysz_f(static_cast<uint16_t>(value_ >> txpaysz_f::offset));}

	constexpr ucpd_tx_payszr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_tx_payszr_r other) const -> ucpd_tx_payszr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_tx_payszr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Tx data register 
 */
class ucpd_txdr_r {
public:

/**
 * Data byte to transmit
 */
class txdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr txdata_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_txdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_txdr_r>() const {return opsy::utility::clear_set<ucpd_txdr_r>(mask, *this);}
	constexpr auto operator|(ucpd_txdr_r other) const -> ucpd_txdr_r { return static_cast<ucpd_txdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_txdr_r> other) const -> opsy::utility::clear_set<ucpd_txdr_r> {return opsy::utility::clear_set<ucpd_txdr_r>(ucpd_txdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto txdata() const -> txdata_f {return txdata_f(static_cast<uint8_t>(value_ >> txdata_f::offset));}

	constexpr ucpd_txdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_txdr_r other) const -> ucpd_txdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_txdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Rx ordered set register 
 */
class ucpd_rx_ordsetr_r {
public:

/**
 * Rx ordered set code detected
 */
class rxordset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxordset_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_rx_ordsetr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rx_ordsetr_r>() const {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_ordsetr_r other) const -> ucpd_rx_ordsetr_r { return static_cast<ucpd_rx_ordsetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_ordsetr_r> other) const -> opsy::utility::clear_set<ucpd_rx_ordsetr_r> {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(ucpd_rx_ordsetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * The bit indicates the number of correct K-codes. For debug purposes only.
 */
class rxsop3of4_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxsop3of4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ucpd_rx_ordsetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ucpd_rx_ordsetr_r>() const {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_ordsetr_r other) const -> ucpd_rx_ordsetr_r { return static_cast<ucpd_rx_ordsetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_ordsetr_r> other) const -> opsy::utility::clear_set<ucpd_rx_ordsetr_r> {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(ucpd_rx_ordsetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * The bitfield is for debug purposes only. Others: Invalid
 */
class rxsopkinvalid_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxsopkinvalid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_rx_ordsetr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rx_ordsetr_r>() const {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_ordsetr_r other) const -> ucpd_rx_ordsetr_r { return static_cast<ucpd_rx_ordsetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_ordsetr_r> other) const -> opsy::utility::clear_set<ucpd_rx_ordsetr_r> {return opsy::utility::clear_set<ucpd_rx_ordsetr_r>(ucpd_rx_ordsetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rxordset() const -> rxordset_f {return rxordset_f(static_cast<uint8_t>(value_ >> rxordset_f::offset));}
	[[nodiscard]] constexpr auto rxsop3of4() const -> rxsop3of4_f {return rxsop3of4_f((value_ & rxsop3of4_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxsopkinvalid() const -> rxsopkinvalid_f {return rxsopkinvalid_f(static_cast<uint8_t>(value_ >> rxsopkinvalid_f::offset));}

	constexpr ucpd_rx_ordsetr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_rx_ordsetr_r other) const -> ucpd_rx_ordsetr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_rx_ordsetr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Rx payload size register 
 */
class ucpd_rx_payszr_r {
public:

/**
 * Rx payload size received This bitfield contains the number of bytes of a payload (including header but excluding CRC) received: each time a new data byte is received in the UCPD_RXDR register, the bitfield value increments and the RXMSGEND flag is set (and an interrupt generated if enabled). The bitfield may return a spurious value when a byte reception is ongoing (the RXMSGEND flag is low).
 */
class rxpaysz_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rxpaysz_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator ucpd_rx_payszr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rx_payszr_r>() const {return opsy::utility::clear_set<ucpd_rx_payszr_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_payszr_r other) const -> ucpd_rx_payszr_r { return static_cast<ucpd_rx_payszr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_payszr_r> other) const -> opsy::utility::clear_set<ucpd_rx_payszr_r> {return opsy::utility::clear_set<ucpd_rx_payszr_r>(ucpd_rx_payszr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rxpaysz() const -> rxpaysz_f {return rxpaysz_f(static_cast<uint16_t>(value_ >> rxpaysz_f::offset));}

	constexpr ucpd_rx_payszr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_rx_payszr_r other) const -> ucpd_rx_payszr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_rx_payszr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD receive data register 
 */
class ucpd_rxdr_r {
public:

/**
 * Data byte received
 */
class rxdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxdata_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_rxdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rxdr_r>() const {return opsy::utility::clear_set<ucpd_rxdr_r>(mask, *this);}
	constexpr auto operator|(ucpd_rxdr_r other) const -> ucpd_rxdr_r { return static_cast<ucpd_rxdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rxdr_r> other) const -> opsy::utility::clear_set<ucpd_rxdr_r> {return opsy::utility::clear_set<ucpd_rxdr_r>(ucpd_rxdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rxdata() const -> rxdata_f {return rxdata_f(static_cast<uint8_t>(value_ >> rxdata_f::offset));}

	constexpr ucpd_rxdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_rxdr_r other) const -> ucpd_rxdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_rxdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Rx ordered set extension register 1 
 */
class ucpd_rx_ordextr1_r {
public:

/**
 * Ordered set 1 received The bitfield contains a full 20-bit sequence received, consisting of four K-codes, each of five bits. The bit 0 (bit 0 of K-code1) is receive first, the bit 19 (bit 4 of K-code4) last.
 */
class rxsopx1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxsopx1_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator ucpd_rx_ordextr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rx_ordextr1_r>() const {return opsy::utility::clear_set<ucpd_rx_ordextr1_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_ordextr1_r other) const -> ucpd_rx_ordextr1_r { return static_cast<ucpd_rx_ordextr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_ordextr1_r> other) const -> opsy::utility::clear_set<ucpd_rx_ordextr1_r> {return opsy::utility::clear_set<ucpd_rx_ordextr1_r>(ucpd_rx_ordextr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxsopx1() const -> rxsopx1_f {return rxsopx1_f(static_cast<uint32_t>(value_ >> rxsopx1_f::offset));}

	constexpr ucpd_rx_ordextr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_rx_ordextr1_r other) const -> ucpd_rx_ordextr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_rx_ordextr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * UCPD Rx ordered set extension register 2 
 */
class ucpd_rx_ordextr2_r {
public:

/**
 * Ordered set 2 received The bitfield contains a full 20-bit sequence received, consisting of four K-codes, each of five bits. The bit 0 (bit 0 of K-code1) is receive first, the bit 19 (bit 4 of K-code4) last.
 */
class rxsopx2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxsopx2_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator ucpd_rx_ordextr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_rx_ordextr2_r>() const {return opsy::utility::clear_set<ucpd_rx_ordextr2_r>(mask, *this);}
	constexpr auto operator|(ucpd_rx_ordextr2_r other) const -> ucpd_rx_ordextr2_r { return static_cast<ucpd_rx_ordextr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_rx_ordextr2_r> other) const -> opsy::utility::clear_set<ucpd_rx_ordextr2_r> {return opsy::utility::clear_set<ucpd_rx_ordextr2_r>(ucpd_rx_ordextr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxsopx2() const -> rxsopx2_f {return rxsopx2_f(static_cast<uint32_t>(value_ >> rxsopx2_f::offset));}

	constexpr ucpd_rx_ordextr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_rx_ordextr2_r other) const -> ucpd_rx_ordextr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_rx_ordextr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,ucpd_cfgr1_r> ucpd_cfgr1;
	opsy::utility::memory<uint32_t,ucpd_cfgr2_r> ucpd_cfgr2;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,ucpd_cr_r> ucpd_cr;
	opsy::utility::memory<uint32_t,ucpd_imr_r> ucpd_imr;
	opsy::utility::memory<uint32_t,ucpd_sr_r> ucpd_sr;
	opsy::utility::memory<uint32_t,ucpd_icr_r> ucpd_icr;
	opsy::utility::memory<uint32_t,ucpd_tx_ordsetr_r> ucpd_tx_ordsetr;
	opsy::utility::memory<uint32_t,ucpd_tx_payszr_r> ucpd_tx_payszr;
	opsy::utility::memory<uint32_t,ucpd_txdr_r> ucpd_txdr;
	opsy::utility::memory<uint32_t,ucpd_rx_ordsetr_r> ucpd_rx_ordsetr;
	opsy::utility::memory<uint32_t,ucpd_rx_payszr_r> ucpd_rx_payszr;
	opsy::utility::memory<uint32_t,ucpd_rxdr_r> ucpd_rxdr;
	opsy::utility::memory<uint32_t,ucpd_rx_ordextr1_r> ucpd_rx_ordextr1;
	opsy::utility::memory<uint32_t,ucpd_rx_ordextr2_r> ucpd_rx_ordextr2;
};

static_assert(std::is_standard_layout_v<ucpd_p>);
static_assert(offsetof(ucpd_p, ucpd_cfgr1) == 0);
static_assert(offsetof(ucpd_p, ucpd_cfgr2) == 4);
static_assert(offsetof(ucpd_p, ucpd_cr) == 12);
static_assert(offsetof(ucpd_p, ucpd_imr) == 16);
static_assert(offsetof(ucpd_p, ucpd_sr) == 20);
static_assert(offsetof(ucpd_p, ucpd_icr) == 24);
static_assert(offsetof(ucpd_p, ucpd_tx_ordsetr) == 28);
static_assert(offsetof(ucpd_p, ucpd_tx_payszr) == 32);
static_assert(offsetof(ucpd_p, ucpd_txdr) == 36);
static_assert(offsetof(ucpd_p, ucpd_rx_ordsetr) == 40);
static_assert(offsetof(ucpd_p, ucpd_rx_payszr) == 44);
static_assert(offsetof(ucpd_p, ucpd_rxdr) == 48);
static_assert(offsetof(ucpd_p, ucpd_rx_ordextr1) == 52);
static_assert(offsetof(ucpd_p, ucpd_rx_ordextr2) == 56);

inline ucpd_p& sec_ucpd1 = *reinterpret_cast<ucpd_p*>(0x5000DC00);
inline ucpd_p& ucpd1 = *reinterpret_cast<ucpd_p*>(0x4000DC00);

} // STM32H563

