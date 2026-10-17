#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Universal synchronous asynchronous receiver transmitter
 */
class usart_p {
public:

/**
 * USART control register 1 [alternate] 
 */
class usart_cr1_enabled_r {
public:

/**
 * USART enable When this bit is cleared, the USART prescalers and outputs are stopped immediately, and all current operations are discarded. The USART configuration is kept, but all the USART_ISR status flags are reset. This bit is set and cleared by software. Note: To enter low-power mode without generating errors on the line, the TE bit must be previously reset and the software must wait for the TC bit in the USART_ISR to be set before resetting the UE bit. The DMA requests are also reset when UE = 0 so the DMA channel must be disabled before resetting the UE bit. In Smartcard mode, (SCEN = 1), the SCLK is always available when CLKEN = 1, regardless of the UE bit value.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART enable in low-power mode When this bit is cleared, the USART cannot wake up the MCU from low-power mode. When this bit is set, the USART can wake up the MCU from low-power mode. This bit is set and cleared by software. Note: It is recommended to set the UESM bit just before entering low-power mode, and clear it when exiting low-power mode.
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable This bit enables the receiver. It is set and cleared by software.
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable This bit enables the transmitter. It is set and cleared by software. Note: During transmission, a low pulse on the TE bit ('0' followed by '1') sends a preamble (idle line) after the current word, except in Smartcard mode. In order to generate an idle character, the TE must not be immediately written to '1'. To ensure the required duration, the software can poll the TEACK bit in the USART_ISR register. In Smartcard mode, when TE is set, there is a 1 bit-time delay before the transmission starts.
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable This bit is set and cleared by software.
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty interrupt enable This bit is set and cleared by software.
 */
class rxfneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable This bit is set and cleared by software.
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full interrupt enable This bit is set and cleared by software.
 */
class txfnfie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable This bit is set and cleared by software.
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity is selected after the current byte. This bitfield can only be written when the USART is disabled (UE=0).
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0) and the parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission). This bitfield can only be written when the USART is disabled (UE=0).
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup method This bit determines the USART wakeup method from Mute mode. It is set or cleared by software. This bitfield can only be written when the USART is disabled (UE=0).
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit is used in conjunction with bit 28 (M1) to determine the word length. It is set or cleared by software (refer to bit 28 (M1)description). This bit can only be written when the USART is disabled (UE=0).
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable This bit enables the USART Mute mode function. When set, the USART can switch between active and Mute mode, as defined by the WAKE bit. It is set and cleared by software.
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable This bit is set and cleared by software.
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Oversampling mode This bit can only be written when the USART is disabled (UE=0). Note: In LIN, IrDA and Smartcard modes, this bit must be kept cleared.
 */
class over8_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr over8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time This 5-bit value defines the time between the end of the last stop bit, in a transmitted message, and the de-activation of the DE (Driver Enable) signal. It is expressed in sample time units (1/8 or 1/16 bit time, depending on the oversampling rate). If the USART_TDR register is written during the DEDT time, the new data is transmitted only when the DEDT and DEAT times have both elapsed. This bitfield can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time This 5-bit value defines the time between the activation of the DE (Driver Enable) signal and the beginning of the start bit. It is expressed in sample time units (1/8 or 1/16 bit time, depending on the oversampling rate). This bitfield can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver timeout interrupt enable This bit is set and cleared by software. Note: If the USART does not support the Receiver timeout feature, this bit is reserved and must be kept at reset value. .
 */
class rtoie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtoie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of Block interrupt enable This bit is set and cleared by software. Note: If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
 */
class eobie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eobie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit must be used in conjunction with bit 12 (M0) to determine the word length. It is set or cleared by software. M[1:0] = '00': 1 start bit, 8 Data bits, n Stop bit M[1:0] = '01': 1 start bit, 9 Data bits, n Stop bit M[1:0] = '10': 1 start bit, 7 Data bits, n Stop bit This bit can only be written when the USART is disabled (UE=0). Note: In 7-bits data length mode, the Smartcard mode, LIN master mode and auto baud rate (0x7F and 0x55 frames detection) are not supported.
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable This bit is set and cleared by software. This bitfield can only be written when the USART is disabled (UE=0). Note: FIFO mode can be used on standard UART communication, in SPI Master/Slave mode and in Smartcard modes only. It must not be enabled in IrDA and LIN modes.
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO empty interrupt enable This bit is set and cleared by software.
 */
class txfeie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full interrupt enable This bit is set and cleared by software.
 */
class rxffie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxffie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_enabled_r>() const {return opsy::utility::clear_set<usart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return static_cast<usart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_enabled_r> other) const -> opsy::utility::clear_set<usart_cr1_enabled_r> {return opsy::utility::clear_set<usart_cr1_enabled_r>(usart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr usart_cr1_enabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr1_enabled_r other) const -> usart_cr1_enabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr1_enabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Control register 1
 */
class usart_cr1_disabled_r {
public:

/**
 * USART enable When this bit is cleared, the USART prescalers and outputs are stopped immediately, and all current operations are discarded. The USART configuration is kept, but all the USART_ISR status flags are reset. This bit is set and cleared by software. Note: To enter low-power mode without generating errors on the line, the TE bit must be previously reset and the software must wait for the TC bit in the USART_ISR to be set before resetting the UE bit. The DMA requests are also reset when UE = 0 so the DMA channel must be disabled before resetting the UE bit. In Smartcard mode, (SCEN = 1), the SCLK is always available when CLKEN = 1, regardless of the UE bit value.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USART enable in low-power mode When this bit is cleared, the USART cannot wake up the MCU from low-power mode. When this bit is set, the USART can wake up the MCU from low-power mode. This bit is set and cleared by software. Note: It is recommended to set the UESM bit just before entering low-power mode, and clear it when exiting low-power mode.
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable This bit enables the receiver. It is set and cleared by software.
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable This bit enables the transmitter. It is set and cleared by software. Note: During transmission, a low pulse on the TE bit ('0' followed by '1') sends a preamble (idle line) after the current word, except in Smartcard mode. In order to generate an idle character, the TE must not be immediately written to '1'. To ensure the required duration, the software can poll the TEACK bit in the USART_ISR register. In Smartcard mode, when TE is set, there is a 1 bit-time delay before the transmission starts.
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable This bit is set and cleared by software.
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data register not empty This bit is set and cleared by software.
 */
class rxneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable This bit is set and cleared by software.
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty This bit is set and cleared by software.
 */
class txeie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable This bit is set and cleared by software.
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity is selected after the current byte. This bitfield can only be written when the USART is disabled (UE=0).
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0) and the parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission). This bitfield can only be written when the USART is disabled (UE=0).
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup method This bit determines the USART wakeup method from Mute mode. It is set or cleared by software. This bitfield can only be written when the USART is disabled (UE=0).
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit is used in conjunction with bit 28 (M1) to determine the word length. It is set or cleared by software (refer to bit 28 (M1)description). This bit can only be written when the USART is disabled (UE=0).
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable This bit enables the USART Mute mode function. When set, the USART can switch between active and Mute mode, as defined by the WAKE bit. It is set and cleared by software.
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable This bit is set and cleared by software.
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Oversampling mode This bit can only be written when the USART is disabled (UE=0). Note: In LIN, IrDA and Smartcard modes, this bit must be kept cleared.
 */
