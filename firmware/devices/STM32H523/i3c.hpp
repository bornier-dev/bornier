#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * I3C register block
 */
class i3c_p {
public:

/**
 * I3C message control register
 */
class i3c_cr_r {
public:

/**
 * Count of data to transfer during a read or write message, in bytes (whatever I3C acts as controller/target) 
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
 * Read / non-write message (when I3C acts as controller) 
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
 * 7-bit I3C dynamic / Iless thansup>2less than/sup>C static target address (when I3C acts as controller) 
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
 * Message type (whatever I3C acts as controller/target) 
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
 * Message end type/last message of a frame (when the I3C acts as controller)
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
 * I3C message control register
 */
class i3c_cr_alternate1_r {
public:

/**
 * Count of related data to the CCC command to transfer as CCC defining bytes, or CCC sub-command bytes, or CCC data bytes, in bytes 
 */
class dcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dcnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator i3c_cr_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate1_r>() const {return opsy::utility::clear_set<i3c_cr_alternate1_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate1_r other) const -> i3c_cr_alternate1_r { return static_cast<i3c_cr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate1_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate1_r> {return opsy::utility::clear_set<i3c_cr_alternate1_r>(i3c_cr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * 8-bit CCC code (when I3C acts as controller) 
 */
class ccc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate1_r>() const {return opsy::utility::clear_set<i3c_cr_alternate1_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate1_r other) const -> i3c_cr_alternate1_r { return static_cast<i3c_cr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate1_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate1_r> {return opsy::utility::clear_set<i3c_cr_alternate1_r>(i3c_cr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Message type (when I3C acts as controller) 
 */
class mtype_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mtype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator i3c_cr_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate1_r>() const {return opsy::utility::clear_set<i3c_cr_alternate1_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate1_r other) const -> i3c_cr_alternate1_r { return static_cast<i3c_cr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate1_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate1_r> {return opsy::utility::clear_set<i3c_cr_alternate1_r>(i3c_cr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Message end type/last message of a frame (when I3C acts as controller)
 */
class mend_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mend_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cr_alternate1_r>() const {return opsy::utility::clear_set<i3c_cr_alternate1_r>(mask, *this);}
	constexpr auto operator|(i3c_cr_alternate1_r other) const -> i3c_cr_alternate1_r { return static_cast<i3c_cr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cr_alternate1_r> other) const -> opsy::utility::clear_set<i3c_cr_alternate1_r> {return opsy::utility::clear_set<i3c_cr_alternate1_r>(i3c_cr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dcnt() const -> dcnt_f {return dcnt_f(static_cast<uint16_t>(value_ >> dcnt_f::offset));}
	[[nodiscard]] constexpr auto ccc() const -> ccc_f {return ccc_f(static_cast<uint8_t>(value_ >> ccc_f::offset));}
	[[nodiscard]] constexpr auto mtype() const -> mtype_f {return mtype_f(static_cast<uint8_t>(value_ >> mtype_f::offset));}
	[[nodiscard]] constexpr auto mend() const -> mend_f {return mend_f((value_ & mend_f::mask) != 0);}

	constexpr i3c_cr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(i3c_cr_alternate1_r other) const -> i3c_cr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> i3c_cr_alternate1_r { return ~value_; }
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
 * I3C enable (whatever I3C acts as controller/target) 
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
 * Initial controller/target role 
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
 * No arbitrable header after a start (when I3C acts as a controller) 
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
 * HDR reset pattern enable (when I3C acts as a controller) 
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
 * HDR exit pattern enable (when I3C acts as a controller) 
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
 * High-keeper enable on SDA line (when I3C acts as a controller) 
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
 * Hot-join request acknowledge (when I3C acts as a controller) 
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
 * RX-FIFO DMA request enable (whatever I3C acts as controller/target) 
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
 * RX-FIFO flush (whatever I3C acts as controller/target) 
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
 * RX-FIFO threshold (whatever I3C acts as controller/target) 
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
 * TX-FIFO DMA request enable (whatever I3C acts as controller/target) 
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
 * TX-FIFO flush (whatever I3C acts as controller/target) 
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
 * TX-FIFO threshold (whatever I3C acts as controller/target) 
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
 * S-FIFO DMA request enable (when I3C acts as controller) 
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
 * S-FIFO flush (when I3C acts as controller) 
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
 * S-FIFO enable / status receive mode (when I3C acts as controller) 
 */
class smode_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator i3c_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<i3c_cfgr_r>() const {return opsy::utility::clear_set<i3c_cfgr_r>(mask, *this);}
	constexpr auto operator|(i3c_cfgr_r other) const -> i3c_cfgr_r { return static_cast<i3c_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<i3c_cfgr_r> other) const -> opsy::utility::clear_set<i3c_cfgr_r> {return opsy::utility::clear_set<i3c_cfgr_r>(i3c_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit mode (when I3C acts as controller) 
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
 * C-FIFO DMA request enable (when I3C acts as controller) 
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
 * C-FIFO flush (when I3C acts as controller) 
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
 * Frame transfer set (software trigger) (when I3C acts as controller) 
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
	[[nodiscard]] constexpr auto smode() const -> smode_f {return smode_f((value_ & smode_f::mask) != 0);}
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
 * 8-bit IBI payload data (earliest byte on I3C bus, MDB[7:0] mandatory data byte).
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
 * Transmit data counter, in bytes (when I3C is configured as target) 
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
 * Preload of the TX-FIFO (when I3C is configured as target) 
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
 * Data counter 
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
 * A private read message is ended prematurely by the target (when the I3C acts as controller) 
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
 * Message direction 
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
 * Message identifier/counter of a given frame (when the I3C acts as controller) 
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
 * Protocol error code/type 
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
 * Protocol error
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
 * SCL stall error (when the I3C acts as target)
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
 * RX-FIFO overrun or TX-FIFO underrun 
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
 * C-FIFO underrun or S-FIFO overrun (when the I3C acts as controller) 
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
 * Address not acknowledged (when the I3C is configured as controller) 
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
 * Data not acknowledged (when the I3C acts as controller) 
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
 * Data error (when the I3C acts as controller)
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
 * IBI received payload data count (when the I3C is configured as controller) 
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
 * Received CCC code (when the I3C is configured as target) 
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
 * Received target address (when the I3C is configured as controller) 
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
 * C-FIFO empty flag (whatever the I3C acts as controller) 
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
 * TX-FIFO empty flag (whatever the I3C acts as controller/target) 
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
 * C-FIFO not full flag (when the I3C acts as controller) 
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
 * S-FIFO not empty flag (when the I3C acts as controller) 
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
 * TX-FIFO not full flag (whatever the I3C acts as controller/target) 
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
 * RX-FIFO not empty flag (whatever the I3C acts as controller/target) 
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
 * Last written data byte/word flag (whatever the I3C acts as controller/target) 
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
 * Last read data byte/word flag (when the I3C acts as controller) 
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
 * Frame complete flag (whatever the I3C acts as controller/target) 
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
 * Target-initiated read end flag (when the I3C acts as controller) 
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
 * Flag (whatever the I3C acts as controller/target) 
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
 * IBI flag (when the I3C acts as controller) 
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
 * IBI end flag (when the I3C acts as target) 
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
 * Controller-role request flag (when the I3C acts as controller) 
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
 * Controller-role update flag (when the I3C acts as target) 
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
 * Hot-join flag (when the I3C acts as controller) 
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
 * Wake-up/missed start flag (when the I3C acts as target) 
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
 * Get flag (when the I3C acts as target) 
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
 * Get status flag (when the I3C acts as target) 
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
 * Dynamic address update flag (when the I3C acts as target) 
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
 * Maximum write length update flag (when the I3C acts as target) 
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
 * Maximum read length update flag (when the I3C acts as target) 
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
 * Reset pattern flag (when the I3C acts as target) 
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
 * Activity state update flag (when the I3C acts as target) 
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
 * Interrupt/controller-role/hot-join update flag (when the I3C acts as target) 
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
 * DEFTGTS flag (when the I3C acts as target) 
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
 * Group addressing flag (when the I3C acts as target) 
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
 * C-FIFO not full interrupt enable when the I3C acts as controller
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
 * S-FIFO not empty interrupt enable when the I3C acts as controller
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
 * TX-FIFO not full interrupt enable (whatever the I3C acts as controller/target)
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
 * RX-FIFO not empty interrupt enable (whatever the I3C acts as controller/target)
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
 * frame complete interrupt enable (whatever the I3C acts as controller/target)
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
 * target-initiated read end interrupt enable (when the I3C acts as controller)
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
 * error interrupt enable (whatever the I3C acts as controller/target)
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
 * IBI request interrupt enable (when the I3C acts as controller)
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
 * IBI end interrupt enable (when the I3C acts as target)
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
 * Controller-role request interrupt enable (when the I3C acts as controller)
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
 * Controller-role update interrupt enable (when the I3C acts as target)
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
 * Hot-join interrupt enable (when the I3C acts as controller)
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
 * Wake-up interrupt enable (when the I3C acts as target)
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
 * GETxxx CCC interrupt enable (except GETSTATUS of format 1) (when the I3C acts as target)
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
 * format 1 GETSTATUS CCC interrupt enable (when the I3C acts as target)
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
 * ENTDAA/RSTDAA/SETNEWDA CCC interrupt enable (when the I3C acts as target)
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
 * SETMWL CCC interrupt enable (when the I3C acts as target)
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
 * SETMRL CCC interrupt enable (when the I3C acts as target)
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
 * reset pattern interrupt enable (when the I3C acts as target)
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
 * ENTASx CCC interrupt enable (when the I3C acts as target)
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
 * ENEC/DISEC CCC interrupt enable (when the I3C acts as target)
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
 * DEFTGTS CCC interrupt enable (when the I3C acts as target)
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
 * DEFGRPA CCC interrupt enable (when the I3C acts as target)
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
 * Clear frame complete flag (whatever the I3C acts as controller/target)
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
 * Clear target-initiated read end flag (when the I3C acts as controller)
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
 * Clear error flag (whatever the I3C acts as controller/target)
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
 * Clear IBI request flag (when the I3C acts as controller)
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
 * Clear IBI end flag (when the I3C acts as target)
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
 * Clear controller-role request flag (when the I3C acts as controller)
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
 * Clear controller-role update flag (when the I3C acts as target)
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
 * Clear hot-join flag (when the I3C acts as controller)
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
 * Clear wake-up flag (when the I3C acts as target)
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
 * Clear GETxxx CCC flag (except GETSTATUS of format 1) (when the I3C acts as target)
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
 * Clear format 1 GETSTATUS CCC flag (when the I3C acts as target)
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
 * Clear ENTDAA/RSTDAA/SETNEWDA CCC flag (when the I3C acts as target)
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
 * Clear SETMWL CCC flag (when the I3C acts as target)
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
 * Clear SETMRL CCC flag (when the I3C acts as target)
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
 * Clear reset pattern flag (when the I3C acts as target)
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
 * Clear ENTASx CCC flag (when the I3C acts as target)
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
 * Clear ENEC/DISEC CCC flag (when the I3C acts as target)
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
 * Clear DEFTGTS CCC flag (when the I3C acts as target)
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
 * Clear DEFGRPA CCC flag (when the I3C acts as target)
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
 * Dynamic address is valid (when the I3C acts as target) 
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
 * 7-bit dynamic address 
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
 * IBI request enable (when the I3C acts as target) 
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
 * Controller-role request enable (when the I3C acts as target) 
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
 * Hot-join request enable (when the I3C acts as target) 
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
 * Activity state (when the I3C acts as target) 
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
 * Reset action/level on received reset pattern (when the I3C acts as target) 
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
 * Reset action is valid (when the I3C acts as target) 
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
 * Assigned I3C dynamic address to target x (when the I3C acts as controller) 
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
 * IBI request acknowledge (when the I3C acts as controller) 
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
 * Controller-role request acknowledge (when the I3C acts as controller) 
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
 * IBI data enable (when the I3C acts as controller) 
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
 * Suspend/stop I3C transfer on received IBI (when the I3C acts as controller) 
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
 * DA[6:0] write disabled (when the I3C acts as controller) 
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
 * Maximum data read length (when I3C acts as target) 
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
 * IBI payload data maximum size, in bytes (when I3C acts as target) 
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
 * Maximum data write length (when I3C acts as target) 
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
 * SCL low duration in I3C push-pull phases, in number of kernel clocks cycles: 
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
 * SCL high duration, used for I3C messages (both in push-pull and open-drain phases), in number of kernel clocks cycles: 
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
 * SCL low duration in open-drain phases, used for legacy Iless thansup>2less than/sup>C messages and for I3C open-drain phases (address phase following a start, ACK phase during controller-initiated messages, and T bit phase during direct/private/IBI payload), in number of kernel clocks cycles: 
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
 * SCL high duration, used for legacy Iless thansup>2less than/sup>C messages, in number of kernel clocks cycles: 
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
 * Number of kernel clock cycles to set a time unit of 1 s, whatever I3C acts as controller or target.
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
 * Activity state of the new controller (when I3C acts as active controller) 
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
 * Number of kernel clocks cycles that is used to set some MIPI timings like bus free condition time (when the I3C acts as controller) 
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
 * SDA hold time (when the I3C acts as controller), in number of kernel clocks cycles (refer to MIPI timing SDA hold time in push-pull tless thansub>HD_PPless than/sub>): 
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
 * Controller clock stall enable on T-bit phase of data (and on the ACK/NACK phase of data byte of a legacy Iless thansup>2less than/sup>C read) 
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
 * Controller clock stall enable on PAR phase of Data 
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
 * Controller clock stall enable on PAR phase of CCC 
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
 * Controller clock stall enable on ACK phase 
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
 * Controller clock stall time, in number of kernel clock cycles 
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
 * Controller capable
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
 * device characteristics ID 
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
 * IBI MDB support for pending read notification 
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
 * delayed controller-role hand-off 
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
 * group management support (when acting as controller) 
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
 * I3C get max data speed register
 */
class i3c_getmxdsr_r {
public:

/**
 * Controller hand-off activity state 
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
 * programmed byte of the 3-byte MaxRdTurn (maximum read turnaround byte) 
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
 * clock-to-data turnaround time (tless thansub>SCOless than/sub>) 
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
 * 4-bit MIPI Instance ID 
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
 * provisioned ID type selector 
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
 * 15-bit MIPI manufacturer ID 
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
		opsy::utility::write_only_memory<uint32_t,i3c_cr_r> i3c_cr;
		opsy::utility::write_only_memory<uint32_t,i3c_cr_alternate1_r> i3c_cr_alternate1;
	};
	opsy::utility::memory<uint32_t,i3c_cfgr_r> i3c_cfgr;
	opsy::utility::padding<8> _p8;
	opsy::utility::read_only_memory<uint32_t,i3c_rdr_r> i3c_rdr;
	opsy::utility::read_only_memory<uint32_t,i3c_rdwr_r> i3c_rdwr;
	opsy::utility::write_only_memory<uint32_t,i3c_tdr_r> i3c_tdr;
	opsy::utility::write_only_memory<uint32_t,i3c_tdwr_r> i3c_tdwr;
	opsy::utility::memory<uint32_t,i3c_ibidr_r> i3c_ibidr;
	opsy::utility::memory<uint32_t,i3c_tgttdr_r> i3c_tgttdr;
	opsy::utility::padding<8> _p40;
	opsy::utility::read_only_memory<uint32_t,i3c_sr_r> i3c_sr;
	opsy::utility::read_only_memory<uint32_t,i3c_ser_r> i3c_ser;
	opsy::utility::padding<8> _p56;
	opsy::utility::read_only_memory<uint32_t,i3c_rmr_r> i3c_rmr;
	opsy::utility::padding<12> _p68;
	opsy::utility::read_only_memory<uint32_t,i3c_evr_r> i3c_evr;
	opsy::utility::read_only_memory<uint32_t,i3c_ier_r> i3c_ier;
	opsy::utility::write_only_memory<uint32_t,i3c_cevr_r> i3c_cevr;
	opsy::utility::padding<4> _p92;
	opsy::utility::memory<uint32_t,i3c_devr0_r> i3c_devr0;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr1;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr2;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr3;
	opsy::utility::memory<uint32_t,i3c_devrx_r> i3c_devr4;
	opsy::utility::padding<28> _p116;
	opsy::utility::memory<uint32_t,i3c_maxrlr_r> i3c_maxrlr;
	opsy::utility::memory<uint32_t,i3c_maxwlr_r> i3c_maxwlr;
	opsy::utility::padding<8> _p152;
	opsy::utility::memory<uint32_t,i3c_timingr0_r> i3c_timingr0;
	opsy::utility::memory<uint32_t,i3c_timingr1_r> i3c_timingr1;
	opsy::utility::memory<uint32_t,i3c_timingr2_r> i3c_timingr2;
	opsy::utility::padding<20> _p172;
	opsy::utility::memory<uint32_t,i3c_bcr_r> i3c_bcr;
	opsy::utility::memory<uint32_t,i3c_dcr_r> i3c_dcr;
	opsy::utility::memory<uint32_t,i3c_getcapr_r> i3c_getcapr;
	opsy::utility::memory<uint32_t,i3c_crcapr_r> i3c_crcapr;
	opsy::utility::memory<uint32_t,i3c_getmxdsr_r> i3c_getmxdsr;
	opsy::utility::memory<uint32_t,i3c_epidr_r> i3c_epidr;
};

static_assert(std::is_standard_layout_v<i3c_p>);
static_assert(offsetof(i3c_p, i3c_cr) == 0);
static_assert(offsetof(i3c_p, i3c_cr_alternate1) == 0);
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
inline i3c_p& i3c_s = *reinterpret_cast<i3c_p*>(0x50005C00);
inline i3c_p& i3c2 = *reinterpret_cast<i3c_p*>(0x44003000);
inline i3c_p& i3c2_s = *reinterpret_cast<i3c_p*>(0x54003000);

} // STM32H523

