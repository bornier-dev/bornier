#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * IWDG address block description
 */
class iwdg_p {
public:

/**
 * IWDG key register
 */
class iwdg_kr_r {
public:

/**
 * Key value (write only, read 0x0000) 
 */
class key_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr key_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator iwdg_kr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<iwdg_kr_r>() const {return opsy::utility::clear_set<iwdg_kr_r>(mask, *this);}
	constexpr auto operator|(iwdg_kr_r other) const -> iwdg_kr_r { return static_cast<iwdg_kr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_kr_r> other) const -> opsy::utility::clear_set<iwdg_kr_r> {return opsy::utility::clear_set<iwdg_kr_r>(iwdg_kr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto key() const -> key_f {return key_f(static_cast<uint16_t>(value_ >> key_f::offset));}

	constexpr iwdg_kr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_kr_r other) const -> iwdg_kr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_kr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * IWDG prescaler register
 */
class iwdg_pr_r {
public:

/**
 * Prescaler divider 
 */
class pr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator iwdg_pr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<iwdg_pr_r>() const {return opsy::utility::clear_set<iwdg_pr_r>(mask, *this);}
	constexpr auto operator|(iwdg_pr_r other) const -> iwdg_pr_r { return static_cast<iwdg_pr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_pr_r> other) const -> opsy::utility::clear_set<iwdg_pr_r> {return opsy::utility::clear_set<iwdg_pr_r>(iwdg_pr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pr() const -> pr_f {return pr_f(static_cast<uint8_t>(value_ >> pr_f::offset));}

	constexpr iwdg_pr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_pr_r other) const -> iwdg_pr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_pr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * IWDG reload register
 */
class iwdg_rlr_r {
public:

/**
 * Watchdog counter reload value 
 */
class rl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rl_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator iwdg_rlr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<iwdg_rlr_r>() const {return opsy::utility::clear_set<iwdg_rlr_r>(mask, *this);}
	constexpr auto operator|(iwdg_rlr_r other) const -> iwdg_rlr_r { return static_cast<iwdg_rlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_rlr_r> other) const -> opsy::utility::clear_set<iwdg_rlr_r> {return opsy::utility::clear_set<iwdg_rlr_r>(iwdg_rlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rl() const -> rl_f {return rl_f(static_cast<uint16_t>(value_ >> rl_f::offset));}

	constexpr iwdg_rlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_rlr_r other) const -> iwdg_rlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_rlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111111111111; // 4095 0xFFF

private:
	uint32_t value_;
};

/**
 * IWDG status register
 */
class iwdg_sr_r {
public:

/**
 * Watchdog prescaler value update 
 */
class pvu_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pvu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog counter reload value update 
 */
class rvu_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rvu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog counter window value update 
 */
class wvu_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wvu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog interrupt comparator value update 
 */
class ewu_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ewu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog enable status bit 
 */
class onf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr onf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog early interrupt flag 
 */
class ewif_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ewif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_sr_r>() const {return opsy::utility::clear_set<iwdg_sr_r>(mask, *this);}
	constexpr auto operator|(iwdg_sr_r other) const -> iwdg_sr_r { return static_cast<iwdg_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_sr_r> other) const -> opsy::utility::clear_set<iwdg_sr_r> {return opsy::utility::clear_set<iwdg_sr_r>(iwdg_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pvu() const -> pvu_f {return pvu_f((value_ & pvu_f::mask) != 0);}
	[[nodiscard]] constexpr auto rvu() const -> rvu_f {return rvu_f((value_ & rvu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wvu() const -> wvu_f {return wvu_f((value_ & wvu_f::mask) != 0);}
	[[nodiscard]] constexpr auto ewu() const -> ewu_f {return ewu_f((value_ & ewu_f::mask) != 0);}
	[[nodiscard]] constexpr auto onf() const -> onf_f {return onf_f((value_ & onf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ewif() const -> ewif_f {return ewif_f((value_ & ewif_f::mask) != 0);}

	constexpr iwdg_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_sr_r other) const -> iwdg_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * IWDG window register
 */
class iwdg_winr_r {
public:

/**
 * Watchdog counter window value 
 */
class win_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr win_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator iwdg_winr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<iwdg_winr_r>() const {return opsy::utility::clear_set<iwdg_winr_r>(mask, *this);}
	constexpr auto operator|(iwdg_winr_r other) const -> iwdg_winr_r { return static_cast<iwdg_winr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_winr_r> other) const -> opsy::utility::clear_set<iwdg_winr_r> {return opsy::utility::clear_set<iwdg_winr_r>(iwdg_winr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto win() const -> win_f {return win_f(static_cast<uint16_t>(value_ >> win_f::offset));}

	constexpr iwdg_winr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_winr_r other) const -> iwdg_winr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_winr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111111111111; // 4095 0xFFF

private:
	uint32_t value_;
};

/**
 * IWDG early wake-up interrupt register
 */
class iwdg_ewcr_r {
public:

/**
 * Watchdog counter window value 
 */
class ewit_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ewit_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator iwdg_ewcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<iwdg_ewcr_r>() const {return opsy::utility::clear_set<iwdg_ewcr_r>(mask, *this);}
	constexpr auto operator|(iwdg_ewcr_r other) const -> iwdg_ewcr_r { return static_cast<iwdg_ewcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_ewcr_r> other) const -> opsy::utility::clear_set<iwdg_ewcr_r> {return opsy::utility::clear_set<iwdg_ewcr_r>(iwdg_ewcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Watchdog early interrupt acknowledge 
 */
class ewic_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ewic_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_ewcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_ewcr_r>() const {return opsy::utility::clear_set<iwdg_ewcr_r>(mask, *this);}
	constexpr auto operator|(iwdg_ewcr_r other) const -> iwdg_ewcr_r { return static_cast<iwdg_ewcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_ewcr_r> other) const -> opsy::utility::clear_set<iwdg_ewcr_r> {return opsy::utility::clear_set<iwdg_ewcr_r>(iwdg_ewcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Watchdog early interrupt enable 
 */
class ewie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ewie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator iwdg_ewcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<iwdg_ewcr_r>() const {return opsy::utility::clear_set<iwdg_ewcr_r>(mask, *this);}
	constexpr auto operator|(iwdg_ewcr_r other) const -> iwdg_ewcr_r { return static_cast<iwdg_ewcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<iwdg_ewcr_r> other) const -> opsy::utility::clear_set<iwdg_ewcr_r> {return opsy::utility::clear_set<iwdg_ewcr_r>(iwdg_ewcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ewit() const -> ewit_f {return ewit_f(static_cast<uint16_t>(value_ >> ewit_f::offset));}
	[[nodiscard]] constexpr auto ewic() const -> ewic_f {return ewic_f((value_ & ewic_f::mask) != 0);}
	[[nodiscard]] constexpr auto ewie() const -> ewie_f {return ewie_f((value_ & ewie_f::mask) != 0);}

	constexpr iwdg_ewcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(iwdg_ewcr_r other) const -> iwdg_ewcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> iwdg_ewcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::write_only_memory<uint32_t,iwdg_kr_r> iwdg_kr;
	opsy::utility::memory<uint32_t,iwdg_pr_r> iwdg_pr;
	opsy::utility::memory<uint32_t,iwdg_rlr_r> iwdg_rlr;
	opsy::utility::read_only_memory<uint32_t,iwdg_sr_r> iwdg_sr;
	opsy::utility::memory<uint32_t,iwdg_winr_r> iwdg_winr;
	opsy::utility::memory<uint32_t,iwdg_ewcr_r> iwdg_ewcr;
};

static_assert(std::is_standard_layout_v<iwdg_p>);
static_assert(offsetof(iwdg_p, iwdg_kr) == 0);
static_assert(offsetof(iwdg_p, iwdg_pr) == 4);
static_assert(offsetof(iwdg_p, iwdg_rlr) == 8);
static_assert(offsetof(iwdg_p, iwdg_sr) == 12);
static_assert(offsetof(iwdg_p, iwdg_winr) == 16);
static_assert(offsetof(iwdg_p, iwdg_ewcr) == 20);

inline iwdg_p& iwdg = *reinterpret_cast<iwdg_p*>(0x40003000);
inline iwdg_p& iwdg_s = *reinterpret_cast<iwdg_p*>(0x50003000);

} // STM32H523