class over8_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr over8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time This 5-bit value defines the time between the end of the last stop bit, in a transmitted message, and the de-activation of the DE (Driver Enable) signal. It is expressed in sample time units (1/8 or 1/16 bit time, depending on the oversampling rate). If the USART_TDR register is written during the DEDT time, the new data is transmitted only when the DEDT and DEAT times have both elapsed. This bitfield can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time This 5-bit value defines the time between the activation of the DE (Driver Enable) signal and the beginning of the start bit. It is expressed in sample time units (1/8 or 1/16 bit time, depending on the oversampling rate). This bitfield can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receiver timeout interrupt enable This bit is set and cleared by software. Note: If the USART does not support the Receiver timeout feature, this bit is reserved and must be kept at reset value. .
 */
class rtoie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rtoie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of Block interrupt enable This bit is set and cleared by software. Note: If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
 */
class eobie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eobie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit must be used in conjunction with bit 12 (M0) to determine the word length. It is set or cleared by software. M[1:0] = '00': 1 start bit, 8 Data bits, n Stop bit M[1:0] = '01': 1 start bit, 9 Data bits, n Stop bit M[1:0] = '10': 1 start bit, 7 Data bits, n Stop bit This bit can only be written when the USART is disabled (UE=0). Note: In 7-bits data length mode, the Smartcard mode, LIN master mode and auto baud rate (0x7F and 0x55 frames detection) are not supported.
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable This bit is set and cleared by software. This bitfield can only be written when the USART is disabled (UE=0). Note: FIFO mode can be used on standard UART communication, in SPI Master/Slave mode and in Smartcard modes only. It must not be enabled in IrDA and LIN modes.
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_cr1_disabled_r>() const {return opsy::utility::clear_set<usart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return static_cast<usart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_cr1_disabled_r> other) const -> opsy::utility::clear_set<usart_cr1_disabled_r> {return opsy::utility::clear_set<usart_cr1_disabled_r>(usart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr usart_cr1_disabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_cr1_disabled_r other) const -> usart_cr1_disabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_cr1_disabled_r { return ~value_; }
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
 * Synchronous Slave mode enable When the SLVEN bit is set, the Synchronous slave mode is enabled. Note: When SPI slave mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * When the DIS_NSS bit is set, the NSS pin input is ignored. Note: When SPI slave mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * 7-bit Address Detection/4-bit Address Detection This bit is for selection between 4-bit address detection or 7-bit address detection. This bit can only be written when the USART is disabled (UE=0) Note: In 7-bit and 9-bit data modes, the address detection is done on 6-bit and 8-bit address (ADD[5:0] and ADD[7:0]) respectively.
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
 * LIN break detection length This bit is for selection between 11 bit or 10 bit break detection. This bit can only be written when the USART is disabled (UE=0). Note: If LIN mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * LIN break detection interrupt enable Break interrupt mask (break detection using break delimiter). Note: If LIN mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Last bit clock pulse This bit is used to select whether the clock pulse associated with the last data bit transmitted (MSB) has to be output on the SCLK pin in Synchronous mode. The last bit is the 7th or 8th or 9th data bit transmitted depending on the 7 or 8 or 9 bit format selected by the M bit in the USART_CR1 register. This bit can only be written when the USART is disabled (UE=0). Note: If Synchronous mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Clock phase This bit is used to select the phase of the clock output on the SCLK pin in Synchronous mode. It works in conjunction with the CPOL bit to produce the desired clock/data relationship (see and ) This bit can only be written when the USART is disabled (UE=0). Note: If Synchronous mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Clock polarity This bit enables the user to select the polarity of the clock output on the SCLK pin in Synchronous mode. It works in conjunction with the CPHA bit to produce the desired clock/data relationship This bit can only be written when the USART is disabled (UE=0). Note: If Synchronous mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Clock enable This bit enables the user to enable the SCLK pin. This bit can only be written when the USART is disabled (UE=0). Note: If neither Synchronous mode nor Smartcard mode is supported, this bit is reserved and must be kept at reset value. Refer to . In Smartcard mode, in order to provide correctly the SCLK clock to the smartcard, the steps below must be respected: UE = 0 SCEN = 1 GTPR configuration CLKEN= 1 UE = 1
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
 * stop bits These bits are used for programming the stop bits. This bitfield can only be written when the USART is disabled (UE=0).
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
 * LIN mode enable This bit is set and cleared by software. The LIN mode enables the capability to send LIN synchronous breaks (13 low bits) using the SBKRQ bit in the USART_CR1 register, and to detect LIN Sync breaks. This bitfield can only be written when the USART is disabled (UE=0). Note: If the USART does not support LIN mode, this bit is reserved and must be kept at reset value. Refer to .
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
 * Swap TX/RX pins This bit is set and cleared by software. This bitfield can only be written when the USART is disabled (UE=0).
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
 * RX pin active level inversion This bit is set and cleared by software. This enables the use of an external inverter on the RX line. This bitfield can only be written when the USART is disabled (UE=0).
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
 * TX pin active level inversion This bit is set and cleared by software. This enables the use of an external inverter on the TX line. This bitfield can only be written when the USART is disabled (UE=0).
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
 * Binary data inversion This bit is set and cleared by software. This bitfield can only be written when the USART is disabled (UE=0).
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
 * Most significant bit first This bit is set and cleared by software. This bitfield can only be written when the USART is disabled (UE=0).
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
 * Auto baud rate enable This bit is set and cleared by software. Note: If the USART does not support the auto baud rate feature, this bit is reserved and must be kept at reset value. Refer to .
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
 * Auto baud rate mode These bits are set and cleared by software. This bitfield can only be written when ABREN = 0 or the USART is disabled (UE=0). Note: If DATAINV=1 and/or MSBFIRST=1 the patterns must be the same on the line, for example 0xAA for MSBFIRST) If the USART does not support the auto baud rate feature, this bit is reserved and must be kept at reset value. Refer to .
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
 * Receiver timeout enable This bit is set and cleared by software. When this feature is enabled, the RTOF flag in the USART_ISR register is set if the RX line is idle (no reception) for the duration programmed in the RTOR (receiver timeout register). Note: If the USART does not support the Receiver timeout feature, this bit is reserved and must be kept at reset value. Refer to .
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
 * Address of the USART node These bits give the address of the USART node in Mute mode or a character code to be recognized in low-power or Run mode: In Mute mode: they are used in multiprocessor communication to wakeup from Mute mode with 4-bit/7-bit address mark detection. The MSB of the character sent by the transmitter should be equal to 1. In 4-bit address mark detection, only ADD[3:0] bits are used. In low-power mode: they are used for wake up from low-power mode on character match. When WUS[1:0] is programmed to 0b00 (WUF active on address match), the wakeup from low-power mode is performed when the received character corresponds to the character programmed through ADD[6:0] or ADD[3:0] bitfield (depending on ADDM7 bit), and WUF interrupt is enabled by setting WUFIE bit. The MSB of the character sent by transmitter should be equal to 1. In Run mode with Mute mode inactive (for example, end-of-block detection in ModBus protocol): the whole received character (8 bits) is compared to ADD[7:0] value and CMF flag is set on match. An interrupt is generated if the CMIE bit is set. These bits can only be written when the reception is disabled (RE = 0) or when the USART is disabled (UE = 0).
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
 * Error interrupt enable Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error noise flag or SPI slave underrun error (FE=1 or ORE=1 or NE=1or UDR = 1 in the USART_ISR register).
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
 * IrDA mode enable This bit is set and cleared by software. This bit can only be written when the USART is disabled (UE=0). Note: If IrDA mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * IrDA low-power This bit is used for selecting between normal and low-power IrDA modes This bit can only be written when the USART is disabled (UE=0). Note: If IrDA mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Half-duplex selection Selection of Single-wire Half-duplex mode This bit can only be written when the USART is disabled (UE=0).
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
 * Smartcard NACK enable This bitfield can only be written when the USART is disabled (UE=0). Note: If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
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
 * Smartcard mode enable This bit is used for enabling Smartcard mode. This bitfield can only be written when the USART is disabled (UE=0). Note: If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
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
 * DMA enable receiver This bit is set/reset by software
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
 * DMA enable transmitter This bit is set/reset by software
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
 * RTS enable This bit can only be written when the USART is disabled (UE=0). Note: If the hardware flow control feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * CTS enable This bit can only be written when the USART is disabled (UE=0) Note: If the hardware flow control feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * CTS interrupt enable Note: If the hardware flow control feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * One sample bit method enable This bit enables the user to select the sample method. When the one sample bit method is selected the noise detection flag (NE) is disabled. This bit can only be written when the USART is disabled (UE=0).
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
 * Overrun Disable This bit is used to disable the receive overrun detection. the ORE flag is not set and the new received data overwrites the previous content of the USART_RDR register. When FIFO mode is enabled, the RXFIFO is bypassed and data are written directly in USART_RDR register. Even when FIFO management is enabled, the RXNE flag is to be used. This bit can only be written when the USART is disabled (UE=0). Note: This control bit enables checking the communication flow w/o reading the data
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
 * DMA Disable on Reception Error This bit can only be written when the USART is disabled (UE=0). Note: The reception errors are: parity error, framing error or noise error.
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
 * Driver enable mode This bit enables the user to activate the external transceiver control, through the DE signal. This bit can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. .
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
 * Driver enable polarity selection This bit can only be written when the USART is disabled (UE=0). Note: If the Driver Enable feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Smartcard auto-retry count This bitfield specifies the number of retries for transmission and reception in Smartcard mode. In Transmission mode, it specifies the number of automatic retransmission retries, before generating a transmission error (FE bit set). In Reception mode, it specifies the number or erroneous reception trials, before generating a reception error (RXNE/RXFNE and PE bits set). This bitfield must be programmed only when the USART is disabled (UE=0). When the USART is enabled (UE=1), this bitfield may only be written to 0x0, in order to stop retransmission. Note: If Smartcard mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Wakeup from low-power mode interrupt flag selection This bitfield specifies the event which activates the WUF (Wakeup from low-power mode flag). This bitfield can only be written when the USART is disabled (UE=0). Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2297.
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
 * Wakeup from low-power mode interrupt flag selection This bitfield specifies the event which activates the WUF (Wakeup from low-power mode flag). This bitfield can only be written when the USART is disabled (UE=0). Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2297.
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
 * Wakeup from low-power mode interrupt enable This bit is set and cleared by software. Note: WUFIE must be set before entering in low-power mode. If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2297.
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
 * TXFIFO threshold interrupt enable This bit is set and cleared by software.
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
 * Transmission Complete before guard time, interrupt enable This bit is set and cleared by software. Note: If the USART does not support the Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
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
 * Receive FIFO threshold configuration Remaining combinations: Reserved
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
 * RXFIFO threshold interrupt enable This bit is set and cleared by software.
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
 * TXFIFO threshold configuration Remaining combinations: Reserved
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
 * USART baud rate register 
 */
