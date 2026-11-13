#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * SPI address block description
 */
class spi_p {
public:

/**
 * SPI/I2S control register 1
 */
class spi_cr1_r {
public:

/**
 * serial peripheral enable 
 */
class spe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * master automatic suspension in Receive mode 
 */
class masrx_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr masrx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * master transfer start 
 */
class cstart_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cstart_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * master suspend request 
 */
class csusp_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr csusp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx/Tx direction at half-duplex mode 
 */
class hddir_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hddir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal SS signal input level 
 */
class ssi_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ssi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 32-bit CRC polynomial configuration
 */
class crc33_17_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crc33_17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC calculation initialization pattern control for receiver
 */
class rcrcini_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rcrcini_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC calculation initialization pattern control for transmitter
 */
class tcrcini_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcrcini_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * locking the AF configuration of associated I/Os 
 */
class iolock_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iolock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cr1_r>() const {return opsy::utility::clear_set<spi_cr1_r>(mask, *this);}
	constexpr auto operator|(spi_cr1_r other) const -> spi_cr1_r { return static_cast<spi_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr1_r> other) const -> opsy::utility::clear_set<spi_cr1_r> {return opsy::utility::clear_set<spi_cr1_r>(spi_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto spe() const -> spe_f {return spe_f((value_ & spe_f::mask) != 0);}
	[[nodiscard]] constexpr auto masrx() const -> masrx_f {return masrx_f((value_ & masrx_f::mask) != 0);}
	[[nodiscard]] constexpr auto cstart() const -> cstart_f {return cstart_f((value_ & cstart_f::mask) != 0);}
	[[nodiscard]] constexpr auto csusp() const -> csusp_f {return csusp_f((value_ & csusp_f::mask) != 0);}
	[[nodiscard]] constexpr auto hddir() const -> hddir_f {return hddir_f((value_ & hddir_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssi() const -> ssi_f {return ssi_f((value_ & ssi_f::mask) != 0);}
	[[nodiscard]] constexpr auto crc33_17() const -> crc33_17_f {return crc33_17_f((value_ & crc33_17_f::mask) != 0);}
	[[nodiscard]] constexpr auto rcrcini() const -> rcrcini_f {return rcrcini_f((value_ & rcrcini_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcrcini() const -> tcrcini_f {return tcrcini_f((value_ & tcrcini_f::mask) != 0);}
	[[nodiscard]] constexpr auto iolock() const -> iolock_f {return iolock_f((value_ & iolock_f::mask) != 0);}

	constexpr spi_cr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_cr1_r other) const -> spi_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S control register 2
 */
class spi_cr2_r {
public:

/**
 * number of data at current transfer 
 */
class tsize_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tsize_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator spi_cr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cr2_r>() const {return opsy::utility::clear_set<spi_cr2_r>(mask, *this);}
	constexpr auto operator|(spi_cr2_r other) const -> spi_cr2_r { return static_cast<spi_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cr2_r> other) const -> opsy::utility::clear_set<spi_cr2_r> {return opsy::utility::clear_set<spi_cr2_r>(spi_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tsize() const -> tsize_f {return tsize_f(static_cast<uint16_t>(value_ >> tsize_f::offset));}

	constexpr spi_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_cr2_r other) const -> spi_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S configuration register 1
 */
class spi_cfg1_r {
public:

/**
 * number of bits in a single SPI data frame 
 */
class dsize_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FIFO threshold level 
 */
class fthlv_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fthlv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * behavior of slave transmitter at underrun condition 
 */
class udrcfg_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udrcfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx DMA stream enable
 */
class rxdmaen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx DMA stream enable
 */
class txdmaen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * length of CRC frame to be transacted and compared 
 */
class crcsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr crcsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * hardware CRC computation enable
 */
class crcen_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * master baud rate prescaler setting 
 */
class mbr_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mbr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * bypass of the prescaler at master baud rate clock generator
 */
class bpass_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bpass_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg1_r>() const {return opsy::utility::clear_set<spi_cfg1_r>(mask, *this);}
	constexpr auto operator|(spi_cfg1_r other) const -> spi_cfg1_r { return static_cast<spi_cfg1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg1_r> other) const -> opsy::utility::clear_set<spi_cfg1_r> {return opsy::utility::clear_set<spi_cfg1_r>(spi_cfg1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dsize() const -> dsize_f {return dsize_f(static_cast<uint8_t>(value_ >> dsize_f::offset));}
	[[nodiscard]] constexpr auto fthlv() const -> fthlv_f {return fthlv_f(static_cast<uint8_t>(value_ >> fthlv_f::offset));}
	[[nodiscard]] constexpr auto udrcfg() const -> udrcfg_f {return udrcfg_f((value_ & udrcfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdmaen() const -> rxdmaen_f {return rxdmaen_f((value_ & rxdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto txdmaen() const -> txdmaen_f {return txdmaen_f((value_ & txdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcsize() const -> crcsize_f {return crcsize_f(static_cast<uint8_t>(value_ >> crcsize_f::offset));}
	[[nodiscard]] constexpr auto crcen() const -> crcen_f {return crcen_f((value_ & crcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto mbr() const -> mbr_f {return mbr_f(static_cast<uint8_t>(value_ >> mbr_f::offset));}
	[[nodiscard]] constexpr auto bpass() const -> bpass_f {return bpass_f((value_ & bpass_f::mask) != 0);}

	constexpr spi_cfg1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_cfg1_r other) const -> spi_cfg1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_cfg1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1110000000000000111; // 458759 0x70007

private:
	uint32_t value_;
};

/**
 * SPI/I2S configuration register 2
 */
class spi_cfg2_r {
public:

/**
 * Master SS Idleness 
 */
class mssi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mssi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * master Inter-Data Idleness 
 */
class midi_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr midi_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RDY signal input/output management 
 */
class rdiom_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rdiom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RDY signal input/output polarity
 */
class rdiop_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rdiop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * swap functionality of MISO and MOSI pins 
 */
class ioswp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ioswp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI Communication Mode
 */
class comm_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr comm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * serial protocol 
 */
class sp_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_cfg2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SPI master
 */
class master_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr master_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data frame format 
 */
class lsbfrst_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lsbfrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clock phase
 */
class cpha_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cpha_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clock polarity
 */
class cpol_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * software management of SS signal input 
 */
class ssm_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ssm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SS input/output polarity
 */
class ssiop_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ssiop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SS output enable 
 */
class ssoe_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ssoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SS output management in master mode 
 */
class ssom_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ssom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * alternate function GPIOs control 
 */
class afcntr_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr afcntr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_cfg2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_cfg2_r>() const {return opsy::utility::clear_set<spi_cfg2_r>(mask, *this);}
	constexpr auto operator|(spi_cfg2_r other) const -> spi_cfg2_r { return static_cast<spi_cfg2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_cfg2_r> other) const -> opsy::utility::clear_set<spi_cfg2_r> {return opsy::utility::clear_set<spi_cfg2_r>(spi_cfg2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mssi() const -> mssi_f {return mssi_f(static_cast<uint8_t>(value_ >> mssi_f::offset));}
	[[nodiscard]] constexpr auto midi() const -> midi_f {return midi_f(static_cast<uint8_t>(value_ >> midi_f::offset));}
	[[nodiscard]] constexpr auto rdiom() const -> rdiom_f {return rdiom_f((value_ & rdiom_f::mask) != 0);}
	[[nodiscard]] constexpr auto rdiop() const -> rdiop_f {return rdiop_f((value_ & rdiop_f::mask) != 0);}
	[[nodiscard]] constexpr auto ioswp() const -> ioswp_f {return ioswp_f((value_ & ioswp_f::mask) != 0);}
	[[nodiscard]] constexpr auto comm() const -> comm_f {return comm_f(static_cast<uint8_t>(value_ >> comm_f::offset));}
	[[nodiscard]] constexpr auto sp() const -> sp_f {return sp_f(static_cast<uint8_t>(value_ >> sp_f::offset));}
	[[nodiscard]] constexpr auto master() const -> master_f {return master_f((value_ & master_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsbfrst() const -> lsbfrst_f {return lsbfrst_f((value_ & lsbfrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpha() const -> cpha_f {return cpha_f((value_ & cpha_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpol() const -> cpol_f {return cpol_f((value_ & cpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssm() const -> ssm_f {return ssm_f((value_ & ssm_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssiop() const -> ssiop_f {return ssiop_f((value_ & ssiop_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssoe() const -> ssoe_f {return ssoe_f((value_ & ssoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssom() const -> ssom_f {return ssom_f((value_ & ssom_f::mask) != 0);}
	[[nodiscard]] constexpr auto afcntr() const -> afcntr_f {return afcntr_f((value_ & afcntr_f::mask) != 0);}

	constexpr spi_cfg2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_cfg2_r other) const -> spi_cfg2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_cfg2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S interrupt enable register
 */
class spi_ier_r {
public:

/**
 * RXP interrupt enable
 */
class rxpie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXP interrupt enable 
 */
class txpie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DXP interrupt enabled 
 */
class dxpie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dxpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * EOT, SUSP and TXC interrupt enable
 */
class eotie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eotie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXTFIE interrupt enable
 */
class txtfie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txtfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UDR interrupt enable
 */
class udrie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr udrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OVR interrupt enable
 */
class ovrie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC error interrupt enable
 */
class crceie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crceie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIFRE interrupt enable
 */
class tifreie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tifreie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * mode Fault interrupt enable
 */
class modfie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr modfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ier_r>() const {return opsy::utility::clear_set<spi_ier_r>(mask, *this);}
	constexpr auto operator|(spi_ier_r other) const -> spi_ier_r { return static_cast<spi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ier_r> other) const -> opsy::utility::clear_set<spi_ier_r> {return opsy::utility::clear_set<spi_ier_r>(spi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rxpie() const -> rxpie_f {return rxpie_f((value_ & rxpie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txpie() const -> txpie_f {return txpie_f((value_ & txpie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dxpie() const -> dxpie_f {return dxpie_f((value_ & dxpie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eotie() const -> eotie_f {return eotie_f((value_ & eotie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txtfie() const -> txtfie_f {return txtfie_f((value_ & txtfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto udrie() const -> udrie_f {return udrie_f((value_ & udrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrie() const -> ovrie_f {return ovrie_f((value_ & ovrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto crceie() const -> crceie_f {return crceie_f((value_ & crceie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tifreie() const -> tifreie_f {return tifreie_f((value_ & tifreie_f::mask) != 0);}
	[[nodiscard]] constexpr auto modfie() const -> modfie_f {return modfie_f((value_ & modfie_f::mask) != 0);}

	constexpr spi_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_ier_r other) const -> spi_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S status register
 */
class spi_sr_r {
public:

/**
 * Rx-packet available 
 */
class rxp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx-packet space available 
 */
class txp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * duplex packet 
 */
class dxp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dxp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of transfer 
 */
class eot_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eot_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * transmission transfer filled 
 */
class txtf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txtf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * underrun 
 */
class udr_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr udr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * overrun 
 */
class ovr_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC error 
 */
class crce_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TI frame format error 
 */
class tifre_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tifre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * mode fault 
 */
class modf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr modf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * suspension status 
 */
class susp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr susp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TxFIFO transmission complete 
 */
class txc_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RxFIFO packing level 
 */
class rxplvl_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rxplvl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RxFIFO word not empty 
 */
class rxwne_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxwne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * number of data frames remaining in current TSIZE session 
 */
class ctsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ctsize_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator spi_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_sr_r>() const {return opsy::utility::clear_set<spi_sr_r>(mask, *this);}
	constexpr auto operator|(spi_sr_r other) const -> spi_sr_r { return static_cast<spi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_sr_r> other) const -> opsy::utility::clear_set<spi_sr_r> {return opsy::utility::clear_set<spi_sr_r>(spi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rxp() const -> rxp_f {return rxp_f((value_ & rxp_f::mask) != 0);}
	[[nodiscard]] constexpr auto txp() const -> txp_f {return txp_f((value_ & txp_f::mask) != 0);}
	[[nodiscard]] constexpr auto dxp() const -> dxp_f {return dxp_f((value_ & dxp_f::mask) != 0);}
	[[nodiscard]] constexpr auto eot() const -> eot_f {return eot_f((value_ & eot_f::mask) != 0);}
	[[nodiscard]] constexpr auto txtf() const -> txtf_f {return txtf_f((value_ & txtf_f::mask) != 0);}
	[[nodiscard]] constexpr auto udr() const -> udr_f {return udr_f((value_ & udr_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr() const -> ovr_f {return ovr_f((value_ & ovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto crce() const -> crce_f {return crce_f((value_ & crce_f::mask) != 0);}
	[[nodiscard]] constexpr auto tifre() const -> tifre_f {return tifre_f((value_ & tifre_f::mask) != 0);}
	[[nodiscard]] constexpr auto modf() const -> modf_f {return modf_f((value_ & modf_f::mask) != 0);}
	[[nodiscard]] constexpr auto susp() const -> susp_f {return susp_f((value_ & susp_f::mask) != 0);}
	[[nodiscard]] constexpr auto txc() const -> txc_f {return txc_f((value_ & txc_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxplvl() const -> rxplvl_f {return rxplvl_f(static_cast<uint8_t>(value_ >> rxplvl_f::offset));}
	[[nodiscard]] constexpr auto rxwne() const -> rxwne_f {return rxwne_f((value_ & rxwne_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsize() const -> ctsize_f {return ctsize_f(static_cast<uint16_t>(value_ >> ctsize_f::offset));}

	constexpr spi_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_sr_r other) const -> spi_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000000010; // 4098 0x1002

private:
	uint32_t value_;
};

/**
 * SPI/I2S interrupt/status flags clear register
 */
class spi_ifcr_r {
public:

/**
 * end of transfer flag clear 
 */
class eotc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eotc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * transmission transfer filled flag clear 
 */
class txtfc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txtfc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * underrun flag clear 
 */
class udrc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr udrc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * overrun flag clear 
 */
class ovrc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovrc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC error flag clear 
 */
class crcec_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crcec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TI frame format error flag clear 
 */
class tifrec_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tifrec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * mode fault flag clear 
 */
class modfc_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr modfc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend flag clear 
 */
class suspc_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_ifcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_ifcr_r>() const {return opsy::utility::clear_set<spi_ifcr_r>(mask, *this);}
	constexpr auto operator|(spi_ifcr_r other) const -> spi_ifcr_r { return static_cast<spi_ifcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_ifcr_r> other) const -> opsy::utility::clear_set<spi_ifcr_r> {return opsy::utility::clear_set<spi_ifcr_r>(spi_ifcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto eotc() const -> eotc_f {return eotc_f((value_ & eotc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txtfc() const -> txtfc_f {return txtfc_f((value_ & txtfc_f::mask) != 0);}
	[[nodiscard]] constexpr auto udrc() const -> udrc_f {return udrc_f((value_ & udrc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrc() const -> ovrc_f {return ovrc_f((value_ & ovrc_f::mask) != 0);}
	[[nodiscard]] constexpr auto crcec() const -> crcec_f {return crcec_f((value_ & crcec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tifrec() const -> tifrec_f {return tifrec_f((value_ & tifrec_f::mask) != 0);}
	[[nodiscard]] constexpr auto modfc() const -> modfc_f {return modfc_f((value_ & modfc_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspc() const -> suspc_f {return suspc_f((value_ & suspc_f::mask) != 0);}

	constexpr spi_ifcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_ifcr_r other) const -> spi_ifcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_ifcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * /I2SSPI/I2S transmit data register
 */
class spi_txdr_r {
public:

/**
 * transmit data register 
 */
class txdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txdr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_txdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_txdr_r>() const {return opsy::utility::clear_set<spi_txdr_r>(mask, *this);}
	constexpr auto operator|(spi_txdr_r other) const -> spi_txdr_r { return static_cast<spi_txdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_txdr_r> other) const -> opsy::utility::clear_set<spi_txdr_r> {return opsy::utility::clear_set<spi_txdr_r>(spi_txdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txdr() const -> txdr_f {return txdr_f(static_cast<uint32_t>(value_ >> txdr_f::offset));}

	constexpr spi_txdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_txdr_r other) const -> spi_txdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_txdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S receive data register
 */
class spi_rxdr_r {
public:

/**
 * receive data register 
 */
class rxdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxdr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_rxdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_rxdr_r>() const {return opsy::utility::clear_set<spi_rxdr_r>(mask, *this);}
	constexpr auto operator|(spi_rxdr_r other) const -> spi_rxdr_r { return static_cast<spi_rxdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_rxdr_r> other) const -> opsy::utility::clear_set<spi_rxdr_r> {return opsy::utility::clear_set<spi_rxdr_r>(spi_rxdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxdr() const -> rxdr_f {return rxdr_f(static_cast<uint32_t>(value_ >> rxdr_f::offset));}

	constexpr spi_rxdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_rxdr_r other) const -> spi_rxdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_rxdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S polynomial register
 */
class spi_crcpoly_r {
public:

/**
 * CRC polynomial register 
 */
class crcpoly_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr crcpoly_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_crcpoly_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_crcpoly_r>() const {return opsy::utility::clear_set<spi_crcpoly_r>(mask, *this);}
	constexpr auto operator|(spi_crcpoly_r other) const -> spi_crcpoly_r { return static_cast<spi_crcpoly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_crcpoly_r> other) const -> opsy::utility::clear_set<spi_crcpoly_r> {return opsy::utility::clear_set<spi_crcpoly_r>(spi_crcpoly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto crcpoly() const -> crcpoly_f {return crcpoly_f(static_cast<uint32_t>(value_ >> crcpoly_f::offset));}

	constexpr spi_crcpoly_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_crcpoly_r other) const -> spi_crcpoly_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_crcpoly_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000111; // 263 0x107

private:
	uint32_t value_;
};

/**
 * SPI/I2S transmitter CRC register
 */
class spi_txcrc_r {
public:

/**
 * CRC register for transmitter 
 */
class txcrc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txcrc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_txcrc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_txcrc_r>() const {return opsy::utility::clear_set<spi_txcrc_r>(mask, *this);}
	constexpr auto operator|(spi_txcrc_r other) const -> spi_txcrc_r { return static_cast<spi_txcrc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_txcrc_r> other) const -> opsy::utility::clear_set<spi_txcrc_r> {return opsy::utility::clear_set<spi_txcrc_r>(spi_txcrc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txcrc() const -> txcrc_f {return txcrc_f(static_cast<uint32_t>(value_ >> txcrc_f::offset));}

	constexpr spi_txcrc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_txcrc_r other) const -> spi_txcrc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_txcrc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S receiver CRC register
 */
class spi_rxcrc_r {
public:

/**
 * CRC register for receiver 
 */
class rxcrc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxcrc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_rxcrc_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_rxcrc_r>() const {return opsy::utility::clear_set<spi_rxcrc_r>(mask, *this);}
	constexpr auto operator|(spi_rxcrc_r other) const -> spi_rxcrc_r { return static_cast<spi_rxcrc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_rxcrc_r> other) const -> opsy::utility::clear_set<spi_rxcrc_r> {return opsy::utility::clear_set<spi_rxcrc_r>(spi_rxcrc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxcrc() const -> rxcrc_f {return rxcrc_f(static_cast<uint32_t>(value_ >> rxcrc_f::offset));}

	constexpr spi_rxcrc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_rxcrc_r other) const -> spi_rxcrc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_rxcrc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI underrun data register
 */
class spi_udrdr_r {
public:

/**
 * data at slave underrun condition 
 */
class udrdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr udrdr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator spi_udrdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_udrdr_r>() const {return opsy::utility::clear_set<spi_udrdr_r>(mask, *this);}
	constexpr auto operator|(spi_udrdr_r other) const -> spi_udrdr_r { return static_cast<spi_udrdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_udrdr_r> other) const -> opsy::utility::clear_set<spi_udrdr_r> {return opsy::utility::clear_set<spi_udrdr_r>(spi_udrdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto udrdr() const -> udrdr_f {return udrdr_f(static_cast<uint32_t>(value_ >> udrdr_f::offset));}

	constexpr spi_udrdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_udrdr_r other) const -> spi_udrdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_udrdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SPI/I2S configuration register
 */
class spi_i2scfgr_r {
public:

/**
 * I2S mode selection
 */
class i2smod_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr i2smod_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * I2S configuration mode 
 */
class i2scfg_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr i2scfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Iless thansup>2less than/sup>S standard selection 
 */
class i2sstd_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr i2sstd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PCM frame synchronization
 */
class pcmsync_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pcmsync_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data length to be transferred.
 */
class datlen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr datlen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * channel length (number of bits per audio channel)
 */
class chlen_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr chlen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * serial audio clock polarity
 */
class ckpol_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ckpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * fixed channel length in slave
 */
class fixch_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fixch_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * word select inversion 
 */
class wsinv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wsinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data format
 */
class datfmt_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr datfmt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Iless thansup>2less than/sup>S linear prescaler 
 */
class i2sdiv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr i2sdiv_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * odd factor for the prescaler 
 */
class odd_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr odd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * master clock output enable
 */
class mckoe_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mckoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator spi_i2scfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<spi_i2scfgr_r>() const {return opsy::utility::clear_set<spi_i2scfgr_r>(mask, *this);}
	constexpr auto operator|(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return static_cast<spi_i2scfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<spi_i2scfgr_r> other) const -> opsy::utility::clear_set<spi_i2scfgr_r> {return opsy::utility::clear_set<spi_i2scfgr_r>(spi_i2scfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto i2smod() const -> i2smod_f {return i2smod_f((value_ & i2smod_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2scfg() const -> i2scfg_f {return i2scfg_f(static_cast<uint8_t>(value_ >> i2scfg_f::offset));}
	[[nodiscard]] constexpr auto i2sstd() const -> i2sstd_f {return i2sstd_f(static_cast<uint8_t>(value_ >> i2sstd_f::offset));}
	[[nodiscard]] constexpr auto pcmsync() const -> pcmsync_f {return pcmsync_f((value_ & pcmsync_f::mask) != 0);}
	[[nodiscard]] constexpr auto datlen() const -> datlen_f {return datlen_f(static_cast<uint8_t>(value_ >> datlen_f::offset));}
	[[nodiscard]] constexpr auto chlen() const -> chlen_f {return chlen_f((value_ & chlen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckpol() const -> ckpol_f {return ckpol_f((value_ & ckpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto fixch() const -> fixch_f {return fixch_f((value_ & fixch_f::mask) != 0);}
	[[nodiscard]] constexpr auto wsinv() const -> wsinv_f {return wsinv_f((value_ & wsinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto datfmt() const -> datfmt_f {return datfmt_f((value_ & datfmt_f::mask) != 0);}
	[[nodiscard]] constexpr auto i2sdiv() const -> i2sdiv_f {return i2sdiv_f(static_cast<uint8_t>(value_ >> i2sdiv_f::offset));}
	[[nodiscard]] constexpr auto odd() const -> odd_f {return odd_f((value_ & odd_f::mask) != 0);}
	[[nodiscard]] constexpr auto mckoe() const -> mckoe_f {return mckoe_f((value_ & mckoe_f::mask) != 0);}

	constexpr spi_i2scfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(spi_i2scfgr_r other) const -> spi_i2scfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> spi_i2scfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,spi_cr1_r> spi_cr1;
	opsy::utility::memory<uint32_t,spi_cr2_r> spi_cr2;
	opsy::utility::memory<uint32_t,spi_cfg1_r> spi_cfg1;
	opsy::utility::memory<uint32_t,spi_cfg2_r> spi_cfg2;
	opsy::utility::memory<uint32_t,spi_ier_r> spi_ier;
	opsy::utility::read_only_memory<uint32_t,spi_sr_r> spi_sr;
	opsy::utility::write_only_memory<uint32_t,spi_ifcr_r> spi_ifcr;
	opsy::utility::padding<4> _p28;
	opsy::utility::write_only_memory<uint32_t,spi_txdr_r> spi_txdr;
	opsy::utility::padding<12> _p36;
	opsy::utility::read_only_memory<uint32_t,spi_rxdr_r> spi_rxdr;
	opsy::utility::padding<12> _p52;
	opsy::utility::memory<uint32_t,spi_crcpoly_r> spi_crcpoly;
	opsy::utility::read_only_memory<uint32_t,spi_txcrc_r> spi_txcrc;
	opsy::utility::read_only_memory<uint32_t,spi_rxcrc_r> spi_rxcrc;
	opsy::utility::memory<uint32_t,spi_udrdr_r> spi_udrdr;
	opsy::utility::memory<uint32_t,spi_i2scfgr_r> spi_i2scfgr;
};

static_assert(std::is_standard_layout_v<spi_p>);
static_assert(offsetof(spi_p, spi_cr1) == 0);
static_assert(offsetof(spi_p, spi_cr2) == 4);
static_assert(offsetof(spi_p, spi_cfg1) == 8);
static_assert(offsetof(spi_p, spi_cfg2) == 12);
static_assert(offsetof(spi_p, spi_ier) == 16);
static_assert(offsetof(spi_p, spi_sr) == 20);
static_assert(offsetof(spi_p, spi_ifcr) == 24);
static_assert(offsetof(spi_p, spi_txdr) == 32);
static_assert(offsetof(spi_p, spi_rxdr) == 48);
static_assert(offsetof(spi_p, spi_crcpoly) == 64);
static_assert(offsetof(spi_p, spi_txcrc) == 68);
static_assert(offsetof(spi_p, spi_rxcrc) == 72);
static_assert(offsetof(spi_p, spi_udrdr) == 76);
static_assert(offsetof(spi_p, spi_i2scfgr) == 80);

inline spi_p& spi = *reinterpret_cast<spi_p*>(0x40013000);
inline spi_p& spi_s = *reinterpret_cast<spi_p*>(0x50013000);
inline spi_p& spi2 = *reinterpret_cast<spi_p*>(0x40003800);
inline spi_p& spi2_s = *reinterpret_cast<spi_p*>(0x50003800);
inline spi_p& spi3 = *reinterpret_cast<spi_p*>(0x40003C00);
inline spi_p& spi3_s = *reinterpret_cast<spi_p*>(0x50003C00);
inline spi_p& spi4 = *reinterpret_cast<spi_p*>(0x40014C00);
inline spi_p& spi4_s = *reinterpret_cast<spi_p*>(0x50014C00);

} // STM32H523

