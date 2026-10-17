#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * USB full speed
 */
class usb_p {
public:

/**
 * USB endpoint/channel X register
 */
class usb_chepxr_r {
public:

/**
 * endpoint/channel address Device mode Software must write in this field the 4-bit address used to identify the transactions directed to this endpoint. A value must be written before enabling the corresponding endpoint. Host mode Software must write in this field the 4-bit address used to identify the channel addressed by the host transaction.
 */
class ea_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ea_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Status bits, for transmission transfers Device mode These bits contain the information about the endpoint status, listed in . These bits can be toggled by the software to initialize their value. When the application software writes 0, the value remains unchanged, while writing 1 makes the bit value to toggle. Hardware sets the STATTX bits to NAK, when a correct transfer has occurred (VTTX = 1) corresponding to a IN or SETUP (control only) transaction addressed to this channel/endpoint. It then waits for the software to prepare the next set of data to be transmitted. Double-buffered bulk endpoints implement a special transaction flow control, which controls the status based on buffer availability condition (Refer to endpoints and usage in Device mode). If the endpoint is defined as isochronous, its status can only be 'VALID' or 'DISABLED'. Therefore, the hardware cannot change the status of the channel/endpoint/channel after a successful transaction. If the software sets the STATTX bits to 'STALL' or 'NAK' for an isochronous channel/endpoint, the USB peripheral behavior is not defined. These bits are read/write but they can be only toggled by writing 1. Host mode The STATTX bits contain the information about the channel status. Refer to for the full descriptions ('Host mode' descriptions). Whereas in Device mode, these bits contain the status that are given out on the following transaction, in Host mode they capture the status last received from the device. If a NAK is received, STATTX contains the value indicating NAK.
 */
class stattx_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr stattx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data toggle, for transmission transfers If the endpoint/channel is non-isochronous, this bit contains the required value of the data toggle bit (0 = DATA0, 1 = DATA1) for the next data packet to be transmitted. Hardware toggles this bit when the ACK handshake is received from the USB host, following a data packet transmission. If the endpoint/channel is defined as a control one, hardware sets this bit to 1 at the reception of a SETUP PID addressed to this endpoint. If the endpoint/channel is using the double buffer feature, this bit is used to support packet buffer swapping too (Refer to Device mode) If the endpoint/channel is isochronous, this bit is used to support packet buffer swapping since no data toggling is used for this sort of endpoints and only DATA0 packet are transmitted (refer to ). Hardware toggles this bit just after the end of data packet transmission, since no handshake is used for isochronous transfers. This bit can also be toggled by the software to initialize its value (mandatory when the endpoint/channel is not a control one) or to force a specific data toggle/packet buffer usage. When the application software writes 0, the value of DTOGTX remains unchanged, while writing 1 makes the bit value to toggle. This bit is read/write but it can only be toggled by writing 1.
 */
class dtogtx_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtogtx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Valid USB transaction transmitted Device mode This bit is set by the hardware when an IN transaction is successfully completed on this endpoint; the software can only clear this bit. If the CTRM bit in the USB_CNTR register is set accordingly, a generic interrupt condition is generated together with the endpoint related interrupt condition, which is always activated. A transaction ended with a NAK or STALL handshake does not set this bit, since no data is actually transferred, as in the case of protocol errors or data toggle mismatches. This bit is read/write but only 0 can be written. Host mode Same as VTRX behavior but for USB OUT and SETUP transactions.
 */
class vttx_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vttx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * endpoint/channel kind The meaning of this bit depends on the endpoint/channel type configured by the UTYPE bits. summarizes the different meanings. DBL_BUF: This bit is set by the software to enable the double-buffering feature for this bulk endpoint. The usage of double-buffered bulk endpoints is explained in Double-buffered endpoints and usage in Device mode. STATUS_OUT: This bit is set by the software to indicate that a status out transaction is expected: in this case all OUT transactions containing more than zero data bytes are answered 'STALL' instead of 'ACK'. This bit may be used to improve the robustness of the application to protocol errors during control transfers and its usage is intended for control endpoints only. When STATUS_OUT is reset, OUT transactions can have any number of bytes, as required.
 */
class epkind_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr epkind_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB type of transaction These bits configure the behavior of this endpoint/channel as described in Endpoint/channel type encoding. Channel0/Endpoint0 must always be a control endpoint/channel and each USB function must have at least one control endpoint/channel which has address 0, but there may be other control channels/endpoints if required. Only control channels/endpoints handle SETUP transactions, which are ignored by endpoints of other kinds. SETUP transactions cannot be answered with NAK or STALL. If a control endpoint/channel is defined as NAK, the USB peripheral does not answer, simulating a receive error, in the receive direction when a SETUP transaction is received. If the control endpoint/channel is defined as STALL in the receive direction, then the SETUP packet is accepted anyway, transferring data and issuing the CTR interrupt. The reception of OUT transactions is handled in the normal way, even if the endpoint/channel is a control one. Bulk and interrupt endpoints have very similar behavior and they differ only in the special feature available using the EPKIND configuration bit. The usage of isochronous channels/endpoints is explained in transfers in Device mode
 */
class utype_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr utype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Setup transaction completed Device mode This bit is read-only and it is set by the hardware when the last completed transaction is a SETUP. This bit changes its value only for control endpoints. It must be examined, in the case of a successful receive transaction (VTRX event), to determine the type of transaction occurred. To protect the interrupt service routine from the changes in SETUP bits due to next incoming tokens, this bit is kept frozen while VTRX bit is at 1; its state changes when VTRX is at 0. This bit is read-only. Host mode This bit is set by the software to send a SETUP transaction on a control endpoint. This bit changes its value only for control endpoints. It is cleared by hardware when the SETUP transaction is acknowledged and VTTX interrupt generated.
 */
class setup_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr setup_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status bits, for reception transfers Device mode These bits contain information about the endpoint status, which are listed in Reception status encoding on page 2492. These bits can be toggled by software to initialize their value. When the application software writes 0, the value remains unchanged, while writing 1 makes the bit value to toggle. Hardware sets the STATRX bits to NAK when a correct transfer has occurred (VTRX = 1) corresponding to a OUT or SETUP (control only) transaction addressed to this endpoint, so the software has the time to elaborate the received data before it acknowledges a new transaction. Double-buffered bulk endpoints implement a special transaction flow control, which control the status based upon buffer availability condition (Refer to endpoints and usage in Device mode). If the endpoint is defined as isochronous, its status can be only 'VALID' or 'DISABLED', so that the hardware cannot change the status of the endpoint after a successful transaction. If the software sets the STATRX bits to 'STALL' or 'NAK' for an isochronous endpoint, the USB peripheral behavior is not defined. These bits are read/write but they can be only toggled by writing 1. Host mode These bits are the host application controls to start, retry, or abort host transactions driven by the channel. These bits also contain information about the device answer to the last IN channel transaction and report the current status of the channel according to the following STATRX table of states: - DISABLE DISABLE value is reported in case of ACK acknowledge is received on a single-buffer channel. When in DISABLE state the channel is unused or not active waiting for application to restart it by writing VALID. Application can reset a VALID channel to DISABLE to abort a transaction. In this case the transaction is immediately removed from the host execution list. If the aborted transaction was already under execution it is regularly terminated on the USB but the relative VTRX interrupt is not generated. - VALID A host channel is actively trying to submit USB transaction to device only when in VALID state.VALID state can be set by software or automatically by hardware on a NAKED channel at the start of a new frame. When set to VALID, an host channel enters the host execution queue and waits permission from the host frame scheduler to submit its configured transaction. VALID value is also reported in case of ACK acknowledge is received on a double-buffered channel. In this case the channel remains active on the alternate buffer while application needs to read the current buffer and toggle DTOGTX. In case software is late in reading and the alternate buffer is not ready, the host channel is automatically suspended transparently to the application. The suspended double buffered channel is re-activated as soon as delay is recovered and DTOGTX is toggled. - NAK NAK value is reported in case of NAK acknowledge received. When in NAK state the channel is suspended and does not try to transmit. NAK state is moved to VALID by hardware at the start of the next frame, or software can change it to immediately retry transmission by writing it to VALID, or can disable it and abort the transaction by writing DISABLE - STALL STALL value is reported in case of STALL acknowledge received. When in STALL state the channel behaves as disabled. Application should not retry transmission but reset the USB and re-enumerate.
 */
class statrx_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr statrx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data Toggle, for reception transfers If the endpoint/channel is not isochronous, this bit contains the expected value of the data toggle bit (0 = DATA0, 1 = DATA1) for the next data packet to be received. Hardware toggles this bit, when the ACK handshake is sent following a data packet reception having a matching data PID value; if the endpoint is defined as a control one, hardware clears this bit at the reception of a SETUP PID received from host (in device) or acknowledged by device (in host). If the endpoint/channel is using the double-buffering feature this bit is used to support packet buffer swapping too (Refer to Device mode). If the endpoint/channel is isochronous, this bit is used only to support packet buffer swapping for data transmission since no data toggling is used for this kind of channels/endpoints and only DATA0 packet are transmitted (Refer to Isochronous transfers in Device mode). Hardware toggles this bit just after the end of data packet reception, since no handshake is used for isochronous transfers. This bit can also be toggled by the software to initialize its value (mandatory when the endpoint is not a control one) or to force specific data toggle/packet buffer usage. When the application software writes 0, the value of DTOGRX remains unchanged, while writing 1 makes the bit value toggle. This bit is read/write but it can be only toggled by writing 1.
 */
class dtogrx_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dtogrx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB valid transaction received Device mode This bit is set by the hardware when an OUT/SETUP transaction is successfully completed on this endpoint; the software can only clear this bit. If the CTRM bit in USB_CNTR register is set accordingly, a generic interrupt condition is generated together with the endpoint related interrupt condition, which is always activated. The type of occurred transaction, OUT or SETUP, can be determined from the SETUP bit described below. A transaction ended with a NAK or STALL handshake does not set this bit, since no data is actually transferred, as in the case of protocol errors or data toggle mismatches. This bit is read/write but only 0 can be written, writing 1 has no effect. Host mode This bit is set by the hardware when an IN transaction is successfully completed on this channel. The software can only clear this bit. If the CTRM bit in USB_CNTR register is set a generic interrupt condition is generated together with the channel related flag, which is always activated. - A transaction ended with a NAK sets this bit and NAK answer is reported to application reading the NAK state from the STATRX field of this register. One NAKed transaction keeps pending and is automatically retried by the host at the next frame, or the host can immediately retry by resetting STATRX state to VALID. - A transaction ended by STALL handshake sets this bit and the STALL answer is reported to application reading the STALL state from the STATRX field of this register. Host application should consequently disable the channel and re-enumerate. - A transaction ended with ACK handshake sets this bit If double buffering is disabled, ACK answer is reported by application reading the DISABLE state from the STATRX field of this register. Host application should read received data from USBRAM and re-arm the channel by writing VALID to the STATRX field of this register. If double buffering is enabled, ACK answer is reported by application reading VALID state from the STATRX field of this register. Host application should read received data from USBRAM and toggle the DTOGTX bit of this register. - A transaction ended with error sets this bit. Errors can be seen via the bits ERR_RX (host mode only). This bit is read/write but only 0 can be written, writing 1 has no effect.
 */
class vtrx_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vtrx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Host mode Device address assigned to the endpoint during the enumeration process.
 */
class devaddr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr devaddr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Host mode This bit is set by the hardware when a device responds with a NAK. Software can use this bit to monitor the number of NAKs received from a device.
 */
class nak_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nak_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low speed endpoint host with HUB only Host mode This bit is set by the software to send an LS transaction to the corresponding endpoint.
 */
class ls_ep_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ls_ep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received error for an OUT/SETUP transaction Host mode This bit is set by the hardware when an error (for example no answer by the device, CRC error, bit stuffing error, framing format violation, etc.) has occurred during an OUT or SETUP transaction on this channel. The software can only clear this bit. If the ERRM bit in USB_CNTR register is set, a generic interrupt condition is generated together with the channel related flag, which is always activated.
 */
class err_tx_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr err_tx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received error for an IN transaction Host mode This bit is set by the hardware when an error (for example no answer by the device, CRC error, bit stuffing error, framing format violation, etc.) has occurred during an IN transaction on this channel. The software can only clear this bit. If the ERRM bit in USB_CNTR register is set, a generic interrupt condition is generated together with the channel related flag, which is always activated.
 */
class err_rx_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr err_rx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Three errors for an OUT or SETUP transaction Host mode This bit is set by the hardware when 3 consecutive transaction errors occurred on the USB bus for an OUT transaction. THREE_ERR_TX is not generated for isochronous transactions. The software can only clear this bit. Coding of the received error:
 */
class three_err_tx_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr three_err_tx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Three errors for an IN transaction Host mode This bit is set by the hardware when 3 consecutive transaction errors occurred on the USB bus for an IN transaction. THREE_ERR_RX is not generated for isochronous transactions. The software can only clear this bit. Coding of the received error:
 */
class three_err_rx_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr three_err_rx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ea() const -> ea_f {return ea_f(static_cast<uint8_t>(value_ >> ea_f::offset));}
	[[nodiscard]] constexpr auto stattx() const -> stattx_f {return stattx_f(static_cast<uint8_t>(value_ >> stattx_f::offset));}
	[[nodiscard]] constexpr auto dtogtx() const -> dtogtx_f {return dtogtx_f((value_ & dtogtx_f::mask) != 0);}
	[[nodiscard]] constexpr auto vttx() const -> vttx_f {return vttx_f((value_ & vttx_f::mask) != 0);}
	[[nodiscard]] constexpr auto epkind() const -> epkind_f {return epkind_f((value_ & epkind_f::mask) != 0);}
	[[nodiscard]] constexpr auto utype() const -> utype_f {return utype_f(static_cast<uint8_t>(value_ >> utype_f::offset));}
	[[nodiscard]] constexpr auto setup() const -> setup_f {return setup_f((value_ & setup_f::mask) != 0);}
	[[nodiscard]] constexpr auto statrx() const -> statrx_f {return statrx_f(static_cast<uint8_t>(value_ >> statrx_f::offset));}
	[[nodiscard]] constexpr auto dtogrx() const -> dtogrx_f {return dtogrx_f((value_ & dtogrx_f::mask) != 0);}
	[[nodiscard]] constexpr auto vtrx() const -> vtrx_f {return vtrx_f((value_ & vtrx_f::mask) != 0);}
	[[nodiscard]] constexpr auto devaddr() const -> devaddr_f {return devaddr_f(static_cast<uint8_t>(value_ >> devaddr_f::offset));}
	[[nodiscard]] constexpr auto nak() const -> nak_f {return nak_f((value_ & nak_f::mask) != 0);}
	[[nodiscard]] constexpr auto ls_ep() const -> ls_ep_f {return ls_ep_f((value_ & ls_ep_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_tx() const -> err_tx_f {return err_tx_f((value_ & err_tx_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_rx() const -> err_rx_f {return err_rx_f((value_ & err_rx_f::mask) != 0);}
	[[nodiscard]] constexpr auto three_err_tx() const -> three_err_tx_f {return three_err_tx_f(static_cast<uint8_t>(value_ >> three_err_tx_f::offset));}
	[[nodiscard]] constexpr auto three_err_rx() const -> three_err_rx_f {return three_err_rx_f(static_cast<uint8_t>(value_ >> three_err_rx_f::offset));}

	constexpr usb_chepxr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_chepxr_r other) const -> usb_chepxr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_chepxr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * 
 */
class usb_cntr_r {
public:

/**
 * USB Reset Software can set this bit to reset the USB core, exactly as it happens when receiving a RESET signaling on the USB.The USB peripheral, in response to a RESET, resets its internal protocol state machine. Reception and transmission are disabled until the RST_DCON bit is cleared. All configuration registers do not reset: the microcontroller must explicitly clear these registers (this is to ensure that the RST_DCON interrupt can be safely delivered, and any transaction immediately followed by a RESET can be completed). The function address and endpoint registers are reset by an USB reset event. Software sets this bit to drive USB reset state on the bus and initialize the device. USB reset terminates as soon as this bit is cleared by software.
 */
class usbrst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr usbrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Power down This bit is used to completely switch off all USB-related analog parts if it is required to completely disable the USB peripheral for any reason. When this bit is set, the USB peripheral is disconnected from the transceivers and it cannot be used.
 */
class pdwn_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pdwn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend state effective This bit is set by hardware as soon as the suspend state entered through the SUSPEN control gets internally effective. In this state USB activity is suspended, USB clock is gated, transceiver is set in low power mode by disabling the differential receiver. Only asynchronous wakeup logic and single ended receiver is kept alive to detect remote wakeup or resume events. Software must poll this bit to confirm it to be set before any STOP mode entry. This bit is cleared by hardware simultaneously to the WAKEUP flag being set.
 */
class susprdy_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr susprdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend state enable Software can set this bit when the SUSP interrupt is received, which is issued when no traffic is received by the USB peripheral for 3 ms. Software can also set this bit when the L1REQ interrupt is received with positive acknowledge sent. As soon as the suspend state is propagated internally all device activity is stopped, USB clock is gated, USB transceiver is set into low power mode and the SUSPRDY bit is set by hardware. In the case that device application wants to pursue more aggressive power saving by stopping the USB clock source and by moving the microcontroller to stop mode, as in the case of bus powered device application, it must first wait few cycles to see the SUSPRDY = 1 acknowledge the suspend request. This bit is cleared by hardware simultaneous with the WAKEUP flag set. Software can set this bit when host application has nothing scheduled for the next frames and wants to enter long term power saving. When set, it stops immediately SOF generation and any other host activity, gates the USB clock and sets the transceiver in low power mode. If any USB transaction is on-going at the time SUSPEN is set, suspend is entered at the end of the current transaction. As soon as suspend state is propagated internally and gets effective the SUSPRDY bit is set. In the case that host application wants to pursue more aggressive power saving by stopping the USB clock source and by moving the micro-controller to STOP mode, it must first wait few cycles to see SUSPRDY=1 acknowledge to the suspend request. This bit is cleared by hardware simultaneous with the WAKEUP flag set.
 */
class suspen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr suspen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * L2 remote wakeup / resume driver Device mode The microcontroller can set this bit to send remote wake-up signaling to the host. It must be activated, according to USB specifications, for no less than 1 ms and no more than 15 ms after which the host PC is ready to drive the resume sequence up to its end. Host mode Software sets this bit to send resume signaling to the device. Software clears this bit to send end of resume to device and restart SOF generation. In the context of remote wake up, this bit is to be set following the WAKEUP interrupt.
 */
class l2res_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l2res_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * L1 remote wakeup / resume driver Device mode Software sets this bit to send a LPM L1 50 us remote wakeup signaling to the host. After the signaling ends, this bit is cleared by hardware.
 */
class l1res_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1res_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM L1 state request interrupt mask
 */
class l1reqm_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1reqm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected start of frame interrupt mask
 */
class esofm_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr esofm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start of frame interrupt mask
 */
class sofm_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sofm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB reset request (Device mode) or device connect/disconnect (Host mode) interrupt mask
 */
class rst_dconm_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rst_dconm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend mode interrupt mask
 */
class suspm_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup interrupt mask
 */
class wkupm_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wkupm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error interrupt mask
 */
class errm_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr errm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Packet memory area over / underrun interrupt mask
 */
class pmaovrm_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pmaovrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Correct transfer interrupt mask
 */
class ctrm_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 512 byte threshold interrupt mask
 */
class thr512m_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr thr512m_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device disconnection mask Host mode
 */
class ddiscm_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddiscm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HOST mode HOST bit selects betweens host or device USB mode of operation. It must be set before enabling the USB peripheral by the function enable bit.
 */
class host_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr host_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto usbrst() const -> usbrst_f {return usbrst_f((value_ & usbrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto pdwn() const -> pdwn_f {return pdwn_f((value_ & pdwn_f::mask) != 0);}
	[[nodiscard]] constexpr auto susprdy() const -> susprdy_f {return susprdy_f((value_ & susprdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspen() const -> suspen_f {return suspen_f((value_ & suspen_f::mask) != 0);}
	[[nodiscard]] constexpr auto l2res() const -> l2res_f {return l2res_f((value_ & l2res_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1res() const -> l1res_f {return l1res_f((value_ & l1res_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1reqm() const -> l1reqm_f {return l1reqm_f((value_ & l1reqm_f::mask) != 0);}
	[[nodiscard]] constexpr auto esofm() const -> esofm_f {return esofm_f((value_ & esofm_f::mask) != 0);}
	[[nodiscard]] constexpr auto sofm() const -> sofm_f {return sofm_f((value_ & sofm_f::mask) != 0);}
	[[nodiscard]] constexpr auto rst_dconm() const -> rst_dconm_f {return rst_dconm_f((value_ & rst_dconm_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspm() const -> suspm_f {return suspm_f((value_ & suspm_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkupm() const -> wkupm_f {return wkupm_f((value_ & wkupm_f::mask) != 0);}
	[[nodiscard]] constexpr auto errm() const -> errm_f {return errm_f((value_ & errm_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmaovrm() const -> pmaovrm_f {return pmaovrm_f((value_ & pmaovrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctrm() const -> ctrm_f {return ctrm_f((value_ & ctrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto thr512m() const -> thr512m_f {return thr512m_f((value_ & thr512m_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddiscm() const -> ddiscm_f {return ddiscm_f((value_ & ddiscm_f::mask) != 0);}
	[[nodiscard]] constexpr auto host() const -> host_f {return host_f((value_ & host_f::mask) != 0);}

	constexpr usb_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_cntr_r other) const -> usb_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11; // 3 0x3

private:
	uint32_t value_;
};

/**
 * USB interrupt status register 
 */
class usb_istr_r {
public:

/**
 * Device Endpoint / host channel identification number These bits are written by the hardware according to the host channel or device endpoint number, which generated the interrupt request. If several endpoint/channel transactions are pending, the hardware writes the identification number related to the endpoint/channel having the highest priority defined in the following way: two levels are defined, in order of priority: isochronous and double-buffered bulk channels/endpoints are considered first and then the others are examined. If more than one endpoint/channel from the same set is requesting an interrupt, the IDN bits in USB_ISTR register are assigned according to the lowest requesting register, CHEP0R having the highest priority followed by CHEP1R and so on. The application software can assign a register to each endpoint/channel according to this priority scheme, so as to order the concurring endpoint/channel requests in a suitable way. These bits are read only.
 */
class idn_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr idn_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_istr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Direction of transaction This bit is written by the hardware according to the direction of the successful transaction, which generated the interrupt request. If DIR bit = 0, VTTX bit is set in the USB_CHEPnR register related to the interrupting endpoint. The interrupting transaction is of IN type (data transmitted by the USB peripheral to the host PC). If DIR bit = 1, VTRX bit or both VTTX/VTRX are set in the USB_CHEPnR register related to the interrupting endpoint. The interrupting transaction is of OUT type (data received by the USB peripheral from the host PC) or two pending transactions are waiting to be processed. This information can be used by the application software to access the USB_CHEPnR bits related to the triggering transaction since it represents the direction having the interrupt pending. This bit is read-only.
 */
class dir_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM L1 state request Device mode This bit is set by the hardware when LPM command to enter the L1 state is successfully received and acknowledged. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class l1req_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1req_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected start of frame Device mode This bit is set by the hardware when an SOF packet is expected but not received. The host sends an SOF packet each 1 ms, but if the device does not receive it properly, the suspend timer issues this interrupt. If three consecutive ESOF interrupts are generated (for example three SOF packets are lost) without any traffic occurring in between, a SUSP interrupt is generated. This bit is set even when the missing SOF packets occur while the suspend timer is not yet locked. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class esof_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr esof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start of frame This bit signals the beginning of a new USB frame and it is set when a SOF packet arrives through the USB bus. The interrupt service routine may monitor the SOF events to have a 1 ms synchronization event to the USB host and to safely read the USB_FNR register which is updated at the SOF packet reception (this could be useful for isochronous applications). This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class sof_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB reset request (Device mode) or device connect/disconnect (Host mode) Device mode This bit is set by hardware when an USB reset is released by the host and the bus returns to idle. USB reset state is internally detected after the sampling of 60 consecutive SE0 cycles. Host mode This bit is set by hardware when device connection or device disconnection is detected. Device connection is signaled after J state is sampled for 22 cycles consecutively from unconnected state. Device disconnection is signaled after SE0 state is seen for 22 bit times consecutively from connected state.
 */
class rst_dcon_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rst_dcon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend mode request Device mode This bit is set by the hardware when no traffic has been received for 3 ms, indicating a suspend mode request from the USB bus. The suspend condition check is enabled immediately after any USB reset and it is disabled by the hardware when the suspend mode is active (SUSPEN=1) until the end of resume sequence. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class susp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr susp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup This bit is set to 1 by the hardware when, during suspend mode, activity is detected that wakes up the USB peripheral. This event asynchronously clears the SUSPRDY bit in the CTLR register and activates the USB_WAKEUP line, which can be used to notify the rest of the device (for example wakeup unit) about the start of the resume process. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class wkup_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wkup_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error This flag is set whenever one of the errors listed below has occurred: NANS: No ANSwer. The timeout for a host response has expired. CRC: Cyclic redundancy check error. One of the received CRCs, either in the token or in the data, was wrong. BST: Bit stuffing error. A bit stuffing error was detected anywhere in the PID, data, and/or CRC. FVIO: Framing format violation. A non-standard frame was received (EOP not in the right place, wrong token sequence, etc.). The USB software can usually ignore errors, since the USB peripheral and the PC host manage retransmission in case of errors in a fully transparent way. This interrupt can be useful during the software development phase, or to monitor the quality of transmission over the USB bus, to flag possible problems to the user (for example loose connector, too noisy environment, broken conductor in the USB cable and so on). This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class err_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr err_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Packet memory area over / underrun This bit is set if the microcontroller has not been able to respond in time to an USB memory request. The USB peripheral handles this event in the following way: During reception an ACK handshake packet is not sent, during transmission a bit-stuff error is forced on the transmitted stream; in both cases the host retries the transaction. The PMAOVR interrupt should never occur during normal operations. Since the failed transaction is retried by the host, the application software has the chance to speed-up device operations during this interrupt handling, to be ready for the next transaction retry; however this does not happen during isochronous transfers (no isochronous transaction is anyway retried) leading to a loss of data in this case. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class pmaovr_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pmaovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Completed transfer in host mode This bit is set by the hardware to indicate that an endpoint/channel has successfully completed a transaction; using DIR and IDN bits software can determine which endpoint/channel requested the interrupt. This bit is read-only.
 */
class ctr_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 512 byte threshold interrupt This bit is set to 1 by the hardware when 512 bytes have been transmitted or received during isochronous transfers. This bit is read/write but only 0 can be written and writing 1 has no effect. Note that no information is available to indicate the associated channel/endpoint, however in practice only one ISO endpoint/channel with such large packets can be supported, so that channel.
 */
class thr512_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr thr512_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device connection Host mode This bit is set when a device connection is detected. This bit is read/write but only 0 can be written and writing 1 has no effect.
 */
class ddisc_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddisc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device connection status Host mode: This bit contains information about device connection status. It is set by hardware when a LS/FS device is attached to the host while it is reset when the device is disconnected.
 */
class dcon_stat_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcon_stat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low speed device connected Host mode: This bit is set by hardware when an LS device connection is detected. Device connection is signaled after LS J-state is sampled for 22 consecutive cycles of the USB clock (48 MHz) from the unconnected state.
 */
class ls_dcon_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ls_dcon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto idn() const -> idn_f {return idn_f(static_cast<uint8_t>(value_ >> idn_f::offset));}
	[[nodiscard]] constexpr auto dir() const -> dir_f {return dir_f((value_ & dir_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1req() const -> l1req_f {return l1req_f((value_ & l1req_f::mask) != 0);}
	[[nodiscard]] constexpr auto esof() const -> esof_f {return esof_f((value_ & esof_f::mask) != 0);}
	[[nodiscard]] constexpr auto sof() const -> sof_f {return sof_f((value_ & sof_f::mask) != 0);}
	[[nodiscard]] constexpr auto rst_dcon() const -> rst_dcon_f {return rst_dcon_f((value_ & rst_dcon_f::mask) != 0);}
	[[nodiscard]] constexpr auto susp() const -> susp_f {return susp_f((value_ & susp_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkup() const -> wkup_f {return wkup_f((value_ & wkup_f::mask) != 0);}
	[[nodiscard]] constexpr auto err() const -> err_f {return err_f((value_ & err_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmaovr() const -> pmaovr_f {return pmaovr_f((value_ & pmaovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctr() const -> ctr_f {return ctr_f((value_ & ctr_f::mask) != 0);}
	[[nodiscard]] constexpr auto thr512() const -> thr512_f {return thr512_f((value_ & thr512_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddisc() const -> ddisc_f {return ddisc_f((value_ & ddisc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcon_stat() const -> dcon_stat_f {return dcon_stat_f((value_ & dcon_stat_f::mask) != 0);}
	[[nodiscard]] constexpr auto ls_dcon() const -> ls_dcon_f {return ls_dcon_f((value_ & ls_dcon_f::mask) != 0);}

	constexpr usb_istr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_istr_r other) const -> usb_istr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_istr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB frame number register 
 */
class usb_fnr_r {
public:

/**
 * Frame number This bit field contains the 11-bits frame number contained in the last received SOF packet. The frame number is incremented for every frame sent by the host and it is useful for isochronous transfers. This bit field is updated on the generation of an SOF interrupt.
 */
class fn_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fn_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usb_fnr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Lost SOF Device mode These bits are written by the hardware when an ESOF interrupt is generated, counting the number of consecutive SOF packets lost. At the reception of an SOF packet, these bits are cleared.
 */
class lsof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lsof_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_fnr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Locked Device mode This bit is set by the hardware when at least two consecutive SOF packets have been received after the end of an USB reset condition or after the end of an USB resume sequence. Once locked, the frame timer remains in this state until an USB reset or USB suspend event occurs.
 */
class lck_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive dataline status This bit can be used to observe the status of received data minus upstream port data line. It can be used during end-of-suspend routines to help determining the wakeup event.
 */
class rxdm_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data + line status This bit can be used to observe the status of received data plus upstream port data line. It can be used during end-of-suspend routines to help determining the wakeup event.
 */
class rxdp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fn() const -> fn_f {return fn_f(static_cast<uint16_t>(value_ >> fn_f::offset));}
	[[nodiscard]] constexpr auto lsof() const -> lsof_f {return lsof_f(static_cast<uint8_t>(value_ >> lsof_f::offset));}
	[[nodiscard]] constexpr auto lck() const -> lck_f {return lck_f((value_ & lck_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdm() const -> rxdm_f {return rxdm_f((value_ & rxdm_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdp() const -> rxdp_f {return rxdp_f((value_ & rxdp_f::mask) != 0);}

	constexpr usb_fnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_fnr_r other) const -> usb_fnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_fnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB_DADDR
 */
class usb_daddr_r {
public:

/**
 * Device address Device mode These bits contain the USB function address assigned by the host PC during the enumeration process. Both this field and the endpoint/channel address (EA) field in the associated USB_CHEPnR register must match with the information contained in a USB token in order to handle a transaction to the required endpoint. Host mode These bits contain the address transmitted with the LPM transaction
 */
class add_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_daddr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_daddr_r>() const {return opsy::utility::clear_set<usb_daddr_r>(mask, *this);}
	constexpr auto operator|(usb_daddr_r other) const -> usb_daddr_r { return static_cast<usb_daddr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_daddr_r> other) const -> opsy::utility::clear_set<usb_daddr_r> {return opsy::utility::clear_set<usb_daddr_r>(usb_daddr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable function This bit is set by the software to enable the USB Device. The address of this device is contained in the following ADD[6:0] bits. If this bit is at 0 no transactions are handled, irrespective of the settings of USB_CHEPnR registers.
 */
class ef_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_daddr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_daddr_r>() const {return opsy::utility::clear_set<usb_daddr_r>(mask, *this);}
	constexpr auto operator|(usb_daddr_r other) const -> usb_daddr_r { return static_cast<usb_daddr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_daddr_r> other) const -> opsy::utility::clear_set<usb_daddr_r> {return opsy::utility::clear_set<usb_daddr_r>(usb_daddr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}
	[[nodiscard]] constexpr auto ef() const -> ef_f {return ef_f((value_ & ef_f::mask) != 0);}

	constexpr usb_daddr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_daddr_r other) const -> usb_daddr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_daddr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB_LPMCSR
 */
class usb_lpmcsr_r {
public:

/**
 * LPM support enable Device mode This bit is set by the software to enable the LPM support within the USB Device. If this bit is at 0 no LPM transactions are handled.
 */
class lpmen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM token acknowledge enable Device mode: The NYET/ACK is returned only on a successful LPM transaction: No errors in both the EXT token and the LPM token (else ERROR) A valid bLinkState = 0001B (L1) is received (else STALL)
 */
class lpmack_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpmack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * bRemoteWake value Device mode This bit contains the bRemoteWake value received with last ACKed LPM Token
 */
class remwake_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr remwake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BESL value Device mode These bits contain the BESL value received with last ACKed LPM Token
 */
class besl_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr besl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lpmen() const -> lpmen_f {return lpmen_f((value_ & lpmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpmack() const -> lpmack_f {return lpmack_f((value_ & lpmack_f::mask) != 0);}
	[[nodiscard]] constexpr auto remwake() const -> remwake_f {return remwake_f((value_ & remwake_f::mask) != 0);}
	[[nodiscard]] constexpr auto besl() const -> besl_f {return besl_f(static_cast<uint8_t>(value_ >> besl_f::offset));}

	constexpr usb_lpmcsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_lpmcsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB_BCDR
 */
class usb_bcdr_r {
public:

/**
 * Battery charging detector (BCD) enable Device mode This bit is set by the software to enable the BCD support within the USB Device. When enabled, the USB PHY is fully controlled by BCD and cannot be used for normal communication. Once the BCD discovery is finished, the BCD should be placed in OFF mode by clearing this bit to 0 in order to allow the normal USB operation.
 */
class bcden_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bcden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data contact detection (DCD) mode enable Device mode This bit is set by the software to put the BCD into DCD mode. Only one detection mode (DCD, PD, SD or OFF) should be selected to work correctly.
 */
class dcden_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Primary detection (PD) mode enable Device mode This bit is set by the software to put the BCD into PD mode. Only one detection mode (DCD, PD, SD or OFF) should be selected to work correctly.
 */
class pden_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Secondary detection (SD) mode enable Device mode This bit is set by the software to put the BCD into SD mode. Only one detection mode (DCD, PD, SD or OFF) should be selected to work correctly.
 */
class sden_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data contact detection (DCD) status Device mode This bit gives the result of DCD.
 */
class dcdet_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Primary detection (PD) status Device mode This bit gives the result of PD.
 */
class pdet_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Secondary detection (SD) status Device mode This bit gives the result of SD.
 */
class sdet_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DM pull-up detection status Device mode This bit is active only during PD and gives the result of comparison between DM voltage level and VLGC threshold. In normal situation, the DM level should be below this threshold. If it is above, it means that the DM is externally pulled high. This can be caused by connection to a PS2 port (which pulls-up both DP and DM lines) or to some proprietary charger not following the BCD specification.
 */
class ps2det_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ps2det_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DP pull-up / DPDM pull-down Device mode This bit is set by software to enable the embedded pull-up on DP line. Clearing it to 0 can be used to signal disconnect to the host when needed by the user software. Host mode This bit is set by software to enable the embedded pull-down on DP and DM lines.
 */
class dppu_dpd_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dppu_dpd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bcden() const -> bcden_f {return bcden_f((value_ & bcden_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcden() const -> dcden_f {return dcden_f((value_ & dcden_f::mask) != 0);}
	[[nodiscard]] constexpr auto pden() const -> pden_f {return pden_f((value_ & pden_f::mask) != 0);}
	[[nodiscard]] constexpr auto sden() const -> sden_f {return sden_f((value_ & sden_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcdet() const -> dcdet_f {return dcdet_f((value_ & dcdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto pdet() const -> pdet_f {return pdet_f((value_ & pdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdet() const -> sdet_f {return sdet_f((value_ & sdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps2det() const -> ps2det_f {return ps2det_f((value_ & ps2det_f::mask) != 0);}
	[[nodiscard]] constexpr auto dppu_dpd() const -> dppu_dpd_f {return dppu_dpd_f((value_ & dppu_dpd_f::mask) != 0);}

	constexpr usb_bcdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_bcdr_r other) const -> usb_bcdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_bcdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep0r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep1r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep2r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep3r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep4r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep5r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep6r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep7r;
	opsy::utility::padding<32> _p0;
	opsy::utility::memory<uint32_t,usb_cntr_r> usb_cntr;
	opsy::utility::memory<uint32_t,usb_istr_r> usb_istr;
	opsy::utility::memory<uint32_t,usb_fnr_r> usb_fnr;
	opsy::utility::memory<uint32_t,usb_daddr_r> usb_daddr;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,usb_lpmcsr_r> usb_lpmcsr;
	opsy::utility::memory<uint32_t,usb_bcdr_r> usb_bcdr;
};

static_assert(std::is_standard_layout_v<usb_p>);
static_assert(offsetof(usb_p, usb_chep0r) == 0);
static_assert(offsetof(usb_p, usb_chep1r) == 4);
static_assert(offsetof(usb_p, usb_chep2r) == 8);
static_assert(offsetof(usb_p, usb_chep3r) == 12);
static_assert(offsetof(usb_p, usb_chep4r) == 16);
static_assert(offsetof(usb_p, usb_chep5r) == 20);
static_assert(offsetof(usb_p, usb_chep6r) == 24);
static_assert(offsetof(usb_p, usb_chep7r) == 28);
static_assert(offsetof(usb_p, usb_cntr) == 64);
static_assert(offsetof(usb_p, usb_istr) == 68);
static_assert(offsetof(usb_p, usb_fnr) == 72);
static_assert(offsetof(usb_p, usb_daddr) == 76);
static_assert(offsetof(usb_p, usb_lpmcsr) == 84);
static_assert(offsetof(usb_p, usb_bcdr) == 88);

inline usb_p& sec_usb = *reinterpret_cast<usb_p*>(0x50016000);
inline usb_p& usb = *reinterpret_cast<usb_p*>(0x40016000);

} // STM32H563

