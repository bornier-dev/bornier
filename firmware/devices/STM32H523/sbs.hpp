#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * SBS address block description
 */
class sbs_p {
public:

/**
 * SBS temporal isolation control register
 */
class sbs_hdplcr_r {
public:

/**
 * increment HDPL value 
 */
class incr_hdpl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr incr_hdpl_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_hdplcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_hdplcr_r>() const {return opsy::utility::clear_set<sbs_hdplcr_r>(mask, *this);}
	constexpr auto operator|(sbs_hdplcr_r other) const -> sbs_hdplcr_r { return static_cast<sbs_hdplcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_hdplcr_r> other) const -> opsy::utility::clear_set<sbs_hdplcr_r> {return opsy::utility::clear_set<sbs_hdplcr_r>(sbs_hdplcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto incr_hdpl() const -> incr_hdpl_f {return incr_hdpl_f(static_cast<uint8_t>(value_ >> incr_hdpl_f::offset));}

	constexpr sbs_hdplcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_hdplcr_r other) const -> sbs_hdplcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_hdplcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10110100; // 180 0xB4

private:
	uint32_t value_;
};

/**
 * SBS temporal isolation status register
 */
class sbs_hdplsr_r {
public:

/**
 * temporal isolation level 
 */
class hdpl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdpl_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_hdplsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_hdplsr_r>() const {return opsy::utility::clear_set<sbs_hdplsr_r>(mask, *this);}
	constexpr auto operator|(sbs_hdplsr_r other) const -> sbs_hdplsr_r { return static_cast<sbs_hdplsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_hdplsr_r> other) const -> opsy::utility::clear_set<sbs_hdplsr_r> {return opsy::utility::clear_set<sbs_hdplsr_r>(sbs_hdplsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdpl() const -> hdpl_f {return hdpl_f(static_cast<uint8_t>(value_ >> hdpl_f::offset));}

	constexpr sbs_hdplsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_hdplsr_r other) const -> sbs_hdplsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_hdplsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS next HDPL control register
 */
class sbs_nexthdplcr_r {
public:

/**
 * index to point to a higher HDPL than the current one 
 */
class nexthdpl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nexthdpl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_nexthdplcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_nexthdplcr_r>() const {return opsy::utility::clear_set<sbs_nexthdplcr_r>(mask, *this);}
	constexpr auto operator|(sbs_nexthdplcr_r other) const -> sbs_nexthdplcr_r { return static_cast<sbs_nexthdplcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_nexthdplcr_r> other) const -> opsy::utility::clear_set<sbs_nexthdplcr_r> {return opsy::utility::clear_set<sbs_nexthdplcr_r>(sbs_nexthdplcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto nexthdpl() const -> nexthdpl_f {return nexthdpl_f(static_cast<uint8_t>(value_ >> nexthdpl_f::offset));}

	constexpr sbs_nexthdplcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_nexthdplcr_r other) const -> sbs_nexthdplcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_nexthdplcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS debug control register
 */
class sbs_dbgcr_r {
public:

/**
 * access port unlock 
 */
class ap_unlock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ap_unlock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_dbgcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_dbgcr_r>() const {return opsy::utility::clear_set<sbs_dbgcr_r>(mask, *this);}
	constexpr auto operator|(sbs_dbgcr_r other) const -> sbs_dbgcr_r { return static_cast<sbs_dbgcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_dbgcr_r> other) const -> opsy::utility::clear_set<sbs_dbgcr_r> {return opsy::utility::clear_set<sbs_dbgcr_r>(sbs_dbgcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * debug unlock when DBG_AUTH_HDPL is reached 
 */
class dbg_unlock_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dbg_unlock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_dbgcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_dbgcr_r>() const {return opsy::utility::clear_set<sbs_dbgcr_r>(mask, *this);}
	constexpr auto operator|(sbs_dbgcr_r other) const -> sbs_dbgcr_r { return static_cast<sbs_dbgcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_dbgcr_r> other) const -> opsy::utility::clear_set<sbs_dbgcr_r> {return opsy::utility::clear_set<sbs_dbgcr_r>(sbs_dbgcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * authenticated debug temporal isolation level 
 */
class dbg_auth_hdpl_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dbg_auth_hdpl_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_dbgcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_dbgcr_r>() const {return opsy::utility::clear_set<sbs_dbgcr_r>(mask, *this);}
	constexpr auto operator|(sbs_dbgcr_r other) const -> sbs_dbgcr_r { return static_cast<sbs_dbgcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_dbgcr_r> other) const -> opsy::utility::clear_set<sbs_dbgcr_r> {return opsy::utility::clear_set<sbs_dbgcr_r>(sbs_dbgcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * control debug opening secure/non-secure 
 */
class dbg_auth_sec_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dbg_auth_sec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_dbgcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_dbgcr_r>() const {return opsy::utility::clear_set<sbs_dbgcr_r>(mask, *this);}
	constexpr auto operator|(sbs_dbgcr_r other) const -> sbs_dbgcr_r { return static_cast<sbs_dbgcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_dbgcr_r> other) const -> opsy::utility::clear_set<sbs_dbgcr_r> {return opsy::utility::clear_set<sbs_dbgcr_r>(sbs_dbgcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ap_unlock() const -> ap_unlock_f {return ap_unlock_f(static_cast<uint8_t>(value_ >> ap_unlock_f::offset));}
	[[nodiscard]] constexpr auto dbg_unlock() const -> dbg_unlock_f {return dbg_unlock_f(static_cast<uint8_t>(value_ >> dbg_unlock_f::offset));}
	[[nodiscard]] constexpr auto dbg_auth_hdpl() const -> dbg_auth_hdpl_f {return dbg_auth_hdpl_f(static_cast<uint8_t>(value_ >> dbg_auth_hdpl_f::offset));}
	[[nodiscard]] constexpr auto dbg_auth_sec() const -> dbg_auth_sec_f {return dbg_auth_sec_f(static_cast<uint8_t>(value_ >> dbg_auth_sec_f::offset));}

	constexpr sbs_dbgcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_dbgcr_r other) const -> sbs_dbgcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_dbgcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS debug lock register
 */
class sbs_dbglockr_r {
public:

/**
 * debug configuration lock 
 */
class dbgcfg_lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dbgcfg_lock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_dbglockr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_dbglockr_r>() const {return opsy::utility::clear_set<sbs_dbglockr_r>(mask, *this);}
	constexpr auto operator|(sbs_dbglockr_r other) const -> sbs_dbglockr_r { return static_cast<sbs_dbglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_dbglockr_r> other) const -> opsy::utility::clear_set<sbs_dbglockr_r> {return opsy::utility::clear_set<sbs_dbglockr_r>(sbs_dbglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dbgcfg_lock() const -> dbgcfg_lock_f {return dbgcfg_lock_f(static_cast<uint8_t>(value_ >> dbgcfg_lock_f::offset));}

	constexpr sbs_dbglockr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_dbglockr_r other) const -> sbs_dbglockr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_dbglockr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10110100; // 180 0xB4

private:
	uint32_t value_;
};

/**
 * SBS RSS command register
 */
class sbs_rsscmdr_r {
public:

/**
 * RSS command 
 */
class rsscmd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rsscmd_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator sbs_rsscmdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_rsscmdr_r>() const {return opsy::utility::clear_set<sbs_rsscmdr_r>(mask, *this);}
	constexpr auto operator|(sbs_rsscmdr_r other) const -> sbs_rsscmdr_r { return static_cast<sbs_rsscmdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_rsscmdr_r> other) const -> opsy::utility::clear_set<sbs_rsscmdr_r> {return opsy::utility::clear_set<sbs_rsscmdr_r>(sbs_rsscmdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rsscmd() const -> rsscmd_f {return rsscmd_f(static_cast<uint16_t>(value_ >> rsscmd_f::offset));}

	constexpr sbs_rsscmdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_rsscmdr_r other) const -> sbs_rsscmdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_rsscmdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS EPOCH selection control register
 */
class sbs_epochselcr_r {
public:

/**
 * select EPOCH value to be sent to the SAES 
 */
class epoch_sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr epoch_sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_epochselcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_epochselcr_r>() const {return opsy::utility::clear_set<sbs_epochselcr_r>(mask, *this);}
	constexpr auto operator|(sbs_epochselcr_r other) const -> sbs_epochselcr_r { return static_cast<sbs_epochselcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_epochselcr_r> other) const -> opsy::utility::clear_set<sbs_epochselcr_r> {return opsy::utility::clear_set<sbs_epochselcr_r>(sbs_epochselcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto epoch_sel() const -> epoch_sel_f {return epoch_sel_f(static_cast<uint8_t>(value_ >> epoch_sel_f::offset));}

	constexpr sbs_epochselcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_epochselcr_r other) const -> sbs_epochselcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_epochselcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS security mode configuration control register
 */
class sbs_seccfgr_r {
public:

/**
 * SBS clock control, memory-erase status register and compensation cell register security enable
 */
class sbssec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbssec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_seccfgr_r>() const {return opsy::utility::clear_set<sbs_seccfgr_r>(mask, *this);}
	constexpr auto operator|(sbs_seccfgr_r other) const -> sbs_seccfgr_r { return static_cast<sbs_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_seccfgr_r> other) const -> opsy::utility::clear_set<sbs_seccfgr_r> {return opsy::utility::clear_set<sbs_seccfgr_r>(sbs_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ClassB security enable
 */
class classbsec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr classbsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_seccfgr_r>() const {return opsy::utility::clear_set<sbs_seccfgr_r>(mask, *this);}
	constexpr auto operator|(sbs_seccfgr_r other) const -> sbs_seccfgr_r { return static_cast<sbs_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_seccfgr_r> other) const -> opsy::utility::clear_set<sbs_seccfgr_r> {return opsy::utility::clear_set<sbs_seccfgr_r>(sbs_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FPU security enable 
 */
class fpusec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpusec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_seccfgr_r>() const {return opsy::utility::clear_set<sbs_seccfgr_r>(mask, *this);}
	constexpr auto operator|(sbs_seccfgr_r other) const -> sbs_seccfgr_r { return static_cast<sbs_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_seccfgr_r> other) const -> opsy::utility::clear_set<sbs_seccfgr_r> {return opsy::utility::clear_set<sbs_seccfgr_r>(sbs_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbssec() const -> sbssec_f {return sbssec_f((value_ & sbssec_f::mask) != 0);}
	[[nodiscard]] constexpr auto classbsec() const -> classbsec_f {return classbsec_f((value_ & classbsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpusec() const -> fpusec_f {return fpusec_f((value_ & fpusec_f::mask) != 0);}

	constexpr sbs_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_seccfgr_r other) const -> sbs_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS product mode and configuration register
 */
class sbs_pmcr_r {
public:

/**
 * Fast-mode Plus driving capability activation on PB6 
 */
class pb6_fmp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pb6_fmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_pmcr_r>() const {return opsy::utility::clear_set<sbs_pmcr_r>(mask, *this);}
	constexpr auto operator|(sbs_pmcr_r other) const -> sbs_pmcr_r { return static_cast<sbs_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_pmcr_r> other) const -> opsy::utility::clear_set<sbs_pmcr_r> {return opsy::utility::clear_set<sbs_pmcr_r>(sbs_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fast-mode Plus driving capability activation on PB7 
 */
class pb7_fmp_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pb7_fmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_pmcr_r>() const {return opsy::utility::clear_set<sbs_pmcr_r>(mask, *this);}
	constexpr auto operator|(sbs_pmcr_r other) const -> sbs_pmcr_r { return static_cast<sbs_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_pmcr_r> other) const -> opsy::utility::clear_set<sbs_pmcr_r> {return opsy::utility::clear_set<sbs_pmcr_r>(sbs_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fast-mode Plus driving capability activation on PB8 
 */
class pb8_fmp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pb8_fmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_pmcr_r>() const {return opsy::utility::clear_set<sbs_pmcr_r>(mask, *this);}
	constexpr auto operator|(sbs_pmcr_r other) const -> sbs_pmcr_r { return static_cast<sbs_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_pmcr_r> other) const -> opsy::utility::clear_set<sbs_pmcr_r> {return opsy::utility::clear_set<sbs_pmcr_r>(sbs_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Fast-mode Plus driving capability activation on PB9 
 */
class pb9_fmp_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pb9_fmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_pmcr_r>() const {return opsy::utility::clear_set<sbs_pmcr_r>(mask, *this);}
	constexpr auto operator|(sbs_pmcr_r other) const -> sbs_pmcr_r { return static_cast<sbs_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_pmcr_r> other) const -> opsy::utility::clear_set<sbs_pmcr_r> {return opsy::utility::clear_set<sbs_pmcr_r>(sbs_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Ethernet PHY interface selection 
 */
class eth_sel_phy_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr eth_sel_phy_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_pmcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_pmcr_r>() const {return opsy::utility::clear_set<sbs_pmcr_r>(mask, *this);}
	constexpr auto operator|(sbs_pmcr_r other) const -> sbs_pmcr_r { return static_cast<sbs_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_pmcr_r> other) const -> opsy::utility::clear_set<sbs_pmcr_r> {return opsy::utility::clear_set<sbs_pmcr_r>(sbs_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pb6_fmp() const -> pb6_fmp_f {return pb6_fmp_f((value_ & pb6_fmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto pb7_fmp() const -> pb7_fmp_f {return pb7_fmp_f((value_ & pb7_fmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto pb8_fmp() const -> pb8_fmp_f {return pb8_fmp_f((value_ & pb8_fmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto pb9_fmp() const -> pb9_fmp_f {return pb9_fmp_f((value_ & pb9_fmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto eth_sel_phy() const -> eth_sel_phy_f {return eth_sel_phy_f(static_cast<uint8_t>(value_ >> eth_sel_phy_f::offset));}

	constexpr sbs_pmcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_pmcr_r other) const -> sbs_pmcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_pmcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS FPU interrupt mask register
 */
class sbs_fpuimr_r {
public:

/**
 * FPU interrupt enable 
 */
class fpu_ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr fpu_ie_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_fpuimr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_fpuimr_r>() const {return opsy::utility::clear_set<sbs_fpuimr_r>(mask, *this);}
	constexpr auto operator|(sbs_fpuimr_r other) const -> sbs_fpuimr_r { return static_cast<sbs_fpuimr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_fpuimr_r> other) const -> opsy::utility::clear_set<sbs_fpuimr_r> {return opsy::utility::clear_set<sbs_fpuimr_r>(sbs_fpuimr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto fpu_ie() const -> fpu_ie_f {return fpu_ie_f(static_cast<uint8_t>(value_ >> fpu_ie_f::offset));}

	constexpr sbs_fpuimr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_fpuimr_r other) const -> sbs_fpuimr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_fpuimr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111; // 31 0x1F

private:
	uint32_t value_;
};

/**
 * SBS memory erase status register
 */
class sbs_mesr_r {
public:

/**
 * device memories erase status 
 */
class mclr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_mesr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_mesr_r>() const {return opsy::utility::clear_set<sbs_mesr_r>(mask, *this);}
	constexpr auto operator|(sbs_mesr_r other) const -> sbs_mesr_r { return static_cast<sbs_mesr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_mesr_r> other) const -> opsy::utility::clear_set<sbs_mesr_r> {return opsy::utility::clear_set<sbs_mesr_r>(sbs_mesr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ICACHE erase status 
 */
class ipmee_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ipmee_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_mesr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_mesr_r>() const {return opsy::utility::clear_set<sbs_mesr_r>(mask, *this);}
	constexpr auto operator|(sbs_mesr_r other) const -> sbs_mesr_r { return static_cast<sbs_mesr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_mesr_r> other) const -> opsy::utility::clear_set<sbs_mesr_r> {return opsy::utility::clear_set<sbs_mesr_r>(sbs_mesr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mclr() const -> mclr_f {return mclr_f((value_ & mclr_f::mask) != 0);}
	[[nodiscard]] constexpr auto ipmee() const -> ipmee_f {return ipmee_f((value_ & ipmee_f::mask) != 0);}

	constexpr sbs_mesr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_mesr_r other) const -> sbs_mesr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_mesr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS compensation cell for I/Os control and status register
 */
class sbs_cccsr_r {
public:

/**
 * enable compensation cell for VDDIO power rail 
 */
class en1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * code selection for VDDIO power rail (reset value set to 1) 
 */
class cs1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cs1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable compensation cell for VDDIO2 power rail 
 */
class en2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * code selection for VDDIO2 power rail (reset value set to 1) 
 */
class cs2_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cs2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VDDIO compensation cell ready flag 
 */
class rdy1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rdy1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VDDIO2 compensation cell ready flag 
 */
class rdy2_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rdy2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cccsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cccsr_r>() const {return opsy::utility::clear_set<sbs_cccsr_r>(mask, *this);}
	constexpr auto operator|(sbs_cccsr_r other) const -> sbs_cccsr_r { return static_cast<sbs_cccsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cccsr_r> other) const -> opsy::utility::clear_set<sbs_cccsr_r> {return opsy::utility::clear_set<sbs_cccsr_r>(sbs_cccsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto en1() const -> en1_f {return en1_f((value_ & en1_f::mask) != 0);}
	[[nodiscard]] constexpr auto cs1() const -> cs1_f {return cs1_f((value_ & cs1_f::mask) != 0);}
	[[nodiscard]] constexpr auto en2() const -> en2_f {return en2_f((value_ & en2_f::mask) != 0);}
	[[nodiscard]] constexpr auto cs2() const -> cs2_f {return cs2_f((value_ & cs2_f::mask) != 0);}
	[[nodiscard]] constexpr auto rdy1() const -> rdy1_f {return rdy1_f((value_ & rdy1_f::mask) != 0);}
	[[nodiscard]] constexpr auto rdy2() const -> rdy2_f {return rdy2_f((value_ & rdy2_f::mask) != 0);}

	constexpr sbs_cccsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_cccsr_r other) const -> sbs_cccsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_cccsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS compensation cell for I/Os value register
 */
class sbs_ccvalr_r {
public:

/**
 * compensation value for the NMOS transistor 
 */
class ansrc1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ansrc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccvalr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccvalr_r>() const {return opsy::utility::clear_set<sbs_ccvalr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccvalr_r other) const -> sbs_ccvalr_r { return static_cast<sbs_ccvalr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccvalr_r> other) const -> opsy::utility::clear_set<sbs_ccvalr_r> {return opsy::utility::clear_set<sbs_ccvalr_r>(sbs_ccvalr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * compensation value for the PMOS transistor 
 */
class apsrc1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr apsrc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccvalr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccvalr_r>() const {return opsy::utility::clear_set<sbs_ccvalr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccvalr_r other) const -> sbs_ccvalr_r { return static_cast<sbs_ccvalr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccvalr_r> other) const -> opsy::utility::clear_set<sbs_ccvalr_r> {return opsy::utility::clear_set<sbs_ccvalr_r>(sbs_ccvalr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Compensation value for the NMOS transistor 
 */
class ansrc2_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ansrc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccvalr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccvalr_r>() const {return opsy::utility::clear_set<sbs_ccvalr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccvalr_r other) const -> sbs_ccvalr_r { return static_cast<sbs_ccvalr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccvalr_r> other) const -> opsy::utility::clear_set<sbs_ccvalr_r> {return opsy::utility::clear_set<sbs_ccvalr_r>(sbs_ccvalr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * compensation value for the PMOS transistor 
 */
class apsrc2_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr apsrc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccvalr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccvalr_r>() const {return opsy::utility::clear_set<sbs_ccvalr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccvalr_r other) const -> sbs_ccvalr_r { return static_cast<sbs_ccvalr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccvalr_r> other) const -> opsy::utility::clear_set<sbs_ccvalr_r> {return opsy::utility::clear_set<sbs_ccvalr_r>(sbs_ccvalr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ansrc1() const -> ansrc1_f {return ansrc1_f(static_cast<uint8_t>(value_ >> ansrc1_f::offset));}
	[[nodiscard]] constexpr auto apsrc1() const -> apsrc1_f {return apsrc1_f(static_cast<uint8_t>(value_ >> apsrc1_f::offset));}
	[[nodiscard]] constexpr auto ansrc2() const -> ansrc2_f {return ansrc2_f(static_cast<uint8_t>(value_ >> ansrc2_f::offset));}
	[[nodiscard]] constexpr auto apsrc2() const -> apsrc2_f {return apsrc2_f(static_cast<uint8_t>(value_ >> apsrc2_f::offset));}

	constexpr sbs_ccvalr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_ccvalr_r other) const -> sbs_ccvalr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_ccvalr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10001000; // 136 0x88

private:
	uint32_t value_;
};

/**
 * SBS compensation cell for I/Os software code register
 */
class sbs_ccswcr_r {
public:

/**
 * NMOS compensation code for VDD power rails 
 */
class sw_ansrc1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sw_ansrc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccswcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccswcr_r>() const {return opsy::utility::clear_set<sbs_ccswcr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccswcr_r other) const -> sbs_ccswcr_r { return static_cast<sbs_ccswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccswcr_r> other) const -> opsy::utility::clear_set<sbs_ccswcr_r> {return opsy::utility::clear_set<sbs_ccswcr_r>(sbs_ccswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PMOS compensation code for the VDD power rails 
 */
class sw_apsrc1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sw_apsrc1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccswcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccswcr_r>() const {return opsy::utility::clear_set<sbs_ccswcr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccswcr_r other) const -> sbs_ccswcr_r { return static_cast<sbs_ccswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccswcr_r> other) const -> opsy::utility::clear_set<sbs_ccswcr_r> {return opsy::utility::clear_set<sbs_ccswcr_r>(sbs_ccswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * NMOS compensation code for VDDIO power rails 
 */
class sw_ansrc2_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sw_ansrc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccswcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccswcr_r>() const {return opsy::utility::clear_set<sbs_ccswcr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccswcr_r other) const -> sbs_ccswcr_r { return static_cast<sbs_ccswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccswcr_r> other) const -> opsy::utility::clear_set<sbs_ccswcr_r> {return opsy::utility::clear_set<sbs_ccswcr_r>(sbs_ccswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * PMOS compensation code for the Vless thansub>DDIOless than/sub> power rails 
 */
class sw_apsrc2_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sw_apsrc2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sbs_ccswcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sbs_ccswcr_r>() const {return opsy::utility::clear_set<sbs_ccswcr_r>(mask, *this);}
	constexpr auto operator|(sbs_ccswcr_r other) const -> sbs_ccswcr_r { return static_cast<sbs_ccswcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_ccswcr_r> other) const -> opsy::utility::clear_set<sbs_ccswcr_r> {return opsy::utility::clear_set<sbs_ccswcr_r>(sbs_ccswcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sw_ansrc1() const -> sw_ansrc1_f {return sw_ansrc1_f(static_cast<uint8_t>(value_ >> sw_ansrc1_f::offset));}
	[[nodiscard]] constexpr auto sw_apsrc1() const -> sw_apsrc1_f {return sw_apsrc1_f(static_cast<uint8_t>(value_ >> sw_apsrc1_f::offset));}
	[[nodiscard]] constexpr auto sw_ansrc2() const -> sw_ansrc2_f {return sw_ansrc2_f(static_cast<uint8_t>(value_ >> sw_ansrc2_f::offset));}
	[[nodiscard]] constexpr auto sw_apsrc2() const -> sw_apsrc2_f {return sw_apsrc2_f(static_cast<uint8_t>(value_ >> sw_apsrc2_f::offset));}

	constexpr sbs_ccswcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_ccswcr_r other) const -> sbs_ccswcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_ccswcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111100001111000; // 30840 0x7878

private:
	uint32_t value_;
};

/**
 * SBS Class B register
 */
class sbs_cfgr2_r {
public:

/**
 * core lockup lock 
 */
class cll_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cll_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cfgr2_r>() const {return opsy::utility::clear_set<sbs_cfgr2_r>(mask, *this);}
	constexpr auto operator|(sbs_cfgr2_r other) const -> sbs_cfgr2_r { return static_cast<sbs_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cfgr2_r> other) const -> opsy::utility::clear_set<sbs_cfgr2_r> {return opsy::utility::clear_set<sbs_cfgr2_r>(sbs_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM ECC error lock 
 */
class sel_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cfgr2_r>() const {return opsy::utility::clear_set<sbs_cfgr2_r>(mask, *this);}
	constexpr auto operator|(sbs_cfgr2_r other) const -> sbs_cfgr2_r { return static_cast<sbs_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cfgr2_r> other) const -> opsy::utility::clear_set<sbs_cfgr2_r> {return opsy::utility::clear_set<sbs_cfgr2_r>(sbs_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PVD lock 
 */
class pvdl_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pvdl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cfgr2_r>() const {return opsy::utility::clear_set<sbs_cfgr2_r>(mask, *this);}
	constexpr auto operator|(sbs_cfgr2_r other) const -> sbs_cfgr2_r { return static_cast<sbs_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cfgr2_r> other) const -> opsy::utility::clear_set<sbs_cfgr2_r> {return opsy::utility::clear_set<sbs_cfgr2_r>(sbs_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC lock 
 */
class eccl_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eccl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cfgr2_r>() const {return opsy::utility::clear_set<sbs_cfgr2_r>(mask, *this);}
	constexpr auto operator|(sbs_cfgr2_r other) const -> sbs_cfgr2_r { return static_cast<sbs_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cfgr2_r> other) const -> opsy::utility::clear_set<sbs_cfgr2_r> {return opsy::utility::clear_set<sbs_cfgr2_r>(sbs_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cll() const -> cll_f {return cll_f((value_ & cll_f::mask) != 0);}
	[[nodiscard]] constexpr auto sel() const -> sel_f {return sel_f((value_ & sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto pvdl() const -> pvdl_f {return pvdl_f((value_ & pvdl_f::mask) != 0);}
	[[nodiscard]] constexpr auto eccl() const -> eccl_f {return eccl_f((value_ & eccl_f::mask) != 0);}

	constexpr sbs_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_cfgr2_r other) const -> sbs_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS CPU non-secure lock register
 */
class sbs_cnslckr_r {
public:

/**
 * VTOR_NS register lock 
 */
class locknsvtor_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr locknsvtor_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cnslckr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cnslckr_r>() const {return opsy::utility::clear_set<sbs_cnslckr_r>(mask, *this);}
	constexpr auto operator|(sbs_cnslckr_r other) const -> sbs_cnslckr_r { return static_cast<sbs_cnslckr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cnslckr_r> other) const -> opsy::utility::clear_set<sbs_cnslckr_r> {return opsy::utility::clear_set<sbs_cnslckr_r>(sbs_cnslckr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * non-secure MPU register lock 
 */
class locknsmpu_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr locknsmpu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cnslckr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cnslckr_r>() const {return opsy::utility::clear_set<sbs_cnslckr_r>(mask, *this);}
	constexpr auto operator|(sbs_cnslckr_r other) const -> sbs_cnslckr_r { return static_cast<sbs_cnslckr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cnslckr_r> other) const -> opsy::utility::clear_set<sbs_cnslckr_r> {return opsy::utility::clear_set<sbs_cnslckr_r>(sbs_cnslckr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto locknsvtor() const -> locknsvtor_f {return locknsvtor_f((value_ & locknsvtor_f::mask) != 0);}
	[[nodiscard]] constexpr auto locknsmpu() const -> locknsmpu_f {return locknsmpu_f((value_ & locknsmpu_f::mask) != 0);}

	constexpr sbs_cnslckr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_cnslckr_r other) const -> sbs_cnslckr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_cnslckr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS CPU secure lock register
 */
class sbs_cslckr_r {
public:

/**
 * VTOR_S and AIRCR register lock 
 */
class locksvtaircr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr locksvtaircr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cslckr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cslckr_r>() const {return opsy::utility::clear_set<sbs_cslckr_r>(mask, *this);}
	constexpr auto operator|(sbs_cslckr_r other) const -> sbs_cslckr_r { return static_cast<sbs_cslckr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cslckr_r> other) const -> opsy::utility::clear_set<sbs_cslckr_r> {return opsy::utility::clear_set<sbs_cslckr_r>(sbs_cslckr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure MPU registers lock 
 */
class locksmpu_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr locksmpu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cslckr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cslckr_r>() const {return opsy::utility::clear_set<sbs_cslckr_r>(mask, *this);}
	constexpr auto operator|(sbs_cslckr_r other) const -> sbs_cslckr_r { return static_cast<sbs_cslckr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cslckr_r> other) const -> opsy::utility::clear_set<sbs_cslckr_r> {return opsy::utility::clear_set<sbs_cslckr_r>(sbs_cslckr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SAU registers lock 
 */
class locksau_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr locksau_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_cslckr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_cslckr_r>() const {return opsy::utility::clear_set<sbs_cslckr_r>(mask, *this);}
	constexpr auto operator|(sbs_cslckr_r other) const -> sbs_cslckr_r { return static_cast<sbs_cslckr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_cslckr_r> other) const -> opsy::utility::clear_set<sbs_cslckr_r> {return opsy::utility::clear_set<sbs_cslckr_r>(sbs_cslckr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto locksvtaircr() const -> locksvtaircr_f {return locksvtaircr_f((value_ & locksvtaircr_f::mask) != 0);}
	[[nodiscard]] constexpr auto locksmpu() const -> locksmpu_f {return locksmpu_f((value_ & locksmpu_f::mask) != 0);}
	[[nodiscard]] constexpr auto locksau() const -> locksau_f {return locksau_f((value_ & locksau_f::mask) != 0);}

	constexpr sbs_cslckr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_cslckr_r other) const -> sbs_cslckr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_cslckr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SBS flift ECC NMI mask register
 */
class sbs_eccnmir_r {
public:

/**
 * NMI behavior setup when a double ECC error occurs on flitf data part
 */
class eccnmi_mask_en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eccnmi_mask_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sbs_eccnmir_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sbs_eccnmir_r>() const {return opsy::utility::clear_set<sbs_eccnmir_r>(mask, *this);}
	constexpr auto operator|(sbs_eccnmir_r other) const -> sbs_eccnmir_r { return static_cast<sbs_eccnmir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sbs_eccnmir_r> other) const -> opsy::utility::clear_set<sbs_eccnmir_r> {return opsy::utility::clear_set<sbs_eccnmir_r>(sbs_eccnmir_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto eccnmi_mask_en() const -> eccnmi_mask_en_f {return eccnmi_mask_en_f((value_ & eccnmi_mask_en_f::mask) != 0);}

	constexpr sbs_eccnmir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sbs_eccnmir_r other) const -> sbs_eccnmir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sbs_eccnmir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::padding<16> _p0;
	opsy::utility::memory<uint32_t,sbs_hdplcr_r> sbs_hdplcr;
	opsy::utility::read_only_memory<uint32_t,sbs_hdplsr_r> sbs_hdplsr;
	opsy::utility::memory<uint32_t,sbs_nexthdplcr_r> sbs_nexthdplcr;
	opsy::utility::padding<4> _p28;
	opsy::utility::memory<uint32_t,sbs_dbgcr_r> sbs_dbgcr;
	opsy::utility::memory<uint32_t,sbs_dbglockr_r> sbs_dbglockr;
	opsy::utility::padding<12> _p40;
	opsy::utility::memory<uint32_t,sbs_rsscmdr_r> sbs_rsscmdr;
	opsy::utility::padding<104> _p56;
	opsy::utility::memory<uint32_t,sbs_epochselcr_r> sbs_epochselcr;
	opsy::utility::padding<28> _p164;
	opsy::utility::memory<uint32_t,sbs_seccfgr_r> sbs_seccfgr;
	opsy::utility::padding<60> _p196;
	opsy::utility::memory<uint32_t,sbs_pmcr_r> sbs_pmcr;
	opsy::utility::memory<uint32_t,sbs_fpuimr_r> sbs_fpuimr;
	opsy::utility::memory<uint32_t,sbs_mesr_r> sbs_mesr;
	opsy::utility::padding<4> _p268;
	opsy::utility::memory<uint32_t,sbs_cccsr_r> sbs_cccsr;
	opsy::utility::read_only_memory<uint32_t,sbs_ccvalr_r> sbs_ccvalr;
	opsy::utility::memory<uint32_t,sbs_ccswcr_r> sbs_ccswcr;
	opsy::utility::padding<4> _p284;
	opsy::utility::memory<uint32_t,sbs_cfgr2_r> sbs_cfgr2;
	opsy::utility::padding<32> _p292;
	opsy::utility::memory<uint32_t,sbs_cnslckr_r> sbs_cnslckr;
	opsy::utility::memory<uint32_t,sbs_cslckr_r> sbs_cslckr;
	opsy::utility::memory<uint32_t,sbs_eccnmir_r> sbs_eccnmir;
};

static_assert(std::is_standard_layout_v<sbs_p>);
static_assert(offsetof(sbs_p, sbs_hdplcr) == 16);
static_assert(offsetof(sbs_p, sbs_hdplsr) == 20);
static_assert(offsetof(sbs_p, sbs_nexthdplcr) == 24);
static_assert(offsetof(sbs_p, sbs_dbgcr) == 32);
static_assert(offsetof(sbs_p, sbs_dbglockr) == 36);
static_assert(offsetof(sbs_p, sbs_rsscmdr) == 52);
static_assert(offsetof(sbs_p, sbs_epochselcr) == 160);
static_assert(offsetof(sbs_p, sbs_seccfgr) == 192);
static_assert(offsetof(sbs_p, sbs_pmcr) == 256);
static_assert(offsetof(sbs_p, sbs_fpuimr) == 260);
static_assert(offsetof(sbs_p, sbs_mesr) == 264);
static_assert(offsetof(sbs_p, sbs_cccsr) == 272);
static_assert(offsetof(sbs_p, sbs_ccvalr) == 276);
static_assert(offsetof(sbs_p, sbs_ccswcr) == 280);
static_assert(offsetof(sbs_p, sbs_cfgr2) == 288);
static_assert(offsetof(sbs_p, sbs_cnslckr) == 324);
static_assert(offsetof(sbs_p, sbs_cslckr) == 328);
static_assert(offsetof(sbs_p, sbs_eccnmir) == 332);

inline sbs_p& sbs = *reinterpret_cast<sbs_p*>(0x44000400);
inline sbs_p& sbs_s = *reinterpret_cast<sbs_p*>(0x54000400);

} // STM32H523

