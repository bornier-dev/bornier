#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * USART address block description
 */
class usart_p {
public:

/**
 * USART control register 1
 */
class usart_cr1_r {
public:

/**
 * USART enable 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART enable in low-power mode 
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable 
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable 
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable 
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty interrupt enable 
 */
class rxfneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full interrupt enable 
 */
class txfnfie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable 
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection 
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable 
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up method 
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable 
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable 
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Oversampling mode 
 */
class over8_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr over8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time 
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time 
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver timeout interrupt enable 
 */
class rtoie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtoie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block interrupt enable 
 */
class eobie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eobie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable 
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO empty interrupt enable 
 */
class txfeie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full interrupt enable 
 */
class rxffie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxffie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_r>() const {return opsy::utility::clear_set<usart_cr1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_r other) const -> usart_cr1_r { return static_cast<usart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_r> other) const -> opsy::utility::clear_set<usart_cr1_r> {return opsy::utility::clear_set<usart_cr1_r>(usart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto uesm() const -> uesm_f {return uesm_f((value_ & uesm_f::mask) != 0);}
	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto te() const -> te_f {return te_f((value_ & te_f::mask) != 0);}
	[[nodiscard]] constexpr auto idleie() const -> idleie_f {return idleie_f((value_ & idleie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfneie() const -> rxfneie_f {return rxfneie_f((value_ & rxfneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnfie() const -> txfnfie_f {return txfnfie_f((value_ & txfnfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto peie() const -> peie_f {return peie_f((value_ & peie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps() const -> ps_f {return ps_f((value_ & ps_f::mask) != 0);}
	[[nodiscard]] constexpr auto pce() const -> pce_f {return pce_f((value_ & pce_f::mask) != 0);}
	[[nodiscard]] constexpr auto wake() const -> wake_f {return wake_f((value_ & wake_f::mask) != 0);}
	[[nodiscard]] constexpr auto m0() const -> m0_f {return m0_f((value_ & m0_f::mask) != 0);}
	[[nodiscard]] constexpr auto mme() const -> mme_f {return mme_f((value_ & mme_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmie() const -> cmie_f {return cmie_f((value_ & cmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto over8() const -> over8_f {return over8_f((value_ & over8_f::mask) != 0);}
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto rtoie() const -> rtoie_f {return rtoie_f((value_ & rtoie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eobie() const -> eobie_f {return eobie_f((value_ & eobie_f::mask) != 0);}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfeie() const -> txfeie_f {return txfeie_f((value_ & txfeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxffie() const -> rxffie_f {return rxffie_f((value_ & rxffie_f::mask) != 0);}

	constexpr usart_cr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr1_r other) const -> usart_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART control register 1
 */
class usart_cr1_alternate1_r {
public:

/**
 * USART enable 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART enable in low-power mode 
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable 
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable 
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable 
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data register not empty 
 */
class rxneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty 
 */
class txeie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable 
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection 
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable 
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up method 
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable 
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable 
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Oversampling mode 
 */
class over8_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr over8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time 
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time 
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver timeout interrupt enable 
 */
class rtoie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtoie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block interrupt enable 
 */
class eobie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eobie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable 
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_alternate1_r>() const {return opsy::utility::clear_set<usart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return static_cast<usart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr1_alternate1_r> {return opsy::utility::clear_set<usart_cr1_alternate1_r>(usart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto uesm() const -> uesm_f {return uesm_f((value_ & uesm_f::mask) != 0);}
	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto te() const -> te_f {return te_f((value_ & te_f::mask) != 0);}
	[[nodiscard]] constexpr auto idleie() const -> idleie_f {return idleie_f((value_ & idleie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxneie() const -> rxneie_f {return rxneie_f((value_ & rxneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txeie() const -> txeie_f {return txeie_f((value_ & txeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto peie() const -> peie_f {return peie_f((value_ & peie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps() const -> ps_f {return ps_f((value_ & ps_f::mask) != 0);}
	[[nodiscard]] constexpr auto pce() const -> pce_f {return pce_f((value_ & pce_f::mask) != 0);}
	[[nodiscard]] constexpr auto wake() const -> wake_f {return wake_f((value_ & wake_f::mask) != 0);}
	[[nodiscard]] constexpr auto m0() const -> m0_f {return m0_f((value_ & m0_f::mask) != 0);}
	[[nodiscard]] constexpr auto mme() const -> mme_f {return mme_f((value_ & mme_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmie() const -> cmie_f {return cmie_f((value_ & cmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto over8() const -> over8_f {return over8_f((value_ & over8_f::mask) != 0);}
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto rtoie() const -> rtoie_f {return rtoie_f((value_ & rtoie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eobie() const -> eobie_f {return eobie_f((value_ & eobie_f::mask) != 0);}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}

	constexpr usart_cr1_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr1_alternate1_r other) const -> usart_cr1_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr1_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART control register 2
 */
class usart_cr2_r {
public:

/**
 * Synchronous slave mode enable 
 */
class slven_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr slven_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * When the DIS_NSS bit is set, the NSS pin input is ignored.
 */
class dis_nss_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dis_nss_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 7-bit Address Detection/4-bit Address Detection 
 */
class addm7_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addm7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection length 
 */
class lbdl_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lbdl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection interrupt enable 
 */
class lbdie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lbdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Last bit clock pulse 
 */
class lbcl_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbcl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock phase 
 */
class cpha_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpha_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock polarity 
 */
class cpol_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock enable 
 */
class clken_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr clken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * stop bits 
 */
class stop_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr stop_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LIN mode enable 
 */
class linen_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr linen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Swap TX/RX pins 
 */
class swap_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX pin active level inversion 
 */
class rxinv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX pin active level inversion 
 */
class txinv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Binary data inversion 
 */
class datainv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr datainv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Most significant bit first 
 */
class msbfirst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr msbfirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate enable 
 */
class abren_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate mode 
 */
class abrmod_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr abrmod_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver timeout enable 
 */
class rtoen_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address of the USART node 
 */
class add_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr2_r>() const {return opsy::utility::clear_set<usart_cr2_r>(mask, *this);}
	constexpr auto operator|(usart_cr2_r other) const -> usart_cr2_r { return static_cast<usart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr2_r> other) const -> opsy::utility::clear_set<usart_cr2_r> {return opsy::utility::clear_set<usart_cr2_r>(usart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto slven() const -> slven_f {return slven_f((value_ & slven_f::mask) != 0);}
	[[nodiscard]] constexpr auto dis_nss() const -> dis_nss_f {return dis_nss_f((value_ & dis_nss_f::mask) != 0);}
	[[nodiscard]] constexpr auto addm7() const -> addm7_f {return addm7_f((value_ & addm7_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbdl() const -> lbdl_f {return lbdl_f((value_ & lbdl_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbdie() const -> lbdie_f {return lbdie_f((value_ & lbdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbcl() const -> lbcl_f {return lbcl_f((value_ & lbcl_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpha() const -> cpha_f {return cpha_f((value_ & cpha_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpol() const -> cpol_f {return cpol_f((value_ & cpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto clken() const -> clken_f {return clken_f((value_ & clken_f::mask) != 0);}
	[[nodiscard]] constexpr auto stop() const -> stop_f {return stop_f(static_cast<uint8_t>(value_ >> stop_f::offset));}
	[[nodiscard]] constexpr auto linen() const -> linen_f {return linen_f((value_ & linen_f::mask) != 0);}
	[[nodiscard]] constexpr auto swap() const -> swap_f {return swap_f((value_ & swap_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxinv() const -> rxinv_f {return rxinv_f((value_ & rxinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto txinv() const -> txinv_f {return txinv_f((value_ & txinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto datainv() const -> datainv_f {return datainv_f((value_ & datainv_f::mask) != 0);}
	[[nodiscard]] constexpr auto msbfirst() const -> msbfirst_f {return msbfirst_f((value_ & msbfirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto abren() const -> abren_f {return abren_f((value_ & abren_f::mask) != 0);}
	[[nodiscard]] constexpr auto abrmod() const -> abrmod_f {return abrmod_f(static_cast<uint8_t>(value_ >> abrmod_f::offset));}
	[[nodiscard]] constexpr auto rtoen() const -> rtoen_f {return rtoen_f((value_ & rtoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}

	constexpr usart_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr2_r other) const -> usart_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART control register 3
 */
class usart_cr3_r {
public:

/**
 * Error interrupt enable 
 */
class eie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IrDA mode enable 
 */
class iren_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr iren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IrDA low-power 
 */
class irlp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr irlp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex selection 
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard NACK enable 
 */
class nack_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard mode enable 
 */
class scen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr scen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable receiver 
 */
class dmar_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmar_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable transmitter 
 */
class dmat_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTS enable 
 */
class rtse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS enable 
 */
class ctse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt enable 
 */
class ctsie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * One sample bit method enable 
 */
class onebit_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr onebit_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun Disable 
 */
class ovrdis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Disable on reception Error 
 */
class ddre_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ddre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable mode 
 */
class dem_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dem_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable polarity selection 
 */
class dep_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard auto-retry count 
 */
class scarcnt_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr scarcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt enable 
 */
class wufie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold interrupt enable 
 */
class txftie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission Complete before guard time, interrupt enable 
 */
class tcbgtie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgtie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO threshold configuration 
 */
class rxftcfg_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RXFIFO threshold interrupt enable 
 */
class rxftie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold configuration 
 */
class txftcfg_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr3_r>() const {return opsy::utility::clear_set<usart_cr3_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_r other) const -> usart_cr3_r { return static_cast<usart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_r> other) const -> opsy::utility::clear_set<usart_cr3_r> {return opsy::utility::clear_set<usart_cr3_r>(usart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto eie() const -> eie_f {return eie_f((value_ & eie_f::mask) != 0);}
	[[nodiscard]] constexpr auto iren() const -> iren_f {return iren_f((value_ & iren_f::mask) != 0);}
	[[nodiscard]] constexpr auto irlp() const -> irlp_f {return irlp_f((value_ & irlp_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto nack() const -> nack_f {return nack_f((value_ & nack_f::mask) != 0);}
	[[nodiscard]] constexpr auto scen() const -> scen_f {return scen_f((value_ & scen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmar() const -> dmar_f {return dmar_f((value_ & dmar_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmat() const -> dmat_f {return dmat_f((value_ & dmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtse() const -> rtse_f {return rtse_f((value_ & rtse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctse() const -> ctse_f {return ctse_f((value_ & ctse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsie() const -> ctsie_f {return ctsie_f((value_ & ctsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto onebit() const -> onebit_f {return onebit_f((value_ & onebit_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrdis() const -> ovrdis_f {return ovrdis_f((value_ & ovrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddre() const -> ddre_f {return ddre_f((value_ & ddre_f::mask) != 0);}
	[[nodiscard]] constexpr auto dem() const -> dem_f {return dem_f((value_ & dem_f::mask) != 0);}
	[[nodiscard]] constexpr auto dep() const -> dep_f {return dep_f((value_ & dep_f::mask) != 0);}
	[[nodiscard]] constexpr auto scarcnt() const -> scarcnt_f {return scarcnt_f(static_cast<uint8_t>(value_ >> scarcnt_f::offset));}
	[[nodiscard]] constexpr auto wus0() const -> wus0_f {return wus0_f((value_ & wus0_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus1() const -> wus1_f {return wus1_f((value_ & wus1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wufie() const -> wufie_f {return wufie_f((value_ & wufie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftie() const -> txftie_f {return txftie_f((value_ & txftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcbgtie() const -> tcbgtie_f {return tcbgtie_f((value_ & tcbgtie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxftcfg() const -> rxftcfg_f {return rxftcfg_f(static_cast<uint8_t>(value_ >> rxftcfg_f::offset));}
	[[nodiscard]] constexpr auto rxftie() const -> rxftie_f {return rxftie_f((value_ & rxftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftcfg() const -> txftcfg_f {return txftcfg_f(static_cast<uint8_t>(value_ >> txftcfg_f::offset));}

	constexpr usart_cr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr3_r other) const -> usart_cr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART control register 3
 */
class usart_cr3_alternate1_r {
public:

/**
 * Error interrupt enable 
 */
class eie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IrDA mode enable 
 */
class iren_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr iren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IrDA low-power 
 */
class irlp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr irlp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex selection 
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard NACK enable 
 */
class nack_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard mode enable 
 */
class scen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr scen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable receiver 
 */
class dmar_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmar_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable transmitter 
 */
class dmat_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTS enable 
 */
class rtse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS enable 
 */
class ctse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt enable 
 */
class ctsie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * One sample bit method enable 
 */
class onebit_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr onebit_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun Disable 
 */
class ovrdis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Disable on reception Error 
 */
class ddre_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ddre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable mode 
 */
class dem_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dem_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable polarity selection 
 */
class dep_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Smartcard auto-retry count 
 */
class scarcnt_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr scarcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt enable 
 */
class wufie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission Complete before guard time, interrupt enable 
 */
class tcbgtie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgtie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr3_alternate1_r>() const {return opsy::utility::clear_set<usart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return static_cast<usart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<usart_cr3_alternate1_r> {return opsy::utility::clear_set<usart_cr3_alternate1_r>(usart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto eie() const -> eie_f {return eie_f((value_ & eie_f::mask) != 0);}
	[[nodiscard]] constexpr auto iren() const -> iren_f {return iren_f((value_ & iren_f::mask) != 0);}
	[[nodiscard]] constexpr auto irlp() const -> irlp_f {return irlp_f((value_ & irlp_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto nack() const -> nack_f {return nack_f((value_ & nack_f::mask) != 0);}
	[[nodiscard]] constexpr auto scen() const -> scen_f {return scen_f((value_ & scen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmar() const -> dmar_f {return dmar_f((value_ & dmar_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmat() const -> dmat_f {return dmat_f((value_ & dmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtse() const -> rtse_f {return rtse_f((value_ & rtse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctse() const -> ctse_f {return ctse_f((value_ & ctse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsie() const -> ctsie_f {return ctsie_f((value_ & ctsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto onebit() const -> onebit_f {return onebit_f((value_ & onebit_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrdis() const -> ovrdis_f {return ovrdis_f((value_ & ovrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddre() const -> ddre_f {return ddre_f((value_ & ddre_f::mask) != 0);}
	[[nodiscard]] constexpr auto dem() const -> dem_f {return dem_f((value_ & dem_f::mask) != 0);}
	[[nodiscard]] constexpr auto dep() const -> dep_f {return dep_f((value_ & dep_f::mask) != 0);}
	[[nodiscard]] constexpr auto scarcnt() const -> scarcnt_f {return scarcnt_f(static_cast<uint8_t>(value_ >> scarcnt_f::offset));}
	[[nodiscard]] constexpr auto wus0() const -> wus0_f {return wus0_f((value_ & wus0_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus1() const -> wus1_f {return wus1_f((value_ & wus1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wufie() const -> wufie_f {return wufie_f((value_ & wufie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcbgtie() const -> tcbgtie_f {return tcbgtie_f((value_ & tcbgtie_f::mask) != 0);}

	constexpr usart_cr3_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr3_alternate1_r other) const -> usart_cr3_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr3_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART baud rate register
 */
class usart_brr_r {
public:

/**
 * USART baud rate 
 */
class brr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr brr_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usart_brr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_brr_r>() const {return opsy::utility::clear_set<usart_brr_r>(mask, *this);}
	constexpr auto operator|(usart_brr_r other) const -> usart_brr_r { return static_cast<usart_brr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_brr_r> other) const -> opsy::utility::clear_set<usart_brr_r> {return opsy::utility::clear_set<usart_brr_r>(usart_brr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto brr() const -> brr_f {return brr_f(static_cast<uint16_t>(value_ >> brr_f::offset));}

	constexpr usart_brr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_brr_r other) const -> usart_brr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_brr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART guard time and prescaler register
 */
class usart_gtpr_r {
public:

/**
 * Prescaler value 
 */
class psc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr psc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_gtpr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_gtpr_r>() const {return opsy::utility::clear_set<usart_gtpr_r>(mask, *this);}
	constexpr auto operator|(usart_gtpr_r other) const -> usart_gtpr_r { return static_cast<usart_gtpr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_gtpr_r> other) const -> opsy::utility::clear_set<usart_gtpr_r> {return opsy::utility::clear_set<usart_gtpr_r>(usart_gtpr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Guard time value 
 */
class gt_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr gt_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_gtpr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_gtpr_r>() const {return opsy::utility::clear_set<usart_gtpr_r>(mask, *this);}
	constexpr auto operator|(usart_gtpr_r other) const -> usart_gtpr_r { return static_cast<usart_gtpr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_gtpr_r> other) const -> opsy::utility::clear_set<usart_gtpr_r> {return opsy::utility::clear_set<usart_gtpr_r>(usart_gtpr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto psc() const -> psc_f {return psc_f(static_cast<uint8_t>(value_ >> psc_f::offset));}
	[[nodiscard]] constexpr auto gt() const -> gt_f {return gt_f(static_cast<uint8_t>(value_ >> gt_f::offset));}

	constexpr usart_gtpr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_gtpr_r other) const -> usart_gtpr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_gtpr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART receiver timeout register
 */
class usart_rtor_r {
public:

/**
 * Receiver timeout value 
 */
class rto_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rto_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator usart_rtor_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_rtor_r>() const {return opsy::utility::clear_set<usart_rtor_r>(mask, *this);}
	constexpr auto operator|(usart_rtor_r other) const -> usart_rtor_r { return static_cast<usart_rtor_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rtor_r> other) const -> opsy::utility::clear_set<usart_rtor_r> {return opsy::utility::clear_set<usart_rtor_r>(usart_rtor_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Block Length 
 */
class blen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr blen_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_rtor_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_rtor_r>() const {return opsy::utility::clear_set<usart_rtor_r>(mask, *this);}
	constexpr auto operator|(usart_rtor_r other) const -> usart_rtor_r { return static_cast<usart_rtor_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rtor_r> other) const -> opsy::utility::clear_set<usart_rtor_r> {return opsy::utility::clear_set<usart_rtor_r>(usart_rtor_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rto() const -> rto_f {return rto_f(static_cast<uint32_t>(value_ >> rto_f::offset));}
	[[nodiscard]] constexpr auto blen() const -> blen_f {return blen_f(static_cast<uint8_t>(value_ >> blen_f::offset));}

	constexpr usart_rtor_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_rtor_r other) const -> usart_rtor_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_rtor_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART request register
 */
class usart_rqr_r {
public:

/**
 * Auto baud rate request 
 */
class abrrq_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr abrrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_rqr_r>() const {return opsy::utility::clear_set<usart_rqr_r>(mask, *this);}
	constexpr auto operator|(usart_rqr_r other) const -> usart_rqr_r { return static_cast<usart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rqr_r> other) const -> opsy::utility::clear_set<usart_rqr_r> {return opsy::utility::clear_set<usart_rqr_r>(usart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break request 
 */
class sbkrq_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbkrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_rqr_r>() const {return opsy::utility::clear_set<usart_rqr_r>(mask, *this);}
	constexpr auto operator|(usart_rqr_r other) const -> usart_rqr_r { return static_cast<usart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rqr_r> other) const -> opsy::utility::clear_set<usart_rqr_r> {return opsy::utility::clear_set<usart_rqr_r>(usart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode request 
 */
class mmrq_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mmrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_rqr_r>() const {return opsy::utility::clear_set<usart_rqr_r>(mask, *this);}
	constexpr auto operator|(usart_rqr_r other) const -> usart_rqr_r { return static_cast<usart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rqr_r> other) const -> opsy::utility::clear_set<usart_rqr_r> {return opsy::utility::clear_set<usart_rqr_r>(usart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data flush request 
 */
class rxfrq_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_rqr_r>() const {return opsy::utility::clear_set<usart_rqr_r>(mask, *this);}
	constexpr auto operator|(usart_rqr_r other) const -> usart_rqr_r { return static_cast<usart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rqr_r> other) const -> opsy::utility::clear_set<usart_rqr_r> {return opsy::utility::clear_set<usart_rqr_r>(usart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data flush request 
 */
class txfrq_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_rqr_r>() const {return opsy::utility::clear_set<usart_rqr_r>(mask, *this);}
	constexpr auto operator|(usart_rqr_r other) const -> usart_rqr_r { return static_cast<usart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rqr_r> other) const -> opsy::utility::clear_set<usart_rqr_r> {return opsy::utility::clear_set<usart_rqr_r>(usart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto abrrq() const -> abrrq_f {return abrrq_f((value_ & abrrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkrq() const -> sbkrq_f {return sbkrq_f((value_ & sbkrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmrq() const -> mmrq_f {return mmrq_f((value_ & mmrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfrq() const -> rxfrq_f {return rxfrq_f((value_ & rxfrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfrq() const -> txfrq_f {return txfrq_f((value_ & txfrq_f::mask) != 0);}

	constexpr usart_rqr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_rqr_r other) const -> usart_rqr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_rqr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART interrupt and status register
 */
class usart_isr_r {
public:

/**
 * Parity error 
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error 
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detection flag 
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error 
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected 
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty 
 */
class rxfne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete 
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full 
 */
class txfnf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection flag 
 */
class lbdf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag 
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag 
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver timeout 
 */
class rtof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block flag 
 */
class eobf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eobf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI slave underrun error flag 
 */
class udr_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate error 
 */
class abre_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate flag 
 */
class abrf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag 
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag 
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up from mute mode 
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode flag 
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag 
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag 
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO Empty 
 */
class txfe_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full 
 */
class rxff_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete before guard time flag 
 */
class tcbgt_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO threshold flag 
 */
class rxft_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold flag 
 */
class txft_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_r>() const {return opsy::utility::clear_set<usart_isr_r>(mask, *this);}
	constexpr auto operator|(usart_isr_r other) const -> usart_isr_r { return static_cast<usart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_r> other) const -> opsy::utility::clear_set<usart_isr_r> {return opsy::utility::clear_set<usart_isr_r>(usart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pe() const -> pe_f {return pe_f((value_ & pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto fe() const -> fe_f {return fe_f((value_ & fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ne() const -> ne_f {return ne_f((value_ & ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto ore() const -> ore_f {return ore_f((value_ & ore_f::mask) != 0);}
	[[nodiscard]] constexpr auto idle() const -> idle_f {return idle_f((value_ & idle_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfne() const -> rxfne_f {return rxfne_f((value_ & rxfne_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnf() const -> txfnf_f {return txfnf_f((value_ & txfnf_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbdf() const -> lbdf_f {return lbdf_f((value_ & lbdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtof() const -> rtof_f {return rtof_f((value_ & rtof_f::mask) != 0);}
	[[nodiscard]] constexpr auto eobf() const -> eobf_f {return eobf_f((value_ & eobf_f::mask) != 0);}
	[[nodiscard]] constexpr auto udr() const -> udr_f {return udr_f((value_ & udr_f::mask) != 0);}
	[[nodiscard]] constexpr auto abre() const -> abre_f {return abre_f((value_ & abre_f::mask) != 0);}
	[[nodiscard]] constexpr auto abrf() const -> abrf_f {return abrf_f((value_ & abrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfe() const -> txfe_f {return txfe_f((value_ & txfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxff() const -> rxff_f {return rxff_f((value_ & rxff_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcbgt() const -> tcbgt_f {return tcbgt_f((value_ & tcbgt_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxft() const -> rxft_f {return rxft_f((value_ & rxft_f::mask) != 0);}
	[[nodiscard]] constexpr auto txft() const -> txft_f {return txft_f((value_ & txft_f::mask) != 0);}

	constexpr usart_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_isr_r other) const -> usart_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000; // 192 0xC0

private:
	uint32_t value_;
};

/**
 * USART interrupt and status register
 */
class usart_isr_alternate1_r {
public:

/**
 * Parity error 
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error 
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detection flag 
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error 
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected 
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read data register not empty 
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete 
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty 
 */
class txe_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection flag 
 */
class lbdf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag 
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag 
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver timeout 
 */
class rtof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block flag 
 */
class eobf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eobf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI slave underrun error flag 
 */
class udr_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate error 
 */
class abre_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate flag 
 */
class abrf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag 
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag 
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up from mute mode 
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode flag 
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag 
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag 
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete before guard time flag 
 */
class tcbgt_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_alternate1_r>() const {return opsy::utility::clear_set<usart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return static_cast<usart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_alternate1_r> other) const -> opsy::utility::clear_set<usart_isr_alternate1_r> {return opsy::utility::clear_set<usart_isr_alternate1_r>(usart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pe() const -> pe_f {return pe_f((value_ & pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto fe() const -> fe_f {return fe_f((value_ & fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ne() const -> ne_f {return ne_f((value_ & ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto ore() const -> ore_f {return ore_f((value_ & ore_f::mask) != 0);}
	[[nodiscard]] constexpr auto idle() const -> idle_f {return idle_f((value_ & idle_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxne() const -> rxne_f {return rxne_f((value_ & rxne_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txe() const -> txe_f {return txe_f((value_ & txe_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbdf() const -> lbdf_f {return lbdf_f((value_ & lbdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtof() const -> rtof_f {return rtof_f((value_ & rtof_f::mask) != 0);}
	[[nodiscard]] constexpr auto eobf() const -> eobf_f {return eobf_f((value_ & eobf_f::mask) != 0);}
	[[nodiscard]] constexpr auto udr() const -> udr_f {return udr_f((value_ & udr_f::mask) != 0);}
	[[nodiscard]] constexpr auto abre() const -> abre_f {return abre_f((value_ & abre_f::mask) != 0);}
	[[nodiscard]] constexpr auto abrf() const -> abrf_f {return abrf_f((value_ & abrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcbgt() const -> tcbgt_f {return tcbgt_f((value_ & tcbgt_f::mask) != 0);}

	constexpr usart_isr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_isr_alternate1_r other) const -> usart_isr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_isr_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000; // 192 0xC0

private:
	uint32_t value_;
};

/**
 * USART interrupt flag clear register
 */
class usart_icr_r {
public:

/**
 * Parity error clear flag 
 */
class pecf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error clear flag 
 */
class fecf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detected clear flag 
 */
class necf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr necf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error clear flag 
 */
class orecf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr orecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected clear flag 
 */
class idlecf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idlecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO empty clear flag 
 */
class txfecf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete clear flag 
 */
class tccf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete before Guard time clear flag 
 */
class tcbgtcf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcbgtcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection clear flag 
 */
class lbdcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbdcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS clear flag 
 */
class ctscf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctscf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver timeout clear flag 
 */
class rtocf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block clear flag 
 */
class eobcf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eobcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI slave underrun clear flag 
 */
class udrcf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udrcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match clear flag 
 */
class cmcf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode clear flag 
 */
class wucf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wucf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_icr_r>() const {return opsy::utility::clear_set<usart_icr_r>(mask, *this);}
	constexpr auto operator|(usart_icr_r other) const -> usart_icr_r { return static_cast<usart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_icr_r> other) const -> opsy::utility::clear_set<usart_icr_r> {return opsy::utility::clear_set<usart_icr_r>(usart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pecf() const -> pecf_f {return pecf_f((value_ & pecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fecf() const -> fecf_f {return fecf_f((value_ & fecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto necf() const -> necf_f {return necf_f((value_ & necf_f::mask) != 0);}
	[[nodiscard]] constexpr auto orecf() const -> orecf_f {return orecf_f((value_ & orecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto idlecf() const -> idlecf_f {return idlecf_f((value_ & idlecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfecf() const -> txfecf_f {return txfecf_f((value_ & txfecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tccf() const -> tccf_f {return tccf_f((value_ & tccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcbgtcf() const -> tcbgtcf_f {return tcbgtcf_f((value_ & tcbgtcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto lbdcf() const -> lbdcf_f {return lbdcf_f((value_ & lbdcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctscf() const -> ctscf_f {return ctscf_f((value_ & ctscf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtocf() const -> rtocf_f {return rtocf_f((value_ & rtocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto eobcf() const -> eobcf_f {return eobcf_f((value_ & eobcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto udrcf() const -> udrcf_f {return udrcf_f((value_ & udrcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmcf() const -> cmcf_f {return cmcf_f((value_ & cmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wucf() const -> wucf_f {return wucf_f((value_ & wucf_f::mask) != 0);}

	constexpr usart_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_icr_r other) const -> usart_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART receive data register
 */
class usart_rdr_r {
public:

/**
 * Receive data value 
 */
class rdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usart_rdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_rdr_r>() const {return opsy::utility::clear_set<usart_rdr_r>(mask, *this);}
	constexpr auto operator|(usart_rdr_r other) const -> usart_rdr_r { return static_cast<usart_rdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_rdr_r> other) const -> opsy::utility::clear_set<usart_rdr_r> {return opsy::utility::clear_set<usart_rdr_r>(usart_rdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdr() const -> rdr_f {return rdr_f(static_cast<uint16_t>(value_ >> rdr_f::offset));}

	constexpr usart_rdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_rdr_r other) const -> usart_rdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_rdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART transmit data register
 */
class usart_tdr_r {
public:

/**
 * Transmit data value 
 */
class tdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usart_tdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_tdr_r>() const {return opsy::utility::clear_set<usart_tdr_r>(mask, *this);}
	constexpr auto operator|(usart_tdr_r other) const -> usart_tdr_r { return static_cast<usart_tdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_tdr_r> other) const -> opsy::utility::clear_set<usart_tdr_r> {return opsy::utility::clear_set<usart_tdr_r>(usart_tdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tdr() const -> tdr_f {return tdr_f(static_cast<uint16_t>(value_ >> tdr_f::offset));}

	constexpr usart_tdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_tdr_r other) const -> usart_tdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_tdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USART prescaler register
 */
class usart_presc_r {
public:

/**
 * Clock prescaler 
 */
class prescaler_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prescaler_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_presc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_presc_r>() const {return opsy::utility::clear_set<usart_presc_r>(mask, *this);}
	constexpr auto operator|(usart_presc_r other) const -> usart_presc_r { return static_cast<usart_presc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_presc_r> other) const -> opsy::utility::clear_set<usart_presc_r> {return opsy::utility::clear_set<usart_presc_r>(usart_presc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prescaler() const -> prescaler_f {return prescaler_f(static_cast<uint8_t>(value_ >> prescaler_f::offset));}

	constexpr usart_presc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_presc_r other) const -> usart_presc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_presc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,usart_cr1_r> usart_cr1;
		opsy::utility::memory<uint32_t,usart_cr1_alternate1_r> usart_cr1_alternate1;
	};
	opsy::utility::memory<uint32_t,usart_cr2_r> usart_cr2;
	union {
		opsy::utility::memory<uint32_t,usart_cr3_r> usart_cr3;
		opsy::utility::memory<uint32_t,usart_cr3_alternate1_r> usart_cr3_alternate1;
	};
	opsy::utility::memory<uint32_t,usart_brr_r> usart_brr;
	opsy::utility::memory<uint32_t,usart_gtpr_r> usart_gtpr;
	opsy::utility::memory<uint32_t,usart_rtor_r> usart_rtor;
	opsy::utility::write_only_memory<uint32_t,usart_rqr_r> usart_rqr;
	union {
		opsy::utility::read_only_memory<uint32_t,usart_isr_r> usart_isr;
		opsy::utility::read_only_memory<uint32_t,usart_isr_alternate1_r> usart_isr_alternate1;
	};
	opsy::utility::write_only_memory<uint32_t,usart_icr_r> usart_icr;
	opsy::utility::read_only_memory<uint32_t,usart_rdr_r> usart_rdr;
	opsy::utility::memory<uint32_t,usart_tdr_r> usart_tdr;
	opsy::utility::memory<uint32_t,usart_presc_r> usart_presc;
};

static_assert(std::is_standard_layout_v<usart_p>);
static_assert(offsetof(usart_p, usart_cr1) == 0);
static_assert(offsetof(usart_p, usart_cr1_alternate1) == 0);
static_assert(offsetof(usart_p, usart_cr2) == 4);
static_assert(offsetof(usart_p, usart_cr3) == 8);
static_assert(offsetof(usart_p, usart_cr3_alternate1) == 8);
static_assert(offsetof(usart_p, usart_brr) == 12);
static_assert(offsetof(usart_p, usart_gtpr) == 16);
static_assert(offsetof(usart_p, usart_rtor) == 20);
static_assert(offsetof(usart_p, usart_rqr) == 24);
static_assert(offsetof(usart_p, usart_isr) == 28);
static_assert(offsetof(usart_p, usart_isr_alternate1) == 28);
static_assert(offsetof(usart_p, usart_icr) == 32);
static_assert(offsetof(usart_p, usart_rdr) == 36);
static_assert(offsetof(usart_p, usart_tdr) == 40);
static_assert(offsetof(usart_p, usart_presc) == 44);

inline usart_p& uart4 = *reinterpret_cast<usart_p*>(0x40004C00);
inline usart_p& uart4_s = *reinterpret_cast<usart_p*>(0x50004C00);
inline usart_p& uart5 = *reinterpret_cast<usart_p*>(0x40005000);
inline usart_p& uart5_s = *reinterpret_cast<usart_p*>(0x50005000);
inline usart_p& usart = *reinterpret_cast<usart_p*>(0x40013800);
inline usart_p& usart_s = *reinterpret_cast<usart_p*>(0x50013800);
inline usart_p& usart2 = *reinterpret_cast<usart_p*>(0x40004400);
inline usart_p& usart2_s = *reinterpret_cast<usart_p*>(0x50004400);
inline usart_p& usart3 = *reinterpret_cast<usart_p*>(0x40004800);
inline usart_p& usart3_s = *reinterpret_cast<usart_p*>(0x50004800);
inline usart_p& usart6 = *reinterpret_cast<usart_p*>(0x40006400);
inline usart_p& usart6_s = *reinterpret_cast<usart_p*>(0x50006400);

} // STM32H523

