#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * CRS address block description
 */
class crs_p {
public:

/**
 * CRS control register
 */
class crs_cr_r {
public:

/**
 * SYNC event OK interrupt enable
 */
class syncokie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning interrupt enable
 */
class syncwarnie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization or trimming error interrupt enable
 */
class errie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC interrupt enable
 */
class esyncie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error counter enable 
 */
class cen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic trimming enable 
 */
class autotrimen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr autotrimen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Generate software SYNC event 
 */
class swsync_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swsync_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HSI48 oscillator smooth trimming 
 */
class trim_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trim_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cr_r>() const {return opsy::utility::clear_set<crs_cr_r>(mask, *this);}
	constexpr auto operator|(crs_cr_r other) const -> crs_cr_r { return static_cast<crs_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cr_r> other) const -> opsy::utility::clear_set<crs_cr_r> {return opsy::utility::clear_set<crs_cr_r>(crs_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto syncokie() const -> syncokie_f {return syncokie_f((value_ & syncokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnie() const -> syncwarnie_f {return syncwarnie_f((value_ & syncwarnie_f::mask) != 0);}
	[[nodiscard]] constexpr auto errie() const -> errie_f {return errie_f((value_ & errie_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncie() const -> esyncie_f {return esyncie_f((value_ & esyncie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cen() const -> cen_f {return cen_f((value_ & cen_f::mask) != 0);}
	[[nodiscard]] constexpr auto autotrimen() const -> autotrimen_f {return autotrimen_f((value_ & autotrimen_f::mask) != 0);}
	[[nodiscard]] constexpr auto swsync() const -> swsync_f {return swsync_f((value_ & swsync_f::mask) != 0);}
	[[nodiscard]] constexpr auto trim() const -> trim_f {return trim_f(static_cast<uint8_t>(value_ >> trim_f::offset));}

	constexpr crs_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_cr_r other) const -> crs_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000000000; // 16384 0x4000

private:
	uint32_t value_;
};

/**
 * CRS configuration register
 */
class crs_cfgr_r {
public:

/**
 * Counter reload value 
 */
class reload_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr reload_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Frequency error limit 
 */
class felim_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr felim_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC divider 
 */
class syncdiv_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr syncdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC signal source selection 
 */
class syncsrc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr syncsrc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator crs_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SYNC polarity selection 
 */
class syncpol_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr syncpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_cfgr_r>() const {return opsy::utility::clear_set<crs_cfgr_r>(mask, *this);}
	constexpr auto operator|(crs_cfgr_r other) const -> crs_cfgr_r { return static_cast<crs_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_cfgr_r> other) const -> opsy::utility::clear_set<crs_cfgr_r> {return opsy::utility::clear_set<crs_cfgr_r>(crs_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto reload() const -> reload_f {return reload_f(static_cast<uint16_t>(value_ >> reload_f::offset));}
	[[nodiscard]] constexpr auto felim() const -> felim_f {return felim_f(static_cast<uint8_t>(value_ >> felim_f::offset));}
	[[nodiscard]] constexpr auto syncdiv() const -> syncdiv_f {return syncdiv_f(static_cast<uint8_t>(value_ >> syncdiv_f::offset));}
	[[nodiscard]] constexpr auto syncsrc() const -> syncsrc_f {return syncsrc_f(static_cast<uint8_t>(value_ >> syncsrc_f::offset));}
	[[nodiscard]] constexpr auto syncpol() const -> syncpol_f {return syncpol_f((value_ & syncpol_f::mask) != 0);}

	constexpr crs_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_cfgr_r other) const -> crs_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000001000101011101101111111; // 539147135 0x2022BB7F

private:
	uint32_t value_;
};

/**
 * CRS interrupt and status register
 */
class crs_isr_r {
public:

/**
 * SYNC event OK flag 
 */
class syncokf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning flag 
 */
class syncwarnf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error flag 
 */
class errf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC flag 
 */
class esyncf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC error 
 */
class syncerr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr syncerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC missed 
 */
class syncmiss_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr syncmiss_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trimming overflow or underflow 
 */
class trimovf_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr trimovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error direction 
 */
class fedir_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fedir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frequency error capture 
 */
class fecap_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fecap_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator crs_isr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<crs_isr_r>() const {return opsy::utility::clear_set<crs_isr_r>(mask, *this);}
	constexpr auto operator|(crs_isr_r other) const -> crs_isr_r { return static_cast<crs_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_isr_r> other) const -> opsy::utility::clear_set<crs_isr_r> {return opsy::utility::clear_set<crs_isr_r>(crs_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto syncokf() const -> syncokf_f {return syncokf_f((value_ & syncokf_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnf() const -> syncwarnf_f {return syncwarnf_f((value_ & syncwarnf_f::mask) != 0);}
	[[nodiscard]] constexpr auto errf() const -> errf_f {return errf_f((value_ & errf_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncf() const -> esyncf_f {return esyncf_f((value_ & esyncf_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncerr() const -> syncerr_f {return syncerr_f((value_ & syncerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncmiss() const -> syncmiss_f {return syncmiss_f((value_ & syncmiss_f::mask) != 0);}
	[[nodiscard]] constexpr auto trimovf() const -> trimovf_f {return trimovf_f((value_ & trimovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fedir() const -> fedir_f {return fedir_f((value_ & fedir_f::mask) != 0);}
	[[nodiscard]] constexpr auto fecap() const -> fecap_f {return fecap_f(static_cast<uint16_t>(value_ >> fecap_f::offset));}

	constexpr crs_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_isr_r other) const -> crs_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * CRS interrupt flag clear register
 */
class crs_icr_r {
public:

/**
 * SYNC event OK clear flag 
 */
class syncokc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncokc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SYNC warning clear flag 
 */
class syncwarnc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr syncwarnc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error clear flag 
 */
class errc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr errc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected SYNC clear flag 
 */
class esyncc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr esyncc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator crs_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<crs_icr_r>() const {return opsy::utility::clear_set<crs_icr_r>(mask, *this);}
	constexpr auto operator|(crs_icr_r other) const -> crs_icr_r { return static_cast<crs_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<crs_icr_r> other) const -> opsy::utility::clear_set<crs_icr_r> {return opsy::utility::clear_set<crs_icr_r>(crs_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto syncokc() const -> syncokc_f {return syncokc_f((value_ & syncokc_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncwarnc() const -> syncwarnc_f {return syncwarnc_f((value_ & syncwarnc_f::mask) != 0);}
	[[nodiscard]] constexpr auto errc() const -> errc_f {return errc_f((value_ & errc_f::mask) != 0);}
	[[nodiscard]] constexpr auto esyncc() const -> esyncc_f {return esyncc_f((value_ & esyncc_f::mask) != 0);}

	constexpr crs_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(crs_icr_r other) const -> crs_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> crs_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,crs_cr_r> crs_cr;
	opsy::utility::memory<uint32_t,crs_cfgr_r> crs_cfgr;
	opsy::utility::read_only_memory<uint32_t,crs_isr_r> crs_isr;
	opsy::utility::memory<uint32_t,crs_icr_r> crs_icr;
};

static_assert(std::is_standard_layout_v<crs_p>);
static_assert(offsetof(crs_p, crs_cr) == 0);
static_assert(offsetof(crs_p, crs_cfgr) == 4);
static_assert(offsetof(crs_p, crs_isr) == 8);
static_assert(offsetof(crs_p, crs_icr) == 12);

inline crs_p& crs = *reinterpret_cast<crs_p*>(0x40006000);
inline crs_p& crs_s = *reinterpret_cast<crs_p*>(0x50006000);

} // STM32H523

