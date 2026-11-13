#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * TIM7 address block description
 */
class tim7_p {
public:

/**
 * TIM7 control register 1
 */
class tim7_cr1_r {
public:

/**
 * Counter enable 
 */
class cen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update disable 
 */
class udis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr udis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update request source 
 */
class urs_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr urs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * One-pulse mode
 */
class opm_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr opm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Auto-reload preload enable
 */
class arpe_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arpe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * UIF status bit remapping
 */
class uifremap_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uifremap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Dithering enable 
 */
class dithen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dithen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cr1_r>() const {return opsy::utility::clear_set<tim7_cr1_r>(mask, *this);}
	constexpr auto operator|(tim7_cr1_r other) const -> tim7_cr1_r { return static_cast<tim7_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr1_r> other) const -> opsy::utility::clear_set<tim7_cr1_r> {return opsy::utility::clear_set<tim7_cr1_r>(tim7_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cen() const -> cen_f {return cen_f((value_ & cen_f::mask) != 0);}
	[[nodiscard]] constexpr auto udis() const -> udis_f {return udis_f((value_ & udis_f::mask) != 0);}
	[[nodiscard]] constexpr auto urs() const -> urs_f {return urs_f((value_ & urs_f::mask) != 0);}
	[[nodiscard]] constexpr auto opm() const -> opm_f {return opm_f((value_ & opm_f::mask) != 0);}
	[[nodiscard]] constexpr auto arpe() const -> arpe_f {return arpe_f((value_ & arpe_f::mask) != 0);}
	[[nodiscard]] constexpr auto uifremap() const -> uifremap_f {return uifremap_f((value_ & uifremap_f::mask) != 0);}
	[[nodiscard]] constexpr auto dithen() const -> dithen_f {return dithen_f((value_ & dithen_f::mask) != 0);}

	constexpr tim7_cr1_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_cr1_r other) const -> tim7_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 control register 2
 */
class tim7_cr2_r {
public:

/**
 * Master mode selection 
 */
class mms_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mms_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim7_cr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim7_cr2_r>() const {return opsy::utility::clear_set<tim7_cr2_r>(mask, *this);}
	constexpr auto operator|(tim7_cr2_r other) const -> tim7_cr2_r { return static_cast<tim7_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cr2_r> other) const -> opsy::utility::clear_set<tim7_cr2_r> {return opsy::utility::clear_set<tim7_cr2_r>(tim7_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto mms() const -> mms_f {return mms_f(static_cast<uint8_t>(value_ >> mms_f::offset));}

	constexpr tim7_cr2_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_cr2_r other) const -> tim7_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 DMA/Interrupt enable register
 */
class tim7_dier_r {
public:

/**
 * Update interrupt enable
 */
class uie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_dier_r>() const {return opsy::utility::clear_set<tim7_dier_r>(mask, *this);}
	constexpr auto operator|(tim7_dier_r other) const -> tim7_dier_r { return static_cast<tim7_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_dier_r> other) const -> opsy::utility::clear_set<tim7_dier_r> {return opsy::utility::clear_set<tim7_dier_r>(tim7_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update DMA request enable
 */
class ude_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ude_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_dier_r>() const {return opsy::utility::clear_set<tim7_dier_r>(mask, *this);}
	constexpr auto operator|(tim7_dier_r other) const -> tim7_dier_r { return static_cast<tim7_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_dier_r> other) const -> opsy::utility::clear_set<tim7_dier_r> {return opsy::utility::clear_set<tim7_dier_r>(tim7_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uie() const -> uie_f {return uie_f((value_ & uie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ude() const -> ude_f {return ude_f((value_ & ude_f::mask) != 0);}

	constexpr tim7_dier_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_dier_r other) const -> tim7_dier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_dier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 status register
 */
class tim7_sr_r {
public:

/**
 * Update interrupt flag 
 */
class uif_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_sr_r>() const {return opsy::utility::clear_set<tim7_sr_r>(mask, *this);}
	constexpr auto operator|(tim7_sr_r other) const -> tim7_sr_r { return static_cast<tim7_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_sr_r> other) const -> opsy::utility::clear_set<tim7_sr_r> {return opsy::utility::clear_set<tim7_sr_r>(tim7_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uif() const -> uif_f {return uif_f((value_ & uif_f::mask) != 0);}

	constexpr tim7_sr_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_sr_r other) const -> tim7_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 event generation register
 */
class tim7_egr_r {
public:

/**
 * Update generation 
 */
class ug_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ug_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_egr_r>() const {return opsy::utility::clear_set<tim7_egr_r>(mask, *this);}
	constexpr auto operator|(tim7_egr_r other) const -> tim7_egr_r { return static_cast<tim7_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_egr_r> other) const -> opsy::utility::clear_set<tim7_egr_r> {return opsy::utility::clear_set<tim7_egr_r>(tim7_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ug() const -> ug_f {return ug_f((value_ & ug_f::mask) != 0);}

	constexpr tim7_egr_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_egr_r other) const -> tim7_egr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_egr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 counter
 */
class tim7_cnt_r {
public:

/**
 * Counter value 
 */
class cnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator tim7_cnt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim7_cnt_r>() const {return opsy::utility::clear_set<tim7_cnt_r>(mask, *this);}
	constexpr auto operator|(tim7_cnt_r other) const -> tim7_cnt_r { return static_cast<tim7_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cnt_r> other) const -> opsy::utility::clear_set<tim7_cnt_r> {return opsy::utility::clear_set<tim7_cnt_r>(tim7_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * UIF copy 
 */
class uifcpy_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uifcpy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim7_cnt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim7_cnt_r>() const {return opsy::utility::clear_set<tim7_cnt_r>(mask, *this);}
	constexpr auto operator|(tim7_cnt_r other) const -> tim7_cnt_r { return static_cast<tim7_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_cnt_r> other) const -> opsy::utility::clear_set<tim7_cnt_r> {return opsy::utility::clear_set<tim7_cnt_r>(tim7_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cnt() const -> cnt_f {return cnt_f(static_cast<uint16_t>(value_ >> cnt_f::offset));}
	[[nodiscard]] constexpr auto uifcpy() const -> uifcpy_f {return uifcpy_f((value_ & uifcpy_f::mask) != 0);}

	constexpr tim7_cnt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim7_cnt_r other) const -> tim7_cnt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_cnt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM7 prescaler
 */
class tim7_psc_r {
public:

/**
 * Prescaler value 
 */
class psc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr psc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator tim7_psc_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim7_psc_r>() const {return opsy::utility::clear_set<tim7_psc_r>(mask, *this);}
	constexpr auto operator|(tim7_psc_r other) const -> tim7_psc_r { return static_cast<tim7_psc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_psc_r> other) const -> opsy::utility::clear_set<tim7_psc_r> {return opsy::utility::clear_set<tim7_psc_r>(tim7_psc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto psc() const -> psc_f {return psc_f(static_cast<uint16_t>(value_ >> psc_f::offset));}

	constexpr tim7_psc_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim7_psc_r other) const -> tim7_psc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_psc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM7 auto-reload register
 */
class tim7_arr_r {
public:

/**
 * Auto-reload value 
 */
class arr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr arr_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim7_arr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim7_arr_r>() const {return opsy::utility::clear_set<tim7_arr_r>(mask, *this);}
	constexpr auto operator|(tim7_arr_r other) const -> tim7_arr_r { return static_cast<tim7_arr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim7_arr_r> other) const -> opsy::utility::clear_set<tim7_arr_r> {return opsy::utility::clear_set<tim7_arr_r>(tim7_arr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto arr() const -> arr_f {return arr_f(static_cast<uint32_t>(value_ >> arr_f::offset));}

	constexpr tim7_arr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim7_arr_r other) const -> tim7_arr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim7_arr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111; // 65535 0xFFFF

private:
	uint32_t value_;
};

	opsy::utility::memory<uint16_t,tim7_cr1_r> tim7_cr1;
	opsy::utility::padding<2> _p2;
	opsy::utility::memory<uint16_t,tim7_cr2_r> tim7_cr2;
	opsy::utility::padding<6> _p6;
	opsy::utility::memory<uint16_t,tim7_dier_r> tim7_dier;
	opsy::utility::padding<2> _p14;
	opsy::utility::memory<uint16_t,tim7_sr_r> tim7_sr;
	opsy::utility::padding<2> _p18;
	opsy::utility::write_only_memory<uint16_t,tim7_egr_r> tim7_egr;
	opsy::utility::padding<14> _p22;
	opsy::utility::memory<uint32_t,tim7_cnt_r> tim7_cnt;
	opsy::utility::memory<uint16_t,tim7_psc_r> tim7_psc;
	opsy::utility::padding<2> _p42;
	opsy::utility::memory<uint32_t,tim7_arr_r> tim7_arr;
};

static_assert(std::is_standard_layout_v<tim7_p>);
static_assert(offsetof(tim7_p, tim7_cr1) == 0);
static_assert(offsetof(tim7_p, tim7_cr2) == 4);
static_assert(offsetof(tim7_p, tim7_dier) == 12);
static_assert(offsetof(tim7_p, tim7_sr) == 16);
static_assert(offsetof(tim7_p, tim7_egr) == 20);
static_assert(offsetof(tim7_p, tim7_cnt) == 36);
static_assert(offsetof(tim7_p, tim7_psc) == 40);
static_assert(offsetof(tim7_p, tim7_arr) == 44);

inline tim7_p& tim7 = *reinterpret_cast<tim7_p*>(0x40001400);
inline tim7_p& tim7_s = *reinterpret_cast<tim7_p*>(0x50001400);

} // STM32H523

