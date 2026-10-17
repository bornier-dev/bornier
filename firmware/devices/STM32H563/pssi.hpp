#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Parallel synchronous slave interface
 */
class pssi_p {
public:

/**
 * PSSI control register 
 */
class pssi_cr_r {
public:

/**
 * Parallel data clock polarity This bit configures the capture edge of the parallel clock or the edge used for driving outputs, depending on OUTEN.
 */
class ckpol_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ckpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data enable (PSSI_DE) polarity This bit indicates the level on the PSSI_DE pin when the data are not valid on the parallel interface.
 */
class depol_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr depol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Ready (PSSI_RDY) polarity This bit indicates the level on the PSSI_RDY pin when the data are not valid on the parallel interface.
 */
class rdypol_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rdypol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Extended data mode
 */
class edm_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr edm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PSSI enable The contents of the FIFO are flushed when ENABLE is cleared to 0. Note: When ENABLE=1, the content of PSSI_CR must not be changed, except for the ENABLE bit itself. All configuration bits can change as soon as ENABLE changes from 0 to 1. The DMA controller and all PSSI configuration registers must be programmed correctly before setting the ENABLE bit to 1. The ENABLE bit and the DCMI ENABLE bit (bit 15 of DCMI_CR) must not be set to 1 at the same time.
 */
class enable_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr enable_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data enable and ready configuration When the PSSI_RDY function is mapped to the PSSI_DE pin (settings 101 or 111), it is still the RDYPOL bit which determines its polarity. Similarly, when the PSSI_DE function is mapped to the PSSI_RDY pin (settings 110 or 111), it is still the DEPOL bit which determines its polarity.
 */
class derdycfg_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr derdycfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA enable bit
 */
class dmaen_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data direction selection bit
 */
class outen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr outen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_cr_r>() const {return opsy::utility::clear_set<pssi_cr_r>(mask, *this);}
	constexpr auto operator|(pssi_cr_r other) const -> pssi_cr_r { return static_cast<pssi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_cr_r> other) const -> opsy::utility::clear_set<pssi_cr_r> {return opsy::utility::clear_set<pssi_cr_r>(pssi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ckpol() const -> ckpol_f {return ckpol_f((value_ & ckpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto depol() const -> depol_f {return depol_f((value_ & depol_f::mask) != 0);}
	[[nodiscard]] constexpr auto rdypol() const -> rdypol_f {return rdypol_f((value_ & rdypol_f::mask) != 0);}
	[[nodiscard]] constexpr auto edm() const -> edm_f {return edm_f(static_cast<uint8_t>(value_ >> edm_f::offset));}
	[[nodiscard]] constexpr auto enable() const -> enable_f {return enable_f((value_ & enable_f::mask) != 0);}
	[[nodiscard]] constexpr auto derdycfg() const -> derdycfg_f {return derdycfg_f(static_cast<uint8_t>(value_ >> derdycfg_f::offset));}
	[[nodiscard]] constexpr auto dmaen() const -> dmaen_f {return dmaen_f((value_ & dmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto outen() const -> outen_f {return outen_f((value_ & outen_f::mask) != 0);}

	constexpr pssi_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_cr_r other) const -> pssi_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000000000000000000000000000; // 1073741824 0x40000000

private:
	uint32_t value_;
};

/**
 * PSSI status register 
 */
class pssi_sr_r {
public:

/**
 * FIFO is ready to transfer four bytes
 */
class rtt4b_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rtt4b_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_sr_r>() const {return opsy::utility::clear_set<pssi_sr_r>(mask, *this);}
	constexpr auto operator|(pssi_sr_r other) const -> pssi_sr_r { return static_cast<pssi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_sr_r> other) const -> opsy::utility::clear_set<pssi_sr_r> {return opsy::utility::clear_set<pssi_sr_r>(pssi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO is ready to transfer one byte
 */
class rtt1b_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rtt1b_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_sr_r>() const {return opsy::utility::clear_set<pssi_sr_r>(mask, *this);}
	constexpr auto operator|(pssi_sr_r other) const -> pssi_sr_r { return static_cast<pssi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_sr_r> other) const -> opsy::utility::clear_set<pssi_sr_r> {return opsy::utility::clear_set<pssi_sr_r>(pssi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rtt4b() const -> rtt4b_f {return rtt4b_f((value_ & rtt4b_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtt1b() const -> rtt1b_f {return rtt1b_f((value_ & rtt1b_f::mask) != 0);}

	constexpr pssi_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_sr_r other) const -> pssi_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PSSI raw interrupt status register 
 */
class pssi_ris_r {
public:

/**
 * Data buffer overrun/underrun raw interrupt status This bit is cleared by writing a 1 to the OVR_ISC bit in PSSI_ICR.
 */
class ovr_ris_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_ris_r>() const {return opsy::utility::clear_set<pssi_ris_r>(mask, *this);}
	constexpr auto operator|(pssi_ris_r other) const -> pssi_ris_r { return static_cast<pssi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_ris_r> other) const -> opsy::utility::clear_set<pssi_ris_r> {return opsy::utility::clear_set<pssi_ris_r>(pssi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovr_ris() const -> ovr_ris_f {return ovr_ris_f((value_ & ovr_ris_f::mask) != 0);}

	constexpr pssi_ris_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_ris_r other) const -> pssi_ris_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_ris_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PSSI interrupt enable register 
 */
class pssi_ier_r {
public:

/**
 * Data buffer overrun/underrun interrupt enable
 */
class ovr_ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_ier_r>() const {return opsy::utility::clear_set<pssi_ier_r>(mask, *this);}
	constexpr auto operator|(pssi_ier_r other) const -> pssi_ier_r { return static_cast<pssi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_ier_r> other) const -> opsy::utility::clear_set<pssi_ier_r> {return opsy::utility::clear_set<pssi_ier_r>(pssi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovr_ie() const -> ovr_ie_f {return ovr_ie_f((value_ & ovr_ie_f::mask) != 0);}

	constexpr pssi_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_ier_r other) const -> pssi_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PSSI masked interrupt status register 
 */
class pssi_mis_r {
public:

/**
 * Data buffer overrun/underrun masked interrupt status This bit is set to 1 only when PSSI_IER/OVR_IE and PSSI_RIS/OVR_RIS are both set to 1.
 */
class ovr_mis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_mis_r>() const {return opsy::utility::clear_set<pssi_mis_r>(mask, *this);}
	constexpr auto operator|(pssi_mis_r other) const -> pssi_mis_r { return static_cast<pssi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_mis_r> other) const -> opsy::utility::clear_set<pssi_mis_r> {return opsy::utility::clear_set<pssi_mis_r>(pssi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovr_mis() const -> ovr_mis_f {return ovr_mis_f((value_ & ovr_mis_f::mask) != 0);}

	constexpr pssi_mis_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_mis_r other) const -> pssi_mis_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_mis_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PSSI interrupt clear register 
 */
class pssi_icr_r {
public:

/**
 * Data buffer overrun/underrun interrupt status clear Writing this bit to 1 clears the OVR_RIS bit in PSSI_RIS.
 */
class ovr_isc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pssi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pssi_icr_r>() const {return opsy::utility::clear_set<pssi_icr_r>(mask, *this);}
	constexpr auto operator|(pssi_icr_r other) const -> pssi_icr_r { return static_cast<pssi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_icr_r> other) const -> opsy::utility::clear_set<pssi_icr_r> {return opsy::utility::clear_set<pssi_icr_r>(pssi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovr_isc() const -> ovr_isc_f {return ovr_isc_f((value_ & ovr_isc_f::mask) != 0);}

	constexpr pssi_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_icr_r other) const -> pssi_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PSSI data register 
 */
class pssi_dr_r {
public:

/**
 * Data byte 0
 */
class byte0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr byte0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_dr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_dr_r>() const {return opsy::utility::clear_set<pssi_dr_r>(mask, *this);}
	constexpr auto operator|(pssi_dr_r other) const -> pssi_dr_r { return static_cast<pssi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_dr_r> other) const -> opsy::utility::clear_set<pssi_dr_r> {return opsy::utility::clear_set<pssi_dr_r>(pssi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 1
 */
class byte1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr byte1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_dr_r>() const {return opsy::utility::clear_set<pssi_dr_r>(mask, *this);}
	constexpr auto operator|(pssi_dr_r other) const -> pssi_dr_r { return static_cast<pssi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_dr_r> other) const -> opsy::utility::clear_set<pssi_dr_r> {return opsy::utility::clear_set<pssi_dr_r>(pssi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 2
 */
class byte2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr byte2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_dr_r>() const {return opsy::utility::clear_set<pssi_dr_r>(mask, *this);}
	constexpr auto operator|(pssi_dr_r other) const -> pssi_dr_r { return static_cast<pssi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_dr_r> other) const -> opsy::utility::clear_set<pssi_dr_r> {return opsy::utility::clear_set<pssi_dr_r>(pssi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 3
 */
class byte3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr byte3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pssi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pssi_dr_r>() const {return opsy::utility::clear_set<pssi_dr_r>(mask, *this);}
	constexpr auto operator|(pssi_dr_r other) const -> pssi_dr_r { return static_cast<pssi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pssi_dr_r> other) const -> opsy::utility::clear_set<pssi_dr_r> {return opsy::utility::clear_set<pssi_dr_r>(pssi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto byte0() const -> byte0_f {return byte0_f(static_cast<uint8_t>(value_ >> byte0_f::offset));}
	[[nodiscard]] constexpr auto byte1() const -> byte1_f {return byte1_f(static_cast<uint8_t>(value_ >> byte1_f::offset));}
	[[nodiscard]] constexpr auto byte2() const -> byte2_f {return byte2_f(static_cast<uint8_t>(value_ >> byte2_f::offset));}
	[[nodiscard]] constexpr auto byte3() const -> byte3_f {return byte3_f(static_cast<uint8_t>(value_ >> byte3_f::offset));}

	constexpr pssi_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pssi_dr_r other) const -> pssi_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pssi_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,pssi_cr_r> pssi_cr;
	opsy::utility::memory<uint32_t,pssi_sr_r> pssi_sr;
	opsy::utility::memory<uint32_t,pssi_ris_r> pssi_ris;
	opsy::utility::memory<uint32_t,pssi_ier_r> pssi_ier;
	opsy::utility::memory<uint32_t,pssi_mis_r> pssi_mis;
	opsy::utility::memory<uint32_t,pssi_icr_r> pssi_icr;
	opsy::utility::padding<16> _p0;
	opsy::utility::memory<uint32_t,pssi_dr_r> pssi_dr;
};

static_assert(std::is_standard_layout_v<pssi_p>);
static_assert(offsetof(pssi_p, pssi_cr) == 0);
static_assert(offsetof(pssi_p, pssi_sr) == 4);
static_assert(offsetof(pssi_p, pssi_ris) == 8);
static_assert(offsetof(pssi_p, pssi_ier) == 12);
static_assert(offsetof(pssi_p, pssi_mis) == 16);
static_assert(offsetof(pssi_p, pssi_icr) == 20);
static_assert(offsetof(pssi_p, pssi_dr) == 40);

inline pssi_p& pssi = *reinterpret_cast<pssi_p*>(0x4202C400);
inline pssi_p& sec_pssi = *reinterpret_cast<pssi_p*>(0x5202C400);

} // STM32H563

