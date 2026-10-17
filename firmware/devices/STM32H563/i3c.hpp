#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Improved inter-integrated circuit
 */
class i3c_p {
public:

/**
 * I3C message control register 
 */
class i3c_cr_r {
public:

/**
 * count of data to transfer during a read or write message, in bytes (whatever I3C is acting as controller/target) Linear encoding up to 64 Kbytes -1 ...
 */
class dcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dcnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_r>() const {return opsy::utility::clear_set<i3c_cr_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_r other) const -> i3c_cr_r { return static_cast<i3c_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_r> other) const -> opsy::utility::clear_set<i3c_cr_r> {return opsy::utility::clear_set<i3c_cr_r>(i3c_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * read / non-write message (when I3C is acting as controller) When I3C is acting as controller, this field is used if MTYPE[3:0]=0010 (private message) or MTYPE[3:0]=0011 (direct message) or MTYPE[3:0]=0100 (legacy I2C message), in order to emit the RnW bit on the I3C bus.
 */
class rnw_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rnw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cr_r>() const {return opsy::utility::clear_set<i3c_cr_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_r other) const -> i3c_cr_r { return static_cast<i3c_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_r> other) const -> opsy::utility::clear_set<i3c_cr_r> {return opsy::utility::clear_set<i3c_cr_r>(i3c_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 7-bit I3C dynamic / I2C static target address (when I3C is acting as controller) When I3C is acting as controller, this field is used if MTYPE[3:0]=0010 (private message) or MTYPE[3:0]=0011 (direct message) or MTYPE[3:0]=0100 (legacy I2C message)
 */
class add_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_r>() const {return opsy::utility::clear_set<i3c_cr_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_r other) const -> i3c_cr_r { return static_cast<i3c_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_r> other) const -> opsy::utility::clear_set<i3c_cr_r> {return opsy::utility::clear_set<i3c_cr_r>(i3c_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * message type (whatever I3C is acting as controller/target) Bits[26:0] are ignored. After M2 error detection on an I3C SDR message, this is needed for SCL 'stuck at' recovery. Bits[26:0] are ignored. If I3C_CFGR.EXITPTRN=1, an HDR exit pattern is emitted on the bus to generate an escalation fault. Bits[23:17] (ADD[6:0]) is the emitted 7-bit dynamic address. Bit[16] (RNW) is the emitted RnW bit. The transferred private message is: {S / S+7'h7E+RnW=0+Sr / Sr+*} + 7-bit DynAddr + RnW + (8-bit Data + T)* + Sr/P. After a S (START), depending on I3C_CFGR.NOARBH, the arbitrable header (7'h7E+RnW=0) is inserted or not. Sr+*: after a Sr (Repeated Start), the hardware automatically inserts (7'h7E+RnW=0) if needed, i.e. if it follows an I3C direct message without ending by a P (Stop). Bits[23:17] (ADD[6:0]) is the emitted 7-bit dynamic address. Bit[16] (RNW) is the emitted RnW bit. The transferred direct message is: Sr + 7-bit DynAddr + RnW + (8-bit Data + T)* + Sr/P Bits[23:17] (ADD[6:0]) is the emitted 7-bit static address. Bit[16] (RNW) is the emitted RnW bit. The transferred legacy I2C message is: {S / S+ 7'h7E+RnW=0 + Sr / Sr+*} + 7-bit StaAddr + RnW + (8-bit Data + T)* + Sr/P. After a S (START), depending on I3C_CFGR.NOARBH, the arbitrable header (7'h7E+RnW=0) is inserted or not. Sr+*: after a Sr (Repeated Start), the hardware automatically inserts (7'h7E+RnW=0) if needed, i.e. if it follows an I3C direct message without ending by a P (Stop). 1xxx: reserved (when I3C is acting as I3C controller, used when target) 0xxx: reserved {S +} 7'h02 addr + RnW=0 {S +} 7-bit I3C_DEVR0.DA[6:0] + RnW=0 after a bus available condition (the target first emits a START request), or once the controller drives a START. {S +} 7-bit I3C_DEVR0.DA[6:0] + RnW=1 (+Ack/Nack from controller) When acknowledged from controller, the next (optional, depending on I3C_BCR.BCR2) transmitted IBI payload data is defined by I3C_CR.DCNT[15:0] and must be consistently programmed vs the maximum IBI payload data size which is defined by I3C_IBIDR.IBIP[2:0]. Others: reserved
 */
class mtype_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mtype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_r>() const {return opsy::utility::clear_set<i3c_cr_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_r other) const -> i3c_cr_r { return static_cast<i3c_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_r> other) const -> opsy::utility::clear_set<i3c_cr_r> {return opsy::utility::clear_set<i3c_cr_r>(i3c_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * message end type (when the I3C is acting as controller)
 */
class mend_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cr_r>() const {return opsy::utility::clear_set<i3c_cr_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_r other) const -> i3c_cr_r { return static_cast<i3c_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_r> other) const -> opsy::utility::clear_set<i3c_cr_r> {return opsy::utility::clear_set<i3c_cr_r>(i3c_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dcnt() const -> dcnt_f {return dcnt_f(static_cast<uint16_t>(value_ >> dcnt_f::offset));}
	[[nodiscard]] constexpr auto rnw() const -> rnw_f {return rnw_f((value_ & rnw_f::mask) != 0);}
	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}
	[[nodiscard]] constexpr auto mtype() const -> mtype_f {return mtype_f(static_cast<uint8_t>(value_ >> mtype_f::offset));}
	[[nodiscard]] constexpr auto mend() const -> mend_f {return mend_f((value_ & mend_f::mask) != 0);}

	constexpr i3c_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_cr_r other) const -> i3c_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C message control register alternate
 */
class i3c_cr_alternate_r {
public:

/**
 * count of data to transfer during a read or write message, in bytes (when I3C is acting as controller) Linear encoding up to 64 Kbytes -1. ...
 */
class dcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dcnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_cr_alternate_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate_r>() const {return opsy::utility::clear_set<i3c_cr_alternate_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate_r other) const -> i3c_cr_alternate_r { return static_cast<i3c_cr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate_r> {return opsy::utility::clear_set<i3c_cr_alternate_r>(i3c_cr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * 8-bit CCC code (when I3C is acting as controller) If Bit[23]=CCC[7]=1, this is the 1st part of an I3C SDR direct CCC command. If Bit[23]=CCC[7]=0, this is an I3C SDR broadcast CCC command (including ENTDAA and ENTHDR0).
 */
class ccc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_alternate_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate_r>() const {return opsy::utility::clear_set<i3c_cr_alternate_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate_r other) const -> i3c_cr_alternate_r { return static_cast<i3c_cr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate_r> {return opsy::utility::clear_set<i3c_cr_alternate_r>(i3c_cr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * message type (when I3C is acting as controller) Bits[23:16] (CCC[7:0]) is the emitted 8-bit CCC code If Bit[23]=CCC[7]=1: this is the 1st part of an I3C SDR direct CCC command The transferred direct CCC command message is: {S / S+7'h7E +RnW=0 / Sr+*} + (direct CCC + T) + (8-bit Data + T)* + Sr After a S (START), depending on I3C_CFGR.NOARBH, the arbitrable header (7'h7E+RnW=0) is inserted or not. Sr+*: after a Sr (Repeated Start), the hardware automatically inserts (7'h7E+R/W). If Bit[23]=CCC[7]=0: this is an I3C SDR broadcast CCC command (including ENTDAA and ENTHDR0) The transferred broadcast CCC command message is: {S / S+7'h7E +RnW=0 / Sr+*} + (broadcast CCC + T) + (8-bit Data + T)* + Sr/P After a S (START), depending on I3C_CFGR.NOARBH, the arbitrable header (7'h7E+RnW=0) is inserted or not. Sr+*: after a Sr (Repeated Start), the hardware automatically inserts (7'h7E+R/W). others: reserved
 */
class mtype_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mtype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_alternate_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate_r>() const {return opsy::utility::clear_set<i3c_cr_alternate_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate_r other) const -> i3c_cr_alternate_r { return static_cast<i3c_cr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate_r> {return opsy::utility::clear_set<i3c_cr_alternate_r>(i3c_cr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * message end type (when I3C is acting as controller)
 */
class mend_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cr_alternate_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate_r>() const {return opsy::utility::clear_set<i3c_cr_alternate_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate_r other) const -> i3c_cr_alternate_r { return static_cast<i3c_cr_alternate_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate_r> {return opsy::utility::clear_set<i3c_cr_alternate_r>(i3c_cr_alternate_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dcnt() const -> dcnt_f {return dcnt_f(static_cast<uint16_t>(value_ >> dcnt_f::offset));}
	[[nodiscard]] constexpr auto ccc() const -> ccc_f {return ccc_f(static_cast<uint8_t>(value_ >> ccc_f::offset));}
	[[nodiscard]] constexpr auto mtype() const -> mtype_f {return mtype_f(static_cast<uint8_t>(value_ >> mtype_f::offset));}
	[[nodiscard]] constexpr auto mend() const -> mend_f {return mend_f((value_ & mend_f::mask) != 0);}

	constexpr i3c_cr_alternate_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_cr_alternate_r other) const -> i3c_cr_alternate_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_cr_alternate_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C configuration register 
 */
class i3c_cfgr_r {
public:

/**
 * I3C enable (whatever I3C is acting as controller/target) - Except registers, the peripheral is under reset (a.k.a. partial reset). - Before clearing EN, when I3C is acting as a controller, all the possible target requests must be disabled using DISEC CCC. - When I3C is acting as a target, software should not disable the I3C, unless a partial reset is needed. In this state, some register fields can not be modified (like CRINIT, HKSDAEN for the I3C_CFGR)
 */
class en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * initial controller/target role This bit can be modified only when I3C_CFGR.EN = 0. Once enabled by setting I3C_CFGR.EN = 1, I3C peripheral initially acts as an I3C target. I3C does not drive SCL line and does not enable SDA pull-up, until it eventually acquires the controller role. Once enabled by setting I3C_CFGR.EN = 1, I3C peripheral initially acts as a controller. It has the I3C controller role, so drives SCL line and enables SDA pull-up, until it eventually offers the controller role to an I3C secondary controller.
 */
class crinit_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crinit_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * no arbitrable header after a START (when I3C is acting as a controller) This bit can be modified only when there is no on-going frame. - The target address is emitted directly after a START in case of a legacy I2C message or an I3C SDR private read/write message. - This is a more performing option (when is useless the emission of the 0x7E arbitrable header), but this is to be used only when the controller is sure that the addressed target device can not emit concurrently an IBI or a controller-role request (to insure no misinterpretation and no potential conflict between the address emitted by the controller in open-drain mode and the same address a target device can emit after a START, for IBI or MR).
 */
class noarbh_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr noarbh_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HDR reset pattern enable (when I3C is acting as a controller) This bit can be modified only when there is no on-going frame.
 */
class rstptrn_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rstptrn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HDR Exit Pattern enable (when I3C is acting as a controller) This bit can be modified only when there is no on-going frame. This is used to send only the header to test ownership of the bus when there is a suspicion of problem after controller-role hand-off (new controller didn't assert its controller-role by accessing the previous one in less than Activity State time). The HDR Exit Pattern is sent even if the message header {S/Sr + 0x7E addr + W } is ACKed.
 */
class exitptrn_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exitptrn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High-keeper enable on SDA line (when I3C is acting as a controller) This bit can be modified only when I3C_CFGR.EN=0.
 */
class hksdaen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hksdaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hot Join request acknowledge (when I3C is acting as a controller) After the NACK, the message continues as initially programmed (the hot-joining target is aware of the NACK and surely emits another hot-join request later on). After the ACK, the message continues as initially programmed. The software is aware by the HJ interrupt (flag I3C_EVR.HJF is set) and initiates the ENTDAA sequence later on, potentially preventing others Hot Join requests with a Disable target events command (DISEC, with DISHJ=1). Independently of the HJACK configuration, further Hot Join request(s) are NACKed until the Hot Join flag, HJF, is cleared. However, a NACKed target can be assigned a dynamic address by the ENTDAA sequence initiated later on by the first HJ request, preventing this target to emit an HJ request again.
 */
class hjack_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hjack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO DMA request enable (whatever I3C is acting as controller/target) - Software reads and pops a data byte/word from RX-FIFO i.e. reads I3C_RDR or I3C_RDWR register. - A next data byte/word is to be read by the software either via polling on the flag I3C_EVR.RXFNEF=1 or via interrupt notification (enabled by I3C_IER.RXFNEIE=1). - DMA reads and pops data byte(s)/word(s) from RX-FIFO i.e. reads I3C_RDR or I3C_RDWR register. - A next data byte/word is automatically read by the programmed hardware (i.e. via the asserted RX-FIFO DMA request from the I3C and the programmed DMA channel).
 */
class rxdmaen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO flush (whatever I3C is acting as controller/target) This bit can only be written.
 */
class rxflush_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxflush_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO threshold (whatever I3C is acting as controller/target) This threshold defines, compared to the RX-FIFO level, when the I3C_EVR.RXFNEF flag is set (and consequently if RXDMAEN=1 when is asserted a DMA RX request). RXFNEF is set when 1 byte is to be read in RX-FIFO (i.e. in I3C_RDR). RXFNEF is set when 4 bytes are to be read in RX-FIFO (i.e. in I3C_RDWR).
 */
class rxthres_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxthres_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO DMA request enable (whatever I3C is acting as controller/target) - Software writes and pushes a data byte/word into TX-FIFO i.e. writes I3C_TDR or I3C_TDWR register, to be transmitted over the I3C bus. - A next data byte/word is to be written by the software either via polling on the flag I3C_EVR.TXFNFF=1 or via interrupt notification (enabled by I3C_IER.TXFNFIE=1). - DMA writes and pushes data byte(s)/word(s) into TX-FIFO i.e. writes I3C_TDR or I3C_TDWR register. - A next data byte/word transfer is automatically pushed by the programmed hardware (i.e. via the asserted TX-FIFO DMA request from the I3C and the programmed DMA channel).
 */
class txdmaen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO flush (whatever I3C is acting as controller/target) This bit can only be written. When the I3C is acting as target, this bit can be used to flush the TX-FIFO on a private read if the controller has early ended the read data (i.e. driven low the T bit) and there is/are remaining data in the TX-FIFO (i.e. I3C_SR.ABT=1 and I3C_SR.XDCNT[15:0] I3C_TGTTDR.TGTTDCNT[15:0]).
 */
class txflush_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txflush_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO threshold (whatever I3C is acting as controller/target) This threshold defines, compared to the TX-FIFO level, when the I3C_EVR.TXFNFF flag is set (and consequently if TXDMAEN=1 when is asserted a DMA TX request). TXFNFF is set when 1 byte is to be written in TX-FIFO (i.e. in I3C_TDR). TXFNFF is set when 4 bytes are to be written in TX-FIFO (i.e. in I3C_TDWR).
 */
class txthres_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr txthres_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * S-FIFO DMA request enable (when I3C is acting as controller) Condition: When RMODE=1 (FIFO is enabled for the status): - Software reads and pops a status word from S-FIFO i.e. reads I3C_SR register after a completed frame (I3C_EVR.FCF=1) or an error (I3C_EVR.ERRF=1). - A status word can be read by the software either via polling on these register flags or via interrupt notification (enabled by I3C_IER.FCIE=1 and I3C_IER.ERRIE=1). - DMA reads and pops status word(s) from S-FIFO i.e. reads I3C_SR register. - Status word(s) are automatically read by the programmed hardware (i.e. via the asserted S-FIFO DMA request from the I3C and the programmed DMA channel).
 */
class sdmaen_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * S-FIFO flush (when I3C is acting as controller) When I3C is acting as I3C controller, this bit can only be written (and is only used when I3C is acting as controller).
 */
class sflush_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sflush_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * S-FIFO enable / status receive mode (when I3C is acting as controller) When I3C is acting as I3C controller, this bit is used for the enabling the FIFO for the status (S-FIFO) vs the received status from the target on the I3C bus. When I3C is acting as target, this bit must be cleared. - Status register (i.e. I3C_SR) is used without FIFO mechanism. - There is no SCL stretch if a new status register content is not read. - Status register must be read before being lost/overwritten. All message status must be read. There is SCL stretch when there is no more space in the S-FIFO.
 */
class rmode_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * transmit mode (when I3C is acting as controller) When I3C is acting as I3C controller, this bit is used for the C-FIFO and TX-FIFO management vs the emitted frame on the I3C bus. A frame transfer starts as soon as first control word is present in C-FIFO.
 */
class tmode_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * C-FIFO DMA request enable (when I3C is acting as controller) When I3C is acting as controller: - Software writes and pushes control word(s) into C-FIFO i.e. writes I3C_CR register, as needed for a given frame. - A next control word transfer can be written by software either via polling on the flag I3C_EVR.CFNFF=1 or via interrupt notification (enabled by I3C_IER.CFNFIE=1). - DMA writes and pushes control word(s) into C-FIFO i.e. writes I3C_CR register, as needed for a given frame. - A next control word transfer is automatically written by the programmed hardware (i.e. via the asserted C-FIFO DMA request from the I3C and the programmed DMA channel).
 */
class cdmaen_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cdmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * C-FIFO flush (when I3C is acting as controller) This bit can only be written.
 */
class cflush_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cflush_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * frame transfer set (a.k.a. software trigger) (when I3C is acting as controller) This bit can only be written. When I3C is acting as I3C controller: Note: If this bit is not set, the other alternative for the software to initiate a frame transfer is to directly write the first control word register (i.e. I3C_CR) while C-FIFO is empty (i.e. I3C_EVR.CFEF=1). Then, if the first written control word is not tagged as a message end (i.e I3C_CR.MEND=0), it causes the hardware to assert the flag I3C_EVR.CFNFF (C-FIFO not full and a next control word is needed).
 */
class tsfset_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tsfset_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto crinit() const -> crinit_f {return crinit_f((value_ & crinit_f::mask) != 0);}
	[[nodiscard]] constexpr auto noarbh() const -> noarbh_f {return noarbh_f((value_ & noarbh_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstptrn() const -> rstptrn_f {return rstptrn_f((value_ & rstptrn_f::mask) != 0);}
	[[nodiscard]] constexpr auto exitptrn() const -> exitptrn_f {return exitptrn_f((value_ & exitptrn_f::mask) != 0);}
	[[nodiscard]] constexpr auto hksdaen() const -> hksdaen_f {return hksdaen_f((value_ & hksdaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto hjack() const -> hjack_f {return hjack_f((value_ & hjack_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdmaen() const -> rxdmaen_f {return rxdmaen_f((value_ & rxdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxflush() const -> rxflush_f {return rxflush_f((value_ & rxflush_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxthres() const -> rxthres_f {return rxthres_f((value_ & rxthres_f::mask) != 0);}
	[[nodiscard]] constexpr auto txdmaen() const -> txdmaen_f {return txdmaen_f((value_ & txdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto txflush() const -> txflush_f {return txflush_f((value_ & txflush_f::mask) != 0);}
	[[nodiscard]] constexpr auto txthres() const -> txthres_f {return txthres_f((value_ & txthres_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdmaen() const -> sdmaen_f {return sdmaen_f((value_ & sdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto sflush() const -> sflush_f {return sflush_f((value_ & sflush_f::mask) != 0);}
	[[nodiscard]] constexpr auto rmode() const -> rmode_f {return rmode_f((value_ & rmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto tmode() const -> tmode_f {return tmode_f((value_ & tmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdmaen() const -> cdmaen_f {return cdmaen_f((value_ & cdmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto cflush() const -> cflush_f {return cflush_f((value_ & cflush_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsfset() const -> tsfset_f {return tsfset_f((value_ & tsfset_f::mask) != 0);}

	constexpr i3c_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_cfgr_r other) const -> i3c_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C receive data byte register 
 */
class i3c_rdr_r {
public:

/**
 * 8-bit received data on I3C bus.
 */
class rdb0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rdb0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rdr_r>() const {return opsy::utility::clear_set<i3c_rdr_r>(mask, *this);}
	constexpr auto operator|(i3c_rdr_r other) const -> i3c_rdr_r { return static_cast<i3c_rdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rdr_r> other) const -> opsy::utility::clear_set<i3c_rdr_r> {return opsy::utility::clear_set<i3c_rdr_r>(i3c_rdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rdb0() const -> rdb0_f {return rdb0_f(static_cast<uint8_t>(value_ >> rdb0_f::offset));}

	constexpr i3c_rdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_rdr_r other) const -> i3c_rdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_rdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C receive data word register 
 */
class i3c_rdwr_r {
public:

/**
 * 8-bit received data (earliest byte on I3C bus).
 */
class rdb0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rdb0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rdwr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rdwr_r>() const {return opsy::utility::clear_set<i3c_rdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_rdwr_r other) const -> i3c_rdwr_r { return static_cast<i3c_rdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rdwr_r> other) const -> opsy::utility::clear_set<i3c_rdwr_r> {return opsy::utility::clear_set<i3c_rdwr_r>(i3c_rdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit received data (next byte after RDB0 on I3C bus).
 */
class rdb1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdb1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rdwr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rdwr_r>() const {return opsy::utility::clear_set<i3c_rdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_rdwr_r other) const -> i3c_rdwr_r { return static_cast<i3c_rdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rdwr_r> other) const -> opsy::utility::clear_set<i3c_rdwr_r> {return opsy::utility::clear_set<i3c_rdwr_r>(i3c_rdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit received data (next byte after RDB1 on I3C bus).
 */
class rdb2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdb2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rdwr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rdwr_r>() const {return opsy::utility::clear_set<i3c_rdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_rdwr_r other) const -> i3c_rdwr_r { return static_cast<i3c_rdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rdwr_r> other) const -> opsy::utility::clear_set<i3c_rdwr_r> {return opsy::utility::clear_set<i3c_rdwr_r>(i3c_rdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit received data (latest byte on I3C bus).
 */
class rdb3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdb3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rdwr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rdwr_r>() const {return opsy::utility::clear_set<i3c_rdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_rdwr_r other) const -> i3c_rdwr_r { return static_cast<i3c_rdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rdwr_r> other) const -> opsy::utility::clear_set<i3c_rdwr_r> {return opsy::utility::clear_set<i3c_rdwr_r>(i3c_rdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rdb0() const -> rdb0_f {return rdb0_f(static_cast<uint8_t>(value_ >> rdb0_f::offset));}
	[[nodiscard]] constexpr auto rdb1() const -> rdb1_f {return rdb1_f(static_cast<uint8_t>(value_ >> rdb1_f::offset));}
	[[nodiscard]] constexpr auto rdb2() const -> rdb2_f {return rdb2_f(static_cast<uint8_t>(value_ >> rdb2_f::offset));}
	[[nodiscard]] constexpr auto rdb3() const -> rdb3_f {return rdb3_f(static_cast<uint8_t>(value_ >> rdb3_f::offset));}

	constexpr i3c_rdwr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_rdwr_r other) const -> i3c_rdwr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_rdwr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C transmit data byte register 
 */
class i3c_tdr_r {
public:

/**
 * 8-bit data to transmit on I3C bus.
 */
class tdb0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tdb0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_tdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tdr_r>() const {return opsy::utility::clear_set<i3c_tdr_r>(mask, *this);}
	constexpr auto operator|(i3c_tdr_r other) const -> i3c_tdr_r { return static_cast<i3c_tdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tdr_r> other) const -> opsy::utility::clear_set<i3c_tdr_r> {return opsy::utility::clear_set<i3c_tdr_r>(i3c_tdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tdb0() const -> tdb0_f {return tdb0_f(static_cast<uint8_t>(value_ >> tdb0_f::offset));}

	constexpr i3c_tdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_tdr_r other) const -> i3c_tdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_tdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C transmit data word register 
 */
class i3c_tdwr_r {
public:

/**
 * 8-bit transmit data (earliest byte on I3C bus)
 */
class tdb0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tdb0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_tdwr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tdwr_r>() const {return opsy::utility::clear_set<i3c_tdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_tdwr_r other) const -> i3c_tdwr_r { return static_cast<i3c_tdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tdwr_r> other) const -> opsy::utility::clear_set<i3c_tdwr_r> {return opsy::utility::clear_set<i3c_tdwr_r>(i3c_tdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit transmit data (next byte after TDB0[7:0] on I3C bus).
 */
class tdb1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdb1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_tdwr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tdwr_r>() const {return opsy::utility::clear_set<i3c_tdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_tdwr_r other) const -> i3c_tdwr_r { return static_cast<i3c_tdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tdwr_r> other) const -> opsy::utility::clear_set<i3c_tdwr_r> {return opsy::utility::clear_set<i3c_tdwr_r>(i3c_tdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit transmit data (next byte after TDB1[7:0] on I3C bus).
 */
class tdb2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdb2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_tdwr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tdwr_r>() const {return opsy::utility::clear_set<i3c_tdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_tdwr_r other) const -> i3c_tdwr_r { return static_cast<i3c_tdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tdwr_r> other) const -> opsy::utility::clear_set<i3c_tdwr_r> {return opsy::utility::clear_set<i3c_tdwr_r>(i3c_tdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit transmit data (latest byte on I3C bus).
 */
class tdb3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tdb3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_tdwr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tdwr_r>() const {return opsy::utility::clear_set<i3c_tdwr_r>(mask, *this);}
	constexpr auto operator|(i3c_tdwr_r other) const -> i3c_tdwr_r { return static_cast<i3c_tdwr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tdwr_r> other) const -> opsy::utility::clear_set<i3c_tdwr_r> {return opsy::utility::clear_set<i3c_tdwr_r>(i3c_tdwr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tdb0() const -> tdb0_f {return tdb0_f(static_cast<uint8_t>(value_ >> tdb0_f::offset));}
	[[nodiscard]] constexpr auto tdb1() const -> tdb1_f {return tdb1_f(static_cast<uint8_t>(value_ >> tdb1_f::offset));}
	[[nodiscard]] constexpr auto tdb2() const -> tdb2_f {return tdb2_f(static_cast<uint8_t>(value_ >> tdb2_f::offset));}
	[[nodiscard]] constexpr auto tdb3() const -> tdb3_f {return tdb3_f(static_cast<uint8_t>(value_ >> tdb3_f::offset));}

	constexpr i3c_tdwr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_tdwr_r other) const -> i3c_tdwr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_tdwr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C IBI payload data register 
 */
class i3c_ibidr_r {
public:

/**
 * 8-bit IBI payload data (earliest byte on I3C bus, i.e. MDB[7:0] mandatory data byte).
 */
class ibidb0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ibidb0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_ibidr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_ibidr_r>() const {return opsy::utility::clear_set<i3c_ibidr_r>(mask, *this);}
	constexpr auto operator|(i3c_ibidr_r other) const -> i3c_ibidr_r { return static_cast<i3c_ibidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ibidr_r> other) const -> opsy::utility::clear_set<i3c_ibidr_r> {return opsy::utility::clear_set<i3c_ibidr_r>(i3c_ibidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit IBI payload data (next byte on I3C bus after IBIDB0[7:0]).
 */
class ibidb1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ibidb1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_ibidr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_ibidr_r>() const {return opsy::utility::clear_set<i3c_ibidr_r>(mask, *this);}
	constexpr auto operator|(i3c_ibidr_r other) const -> i3c_ibidr_r { return static_cast<i3c_ibidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ibidr_r> other) const -> opsy::utility::clear_set<i3c_ibidr_r> {return opsy::utility::clear_set<i3c_ibidr_r>(i3c_ibidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit IBI payload data (next byte on I3C bus after IBIDB1[7:0]).
 */
class ibidb2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ibidb2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_ibidr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_ibidr_r>() const {return opsy::utility::clear_set<i3c_ibidr_r>(mask, *this);}
	constexpr auto operator|(i3c_ibidr_r other) const -> i3c_ibidr_r { return static_cast<i3c_ibidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ibidr_r> other) const -> opsy::utility::clear_set<i3c_ibidr_r> {return opsy::utility::clear_set<i3c_ibidr_r>(i3c_ibidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * 8-bit IBI payload data (latest byte on I3C bus).
 */
class ibidb3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ibidb3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_ibidr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_ibidr_r>() const {return opsy::utility::clear_set<i3c_ibidr_r>(mask, *this);}
	constexpr auto operator|(i3c_ibidr_r other) const -> i3c_ibidr_r { return static_cast<i3c_ibidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ibidr_r> other) const -> opsy::utility::clear_set<i3c_ibidr_r> {return opsy::utility::clear_set<i3c_ibidr_r>(i3c_ibidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ibidb0() const -> ibidb0_f {return ibidb0_f(static_cast<uint8_t>(value_ >> ibidb0_f::offset));}
	[[nodiscard]] constexpr auto ibidb1() const -> ibidb1_f {return ibidb1_f(static_cast<uint8_t>(value_ >> ibidb1_f::offset));}
	[[nodiscard]] constexpr auto ibidb2() const -> ibidb2_f {return ibidb2_f(static_cast<uint8_t>(value_ >> ibidb2_f::offset));}
	[[nodiscard]] constexpr auto ibidb3() const -> ibidb3_f {return ibidb3_f(static_cast<uint8_t>(value_ >> ibidb3_f::offset));}

	constexpr i3c_ibidr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_ibidr_r other) const -> i3c_ibidr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_ibidr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C target transmit configuration register 
 */
class i3c_tgttdr_r {
public:

/**
 * transmit data counter, in bytes (when I3C is configured as target) This field must be written by software in the same access when is asserted PRELOAD, in order to define the number of bytes to preload and to transmit. This field is updated by hardware and reports, when read, the remaining number of bytes to be loaded into the TX-FIFO.
 */
class tgttdcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tgttdcnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_tgttdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_tgttdr_r>() const {return opsy::utility::clear_set<i3c_tgttdr_r>(mask, *this);}
	constexpr auto operator|(i3c_tgttdr_r other) const -> i3c_tgttdr_r { return static_cast<i3c_tgttdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tgttdr_r> other) const -> opsy::utility::clear_set<i3c_tgttdr_r> {return opsy::utility::clear_set<i3c_tgttdr_r>(i3c_tgttdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * preload of the TX-FIFO (when I3C is configured as target) This bit must be written and asserted by software in the same access when is written and defined the number of bytes to preload into the TX-FIFO and to transmit. This bit is cleared by hardware when all the data bytes to transmit are loaded into the TX-FIFO.
 */
class preload_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr preload_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_tgttdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_tgttdr_r>() const {return opsy::utility::clear_set<i3c_tgttdr_r>(mask, *this);}
	constexpr auto operator|(i3c_tgttdr_r other) const -> i3c_tgttdr_r { return static_cast<i3c_tgttdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_tgttdr_r> other) const -> opsy::utility::clear_set<i3c_tgttdr_r> {return opsy::utility::clear_set<i3c_tgttdr_r>(i3c_tgttdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tgttdcnt() const -> tgttdcnt_f {return tgttdcnt_f(static_cast<uint16_t>(value_ >> tgttdcnt_f::offset));}
	[[nodiscard]] constexpr auto preload() const -> preload_f {return preload_f((value_ & preload_f::mask) != 0);}

	constexpr i3c_tgttdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_tgttdr_r other) const -> i3c_tgttdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_tgttdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C status register 
 */
class i3c_sr_r {
public:

/**
 * data counter - When the I3C is acting as controller: number of targets detected on the bus - When the I3C is acting as target: number of transmitted bytes - Whatever the I3C is acting as controller or target: number of data bytes read from or transmitted on the I3C bus during the MID[7:0] message
 */
class xdcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr xdcnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_sr_r>() const {return opsy::utility::clear_set<i3c_sr_r>(mask, *this);}
	constexpr auto operator|(i3c_sr_r other) const -> i3c_sr_r { return static_cast<i3c_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_sr_r> other) const -> opsy::utility::clear_set<i3c_sr_r> {return opsy::utility::clear_set<i3c_sr_r>(i3c_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * a private read message is completed/aborted prematurely by the target (when the I3C is acting as controller) When the I3C is acting as controller, this bit indicates if the private read data which is transmitted by the target early terminates (i.e. the target drives T bit low earlier vs what does expect the controller in terms of programmed number of read data bytes i.e. I3C_CR.DCNT[15:0]).
 */
class abt_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_sr_r>() const {return opsy::utility::clear_set<i3c_sr_r>(mask, *this);}
	constexpr auto operator|(i3c_sr_r other) const -> i3c_sr_r { return static_cast<i3c_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_sr_r> other) const -> opsy::utility::clear_set<i3c_sr_r> {return opsy::utility::clear_set<i3c_sr_r>(i3c_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * message direction Whatever the I3C is acting as controller or target, this bit indicates the direction of the related message on the I3C bus Note: ENTDAA CCC is considered as a write command.
 */
class dir_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_sr_r>() const {return opsy::utility::clear_set<i3c_sr_r>(mask, *this);}
	constexpr auto operator|(i3c_sr_r other) const -> i3c_sr_r { return static_cast<i3c_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_sr_r> other) const -> opsy::utility::clear_set<i3c_sr_r> {return opsy::utility::clear_set<i3c_sr_r>(i3c_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * message identifier/counter of a given frame (when the I3C is acting as controller) When the I3C is acting as controller, this field identifies the control word message (i.e. I3C_CR) to which the I3C_SR status register refers. First message of a frame is identified with MID[7:0]=0. This field is incremented (by hardware) on the completion of a new message control word (i.e. I3C_CR) over I3C bus. This field is reset for every new frame start.
 */
class mid_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mid_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_sr_r>() const {return opsy::utility::clear_set<i3c_sr_r>(mask, *this);}
	constexpr auto operator|(i3c_sr_r other) const -> i3c_sr_r { return static_cast<i3c_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_sr_r> other) const -> opsy::utility::clear_set<i3c_sr_r> {return opsy::utility::clear_set<i3c_sr_r>(i3c_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto xdcnt() const -> xdcnt_f {return xdcnt_f(static_cast<uint16_t>(value_ >> xdcnt_f::offset));}
	[[nodiscard]] constexpr auto abt() const -> abt_f {return abt_f((value_ & abt_f::mask) != 0);}
	[[nodiscard]] constexpr auto dir() const -> dir_f {return dir_f((value_ & dir_f::mask) != 0);}
	[[nodiscard]] constexpr auto mid() const -> mid_f {return mid_f(static_cast<uint8_t>(value_ >> mid_f::offset));}

	constexpr i3c_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_sr_r other) const -> i3c_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C status error register 
 */
class i3c_ser_r {
public:

/**
 * protocol error code/type controller detected an illegally formatted CCC controller detected that transmitted data on the bus is different from expected controller detected a not acknowledged broadcast address (7'hE) controller detected the new controller did not drive bus after controller-role hand-off target detected an invalid broadcast address 7'hE+W target detected a parity error on a CCC code via a parity check (vs T bit) target detected a parity error on a write data via a parity check (vs T bit) target detected a parity error on the assigned address during dynamic address arbitration via a parity check (vs PAR bit) target detected a 7'hE+R missing after Sr during dynamic address arbitration target detected an illegally formatted CCC target detected that transmitted data on the bus is different from expected others: reserved
 */
class coderr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr coderr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_ser_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * protocol error
 */
class perr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr perr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SCL stall error (when the I3C is acting as target)
 */
class stall_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stall_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO overrun or TX-FIFO underrun i) a TX-FIFO underrun: TX-FIFO is empty and a write data byte has to be transmitted ii) a RX-FIFO overrun: RX-FIFO is full and a new data byte is received
 */
class dovr_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * C-FIFO underrun or S-FIFO overrun (when the I3C is acting as controller) i) a C-FIFO underrun: control FIFO is empty and a restart has to be emitted ii) a S-FIFO overrun: S-FIFO is full and a new message ends
 */
class covr_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr covr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * address not acknowledged (when the I3C is configured as controller) i) a legacy I2C read/write transfer ii) a direct CCC write transfer iii) the second trial of a direct CCC read transfer iv) a private read/write transfer
 */
class anack_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr anack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data not acknowledged (when the I3C is acting as controller) i) a legacy I2C write transfer ii) the second trial when sending dynamic address during ENTDAA procedure
 */
class dnack_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dnack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data error (when the I3C is acting as controller)
 */
class derr_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr derr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ser_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ser_r>() const {return opsy::utility::clear_set<i3c_ser_r>(mask, *this);}
	constexpr auto operator|(i3c_ser_r other) const -> i3c_ser_r { return static_cast<i3c_ser_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ser_r> other) const -> opsy::utility::clear_set<i3c_ser_r> {return opsy::utility::clear_set<i3c_ser_r>(i3c_ser_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto coderr() const -> coderr_f {return coderr_f(static_cast<uint8_t>(value_ >> coderr_f::offset));}
	[[nodiscard]] constexpr auto perr() const -> perr_f {return perr_f((value_ & perr_f::mask) != 0);}
	[[nodiscard]] constexpr auto stall() const -> stall_f {return stall_f((value_ & stall_f::mask) != 0);}
	[[nodiscard]] constexpr auto dovr() const -> dovr_f {return dovr_f((value_ & dovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto covr() const -> covr_f {return covr_f((value_ & covr_f::mask) != 0);}
	[[nodiscard]] constexpr auto anack() const -> anack_f {return anack_f((value_ & anack_f::mask) != 0);}
	[[nodiscard]] constexpr auto dnack() const -> dnack_f {return dnack_f((value_ & dnack_f::mask) != 0);}
	[[nodiscard]] constexpr auto derr() const -> derr_f {return derr_f((value_ & derr_f::mask) != 0);}

	constexpr i3c_ser_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_ser_r other) const -> i3c_ser_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_ser_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C received message register 
 */
class i3c_rmr_r {
public:

/**
 * IBI received payload data count (when the I3C is configured as controller) When the I3C is configured as controller, this field logs the number of data bytes effectively received in the I3C_IBIDR register.
 */
class ibirdcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ibirdcnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rmr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rmr_r>() const {return opsy::utility::clear_set<i3c_rmr_r>(mask, *this);}
	constexpr auto operator|(i3c_rmr_r other) const -> i3c_rmr_r { return static_cast<i3c_rmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rmr_r> other) const -> opsy::utility::clear_set<i3c_rmr_r> {return opsy::utility::clear_set<i3c_rmr_r>(i3c_rmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * received CCC code (when the I3C is configured as target) When the I3C is configured as target, this field logs the received CCC code.
 */
class rcode_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rcode_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rmr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rmr_r>() const {return opsy::utility::clear_set<i3c_rmr_r>(mask, *this);}
	constexpr auto operator|(i3c_rmr_r other) const -> i3c_rmr_r { return static_cast<i3c_rmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rmr_r> other) const -> opsy::utility::clear_set<i3c_rmr_r> {return opsy::utility::clear_set<i3c_rmr_r>(i3c_rmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * received target address (when the I3C is configured as controller) When the I3C is configured as controller, this field logs the received dynamic address from the target during acknowledged IBI or controller-role request.
 */
class radd_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr radd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_rmr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_rmr_r>() const {return opsy::utility::clear_set<i3c_rmr_r>(mask, *this);}
	constexpr auto operator|(i3c_rmr_r other) const -> i3c_rmr_r { return static_cast<i3c_rmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_rmr_r> other) const -> opsy::utility::clear_set<i3c_rmr_r> {return opsy::utility::clear_set<i3c_rmr_r>(i3c_rmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ibirdcnt() const -> ibirdcnt_f {return ibirdcnt_f(static_cast<uint8_t>(value_ >> ibirdcnt_f::offset));}
	[[nodiscard]] constexpr auto rcode() const -> rcode_f {return rcode_f(static_cast<uint8_t>(value_ >> rcode_f::offset));}
	[[nodiscard]] constexpr auto radd() const -> radd_f {return radd_f(static_cast<uint8_t>(value_ >> radd_f::offset));}

	constexpr i3c_rmr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_rmr_r other) const -> i3c_rmr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_rmr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C event register 
 */
class i3c_evr_r {
public:

/**
 * C-FIFO empty flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that the C-FIFO is empty when controller, and that the I3C_CR register contains no control word (i.e. none IBI/CR/HJ request) when target. This flag is de-asserted by hardware to indicate that the C-FIFO is not empty when controller, and that the I3C_CR register contains one control word (i.e. a pending IBI/CR/HJ request) when target. Note: When the I3C is acting as controller, if the C-FIFO and TX-FIFO preload is configured (i.e. I3C_CFGR.TMODE=1), the software must wait for TXFEF=1 and CFEF=1 before starting a new frame transfer.
 */
class cfef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cfef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO empty flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that the TX-FIFO is empty. This flag is de-asserted by hardware to indicate that the TX-FIFO is not empty. Note: When the I3C is acting as controller, if the C-FIFO and TX-FIFO preload is configured (i.e. I3C_CFGR.TMODE=1), the software must wait for TXFEF=1 and CFEF=1 before starting a new frame transfer.
 */
class txfef_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * C-FIFO not full flag (when the I3C is acting as controller) When the I3C is acting as controller, this flag is asserted by hardware to indicate that a control word is to be written to the C-FIFO. This flag is de-asserted by hardware to indicate that a control word is not to be written to the C-FIFO. Note: The software must wait for CFNFF=1 (by polling or via the enabled interrupt) before writing to C-FIFO (i.e. writing to I3C_CR).
 */
class cfnff_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cfnff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * S-FIFO not empty flag (when the I3C is acting as controller) When the I3C is acting as controller, if the S-FIFO is enabled (i.e. I3C_CFGR.RMODE=1), this flag is asserted by hardware to indicate that a status word is to be read from the S-FIFO. This flag is de-asserted by hardware to indicate that a status word is not to be read from the S-FIFO.
 */
class sfnef_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sfnef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO not full flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that a data byte/word is to be written to the TX-FIFO. This flag is de-asserted by hardware to indicate that a data byte/word is not to be written to the TX-FIFO. Note: The software must wait for TXFNFF=1 (by polling or via the enabled interrupt) before writing to TX-FIFO (i.e. writing to I3C_TDR or I3C_TDWR depending on I3C_CFGR.TXTHRES). Note: When the I3C is acting as target, if the software intends to use the TXFNFF flag for writing into I3C_TDR/I3C_TDWR, it must have configured and set the TX-FIFO preload (i.e. write I3C_TGTTDR.PRELOAD).
 */
class txfnff_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO not empty flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that a data byte is to be read from the RX-FIFO. This flag is de-asserted by hardware to indicate that a data byte is not to be read from the RX-FIFO. Note: The software must wait for RXFNEF=1 (by polling or via the enabled interrupt) before reading from RX-FIFO (i.e. writing to I3C_RDR or I3C_RDWR depending on I3C_CFGR.RXTHRES).
 */
class rxfnef_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfnef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * last written data byte/word flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that the last data byte/word (depending on I3C_CFGR.TXTHRES) of a message is to be written to the TX-FIFO. This flag is de-asserted by hardware when the last data byte/word of a message is written.
 */
class txlastf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txlastf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * last read data byte/word flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that the last data byte/word (depending on I3C_CFGR.RXTHRES) of a message is to be read from the RX-FIFO. This flag is de-asserted by hardware when the last data byte/word of a message is read.
 */
class rxlastf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxlastf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * frame complete flag (whatever the I3C is acting as controller/target) When the I3C is acting as controller, this flag is asserted by hardware to indicate that a frame has been (normally) completed on the I3C bus, i.e when a stop is issued. When the I3C is acting as target, this flag is asserted by hardware to indicate that a message addressed to/by this target has been (normally) completed on the I3C bus, i.e when a next stop or repeated start is then issued by the controller. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CFCF bit.
 */
class fcf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * target-initiated read end flag (when the I3C is acting as controller) When the I3C is acting as controller, this flag is asserted by hardware to indicate that the target has prematurely ended a read transfer. Then, software should read I3C_SR to get more information on the prematurely read transfer. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CRXTGTENDF bit.
 */
class rxtgtendf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxtgtendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * flag (whatever the I3C is acting as controller/target) This flag is asserted by hardware to indicate that an error occurred.Then, software should read I3C_SER to get the error type. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CERRF bit.
 */
class errf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr errf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IBI flag (when the I3C is acting as controller) When the I3C is acting as controller, this flag is asserted by hardware to indicate that an IBI request has been received. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CIBIF bit.
 */
class ibif_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ibif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IBI end flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a IBI transfer has been received and completed (IBI acknowledged and IBI data bytes read by controller if any). This flag is cleared when software writes 1 into corresponding I3C_CEVR.CIBIENDF bit.
 */
class ibiendf_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ibiendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role request flag (when the I3C is acting as controller) When the I3C is acting as controller, this flag is asserted by hardware to indicate that a controller-role request has been acknowledged and completed (by hardware). The software should then issue a GETACCCR CCC (get accept controller role) for the controller-role hand-off procedure. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CCRF bit.
 */
class crf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that it has now gained the controller role after the completed controller-role hand-off procedure. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CCRUPDF bit.
 */
class crupdf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * hot-join flag (when the I3C is acting as controller) When the I3C is acting as controller, this flag is asserted by hardware to indicate that an hot join request has been received. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CHJF bit.
 */
class hjf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hjf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wakeup/missed start flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a start has been detected (i.e. a SDA falling edge followed by a SCL falling edge) but on the next SCL falling edge, the I3C kernel clock is (still) gated. Thus an I3C bus transaction may have been lost by the target. The corresponding interrupt may be used to wakeup the device from a low power mode (Sleep or Stop mode). This flag is cleared when software writes 1 into corresponding I3C_CEVR.CWKPF bit.
 */
class wkpf_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wkpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * get flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that any direct CCC of get type (GET*** CCC) has been received. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CGETF bit.
 */
class getf_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr getf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * get status flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a direct GETSTATUS CCC (get status) has been received. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CSTAF bit.
 */
class staf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr staf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * dynamic address update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a dynamic address update has been received via any of the broadcast ENTDAA, RSTDAA and direct SETNEWDA CCC. Then, software should read I3C_DEVR0.DA[6:0] to get the maximum write length value. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CDAUPDF bit.
 */
class daupdf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr daupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * maximum write length update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a direct SETMWL CCC (set max write length) has been received. Then, software should read I3C_MAXWLR.MWL[15:0] to get the maximum write length value. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CMWLUPDF bit.
 */
class mwlupdf_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mwlupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * maximum read length update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a direct SETMRL CCC (set max read length) has been received. Then, software should read I3C_MAXRLR.MRL[15:0] to get the maximum read length value. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CMRLUPDF bit.
 */
class mrlupdf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mrlupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * reset pattern flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that a reset pattern has been detected (i.e. 14 SDA transitions while SCL is low, followed by repeated start, then stop). Then, software should read I3C_DEVR0.RSTACT[1:0] and I3C_DEVR0.RSTVAL, to know what reset level is required. If RSTVAL=1: when the RSTF is asserted (and/or the corresponding interrupt if enabled), I3C_DEVR0.RSTACT[1:0] dictates the reset action to be performed by the software if any. If RSTVAL=0: when the RSTF is asserted (and/or the corresponding interrupt if enabled), the software should issue an I3C reset after a first detected reset pattern, and a system reset on the second one. The corresponding interrupt may be used to wakeup the device from a low power mode (Sleep or Stop mode). This flag is cleared when software writes 1 into corresponding I3C_CEVR.CRSTF bit.
 */
class rstf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * activity state update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that the direct or broadcast ENTASx CCC (with x=0...3) has been received. Then, software should read I3C_DEVR0.AS[1:0]. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CASUPDF bit.
 */
class asupdf_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr asupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * interrupt/controller-role/hot-join update flag (when the I3C is acting as target) When the I3C is acting as target, this flag is asserted by hardware to indicate that the direct or broadcast ENEC/DISEC CCC (enable/disable target events) has been received, where a target event is either an interrupt/IBI request, a controller-role request, or an hot-join request. Then, software should read respectively I3C_DEVR0.IBIEN, I3C_DEVR0.CREN or I3C_DEVR0.HJEN. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CINTUPDF bit.
 */
class intupdf_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr intupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DEFTGTS flag (when the I3C is acting as target) When the I3C is acting as target (and is typically controller capable), this flag is asserted by hardware to indicate that the broadcast DEFTGTS CCC (define list of targets) has been received. Then, software may store the received data for when getting the controller role. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CDEFF bit.
 */
class deff_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr deff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * group addressing flag (when the I3C is acting as target) When the I3C is acting as target (and is typically controller capable), this flag is asserted by hardware to indicate that the broadcast DEFGRPA CCC (define list of group addresses) has been received. Then, software may store the received data for when getting the controller role. This flag is cleared when software writes 1 into corresponding I3C_CEVR.CGRPF bit.
 */
class grpf_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr grpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_evr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_evr_r>() const {return opsy::utility::clear_set<i3c_evr_r>(mask, *this);}
	constexpr auto operator|(i3c_evr_r other) const -> i3c_evr_r { return static_cast<i3c_evr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_evr_r> other) const -> opsy::utility::clear_set<i3c_evr_r> {return opsy::utility::clear_set<i3c_evr_r>(i3c_evr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cfef() const -> cfef_f {return cfef_f((value_ & cfef_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfef() const -> txfef_f {return txfef_f((value_ & txfef_f::mask) != 0);}
	[[nodiscard]] constexpr auto cfnff() const -> cfnff_f {return cfnff_f((value_ & cfnff_f::mask) != 0);}
	[[nodiscard]] constexpr auto sfnef() const -> sfnef_f {return sfnef_f((value_ & sfnef_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnff() const -> txfnff_f {return txfnff_f((value_ & txfnff_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfnef() const -> rxfnef_f {return rxfnef_f((value_ & rxfnef_f::mask) != 0);}
	[[nodiscard]] constexpr auto txlastf() const -> txlastf_f {return txlastf_f((value_ & txlastf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxlastf() const -> rxlastf_f {return rxlastf_f((value_ & rxlastf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fcf() const -> fcf_f {return fcf_f((value_ & fcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxtgtendf() const -> rxtgtendf_f {return rxtgtendf_f((value_ & rxtgtendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto errf() const -> errf_f {return errf_f((value_ & errf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ibif() const -> ibif_f {return ibif_f((value_ & ibif_f::mask) != 0);}
	[[nodiscard]] constexpr auto ibiendf() const -> ibiendf_f {return ibiendf_f((value_ & ibiendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crf() const -> crf_f {return crf_f((value_ & crf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crupdf() const -> crupdf_f {return crupdf_f((value_ & crupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto hjf() const -> hjf_f {return hjf_f((value_ & hjf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkpf() const -> wkpf_f {return wkpf_f((value_ & wkpf_f::mask) != 0);}
	[[nodiscard]] constexpr auto getf() const -> getf_f {return getf_f((value_ & getf_f::mask) != 0);}
	[[nodiscard]] constexpr auto staf() const -> staf_f {return staf_f((value_ & staf_f::mask) != 0);}
	[[nodiscard]] constexpr auto daupdf() const -> daupdf_f {return daupdf_f((value_ & daupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto mwlupdf() const -> mwlupdf_f {return mwlupdf_f((value_ & mwlupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto mrlupdf() const -> mrlupdf_f {return mrlupdf_f((value_ & mrlupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstf() const -> rstf_f {return rstf_f((value_ & rstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto asupdf() const -> asupdf_f {return asupdf_f((value_ & asupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto intupdf() const -> intupdf_f {return intupdf_f((value_ & intupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto deff() const -> deff_f {return deff_f((value_ & deff_f::mask) != 0);}
	[[nodiscard]] constexpr auto grpf() const -> grpf_f {return grpf_f((value_ & grpf_f::mask) != 0);}

	constexpr i3c_evr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_evr_r other) const -> i3c_evr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_evr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11; // 3 0x3

private:
	uint32_t value_;
};

/**
 * I3C interrupt enable register 
 */
class i3c_ier_r {
public:

/**
 * C-FIFO not full interrupt enable (whatever the I3C is acting as controller/target)
 */
class cfnfie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cfnfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * S-FIFO not empty interrupt enable (whatever the I3C is acting as controller/target)
 */
class sfneie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sfneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX-FIFO not full interrupt enable (whatever the I3C is acting as controller/target)
 */
class txfnfie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX-FIFO not empty interrupt enable (whatever the I3C is acting as controller/target)
 */
class rxfneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * frame complete interrupt enable (whatever the I3C is acting as controller/target)
 */
class fcie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * target-initiated read end interrupt enable (when the I3C is acting as controller)
 */
class rxtgtendie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxtgtendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * error interrupt enable (whatever the I3C is acting as controller/target)
 */
class errie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IBI request interrupt enable (when the I3C is acting as controller)
 */
class ibiie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ibiie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IBI end interrupt enable (when the I3C is acting as target)
 */
class ibiendie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ibiendie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role request interrupt enable (when the I3C is acting as controller)
 */
class crie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role update interrupt enable (when the I3C is acting as target)
 */
class crupdie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * hot-join interrupt enable (when the I3C is acting as controller)
 */
class hjie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hjie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wakeup interrupt enable (when the I3C is acting as target)
 */
class wkpie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wkpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GETxxx CCC interrupt enable (when the I3C is acting as target)
 */
class getie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr getie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * GETSTATUS CCC interrupt enable (when the I3C is acting as target)
 */
class staie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr staie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ENTDAA/RSTDAA/SETNEWDA CCC interrupt enable (when the I3C is acting as target)
 */
class daupdie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr daupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SETMWL CCC interrupt enable (when the I3C is acting as target)
 */
class mwlupdie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mwlupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SETMRL CCC interrupt enable (when the I3C is acting as target)
 */
class mrlupdie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mrlupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * reset pattern interrupt enable (when the I3C is acting as target)
 */
class rstie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rstie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ENTASx CCC interrupt enable (when the I3C is acting as target)
 */
class asupdie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr asupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ENEC/DISEC CCC interrupt enable (when the I3C is acting as target)
 */
class intupdie_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr intupdie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DEFTGTS CCC interrupt enable (when the I3C is acting as target)
 */
class defie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr defie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DEFGRPA CCC interrupt enable (when the I3C is acting as target)
 */
class grpie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr grpie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_ier_r>() const {return opsy::utility::clear_set<i3c_ier_r>(mask, *this);}
	constexpr auto operator|(i3c_ier_r other) const -> i3c_ier_r { return static_cast<i3c_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_ier_r> other) const -> opsy::utility::clear_set<i3c_ier_r> {return opsy::utility::clear_set<i3c_ier_r>(i3c_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cfnfie() const -> cfnfie_f {return cfnfie_f((value_ & cfnfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto sfneie() const -> sfneie_f {return sfneie_f((value_ & sfneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnfie() const -> txfnfie_f {return txfnfie_f((value_ & txfnfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfneie() const -> rxfneie_f {return rxfneie_f((value_ & rxfneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto fcie() const -> fcie_f {return fcie_f((value_ & fcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxtgtendie() const -> rxtgtendie_f {return rxtgtendie_f((value_ & rxtgtendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ibiie() const -> ibiie_f {return ibiie_f((value_ & ibiie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ibiendie() const -> ibiendie_f {return ibiendie_f((value_ & ibiendie_f::mask) != 0);}
	[[nodiscard]] constexpr auto crie() const -> crie_f {return crie_f((value_ & crie_f::mask) != 0);}
	[[nodiscard]] constexpr auto crupdie() const -> crupdie_f {return crupdie_f((value_ & crupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hjie() const -> hjie_f {return hjie_f((value_ & hjie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkpie() const -> wkpie_f {return wkpie_f((value_ & wkpie_f::mask) != 0);}
	[[nodiscard]] constexpr auto getie() const -> getie_f {return getie_f((value_ & getie_f::mask) != 0);}
	[[nodiscard]] constexpr auto staie() const -> staie_f {return staie_f((value_ & staie_f::mask) != 0);}
	[[nodiscard]] constexpr auto daupdie() const -> daupdie_f {return daupdie_f((value_ & daupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mwlupdie() const -> mwlupdie_f {return mwlupdie_f((value_ & mwlupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mrlupdie() const -> mrlupdie_f {return mrlupdie_f((value_ & mrlupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstie() const -> rstie_f {return rstie_f((value_ & rstie_f::mask) != 0);}
	[[nodiscard]] constexpr auto asupdie() const -> asupdie_f {return asupdie_f((value_ & asupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto intupdie() const -> intupdie_f {return intupdie_f((value_ & intupdie_f::mask) != 0);}
	[[nodiscard]] constexpr auto defie() const -> defie_f {return defie_f((value_ & defie_f::mask) != 0);}
	[[nodiscard]] constexpr auto grpie() const -> grpie_f {return grpie_f((value_ & grpie_f::mask) != 0);}

	constexpr i3c_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_ier_r other) const -> i3c_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C clear event register 
 */
class i3c_cevr_r {
public:

/**
 * clear frame complete flag (whatever the I3C is acting as controller/target)
 */
class cfcf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cfcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear target-initiated read end flag (when the I3C is acting as controller)
 */
class crxtgtendf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr crxtgtendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear error flag (whatever the I3C is acting as controller/target)
 */
class cerrf_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cerrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear IBI request flag (when the I3C is acting as controller)
 */
class cibif_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cibif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear IBI end flag (when the I3C is acting as target)
 */
class cibiendf_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cibiendf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear controller-role request flag (when the I3C is acting as controller)
 */
class ccrf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ccrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear controller-role update flag (when the I3C is acting as target)
 */
class ccrupdf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ccrupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear hot-join flag (when the I3C is acting as controller)
 */
class chjf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr chjf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wakeup flag (when the I3C is acting as target)
 */
class cwkpf_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cwkpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear GETxxx CCC flag (when the I3C is acting as target)
 */
class cgetf_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cgetf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear GETSTATUS CCC flag (when the I3C is acting as target)
 */
class cstaf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cstaf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear ENTDAA/RSTDAA/SETNEWDA CCC flag (when the I3C is acting as target)
 */
class cdaupdf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cdaupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear SETMWL CCC flag (when the I3C is acting as target)
 */
class cmwlupdf_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmwlupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear SETMRL CCC flag (when the I3C is acting as target)
 */
class cmrlupdf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmrlupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear reset pattern flag (when the I3C is acting as target)
 */
class crstf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crstf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear ENTASx CCC flag (when the I3C is acting as target)
 */
class casupdf_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr casupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear ENEC/DISEC CCC flag (when the I3C is acting as target)
 */
class cintupdf_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cintupdf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear DEFTGTS CCC flag (when the I3C is acting as target)
 */
class cdeff_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cdeff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear DEFGRPA CCC flag (when the I3C is acting as target)
 */
class cgrpf_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cgrpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cevr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cevr_r>() const {return opsy::utility::clear_set<i3c_cevr_r>(mask, *this);}
	constexpr auto operator|(i3c_cevr_r other) const -> i3c_cevr_r { return static_cast<i3c_cevr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cevr_r> other) const -> opsy::utility::clear_set<i3c_cevr_r> {return opsy::utility::clear_set<i3c_cevr_r>(i3c_cevr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cfcf() const -> cfcf_f {return cfcf_f((value_ & cfcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crxtgtendf() const -> crxtgtendf_f {return crxtgtendf_f((value_ & crxtgtendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cerrf() const -> cerrf_f {return cerrf_f((value_ & cerrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cibif() const -> cibif_f {return cibif_f((value_ & cibif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cibiendf() const -> cibiendf_f {return cibiendf_f((value_ & cibiendf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccrf() const -> ccrf_f {return ccrf_f((value_ & ccrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccrupdf() const -> ccrupdf_f {return ccrupdf_f((value_ & ccrupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto chjf() const -> chjf_f {return chjf_f((value_ & chjf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwkpf() const -> cwkpf_f {return cwkpf_f((value_ & cwkpf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cgetf() const -> cgetf_f {return cgetf_f((value_ & cgetf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cstaf() const -> cstaf_f {return cstaf_f((value_ & cstaf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdaupdf() const -> cdaupdf_f {return cdaupdf_f((value_ & cdaupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmwlupdf() const -> cmwlupdf_f {return cmwlupdf_f((value_ & cmwlupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmrlupdf() const -> cmrlupdf_f {return cmrlupdf_f((value_ & cmrlupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto crstf() const -> crstf_f {return crstf_f((value_ & crstf_f::mask) != 0);}
	[[nodiscard]] constexpr auto casupdf() const -> casupdf_f {return casupdf_f((value_ & casupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cintupdf() const -> cintupdf_f {return cintupdf_f((value_ & cintupdf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cdeff() const -> cdeff_f {return cdeff_f((value_ & cdeff_f::mask) != 0);}
	[[nodiscard]] constexpr auto cgrpf() const -> cgrpf_f {return cgrpf_f((value_ & cgrpf_f::mask) != 0);}

	constexpr i3c_cevr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_cevr_r other) const -> i3c_cevr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_cevr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C own device characteristics register 
 */
class i3c_devr0_r {
public:

/**
 * dynamic address is valid (when the I3C is acting as target) When the I3C is acting as controller, this field can be written by software, for validating its own dynamic address, for example before a controller-role hand-off. When the I3C is acting as target, this field is asserted by hardware on the acknowledge of the broadcast ENTDAA CCC or the direct SETNEWDA CCC, and this field is cleared by hardware on the acknowledge of the broadcast RSTDAA CCC.
 */
class daval_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr daval_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 7-bit dynamic address When the I3C is acting as controller, this field can be written by software, for defining its own dynamic address. When the I3C is acting as target, this field is updated by hardware on the reception of either the broadcast ENTDAA CCC or the direct SETNEWDA CCC.
 */
class da_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr da_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_devr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * IBI request enable (when the I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0, and is updated by hardware on the reception of DISEC CCC with DISINT=1 (i.e. cleared) and the reception of ENEC CCC with ENINT=1 (i.e. set).
 */
class ibien_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ibien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role request enable (when the I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0, and is updated by hardware on the reception of DISEC CCC with DISCR=1 (i.e. cleared) and the reception of ENEC CCC with ENCR=1 (i.e. set).
 */
class cren_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * hot-join request enable (when the I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0, and is updated by hardware on the reception of DISEC CCC with DISHJ=1 (i.e. cleared) and the reception of ENEC CCC with ENHJ=1 (i.e. set).
 */
class hjen_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr hjen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * activity state (when the I3C is acting as target) This read field is updated by hardware on the reception of a ENTASx CCC (enter activity state, with x=0-3):
 */
class as_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr as_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_devr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * reset action/level on received reset pattern (when the I3C is acting as target) This read field is used by hardware on the reception of a direct read RSTACT CCC in order to return the corresponding data byte on the I3C bus.
 */
class rstact_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rstact_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_devr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * reset action is valid (when the I3C is acting as target) This read bit is asserted by hardware to indicate that the RTSACT[1:0] field has been updated on the reception of a broadcast or direct write RSTACT CCC (target reset action) and is valid. This field is cleared by hardware when the target receives a frame start. If RSTVAL=1: when the RSTF is asserted (and/or the corresponding interrupt if enabled), I3C_DEVR0.RSTACT[1:0] dictates the reset action to be performed by the software if any. If RSTVAL=0: when the RSTF is asserted (and/or the corresponding interrupt if enabled), the software should issue an I3C reset after a first detected reset pattern, and a system reset on the second one.
 */
class rstval_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rstval_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devr0_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devr0_r>() const {return opsy::utility::clear_set<i3c_devr0_r>(mask, *this);}
	constexpr auto operator|(i3c_devr0_r other) const -> i3c_devr0_r { return static_cast<i3c_devr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devr0_r> other) const -> opsy::utility::clear_set<i3c_devr0_r> {return opsy::utility::clear_set<i3c_devr0_r>(i3c_devr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto daval() const -> daval_f {return daval_f((value_ & daval_f::mask) != 0);}
	[[nodiscard]] constexpr auto da() const -> da_f {return da_f(static_cast<uint8_t>(value_ >> da_f::offset));}
	[[nodiscard]] constexpr auto ibien() const -> ibien_f {return ibien_f((value_ & ibien_f::mask) != 0);}
	[[nodiscard]] constexpr auto cren() const -> cren_f {return cren_f((value_ & cren_f::mask) != 0);}
	[[nodiscard]] constexpr auto hjen() const -> hjen_f {return hjen_f((value_ & hjen_f::mask) != 0);}
	[[nodiscard]] constexpr auto as() const -> as_f {return as_f(static_cast<uint8_t>(value_ >> as_f::offset));}
	[[nodiscard]] constexpr auto rstact() const -> rstact_f {return rstact_f(static_cast<uint8_t>(value_ >> rstact_f::offset));}
	[[nodiscard]] constexpr auto rstval() const -> rstval_f {return rstval_f((value_ & rstval_f::mask) != 0);}

	constexpr i3c_devr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_devr0_r other) const -> i3c_devr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_devr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C device X characteristics register
 */
class i3c_devrx_r {
public:

/**
 * assigned I3C dynamic address to target x (when the I3C is acting as controller) When the I3C is acting as controller, this field should be written by software to store the 7-bit dynamic address that the controller sends via a broadcast ENTDAA or a direct SETNEWDA CCC which has been acknowledged by the target x. Writing to this field has no impact when the read field I3C_DEVRx.DIS=1.
 */
class da_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr da_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_devrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * IBI request acknowledge (when the I3C is acting as controller) When the I3C is acting as controller, this bit is written by software to define the acknowledge policy to be applied on the I3C bus on the reception of a IBI request from target x: - After the NACK, the message continues as initially programmed (the target is aware of the NACK and can emit another IBI request later on) - The field DIS is asserted by hardware to protect DA[6:0] from being modified by software meanwhile the hardware can store internally the current DA[6:0] into the kernel clock domain. - After the ACK, the controller logs the IBI payload data, if any, depending on I3C_DEVRx.IBIDEN. - The software is notified by the IBI flag (i.e. I3C_EVR.IBIF=1) and/or the corresponding interrupt if enabled; - Independently from IBIACK configuration for this or other devices, further IBI request(s) are NACKed until IBI request flag (i.e. I3C_EVR.IBIF) and controller-role request flag (i.e. I3C_EVR.CRF) are both cleared.
 */
class ibiack_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ibiack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller-role request acknowledge (when the I3C is acting as controller) When the I3C is acting as controller, this bit is written by software to define the acknowledge policy to be applied on the I3C bus on the reception of a controller-role request from target x: After the NACK, the message continues as initially programmed (the target is aware of the NACK and can emit another controller-role request later on) - The field DIS is asserted by hardware to protect DA[6:0] from being modified by software meanwhile the hardware can store internally the current DA[6:0] into the kernel clock domain. - After the ACK, the message continues as initially programmed. The software is notified by the controller-role request flag (i.e. I3C_EVR.CRF=1) and/or the corresponding interrupt if enabled; For effectively granting the controller-role to the requesting secondary controller, software should issue a GETACCCR (formerly known as GETACCMST), followed by a STOP. - Independently of CRACK configuration for this or other devices, further controller-role request(s) are NACKed until controller-role request flag (i.e. I3C_EVR.CRF) and IBI flag (i.e. I3C_EVR.IBIF) are both cleared.
 */
class crack_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr crack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IBI data enable (when the I3C is acting as controller) When the I3C is acting as controller, this bit should be written by software to store the BCR[2] bit as received from the target x during broadcast ENTDAA or direct GETBCR CCC via the received I3C_RDR. Writing to this field has no impact when the read field I3C_DEVRx.DIS=1.
 */
class ibiden_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ibiden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * suspend/stop I3C transfer on received IBI (when the I3C is acting as controller) When the I3C is acting as controller, this bit is used to receive an IBI from target x with pending read notification feature (i.e. with received MDB[7:5]=3'b101). If this bit is set, when an IBI is received (i.e. I3C_EVR.IBIF=1), a Stop is emitted on the I3C bus and the C-FIFO is automatically flushed by hardware; to avoid a next private read communication issue if a previous private read message to the target x was stored in the C-FIFO.
 */
class susp_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr susp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DA[6:0] write disabled (when the I3C is acting as controller) When the I3C is acting as controller, once that software set IBIACK=1 or CRACK=1, this read bit is set by hardware (i.e. DIS=1) to lock the configured DA[6:0] and IBIDEN values. Then, to be able to next modify DA[6:0] or IBIDEN, the software must wait for this field DIS to be de-asserted by hardware (i.e. polling on DIS=0) before modifying these two assigned values to the target x. Indeed, the target may be requesting an IBI or a controller-role meanwhile the controller intends to modify DA[6:0] or IBIDEN.
 */
class dis_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_devrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_devrx_r>() const {return opsy::utility::clear_set<i3c_devrx_r>(mask, *this);}
	constexpr auto operator|(i3c_devrx_r other) const -> i3c_devrx_r { return static_cast<i3c_devrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_devrx_r> other) const -> opsy::utility::clear_set<i3c_devrx_r> {return opsy::utility::clear_set<i3c_devrx_r>(i3c_devrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto da() const -> da_f {return da_f(static_cast<uint8_t>(value_ >> da_f::offset));}
	[[nodiscard]] constexpr auto ibiack() const -> ibiack_f {return ibiack_f((value_ & ibiack_f::mask) != 0);}
	[[nodiscard]] constexpr auto crack() const -> crack_f {return crack_f((value_ & crack_f::mask) != 0);}
	[[nodiscard]] constexpr auto ibiden() const -> ibiden_f {return ibiden_f((value_ & ibiden_f::mask) != 0);}
	[[nodiscard]] constexpr auto susp() const -> susp_f {return susp_f((value_ & susp_f::mask) != 0);}
	[[nodiscard]] constexpr auto dis() const -> dis_f {return dis_f((value_ & dis_f::mask) != 0);}

	constexpr i3c_devrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_devrx_r other) const -> i3c_devrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_devrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C maximum read length register 
 */
class i3c_maxrlr_r {
public:

/**
 * maximum data read length (when I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0 and updated by hardware on the reception of SETMRL command (with potentially also updated IBIP[2:0]). Software is notified of a MRL update by the I3C_EVR.MRLUPF and the corresponding interrupt if enabled. This field is used by hardware to return the value on the I3C bus when the target receives a GETMRL CCC.
 */
class mrl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mrl_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_maxrlr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_maxrlr_r>() const {return opsy::utility::clear_set<i3c_maxrlr_r>(mask, *this);}
	constexpr auto operator|(i3c_maxrlr_r other) const -> i3c_maxrlr_r { return static_cast<i3c_maxrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_maxrlr_r> other) const -> opsy::utility::clear_set<i3c_maxrlr_r> {return opsy::utility::clear_set<i3c_maxrlr_r>(i3c_maxrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * IBI payload data size, in bytes (when I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0 to set the number of data bytes to be sent to the controller after an IBI request has been acknowledged.This field may be updated by hardware on the reception of SETMRL command (which potentially also updated IBIP[2:0]). Software is notified of a MRL update by the I3C_EVR.MRLUPF and the corresponding interrupt if enabled. others: same as 100
 */
class ibip_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ibip_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_maxrlr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_maxrlr_r>() const {return opsy::utility::clear_set<i3c_maxrlr_r>(mask, *this);}
	constexpr auto operator|(i3c_maxrlr_r other) const -> i3c_maxrlr_r { return static_cast<i3c_maxrlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_maxrlr_r> other) const -> opsy::utility::clear_set<i3c_maxrlr_r> {return opsy::utility::clear_set<i3c_maxrlr_r>(i3c_maxrlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto mrl() const -> mrl_f {return mrl_f(static_cast<uint16_t>(value_ >> mrl_f::offset));}
	[[nodiscard]] constexpr auto ibip() const -> ibip_f {return ibip_f(static_cast<uint8_t>(value_ >> ibip_f::offset));}

	constexpr i3c_maxrlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_maxrlr_r other) const -> i3c_maxrlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_maxrlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C maximum write length register 
 */
class i3c_maxwlr_r {
public:

/**
 * maximum data write length (when I3C is acting as target) This field is initially written by software when I3C_CFGR.EN=0 and updated by hardware on the reception of SETMWL command. Software is notified of a MWL update by the I3C_EVR.MWLUPF and the corresponding interrupt if enabled. This field is used by hardware to return the value on the I3C bus when the target receives a GETMWL CCC.
 */
class mwl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mwl_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_maxwlr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_maxwlr_r>() const {return opsy::utility::clear_set<i3c_maxwlr_r>(mask, *this);}
	constexpr auto operator|(i3c_maxwlr_r other) const -> i3c_maxwlr_r { return static_cast<i3c_maxwlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_maxwlr_r> other) const -> opsy::utility::clear_set<i3c_maxwlr_r> {return opsy::utility::clear_set<i3c_maxwlr_r>(i3c_maxwlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto mwl() const -> mwl_f {return mwl_f(static_cast<uint16_t>(value_ >> mwl_f::offset));}

	constexpr i3c_maxwlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_maxwlr_r other) const -> i3c_maxwlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_maxwlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C timing register 0 
 */
class i3c_timingr0_r {
public:

/**
 * SCL low duration in I3C push-pull phases, in number of kernel clocks cycles: tSCLL_PP = (SCLL_PP + 1) x tI3CCLK SCLL_PP is used to generate tLOW (I3C) timing.
 */
class scll_pp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr scll_pp_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr0_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr0_r>() const {return opsy::utility::clear_set<i3c_timingr0_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr0_r other) const -> i3c_timingr0_r { return static_cast<i3c_timingr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr0_r> other) const -> opsy::utility::clear_set<i3c_timingr0_r> {return opsy::utility::clear_set<i3c_timingr0_r>(i3c_timingr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SCL high duration, used for I3C messages (both in push-pull and open-drain phases), in number of kernel clocks cycles: tSCLH_I3C = (SCLH_I3C + 1) x tI3CCLK SCLH_I3C is used to generate both tHIGH (I3C) and tHIGH_MIXED timings.
 */
class sclh_i3c_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sclh_i3c_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr0_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr0_r>() const {return opsy::utility::clear_set<i3c_timingr0_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr0_r other) const -> i3c_timingr0_r { return static_cast<i3c_timingr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr0_r> other) const -> opsy::utility::clear_set<i3c_timingr0_r> {return opsy::utility::clear_set<i3c_timingr0_r>(i3c_timingr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SCL low duration in open-drain phases, used for legacy I2C commands and for I3C open-drain phases (address header phase following a START, not a Repeated START), in number of kernel clocks cycles: tSCLL_OD = (SCLL_OD + 1) x tI3CCLK SCLL_OD is used to generate both tLOW (I2C) and tLOW_OD timings (max. of the two).
 */
class scll_od_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr scll_od_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr0_r>() const {return opsy::utility::clear_set<i3c_timingr0_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr0_r other) const -> i3c_timingr0_r { return static_cast<i3c_timingr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr0_r> other) const -> opsy::utility::clear_set<i3c_timingr0_r> {return opsy::utility::clear_set<i3c_timingr0_r>(i3c_timingr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SCL high duration, used for legacy I2C commands, in number of kernel clocks cycles: tSCLH_I2C = (SCLH_I2C + 1) x tI3CCLK SCLH_I2C is used to generate tHIGH (I2C) timing.
 */
class sclh_i2c_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sclh_i2c_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr0_r>() const {return opsy::utility::clear_set<i3c_timingr0_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr0_r other) const -> i3c_timingr0_r { return static_cast<i3c_timingr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr0_r> other) const -> opsy::utility::clear_set<i3c_timingr0_r> {return opsy::utility::clear_set<i3c_timingr0_r>(i3c_timingr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto scll_pp() const -> scll_pp_f {return scll_pp_f(static_cast<uint8_t>(value_ >> scll_pp_f::offset));}
	[[nodiscard]] constexpr auto sclh_i3c() const -> sclh_i3c_f {return sclh_i3c_f(static_cast<uint8_t>(value_ >> sclh_i3c_f::offset));}
	[[nodiscard]] constexpr auto scll_od() const -> scll_od_f {return scll_od_f(static_cast<uint8_t>(value_ >> scll_od_f::offset));}
	[[nodiscard]] constexpr auto sclh_i2c() const -> sclh_i2c_f {return sclh_i2c_f(static_cast<uint8_t>(value_ >> sclh_i2c_f::offset));}

	constexpr i3c_timingr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_timingr0_r other) const -> i3c_timingr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_timingr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C timing register 1 
 */
class i3c_timingr1_r {
public:

/**
 * number of kernel clock cycles, that is used whatever I3C is acting as controller or target, to set the following MIPI I3C timings, like bus available condition time: When the I3C is acting as target: for bus available condition time: it must wait for (bus available condition) time to be elapsed after a stop and before issuing a start request for an IBI or a controller-role request (i.e. bus free condition is sustained for at least tAVAL). refer to MIPI timing tAVAL = 1 s. This timing is defined by: tAVAL = (AVAL[7:0] + 2) x tI3CCLK for bus idle condition time: it must wait for (bus idle condition) time to be elapsed after that both SDA and SCL are continuously high and stable before issuing a hot-join event. Refer to MIPI v1.1 timing tIDLE = 200 s . This timing is defined by: tIDLE = (AVAL[7:0] + 2) x 200 x tI3CCLK When the I3C is acting as controller, it can not stall the clock beyond a maximum stall time (i.e. stall the SCL clock low), as follows: on first bit of assigned address during dynamic address assignment: it can not stall the clock beyond the MIPI timing tSTALLDAA = 15 ms. This timing is defined by: tSTALLDAA = (AVAL[7:0] + 1) x 15000 x tI3CCLK on ACK/NACK phase of I3C/I2C transfer, on parity bit of write data transfer, on transition bit of I3C read transfer: it can not stall the clock beyond the MIPI timing tSTALL = 100 s. This timing is defined by: tSTALL = (AVAL[7:0] + 1) x 100 x tI3CCLK Whatever the I3C is acting as controller or as (controller-capable) target, during a controller-role hand-off procedure: The new controller must wait for a time (refer to MIPI timing tNEWCRLock) before pulling SDA low (i.e. issuing a start). And the active controller must wait for the same time while monitoring new controller and before testing the new controller by pulling SDA low. This time to wait is dependent on the defined I3C_TIMINGR1.ANSCR[1:0], as follows: If ASNCR[1:0]=00: tNEWCRLock = (AVAL[7:0] + 1) x tI3CCLK If ASNCR[1:0]=01: tNEWCRLock = (AVAL[7:0] + 1) x 100 x tI3CCLK If ASNCR[1:0]=10: tNEWCRLock = (AVAL[7:0] + 1) x 2000 x tI3CCLK If ASNCR[1:0]=11: tNEWCRLock = (AVAL[7:0] + 1) x 50000 x tI3CCLK
 */
class aval_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr aval_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr1_r>() const {return opsy::utility::clear_set<i3c_timingr1_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr1_r other) const -> i3c_timingr1_r { return static_cast<i3c_timingr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr1_r> other) const -> opsy::utility::clear_set<i3c_timingr1_r> {return opsy::utility::clear_set<i3c_timingr1_r>(i3c_timingr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * activity state of the new controller (when I3C is acting asactive- controller) This field indicates the time to wait before being accessed as new target, refer to the other field AVAL[7:0]. This field can be modified only when the I3C is acting as controller.
 */
class asncr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr asncr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr1_r>() const {return opsy::utility::clear_set<i3c_timingr1_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr1_r other) const -> i3c_timingr1_r { return static_cast<i3c_timingr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr1_r> other) const -> opsy::utility::clear_set<i3c_timingr1_r> {return opsy::utility::clear_set<i3c_timingr1_r>(i3c_timingr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * number of kernel clocks cycles that is used to set some MIPI timings like bus free condition time (when the I3C is acting as controller) When the I3C is acting as controller: for I3C start timing: it must wait for (bus free condition) time to be elapsed after a stop and before a start, refer to MIPI timings (I3C) tCAS and (I2C) tBUF. These timings are defined by: tBUF= tCAS = [ (FREE[6:0] + 1) x 2(0,5 + SDA_HD)] x tI3CCLK Note: for pure I3C bus: tCASmin= 38,4 ns. Note: for pure I3C bus: tCASmax=1s, 100s, 2ms, 50ms for respectively ENTAS0,1,2, and 3. Note: for mixed bus with I2C fm+ device: tBUFmin = 0,5 s. Note: for mixed bus with I2C fm device: tBUFmin = 1,3 s. for I3C repeated start timing: it must wait for time to be elapsed after a repeated start (i.e. SDA is de-asserted) and before driving SCL low, refer to. MIPI timing tCASr. This timing is defined by: tCASr = [ (FREE[6:0] + 1) x 2(0,5 + SDA_HD)] x tI3CCLK for I3C stop timing: it must wait for time to be elapsed after that the SCL clock is driven high and before the stop condition (i.e. SDA is asserted). This timing is defined by: tCBP = (FREE[6:0] + 1) x tI3CCLK for I3C repeated start timing (T-bit when controller ends read with repeated start followed by stop): it must wait for time to be elapsed after that the SCL clock is driven high and before the repeated start condition (i.e. SDA is de-asserted). This timing is defined by: tCBSr = (FREE[6:0] + 1) x tI3CCLK
 */
class free_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr free_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr1_r>() const {return opsy::utility::clear_set<i3c_timingr1_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr1_r other) const -> i3c_timingr1_r { return static_cast<i3c_timingr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr1_r> other) const -> opsy::utility::clear_set<i3c_timingr1_r> {return opsy::utility::clear_set<i3c_timingr1_r>(i3c_timingr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SDA hold time (when the I3C is acting as controller), in number of kernel clocks cycles (refer to MIPI timing SDA hold time in push-pull tHD_PP):
 */
class sda_hd_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sda_hd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_timingr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_timingr1_r>() const {return opsy::utility::clear_set<i3c_timingr1_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr1_r other) const -> i3c_timingr1_r { return static_cast<i3c_timingr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr1_r> other) const -> opsy::utility::clear_set<i3c_timingr1_r> {return opsy::utility::clear_set<i3c_timingr1_r>(i3c_timingr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto aval() const -> aval_f {return aval_f(static_cast<uint8_t>(value_ >> aval_f::offset));}
	[[nodiscard]] constexpr auto asncr() const -> asncr_f {return asncr_f(static_cast<uint8_t>(value_ >> asncr_f::offset));}
	[[nodiscard]] constexpr auto free() const -> free_f {return free_f(static_cast<uint8_t>(value_ >> free_f::offset));}
	[[nodiscard]] constexpr auto sda_hd() const -> sda_hd_f {return sda_hd_f((value_ & sda_hd_f::mask) != 0);}

	constexpr i3c_timingr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_timingr1_r other) const -> i3c_timingr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_timingr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C timing register 2 
 */
class i3c_timingr2_r {
public:

/**
 * Controller clock stall on T-bit phase of Data enable The SCL is stalled during STALL x tSCLL_PP in the T-bit phase (before 9th bit). This allows the target to prepare data to be sent.
 */
class stallt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stallt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_timingr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_timingr2_r>() const {return opsy::utility::clear_set<i3c_timingr2_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr2_r other) const -> i3c_timingr2_r { return static_cast<i3c_timingr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr2_r> other) const -> opsy::utility::clear_set<i3c_timingr2_r> {return opsy::utility::clear_set<i3c_timingr2_r>(i3c_timingr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller clock stall on PAR phase of Data enable The SCL is stalled during STALL x tSCLL_PP in the T-bit phase (before 9th bit). This allows the target to read received data.
 */
class stalld_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stalld_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_timingr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_timingr2_r>() const {return opsy::utility::clear_set<i3c_timingr2_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr2_r other) const -> i3c_timingr2_r { return static_cast<i3c_timingr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr2_r> other) const -> opsy::utility::clear_set<i3c_timingr2_r> {return opsy::utility::clear_set<i3c_timingr2_r>(i3c_timingr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller clock stall on PAR phase of CCC enable The SCL is stalled during STALL x tSCLL_PP in the T-bit phase of common command code (before 9th bit). This allows the target to decode the command.
 */
class stallc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stallc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_timingr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_timingr2_r>() const {return opsy::utility::clear_set<i3c_timingr2_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr2_r other) const -> i3c_timingr2_r { return static_cast<i3c_timingr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr2_r> other) const -> opsy::utility::clear_set<i3c_timingr2_r> {return opsy::utility::clear_set<i3c_timingr2_r>(i3c_timingr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller clock stall enable on ACK phase The SCL is stalled (during tSCLL_STALLas defined by STALL) in the address ACK/NACK phase (before 9th bit). This allows the target to prepare data or the controller to respond to target interrupt.
 */
class stalla_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stalla_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_timingr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_timingr2_r>() const {return opsy::utility::clear_set<i3c_timingr2_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr2_r other) const -> i3c_timingr2_r { return static_cast<i3c_timingr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr2_r> other) const -> opsy::utility::clear_set<i3c_timingr2_r> {return opsy::utility::clear_set<i3c_timingr2_r>(i3c_timingr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller clock stall time, in number of kernel clock cycles tSCLL_STALL = STALL x tI3CCLK
 */
class stall_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr stall_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_timingr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_timingr2_r>() const {return opsy::utility::clear_set<i3c_timingr2_r>(mask, *this);}
	constexpr auto operator|(i3c_timingr2_r other) const -> i3c_timingr2_r { return static_cast<i3c_timingr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_timingr2_r> other) const -> opsy::utility::clear_set<i3c_timingr2_r> {return opsy::utility::clear_set<i3c_timingr2_r>(i3c_timingr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto stallt() const -> stallt_f {return stallt_f((value_ & stallt_f::mask) != 0);}
	[[nodiscard]] constexpr auto stalld() const -> stalld_f {return stalld_f((value_ & stalld_f::mask) != 0);}
	[[nodiscard]] constexpr auto stallc() const -> stallc_f {return stallc_f((value_ & stallc_f::mask) != 0);}
	[[nodiscard]] constexpr auto stalla() const -> stalla_f {return stalla_f((value_ & stalla_f::mask) != 0);}
	[[nodiscard]] constexpr auto stall() const -> stall_f {return stall_f(static_cast<uint8_t>(value_ >> stall_f::offset));}

	constexpr i3c_timingr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_timingr2_r other) const -> i3c_timingr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_timingr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C bus characteristics register 
 */
class i3c_bcr_r {
public:

/**
 * max data speed limitation
 */
class bcr0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bcr0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_bcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_bcr_r>() const {return opsy::utility::clear_set<i3c_bcr_r>(mask, *this);}
	constexpr auto operator|(i3c_bcr_r other) const -> i3c_bcr_r { return static_cast<i3c_bcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_bcr_r> other) const -> opsy::utility::clear_set<i3c_bcr_r> {return opsy::utility::clear_set<i3c_bcr_r>(i3c_bcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * in-band interrupt (IBI) payload
 */
class bcr2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bcr2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_bcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_bcr_r>() const {return opsy::utility::clear_set<i3c_bcr_r>(mask, *this);}
	constexpr auto operator|(i3c_bcr_r other) const -> i3c_bcr_r { return static_cast<i3c_bcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_bcr_r> other) const -> opsy::utility::clear_set<i3c_bcr_r> {return opsy::utility::clear_set<i3c_bcr_r>(i3c_bcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * controller capable
 */
class bcr6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bcr6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_bcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_bcr_r>() const {return opsy::utility::clear_set<i3c_bcr_r>(mask, *this);}
	constexpr auto operator|(i3c_bcr_r other) const -> i3c_bcr_r { return static_cast<i3c_bcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_bcr_r> other) const -> opsy::utility::clear_set<i3c_bcr_r> {return opsy::utility::clear_set<i3c_bcr_r>(i3c_bcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bcr0() const -> bcr0_f {return bcr0_f((value_ & bcr0_f::mask) != 0);}
	[[nodiscard]] constexpr auto bcr2() const -> bcr2_f {return bcr2_f((value_ & bcr2_f::mask) != 0);}
	[[nodiscard]] constexpr auto bcr6() const -> bcr6_f {return bcr6_f((value_ & bcr6_f::mask) != 0);}

	constexpr i3c_bcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_bcr_r other) const -> i3c_bcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_bcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C device characteristics register 
 */
class i3c_dcr_r {
public:

/**
 * device characteristics ID others: ID to describe the type of the I3C sensor/device Note: The latest MIPI DCR ID assignments are available at: https://www.mipi.org/MIPI_I3C_device_characteristics_register
 */
class dcr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dcr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_dcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_dcr_r>() const {return opsy::utility::clear_set<i3c_dcr_r>(mask, *this);}
	constexpr auto operator|(i3c_dcr_r other) const -> i3c_dcr_r { return static_cast<i3c_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_dcr_r> other) const -> opsy::utility::clear_set<i3c_dcr_r> {return opsy::utility::clear_set<i3c_dcr_r>(i3c_dcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dcr() const -> dcr_f {return dcr_f(static_cast<uint8_t>(value_ >> dcr_f::offset));}

	constexpr i3c_dcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_dcr_r other) const -> i3c_dcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_dcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C get capability register 
 */
class i3c_getcapr_r {
public:

/**
 * IBI MDB support for pending read notification This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and indicates the support (or not) of the pending read notification via the IBI MDB[7:0] value. This bit is used to return the GETCAP3 byte in response to the GETCAPS CCC format 1.
 */
class cappend_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cappend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_getcapr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_getcapr_r>() const {return opsy::utility::clear_set<i3c_getcapr_r>(mask, *this);}
	constexpr auto operator|(i3c_getcapr_r other) const -> i3c_getcapr_r { return static_cast<i3c_getcapr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_getcapr_r> other) const -> opsy::utility::clear_set<i3c_getcapr_r> {return opsy::utility::clear_set<i3c_getcapr_r>(i3c_getcapr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cappend() const -> cappend_f {return cappend_f((value_ & cappend_f::mask) != 0);}

	constexpr i3c_getcapr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_getcapr_r other) const -> i3c_getcapr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_getcapr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C controller-role capability register 
 */
class i3c_crcapr_r {
public:

/**
 * delayed controller-role hand-off This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and indicates if this target I3C may need additional time to process a controller-role hand-off requested by the current controller. This bit is used to return the CRCAP2 byte in response to the GETCAPS CCC format 2.
 */
class capdhoff_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr capdhoff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_crcapr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_crcapr_r>() const {return opsy::utility::clear_set<i3c_crcapr_r>(mask, *this);}
	constexpr auto operator|(i3c_crcapr_r other) const -> i3c_crcapr_r { return static_cast<i3c_crcapr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_crcapr_r> other) const -> opsy::utility::clear_set<i3c_crcapr_r> {return opsy::utility::clear_set<i3c_crcapr_r>(i3c_crcapr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * group management support (when acting as controller) This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and indicates if the I3C is able to support group management when it acts as a controller (after controller-role hand-off) via emitted DEFGRPA, RSTGRPA, and SETGRPA CCC. This bit is used to return the CRCAP1 byte in response to the GETCAPS CCC format 2.
 */
class capgrp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr capgrp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_crcapr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_crcapr_r>() const {return opsy::utility::clear_set<i3c_crcapr_r>(mask, *this);}
	constexpr auto operator|(i3c_crcapr_r other) const -> i3c_crcapr_r { return static_cast<i3c_crcapr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_crcapr_r> other) const -> opsy::utility::clear_set<i3c_crcapr_r> {return opsy::utility::clear_set<i3c_crcapr_r>(i3c_crcapr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto capdhoff() const -> capdhoff_f {return capdhoff_f((value_ & capdhoff_f::mask) != 0);}
	[[nodiscard]] constexpr auto capgrp() const -> capgrp_f {return capgrp_f((value_ & capgrp_f::mask) != 0);}

	constexpr i3c_crcapr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_crcapr_r other) const -> i3c_crcapr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_crcapr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C get capability register 
 */
class i3c_getmxdsr_r {
public:

/**
 * controller hand-off activity state This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and indicates in which initial activity state the (other) current controller should expect the I3C bus after a controller-role hand-off to this controller-capable I3C, when returning the defining byte CRHDLY (0x91) to a GETMXDS CCC. This 2-bit field is used to return the CRHDLY1 byte in response to the GETCAPS CCC format 3, in order to state which is the activity state of this I3C when becoming controller after a controller-role hand-off, and consequently the time the former controller should wait before testing this I3C to be confirmed its ownership.
 */
class hoffas_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hoffas_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_getmxdsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_getmxdsr_r>() const {return opsy::utility::clear_set<i3c_getmxdsr_r>(mask, *this);}
	constexpr auto operator|(i3c_getmxdsr_r other) const -> i3c_getmxdsr_r { return static_cast<i3c_getmxdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_getmxdsr_r> other) const -> opsy::utility::clear_set<i3c_getmxdsr_r> {return opsy::utility::clear_set<i3c_getmxdsr_r>(i3c_getmxdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * GETMXDS CCC format
 */
class fmt_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fmt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_getmxdsr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_getmxdsr_r>() const {return opsy::utility::clear_set<i3c_getmxdsr_r>(mask, *this);}
	constexpr auto operator|(i3c_getmxdsr_r other) const -> i3c_getmxdsr_r { return static_cast<i3c_getmxdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_getmxdsr_r> other) const -> opsy::utility::clear_set<i3c_getmxdsr_r> {return opsy::utility::clear_set<i3c_getmxdsr_r>(i3c_getmxdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * programmed byte of the 3-byte MaxRdTurn (maximum read turnaround byte) This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and writes the value of the selected byte (via the FMT[1:0] field) of the 3-byte MaxRdTurn which is returned in response to the GETMXDS CCC format 2 to encode the maximum read turnaround time.
 */
class rdturn_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rdturn_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_getmxdsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_getmxdsr_r>() const {return opsy::utility::clear_set<i3c_getmxdsr_r>(mask, *this);}
	constexpr auto operator|(i3c_getmxdsr_r other) const -> i3c_getmxdsr_r { return static_cast<i3c_getmxdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_getmxdsr_r> other) const -> opsy::utility::clear_set<i3c_getmxdsr_r> {return opsy::utility::clear_set<i3c_getmxdsr_r>(i3c_getmxdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * clock-to-data turnaround time (tSCO) This bit is written by software during bus initialization (i.e. I3C_CFGR.EN=0) and is used to specify the clock-to-data turnaround time tSCO (vs the value of 12 ns). This bit is used by the hardware in response to the GETMXDS CCC to return the encoded clock-to-data turnaround time via the returned MaxRd[5:3] bits.
 */
class tsco_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tsco_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_getmxdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_getmxdsr_r>() const {return opsy::utility::clear_set<i3c_getmxdsr_r>(mask, *this);}
	constexpr auto operator|(i3c_getmxdsr_r other) const -> i3c_getmxdsr_r { return static_cast<i3c_getmxdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_getmxdsr_r> other) const -> opsy::utility::clear_set<i3c_getmxdsr_r> {return opsy::utility::clear_set<i3c_getmxdsr_r>(i3c_getmxdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hoffas() const -> hoffas_f {return hoffas_f(static_cast<uint8_t>(value_ >> hoffas_f::offset));}
	[[nodiscard]] constexpr auto fmt() const -> fmt_f {return fmt_f(static_cast<uint8_t>(value_ >> fmt_f::offset));}
	[[nodiscard]] constexpr auto rdturn() const -> rdturn_f {return rdturn_f(static_cast<uint8_t>(value_ >> rdturn_f::offset));}
	[[nodiscard]] constexpr auto tsco() const -> tsco_f {return tsco_f((value_ & tsco_f::mask) != 0);}

	constexpr i3c_getmxdsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_getmxdsr_r other) const -> i3c_getmxdsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_getmxdsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * I3C extended provisioned ID register 
 */
class i3c_epidr_r {
public:

/**
 * 4-bit MIPI Instance ID This field is written by software to set and identify individually each instance of this I3C IP with a specific number on a single I3C bus. This field represents the bits[15:12] of the 48-bit provisioned ID. Note: The bits[11:0] of the provisioned ID may be 0.
 */
class mipiid_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mipiid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_epidr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_epidr_r>() const {return opsy::utility::clear_set<i3c_epidr_r>(mask, *this);}
	constexpr auto operator|(i3c_epidr_r other) const -> i3c_epidr_r { return static_cast<i3c_epidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_epidr_r> other) const -> opsy::utility::clear_set<i3c_epidr_r> {return opsy::utility::clear_set<i3c_epidr_r>(i3c_epidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * provisioned ID type selector This field is set as 0 i.e. vendor fixed value. This field represents the bit[32] of the 48-bit provisioned ID. Note: The bits[31:16] of the provisioned ID may be 0.
 */
class idtsel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idtsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_epidr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_epidr_r>() const {return opsy::utility::clear_set<i3c_epidr_r>(mask, *this);}
	constexpr auto operator|(i3c_epidr_r other) const -> i3c_epidr_r { return static_cast<i3c_epidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_epidr_r> other) const -> opsy::utility::clear_set<i3c_epidr_r> {return opsy::utility::clear_set<i3c_epidr_r>(i3c_epidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 15-bit MIPI manufacturer ID This read field is the 15-bit STMicroelectronics MIPI ID i.e. 0x0104. This field represents the bits[47:33] of the 48-bit provisioned ID.
 */
class mipimid_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 15;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mipimid_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_epidr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_epidr_r>() const {return opsy::utility::clear_set<i3c_epidr_r>(mask, *this);}
	constexpr auto operator|(i3c_epidr_r other) const -> i3c_epidr_r { return static_cast<i3c_epidr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_epidr_r> other) const -> opsy::utility::clear_set<i3c_epidr_r> {return opsy::utility::clear_set<i3c_epidr_r>(i3c_epidr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto mipiid() const -> mipiid_f {return mipiid_f(static_cast<uint8_t>(value_ >> mipiid_f::offset));}
	[[nodiscard]] constexpr auto idtsel() const -> idtsel_f {return idtsel_f((value_ & idtsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto mipimid() const -> mipimid_f {return mipimid_f(static_cast<uint16_t>(value_ >> mipimid_f::offset));}

	constexpr i3c_epidr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_epidr_r other) const -> i3c_epidr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_epidr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000010000000000000000000; // 34078720 0x2080000

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,i3c_cr_r> i3c_cr;
		opsy::utility::memory<uint32_t,i3c_cr_alternate_r> i3c_cr_alternate;
	};
	opsy::utility::memory<uint32_t,i3c_cfgr_r> i3c_cfgr;
	opsy::utility::padding<8> _p0;
	opsy::utility::memory<uint32_t,i3c_rdr_r> i3c_rdr;
	opsy::utility::memory<uint32_t,i3c_rdwr_r> i3c_rdwr;
	opsy::utility::memory<uint32_t,i3c_tdr_r> i3c_tdr;
	opsy::utility::memory<uint32_t,i3c_tdwr_r> i3c_tdwr;
	opsy::utility::memory<uint32_t,i3c_ibidr_r> i3c_ibidr;
	opsy::utility::memory<uint32_t,i3c_tgttdr_r> i3c_tgttdr;
	opsy::utility::padding<8> _p1;
	opsy::utility::memory<uint32_t,i3c_sr_r> i3c_sr;
	opsy::utility::memory<uint32_t,i3c_ser_r> i3c_ser;
	opsy::utility::padding<8> _p2;
	opsy::utility::memory<uint32_t,i3c_rmr_r> i3c_rmr;
	opsy::utility::padding<12> _p3;
	opsy::utility::memory<uint32_t,i3c_evr_r> i3c_evr;
	opsy::utility::memory<uint32_t,i3c_ier_r> i3c_ier;
	opsy::utility::memory<uint32_t,i3c_cevr_r> i3c_cevr;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,i3c_devr0_r> i3c_devr0;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr1;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr2;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr3;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr4;
	opsy::utility::padding<28> _p5;
	opsy::utility::memory<uint32_t,i3c_maxrlr_r> i3c_maxrlr;
	opsy::utility::memory<uint32_t,i3c_maxwlr_r> i3c_maxwlr;
	opsy::utility::padding<8> _p6;
	opsy::utility::memory<uint32_t,i3c_timingr0_r> i3c_timingr0;
	opsy::utility::memory<uint32_t,i3c_timingr1_r> i3c_timingr1;
	opsy::utility::memory<uint32_t,i3c_timingr2_r> i3c_timingr2;
	opsy::utility::padding<20> _p7;
	opsy::utility::memory<uint32_t,i3c_bcr_r> i3c_bcr;
	opsy::utility::memory<uint32_t,i3c_dcr_r> i3c_dcr;
	opsy::utility::memory<uint32_t,i3c_getcapr_r> i3c_getcapr;
	opsy::utility::memory<uint32_t,i3c_crcapr_r> i3c_crcapr;
	opsy::utility::memory<uint32_t,i3c_getmxdsr_r> i3c_getmxdsr;
	opsy::utility::memory<uint32_t,i3c_epidr_r> i3c_epidr;
};

static_assert(std::is_standard_layout_v<i3c_p>);
static_assert(offsetof(i3c_p, i3c_cr) == 0);
static_assert(offsetof(i3c_p, i3c_cr_alternate) == 0);
static_assert(offsetof(i3c_p, i3c_cfgr) == 4);
static_assert(offsetof(i3c_p, i3c_rdr) == 16);
static_assert(offsetof(i3c_p, i3c_rdwr) == 20);
static_assert(offsetof(i3c_p, i3c_tdr) == 24);
static_assert(offsetof(i3c_p, i3c_tdwr) == 28);
static_assert(offsetof(i3c_p, i3c_ibidr) == 32);
static_assert(offsetof(i3c_p, i3c_tgttdr) == 36);
static_assert(offsetof(i3c_p, i3c_sr) == 48);
static_assert(offsetof(i3c_p, i3c_ser) == 52);
static_assert(offsetof(i3c_p, i3c_rmr) == 64);
static_assert(offsetof(i3c_p, i3c_evr) == 80);
static_assert(offsetof(i3c_p, i3c_ier) == 84);
static_assert(offsetof(i3c_p, i3c_cevr) == 88);
static_assert(offsetof(i3c_p, i3c_devr0) == 96);
static_assert(offsetof(i3c_p, i3c_devr1) == 100);
static_assert(offsetof(i3c_p, i3c_devr2) == 104);
static_assert(offsetof(i3c_p, i3c_devr3) == 108);
static_assert(offsetof(i3c_p, i3c_devr4) == 112);
static_assert(offsetof(i3c_p, i3c_maxrlr) == 144);
static_assert(offsetof(i3c_p, i3c_maxwlr) == 148);
static_assert(offsetof(i3c_p, i3c_timingr0) == 160);
static_assert(offsetof(i3c_p, i3c_timingr1) == 164);
static_assert(offsetof(i3c_p, i3c_timingr2) == 168);
static_assert(offsetof(i3c_p, i3c_bcr) == 192);
static_assert(offsetof(i3c_p, i3c_dcr) == 196);
static_assert(offsetof(i3c_p, i3c_getcapr) == 200);
static_assert(offsetof(i3c_p, i3c_crcapr) == 204);
static_assert(offsetof(i3c_p, i3c_getmxdsr) == 208);
static_assert(offsetof(i3c_p, i3c_epidr) == 212);

inline i3c_p& i3c = *reinterpret_cast<i3c_p*>(0x40005C00);
inline i3c_p& sec_i3c = *reinterpret_cast<i3c_p*>(0x50005C00);

} // STM32H563