class usart_brr_r {
public:

/**
 * USART baud rate BRR[15:4] BRR[15:4] correspond to USARTDIV[15:4] BRR[3:0] When OVER8 = 0, BRR[3:0] = USARTDIV[3:0]. When OVER8 = 1: BRR[2:0] = USARTDIV[3:0] shifted 1 bit to the right. BRR[3] must be kept cleared.
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
 * Prescaler value PSC[7:0] = IrDA Normal and Low-power baud rate This bitfield is used for programming the prescaler for dividing the USART source clock to achieve the low-power frequency: The source clock is divided by the value given in the register (8 significant bits): ... PSC[4:0]: Prescaler value This bitfield is used for programming the prescaler for dividing the USART source clock to provide the Smartcard clock. The value given in the register (5 significant bits) is multiplied by 2 to give the division factor of the source clock frequency: ... This bitfield can only be written when the USART is disabled (UE=0). Note: Bits [7:5] must be kept cleared if Smartcard mode is used. This bitfield is reserved and forced by hardware to '0' when the Smartcard and IrDA modes are not supported. Refer to .
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
 * Guard time value This bitfield is used to program the Guard time value in terms of number of baud clock periods. This is used in Smartcard mode. The Transmission Complete flag is set after this guard time value. This bitfield can only be written when the USART is disabled (UE=0). Note: If Smartcard mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Receiver timeout value This bitfield gives the Receiver timeout value in terms of number of bit duration. In Standard mode, the RTOF flag is set if, after the last received character, no new start bit is detected for more than the RTO value. In Smartcard mode, this value is used to implement the CWT and BWT. See Smartcard chapter for more details. In the standard, the CWT/BWT measurement is done starting from the start bit of the last received character. Note: This value must only be programmed once per received character.
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
 * Block Length This bitfield gives the Block length in Smartcard T=1 Reception. Its value equals the number of information characters + the length of the Epilogue Field (1-LEC/2-CRC)1. Examples: BLEN = 0 0 information characters + LEC BLEN = 1 0 information characters + CRC BLEN = 255 254 information characters + CRC (total 256 characters)) In Smartcard mode, the Block length counter is reset when TXE=0 (TXFE = 0 in case FIFO mode is enabled). This bitfield can be used also in other modes. In this case, the Block length counter is reset when RE=0 (receiver disabled) and/or when the EOBCF bit is written to 1. Note: This value can be programmed after the start of the block reception (using the data from the LEN character in the Prologue Field). It must be programmed only once per received block.
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
 * auto baud rate request Writing 1 to this bit resets the ABRF and ABRE flags in the USART_ISR and requests an automatic baud rate measurement on the next received data frame. Note: If the USART does not support the auto baud rate feature, this bit is reserved and must be kept at reset value. Refer to .
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
 * Send break request Writing 1 to this bit sets the SBKF flag and request to send a BREAK on the line, as soon as the transmit machine is available. Note: When the application needs to send the break character following all previously inserted data, including the ones not yet transmitted, the software should wait for the TXE flag assertion before setting the SBKRQ bit.
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
 * Mute mode request Writing 1 to this bit puts the USART in Mute mode and resets the RWU flag.
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
 * Receive data flush request Writing 1 to this bit empties the entire receive FIFO i.e. clears the bit RXFNE. This enables to discard the received data without reading them, and avoid an overrun condition.
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
 * Transmit data flush request When FIFO mode is disabled, writing '1' to this bit sets the TXE flag. This enables to discard the transmit data. This bit must be used only in Smartcard mode, when data have not been sent due to errors (NACK) and the FE flag is active in the USART_ISR register. If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. When FIFO is enabled, TXFRQ bit is set to flush the whole FIFO. This sets the TXFE flag (Transmit FIFO empty, bit 23 in the USART_ISR register). Flushing the Transmit FIFO is supported in both UART and Smartcard modes. Note: In FIFO mode, the TXFNF flag is reset during the flush request until TxFIFO is empty in order to ensure that no data are written in the data register.
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
class usart_isr_enabled_r {
public:

/**
 * Parity error This bit is set by hardware when a parity error occurs in Reception mode. It is cleared by software, writing 1 to the PECF in the USART_ICR register. An interrupt is generated if PEIE = 1 in the USART_CR1 register. Note: This error is associated with the character in the USART_RDR.
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error This bit is set by hardware when a de-synchronization, excessive noise or a break character is detected. It is cleared by software, writing 1 to the FECF bit in the USART_ICR register. When transmitting data in Smartcard mode, this bit is set when the maximum number of transmit attempts is reached without success (the card NACKs the data frame). An interrupt is generated if EIE = 1 in the USART_CR1 register. Note: This error is associated with the character in the USART_RDR.
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detection flag This bit is set by hardware when noise is detected on a received frame. It is cleared by software, writing 1 to the NFCF bit in the USART_ICR register. Note: This bit does not generate an interrupt as it appears at the same time as the RXFNE bit which itself generates an interrupt. An interrupt is generated when the NE flag is set during multi buffer communication if the EIE bit is set. When the line is noise-free, the NE flag can be disabled by programming the ONEBIT bit to 1 to increase the USART tolerance to deviations (Refer to Tolerance of the USART receiver to clock deviation on page 2317). This error is associated with the character in the USART_RDR.
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error This bit is set by hardware when the data currently being received in the shift register is ready to be transferred into the USART_RDR register while RXFF = 1. It is cleared by a software, writing 1 to the ORECF, in the USART_ICR register. An interrupt is generated if RXFNEIE=1 or EIE = 1 in the USART_CR1 register. Note: When this bit is set, the USART_RDR register content is not lost but the shift register is overwritten. An interrupt is generated if the ORE flag is set during multi buffer communication if the EIE bit is set. This bit is permanently forced to 0 (no overrun detection) when the bit OVRDIS is set in the USART_CR3 register.
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected This bit is set by hardware when an Idle Line is detected. An interrupt is generated if IDLEIE=1 in the USART_CR1 register. It is cleared by software, writing 1 to the IDLECF in the USART_ICR register. Note: The IDLE bit is not set again until the RXFNE bit has been set (i.e. a new idle line occurs). If Mute mode is enabled (MME=1), IDLE is set if the USART is not mute (RWU=0), whatever the Mute mode selected by the WAKE bit. If RWU=1, IDLE is not set.
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty RXFNE bit is set by hardware when the RXFIFO is not empty, meaning that data can be read from the USART_RDR register. Every read operation from the USART_RDR frees a location in the RXFIFO. RXFNE is cleared when the RXFIFO is empty. The RXFNE flag can also be cleared by writing 1 to the RXFRQ in the USART_RQR register. An interrupt is generated if RXFNEIE=1 in the USART_CR1 register.
 */
class rxfne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete This bit indicates that the last data written in the USART_TDR has been transmitted out of the shift register. The TC flag behaves as follows: When TDN = 0, the TC flag is set when the transmission of a frame containing data is complete and when TXE/TXFE is set. When TDN is equal to the number of data in the TXFIFO, the TC flag is set when TXFIFO is empty and TDN is reached. When TDN is greater than the number of data in the TXFIFO, TC remains cleared until the TXFIFO is filled again to reach the programmed number of data to be transferred. When TDN is less than the number of data in the TXFIFO, TC is set when TDN is reached even if the TXFIFO is not empty. An interrupt is generated if TCIE=1 in the USART_CR1 register. TC bit is cleared by software by writing 1 to the TCCF in the USART_ICR register or by writing to the USART_TDR register.
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full TXFNF is set by hardware when TXFIFO is not full meaning that data can be written in the USART_TDR. Every write operation to the USART_TDR places the data in the TXFIFO. This flag remains set until the TXFIFO is full. When the TXFIFO is full, this flag is cleared indicating that data can not be written into the USART_TDR. An interrupt is generated if the TXFNFIE bit =1 in the USART_CR1 register. Note: The TXFNF is kept reset during the flush request until TXFIFO is empty. After sending the flush request (by setting TXFRQ bit), the flag TXFNF should be checked prior to writing in TXFIFO (TXFNF and TXFE is set at the same time). This bit is used during single buffer transmission.
 */
class txfnf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection flag This bit is set by hardware when the LIN break is detected. It is cleared by software, by writing 1 to the LBDCF in the USART_ICR. An interrupt is generated if LBDIE = 1 in the USART_CR2 register. Note: If the USART does not support LIN mode, this bit is reserved and kept at reset value. Refer to .
 */
class lbdf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag This bit is set by hardware when the nCTS input toggles, if the CTSE bit is set. It is cleared by software, by writing 1 to the CTSCF bit in the USART_ICR register. An interrupt is generated if CTSIE=1 in the USART_CR3 register. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag This bit is set/reset by hardware. It is an inverted copy of the status of the nCTS input pin. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver timeout This bit is set by hardware when the timeout value, programmed in the RTOR register has lapsed, without any communication. It is cleared by software, writing 1 to the RTOCF bit in the USART_ICR register. An interrupt is generated if RTOIE=1 in the USART_CR2 register. In Smartcard mode, the timeout corresponds to the CWT or BWT timings. Note: If a time equal to the value programmed in RTOR register separates 2 characters, RTOF is not set. If this time exceeds this value + 2 sample times (2/16 or 2/8, depending on the oversampling method), RTOF flag is set. The counter counts even if RE = 0 but RTOF is set only when RE = 1. If the timeout has already elapsed when RE is set, then RTOF is set. If the USART does not support the Receiver timeout feature, this bit is reserved and kept at reset value.
 */
class rtof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block flag This bit is set by hardware when a complete block has been received (for example T=1 Smartcard mode). The detection is done when the number of received bytes (from the start of the block, including the prologue) is equal or greater than BLEN + 4. An interrupt is generated if EOBIE = 1 in the USART_CR1 register. It is cleared by software, writing 1 to EOBCF in the USART_ICR register. Note: If Smartcard mode is not supported, this bit is reserved and kept at reset value. Refer to .
 */
class eobf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eobf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI slave underrun error flag In Slave transmission mode, this flag is set when the first clock pulse for data transmission appears while the software has not yet loaded any value into USART_TDR. This flag is reset by setting UDRCF bit in the USART_ICR register. Note: If the USART does not support the SPI slave mode, this bit is reserved and kept at reset value. Refer to .
 */
class udr_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate error This bit is set by hardware if the baud rate measurement failed (baud rate out of range or character comparison failed) It is cleared by software, by writing 1 to the ABRRQ bit in the USART_RQR register. Note: If the USART does not support the auto baud rate feature, this bit is reserved and kept at reset value.
 */
class abre_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate flag This bit is set by hardware when the automatic baud rate has been set (RXFNE is also set, generating an interrupt if RXFNEIE = 1) or when the auto baud rate operation was completed without success (ABRE=1) (ABRE, RXFNE and FE are also set in this case) It is cleared by software, in order to request a new auto baud rate detection, by writing 1 to the ABRRQ in the USART_RQR register. Note: If the USART does not support the auto baud rate feature, this bit is reserved and kept at reset value.
 */
class abrf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag This bit is set and reset by hardware. It is active when a communication is ongoing on the RX line (successful start bit detected). It is reset at the end of the reception (successful or not).
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag This bit is set by hardware, when a the character defined by ADD[7:0] is received. It is cleared by software, writing 1 to the CMCF in the USART_ICR register. An interrupt is generated if CMIE=1in the USART_CR1 register.
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag This bit indicates that a send break character was requested. It is set by software, by writing 1 to the SBKRQ bit in the USART_CR3 register. It is automatically reset by hardware during the stop bit of break transmission.
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup from Mute mode This bit indicates if the USART is in Mute mode. It is cleared/set by hardware when a wakeup/mute sequence is recognized. The Mute mode control sequence (address or IDLE) is selected by the WAKE bit in the USART_CR1 register. When wakeup on IDLE mode is selected, this bit can only be set by software, writing 1 to the MMRQ bit in the USART_RQR register. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode flag This bit is set by hardware, when a wakeup event is detected. The event is defined by the WUS bitfield. It is cleared by software, writing a 1 to the WUCF in the USART_ICR register. An interrupt is generated if WUFIE=1 in the USART_CR3 register. Note: When UESM is cleared, WUF flag is also cleared. If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag This bit is set/reset by hardware, when the Transmit Enable value is taken into account by the USART. It can be used when an idle frame request is generated by writing TE=0, followed by TE=1 in the USART_CR1 register, in order to respect the TE=0 minimum period.
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag This bit is set/reset by hardware, when the Receive Enable value is taken into account by the USART. It can be used to verify that the USART is ready for reception before entering low-power mode. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO Empty This bit is set by hardware when TXFIFO is Empty. When the TXFIFO contains at least one data, this flag is cleared. The TXFE flag can also be set by writing 1 to the bit TXFRQ (bit 4) in the USART_RQR register. An interrupt is generated if the TXFEIE bit =1 (bit 30) in the USART_CR1 register.
 */
class txfe_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full This bit is set by hardware when the number of received data corresponds to RXFIFO size + 1 (RXFIFO full + 1 data in the USART_RDR register. An interrupt is generated if the RXFFIE bit =1 in the USART_CR1 register.
 */
class rxff_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete before guard time flag This bit is set when the last data written in the USART_TDR has been transmitted correctly out of the shift register. It is set by hardware in Smartcard mode, if the transmission of a frame containing data is complete and if the smartcard did not send back any NACK. An interrupt is generated if TCBGTIE=1 in the USART_CR3 register. This bit is cleared by software, by writing 1 to the TCBGTCF in the USART_ICR register or by a write to the USART_TDR register. Note: If the USART does not support the Smartcard mode, this bit is reserved and kept at reset value. If the USART supports the Smartcard mode and the Smartcard mode is enabled, the TCBGT reset value is '1'. Refer to on page 2297.
 */
class tcbgt_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO threshold flag This bit is set by hardware when the threshold programmed in RXFTCFG in USART_CR3 register is reached. This means that there are (RXFTCFG1) data in the Receive FIFO and one data in the USART_RDR register. An interrupt is generated if the RXFTIE bit =1 (bit 27) in the USART_CR3 register. Note: When the RXFTCFG threshold is configured to '101', RXFT flag is set if 16 data are available i.e. 15 data in the RXFIFO and 1 data in the USART_RDR. Consequently, the 17th received data does not cause an overrun error. The overrun error occurs after receiving the 18th data.
 */
class rxft_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold flag This bit is set by hardware when the TXFIFO reaches the threshold programmed in TXFTCFG of USART_CR3 register i.e. the TXFIFO contains TXFTCFG empty locations. An interrupt is generated if the TXFTIE bit =1 (bit 31) in the USART_CR3 register.
 */
class txft_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_enabled_r>() const {return opsy::utility::clear_set<usart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return static_cast<usart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_enabled_r> other) const -> opsy::utility::clear_set<usart_isr_enabled_r> {return opsy::utility::clear_set<usart_isr_enabled_r>(usart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr usart_isr_enabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_isr_enabled_r other) const -> usart_isr_enabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_isr_enabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000; // 192 0xC0

private:
	uint32_t value_;
};

/**
 * Interrupt and status register
 */
class usart_isr_disabled_r {
public:

/**
 * Parity error This bit is set by hardware when a parity error occurs in Reception mode. It is cleared by software, writing 1 to the PECF in the USART_ICR register. An interrupt is generated if PEIE = 1 in the USART_CR1 register. Note: This error is associated with the character in the USART_RDR.
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error This bit is set by hardware when a de-synchronization, excessive noise or a break character is detected. It is cleared by software, writing 1 to the FECF bit in the USART_ICR register. When transmitting data in Smartcard mode, this bit is set when the maximum number of transmit attempts is reached without success (the card NACKs the data frame). An interrupt is generated if EIE = 1 in the USART_CR1 register. Note: This error is associated with the character in the USART_RDR.
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detection flag This bit is set by hardware when noise is detected on a received frame. It is cleared by software, writing 1 to the NFCF bit in the USART_ICR register. Note: This bit does not generate an interrupt as it appears at the same time as the RXNE bit which itself generates an interrupt. An interrupt is generated when the NE flag is set during multi buffer communication if the EIE bit is set. When the line is noise-free, the NE flag can be disabled by programming the ONEBIT bit to 1 to increase the USART tolerance to deviations (Refer to Tolerance of the USART receiver to clock deviation on page 2317). This error is associated with the character in the USART_RDR.
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error This bit is set by hardware when the data currently being received in the shift register is ready to be transferred into the USART_RDR register while RXNE=1. It is cleared by a software, writing 1 to the ORECF, in the USART_ICR register. An interrupt is generated if RXNEIE=1 or EIE = 1 in the USART_CR1 register. Note: When this bit is set, the USART_RDR register content is not lost but the shift register is overwritten. An interrupt is generated if the ORE flag is set during multi buffer communication if the EIE bit is set. This bit is permanently forced to 0 (no overrun detection) when the bit OVRDIS is set in the USART_CR3 register.
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected This bit is set by hardware when an Idle Line is detected. An interrupt is generated if IDLEIE=1 in the USART_CR1 register. It is cleared by software, writing 1 to the IDLECF in the USART_ICR register. Note: The IDLE bit is not set again until the RXNE bit has been set (i.e. a new idle line occurs). If Mute mode is enabled (MME=1), IDLE is set if the USART is not mute (RWU=0), whatever the Mute mode selected by the WAKE bit. If RWU=1, IDLE is not set.
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read data register not empty RXNE bit is set by hardware when the content of the USART_RDR shift register has been transferred to the USART_RDR register. It is cleared by reading from the USART_RDR register. The RXNE flag can also be cleared by writing 1 to the RXFRQ in the USART_RQR register. An interrupt is generated if RXNEIE=1 in the USART_CR1 register.
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete This bit indicates that the last data written in the USART_TDR has been transmitted out of the shift register. The TC flag is set when the transmission of a frame containing data is complete and when TXE is set. An interrupt is generated if TCIE=1 in the USART_CR1 register. TC bit is cleared by software by writing 1 to the TCCF in the USART_ICR register or by writing to the USART_TDR register.
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty TXE is set by hardware when the content of the USART_TDR register has been transferred into the shift register. It is cleared by writing to the USART_TDR register. The TXE flag can also be set by writing 1 to the TXFRQ in the USART_RQR register, in order to discard the data (only in Smartcard T=0 mode, in case of transmission failure). An interrupt is generated if the TXEIE bit =1 in the USART_CR1 register.
 */
class txe_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LIN break detection flag This bit is set by hardware when the LIN break is detected. It is cleared by software, by writing 1 to the LBDCF in the USART_ICR. An interrupt is generated if LBDIE = 1 in the USART_CR2 register. Note: If the USART does not support LIN mode, this bit is reserved and kept at reset value. Refer to .
 */
class lbdf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lbdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag This bit is set by hardware when the nCTS input toggles, if the CTSE bit is set. It is cleared by software, by writing 1 to the CTSCF bit in the USART_ICR register. An interrupt is generated if CTSIE=1 in the USART_CR3 register. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag This bit is set/reset by hardware. It is an inverted copy of the status of the nCTS input pin. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver timeout This bit is set by hardware when the timeout value, programmed in the RTOR register has lapsed, without any communication. It is cleared by software, writing 1 to the RTOCF bit in the USART_ICR register. An interrupt is generated if RTOIE=1 in the USART_CR2 register. In Smartcard mode, the timeout corresponds to the CWT or BWT timings. Note: If a time equal to the value programmed in RTOR register separates 2 characters, RTOF is not set. If this time exceeds this value + 2 sample times (2/16 or 2/8, depending on the oversampling method), RTOF flag is set. The counter counts even if RE = 0 but RTOF is set only when RE = 1. If the timeout has already elapsed when RE is set, then RTOF is set. If the USART does not support the Receiver timeout feature, this bit is reserved and kept at reset value.
 */
class rtof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * End of block flag This bit is set by hardware when a complete block has been received (for example T=1 Smartcard mode). The detection is done when the number of received bytes (from the start of the block, including the prologue) is equal or greater than BLEN + 4. An interrupt is generated if EOBIE = 1 in the USART_CR1 register. It is cleared by software, writing 1 to EOBCF in the USART_ICR register. Note: If Smartcard mode is not supported, this bit is reserved and kept at reset value. Refer to .
 */
class eobf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eobf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SPI slave underrun error flag In Slave transmission mode, this flag is set when the first clock pulse for data transmission appears while the software has not yet loaded any value into USART_TDR. This flag is reset by setting UDRCF bit in the USART_ICR register. Note: If the USART does not support the SPI slave mode, this bit is reserved and kept at reset value. Refer to .
 */
class udr_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr udr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate error This bit is set by hardware if the baud rate measurement failed (baud rate out of range or character comparison failed) It is cleared by software, by writing 1 to the ABRRQ bit in the USART_RQR register. Note: If the USART does not support the auto baud rate feature, this bit is reserved and kept at reset value.
 */
class abre_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto baud rate flag This bit is set by hardware when the automatic baud rate has been set (RXNE is also set, generating an interrupt if RXNEIE = 1) or when the auto baud rate operation was completed without success (ABRE=1) (ABRE, RXNE and FE are also set in this case) It is cleared by software, in order to request a new auto baud rate detection, by writing 1 to the ABRRQ in the USART_RQR register. Note: If the USART does not support the auto baud rate feature, this bit is reserved and kept at reset value.
 */
class abrf_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr abrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag This bit is set and reset by hardware. It is active when a communication is ongoing on the RX line (successful start bit detected). It is reset at the end of the reception (successful or not).
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag This bit is set by hardware, when a the character defined by ADD[7:0] is received. It is cleared by software, writing 1 to the CMCF in the USART_ICR register. An interrupt is generated if CMIE=1in the USART_CR1 register.
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag This bit indicates that a send break character was requested. It is set by software, by writing 1 to the SBKRQ bit in the USART_CR3 register. It is automatically reset by hardware during the stop bit of break transmission.
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup from Mute mode This bit indicates if the USART is in Mute mode. It is cleared/set by hardware when a wakeup/mute sequence is recognized. The Mute mode control sequence (address or IDLE) is selected by the WAKE bit in the USART_CR1 register. When wakeup on IDLE mode is selected, this bit can only be set by software, writing 1 to the MMRQ bit in the USART_RQR register. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode flag This bit is set by hardware, when a wakeup event is detected. The event is defined by the WUS bitfield. It is cleared by software, writing a 1 to the WUCF in the USART_ICR register. An interrupt is generated if WUFIE=1 in the USART_CR3 register. Note: When UESM is cleared, WUF flag is also cleared. If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag This bit is set/reset by hardware, when the Transmit Enable value is taken into account by the USART. It can be used when an idle frame request is generated by writing TE=0, followed by TE=1 in the USART_CR1 register, in order to respect the TE=0 minimum period.
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag This bit is set/reset by hardware, when the Receive Enable value is taken into account by the USART. It can be used to verify that the USART is ready for reception before entering low-power mode. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete before guard time flag This bit is set when the last data written in the USART_TDR has been transmitted correctly out of the shift register. It is set by hardware in Smartcard mode, if the transmission of a frame containing data is complete and if the smartcard did not send back any NACK. An interrupt is generated if TCBGTIE=1 in the USART_CR3 register. This bit is cleared by software, by writing 1 to the TCBGTCF in the USART_ICR register or by a write to the USART_TDR register. Note: If the USART does not support the Smartcard mode, this bit is reserved and kept at reset value. If the USART supports the Smartcard mode and the Smartcard mode is enabled, the TCBGT reset value is '1'. Refer to on page 2297.
 */
class tcbgt_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcbgt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usart_isr_disabled_r>() const {return opsy::utility::clear_set<usart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return static_cast<usart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usart_isr_disabled_r> other) const -> opsy::utility::clear_set<usart_isr_disabled_r> {return opsy::utility::clear_set<usart_isr_disabled_r>(usart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr usart_isr_disabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usart_isr_disabled_r other) const -> usart_isr_disabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usart_isr_disabled_r { return ~value_; }
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
 * Parity error clear flag Writing 1 to this bit clears the PE flag in the USART_ISR register.
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
 * Framing error clear flag Writing 1 to this bit clears the FE flag in the USART_ISR register.
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
 * Noise detected clear flag Writing 1 to this bit clears the NE flag in the USART_ISR register.
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
 * Overrun error clear flag Writing 1 to this bit clears the ORE flag in the USART_ISR register.
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
 * Idle line detected clear flag Writing 1 to this bit clears the IDLE flag in the USART_ISR register.
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
 * TXFIFO empty clear flag Writing 1 to this bit clears the TXFE flag in the USART_ISR register.
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
 * Transmission complete clear flag Writing 1 to this bit clears the TC flag in the USART_ISR register.
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
 * Transmission complete before Guard time clear flag Writing 1 to this bit clears the TCBGT flag in the USART_ISR register.
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
 * LIN break detection clear flag Writing 1 to this bit clears the LBDF flag in the USART_ISR register. Note: If LIN mode is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * CTS clear flag Writing 1 to this bit clears the CTSIF flag in the USART_ISR register. Note: If the hardware flow control feature is not supported, this bit is reserved and must be kept at reset value. Refer to .
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
 * Receiver timeout clear flag Writing 1 to this bit clears the RTOF flag in the USART_ISR register. Note: If the USART does not support the Receiver timeout feature, this bit is reserved and must be kept at reset value. Refer to page 2297.
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
 * End of block clear flag Writing 1 to this bit clears the EOBF flag in the USART_ISR register. Note: If the USART does not support Smartcard mode, this bit is reserved and must be kept at reset value. Refer to .
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
 * SPI slave underrun clear flag Writing 1 to this bit clears the UDRF flag in the USART_ISR register. Note: If the USART does not support SPI slave mode, this bit is reserved and must be kept at reset value. Refer to
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
 * Character match clear flag Writing 1 to this bit clears the CMF flag in the USART_ISR register.
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
 * Wakeup from low-power mode clear flag Writing 1 to this bit clears the WUF flag in the USART_ISR register. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2297.
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
 * Receive data value Contains the received data character. The RDR register provides the parallel interface between the input shift register and the internal bus (see ). When receiving with the parity enabled, the value read in the MSB bit is the received parity bit.
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
 * Transmit data value Contains the data character to be transmitted. The USART_TDR register provides the parallel interface between the internal bus and the output shift register (see ). When transmitting with the parity enabled (PCE bit set to 1 in the USART_CR1 register), the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect because it is replaced by the parity. Note: This register must be written only when TXE/TXFNF=1.
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
 * Clock prescaler The USART input clock can be divided by a prescaler factor: Remaining combinations: Reserved Note: When PRESCALER is programmed with a value different of the allowed ones, programmed prescaler value is equal to '1011' i.e. input clock divided by 256.
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
		opsy::utility::memory<uint32_t,usart_cr1_enabled_r> usart_cr1_enabled;
		opsy::utility::memory<uint32_t,usart_cr1_disabled_r> usart_cr1_disabled;
	};
	opsy::utility::memory<uint32_t,usart_cr2_r> usart_cr2;
	opsy::utility::memory<uint32_t,usart_cr3_r> usart_cr3;
	opsy::utility::memory<uint32_t,usart_brr_r> usart_brr;
	opsy::utility::memory<uint32_t,usart_gtpr_r> usart_gtpr;
	opsy::utility::memory<uint32_t,usart_rtor_r> usart_rtor;
	opsy::utility::memory<uint32_t,usart_rqr_r> usart_rqr;
	union {
		opsy::utility::memory<uint32_t,usart_isr_enabled_r> usart_isr_enabled;
		opsy::utility::read_only_memory<uint32_t,usart_isr_disabled_r> usart_isr_disabled;
	};
	opsy::utility::memory<uint32_t,usart_icr_r> usart_icr;
	opsy::utility::memory<uint32_t,usart_rdr_r> usart_rdr;
	opsy::utility::memory<uint32_t,usart_tdr_r> usart_tdr;
	opsy::utility::memory<uint32_t,usart_presc_r> usart_presc;
};

static_assert(std::is_standard_layout_v<usart_p>);
static_assert(offsetof(usart_p, usart_cr1_enabled) == 0);
static_assert(offsetof(usart_p, usart_cr1_disabled) == 0);
static_assert(offsetof(usart_p, usart_cr2) == 4);
static_assert(offsetof(usart_p, usart_cr3) == 8);
static_assert(offsetof(usart_p, usart_brr) == 12);
static_assert(offsetof(usart_p, usart_gtpr) == 16);
static_assert(offsetof(usart_p, usart_rtor) == 20);
static_assert(offsetof(usart_p, usart_rqr) == 24);
static_assert(offsetof(usart_p, usart_isr_enabled) == 28);
static_assert(offsetof(usart_p, usart_isr_disabled) == 28);
static_assert(offsetof(usart_p, usart_icr) == 32);
static_assert(offsetof(usart_p, usart_rdr) == 36);
static_assert(offsetof(usart_p, usart_tdr) == 40);
static_assert(offsetof(usart_p, usart_presc) == 44);

inline usart_p& sec_uart12 = *reinterpret_cast<usart_p*>(0x50008400);
inline usart_p& sec_uart4 = *reinterpret_cast<usart_p*>(0x50004C00);
inline usart_p& sec_uart5 = *reinterpret_cast<usart_p*>(0x50005000);
inline usart_p& sec_uart7 = *reinterpret_cast<usart_p*>(0x50007800);
inline usart_p& sec_uart8 = *reinterpret_cast<usart_p*>(0x50007C00);
inline usart_p& sec_uart9 = *reinterpret_cast<usart_p*>(0x50008000);
inline usart_p& sec_usart1 = *reinterpret_cast<usart_p*>(0x50013800);
inline usart_p& sec_usart10 = *reinterpret_cast<usart_p*>(0x50006800);
inline usart_p& sec_usart11 = *reinterpret_cast<usart_p*>(0x50006C00);
inline usart_p& sec_usart2 = *reinterpret_cast<usart_p*>(0x50004400);
inline usart_p& sec_usart3 = *reinterpret_cast<usart_p*>(0x50004800);
inline usart_p& sec_usart6 = *reinterpret_cast<usart_p*>(0x50006400);
inline usart_p& uart12 = *reinterpret_cast<usart_p*>(0x40008400);
inline usart_p& uart4 = *reinterpret_cast<usart_p*>(0x40004C00);
inline usart_p& uart5 = *reinterpret_cast<usart_p*>(0x40005000);
inline usart_p& uart7 = *reinterpret_cast<usart_p*>(0x40007800);
inline usart_p& uart8 = *reinterpret_cast<usart_p*>(0x40007C00);
inline usart_p& uart9 = *reinterpret_cast<usart_p*>(0x40008000);
inline usart_p& usart1 = *reinterpret_cast<usart_p*>(0x40013800);
inline usart_p& usart10 = *reinterpret_cast<usart_p*>(0x40006800);
inline usart_p& usart11 = *reinterpret_cast<usart_p*>(0x40006C00);
inline usart_p& usart2 = *reinterpret_cast<usart_p*>(0x40004400);
inline usart_p& usart3 = *reinterpret_cast<usart_p*>(0x40004800);
inline usart_p& usart6 = *reinterpret_cast<usart_p*>(0x40006400);

} // STM32H563

