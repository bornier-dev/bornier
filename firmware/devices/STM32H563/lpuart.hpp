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
class lpuart_p {
public:

/**
 * LPUART control register 1 [alternate] 
 */
class lpuart_cr1_enabled_r {
public:

/**
 * LPUART enable When this bit is cleared, the LPUART prescalers and outputs are stopped immediately, and current operations are discarded. The configuration of the LPUART is kept, but all the status flags, in the LPUART_ISR are reset. This bit is set and cleared by software. Note: To enter low-power mode without generating errors on the line, the TE bit must be reset before and the software must wait for the TC bit in the LPUART_ISR to be set before resetting the UE bit. The DMA requests are also reset when UE = 0 so the DMA channel must be disabled before resetting the UE bit.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART enable in low-power mode When this bit is cleared, the LPUART cannot wake up the MCU from low-power mode. When this bit is set, the LPUART can wake up the MCU from low-power mode. This bit is set and cleared by software. Note: It is recommended to set the UESM bit just before entering low-power mode, and clear it when exiting low-power mode.
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable This bit enables the transmitter. It is set and cleared by software. Note: During transmission, a low pulse on the TE bit ('0' followed by '1') sends a preamble (idle line) after the current word, except in Smartcard mode. In order to generate an idle character, the TE must not be immediately written to '1'. To ensure the required duration, the software can poll the TEACK bit in the LPUART_ISR register. In Smartcard mode, when TE is set, there is a 1 bit-time delay before the transmission starts.
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity is selected after the current byte. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0) and parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission). This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup method This bit determines the LPUART wakeup method from Mute mode. It is set or cleared by software. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit is used in conjunction with bit 28 (M1) to determine the word length. It is set or cleared by software (refer to bit 28 (M1) description). This bit can only be written when the LPUART is disabled (UE=0).
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable This bit activates the Mute mode function of the LPUART. When set, the LPUART can switch between the active and Mute modes, as defined by the WAKE bit. It is set and cleared by software.
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time This 5-bit value defines the time between the end of the last stop bit, in a transmitted message, and the de-activation of the DE (Driver Enable) signal.It is expressed in lpuart_ker_ck clock cycles. For more details, refer control and RS485 Driver Enable. If the LPUART_TDR register is written during the DEDT time, the new data is transmitted only when the DEDT and DEAT times have both elapsed. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time This 5-bit value defines the time between the activation of the DE (Driver Enable) signal and the beginning of the start bit. It is expressed in lpuart_ker_ck clock cycles. For more details, refer . This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Word length This bit must be used in conjunction with bit 12 (M0) to determine the word length. It is set or cleared by software. M[1:0] = '00': 1 Start bit, 8 Data bits, n Stop bit M[1:0] = '01': 1 Start bit, 9 Data bits, n Stop bit M[1:0] = '10': 1 Start bit, 7 Data bits, n Stop bit This bit can only be written when the LPUART is disabled (UE=0). Note: In 7-bit data length mode, the Smartcard mode, LIN master mode and auto baud rate (0x7F and 0x55 frames detection) are not supported.
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable This bit is set and cleared by software.
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_enabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return static_cast<lpuart_cr1_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_enabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_enabled_r> {return opsy::utility::clear_set<lpuart_cr1_enabled_r>(lpuart_cr1_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfeie() const -> txfeie_f {return txfeie_f((value_ & txfeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxffie() const -> rxffie_f {return rxffie_f((value_ & rxffie_f::mask) != 0);}

	constexpr lpuart_cr1_enabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr1_enabled_r other) const -> lpuart_cr1_enabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr1_enabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 1 [alternate] 
 */
class lpuart_cr1_disabled_r {
public:

/**
 * LPUART enable When this bit is cleared, the LPUART prescalers and outputs are stopped immediately, and current operations are discarded. The configuration of the LPUART is kept, but all the status flags, in the LPUART_ISR are reset. This bit is set and cleared by software. Note: To enter low-power mode without generating errors on the line, the TE bit must be reset before and the software must wait for the TC bit in the LPUART_ISR to be set before resetting the UE bit. The DMA requests are also reset when UE = 0 so the DMA channel must be disabled before resetting the UE bit.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART enable in low-power mode When this bit is cleared, the LPUART cannot wake up the MCU from low-power mode. When this bit is set, the LPUART can wake up the MCU from low-power mode. This bit is set and cleared by software. Note: It is recommended to set the UESM bit just before entering low-power mode, and clear it when exiting low-power mode.
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable This bit enables the transmitter. It is set and cleared by software. Note: During transmission, a low pulse on the TE bit ('0' followed by '1') sends a preamble (idle line) after the current word, except in Smartcard mode. In order to generate an idle character, the TE must not be immediately written to '1. To ensure the required duration, the software can poll the TEACK bit in the LPUART_ISR register. In Smartcard mode, when TE is set, there is a 1 bit-time delay before the transmission starts.
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection This bit selects the odd or even parity when the parity generation/detection is enabled (PCE bit set). It is set and cleared by software. The parity is selected after the current byte. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable This bit selects the hardware parity control (generation and detection). When the parity control is enabled, the computed parity is inserted at the MSB position (9th bit if M=1; 8th bit if M=0) and parity is checked on the received data. This bit is set and cleared by software. Once it is set, PCE is active after the current byte (in reception and in transmission). This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup method This bit determines the LPUART wakeup method from Mute mode. It is set or cleared by software. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length This bit is used in conjunction with bit 28 (M1) to determine the word length. It is set or cleared by software (refer to bit 28 (M1) description). This bit can only be written when the LPUART is disabled (UE=0).
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable This bit activates the Mute mode function of the LPUART. When set, the LPUART can switch between the active and Mute modes, as defined by the WAKE bit. It is set and cleared by software.
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time This 5-bit value defines the time between the end of the last stop bit, in a transmitted message, and the de-activation of the DE (Driver Enable) signal.It is expressed in lpuart_ker_ck clock cycles. For more details, refer control and RS485 Driver Enable. If the LPUART_TDR register is written during the DEDT time, the new data is transmitted only when the DEDT and DEAT times have both elapsed. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time This 5-bit value defines the time between the activation of the DE (Driver Enable) signal and the beginning of the start bit. It is expressed in lpuart_ker_ck clock cycles. For more details, refer . This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Word length This bit must be used in conjunction with bit 12 (M0) to determine the word length. It is set or cleared by software. M[1:0] = '00': 1 Start bit, 8 Data bits, n Stop bit M[1:0] = '01': 1 Start bit, 9 Data bits, n Stop bit M[1:0] = '10': 1 Start bit, 7 Data bits, n Stop bit This bit can only be written when the LPUART is disabled (UE=0). Note: In 7-bit data length mode, the Smartcard mode, LIN master mode and auto baud rate (0x7F and 0x55 frames detection) are not supported.
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable This bit is set and cleared by software.
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_disabled_r>() const {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return static_cast<lpuart_cr1_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_disabled_r> other) const -> opsy::utility::clear_set<lpuart_cr1_disabled_r> {return opsy::utility::clear_set<lpuart_cr1_disabled_r>(lpuart_cr1_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}

	constexpr lpuart_cr1_disabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr1_disabled_r other) const -> lpuart_cr1_disabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr1_disabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 2 
 */
class lpuart_cr2_r {
public:

/**
 * 7-bit Address Detection/4-bit Address Detection This bit is for selection between 4-bit address detection or 7-bit address detection. This bit can only be written when the LPUART is disabled (UE=0) Note: In 7-bit and 9-bit data modes, the address detection is done on 6-bit and 8-bit address (ADD[5:0] and ADD[7:0]) respectively.
 */
class addm7_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addm7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STOP bits These bits are used for programming the stop bits. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class stop_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr stop_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Swap TX/RX pins This bit is set and cleared by software. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class swap_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX pin active level inversion This bit is set and cleared by software. This enables the use of an external inverter on the RX line. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class rxinv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX pin active level inversion This bit is set and cleared by software. This enables the use of an external inverter on the TX line. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class txinv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Binary data inversion This bit is set and cleared by software. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class datainv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr datainv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Most significant bit first This bit is set and cleared by software. This bitfield can only be written when the LPUART is disabled (UE=0).
 */
class msbfirst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr msbfirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address of the LPUART node These bits give the address of the LPUART node in Mute mode or a character code to be recognized in low-power or Run mode: In Mute mode: they are used in multiprocessor communication to wakeup from Mute mode with 4-bit/7-bit address mark detection. The MSB of the character sent by the transmitter should be equal to 1. In 4-bit address mark detection, only ADD[3:0] bits are used. In low-power mode: they are used for wake up from low-power mode on character match. When WUS[1:0] is programmed to 0b00 (WUF active on address match), the wakeup from low-power mode is performed when the received character corresponds to the character programmed through ADD[6:0] or ADD[3:0] bitfield (depending on ADDM7 bit), and WUF interrupt is enabled by setting WUFIE bit. The MSB of the character sent by transmitter should be equal to 1. In Run mode with Mute mode inactive (for example, end-of-block detection in ModBus protocol): the whole received character (8 bits) is compared to ADD[7:0] value and CMF flag is set on match. An interrupt is generated if the CMIE bit is set. These bits can only be written when the reception is disabled (RE = 0) or when the USART is disabled (UE = 0).
 */
class add_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto addm7() const -> addm7_f {return addm7_f((value_ & addm7_f::mask) != 0);}
	[[nodiscard]] constexpr auto stop() const -> stop_f {return stop_f(static_cast<uint8_t>(value_ >> stop_f::offset));}
	[[nodiscard]] constexpr auto swap() const -> swap_f {return swap_f((value_ & swap_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxinv() const -> rxinv_f {return rxinv_f((value_ & rxinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto txinv() const -> txinv_f {return txinv_f((value_ & txinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto datainv() const -> datainv_f {return datainv_f((value_ & datainv_f::mask) != 0);}
	[[nodiscard]] constexpr auto msbfirst() const -> msbfirst_f {return msbfirst_f((value_ & msbfirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}

	constexpr lpuart_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr2_r other) const -> lpuart_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 3 
 */
class lpuart_cr3_r {
public:

/**
 * Error interrupt enable Error Interrupt Enable Bit is required to enable interrupt generation in case of a framing error, overrun error or noise flag (FE=1 or ORE=1 or NE=1 in the LPUART_ISR register).
 */
class eie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex selection Selection of Single-wire Half-duplex mode This bit can only be written when the LPUART is disabled (UE=0).
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTS enable This bit can only be written when the LPUART is disabled (UE=0).
 */
class rtse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS enable This bit can only be written when the LPUART is disabled (UE=0)
 */
class ctse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun Disable This bit is used to disable the receive overrun detection. the ORE flag is not set and the new received data overwrites the previous content of the LPUART_RDR register. This bit can only be written when the LPUART is disabled (UE=0). Note: This control bit enables checking the communication flow w/o reading the data.
 */
class ovrdis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Disable on Reception Error This bit can only be written when the LPUART is disabled (UE=0). Note: The reception errors are: parity error, framing error or noise error.
 */
class ddre_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ddre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable mode This bit enables the user to activate the external transceiver control, through the DE signal. This bit can only be written when the LPUART is disabled (UE=0).
 */
class dem_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dem_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable polarity selection This bit can only be written when the LPUART is disabled (UE=0).
 */
class dep_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode interrupt flag selection This bitfield specifies the event which activates the WUF (Wakeup from low-power mode flag). This bitfield can only be written when the LPUART is disabled (UE=0). Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2386.
 */
class wus0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode interrupt flag selection This bitfield specifies the event which activates the WUF (Wakeup from low-power mode flag). This bitfield can only be written when the LPUART is disabled (UE=0). Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2386.
 */
class wus1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode interrupt enable This bit is set and cleared by software. Note: WUFIE must be set before entering in low-power mode. If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2386.
 */
class wufie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO threshold configuration Remaining combinations: Reserved.
 */
class rxftcfg_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold configuration Remaining combinations: Reserved.
 */
class txftcfg_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto eie() const -> eie_f {return eie_f((value_ & eie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmar() const -> dmar_f {return dmar_f((value_ & dmar_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmat() const -> dmat_f {return dmat_f((value_ & dmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtse() const -> rtse_f {return rtse_f((value_ & rtse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctse() const -> ctse_f {return ctse_f((value_ & ctse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsie() const -> ctsie_f {return ctsie_f((value_ & ctsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrdis() const -> ovrdis_f {return ovrdis_f((value_ & ovrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddre() const -> ddre_f {return ddre_f((value_ & ddre_f::mask) != 0);}
	[[nodiscard]] constexpr auto dem() const -> dem_f {return dem_f((value_ & dem_f::mask) != 0);}
	[[nodiscard]] constexpr auto dep() const -> dep_f {return dep_f((value_ & dep_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus0() const -> wus0_f {return wus0_f((value_ & wus0_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus1() const -> wus1_f {return wus1_f((value_ & wus1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wufie() const -> wufie_f {return wufie_f((value_ & wufie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftie() const -> txftie_f {return txftie_f((value_ & txftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxftcfg() const -> rxftcfg_f {return rxftcfg_f(static_cast<uint8_t>(value_ >> rxftcfg_f::offset));}
	[[nodiscard]] constexpr auto rxftie() const -> rxftie_f {return rxftie_f((value_ & rxftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftcfg() const -> txftcfg_f {return txftcfg_f(static_cast<uint8_t>(value_ >> txftcfg_f::offset));}

	constexpr lpuart_cr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr3_r other) const -> lpuart_cr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART baud rate register 
 */
class lpuart_brr_r {
public:

/**
 * LPUART baud rate division (LPUARTDIV)
 */
class brr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr brr_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator lpuart_brr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_brr_r>() const {return opsy::utility::clear_set<lpuart_brr_r>(mask, *this);}
	constexpr auto operator|(lpuart_brr_r other) const -> lpuart_brr_r { return static_cast<lpuart_brr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_brr_r> other) const -> opsy::utility::clear_set<lpuart_brr_r> {return opsy::utility::clear_set<lpuart_brr_r>(lpuart_brr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto brr() const -> brr_f {return brr_f(static_cast<uint32_t>(value_ >> brr_f::offset));}

	constexpr lpuart_brr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_brr_r other) const -> lpuart_brr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_brr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART request register 
 */
class lpuart_rqr_r {
public:

/**
 * Send break request Writing 1 to this bit sets the SBKF flag and request to send a BREAK on the line, as soon as the transmit machine is available. Note: If the application needs to send the break character following all previously inserted data, including the ones not yet transmitted, the software should wait for the TXE flag assertion before setting the SBKRQ bit.
 */
class sbkrq_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbkrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode request Writing 1 to this bit puts the LPUART in Mute mode and resets the RWU flag.
 */
class mmrq_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mmrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data flush request Writing 1 to this bit clears the RXNE flag. This enables discarding the received data without reading it, and avoid an overrun condition.
 */
class rxfrq_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data flush request This bit is used when FIFO mode is enabled. TXFRQ bit is set to flush the whole FIFO. This sets the flag TXFE (TXFIFO empty, bit 23 in the LPUART_ISR register). Note: In FIFO mode, the TXFNF flag is reset during the flush request until TxFIFO is empty in order to ensure that no data are written in the data register.
 */
class txfrq_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbkrq() const -> sbkrq_f {return sbkrq_f((value_ & sbkrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmrq() const -> mmrq_f {return mmrq_f((value_ & mmrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfrq() const -> rxfrq_f {return rxfrq_f((value_ & rxfrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfrq() const -> txfrq_f {return txfrq_f((value_ & txfrq_f::mask) != 0);}

	constexpr lpuart_rqr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_rqr_r other) const -> lpuart_rqr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_rqr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt and status register [alternate] 
 */
class lpuart_isr_enabled_r {
public:

/**
 * Parity error This bit is set by hardware when a parity error occurs in Reception mode. It is cleared by software, writing 1 to the PECF in the LPUART_ICR register. An interrupt is generated if PEIE = 1 in the LPUART_CR1 register. Note: This error is associated with the character in the LPUART_RDR.
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error This bit is set by hardware when a de-synchronization, excessive noise or a break character is detected. It is cleared by software, writing 1 to the FECF bit in the LPUART_ICR register. When transmitting data in Smartcard mode, this bit is set when the maximum number of transmit attempts is reached without success (the card NACKs the data frame). An interrupt is generated if EIE = 1 in the LPUART_CR1 register. Note: This error is associated with the character in the LPUART_RDR.
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start bit noise detection flag This bit is set by hardware when noise is detected on the start bit of a received frame. It is cleared by software, writing 1 to the NFCF bit in the LPUART_ICR register. Note: This bit does not generate an interrupt as it appears at the same time as the RXFNE bit which itself generates an interrupt. An interrupt is generated when the NE flag is set during multi buffer communication if the EIE bit is set. This error is associated with the character in the LPUART_RDR.
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error This bit is set by hardware when the data currently being received in the shift register is ready to be transferred into the LPUART_RDR register while RXFF = 1. It is cleared by a software, writing 1 to the ORECF, in the LPUART_ICR register. An interrupt is generated if RXFNEIE=1 or EIE = 1 in the LPUART_CR1 register. Note: When this bit is set, the LPUART_RDR register content is not lost but the shift register is overwritten. An interrupt is generated if the ORE flag is set during multi buffer communication if the EIE bit is set. This bit is permanently forced to 0 (no overrun detection) when the bit OVRDIS is set in the LPUART_CR3 register.
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected This bit is set by hardware when an Idle line is detected. An interrupt is generated if IDLEIE=1 in the LPUART_CR1 register. It is cleared by software, writing 1 to the IDLECF in the LPUART_ICR register. Note: The IDLE bit is not set again until the RXFNE bit has been set (i.e. a new idle line occurs). If Mute mode is enabled (MME=1), IDLE is set if the LPUART is not mute (RWU=0), whatever the Mute mode selected by the WAKE bit. If RWU=1, IDLE is not set.
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty RXFNE bit is set by hardware when the RXFIFO is not empty, and so data can be read from the LPUART_RDR register. Every read of the LPUART_RDR frees a location in the RXFIFO. It is cleared when the RXFIFO is empty. The RXFNE flag can also be cleared by writing 1 to the RXFRQ in the LPUART_RQR register. An interrupt is generated if RXFNEIE=1 in the LPUART_CR1 register.
 */
class rxfne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete This bit indicates that the last data written in the LPUART_TDR has been transmitted out of the shift register. The TC flag behaves as follows: When TDN = 0, the TC flag is set when the transmission of a frame containing data is complete and when TXFE is set. When TDN is equal to the number of data in the TXFIFO, the TC flag is set when TXFIFO is empty and TDN is reached. When TDN is greater than the number of data in the TXFIFO, TC remains cleared until the TXFIFO is filled again to reach the programmed number of data to be transferred. When TDN is less than the number of data in the TXFIFO, TC is set when TDN is reached even if the TXFIFO is not empty. An interrupt is generated if TCIE=1 in the LPUART_CR1 register. TC bit is cleared by software by writing 1 to the TCCF in the LPUART_ICR register or by writing to the LPUART_TDR register.
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full TXFNF is set by hardware when TXFIFO is not full, and so data can be written in the LPUART_TDR. Every write in the LPUART_TDR places the data in the TXFIFO. This flag remains set until the TXFIFO is full. When the TXFIFO is full, this flag is cleared indicating that data can not be written into the LPUART_TDR. The TXFNF is kept reset during the flush request until TXFIFO is empty. After sending the flush request (by setting TXFRQ bit), the flag TXFNF should be checked prior to writing in TXFIFO (TXFNF and TXFE are set at the same time). An interrupt is generated if the TXFNFIE bit =1 in the LPUART_CR1 register. Note: This bit is used during single buffer transmission.
 */
class txfnf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag This bit is set by hardware when the nCTS input toggles, if the CTSE bit is set. It is cleared by software, by writing 1 to the CTSCF bit in the LPUART_ICR register. An interrupt is generated if CTSIE=1 in the LPUART_CR3 register. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag This bit is set by hardware, when a the character defined by ADD[7:0] is received. It is cleared by software, writing 1 to the CMCF in the LPUART_ICR register. An interrupt is generated if CMIE=1in the LPUART_CR1 register.
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag This bit indicates that a send break character was requested. It is set by software, by writing 1 to the SBKRQ bit in the LPUART_CR3 register. It is automatically reset by hardware during the stop bit of break transmission.
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup from Mute mode This bit indicates if the LPUART is in Mute mode. It is cleared/set by hardware when a wakeup/mute sequence is recognized. The Mute mode control sequence (address or IDLE) is selected by the WAKE bit in the LPUART_CR1 register. When wakeup on IDLE mode is selected, this bit can only be set by software, writing 1 to the MMRQ bit in the LPUART_RQR register. Note: If the LPUART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value.
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode flag This bit is set by hardware, when a wakeup event is detected. The event is defined by the WUS bitfield. It is cleared by software, writing a 1 to the WUCF in the LPUART_ICR register. An interrupt is generated if WUFIE=1 in the LPUART_CR3 register. Note: When UESM is cleared, WUF flag is also cleared. If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag This bit is set/reset by hardware, when the Transmit Enable value is taken into account by the LPUART. It can be used when an idle frame request is generated by writing TE=0, followed by TE=1 in the LPUART_CR1 register, in order to respect the TE=0 minimum period.
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag This bit is set/reset by hardware, when the Receive Enable value is taken into account by the LPUART. It can be used to verify that the LPUART is ready for reception before entering low-power mode. Note: If the LPUART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value.
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO Empty This bit is set by hardware when TXFIFO is Empty. When the TXFIFO contains at least one data, this flag is cleared. The TXFE flag can also be set by writing 1 to the bit TXFRQ (bit 4) in the LPUART_RQR register. An interrupt is generated if the TXFEIE bit =1 (bit 30) in the LPUART_CR1 register.
 */
class txfe_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full This bit is set by hardware when the number of received data corresponds to RXFIFO size + 1 (RXFIFO full + 1 data in the LPUART_RDR register. An interrupt is generated if the RXFFIE bit =1 in the LPUART_CR1 register.
 */
class rxff_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO threshold flag This bit is set by hardware when the RXFIFO reaches the threshold programmed in RXFTCFG in LPUART_CR3 register i.e. the Receive FIFO contains RXFTCFG data. An interrupt is generated if the RXFTIE bit =1 (bit 27) in the LPUART_CR3 register.
 */
class rxft_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold flag This bit is set by hardware when the TXFIFO reaches the threshold programmed in TXFTCFG in LPUART_CR3 register i.e. the TXFIFO contains TXFTCFG empty locations. An interrupt is generated if the TXFTIE bit =1 (bit 31) in the LPUART_CR3 register.
 */
class txft_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_enabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_enabled_r>() const {return opsy::utility::clear_set<lpuart_isr_enabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return static_cast<lpuart_isr_enabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_enabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_enabled_r> {return opsy::utility::clear_set<lpuart_isr_enabled_r>(lpuart_isr_enabled_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfe() const -> txfe_f {return txfe_f((value_ & txfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxff() const -> rxff_f {return rxff_f((value_ & rxff_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxft() const -> rxft_f {return rxft_f((value_ & rxft_f::mask) != 0);}
	[[nodiscard]] constexpr auto txft() const -> txft_f {return txft_f((value_ & txft_f::mask) != 0);}

	constexpr lpuart_isr_enabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_isr_enabled_r other) const -> lpuart_isr_enabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_isr_enabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000000000011000000; // 8388800 0x8000C0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt and status register [alternate] 
 */
class lpuart_isr_disabled_r {
public:

/**
 * Parity error This bit is set by hardware when a parity error occurs in Reception mode. It is cleared by software, writing 1 to the PECF in the LPUART_ICR register. An interrupt is generated if PEIE = 1 in the LPUART_CR1 register. Note: In FIFO mode, this error is associated with the character in the LPUART_RDR.
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error This bit is set by hardware when a de-synchronization, excessive noise or a break character is detected. It is cleared by software, writing 1 to the FECF bit in the LPUART_ICR register. When transmitting data in Smartcard mode, this bit is set when the maximum number of transmit attempts is reached without success (the card NACKs the data frame). An interrupt is generated if EIE = 1 in the LPUART_CR1 register. Note: In FIFO mode, this error is associated with the character in the LPUART_RDR.
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start bit noise detection flag This bit is set by hardware when noise is detected on the start bit of a received frame. It is cleared by software, writing 1 to the NFCF bit in the LPUART_ICR register. Note: This bit does not generate an interrupt as it appears at the same time as the RXNE/RXFNE bit which itself generates an interrupt. An interrupt is generated when the NE flag is set during multi buffer communication if the EIE bit is set. In FIFO mode, this error is associated with the character in the LPUART_RDR.
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error This bit is set by hardware when the data currently being received in the shift register is ready to be transferred into the LPUART_RDR register while RXNE=1 (RXFF = 1 in case FIFO mode is enabled). It is cleared by a software, writing 1 to the ORECF, in the LPUART_ICR register. An interrupt is generated if RXNEIE=1 or EIE = 1 in the LPUART_CR1 register. Note: When this bit is set, the LPUART_RDR register content is not lost but the shift register is overwritten. An interrupt is generated if the ORE flag is set during multi buffer communication if the EIE bit is set. This bit is permanently forced to 0 (no overrun detection) when the bit OVRDIS is set in the LPUART_CR3 register.
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected This bit is set by hardware when an Idle Line is detected. An interrupt is generated if IDLEIE=1 in the LPUART_CR1 register. It is cleared by software, writing 1 to the IDLECF in the LPUART_ICR register. Note: The IDLE bit is not set again until the RXNE bit has been set (i.e. a new idle line occurs). If Mute mode is enabled (MME=1), IDLE is set if the LPUART is not mute (RWU=0), whatever the Mute mode selected by the WAKE bit. If RWU=1, IDLE is not set.
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read data register not empty RXNE bit is set by hardware when the content of the LPUART_RDR shift register has been transferred to the LPUART_RDR register. It is cleared by a read to the LPUART_RDR register. The RXNE flag can also be cleared by writing 1 to the RXFRQ in the LPUART_RQR register. The RXFNE flag can also be cleared by writing 1 to the RXFRQ in the LPUART_RQR register. An interrupt is generated if RXNEIE=1 in the LPUART_CR1 register.
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty TXE is set by hardware when the content of the LPUART_TDR register has been transferred into the shift register. It is cleared by a write to the LPUART_TDR register. An interrupt is generated if the TXEIE bit =1 in the LPUART_CR1 register. Note: This bit is used during single buffer transmission.
 */
class txe_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag This bit is set by hardware when the nCTS input toggles, if the CTSE bit is set. It is cleared by software, by writing 1 to the CTSCF bit in the LPUART_ICR register. An interrupt is generated if CTSIE=1 in the LPUART_CR3 register. Note: If the hardware flow control feature is not supported, this bit is reserved and kept at reset value.
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag This bit is set by hardware, when a the character defined by ADD[7:0] is received. It is cleared by software, writing 1 to the CMCF in the LPUART_ICR register. An interrupt is generated if CMIE=1in the LPUART_CR1 register.
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag This bit indicates that a send break character was requested. It is set by software, by writing 1 to the SBKRQ bit in the LPUART_CR3 register. It is automatically reset by hardware during the stop bit of break transmission.
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wakeup from Mute mode This bit indicates if the LPUART is in Mute mode. It is cleared/set by hardware when a wakeup/mute sequence is recognized. The Mute mode control sequence (address or IDLE) is selected by the WAKE bit in the LPUART_CR1 register. When wakeup on IDLE mode is selected, this bit can only be set by software, writing 1 to the MMRQ bit in the LPUART_RQR register. Note: If the LPUART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value.
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode flag This bit is set by hardware, when a wakeup event is detected. The event is defined by the WUS bitfield. It is cleared by software, writing a 1 to the WUCF in the LPUART_ICR register. An interrupt is generated if WUFIE=1 in the LPUART_CR3 register. Note: When UESM is cleared, WUF flag is also cleared. If the USART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value. Refer to .
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag This bit is set/reset by hardware, when the Transmit Enable value is taken into account by the LPUART. It can be used when an idle frame request is generated by writing TE=0, followed by TE=1 in the LPUART_CR1 register, in order to respect the TE=0 minimum period.
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag This bit is set/reset by hardware, when the Receive Enable value is taken into account by the LPUART. It can be used to verify that the LPUART is ready for reception before entering low-power mode. Note: If the LPUART does not support the wakeup from Stop feature, this bit is reserved and kept at reset value.
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_disabled_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_disabled_r>() const {return opsy::utility::clear_set<lpuart_isr_disabled_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return static_cast<lpuart_isr_disabled_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_disabled_r> other) const -> opsy::utility::clear_set<lpuart_isr_disabled_r> {return opsy::utility::clear_set<lpuart_isr_disabled_r>(lpuart_isr_disabled_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}

	constexpr lpuart_isr_disabled_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_isr_disabled_r other) const -> lpuart_isr_disabled_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_isr_disabled_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000000000011000000; // 8388800 0x8000C0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt flag clear register 
 */
class lpuart_icr_r {
public:

/**
 * Parity error clear flag Writing 1 to this bit clears the PE flag in the LPUART_ISR register.
 */
class pecf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error clear flag Writing 1 to this bit clears the FE flag in the LPUART_ISR register.
 */
class fecf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detected clear flag Writing 1 to this bit clears the NE flag in the LPUART_ISR register.
 */
class necf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr necf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error clear flag Writing 1 to this bit clears the ORE flag in the LPUART_ISR register.
 */
class orecf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr orecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected clear flag Writing 1 to this bit clears the IDLE flag in the LPUART_ISR register.
 */
class idlecf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idlecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete clear flag Writing 1 to this bit clears the TC flag in the LPUART_ISR register.
 */
class tccf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS clear flag Writing 1 to this bit clears the CTSIF flag in the LPUART_ISR register.
 */
class ctscf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctscf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match clear flag Writing 1 to this bit clears the CMF flag in the LPUART_ISR register.
 */
class cmcf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup from low-power mode clear flag Writing 1 to this bit clears the WUF flag in the USART_ISR register. Note: If the USART does not support the wakeup from Stop feature, this bit is reserved and must be kept at reset value. Refer to page 2386.
 */
class wucf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wucf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pecf() const -> pecf_f {return pecf_f((value_ & pecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fecf() const -> fecf_f {return fecf_f((value_ & fecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto necf() const -> necf_f {return necf_f((value_ & necf_f::mask) != 0);}
	[[nodiscard]] constexpr auto orecf() const -> orecf_f {return orecf_f((value_ & orecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto idlecf() const -> idlecf_f {return idlecf_f((value_ & idlecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tccf() const -> tccf_f {return tccf_f((value_ & tccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctscf() const -> ctscf_f {return ctscf_f((value_ & ctscf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmcf() const -> cmcf_f {return cmcf_f((value_ & cmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wucf() const -> wucf_f {return wucf_f((value_ & wucf_f::mask) != 0);}

	constexpr lpuart_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_icr_r other) const -> lpuart_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART receive data register 
 */
class lpuart_rdr_r {
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
	constexpr operator lpuart_rdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_rdr_r>() const {return opsy::utility::clear_set<lpuart_rdr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rdr_r other) const -> lpuart_rdr_r { return static_cast<lpuart_rdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rdr_r> other) const -> opsy::utility::clear_set<lpuart_rdr_r> {return opsy::utility::clear_set<lpuart_rdr_r>(lpuart_rdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdr() const -> rdr_f {return rdr_f(static_cast<uint16_t>(value_ >> rdr_f::offset));}

	constexpr lpuart_rdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_rdr_r other) const -> lpuart_rdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_rdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART transmit data register 
 */
class lpuart_tdr_r {
public:

/**
 * Transmit data value Contains the data character to be transmitted. The TDR register provides the parallel interface between the internal bus and the output shift register (see ). When transmitting with the parity enabled (PCE bit set to 1 in the LPUART_CR1 register), the value written in the MSB (bit 7 or bit 8 depending on the data length) has no effect because it is replaced by the parity. Note: This register must be written only when TXE/TXFNF=1.
 */
class tdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lpuart_tdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_tdr_r>() const {return opsy::utility::clear_set<lpuart_tdr_r>(mask, *this);}
	constexpr auto operator|(lpuart_tdr_r other) const -> lpuart_tdr_r { return static_cast<lpuart_tdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_tdr_r> other) const -> opsy::utility::clear_set<lpuart_tdr_r> {return opsy::utility::clear_set<lpuart_tdr_r>(lpuart_tdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tdr() const -> tdr_f {return tdr_f(static_cast<uint16_t>(value_ >> tdr_f::offset));}

	constexpr lpuart_tdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_tdr_r other) const -> lpuart_tdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_tdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART prescaler register 
 */
class lpuart_presc_r {
public:

/**
 * Clock prescaler The LPUART input clock can be divided by a prescaler: Remaining combinations: Reserved. Note: When PRESCALER is programmed with a value different of the allowed ones, programmed prescaler value is equal to 1011 i.e. input clock divided by 256.
 */
class prescaler_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prescaler_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_presc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_presc_r>() const {return opsy::utility::clear_set<lpuart_presc_r>(mask, *this);}
	constexpr auto operator|(lpuart_presc_r other) const -> lpuart_presc_r { return static_cast<lpuart_presc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_presc_r> other) const -> opsy::utility::clear_set<lpuart_presc_r> {return opsy::utility::clear_set<lpuart_presc_r>(lpuart_presc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prescaler() const -> prescaler_f {return prescaler_f(static_cast<uint8_t>(value_ >> prescaler_f::offset));}

	constexpr lpuart_presc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_presc_r other) const -> lpuart_presc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_presc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,lpuart_cr1_enabled_r> lpuart_cr1_enabled;
		opsy::utility::memory<uint32_t,lpuart_cr1_disabled_r> lpuart_cr1_disabled;
	};
	opsy::utility::memory<uint32_t,lpuart_cr2_r> lpuart_cr2;
	opsy::utility::memory<uint32_t,lpuart_cr3_r> lpuart_cr3;
	opsy::utility::memory<uint32_t,lpuart_brr_r> lpuart_brr;
	opsy::utility::padding<8> _p0;
	opsy::utility::memory<uint32_t,lpuart_rqr_r> lpuart_rqr;
	union {
		opsy::utility::memory<uint32_t,lpuart_isr_enabled_r> lpuart_isr_enabled;
		opsy::utility::memory<uint32_t,lpuart_isr_disabled_r> lpuart_isr_disabled;
	};
	opsy::utility::memory<uint32_t,lpuart_icr_r> lpuart_icr;
	opsy::utility::memory<uint32_t,lpuart_rdr_r> lpuart_rdr;
	opsy::utility::memory<uint32_t,lpuart_tdr_r> lpuart_tdr;
	opsy::utility::memory<uint32_t,lpuart_presc_r> lpuart_presc;
};

static_assert(std::is_standard_layout_v<lpuart_p>);
static_assert(offsetof(lpuart_p, lpuart_cr1_enabled) == 0);
static_assert(offsetof(lpuart_p, lpuart_cr1_disabled) == 0);
static_assert(offsetof(lpuart_p, lpuart_cr2) == 4);
static_assert(offsetof(lpuart_p, lpuart_cr3) == 8);
static_assert(offsetof(lpuart_p, lpuart_brr) == 12);
static_assert(offsetof(lpuart_p, lpuart_rqr) == 24);
static_assert(offsetof(lpuart_p, lpuart_isr_enabled) == 28);
static_assert(offsetof(lpuart_p, lpuart_isr_disabled) == 28);
static_assert(offsetof(lpuart_p, lpuart_icr) == 32);
static_assert(offsetof(lpuart_p, lpuart_rdr) == 36);
static_assert(offsetof(lpuart_p, lpuart_tdr) == 40);
static_assert(offsetof(lpuart_p, lpuart_presc) == 44);

inline lpuart_p& lpuart = *reinterpret_cast<lpuart_p*>(0x44002400);
inline lpuart_p& sec_lpuart1 = *reinterpret_cast<lpuart_p*>(0x54002400);

} // STM32H563

