#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * I2C address block description
 */
class i2c_p {
public:

/**
 * I2C control register 1
 */
class i2c_cr1_r {
public:

/**
 * Peripheral enable 
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX interrupt enable
 */
class txie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX interrupt enable
 */
class rxie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address match interrupt enable (slave only)
 */
class addrie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Not acknowledge received interrupt enable
 */
class nackie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nackie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Stop detection interrupt enable
 */
class stopie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error interrupts enable 
 */
class errie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Digital noise filter 
 */
class dnf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dnf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_cr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Analog noise filter OFF 
 */
class anfoff_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr anfoff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA transmission requests enable
 */
class txdmaen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA reception requests enable
 */
class rxdmaen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Slave byte control 
 */
class sbc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock stretching disable 
 */
class nostretch_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nostretch_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from Stop mode enable 
 */
class wupen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wupen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * General call enable
 */
class gcen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr gcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMBus host address enable 
 */
class smbhen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smbhen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMBus device default address enable 
 */
class smbden_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smbden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMBus alert enable 
 */
class alerten_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr alerten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PEC enable 
 */
class pecen_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pecen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fast-mode Plus 20 mA drive enable
 */
class fmp_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address match flag (ADDR) automatic clear
 */
class addraclr_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr addraclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STOP detection flag (STOPF) automatic clear
 */
class stopfaclr_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr stopfaclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr1_r>() const {return opsy::utility::clear_set<i2c_cr1_r>(mask, *this);}
	constexpr auto operator|(i2c_cr1_r other) const -> i2c_cr1_r { return static_cast<i2c_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr1_r> other) const -> opsy::utility::clear_set<i2c_cr1_r> {return opsy::utility::clear_set<i2c_cr1_r>(i2c_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pe() const -> pe_f {return pe_f((value_ & pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto txie() const -> txie_f {return txie_f((value_ & txie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxie() const -> rxie_f {return rxie_f((value_ & rxie_f::mask) != 0);}
	[[nodiscard]] constexpr auto addrie() const -> addrie_f {return addrie_f((value_ & addrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto nackie() const -> nackie_f {return nackie_f((value_ & nackie_f::mask) != 0);}
	[[nodiscard]] constexpr auto stopie() const -> stopie_f {return stopie_f((value_ & stopie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dnf() const -> dnf_f {return dnf_f(static_cast<uint8_t>(value_ >> dnf_f::offset));}
	[[nodiscard]] constexpr auto anfoff() const -> anfoff_f {return anfoff_f((value_ & anfoff_f::mask) != 0);}
	[[nodiscard]] constexpr auto txdmaen() const -> txdmaen_f {return txdmaen_f((value_ & txdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdmaen() const -> rxdmaen_f {return rxdmaen_f((value_ & rxdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbc() const -> sbc_f {return sbc_f((value_ & sbc_f::mask) != 0);}
	[[nodiscard]] constexpr auto nostretch() const -> nostretch_f {return nostretch_f((value_ & nostretch_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen() const -> wupen_f {return wupen_f((value_ & wupen_f::mask) != 0);}
	[[nodiscard]] constexpr auto gcen() const -> gcen_f {return gcen_f((value_ & gcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto smbhen() const -> smbhen_f {return smbhen_f((value_ & smbhen_f::mask) != 0);}
	[[nodiscard]] constexpr auto smbden() const -> smbden_f {return smbden_f((value_ & smbden_f::mask) != 0);}
	[[nodiscard]] constexpr auto alerten() const -> alerten_f {return alerten_f((value_ & alerten_f::mask) != 0);}
	[[nodiscard]] constexpr auto pecen() const -> pecen_f {return pecen_f((value_ & pecen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmp() const -> fmp_f {return fmp_f((value_ & fmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto addraclr() const -> addraclr_f {return addraclr_f((value_ & addraclr_f::mask) != 0);}
	[[nodiscard]] constexpr auto stopfaclr() const -> stopfaclr_f {return stopfaclr_f((value_ & stopfaclr_f::mask) != 0);}

	constexpr i2c_cr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_cr1_r other) const -> i2c_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C control register 2
 */
class i2c_cr2_r {
public:

/**
 * Slave address (master mode) 
 */
class sadd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sadd_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i2c_cr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Transfer direction (master mode) 
 */
class rd_wrn_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rd_wrn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 10-bit addressing mode (master mode) 
 */
class add10_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr add10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 10-bit address header only read direction (master receiver mode) 
 */
class head10r_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr head10r_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start generation 
 */
class start_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr start_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Stop generation (master mode) 
 */
class stop_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * NACK generation (slave mode) 
 */
class nack_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr nack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of bytes 
 */
class nbytes_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nbytes_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * NBYTES reload mode 
 */
class reload_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reload_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic end mode (master mode) 
 */
class autoend_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr autoend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Packet error checking byte 
 */
class pecbyte_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pecbyte_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_cr2_r>() const {return opsy::utility::clear_set<i2c_cr2_r>(mask, *this);}
	constexpr auto operator|(i2c_cr2_r other) const -> i2c_cr2_r { return static_cast<i2c_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_cr2_r> other) const -> opsy::utility::clear_set<i2c_cr2_r> {return opsy::utility::clear_set<i2c_cr2_r>(i2c_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sadd() const -> sadd_f {return sadd_f(static_cast<uint16_t>(value_ >> sadd_f::offset));}
	[[nodiscard]] constexpr auto rd_wrn() const -> rd_wrn_f {return rd_wrn_f((value_ & rd_wrn_f::mask) != 0);}
	[[nodiscard]] constexpr auto add10() const -> add10_f {return add10_f((value_ & add10_f::mask) != 0);}
	[[nodiscard]] constexpr auto head10r() const -> head10r_f {return head10r_f((value_ & head10r_f::mask) != 0);}
	[[nodiscard]] constexpr auto start() const -> start_f {return start_f((value_ & start_f::mask) != 0);}
	[[nodiscard]] constexpr auto stop() const -> stop_f {return stop_f((value_ & stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto nack() const -> nack_f {return nack_f((value_ & nack_f::mask) != 0);}
	[[nodiscard]] constexpr auto nbytes() const -> nbytes_f {return nbytes_f(static_cast<uint8_t>(value_ >> nbytes_f::offset));}
	[[nodiscard]] constexpr auto reload() const -> reload_f {return reload_f((value_ & reload_f::mask) != 0);}
	[[nodiscard]] constexpr auto autoend() const -> autoend_f {return autoend_f((value_ & autoend_f::mask) != 0);}
	[[nodiscard]] constexpr auto pecbyte() const -> pecbyte_f {return pecbyte_f((value_ & pecbyte_f::mask) != 0);}

	constexpr i2c_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_cr2_r other) const -> i2c_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C own address 1 register
 */
class i2c_oar1_r {
public:

/**
 * Interface own slave address 
 */
class oa1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr oa1_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i2c_oar1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_oar1_r>() const {return opsy::utility::clear_set<i2c_oar1_r>(mask, *this);}
	constexpr auto operator|(i2c_oar1_r other) const -> i2c_oar1_r { return static_cast<i2c_oar1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar1_r> other) const -> opsy::utility::clear_set<i2c_oar1_r> {return opsy::utility::clear_set<i2c_oar1_r>(i2c_oar1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Own address 1 10-bit mode 
 */
class oa1mode_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oa1mode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_oar1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_oar1_r>() const {return opsy::utility::clear_set<i2c_oar1_r>(mask, *this);}
	constexpr auto operator|(i2c_oar1_r other) const -> i2c_oar1_r { return static_cast<i2c_oar1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar1_r> other) const -> opsy::utility::clear_set<i2c_oar1_r> {return opsy::utility::clear_set<i2c_oar1_r>(i2c_oar1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Own address 1 enable
 */
class oa1en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oa1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_oar1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_oar1_r>() const {return opsy::utility::clear_set<i2c_oar1_r>(mask, *this);}
	constexpr auto operator|(i2c_oar1_r other) const -> i2c_oar1_r { return static_cast<i2c_oar1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar1_r> other) const -> opsy::utility::clear_set<i2c_oar1_r> {return opsy::utility::clear_set<i2c_oar1_r>(i2c_oar1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto oa1() const -> oa1_f {return oa1_f(static_cast<uint16_t>(value_ >> oa1_f::offset));}
	[[nodiscard]] constexpr auto oa1mode() const -> oa1mode_f {return oa1mode_f((value_ & oa1mode_f::mask) != 0);}
	[[nodiscard]] constexpr auto oa1en() const -> oa1en_f {return oa1en_f((value_ & oa1en_f::mask) != 0);}

	constexpr i2c_oar1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_oar1_r other) const -> i2c_oar1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_oar1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C own address 2 register
 */
class i2c_oar2_r {
public:

/**
 * Interface address 
 */
class oa2_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr oa2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_oar2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_oar2_r>() const {return opsy::utility::clear_set<i2c_oar2_r>(mask, *this);}
	constexpr auto operator|(i2c_oar2_r other) const -> i2c_oar2_r { return static_cast<i2c_oar2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar2_r> other) const -> opsy::utility::clear_set<i2c_oar2_r> {return opsy::utility::clear_set<i2c_oar2_r>(i2c_oar2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Own address 2 masks 
 */
class oa2msk_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr oa2msk_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_oar2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_oar2_r>() const {return opsy::utility::clear_set<i2c_oar2_r>(mask, *this);}
	constexpr auto operator|(i2c_oar2_r other) const -> i2c_oar2_r { return static_cast<i2c_oar2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar2_r> other) const -> opsy::utility::clear_set<i2c_oar2_r> {return opsy::utility::clear_set<i2c_oar2_r>(i2c_oar2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Own address 2 enable
 */
class oa2en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oa2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_oar2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_oar2_r>() const {return opsy::utility::clear_set<i2c_oar2_r>(mask, *this);}
	constexpr auto operator|(i2c_oar2_r other) const -> i2c_oar2_r { return static_cast<i2c_oar2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_oar2_r> other) const -> opsy::utility::clear_set<i2c_oar2_r> {return opsy::utility::clear_set<i2c_oar2_r>(i2c_oar2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto oa2() const -> oa2_f {return oa2_f(static_cast<uint8_t>(value_ >> oa2_f::offset));}
	[[nodiscard]] constexpr auto oa2msk() const -> oa2msk_f {return oa2msk_f(static_cast<uint8_t>(value_ >> oa2msk_f::offset));}
	[[nodiscard]] constexpr auto oa2en() const -> oa2en_f {return oa2en_f((value_ & oa2en_f::mask) != 0);}

	constexpr i2c_oar2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_oar2_r other) const -> i2c_oar2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_oar2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C timing register
 */
class i2c_timingr_r {
public:

/**
 * SCL low period (master mode) 
 */
class scll_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr scll_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_timingr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timingr_r>() const {return opsy::utility::clear_set<i2c_timingr_r>(mask, *this);}
	constexpr auto operator|(i2c_timingr_r other) const -> i2c_timingr_r { return static_cast<i2c_timingr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timingr_r> other) const -> opsy::utility::clear_set<i2c_timingr_r> {return opsy::utility::clear_set<i2c_timingr_r>(i2c_timingr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SCL high period (master mode) 
 */
class sclh_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sclh_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_timingr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timingr_r>() const {return opsy::utility::clear_set<i2c_timingr_r>(mask, *this);}
	constexpr auto operator|(i2c_timingr_r other) const -> i2c_timingr_r { return static_cast<i2c_timingr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timingr_r> other) const -> opsy::utility::clear_set<i2c_timingr_r> {return opsy::utility::clear_set<i2c_timingr_r>(i2c_timingr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data hold time 
 */
class sdadel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sdadel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_timingr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timingr_r>() const {return opsy::utility::clear_set<i2c_timingr_r>(mask, *this);}
	constexpr auto operator|(i2c_timingr_r other) const -> i2c_timingr_r { return static_cast<i2c_timingr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timingr_r> other) const -> opsy::utility::clear_set<i2c_timingr_r> {return opsy::utility::clear_set<i2c_timingr_r>(i2c_timingr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data setup time 
 */
class scldel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr scldel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_timingr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timingr_r>() const {return opsy::utility::clear_set<i2c_timingr_r>(mask, *this);}
	constexpr auto operator|(i2c_timingr_r other) const -> i2c_timingr_r { return static_cast<i2c_timingr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timingr_r> other) const -> opsy::utility::clear_set<i2c_timingr_r> {return opsy::utility::clear_set<i2c_timingr_r>(i2c_timingr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timing prescaler 
 */
class presc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr presc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_timingr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timingr_r>() const {return opsy::utility::clear_set<i2c_timingr_r>(mask, *this);}
	constexpr auto operator|(i2c_timingr_r other) const -> i2c_timingr_r { return static_cast<i2c_timingr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timingr_r> other) const -> opsy::utility::clear_set<i2c_timingr_r> {return opsy::utility::clear_set<i2c_timingr_r>(i2c_timingr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto scll() const -> scll_f {return scll_f(static_cast<uint8_t>(value_ >> scll_f::offset));}
	[[nodiscard]] constexpr auto sclh() const -> sclh_f {return sclh_f(static_cast<uint8_t>(value_ >> sclh_f::offset));}
	[[nodiscard]] constexpr auto sdadel() const -> sdadel_f {return sdadel_f(static_cast<uint8_t>(value_ >> sdadel_f::offset));}
	[[nodiscard]] constexpr auto scldel() const -> scldel_f {return scldel_f(static_cast<uint8_t>(value_ >> scldel_f::offset));}
	[[nodiscard]] constexpr auto presc() const -> presc_f {return presc_f(static_cast<uint8_t>(value_ >> presc_f::offset));}

	constexpr i2c_timingr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_timingr_r other) const -> i2c_timingr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_timingr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C timeout register
 */
class i2c_timeoutr_r {
public:

/**
 * Bus timeout A 
 */
class timeouta_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr timeouta_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i2c_timeoutr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timeoutr_r>() const {return opsy::utility::clear_set<i2c_timeoutr_r>(mask, *this);}
	constexpr auto operator|(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return static_cast<i2c_timeoutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timeoutr_r> other) const -> opsy::utility::clear_set<i2c_timeoutr_r> {return opsy::utility::clear_set<i2c_timeoutr_r>(i2c_timeoutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Idle clock timeout detection 
 */
class tidle_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tidle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_timeoutr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_timeoutr_r>() const {return opsy::utility::clear_set<i2c_timeoutr_r>(mask, *this);}
	constexpr auto operator|(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return static_cast<i2c_timeoutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timeoutr_r> other) const -> opsy::utility::clear_set<i2c_timeoutr_r> {return opsy::utility::clear_set<i2c_timeoutr_r>(i2c_timeoutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock timeout enable
 */
class timouten_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr timouten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_timeoutr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_timeoutr_r>() const {return opsy::utility::clear_set<i2c_timeoutr_r>(mask, *this);}
	constexpr auto operator|(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return static_cast<i2c_timeoutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timeoutr_r> other) const -> opsy::utility::clear_set<i2c_timeoutr_r> {return opsy::utility::clear_set<i2c_timeoutr_r>(i2c_timeoutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus timeout B 
 */
class timeoutb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr timeoutb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i2c_timeoutr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_timeoutr_r>() const {return opsy::utility::clear_set<i2c_timeoutr_r>(mask, *this);}
	constexpr auto operator|(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return static_cast<i2c_timeoutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timeoutr_r> other) const -> opsy::utility::clear_set<i2c_timeoutr_r> {return opsy::utility::clear_set<i2c_timeoutr_r>(i2c_timeoutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Extended clock timeout enable
 */
class texten_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr texten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_timeoutr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_timeoutr_r>() const {return opsy::utility::clear_set<i2c_timeoutr_r>(mask, *this);}
	constexpr auto operator|(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return static_cast<i2c_timeoutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_timeoutr_r> other) const -> opsy::utility::clear_set<i2c_timeoutr_r> {return opsy::utility::clear_set<i2c_timeoutr_r>(i2c_timeoutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto timeouta() const -> timeouta_f {return timeouta_f(static_cast<uint16_t>(value_ >> timeouta_f::offset));}
	[[nodiscard]] constexpr auto tidle() const -> tidle_f {return tidle_f((value_ & tidle_f::mask) != 0);}
	[[nodiscard]] constexpr auto timouten() const -> timouten_f {return timouten_f((value_ & timouten_f::mask) != 0);}
	[[nodiscard]] constexpr auto timeoutb() const -> timeoutb_f {return timeoutb_f(static_cast<uint16_t>(value_ >> timeoutb_f::offset));}
	[[nodiscard]] constexpr auto texten() const -> texten_f {return texten_f((value_ & texten_f::mask) != 0);}

	constexpr i2c_timeoutr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_timeoutr_r other) const -> i2c_timeoutr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_timeoutr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C interrupt and status register
 */
class i2c_isr_r {
public:

/**
 * Transmit data register empty (transmitters) 
 */
class txe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit interrupt status (transmitters) 
 */
class txis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data register not empty (receivers) 
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address matched (slave mode) 
 */
class addr_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Not acknowledge received flag 
 */
class nackf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nackf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Stop detection flag 
 */
class stopf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete (master mode) 
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete reload 
 */
class tcr_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus error 
 */
class berr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr berr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Arbitration lost 
 */
class arlo_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr arlo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun/underrun (slave mode) 
 */
class ovr_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PEC error in reception 
 */
class pecerr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pecerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout or tless thansub>LOWless than/sub> detection flag 
 */
class timeout_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr timeout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMBus alert 
 */
class alert_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alert_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus busy 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer direction (slave mode) 
 */
class dir_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address match code (slave mode) 
 */
class addcode_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr addcode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_isr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_isr_r>() const {return opsy::utility::clear_set<i2c_isr_r>(mask, *this);}
	constexpr auto operator|(i2c_isr_r other) const -> i2c_isr_r { return static_cast<i2c_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_isr_r> other) const -> opsy::utility::clear_set<i2c_isr_r> {return opsy::utility::clear_set<i2c_isr_r>(i2c_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto txe() const -> txe_f {return txe_f((value_ & txe_f::mask) != 0);}
	[[nodiscard]] constexpr auto txis() const -> txis_f {return txis_f((value_ & txis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxne() const -> rxne_f {return rxne_f((value_ & rxne_f::mask) != 0);}
	[[nodiscard]] constexpr auto addr() const -> addr_f {return addr_f((value_ & addr_f::mask) != 0);}
	[[nodiscard]] constexpr auto nackf() const -> nackf_f {return nackf_f((value_ & nackf_f::mask) != 0);}
	[[nodiscard]] constexpr auto stopf() const -> stopf_f {return stopf_f((value_ & stopf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcr() const -> tcr_f {return tcr_f((value_ & tcr_f::mask) != 0);}
	[[nodiscard]] constexpr auto berr() const -> berr_f {return berr_f((value_ & berr_f::mask) != 0);}
	[[nodiscard]] constexpr auto arlo() const -> arlo_f {return arlo_f((value_ & arlo_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr() const -> ovr_f {return ovr_f((value_ & ovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto pecerr() const -> pecerr_f {return pecerr_f((value_ & pecerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto timeout() const -> timeout_f {return timeout_f((value_ & timeout_f::mask) != 0);}
	[[nodiscard]] constexpr auto alert() const -> alert_f {return alert_f((value_ & alert_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto dir() const -> dir_f {return dir_f((value_ & dir_f::mask) != 0);}
	[[nodiscard]] constexpr auto addcode() const -> addcode_f {return addcode_f(static_cast<uint8_t>(value_ >> addcode_f::offset));}

	constexpr i2c_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_isr_r other) const -> i2c_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * I2C interrupt clear register
 */
class i2c_icr_r {
public:

/**
 * Address matched flag clear 
 */
class addrcf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Not acknowledge flag clear 
 */
class nackcf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nackcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STOP detection flag clear 
 */
class stopcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bus error flag clear 
 */
class berrcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr berrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Arbitration lost flag clear 
 */
class arlocf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr arlocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun/underrun flag clear 
 */
class ovrcf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PEC error flag clear 
 */
class peccf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout detection flag clear 
 */
class timoutcf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr timoutcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alert flag clear 
 */
class alertcf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alertcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i2c_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i2c_icr_r>() const {return opsy::utility::clear_set<i2c_icr_r>(mask, *this);}
	constexpr auto operator|(i2c_icr_r other) const -> i2c_icr_r { return static_cast<i2c_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_icr_r> other) const -> opsy::utility::clear_set<i2c_icr_r> {return opsy::utility::clear_set<i2c_icr_r>(i2c_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addrcf() const -> addrcf_f {return addrcf_f((value_ & addrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto nackcf() const -> nackcf_f {return nackcf_f((value_ & nackcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto stopcf() const -> stopcf_f {return stopcf_f((value_ & stopcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto berrcf() const -> berrcf_f {return berrcf_f((value_ & berrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arlocf() const -> arlocf_f {return arlocf_f((value_ & arlocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrcf() const -> ovrcf_f {return ovrcf_f((value_ & ovrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto peccf() const -> peccf_f {return peccf_f((value_ & peccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto timoutcf() const -> timoutcf_f {return timoutcf_f((value_ & timoutcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto alertcf() const -> alertcf_f {return alertcf_f((value_ & alertcf_f::mask) != 0);}

	constexpr i2c_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_icr_r other) const -> i2c_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C PEC register
 */
class i2c_pecr_r {
public:

/**
 * Packet error checking register 
 */
class pec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_pecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_pecr_r>() const {return opsy::utility::clear_set<i2c_pecr_r>(mask, *this);}
	constexpr auto operator|(i2c_pecr_r other) const -> i2c_pecr_r { return static_cast<i2c_pecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_pecr_r> other) const -> opsy::utility::clear_set<i2c_pecr_r> {return opsy::utility::clear_set<i2c_pecr_r>(i2c_pecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pec() const -> pec_f {return pec_f(static_cast<uint8_t>(value_ >> pec_f::offset));}

	constexpr i2c_pecr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_pecr_r other) const -> i2c_pecr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_pecr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C receive data register
 */
class i2c_rxdr_r {
public:

/**
 * 8-bit receive data 
 */
class rxdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxdata_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_rxdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_rxdr_r>() const {return opsy::utility::clear_set<i2c_rxdr_r>(mask, *this);}
	constexpr auto operator|(i2c_rxdr_r other) const -> i2c_rxdr_r { return static_cast<i2c_rxdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_rxdr_r> other) const -> opsy::utility::clear_set<i2c_rxdr_r> {return opsy::utility::clear_set<i2c_rxdr_r>(i2c_rxdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rxdata() const -> rxdata_f {return rxdata_f(static_cast<uint8_t>(value_ >> rxdata_f::offset));}

	constexpr i2c_rxdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_rxdr_r other) const -> i2c_rxdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_rxdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I2C transmit data register
 */
class i2c_txdr_r {
public:

/**
 * 8-bit transmit data 
 */
class txdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr txdata_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i2c_txdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i2c_txdr_r>() const {return opsy::utility::clear_set<i2c_txdr_r>(mask, *this);}
	constexpr auto operator|(i2c_txdr_r other) const -> i2c_txdr_r { return static_cast<i2c_txdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i2c_txdr_r> other) const -> opsy::utility::clear_set<i2c_txdr_r> {return opsy::utility::clear_set<i2c_txdr_r>(i2c_txdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto txdata() const -> txdata_f {return txdata_f(static_cast<uint8_t>(value_ >> txdata_f::offset));}

	constexpr i2c_txdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i2c_txdr_r other) const -> i2c_txdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i2c_txdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,i2c_cr1_r> i2c_cr1;
	opsy::utility::memory<uint32_t,i2c_cr2_r> i2c_cr2;
	opsy::utility::memory<uint32_t,i2c_oar1_r> i2c_oar1;
	opsy::utility::memory<uint32_t,i2c_oar2_r> i2c_oar2;
	opsy::utility::memory<uint32_t,i2c_timingr_r> i2c_timingr;
	opsy::utility::memory<uint32_t,i2c_timeoutr_r> i2c_timeoutr;
	opsy::utility::memory<uint32_t,i2c_isr_r> i2c_isr;
	opsy::utility::write_only_memory<uint32_t,i2c_icr_r> i2c_icr;
	opsy::utility::read_only_memory<uint32_t,i2c_pecr_r> i2c_pecr;
	opsy::utility::read_only_memory<uint32_t,i2c_rxdr_r> i2c_rxdr;
	opsy::utility::memory<uint32_t,i2c_txdr_r> i2c_txdr;
};

static_assert(std::is_standard_layout_v<i2c_p>);
static_assert(offsetof(i2c_p, i2c_cr1) == 0);
static_assert(offsetof(i2c_p, i2c_cr2) == 4);
static_assert(offsetof(i2c_p, i2c_oar1) == 8);
static_assert(offsetof(i2c_p, i2c_oar2) == 12);
static_assert(offsetof(i2c_p, i2c_timingr) == 16);
static_assert(offsetof(i2c_p, i2c_timeoutr) == 20);
static_assert(offsetof(i2c_p, i2c_isr) == 24);
static_assert(offsetof(i2c_p, i2c_icr) == 28);
static_assert(offsetof(i2c_p, i2c_pecr) == 32);
static_assert(offsetof(i2c_p, i2c_rxdr) == 36);
static_assert(offsetof(i2c_p, i2c_txdr) == 40);

inline i2c_p& i2c = *reinterpret_cast<i2c_p*>(0x40005400);
inline i2c_p& i2c_s = *reinterpret_cast<i2c_p*>(0x50005400);
inline i2c_p& i2c2 = *reinterpret_cast<i2c_p*>(0x40005800);
inline i2c_p& i2c2_s = *reinterpret_cast<i2c_p*>(0x50005800);
inline i2c_p& i2c3 = *reinterpret_cast<i2c_p*>(0x44002800);
inline i2c_p& i2c3_s = *reinterpret_cast<i2c_p*>(0x54002800);

} // STM32H523

