#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Real-time clock
 */
class rtc_p {
public:

/**
 * RTC time register 
 */
class rtc_tr_r {
public:

/**
 * Second units in BCD format
 */
class su_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr su_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Second tens in BCD format
 */
class st_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr st_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Minute units in BCD format
 */
class mnu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Minute tens in BCD format
 */
class mnt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Hour units in BCD format
 */
class hu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Hour tens in BCD format
 */
class ht_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * AM/PM notation
 */
class pm_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_tr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_tr_r>() const {return opsy::utility::clear_set<rtc_tr_r>(mask, *this);}
	constexpr auto operator|(rtc_tr_r other) const -> rtc_tr_r { return static_cast<rtc_tr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tr_r> other) const -> opsy::utility::clear_set<rtc_tr_r> {return opsy::utility::clear_set<rtc_tr_r>(rtc_tr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto su() const -> su_f {return su_f(static_cast<uint8_t>(value_ >> su_f::offset));}
	[[nodiscard]] constexpr auto st() const -> st_f {return st_f(static_cast<uint8_t>(value_ >> st_f::offset));}
	[[nodiscard]] constexpr auto mnu() const -> mnu_f {return mnu_f(static_cast<uint8_t>(value_ >> mnu_f::offset));}
	[[nodiscard]] constexpr auto mnt() const -> mnt_f {return mnt_f(static_cast<uint8_t>(value_ >> mnt_f::offset));}
	[[nodiscard]] constexpr auto hu() const -> hu_f {return hu_f(static_cast<uint8_t>(value_ >> hu_f::offset));}
	[[nodiscard]] constexpr auto ht() const -> ht_f {return ht_f(static_cast<uint8_t>(value_ >> ht_f::offset));}
	[[nodiscard]] constexpr auto pm() const -> pm_f {return pm_f((value_ & pm_f::mask) != 0);}

	constexpr rtc_tr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_tr_r other) const -> rtc_tr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_tr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC date register 
 */
class rtc_dr_r {
public:

/**
 * Date units in BCD format
 */
class du_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr du_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Date tens in BCD format
 */
class dt_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Month units in BCD format
 */
class mu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Month tens in BCD format
 */
class mt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_dr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Week day units ...
 */
class wdu_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wdu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Year units in BCD format
 */
class yu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr yu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Year tens in BCD format
 */
class yt_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr yt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_dr_r>() const {return opsy::utility::clear_set<rtc_dr_r>(mask, *this);}
	constexpr auto operator|(rtc_dr_r other) const -> rtc_dr_r { return static_cast<rtc_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_dr_r> other) const -> opsy::utility::clear_set<rtc_dr_r> {return opsy::utility::clear_set<rtc_dr_r>(rtc_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto du() const -> du_f {return du_f(static_cast<uint8_t>(value_ >> du_f::offset));}
	[[nodiscard]] constexpr auto dt() const -> dt_f {return dt_f(static_cast<uint8_t>(value_ >> dt_f::offset));}
	[[nodiscard]] constexpr auto mu() const -> mu_f {return mu_f(static_cast<uint8_t>(value_ >> mu_f::offset));}
	[[nodiscard]] constexpr auto mt() const -> mt_f {return mt_f((value_ & mt_f::mask) != 0);}
	[[nodiscard]] constexpr auto wdu() const -> wdu_f {return wdu_f(static_cast<uint8_t>(value_ >> wdu_f::offset));}
	[[nodiscard]] constexpr auto yu() const -> yu_f {return yu_f(static_cast<uint8_t>(value_ >> yu_f::offset));}
	[[nodiscard]] constexpr auto yt() const -> yt_f {return yt_f(static_cast<uint8_t>(value_ >> yt_f::offset));}

	constexpr rtc_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_dr_r other) const -> rtc_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000100000001; // 8449 0x2101

private:
	uint32_t value_;
};

/**
 * RTC sub second register 
 */
class rtc_ssr_r {
public:

/**
 * Synchronous binary counter SS[31:16]: Synchronous binary counter MSB values When Binary or Mixed mode is selected (BIN = 01 or 10 or 11): SS[31:16] are the 16 MSB of the SS[31:0] free-running down-counter. When BCD mode is selected (BIN=00): SS[31:16] are forced by hardware to 0x0000. SS[15:0]: Sub second value/Synchronous binary counter LSB values When Binary mode is selected (BIN = 01 or 10 or 11): SS[15:0] are the 16 LSB of the SS[31:0] free-running down-counter. When BCD mode is selected (BIN=00): SS[15:0] is the value in the synchronous prescaler counter. The fraction of a second is given by the formula below: Second fraction = (PREDIV_SSS) / (PREDIV_S + 1) SS can be larger than PREDIV_S only after a shift operation. In that case, the correct time/date is one second less than as indicated by RTC_TR/RTC_DR.
 */
class ss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ss_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator rtc_ssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_ssr_r>() const {return opsy::utility::clear_set<rtc_ssr_r>(mask, *this);}
	constexpr auto operator|(rtc_ssr_r other) const -> rtc_ssr_r { return static_cast<rtc_ssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_ssr_r> other) const -> opsy::utility::clear_set<rtc_ssr_r> {return opsy::utility::clear_set<rtc_ssr_r>(rtc_ssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ss() const -> ss_f {return ss_f(static_cast<uint32_t>(value_ >> ss_f::offset));}

	constexpr rtc_ssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_ssr_r other) const -> rtc_ssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_ssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC initialization control and status register 
 */
class rtc_icsr_r {
public:

/**
 * Wakeup timer write flag This bit is set by hardware when WUT value can be changed, after the WUTE bit has been set to 0 in RTC_CR. It is cleared by hardware in initialization mode.
 */
class wutwf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wutwf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Shift operation pending This flag is set by hardware as soon as a shift operation is initiated by a write to the RTC_SHIFTR register. It is cleared by hardware when the corresponding shift operation has been executed. Writing to the SHPF bit has no effect.
 */
class shpf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr shpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialization status flag This bit is set by hardware when the calendar year field is different from 0 (Backup domain reset state).
 */
class inits_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr inits_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Registers synchronization flag This bit is set by hardware each time the calendar registers are copied into the shadow registers (RTC_SSR, RTC_TR and RTC_DR). This bit is cleared by hardware in initialization mode, while a shift operation is pending (SHPF = 1), or when in bypass shadow register mode (BYPSHAD = 1). This bit can also be cleared by software. It is cleared either by software or by hardware in initialization mode.
 */
class rsf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialization flag When this bit is set to 1, the RTC is in initialization state, and the time, date and prescaler registers can be updated.
 */
class initf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr initf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialization mode
 */
class init_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr init_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Binary mode
 */
class bin_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr bin_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_icsr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * BCD update (BIN = 10 or 11) In mixed mode when both BCD calendar and binary extended counter are used (BIN = 10 or 11), the calendar second is incremented using the SSR Least Significant Bits.
 */
class bcdu_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr bcdu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_icsr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Recalibration pending Flag The RECALPF status flag is automatically set to 1 when software writes to the RTC_CALR register, indicating that the RTC_CALR register is blocked. When the new calibration settings are taken into account, this bit returns to 0. Refer to .
 */
class recalpf_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr recalpf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_icsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_icsr_r>() const {return opsy::utility::clear_set<rtc_icsr_r>(mask, *this);}
	constexpr auto operator|(rtc_icsr_r other) const -> rtc_icsr_r { return static_cast<rtc_icsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_icsr_r> other) const -> opsy::utility::clear_set<rtc_icsr_r> {return opsy::utility::clear_set<rtc_icsr_r>(rtc_icsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto wutwf() const -> wutwf_f {return wutwf_f((value_ & wutwf_f::mask) != 0);}
	[[nodiscard]] constexpr auto shpf() const -> shpf_f {return shpf_f((value_ & shpf_f::mask) != 0);}
	[[nodiscard]] constexpr auto inits() const -> inits_f {return inits_f((value_ & inits_f::mask) != 0);}
	[[nodiscard]] constexpr auto rsf() const -> rsf_f {return rsf_f((value_ & rsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto initf() const -> initf_f {return initf_f((value_ & initf_f::mask) != 0);}
	[[nodiscard]] constexpr auto init() const -> init_f {return init_f((value_ & init_f::mask) != 0);}
	[[nodiscard]] constexpr auto bin() const -> bin_f {return bin_f(static_cast<uint8_t>(value_ >> bin_f::offset));}
	[[nodiscard]] constexpr auto bcdu() const -> bcdu_f {return bcdu_f(static_cast<uint8_t>(value_ >> bcdu_f::offset));}
	[[nodiscard]] constexpr auto recalpf() const -> recalpf_f {return recalpf_f((value_ & recalpf_f::mask) != 0);}

	constexpr rtc_icsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_icsr_r other) const -> rtc_icsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_icsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111; // 7 0x7

private:
	uint32_t value_;
};

/**
 * RTC prescaler register 
 */
class rtc_prer_r {
public:

/**
 * Synchronous prescaler factor This is the synchronous division factor: ck_spre frequency = ck_apre frequency/(PREDIV_S+1)
 */
class prediv_s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 15;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr prediv_s_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_prer_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_prer_r>() const {return opsy::utility::clear_set<rtc_prer_r>(mask, *this);}
	constexpr auto operator|(rtc_prer_r other) const -> rtc_prer_r { return static_cast<rtc_prer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_prer_r> other) const -> opsy::utility::clear_set<rtc_prer_r> {return opsy::utility::clear_set<rtc_prer_r>(rtc_prer_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Asynchronous prescaler factor This is the asynchronous division factor: ck_apre frequency = RTCCLK frequency/(PREDIV_A+1)
 */
class prediv_a_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr prediv_a_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_prer_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_prer_r>() const {return opsy::utility::clear_set<rtc_prer_r>(mask, *this);}
	constexpr auto operator|(rtc_prer_r other) const -> rtc_prer_r { return static_cast<rtc_prer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_prer_r> other) const -> opsy::utility::clear_set<rtc_prer_r> {return opsy::utility::clear_set<rtc_prer_r>(rtc_prer_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prediv_s() const -> prediv_s_f {return prediv_s_f(static_cast<uint16_t>(value_ >> prediv_s_f::offset));}
	[[nodiscard]] constexpr auto prediv_a() const -> prediv_a_f {return prediv_a_f(static_cast<uint8_t>(value_ >> prediv_a_f::offset));}

	constexpr rtc_prer_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_prer_r other) const -> rtc_prer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_prer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111110000000011111111; // 8323327 0x7F00FF

private:
	uint32_t value_;
};

/**
 * RTC wakeup timer register 
 */
class rtc_wutr_r {
public:

/**
 * Wakeup auto-reload value bits When the wakeup timer is enabled (WUTE set to 1), the WUTF flag is set every (WUT[15:0] + 1) ck_wut cycles. The ck_wut period is selected through WUCKSEL[2:0] bits of the RTC_CR register. When WUCKSEL[2] = 1, the wakeup timer becomes 17-bits and WUCKSEL[1] effectively becomes WUT[16] the most-significant bit to be reloaded into the timer. The first assertion of WUTF occurs between WUT and (WUT + 2) ck_wut cycles after WUTE is set. Setting WUT[15:0] to 0x0000 with WUCKSEL[2:0] = 011 (RTCCLK/2) is forbidden.
 */
class wut_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wut_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_wutr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_wutr_r>() const {return opsy::utility::clear_set<rtc_wutr_r>(mask, *this);}
	constexpr auto operator|(rtc_wutr_r other) const -> rtc_wutr_r { return static_cast<rtc_wutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_wutr_r> other) const -> opsy::utility::clear_set<rtc_wutr_r> {return opsy::utility::clear_set<rtc_wutr_r>(rtc_wutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Wakeup auto-reload output clear value When WUTOCLR[15:0] is different from 0x0000, WUTF is set by hardware when the auto-reload down-counter reaches 0 and is cleared by hardware when the auto-reload downcounter reaches WUTOCLR[15:0]. When WUTOCLR[15:0] = 0x0000, WUTF is set by hardware when the WUT down-counter reaches 0 and is cleared by software.
 */
class wutoclr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wutoclr_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_wutr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_wutr_r>() const {return opsy::utility::clear_set<rtc_wutr_r>(mask, *this);}
	constexpr auto operator|(rtc_wutr_r other) const -> rtc_wutr_r { return static_cast<rtc_wutr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_wutr_r> other) const -> opsy::utility::clear_set<rtc_wutr_r> {return opsy::utility::clear_set<rtc_wutr_r>(rtc_wutr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto wut() const -> wut_f {return wut_f(static_cast<uint16_t>(value_ >> wut_f::offset));}
	[[nodiscard]] constexpr auto wutoclr() const -> wutoclr_f {return wutoclr_f(static_cast<uint16_t>(value_ >> wutoclr_f::offset));}

	constexpr rtc_wutr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_wutr_r other) const -> rtc_wutr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_wutr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111; // 65535 0xFFFF

private:
	uint32_t value_;
};

/**
 * RTC control register 
 */
class rtc_cr_r {
public:

/**
 * ck_wut wakeup clock selection 10x: ck_spre (usually 1 Hz) clock is selected in BCD mode. In binary or mixed mode, this is the clock selected by BCDU. 11x: ck_spre (usually 1 Hz) clock is selected in BCD mode. In binary or mixed mode, this is the clock selected by BCDU. Furthermore, 216 is added to the WUT counter value.
 */
class wucksel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr wucksel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timestamp event active edge TSE must be reset when TSEDGE is changed to avoid unwanted TSF setting.
 */
class tsedge_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsedge_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC_REFIN reference clock detection enable (50 or 60 Hz) Note: BIN must be 0x00 and PREDIV_S must be 0x00FF.
 */
class refckon_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr refckon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bypass the shadow registers Note: If the frequency of the APB1 clock is less than seven times the frequency of RTCCLK, BYPSHAD must be set to 1.
 */
class bypshad_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bypshad_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hour format
 */
class fmt_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fmt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SSR underflow interrupt enable
 */
class ssruie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ssruie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm A enable
 */
class alrae_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alrae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B enable
 */
class alrbe_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alrbe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer enable Note: When the wakeup timer is disabled, wait for WUTWF = 1 before enabling it again.
 */
class wute_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wute_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * timestamp enable
 */
class tse_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm A interrupt enable
 */
class alraie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alraie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B interrupt enable
 */
class alrbie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr alrbie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer interrupt enable
 */
class wutie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wutie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp interrupt enable
 */
class tsie_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Add 1 hour (summer time change) When this bit is set outside initialization mode, 1 hour is added to the calendar time. This bit is always read as 0.
 */
class add1h_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr add1h_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Subtract 1 hour (winter time change) When this bit is set outside initialization mode, 1 hour is subtracted to the calendar time if the current hour is not 0. This bit is always read as 0. Setting this bit has no effect when current hour is 0.
 */
class sub1h_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sub1h_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup This bit can be written by the user to memorize whether the daylight saving time change has been performed or not.
 */
class bkp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Calibration output selection When COE = 1, this bit selects which signal is output on CALIB. These frequencies are valid for RTCCLK at 32.768 kHz and prescalers at their default values (PREDIV_A = 127 and PREDIV_S = 255). Refer to .
 */
class cosel_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cosel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output polarity This bit is used to configure the polarity of TAMPALRM output.
 */
class pol_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output selection These bits are used to select the flag to be routed to TAMPALRM output.
 */
class osel_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr osel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Calibration output enable This bit enables the CALIB output
 */
class coe_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr coe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * timestamp on internal event enable
 */
class itse_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Activate timestamp on tamper detection event TAMPTS is valid even if TSE = 0 in the RTC_CR register. Timestamp flag is set up to 3 ck_apre cycles after the tamper flags.
 */
class tampts_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tampts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection output enable on TAMPALRM
 */
class tampoe_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tampoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm A flag automatic clear
 */
class alrafclr_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr alrafclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B flag automatic clear
 */
class alrbfclr_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr alrbfclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMPALRM pull-up enable
 */
class tampalrm_pu_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tampalrm_pu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMPALRM output type
 */
class tampalrm_type_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tampalrm_type_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC_OUT2 output enable Setting this bit permits to remap the RTC outputs on RTC_OUT2 as follows: OUT2EN = 0: RTC output 2 disable If OSEL different 00 or TAMPOE = 1: TAMPALRM is output on RTC_OUT1 If OSEL = 00 and TAMPOE = 0 and COE = 1: CALIB is output on RTC_OUT1 OUT2EN = 1: RTC output 2 enable If (OSEL different 00 or TAMPOE = 1) and COE = 0: TAMPALRM is output on RTC_OUT2 If OSEL = 00 and TAMPOE = 0 and COE = 1: CALIB is output on RTC_OUT2 If (OSEL different 00 or TAMPOE = 1) and COE = 1: CALIB is output on RTC_OUT2 and TAMPALRM is output on RTC_OUT1.
 */
class out2en_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr out2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_cr_r>() const {return opsy::utility::clear_set<rtc_cr_r>(mask, *this);}
	constexpr auto operator|(rtc_cr_r other) const -> rtc_cr_r { return static_cast<rtc_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_cr_r> other) const -> opsy::utility::clear_set<rtc_cr_r> {return opsy::utility::clear_set<rtc_cr_r>(rtc_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto wucksel() const -> wucksel_f {return wucksel_f(static_cast<uint8_t>(value_ >> wucksel_f::offset));}
	[[nodiscard]] constexpr auto tsedge() const -> tsedge_f {return tsedge_f((value_ & tsedge_f::mask) != 0);}
	[[nodiscard]] constexpr auto refckon() const -> refckon_f {return refckon_f((value_ & refckon_f::mask) != 0);}
	[[nodiscard]] constexpr auto bypshad() const -> bypshad_f {return bypshad_f((value_ & bypshad_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmt() const -> fmt_f {return fmt_f((value_ & fmt_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssruie() const -> ssruie_f {return ssruie_f((value_ & ssruie_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrae() const -> alrae_f {return alrae_f((value_ & alrae_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbe() const -> alrbe_f {return alrbe_f((value_ & alrbe_f::mask) != 0);}
	[[nodiscard]] constexpr auto wute() const -> wute_f {return wute_f((value_ & wute_f::mask) != 0);}
	[[nodiscard]] constexpr auto tse() const -> tse_f {return tse_f((value_ & tse_f::mask) != 0);}
	[[nodiscard]] constexpr auto alraie() const -> alraie_f {return alraie_f((value_ & alraie_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbie() const -> alrbie_f {return alrbie_f((value_ & alrbie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wutie() const -> wutie_f {return wutie_f((value_ & wutie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsie() const -> tsie_f {return tsie_f((value_ & tsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto add1h() const -> add1h_f {return add1h_f((value_ & add1h_f::mask) != 0);}
	[[nodiscard]] constexpr auto sub1h() const -> sub1h_f {return sub1h_f((value_ & sub1h_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkp() const -> bkp_f {return bkp_f((value_ & bkp_f::mask) != 0);}
	[[nodiscard]] constexpr auto cosel() const -> cosel_f {return cosel_f((value_ & cosel_f::mask) != 0);}
	[[nodiscard]] constexpr auto pol() const -> pol_f {return pol_f((value_ & pol_f::mask) != 0);}
	[[nodiscard]] constexpr auto osel() const -> osel_f {return osel_f(static_cast<uint8_t>(value_ >> osel_f::offset));}
	[[nodiscard]] constexpr auto coe() const -> coe_f {return coe_f((value_ & coe_f::mask) != 0);}
	[[nodiscard]] constexpr auto itse() const -> itse_f {return itse_f((value_ & itse_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampts() const -> tampts_f {return tampts_f((value_ & tampts_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampoe() const -> tampoe_f {return tampoe_f((value_ & tampoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrafclr() const -> alrafclr_f {return alrafclr_f((value_ & alrafclr_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbfclr() const -> alrbfclr_f {return alrbfclr_f((value_ & alrbfclr_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampalrm_pu() const -> tampalrm_pu_f {return tampalrm_pu_f((value_ & tampalrm_pu_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampalrm_type() const -> tampalrm_type_f {return tampalrm_type_f((value_ & tampalrm_type_f::mask) != 0);}
	[[nodiscard]] constexpr auto out2en() const -> out2en_f {return out2en_f((value_ & out2en_f::mask) != 0);}

	constexpr rtc_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_cr_r other) const -> rtc_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC privilege mode control register 
 */
class rtc_privcfgr_r {
public:

/**
 * Alarm A and SSR underflow privilege protection
 */
class alrapriv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrapriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B privilege protection
 */
class alrbpriv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrbpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer privilege protection
 */
class wutpriv_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wutpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp privilege protection
 */
class tspriv_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Shift register, Delight saving, calibration and reference clock privilege protection
 */
class calpriv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr calpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialization privilege protection
 */
class initpriv_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr initpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC privilege protection
 */
class priv_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_privcfgr_r>() const {return opsy::utility::clear_set<rtc_privcfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return static_cast<rtc_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_privcfgr_r> other) const -> opsy::utility::clear_set<rtc_privcfgr_r> {return opsy::utility::clear_set<rtc_privcfgr_r>(rtc_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto alrapriv() const -> alrapriv_f {return alrapriv_f((value_ & alrapriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbpriv() const -> alrbpriv_f {return alrbpriv_f((value_ & alrbpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto wutpriv() const -> wutpriv_f {return wutpriv_f((value_ & wutpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tspriv() const -> tspriv_f {return tspriv_f((value_ & tspriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto calpriv() const -> calpriv_f {return calpriv_f((value_ & calpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto initpriv() const -> initpriv_f {return initpriv_f((value_ & initpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv() const -> priv_f {return priv_f((value_ & priv_f::mask) != 0);}

	constexpr rtc_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_privcfgr_r other) const -> rtc_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC secure configuration register 
 */
class rtc_seccfgr_r {
public:

/**
 * Alarm A and SSR underflow protection
 */
class alrasec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrasec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B protection
 */
class alrbsec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrbsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer protection
 */
class wutsec_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wutsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp protection
 */
class tssec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tssec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Shift register, daylight saving, calibration and reference clock protection
 */
class calsec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr calsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Initialization protection
 */
class initsec_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr initsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTC global protection
 */
class sec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_seccfgr_r>() const {return opsy::utility::clear_set<rtc_seccfgr_r>(mask, *this);}
	constexpr auto operator|(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return static_cast<rtc_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_seccfgr_r> other) const -> opsy::utility::clear_set<rtc_seccfgr_r> {return opsy::utility::clear_set<rtc_seccfgr_r>(rtc_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto alrasec() const -> alrasec_f {return alrasec_f((value_ & alrasec_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbsec() const -> alrbsec_f {return alrbsec_f((value_ & alrbsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wutsec() const -> wutsec_f {return wutsec_f((value_ & wutsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto tssec() const -> tssec_f {return tssec_f((value_ & tssec_f::mask) != 0);}
	[[nodiscard]] constexpr auto calsec() const -> calsec_f {return calsec_f((value_ & calsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto initsec() const -> initsec_f {return initsec_f((value_ & initsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec() const -> sec_f {return sec_f((value_ & sec_f::mask) != 0);}

	constexpr rtc_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_seccfgr_r other) const -> rtc_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC write protection register 
 */
class rtc_wpr_r {
public:

/**
 * Write protection key This byte is written by software. Reading this byte always returns 0x00. Refer to for a description of how to unlock RTC register write protection.
 */
class key_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr key_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_wpr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_wpr_r>() const {return opsy::utility::clear_set<rtc_wpr_r>(mask, *this);}
	constexpr auto operator|(rtc_wpr_r other) const -> rtc_wpr_r { return static_cast<rtc_wpr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_wpr_r> other) const -> opsy::utility::clear_set<rtc_wpr_r> {return opsy::utility::clear_set<rtc_wpr_r>(rtc_wpr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto key() const -> key_f {return key_f(static_cast<uint8_t>(value_ >> key_f::offset));}

	constexpr rtc_wpr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_wpr_r other) const -> rtc_wpr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_wpr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC calibration register 
 */
class rtc_calr_r {
public:

/**
 * Calibration minus The frequency of the calendar is reduced by masking CALM out of 220 RTCCLK pulses (32 seconds if the input frequency is 32768 Hz). This decreases the frequency of the calendar with a resolution of 0.9537 ppm. To increase the frequency of the calendar, this feature should be used in conjunction with CALP. See .
 */
class calm_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr calm_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_calr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_calr_r>() const {return opsy::utility::clear_set<rtc_calr_r>(mask, *this);}
	constexpr auto operator|(rtc_calr_r other) const -> rtc_calr_r { return static_cast<rtc_calr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_calr_r> other) const -> opsy::utility::clear_set<rtc_calr_r> {return opsy::utility::clear_set<rtc_calr_r>(rtc_calr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * RTC low-power mode
 */
class lpcal_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lpcal_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_calr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_calr_r>() const {return opsy::utility::clear_set<rtc_calr_r>(mask, *this);}
	constexpr auto operator|(rtc_calr_r other) const -> rtc_calr_r { return static_cast<rtc_calr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_calr_r> other) const -> opsy::utility::clear_set<rtc_calr_r> {return opsy::utility::clear_set<rtc_calr_r>(rtc_calr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Use a 16-second calibration cycle period When CALW16 is set to 1, the 16-second calibration cycle period is selected. This bit must not be set to 1 if CALW8 = 1. Note: CALM[0] is stuck at 0 when CALW16 = 1. Refer to calibration.
 */
class calw16_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr calw16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_calr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_calr_r>() const {return opsy::utility::clear_set<rtc_calr_r>(mask, *this);}
	constexpr auto operator|(rtc_calr_r other) const -> rtc_calr_r { return static_cast<rtc_calr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_calr_r> other) const -> opsy::utility::clear_set<rtc_calr_r> {return opsy::utility::clear_set<rtc_calr_r>(rtc_calr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Use an 8-second calibration cycle period When CALW8 is set to 1, the 8-second calibration cycle period is selected. Note: CALM[1:0] are stuck at 00 when CALW8 = 1. Refer to digital calibration.
 */
class calw8_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr calw8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_calr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_calr_r>() const {return opsy::utility::clear_set<rtc_calr_r>(mask, *this);}
	constexpr auto operator|(rtc_calr_r other) const -> rtc_calr_r { return static_cast<rtc_calr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_calr_r> other) const -> opsy::utility::clear_set<rtc_calr_r> {return opsy::utility::clear_set<rtc_calr_r>(rtc_calr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Increase frequency of RTC by 488.5 ppm This feature is intended to be used in conjunction with CALM, which lowers the frequency of the calendar with a fine resolution. if the input frequency is 32768 Hz, the number of RTCCLK pulses added during a 32-second window is calculated as follows: (512 CALP)CALM. Refer to .
 */
class calp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr calp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_calr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_calr_r>() const {return opsy::utility::clear_set<rtc_calr_r>(mask, *this);}
	constexpr auto operator|(rtc_calr_r other) const -> rtc_calr_r { return static_cast<rtc_calr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_calr_r> other) const -> opsy::utility::clear_set<rtc_calr_r> {return opsy::utility::clear_set<rtc_calr_r>(rtc_calr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto calm() const -> calm_f {return calm_f(static_cast<uint16_t>(value_ >> calm_f::offset));}
	[[nodiscard]] constexpr auto lpcal() const -> lpcal_f {return lpcal_f((value_ & lpcal_f::mask) != 0);}
	[[nodiscard]] constexpr auto calw16() const -> calw16_f {return calw16_f((value_ & calw16_f::mask) != 0);}
	[[nodiscard]] constexpr auto calw8() const -> calw8_f {return calw8_f((value_ & calw8_f::mask) != 0);}
	[[nodiscard]] constexpr auto calp() const -> calp_f {return calp_f((value_ & calp_f::mask) != 0);}

	constexpr rtc_calr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_calr_r other) const -> rtc_calr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_calr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC shift control register 
 */
class rtc_shiftr_r {
public:

/**
 * Subtract a fraction of a second These bits are write only and is always read as zero. Writing to this bit has no effect when a shift operation is pending (when SHPF = 1, in RTC_ICSR). The value which is written to SUBFS is added to the synchronous prescaler counter. Since this counter counts down, this operation effectively subtracts from (delays) the clock by: Delay (seconds) = SUBFS / (PREDIV_S + 1) A fraction of a second can effectively be added to the clock (advancing the clock) when the ADD1S function is used in conjunction with SUBFS, effectively advancing the clock by: Advance (seconds) = (1(SUBFS / (PREDIV_S + 1))). In mixed BCD-binary mode (BIN=10 or 11), the SUBFS[14:BCDU+8] must be written with 0. Note: Writing to SUBFS causes RSF to be cleared. Software can then wait until RSF = 1 to be sure that the shadow registers have been updated with the shifted time.
 */
class subfs_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 15;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr subfs_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_shiftr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_shiftr_r>() const {return opsy::utility::clear_set<rtc_shiftr_r>(mask, *this);}
	constexpr auto operator|(rtc_shiftr_r other) const -> rtc_shiftr_r { return static_cast<rtc_shiftr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_shiftr_r> other) const -> opsy::utility::clear_set<rtc_shiftr_r> {return opsy::utility::clear_set<rtc_shiftr_r>(rtc_shiftr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Add one second This bit is write only and is always read as zero. Writing to this bit has no effect when a shift operation is pending (when SHPF = 1, in RTC_ICSR). This function is intended to be used with SUBFS (see description below) in order to effectively add a fraction of a second to the clock in an atomic operation.
 */
class add1s_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr add1s_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_shiftr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_shiftr_r>() const {return opsy::utility::clear_set<rtc_shiftr_r>(mask, *this);}
	constexpr auto operator|(rtc_shiftr_r other) const -> rtc_shiftr_r { return static_cast<rtc_shiftr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_shiftr_r> other) const -> opsy::utility::clear_set<rtc_shiftr_r> {return opsy::utility::clear_set<rtc_shiftr_r>(rtc_shiftr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto subfs() const -> subfs_f {return subfs_f(static_cast<uint16_t>(value_ >> subfs_f::offset));}
	[[nodiscard]] constexpr auto add1s() const -> add1s_f {return add1s_f((value_ & add1s_f::mask) != 0);}

	constexpr rtc_shiftr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_shiftr_r other) const -> rtc_shiftr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_shiftr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC timestamp time register 
 */
class rtc_tstr_r {
public:

/**
 * Second units in BCD format.
 */
class su_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr su_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Second tens in BCD format.
 */
class st_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr st_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Minute units in BCD format.
 */
class mnu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Minute tens in BCD format.
 */
class mnt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Hour units in BCD format.
 */
class hu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Hour tens in BCD format.
 */
class ht_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tstr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * AM/PM notation
 */
class pm_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_tstr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_tstr_r>() const {return opsy::utility::clear_set<rtc_tstr_r>(mask, *this);}
	constexpr auto operator|(rtc_tstr_r other) const -> rtc_tstr_r { return static_cast<rtc_tstr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tstr_r> other) const -> opsy::utility::clear_set<rtc_tstr_r> {return opsy::utility::clear_set<rtc_tstr_r>(rtc_tstr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto su() const -> su_f {return su_f(static_cast<uint8_t>(value_ >> su_f::offset));}
	[[nodiscard]] constexpr auto st() const -> st_f {return st_f(static_cast<uint8_t>(value_ >> st_f::offset));}
	[[nodiscard]] constexpr auto mnu() const -> mnu_f {return mnu_f(static_cast<uint8_t>(value_ >> mnu_f::offset));}
	[[nodiscard]] constexpr auto mnt() const -> mnt_f {return mnt_f(static_cast<uint8_t>(value_ >> mnt_f::offset));}
	[[nodiscard]] constexpr auto hu() const -> hu_f {return hu_f(static_cast<uint8_t>(value_ >> hu_f::offset));}
	[[nodiscard]] constexpr auto ht() const -> ht_f {return ht_f(static_cast<uint8_t>(value_ >> ht_f::offset));}
	[[nodiscard]] constexpr auto pm() const -> pm_f {return pm_f((value_ & pm_f::mask) != 0);}

	constexpr rtc_tstr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_tstr_r other) const -> rtc_tstr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_tstr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC timestamp date register 
 */
class rtc_tsdr_r {
public:

/**
 * Date units in BCD format
 */
class du_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr du_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tsdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tsdr_r>() const {return opsy::utility::clear_set<rtc_tsdr_r>(mask, *this);}
	constexpr auto operator|(rtc_tsdr_r other) const -> rtc_tsdr_r { return static_cast<rtc_tsdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tsdr_r> other) const -> opsy::utility::clear_set<rtc_tsdr_r> {return opsy::utility::clear_set<rtc_tsdr_r>(rtc_tsdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Date tens in BCD format
 */
class dt_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tsdr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tsdr_r>() const {return opsy::utility::clear_set<rtc_tsdr_r>(mask, *this);}
	constexpr auto operator|(rtc_tsdr_r other) const -> rtc_tsdr_r { return static_cast<rtc_tsdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tsdr_r> other) const -> opsy::utility::clear_set<rtc_tsdr_r> {return opsy::utility::clear_set<rtc_tsdr_r>(rtc_tsdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Month units in BCD format
 */
class mu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tsdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tsdr_r>() const {return opsy::utility::clear_set<rtc_tsdr_r>(mask, *this);}
	constexpr auto operator|(rtc_tsdr_r other) const -> rtc_tsdr_r { return static_cast<rtc_tsdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tsdr_r> other) const -> opsy::utility::clear_set<rtc_tsdr_r> {return opsy::utility::clear_set<rtc_tsdr_r>(rtc_tsdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Month tens in BCD format
 */
class mt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_tsdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_tsdr_r>() const {return opsy::utility::clear_set<rtc_tsdr_r>(mask, *this);}
	constexpr auto operator|(rtc_tsdr_r other) const -> rtc_tsdr_r { return static_cast<rtc_tsdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tsdr_r> other) const -> opsy::utility::clear_set<rtc_tsdr_r> {return opsy::utility::clear_set<rtc_tsdr_r>(rtc_tsdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Week day units
 */
class wdu_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wdu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_tsdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_tsdr_r>() const {return opsy::utility::clear_set<rtc_tsdr_r>(mask, *this);}
	constexpr auto operator|(rtc_tsdr_r other) const -> rtc_tsdr_r { return static_cast<rtc_tsdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_tsdr_r> other) const -> opsy::utility::clear_set<rtc_tsdr_r> {return opsy::utility::clear_set<rtc_tsdr_r>(rtc_tsdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto du() const -> du_f {return du_f(static_cast<uint8_t>(value_ >> du_f::offset));}
	[[nodiscard]] constexpr auto dt() const -> dt_f {return dt_f(static_cast<uint8_t>(value_ >> dt_f::offset));}
	[[nodiscard]] constexpr auto mu() const -> mu_f {return mu_f(static_cast<uint8_t>(value_ >> mu_f::offset));}
	[[nodiscard]] constexpr auto mt() const -> mt_f {return mt_f((value_ & mt_f::mask) != 0);}
	[[nodiscard]] constexpr auto wdu() const -> wdu_f {return wdu_f(static_cast<uint8_t>(value_ >> wdu_f::offset));}

	constexpr rtc_tsdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_tsdr_r other) const -> rtc_tsdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_tsdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC alarm X register 
 */
class rtc_alrmxr_r {
public:

/**
 * Second units in BCD format.
 */
class su_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr su_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Second tens in BCD format.
 */
class st_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr st_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alarm A seconds mask
 */
class msk1_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr msk1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Minute units in BCD format
 */
class mnu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Minute tens in BCD format
 */
class mnt_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alarm A minutes mask
 */
class msk2_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr msk2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hour units in BCD format
 */
class hu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hu_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Hour tens in BCD format
 */
class ht_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ht_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * AM/PM notation
 */
class pm_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm A hours mask
 */
class msk3_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr msk3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Date units or day in BCD format
 */
class du_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr du_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Date tens in BCD format
 */
class dt_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Week day selection
 */
class wdsel_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm A date mask
 */
class msk4_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr msk4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxr_r>() const {return opsy::utility::clear_set<rtc_alrmxr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return static_cast<rtc_alrmxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxr_r> other) const -> opsy::utility::clear_set<rtc_alrmxr_r> {return opsy::utility::clear_set<rtc_alrmxr_r>(rtc_alrmxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto su() const -> su_f {return su_f(static_cast<uint8_t>(value_ >> su_f::offset));}
	[[nodiscard]] constexpr auto st() const -> st_f {return st_f(static_cast<uint8_t>(value_ >> st_f::offset));}
	[[nodiscard]] constexpr auto msk1() const -> msk1_f {return msk1_f((value_ & msk1_f::mask) != 0);}
	[[nodiscard]] constexpr auto mnu() const -> mnu_f {return mnu_f(static_cast<uint8_t>(value_ >> mnu_f::offset));}
	[[nodiscard]] constexpr auto mnt() const -> mnt_f {return mnt_f(static_cast<uint8_t>(value_ >> mnt_f::offset));}
	[[nodiscard]] constexpr auto msk2() const -> msk2_f {return msk2_f((value_ & msk2_f::mask) != 0);}
	[[nodiscard]] constexpr auto hu() const -> hu_f {return hu_f(static_cast<uint8_t>(value_ >> hu_f::offset));}
	[[nodiscard]] constexpr auto ht() const -> ht_f {return ht_f(static_cast<uint8_t>(value_ >> ht_f::offset));}
	[[nodiscard]] constexpr auto pm() const -> pm_f {return pm_f((value_ & pm_f::mask) != 0);}
	[[nodiscard]] constexpr auto msk3() const -> msk3_f {return msk3_f((value_ & msk3_f::mask) != 0);}
	[[nodiscard]] constexpr auto du() const -> du_f {return du_f(static_cast<uint8_t>(value_ >> du_f::offset));}
	[[nodiscard]] constexpr auto dt() const -> dt_f {return dt_f(static_cast<uint8_t>(value_ >> dt_f::offset));}
	[[nodiscard]] constexpr auto wdsel() const -> wdsel_f {return wdsel_f((value_ & wdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto msk4() const -> msk4_f {return msk4_f((value_ & msk4_f::mask) != 0);}

	constexpr rtc_alrmxr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_alrmxr_r other) const -> rtc_alrmxr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_alrmxr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC alarm X sub second register 
 */
class rtc_alrmxssr_r {
public:

/**
 * Sub seconds value This value is compared with the contents of the synchronous prescaler counter to determine if alarm A is to be activated. Only bits 0 up MASKSS-1 are compared. This field is the mirror of SS[14:0] in the RTC_ALRMABINR, and so can also be read or written through RTC_ALRMABINR.
 */
class ss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 15;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ss_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator rtc_alrmxssr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxssr_r>() const {return opsy::utility::clear_set<rtc_alrmxssr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxssr_r other) const -> rtc_alrmxssr_r { return static_cast<rtc_alrmxssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxssr_r> other) const -> opsy::utility::clear_set<rtc_alrmxssr_r> {return opsy::utility::clear_set<rtc_alrmxssr_r>(rtc_alrmxssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Mask the most-significant bits starting at this bit 2: SS[31:2] are don't care in Alarm A comparison. Only SS[1:0] are compared. ... 31: SS[31] is don't care in Alarm A comparison. Only SS[30:0] are compared. From 32 to 63: All 32 SS bits are compared and must match to activate alarm. Note: In BCD mode (BIN=00) the overflow bits of the synchronous counter (bits 31:15) are never compared. These bits can be different from 0 only after a shift operation.
 */
class maskss_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr maskss_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator rtc_alrmxssr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrmxssr_r>() const {return opsy::utility::clear_set<rtc_alrmxssr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxssr_r other) const -> rtc_alrmxssr_r { return static_cast<rtc_alrmxssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxssr_r> other) const -> opsy::utility::clear_set<rtc_alrmxssr_r> {return opsy::utility::clear_set<rtc_alrmxssr_r>(rtc_alrmxssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clear synchronous counter on alarm (Binary mode only) Note: SSCLR must be kept to 0 when BCD or mixed mode is used (BIN = 00, 10 or 11).
 */
class ssclr_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ssclr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_alrmxssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_alrmxssr_r>() const {return opsy::utility::clear_set<rtc_alrmxssr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrmxssr_r other) const -> rtc_alrmxssr_r { return static_cast<rtc_alrmxssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrmxssr_r> other) const -> opsy::utility::clear_set<rtc_alrmxssr_r> {return opsy::utility::clear_set<rtc_alrmxssr_r>(rtc_alrmxssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ss() const -> ss_f {return ss_f(static_cast<uint16_t>(value_ >> ss_f::offset));}
	[[nodiscard]] constexpr auto maskss() const -> maskss_f {return maskss_f(static_cast<uint8_t>(value_ >> maskss_f::offset));}
	[[nodiscard]] constexpr auto ssclr() const -> ssclr_f {return ssclr_f((value_ & ssclr_f::mask) != 0);}

	constexpr rtc_alrmxssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_alrmxssr_r other) const -> rtc_alrmxssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_alrmxssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC status register 
 */
class rtc_sr_r {
public:

/**
 * Alarm A flag This flag is set by hardware when the time/date registers (RTC_TR and RTC_DR) match the alarm A register (RTC_ALRMAR).
 */
class alraf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alraf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B flag This flag is set by hardware when the time/date registers (RTC_TR and RTC_DR) match the alarm B register (RTC_ALRMBR).
 */
class alrbf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer flag This flag is set by hardware when the wakeup auto-reload counter reaches 0. If WUTOCLR[15:0] is different from 0x0000, WUTF is cleared by hardware when the wakeup auto-reload counter reaches WUTOCLR value. If WUTOCLR[15:0] is 0x0000, WUTF must be cleared by software. This flag must be cleared by software at least 1.5 RTCCLK periods before WUTF is set to 1 again.
 */
class wutf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wutf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp flag This flag is set by hardware when a timestamp event occurs. If ITSF flag is set, TSF must be cleared together with ITSF. Note: TSF is not set if TAMPTS = 1 and the tamper flag is read during the 3 ck_apre cycles following tamper event. Refer to for more details.
 */
class tsf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp overflow flag This flag is set by hardware when a timestamp event occurs while TSF is already set. It is recommended to check and then clear TSOVF only after clearing the TSF bit. Otherwise, an overflow might not be noticed if a timestamp event occurs immediately before the TSF bit is cleared.
 */
class tsovf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal timestamp flag This flag is set by hardware when a timestamp on the internal event occurs.
 */
class itsf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SSR underflow flag This flag is set by hardware when the SSR rolls under 0. SSRUF is not set when SSCLR=1.
 */
class ssruf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ssruf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_sr_r>() const {return opsy::utility::clear_set<rtc_sr_r>(mask, *this);}
	constexpr auto operator|(rtc_sr_r other) const -> rtc_sr_r { return static_cast<rtc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_sr_r> other) const -> opsy::utility::clear_set<rtc_sr_r> {return opsy::utility::clear_set<rtc_sr_r>(rtc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto alraf() const -> alraf_f {return alraf_f((value_ & alraf_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbf() const -> alrbf_f {return alrbf_f((value_ & alrbf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wutf() const -> wutf_f {return wutf_f((value_ & wutf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsf() const -> tsf_f {return tsf_f((value_ & tsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsovf() const -> tsovf_f {return tsovf_f((value_ & tsovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itsf() const -> itsf_f {return itsf_f((value_ & itsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssruf() const -> ssruf_f {return ssruf_f((value_ & ssruf_f::mask) != 0);}

	constexpr rtc_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_sr_r other) const -> rtc_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC non-secure masked interrupt status register 
 */
class rtc_misr_r {
public:

/**
 * Alarm A masked flag This flag is set by hardware when the alarm A non-secure interrupt occurs.
 */
class alramf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alramf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alarm B non-secure masked flag This flag is set by hardware when the alarm B non-secure interrupt occurs.
 */
class alrbmf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alrbmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wakeup timer non-secure masked flag This flag is set by hardware when the wakeup timer non-secure interrupt occurs. This flag must be cleared by software at least 1.5 RTCCLK periods before WUTF is set to 1 again.
 */
class wutmf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wutmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp non-secure masked flag This flag is set by hardware when a timestamp non-secure interrupt occurs. If ITSF flag is set, TSF must be cleared together with ITSF.
 */
class tsmf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timestamp overflow non-secure masked flag This flag is set by hardware when a timestamp interrupt occurs while TSMF is already set. It is recommended to check and then clear TSOVF only after clearing the TSF bit. Otherwise, an overflow might not be noticed if a timestamp event occurs immediately before the TSF bit is cleared.
 */
class tsovmf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tsovmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal timestamp non-secure masked flag This flag is set by hardware when a timestamp on the internal event occurs and timestamp non-secure interrupt is raised.
 */
class itsmf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itsmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SSR underflow non-secure masked flag This flag is set by hardware when the SSR underflow non-secure interrupt occurs.
 */
class ssrumf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ssrumf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_misr_r>() const {return opsy::utility::clear_set<rtc_misr_r>(mask, *this);}
	constexpr auto operator|(rtc_misr_r other) const -> rtc_misr_r { return static_cast<rtc_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_misr_r> other) const -> opsy::utility::clear_set<rtc_misr_r> {return opsy::utility::clear_set<rtc_misr_r>(rtc_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto alramf() const -> alramf_f {return alramf_f((value_ & alramf_f::mask) != 0);}
	[[nodiscard]] constexpr auto alrbmf() const -> alrbmf_f {return alrbmf_f((value_ & alrbmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wutmf() const -> wutmf_f {return wutmf_f((value_ & wutmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsmf() const -> tsmf_f {return tsmf_f((value_ & tsmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsovmf() const -> tsovmf_f {return tsovmf_f((value_ & tsovmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itsmf() const -> itsmf_f {return itsmf_f((value_ & itsmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssrumf() const -> ssrumf_f {return ssrumf_f((value_ & ssrumf_f::mask) != 0);}

	constexpr rtc_misr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_misr_r other) const -> rtc_misr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_misr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC status clear register 
 */
class rtc_scr_r {
public:

/**
 * Clear alarm A flag Writing 1 in this bit clears the ALRAF bit in the RTC_SR register.
 */
class calraf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr calraf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear alarm B flag Writing 1 in this bit clears the ALRBF bit in the RTC_SR register.
 */
class calrbf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr calrbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear wakeup timer flag Writing 1 in this bit clears the WUTF bit in the RTC_SR register.
 */
class cwutf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwutf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear timestamp flag Writing 1 in this bit clears the TSOVF bit in the RTC_SR register. If ITSF flag is set, TSF must be cleared together with ITSF by setting CRSF and CITSF.
 */
class ctsf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear timestamp overflow flag Writing 1 in this bit clears the TSOVF bit in the RTC_SR register. It is recommended to check and then clear TSOVF only after clearing the TSF bit. Otherwise, an overflow might not be noticed if a timestamp event occurs immediately before the TSF bit is cleared.
 */
class ctsovf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctsovf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear internal timestamp flag Writing 1 in this bit clears the ITSF bit in the RTC_SR register.
 */
class citsf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr citsf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear SSR underflow flag Writing '1' in this bit clears the SSRUF in the RTC_SR register.
 */
class cssruf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cssruf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_scr_r>() const {return opsy::utility::clear_set<rtc_scr_r>(mask, *this);}
	constexpr auto operator|(rtc_scr_r other) const -> rtc_scr_r { return static_cast<rtc_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_scr_r> other) const -> opsy::utility::clear_set<rtc_scr_r> {return opsy::utility::clear_set<rtc_scr_r>(rtc_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto calraf() const -> calraf_f {return calraf_f((value_ & calraf_f::mask) != 0);}
	[[nodiscard]] constexpr auto calrbf() const -> calrbf_f {return calrbf_f((value_ & calrbf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwutf() const -> cwutf_f {return cwutf_f((value_ & cwutf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsf() const -> ctsf_f {return ctsf_f((value_ & ctsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsovf() const -> ctsovf_f {return ctsovf_f((value_ & ctsovf_f::mask) != 0);}
	[[nodiscard]] constexpr auto citsf() const -> citsf_f {return citsf_f((value_ & citsf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cssruf() const -> cssruf_f {return cssruf_f((value_ & cssruf_f::mask) != 0);}

	constexpr rtc_scr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_scr_r other) const -> rtc_scr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_scr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC option register 
 */
class rtc_or_r {
public:

/**
 * RTC_OUT2 mapping
 */
class out2_rmp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr out2_rmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator rtc_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<rtc_or_r>() const {return opsy::utility::clear_set<rtc_or_r>(mask, *this);}
	constexpr auto operator|(rtc_or_r other) const -> rtc_or_r { return static_cast<rtc_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_or_r> other) const -> opsy::utility::clear_set<rtc_or_r> {return opsy::utility::clear_set<rtc_or_r>(rtc_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto out2_rmp() const -> out2_rmp_f {return out2_rmp_f((value_ & out2_rmp_f::mask) != 0);}

	constexpr rtc_or_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_or_r other) const -> rtc_or_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_or_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RTC alarm X binary mode register 
 */
class rtc_alrxbinr_r {
public:

/**
 * Synchronous counter alarm value in Binary mode This value is compared with the contents of the synchronous counter to determine if Alarm A is to be activated. Only bits 0 up MASKSS-1 are compared. SS[14:0] is the mirror of SS[14:0] in the RTC_ALRMASSRR, and so can also be read or written through RTC_ALRMASSR.
 */
class ss_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ss_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator rtc_alrxbinr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<rtc_alrxbinr_r>() const {return opsy::utility::clear_set<rtc_alrxbinr_r>(mask, *this);}
	constexpr auto operator|(rtc_alrxbinr_r other) const -> rtc_alrxbinr_r { return static_cast<rtc_alrxbinr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<rtc_alrxbinr_r> other) const -> opsy::utility::clear_set<rtc_alrxbinr_r> {return opsy::utility::clear_set<rtc_alrxbinr_r>(rtc_alrxbinr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ss() const -> ss_f {return ss_f(static_cast<uint32_t>(value_ >> ss_f::offset));}

	constexpr rtc_alrxbinr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(rtc_alrxbinr_r other) const -> rtc_alrxbinr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> rtc_alrxbinr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,rtc_tr_r> rtc_tr;
	opsy::utility::memory<uint32_t,rtc_dr_r> rtc_dr;
	opsy::utility::memory<uint32_t,rtc_ssr_r> rtc_ssr;
	opsy::utility::memory<uint32_t,rtc_icsr_r> rtc_icsr;
	opsy::utility::memory<uint32_t,rtc_prer_r> rtc_prer;
	opsy::utility::memory<uint32_t,rtc_wutr_r> rtc_wutr;
	opsy::utility::memory<uint32_t,rtc_cr_r> rtc_cr;
	opsy::utility::memory<uint32_t,rtc_privcfgr_r> rtc_privcfgr;
	opsy::utility::memory<uint32_t,rtc_seccfgr_r> rtc_seccfgr;
	opsy::utility::memory<uint32_t,rtc_wpr_r> rtc_wpr;
	opsy::utility::memory<uint32_t,rtc_calr_r> rtc_calr;
	opsy::utility::memory<uint32_t,rtc_shiftr_r> rtc_shiftr;
	opsy::utility::memory<uint32_t,rtc_tstr_r> rtc_tstr;
	opsy::utility::memory<uint32_t,rtc_tsdr_r> rtc_tsdr;
	opsy::utility::memory<uint32_t,rtc_ssr_r> rtc_tsssr;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,rtc_alrmxr_r> rtc_alrmar;
	opsy::utility::memory<uint32_t,rtc_alrmxssr_r> rtc_alrmassr;
	opsy::utility::memory<uint32_t,rtc_alrmxr_r> rtc_alrmbr;
	opsy::utility::memory<uint32_t,rtc_alrmxssr_r> rtc_alrmbssr;
	opsy::utility::memory<uint32_t,rtc_sr_r> rtc_sr;
	opsy::utility::memory<uint32_t,rtc_misr_r> rtc_misr;
	opsy::utility::memory<uint32_t,rtc_misr_r> rtc_smisr;
	opsy::utility::memory<uint32_t,rtc_scr_r> rtc_scr;
	opsy::utility::memory<uint32_t,rtc_or_r> rtc_or;
	opsy::utility::padding<12> _p1;
	opsy::utility::memory<uint32_t,rtc_alrxbinr_r> rtc_alrabinr;
	opsy::utility::memory<uint32_t,rtc_alrxbinr_r> rtc_alrbbinr;
};

static_assert(std::is_standard_layout_v<rtc_p>);
static_assert(offsetof(rtc_p, rtc_tr) == 0);
static_assert(offsetof(rtc_p, rtc_dr) == 4);
static_assert(offsetof(rtc_p, rtc_ssr) == 8);
static_assert(offsetof(rtc_p, rtc_icsr) == 12);
static_assert(offsetof(rtc_p, rtc_prer) == 16);
static_assert(offsetof(rtc_p, rtc_wutr) == 20);
static_assert(offsetof(rtc_p, rtc_cr) == 24);
static_assert(offsetof(rtc_p, rtc_privcfgr) == 28);
static_assert(offsetof(rtc_p, rtc_seccfgr) == 32);
static_assert(offsetof(rtc_p, rtc_wpr) == 36);
static_assert(offsetof(rtc_p, rtc_calr) == 40);
static_assert(offsetof(rtc_p, rtc_shiftr) == 44);
static_assert(offsetof(rtc_p, rtc_tstr) == 48);
static_assert(offsetof(rtc_p, rtc_tsdr) == 52);
static_assert(offsetof(rtc_p, rtc_tsssr) == 56);
static_assert(offsetof(rtc_p, rtc_alrmar) == 64);
static_assert(offsetof(rtc_p, rtc_alrmassr) == 68);
static_assert(offsetof(rtc_p, rtc_alrmbr) == 72);
static_assert(offsetof(rtc_p, rtc_alrmbssr) == 76);
static_assert(offsetof(rtc_p, rtc_sr) == 80);
static_assert(offsetof(rtc_p, rtc_misr) == 84);
static_assert(offsetof(rtc_p, rtc_smisr) == 88);
static_assert(offsetof(rtc_p, rtc_scr) == 92);
static_assert(offsetof(rtc_p, rtc_or) == 96);
static_assert(offsetof(rtc_p, rtc_alrabinr) == 112);
static_assert(offsetof(rtc_p, rtc_alrbbinr) == 116);

inline rtc_p& rtc = *reinterpret_cast<rtc_p*>(0x44007800);
inline rtc_p& sec_rtc = *reinterpret_cast<rtc_p*>(0x54007800);

} // STM32H563

