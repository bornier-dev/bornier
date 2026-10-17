#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Ethernet media access control
 */
class eth_p {
public:

/**
 * Operating mode configuration register
 */
class eth_maccr_r {
public:

/**
 * Receiver Enable When this bit is set, the Rx state machine of the MAC is enabled for receiving packets from the MII interface. When this bit is reset, the MAC Rx state machine is disabled after it completes the reception of the current packet. The Rx state machine does not receive any more packets from the MII interface.
 */
class re_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter Enable When this bit is set, the Tx state machine of the MAC is enabled for transmission on the MII interface. When this bit is reset, the MAC Tx state machine is disabled after it completes the transmission of the current packet. The Tx state machine does not transmit any more packets.
 */
class te_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Preamble Length for Transmit packets These bits control the number of preamble bytes that are added to the beginning of every Tx packet. The preamble reduction occurs only when the MAC is operating in the Full-duplex mode.
 */
class prelen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prelen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Deferral Check When this bit is set, the deferral check function is enabled in the MAC. The MAC issues a Packet Abort status, along with the excessive deferral error bit set in the Tx packet status, when the Tx state machine is deferred for more than 24,288 bit times in 10 or 100 Mbps mode. Deferral begins when the transmitter is ready to transmit, but it is prevented because of an active carrier sense signal (CRS) on MII. The defer time is not cumulative. For example, if the transmitter defers for 10,000 bit times because the CRS signal is active and the CRS signal becomes inactive, the transmitter transmits and collision happens. Because of collision, the transmitter needs to back off and then defer again after back off completion. In such a scenario, the deferral timer is reset to 0, and it is restarted. When this bit is reset, the deferral check function is disabled and the MAC defers until the CRS signal goes inactive. This bit is applicable only in the Half-duplex mode.
 */
class dc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Back-Off Limit The back-off limit determines the random integer number (r) of slot time delays (512 bit times for 10/100 Mbps) for which the MAC waits before rescheduling a transmission attempt during retries after a collision: where n = retransmission attempt The random integer r takes the value in the range 0 = r 2^k. This bit is applicable only in the Half-duplex mode.
 */
class bl_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr bl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Disable Retry When this bit is set, the MAC attempts only one transmission. When a collision occurs on the MII interface, the MAC ignores the current packet transmission and reports a Packet Abort with excessive collision error in the Tx packet status. When this bit is reset, the MAC retries based on the settings of the BL field. This bit is applicable only in the Half-duplex mode.
 */
class dr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable Carrier Sense During Transmission When this bit is set, the MAC transmitter ignores the MII CRS signal during packet transmission in the Half-duplex mode. As a result, no errors are generated because of Loss of Carrier or No Carrier during transmission. When this bit is reset, the MAC transmitter generates errors because of Carrier Sense. The MAC can even abort the transmission.
 */
class dcrs_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcrs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable Receive Own When this bit is set, the MAC disables the reception of packets when the ETH_TX_EN is asserted in the Half-duplex mode. When this bit is reset, the MAC receives all packets given by the PHY. This bit is not applicable in the Full-duplex mode. This bit is reserved and read-only (RO) with default value in the Full-duplex-only configurations.
 */
class do_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr do_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Carrier Sense Before Transmission in Full-duplex mode When this bit is set, the MAC transmitter checks the CRS signal before packet transmission in the Full-duplex mode. The MAC starts the transmission only when the CRS signal is low. When this bit is reset, the MAC transmitter ignores the status of the CRS signal.
 */
class ecrsfd_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ecrsfd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Loopback Mode When this bit is set, the MAC operates in the loopback mode at MII. The MII Rx clock input (eth_mii_rx_clk) is required for the loopback to work properly. This is because the Tx clock is not internally looped back.
 */
class lm_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Duplex Mode When this bit is set, the MAC operates in the Full-duplex mode in which it can transmit and receive simultaneously.
 */
class dm_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Speed This bit selects the speed in the 10/100 Mbps mode:
 */
class fes_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fes_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Jumbo Packet Enable When this bit is set, the MAC allows jumbo packets of 9,018 bytes (9,022 bytes for VLAN tagged packets) without reporting a giant packet error in the Rx packet status. For more information about how the setting of this bit and the JE bit impact the Giant packet status, see Table679: Giant Packet Status based on S2KP and JE Bits.
 */
class je_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr je_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Jabber Disable When this bit is set, the MAC disables the jabber timer on the transmitter. The MAC can transfer packets of up to 16,383 bytes. When this bit is reset, if the application sends more than 2,048 bytes of data (10,240 if JE is set high) during transmission, the MAC does not send rest of the bytes in that packet.
 */
class jd_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog Disable When this bit is set, the MAC disables the watchdog timer on the receiver. The MAC can receive packets of up to 16,383 bytes. When this bit is reset, the MAC does not allow more than 2,048 bytes (10,240 if JE is set high) of the packet being received. The MAC cuts off any bytes received after 2,048 bytes.
 */
class wd_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic Pad or CRC Stripping When this bit is set, the MAC strips the Pad or FCS field on the incoming packets only if the value of the length field is less than 1,536 bytes. All received packets with length field greater than or equal to 1,536 bytes are passed to the application without stripping the Pad or FCS field. When this bit is reset, the MAC passes all incoming packets to the application, without any modification. Note: For information about how the settings of CST bit and this bit impact the packet length, see Table680: Packet Length based on the CST and ACS bits.
 */
class acs_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr acs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRC stripping for Type packets When this bit is set, the last four bytes (FCS) of all packets of Ether type (type field greater than 1,536) are stripped and dropped before forwarding the packet to the application. This function is not valid when the IP Checksum Engine (Type 1) is enabled in the MAC receiver. This function is valid when Type 2 Checksum Offload Engine is enabled. Note: For information about how the settings of the ACS bit and this bit impact the packet length, see Table680: Packet Length based on the CST and ACS bits.
 */
class cst_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IEEE 802.3as Support for 2K Packets When this bit is set, the MAC considers all packets with up to 2,000 bytes length as normal packets. When the JE bit is not set, the MAC considers all received packets of size more than 2K bytes as Giant packets. When this bit is reset and the JE bit is not set, the MAC considers all received packets of size more than 1,518 bytes (1,522 bytes for tagged) as giant packets. For more information about how the setting of this bit and the JE bit impact the Giant packet status, see Table679: Giant Packet Status based on S2KP and JE Bits. Note: When the JE bit is set, setting this bit has no effect on the giant packet status.
 */
class s2kp_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr s2kp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Giant Packet Size Limit Control Enable When this bit is set, the MAC considers the value in GPSL field in ETH_MACECR register to declare a received packet as Giant packet. This field must be programmed to more than 1,518 bytes. Otherwise, the MAC considers 1,518 bytes as giant packet limit. When this bit is reset, the MAC considers a received packet as Giant packet when its size is greater than 1,518 bytes (1522 bytes for tagged packet). The watchdog timeout limit, Jumbo Packet Enable and 2K Packet Enable have higher precedence over this bit, that is the MAC considers a received packet as Giant packet when its size is greater than 9,018 bytes (9,022 bytes for tagged packet) with Jumbo Packet Enabled and greater than 2,000 bytes with 2K Packet Enabled. The watchdog timeout, if enabled, terminates the received packet when watchdog limit is reached. Therefore, the programmed giant packet limit should be less than the watchdog limit to get the giant packet status.
 */
class gpslce_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr gpslce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Inter-Packet Gap These bits control the minimum IPG between packets during transmission. ... This range of minimum IPG is valid in Full-duplex mode. In the Half-duplex mode, the minimum IPG can be configured only for 64-bit times (IPG = 100). Lower values are not considered. When a JAM pattern is being transmitted because of backpressure activation, the MAC does not consider the minimum IPG. The above function (IPG less than 96 bit times) is valid only when EIPGEN bit in ETH_MACECR register is reset. When EIPGEN is set, then the minimum IPG (greater than 96 bit times) is controlled as per the description given in EIPG field in ETH_MACECR register.
 */
class ipg_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ipg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Checksum Offload When set, this bit enables the IPv4 header checksum checking and IPv4 or IPv6 TCP, UDP, or ICMP payload checksum checking. When this bit is reset, the COE function in the receiver is disabled. The Layer 3 and Layer 4 Packet Filter feature automatically selects the IPC Full Checksum Offload Engine on the Receive side. When this feature is enabled, you must set the IPC bit.
 */
class ipc_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ipc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Source Address Insertion or Replacement Control This field controls the source address insertion or replacement for all transmitted packets. Bit 30 specifies which MAC Address register (0 or 1) is used for source address insertion or replacement based on the values of Bits[29:28]: Others: Reserved, must not be used. Note: Changes to this field take effect only on the start of a packet. If you write to this register field when a packet is being transmitted, only the subsequent packet can use the updated value, that is, the current packet does not use the updated value.
 */
class sarc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sarc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ARP Offload Enable When this bit is set, the MAC can recognize an incoming ARP request packet and schedules the ARP packet for transmission. It forwards the ARP packet to the application and also indicate the events in the RxStatus. When this bit is reset, the MAC receiver does not recognize any ARP packet and indicates them as Type frame in the RxStatus.
 */
class arpen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr arpen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccr_r>() const {return opsy::utility::clear_set<eth_maccr_r>(mask, *this);}
	constexpr auto operator|(eth_maccr_r other) const -> eth_maccr_r { return static_cast<eth_maccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccr_r> other) const -> opsy::utility::clear_set<eth_maccr_r> {return opsy::utility::clear_set<eth_maccr_r>(eth_maccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto te() const -> te_f {return te_f((value_ & te_f::mask) != 0);}
	[[nodiscard]] constexpr auto prelen() const -> prelen_f {return prelen_f(static_cast<uint8_t>(value_ >> prelen_f::offset));}
	[[nodiscard]] constexpr auto dc() const -> dc_f {return dc_f((value_ & dc_f::mask) != 0);}
	[[nodiscard]] constexpr auto bl() const -> bl_f {return bl_f(static_cast<uint8_t>(value_ >> bl_f::offset));}
	[[nodiscard]] constexpr auto dr() const -> dr_f {return dr_f((value_ & dr_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcrs() const -> dcrs_f {return dcrs_f((value_ & dcrs_f::mask) != 0);}
	[[nodiscard]] constexpr auto _do() const -> do_f {return do_f((value_ & do_f::mask) != 0);}
	[[nodiscard]] constexpr auto ecrsfd() const -> ecrsfd_f {return ecrsfd_f((value_ & ecrsfd_f::mask) != 0);}
	[[nodiscard]] constexpr auto lm() const -> lm_f {return lm_f((value_ & lm_f::mask) != 0);}
	[[nodiscard]] constexpr auto dm() const -> dm_f {return dm_f((value_ & dm_f::mask) != 0);}
	[[nodiscard]] constexpr auto fes() const -> fes_f {return fes_f((value_ & fes_f::mask) != 0);}
	[[nodiscard]] constexpr auto je() const -> je_f {return je_f((value_ & je_f::mask) != 0);}
	[[nodiscard]] constexpr auto jd() const -> jd_f {return jd_f((value_ & jd_f::mask) != 0);}
	[[nodiscard]] constexpr auto wd() const -> wd_f {return wd_f((value_ & wd_f::mask) != 0);}
	[[nodiscard]] constexpr auto acs() const -> acs_f {return acs_f((value_ & acs_f::mask) != 0);}
	[[nodiscard]] constexpr auto cst() const -> cst_f {return cst_f((value_ & cst_f::mask) != 0);}
	[[nodiscard]] constexpr auto s2kp() const -> s2kp_f {return s2kp_f((value_ & s2kp_f::mask) != 0);}
	[[nodiscard]] constexpr auto gpslce() const -> gpslce_f {return gpslce_f((value_ & gpslce_f::mask) != 0);}
	[[nodiscard]] constexpr auto ipg() const -> ipg_f {return ipg_f(static_cast<uint8_t>(value_ >> ipg_f::offset));}
	[[nodiscard]] constexpr auto ipc() const -> ipc_f {return ipc_f((value_ & ipc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sarc() const -> sarc_f {return sarc_f(static_cast<uint8_t>(value_ >> sarc_f::offset));}
	[[nodiscard]] constexpr auto arpen() const -> arpen_f {return arpen_f((value_ & arpen_f::mask) != 0);}

	constexpr eth_maccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_maccr_r other) const -> eth_maccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_maccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Extended operating mode configuration register
 */
class eth_macecr_r {
public:

/**
 * Giant Packet Size Limit If the received packet size is greater than the value programmed in this field in units of bytes, the MAC declares the received packet as Giant packet. The value programmed in this field must be greater than or equal to 1,518 bytes. Any other programmed value is considered as 1,518 bytes. For VLAN tagged packets, the MAC adds 4 bytes to the programmed value. For double VLAN tagged packets, the MAC adds 8 bytes to the programmed value. The value in this field is applicable when the GPSLCE bit is set in ETH_MACCR register.
 */
class gpsl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr gpsl_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macecr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Disable CRC Checking for Received Packets When this bit is set, the MAC receiver does not check the CRC field in the received packets. When this bit is reset, the MAC receiver always checks the CRC field in the received packets.
 */
class dcrcc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcrcc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Slow Protocol Detection Enable When this bit is set, MAC processes the Slow Protocol packets (Ether Type 0x8809) and provides the Rx status. The MAC discards the Slow Protocol packets with invalid subtypes. When this bit is reset, the MAC forwards all error-free Slow Protocol packets to the application. The MAC considers such packets as normal Type packets.
 */
class spen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr spen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Unicast Slow Protocol Packet Detect When this bit is set, the MAC detects the Slow Protocol packets with unicast address of the station specified in the MAC Address 0 high register (ETH_MACA0HR) and MAC Address 0 low register MAC Address x low register (ETH_MACAxLR). The MAC also detects the Slow Protocol packets with the Slow Protocols multicast address (01-80-C2-00-00-02). When this bit is reset, the MAC detects only Slow Protocol packets with the Slow Protocol multicast address specified in the IEEE 802.3-2008, Section 5.
 */
class usp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Extended Inter-Packet Gap Enable When this bit is set, the MAC interprets EIPG field and IPG field in Operating mode configuration register (ETH_MACCR) together as minimum IPG greater than 96 bit times in steps of 8 bit times. When this bit is reset, the MAC ignores EIPG field and interprets IPG field in Operating mode configuration register (ETH_MACCR) as minimum IPG less than or equal to 96 bit times in steps of 8 bit times. Note: The extended Inter-Packet Gap feature must be enabled when operating in Full-duplex mode only. There may be undesirable effects on back-pressure function and frame transmission if it is enabled in Half-duplex mode.
 */
class eipgen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eipgen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Extended Inter-Packet Gap The value in this field is applicable when the EIPGEN bit is set. This field (as Most Significant bits) along with IPG field in Operating mode configuration register (ETH_MACCR), gives the minimum IPG greater than 96 bit times in steps of 8 bit times. For example: EIPG= 0 and IPG=0 give 104 bit times EIPG= 0 and IPG=1 give 112 bit times EIPG= 0 and IPG=2 give 120 bit times .. EIPG=7 and IPG=31 give 2144 bit times
 */
class eipg_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr eipg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macecr_r>() const {return opsy::utility::clear_set<eth_macecr_r>(mask, *this);}
	constexpr auto operator|(eth_macecr_r other) const -> eth_macecr_r { return static_cast<eth_macecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macecr_r> other) const -> opsy::utility::clear_set<eth_macecr_r> {return opsy::utility::clear_set<eth_macecr_r>(eth_macecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto gpsl() const -> gpsl_f {return gpsl_f(static_cast<uint16_t>(value_ >> gpsl_f::offset));}
	[[nodiscard]] constexpr auto dcrcc() const -> dcrcc_f {return dcrcc_f((value_ & dcrcc_f::mask) != 0);}
	[[nodiscard]] constexpr auto spen() const -> spen_f {return spen_f((value_ & spen_f::mask) != 0);}
	[[nodiscard]] constexpr auto usp() const -> usp_f {return usp_f((value_ & usp_f::mask) != 0);}
	[[nodiscard]] constexpr auto eipgen() const -> eipgen_f {return eipgen_f((value_ & eipgen_f::mask) != 0);}
	[[nodiscard]] constexpr auto eipg() const -> eipg_f {return eipg_f(static_cast<uint8_t>(value_ >> eipg_f::offset));}

	constexpr eth_macecr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macecr_r other) const -> eth_macecr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macecr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Packet filtering control register
 */
class eth_macpfr_r {
public:

/**
 * Promiscuous Mode When this bit is set, the Address Filtering module passes all incoming packets irrespective of the destination or source address. The SA or DA Filter Fails status bits of the Rx Status Word are always cleared when PR is set.
 */
class pr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hash Unicast When this bit is set, the MAC performs the destination address filtering of unicast packets according to the Hash table. When this bit is reset, the MAC performs a perfect destination address filtering for unicast packets, that is, it compares the DA field with the values programmed in DA registers.
 */
class huc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr huc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hash Multicast When this bit is set, the MAC performs the destination address filtering of received multicast packets according to the Hash table. When this bit is reset, the MAC performs the perfect destination address filtering for multicast packets, that is, it compares the DA field with the values programmed in DA registers.
 */
class hmc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hmc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DA Inverse Filtering When this bit is set, the Address Check block operates in inverse filtering mode for the DA address comparison for both unicast and multicast packets. When this bit is reset, normal filtering of packets is performed.
 */
class daif_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr daif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Pass All Multicast When this bit is set, it indicates that all received packets with a multicast destination address (first bit in the destination address field is '1') are passed. When this bit is reset, filtering of multicast packet depends on HMC bit.
 */
class pm_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable Broadcast Packets When this bit is set, the AFM module blocks all incoming broadcast packets. In addition, it overrides all other filter settings. When this bit is reset, the AFM module passes all received broadcast packets.
 */
class dbf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Pass Control Packets These bits control the forwarding of all control packets (including unicast and multicast Pause packets).
 */
class pcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pcf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macpfr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SA Inverse Filtering When this bit is set, the Address Check block operates in the inverse filtering mode for SA address comparison. If the SA of a packet matches the values programmed in the SA registers, it is marked as failing the SA Address filter. When this bit is reset, if the SA of a packet does not match the values programmed in the SA registers, it is marked as failing the SA Address filter.
 */
class saif_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr saif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Source Address Filter Enable When this bit is set, the MAC compares the SA field of the received packets with the values programmed in the enabled SA registers. If the comparison fails, the MAC drops the packet. When this bit is reset, the MAC forwards the received packet to the application with updated SAF bit of the Rx Status depending on the SA address comparison. Note: According to the IEEE specification, Bit 47 of the SA is reserved. However, the MAC compares all 48 bits. The software driver should take this into consideration while programming the MAC address registers for SA.
 */
class saf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr saf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hash or Perfect Filter When this bit is set, the address filter passes a packet if it matches either the perfect filtering or Hash filtering as set by the HMC or HUC bit. When this bit is reset and the HUC or HMC bit is set, the packet is passed only if it matches the Hash filter.
 */
class hpf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VLAN Tag Filter Enable When this bit is set, the MAC drops the VLAN tagged packets that do not match the VLAN Tag. When this bit is reset, the MAC forwards all packets irrespective of the match status of the VLAN Tag.
 */
class vtfe_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vtfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 and Layer 4 Filter Enable When this bit is set, the MAC drops packets that do not match the enabled Layer 3 and Layer 4 filters. If Layer 3 or Layer 4 filters are not enabled for matching, this bit does not have any effect. When this bit is reset, the MAC forwards all packets irrespective of the match status of the Layer 3 and Layer 4 fields.
 */
class ipfe_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ipfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Drop Non-TCP/UDP over IP Packets When this bit is set, the MAC drops the non-TCP or UDP over IP packets. The MAC forward only those packets that are processed by the Layer 4 filter. When this bit is reset, the MAC forwards all non-TCP or UDP over IP packets.
 */
class dntu_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dntu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive All When this bit is set, the MAC Receiver module passes all received packets to the application, irrespective of whether they pass the address filter or not. The result of the SA or DA filtering is updated (pass or fail) in the corresponding bit in the Rx Status Word. When this bit is reset, the Receiver module passes only those packets to the application that pass the SA or DA address filter.
 */
class ra_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ra_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpfr_r>() const {return opsy::utility::clear_set<eth_macpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macpfr_r other) const -> eth_macpfr_r { return static_cast<eth_macpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpfr_r> other) const -> opsy::utility::clear_set<eth_macpfr_r> {return opsy::utility::clear_set<eth_macpfr_r>(eth_macpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pr() const -> pr_f {return pr_f((value_ & pr_f::mask) != 0);}
	[[nodiscard]] constexpr auto huc() const -> huc_f {return huc_f((value_ & huc_f::mask) != 0);}
	[[nodiscard]] constexpr auto hmc() const -> hmc_f {return hmc_f((value_ & hmc_f::mask) != 0);}
	[[nodiscard]] constexpr auto daif() const -> daif_f {return daif_f((value_ & daif_f::mask) != 0);}
	[[nodiscard]] constexpr auto pm() const -> pm_f {return pm_f((value_ & pm_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbf() const -> dbf_f {return dbf_f((value_ & dbf_f::mask) != 0);}
	[[nodiscard]] constexpr auto pcf() const -> pcf_f {return pcf_f(static_cast<uint8_t>(value_ >> pcf_f::offset));}
	[[nodiscard]] constexpr auto saif() const -> saif_f {return saif_f((value_ & saif_f::mask) != 0);}
	[[nodiscard]] constexpr auto saf() const -> saf_f {return saf_f((value_ & saf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hpf() const -> hpf_f {return hpf_f((value_ & hpf_f::mask) != 0);}
	[[nodiscard]] constexpr auto vtfe() const -> vtfe_f {return vtfe_f((value_ & vtfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ipfe() const -> ipfe_f {return ipfe_f((value_ & ipfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto dntu() const -> dntu_f {return dntu_f((value_ & dntu_f::mask) != 0);}
	[[nodiscard]] constexpr auto ra() const -> ra_f {return ra_f((value_ & ra_f::mask) != 0);}

	constexpr eth_macpfr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macpfr_r other) const -> eth_macpfr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macpfr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Watchdog timeout register
 */
class eth_macwtr_r {
public:

/**
 * Watchdog Timeout When the PWE bit is set and the WD bit of the Operating mode configuration register (ETH_MACCR) register is reset, this field is used as watchdog timeout for a received packet. If the length of a received packet exceeds the value of this field, such packet is terminated and declared as an error packet. Encoding is as follows: .. Note: When the PWE bit is set, the value in this field should be more than 1,522 (0x05F2). Otherwise, the IEEE 802.3-specified valid tagged packets are declared as error packets and then dropped.
 */
class wto_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr wto_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macwtr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macwtr_r>() const {return opsy::utility::clear_set<eth_macwtr_r>(mask, *this);}
	constexpr auto operator|(eth_macwtr_r other) const -> eth_macwtr_r { return static_cast<eth_macwtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macwtr_r> other) const -> opsy::utility::clear_set<eth_macwtr_r> {return opsy::utility::clear_set<eth_macwtr_r>(eth_macwtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Programmable Watchdog Enable When this bit is set and the WD bit of the Operating mode configuration register (ETH_MACCR) register is reset, the WTO field is used as watchdog timeout for a received packet. When this bit is cleared, the watchdog timeout for a received packet is controlled by setting of WD and JE bits in Operating mode configuration register (ETH_MACCR) register.
 */
class pwe_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pwe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macwtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macwtr_r>() const {return opsy::utility::clear_set<eth_macwtr_r>(mask, *this);}
	constexpr auto operator|(eth_macwtr_r other) const -> eth_macwtr_r { return static_cast<eth_macwtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macwtr_r> other) const -> opsy::utility::clear_set<eth_macwtr_r> {return opsy::utility::clear_set<eth_macwtr_r>(eth_macwtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto wto() const -> wto_f {return wto_f(static_cast<uint8_t>(value_ >> wto_f::offset));}
	[[nodiscard]] constexpr auto pwe() const -> pwe_f {return pwe_f((value_ & pwe_f::mask) != 0);}

	constexpr eth_macwtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macwtr_r other) const -> eth_macwtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macwtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Hash Table 0 register
 */
class eth_macht0r_r {
public:

/**
 * MAC Hash Table First 32 Bits This field contains the first 32 Bits [31:0] of the Hash table.
 */
class ht31t0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht31t0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macht0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macht0r_r>() const {return opsy::utility::clear_set<eth_macht0r_r>(mask, *this);}
	constexpr auto operator|(eth_macht0r_r other) const -> eth_macht0r_r { return static_cast<eth_macht0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macht0r_r> other) const -> opsy::utility::clear_set<eth_macht0r_r> {return opsy::utility::clear_set<eth_macht0r_r>(eth_macht0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ht31t0() const -> ht31t0_f {return ht31t0_f(static_cast<uint32_t>(value_ >> ht31t0_f::offset));}

	constexpr eth_macht0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macht0r_r other) const -> eth_macht0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macht0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Hash Table 1 register
 */
class eth_macht1r_r {
public:

/**
 * MAC Hash Table Second 32 Bits This field contains the second 32 Bits [63:32] of the Hash table.
 */
class ht63t32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht63t32_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macht1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macht1r_r>() const {return opsy::utility::clear_set<eth_macht1r_r>(mask, *this);}
	constexpr auto operator|(eth_macht1r_r other) const -> eth_macht1r_r { return static_cast<eth_macht1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macht1r_r> other) const -> opsy::utility::clear_set<eth_macht1r_r> {return opsy::utility::clear_set<eth_macht1r_r>(eth_macht1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ht63t32() const -> ht63t32_f {return ht63t32_f(static_cast<uint32_t>(value_ >> ht63t32_f::offset));}

	constexpr eth_macht1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macht1r_r other) const -> eth_macht1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macht1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * VLAN tag register
 */
class eth_macvtr_r {
public:

/**
 * VLAN Tag Identifier for Receive Packets This field contains the 802.1Q VLAN tag to identify the VLAN packets. This VLAN tag identifier is compared to the 15th and 16th bytes of the packets being received for VLAN packets. The following list describes the bits of this field: Bits[15:13]: User Priority Bit 12: Canonical Format Indicator (CFI) or Drop Eligible Indicator (DEI) Bits[11:0]: VLAN Identifier (VID) field of VLAN tag When the ETV bit is set, only the VID is used for comparison. If this field ([11:0] if ETV is set) is all zeros, the MAC does not check the 15th and 16th bytes for VLAN tag comparison and declares all packets with Type field value of 0x8100 or 0x88a8 as VLAN packets.
 */
class vl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr vl_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macvtr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Enable 12-Bit VLAN Tag Comparison When this bit is set, a 12-bit VLAN identifier is used for comparing and filtering instead of the complete 16-bit VLAN tag. Bits[11:0] of VLAN tag are compared with the corresponding field in the received VLAN-tagged packet. Similarly, when enabled, only 12 bits of the VLAN tag in the received packet are used for Hash-based VLAN filtering. When this bit is reset, all 16 bits of the 15th and 16th bytes of the received VLAN packet are used for comparison and VLAN Hash filtering.
 */
class etv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr etv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VLAN Tag Inverse Match Enable When this bit is set, this bit enables the VLAN Tag inverse matching. The packets without matching VLAN Tag are marked as matched. When reset, this bit enables the VLAN Tag perfect matching. The packets with matched VLAN Tag are marked as matched.
 */
class vtim_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vtim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable S-VLAN When this bit is set, the MAC transmitter and receiver consider the S-VLAN packets (Type = 0x88A8) as valid VLAN tagged packets.
 */
class esvl_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr esvl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Receive S-VLAN Match When this bit is set, the MAC receiver enables filtering or matching for S-VLAN (Type = 0x88A8) packets. When this bit is reset, the MAC receiver enables filtering or matching for C-VLAN (Type = 0x8100) packets. The ERIVLT bit determines the VLAN tag position considered for filtering or matching.
 */
class ersvlm_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ersvlm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable VLAN Type Check When this bit is set, the MAC does not check whether the VLAN Tag specified by the ERIVLT bit is of type S-VLAN or C-VLAN. When this bit is reset, the MAC filters or matches the VLAN Tag specified by the ERIVLT bit only when VLAN Tag type is similar to the one specified by the ERSVLM bit.
 */
class dovltc_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dovltc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable VLAN Tag Stripping on Receive This field indicates the stripping operation on the outer VLAN Tag in received packet:
 */
class evls_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr evls_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macvtr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable VLAN Tag in Rx status When this bit is set, MAC provides the outer VLAN Tag in the Rx status. When this bit is reset, the MAC does not provide the outer VLAN Tag in Rx status.
 */
class evlrxs_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr evlrxs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VLAN Tag Hash Table Match Enable When this bit is set, the most significant four bits of CRC of VLAN Tag are used to index the content of the ETH_MACVLANHTR register. A value of 1 in the VLAN Hash Table register, corresponding to the index, indicates that the packet matched the VLAN Hash table. When the ETV bit is set, the CRC of the 12-bit VLAN Identifier (VID) is used for comparison. When the ETV bit is reset, the CRC of the 16-bit VLAN tag is used for comparison. When this bit is reset, the VLAN Hash Match operation is not performed.
 */
class vthm_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vthm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Double VLAN Processing When this bit is set, the MAC enables processing of up to two VLAN Tags on Tx and Rx (if present). When this bit is reset, the MAC enables processing of up to one VLAN Tag on Tx and Rx (if present).
 */
class edvlp_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr edvlp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Inner VLAN Tag When this bit and the EDVLP field are set, the MAC receiver enables operation on the inner VLAN Tag (if present). When this bit is reset, the MAC receiver enables operation on the outer VLAN Tag (if present). The ERSVLM bit determines which VLAN type is enabled for filtering or matching.The ERSVLM bit and DOVLTC bit determines which VLAN type is enabled for filtering.
 */
class erivlt_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr erivlt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Inner VLAN Tag Stripping on Receive This field indicates the stripping operation on inner VLAN Tag in received packet:
 */
class eivls_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr eivls_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macvtr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable Inner VLAN Tag in Rx Status When this bit is set, the MAC provides the inner VLAN Tag in the Rx status. When this bit is reset, the MAC does not provide the inner VLAN Tag in Rx status.
 */
class eivlrxs_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eivlrxs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvtr_r>() const {return opsy::utility::clear_set<eth_macvtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvtr_r other) const -> eth_macvtr_r { return static_cast<eth_macvtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvtr_r> other) const -> opsy::utility::clear_set<eth_macvtr_r> {return opsy::utility::clear_set<eth_macvtr_r>(eth_macvtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto vl() const -> vl_f {return vl_f(static_cast<uint16_t>(value_ >> vl_f::offset));}
	[[nodiscard]] constexpr auto etv() const -> etv_f {return etv_f((value_ & etv_f::mask) != 0);}
	[[nodiscard]] constexpr auto vtim() const -> vtim_f {return vtim_f((value_ & vtim_f::mask) != 0);}
	[[nodiscard]] constexpr auto esvl() const -> esvl_f {return esvl_f((value_ & esvl_f::mask) != 0);}
	[[nodiscard]] constexpr auto ersvlm() const -> ersvlm_f {return ersvlm_f((value_ & ersvlm_f::mask) != 0);}
	[[nodiscard]] constexpr auto dovltc() const -> dovltc_f {return dovltc_f((value_ & dovltc_f::mask) != 0);}
	[[nodiscard]] constexpr auto evls() const -> evls_f {return evls_f(static_cast<uint8_t>(value_ >> evls_f::offset));}
	[[nodiscard]] constexpr auto evlrxs() const -> evlrxs_f {return evlrxs_f((value_ & evlrxs_f::mask) != 0);}
	[[nodiscard]] constexpr auto vthm() const -> vthm_f {return vthm_f((value_ & vthm_f::mask) != 0);}
	[[nodiscard]] constexpr auto edvlp() const -> edvlp_f {return edvlp_f((value_ & edvlp_f::mask) != 0);}
	[[nodiscard]] constexpr auto erivlt() const -> erivlt_f {return erivlt_f((value_ & erivlt_f::mask) != 0);}
	[[nodiscard]] constexpr auto eivls() const -> eivls_f {return eivls_f(static_cast<uint8_t>(value_ >> eivls_f::offset));}
	[[nodiscard]] constexpr auto eivlrxs() const -> eivlrxs_f {return eivlrxs_f((value_ & eivlrxs_f::mask) != 0);}

	constexpr eth_macvtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macvtr_r other) const -> eth_macvtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macvtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * VLAN Hash table register
 */
class eth_macvhtr_r {
public:

/**
 * VLAN Hash Table This field contains the 16-bit VLAN Hash Table.
 */
class vlht_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr vlht_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macvhtr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvhtr_r>() const {return opsy::utility::clear_set<eth_macvhtr_r>(mask, *this);}
	constexpr auto operator|(eth_macvhtr_r other) const -> eth_macvhtr_r { return static_cast<eth_macvhtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvhtr_r> other) const -> opsy::utility::clear_set<eth_macvhtr_r> {return opsy::utility::clear_set<eth_macvhtr_r>(eth_macvhtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto vlht() const -> vlht_f {return vlht_f(static_cast<uint16_t>(value_ >> vlht_f::offset));}

	constexpr eth_macvhtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macvhtr_r other) const -> eth_macvhtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macvhtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * VLAN inclusion register
 */
class eth_macvir_r {
public:

/**
 * VLAN Tag for Transmit Packets This field contains the value of the VLAN tag to be inserted or replaced. The value must only be changed when the transmit lines are inactive or during the initialization phase. The following list describes the bits of this field: Bits[15:13]: User Priority Bit 12: Canonical Format Indicator (CFI) or Drop Eligible Indicator (DEI) Bits[11:0]: VLAN Identifier (VID) field of VLAN tag
 */
class vlt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr vlt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macvir_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvir_r>() const {return opsy::utility::clear_set<eth_macvir_r>(mask, *this);}
	constexpr auto operator|(eth_macvir_r other) const -> eth_macvir_r { return static_cast<eth_macvir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvir_r> other) const -> opsy::utility::clear_set<eth_macvir_r> {return opsy::utility::clear_set<eth_macvir_r>(eth_macvir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * VLAN Tag Control in Transmit Packets Note: Changes to this field take effect only on the start of a packet. If you write this register field when a packet is being transmitted, only the subsequent packet can use the updated value, that is, the current packet does not use the updated value.
 */
class vlc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr vlc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macvir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvir_r>() const {return opsy::utility::clear_set<eth_macvir_r>(mask, *this);}
	constexpr auto operator|(eth_macvir_r other) const -> eth_macvir_r { return static_cast<eth_macvir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvir_r> other) const -> opsy::utility::clear_set<eth_macvir_r> {return opsy::utility::clear_set<eth_macvir_r>(eth_macvir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * VLAN Priority Control When this bit is set, the control bits[17:16] are used for VLAN deletion, insertion, or replacement. When this bit is reset, bits[17:16] are ignored.
 */
class vlp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vlp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvir_r>() const {return opsy::utility::clear_set<eth_macvir_r>(mask, *this);}
	constexpr auto operator|(eth_macvir_r other) const -> eth_macvir_r { return static_cast<eth_macvir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvir_r> other) const -> opsy::utility::clear_set<eth_macvir_r> {return opsy::utility::clear_set<eth_macvir_r>(eth_macvir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * C-VLAN or S-VLAN When this bit is set, S-VLAN type (0x88A8) is inserted or replaced in the 13th and 14th bytes of transmitted packets. When this bit is reset, C-VLAN type (0x8100) is inserted or replaced in the 13th and 14th bytes of transmitted packets.
 */
class csvl_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr csvl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvir_r>() const {return opsy::utility::clear_set<eth_macvir_r>(mask, *this);}
	constexpr auto operator|(eth_macvir_r other) const -> eth_macvir_r { return static_cast<eth_macvir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvir_r> other) const -> opsy::utility::clear_set<eth_macvir_r> {return opsy::utility::clear_set<eth_macvir_r>(eth_macvir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VLAN Tag Input When this bit is set, it indicates that the VLAN tag to be inserted or replaced in Tx packet should be taken from the Tx descriptor.
 */
class vlti_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vlti_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macvir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macvir_r>() const {return opsy::utility::clear_set<eth_macvir_r>(mask, *this);}
	constexpr auto operator|(eth_macvir_r other) const -> eth_macvir_r { return static_cast<eth_macvir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvir_r> other) const -> opsy::utility::clear_set<eth_macvir_r> {return opsy::utility::clear_set<eth_macvir_r>(eth_macvir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto vlt() const -> vlt_f {return vlt_f(static_cast<uint16_t>(value_ >> vlt_f::offset));}
	[[nodiscard]] constexpr auto vlc() const -> vlc_f {return vlc_f(static_cast<uint8_t>(value_ >> vlc_f::offset));}
	[[nodiscard]] constexpr auto vlp() const -> vlp_f {return vlp_f((value_ & vlp_f::mask) != 0);}
	[[nodiscard]] constexpr auto csvl() const -> csvl_f {return csvl_f((value_ & csvl_f::mask) != 0);}
	[[nodiscard]] constexpr auto vlti() const -> vlti_f {return vlti_f((value_ & vlti_f::mask) != 0);}

	constexpr eth_macvir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macvir_r other) const -> eth_macvir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macvir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx Queue flow control register
 */
class eth_macqtxfcr_r {
public:

/**
 * Flow Control Busy or Backpressure Activate This bit initiates a Pause packet in the Full-duplex mode and activates the backpressure function in the Half-duplex mode if the TFE bit is set. Full-Duplex mode: this bit should be read as 0 before writing to this register. To initiate a Pause packet, the application must set this bit to 1. During Control packet transfer, this bit continues to be set to indicate that a packet transmission is in progress. When Pause packet transmission is complete, the MAC resets this bit to 0. You should not write to this register until this bit is cleared. Half-duplex mode: When this bit is set (and TFE bit is set) in the Half-duplex mode, the MAC asserts the backpressure. During backpressure, when the MAC receives a new packet, the transmitter starts sending a JAM pattern resulting in a collision. When the MAC is configured for the Full-duplex mode, the BPA is automatically disabled.
 */
class fcb_bpa_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fcb_bpa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macqtxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macqtxfcr_r>() const {return opsy::utility::clear_set<eth_macqtxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return static_cast<eth_macqtxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macqtxfcr_r> other) const -> opsy::utility::clear_set<eth_macqtxfcr_r> {return opsy::utility::clear_set<eth_macqtxfcr_r>(eth_macqtxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Flow Control Enable Full-duplex mode: when this bit is set, the MAC enables the flow control operation to Tx Pause packets. When this bit is reset, the flow control operation in the MAC is disabled, and the MAC does not transmit any Pause packets. Half-duplex mode: when this bit is set, the MAC enables the backpressure operation. When this bit is reset, the backpressure feature is disabled.
 */
class tfe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macqtxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macqtxfcr_r>() const {return opsy::utility::clear_set<eth_macqtxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return static_cast<eth_macqtxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macqtxfcr_r> other) const -> opsy::utility::clear_set<eth_macqtxfcr_r> {return opsy::utility::clear_set<eth_macqtxfcr_r>(eth_macqtxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Pause Low Threshold This field configures the threshold of the Pause timer at which the input flow is checked for automatic retransmission of the Pause packet. The threshold values should be always less than the Pause Time configured in Bits[31:16]. For example, if PT = 100H (256 slot times), and PLT = 001, a second Pause packet is automatically transmitted at 228 (256-28) slot times after the first Pause packet is transmitted. The following list provides the threshold values for different values: 110 to 111: Reserved, must not be used The slot time is defined as the time taken to transmit 512 bits (64 bytes) on the MII interface. This (approximate) computation is based on the packet size (64, 1518, 2000, 9018, 16384, or 32768) + 2 Pause Packet Size + IPG in Slot Times.
 */
class plt_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr plt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macqtxfcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macqtxfcr_r>() const {return opsy::utility::clear_set<eth_macqtxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return static_cast<eth_macqtxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macqtxfcr_r> other) const -> opsy::utility::clear_set<eth_macqtxfcr_r> {return opsy::utility::clear_set<eth_macqtxfcr_r>(eth_macqtxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Disable Zero-Quanta Pause When this bit is set, it disables the automatic generation of the zero-quanta Pause packets. When this bit is reset, normal operation with automatic zero-quanta Pause packet generation is enabled.
 */
class dzpq_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dzpq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macqtxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macqtxfcr_r>() const {return opsy::utility::clear_set<eth_macqtxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return static_cast<eth_macqtxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macqtxfcr_r> other) const -> opsy::utility::clear_set<eth_macqtxfcr_r> {return opsy::utility::clear_set<eth_macqtxfcr_r>(eth_macqtxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Pause Time This field holds the value to be used in the Pause Time field in the Tx control packet. I
 */
class pt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macqtxfcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macqtxfcr_r>() const {return opsy::utility::clear_set<eth_macqtxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return static_cast<eth_macqtxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macqtxfcr_r> other) const -> opsy::utility::clear_set<eth_macqtxfcr_r> {return opsy::utility::clear_set<eth_macqtxfcr_r>(eth_macqtxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto fcb_bpa() const -> fcb_bpa_f {return fcb_bpa_f((value_ & fcb_bpa_f::mask) != 0);}
	[[nodiscard]] constexpr auto tfe() const -> tfe_f {return tfe_f((value_ & tfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto plt() const -> plt_f {return plt_f(static_cast<uint8_t>(value_ >> plt_f::offset));}
	[[nodiscard]] constexpr auto dzpq() const -> dzpq_f {return dzpq_f((value_ & dzpq_f::mask) != 0);}
	[[nodiscard]] constexpr auto pt() const -> pt_f {return pt_f(static_cast<uint16_t>(value_ >> pt_f::offset));}

	constexpr eth_macqtxfcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macqtxfcr_r other) const -> eth_macqtxfcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macqtxfcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx flow control register
 */
class eth_macrxfcr_r {
public:

/**
 * Receive Flow Control Enable When this bit is set and the MAC is operating in Full-duplex mode, the MAC decodes the received Pause packet and disables its transmitter for a specified (Pause) time. When this bit is reset or the MAC is operating in Half-duplex mode, the decode function of the Pause packet is disabled. When PFC is enabled, flow control is enabled for PFC packets. The MAC decodes the received PFC packet and disables the Transmit queue, with matching priorities, for a duration of received Pause time.
 */
class rfe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxfcr_r>() const {return opsy::utility::clear_set<eth_macrxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxfcr_r other) const -> eth_macrxfcr_r { return static_cast<eth_macrxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxfcr_r> other) const -> opsy::utility::clear_set<eth_macrxfcr_r> {return opsy::utility::clear_set<eth_macrxfcr_r>(eth_macrxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Unicast Pause Packet Detect A pause packet is processed when it has the unique multicast address specified in the IEEE 802.3. When this bit is set, the MAC can also detect Pause packets with unicast address of the station. This unicast address should be as specified in MAC Address 0 high register (ETH_MACA0HR) and MAC Address 0 low register MAC Address x low register (ETH_MACAxLR). When this bit is reset, the MAC only detects Pause packets with unique multicast address. Note: The MAC does not process a Pause packet if the multicast address is different from the unique multicast address. This is also applicable to the received PFC packet when the Priority Flow Control (PFC) is enabled. The unique multicast address (0x01_80_C2_00_00_01) is as specified in IEEE 802.1 Qbb-2011.
 */
class up_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr up_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxfcr_r>() const {return opsy::utility::clear_set<eth_macrxfcr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxfcr_r other) const -> eth_macrxfcr_r { return static_cast<eth_macrxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxfcr_r> other) const -> opsy::utility::clear_set<eth_macrxfcr_r> {return opsy::utility::clear_set<eth_macrxfcr_r>(eth_macrxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rfe() const -> rfe_f {return rfe_f((value_ & rfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto up() const -> up_f {return up_f((value_ & up_f::mask) != 0);}

	constexpr eth_macrxfcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macrxfcr_r other) const -> eth_macrxfcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macrxfcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Interrupt status register
 */
class eth_macisr_r {
public:

/**
 * PHY Interrupt This bit is set when rising edge is detected on the ETH_PHY_INTN input. This bit is cleared when this register is read.
 */
class phyis_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr phyis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PMT Interrupt Status This bit is set when a Magic packet or Wake-on-LAN packet is received in the power-down mode (RWKPRCVD and MGKPRCVD bits in ETH_MACPCSR register). This bit is cleared when Bits[6:5] are cleared because of a Read operation to the PMT control status register (ETH_MACPCSR).
 */
class pmtis_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pmtis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Interrupt Status This bit is set for any LPI state entry or exit in the MAC Transmitter or Receiver. This bit is cleared when the TLPIEN bit of LPI control and status register (ETH_MACLCSR) is read.
 */
class lpiis_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpiis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Interrupt Status This bit is set high when MMCTXIS or MMCRXIS is set high. This bit is cleared only when all these bits are low.
 */
class mmcis_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mmcis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive Interrupt Status This bit is set high when an interrupt is generated in the MMC Rx interrupt register (ETH_MMC_RX_INTERRUPT). This bit is cleared when all bits in this interrupt register are cleared.
 */
class mmcrxis_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mmcrxis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit Interrupt Status This bit is set high when an interrupt is generated in the MMC Tx interrupt register (ETH_MMC_TX_INTERRUPT). This bit is cleared when all bits in this interrupt register are cleared.
 */
class mmctxis_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mmctxis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp Interrupt Status If the Timestamp feature is enabled, this bit is set when any of the following conditions is true: The system time value is equal to or exceeds the value specified in the Target Time High and Low registers. There is an overflow in the Seconds register. The Target Time Error occurred, that is, programmed target time already elapsed. If the Auxiliary Snapshot feature is enabled, this bit is set when the auxiliary snapshot trigger is asserted. When drop transmit status is enabled in MTL, this bit is set when the captured transmit timestamp is updated in the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) and Tx timestamp status seconds register (ETH_MACTXTSSSR) registers. When PTP offload feature is enabled, this bit is set when the captured transmit timestamp is updated in the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) and Tx timestamp status seconds register (ETH_MACTXTSSSR) registers, for PTO generated Delay Request and Pdelay request packets. This bit is cleared when the corresponding interrupt source bit is read (or corresponding interrupt source bit is written to 1 when RCWE bit of CSR software control register (ETH_MACCSRSWCR) is set) in the Timestamp status register (ETH_MACTSSR).
 */
class tsis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Status Interrupt This bit indicates the status of transmitted packets. This bit is set when any of the following bits is set in the Rx Tx status register (ETH_MACRXTXSR): Excessive Collision (EXCOL) Late Collision (LCOL) Excessive Deferral (EXDEF) Loss of Carrier (LCARR) No Carrier (NCARR) Jabber Timeout (TJT) This bit is cleared when the corresponding interrupt source bit is read (or corresponding interrupt source bit is written to 1 when RCWE bit of CSR software control register (ETH_MACCSRSWCR) is set) in the ETH_MACISR register.
 */
class txstsis_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txstsis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Status Interrupt This bit indicates the status of received packets. This bit is set when the RWT bit is set in the Rx Tx status register (ETH_MACRXTXSR). This bit is cleared when the corresponding interrupt source bit is read (or corresponding interrupt source bit is written to 1 when RCWE bit of CSR software control register (ETH_MACCSRSWCR) is set) in the ETH_MACISR register.
 */
class rxstsis_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxstsis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macisr_r>() const {return opsy::utility::clear_set<eth_macisr_r>(mask, *this);}
	constexpr auto operator|(eth_macisr_r other) const -> eth_macisr_r { return static_cast<eth_macisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macisr_r> other) const -> opsy::utility::clear_set<eth_macisr_r> {return opsy::utility::clear_set<eth_macisr_r>(eth_macisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto phyis() const -> phyis_f {return phyis_f((value_ & phyis_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmtis() const -> pmtis_f {return pmtis_f((value_ & pmtis_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpiis() const -> lpiis_f {return lpiis_f((value_ & lpiis_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmcis() const -> mmcis_f {return mmcis_f((value_ & mmcis_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmcrxis() const -> mmcrxis_f {return mmcrxis_f((value_ & mmcrxis_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmctxis() const -> mmctxis_f {return mmctxis_f((value_ & mmctxis_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsis() const -> tsis_f {return tsis_f((value_ & tsis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txstsis() const -> txstsis_f {return txstsis_f((value_ & txstsis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxstsis() const -> rxstsis_f {return rxstsis_f((value_ & rxstsis_f::mask) != 0);}

	constexpr eth_macisr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macisr_r other) const -> eth_macisr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macisr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Interrupt enable register
 */
class eth_macier_r {
public:

/**
 * PHY Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of PHYIS bit in Interrupt status register (ETH_MACISR).
 */
class phyie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr phyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PMT Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of PMTIS bit in Interrupt status register (ETH_MACISR).
 */
class pmtie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pmtie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of LPIIS bit in Interrupt status register (ETH_MACISR).
 */
class lpiie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpiie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of TSIS bit in Interrupt status register (ETH_MACISR).
 */
class tsie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Status Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of TXSTSIS bit in the Interrupt status register (ETH_MACISR).
 */
class txstsie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txstsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Status Interrupt Enable When this bit is set, it enables the assertion of the interrupt signal because of the setting of RXSTSIS bit in the Interrupt status register (ETH_MACISR).
 */
class rxstsie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxstsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macier_r>() const {return opsy::utility::clear_set<eth_macier_r>(mask, *this);}
	constexpr auto operator|(eth_macier_r other) const -> eth_macier_r { return static_cast<eth_macier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macier_r> other) const -> opsy::utility::clear_set<eth_macier_r> {return opsy::utility::clear_set<eth_macier_r>(eth_macier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto phyie() const -> phyie_f {return phyie_f((value_ & phyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmtie() const -> pmtie_f {return pmtie_f((value_ & pmtie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpiie() const -> lpiie_f {return lpiie_f((value_ & lpiie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsie() const -> tsie_f {return tsie_f((value_ & tsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txstsie() const -> txstsie_f {return txstsie_f((value_ & txstsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxstsie() const -> rxstsie_f {return rxstsie_f((value_ & rxstsie_f::mask) != 0);}

	constexpr eth_macier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macier_r other) const -> eth_macier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx Tx status register
 */
class eth_macrxtxsr_r {
public:

/**
 * Transmit Jabber Timeout This bit indicates that the Transmit Jabber Timer expired which happens when the packet size exceeds 2,048 bytes (10,240 bytes when the Jumbo packet is enabled) and JD bit is reset in the Operating mode configuration register (ETH_MACCR). This bit is set when the packet size exceeds 16,383 bytes and the JD bit is set in the Operating mode configuration register (ETH_MACCR). Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class tjt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tjt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * No Carrier When the DTXSTS bit is set in the Operating mode Register (ETH_MTLOMR), this bit indicates that the carrier signal from the PHY is not present at the end of preamble transmission. Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class ncarr_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ncarr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Loss of Carrier When the DTXSTS bit is set in the Operating mode Register (ETH_MTLOMR), this bit indicates that the loss of carrier occurred during packet transmission, that is, the ETH_CRS signal was inactive for one or more transmission clock periods during packet transmission. This bit is valid only for packets transmitted without collision. Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class lcarr_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lcarr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Excessive Deferral When the DTXSTS bit is set in the Operating mode Register (ETH_MTLOMR) and the DC bit is set in the Operating mode configuration register (ETH_MACCR), this bit indicates that the transmission ended because of excessive deferral of over 24,288 bit times (155,680 when Jumbo packet is enabled). Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class exdef_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exdef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Late Collision When the DTXSTS bit is set in the Operating mode Register (ETH_MTLOMR), this bit indicates that the packet transmission aborted because a collision occurred after the collision window (64 bytes including Preamble in MII mode. This bit is not valid if the Underflow error occurs. Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class lcol_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lcol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Excessive Collisions When the DTXSTS bit is set in the Operating mode Register (ETH_MTLOMR), this bit indicates that the transmission aborted after 16 successive collisions while attempting to transmit the current packet. If the DR bit is set in the Operating mode configuration register (ETH_MACCR), this bit is set after the first collision and the packet transmission is aborted. Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class excol_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr excol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Watchdog Timeout This bit is set when a packet with length greater than 2,048 bytes is received (10, 240 bytes when Jumbo Packet mode is enabled) and the WD bit is reset in the Operating mode configuration register (ETH_MACCR). This bit is set when a packet with length greater than 16,383 bytes is received and the WD bit is set in the Operating mode configuration register (ETH_MACCR). Cleared on read (or write of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class rwt_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macrxtxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macrxtxsr_r>() const {return opsy::utility::clear_set<eth_macrxtxsr_r>(mask, *this);}
	constexpr auto operator|(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return static_cast<eth_macrxtxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrxtxsr_r> other) const -> opsy::utility::clear_set<eth_macrxtxsr_r> {return opsy::utility::clear_set<eth_macrxtxsr_r>(eth_macrxtxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tjt() const -> tjt_f {return tjt_f((value_ & tjt_f::mask) != 0);}
	[[nodiscard]] constexpr auto ncarr() const -> ncarr_f {return ncarr_f((value_ & ncarr_f::mask) != 0);}
	[[nodiscard]] constexpr auto lcarr() const -> lcarr_f {return lcarr_f((value_ & lcarr_f::mask) != 0);}
	[[nodiscard]] constexpr auto exdef() const -> exdef_f {return exdef_f((value_ & exdef_f::mask) != 0);}
	[[nodiscard]] constexpr auto lcol() const -> lcol_f {return lcol_f((value_ & lcol_f::mask) != 0);}
	[[nodiscard]] constexpr auto excol() const -> excol_f {return excol_f((value_ & excol_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwt() const -> rwt_f {return rwt_f((value_ & rwt_f::mask) != 0);}

	constexpr eth_macrxtxsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macrxtxsr_r other) const -> eth_macrxtxsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macrxtxsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PMT control status register
 */
class eth_macpcsr_r {
public:

/**
 * Power Down When this bit is set, the MAC receiver drops all received packets until it receives the expected magic packet or remote wakeup packet. This bit is then self-cleared and the power-down mode is disabled. The software can clear this bit before the expected magic packet or remote wakeup packet is received. The packets received by the MAC after this bit is cleared are forwarded to the application. This bit must only be set when the Magic Packet Enable, Global Unicast, or Remote wakeup Packet Enable bit is set high. Note: You can gate-off the CSR clock during the power-down mode. However, when the CSR clock is gated-off, you cannot perform any read or write operations on this register. Therefore, the Software cannot clear this bit.
 */
class pwrdwn_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pwrdwn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Magic Packet Enable When this bit is set, a power management event is generated when the MAC receives a magic packet.
 */
class mgkpkten_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mgkpkten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Remote wakeup Packet Enable When this bit is set, a power management event is generated when the MAC receives a remote wakeup packet.
 */
class rwkpkten_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rwkpkten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Magic Packet Received When this bit is set, it indicates that the power management event is generated because of the reception of a magic packet. This bit is cleared when this register is read (or written to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class mgkprcvd_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mgkprcvd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Remote wakeup Packet Received When this bit is set, it indicates that the power management event is generated because of the reception of a remote wakeup packet. This bit is cleared when this register is read.
 */
class rwkprcvd_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rwkprcvd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Global Unicast When this bit set, any unicast packet filtered by the MAC (DAF) address recognition is detected as a remote wakeup packet.
 */
class glblucast_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr glblucast_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Remote wakeup Packet Forwarding Enable When this bit is set along with RWKPKTEN, the MAC receiver drops all received frames until it receives the expected wakeup frame. All frames after that event including the received wakeup frame are forwarded to application. This bit is then self-cleared on receiving the wakeup packet. The application can also clear this bit before the expected wakeup frame is received. In such cases, the MAC reverts to the default behavior where packets received are forwarded to the application. This bit must only be set when RWKPKTEN is set high and PWRDWN is set low. The setting of this bit has no effect when PWRDWN is set high. Note: If Magic Packet Enable and wakeup Frame Enable are both set along with setting of this bit and Magic Packet is received prior to wakeup frame, this bit is self-cleared on receiving Magic Packet, the received Magic packet is dropped, and all frames after received Magic Packet are forwarded to application.
 */
class rwkpfe_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwkpfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Remote wakeup FIFO Pointer This field gives the current value (0 to 7) of the Remote wakeup Packet Filter register pointer. When the value of this pointer is equal to 7, the contents of the Remote wakeup Packet Filter Register are transferred to the eth_mii_rx_clk domain when a Write occurs to that register.
 */
class rwkptr_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rwkptr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Remote wakeup Packet Filter Register Pointer Reset When this bit is set, the remote wakeup packet filter register pointer is reset to 0. It is automatically cleared after 1 clock cycle.
 */
class rwkfiltrst_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwkfiltrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpcsr_r>() const {return opsy::utility::clear_set<eth_macpcsr_r>(mask, *this);}
	constexpr auto operator|(eth_macpcsr_r other) const -> eth_macpcsr_r { return static_cast<eth_macpcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpcsr_r> other) const -> opsy::utility::clear_set<eth_macpcsr_r> {return opsy::utility::clear_set<eth_macpcsr_r>(eth_macpcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pwrdwn() const -> pwrdwn_f {return pwrdwn_f((value_ & pwrdwn_f::mask) != 0);}
	[[nodiscard]] constexpr auto mgkpkten() const -> mgkpkten_f {return mgkpkten_f((value_ & mgkpkten_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwkpkten() const -> rwkpkten_f {return rwkpkten_f((value_ & rwkpkten_f::mask) != 0);}
	[[nodiscard]] constexpr auto mgkprcvd() const -> mgkprcvd_f {return mgkprcvd_f((value_ & mgkprcvd_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwkprcvd() const -> rwkprcvd_f {return rwkprcvd_f((value_ & rwkprcvd_f::mask) != 0);}
	[[nodiscard]] constexpr auto glblucast() const -> glblucast_f {return glblucast_f((value_ & glblucast_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwkpfe() const -> rwkpfe_f {return rwkpfe_f((value_ & rwkpfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwkptr() const -> rwkptr_f {return rwkptr_f(static_cast<uint8_t>(value_ >> rwkptr_f::offset));}
	[[nodiscard]] constexpr auto rwkfiltrst() const -> rwkfiltrst_f {return rwkfiltrst_f((value_ & rwkfiltrst_f::mask) != 0);}

	constexpr eth_macpcsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macpcsr_r other) const -> eth_macpcsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macpcsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Remote wakeup packet filter register
 */
class eth_macrwkpfr_r {
public:

/**
 * Remote wakeup packet filter Refer to Table648, Table649 and Table650 for details on register content and programming sequence.
 */
class macrwkpfr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr macrwkpfr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macrwkpfr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macrwkpfr_r>() const {return opsy::utility::clear_set<eth_macrwkpfr_r>(mask, *this);}
	constexpr auto operator|(eth_macrwkpfr_r other) const -> eth_macrwkpfr_r { return static_cast<eth_macrwkpfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macrwkpfr_r> other) const -> opsy::utility::clear_set<eth_macrwkpfr_r> {return opsy::utility::clear_set<eth_macrwkpfr_r>(eth_macrwkpfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto macrwkpfr() const -> macrwkpfr_f {return macrwkpfr_f(static_cast<uint32_t>(value_ >> macrwkpfr_f::offset));}

	constexpr eth_macrwkpfr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macrwkpfr_r other) const -> eth_macrwkpfr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macrwkpfr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPI control and status register
 */
class eth_maclcsr_r {
public:

/**
 * Transmit LPI Entry When this bit is set, it indicates that the MAC Transmitter has entered the LPI state because of the setting of the LPIEN bit. This bit is cleared by a read into this register (or by writing it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class tlpien_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tlpien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit LPI Exit When this bit is set, it indicates that the MAC transmitter exited the LPI state after the application cleared the LPIEN bit and the LPI TW Timer has expired. This bit is cleared by a read into this register (or by writing it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class tlpiex_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tlpiex_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive LPI Entry When this bit is set, it indicates that the MAC Receiver has received an LPI pattern and entered the LPI state. This bit is cleared by a read into this register (or by writing it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set). Note: This bit may not be set if the MAC stops receiving the LPI pattern for a very short duration, such as, less than three clock cycles of CSR clock.
 */
class rlpien_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rlpien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive LPI Exit When this bit is set, it indicates that the MAC Receiver has stopped receiving the LPI pattern on the MII interface, exited the LPI state, and resumed the normal reception. This bit is cleared by a read into this register (or by writing it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set). Note: This bit may not be set if the MAC stops receiving the LPI pattern for a very short duration, such as, less than three clock cycles of CSR clock.
 */
class rlpiex_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rlpiex_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit LPI State When this bit is set, it indicates that the MAC is transmitting the LPI pattern on the MII interface.
 */
class tlpist_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tlpist_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive LPI State When this bit is set, it indicates that the MAC is receiving the LPI pattern on the MII interface.
 */
class rlpist_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rlpist_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Enable When this bit is set, it instructs the MAC Transmitter to enter the LPI state. When this bit is reset, it instructs the MAC to exit the LPI state and resume normal transmission. This bit is cleared when the LPITXA bit is set and the MAC exits the LPI state because of the arrival of a new packet for transmission.
 */
class lpien_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PHY Link Status This bit indicates the link status of the PHY. The MAC Transmitter asserts the LPI pattern only when the link status is up (OKAY) at least for the time indicated by the LPI LS TIMER. When this bit is set, the link is considered to be okay (UP) and when this bit is reset, the link is considered to be down.
 */
class pls_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pls_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Tx Automate This bit controls the behavior of the MAC when it is entering or coming out of the LPI mode on the Transmit side. If the LPITXA and LPIEN bits are set to 1, the MAC enters the LPI mode only after all outstanding packets (in the core) and pending packets (in the application interface) have been transmitted. The MAC comes out of the LPI mode when the application sends any packet for transmission or the application issues a Tx FIFO Flush command. In addition, the MAC automatically clears the LPIEN bit when it exits the LPI state. If Tx FIFO Flush is set in the FTQ bit of ETH_MTLTxQOMR, when the MAC is in the LPI mode, it exits the LPI mode. When this bit is 0, the LPIEN bit directly controls behavior of the MAC when it is entering or coming out of the LPI mode.
 */
class lpitxa_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpitxa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Timer Enable This bit controls the automatic entry of the MAC Transmitter into and exit out of the LPI state. When LPITE, LPITXA and LPIEN bits are set, the MAC Transmitter enters LPI state only when the complete MAC TX data path is IDLE for a period indicated by the ETH_MACLETR register. After entering LPI state, if the data path becomes non-IDLE (due to a new packet being accepted for transmission), the Transmitter exits LPI state but does not clear LPIEN bit. This enables the re-entry into LPI state when it is IDLE again. When LPITE is 0, the LPI Auto timer is disabled and MAC Transmitter enters LPI state based on the settings of LPITXA and LPIEN bit descriptions.
 */
class lpite_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpite_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPI Tx Clock Stop Enable When this bit is set, the MAC asserts sbd_tx_clk_gating_ctrl_o signal high after it enters Tx LPI mode to indicate that the Tx clock to MAC can be stopped. When this bit is reset, the MAC does not assert sbd_tx_clk_gating_ctrl_o signal high after it enters Tx LPI mode. If RGMII Interface is selected, the Tx clock is required for transmitting the LPI pattern. The Tx Clock cannot be gated and so the LPITCSE bit cannot be programmed.
 */
class lpitcse_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lpitcse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maclcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maclcsr_r>() const {return opsy::utility::clear_set<eth_maclcsr_r>(mask, *this);}
	constexpr auto operator|(eth_maclcsr_r other) const -> eth_maclcsr_r { return static_cast<eth_maclcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclcsr_r> other) const -> opsy::utility::clear_set<eth_maclcsr_r> {return opsy::utility::clear_set<eth_maclcsr_r>(eth_maclcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tlpien() const -> tlpien_f {return tlpien_f((value_ & tlpien_f::mask) != 0);}
	[[nodiscard]] constexpr auto tlpiex() const -> tlpiex_f {return tlpiex_f((value_ & tlpiex_f::mask) != 0);}
	[[nodiscard]] constexpr auto rlpien() const -> rlpien_f {return rlpien_f((value_ & rlpien_f::mask) != 0);}
	[[nodiscard]] constexpr auto rlpiex() const -> rlpiex_f {return rlpiex_f((value_ & rlpiex_f::mask) != 0);}
	[[nodiscard]] constexpr auto tlpist() const -> tlpist_f {return tlpist_f((value_ & tlpist_f::mask) != 0);}
	[[nodiscard]] constexpr auto rlpist() const -> rlpist_f {return rlpist_f((value_ & rlpist_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpien() const -> lpien_f {return lpien_f((value_ & lpien_f::mask) != 0);}
	[[nodiscard]] constexpr auto pls() const -> pls_f {return pls_f((value_ & pls_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpitxa() const -> lpitxa_f {return lpitxa_f((value_ & lpitxa_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpite() const -> lpite_f {return lpite_f((value_ & lpite_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpitcse() const -> lpitcse_f {return lpitcse_f((value_ & lpitcse_f::mask) != 0);}

	constexpr eth_maclcsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_maclcsr_r other) const -> eth_maclcsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_maclcsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPI timers control register
 */
class eth_macltcr_r {
public:

/**
 * LPI TW Timer This field specifies the minimum time (in microseconds) for which the MAC waits after it stops transmitting the LPI pattern to the PHY and before it resumes the normal transmission. The TLPIEX status bit is set after the expiry of this timer.
 */
class twt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr twt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macltcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macltcr_r>() const {return opsy::utility::clear_set<eth_macltcr_r>(mask, *this);}
	constexpr auto operator|(eth_macltcr_r other) const -> eth_macltcr_r { return static_cast<eth_macltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macltcr_r> other) const -> opsy::utility::clear_set<eth_macltcr_r> {return opsy::utility::clear_set<eth_macltcr_r>(eth_macltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * LPI LS Timer This field specifies the minimum time (in milliseconds) for which the link status from the PHY should be up (OKAY) before the LPI pattern can be transmitted to the PHY. The MAC does not transmit the LPI pattern even when the LPIEN bit is set unless the LPI LS Timer reaches the programmed terminal count. The default value of the LPI LS Timer is 1000 (1 sec) as defined in the IEEE standard.
 */
class lst_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lst_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macltcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macltcr_r>() const {return opsy::utility::clear_set<eth_macltcr_r>(mask, *this);}
	constexpr auto operator|(eth_macltcr_r other) const -> eth_macltcr_r { return static_cast<eth_macltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macltcr_r> other) const -> opsy::utility::clear_set<eth_macltcr_r> {return opsy::utility::clear_set<eth_macltcr_r>(eth_macltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto twt() const -> twt_f {return twt_f(static_cast<uint16_t>(value_ >> twt_f::offset));}
	[[nodiscard]] constexpr auto lst() const -> lst_f {return lst_f(static_cast<uint16_t>(value_ >> lst_f::offset));}

	constexpr eth_macltcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macltcr_r other) const -> eth_macltcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macltcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111010000000000000000000; // 65536000 0x3E80000

private:
	uint32_t value_;
};

/**
 * LPI entry timer register
 */
class eth_macletr_r {
public:

/**
 * LPI Entry Timer This field specifies the time in microseconds the MAC waits to enter LPI mode, after it has transmitted all the frames. This field is valid and used only when LPITE and LPITXA are set to 1. Bits [2:0] are read-only so that the granularity of this timer is in steps of 8 micro-seconds.
 */
class lpiet_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lpiet_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macletr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macletr_r>() const {return opsy::utility::clear_set<eth_macletr_r>(mask, *this);}
	constexpr auto operator|(eth_macletr_r other) const -> eth_macletr_r { return static_cast<eth_macletr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macletr_r> other) const -> opsy::utility::clear_set<eth_macletr_r> {return opsy::utility::clear_set<eth_macletr_r>(eth_macletr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto lpiet() const -> lpiet_f {return lpiet_f(static_cast<uint32_t>(value_ >> lpiet_f::offset));}

	constexpr eth_macletr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macletr_r other) const -> eth_macletr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macletr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * One-microsecond-tick counter register
 */
class eth_mac1ustcr_r {
public:

/**
 * 1s tick Counter The application must program this counter so that the number of clock cycles of CSR clock is 1s (subtract 1 from the value before programming). For example if the CSR clock is 100MHz then this field needs to be programmed to 1001 = 99 (which is 0x63). This is required to generate the 1s events that are used to update some of the EEE related counters.
 */
class tic_1us_cntr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tic_1us_cntr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_mac1ustcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mac1ustcr_r>() const {return opsy::utility::clear_set<eth_mac1ustcr_r>(mask, *this);}
	constexpr auto operator|(eth_mac1ustcr_r other) const -> eth_mac1ustcr_r { return static_cast<eth_mac1ustcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mac1ustcr_r> other) const -> opsy::utility::clear_set<eth_mac1ustcr_r> {return opsy::utility::clear_set<eth_mac1ustcr_r>(eth_mac1ustcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tic_1us_cntr() const -> tic_1us_cntr_f {return tic_1us_cntr_f(static_cast<uint16_t>(value_ >> tic_1us_cntr_f::offset));}

	constexpr eth_mac1ustcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mac1ustcr_r other) const -> eth_mac1ustcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mac1ustcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Version register
 */
class eth_macvr_r {
public:

/**
 * IP version
 */
class snpsver_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr snpsver_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macvr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvr_r>() const {return opsy::utility::clear_set<eth_macvr_r>(mask, *this);}
	constexpr auto operator|(eth_macvr_r other) const -> eth_macvr_r { return static_cast<eth_macvr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvr_r> other) const -> opsy::utility::clear_set<eth_macvr_r> {return opsy::utility::clear_set<eth_macvr_r>(eth_macvr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ST-defined version
 */
class userver_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr userver_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macvr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macvr_r>() const {return opsy::utility::clear_set<eth_macvr_r>(mask, *this);}
	constexpr auto operator|(eth_macvr_r other) const -> eth_macvr_r { return static_cast<eth_macvr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macvr_r> other) const -> opsy::utility::clear_set<eth_macvr_r> {return opsy::utility::clear_set<eth_macvr_r>(eth_macvr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto snpsver() const -> snpsver_f {return snpsver_f(static_cast<uint8_t>(value_ >> snpsver_f::offset));}
	[[nodiscard]] constexpr auto userver() const -> userver_f {return userver_f(static_cast<uint8_t>(value_ >> userver_f::offset));}

	constexpr eth_macvr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macvr_r other) const -> eth_macvr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macvr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11001001000010; // 12866 0x3242

private:
	uint32_t value_;
};

/**
 * Debug register
 */
class eth_macdr_r {
public:

/**
 * MAC MII Receive Protocol Engine Status When this bit is set, it indicates that the MAC MII receive protocol engine is actively receiving data, and it is not in the Idle state.
 */
class rpests_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpests_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macdr_r>() const {return opsy::utility::clear_set<eth_macdr_r>(mask, *this);}
	constexpr auto operator|(eth_macdr_r other) const -> eth_macdr_r { return static_cast<eth_macdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macdr_r> other) const -> opsy::utility::clear_set<eth_macdr_r> {return opsy::utility::clear_set<eth_macdr_r>(eth_macdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Receive Packet Controller FIFO Status When this bit is set, this field indicates the active state of the small FIFO Read and Write controllers of the MAC Receive Packet Controller module.
 */
class rfcfcsts_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rfcfcsts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macdr_r>() const {return opsy::utility::clear_set<eth_macdr_r>(mask, *this);}
	constexpr auto operator|(eth_macdr_r other) const -> eth_macdr_r { return static_cast<eth_macdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macdr_r> other) const -> opsy::utility::clear_set<eth_macdr_r> {return opsy::utility::clear_set<eth_macdr_r>(eth_macdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MAC MII Transmit Protocol Engine Status When this bit is set, it indicates that the MAC MII transmit protocol engine is actively transmitting data, and it is not in the Idle state.
 */
class tpests_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tpests_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macdr_r>() const {return opsy::utility::clear_set<eth_macdr_r>(mask, *this);}
	constexpr auto operator|(eth_macdr_r other) const -> eth_macdr_r { return static_cast<eth_macdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macdr_r> other) const -> opsy::utility::clear_set<eth_macdr_r> {return opsy::utility::clear_set<eth_macdr_r>(eth_macdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Transmit Packet Controller Status This field indicates the state of the MAC Transmit Packet Controller module: Status of the previous packet IPG or backoff period to be over
 */
class tfcsts_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tfcsts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macdr_r>() const {return opsy::utility::clear_set<eth_macdr_r>(mask, *this);}
	constexpr auto operator|(eth_macdr_r other) const -> eth_macdr_r { return static_cast<eth_macdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macdr_r> other) const -> opsy::utility::clear_set<eth_macdr_r> {return opsy::utility::clear_set<eth_macdr_r>(eth_macdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rpests() const -> rpests_f {return rpests_f((value_ & rpests_f::mask) != 0);}
	[[nodiscard]] constexpr auto rfcfcsts() const -> rfcfcsts_f {return rfcfcsts_f(static_cast<uint8_t>(value_ >> rfcfcsts_f::offset));}
	[[nodiscard]] constexpr auto tpests() const -> tpests_f {return tpests_f((value_ & tpests_f::mask) != 0);}
	[[nodiscard]] constexpr auto tfcsts() const -> tfcsts_f {return tfcsts_f(static_cast<uint8_t>(value_ >> tfcsts_f::offset));}

	constexpr eth_macdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macdr_r other) const -> eth_macdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HW feature 0 register
 */
class eth_machwf0r_r {
public:

/**
 * 10 or 100 Mbps Support This bit is set to 1 when 10/100 Mbps is selected as operating mode.
 */
class miisel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr miisel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 1000 Mbps Support This bit is set to 1 when 1000 Mbps is selected as operating mode.
 */
class gmiisel_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr gmiisel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex Support This bit is set to 1 when the Half-duplex mode is selected
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PCS Registers (TBI, SGMII, or RTBI PHY interface) This bit is set to 1 when the TBI, SGMII, or RTBI PHY interface option is selected
 */
class pcssel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pcssel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VLAN Hash Filter Selected This bit is set to 1 when the Enable VLAN Hash Table Based Filtering option is selected
 */
class vlhash_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vlhash_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMA (MDIO) Interface This bit is set to 1 when the Enable Station Management (MDIO Interface) option is selected
 */
class smasel_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr smasel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PMT Remote Wakeup Packet Enable This bit is set to 1 when the Enable Remote wakeup Packet Detection option is selected
 */
class rwksel_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rwksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PMT Magic Packet Enable This bit is set to 1 when the Enable Magic Packet Detection option is selected
 */
class mgksel_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mgksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RMON Module Enable This bit is set to 1 when the Enable MAC management counters (MMC) option is selected
 */
class mmcsel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mmcsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ARP Offload Enabled This bit is set to 1 when the Enable IPv4 ARP Offload option is selected
 */
class arpoffsel_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr arpoffsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IEEE 1588-2008 Timestamp Enabled This bit is set to 1 when the Enable IEEE 1588 Timestamp Support option is selected
 */
class tssel_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tssel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Energy Efficient Ethernet Enabled This bit is set to 1 when the Enable Energy Efficient Ethernet (EEE) option is selected
 */
class eeesel_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eeesel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Checksum Offload Enabled This bit is set to 1 when the Enable Transmit TCP/IP Checksum Insertion option is selected
 */
class txcoesel_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txcoesel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Checksum Offload Enabled This bit is set to 1 when the Enable Receive TCP/IP Checksum Check option is selected
 */
class rxcoesel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxcoesel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Addresses 1-31 Selected This bit is set to 1 when the Enable Additional 1-31 MAC Address Registers option is selected
 */
class addmacadrsel_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr addmacadrsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MAC Addresses 32-63 Selected This bit is set to 1 when the Enable Additional 32 MAC Address Registers (32-63) option is selected
 */
class macadr32sel_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr macadr32sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Addresses 64-127 Selected This bit is set to 1 when the Enable Additional 64 MAC Address Registers (64-127) option is selected
 */
class macadr64sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr macadr64sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp System Time Source This bit indicates the source of the Timestamp system time: This bit is set to 1 when the Enable IEEE 1588 Timestamp Support option is selected
 */
class tsstssel_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsstssel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Source Address or VLAN Insertion Enable This bit is set to 1 when the Enable SA and VLAN Insertion on Tx option is selected
 */
class savlanins_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr savlanins_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active PHY Selected When you have multiple PHY interfaces in your configuration, this field indicates the sampled value of phy_intf_sel_i during reset de-assertion: Others: Reserved, must not be used
 */
class actphysel_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr actphysel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf0r_r>() const {return opsy::utility::clear_set<eth_machwf0r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf0r_r other) const -> eth_machwf0r_r { return static_cast<eth_machwf0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf0r_r> other) const -> opsy::utility::clear_set<eth_machwf0r_r> {return opsy::utility::clear_set<eth_machwf0r_r>(eth_machwf0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto miisel() const -> miisel_f {return miisel_f((value_ & miisel_f::mask) != 0);}
	[[nodiscard]] constexpr auto gmiisel() const -> gmiisel_f {return gmiisel_f((value_ & gmiisel_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto pcssel() const -> pcssel_f {return pcssel_f((value_ & pcssel_f::mask) != 0);}
	[[nodiscard]] constexpr auto vlhash() const -> vlhash_f {return vlhash_f((value_ & vlhash_f::mask) != 0);}
	[[nodiscard]] constexpr auto smasel() const -> smasel_f {return smasel_f((value_ & smasel_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwksel() const -> rwksel_f {return rwksel_f((value_ & rwksel_f::mask) != 0);}
	[[nodiscard]] constexpr auto mgksel() const -> mgksel_f {return mgksel_f((value_ & mgksel_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmcsel() const -> mmcsel_f {return mmcsel_f((value_ & mmcsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto arpoffsel() const -> arpoffsel_f {return arpoffsel_f((value_ & arpoffsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto tssel() const -> tssel_f {return tssel_f((value_ & tssel_f::mask) != 0);}
	[[nodiscard]] constexpr auto eeesel() const -> eeesel_f {return eeesel_f((value_ & eeesel_f::mask) != 0);}
	[[nodiscard]] constexpr auto txcoesel() const -> txcoesel_f {return txcoesel_f((value_ & txcoesel_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxcoesel() const -> rxcoesel_f {return rxcoesel_f((value_ & rxcoesel_f::mask) != 0);}
	[[nodiscard]] constexpr auto addmacadrsel() const -> addmacadrsel_f {return addmacadrsel_f(static_cast<uint8_t>(value_ >> addmacadrsel_f::offset));}
	[[nodiscard]] constexpr auto macadr32sel() const -> macadr32sel_f {return macadr32sel_f((value_ & macadr32sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto macadr64sel() const -> macadr64sel_f {return macadr64sel_f((value_ & macadr64sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsstssel() const -> tsstssel_f {return tsstssel_f(static_cast<uint8_t>(value_ >> tsstssel_f::offset));}
	[[nodiscard]] constexpr auto savlanins() const -> savlanins_f {return savlanins_f((value_ & savlanins_f::mask) != 0);}
	[[nodiscard]] constexpr auto actphysel() const -> actphysel_f {return actphysel_f(static_cast<uint8_t>(value_ >> actphysel_f::offset));}

	constexpr eth_machwf0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_machwf0r_r other) const -> eth_machwf0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_machwf0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1010000011010111001111110111; // 168653815 0xA0D73F7

private:
	uint32_t value_;
};

/**
 * HW feature 1 register
 */
class eth_machwf1r_r {
public:

/**
 * MTL Receive FIFO Size This field contains the configured value of MTL Rx FIFO in bytes expressed as Log to base 2 minus 7, that is, Log2(RXFIFO_SIZE) -7: 01100 to 11111: Reserved, must not be used
 */
class rxfifosize_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxfifosize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MTL Transmit FIFO Size This field contains the configured value of MTL Tx FIFO in bytes expressed as Log to base 2 minus 7, that is, Log2(TXFIFO_SIZE) -7: 01011 to 11111: Reserved, must not be used
 */
class txfifosize_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr txfifosize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * One-Step Timestamping Enable This bit is set to 1 when the Enable One-Step Timestamp Feature is selected.
 */
class osten_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr osten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PTP Offload Enable This bit is set to 1 when the Enable PTP Timestamp Offload Feature is selected.
 */
class ptoen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ptoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IEEE 1588 High Word Register Enable This bit is set to 1 when the Add IEEE 1588 Higher Word Register option is selected
 */
class advthword_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr advthword_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address width This field indicates the configured address width. Others: Reserved, must not be used
 */
class addr64_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addr64_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DCB Feature Enable This bit is set to 1 when the Enable Data Center Bridging option is selected
 */
class dcben_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcben_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Split Header Feature Enable This bit is set to 1 when the Enable Split Header Structure option is selected
 */
class sphen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sphen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TCP Segmentation Offload Enable This bit is set to 1 when the Enable TCP Segmentation Offloading for TCP/IP Packets option is selected
 */
class tsoen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tsoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Debug Registers Enable This bit is set to 1 when the Debug Mode Enable option is selected
 */
class dbgmema_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbgmema_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AV Feature Enable This bit is set to 1 when the Enable Audio video bridging option is selected.
 */
class avsel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr avsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rx Side Only AV Feature Enable This bit is set to 1 when the Enable Audio video bridging option on Rx Side Only is selected.
 */
class ravsel_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ravsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * One Step for PTP over UDP/IP Feature Enable This bit is set to 1 when the Enable one step timestamp for PTP over UDP/IP feature is selected.
 */
class pouost_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pouost_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hash Table Size This field indicates the size of the Hash table:
 */
class hashtblsz_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hashtblsz_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Total number of L3 or L4 Filters This field indicates the total number of L3 or L4 filters: ..
 */
class l3l4fnum_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3l4fnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf1r_r>() const {return opsy::utility::clear_set<eth_machwf1r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf1r_r other) const -> eth_machwf1r_r { return static_cast<eth_machwf1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf1r_r> other) const -> opsy::utility::clear_set<eth_machwf1r_r> {return opsy::utility::clear_set<eth_machwf1r_r>(eth_machwf1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rxfifosize() const -> rxfifosize_f {return rxfifosize_f(static_cast<uint8_t>(value_ >> rxfifosize_f::offset));}
	[[nodiscard]] constexpr auto txfifosize() const -> txfifosize_f {return txfifosize_f(static_cast<uint8_t>(value_ >> txfifosize_f::offset));}
	[[nodiscard]] constexpr auto osten() const -> osten_f {return osten_f((value_ & osten_f::mask) != 0);}
	[[nodiscard]] constexpr auto ptoen() const -> ptoen_f {return ptoen_f((value_ & ptoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto advthword() const -> advthword_f {return advthword_f((value_ & advthword_f::mask) != 0);}
	[[nodiscard]] constexpr auto addr64() const -> addr64_f {return addr64_f(static_cast<uint8_t>(value_ >> addr64_f::offset));}
	[[nodiscard]] constexpr auto dcben() const -> dcben_f {return dcben_f((value_ & dcben_f::mask) != 0);}
	[[nodiscard]] constexpr auto sphen() const -> sphen_f {return sphen_f((value_ & sphen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsoen() const -> tsoen_f {return tsoen_f((value_ & tsoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbgmema() const -> dbgmema_f {return dbgmema_f((value_ & dbgmema_f::mask) != 0);}
	[[nodiscard]] constexpr auto avsel() const -> avsel_f {return avsel_f((value_ & avsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto ravsel() const -> ravsel_f {return ravsel_f((value_ & ravsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto pouost() const -> pouost_f {return pouost_f((value_ & pouost_f::mask) != 0);}
	[[nodiscard]] constexpr auto hashtblsz() const -> hashtblsz_f {return hashtblsz_f(static_cast<uint8_t>(value_ >> hashtblsz_f::offset));}
	[[nodiscard]] constexpr auto l3l4fnum() const -> l3l4fnum_f {return l3l4fnum_f(static_cast<uint8_t>(value_ >> l3l4fnum_f::offset));}

	constexpr eth_machwf1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_machwf1r_r other) const -> eth_machwf1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_machwf1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10001000001000001100100000100; // 285481220 0x11041904

private:
	uint32_t value_;
};

/**
 * HW feature 2 register
 */
class eth_machwf2r_r {
public:

/**
 * Number of MTL Receive Queues This field indicates the number of MTL Receive queues: ..
 */
class rxqcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxqcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of MTL Transmit Queues This field indicates the number of MTL Transmit queues: ..
 */
class txqcnt_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr txqcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of DMA Receive Channels This field indicates the number of DMA Receive channels: ..
 */
class rxchcnt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rxchcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx DMA Descriptor Cache Size in terms of 16-byte descriptors
 */
class rdcsz_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdcsz_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of DMA Transmit Channels This field indicates the number of DMA Transmit channels: ..
 */
class txchcnt_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txchcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Tx DMA Descriptor Cache Size in terms of 16-byte descriptors
 */
class tdcsz_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdcsz_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of PPS Outputs This field indicates the number of PPS outputs: 101 to 111: Reserved, must not be used
 */
class ppsoutnum_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ppsoutnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of Auxiliary Snapshot Inputs This field indicates the number of auxiliary snapshot inputs: 101 to 111: Reserved, must not be used
 */
class auxsnapnum_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr auxsnapnum_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf2r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf2r_r>() const {return opsy::utility::clear_set<eth_machwf2r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf2r_r other) const -> eth_machwf2r_r { return static_cast<eth_machwf2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf2r_r> other) const -> opsy::utility::clear_set<eth_machwf2r_r> {return opsy::utility::clear_set<eth_machwf2r_r>(eth_machwf2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rxqcnt() const -> rxqcnt_f {return rxqcnt_f(static_cast<uint8_t>(value_ >> rxqcnt_f::offset));}
	[[nodiscard]] constexpr auto txqcnt() const -> txqcnt_f {return txqcnt_f(static_cast<uint8_t>(value_ >> txqcnt_f::offset));}
	[[nodiscard]] constexpr auto rxchcnt() const -> rxchcnt_f {return rxchcnt_f(static_cast<uint8_t>(value_ >> rxchcnt_f::offset));}
	[[nodiscard]] constexpr auto rdcsz() const -> rdcsz_f {return rdcsz_f(static_cast<uint8_t>(value_ >> rdcsz_f::offset));}
	[[nodiscard]] constexpr auto txchcnt() const -> txchcnt_f {return txchcnt_f(static_cast<uint8_t>(value_ >> txchcnt_f::offset));}
	[[nodiscard]] constexpr auto tdcsz() const -> tdcsz_f {return tdcsz_f(static_cast<uint8_t>(value_ >> tdcsz_f::offset));}
	[[nodiscard]] constexpr auto ppsoutnum() const -> ppsoutnum_f {return ppsoutnum_f(static_cast<uint8_t>(value_ >> ppsoutnum_f::offset));}
	[[nodiscard]] constexpr auto auxsnapnum() const -> auxsnapnum_f {return auxsnapnum_f(static_cast<uint8_t>(value_ >> auxsnapnum_f::offset));}

	constexpr eth_machwf2r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_machwf2r_r other) const -> eth_machwf2r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_machwf2r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000001000000000000000000000000; // 1090519040 0x41000000

private:
	uint32_t value_;
};

/**
 * HW feature 3 register
 */
class eth_machwf3r_r {
public:

/**
 * Number of Extended VLAN Tag Filters Enabled This field indicates the Number of Extended VLAN Tag Filters selected: 110 to 111: Reserved, must not be used
 */
class nrvf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nrvf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_machwf3r_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_machwf3r_r>() const {return opsy::utility::clear_set<eth_machwf3r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf3r_r other) const -> eth_machwf3r_r { return static_cast<eth_machwf3r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf3r_r> other) const -> opsy::utility::clear_set<eth_machwf3r_r> {return opsy::utility::clear_set<eth_machwf3r_r>(eth_machwf3r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Queue/Channel based VLAN tag insertion on Tx enable This bit is set to 1 when the Enable Queue/Channel based VLAN tag insertion on Tx feature is selected.
 */
class cbtisel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cbtisel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf3r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf3r_r>() const {return opsy::utility::clear_set<eth_machwf3r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf3r_r other) const -> eth_machwf3r_r { return static_cast<eth_machwf3r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf3r_r> other) const -> opsy::utility::clear_set<eth_machwf3r_r> {return opsy::utility::clear_set<eth_machwf3r_r>(eth_machwf3r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Double VLAN processing enable This bit is set to 1 when Double VLAN processing is enabled.
 */
class dvlan_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dvlan_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_machwf3r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_machwf3r_r>() const {return opsy::utility::clear_set<eth_machwf3r_r>(mask, *this);}
	constexpr auto operator|(eth_machwf3r_r other) const -> eth_machwf3r_r { return static_cast<eth_machwf3r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_machwf3r_r> other) const -> opsy::utility::clear_set<eth_machwf3r_r> {return opsy::utility::clear_set<eth_machwf3r_r>(eth_machwf3r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto nrvf() const -> nrvf_f {return nrvf_f(static_cast<uint8_t>(value_ >> nrvf_f::offset));}
	[[nodiscard]] constexpr auto cbtisel() const -> cbtisel_f {return cbtisel_f((value_ & cbtisel_f::mask) != 0);}
	[[nodiscard]] constexpr auto dvlan() const -> dvlan_f {return dvlan_f((value_ & dvlan_f::mask) != 0);}

	constexpr eth_machwf3r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_machwf3r_r other) const -> eth_machwf3r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_machwf3r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000; // 32 0x20

private:
	uint32_t value_;
};

/**
 * MDIO address register
 */
class eth_macmdioar_r {
public:

/**
 * MII Busy The application sets this bit to instruct the SMA to initiate a Read or Write access to the MDIOS. The MAC clears this bit after the MDIO frame transfer is completed. Hence the software must not write or change any of the fields in MDIO address register (ETH_MACMDIOAR) and MDIO data register (ETH_MACMDIODR) as long as this bit is set. For write transfers, the application must first write 16-bit data in the MD field (and also RA field when C45E is set) in MDIO data register (ETH_MACMDIODR) register before setting this bit. When C45E is set, it should also write into the RA field of MDIO data register (ETH_MACMDIODR) before initiating a read transfer. When a read transfer is completed (MII busy=0), the data read from the PHY register is valid in the MD field of the MDIO data register (ETH_MACMDIODR). Note: Even if the addressed PHY is not present, there is no change in the functionality of this bit.
 */
class mb_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clause 45 PHY Enable When this bit is set, Clause 45 capable PHY is connected to MDIO. When this bit is reset, Clause 22 capable PHY is connected to MDIO.
 */
class c45e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr c45e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MII Operation Command This bit indicates the operation command to the PHY. When Clause 22 PHY is enabled, only Write and Read commands are valid.
 */
class goc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr goc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Skip Address Packet When this bit is set, the SMA does not send the address packets before read, write, or post-read increment address packets. This bit is valid only when C45E is set.
 */
class skap_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr skap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CSR Clock Range The CSR Clock Range selection determines the frequency of the MDC clock according to the CSR clock frequency used in your design: 0110 to 0111: Reserved, must not be used The suggested range of CSR clock frequency applicable for each value (when Bit 11 = 0) ensures that the MDC clock is approximately between 1.0 MHz to 2.5 MHz frequency range. When Bit 11 is set, you can achieve a higher frequency of the MDC clock than the frequency limit of 2.5 MHz (specified in the IEEE 802.3) and program a clock divider of lower value. For example, when CSR clock is of 100 MHz frequency and you program these bits to 1010, the resultant MDC clock is of 12.5 MHz which is above the range specified in IEEE 802.3. Program the following values only if the interfacing chips support faster MDC clocks:
 */
class cr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of Training Clocks This field controls the number of trailing clock cycles generated on ETH_MDC after the end of transmission of MDIO frame. The valid values can be from 0 to 7. Programming the value to 011 indicates that there are additional three clock cycles on the MDC line after the end of MDIO frame transfer.
 */
class ntc_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ntc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Register/Device Address These bits select the PHY register in selected Clause 22 PHY device. These bits select the Device (MMD) in selected Clause 45 capable PHY.
 */
class rda_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rda_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Physical Layer Address This field indicates which Clause 22 PHY devices (out of 32 devices) the MAC is accessing. This field indicates which Clause 45 capable PHYs (out of 32 PHYs) the MAC is accessing.
 */
class pa_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pa_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Back to Back transactions When this bit is set and the NTC has value greater than 0, then the MAC informs the completion of a read or write command at the end of frame transfer (before the trailing clocks are transmitted). The software can thus initiate the next command which is executed immediately irrespective of the number trailing clocks generated for the previous frame. When this bit is reset, then the read/write command completion (MII busy is cleared) only after the trailing clocks are generated. In this mode, it is ensured that the NTC is always generated after each frame. This bit must not be set when NTC=0.
 */
class btb_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr btb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Preamble Suppression Enable When this bit is set, the SMA suppresses the 32-bit preamble and transmit MDIO frames with only 1 preamble bit. When this bit is 0, the MDIO frame always has 32 bits of preamble as defined in the IEEE specifications.
 */
class pse_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macmdioar_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macmdioar_r>() const {return opsy::utility::clear_set<eth_macmdioar_r>(mask, *this);}
	constexpr auto operator|(eth_macmdioar_r other) const -> eth_macmdioar_r { return static_cast<eth_macmdioar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdioar_r> other) const -> opsy::utility::clear_set<eth_macmdioar_r> {return opsy::utility::clear_set<eth_macmdioar_r>(eth_macmdioar_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mb() const -> mb_f {return mb_f((value_ & mb_f::mask) != 0);}
	[[nodiscard]] constexpr auto c45e() const -> c45e_f {return c45e_f((value_ & c45e_f::mask) != 0);}
	[[nodiscard]] constexpr auto goc() const -> goc_f {return goc_f(static_cast<uint8_t>(value_ >> goc_f::offset));}
	[[nodiscard]] constexpr auto skap() const -> skap_f {return skap_f((value_ & skap_f::mask) != 0);}
	[[nodiscard]] constexpr auto cr() const -> cr_f {return cr_f(static_cast<uint8_t>(value_ >> cr_f::offset));}
	[[nodiscard]] constexpr auto ntc() const -> ntc_f {return ntc_f(static_cast<uint8_t>(value_ >> ntc_f::offset));}
	[[nodiscard]] constexpr auto rda() const -> rda_f {return rda_f(static_cast<uint8_t>(value_ >> rda_f::offset));}
	[[nodiscard]] constexpr auto pa() const -> pa_f {return pa_f(static_cast<uint8_t>(value_ >> pa_f::offset));}
	[[nodiscard]] constexpr auto btb() const -> btb_f {return btb_f((value_ & btb_f::mask) != 0);}
	[[nodiscard]] constexpr auto pse() const -> pse_f {return pse_f((value_ & pse_f::mask) != 0);}

	constexpr eth_macmdioar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macmdioar_r other) const -> eth_macmdioar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macmdioar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MDIO data register
 */
class eth_macmdiodr_r {
public:

/**
 * MII Data This field contains the 16-bit data value read from the PHY after a Management Read operation or the 16-bit data value to be written to the PHY before a Management Write operation.
 */
class md_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr md_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macmdiodr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdiodr_r>() const {return opsy::utility::clear_set<eth_macmdiodr_r>(mask, *this);}
	constexpr auto operator|(eth_macmdiodr_r other) const -> eth_macmdiodr_r { return static_cast<eth_macmdiodr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdiodr_r> other) const -> opsy::utility::clear_set<eth_macmdiodr_r> {return opsy::utility::clear_set<eth_macmdiodr_r>(eth_macmdiodr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Register Address This field is valid only when C45E is set. It contains the Register Address in the PHY to which the MDIO frame is intended for.
 */
class ra_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ra_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macmdiodr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macmdiodr_r>() const {return opsy::utility::clear_set<eth_macmdiodr_r>(mask, *this);}
	constexpr auto operator|(eth_macmdiodr_r other) const -> eth_macmdiodr_r { return static_cast<eth_macmdiodr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macmdiodr_r> other) const -> opsy::utility::clear_set<eth_macmdiodr_r> {return opsy::utility::clear_set<eth_macmdiodr_r>(eth_macmdiodr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto md() const -> md_f {return md_f(static_cast<uint16_t>(value_ >> md_f::offset));}
	[[nodiscard]] constexpr auto ra() const -> ra_f {return ra_f(static_cast<uint16_t>(value_ >> ra_f::offset));}

	constexpr eth_macmdiodr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macmdiodr_r other) const -> eth_macmdiodr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macmdiodr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * ARP address register
 */
class eth_macarpar_r {
public:

/**
 * ARP Protocol Address This field contains the IPv4 Destination Address of the MAC. This address is used for perfect match with the Protocol Address of Target field in the received ARP packet.
 */
class arppa_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr arppa_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macarpar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macarpar_r>() const {return opsy::utility::clear_set<eth_macarpar_r>(mask, *this);}
	constexpr auto operator|(eth_macarpar_r other) const -> eth_macarpar_r { return static_cast<eth_macarpar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macarpar_r> other) const -> opsy::utility::clear_set<eth_macarpar_r> {return opsy::utility::clear_set<eth_macarpar_r>(eth_macarpar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto arppa() const -> arppa_f {return arppa_f(static_cast<uint32_t>(value_ >> arppa_f::offset));}

	constexpr eth_macarpar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macarpar_r other) const -> eth_macarpar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macarpar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * CSR software control register
 */
class eth_maccsrswcr_r {
public:

/**
 * Register Clear on Write 1 Enable When this bit is set, the access mode to some register fields changes to rc_w1 (clear on write) meaning that the application needs to set that respective bit to 1 to clear it. When this bit is reset, the access mode to these register fields remains rc_r (clear on read).
 */
class rcwe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rcwe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccsrswcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccsrswcr_r>() const {return opsy::utility::clear_set<eth_maccsrswcr_r>(mask, *this);}
	constexpr auto operator|(eth_maccsrswcr_r other) const -> eth_maccsrswcr_r { return static_cast<eth_maccsrswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccsrswcr_r> other) const -> opsy::utility::clear_set<eth_maccsrswcr_r> {return opsy::utility::clear_set<eth_maccsrswcr_r>(eth_maccsrswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Slave Error Response Enable When this bit is set, the MAC responds with a Slave Error for accesses to reserved registers in CSR space. When this bit is reset, the MAC responds with an Okay response to any register accessed from CSR space.
 */
class seen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr seen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maccsrswcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maccsrswcr_r>() const {return opsy::utility::clear_set<eth_maccsrswcr_r>(mask, *this);}
	constexpr auto operator|(eth_maccsrswcr_r other) const -> eth_maccsrswcr_r { return static_cast<eth_maccsrswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maccsrswcr_r> other) const -> opsy::utility::clear_set<eth_maccsrswcr_r> {return opsy::utility::clear_set<eth_maccsrswcr_r>(eth_maccsrswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rcwe() const -> rcwe_f {return rcwe_f((value_ & rcwe_f::mask) != 0);}
	[[nodiscard]] constexpr auto seen() const -> seen_f {return seen_f((value_ & seen_f::mask) != 0);}

	constexpr eth_maccsrswcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_maccsrswcr_r other) const -> eth_maccsrswcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_maccsrswcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MAC Address 0 high register
 */
class eth_maca0hr_r {
public:

/**
 * MAC Address0[47:32] This field contains the upper 16 bits [47:32] of the first 6-byte MAC address. The MAC uses this field for filtering the received packets and inserting the MAC address in the Transmit Flow Control (Pause) Packets.
 */
class addrhi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addrhi_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_maca0hr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maca0hr_r>() const {return opsy::utility::clear_set<eth_maca0hr_r>(mask, *this);}
	constexpr auto operator|(eth_maca0hr_r other) const -> eth_maca0hr_r { return static_cast<eth_maca0hr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maca0hr_r> other) const -> opsy::utility::clear_set<eth_maca0hr_r> {return opsy::utility::clear_set<eth_maca0hr_r>(eth_maca0hr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Address Enable This bit is always set to 1.
 */
class ae_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_maca0hr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_maca0hr_r>() const {return opsy::utility::clear_set<eth_maca0hr_r>(mask, *this);}
	constexpr auto operator|(eth_maca0hr_r other) const -> eth_maca0hr_r { return static_cast<eth_maca0hr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maca0hr_r> other) const -> opsy::utility::clear_set<eth_maca0hr_r> {return opsy::utility::clear_set<eth_maca0hr_r>(eth_maca0hr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addrhi() const -> addrhi_f {return addrhi_f(static_cast<uint16_t>(value_ >> addrhi_f::offset));}
	[[nodiscard]] constexpr auto ae() const -> ae_f {return ae_f((value_ & ae_f::mask) != 0);}

	constexpr eth_maca0hr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_maca0hr_r other) const -> eth_maca0hr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_maca0hr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000001111111111111111; // 2147549183 0x8000FFFF

private:
	uint32_t value_;
};

/**
 * MAC Address X low register
 */
class eth_macaxlr_r {
public:

/**
 * MAC Address x [31:0] This field contains the lower 32 bits of the first 6-byte MAC address. The MAC uses this field for filtering the received packets and inserting the MAC address in the Transmit Flow Control (Pause) Packets.
 */
class addrlo_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr addrlo_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macaxlr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macaxlr_r>() const {return opsy::utility::clear_set<eth_macaxlr_r>(mask, *this);}
	constexpr auto operator|(eth_macaxlr_r other) const -> eth_macaxlr_r { return static_cast<eth_macaxlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macaxlr_r> other) const -> opsy::utility::clear_set<eth_macaxlr_r> {return opsy::utility::clear_set<eth_macaxlr_r>(eth_macaxlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto addrlo() const -> addrlo_f {return addrlo_f(static_cast<uint32_t>(value_ >> addrlo_f::offset));}

	constexpr eth_macaxlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macaxlr_r other) const -> eth_macaxlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macaxlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

/**
 * MAC Address X high register
 */
class eth_macaxhr_r {
public:

/**
 * MAC Address1 [47:32] This field contains the upper 16 bits[47:32] of the second 6-byte MAC address.
 */
class addrhi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addrhi_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macaxhr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macaxhr_r>() const {return opsy::utility::clear_set<eth_macaxhr_r>(mask, *this);}
	constexpr auto operator|(eth_macaxhr_r other) const -> eth_macaxhr_r { return static_cast<eth_macaxhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macaxhr_r> other) const -> opsy::utility::clear_set<eth_macaxhr_r> {return opsy::utility::clear_set<eth_macaxhr_r>(eth_macaxhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Mask Byte Control These bits are mask control bits for comparing each of the MAC Address bytes. When set high, the MAC does not compare the corresponding byte of received DA or SA with the contents of MAC Address1 registers. Each bit controls the masking of the bytes as follows: Bit 29: ETH_MACAxHR[15:8] Bit 28: ETH_MACAxHR[7:0] Bit 27: ETH_MACAxLR[31:24] Bit 26: ETH_MACAxLR[23:16] Bit 25: ETH_MACAxLR[15:8] Bit 24: ETH_MACAxLR[7:0] You can filter a group of addresses (known as group address filtering) by masking one or more bytes of the address.
 */
class mbc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mbc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macaxhr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macaxhr_r>() const {return opsy::utility::clear_set<eth_macaxhr_r>(mask, *this);}
	constexpr auto operator|(eth_macaxhr_r other) const -> eth_macaxhr_r { return static_cast<eth_macaxhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macaxhr_r> other) const -> opsy::utility::clear_set<eth_macaxhr_r> {return opsy::utility::clear_set<eth_macaxhr_r>(eth_macaxhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Source Address When this bit is set, the MAC Addressx[47:0] is used to compare with the SA fields of the received packet. When this bit is reset, the MAC Address x[47:0] is used to compare with the DA fields of the received packet.
 */
class sa_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macaxhr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macaxhr_r>() const {return opsy::utility::clear_set<eth_macaxhr_r>(mask, *this);}
	constexpr auto operator|(eth_macaxhr_r other) const -> eth_macaxhr_r { return static_cast<eth_macaxhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macaxhr_r> other) const -> opsy::utility::clear_set<eth_macaxhr_r> {return opsy::utility::clear_set<eth_macaxhr_r>(eth_macaxhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address Enable When this bit is set, the address filter module uses the second MAC address for perfect filtering. When this bit is reset, the address filter module ignores the address for filtering.
 */
class ae_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macaxhr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macaxhr_r>() const {return opsy::utility::clear_set<eth_macaxhr_r>(mask, *this);}
	constexpr auto operator|(eth_macaxhr_r other) const -> eth_macaxhr_r { return static_cast<eth_macaxhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macaxhr_r> other) const -> opsy::utility::clear_set<eth_macaxhr_r> {return opsy::utility::clear_set<eth_macaxhr_r>(eth_macaxhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addrhi() const -> addrhi_f {return addrhi_f(static_cast<uint16_t>(value_ >> addrhi_f::offset));}
	[[nodiscard]] constexpr auto mbc() const -> mbc_f {return mbc_f(static_cast<uint8_t>(value_ >> mbc_f::offset));}
	[[nodiscard]] constexpr auto sa() const -> sa_f {return sa_f((value_ & sa_f::mask) != 0);}
	[[nodiscard]] constexpr auto ae() const -> ae_f {return ae_f((value_ & ae_f::mask) != 0);}

	constexpr eth_macaxhr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macaxhr_r other) const -> eth_macaxhr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macaxhr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111; // 65535 0xFFFF

private:
	uint32_t value_;
};

/**
 * MMC control register
 */
class eth_mmc_control_r {
public:

/**
 * Counters Reset When this bit is set, all counters are reset. This bit is cleared automatically after 1 clock cycle.
 */
class cntrst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter Stop Rollover When this bit is set, the counter does not roll over to zero after reaching the maximum value.
 */
class cntstopro_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntstopro_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reset on Read When this bit is set, the MMC counters are reset to zero after Read (self-clearing after reset). The counters are cleared when the least significant byte lane (Bits[7:0]) is read.
 */
class rstonrd_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rstonrd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Counter Freeze When this bit is set, it freezes all MMC counters to their current value. Until this bit is reset to 0, no MMC counter is updated because of any transmitted or received packet. If any MMC counter is read with the Reset on Read bit set, then that counter is also cleared in this mode.
 */
class cntfreez_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntfreez_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counters Preset When this bit is set, all counters are initialized or preset to almost full or almost half according to the CNTPRSTLVL bit. This bit is cleared automatically after 1 clock cycle. This bit, along with the CNTPRSTLVL bit, is useful for debugging and testing the assertion of interrupts because of MMC counter becoming half-full or full.
 */
class cntprst_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntprst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Full-Half Preset When this bit is low and the CNTPRST bit is set, all MMC counters get preset to almost-half value. All octet counters get preset to 0x7FFF_F800 (Half 2Kbytes) and all packet-counters get preset to 0x7FFF_FFF0 (Half 16). When this bit is high and the CNTPRST bit is set, all MMC counters get preset to almost-full value. All octet counters get preset to 0xFFFF_F800 (Full 2Kbytes) and all packet-counters get preset to 0xFFFF_FFF0 (Full 16). For 16-bit counters, the almost-half preset values are 0x7800 and 0x7FF0 for the respective octet and packet counters. Similarly, the almost-full preset values for the 16-bit counters are 0xF800 and 0xFFF0.
 */
class cntprstlvl_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntprstlvl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update MMC Counters for Dropped Broadcast Packets The CNTRST bit has a higher priority than the CNTPRST bit. Therefore, when the software tries to set both bits in the same write cycle, all counters are cleared and the CNTPRST bit is not set. When set, the MAC updates all related MMC Counters for Broadcast packets that are dropped because of the setting of the DBF bit of Packet filtering control register (ETH_MACPFR). When reset, the MMC Counters are not updated for dropped Broadcast packets.
 */
class ucdbc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ucdbc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_control_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_control_r>() const {return opsy::utility::clear_set<eth_mmc_control_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_control_r other) const -> eth_mmc_control_r { return static_cast<eth_mmc_control_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_control_r> other) const -> opsy::utility::clear_set<eth_mmc_control_r> {return opsy::utility::clear_set<eth_mmc_control_r>(eth_mmc_control_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cntrst() const -> cntrst_f {return cntrst_f((value_ & cntrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntstopro() const -> cntstopro_f {return cntstopro_f((value_ & cntstopro_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstonrd() const -> rstonrd_f {return rstonrd_f((value_ & rstonrd_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntfreez() const -> cntfreez_f {return cntfreez_f((value_ & cntfreez_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntprst() const -> cntprst_f {return cntprst_f((value_ & cntprst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntprstlvl() const -> cntprstlvl_f {return cntprstlvl_f((value_ & cntprstlvl_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucdbc() const -> ucdbc_f {return ucdbc_f((value_ & ucdbc_f::mask) != 0);}

	constexpr eth_mmc_control_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mmc_control_r other) const -> eth_mmc_control_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mmc_control_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MMC Rx interrupt register
 */
class eth_mmc_rx_interrupt_r {
public:

/**
 * MMC Receive CRC Error Packet Counter Interrupt Status This bit is set when the Rx CRC error packets register (ETH_RX_CRC_ERROR_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class rxcrcerpis_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxcrcerpis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return static_cast<eth_mmc_rx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(eth_mmc_rx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive Alignment Error Packet Counter Interrupt Status This bit is set when the Rx alignment error packets register (ETH_RX_ALIGNMENT_ERROR_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class rxalgnerpis_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxalgnerpis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return static_cast<eth_mmc_rx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(eth_mmc_rx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive Unicast Good Packet Counter Interrupt Status This bit is set when the Rx unicast packets good register (ETH_RX_UNICAST_PACKETS_GOOD) counter reaches half of the maximum value or the maximum value.
 */
class rxucgpis_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxucgpis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return static_cast<eth_mmc_rx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(eth_mmc_rx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive LPI microsecond counter interrupt status This bit is set when the Rx LPI microsecond counter register (ETH_RX_LPI_USEC_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class rxlpiuscis_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxlpiuscis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return static_cast<eth_mmc_rx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(eth_mmc_rx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive LPI transition counter interrupt status This bit is set when the Rx LPI transition counter register (ETH_RX_LPI_TRAN_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class rxlpitrcis_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxlpitrcis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return static_cast<eth_mmc_rx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_r>(eth_mmc_rx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rxcrcerpis() const -> rxcrcerpis_f {return rxcrcerpis_f((value_ & rxcrcerpis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxalgnerpis() const -> rxalgnerpis_f {return rxalgnerpis_f((value_ & rxalgnerpis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxucgpis() const -> rxucgpis_f {return rxucgpis_f((value_ & rxucgpis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxlpiuscis() const -> rxlpiuscis_f {return rxlpiuscis_f((value_ & rxlpiuscis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxlpitrcis() const -> rxlpitrcis_f {return rxlpitrcis_f((value_ & rxlpitrcis_f::mask) != 0);}

	constexpr eth_mmc_rx_interrupt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mmc_rx_interrupt_r other) const -> eth_mmc_rx_interrupt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mmc_rx_interrupt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MMC Tx interrupt register
 */
class eth_mmc_tx_interrupt_r {
public:

/**
 * MMC Transmit Single Collision Good Packet Counter Interrupt Status This bit is set when the Tx single collision good packets register (ETH_TX_SINGLE_COLLISION_GOOD_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class txscolgpis_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txscolgpis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return static_cast<eth_mmc_tx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(eth_mmc_tx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit Multiple Collision Good Packet Counter Interrupt Status This bit is set when the Tx multiple collision good packets register (ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class txmcolgpis_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txmcolgpis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return static_cast<eth_mmc_tx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(eth_mmc_tx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit Good Packet Counter Interrupt Status This bit is set when the Tx packet count good register (ETH_TX_PACKET_COUNT_GOOD) counter reaches half of the maximum value or the maximum value.
 */
class txgpktis_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txgpktis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return static_cast<eth_mmc_tx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(eth_mmc_tx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit LPI microsecond counter interrupt status This bit is set when the Tx LPI microsecond timer register (ETH_TX_LPI_USEC_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class txlpiuscis_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txlpiuscis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return static_cast<eth_mmc_tx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(eth_mmc_tx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit LPI transition counter interrupt status This bit is set when the Tx LPI transition counter register (ETH_TX_LPI_TRAN_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class txlpitrcis_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txlpitrcis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return static_cast<eth_mmc_tx_interrupt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_r>(eth_mmc_tx_interrupt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txscolgpis() const -> txscolgpis_f {return txscolgpis_f((value_ & txscolgpis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmcolgpis() const -> txmcolgpis_f {return txmcolgpis_f((value_ & txmcolgpis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txgpktis() const -> txgpktis_f {return txgpktis_f((value_ & txgpktis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txlpiuscis() const -> txlpiuscis_f {return txlpiuscis_f((value_ & txlpiuscis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txlpitrcis() const -> txlpitrcis_f {return txlpitrcis_f((value_ & txlpitrcis_f::mask) != 0);}

	constexpr eth_mmc_tx_interrupt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mmc_tx_interrupt_r other) const -> eth_mmc_tx_interrupt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mmc_tx_interrupt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MMC Rx interrupt mask register
 */
class eth_mmc_rx_interrupt_mask_r {
public:

/**
 * MMC Receive CRC Error Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Rx CRC error packets register (ETH_RX_CRC_ERROR_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class rxcrcerpim_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxcrcerpim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return static_cast<eth_mmc_rx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(eth_mmc_rx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive Alignment Error Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Rx alignment error packets register (ETH_RX_ALIGNMENT_ERROR_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class rxalgnerpim_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxalgnerpim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return static_cast<eth_mmc_rx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(eth_mmc_rx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive Unicast Good Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Rx unicast packets good register (ETH_RX_UNICAST_PACKETS_GOOD) counter reaches half of the maximum value or the maximum value.
 */
class rxucgpim_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxucgpim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return static_cast<eth_mmc_rx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(eth_mmc_rx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive LPI microsecond counter interrupt Mask Setting this bit masks the interrupt when the Rx LPI microsecond counter register (ETH_RX_LPI_USEC_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class rxlpiuscim_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxlpiuscim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return static_cast<eth_mmc_rx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(eth_mmc_rx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Receive LPI transition counter interrupt Mask Setting this bit masks the interrupt when the Rx LPI transition counter register (ETH_RX_LPI_TRAN_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class rxlpitrcim_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxlpitrcim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_rx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return static_cast<eth_mmc_rx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_rx_interrupt_mask_r>(eth_mmc_rx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rxcrcerpim() const -> rxcrcerpim_f {return rxcrcerpim_f((value_ & rxcrcerpim_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxalgnerpim() const -> rxalgnerpim_f {return rxalgnerpim_f((value_ & rxalgnerpim_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxucgpim() const -> rxucgpim_f {return rxucgpim_f((value_ & rxucgpim_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxlpiuscim() const -> rxlpiuscim_f {return rxlpiuscim_f((value_ & rxlpiuscim_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxlpitrcim() const -> rxlpitrcim_f {return rxlpitrcim_f((value_ & rxlpitrcim_f::mask) != 0);}

	constexpr eth_mmc_rx_interrupt_mask_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mmc_rx_interrupt_mask_r other) const -> eth_mmc_rx_interrupt_mask_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mmc_rx_interrupt_mask_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * MMC Tx interrupt mask register
 */
class eth_mmc_tx_interrupt_mask_r {
public:

/**
 * MMC Transmit Single Collision Good Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Tx single collision good packets register (ETH_TX_SINGLE_COLLISION_GOOD_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class txscolgpim_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txscolgpim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return static_cast<eth_mmc_tx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(eth_mmc_tx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit Multiple Collision Good Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Tx multiple collision good packets register (ETH_TX_MULTIPLE_COLLISION_GOOD_PACKETS) counter reaches half of the maximum value or the maximum value.
 */
class txmcolgpim_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txmcolgpim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return static_cast<eth_mmc_tx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(eth_mmc_tx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit Good Packet Counter Interrupt Mask Setting this bit masks the interrupt when the Tx packet count good register (ETH_TX_PACKET_COUNT_GOOD) counter reaches half of the maximum value or the maximum value.
 */
class txgpktim_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txgpktim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return static_cast<eth_mmc_tx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(eth_mmc_tx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit LPI microsecond counter interrupt Mask Setting this bit masks the interrupt when the Tx LPI microsecond timer register (ETH_TX_LPI_USEC_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class txlpiuscim_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txlpiuscim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return static_cast<eth_mmc_tx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(eth_mmc_tx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMC Transmit LPI transition counter interrupt Mask Setting this bit masks the interrupt when the Tx LPI transition counter register (ETH_TX_LPI_TRAN_CNTR) counter reaches half of the maximum value or the maximum value.
 */
class txlpitrcim_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txlpitrcim_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mmc_tx_interrupt_mask_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>() const {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(mask, *this);}
	constexpr auto operator|(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return static_cast<eth_mmc_tx_interrupt_mask_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> other) const -> opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r> {return opsy::utility::clear_set<eth_mmc_tx_interrupt_mask_r>(eth_mmc_tx_interrupt_mask_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txscolgpim() const -> txscolgpim_f {return txscolgpim_f((value_ & txscolgpim_f::mask) != 0);}
	[[nodiscard]] constexpr auto txmcolgpim() const -> txmcolgpim_f {return txmcolgpim_f((value_ & txmcolgpim_f::mask) != 0);}
	[[nodiscard]] constexpr auto txgpktim() const -> txgpktim_f {return txgpktim_f((value_ & txgpktim_f::mask) != 0);}
	[[nodiscard]] constexpr auto txlpiuscim() const -> txlpiuscim_f {return txlpiuscim_f((value_ & txlpiuscim_f::mask) != 0);}
	[[nodiscard]] constexpr auto txlpitrcim() const -> txlpitrcim_f {return txlpitrcim_f((value_ & txlpitrcim_f::mask) != 0);}

	constexpr eth_mmc_tx_interrupt_mask_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mmc_tx_interrupt_mask_r other) const -> eth_mmc_tx_interrupt_mask_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mmc_tx_interrupt_mask_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx single collision good packets register
 */
class eth_tx_single_collision_good_packets_r {
public:

/**
 * Tx Single Collision Good Packets This field indicates the number of successfully transmitted packets after a single collision in the Half-duplex mode.
 */
class txsnglcolg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txsnglcolg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_tx_single_collision_good_packets_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_tx_single_collision_good_packets_r>() const {return opsy::utility::clear_set<eth_tx_single_collision_good_packets_r>(mask, *this);}
	constexpr auto operator|(eth_tx_single_collision_good_packets_r other) const -> eth_tx_single_collision_good_packets_r { return static_cast<eth_tx_single_collision_good_packets_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_tx_single_collision_good_packets_r> other) const -> opsy::utility::clear_set<eth_tx_single_collision_good_packets_r> {return opsy::utility::clear_set<eth_tx_single_collision_good_packets_r>(eth_tx_single_collision_good_packets_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txsnglcolg() const -> txsnglcolg_f {return txsnglcolg_f(static_cast<uint32_t>(value_ >> txsnglcolg_f::offset));}

	constexpr eth_tx_single_collision_good_packets_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_tx_single_collision_good_packets_r other) const -> eth_tx_single_collision_good_packets_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_tx_single_collision_good_packets_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx multiple collision good packets register
 */
class eth_tx_multiple_collision_good_packets_r {
public:

/**
 * Tx Multiple Collision Good Packets This field indicates the number of successfully transmitted packets after multiple collisions in the Half-duplex mode.
 */
class txmultcolg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txmultcolg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_tx_multiple_collision_good_packets_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_tx_multiple_collision_good_packets_r>() const {return opsy::utility::clear_set<eth_tx_multiple_collision_good_packets_r>(mask, *this);}
	constexpr auto operator|(eth_tx_multiple_collision_good_packets_r other) const -> eth_tx_multiple_collision_good_packets_r { return static_cast<eth_tx_multiple_collision_good_packets_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_tx_multiple_collision_good_packets_r> other) const -> opsy::utility::clear_set<eth_tx_multiple_collision_good_packets_r> {return opsy::utility::clear_set<eth_tx_multiple_collision_good_packets_r>(eth_tx_multiple_collision_good_packets_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txmultcolg() const -> txmultcolg_f {return txmultcolg_f(static_cast<uint32_t>(value_ >> txmultcolg_f::offset));}

	constexpr eth_tx_multiple_collision_good_packets_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_tx_multiple_collision_good_packets_r other) const -> eth_tx_multiple_collision_good_packets_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_tx_multiple_collision_good_packets_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx packet count good register
 */
class eth_tx_packet_count_good_r {
public:

/**
 * Tx Packet Count Good This field indicates the number of good packets transmitted.
 */
class txpktg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txpktg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_tx_packet_count_good_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_tx_packet_count_good_r>() const {return opsy::utility::clear_set<eth_tx_packet_count_good_r>(mask, *this);}
	constexpr auto operator|(eth_tx_packet_count_good_r other) const -> eth_tx_packet_count_good_r { return static_cast<eth_tx_packet_count_good_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_tx_packet_count_good_r> other) const -> opsy::utility::clear_set<eth_tx_packet_count_good_r> {return opsy::utility::clear_set<eth_tx_packet_count_good_r>(eth_tx_packet_count_good_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txpktg() const -> txpktg_f {return txpktg_f(static_cast<uint32_t>(value_ >> txpktg_f::offset));}

	constexpr eth_tx_packet_count_good_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_tx_packet_count_good_r other) const -> eth_tx_packet_count_good_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_tx_packet_count_good_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx CRC error packets register
 */
class eth_rx_crc_error_packets_r {
public:

/**
 * Rx CRC Error Packets This field indicates the number of packets received with CRC error.
 */
class rxcrcerr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxcrcerr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_rx_crc_error_packets_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_rx_crc_error_packets_r>() const {return opsy::utility::clear_set<eth_rx_crc_error_packets_r>(mask, *this);}
	constexpr auto operator|(eth_rx_crc_error_packets_r other) const -> eth_rx_crc_error_packets_r { return static_cast<eth_rx_crc_error_packets_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_rx_crc_error_packets_r> other) const -> opsy::utility::clear_set<eth_rx_crc_error_packets_r> {return opsy::utility::clear_set<eth_rx_crc_error_packets_r>(eth_rx_crc_error_packets_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxcrcerr() const -> rxcrcerr_f {return rxcrcerr_f(static_cast<uint32_t>(value_ >> rxcrcerr_f::offset));}

	constexpr eth_rx_crc_error_packets_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_rx_crc_error_packets_r other) const -> eth_rx_crc_error_packets_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_rx_crc_error_packets_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx alignment error packets register
 */
class eth_rx_alignment_error_packets_r {
public:

/**
 * Rx Alignment Error Packets This field indicates the number of packets received with alignment (dribble) error. It is valid only in 10/100 mode.
 */
class rxalgnerr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxalgnerr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_rx_alignment_error_packets_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_rx_alignment_error_packets_r>() const {return opsy::utility::clear_set<eth_rx_alignment_error_packets_r>(mask, *this);}
	constexpr auto operator|(eth_rx_alignment_error_packets_r other) const -> eth_rx_alignment_error_packets_r { return static_cast<eth_rx_alignment_error_packets_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_rx_alignment_error_packets_r> other) const -> opsy::utility::clear_set<eth_rx_alignment_error_packets_r> {return opsy::utility::clear_set<eth_rx_alignment_error_packets_r>(eth_rx_alignment_error_packets_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxalgnerr() const -> rxalgnerr_f {return rxalgnerr_f(static_cast<uint32_t>(value_ >> rxalgnerr_f::offset));}

	constexpr eth_rx_alignment_error_packets_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_rx_alignment_error_packets_r other) const -> eth_rx_alignment_error_packets_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_rx_alignment_error_packets_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx unicast packets good register
 */
class eth_rx_unicast_packets_good_r {
public:

/**
 * Rx Unicast Packets Good This field indicates the number of good unicast packets received.
 */
class rxucastg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxucastg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_rx_unicast_packets_good_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_rx_unicast_packets_good_r>() const {return opsy::utility::clear_set<eth_rx_unicast_packets_good_r>(mask, *this);}
	constexpr auto operator|(eth_rx_unicast_packets_good_r other) const -> eth_rx_unicast_packets_good_r { return static_cast<eth_rx_unicast_packets_good_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_rx_unicast_packets_good_r> other) const -> opsy::utility::clear_set<eth_rx_unicast_packets_good_r> {return opsy::utility::clear_set<eth_rx_unicast_packets_good_r>(eth_rx_unicast_packets_good_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxucastg() const -> rxucastg_f {return rxucastg_f(static_cast<uint32_t>(value_ >> rxucastg_f::offset));}

	constexpr eth_rx_unicast_packets_good_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_rx_unicast_packets_good_r other) const -> eth_rx_unicast_packets_good_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_rx_unicast_packets_good_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx LPI microsecond timer register
 */
class eth_tx_lpi_usec_cntr_r {
public:

/**
 * Tx LPI Microseconds Counter This field indicates the number of microseconds Tx LPI is asserted. For every Tx LPI Entry and Exit, the Timer value can have an error of +/- 1 microsecond.
 */
class txlpiusc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txlpiusc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_tx_lpi_usec_cntr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_tx_lpi_usec_cntr_r>() const {return opsy::utility::clear_set<eth_tx_lpi_usec_cntr_r>(mask, *this);}
	constexpr auto operator|(eth_tx_lpi_usec_cntr_r other) const -> eth_tx_lpi_usec_cntr_r { return static_cast<eth_tx_lpi_usec_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_tx_lpi_usec_cntr_r> other) const -> opsy::utility::clear_set<eth_tx_lpi_usec_cntr_r> {return opsy::utility::clear_set<eth_tx_lpi_usec_cntr_r>(eth_tx_lpi_usec_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txlpiusc() const -> txlpiusc_f {return txlpiusc_f(static_cast<uint32_t>(value_ >> txlpiusc_f::offset));}

	constexpr eth_tx_lpi_usec_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_tx_lpi_usec_cntr_r other) const -> eth_tx_lpi_usec_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_tx_lpi_usec_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx LPI transition counter register
 */
class eth_tx_lpi_tran_cntr_r {
public:

/**
 * Tx LPI Transition counter This field indicates the number of times Tx LPI Entry has occurred. Even if Tx LPI Entry occurs in Automate mode (because of LPITXA bit set in the LPI control and status register (ETH_MACLCSR)), the counter is incremented.
 */
class txlpitrc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txlpitrc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_tx_lpi_tran_cntr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_tx_lpi_tran_cntr_r>() const {return opsy::utility::clear_set<eth_tx_lpi_tran_cntr_r>(mask, *this);}
	constexpr auto operator|(eth_tx_lpi_tran_cntr_r other) const -> eth_tx_lpi_tran_cntr_r { return static_cast<eth_tx_lpi_tran_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_tx_lpi_tran_cntr_r> other) const -> opsy::utility::clear_set<eth_tx_lpi_tran_cntr_r> {return opsy::utility::clear_set<eth_tx_lpi_tran_cntr_r>(eth_tx_lpi_tran_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txlpitrc() const -> txlpitrc_f {return txlpitrc_f(static_cast<uint32_t>(value_ >> txlpitrc_f::offset));}

	constexpr eth_tx_lpi_tran_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_tx_lpi_tran_cntr_r other) const -> eth_tx_lpi_tran_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_tx_lpi_tran_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx LPI microsecond counter register
 */
class eth_rx_lpi_usec_cntr_r {
public:

/**
 * Rx LPI Microseconds Counter This field indicates the number of microseconds Rx LPI is asserted. For every Rx LPI Entry and Exit, the Timer value can have an error of +/- 1 microsecond.
 */
class rxlpiusc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxlpiusc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_rx_lpi_usec_cntr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_rx_lpi_usec_cntr_r>() const {return opsy::utility::clear_set<eth_rx_lpi_usec_cntr_r>(mask, *this);}
	constexpr auto operator|(eth_rx_lpi_usec_cntr_r other) const -> eth_rx_lpi_usec_cntr_r { return static_cast<eth_rx_lpi_usec_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_rx_lpi_usec_cntr_r> other) const -> opsy::utility::clear_set<eth_rx_lpi_usec_cntr_r> {return opsy::utility::clear_set<eth_rx_lpi_usec_cntr_r>(eth_rx_lpi_usec_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxlpiusc() const -> rxlpiusc_f {return rxlpiusc_f(static_cast<uint32_t>(value_ >> rxlpiusc_f::offset));}

	constexpr eth_rx_lpi_usec_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_rx_lpi_usec_cntr_r other) const -> eth_rx_lpi_usec_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_rx_lpi_usec_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx LPI transition counter register
 */
class eth_rx_lpi_tran_cntr_r {
public:

/**
 * Rx LPI Transition counter This field indicates the number of times Rx LPI Entry has occurred.
 */
class rxlpitrc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxlpitrc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_rx_lpi_tran_cntr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_rx_lpi_tran_cntr_r>() const {return opsy::utility::clear_set<eth_rx_lpi_tran_cntr_r>(mask, *this);}
	constexpr auto operator|(eth_rx_lpi_tran_cntr_r other) const -> eth_rx_lpi_tran_cntr_r { return static_cast<eth_rx_lpi_tran_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_rx_lpi_tran_cntr_r> other) const -> opsy::utility::clear_set<eth_rx_lpi_tran_cntr_r> {return opsy::utility::clear_set<eth_rx_lpi_tran_cntr_r>(eth_rx_lpi_tran_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rxlpitrc() const -> rxlpitrc_f {return rxlpitrc_f(static_cast<uint32_t>(value_ >> rxlpitrc_f::offset));}

	constexpr eth_rx_lpi_tran_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_rx_lpi_tran_cntr_r other) const -> eth_rx_lpi_tran_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_rx_lpi_tran_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * L3 and L4 control 0 register
 */
class eth_macl3l4c0r_r {
public:

/**
 * Layer 3 Protocol Enable When this bit is set, the Layer 3 IP Source or Destination Address matching is enabled for IPv6 packets. When this bit is reset, the Layer 3 IP Source or Destination Address matching is enabled for IPv4 packets. The Layer 3 matching is done only when the L3SAM0 or L3DAM0 bit is set.
 */
class l3pen0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3pen0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA Match Enable When this bit is set, the Layer 3 IP Source Address field is enabled for matching. When this bit is reset, the MAC ignores the Layer 3 IP Source Address field for matching. Note: When the L3PEN0 bit is set, you should set either this bit or the L3DAM0 bit because either IPv6 SA or DA can be checked for filtering.
 */
class l3sam0_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3sam0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA Inverse Match Enable When this bit is set, the Layer 3 IP Source Address field is enabled for inverse matching. When this bit reset, the Layer 3 IP Source Address field is enabled for perfect matching. This bit is valid and applicable only when the L3SAM0 bit is set.
 */
class l3saim0_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3saim0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP DA Match Enable When this bit is set, the Layer 3 IP Destination Address field is enabled for matching. When this bit is reset, the MAC ignores the Layer 3 IP Destination Address field for matching. Note: When the L3PEN0 bit is set, you should set either this bit or the L3SAM0 bit because either IPv6 DA or SA can be checked for filtering.
 */
class l3dam0_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3dam0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP DA Inverse Match Enable When this bit is set, the Layer 3 IP Destination Address field is enabled for inverse matching. When this bit is reset, the Layer 3 IP Destination Address field is enabled for perfect matching. This bit is valid and applicable only when the L3DAM0 bit is set high.
 */
class l3daim0_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3daim0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA higher bits match This field contains the number of lower bits of IP source address that are masked for matching in the IPv4 packets. The following list describes the values of this field: .. Condition: IPv6 packets: This field contains Bits[4:0] of L3HSBM0. These bits indicate the number of higher bits of IP source or destination address matched in the IPv6 packets. This field is valid and applicable only when the L3DAM0 or L3SAM0 bit is set high.
 */
class l3hsbm0_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l3hsbm0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Layer 3 IP DA higher bits match This field contains the number of higher bits of IP Destination Address that are masked in the IPv4 packets: .. Bits[12:11] of this field correspond to Bits[6:5] of L3HSBM0 which indicate the number of lower bits of IP Source or Destination Address that are masked in the IPv6 packets. Number of bits masked is given by concatenated values of the L3HDBM0[1:0] and L3HSBM0 bits: .. This field is valid and applicable only when the L3DAM0 or L3SAM0 bit is set.
 */
class l3hdbm0_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l3hdbm0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Layer 4 Protocol Enable When this bit is set, the Source and Destination Port number fields of UDP packets are used for matching. When this bit is reset, the Source and Destination Port number fields of TCP packets are used for matching. The Layer 4 matching is done only when the L4SPM0 or L4DPM0 bit is set.
 */
class l4pen0_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4pen0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Source Port Match Enable When this bit is set, the Layer 4 Source Port number field is enabled for matching. When this bit is reset, the MAC ignores the Layer 4 Source Port number field for matching.
 */
class l4spm0_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4spm0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Source Port Inverse Match Enable When this bit is set, the Layer 4 Source Port number field is enabled for inverse matching. When this bit is reset, the Layer 4 Source Port number field is enabled for perfect matching. This bit is valid and applicable only when the L4SPM0 bit is set high.
 */
class l4spim0_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4spim0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Destination Port Match Enable When this bit is set, the Layer 4 Destination Port number field is enabled for matching. When this bit is reset, the MAC ignores the Layer 4 Destination Port number field for matching.
 */
class l4dpm0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4dpm0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Destination Port Inverse Match Enable When this bit is set, the Layer 4 Destination Port number field is enabled for inverse matching. When this bit is reset, the Layer 4 Destination Port number field is enabled for perfect matching. This bit is valid and applicable only when the L4DPM0 bit is set high.
 */
class l4dpim0_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4dpim0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c0r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c0r_r>() const {return opsy::utility::clear_set<eth_macl3l4c0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return static_cast<eth_macl3l4c0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c0r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c0r_r> {return opsy::utility::clear_set<eth_macl3l4c0r_r>(eth_macl3l4c0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto l3pen0() const -> l3pen0_f {return l3pen0_f((value_ & l3pen0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3sam0() const -> l3sam0_f {return l3sam0_f((value_ & l3sam0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3saim0() const -> l3saim0_f {return l3saim0_f((value_ & l3saim0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3dam0() const -> l3dam0_f {return l3dam0_f((value_ & l3dam0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3daim0() const -> l3daim0_f {return l3daim0_f((value_ & l3daim0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3hsbm0() const -> l3hsbm0_f {return l3hsbm0_f(static_cast<uint8_t>(value_ >> l3hsbm0_f::offset));}
	[[nodiscard]] constexpr auto l3hdbm0() const -> l3hdbm0_f {return l3hdbm0_f(static_cast<uint8_t>(value_ >> l3hdbm0_f::offset));}
	[[nodiscard]] constexpr auto l4pen0() const -> l4pen0_f {return l4pen0_f((value_ & l4pen0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4spm0() const -> l4spm0_f {return l4spm0_f((value_ & l4spm0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4spim0() const -> l4spim0_f {return l4spim0_f((value_ & l4spim0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4dpm0() const -> l4dpm0_f {return l4dpm0_f((value_ & l4dpm0_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4dpim0() const -> l4dpim0_f {return l4dpim0_f((value_ & l4dpim0_f::mask) != 0);}

	constexpr eth_macl3l4c0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3l4c0r_r other) const -> eth_macl3l4c0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3l4c0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer4 Address filter 0 register
 */
class eth_macl4a0r_r {
public:

/**
 * Layer 4 Source Port Number Field When the L4PEN0 bit is reset and the L4DPM0 bit is set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the TCP Source Port Number field in the IPv4 or IPv6 packets. When the L4PEN0 and L4DPM0 bits are set in L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the UDP Source Port Number field in the IPv4 or IPv6 packets.
 */
class l4sp0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l4sp0_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macl4a0r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl4a0r_r>() const {return opsy::utility::clear_set<eth_macl4a0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl4a0r_r other) const -> eth_macl4a0r_r { return static_cast<eth_macl4a0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl4a0r_r> other) const -> opsy::utility::clear_set<eth_macl4a0r_r> {return opsy::utility::clear_set<eth_macl4a0r_r>(eth_macl4a0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Layer 4 Destination Port Number Field When the L4PEN0 bit is reset and the L4DPM0 bit is set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the TCP Destination Port Number field in the IPv4 or IPv6 packets. When the L4PEN0 and L4DPM0 bits are set in L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the UDP Destination Port Number field in the IPv4 or IPv6 packets.
 */
class l4dp0_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l4dp0_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macl4a0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl4a0r_r>() const {return opsy::utility::clear_set<eth_macl4a0r_r>(mask, *this);}
	constexpr auto operator|(eth_macl4a0r_r other) const -> eth_macl4a0r_r { return static_cast<eth_macl4a0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl4a0r_r> other) const -> opsy::utility::clear_set<eth_macl4a0r_r> {return opsy::utility::clear_set<eth_macl4a0r_r>(eth_macl4a0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto l4sp0() const -> l4sp0_f {return l4sp0_f(static_cast<uint16_t>(value_ >> l4sp0_f::offset));}
	[[nodiscard]] constexpr auto l4dp0() const -> l4dp0_f {return l4dp0_f(static_cast<uint16_t>(value_ >> l4dp0_f::offset));}

	constexpr eth_macl4a0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl4a0r_r other) const -> eth_macl4a0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl4a0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 Address 0 filter 0 register
 */
class eth_macl3a00r_r {
public:

/**
 * Layer 3 Address 0 Field When the L3PEN0 and L3SAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[31:0] of the IP Source Address field in the IPv6 packets. When the L3PEN0 and L3DAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[31:0] of the IP Destination Address field in the IPv6 packets. When the L3PEN0 bit is reset and the L3SAM0 bit is set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the IP Source Address field in the IPv4 packets.
 */
class l3a00_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a00_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a00r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a00r_r>() const {return opsy::utility::clear_set<eth_macl3a00r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a00r_r other) const -> eth_macl3a00r_r { return static_cast<eth_macl3a00r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a00r_r> other) const -> opsy::utility::clear_set<eth_macl3a00r_r> {return opsy::utility::clear_set<eth_macl3a00r_r>(eth_macl3a00r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a00() const -> l3a00_f {return l3a00_f(static_cast<uint32_t>(value_ >> l3a00_f::offset));}

	constexpr eth_macl3a00r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a00r_r other) const -> eth_macl3a00r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a00r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 Address 1 filter 0 register
 */
class eth_macl3a10r_r {
public:

/**
 * Layer 3 Address 1 Field When the L3PEN0 and L3SAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[63:32] of the IP Source Address field in the IPv6 packets. When the L3PEN0 and L3DAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[63:32] of the IP Destination Address field in the IPv6 packets. When the L3PEN0 bit is reset and the L3SAM0 bit is set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with the IP Destination Address field in the IPv4 packets.
 */
class l3a10_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a10_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a10r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a10r_r>() const {return opsy::utility::clear_set<eth_macl3a10r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a10r_r other) const -> eth_macl3a10r_r { return static_cast<eth_macl3a10r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a10r_r> other) const -> opsy::utility::clear_set<eth_macl3a10r_r> {return opsy::utility::clear_set<eth_macl3a10r_r>(eth_macl3a10r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a10() const -> l3a10_f {return l3a10_f(static_cast<uint32_t>(value_ >> l3a10_f::offset));}

	constexpr eth_macl3a10r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a10r_r other) const -> eth_macl3a10r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a10r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 Address 2 filter 0 register
 */
class eth_macl3a20r_r {
public:

/**
 * Layer 3 Address 2 Field When the L3PEN0 and L3SAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[95:64] of the IP Source Address field in the IPv6 packets. When the L3PEN0 and L3DAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[95:64] of the IP Destination Address field in the IPv6 packets. When the L3PEN0 bit is reset in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field is not used.
 */
class l3a20_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a20_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a20r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a20r_r>() const {return opsy::utility::clear_set<eth_macl3a20r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a20r_r other) const -> eth_macl3a20r_r { return static_cast<eth_macl3a20r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a20r_r> other) const -> opsy::utility::clear_set<eth_macl3a20r_r> {return opsy::utility::clear_set<eth_macl3a20r_r>(eth_macl3a20r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a20() const -> l3a20_f {return l3a20_f(static_cast<uint32_t>(value_ >> l3a20_f::offset));}

	constexpr eth_macl3a20r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a20r_r other) const -> eth_macl3a20r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a20r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 Address 3 filter 0 register
 */
class eth_macl3a30r_r {
public:

/**
 * Layer 3 Address 3 Field When the L3PEN0 and L3SAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[127:96] of the IP Source Address field in the IPv6 packets. When the L3PEN0 and L3DAM0 bits are set in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field contains the value to be matched with Bits[127:96] of the IP Destination Address field in the IPv6 packets. When the L3PEN0 bit is reset in the L3 and L4 control 0 register (ETH_MACL3L4C0R), this field is not used.
 */
class l3a30_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a30_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a30r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a30r_r>() const {return opsy::utility::clear_set<eth_macl3a30r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a30r_r other) const -> eth_macl3a30r_r { return static_cast<eth_macl3a30r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a30r_r> other) const -> opsy::utility::clear_set<eth_macl3a30r_r> {return opsy::utility::clear_set<eth_macl3a30r_r>(eth_macl3a30r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a30() const -> l3a30_f {return l3a30_f(static_cast<uint32_t>(value_ >> l3a30_f::offset));}

	constexpr eth_macl3a30r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a30r_r other) const -> eth_macl3a30r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a30r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * L3 and L4 control 1 register
 */
class eth_macl3l4c1r_r {
public:

/**
 * Layer 3 Protocol Enable When this bit is set, the Layer 3 IP Source or Destination Address matching is enabled for IPv6 packets. When this bit is reset, the Layer 3 IP Source or Destination Address matching is enabled for IPv4 packets. The Layer 3 matching is done only when the L3SAM1 or L3DAM1 bit is set.
 */
class l3pen1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3pen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA Match Enable When this bit is set, the Layer 3 IP Source Address field is enabled for matching. When this bit is reset, the MAC ignores the Layer 3 IP Source Address field for matching. Note: When the L3PEN01 bit is set, you should set either this bit or the L3DAM1 bit because either IPv6 SA or DA can be checked for filtering.
 */
class l3sam1_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3sam1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA Inverse Match Enable When this bit is set, the Layer 3 IP Source Address field is enabled for inverse matching. When this bit reset, the Layer 3 IP Source Address field is enabled for perfect matching. This bit is valid and applicable only when the L3SAM1 bit is set.
 */
class l3saim1_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3saim1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP DA Match Enable When this bit is set, the Layer 3 IP Destination Address field is enabled for matching. When this bit is reset, the MAC ignores the Layer 3 IP Destination Address field for matching. Note: When the L3PEN1 bit is set, you should set either this bit or the L3SAM1 bit because either IPv6 DA or SA can be checked for filtering.
 */
class l3dam1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3dam1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP DA Inverse Match Enable When this bit is set, the Layer 3 IP Destination Address field is enabled for inverse matching. When this bit is reset, the Layer 3 IP Destination Address field is enabled for perfect matching. This bit is valid and applicable only when the L3DAM1 bit is set high.
 */
class l3daim1_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l3daim1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 3 IP SA Higher Bits Match This field contains the number of lower bits of IP Source Address that are masked for matching in the IPv4 packets. The following list describes the values of this field: .. This field contains Bits[4:0] of L3HSBM1. These bits indicate the number of higher bits of IP Source or Destination Address matched in the IPv6 packets. This field is valid and applicable only when the L3DAM1 or L3SAM1 bit is set high.
 */
class l3hsbm1_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l3hsbm1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Layer 3 IP DA higher bits match This field contains the number of lower bits of IP Destination Address that are masked for matching in the IPv4 packets. The following list describes the values of this field: .. Bits[12:11] of this field correspond to Bits[6:5] of L3HSBM1, which indicate the number of lower bits of IP Source or Destination Address that are masked in the IPv6 packets. The following list describes the concatenated values of the L3HDBM1[1:0] and L3HSBM1 bits: .. This field is valid and applicable only when the L3DAM1 or L3SAM1 bit is set.
 */
class l3hdbm1_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l3hdbm1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Layer 4 Protocol Enable When this bit is set, the Source and Destination Port number fields of UDP packets are used for matching. When this bit is reset, the Source and Destination Port number fields of TCP packets are used for matching. The Layer 4 matching is done only when the L4SPM1 or L4DPM1 bit is set.
 */
class l4pen1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4pen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Source Port Match Enable When this bit is set, the Layer 4 Source Port number field is enabled for matching. When this bit is reset, the MAC ignores the Layer 4 Source Port number field for matching.
 */
class l4spm1_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4spm1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Source Port Inverse Match Enable When this bit is set, the Layer 4 Source Port number field is enabled for inverse matching. When this bit is reset, the Layer 4 Source Port number field is enabled for perfect matching. This bit is valid and applicable only when the L4SPM1 bit is set high.
 */
class l4spim1_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4spim1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Destination Port Match Enable When this bit is set, the Layer 4 Destination Port number field is enabled for matching. When this bit is reset, the MAC ignores the Layer 4 Destination Port number field for matching.
 */
class l4dpm1_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4dpm1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Layer 4 Destination Port Inverse Match Enable When this bit is set, the Layer 4 Destination Port number field is enabled for inverse matching. When this bit is reset, the Layer 4 Destination Port number field is enabled for perfect matching. This bit is valid and applicable only when the L4DPM1 bit is set high.
 */
class l4dpim1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr l4dpim1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macl3l4c1r_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macl3l4c1r_r>() const {return opsy::utility::clear_set<eth_macl3l4c1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return static_cast<eth_macl3l4c1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3l4c1r_r> other) const -> opsy::utility::clear_set<eth_macl3l4c1r_r> {return opsy::utility::clear_set<eth_macl3l4c1r_r>(eth_macl3l4c1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto l3pen1() const -> l3pen1_f {return l3pen1_f((value_ & l3pen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3sam1() const -> l3sam1_f {return l3sam1_f((value_ & l3sam1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3saim1() const -> l3saim1_f {return l3saim1_f((value_ & l3saim1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3dam1() const -> l3dam1_f {return l3dam1_f((value_ & l3dam1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3daim1() const -> l3daim1_f {return l3daim1_f((value_ & l3daim1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l3hsbm1() const -> l3hsbm1_f {return l3hsbm1_f(static_cast<uint8_t>(value_ >> l3hsbm1_f::offset));}
	[[nodiscard]] constexpr auto l3hdbm1() const -> l3hdbm1_f {return l3hdbm1_f(static_cast<uint8_t>(value_ >> l3hdbm1_f::offset));}
	[[nodiscard]] constexpr auto l4pen1() const -> l4pen1_f {return l4pen1_f((value_ & l4pen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4spm1() const -> l4spm1_f {return l4spm1_f((value_ & l4spm1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4spim1() const -> l4spim1_f {return l4spim1_f((value_ & l4spim1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4dpm1() const -> l4dpm1_f {return l4dpm1_f((value_ & l4dpm1_f::mask) != 0);}
	[[nodiscard]] constexpr auto l4dpim1() const -> l4dpim1_f {return l4dpim1_f((value_ & l4dpim1_f::mask) != 0);}

	constexpr eth_macl3l4c1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3l4c1r_r other) const -> eth_macl3l4c1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3l4c1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer 4 address filter 1 register
 */
class eth_macl4a1r_r {
public:

/**
 * Layer 4 Source Port Number Field When the L4PEN1 bit is reset and the L4DPM1 bit is set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the TCP Source Port Number field in the IPv4 or IPv6 packets. When the L4PEN1 and L4DPM1 bits are set in L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the UDP Source Port Number field in the IPv4 or IPv6 packets.
 */
class l4sp1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr l4sp1_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macl4a1r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl4a1r_r>() const {return opsy::utility::clear_set<eth_macl4a1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl4a1r_r other) const -> eth_macl4a1r_r { return static_cast<eth_macl4a1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl4a1r_r> other) const -> opsy::utility::clear_set<eth_macl4a1r_r> {return opsy::utility::clear_set<eth_macl4a1r_r>(eth_macl4a1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Layer 4 Destination Port Number Field When the L4PEN1 bit is reset and the L4DPM1 bit is set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the TCP Destination Port Number field in the IPv4 or IPv6 packets. When the L4PEN1 and L4DPM1 bits are set in L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the UDP Destination Port Number field in the IPv4 or IPv6 packets.
 */
class l4dp1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l4dp1_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macl4a1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl4a1r_r>() const {return opsy::utility::clear_set<eth_macl4a1r_r>(mask, *this);}
	constexpr auto operator|(eth_macl4a1r_r other) const -> eth_macl4a1r_r { return static_cast<eth_macl4a1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl4a1r_r> other) const -> opsy::utility::clear_set<eth_macl4a1r_r> {return opsy::utility::clear_set<eth_macl4a1r_r>(eth_macl4a1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto l4sp1() const -> l4sp1_f {return l4sp1_f(static_cast<uint16_t>(value_ >> l4sp1_f::offset));}
	[[nodiscard]] constexpr auto l4dp1() const -> l4dp1_f {return l4dp1_f(static_cast<uint16_t>(value_ >> l4dp1_f::offset));}

	constexpr eth_macl4a1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl4a1r_r other) const -> eth_macl4a1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl4a1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 address 0 filter 1 Register
 */
class eth_macl3a01r_r {
public:

/**
 * Layer 3 Address 0 Field When the L3PEN1 and L3SAM1bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[31:0] of the IP Source Address field in the IPv6 packets. When the L3PEN1 and L3DAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[31:0] of the IP Destination Address field in the IPv6 packets. When the L3PEN1 bit is reset and the L3SAM1 bit is set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the IP Source Address field in the IPv4 packets.
 */
class l3a01_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a01_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a01r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a01r_r>() const {return opsy::utility::clear_set<eth_macl3a01r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a01r_r other) const -> eth_macl3a01r_r { return static_cast<eth_macl3a01r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a01r_r> other) const -> opsy::utility::clear_set<eth_macl3a01r_r> {return opsy::utility::clear_set<eth_macl3a01r_r>(eth_macl3a01r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a01() const -> l3a01_f {return l3a01_f(static_cast<uint32_t>(value_ >> l3a01_f::offset));}

	constexpr eth_macl3a01r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a01r_r other) const -> eth_macl3a01r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a01r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 address 1 filter 1 register
 */
class eth_macl3a11r_r {
public:

/**
 * Layer 3 Address 1 Field When the L3PEN1 and L3SAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[63:32] of the IP Source Address field in the IPv6 packets. When the L3PEN1 and L3DAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[63:32] of the IP Destination Address field in the IPv6 packets. When the L3PEN1 bit is reset and the L3SAM1 bit is set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with the IP Destination Address field in the IPv4 packets.
 */
class l3a11_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a11_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a11r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a11r_r>() const {return opsy::utility::clear_set<eth_macl3a11r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a11r_r other) const -> eth_macl3a11r_r { return static_cast<eth_macl3a11r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a11r_r> other) const -> opsy::utility::clear_set<eth_macl3a11r_r> {return opsy::utility::clear_set<eth_macl3a11r_r>(eth_macl3a11r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a11() const -> l3a11_f {return l3a11_f(static_cast<uint32_t>(value_ >> l3a11_f::offset));}

	constexpr eth_macl3a11r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a11r_r other) const -> eth_macl3a11r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a11r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 address 2 filter 1 Register
 */
class eth_macl3a21r_r {
public:

/**
 * Layer 3 Address 2 Field When the L3PEN1 and L3SAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[95:64] of the IP Source Address field in the IPv6 packets. When the L3PEN1 and L3DAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[95:64] of the IP Destination Address field in the IPv6 packets. When the L3PEN1 bit is reset in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field is not used.
 */
class l3a21_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a21_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a21r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a21r_r>() const {return opsy::utility::clear_set<eth_macl3a21r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a21r_r other) const -> eth_macl3a21r_r { return static_cast<eth_macl3a21r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a21r_r> other) const -> opsy::utility::clear_set<eth_macl3a21r_r> {return opsy::utility::clear_set<eth_macl3a21r_r>(eth_macl3a21r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a21() const -> l3a21_f {return l3a21_f(static_cast<uint32_t>(value_ >> l3a21_f::offset));}

	constexpr eth_macl3a21r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a21r_r other) const -> eth_macl3a21r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a21r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Layer3 address 3 filter 1 register
 */
class eth_macl3a31r_r {
public:

/**
 * Layer 3 Address 3 Field When the L3PEN1 and L3SAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[127:96] of the IP Source Address field in the IPv6 packets. When the L3PEN1 and L3DAM1 bits are set in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field contains the value to be matched with Bits[127:96] of the IP Destination Address field in the IPv6 packets. When the L3PEN1 bit is reset in the L3 and L4 control 1 register (ETH_MACL3L4C1R), this field is not used.
 */
class l3a31_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr l3a31_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macl3a31r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macl3a31r_r>() const {return opsy::utility::clear_set<eth_macl3a31r_r>(mask, *this);}
	constexpr auto operator|(eth_macl3a31r_r other) const -> eth_macl3a31r_r { return static_cast<eth_macl3a31r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macl3a31r_r> other) const -> opsy::utility::clear_set<eth_macl3a31r_r> {return opsy::utility::clear_set<eth_macl3a31r_r>(eth_macl3a31r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto l3a31() const -> l3a31_f {return l3a31_f(static_cast<uint32_t>(value_ >> l3a31_f::offset));}

	constexpr eth_macl3a31r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macl3a31r_r other) const -> eth_macl3a31r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macl3a31r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp control Register
 */
class eth_mactscr_r {
public:

/**
 * Enable Timestamp When this bit is set, the timestamp is added for Transmit and Receive packets. When disabled, timestamp is not added for transmit and receive packets and the Timestamp Generator is also suspended. You need to initialize the Timestamp (system time) after enabling this mode. On the Receive side, the MAC processes the 1588 packets only if this bit is set.
 */
class tsena_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fine or Coarse Timestamp Update When this bit is set, the Fine method is used to update system timestamp. When this bit is reset, Coarse method is used to update the system timestamp.
 */
class tscfupdt_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tscfupdt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialize Timestamp When this bit is set, the system time is initialized (overwritten) with the value specified in the System time seconds update register (ETH_MACSTSUR) and System time nanoseconds update register (ETH_MACSTNUR). This bit should be zero before it is updated. This bit is reset when the initialization is complete.
 */
class tsinit_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsinit_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update Timestamp When this bit is set, the system time is updated (added or subtracted) with the value specified in System time seconds update register (ETH_MACSTSUR) and System time nanoseconds update register (ETH_MACSTNUR). This bit should be zero before updating it. This bit is reset when the update is complete in hardware.
 */
class tsupdt_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsupdt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update Addend Register When this bit is set, the content of the Timestamp Addend register is updated in the PTP block for fine correction. This bit is cleared when the update is complete. This bit should be zero before it is set.
 */
class tsaddreg_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsaddreg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Timestamp for All Packets When this bit is set, the timestamp snapshot is enabled for all packets received by the MAC.
 */
class tsenall_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsenall_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp Digital or Binary Rollover Control When this bit is set, the Timestamp Low register rolls over after 0x3B9A_C9FF value (that is, 1 nanosecond accuracy) and increments the timestamp (High) seconds. When this bit is reset, the rollover value of subsecond register is 0x7FFF_FFFF. The subsecond increment must be programmed correctly depending on the PTP reference clock frequency and the value of this bit.
 */
class tsctrlssr_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsctrlssr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable PTP Packet Processing for Version 2 Format When this bit is set, the IEEE 1588 version 2 format is used to process the PTP packets. When this bit is reset, the IEEE 1588 version 1 format is used to process the PTP packets. The IEEE 1588 formats are described in 'PTP Processing and Control'.
 */
class tsver2ena_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsver2ena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Processing of PTP over Ethernet Packets When this bit is set, the MAC receiver processes the PTP packets encapsulated directly in the Ethernet packets. When this bit is reset, the MAC ignores the PTP over Ethernet packets.
 */
class tsipena_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsipena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Processing of PTP Packets Sent over IPv6-UDP When this bit is set, the MAC receiver processes the PTP packets encapsulated in IPv6-UDP packets. When this bit is clear, the MAC ignores the PTP transported over IPv6-UDP packets.
 */
class tsipv6ena_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsipv6ena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Processing of PTP Packets Sent over IPv4-UDP When this bit is set, the MAC receiver processes the PTP packets encapsulated in IPv4-UDP packets. When this bit is reset, the MAC ignores the PTP transported over IPv4-UDP packets. This bit is set by default.
 */
class tsipv4ena_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsipv4ena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Timestamp Snapshot for Event Messages When this bit is set, the timestamp snapshot is taken only for event messages (SYNC, Delay_Req, Pdelay_Req, or Pdelay_Resp). When this bit is reset, the snapshot is taken for all messages except Announce, Management, and Signaling. For more information about the timestamp snapshots, see Table634: Timestamp Snapshot Dependency on ETH_MACTSCR bits.
 */
class tsevntena_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsevntena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable Snapshot for Messages Relevant to Master When this bit is set, the snapshot is taken only for the messages that are relevant to the master node. Otherwise, the snapshot is taken for the messages relevant to the slave node.
 */
class tsmstrena_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsmstrena_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Select PTP packets for Taking Snapshots These bits, along with Bits 15 and 14, define the set of PTP packet types for which snapshot needs to be taken. The encoding is given in Table634: Timestamp Snapshot Dependency on ETH_MACTSCR bits.
 */
class snaptypsel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr snaptypsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mactscr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable MAC Address for PTP Packet Filtering When this bit is set, the DA MAC address (that matches any MAC Address register) is used to filter the PTP packets when PTP is directly sent over Ethernet. When this bit is set, received PTP packets with DA containing a special multicast or unicast address that matches the one programmed in MAC address registers are considered for processing as indicated below, when PTP is directly sent over Ethernet. For normal timestamping operation, MAC address registers 0 to 31 is considered for unicast destination address matching. For PTP offload, only MAC address register 0 is considered for unicast destination address matching.
 */
class tsenmacaddr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tsenmacaddr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Timestamp Status Mode When this bit is set, the MAC overwrites the earlier transmit timestamp status even if it is not read by the software. The MAC indicates this by setting the TXTSSMIS bit of the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) register. When this bit is reset, the MAC ignores the timestamp status of current packet if the timestamp status of previous packet is not read by the software. The MAC indicates this by setting the TXTSSMIS bit of the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR).
 */
class txtsstsm_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txtsstsm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AV 802.1AS Mode Enable When this bit is set, the MAC processes only untagged PTP over Ethernet packets for providing PTP status and capturing timestamp snapshots, that is, IEEE 802.1AS operating mode. When PTP offload feature is enabled, for the purpose of PTP offload, the transport specific field in the PTP header is generated and checked based on the value of this bit.
 */
class av8021asmen_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr av8021asmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactscr_r>() const {return opsy::utility::clear_set<eth_mactscr_r>(mask, *this);}
	constexpr auto operator|(eth_mactscr_r other) const -> eth_mactscr_r { return static_cast<eth_mactscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactscr_r> other) const -> opsy::utility::clear_set<eth_mactscr_r> {return opsy::utility::clear_set<eth_mactscr_r>(eth_mactscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tsena() const -> tsena_f {return tsena_f((value_ & tsena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tscfupdt() const -> tscfupdt_f {return tscfupdt_f((value_ & tscfupdt_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsinit() const -> tsinit_f {return tsinit_f((value_ & tsinit_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsupdt() const -> tsupdt_f {return tsupdt_f((value_ & tsupdt_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsaddreg() const -> tsaddreg_f {return tsaddreg_f((value_ & tsaddreg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsenall() const -> tsenall_f {return tsenall_f((value_ & tsenall_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsctrlssr() const -> tsctrlssr_f {return tsctrlssr_f((value_ & tsctrlssr_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsver2ena() const -> tsver2ena_f {return tsver2ena_f((value_ & tsver2ena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsipena() const -> tsipena_f {return tsipena_f((value_ & tsipena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsipv6ena() const -> tsipv6ena_f {return tsipv6ena_f((value_ & tsipv6ena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsipv4ena() const -> tsipv4ena_f {return tsipv4ena_f((value_ & tsipv4ena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsevntena() const -> tsevntena_f {return tsevntena_f((value_ & tsevntena_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsmstrena() const -> tsmstrena_f {return tsmstrena_f((value_ & tsmstrena_f::mask) != 0);}
	[[nodiscard]] constexpr auto snaptypsel() const -> snaptypsel_f {return snaptypsel_f(static_cast<uint8_t>(value_ >> snaptypsel_f::offset));}
	[[nodiscard]] constexpr auto tsenmacaddr() const -> tsenmacaddr_f {return tsenmacaddr_f((value_ & tsenmacaddr_f::mask) != 0);}
	[[nodiscard]] constexpr auto txtsstsm() const -> txtsstsm_f {return txtsstsm_f((value_ & txtsstsm_f::mask) != 0);}
	[[nodiscard]] constexpr auto av8021asmen() const -> av8021asmen_f {return av8021asmen_f((value_ & av8021asmen_f::mask) != 0);}

	constexpr eth_mactscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactscr_r other) const -> eth_mactscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000; // 8192 0x2000

private:
	uint32_t value_;
};

/**
 * Subsecond increment register
 */
class eth_macssir_r {
public:

/**
 * Subsecond Increment Value The value programmed in this field is accumulated every clock cycle (of clk_ptp_i) with the contents of the subsecond register. For example, when the PTP clock is 50 MHz (period is 20 ns), you should program 20 (0x14) when the System Time Nanoseconds register has an accuracy of 1 ns [TSCTRLSSR bit is set in Timestamp control Register (ETH_MACTSCR)]. When TSCTRLSSR is cleared, the Nanoseconds register has a resolution of ~0.465 ns. In this case, you should program a value of 43 (0x2B) which is derived by 20 ns/0.465.
 */
class ssinc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ssinc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macssir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macssir_r>() const {return opsy::utility::clear_set<eth_macssir_r>(mask, *this);}
	constexpr auto operator|(eth_macssir_r other) const -> eth_macssir_r { return static_cast<eth_macssir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macssir_r> other) const -> opsy::utility::clear_set<eth_macssir_r> {return opsy::utility::clear_set<eth_macssir_r>(eth_macssir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ssinc() const -> ssinc_f {return ssinc_f(static_cast<uint8_t>(value_ >> ssinc_f::offset));}

	constexpr eth_macssir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macssir_r other) const -> eth_macssir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macssir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * System time seconds register
 */
class eth_macstsr_r {
public:

/**
 * Timestamp Second The value in this field indicates the current value in seconds of the System Time maintained by the MAC.
 */
class tss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tss_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macstsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macstsr_r>() const {return opsy::utility::clear_set<eth_macstsr_r>(mask, *this);}
	constexpr auto operator|(eth_macstsr_r other) const -> eth_macstsr_r { return static_cast<eth_macstsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macstsr_r> other) const -> opsy::utility::clear_set<eth_macstsr_r> {return opsy::utility::clear_set<eth_macstsr_r>(eth_macstsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tss() const -> tss_f {return tss_f(static_cast<uint32_t>(value_ >> tss_f::offset));}

	constexpr eth_macstsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macstsr_r other) const -> eth_macstsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macstsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * System time nanoseconds register
 */
class eth_macstnr_r {
public:

/**
 * Timestamp subseconds The value in this field has the subsecond representation of time, with an accuracy of 0.46 ns. When TSCTRLSSR is set in Timestamp control Register (ETH_MACTSCR), each bit represents 1 ns. The maximum value is 0x3B9A_C9FF after which it rolls-over to zero.
 */
class tsss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsss_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macstnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macstnr_r>() const {return opsy::utility::clear_set<eth_macstnr_r>(mask, *this);}
	constexpr auto operator|(eth_macstnr_r other) const -> eth_macstnr_r { return static_cast<eth_macstnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macstnr_r> other) const -> opsy::utility::clear_set<eth_macstnr_r> {return opsy::utility::clear_set<eth_macstnr_r>(eth_macstnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tsss() const -> tsss_f {return tsss_f(static_cast<uint32_t>(value_ >> tsss_f::offset));}

	constexpr eth_macstnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macstnr_r other) const -> eth_macstnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macstnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * System time seconds update register
 */
class eth_macstsur_r {
public:

/**
 * Timestamp Seconds The value in this field is the seconds part of the update.
 */
class tss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tss_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macstsur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macstsur_r>() const {return opsy::utility::clear_set<eth_macstsur_r>(mask, *this);}
	constexpr auto operator|(eth_macstsur_r other) const -> eth_macstsur_r { return static_cast<eth_macstsur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macstsur_r> other) const -> opsy::utility::clear_set<eth_macstsur_r> {return opsy::utility::clear_set<eth_macstsur_r>(eth_macstsur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tss() const -> tss_f {return tss_f(static_cast<uint32_t>(value_ >> tss_f::offset));}

	constexpr eth_macstsur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macstsur_r other) const -> eth_macstsur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macstsur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * System time nanoseconds update register
 */
class eth_macstnur_r {
public:

/**
 * Timestamp subseconds The value in this field is the subseconds part of the update.
 */
class tsss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsss_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macstnur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macstnur_r>() const {return opsy::utility::clear_set<eth_macstnur_r>(mask, *this);}
	constexpr auto operator|(eth_macstnur_r other) const -> eth_macstnur_r { return static_cast<eth_macstnur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macstnur_r> other) const -> opsy::utility::clear_set<eth_macstnur_r> {return opsy::utility::clear_set<eth_macstnur_r>(eth_macstnur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Add or Subtract Time When this bit is set, the time value is subtracted with the contents of the update register. When this bit is reset, the time value is added with the contents of the update register.
 */
class addsub_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr addsub_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macstnur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macstnur_r>() const {return opsy::utility::clear_set<eth_macstnur_r>(mask, *this);}
	constexpr auto operator|(eth_macstnur_r other) const -> eth_macstnur_r { return static_cast<eth_macstnur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macstnur_r> other) const -> opsy::utility::clear_set<eth_macstnur_r> {return opsy::utility::clear_set<eth_macstnur_r>(eth_macstnur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tsss() const -> tsss_f {return tsss_f(static_cast<uint32_t>(value_ >> tsss_f::offset));}
	[[nodiscard]] constexpr auto addsub() const -> addsub_f {return addsub_f((value_ & addsub_f::mask) != 0);}

	constexpr eth_macstnur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macstnur_r other) const -> eth_macstnur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macstnur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp addend register
 */
class eth_mactsar_r {
public:

/**
 * Timestamp Addend Register This field indicates the 32-bit time value to be added to the Accumulator register to achieve time synchronization.
 */
class tsar_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsar_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactsar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactsar_r>() const {return opsy::utility::clear_set<eth_mactsar_r>(mask, *this);}
	constexpr auto operator|(eth_mactsar_r other) const -> eth_mactsar_r { return static_cast<eth_mactsar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactsar_r> other) const -> opsy::utility::clear_set<eth_mactsar_r> {return opsy::utility::clear_set<eth_mactsar_r>(eth_mactsar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tsar() const -> tsar_f {return tsar_f(static_cast<uint32_t>(value_ >> tsar_f::offset));}

	constexpr eth_mactsar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactsar_r other) const -> eth_mactsar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactsar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp status register
 */
class eth_mactssr_r {
public:

/**
 * Timestamp Seconds Overflow When this bit is set, it indicates that the seconds value of the timestamp (when supporting version 2 format) has overflowed beyond 32'hFFFF_FFFF. This bit is cleared when the application reads this bit (or writes it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set)
 */
class tssovf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tssovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp Target Time Reached When set, this bit indicates that the value of system time is greater than or equal to the value specified in the ETH_MACPPSTTSR and ETH_MACPPSTTSNR registers (see PPS target time seconds register (ETH_MACPPSTTSR) and PPS target time nanoseconds register (ETH_MACPPSTTNR)). This bit is cleared when the application reads this bit (or writes of 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set)
 */
class tstargt0_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tstargt0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Timestamp Trigger Snapshot This bit is set high when the auxiliary snapshot is written to the FIFO. This bit is cleared when the application reads this bit (or writes it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class auxtstrig_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr auxtstrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp Target Time Error This bit is set when the latest target time programmed in the ETH_MACPPSTTSR and ETH_MACPPSTTSNR elapses (see PPS target time seconds register (ETH_MACPPSTTSR) and PPS target time nanoseconds register (ETH_MACPPSTTNR)). This bit is cleared when the application reads this bit (or writes it to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class tstrgterr0_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tstrgterr0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx Timestamp Status Interrupt Status When drop transmit status is enabled in MTL, this bit is set when the captured transmit timestamp is updated in the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) and Tx timestamp status seconds register (ETH_MACTXTSSSR). When PTP offload feature is enabled, this bit is set when the captured transmit timestamp is updated in the Tx timestamp status nanoseconds register (ETH_MACTXTSSNR) and Tx timestamp status seconds register (ETH_MACTXTSSSR), for PTO generated Delay Request and Pdelay request packets. This bit is cleared when the Tx timestamp status seconds register (ETH_MACTXTSSSR) is read (or written to 1 when RCWE bit in CSR software control register (ETH_MACCSRSWCR) is set).
 */
class txtssis_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txtssis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Timestamp Snapshot Trigger Identifier These bits identify the Auxiliary trigger inputs for which the timestamp available in the Auxiliary Snapshot Register is applicable. When more than one bit is set at the same time, it means that corresponding auxiliary triggers were sampled at the same clock. These bits are applicable only if the number of Auxiliary snapshots is more than one. One bit is assigned for each trigger as shown in the following list: Bit 16: Auxiliary trigger 0 Bit 17: Auxiliary trigger 1 Bit 18: Auxiliary trigger 2 Bit 19: Auxiliary trigger 3 The software can read this register to find the triggers that are set when the timestamp is taken.
 */
class atsstn_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atsstn_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mactssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Auxiliary Timestamp Snapshot Trigger Missed This bit is set when the Auxiliary timestamp snapshot FIFO is full and external trigger was set. This indicates that the latest snapshot is not stored in the FIFO.
 */
class atsstm_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr atsstm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of Auxiliary Timestamp Snapshots This field indicates the number of Snapshots available in the FIFO. A value equal to the depth of FIFO (4) indicates that the Auxiliary Snapshot FIFO is full. These bits are cleared (to 00000) when the Auxiliary snapshot FIFO clear bit is set.
 */
class atsns_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atsns_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mactssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactssr_r>() const {return opsy::utility::clear_set<eth_mactssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactssr_r other) const -> eth_mactssr_r { return static_cast<eth_mactssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactssr_r> other) const -> opsy::utility::clear_set<eth_mactssr_r> {return opsy::utility::clear_set<eth_mactssr_r>(eth_mactssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tssovf() const -> tssovf_f {return tssovf_f((value_ & tssovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tstargt0() const -> tstargt0_f {return tstargt0_f((value_ & tstargt0_f::mask) != 0);}
	[[nodiscard]] constexpr auto auxtstrig() const -> auxtstrig_f {return auxtstrig_f((value_ & auxtstrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto tstrgterr0() const -> tstrgterr0_f {return tstrgterr0_f((value_ & tstrgterr0_f::mask) != 0);}
	[[nodiscard]] constexpr auto txtssis() const -> txtssis_f {return txtssis_f((value_ & txtssis_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsstn() const -> atsstn_f {return atsstn_f(static_cast<uint8_t>(value_ >> atsstn_f::offset));}
	[[nodiscard]] constexpr auto atsstm() const -> atsstm_f {return atsstm_f((value_ & atsstm_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsns() const -> atsns_f {return atsns_f(static_cast<uint8_t>(value_ >> atsns_f::offset));}

	constexpr eth_mactssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactssr_r other) const -> eth_mactssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx timestamp status nanoseconds register
 */
class eth_mactxtssnr_r {
public:

/**
 * Transmit Timestamp Status Low This field contains the 31 bits of the Nanoseconds field of the Transmit packet's captured timestamp.
 */
class txtsslo_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txtsslo_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactxtssnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactxtssnr_r>() const {return opsy::utility::clear_set<eth_mactxtssnr_r>(mask, *this);}
	constexpr auto operator|(eth_mactxtssnr_r other) const -> eth_mactxtssnr_r { return static_cast<eth_mactxtssnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactxtssnr_r> other) const -> opsy::utility::clear_set<eth_mactxtssnr_r> {return opsy::utility::clear_set<eth_mactxtssnr_r>(eth_mactxtssnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Transmit Timestamp Status Missed When this bit is set, it indicates one of the following: The timestamp of the current packet is ignored if TXTSSTSM bit of the Timestamp control Register (ETH_MACTSCR) is reset The timestamp of the previous packet is overwritten with timestamp of the current packet if TXTSSTSM bit of the Timestamp control Register (ETH_MACTSCR) is set.
 */
class txtssmis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txtssmis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mactxtssnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mactxtssnr_r>() const {return opsy::utility::clear_set<eth_mactxtssnr_r>(mask, *this);}
	constexpr auto operator|(eth_mactxtssnr_r other) const -> eth_mactxtssnr_r { return static_cast<eth_mactxtssnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactxtssnr_r> other) const -> opsy::utility::clear_set<eth_mactxtssnr_r> {return opsy::utility::clear_set<eth_mactxtssnr_r>(eth_mactxtssnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txtsslo() const -> txtsslo_f {return txtsslo_f(static_cast<uint32_t>(value_ >> txtsslo_f::offset));}
	[[nodiscard]] constexpr auto txtssmis() const -> txtssmis_f {return txtssmis_f((value_ & txtssmis_f::mask) != 0);}

	constexpr eth_mactxtssnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactxtssnr_r other) const -> eth_mactxtssnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactxtssnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx timestamp status seconds register
 */
class eth_mactxtsssr_r {
public:

/**
 * Transmit Timestamp Status High This field contains the lower 32 bits of the Seconds field of Transmit packet's captured timestamp.
 */
class txtsshi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txtsshi_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactxtsssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactxtsssr_r>() const {return opsy::utility::clear_set<eth_mactxtsssr_r>(mask, *this);}
	constexpr auto operator|(eth_mactxtsssr_r other) const -> eth_mactxtsssr_r { return static_cast<eth_mactxtsssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactxtsssr_r> other) const -> opsy::utility::clear_set<eth_mactxtsssr_r> {return opsy::utility::clear_set<eth_mactxtsssr_r>(eth_mactxtsssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto txtsshi() const -> txtsshi_f {return txtsshi_f(static_cast<uint32_t>(value_ >> txtsshi_f::offset));}

	constexpr eth_mactxtsssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactxtsssr_r other) const -> eth_mactxtsssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactxtsssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Auxiliary control register
 */
class eth_macacr_r {
public:

/**
 * Auxiliary Snapshot FIFO Clear When set, this bit resets the pointers of the Auxiliary Snapshot FIFO. This bit is cleared when the pointers are reset and the FIFO is empty. When this bit is high, the auxiliary snapshots are stored in the FIFO.
 */
class atsfc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr atsfc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macacr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macacr_r>() const {return opsy::utility::clear_set<eth_macacr_r>(mask, *this);}
	constexpr auto operator|(eth_macacr_r other) const -> eth_macacr_r { return static_cast<eth_macacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macacr_r> other) const -> opsy::utility::clear_set<eth_macacr_r> {return opsy::utility::clear_set<eth_macacr_r>(eth_macacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Snapshot 0 Enable This bit controls the capturing of Auxiliary Snapshot Trigger 0. When this bit is set, the auxiliary snapshot of the event on eth_ptp_trg0 input is enabled. When this bit is reset, the events on this input are ignored.
 */
class atsen0_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr atsen0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macacr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macacr_r>() const {return opsy::utility::clear_set<eth_macacr_r>(mask, *this);}
	constexpr auto operator|(eth_macacr_r other) const -> eth_macacr_r { return static_cast<eth_macacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macacr_r> other) const -> opsy::utility::clear_set<eth_macacr_r> {return opsy::utility::clear_set<eth_macacr_r>(eth_macacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Snapshot 1 Enable This bit controls the capturing of Auxiliary Snapshot Trigger 1. When this bit is set, the auxiliary snapshot of the event on eth_ptp_trg1 input is enabled. When this bit is reset, the events on this input are ignored.
 */
class atsen1_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr atsen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macacr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macacr_r>() const {return opsy::utility::clear_set<eth_macacr_r>(mask, *this);}
	constexpr auto operator|(eth_macacr_r other) const -> eth_macacr_r { return static_cast<eth_macacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macacr_r> other) const -> opsy::utility::clear_set<eth_macacr_r> {return opsy::utility::clear_set<eth_macacr_r>(eth_macacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Snapshot 2 Enable This bit controls the capturing of Auxiliary Snapshot Trigger 2. When this bit is set, the auxiliary snapshot of the event on eth_ptp_trg2 input is enabled. When this bit is reset, the events on this input are ignored.
 */
class atsen2_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr atsen2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macacr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macacr_r>() const {return opsy::utility::clear_set<eth_macacr_r>(mask, *this);}
	constexpr auto operator|(eth_macacr_r other) const -> eth_macacr_r { return static_cast<eth_macacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macacr_r> other) const -> opsy::utility::clear_set<eth_macacr_r> {return opsy::utility::clear_set<eth_macacr_r>(eth_macacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auxiliary Snapshot 3 Enable This bit controls the capturing of Auxiliary Snapshot Trigger 3. When this bit is set, the auxiliary snapshot of the event on eth_ptp_trg3 input is enabled. When this bit is reset, the events on this input are ignored.
 */
class atsen3_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr atsen3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macacr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macacr_r>() const {return opsy::utility::clear_set<eth_macacr_r>(mask, *this);}
	constexpr auto operator|(eth_macacr_r other) const -> eth_macacr_r { return static_cast<eth_macacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macacr_r> other) const -> opsy::utility::clear_set<eth_macacr_r> {return opsy::utility::clear_set<eth_macacr_r>(eth_macacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto atsfc() const -> atsfc_f {return atsfc_f((value_ & atsfc_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsen0() const -> atsen0_f {return atsen0_f((value_ & atsen0_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsen1() const -> atsen1_f {return atsen1_f((value_ & atsen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsen2() const -> atsen2_f {return atsen2_f((value_ & atsen2_f::mask) != 0);}
	[[nodiscard]] constexpr auto atsen3() const -> atsen3_f {return atsen3_f((value_ & atsen3_f::mask) != 0);}

	constexpr eth_macacr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macacr_r other) const -> eth_macacr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macacr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Auxiliary timestamp nanoseconds register
 */
class eth_macatsnr_r {
public:

/**
 * Auxiliary Timestamp Contains the lower 31 bits (nanoseconds field) of the auxiliary timestamp.
 */
class auxtslo_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr auxtslo_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macatsnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macatsnr_r>() const {return opsy::utility::clear_set<eth_macatsnr_r>(mask, *this);}
	constexpr auto operator|(eth_macatsnr_r other) const -> eth_macatsnr_r { return static_cast<eth_macatsnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macatsnr_r> other) const -> opsy::utility::clear_set<eth_macatsnr_r> {return opsy::utility::clear_set<eth_macatsnr_r>(eth_macatsnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto auxtslo() const -> auxtslo_f {return auxtslo_f(static_cast<uint32_t>(value_ >> auxtslo_f::offset));}

	constexpr eth_macatsnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macatsnr_r other) const -> eth_macatsnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macatsnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Auxiliary timestamp seconds register
 */
class eth_macatssr_r {
public:

/**
 * Auxiliary Timestamp Contains the lower 32 bits of the Seconds field of the auxiliary timestamp.
 */
class auxtshi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr auxtshi_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macatssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macatssr_r>() const {return opsy::utility::clear_set<eth_macatssr_r>(mask, *this);}
	constexpr auto operator|(eth_macatssr_r other) const -> eth_macatssr_r { return static_cast<eth_macatssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macatssr_r> other) const -> opsy::utility::clear_set<eth_macatssr_r> {return opsy::utility::clear_set<eth_macatssr_r>(eth_macatssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto auxtshi() const -> auxtshi_f {return auxtshi_f(static_cast<uint32_t>(value_ >> auxtshi_f::offset));}

	constexpr eth_macatssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macatssr_r other) const -> eth_macatssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macatssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp Ingress asymmetric correction register
 */
class eth_mactsiacr_r {
public:

/**
 * One-Step Timestamp Ingress Asymmetry Correction This field contains the ingress path asymmetry value to be added to correctionField of Pdelay_Resp PTP packet. The programmed value should be in units of nanoseconds and multiplied by 2^16. For example, 2.5 ns is represented as 0x00028000. The value can also be negative, which is represented in 2's complement form with bit 31 representing the sign bit.
 */
class ostiac_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ostiac_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactsiacr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactsiacr_r>() const {return opsy::utility::clear_set<eth_mactsiacr_r>(mask, *this);}
	constexpr auto operator|(eth_mactsiacr_r other) const -> eth_mactsiacr_r { return static_cast<eth_mactsiacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactsiacr_r> other) const -> opsy::utility::clear_set<eth_mactsiacr_r> {return opsy::utility::clear_set<eth_mactsiacr_r>(eth_mactsiacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ostiac() const -> ostiac_f {return ostiac_f(static_cast<uint32_t>(value_ >> ostiac_f::offset));}

	constexpr eth_mactsiacr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactsiacr_r other) const -> eth_mactsiacr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactsiacr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp Egress asymmetric correction register
 */
class eth_mactseacr_r {
public:

/**
 * One-Step Timestamp Egress Asymmetry Correction This field contains the egress path asymmetry value to be subtracted from correctionField of Pdelay_Resp PTP packet. The programmed value must be the negated value in units of nanoseconds multiplied by 2^16. For example, if the required correction is +2.5 ns, the programmed value must be 0xFFFD_8000, which is the 2's complement of 0x0002_8000(2.5 * 2^16). Similarly, if the required correction is -3.3 ns, the programmed value is 0x0003_4CCC (3.3 *2^16).
 */
class osteac_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr osteac_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactseacr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactseacr_r>() const {return opsy::utility::clear_set<eth_mactseacr_r>(mask, *this);}
	constexpr auto operator|(eth_mactseacr_r other) const -> eth_mactseacr_r { return static_cast<eth_mactseacr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactseacr_r> other) const -> opsy::utility::clear_set<eth_mactseacr_r> {return opsy::utility::clear_set<eth_mactseacr_r>(eth_mactseacr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto osteac() const -> osteac_f {return osteac_f(static_cast<uint32_t>(value_ >> osteac_f::offset));}

	constexpr eth_mactseacr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactseacr_r other) const -> eth_mactseacr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactseacr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp Ingress correction nanosecond register
 */
class eth_mactsicnr_r {
public:

/**
 * Timestamp Ingress Correction This field contains the ingress path correction value as defined by the Ingress Correction expression.
 */
class tsic_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsic_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactsicnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactsicnr_r>() const {return opsy::utility::clear_set<eth_mactsicnr_r>(mask, *this);}
	constexpr auto operator|(eth_mactsicnr_r other) const -> eth_mactsicnr_r { return static_cast<eth_mactsicnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactsicnr_r> other) const -> opsy::utility::clear_set<eth_mactsicnr_r> {return opsy::utility::clear_set<eth_mactsicnr_r>(eth_mactsicnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tsic() const -> tsic_f {return tsic_f(static_cast<uint32_t>(value_ >> tsic_f::offset));}

	constexpr eth_mactsicnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactsicnr_r other) const -> eth_mactsicnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactsicnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Timestamp Egress correction nanosecond register
 */
class eth_mactsecnr_r {
public:

/**
 * Timestamp Egress Correction This field contains the nanoseconds part of the egress path correction value as defined by the Egress Correction expression.
 */
class tsec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsec_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_mactsecnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mactsecnr_r>() const {return opsy::utility::clear_set<eth_mactsecnr_r>(mask, *this);}
	constexpr auto operator|(eth_mactsecnr_r other) const -> eth_mactsecnr_r { return static_cast<eth_mactsecnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mactsecnr_r> other) const -> opsy::utility::clear_set<eth_mactsecnr_r> {return opsy::utility::clear_set<eth_mactsecnr_r>(eth_mactsecnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tsec() const -> tsec_f {return tsec_f(static_cast<uint32_t>(value_ >> tsec_f::offset));}

	constexpr eth_mactsecnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mactsecnr_r other) const -> eth_mactsecnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mactsecnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS control register
 */
class eth_macppscr_r {
public:

/**
 * PPS Output Frequency Control This field controls the frequency of the PPS output (eth_ptp_pps_out) signal. The default value of PPSCTRL is 0000, and the PPS output is 1 pulse (of width clk_ptp_i) every second. For other values of PPSCTRL, the PPS output becomes a generated clock of following frequencies: .. Note: In the binary rollover mode, the PPS output (eth_ptp_pps_out) has a duty cycle of 50 percent with these frequencies. In the digital rollover mode, the PPS output frequency is an average number. The actual clock is of different frequency that gets synchronized every second. For example: When PPSCTRL = 0001, the PPS (1 Hz) has a low period of 537 ms and a high period of 463 ms When PPSCTRL = 0010, the PPS (2 Hz) is a sequence of One clock of 50 percent duty cycle and 537 ms period Second clock of 463 ms period (268 ms low and 195 ms high) When PPSCTRL = 0011, the PPS (4 Hz) is a sequence of Three clocks of 50 percent duty cycle and 268 ms period Fourth clock of 195 ms period (134 ms low and 61 ms high) This behavior is because of the non-linear toggling of bits in the digital rollover mode in the ETH_MACSTNR register.
 */
class ppsctrl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ppsctrl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macppscr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppscr_r>() const {return opsy::utility::clear_set<eth_macppscr_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_r other) const -> eth_macppscr_r { return static_cast<eth_macppscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_r> other) const -> opsy::utility::clear_set<eth_macppscr_r> {return opsy::utility::clear_set<eth_macppscr_r>(eth_macppscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Flexible PPS Output Mode Enable When this bit is set, PPSCTRL[3:0] function as PPSCMD[3:0]. When this bit is reset, PPSCTRL[3:0] function as PPSCTRL (Fixed PPS mode).
 */
class ppsen0_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ppsen0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macppscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macppscr_r>() const {return opsy::utility::clear_set<eth_macppscr_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_r other) const -> eth_macppscr_r { return static_cast<eth_macppscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_r> other) const -> opsy::utility::clear_set<eth_macppscr_r> {return opsy::utility::clear_set<eth_macppscr_r>(eth_macppscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Target Time Register Mode for PPS Output This field indicates the Target Time registers (PPS target time seconds register (ETH_MACPPSTTSR) and PPS target time nanoseconds register (ETH_MACPPSTTNR)) mode for PPS output signal:
 */
class trgtmodsel0_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trgtmodsel0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macppscr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppscr_r>() const {return opsy::utility::clear_set<eth_macppscr_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_r other) const -> eth_macppscr_r { return static_cast<eth_macppscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_r> other) const -> opsy::utility::clear_set<eth_macppscr_r> {return opsy::utility::clear_set<eth_macppscr_r>(eth_macppscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ppsctrl() const -> ppsctrl_f {return ppsctrl_f(static_cast<uint8_t>(value_ >> ppsctrl_f::offset));}
	[[nodiscard]] constexpr auto ppsen0() const -> ppsen0_f {return ppsen0_f((value_ & ppsen0_f::mask) != 0);}
	[[nodiscard]] constexpr auto trgtmodsel0() const -> trgtmodsel0_f {return trgtmodsel0_f(static_cast<uint8_t>(value_ >> trgtmodsel0_f::offset));}

	constexpr eth_macppscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppscr_r other) const -> eth_macppscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS control register
 */
class eth_macppscr_alternate_r {
public:

/**
 * Flexible PPS Output (eth_ptp_pps_out) Control Programming these bits with a non-zero value instructs the MAC to initiate an event. When the command is transferred or synchronized to the PTP clock domain, these bits get cleared automatically. The software should ensure that these bits are programmed only when they are 'all zero'. The following list describes the values of PPSCMD0: This command generates single pulse rising at the start point defined in Target Time Registers (register 455 and 456) and of a duration defined in the PPS Width Register. This command generates the train of pulses rising at the start point defined in the Target Time Registers and of a duration defined in the PPS Width Register and repeated at interval defined in the PPS Interval Register. By default, the PPS pulse train is free-running unless stopped by the Stop Pulse train at time or Stop Pulse Train immediately commands. This command cancels the START Single Pulse and START Pulse Train commands if the system time has not crossed the programmed start time. This command stops the train of pulses initiated by the START Pulse Train command (PPSCMD[3:0] = 0010) after the time programmed in the Target Time registers elapses. This command immediately stops the train of pulses initiated by the START Pulse Train command (PPSCMD[3:0] = 0010). This command cancels the STOP pulse train at time command if the programmed stop time has not elapsed. The PPS pulse train becomes free-running on the successful execution of this command. 0111 to 1111: Reserved, must not be used
 */
class ppscmd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ppscmd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macppscr_alternate_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppscr_alternate_r>() const {return opsy::utility::clear_set<eth_macppscr_alternate_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_alternate_r other) const -> eth_macppscr_alternate_r { return static_cast<eth_macppscr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_alternate_r> other) const -> opsy::utility::clear_set<eth_macppscr_alternate_r> {return opsy::utility::clear_set<eth_macppscr_alternate_r>(eth_macppscr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Flexible PPS Output Mode Enable When this bit is set, Bits[3:0] function as PPSCMD[3:0]. When this bit is reset, Bits[3:0] function as PPSCTRL(Fixed PPS mode).
 */
class ppsen0_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ppsen0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macppscr_alternate_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macppscr_alternate_r>() const {return opsy::utility::clear_set<eth_macppscr_alternate_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_alternate_r other) const -> eth_macppscr_alternate_r { return static_cast<eth_macppscr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_alternate_r> other) const -> opsy::utility::clear_set<eth_macppscr_alternate_r> {return opsy::utility::clear_set<eth_macppscr_alternate_r>(eth_macppscr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Target Time Register Mode for PPS Output This field indicates the Target Time registers (PPS target time seconds register (ETH_MACPPSTTSR) and PPS target time nanoseconds register (ETH_MACPPSTTNR)) mode for PPS output signal:
 */
class trgtmodsel0_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trgtmodsel0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macppscr_alternate_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppscr_alternate_r>() const {return opsy::utility::clear_set<eth_macppscr_alternate_r>(mask, *this);}
	constexpr auto operator|(eth_macppscr_alternate_r other) const -> eth_macppscr_alternate_r { return static_cast<eth_macppscr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppscr_alternate_r> other) const -> opsy::utility::clear_set<eth_macppscr_alternate_r> {return opsy::utility::clear_set<eth_macppscr_alternate_r>(eth_macppscr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ppscmd() const -> ppscmd_f {return ppscmd_f(static_cast<uint8_t>(value_ >> ppscmd_f::offset));}
	[[nodiscard]] constexpr auto ppsen0() const -> ppsen0_f {return ppsen0_f((value_ & ppsen0_f::mask) != 0);}
	[[nodiscard]] constexpr auto trgtmodsel0() const -> trgtmodsel0_f {return trgtmodsel0_f(static_cast<uint8_t>(value_ >> trgtmodsel0_f::offset));}

	constexpr eth_macppscr_alternate_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppscr_alternate_r other) const -> eth_macppscr_alternate_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppscr_alternate_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS target time seconds register
 */
class eth_macppsttsr_r {
public:

/**
 * PPS Target Time Seconds Register This field stores the time in seconds. When the timestamp value matches or exceeds both Target Timestamp registers, the MAC starts or stops the PPS signal output and generates an interrupt (if enabled) based on Target Time mode selected for the corresponding PPS output in the PPS control register (ETH_MACPPSCR).
 */
class tstrh0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tstrh0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macppsttsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppsttsr_r>() const {return opsy::utility::clear_set<eth_macppsttsr_r>(mask, *this);}
	constexpr auto operator|(eth_macppsttsr_r other) const -> eth_macppsttsr_r { return static_cast<eth_macppsttsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppsttsr_r> other) const -> opsy::utility::clear_set<eth_macppsttsr_r> {return opsy::utility::clear_set<eth_macppsttsr_r>(eth_macppsttsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tstrh0() const -> tstrh0_f {return tstrh0_f(static_cast<uint32_t>(value_ >> tstrh0_f::offset));}

	constexpr eth_macppsttsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppsttsr_r other) const -> eth_macppsttsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppsttsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS target time nanoseconds register
 */
class eth_macppsttnr_r {
public:

/**
 * Target Time Low for PPS Register This register stores the time in (signed) nanoseconds. When the value of the timestamp matches the value in both Target Timestamp registers, the MAC starts or stops the PPS signal output and generates an interrupt (if enabled) based on the TRGTMODSEL0 field (Bits [6:5]) in PPS control register (ETH_MACPPSCR). When the TSCTRLSSR bit is set in the Timestamp control Register (ETH_MACTSCR), this value should not exceed 0x3B9A_C9FF. The actual start or stop time of the PPS signal output may have an error margin up to one unit of subsecond increment value.
 */
class ttsl0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ttsl0_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macppsttnr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppsttnr_r>() const {return opsy::utility::clear_set<eth_macppsttnr_r>(mask, *this);}
	constexpr auto operator|(eth_macppsttnr_r other) const -> eth_macppsttnr_r { return static_cast<eth_macppsttnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppsttnr_r> other) const -> opsy::utility::clear_set<eth_macppsttnr_r> {return opsy::utility::clear_set<eth_macppsttnr_r>(eth_macppsttnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * PPS Target Time Register Busy The MAC sets this bit when the PPSCMD0 field in the PPS control register (ETH_MACPPSCR) is programmed to 010 or 011. Programming the PPSCMD0 field to 010 or 011 instructs the MAC to synchronize the Target Time Registers to the PTP clock domain. The MAC clears this bit after synchronizing the Target Time Registers with the PTP clock domain The application must not update the Target Time Registers when this bit is read as 1. Otherwise, the synchronization of the previous programmed time gets corrupted.
 */
class trgtbusy0_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr trgtbusy0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macppsttnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macppsttnr_r>() const {return opsy::utility::clear_set<eth_macppsttnr_r>(mask, *this);}
	constexpr auto operator|(eth_macppsttnr_r other) const -> eth_macppsttnr_r { return static_cast<eth_macppsttnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppsttnr_r> other) const -> opsy::utility::clear_set<eth_macppsttnr_r> {return opsy::utility::clear_set<eth_macppsttnr_r>(eth_macppsttnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ttsl0() const -> ttsl0_f {return ttsl0_f(static_cast<uint32_t>(value_ >> ttsl0_f::offset));}
	[[nodiscard]] constexpr auto trgtbusy0() const -> trgtbusy0_f {return trgtbusy0_f((value_ & trgtbusy0_f::mask) != 0);}

	constexpr eth_macppsttnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppsttnr_r other) const -> eth_macppsttnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppsttnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS interval register
 */
class eth_macppsir_r {
public:

/**
 * PPS Output Signal Interval These bits store the interval between the rising edges of PPS signal output. The interval is stored in terms of number of units of subsecond increment value. You need to program one value less than the required interval. For example, if the PTP reference clock is 50 MHz (period of 20 ns), and desired interval between the rising edges of PPS signal output is 100 ns (that is, 5 units of subsecond increment value), you should program value 4 (5-1) in this register.
 */
class ppsint0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ppsint0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macppsir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppsir_r>() const {return opsy::utility::clear_set<eth_macppsir_r>(mask, *this);}
	constexpr auto operator|(eth_macppsir_r other) const -> eth_macppsir_r { return static_cast<eth_macppsir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppsir_r> other) const -> opsy::utility::clear_set<eth_macppsir_r> {return opsy::utility::clear_set<eth_macppsir_r>(eth_macppsir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ppsint0() const -> ppsint0_f {return ppsint0_f(static_cast<uint32_t>(value_ >> ppsint0_f::offset));}

	constexpr eth_macppsir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppsir_r other) const -> eth_macppsir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppsir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PPS width register
 */
class eth_macppswr_r {
public:

/**
 * PPS Output Signal Width These bits store the width between the rising edge and corresponding falling edge of PPS signal output. The width is stored in terms of number of units of subsecond increment value. You need to program one value less than the required interval. For example, if PTP reference clock is 50 MHz (period of 20 ns), and width between the rising and corresponding falling edges of PPS signal output is 80 ns (that is, four units of subsecond increment value), you should program value 3 (4-1) in this register. Note: The value programmed in this register must be lesser than the value programmed in PPS interval register (ETH_MACPPSIR).
 */
class ppswidth0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ppswidth0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macppswr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macppswr_r>() const {return opsy::utility::clear_set<eth_macppswr_r>(mask, *this);}
	constexpr auto operator|(eth_macppswr_r other) const -> eth_macppswr_r { return static_cast<eth_macppswr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macppswr_r> other) const -> opsy::utility::clear_set<eth_macppswr_r> {return opsy::utility::clear_set<eth_macppswr_r>(eth_macppswr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ppswidth0() const -> ppswidth0_f {return ppswidth0_f(static_cast<uint32_t>(value_ >> ppswidth0_f::offset));}

	constexpr eth_macppswr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macppswr_r other) const -> eth_macppswr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macppswr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PTP Offload control register
 */
class eth_macpocr_r {
public:

/**
 * PTP Offload Enable When this bit is set, the PTP Offload feature is enabled.
 */
class ptoen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ptoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic PTP SYNC message Enable When this bit is set, PTP SYNC message is generated periodically based on interval programmed or trigger from application, when the MAC is programmed to be in Clock Master mode.
 */
class asyncen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr asyncen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic PTP Pdelay_Req message Enable When this bit is set, PTP Pdelay_Req message is generated periodically based on interval programmed or trigger from application, when the MAC is programmed to be in Peer-to-Peer Transparent mode.
 */
class apdreqen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr apdreqen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic PTP SYNC message Trigger When this bit is set, one PTP SYNC message is transmitted. This bit is automatically cleared after the PTP SYNC message is transmitted. The application should set the ASYNCEN bit for this operation.
 */
class asynctrig_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr asynctrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic PTP Pdelay_Req message Trigger When this bit is set, one PTP Pdelay_Req message is transmitted. This bit is automatically cleared after the PTP Pdelay_Req message is transmitted. The application should set the APDREQEN bit for this operation.
 */
class apdreqtrig_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr apdreqtrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable PTO Delay Request/Response response generation When this bit is set, the Delay Request and Delay response are not generated for received SYNC and Delay request packet respectively, as required by the programmed mode.
 */
class drrdis_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr drrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_macpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Domain Number This field indicates the domain Number in which the PTP node is operating.
 */
class dn_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dn_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_macpocr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macpocr_r>() const {return opsy::utility::clear_set<eth_macpocr_r>(mask, *this);}
	constexpr auto operator|(eth_macpocr_r other) const -> eth_macpocr_r { return static_cast<eth_macpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macpocr_r> other) const -> opsy::utility::clear_set<eth_macpocr_r> {return opsy::utility::clear_set<eth_macpocr_r>(eth_macpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ptoen() const -> ptoen_f {return ptoen_f((value_ & ptoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto asyncen() const -> asyncen_f {return asyncen_f((value_ & asyncen_f::mask) != 0);}
	[[nodiscard]] constexpr auto apdreqen() const -> apdreqen_f {return apdreqen_f((value_ & apdreqen_f::mask) != 0);}
	[[nodiscard]] constexpr auto asynctrig() const -> asynctrig_f {return asynctrig_f((value_ & asynctrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto apdreqtrig() const -> apdreqtrig_f {return apdreqtrig_f((value_ & apdreqtrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto drrdis() const -> drrdis_f {return drrdis_f((value_ & drrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto dn() const -> dn_f {return dn_f(static_cast<uint8_t>(value_ >> dn_f::offset));}

	constexpr eth_macpocr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macpocr_r other) const -> eth_macpocr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macpocr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PTP Source Port Identity 0 Register
 */
class eth_macspi0r_r {
public:

/**
 * Source Port Identity 0 This field indicates bits [31:0] of sourcePortIdentity of PTP node.
 */
class spi0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr spi0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macspi0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macspi0r_r>() const {return opsy::utility::clear_set<eth_macspi0r_r>(mask, *this);}
	constexpr auto operator|(eth_macspi0r_r other) const -> eth_macspi0r_r { return static_cast<eth_macspi0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macspi0r_r> other) const -> opsy::utility::clear_set<eth_macspi0r_r> {return opsy::utility::clear_set<eth_macspi0r_r>(eth_macspi0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto spi0() const -> spi0_f {return spi0_f(static_cast<uint32_t>(value_ >> spi0_f::offset));}

	constexpr eth_macspi0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macspi0r_r other) const -> eth_macspi0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macspi0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PTP Source port identity 1 register
 */
class eth_macspi1r_r {
public:

/**
 * Source Port Identity 1 This field indicates bits [63:32] of sourcePortIdentity of PTP node.
 */
class spi1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr spi1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_macspi1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macspi1r_r>() const {return opsy::utility::clear_set<eth_macspi1r_r>(mask, *this);}
	constexpr auto operator|(eth_macspi1r_r other) const -> eth_macspi1r_r { return static_cast<eth_macspi1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macspi1r_r> other) const -> opsy::utility::clear_set<eth_macspi1r_r> {return opsy::utility::clear_set<eth_macspi1r_r>(eth_macspi1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto spi1() const -> spi1_f {return spi1_f(static_cast<uint32_t>(value_ >> spi1_f::offset));}

	constexpr eth_macspi1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macspi1r_r other) const -> eth_macspi1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macspi1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PTP Source port identity 2 register
 */
class eth_macspi2r_r {
public:

/**
 * Source Port Identity 2 This field indicates bits [79:64] of sourcePortIdentity of PTP node.
 */
class spi2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr spi2_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_macspi2r_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_macspi2r_r>() const {return opsy::utility::clear_set<eth_macspi2r_r>(mask, *this);}
	constexpr auto operator|(eth_macspi2r_r other) const -> eth_macspi2r_r { return static_cast<eth_macspi2r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_macspi2r_r> other) const -> opsy::utility::clear_set<eth_macspi2r_r> {return opsy::utility::clear_set<eth_macspi2r_r>(eth_macspi2r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto spi2() const -> spi2_f {return spi2_f(static_cast<uint16_t>(value_ >> spi2_f::offset));}

	constexpr eth_macspi2r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_macspi2r_r other) const -> eth_macspi2r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_macspi2r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Log message interval register
 */
class eth_maclmir_r {
public:

/**
 * Log Sync Interval This field indicates the periodicity of the automatically generated SYNC message when the PTP node is Master. Allowed values are -15 to 15. Negative value must be represented in 2's-complement form. For example, if the required value is -1, the value programmed must be 0xFF.
 */
class lsi_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr lsi_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maclmir_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maclmir_r>() const {return opsy::utility::clear_set<eth_maclmir_r>(mask, *this);}
	constexpr auto operator|(eth_maclmir_r other) const -> eth_maclmir_r { return static_cast<eth_maclmir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclmir_r> other) const -> opsy::utility::clear_set<eth_maclmir_r> {return opsy::utility::clear_set<eth_maclmir_r>(eth_maclmir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay_Req to SYNC Ratio In Slave mode, it is used for controlling frequency of Delay_Req messages transmitted. Others: Reserved, must not be used The master sends this information (logMinDelayReqInterval) in the DelayResp PTP messages to the slave. The reception processes this value from the received DelayResp messages and updates this field accordingly. In the Slave mode, the host must not write/update this register unless it has to override the received value. In Master mode, the sum of this field and logSyncInterval (LSI) field is provided in the logMinDelayReqInterval field of the generated multicast Delay_Resp PTP message.
 */
class drsyncr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr drsyncr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maclmir_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maclmir_r>() const {return opsy::utility::clear_set<eth_maclmir_r>(mask, *this);}
	constexpr auto operator|(eth_maclmir_r other) const -> eth_maclmir_r { return static_cast<eth_maclmir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclmir_r> other) const -> opsy::utility::clear_set<eth_maclmir_r> {return opsy::utility::clear_set<eth_maclmir_r>(eth_maclmir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Log Min Pdelay_Req Interval This field indicates logMinPdelayReqInterval of PTP node. This is used to schedule the periodic Pdelay request packet transmission. Allowed values are -15 to 15.Negative value must be represented in 2's-complement form. For example, if the required value is -1, the value programmed must be 0xFF.
 */
class lmpdri_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lmpdri_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_maclmir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_maclmir_r>() const {return opsy::utility::clear_set<eth_maclmir_r>(mask, *this);}
	constexpr auto operator|(eth_maclmir_r other) const -> eth_maclmir_r { return static_cast<eth_maclmir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_maclmir_r> other) const -> opsy::utility::clear_set<eth_maclmir_r> {return opsy::utility::clear_set<eth_maclmir_r>(eth_maclmir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lsi() const -> lsi_f {return lsi_f(static_cast<uint8_t>(value_ >> lsi_f::offset));}
	[[nodiscard]] constexpr auto drsyncr() const -> drsyncr_f {return drsyncr_f(static_cast<uint8_t>(value_ >> drsyncr_f::offset));}
	[[nodiscard]] constexpr auto lmpdri() const -> lmpdri_f {return lmpdri_f(static_cast<uint8_t>(value_ >> lmpdri_f::offset));}

	constexpr eth_maclmir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_maclmir_r other) const -> eth_maclmir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_maclmir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Operating mode Register
 */
class eth_mtlomr_r {
public:

/**
 * Drop Transmit Status When this bit is set, the Tx packet status received from the MAC is dropped in the MTL. When this bit is reset, the Tx packet status received from the MAC is forwarded to the application.
 */
class dtxsts_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtxsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlomr_r>() const {return opsy::utility::clear_set<eth_mtlomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlomr_r other) const -> eth_mtlomr_r { return static_cast<eth_mtlomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlomr_r> other) const -> opsy::utility::clear_set<eth_mtlomr_r> {return opsy::utility::clear_set<eth_mtlomr_r>(eth_mtlomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counters Preset When this bit is set: Tx queue underflow register (ETH_MTLTXQUR) is initialized/preset to 0x7F0. Missed Packet and Overflow Packet counters in Rx queue missed packet and overflow counter register (ETH_MTLRXQMPOCR) is initialized/preset to 0x7F0 This bit is cleared automatically.
 */
class cntprst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cntprst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlomr_r>() const {return opsy::utility::clear_set<eth_mtlomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlomr_r other) const -> eth_mtlomr_r { return static_cast<eth_mtlomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlomr_r> other) const -> opsy::utility::clear_set<eth_mtlomr_r> {return opsy::utility::clear_set<eth_mtlomr_r>(eth_mtlomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counters Reset When this bit is set, all counters are reset. This bit is cleared automatically after 1 clock cycle. If this bit is set along with CNTPRST bit, CNTPRST has precedence.
 */
class cntclr_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cntclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlomr_r>() const {return opsy::utility::clear_set<eth_mtlomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlomr_r other) const -> eth_mtlomr_r { return static_cast<eth_mtlomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlomr_r> other) const -> opsy::utility::clear_set<eth_mtlomr_r> {return opsy::utility::clear_set<eth_mtlomr_r>(eth_mtlomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dtxsts() const -> dtxsts_f {return dtxsts_f((value_ & dtxsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntprst() const -> cntprst_f {return cntprst_f((value_ & cntprst_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntclr() const -> cntclr_f {return cntclr_f((value_ & cntclr_f::mask) != 0);}

	constexpr eth_mtlomr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlomr_r other) const -> eth_mtlomr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlomr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Interrupt status Register
 */
class eth_mtlisr_r {
public:

/**
 * Queue interrupt status This bit indicates that an interrupt has been generated by Queue. To reset this bit, read ETH_MTLQICSR register to identify the interrupt cause and clear the source.
 */
class q0is_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr q0is_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlisr_r>() const {return opsy::utility::clear_set<eth_mtlisr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlisr_r other) const -> eth_mtlisr_r { return static_cast<eth_mtlisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlisr_r> other) const -> opsy::utility::clear_set<eth_mtlisr_r> {return opsy::utility::clear_set<eth_mtlisr_r>(eth_mtlisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto q0is() const -> q0is_f {return q0is_f((value_ & q0is_f::mask) != 0);}

	constexpr eth_mtlisr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlisr_r other) const -> eth_mtlisr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlisr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx queue operating mode Register
 */
class eth_mtltxqomr_r {
public:

/**
 * Flush Transmit Queue When this bit is set, the Tx queue controller logic is reset to its default values. Therefore, all the data in the Tx queue is lost or flushed. This bit is internally reset when the flushing operation is complete. Until this bit is reset, you should not write to the ETH_MTLTXQOMR register. The data which is already accepted by the MAC transmitter is not flushed. It is scheduled for transmission and results in underflow and runt packet transmission. Note: The flush operation is complete only when the Tx queue is empty and the application has accepted the pending Tx Status of all transmitted packets. To complete this flush operation, the PHY Tx clock (eth_mii_tx_clk) should be active.
 */
class ftq_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ftq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqomr_r>() const {return opsy::utility::clear_set<eth_mtltxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return static_cast<eth_mtltxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqomr_r> other) const -> opsy::utility::clear_set<eth_mtltxqomr_r> {return opsy::utility::clear_set<eth_mtltxqomr_r>(eth_mtltxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Store and Forward When this bit is set, the transmission starts when a full packet resides in the MTL Tx queue. When this bit is set, the TTC values specified in Bits[6:4] of this register are ignored. This bit should be changed only when the transmission is stopped.
 */
class tsf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqomr_r>() const {return opsy::utility::clear_set<eth_mtltxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return static_cast<eth_mtltxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqomr_r> other) const -> opsy::utility::clear_set<eth_mtltxqomr_r> {return opsy::utility::clear_set<eth_mtltxqomr_r>(eth_mtltxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Queue Enable This field is used to enable/disable the transmit queue . Others: Reserved, must not be used. Note: In multiple Tx queues configuration, all the queues are disabled by default. Enable the Tx queue by programming this field.
 */
class txqen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr txqen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqomr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqomr_r>() const {return opsy::utility::clear_set<eth_mtltxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return static_cast<eth_mtltxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqomr_r> other) const -> opsy::utility::clear_set<eth_mtltxqomr_r> {return opsy::utility::clear_set<eth_mtltxqomr_r>(eth_mtltxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transmit Threshold Control These bits control the threshold level of the MTL Tx queue. The transmission starts when the packet size within the MTL Tx queue is larger than the threshold. In addition, full packets with length less than the threshold are also transmitted. These bits are used only when the TSF bit is reset.
 */
class ttc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ttc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqomr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqomr_r>() const {return opsy::utility::clear_set<eth_mtltxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return static_cast<eth_mtltxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqomr_r> other) const -> opsy::utility::clear_set<eth_mtltxqomr_r> {return opsy::utility::clear_set<eth_mtltxqomr_r>(eth_mtltxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transmit queue size This field indicates the size of the allocated transmit queues in blocks of 256 bytes. Queue size range from 256 bytes (TQS=0b000) to 2048 bytes (TQS=0b111).
 */
class tqs_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tqs_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqomr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqomr_r>() const {return opsy::utility::clear_set<eth_mtltxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return static_cast<eth_mtltxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqomr_r> other) const -> opsy::utility::clear_set<eth_mtltxqomr_r> {return opsy::utility::clear_set<eth_mtltxqomr_r>(eth_mtltxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ftq() const -> ftq_f {return ftq_f((value_ & ftq_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsf() const -> tsf_f {return tsf_f((value_ & tsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto txqen() const -> txqen_f {return txqen_f(static_cast<uint8_t>(value_ >> txqen_f::offset));}
	[[nodiscard]] constexpr auto ttc() const -> ttc_f {return ttc_f(static_cast<uint8_t>(value_ >> ttc_f::offset));}
	[[nodiscard]] constexpr auto tqs() const -> tqs_f {return tqs_f(static_cast<uint8_t>(value_ >> tqs_f::offset));}

	constexpr eth_mtltxqomr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtltxqomr_r other) const -> eth_mtltxqomr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtltxqomr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1110000000000001000; // 458760 0x70008

private:
	uint32_t value_;
};

/**
 * Tx queue underflow register
 */
class eth_mtltxqur_r {
public:

/**
 * Underflow Packet Counter This field indicates the number of packets aborted by the controller because of Tx queue Underflow. This counter is incremented each time the MAC aborts outgoing packet because of underflow. The counter is cleared when this register is read.
 */
class uffrmcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr uffrmcnt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_mtltxqur_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqur_r>() const {return opsy::utility::clear_set<eth_mtltxqur_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqur_r other) const -> eth_mtltxqur_r { return static_cast<eth_mtltxqur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqur_r> other) const -> opsy::utility::clear_set<eth_mtltxqur_r> {return opsy::utility::clear_set<eth_mtltxqur_r>(eth_mtltxqur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Overflow Bit for Underflow Packet Counter This bit is set every time the Tx queue Underflow Packet Counter field overflows, that is, it has crossed the maximum count. In such a scenario, the overflow packet counter is reset to all-zeros and this bit indicates that the rollover happened.
 */
class ufcntovf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ufcntovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqur_r>() const {return opsy::utility::clear_set<eth_mtltxqur_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqur_r other) const -> eth_mtltxqur_r { return static_cast<eth_mtltxqur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqur_r> other) const -> opsy::utility::clear_set<eth_mtltxqur_r> {return opsy::utility::clear_set<eth_mtltxqur_r>(eth_mtltxqur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uffrmcnt() const -> uffrmcnt_f {return uffrmcnt_f(static_cast<uint16_t>(value_ >> uffrmcnt_f::offset));}
	[[nodiscard]] constexpr auto ufcntovf() const -> ufcntovf_f {return ufcntovf_f((value_ & ufcntovf_f::mask) != 0);}

	constexpr eth_mtltxqur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtltxqur_r other) const -> eth_mtltxqur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtltxqur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Tx queue debug register
 */
class eth_mtltxqdr_r {
public:

/**
 * Transmit Queue in Pause When this bit is high and the Rx flow control is enabled, it indicates that the Tx queue is in the Pause condition (in the Full-duplex only mode) because of the following: Reception of the PFC packet for the priorities assigned to the Tx queue when PFC is enabled Reception of 802.3x Pause packet when PFC is disabled
 */
class txqpaused_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txqpaused_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MTL Tx Queue Read Controller Status This field indicates the state of the Tx Queue Read Controller:
 */
class trcsts_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trcsts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MTL Tx Queue Write Controller Status When high, this bit indicates that the MTL Tx queue Write Controller is active, and it is transferring the data to the Tx queue.
 */
class twcsts_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr twcsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MTL Tx Queue Not Empty Status When this bit is high, it indicates that the MTL Tx queue is not empty and some data is left for transmission.
 */
class txqsts_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txqsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MTL Tx Status FIFO Full Status When high, this bit indicates that the MTL Tx Status FIFO is full. Therefore, the MTL cannot accept any more packets for transmission.
 */
class txstsfsts_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txstsfsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of Packets in the Transmit Queue This field indicates the current number of packets in the Tx queue. When the DTXSTS bit of Operating mode Register (ETH_MTLOMR) register is set to 1, this field does not reflect the number of packets in the Transmit queue.
 */
class ptxq_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ptxq_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of Status Words in Tx Status FIFO of Queue This field indicates the current number of status in the Tx Status FIFO of this queue. When the DTXSTS bit of ETH_MTLOMR register is set to 1, this field does not reflect the number of status words in Tx Status FIFO.
 */
class stxstsf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr stxstsf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtltxqdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtltxqdr_r>() const {return opsy::utility::clear_set<eth_mtltxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return static_cast<eth_mtltxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtltxqdr_r> other) const -> opsy::utility::clear_set<eth_mtltxqdr_r> {return opsy::utility::clear_set<eth_mtltxqdr_r>(eth_mtltxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto txqpaused() const -> txqpaused_f {return txqpaused_f((value_ & txqpaused_f::mask) != 0);}
	[[nodiscard]] constexpr auto trcsts() const -> trcsts_f {return trcsts_f(static_cast<uint8_t>(value_ >> trcsts_f::offset));}
	[[nodiscard]] constexpr auto twcsts() const -> twcsts_f {return twcsts_f((value_ & twcsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto txqsts() const -> txqsts_f {return txqsts_f((value_ & txqsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto txstsfsts() const -> txstsfsts_f {return txstsfsts_f((value_ & txstsfsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto ptxq() const -> ptxq_f {return ptxq_f(static_cast<uint8_t>(value_ >> ptxq_f::offset));}
	[[nodiscard]] constexpr auto stxstsf() const -> stxstsf_f {return stxstsf_f(static_cast<uint8_t>(value_ >> stxstsf_f::offset));}

	constexpr eth_mtltxqdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtltxqdr_r other) const -> eth_mtltxqdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtltxqdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Queue interrupt control status Register
 */
class eth_mtlqicsr_r {
public:

/**
 * Transmit Queue Underflow Interrupt Status This bit indicates that the Transmit Queue had an underflow while transmitting the packet. Transmission is suspended and an Underflow Error TDES3[2] is set. This bit is cleared when the application writes 1 to this bit.
 */
class txunfis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txunfis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlqicsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlqicsr_r>() const {return opsy::utility::clear_set<eth_mtlqicsr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlqicsr_r other) const -> eth_mtlqicsr_r { return static_cast<eth_mtlqicsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlqicsr_r> other) const -> opsy::utility::clear_set<eth_mtlqicsr_r> {return opsy::utility::clear_set<eth_mtlqicsr_r>(eth_mtlqicsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Queue Underflow Interrupt Enable When this bit is set, the Transmit Queue Underflow interrupt is enabled. When this bit is reset, the Transmit Queue Underflow interrupt is disabled.
 */
class txuie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txuie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlqicsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlqicsr_r>() const {return opsy::utility::clear_set<eth_mtlqicsr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlqicsr_r other) const -> eth_mtlqicsr_r { return static_cast<eth_mtlqicsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlqicsr_r> other) const -> opsy::utility::clear_set<eth_mtlqicsr_r> {return opsy::utility::clear_set<eth_mtlqicsr_r>(eth_mtlqicsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Queue Overflow Interrupt Status This bit indicates that the Receive Queue had an overflow while receiving the packet. If a partial packet is transferred to the application, the overflow status is set in RDES3[21]. This bit is cleared when the application writes 1 to this bit.
 */
class rxovfis_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxovfis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlqicsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlqicsr_r>() const {return opsy::utility::clear_set<eth_mtlqicsr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlqicsr_r other) const -> eth_mtlqicsr_r { return static_cast<eth_mtlqicsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlqicsr_r> other) const -> opsy::utility::clear_set<eth_mtlqicsr_r> {return opsy::utility::clear_set<eth_mtlqicsr_r>(eth_mtlqicsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Queue Overflow Interrupt Enable When this bit is set, the Receive Queue Overflow interrupt is enabled. When this bit is reset, the Receive Queue Overflow interrupt is disabled.
 */
class rxoie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxoie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlqicsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlqicsr_r>() const {return opsy::utility::clear_set<eth_mtlqicsr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlqicsr_r other) const -> eth_mtlqicsr_r { return static_cast<eth_mtlqicsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlqicsr_r> other) const -> opsy::utility::clear_set<eth_mtlqicsr_r> {return opsy::utility::clear_set<eth_mtlqicsr_r>(eth_mtlqicsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto txunfis() const -> txunfis_f {return txunfis_f((value_ & txunfis_f::mask) != 0);}
	[[nodiscard]] constexpr auto txuie() const -> txuie_f {return txuie_f((value_ & txuie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxovfis() const -> rxovfis_f {return rxovfis_f((value_ & rxovfis_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxoie() const -> rxoie_f {return rxoie_f((value_ & rxoie_f::mask) != 0);}

	constexpr eth_mtlqicsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlqicsr_r other) const -> eth_mtlqicsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlqicsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx queue operating mode register
 */
class eth_mtlrxqomr_r {
public:

/**
 * Receive Queue Threshold Control These bits control the threshold level of the MTL Rx queue (in bytes): The received packet is transferred to the application or DMA when the packet size within the MTL Rx queue is larger than the threshold. In addition, full packets with length less than the threshold are automatically transferred. This field is valid only when the RSF bit is zero. This field is ignored when the RSF bit is set to 1.
 */
class rtc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rtc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Forward Undersized Good Packets When this bit is set, the Rx queue forwards the undersized good packets (packets with no error and length less than 64 bytes), including pad-bytes and CRC. When this bit is reset, the Rx queue drops all packets of less than 64 bytes, unless a packet is already transferred because of the lower value of Rx Threshold, for example, RTC = 01.
 */
class fup_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fup_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Forward Error Packets When this bit is reset, the Rx queue drops packets with error status (CRC error, receive error, watchdog timeout, or overflow). However, if the start byte (write) pointer of a packet is already transferred to the read controller side (in Threshold mode), the packet is not dropped. When this bit is set, all packets except the runt error packets are forwarded to the application or DMA. If the RSF bit is set and the Rx queue overflows when a partial packet is written, the packet is dropped irrespective of the setting of this bit. However, if the RSF bit is reset and the Rx queue overflows when a partial packet is written, a partial packet may be forwarded to the application or DMA.
 */
class fep_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Queue Store and Forward When this bit is set, the Ethernet peripheral reads a packet from the Rx queue only after the complete packet has been written to it, ignoring the RTC field of this register. When this bit is reset, the Rx queue operates in the Threshold (cut-through) mode, subject to the threshold specified by the RTC field of this register.
 */
class rsf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Disable Dropping of TCP/IP Checksum Error Packets When this bit is set, the MAC does not drop the packets which only have the errors detected by the Receive Checksum Offload engine. Such packets have errors only in the encapsulated payload. There are no errors (including FCS error) in the Ethernet packet received by the MAC. When this bit is reset, all error packets are dropped if the FEP bit is reset.
 */
class dis_tcp_ef_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dis_tcp_ef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Queue Size This field is read-only and the configured Rx FIFO size in blocks of 256 bytes is reflected in the reset value. The size of the Queue is (RQS+1)*256 bytes.
 */
class rqs_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rqs_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtlrxqomr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqomr_r>() const {return opsy::utility::clear_set<eth_mtlrxqomr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return static_cast<eth_mtlrxqomr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqomr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqomr_r> {return opsy::utility::clear_set<eth_mtlrxqomr_r>(eth_mtlrxqomr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rtc() const -> rtc_f {return rtc_f(static_cast<uint8_t>(value_ >> rtc_f::offset));}
	[[nodiscard]] constexpr auto fup() const -> fup_f {return fup_f((value_ & fup_f::mask) != 0);}
	[[nodiscard]] constexpr auto fep() const -> fep_f {return fep_f((value_ & fep_f::mask) != 0);}
	[[nodiscard]] constexpr auto rsf() const -> rsf_f {return rsf_f((value_ & rsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dis_tcp_ef() const -> dis_tcp_ef_f {return dis_tcp_ef_f((value_ & dis_tcp_ef_f::mask) != 0);}
	[[nodiscard]] constexpr auto rqs() const -> rqs_f {return rqs_f(static_cast<uint8_t>(value_ >> rqs_f::offset));}

	constexpr eth_mtlrxqomr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlrxqomr_r other) const -> eth_mtlrxqomr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlrxqomr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11100000000000000000000; // 7340032 0x700000

private:
	uint32_t value_;
};

/**
 * Rx queue missed packet and overflow counter register
 */
class eth_mtlrxqmpocr_r {
public:

/**
 * Overflow Packet Counter This field indicates the number of packets discarded by the Ethernet peripheral because of Receive queue overflow. This counter is incremented each time the Ethernet peripheral discards an incoming packet because of overflow. This counter is reset when this register is read.
 */
class ovfpktcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ovfpktcnt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_mtlrxqmpocr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqmpocr_r>() const {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqmpocr_r other) const -> eth_mtlrxqmpocr_r { return static_cast<eth_mtlrxqmpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqmpocr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqmpocr_r> {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(eth_mtlrxqmpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Overflow Counter Overflow Bit When set, this bit indicates that the Rx Queue Overflow Packet Counter field crossed the maximum limit.
 */
class ovfcntovf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovfcntovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqmpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqmpocr_r>() const {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqmpocr_r other) const -> eth_mtlrxqmpocr_r { return static_cast<eth_mtlrxqmpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqmpocr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqmpocr_r> {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(eth_mtlrxqmpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Missed Packet Counter This field indicates the number of packets missed by the Ethernet peripheral because the application requested to flush the packets for this queue. This counter is reset when this register is read. This counter is incremented by 1 when the DMA discards the packet because of buffer unavailability.
 */
class mispktcnt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mispktcnt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_mtlrxqmpocr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqmpocr_r>() const {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqmpocr_r other) const -> eth_mtlrxqmpocr_r { return static_cast<eth_mtlrxqmpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqmpocr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqmpocr_r> {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(eth_mtlrxqmpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Missed Packet Counter Overflow Bit When set, this bit indicates that the Rx Queue Missed Packet Counter crossed the maximum limit.
 */
class miscntovf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr miscntovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqmpocr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqmpocr_r>() const {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqmpocr_r other) const -> eth_mtlrxqmpocr_r { return static_cast<eth_mtlrxqmpocr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqmpocr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqmpocr_r> {return opsy::utility::clear_set<eth_mtlrxqmpocr_r>(eth_mtlrxqmpocr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovfpktcnt() const -> ovfpktcnt_f {return ovfpktcnt_f(static_cast<uint16_t>(value_ >> ovfpktcnt_f::offset));}
	[[nodiscard]] constexpr auto ovfcntovf() const -> ovfcntovf_f {return ovfcntovf_f((value_ & ovfcntovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto mispktcnt() const -> mispktcnt_f {return mispktcnt_f(static_cast<uint16_t>(value_ >> mispktcnt_f::offset));}
	[[nodiscard]] constexpr auto miscntovf() const -> miscntovf_f {return miscntovf_f((value_ & miscntovf_f::mask) != 0);}

	constexpr eth_mtlrxqmpocr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlrxqmpocr_r other) const -> eth_mtlrxqmpocr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlrxqmpocr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Rx queue debug register
 */
class eth_mtlrxqdr_r {
public:

/**
 * MTL Rx Queue Write Controller Active Status When high, this bit indicates that the MTL Rx queue Write controller is active, and it is transferring a received packet to the Rx queue.
 */
class rwcsts_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rwcsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_mtlrxqdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqdr_r>() const {return opsy::utility::clear_set<eth_mtlrxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqdr_r other) const -> eth_mtlrxqdr_r { return static_cast<eth_mtlrxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqdr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqdr_r> {return opsy::utility::clear_set<eth_mtlrxqdr_r>(eth_mtlrxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MTL Rx Queue Read Controller State This field gives the state of the Rx queue Read controller:
 */
class rrcsts_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rrcsts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtlrxqdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqdr_r>() const {return opsy::utility::clear_set<eth_mtlrxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqdr_r other) const -> eth_mtlrxqdr_r { return static_cast<eth_mtlrxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqdr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqdr_r> {return opsy::utility::clear_set<eth_mtlrxqdr_r>(eth_mtlrxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MTL Rx Queue Fill-Level Status This field gives the status of the fill-level of the Rx queue:
 */
class rxqsts_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rxqsts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_mtlrxqdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqdr_r>() const {return opsy::utility::clear_set<eth_mtlrxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqdr_r other) const -> eth_mtlrxqdr_r { return static_cast<eth_mtlrxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqdr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqdr_r> {return opsy::utility::clear_set<eth_mtlrxqdr_r>(eth_mtlrxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of Packets in Receive Queue This field indicates the current number of packets in the Rx queue. The theoretical maximum value for this field is 256Kbyte/16bytes = 16K Packets, that is, Max_Queue_Size/Min_Packet_Size.
 */
class prxq_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr prxq_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_mtlrxqdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_mtlrxqdr_r>() const {return opsy::utility::clear_set<eth_mtlrxqdr_r>(mask, *this);}
	constexpr auto operator|(eth_mtlrxqdr_r other) const -> eth_mtlrxqdr_r { return static_cast<eth_mtlrxqdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_mtlrxqdr_r> other) const -> opsy::utility::clear_set<eth_mtlrxqdr_r> {return opsy::utility::clear_set<eth_mtlrxqdr_r>(eth_mtlrxqdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rwcsts() const -> rwcsts_f {return rwcsts_f((value_ & rwcsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto rrcsts() const -> rrcsts_f {return rrcsts_f(static_cast<uint8_t>(value_ >> rrcsts_f::offset));}
	[[nodiscard]] constexpr auto rxqsts() const -> rxqsts_f {return rxqsts_f(static_cast<uint8_t>(value_ >> rxqsts_f::offset));}
	[[nodiscard]] constexpr auto prxq() const -> prxq_f {return prxq_f(static_cast<uint16_t>(value_ >> prxq_f::offset));}

	constexpr eth_mtlrxqdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_mtlrxqdr_r other) const -> eth_mtlrxqdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_mtlrxqdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DMA mode register
 */
class eth_dmamr_r {
public:

/**
 * Software Reset When this bit is set, the MAC and the DMA controller reset the logic and all internal registers of the DMA, MTL, and MAC. This bit is automatically cleared after the reset operation is complete in all clock domains. Before reprogramming any register, a value of zero should be read in this bit. Note: The reset operation is complete only when all resets in all active clock domains are deasserted. Therefore, it is essential that all PHY inputs clocks (applicable for the selected PHY interface) are present for software reset completion. The time to complete the software reset operation depends on the frequency of the slowest active clock.
 */
class swr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmamr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmamr_r>() const {return opsy::utility::clear_set<eth_dmamr_r>(mask, *this);}
	constexpr auto operator|(eth_dmamr_r other) const -> eth_dmamr_r { return static_cast<eth_dmamr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmamr_r> other) const -> opsy::utility::clear_set<eth_dmamr_r> {return opsy::utility::clear_set<eth_dmamr_r>(eth_dmamr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Tx or Rx Arbitration Scheme This bit specifies the arbitration scheme between the Transmit and Receive paths of all channels: The priority between the paths is according to the priority specified in Bits[14:12] and the priority weight is specified in the TXPR bit. The Tx path has priority over the Rx path when the TXPR bit is set. Otherwise, the Rx path has priority over the Tx path.
 */
class da_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr da_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmamr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmamr_r>() const {return opsy::utility::clear_set<eth_dmamr_r>(mask, *this);}
	constexpr auto operator|(eth_dmamr_r other) const -> eth_dmamr_r { return static_cast<eth_dmamr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmamr_r> other) const -> opsy::utility::clear_set<eth_dmamr_r> {return opsy::utility::clear_set<eth_dmamr_r>(eth_dmamr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit priority When set, this bit indicates that the Tx DMA has higher priority than the Rx DMA during arbitration for the system-side bus.
 */
class txpr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txpr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmamr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmamr_r>() const {return opsy::utility::clear_set<eth_dmamr_r>(mask, *this);}
	constexpr auto operator|(eth_dmamr_r other) const -> eth_dmamr_r { return static_cast<eth_dmamr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmamr_r> other) const -> opsy::utility::clear_set<eth_dmamr_r> {return opsy::utility::clear_set<eth_dmamr_r>(eth_dmamr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Priority ratio These bits control the priority ratio in weighted round-robin arbitration between the Rx DMA and Tx DMA. These bits are valid only when the DA bit is reset. The priority ratio is Rx:Tx or Tx:Rx depending on whether the TXPR bit is reset or set.
 */
class pr_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmamr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmamr_r>() const {return opsy::utility::clear_set<eth_dmamr_r>(mask, *this);}
	constexpr auto operator|(eth_dmamr_r other) const -> eth_dmamr_r { return static_cast<eth_dmamr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmamr_r> other) const -> opsy::utility::clear_set<eth_dmamr_r> {return opsy::utility::clear_set<eth_dmamr_r>(eth_dmamr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Interrupt Mode This field defines the interrupt mode of the Ethernet peripheral. The behavior of the interrupt signal and of the RI/TI bits in the ETH_DMACSR register changes depending on the INTM value (refer to Table651: Transfer complete interrupt behavior).
 */
class intm_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr intm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmamr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmamr_r>() const {return opsy::utility::clear_set<eth_dmamr_r>(mask, *this);}
	constexpr auto operator|(eth_dmamr_r other) const -> eth_dmamr_r { return static_cast<eth_dmamr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmamr_r> other) const -> opsy::utility::clear_set<eth_dmamr_r> {return opsy::utility::clear_set<eth_dmamr_r>(eth_dmamr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto swr() const -> swr_f {return swr_f((value_ & swr_f::mask) != 0);}
	[[nodiscard]] constexpr auto da() const -> da_f {return da_f((value_ & da_f::mask) != 0);}
	[[nodiscard]] constexpr auto txpr() const -> txpr_f {return txpr_f((value_ & txpr_f::mask) != 0);}
	[[nodiscard]] constexpr auto pr() const -> pr_f {return pr_f(static_cast<uint8_t>(value_ >> pr_f::offset));}
	[[nodiscard]] constexpr auto intm() const -> intm_f {return intm_f(static_cast<uint8_t>(value_ >> intm_f::offset));}

	constexpr eth_dmamr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmamr_r other) const -> eth_dmamr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmamr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * System bus mode register
 */
class eth_dmasbmr_r {
public:

/**
 * Fixed Burst Length When this bit is set to 1, the AHB master will initiate burst transfers of specified length (INCRx or SINGLE). When this bit is set to 0, the AHB master will initiate transfers of unspecified length (INCR) or SINGLE transfers.
 */
class fb_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmasbmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmasbmr_r>() const {return opsy::utility::clear_set<eth_dmasbmr_r>(mask, *this);}
	constexpr auto operator|(eth_dmasbmr_r other) const -> eth_dmasbmr_r { return static_cast<eth_dmasbmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmasbmr_r> other) const -> opsy::utility::clear_set<eth_dmasbmr_r> {return opsy::utility::clear_set<eth_dmasbmr_r>(eth_dmasbmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address-Aligned Beats When this bit is set to 1, the master performs address-aligned burst transfers on Read and Write channels.
 */
class aal_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr aal_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmasbmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmasbmr_r>() const {return opsy::utility::clear_set<eth_dmasbmr_r>(mask, *this);}
	constexpr auto operator|(eth_dmasbmr_r other) const -> eth_dmasbmr_r { return static_cast<eth_dmasbmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmasbmr_r> other) const -> opsy::utility::clear_set<eth_dmasbmr_r> {return opsy::utility::clear_set<eth_dmasbmr_r>(eth_dmasbmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mixed Burst When this bit is set high and the FB bit is low, the AHB master performs undefined bursts transfers (INCR) for burst length of 16 or more. For burst length of 16 or less, the AHB master performs fixed burst transfers (INCRx and SINGLE).
 */
class mb_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmasbmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmasbmr_r>() const {return opsy::utility::clear_set<eth_dmasbmr_r>(mask, *this);}
	constexpr auto operator|(eth_dmasbmr_r other) const -> eth_dmasbmr_r { return static_cast<eth_dmasbmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmasbmr_r> other) const -> opsy::utility::clear_set<eth_dmasbmr_r> {return opsy::utility::clear_set<eth_dmasbmr_r>(eth_dmasbmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rebuild INCRx Burst When this bit is set high and the AHB master gets SPLIT, RETRY, or Early Burst Termination (EBT) response, the AHB master interface rebuilds the pending beats of any initiated burst transfer with INCRx and SINGLE transfers. By default, the AHB master interface rebuilds pending beats of an EBT with an unspecified (INCR) burst.
 */
class rb_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmasbmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmasbmr_r>() const {return opsy::utility::clear_set<eth_dmasbmr_r>(mask, *this);}
	constexpr auto operator|(eth_dmasbmr_r other) const -> eth_dmasbmr_r { return static_cast<eth_dmasbmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmasbmr_r> other) const -> opsy::utility::clear_set<eth_dmasbmr_r> {return opsy::utility::clear_set<eth_dmasbmr_r>(eth_dmasbmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fb() const -> fb_f {return fb_f((value_ & fb_f::mask) != 0);}
	[[nodiscard]] constexpr auto aal() const -> aal_f {return aal_f((value_ & aal_f::mask) != 0);}
	[[nodiscard]] constexpr auto mb() const -> mb_f {return mb_f((value_ & mb_f::mask) != 0);}
	[[nodiscard]] constexpr auto rb() const -> rb_f {return rb_f((value_ & rb_f::mask) != 0);}

	constexpr eth_dmasbmr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmasbmr_r other) const -> eth_dmasbmr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmasbmr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Interrupt status register
 */
class eth_dmaisr_r {
public:

/**
 * DMA Channel Interrupt Status This bit indicates an interrupt event in DMA Channel. To reset this bit to 0, the software must read the corresponding register in DMA Channel to get the exact cause of the interrupt and clear its source.
 */
class dc0is_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dc0is_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmaisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmaisr_r>() const {return opsy::utility::clear_set<eth_dmaisr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaisr_r other) const -> eth_dmaisr_r { return static_cast<eth_dmaisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaisr_r> other) const -> opsy::utility::clear_set<eth_dmaisr_r> {return opsy::utility::clear_set<eth_dmaisr_r>(eth_dmaisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MTL Interrupt Status This bit indicates an interrupt event in the MTL. To reset this bit to 1'b0, the software must read the corresponding register in the MTL to get the exact cause of the interrupt and clear its source.
 */
class mtlis_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mtlis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmaisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmaisr_r>() const {return opsy::utility::clear_set<eth_dmaisr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaisr_r other) const -> eth_dmaisr_r { return static_cast<eth_dmaisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaisr_r> other) const -> opsy::utility::clear_set<eth_dmaisr_r> {return opsy::utility::clear_set<eth_dmaisr_r>(eth_dmaisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MAC Interrupt Status This bit indicates an interrupt event in the MAC. To reset this bit to 1'b0, the software must read the corresponding register in the MAC to get the exact cause of the interrupt and clear its source.
 */
class macis_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr macis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmaisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmaisr_r>() const {return opsy::utility::clear_set<eth_dmaisr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaisr_r other) const -> eth_dmaisr_r { return static_cast<eth_dmaisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaisr_r> other) const -> opsy::utility::clear_set<eth_dmaisr_r> {return opsy::utility::clear_set<eth_dmaisr_r>(eth_dmaisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dc0is() const -> dc0is_f {return dc0is_f((value_ & dc0is_f::mask) != 0);}
	[[nodiscard]] constexpr auto mtlis() const -> mtlis_f {return mtlis_f((value_ & mtlis_f::mask) != 0);}
	[[nodiscard]] constexpr auto macis() const -> macis_f {return macis_f((value_ & macis_f::mask) != 0);}

	constexpr eth_dmaisr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaisr_r other) const -> eth_dmaisr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaisr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Debug status register
 */
class eth_dmadsr_r {
public:

/**
 * AHB Master Write Channel When high, this bit indicates that the write channel of the AHB master FMSs are in non-idle state.
 */
class axwhsts_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr axwhsts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmadsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmadsr_r>() const {return opsy::utility::clear_set<eth_dmadsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmadsr_r other) const -> eth_dmadsr_r { return static_cast<eth_dmadsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmadsr_r> other) const -> opsy::utility::clear_set<eth_dmadsr_r> {return opsy::utility::clear_set<eth_dmadsr_r>(eth_dmadsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Channel Receive Process State This field indicates the Rx DMA FSM state for Channel: The MSB of this field always returns 0. This field does not generate an interrupt.
 */
class rps0_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rps0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmadsr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmadsr_r>() const {return opsy::utility::clear_set<eth_dmadsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmadsr_r other) const -> eth_dmadsr_r { return static_cast<eth_dmadsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmadsr_r> other) const -> opsy::utility::clear_set<eth_dmadsr_r> {return opsy::utility::clear_set<eth_dmadsr_r>(eth_dmadsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA Channel Transmit Process State This field indicates the Tx DMA FSM state for Channel: The MSB of this field always returns 0. This field does not generate an interrupt.
 */
class tps0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tps0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmadsr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmadsr_r>() const {return opsy::utility::clear_set<eth_dmadsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmadsr_r other) const -> eth_dmadsr_r { return static_cast<eth_dmadsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmadsr_r> other) const -> opsy::utility::clear_set<eth_dmadsr_r> {return opsy::utility::clear_set<eth_dmadsr_r>(eth_dmadsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto axwhsts() const -> axwhsts_f {return axwhsts_f((value_ & axwhsts_f::mask) != 0);}
	[[nodiscard]] constexpr auto rps0() const -> rps0_f {return rps0_f(static_cast<uint8_t>(value_ >> rps0_f::offset));}
	[[nodiscard]] constexpr auto tps0() const -> tps0_f {return tps0_f(static_cast<uint8_t>(value_ >> tps0_f::offset));}

	constexpr eth_dmadsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmadsr_r other) const -> eth_dmadsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmadsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel control register
 */
class eth_dmaccr_r {
public:

/**
 * Maximum Segment Size This field specifies the maximum segment size that should be used while segmenting the packet. This field is valid only if the TSE bit of Channel transmit control register (ETH_DMACTXCR) is set. The value programmed in this field must be more than the configured Data width in bytes. It is recommended to use a MSS value of 64 bytes or more.
 */
class mss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mss_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_dmaccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccr_r>() const {return opsy::utility::clear_set<eth_dmaccr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccr_r other) const -> eth_dmaccr_r { return static_cast<eth_dmaccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccr_r> other) const -> opsy::utility::clear_set<eth_dmaccr_r> {return opsy::utility::clear_set<eth_dmaccr_r>(eth_dmaccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * 8xPBL mode When this bit is set, the PBL value programmed in Bits[21:16] in Channel transmit control register (ETH_DMACTXCR) is multiplied eight times. Therefore, the DMA transfers the data in 8, 16, 32, 64, 128, and 256 beats depending on the PBL value.
 */
class pblx8_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pblx8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmaccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmaccr_r>() const {return opsy::utility::clear_set<eth_dmaccr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccr_r other) const -> eth_dmaccr_r { return static_cast<eth_dmaccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccr_r> other) const -> opsy::utility::clear_set<eth_dmaccr_r> {return opsy::utility::clear_set<eth_dmaccr_r>(eth_dmaccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Descriptor Skip Length This bit specifies the 32-bit word number to skip between two unchained descriptors. The address skipping starts from the end of the current descriptor to the start of the next descriptor. When the DSL value is equal to zero, the DMA takes the descriptor table as contiguous.
 */
class dsl_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dsl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmaccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccr_r>() const {return opsy::utility::clear_set<eth_dmaccr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccr_r other) const -> eth_dmaccr_r { return static_cast<eth_dmaccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccr_r> other) const -> opsy::utility::clear_set<eth_dmaccr_r> {return opsy::utility::clear_set<eth_dmaccr_r>(eth_dmaccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto mss() const -> mss_f {return mss_f(static_cast<uint16_t>(value_ >> mss_f::offset));}
	[[nodiscard]] constexpr auto pblx8() const -> pblx8_f {return pblx8_f((value_ & pblx8_f::mask) != 0);}
	[[nodiscard]] constexpr auto dsl() const -> dsl_f {return dsl_f(static_cast<uint8_t>(value_ >> dsl_f::offset));}

	constexpr eth_dmaccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaccr_r other) const -> eth_dmaccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel transmit control register
 */
class eth_dmactxcr_r {
public:

/**
 * Start or Stop Transmission Command When this bit is set, transmission is placed in the Running state. The DMA checks the Transmit list at the current position for a packet to be transmitted. The DMA tries to acquire descriptor from either of the following positions: The current position in the list: this is the base address of the Transmit list set by the ETH_DMACTXDLAR register. The position at which the transmission was previously stopped If the DMA does not own the current descriptor, the transmission enters the Suspended state and the TBU bit of the ETH_DMACSR is set. The Start Transmission command is effective only when the transmission is stopped. If the command is issued before setting the ETH_DMACTXDLAR register, the DMA behavior is unpredictable. When this bit is reset, the transmission process is placed in the Stopped state after completing the transmission of the current packet. The Next Descriptor position in the Transmit list is saved, and it becomes the current position when the transmission is restarted. To change the list address, you need to program ETH_DMACTXDLAR register with a new value when this bit is reset. The new value is considered when this bit is set again. The stop transmission command is effective only when the transmission of the current packet is complete or the transmission is in the Suspended state.
 */
class st_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr st_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmactxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmactxcr_r>() const {return opsy::utility::clear_set<eth_dmactxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxcr_r other) const -> eth_dmactxcr_r { return static_cast<eth_dmactxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxcr_r> other) const -> opsy::utility::clear_set<eth_dmactxcr_r> {return opsy::utility::clear_set<eth_dmactxcr_r>(eth_dmactxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Operate on Second Packet When this bit is set, it instructs the DMA to process the second packet of the Transmit data even before the status for the first packet is obtained.
 */
class osf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr osf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmactxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmactxcr_r>() const {return opsy::utility::clear_set<eth_dmactxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxcr_r other) const -> eth_dmactxcr_r { return static_cast<eth_dmactxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxcr_r> other) const -> opsy::utility::clear_set<eth_dmactxcr_r> {return opsy::utility::clear_set<eth_dmactxcr_r>(eth_dmactxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TCP Segmentation Enabled When this bit is set, the DMA performs the TCP segmentation for packets in Channel x. The TCP segmentation is done only for those packets for which the TSE bit (TDES0[19]) is set in the Tx Normal descriptor. When this bit is set, the TxPBL value must be greater than or equal to 4.
 */
class tse_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmactxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmactxcr_r>() const {return opsy::utility::clear_set<eth_dmactxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxcr_r other) const -> eth_dmactxcr_r { return static_cast<eth_dmactxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxcr_r> other) const -> opsy::utility::clear_set<eth_dmactxcr_r> {return opsy::utility::clear_set<eth_dmactxcr_r>(eth_dmactxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Programmable Burst Length These bits indicate the maximum number of beats to be transferred in one DMA data transfer. This is the maximum value that is used in a single block Read or Write. The DMA always attempts to burst as specified in PBL each time it starts a burst transfer on the application bus. You can program PBL with any of the following values: 1, 2, 4, 8, 16, or 32. Any other value results in undefined behavior. To transfer more than 32 beats, perform the following steps: Set the PBLx8 mode in ETH_DMACCR. Set the TXPBL[5:0]. Note: The maximum value of TXPBL must be less than or equal to half the Tx Queue size (TQS field of Tx queue operating mode Register (ETH_MTLTXQOMR)) in terms of beats. This is required so that the Tx Queue has space to store at least another Tx PBL worth of data while the MTL Tx Queue Controller is transferring data to MAC. The total locations in Tx Queue of size 2048 bytes is 512, TXPBL and 8xPBL needs to be programmed to less than or equal to 512/2.
 */
class txpbl_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txpbl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmactxcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmactxcr_r>() const {return opsy::utility::clear_set<eth_dmactxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxcr_r other) const -> eth_dmactxcr_r { return static_cast<eth_dmactxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxcr_r> other) const -> opsy::utility::clear_set<eth_dmactxcr_r> {return opsy::utility::clear_set<eth_dmactxcr_r>(eth_dmactxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto st() const -> st_f {return st_f((value_ & st_f::mask) != 0);}
	[[nodiscard]] constexpr auto osf() const -> osf_f {return osf_f((value_ & osf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tse() const -> tse_f {return tse_f((value_ & tse_f::mask) != 0);}
	[[nodiscard]] constexpr auto txpbl() const -> txpbl_f {return txpbl_f(static_cast<uint8_t>(value_ >> txpbl_f::offset));}

	constexpr eth_dmactxcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmactxcr_r other) const -> eth_dmactxcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmactxcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel receive control register
 */
class eth_dmacrxcr_r {
public:

/**
 * Start or Stop Receive When this bit is set, the DMA tries to acquire the descriptor from the Receive list and processes the incoming packets. The DMA tries to acquire descriptor from either of the following positions: The current position in the list: this is the address set by the Channel Rx descriptor list address register (ETH_DMACRXDLAR). The position at which the Rx process was previously stopped If the DMA does not own the current descriptor, the reception is suspended and the RBU bit of the ETH_DMACSR is set. The Start Receive command is effective only when the reception is stopped. If the command is issued before setting the Channel Rx descriptor list address register (ETH_DMACRXDLAR), the DMA behavior is unpredictable. When this bit is reset, the Rx DMA operation is stopped after the transfer of the current packet. The next descriptor position in the Receive list is saved, and it becomes the current position after the Rx process is restarted. The Stop Receive command is effective only when the Rx process is in the Running (waiting for Rx packet) or Suspended state.
 */
class sr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacrxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacrxcr_r>() const {return opsy::utility::clear_set<eth_dmacrxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxcr_r other) const -> eth_dmacrxcr_r { return static_cast<eth_dmacrxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxcr_r> other) const -> opsy::utility::clear_set<eth_dmacrxcr_r> {return opsy::utility::clear_set<eth_dmacrxcr_r>(eth_dmacrxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Buffer size This field indicates the size of the Rx buffers specified in bytes. The maximum buffer size is limited to 16Kbytes. Note: The buffer size must be a multiple of 4. This is required even if the value of buffer address pointer is not aligned to bus width. If the buffer size is not a multiple of 4, it may result into an undefined behavior. Note: The LSB bits (1:0) are ignored and the DMA internally takes the LSB bits as all-zero. Therefore, these LSB bits are read-only (RO).
 */
class rbsz_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rbsz_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_dmacrxcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxcr_r>() const {return opsy::utility::clear_set<eth_dmacrxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxcr_r other) const -> eth_dmacrxcr_r { return static_cast<eth_dmacrxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxcr_r> other) const -> opsy::utility::clear_set<eth_dmacrxcr_r> {return opsy::utility::clear_set<eth_dmacrxcr_r>(eth_dmacrxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Receive Programmable Burst Length These bits indicate the maximum number of beats to be transferred in one DMA data transfer. This is the maximum value that is used in a single block Read or Write. The DMA always attempts to burst as specified in PBL each time it starts a burst transfer on the application bus. You can program PBL with any of the following values: 1, 2, 4, 8, 16, or 32. Any other value results in undefined behavior. To transfer more than 32 beats, perform the following steps: Set the PBLx8 mode in the ETH_DMACCR. Set the RXPBL[5:0]. Note: The maximum value of RXPBL must be less than or equal to half the Rx Queue size (RQS field of Rx queue operating mode register (ETH_MTLRXQOMR)) in terms of beats. This is required so that the Rx Queue has space to store at least another Rx PBL worth of data while the MTL Rx Queue Controller is transferring data to MAC.The total locations in Rx Queue of size 2048 bytes is 512, RXPBL and 8xPBL needs to be programmed to less than or equal to 512/2.
 */
class rxpbl_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxpbl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacrxcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxcr_r>() const {return opsy::utility::clear_set<eth_dmacrxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxcr_r other) const -> eth_dmacrxcr_r { return static_cast<eth_dmacrxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxcr_r> other) const -> opsy::utility::clear_set<eth_dmacrxcr_r> {return opsy::utility::clear_set<eth_dmacrxcr_r>(eth_dmacrxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA Rx Channel Packet Flush When this bit is set to 1, the Ethernet peripheral will automatically flush the packet from the Rx queues destined to DMA Rx Channel when the DMA Rx Channel is stopped after a system bus error has occurred. When this bit remains set and the DMA is re-started by the software driver, the packets residing in the Rx Queues that were received when this RxDMA was stopped, are flushed out. The packets that are received by the MAC after the RxDMA is re-started are routed to the RxDMA. The flushing happens on the Read side of the Rx queue. When this bit is set to 0 the Ethernet peripheral does not flush the packet in the Rx queue destined to DMA Rx Channel after the DMA is stopped due to a system bus error. This might cause head-of-line blocking in the corresponding RxQueue. Note: The stopping of packet flow from a Rx DMA Channel to the application by setting RPF works only when there is one-to-one mapping of Rx Queue to Rx DMA channels. In Dynamic mapping mode, setting RPF bit in ETH_DMACRXCR register might flush packets from unintended Rx Queues which are destined to the stopped Rx DMA Channel.
 */
class rpf_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacrxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacrxcr_r>() const {return opsy::utility::clear_set<eth_dmacrxcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxcr_r other) const -> eth_dmacrxcr_r { return static_cast<eth_dmacrxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxcr_r> other) const -> opsy::utility::clear_set<eth_dmacrxcr_r> {return opsy::utility::clear_set<eth_dmacrxcr_r>(eth_dmacrxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sr() const -> sr_f {return sr_f((value_ & sr_f::mask) != 0);}
	[[nodiscard]] constexpr auto rbsz() const -> rbsz_f {return rbsz_f(static_cast<uint16_t>(value_ >> rbsz_f::offset));}
	[[nodiscard]] constexpr auto rxpbl() const -> rxpbl_f {return rxpbl_f(static_cast<uint8_t>(value_ >> rxpbl_f::offset));}
	[[nodiscard]] constexpr auto rpf() const -> rpf_f {return rpf_f((value_ & rpf_f::mask) != 0);}

	constexpr eth_dmacrxcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacrxcr_r other) const -> eth_dmacrxcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacrxcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Tx descriptor list address register
 */
class eth_dmactxdlar_r {
public:

/**
 * Start of Transmit List This field contains the base address of the first descriptor in the Transmit descriptor list. The DMA ignores the LSB bits (1:0) for 32-bit bus width and internally takes these bits as all-zero. Therefore, these LSB bits are read-only (RO).
 */
class tdesla_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdesla_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmactxdlar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmactxdlar_r>() const {return opsy::utility::clear_set<eth_dmactxdlar_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxdlar_r other) const -> eth_dmactxdlar_r { return static_cast<eth_dmactxdlar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxdlar_r> other) const -> opsy::utility::clear_set<eth_dmactxdlar_r> {return opsy::utility::clear_set<eth_dmactxdlar_r>(eth_dmactxdlar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tdesla() const -> tdesla_f {return tdesla_f(static_cast<uint32_t>(value_ >> tdesla_f::offset));}

	constexpr eth_dmactxdlar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmactxdlar_r other) const -> eth_dmactxdlar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmactxdlar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Rx descriptor list address register
 */
class eth_dmacrxdlar_r {
public:

/**
 * Start of Receive List This field contains the base address of the first descriptor in the Rx Descriptor list. The DMA ignores the LSB bits (1:0) for 32-bit bus width and internally takes these bits as all-zero. Therefore, these LSB bits are read-only (RO).
 */
class rdesla_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdesla_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmacrxdlar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxdlar_r>() const {return opsy::utility::clear_set<eth_dmacrxdlar_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxdlar_r other) const -> eth_dmacrxdlar_r { return static_cast<eth_dmacrxdlar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxdlar_r> other) const -> opsy::utility::clear_set<eth_dmacrxdlar_r> {return opsy::utility::clear_set<eth_dmacrxdlar_r>(eth_dmacrxdlar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rdesla() const -> rdesla_f {return rdesla_f(static_cast<uint32_t>(value_ >> rdesla_f::offset));}

	constexpr eth_dmacrxdlar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacrxdlar_r other) const -> eth_dmacrxdlar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacrxdlar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Tx descriptor tail pointer register
 */
class eth_dmactxdtpr_r {
public:

/**
 * Transmit Descriptor Tail Pointer This field contains the tail pointer for the Tx descriptor ring. The software writes the tail pointer to add more descriptors to the Tx channel. The hardware tries to transmit all packets referenced by the descriptors between the head and the tail pointer registers.
 */
class tdt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdt_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmactxdtpr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmactxdtpr_r>() const {return opsy::utility::clear_set<eth_dmactxdtpr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxdtpr_r other) const -> eth_dmactxdtpr_r { return static_cast<eth_dmactxdtpr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxdtpr_r> other) const -> opsy::utility::clear_set<eth_dmactxdtpr_r> {return opsy::utility::clear_set<eth_dmactxdtpr_r>(eth_dmactxdtpr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto tdt() const -> tdt_f {return tdt_f(static_cast<uint32_t>(value_ >> tdt_f::offset));}

	constexpr eth_dmactxdtpr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmactxdtpr_r other) const -> eth_dmactxdtpr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmactxdtpr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Rx descriptor tail pointer register
 */
class eth_dmacrxdtpr_r {
public:

/**
 * Receive Descriptor Tail Pointer This field contains the tail pointer for the Rx descriptor ring. The software writes the tail pointer to add more descriptors to the Rx channel. The hardware tries to write all received packets to the descriptors referenced between the head and the tail pointer registers.
 */
class rdt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdt_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmacrxdtpr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxdtpr_r>() const {return opsy::utility::clear_set<eth_dmacrxdtpr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxdtpr_r other) const -> eth_dmacrxdtpr_r { return static_cast<eth_dmacrxdtpr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxdtpr_r> other) const -> opsy::utility::clear_set<eth_dmacrxdtpr_r> {return opsy::utility::clear_set<eth_dmacrxdtpr_r>(eth_dmacrxdtpr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto rdt() const -> rdt_f {return rdt_f(static_cast<uint32_t>(value_ >> rdt_f::offset));}

	constexpr eth_dmacrxdtpr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacrxdtpr_r other) const -> eth_dmacrxdtpr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacrxdtpr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Tx descriptor ring length register
 */
class eth_dmactxrlr_r {
public:

/**
 * Transmit Descriptor Ring Length This field sets the maximum number of Tx descriptors in the circular descriptor ring. The maximum number of descriptors is limited to 1K descriptors. It is recommended to put a minimum ring descriptor length of 4. For example, you can program any value up to 0x3FF in this field. This field is 10 bits wide, if you program 0x3FF, you can have 1024 descriptors. If you want to have 10 descriptors, program it to a value of 0x9.
 */
class tdrl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdrl_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_dmactxrlr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmactxrlr_r>() const {return opsy::utility::clear_set<eth_dmactxrlr_r>(mask, *this);}
	constexpr auto operator|(eth_dmactxrlr_r other) const -> eth_dmactxrlr_r { return static_cast<eth_dmactxrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmactxrlr_r> other) const -> opsy::utility::clear_set<eth_dmactxrlr_r> {return opsy::utility::clear_set<eth_dmactxrlr_r>(eth_dmactxrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tdrl() const -> tdrl_f {return tdrl_f(static_cast<uint16_t>(value_ >> tdrl_f::offset));}

	constexpr eth_dmactxrlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmactxrlr_r other) const -> eth_dmactxrlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmactxrlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Rx descriptor ring length register
 */
class eth_dmacrxrlr_r {
public:

/**
 * Receive Descriptor Ring Length This register sets the maximum number of Rx descriptors in the circular descriptor ring. The maximum number of descriptors is limited to 1K descriptors. For example, you can program any value up to 0x3FF in this field. This field is 10-bit wide. If you program 0x3FF, you can have 1024 descriptors. If you want to have 10 descriptors, program it to a value of 0x9.
 */
class rdrl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdrl_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_dmacrxrlr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxrlr_r>() const {return opsy::utility::clear_set<eth_dmacrxrlr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxrlr_r other) const -> eth_dmacrxrlr_r { return static_cast<eth_dmacrxrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxrlr_r> other) const -> opsy::utility::clear_set<eth_dmacrxrlr_r> {return opsy::utility::clear_set<eth_dmacrxrlr_r>(eth_dmacrxrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Alternate Receive Buffer Size Indicates size in bytes for Buffer 1 when ARBS[7:0] is programmed to a non-zero value. When ARBS[7:0]=0, Rx Buffer1 and Rx Buffer2 sizes are based on RBSZ[13:0] field of Channel receive control register (ETH_DMACRXCR).
 */
class arbs_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr arbs_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacrxrlr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxrlr_r>() const {return opsy::utility::clear_set<eth_dmacrxrlr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxrlr_r other) const -> eth_dmacrxrlr_r { return static_cast<eth_dmacrxrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxrlr_r> other) const -> opsy::utility::clear_set<eth_dmacrxrlr_r> {return opsy::utility::clear_set<eth_dmacrxrlr_r>(eth_dmacrxrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rdrl() const -> rdrl_f {return rdrl_f(static_cast<uint16_t>(value_ >> rdrl_f::offset));}
	[[nodiscard]] constexpr auto arbs() const -> arbs_f {return arbs_f(static_cast<uint8_t>(value_ >> arbs_f::offset));}

	constexpr eth_dmacrxrlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacrxrlr_r other) const -> eth_dmacrxrlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacrxrlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel interrupt enable register
 */
class eth_dmacier_r {
public:

/**
 * Transmit Interrupt Enable When this bit is set along with the NIE bit, the Transmit Interrupt is enabled. When this bit is reset, the Transmit Interrupt is disabled.
 */
class tie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Stopped Enable When this bit is set along with the AIE bit, the Transmission Stopped interrupt is enabled. When this bit is reset, the Transmission Stopped interrupt is disabled.
 */
class txse_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Buffer Unavailable Enable When this bit is set along with the NIE bit, the Transmit Buffer Unavailable interrupt is enabled. When this bit is reset, the Transmit Buffer Unavailable interrupt is disabled.
 */
class tbue_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tbue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Interrupt Enable When this bit is set along with the NIE bit, the Receive Interrupt is enabled. When this bit is reset, the Receive Interrupt is disabled.
 */
class rie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Buffer Unavailable Enable When this bit is set along with the AIE bit, the Receive Buffer Unavailable interrupt is enabled. When this bit is reset, the Receive Buffer Unavailable interrupt is disabled.
 */
class rbue_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rbue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Stopped Enable When this bit is set along with the AIE bit, the Receive Stopped Interrupt is enabled. When this bit is reset, the Receive Stopped interrupt is disabled.
 */
class rse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Watchdog Timeout Enable When this bit is set along with the AIE bit, the Receive Watchdog Timeout interrupt is enabled. When this bit is reset, the Receive Watchdog Timeout interrupt is disabled.
 */
class rwte_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwte_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Early Transmit Interrupt Enable When this bit is set along with the AIE bit, the Early Transmit interrupt is enabled. When this bit is reset, the Early Transmit interrupt is disabled.
 */
class etie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr etie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Early Receive Interrupt Enable When this bit is set along with the NIE bit, the Early Receive interrupt is enabled. When this bit is reset, the Early Receive interrupt is disabled.
 */
class erie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr erie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fatal Bus Error Enable When this bit is set along with the AIE bit, the Fatal Bus error interrupt is enabled. When this bit is reset, the Fatal Bus Error error interrupt is disabled.
 */
class fbee_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fbee_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Context Descriptor Error Enable When this bit is set along with the AIE bit, the Context Descriptor error interrupt is enabled. When this bit is reset, the Context Descriptor error interrupt is disabled.
 */
class cdee_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cdee_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Abnormal Interrupt Summary Enable When this bit is set, the abnormal interrupt summary is enabled. This bit enables the following interrupts in the Channel status register (ETH_DMACSR): Bit 1: Transmit Process Stopped Bit 7: Rx Buffer Unavailable Bit 8: Receive Process Stopped Bit 9: Receive Watchdog Timeout Bit 10: Early Transmit Interrupt Bit 12: Fatal Bus Error When this bit is reset, the abnormal interrupt summary is disabled.
 */
class aie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr aie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Normal Interrupt Summary Enable When this bit is set, the normal interrupt summary is enabled. This bit enables the following interrupts in the Channel status register (ETH_DMACSR): Bit 0: Transmit Interrupt Bit 2: Transmit Buffer Unavailable Bit 6: Receive Interrupt Bit 11: Early Receive Interrupt When this bit is reset, the normal interrupt summary is disabled.
 */
class nie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr nie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacier_r>() const {return opsy::utility::clear_set<eth_dmacier_r>(mask, *this);}
	constexpr auto operator|(eth_dmacier_r other) const -> eth_dmacier_r { return static_cast<eth_dmacier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacier_r> other) const -> opsy::utility::clear_set<eth_dmacier_r> {return opsy::utility::clear_set<eth_dmacier_r>(eth_dmacier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tie() const -> tie_f {return tie_f((value_ & tie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txse() const -> txse_f {return txse_f((value_ & txse_f::mask) != 0);}
	[[nodiscard]] constexpr auto tbue() const -> tbue_f {return tbue_f((value_ & tbue_f::mask) != 0);}
	[[nodiscard]] constexpr auto rie() const -> rie_f {return rie_f((value_ & rie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rbue() const -> rbue_f {return rbue_f((value_ & rbue_f::mask) != 0);}
	[[nodiscard]] constexpr auto rse() const -> rse_f {return rse_f((value_ & rse_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwte() const -> rwte_f {return rwte_f((value_ & rwte_f::mask) != 0);}
	[[nodiscard]] constexpr auto etie() const -> etie_f {return etie_f((value_ & etie_f::mask) != 0);}
	[[nodiscard]] constexpr auto erie() const -> erie_f {return erie_f((value_ & erie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fbee() const -> fbee_f {return fbee_f((value_ & fbee_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdee() const -> cdee_f {return cdee_f((value_ & cdee_f::mask) != 0);}
	[[nodiscard]] constexpr auto aie() const -> aie_f {return aie_f((value_ & aie_f::mask) != 0);}
	[[nodiscard]] constexpr auto nie() const -> nie_f {return nie_f((value_ & nie_f::mask) != 0);}

	constexpr eth_dmacier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacier_r other) const -> eth_dmacier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel Rx interrupt watchdog timer register
 */
class eth_dmacrxiwtr_r {
public:

/**
 * Receive Interrupt Watchdog Timer Count This field indicates the number of system clock cycles, multiplied by factor indicated in RWTU field, for which the watchdog timer is set. The watchdog timer is triggered with the programmed value after the Rx DMA completes the transfer of a packet for which the RI bit is not set in the ETH_DMACSR, because of the setting of Interrupt Enable bit in the corresponding descriptor RDES3[30]. When the watchdog timer runs out, the RI bit is set and the timer is stopped. The watchdog timer is reset when the RI bit is set high because of automatic setting of RI as per the Interrupt Enable bit RDES3[30] of any received packet.
 */
class rwt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rwt_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacrxiwtr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxiwtr_r>() const {return opsy::utility::clear_set<eth_dmacrxiwtr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxiwtr_r other) const -> eth_dmacrxiwtr_r { return static_cast<eth_dmacrxiwtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxiwtr_r> other) const -> opsy::utility::clear_set<eth_dmacrxiwtr_r> {return opsy::utility::clear_set<eth_dmacrxiwtr_r>(eth_dmacrxiwtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Receive Interrupt Watchdog Timer Count Units This field indicates the number of system clock cycles corresponding to one unit in RWT[7:0] field. For example, when RWT[7:0]=2 and RWTU[1:0]=1, the watchdog timer is set for 2*512=1024 system clock cycles.
 */
class rwtu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rwtu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacrxiwtr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacrxiwtr_r>() const {return opsy::utility::clear_set<eth_dmacrxiwtr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacrxiwtr_r other) const -> eth_dmacrxiwtr_r { return static_cast<eth_dmacrxiwtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacrxiwtr_r> other) const -> opsy::utility::clear_set<eth_dmacrxiwtr_r> {return opsy::utility::clear_set<eth_dmacrxiwtr_r>(eth_dmacrxiwtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rwt() const -> rwt_f {return rwt_f(static_cast<uint8_t>(value_ >> rwt_f::offset));}
	[[nodiscard]] constexpr auto rwtu() const -> rwtu_f {return rwtu_f(static_cast<uint8_t>(value_ >> rwtu_f::offset));}

	constexpr eth_dmacrxiwtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacrxiwtr_r other) const -> eth_dmacrxiwtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacrxiwtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel current application transmit descriptor register
 */
class eth_dmaccatxdr_r {
public:

/**
 * Application Transmit Descriptor Address Pointer The DMA updates this pointer during Tx operation. This pointer is cleared on reset.
 */
class curtdesaptr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr curtdesaptr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmaccatxdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccatxdr_r>() const {return opsy::utility::clear_set<eth_dmaccatxdr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccatxdr_r other) const -> eth_dmaccatxdr_r { return static_cast<eth_dmaccatxdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccatxdr_r> other) const -> opsy::utility::clear_set<eth_dmaccatxdr_r> {return opsy::utility::clear_set<eth_dmaccatxdr_r>(eth_dmaccatxdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto curtdesaptr() const -> curtdesaptr_f {return curtdesaptr_f(static_cast<uint32_t>(value_ >> curtdesaptr_f::offset));}

	constexpr eth_dmaccatxdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaccatxdr_r other) const -> eth_dmaccatxdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaccatxdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel current application receive descriptor register
 */
class eth_dmaccarxdr_r {
public:

/**
 * Application Receive Descriptor Address Pointer The DMA updates this pointer during Rx operation. This pointer is cleared on reset.
 */
class currdesaptr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr currdesaptr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmaccarxdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccarxdr_r>() const {return opsy::utility::clear_set<eth_dmaccarxdr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccarxdr_r other) const -> eth_dmaccarxdr_r { return static_cast<eth_dmaccarxdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccarxdr_r> other) const -> opsy::utility::clear_set<eth_dmaccarxdr_r> {return opsy::utility::clear_set<eth_dmaccarxdr_r>(eth_dmaccarxdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto currdesaptr() const -> currdesaptr_f {return currdesaptr_f(static_cast<uint32_t>(value_ >> currdesaptr_f::offset));}

	constexpr eth_dmaccarxdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaccarxdr_r other) const -> eth_dmaccarxdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaccarxdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel current application transmit buffer register
 */
class eth_dmaccatxbr_r {
public:

/**
 * Application Transmit Buffer Address Pointer The DMA updates this pointer during Tx operation. This pointer is cleared on reset.
 */
class curtbufaptr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr curtbufaptr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmaccatxbr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccatxbr_r>() const {return opsy::utility::clear_set<eth_dmaccatxbr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccatxbr_r other) const -> eth_dmaccatxbr_r { return static_cast<eth_dmaccatxbr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccatxbr_r> other) const -> opsy::utility::clear_set<eth_dmaccatxbr_r> {return opsy::utility::clear_set<eth_dmaccatxbr_r>(eth_dmaccatxbr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto curtbufaptr() const -> curtbufaptr_f {return curtbufaptr_f(static_cast<uint32_t>(value_ >> curtbufaptr_f::offset));}

	constexpr eth_dmaccatxbr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaccatxbr_r other) const -> eth_dmaccatxbr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaccatxbr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel current application receive buffer register
 */
class eth_dmaccarxbr_r {
public:

/**
 * Application Receive Buffer Address Pointer The DMA updates this pointer during Rx operation. This pointer is cleared on reset.
 */
class currbufaptr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr currbufaptr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator eth_dmaccarxbr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmaccarxbr_r>() const {return opsy::utility::clear_set<eth_dmaccarxbr_r>(mask, *this);}
	constexpr auto operator|(eth_dmaccarxbr_r other) const -> eth_dmaccarxbr_r { return static_cast<eth_dmaccarxbr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmaccarxbr_r> other) const -> opsy::utility::clear_set<eth_dmaccarxbr_r> {return opsy::utility::clear_set<eth_dmaccarxbr_r>(eth_dmaccarxbr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto currbufaptr() const -> currbufaptr_f {return currbufaptr_f(static_cast<uint32_t>(value_ >> currbufaptr_f::offset));}

	constexpr eth_dmaccarxbr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmaccarxbr_r other) const -> eth_dmaccarxbr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmaccarxbr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel status register
 */
class eth_dmacsr_r {
public:

/**
 * Transmit Interrupt This bit indicates that the packet transmission is complete. When transmission is complete, Bit 31 of TDES3 is reset in the last descriptor, and the specific packet status information is updated in the descriptor.
 */
class ti_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ti_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Process Stopped This bit is set when the transmission is stopped.
 */
class tps_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit Buffer Unavailable This bit indicates that the application owns the next descriptor in the Transmit list, and the DMA cannot acquire it. Transmission is suspended. The TPSi field of the Debug status register (ETH_DMADSR) register explains the Transmit Process state transitions. To resume processing the Transmit descriptors, the application should do the following: 1. Change the ownership of the descriptor by setting Bit 31 of TDES3. 2. Issue a Transmit Poll Demand command. For ring mode, the application should advance the Transmit Descriptor Tail Pointer register of a channel.
 */
class tbu_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tbu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Interrupt This bit indicates that the packet reception is complete. When packet reception is complete, Bit 31 of RDES1 is reset in the last descriptor, and the specific packet status information is updated in the descriptor. The reception remains in the Running state.
 */
class ri_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ri_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Buffer Unavailable This bit indicates that the application owns the next descriptor in the Receive list, and the DMA cannot acquire it. The Rx process is suspended. To resume processing Rx descriptors, the application should change the ownership of the descriptor and issue a Receive Poll Demand command. If this command is not issued, the Rx process resumes when the next recognized incoming packet is received. In ring mode, the application should advance the Receive Descriptor Tail Pointer register of a channel. This bit is set only when the DMA owns the previous Rx descriptor.
 */
class rbu_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rbu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Process Stopped This bit is asserted when the Rx process enters the Stopped state.
 */
class rps_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive Watchdog Timeout This bit is asserted when a packet with length greater than 2,048 bytes (10,240 bytes when Jumbo Packet mode is enabled) is received.
 */
class rwt_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rwt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Early Transmit Interrupt This bit indicates that the packet to be transmitted is fully transferred to the MTL Tx FIFO.
 */
class eti_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eti_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Early Receive Interrupt This bit indicates that the DMA filled the first data buffer of the packet.The RI bit of this register automatically clears this bit.
 */
class eri_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr eri_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fatal Bus Error This bit indicates that a bus error occurred (as described in the EB field). When this bit is set, the corresponding DMA channel engine disables all bus accesses.
 */
class fbe_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fbe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Context Descriptor Error This bit indicates that the DMA Tx/Rx engine received a descriptor error, which indicates invalid context in the middle of packet flow (intermediate descriptor) or all one's descriptor in Tx case and on Rx side it indicates DMA has read a descriptor with either of the buffer address as ones which is considered to be invalid.
 */
class cde_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cde_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Abnormal Interrupt Summary Abnormal Interrupt Summary bit value is the logical OR of the following when the corresponding interrupt bits are enabled in the ETH_DMACIER register: Bit 1: Transmit Process Stopped Bit 7: Receive Buffer Unavailable Bit 8: Receive Process Stopped Bit 10: Early Transmit Interrupt Bit 12: Fatal Bus Error Bit 13: Context Descriptor Error Only unmasked bits affect the Abnormal Interrupt Summary bit. This is a sticky bit. You must clear this bit (by writing 1 to this bit) each time a corresponding bit, which causes AIS to be set, is cleared.
 */
class ais_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ais_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Normal Interrupt Summary Normal Interrupt Summary bit value is the logical OR of the following bits when the corresponding interrupt bits are enabled in the ETH_DMACIER register: Bit 0: Transmit Interrupt Bit 2: Transmit Buffer Unavailable Bit 6: Receive Interrupt Bit 11: Early Receive Interrupt Only unmasked bits (interrupts for which interrupt enable is set in ETH_DMACIER register) affect the Normal Interrupt Summary bit. This is a sticky bit. You must clear this bit (by writing 1 to this bit) each time a corresponding bit which causes NIS to be set is cleared.
 */
class nis_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr nis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tx DMA Error Bits This field indicates the type of error that caused a Bus Error. For example, error response on the AHB interface. Bit[2]: Error during data transfer by Tx DMA when 1, no Error during data transfer by Tx DMA when 0 Bit[1]: Error during descriptor access when 1, Error during data buffer access when 0 Bit[0]: Error during read transfer when 1, Error during write transfer when 0 This field is valid only when the FBE bit is set. This field does not generate an interrupt.
 */
class teb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr teb_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Rx DMA Error Bits This field indicates the type of error that caused a Bus Error. For example, error response on the AHB interface. Bit [2]: Error during data transfer by Rx DMA when 1, no Error during data transfer by Rx DMA when 0. Bit[1]: Error during descriptor access when 1, Error during data buffer access when 0 Bit[0]: Error during read transfer when 1, Error during write transfer when 0 This field is valid only when the FBE bit is set. This field does not generate an interrupt.
 */
class reb_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr reb_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator eth_dmacsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacsr_r>() const {return opsy::utility::clear_set<eth_dmacsr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacsr_r other) const -> eth_dmacsr_r { return static_cast<eth_dmacsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacsr_r> other) const -> opsy::utility::clear_set<eth_dmacsr_r> {return opsy::utility::clear_set<eth_dmacsr_r>(eth_dmacsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ti() const -> ti_f {return ti_f((value_ & ti_f::mask) != 0);}
	[[nodiscard]] constexpr auto tps() const -> tps_f {return tps_f((value_ & tps_f::mask) != 0);}
	[[nodiscard]] constexpr auto tbu() const -> tbu_f {return tbu_f((value_ & tbu_f::mask) != 0);}
	[[nodiscard]] constexpr auto ri() const -> ri_f {return ri_f((value_ & ri_f::mask) != 0);}
	[[nodiscard]] constexpr auto rbu() const -> rbu_f {return rbu_f((value_ & rbu_f::mask) != 0);}
	[[nodiscard]] constexpr auto rps() const -> rps_f {return rps_f((value_ & rps_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwt() const -> rwt_f {return rwt_f((value_ & rwt_f::mask) != 0);}
	[[nodiscard]] constexpr auto eti() const -> eti_f {return eti_f((value_ & eti_f::mask) != 0);}
	[[nodiscard]] constexpr auto eri() const -> eri_f {return eri_f((value_ & eri_f::mask) != 0);}
	[[nodiscard]] constexpr auto fbe() const -> fbe_f {return fbe_f((value_ & fbe_f::mask) != 0);}
	[[nodiscard]] constexpr auto cde() const -> cde_f {return cde_f((value_ & cde_f::mask) != 0);}
	[[nodiscard]] constexpr auto ais() const -> ais_f {return ais_f((value_ & ais_f::mask) != 0);}
	[[nodiscard]] constexpr auto nis() const -> nis_f {return nis_f((value_ & nis_f::mask) != 0);}
	[[nodiscard]] constexpr auto teb() const -> teb_f {return teb_f(static_cast<uint8_t>(value_ >> teb_f::offset));}
	[[nodiscard]] constexpr auto reb() const -> reb_f {return reb_f(static_cast<uint8_t>(value_ >> reb_f::offset));}

	constexpr eth_dmacsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacsr_r other) const -> eth_dmacsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel missed frame count register
 */
class eth_dmacmfcr_r {
public:

/**
 * Dropped Packet Counters This counter indicates the number of packet counters that are dropped by the DMA either because of bus error or because of programing RPF field in Channel receive control register (ETH_DMACRXCR). The counter gets cleared when this register is read.
 */
class mfc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mfc_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator eth_dmacmfcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<eth_dmacmfcr_r>() const {return opsy::utility::clear_set<eth_dmacmfcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacmfcr_r other) const -> eth_dmacmfcr_r { return static_cast<eth_dmacmfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacmfcr_r> other) const -> opsy::utility::clear_set<eth_dmacmfcr_r> {return opsy::utility::clear_set<eth_dmacmfcr_r>(eth_dmacmfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Overflow status of the MFC Counter When this bit is set then the MFC counter does not get incremented further. The bit gets cleared when this register is read.
 */
class mfco_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mfco_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator eth_dmacmfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<eth_dmacmfcr_r>() const {return opsy::utility::clear_set<eth_dmacmfcr_r>(mask, *this);}
	constexpr auto operator|(eth_dmacmfcr_r other) const -> eth_dmacmfcr_r { return static_cast<eth_dmacmfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<eth_dmacmfcr_r> other) const -> opsy::utility::clear_set<eth_dmacmfcr_r> {return opsy::utility::clear_set<eth_dmacmfcr_r>(eth_dmacmfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mfc() const -> mfc_f {return mfc_f(static_cast<uint16_t>(value_ >> mfc_f::offset));}
	[[nodiscard]] constexpr auto mfco() const -> mfco_f {return mfco_f((value_ & mfco_f::mask) != 0);}

	constexpr eth_dmacmfcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(eth_dmacmfcr_r other) const -> eth_dmacmfcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> eth_dmacmfcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,eth_maccr_r> eth_maccr;
	opsy::utility::memory<uint32_t,eth_macecr_r> eth_macecr;
	opsy::utility::memory<uint32_t,eth_macpfr_r> eth_macpfr;
	opsy::utility::memory<uint32_t,eth_macwtr_r> eth_macwtr;
	opsy::utility::memory<uint32_t,eth_macht0r_r> eth_macht0r;
	opsy::utility::memory<uint32_t,eth_macht1r_r> eth_macht1r;
	opsy::utility::padding<56> _p0;
	opsy::utility::memory<uint32_t,eth_macvtr_r> eth_macvtr;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,eth_macvhtr_r> eth_macvhtr;
	opsy::utility::padding<4> _p2;
	opsy::utility::memory<uint32_t,eth_macvir_r> eth_macvir;
	opsy::utility::memory<uint32_t,eth_macvir_r> eth_macivir;
	opsy::utility::padding<8> _p3;
	opsy::utility::memory<uint32_t,eth_macqtxfcr_r> eth_macqtxfcr;
	opsy::utility::padding<28> _p4;
	opsy::utility::memory<uint32_t,eth_macrxfcr_r> eth_macrxfcr;
	opsy::utility::padding<28> _p5;
	opsy::utility::memory<uint32_t,eth_macisr_r> eth_macisr;
	opsy::utility::memory<uint32_t,eth_macier_r> eth_macier;
	opsy::utility::memory<uint32_t,eth_macrxtxsr_r> eth_macrxtxsr;
	opsy::utility::padding<4> _p6;
	opsy::utility::memory<uint32_t,eth_macpcsr_r> eth_macpcsr;
	opsy::utility::memory<uint32_t,eth_macrwkpfr_r> eth_macrwkpfr;
	opsy::utility::padding<8> _p7;
	opsy::utility::memory<uint32_t,eth_maclcsr_r> eth_maclcsr;
	opsy::utility::memory<uint32_t,eth_macltcr_r> eth_macltcr;
	opsy::utility::memory<uint32_t,eth_macletr_r> eth_macletr;
	opsy::utility::memory<uint32_t,eth_mac1ustcr_r> eth_mac1ustcr;
	opsy::utility::padding<48> _p8;
	opsy::utility::memory<uint32_t,eth_macvr_r> eth_macvr;
	opsy::utility::memory<uint32_t,eth_macdr_r> eth_macdr;
	opsy::utility::padding<4> _p9;
	opsy::utility::memory<uint32_t,eth_machwf0r_r> eth_machwf0r;
	opsy::utility::memory<uint32_t,eth_machwf1r_r> eth_machwf1r;
	opsy::utility::memory<uint32_t,eth_machwf2r_r> eth_machwf2r;
	opsy::utility::memory<uint32_t,eth_machwf3r_r> eth_machwf3r;
	opsy::utility::padding<212> _p10;
	opsy::utility::memory<uint32_t,eth_macmdioar_r> eth_macmdioar;
	opsy::utility::memory<uint32_t,eth_macmdiodr_r> eth_macmdiodr;
	opsy::utility::padding<8> _p11;
	opsy::utility::memory<uint32_t,eth_macarpar_r> eth_macarpar;
	opsy::utility::padding<28> _p12;
	opsy::utility::memory<uint32_t,eth_maccsrswcr_r> eth_maccsrswcr;
	opsy::utility::padding<204> _p13;
	opsy::utility::memory<uint32_t,eth_maca0hr_r> eth_maca0hr;
	opsy::utility::memory<uint32_t,eth_macaxlr_r> eth_maca0lr;
	opsy::utility::memory<uint32_t,eth_macaxhr_r> eth_maca1hr;
	opsy::utility::memory<uint32_t,eth_macaxlr_r> eth_maca1lr;
	opsy::utility::memory<uint32_t,eth_macaxhr_r> eth_maca2hr;
	opsy::utility::memory<uint32_t,eth_macaxlr_r> eth_maca2lr;
	opsy::utility::memory<uint32_t,eth_macaxhr_r> eth_maca3hr;
	opsy::utility::memory<uint32_t,eth_macaxlr_r> eth_maca3lr;
	opsy::utility::padding<992> _p14;
	opsy::utility::memory<uint32_t,eth_mmc_control_r> eth_mmc_control;
	opsy::utility::memory<uint32_t,eth_mmc_rx_interrupt_r> eth_mmc_rx_interrupt;
	opsy::utility::memory<uint32_t,eth_mmc_tx_interrupt_r> eth_mmc_tx_interrupt;
	opsy::utility::memory<uint32_t,eth_mmc_rx_interrupt_mask_r> eth_mmc_rx_interrupt_mask;
	opsy::utility::memory<uint32_t,eth_mmc_tx_interrupt_mask_r> eth_mmc_tx_interrupt_mask;
	opsy::utility::padding<56> _p15;
	opsy::utility::memory<uint32_t,eth_tx_single_collision_good_packets_r> eth_tx_single_collision_good_packets;
	opsy::utility::memory<uint32_t,eth_tx_multiple_collision_good_packets_r> eth_tx_multiple_collision_good_packets;
	opsy::utility::padding<20> _p16;
	opsy::utility::memory<uint32_t,eth_tx_packet_count_good_r> eth_tx_packet_count_good;
	opsy::utility::padding<40> _p17;
	opsy::utility::memory<uint32_t,eth_rx_crc_error_packets_r> eth_rx_crc_error_packets;
	opsy::utility::memory<uint32_t,eth_rx_alignment_error_packets_r> eth_rx_alignment_error_packets;
	opsy::utility::padding<40> _p18;
	opsy::utility::memory<uint32_t,eth_rx_unicast_packets_good_r> eth_rx_unicast_packets_good;
	opsy::utility::padding<36> _p19;
	opsy::utility::memory<uint32_t,eth_tx_lpi_usec_cntr_r> eth_tx_lpi_usec_cntr;
	opsy::utility::memory<uint32_t,eth_tx_lpi_tran_cntr_r> eth_tx_lpi_tran_cntr;
	opsy::utility::memory<uint32_t,eth_rx_lpi_usec_cntr_r> eth_rx_lpi_usec_cntr;
	opsy::utility::memory<uint32_t,eth_rx_lpi_tran_cntr_r> eth_rx_lpi_tran_cntr;
	opsy::utility::padding<260> _p20;
	opsy::utility::memory<uint32_t,eth_macl3l4c0r_r> eth_macl3l4c0r;
	opsy::utility::memory<uint32_t,eth_macl4a0r_r> eth_macl4a0r;
	opsy::utility::padding<8> _p21;
	opsy::utility::memory<uint32_t,eth_macl3a00r_r> eth_macl3a00r;
	opsy::utility::memory<uint32_t,eth_macl3a10r_r> eth_macl3a10r;
	opsy::utility::memory<uint32_t,eth_macl3a20r_r> eth_macl3a20r;
	opsy::utility::memory<uint32_t,eth_macl3a30r_r> eth_macl3a30r;
	opsy::utility::padding<16> _p22;
	opsy::utility::memory<uint32_t,eth_macl3l4c1r_r> eth_macl3l4c1r;
	opsy::utility::memory<uint32_t,eth_macl4a1r_r> eth_macl4a1r;
	opsy::utility::padding<8> _p23;
	opsy::utility::memory<uint32_t,eth_macl3a01r_r> eth_macl3a01r;
	opsy::utility::memory<uint32_t,eth_macl3a11r_r> eth_macl3a11r;
	opsy::utility::memory<uint32_t,eth_macl3a21r_r> eth_macl3a21r;
	opsy::utility::memory<uint32_t,eth_macl3a31r_r> eth_macl3a31r;
	opsy::utility::padding<432> _p24;
	opsy::utility::memory<uint32_t,eth_mactscr_r> eth_mactscr;
	opsy::utility::memory<uint32_t,eth_macssir_r> eth_macssir;
	opsy::utility::memory<uint32_t,eth_macstsr_r> eth_macstsr;
	opsy::utility::memory<uint32_t,eth_macstnr_r> eth_macstnr;
	opsy::utility::memory<uint32_t,eth_macstsur_r> eth_macstsur;
	opsy::utility::memory<uint32_t,eth_macstnur_r> eth_macstnur;
	opsy::utility::memory<uint32_t,eth_mactsar_r> eth_mactsar;
	opsy::utility::padding<4> _p25;
	opsy::utility::memory<uint32_t,eth_mactssr_r> eth_mactssr;
	opsy::utility::padding<12> _p26;
	opsy::utility::memory<uint32_t,eth_mactxtssnr_r> eth_mactxtssnr;
	opsy::utility::memory<uint32_t,eth_mactxtsssr_r> eth_mactxtsssr;
	opsy::utility::padding<8> _p27;
	opsy::utility::memory<uint32_t,eth_macacr_r> eth_macacr;
	opsy::utility::padding<4> _p28;
	opsy::utility::memory<uint32_t,eth_macatsnr_r> eth_macatsnr;
	opsy::utility::memory<uint32_t,eth_macatssr_r> eth_macatssr;
	opsy::utility::memory<uint32_t,eth_mactsiacr_r> eth_mactsiacr;
	opsy::utility::memory<uint32_t,eth_mactseacr_r> eth_mactseacr;
	opsy::utility::memory<uint32_t,eth_mactsicnr_r> eth_mactsicnr;
	opsy::utility::memory<uint32_t,eth_mactsecnr_r> eth_mactsecnr;
	opsy::utility::padding<16> _p29;
	union {
		opsy::utility::memory<uint32_t,eth_macppscr_r> eth_macppscr;
		opsy::utility::memory<uint32_t,eth_macppscr_alternate_r> eth_macppscr_alternate;
	};
	opsy::utility::padding<12> _p30;
	opsy::utility::memory<uint32_t,eth_macppsttsr_r> eth_macppsttsr;
	opsy::utility::memory<uint32_t,eth_macppsttnr_r> eth_macppsttnr;
	opsy::utility::memory<uint32_t,eth_macppsir_r> eth_macppsir;
	opsy::utility::memory<uint32_t,eth_macppswr_r> eth_macppswr;
	opsy::utility::padding<48> _p31;
	opsy::utility::memory<uint32_t,eth_macpocr_r> eth_macpocr;
	opsy::utility::memory<uint32_t,eth_macspi0r_r> eth_macspi0r;
	opsy::utility::memory<uint32_t,eth_macspi1r_r> eth_macspi1r;
	opsy::utility::memory<uint32_t,eth_macspi2r_r> eth_macspi2r;
	opsy::utility::memory<uint32_t,eth_maclmir_r> eth_maclmir;
	opsy::utility::padding<44> _p32;
	opsy::utility::memory<uint32_t,eth_mtlomr_r> eth_mtlomr;
	opsy::utility::padding<28> _p33;
	opsy::utility::memory<uint32_t,eth_mtlisr_r> eth_mtlisr;
	opsy::utility::padding<220> _p34;
	opsy::utility::memory<uint32_t,eth_mtltxqomr_r> eth_mtltxqomr;
	opsy::utility::memory<uint32_t,eth_mtltxqur_r> eth_mtltxqur;
	opsy::utility::memory<uint32_t,eth_mtltxqdr_r> eth_mtltxqdr;
	opsy::utility::padding<32> _p35;
	opsy::utility::memory<uint32_t,eth_mtlqicsr_r> eth_mtlqicsr;
	opsy::utility::memory<uint32_t,eth_mtlrxqomr_r> eth_mtlrxqomr;
	opsy::utility::memory<uint32_t,eth_mtlrxqmpocr_r> eth_mtlrxqmpocr;
	opsy::utility::memory<uint32_t,eth_mtlrxqdr_r> eth_mtlrxqdr;
	opsy::utility::padding<708> _p36;
	opsy::utility::memory<uint32_t,eth_dmamr_r> eth_dmamr;
	opsy::utility::memory<uint32_t,eth_dmasbmr_r> eth_dmasbmr;
	opsy::utility::memory<uint32_t,eth_dmaisr_r> eth_dmaisr;
	opsy::utility::memory<uint32_t,eth_dmadsr_r> eth_dmadsr;
	opsy::utility::padding<240> _p37;
	opsy::utility::memory<uint32_t,eth_dmaccr_r> eth_dmaccr;
	opsy::utility::memory<uint32_t,eth_dmactxcr_r> eth_dmactxcr;
	opsy::utility::memory<uint32_t,eth_dmacrxcr_r> eth_dmacrxcr;
	opsy::utility::padding<8> _p38;
	opsy::utility::memory<uint32_t,eth_dmactxdlar_r> eth_dmactxdlar;
	opsy::utility::padding<4> _p39;
	opsy::utility::memory<uint32_t,eth_dmacrxdlar_r> eth_dmacrxdlar;
	opsy::utility::memory<uint32_t,eth_dmactxdtpr_r> eth_dmactxdtpr;
	opsy::utility::padding<4> _p40;
	opsy::utility::memory<uint32_t,eth_dmacrxdtpr_r> eth_dmacrxdtpr;
	opsy::utility::memory<uint32_t,eth_dmactxrlr_r> eth_dmactxrlr;
	opsy::utility::memory<uint32_t,eth_dmacrxrlr_r> eth_dmacrxrlr;
	opsy::utility::memory<uint32_t,eth_dmacier_r> eth_dmacier;
	opsy::utility::memory<uint32_t,eth_dmacrxiwtr_r> eth_dmacrxiwtr;
	opsy::utility::padding<8> _p41;
	opsy::utility::memory<uint32_t,eth_dmaccatxdr_r> eth_dmaccatxdr;
	opsy::utility::padding<4> _p42;
	opsy::utility::memory<uint32_t,eth_dmaccarxdr_r> eth_dmaccarxdr;
	opsy::utility::padding<4> _p43;
	opsy::utility::memory<uint32_t,eth_dmaccatxbr_r> eth_dmaccatxbr;
	opsy::utility::padding<4> _p44;
	opsy::utility::memory<uint32_t,eth_dmaccarxbr_r> eth_dmaccarxbr;
	opsy::utility::memory<uint32_t,eth_dmacsr_r> eth_dmacsr;
	opsy::utility::padding<8> _p45;
	opsy::utility::memory<uint32_t,eth_dmacmfcr_r> eth_dmacmfcr;
};

static_assert(std::is_standard_layout_v<eth_p>);
static_assert(offsetof(eth_p, eth_maccr) == 0);
static_assert(offsetof(eth_p, eth_macecr) == 4);
static_assert(offsetof(eth_p, eth_macpfr) == 8);
static_assert(offsetof(eth_p, eth_macwtr) == 12);
static_assert(offsetof(eth_p, eth_macht0r) == 16);
static_assert(offsetof(eth_p, eth_macht1r) == 20);
static_assert(offsetof(eth_p, eth_macvtr) == 80);
static_assert(offsetof(eth_p, eth_macvhtr) == 88);
static_assert(offsetof(eth_p, eth_macvir) == 96);
static_assert(offsetof(eth_p, eth_macivir) == 100);
static_assert(offsetof(eth_p, eth_macqtxfcr) == 112);
static_assert(offsetof(eth_p, eth_macrxfcr) == 144);
static_assert(offsetof(eth_p, eth_macisr) == 176);
static_assert(offsetof(eth_p, eth_macier) == 180);
static_assert(offsetof(eth_p, eth_macrxtxsr) == 184);
static_assert(offsetof(eth_p, eth_macpcsr) == 192);
static_assert(offsetof(eth_p, eth_macrwkpfr) == 196);
static_assert(offsetof(eth_p, eth_maclcsr) == 208);
static_assert(offsetof(eth_p, eth_macltcr) == 212);
static_assert(offsetof(eth_p, eth_macletr) == 216);
static_assert(offsetof(eth_p, eth_mac1ustcr) == 220);
static_assert(offsetof(eth_p, eth_macvr) == 272);
static_assert(offsetof(eth_p, eth_macdr) == 276);
static_assert(offsetof(eth_p, eth_machwf0r) == 284);
static_assert(offsetof(eth_p, eth_machwf1r) == 288);
static_assert(offsetof(eth_p, eth_machwf2r) == 292);
static_assert(offsetof(eth_p, eth_machwf3r) == 296);
static_assert(offsetof(eth_p, eth_macmdioar) == 512);
static_assert(offsetof(eth_p, eth_macmdiodr) == 516);
static_assert(offsetof(eth_p, eth_macarpar) == 528);
static_assert(offsetof(eth_p, eth_maccsrswcr) == 560);
static_assert(offsetof(eth_p, eth_maca0hr) == 768);
static_assert(offsetof(eth_p, eth_maca0lr) == 772);
static_assert(offsetof(eth_p, eth_maca1hr) == 776);
static_assert(offsetof(eth_p, eth_maca1lr) == 780);
static_assert(offsetof(eth_p, eth_maca2hr) == 784);
static_assert(offsetof(eth_p, eth_maca2lr) == 788);
static_assert(offsetof(eth_p, eth_maca3hr) == 792);
static_assert(offsetof(eth_p, eth_maca3lr) == 796);
static_assert(offsetof(eth_p, eth_mmc_control) == 1792);
static_assert(offsetof(eth_p, eth_mmc_rx_interrupt) == 1796);
static_assert(offsetof(eth_p, eth_mmc_tx_interrupt) == 1800);
static_assert(offsetof(eth_p, eth_mmc_rx_interrupt_mask) == 1804);
static_assert(offsetof(eth_p, eth_mmc_tx_interrupt_mask) == 1808);
static_assert(offsetof(eth_p, eth_tx_single_collision_good_packets) == 1868);
static_assert(offsetof(eth_p, eth_tx_multiple_collision_good_packets) == 1872);
static_assert(offsetof(eth_p, eth_tx_packet_count_good) == 1896);
static_assert(offsetof(eth_p, eth_rx_crc_error_packets) == 1940);
static_assert(offsetof(eth_p, eth_rx_alignment_error_packets) == 1944);
static_assert(offsetof(eth_p, eth_rx_unicast_packets_good) == 1988);
static_assert(offsetof(eth_p, eth_tx_lpi_usec_cntr) == 2028);
static_assert(offsetof(eth_p, eth_tx_lpi_tran_cntr) == 2032);
static_assert(offsetof(eth_p, eth_rx_lpi_usec_cntr) == 2036);
static_assert(offsetof(eth_p, eth_rx_lpi_tran_cntr) == 2040);
static_assert(offsetof(eth_p, eth_macl3l4c0r) == 2304);
static_assert(offsetof(eth_p, eth_macl4a0r) == 2308);
static_assert(offsetof(eth_p, eth_macl3a00r) == 2320);
static_assert(offsetof(eth_p, eth_macl3a10r) == 2324);
static_assert(offsetof(eth_p, eth_macl3a20r) == 2328);
static_assert(offsetof(eth_p, eth_macl3a30r) == 2332);
static_assert(offsetof(eth_p, eth_macl3l4c1r) == 2352);
static_assert(offsetof(eth_p, eth_macl4a1r) == 2356);
static_assert(offsetof(eth_p, eth_macl3a01r) == 2368);
static_assert(offsetof(eth_p, eth_macl3a11r) == 2372);
static_assert(offsetof(eth_p, eth_macl3a21r) == 2376);
static_assert(offsetof(eth_p, eth_macl3a31r) == 2380);
static_assert(offsetof(eth_p, eth_mactscr) == 2816);
static_assert(offsetof(eth_p, eth_macssir) == 2820);
static_assert(offsetof(eth_p, eth_macstsr) == 2824);
static_assert(offsetof(eth_p, eth_macstnr) == 2828);
static_assert(offsetof(eth_p, eth_macstsur) == 2832);
static_assert(offsetof(eth_p, eth_macstnur) == 2836);
static_assert(offsetof(eth_p, eth_mactsar) == 2840);
static_assert(offsetof(eth_p, eth_mactssr) == 2848);
static_assert(offsetof(eth_p, eth_mactxtssnr) == 2864);
static_assert(offsetof(eth_p, eth_mactxtsssr) == 2868);
static_assert(offsetof(eth_p, eth_macacr) == 2880);
static_assert(offsetof(eth_p, eth_macatsnr) == 2888);
static_assert(offsetof(eth_p, eth_macatssr) == 2892);
static_assert(offsetof(eth_p, eth_mactsiacr) == 2896);
static_assert(offsetof(eth_p, eth_mactseacr) == 2900);
static_assert(offsetof(eth_p, eth_mactsicnr) == 2904);
static_assert(offsetof(eth_p, eth_mactsecnr) == 2908);
static_assert(offsetof(eth_p, eth_macppscr) == 2928);
static_assert(offsetof(eth_p, eth_macppscr_alternate) == 2928);
static_assert(offsetof(eth_p, eth_macppsttsr) == 2944);
static_assert(offsetof(eth_p, eth_macppsttnr) == 2948);
static_assert(offsetof(eth_p, eth_macppsir) == 2952);
static_assert(offsetof(eth_p, eth_macppswr) == 2956);
static_assert(offsetof(eth_p, eth_macpocr) == 3008);
static_assert(offsetof(eth_p, eth_macspi0r) == 3012);
static_assert(offsetof(eth_p, eth_macspi1r) == 3016);
static_assert(offsetof(eth_p, eth_macspi2r) == 3020);
static_assert(offsetof(eth_p, eth_maclmir) == 3024);
static_assert(offsetof(eth_p, eth_mtlomr) == 3072);
static_assert(offsetof(eth_p, eth_mtlisr) == 3104);
static_assert(offsetof(eth_p, eth_mtltxqomr) == 3328);
static_assert(offsetof(eth_p, eth_mtltxqur) == 3332);
static_assert(offsetof(eth_p, eth_mtltxqdr) == 3336);
static_assert(offsetof(eth_p, eth_mtlqicsr) == 3372);
static_assert(offsetof(eth_p, eth_mtlrxqomr) == 3376);
static_assert(offsetof(eth_p, eth_mtlrxqmpocr) == 3380);
static_assert(offsetof(eth_p, eth_mtlrxqdr) == 3384);
static_assert(offsetof(eth_p, eth_dmamr) == 4096);
static_assert(offsetof(eth_p, eth_dmasbmr) == 4100);
static_assert(offsetof(eth_p, eth_dmaisr) == 4104);
static_assert(offsetof(eth_p, eth_dmadsr) == 4108);
static_assert(offsetof(eth_p, eth_dmaccr) == 4352);
static_assert(offsetof(eth_p, eth_dmactxcr) == 4356);
static_assert(offsetof(eth_p, eth_dmacrxcr) == 4360);
static_assert(offsetof(eth_p, eth_dmactxdlar) == 4372);
static_assert(offsetof(eth_p, eth_dmacrxdlar) == 4380);
static_assert(offsetof(eth_p, eth_dmactxdtpr) == 4384);
static_assert(offsetof(eth_p, eth_dmacrxdtpr) == 4392);
static_assert(offsetof(eth_p, eth_dmactxrlr) == 4396);
static_assert(offsetof(eth_p, eth_dmacrxrlr) == 4400);
static_assert(offsetof(eth_p, eth_dmacier) == 4404);
static_assert(offsetof(eth_p, eth_dmacrxiwtr) == 4408);
static_assert(offsetof(eth_p, eth_dmaccatxdr) == 4420);
static_assert(offsetof(eth_p, eth_dmaccarxdr) == 4428);
static_assert(offsetof(eth_p, eth_dmaccatxbr) == 4436);
static_assert(offsetof(eth_p, eth_dmaccarxbr) == 4444);
static_assert(offsetof(eth_p, eth_dmacsr) == 4448);
static_assert(offsetof(eth_p, eth_dmacmfcr) == 4460);

inline eth_p& eth = *reinterpret_cast<eth_p*>(0x40028000);
inline eth_p& sec_eth = *reinterpret_cast<eth_p*>(0x50028000);

} // STM32H563

