#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * UCPD register block
 */
class ucpd_p {
public:

/**
 * UCPD configuration register 1
 */
class ucpd_cfgr1_r {
public:

/**
 * Division ratio for producing half-bit clock 
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
 * Division ratio for producing inter-frame gap timer clock 
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
 * Transition window duration 
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
 * Pre-scaler division ratio for generating ucpd_clk 
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
 * Receiver ordered set enable 
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
 * Transmission DMA mode enable 
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
 * Reception DMA mode enable 
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
 * UCPD peripheral enable 
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
 * BMC decoder Rx pre-filter enable 
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
 * BMC decoder Rx pre-filter sampling method 
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
 * Wake-up from Stop mode enable 
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
 * Rx analog filter enable 
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
 * UCPD configuration register 3
 */
class ucpd_cfgr3_r {
public:

/**
 * SW trim value for Rd resistor on the CC1 line
 */
class trim_cc1_rd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trim_cc1_rd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr3_r>() const {return opsy::utility::clear_set<ucpd_cfgr3_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr3_r other) const -> ucpd_cfgr3_r { return static_cast<ucpd_cfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr3_r> other) const -> opsy::utility::clear_set<ucpd_cfgr3_r> {return opsy::utility::clear_set<ucpd_cfgr3_r>(ucpd_cfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SW trim value for Rp current sources on the CC1 line
 */
class trim_cc1_rp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trim_cc1_rp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr3_r>() const {return opsy::utility::clear_set<ucpd_cfgr3_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr3_r other) const -> ucpd_cfgr3_r { return static_cast<ucpd_cfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr3_r> other) const -> opsy::utility::clear_set<ucpd_cfgr3_r> {return opsy::utility::clear_set<ucpd_cfgr3_r>(ucpd_cfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SW trim value for Rd resistor on the CC2 line
 */
class trim_cc2_rd_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trim_cc2_rd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr3_r>() const {return opsy::utility::clear_set<ucpd_cfgr3_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr3_r other) const -> ucpd_cfgr3_r { return static_cast<ucpd_cfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr3_r> other) const -> opsy::utility::clear_set<ucpd_cfgr3_r> {return opsy::utility::clear_set<ucpd_cfgr3_r>(ucpd_cfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SW trim value for Rp current sources on the CC2 line
 */
class trim_cc2_rp_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trim_cc2_rp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ucpd_cfgr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ucpd_cfgr3_r>() const {return opsy::utility::clear_set<ucpd_cfgr3_r>(mask, *this);}
	constexpr auto operator|(ucpd_cfgr3_r other) const -> ucpd_cfgr3_r { return static_cast<ucpd_cfgr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ucpd_cfgr3_r> other) const -> opsy::utility::clear_set<ucpd_cfgr3_r> {return opsy::utility::clear_set<ucpd_cfgr3_r>(ucpd_cfgr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto trim_cc1_rd() const -> trim_cc1_rd_f {return trim_cc1_rd_f(static_cast<uint8_t>(value_ >> trim_cc1_rd_f::offset));}
	[[nodiscard]] constexpr auto trim_cc1_rp() const -> trim_cc1_rp_f {return trim_cc1_rp_f(static_cast<uint8_t>(value_ >> trim_cc1_rp_f::offset));}
	[[nodiscard]] constexpr auto trim_cc2_rd() const -> trim_cc2_rd_f {return trim_cc2_rd_f(static_cast<uint8_t>(value_ >> trim_cc2_rd_f::offset));}
	[[nodiscard]] constexpr auto trim_cc2_rp() const -> trim_cc2_rp_f {return trim_cc2_rp_f(static_cast<uint8_t>(value_ >> trim_cc2_rp_f::offset));}

	constexpr ucpd_cfgr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ucpd_cfgr3_r other) const -> ucpd_cfgr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ucpd_cfgr3_r { return ~value_; }
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
 * Type of Tx packet 
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
 * Command to send a Tx packet 
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
 * Command to send a Tx Hard Reset 
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
 * Receiver mode 
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
 * USB Power Delivery receiver enable 
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
 * CC1/CC2 line selector for USB Power Delivery signaling 
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
 * Analog PHY sub-mode 
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
 * Analog PHY operating mode 
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
 * CC line enable 
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
 * FRS event detection enable 
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
 * FRS Tx signaling enable.
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
 * Rdch condition drive 
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
 * CC1 Type-C detector disable 
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
 * CC2 Type-C detector disable 
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
 * Transmit interrupt status 
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
 * Message transmission discarded 
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
 * Message transmission completed 
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
 * Transmit message abort 
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
 * Hard Reset discarded 
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
 * Hard Reset message sent 
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
 * Tx data underrun detection 
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
 * Receive data register not empty detection 
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
 * Rx ordered set (4 K-codes) detection 
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
 * Rx Hard Reset receipt detection 
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
 * Rx data overflow detection 
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
 * Rx message received 
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
 * Receive message error 
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
 * Type-C voltage level event on CC1 line 
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
 * Type-C voltage level event on CC2 line 
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
 * The status bitfield indicates the voltage level on the CC1 line in its steady state.
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
 * CC2 line voltage level 
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
 * FRS detection event 
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
 * Tx message discard flag (TXMSGDISC) clear 
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
 * Tx message send flag (TXMSGSENT) clear 
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
 * Tx message abort flag (TXMSGABT) clear 
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
 * Hard reset discard flag (HRSTDISC) clear 
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
 * Hard reset send flag (HRSTSENT) clear 
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
 * Tx underflow flag (TXUND) clear 
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
 * Rx ordered set detect flag (RXORDDET) clear 
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
 * Rx Hard Reset detect flag (RXHRSTDET) clear 
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
 * Rx overflow flag (RXOVR) clear 
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
 * Rx message received flag (RXMSGEND) clear 
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
 * Type-C CC1 event flag (TYPECEVT1) clear 
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
 * Type-C CC2 line event flag (TYPECEVT2) clear 
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
 * FRS event flag (FRSEVT) clear 
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
 * Ordered set to transmit 
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
 * Payload size yet to transmit 
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
 * The bit indicates the number of correct K-codes.
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
 * The bitfield is for debug purposes only.
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
 * Rx payload size received 
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
 * Ordered set 1 received 
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
 * Ordered set 2 received 
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
	opsy::utility::memory<uint32_t,ucpd_cfgr3_r> ucpd_cfgr3;
	opsy::utility::memory<uint32_t,ucpd_cr_r> ucpd_cr;
	opsy::utility::memory<uint32_t,ucpd_imr_r> ucpd_imr;
	opsy::utility::read_only_memory<uint32_t,ucpd_sr_r> ucpd_sr;
	opsy::utility::write_only_memory<uint32_t,ucpd_icr_r> ucpd_icr;
	opsy::utility::memory<uint32_t,ucpd_tx_ordsetr_r> ucpd_tx_ordsetr;
	opsy::utility::memory<uint32_t,ucpd_tx_payszr_r> ucpd_tx_payszr;
	opsy::utility::memory<uint32_t,ucpd_txdr_r> ucpd_txdr;
	opsy::utility::read_only_memory<uint32_t,ucpd_rx_ordsetr_r> ucpd_rx_ordsetr;
	opsy::utility::read_only_memory<uint32_t,ucpd_rx_payszr_r> ucpd_rx_payszr;
	opsy::utility::read_only_memory<uint32_t,ucpd_rxdr_r> ucpd_rxdr;
	opsy::utility::memory<uint32_t,ucpd_rx_ordextr1_r> ucpd_rx_ordextr1;
	opsy::utility::memory<uint32_t,ucpd_rx_ordextr2_r> ucpd_rx_ordextr2;
};

static_assert(std::is_standard_layout_v<ucpd_p>);
static_assert(offsetof(ucpd_p, ucpd_cfgr1) == 0);
static_assert(offsetof(ucpd_p, ucpd_cfgr2) == 4);
static_assert(offsetof(ucpd_p, ucpd_cfgr3) == 8);
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

inline ucpd_p& ucpd = *reinterpret_cast<ucpd_p*>(0x4000DC00);
inline ucpd_p& ucpd_s = *reinterpret_cast<ucpd_p*>(0x5000DC00);

} // STM32H523

