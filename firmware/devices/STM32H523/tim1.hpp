#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * TIM1 address block description
 */
class tim1_p {
public:

/**
 * TIM1 control register 1
 */
class tim1_cr1_r {
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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction 
 */
class dir_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Center-aligned mode selection 
 */
class cms_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cms_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_cr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock division 
 */
class ckd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ckd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_cr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr1_r>() const {return opsy::utility::clear_set<tim1_cr1_r>(mask, *this);}
	constexpr auto operator|(tim1_cr1_r other) const -> tim1_cr1_r { return static_cast<tim1_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr1_r> other) const -> opsy::utility::clear_set<tim1_cr1_r> {return opsy::utility::clear_set<tim1_cr1_r>(tim1_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cen() const -> cen_f {return cen_f((value_ & cen_f::mask) != 0);}
	[[nodiscard]] constexpr auto udis() const -> udis_f {return udis_f((value_ & udis_f::mask) != 0);}
	[[nodiscard]] constexpr auto urs() const -> urs_f {return urs_f((value_ & urs_f::mask) != 0);}
	[[nodiscard]] constexpr auto opm() const -> opm_f {return opm_f((value_ & opm_f::mask) != 0);}
	[[nodiscard]] constexpr auto dir() const -> dir_f {return dir_f((value_ & dir_f::mask) != 0);}
	[[nodiscard]] constexpr auto cms() const -> cms_f {return cms_f(static_cast<uint8_t>(value_ >> cms_f::offset));}
	[[nodiscard]] constexpr auto arpe() const -> arpe_f {return arpe_f((value_ & arpe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckd() const -> ckd_f {return ckd_f(static_cast<uint8_t>(value_ >> ckd_f::offset));}
	[[nodiscard]] constexpr auto uifremap() const -> uifremap_f {return uifremap_f((value_ & uifremap_f::mask) != 0);}
	[[nodiscard]] constexpr auto dithen() const -> dithen_f {return dithen_f((value_ & dithen_f::mask) != 0);}

	constexpr tim1_cr1_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim1_cr1_r other) const -> tim1_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM1 control register 2
 */
class tim1_cr2_r {
public:

/**
 * Capture/compare preloaded control 
 */
class ccpc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccpc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare control update selection 
 */
class ccus_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccus_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare DMA selection
 */
class ccds_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccds_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * MMS[2:0]: Master mode selection 
 */
class mms_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mms_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_cr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * tim_ti1 selection
 */
class ti1s_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ti1s_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 1 (tim_oc1 output) 
 */
class ois1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 1 (tim_oc1n output) 
 */
class ois1n_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois1n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 2 (tim_oc2 output) 
 */
class ois2_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 2 (tim_oc2n output) 
 */
class ois2n_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois2n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 3 (tim_oc3n output) 
 */
class ois3_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 3 (tim_oc3n output) 
 */
class ois3n_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois3n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 4 (tim_oc4 output) 
 */
class ois4_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 4 (tim_oc4n output) 
 */
class ois4n_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ois4n_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 5 (tim_oc5 output) 
 */
class ois5_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ois5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output idle state 6 (tim_oc6 output) 
 */
class ois6_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ois6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Master mode selection 2 
 */
class mms2_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mms2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * MMS[3]
 */
class mms_1_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mms_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cr2_r>() const {return opsy::utility::clear_set<tim1_cr2_r>(mask, *this);}
	constexpr auto operator|(tim1_cr2_r other) const -> tim1_cr2_r { return static_cast<tim1_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cr2_r> other) const -> opsy::utility::clear_set<tim1_cr2_r> {return opsy::utility::clear_set<tim1_cr2_r>(tim1_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccpc() const -> ccpc_f {return ccpc_f((value_ & ccpc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccus() const -> ccus_f {return ccus_f((value_ & ccus_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccds() const -> ccds_f {return ccds_f((value_ & ccds_f::mask) != 0);}
	[[nodiscard]] constexpr auto mms() const -> mms_f {return mms_f(static_cast<uint8_t>(value_ >> mms_f::offset));}
	[[nodiscard]] constexpr auto ti1s() const -> ti1s_f {return ti1s_f((value_ & ti1s_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois1() const -> ois1_f {return ois1_f((value_ & ois1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois1n() const -> ois1n_f {return ois1n_f((value_ & ois1n_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois2() const -> ois2_f {return ois2_f((value_ & ois2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois2n() const -> ois2n_f {return ois2n_f((value_ & ois2n_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois3() const -> ois3_f {return ois3_f((value_ & ois3_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois3n() const -> ois3n_f {return ois3n_f((value_ & ois3n_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois4() const -> ois4_f {return ois4_f((value_ & ois4_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois4n() const -> ois4n_f {return ois4n_f((value_ & ois4n_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois5() const -> ois5_f {return ois5_f((value_ & ois5_f::mask) != 0);}
	[[nodiscard]] constexpr auto ois6() const -> ois6_f {return ois6_f((value_ & ois6_f::mask) != 0);}
	[[nodiscard]] constexpr auto mms2() const -> mms2_f {return mms2_f(static_cast<uint8_t>(value_ >> mms2_f::offset));}
	[[nodiscard]] constexpr auto mms_1() const -> mms_1_f {return mms_1_f((value_ & mms_1_f::mask) != 0);}

	constexpr tim1_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_cr2_r other) const -> tim1_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 slave mode control register
 */
class tim1_smcr_r {
public:

/**
 * SMS[2:0]: Slave mode selection 
 */
class sms_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sms_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_smcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * OCREF clear selection 
 */
class occs_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr occs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TS[2:0]: Trigger selection 
 */
class ts_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ts_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_smcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Master/slave mode
 */
class msm_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr msm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger filter 
 */
class etf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr etf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_smcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External trigger prescaler 
 */
class etps_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr etps_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_smcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * External clock enable 
 */
class ece_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ece_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger polarity 
 */
class etp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr etp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Slave mode selection When external signals are selected the active edge of the trigger signal (tim_trgi) is linked to the polarity selected on the external input (see Input Control register and Control Register description. Note: The gated mode must not be used if tim_ti1f_ed is selected as the trigger input (TS=00100). Indeed, tim_ti1f_ed outputs 1 pulse for each transition on tim_ti1f, whereas the gated mode checks the level of the trigger signal. Note: The clock of the slave peripherals (timer, ADC, ...) receiving the tim_trgo signal must be enabled prior to receive events from the master timer, and the clock frequency (prescaler) must not be changed on-the-fly while triggers are received from the master timer.
 */
class sms_1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sms_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trigger selection This bit-field selects the trigger input to be used to synchronize the counter. Others: Reserved See for product specific implementation details. Note: These bits must be changed only when they are not used (e.g. when SMS=000) to avoid wrong edge detections at the transition.
 */
class ts_1_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ts_1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_smcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * SMS preload enable 
 */
class smspe_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smspe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMS preload source 
 */
class smsps_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smsps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_smcr_r>() const {return opsy::utility::clear_set<tim1_smcr_r>(mask, *this);}
	constexpr auto operator|(tim1_smcr_r other) const -> tim1_smcr_r { return static_cast<tim1_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_smcr_r> other) const -> opsy::utility::clear_set<tim1_smcr_r> {return opsy::utility::clear_set<tim1_smcr_r>(tim1_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sms() const -> sms_f {return sms_f(static_cast<uint8_t>(value_ >> sms_f::offset));}
	[[nodiscard]] constexpr auto occs() const -> occs_f {return occs_f((value_ & occs_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts() const -> ts_f {return ts_f(static_cast<uint8_t>(value_ >> ts_f::offset));}
	[[nodiscard]] constexpr auto msm() const -> msm_f {return msm_f((value_ & msm_f::mask) != 0);}
	[[nodiscard]] constexpr auto etf() const -> etf_f {return etf_f(static_cast<uint8_t>(value_ >> etf_f::offset));}
	[[nodiscard]] constexpr auto etps() const -> etps_f {return etps_f(static_cast<uint8_t>(value_ >> etps_f::offset));}
	[[nodiscard]] constexpr auto ece() const -> ece_f {return ece_f((value_ & ece_f::mask) != 0);}
	[[nodiscard]] constexpr auto etp() const -> etp_f {return etp_f((value_ & etp_f::mask) != 0);}
	[[nodiscard]] constexpr auto sms_1() const -> sms_1_f {return sms_1_f((value_ & sms_1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_1() const -> ts_1_f {return ts_1_f(static_cast<uint8_t>(value_ >> ts_1_f::offset));}
	[[nodiscard]] constexpr auto smspe() const -> smspe_f {return smspe_f((value_ & smspe_f::mask) != 0);}
	[[nodiscard]] constexpr auto smsps() const -> smsps_f {return smsps_f((value_ & smsps_f::mask) != 0);}

	constexpr tim1_smcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_smcr_r other) const -> tim1_smcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_smcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 DMA/interrupt enable register
 */
class tim1_dier_r {
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
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 interrupt enable
 */
class cc2ie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 interrupt enable
 */
class cc3ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 interrupt enable
 */
class cc4ie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * COM interrupt enable
 */
class comie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr comie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trigger interrupt enable
 */
class tie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break interrupt enable
 */
class bie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 DMA request enable
 */
class cc1de_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 DMA request enable
 */
class cc2de_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 DMA request enable
 */
class cc3de_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 DMA request enable
 */
class cc4de_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * COM DMA request enable
 */
class comde_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr comde_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trigger DMA request enable
 */
class tde_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tde_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index interrupt enable
 */
class idxie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idxie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change interrupt enable
 */
class dirie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dirie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index error interrupt enable
 */
class ierrie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ierrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transition error interrupt enable
 */
class terrie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr terrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dier_r>() const {return opsy::utility::clear_set<tim1_dier_r>(mask, *this);}
	constexpr auto operator|(tim1_dier_r other) const -> tim1_dier_r { return static_cast<tim1_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dier_r> other) const -> opsy::utility::clear_set<tim1_dier_r> {return opsy::utility::clear_set<tim1_dier_r>(tim1_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uie() const -> uie_f {return uie_f((value_ & uie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ie() const -> cc2ie_f {return cc2ie_f((value_ & cc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3ie() const -> cc3ie_f {return cc3ie_f((value_ & cc3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4ie() const -> cc4ie_f {return cc4ie_f((value_ & cc4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto comie() const -> comie_f {return comie_f((value_ & comie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tie() const -> tie_f {return tie_f((value_ & tie_f::mask) != 0);}
	[[nodiscard]] constexpr auto bie() const -> bie_f {return bie_f((value_ & bie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ude() const -> ude_f {return ude_f((value_ & ude_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1de() const -> cc1de_f {return cc1de_f((value_ & cc1de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2de() const -> cc2de_f {return cc2de_f((value_ & cc2de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3de() const -> cc3de_f {return cc3de_f((value_ & cc3de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4de() const -> cc4de_f {return cc4de_f((value_ & cc4de_f::mask) != 0);}
	[[nodiscard]] constexpr auto comde() const -> comde_f {return comde_f((value_ & comde_f::mask) != 0);}
	[[nodiscard]] constexpr auto tde() const -> tde_f {return tde_f((value_ & tde_f::mask) != 0);}
	[[nodiscard]] constexpr auto idxie() const -> idxie_f {return idxie_f((value_ & idxie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dirie() const -> dirie_f {return dirie_f((value_ & dirie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ierrie() const -> ierrie_f {return ierrie_f((value_ & ierrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto terrie() const -> terrie_f {return terrie_f((value_ & terrie_f::mask) != 0);}

	constexpr tim1_dier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_dier_r other) const -> tim1_dier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_dier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 status register
 */
class tim1_sr_r {
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
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 interrupt flag 
 */
class cc1if_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 interrupt flag 
 */
class cc2if_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 interrupt flag 
 */
class cc3if_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc3if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 interrupt flag 
 */
class cc4if_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc4if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * COM interrupt flag 
 */
class comif_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr comif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trigger interrupt flag 
 */
class tif_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break interrupt flag 
 */
class bif_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break 2 interrupt flag 
 */
class b2if_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr b2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 overcapture flag 
 */
class cc1of_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 overcapture flag 
 */
class cc2of_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 overcapture flag 
 */
class cc3of_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 overcapture flag 
 */
class cc4of_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * System break interrupt flag 
 */
class sbif_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sbif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare 5 interrupt flag 
 */
class cc5if_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc5if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare 6 interrupt flag 
 */
class cc6if_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc6if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index interrupt flag 
 */
class idxf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr idxf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change interrupt flag 
 */
class dirf_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dirf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index error interrupt flag 
 */
class ierrf_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ierrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transition error interrupt flag 
 */
class terrf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr terrf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_sr_r>() const {return opsy::utility::clear_set<tim1_sr_r>(mask, *this);}
	constexpr auto operator|(tim1_sr_r other) const -> tim1_sr_r { return static_cast<tim1_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_sr_r> other) const -> opsy::utility::clear_set<tim1_sr_r> {return opsy::utility::clear_set<tim1_sr_r>(tim1_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uif() const -> uif_f {return uif_f((value_ & uif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2if() const -> cc2if_f {return cc2if_f((value_ & cc2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3if() const -> cc3if_f {return cc3if_f((value_ & cc3if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4if() const -> cc4if_f {return cc4if_f((value_ & cc4if_f::mask) != 0);}
	[[nodiscard]] constexpr auto comif() const -> comif_f {return comif_f((value_ & comif_f::mask) != 0);}
	[[nodiscard]] constexpr auto tif() const -> tif_f {return tif_f((value_ & tif_f::mask) != 0);}
	[[nodiscard]] constexpr auto bif() const -> bif_f {return bif_f((value_ & bif_f::mask) != 0);}
	[[nodiscard]] constexpr auto b2if() const -> b2if_f {return b2if_f((value_ & b2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1of() const -> cc1of_f {return cc1of_f((value_ & cc1of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2of() const -> cc2of_f {return cc2of_f((value_ & cc2of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3of() const -> cc3of_f {return cc3of_f((value_ & cc3of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4of() const -> cc4of_f {return cc4of_f((value_ & cc4of_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbif() const -> sbif_f {return sbif_f((value_ & sbif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc5if() const -> cc5if_f {return cc5if_f((value_ & cc5if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc6if() const -> cc6if_f {return cc6if_f((value_ & cc6if_f::mask) != 0);}
	[[nodiscard]] constexpr auto idxf() const -> idxf_f {return idxf_f((value_ & idxf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dirf() const -> dirf_f {return dirf_f((value_ & dirf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ierrf() const -> ierrf_f {return ierrf_f((value_ & ierrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto terrf() const -> terrf_f {return terrf_f((value_ & terrf_f::mask) != 0);}

	constexpr tim1_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_sr_r other) const -> tim1_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 event generation register
 */
class tim1_egr_r {
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
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 generation 
 */
class cc1g_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1g_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 generation 
 */
class cc2g_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2g_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 generation 
 */
class cc3g_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc3g_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 generation 
 */
class cc4g_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc4g_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare control update generation 
 */
class comg_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr comg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Trigger generation 
 */
class tg_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break generation 
 */
class bg_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break 2 generation 
 */
class b2g_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr b2g_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_egr_r>() const {return opsy::utility::clear_set<tim1_egr_r>(mask, *this);}
	constexpr auto operator|(tim1_egr_r other) const -> tim1_egr_r { return static_cast<tim1_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_egr_r> other) const -> opsy::utility::clear_set<tim1_egr_r> {return opsy::utility::clear_set<tim1_egr_r>(tim1_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ug() const -> ug_f {return ug_f((value_ & ug_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1g() const -> cc1g_f {return cc1g_f((value_ & cc1g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2g() const -> cc2g_f {return cc2g_f((value_ & cc2g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3g() const -> cc3g_f {return cc3g_f((value_ & cc3g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4g() const -> cc4g_f {return cc4g_f((value_ & cc4g_f::mask) != 0);}
	[[nodiscard]] constexpr auto comg() const -> comg_f {return comg_f((value_ & comg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tg() const -> tg_f {return tg_f((value_ & tg_f::mask) != 0);}
	[[nodiscard]] constexpr auto bg() const -> bg_f {return bg_f((value_ & bg_f::mask) != 0);}
	[[nodiscard]] constexpr auto b2g() const -> b2g_f {return b2g_f((value_ & b2g_f::mask) != 0);}

	constexpr tim1_egr_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim1_egr_r other) const -> tim1_egr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_egr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM1 capture/compare mode register 1
 */
class tim1_ccmr1_r {
public:

/**
 * Capture/compare 1 Selection 
 */
class cc1s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 prescaler 
 */
class ic1psc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ic1psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 filter 
 */
class ic1f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ic1f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Capture/compare 2 selection 
 */
class cc2s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc2s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 prescaler
 */
class ic2psc_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic2psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 filter
 */
class ic2f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic2f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return static_cast<tim1_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_r> {return opsy::utility::clear_set<tim1_ccmr1_r>(tim1_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc1s() const -> cc1s_f {return cc1s_f(static_cast<uint8_t>(value_ >> cc1s_f::offset));}
	[[nodiscard]] constexpr auto ic1psc() const -> ic1psc_f {return ic1psc_f(static_cast<uint8_t>(value_ >> ic1psc_f::offset));}
	[[nodiscard]] constexpr auto ic1f() const -> ic1f_f {return ic1f_f(static_cast<uint8_t>(value_ >> ic1f_f::offset));}
	[[nodiscard]] constexpr auto cc2s() const -> cc2s_f {return cc2s_f(static_cast<uint8_t>(value_ >> cc2s_f::offset));}
	[[nodiscard]] constexpr auto ic2psc() const -> ic2psc_f {return ic2psc_f(static_cast<uint8_t>(value_ >> ic2psc_f::offset));}
	[[nodiscard]] constexpr auto ic2f() const -> ic2f_f {return ic2f_f(static_cast<uint8_t>(value_ >> ic2f_f::offset));}

	constexpr tim1_ccmr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccmr1_r other) const -> tim1_ccmr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccmr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare mode register 1
 */
class tim1_ccmr1_alternate1_r {
public:

/**
 * Capture/compare 1 selection 
 */
class cc1s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 1 fast enable 
 */
class oc1fe_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc1fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 1 preload enable 
 */
class oc1pe_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc1pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC1M[2:0]: Output compare 1 mode 
 */
class oc1m_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr oc1m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 1 clear enable
 */
class oc1ce_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc1ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 selection 
 */
class cc2s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc2s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 2 fast enable
 */
class oc2fe_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc2fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 2 preload enable
 */
class oc2pe_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc2pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC2M[2:0]: Output compare 2 mode
 */
class oc2m_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr oc2m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 2 clear enable
 */
class oc2ce_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc2ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC1M[3]
 */
class oc1m_1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc1m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC2M[3]
 */
class oc2m_1_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc2m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return static_cast<tim1_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr1_alternate1_r>(tim1_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1s() const -> cc1s_f {return cc1s_f(static_cast<uint8_t>(value_ >> cc1s_f::offset));}
	[[nodiscard]] constexpr auto oc1fe() const -> oc1fe_f {return oc1fe_f((value_ & oc1fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc1pe() const -> oc1pe_f {return oc1pe_f((value_ & oc1pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc1m() const -> oc1m_f {return oc1m_f(static_cast<uint8_t>(value_ >> oc1m_f::offset));}
	[[nodiscard]] constexpr auto oc1ce() const -> oc1ce_f {return oc1ce_f((value_ & oc1ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2s() const -> cc2s_f {return cc2s_f(static_cast<uint8_t>(value_ >> cc2s_f::offset));}
	[[nodiscard]] constexpr auto oc2fe() const -> oc2fe_f {return oc2fe_f((value_ & oc2fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc2pe() const -> oc2pe_f {return oc2pe_f((value_ & oc2pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc2m() const -> oc2m_f {return oc2m_f(static_cast<uint8_t>(value_ >> oc2m_f::offset));}
	[[nodiscard]] constexpr auto oc2ce() const -> oc2ce_f {return oc2ce_f((value_ & oc2ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc1m_1() const -> oc1m_1_f {return oc1m_1_f((value_ & oc1m_1_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc2m_1() const -> oc2m_1_f {return oc2m_1_f((value_ & oc2m_1_f::mask) != 0);}

	constexpr tim1_ccmr1_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccmr1_alternate1_r other) const -> tim1_ccmr1_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccmr1_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare mode register 2
 */
class tim1_ccmr2_r {
public:

/**
 * Capture/compare 3 selection 
 */
class cc3s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc3s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 3 prescaler
 */
class ic3psc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ic3psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 3 filter
 */
class ic3f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ic3f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Capture/compare 4 selection 
 */
class cc4s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc4s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 4 prescaler
 */
class ic4psc_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic4psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 4 filter
 */
class ic4f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic4f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_r>() const {return opsy::utility::clear_set<tim1_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return static_cast<tim1_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_r> {return opsy::utility::clear_set<tim1_ccmr2_r>(tim1_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc3s() const -> cc3s_f {return cc3s_f(static_cast<uint8_t>(value_ >> cc3s_f::offset));}
	[[nodiscard]] constexpr auto ic3psc() const -> ic3psc_f {return ic3psc_f(static_cast<uint8_t>(value_ >> ic3psc_f::offset));}
	[[nodiscard]] constexpr auto ic3f() const -> ic3f_f {return ic3f_f(static_cast<uint8_t>(value_ >> ic3f_f::offset));}
	[[nodiscard]] constexpr auto cc4s() const -> cc4s_f {return cc4s_f(static_cast<uint8_t>(value_ >> cc4s_f::offset));}
	[[nodiscard]] constexpr auto ic4psc() const -> ic4psc_f {return ic4psc_f(static_cast<uint8_t>(value_ >> ic4psc_f::offset));}
	[[nodiscard]] constexpr auto ic4f() const -> ic4f_f {return ic4f_f(static_cast<uint8_t>(value_ >> ic4f_f::offset));}

	constexpr tim1_ccmr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccmr2_r other) const -> tim1_ccmr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccmr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare mode register 2
 */
class tim1_ccmr2_alternate1_r {
public:

/**
 * Capture/compare 3 selection 
 */
class cc3s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc3s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 3 fast enable
 */
class oc3fe_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc3fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 3 preload enable
 */
class oc3pe_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc3pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC3M[2:0]: Output compare 3 mode 
 */
class oc3m_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr oc3m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 3 clear enable
 */
class oc3ce_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc3ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 selection 
 */
class cc4s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc4s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 4 fast enable
 */
class oc4fe_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc4fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 4 preload enable
 */
class oc4pe_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc4pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC4M[2:0]: Output compare 4 mode 
 */
class oc4m_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr oc4m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 4 clear enable
 */
class oc4ce_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc4ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC3M[3]
 */
class oc3m_1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc3m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC4M[3]
 */
class oc4m_1_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc4m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return static_cast<tim1_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim1_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim1_ccmr2_alternate1_r>(tim1_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc3s() const -> cc3s_f {return cc3s_f(static_cast<uint8_t>(value_ >> cc3s_f::offset));}
	[[nodiscard]] constexpr auto oc3fe() const -> oc3fe_f {return oc3fe_f((value_ & oc3fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc3pe() const -> oc3pe_f {return oc3pe_f((value_ & oc3pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc3m() const -> oc3m_f {return oc3m_f(static_cast<uint8_t>(value_ >> oc3m_f::offset));}
	[[nodiscard]] constexpr auto oc3ce() const -> oc3ce_f {return oc3ce_f((value_ & oc3ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4s() const -> cc4s_f {return cc4s_f(static_cast<uint8_t>(value_ >> cc4s_f::offset));}
	[[nodiscard]] constexpr auto oc4fe() const -> oc4fe_f {return oc4fe_f((value_ & oc4fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc4pe() const -> oc4pe_f {return oc4pe_f((value_ & oc4pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc4m() const -> oc4m_f {return oc4m_f(static_cast<uint8_t>(value_ >> oc4m_f::offset));}
	[[nodiscard]] constexpr auto oc4ce() const -> oc4ce_f {return oc4ce_f((value_ & oc4ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc3m_1() const -> oc3m_1_f {return oc3m_1_f((value_ & oc3m_1_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc4m_1() const -> oc4m_1_f {return oc4m_1_f((value_ & oc4m_1_f::mask) != 0);}

	constexpr tim1_ccmr2_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccmr2_alternate1_r other) const -> tim1_ccmr2_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccmr2_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare enable register
 */
class tim1_ccer_r {
public:

/**
 * Capture/compare 1 output enable 
 */
class cc1e_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 output polarity 
 */
class cc1p_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 complementary output enable 
 */
class cc1ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 complementary output polarity 
 */
class cc1np_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output enable 
 */
class cc2e_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output polarity 
 */
class cc2p_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 complementary output enable 
 */
class cc2ne_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 complementary output polarity 
 */
class cc2np_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 output enable 
 */
class cc3e_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 output polarity 
 */
class cc3p_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 complementary output enable 
 */
class cc3ne_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 3 complementary output polarity 
 */
class cc3np_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 output enable 
 */
class cc4e_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 output polarity 
 */
class cc4p_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 complementary output enable 
 */
class cc4ne_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 4 complementary output polarity 
 */
class cc4np_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 5 output enable 
 */
class cc5e_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc5e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 5 output polarity 
 */
class cc5p_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc5p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 6 output enable 
 */
class cc6e_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc6e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 6 output polarity 
 */
class cc6p_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc6p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccer_r>() const {return opsy::utility::clear_set<tim1_ccer_r>(mask, *this);}
	constexpr auto operator|(tim1_ccer_r other) const -> tim1_ccer_r { return static_cast<tim1_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccer_r> other) const -> opsy::utility::clear_set<tim1_ccer_r> {return opsy::utility::clear_set<tim1_ccer_r>(tim1_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1e() const -> cc1e_f {return cc1e_f((value_ & cc1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1p() const -> cc1p_f {return cc1p_f((value_ & cc1p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1ne() const -> cc1ne_f {return cc1ne_f((value_ & cc1ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1np() const -> cc1np_f {return cc1np_f((value_ & cc1np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2e() const -> cc2e_f {return cc2e_f((value_ & cc2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2p() const -> cc2p_f {return cc2p_f((value_ & cc2p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ne() const -> cc2ne_f {return cc2ne_f((value_ & cc2ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2np() const -> cc2np_f {return cc2np_f((value_ & cc2np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3e() const -> cc3e_f {return cc3e_f((value_ & cc3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3p() const -> cc3p_f {return cc3p_f((value_ & cc3p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3ne() const -> cc3ne_f {return cc3ne_f((value_ & cc3ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3np() const -> cc3np_f {return cc3np_f((value_ & cc3np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4e() const -> cc4e_f {return cc4e_f((value_ & cc4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4p() const -> cc4p_f {return cc4p_f((value_ & cc4p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4ne() const -> cc4ne_f {return cc4ne_f((value_ & cc4ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4np() const -> cc4np_f {return cc4np_f((value_ & cc4np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc5e() const -> cc5e_f {return cc5e_f((value_ & cc5e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc5p() const -> cc5p_f {return cc5p_f((value_ & cc5p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc6e() const -> cc6e_f {return cc6e_f((value_ & cc6e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc6p() const -> cc6p_f {return cc6p_f((value_ & cc6p_f::mask) != 0);}

	constexpr tim1_ccer_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccer_r other) const -> tim1_ccer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 counter
 */
class tim1_cnt_r {
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
	constexpr operator tim1_cnt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_cnt_r>() const {return opsy::utility::clear_set<tim1_cnt_r>(mask, *this);}
	constexpr auto operator|(tim1_cnt_r other) const -> tim1_cnt_r { return static_cast<tim1_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cnt_r> other) const -> opsy::utility::clear_set<tim1_cnt_r> {return opsy::utility::clear_set<tim1_cnt_r>(tim1_cnt_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim1_cnt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_cnt_r>() const {return opsy::utility::clear_set<tim1_cnt_r>(mask, *this);}
	constexpr auto operator|(tim1_cnt_r other) const -> tim1_cnt_r { return static_cast<tim1_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_cnt_r> other) const -> opsy::utility::clear_set<tim1_cnt_r> {return opsy::utility::clear_set<tim1_cnt_r>(tim1_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cnt() const -> cnt_f {return cnt_f(static_cast<uint16_t>(value_ >> cnt_f::offset));}
	[[nodiscard]] constexpr auto uifcpy() const -> uifcpy_f {return uifcpy_f((value_ & uifcpy_f::mask) != 0);}

	constexpr tim1_cnt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_cnt_r other) const -> tim1_cnt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_cnt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 prescaler
 */
class tim1_psc_r {
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
	constexpr operator tim1_psc_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_psc_r>() const {return opsy::utility::clear_set<tim1_psc_r>(mask, *this);}
	constexpr auto operator|(tim1_psc_r other) const -> tim1_psc_r { return static_cast<tim1_psc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_psc_r> other) const -> opsy::utility::clear_set<tim1_psc_r> {return opsy::utility::clear_set<tim1_psc_r>(tim1_psc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto psc() const -> psc_f {return psc_f(static_cast<uint16_t>(value_ >> psc_f::offset));}

	constexpr tim1_psc_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim1_psc_r other) const -> tim1_psc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_psc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM1 auto-reload register
 */
class tim1_arr_r {
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
	constexpr operator tim1_arr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_arr_r>() const {return opsy::utility::clear_set<tim1_arr_r>(mask, *this);}
	constexpr auto operator|(tim1_arr_r other) const -> tim1_arr_r { return static_cast<tim1_arr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_arr_r> other) const -> opsy::utility::clear_set<tim1_arr_r> {return opsy::utility::clear_set<tim1_arr_r>(tim1_arr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto arr() const -> arr_f {return arr_f(static_cast<uint32_t>(value_ >> arr_f::offset));}

	constexpr tim1_arr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_arr_r other) const -> tim1_arr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_arr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111; // 65535 0xFFFF

private:
	uint32_t value_;
};

/**
 * TIM1 repetition counter register
 */
class tim1_rcr_r {
public:

/**
 * Repetition counter reload value 
 */
class rep_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rep_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator tim1_rcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_rcr_r>() const {return opsy::utility::clear_set<tim1_rcr_r>(mask, *this);}
	constexpr auto operator|(tim1_rcr_r other) const -> tim1_rcr_r { return static_cast<tim1_rcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_rcr_r> other) const -> opsy::utility::clear_set<tim1_rcr_r> {return opsy::utility::clear_set<tim1_rcr_r>(tim1_rcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rep() const -> rep_f {return rep_f(static_cast<uint16_t>(value_ >> rep_f::offset));}

	constexpr tim1_rcr_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim1_rcr_r other) const -> tim1_rcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_rcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM1 capture/compare register 1
 */
class tim1_ccr1_r {
public:

/**
 * Capture/compare 1 value 
 */
class ccr1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr1_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr1_r>() const {return opsy::utility::clear_set<tim1_ccr1_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr1_r other) const -> tim1_ccr1_r { return static_cast<tim1_ccr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr1_r> other) const -> opsy::utility::clear_set<tim1_ccr1_r> {return opsy::utility::clear_set<tim1_ccr1_r>(tim1_ccr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr1() const -> ccr1_f {return ccr1_f(static_cast<uint32_t>(value_ >> ccr1_f::offset));}

	constexpr tim1_ccr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr1_r other) const -> tim1_ccr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare register 2
 */
class tim1_ccr2_r {
public:

/**
 * Capture/compare 2 value 
 */
class ccr2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr2_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr2_r>() const {return opsy::utility::clear_set<tim1_ccr2_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr2_r other) const -> tim1_ccr2_r { return static_cast<tim1_ccr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr2_r> other) const -> opsy::utility::clear_set<tim1_ccr2_r> {return opsy::utility::clear_set<tim1_ccr2_r>(tim1_ccr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr2() const -> ccr2_f {return ccr2_f(static_cast<uint32_t>(value_ >> ccr2_f::offset));}

	constexpr tim1_ccr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr2_r other) const -> tim1_ccr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare register 3
 */
class tim1_ccr3_r {
public:

/**
 * Capture/compare value 
 */
class ccr3_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr3_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr3_r>() const {return opsy::utility::clear_set<tim1_ccr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr3_r other) const -> tim1_ccr3_r { return static_cast<tim1_ccr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr3_r> other) const -> opsy::utility::clear_set<tim1_ccr3_r> {return opsy::utility::clear_set<tim1_ccr3_r>(tim1_ccr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr3() const -> ccr3_f {return ccr3_f(static_cast<uint32_t>(value_ >> ccr3_f::offset));}

	constexpr tim1_ccr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr3_r other) const -> tim1_ccr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare register 4
 */
class tim1_ccr4_r {
public:

/**
 * Capture/compare value 
 */
class ccr4_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr4_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr4_r>() const {return opsy::utility::clear_set<tim1_ccr4_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr4_r other) const -> tim1_ccr4_r { return static_cast<tim1_ccr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr4_r> other) const -> opsy::utility::clear_set<tim1_ccr4_r> {return opsy::utility::clear_set<tim1_ccr4_r>(tim1_ccr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr4() const -> ccr4_f {return ccr4_f(static_cast<uint32_t>(value_ >> ccr4_f::offset));}

	constexpr tim1_ccr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr4_r other) const -> tim1_ccr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 break and dead-time register
 */
class tim1_bdtr_r {
public:

/**
 * Dead-time generator setup 
 */
class dtg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dtg_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Lock configuration 
 */
class lock_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lock_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Off-state selection for idle mode 
 */
class ossi_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ossi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Off-state selection for Run mode 
 */
class ossr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ossr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break enable 
 */
class bke_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bke_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break polarity 
 */
class bkp_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic output enable 
 */
class aoe_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr aoe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Main output enable 
 */
class moe_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr moe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break filter 
 */
class bkf_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr bkf_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Break 2 filter 
 */
class bk2f_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr bk2f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Break 2 enable 
 */
class bk2e_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break 2 polarity 
 */
class bk2p_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk2p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break disarm 
 */
class bkdsrm_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkdsrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break2 disarm 
 */
class bk2dsrm_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk2dsrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break bidirectional 
 */
class bkbid_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkbid_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Break2 bidirectional 
 */
class bk2bid_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk2bid_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_bdtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_bdtr_r>() const {return opsy::utility::clear_set<tim1_bdtr_r>(mask, *this);}
	constexpr auto operator|(tim1_bdtr_r other) const -> tim1_bdtr_r { return static_cast<tim1_bdtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_bdtr_r> other) const -> opsy::utility::clear_set<tim1_bdtr_r> {return opsy::utility::clear_set<tim1_bdtr_r>(tim1_bdtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dtg() const -> dtg_f {return dtg_f(static_cast<uint8_t>(value_ >> dtg_f::offset));}
	[[nodiscard]] constexpr auto lock() const -> lock_f {return lock_f(static_cast<uint8_t>(value_ >> lock_f::offset));}
	[[nodiscard]] constexpr auto ossi() const -> ossi_f {return ossi_f((value_ & ossi_f::mask) != 0);}
	[[nodiscard]] constexpr auto ossr() const -> ossr_f {return ossr_f((value_ & ossr_f::mask) != 0);}
	[[nodiscard]] constexpr auto bke() const -> bke_f {return bke_f((value_ & bke_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkp() const -> bkp_f {return bkp_f((value_ & bkp_f::mask) != 0);}
	[[nodiscard]] constexpr auto aoe() const -> aoe_f {return aoe_f((value_ & aoe_f::mask) != 0);}
	[[nodiscard]] constexpr auto moe() const -> moe_f {return moe_f((value_ & moe_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkf() const -> bkf_f {return bkf_f(static_cast<uint8_t>(value_ >> bkf_f::offset));}
	[[nodiscard]] constexpr auto bk2f() const -> bk2f_f {return bk2f_f(static_cast<uint8_t>(value_ >> bk2f_f::offset));}
	[[nodiscard]] constexpr auto bk2e() const -> bk2e_f {return bk2e_f((value_ & bk2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2p() const -> bk2p_f {return bk2p_f((value_ & bk2p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkdsrm() const -> bkdsrm_f {return bkdsrm_f((value_ & bkdsrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2dsrm() const -> bk2dsrm_f {return bk2dsrm_f((value_ & bk2dsrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkbid() const -> bkbid_f {return bkbid_f((value_ & bkbid_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2bid() const -> bk2bid_f {return bk2bid_f((value_ & bk2bid_f::mask) != 0);}

	constexpr tim1_bdtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_bdtr_r other) const -> tim1_bdtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_bdtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare register 5
 */
class tim1_ccr5_r {
public:

/**
 * Capture/compare 5 value 
 */
class ccr5_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr5_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr5_r>() const {return opsy::utility::clear_set<tim1_ccr5_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr5_r other) const -> tim1_ccr5_r { return static_cast<tim1_ccr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr5_r> other) const -> opsy::utility::clear_set<tim1_ccr5_r> {return opsy::utility::clear_set<tim1_ccr5_r>(tim1_ccr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Group channel 5 and channel 1 
 */
class gc5c1_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr gc5c1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccr5_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccr5_r>() const {return opsy::utility::clear_set<tim1_ccr5_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr5_r other) const -> tim1_ccr5_r { return static_cast<tim1_ccr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr5_r> other) const -> opsy::utility::clear_set<tim1_ccr5_r> {return opsy::utility::clear_set<tim1_ccr5_r>(tim1_ccr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Group channel 5 and channel 2 
 */
class gc5c2_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr gc5c2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccr5_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccr5_r>() const {return opsy::utility::clear_set<tim1_ccr5_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr5_r other) const -> tim1_ccr5_r { return static_cast<tim1_ccr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr5_r> other) const -> opsy::utility::clear_set<tim1_ccr5_r> {return opsy::utility::clear_set<tim1_ccr5_r>(tim1_ccr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Group channel 5 and channel 3 
 */
class gc5c3_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr gc5c3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccr5_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccr5_r>() const {return opsy::utility::clear_set<tim1_ccr5_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr5_r other) const -> tim1_ccr5_r { return static_cast<tim1_ccr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr5_r> other) const -> opsy::utility::clear_set<tim1_ccr5_r> {return opsy::utility::clear_set<tim1_ccr5_r>(tim1_ccr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccr5() const -> ccr5_f {return ccr5_f(static_cast<uint32_t>(value_ >> ccr5_f::offset));}
	[[nodiscard]] constexpr auto gc5c1() const -> gc5c1_f {return gc5c1_f((value_ & gc5c1_f::mask) != 0);}
	[[nodiscard]] constexpr auto gc5c2() const -> gc5c2_f {return gc5c2_f((value_ & gc5c2_f::mask) != 0);}
	[[nodiscard]] constexpr auto gc5c3() const -> gc5c3_f {return gc5c3_f((value_ & gc5c3_f::mask) != 0);}

	constexpr tim1_ccr5_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr5_r other) const -> tim1_ccr5_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr5_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare register 6
 */
class tim1_ccr6_r {
public:

/**
 * Capture/compare 6 value 
 */
class ccr6_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr6_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_ccr6_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccr6_r>() const {return opsy::utility::clear_set<tim1_ccr6_r>(mask, *this);}
	constexpr auto operator|(tim1_ccr6_r other) const -> tim1_ccr6_r { return static_cast<tim1_ccr6_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccr6_r> other) const -> opsy::utility::clear_set<tim1_ccr6_r> {return opsy::utility::clear_set<tim1_ccr6_r>(tim1_ccr6_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr6() const -> ccr6_f {return ccr6_f(static_cast<uint32_t>(value_ >> ccr6_f::offset));}

	constexpr tim1_ccr6_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccr6_r other) const -> tim1_ccr6_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccr6_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 capture/compare mode register 3
 */
class tim1_ccmr3_r {
public:

/**
 * Output compare 5 fast enable
 */
class oc5fe_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc5fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 5 preload enable
 */
class oc5pe_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc5pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC5M[2:0]: Output compare 5 mode
 */
class oc5m_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr oc5m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 5 clear enable
 */
class oc5ce_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr oc5ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 6 fast enable
 */
class oc6fe_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc6fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output compare 6 preload enable
 */
class oc6pe_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc6pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC6M[2:0]: Output compare 6 mode
 */
class oc6m_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr oc6m_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Output compare 6 clear enable
 */
class oc6ce_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr oc6ce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC5M[3]
 */
class oc5m_1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc5m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OC6M[3]
 */
class oc6m_1_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oc6m_1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ccmr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ccmr3_r>() const {return opsy::utility::clear_set<tim1_ccmr3_r>(mask, *this);}
	constexpr auto operator|(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return static_cast<tim1_ccmr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ccmr3_r> other) const -> opsy::utility::clear_set<tim1_ccmr3_r> {return opsy::utility::clear_set<tim1_ccmr3_r>(tim1_ccmr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto oc5fe() const -> oc5fe_f {return oc5fe_f((value_ & oc5fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc5pe() const -> oc5pe_f {return oc5pe_f((value_ & oc5pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc5m() const -> oc5m_f {return oc5m_f(static_cast<uint8_t>(value_ >> oc5m_f::offset));}
	[[nodiscard]] constexpr auto oc5ce() const -> oc5ce_f {return oc5ce_f((value_ & oc5ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc6fe() const -> oc6fe_f {return oc6fe_f((value_ & oc6fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc6pe() const -> oc6pe_f {return oc6pe_f((value_ & oc6pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc6m() const -> oc6m_f {return oc6m_f(static_cast<uint8_t>(value_ >> oc6m_f::offset));}
	[[nodiscard]] constexpr auto oc6ce() const -> oc6ce_f {return oc6ce_f((value_ & oc6ce_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc5m_1() const -> oc5m_1_f {return oc5m_1_f((value_ & oc5m_1_f::mask) != 0);}
	[[nodiscard]] constexpr auto oc6m_1() const -> oc6m_1_f {return oc6m_1_f((value_ & oc6m_1_f::mask) != 0);}

	constexpr tim1_ccmr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ccmr3_r other) const -> tim1_ccmr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ccmr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 timer deadtime register 2
 */
class tim1_dtr2_r {
public:

/**
 * Dead-time falling edge generator setup 
 */
class dtgf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dtgf_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_dtr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_dtr2_r>() const {return opsy::utility::clear_set<tim1_dtr2_r>(mask, *this);}
	constexpr auto operator|(tim1_dtr2_r other) const -> tim1_dtr2_r { return static_cast<tim1_dtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dtr2_r> other) const -> opsy::utility::clear_set<tim1_dtr2_r> {return opsy::utility::clear_set<tim1_dtr2_r>(tim1_dtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Deadtime asymmetric enable 
 */
class dtae_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dtr2_r>() const {return opsy::utility::clear_set<tim1_dtr2_r>(mask, *this);}
	constexpr auto operator|(tim1_dtr2_r other) const -> tim1_dtr2_r { return static_cast<tim1_dtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dtr2_r> other) const -> opsy::utility::clear_set<tim1_dtr2_r> {return opsy::utility::clear_set<tim1_dtr2_r>(tim1_dtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Deadtime preload enable 
 */
class dtpe_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dtpe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_dtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_dtr2_r>() const {return opsy::utility::clear_set<tim1_dtr2_r>(mask, *this);}
	constexpr auto operator|(tim1_dtr2_r other) const -> tim1_dtr2_r { return static_cast<tim1_dtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dtr2_r> other) const -> opsy::utility::clear_set<tim1_dtr2_r> {return opsy::utility::clear_set<tim1_dtr2_r>(tim1_dtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dtgf() const -> dtgf_f {return dtgf_f(static_cast<uint8_t>(value_ >> dtgf_f::offset));}
	[[nodiscard]] constexpr auto dtae() const -> dtae_f {return dtae_f((value_ & dtae_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtpe() const -> dtpe_f {return dtpe_f((value_ & dtpe_f::mask) != 0);}

	constexpr tim1_dtr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_dtr2_r other) const -> tim1_dtr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_dtr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 timer encoder control register
 */
class tim1_ecr_r {
public:

/**
 * Index enable 
 */
class ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index direction 
 */
class idir_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr idir_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Index blanking 
 */
class iblk_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr iblk_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * First index 
 */
class fidx_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fidx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_ecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Index positioning 
 */
class ipos_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ipos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Pulse width 
 */
class pw_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pw_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Pulse width prescaler 
 */
class pwprsc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr pwprsc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_ecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_ecr_r>() const {return opsy::utility::clear_set<tim1_ecr_r>(mask, *this);}
	constexpr auto operator|(tim1_ecr_r other) const -> tim1_ecr_r { return static_cast<tim1_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_ecr_r> other) const -> opsy::utility::clear_set<tim1_ecr_r> {return opsy::utility::clear_set<tim1_ecr_r>(tim1_ecr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ie() const -> ie_f {return ie_f((value_ & ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto idir() const -> idir_f {return idir_f(static_cast<uint8_t>(value_ >> idir_f::offset));}
	[[nodiscard]] constexpr auto iblk() const -> iblk_f {return iblk_f(static_cast<uint8_t>(value_ >> iblk_f::offset));}
	[[nodiscard]] constexpr auto fidx() const -> fidx_f {return fidx_f((value_ & fidx_f::mask) != 0);}
	[[nodiscard]] constexpr auto ipos() const -> ipos_f {return ipos_f(static_cast<uint8_t>(value_ >> ipos_f::offset));}
	[[nodiscard]] constexpr auto pw() const -> pw_f {return pw_f(static_cast<uint8_t>(value_ >> pw_f::offset));}
	[[nodiscard]] constexpr auto pwprsc() const -> pwprsc_f {return pwprsc_f(static_cast<uint8_t>(value_ >> pwprsc_f::offset));}

	constexpr tim1_ecr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_ecr_r other) const -> tim1_ecr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_ecr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 timer input selection register
 */
class tim1_tisel_r {
public:

/**
 * Selects tim_ti1[15:0] input 
 */
class ti1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ti1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_tisel_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_tisel_r>() const {return opsy::utility::clear_set<tim1_tisel_r>(mask, *this);}
	constexpr auto operator|(tim1_tisel_r other) const -> tim1_tisel_r { return static_cast<tim1_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_tisel_r> other) const -> opsy::utility::clear_set<tim1_tisel_r> {return opsy::utility::clear_set<tim1_tisel_r>(tim1_tisel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Selects tim_ti2[15:0] input 
 */
class ti2sel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ti2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_tisel_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_tisel_r>() const {return opsy::utility::clear_set<tim1_tisel_r>(mask, *this);}
	constexpr auto operator|(tim1_tisel_r other) const -> tim1_tisel_r { return static_cast<tim1_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_tisel_r> other) const -> opsy::utility::clear_set<tim1_tisel_r> {return opsy::utility::clear_set<tim1_tisel_r>(tim1_tisel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Selects tim_ti3[15:0] input 
 */
class ti3sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ti3sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_tisel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_tisel_r>() const {return opsy::utility::clear_set<tim1_tisel_r>(mask, *this);}
	constexpr auto operator|(tim1_tisel_r other) const -> tim1_tisel_r { return static_cast<tim1_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_tisel_r> other) const -> opsy::utility::clear_set<tim1_tisel_r> {return opsy::utility::clear_set<tim1_tisel_r>(tim1_tisel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Selects tim_ti4[15:0] input 
 */
class ti4sel_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ti4sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_tisel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_tisel_r>() const {return opsy::utility::clear_set<tim1_tisel_r>(mask, *this);}
	constexpr auto operator|(tim1_tisel_r other) const -> tim1_tisel_r { return static_cast<tim1_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_tisel_r> other) const -> opsy::utility::clear_set<tim1_tisel_r> {return opsy::utility::clear_set<tim1_tisel_r>(tim1_tisel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ti1sel() const -> ti1sel_f {return ti1sel_f(static_cast<uint8_t>(value_ >> ti1sel_f::offset));}
	[[nodiscard]] constexpr auto ti2sel() const -> ti2sel_f {return ti2sel_f(static_cast<uint8_t>(value_ >> ti2sel_f::offset));}
	[[nodiscard]] constexpr auto ti3sel() const -> ti3sel_f {return ti3sel_f(static_cast<uint8_t>(value_ >> ti3sel_f::offset));}
	[[nodiscard]] constexpr auto ti4sel() const -> ti4sel_f {return ti4sel_f(static_cast<uint8_t>(value_ >> ti4sel_f::offset));}

	constexpr tim1_tisel_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_tisel_r other) const -> tim1_tisel_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_tisel_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 alternate function option register 1
 */
class tim1_af1_r {
public:

/**
 * TIMx_BKIN input enable 
 */
class bkine_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkine_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp1 enable 
 */
class bkcmp1e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp2 enable 
 */
class bkcmp2e_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp3 enable 
 */
class bkcmp3e_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp4 enable 
 */
class bkcmp4e_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp5 enable 
 */
class bkcmp5e_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp5e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp6 enable 
 */
class bkcmp6e_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp6e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp7 enable 
 */
class bkcmp7e_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkcmp7e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp8 enable 
 */
class bkcmp8e_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkcmp8e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIMx_BKIN input polarity 
 */
class bkinp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkinp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp1 input polarity 
 */
class bkcmp1p_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkcmp1p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp2 input polarity 
 */
class bkcmp2p_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkcmp2p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp3 input polarity 
 */
class bkcmp3p_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkcmp3p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk_cmp4 input polarity 
 */
class bkcmp4p_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bkcmp4p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * etr_in source selection 
 */
class etrsel_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr etrsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_af1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_af1_r>() const {return opsy::utility::clear_set<tim1_af1_r>(mask, *this);}
	constexpr auto operator|(tim1_af1_r other) const -> tim1_af1_r { return static_cast<tim1_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af1_r> other) const -> opsy::utility::clear_set<tim1_af1_r> {return opsy::utility::clear_set<tim1_af1_r>(tim1_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto bkine() const -> bkine_f {return bkine_f((value_ & bkine_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp1e() const -> bkcmp1e_f {return bkcmp1e_f((value_ & bkcmp1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp2e() const -> bkcmp2e_f {return bkcmp2e_f((value_ & bkcmp2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp3e() const -> bkcmp3e_f {return bkcmp3e_f((value_ & bkcmp3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp4e() const -> bkcmp4e_f {return bkcmp4e_f((value_ & bkcmp4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp5e() const -> bkcmp5e_f {return bkcmp5e_f((value_ & bkcmp5e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp6e() const -> bkcmp6e_f {return bkcmp6e_f((value_ & bkcmp6e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp7e() const -> bkcmp7e_f {return bkcmp7e_f((value_ & bkcmp7e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp8e() const -> bkcmp8e_f {return bkcmp8e_f((value_ & bkcmp8e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkinp() const -> bkinp_f {return bkinp_f((value_ & bkinp_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp1p() const -> bkcmp1p_f {return bkcmp1p_f((value_ & bkcmp1p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp2p() const -> bkcmp2p_f {return bkcmp2p_f((value_ & bkcmp2p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp3p() const -> bkcmp3p_f {return bkcmp3p_f((value_ & bkcmp3p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkcmp4p() const -> bkcmp4p_f {return bkcmp4p_f((value_ & bkcmp4p_f::mask) != 0);}
	[[nodiscard]] constexpr auto etrsel() const -> etrsel_f {return etrsel_f(static_cast<uint8_t>(value_ >> etrsel_f::offset));}

	constexpr tim1_af1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_af1_r other) const -> tim1_af1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_af1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * TIM1 alternate function register 2
 */
class tim1_af2_r {
public:

/**
 * TIMx_BKIN2 input enable 
 */
class bk2ine_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2ine_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp1 enable 
 */
class bk2cmp1e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp2 enable 
 */
class bk2cmp2e_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp3 enable 
 */
class bk2cmp3e_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp4 enable 
 */
class bk2cmp4e_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp5 enable 
 */
class bk2cmp5e_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp5e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp6 enable 
 */
class bk2cmp6e_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp6e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp7 enable 
 */
class bk2cmp7e_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bk2cmp7e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp8 enable 
 */
class bk2cmp8e_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2cmp8e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TIMx_BKIN2 input polarity 
 */
class bk2inp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2inp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp1 input polarity 
 */
class bk2cmp1p_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2cmp1p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp2 input polarity 
 */
class bk2cmp2p_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2cmp2p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp3 input polarity 
 */
class bk2cmp3p_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2cmp3p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * tim_brk2_cmp4 input polarity 
 */
class bk2cmp4p_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bk2cmp4p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim1_af2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ocref_clr source selection 
 */
class ocrsel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ocrsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_af2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_af2_r>() const {return opsy::utility::clear_set<tim1_af2_r>(mask, *this);}
	constexpr auto operator|(tim1_af2_r other) const -> tim1_af2_r { return static_cast<tim1_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_af2_r> other) const -> opsy::utility::clear_set<tim1_af2_r> {return opsy::utility::clear_set<tim1_af2_r>(tim1_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto bk2ine() const -> bk2ine_f {return bk2ine_f((value_ & bk2ine_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp1e() const -> bk2cmp1e_f {return bk2cmp1e_f((value_ & bk2cmp1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp2e() const -> bk2cmp2e_f {return bk2cmp2e_f((value_ & bk2cmp2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp3e() const -> bk2cmp3e_f {return bk2cmp3e_f((value_ & bk2cmp3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp4e() const -> bk2cmp4e_f {return bk2cmp4e_f((value_ & bk2cmp4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp5e() const -> bk2cmp5e_f {return bk2cmp5e_f((value_ & bk2cmp5e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp6e() const -> bk2cmp6e_f {return bk2cmp6e_f((value_ & bk2cmp6e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp7e() const -> bk2cmp7e_f {return bk2cmp7e_f((value_ & bk2cmp7e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp8e() const -> bk2cmp8e_f {return bk2cmp8e_f((value_ & bk2cmp8e_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2inp() const -> bk2inp_f {return bk2inp_f((value_ & bk2inp_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp1p() const -> bk2cmp1p_f {return bk2cmp1p_f((value_ & bk2cmp1p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp2p() const -> bk2cmp2p_f {return bk2cmp2p_f((value_ & bk2cmp2p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp3p() const -> bk2cmp3p_f {return bk2cmp3p_f((value_ & bk2cmp3p_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk2cmp4p() const -> bk2cmp4p_f {return bk2cmp4p_f((value_ & bk2cmp4p_f::mask) != 0);}
	[[nodiscard]] constexpr auto ocrsel() const -> ocrsel_f {return ocrsel_f(static_cast<uint8_t>(value_ >> ocrsel_f::offset));}

	constexpr tim1_af2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_af2_r other) const -> tim1_af2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_af2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * TIM1 DMA control register
 */
class tim1_dcr_r {
public:

/**
 * DMA base address 
 */
class dba_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dba_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_dcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_dcr_r>() const {return opsy::utility::clear_set<tim1_dcr_r>(mask, *this);}
	constexpr auto operator|(tim1_dcr_r other) const -> tim1_dcr_r { return static_cast<tim1_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dcr_r> other) const -> opsy::utility::clear_set<tim1_dcr_r> {return opsy::utility::clear_set<tim1_dcr_r>(tim1_dcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA burst length 
 */
class dbl_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dbl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_dcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_dcr_r>() const {return opsy::utility::clear_set<tim1_dcr_r>(mask, *this);}
	constexpr auto operator|(tim1_dcr_r other) const -> tim1_dcr_r { return static_cast<tim1_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dcr_r> other) const -> opsy::utility::clear_set<tim1_dcr_r> {return opsy::utility::clear_set<tim1_dcr_r>(tim1_dcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DMA burst source selection 
 */
class dbss_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dbss_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim1_dcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_dcr_r>() const {return opsy::utility::clear_set<tim1_dcr_r>(mask, *this);}
	constexpr auto operator|(tim1_dcr_r other) const -> tim1_dcr_r { return static_cast<tim1_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dcr_r> other) const -> opsy::utility::clear_set<tim1_dcr_r> {return opsy::utility::clear_set<tim1_dcr_r>(tim1_dcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dba() const -> dba_f {return dba_f(static_cast<uint8_t>(value_ >> dba_f::offset));}
	[[nodiscard]] constexpr auto dbl() const -> dbl_f {return dbl_f(static_cast<uint8_t>(value_ >> dbl_f::offset));}
	[[nodiscard]] constexpr auto dbss() const -> dbss_f {return dbss_f(static_cast<uint8_t>(value_ >> dbss_f::offset));}

	constexpr tim1_dcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_dcr_r other) const -> tim1_dcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_dcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM1 DMA address for full transfer
 */
class tim1_dmar_r {
public:

/**
 * DMA register for burst accesses 
 */
class dmab_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dmab_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim1_dmar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim1_dmar_r>() const {return opsy::utility::clear_set<tim1_dmar_r>(mask, *this);}
	constexpr auto operator|(tim1_dmar_r other) const -> tim1_dmar_r { return static_cast<tim1_dmar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim1_dmar_r> other) const -> opsy::utility::clear_set<tim1_dmar_r> {return opsy::utility::clear_set<tim1_dmar_r>(tim1_dmar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto dmab() const -> dmab_f {return dmab_f(static_cast<uint32_t>(value_ >> dmab_f::offset));}

	constexpr tim1_dmar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim1_dmar_r other) const -> tim1_dmar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim1_dmar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint16_t,tim1_cr1_r> tim1_cr1;
	opsy::utility::padding<2> _p2;
	opsy::utility::memory<uint32_t,tim1_cr2_r> tim1_cr2;
	opsy::utility::memory<uint32_t,tim1_smcr_r> tim1_smcr;
	opsy::utility::memory<uint32_t,tim1_dier_r> tim1_dier;
	opsy::utility::memory<uint32_t,tim1_sr_r> tim1_sr;
	opsy::utility::write_only_memory<uint16_t,tim1_egr_r> tim1_egr;
	opsy::utility::padding<2> _p22;
	union {
		opsy::utility::memory<uint32_t,tim1_ccmr1_r> tim1_ccmr1;
		opsy::utility::memory<uint32_t,tim1_ccmr1_alternate1_r> tim1_ccmr1_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,tim1_ccmr2_r> tim1_ccmr2;
		opsy::utility::memory<uint32_t,tim1_ccmr2_alternate1_r> tim1_ccmr2_alternate1;
	};
	opsy::utility::memory<uint32_t,tim1_ccer_r> tim1_ccer;
	opsy::utility::memory<uint32_t,tim1_cnt_r> tim1_cnt;
	opsy::utility::memory<uint16_t,tim1_psc_r> tim1_psc;
	opsy::utility::padding<2> _p42;
	opsy::utility::memory<uint32_t,tim1_arr_r> tim1_arr;
	opsy::utility::memory<uint16_t,tim1_rcr_r> tim1_rcr;
	opsy::utility::padding<2> _p50;
	opsy::utility::memory<uint32_t,tim1_ccr1_r> tim1_ccr1;
	opsy::utility::memory<uint32_t,tim1_ccr2_r> tim1_ccr2;
	opsy::utility::memory<uint32_t,tim1_ccr3_r> tim1_ccr3;
	opsy::utility::memory<uint32_t,tim1_ccr4_r> tim1_ccr4;
	opsy::utility::memory<uint32_t,tim1_bdtr_r> tim1_bdtr;
	opsy::utility::memory<uint32_t,tim1_ccr5_r> tim1_ccr5;
	opsy::utility::memory<uint32_t,tim1_ccr6_r> tim1_ccr6;
	opsy::utility::memory<uint32_t,tim1_ccmr3_r> tim1_ccmr3;
	opsy::utility::memory<uint32_t,tim1_dtr2_r> tim1_dtr2;
	opsy::utility::memory<uint32_t,tim1_ecr_r> tim1_ecr;
	opsy::utility::memory<uint32_t,tim1_tisel_r> tim1_tisel;
	opsy::utility::memory<uint32_t,tim1_af1_r> tim1_af1;
	opsy::utility::memory<uint32_t,tim1_af2_r> tim1_af2;
	opsy::utility::padding<884> _p104;
	opsy::utility::memory<uint32_t,tim1_dcr_r> tim1_dcr;
	opsy::utility::memory<uint32_t,tim1_dmar_r> tim1_dmar;
};

static_assert(std::is_standard_layout_v<tim1_p>);
static_assert(offsetof(tim1_p, tim1_cr1) == 0);
static_assert(offsetof(tim1_p, tim1_cr2) == 4);
static_assert(offsetof(tim1_p, tim1_smcr) == 8);
static_assert(offsetof(tim1_p, tim1_dier) == 12);
static_assert(offsetof(tim1_p, tim1_sr) == 16);
static_assert(offsetof(tim1_p, tim1_egr) == 20);
static_assert(offsetof(tim1_p, tim1_ccmr1) == 24);
static_assert(offsetof(tim1_p, tim1_ccmr1_alternate1) == 24);
static_assert(offsetof(tim1_p, tim1_ccmr2) == 28);
static_assert(offsetof(tim1_p, tim1_ccmr2_alternate1) == 28);
static_assert(offsetof(tim1_p, tim1_ccer) == 32);
static_assert(offsetof(tim1_p, tim1_cnt) == 36);
static_assert(offsetof(tim1_p, tim1_psc) == 40);
static_assert(offsetof(tim1_p, tim1_arr) == 44);
static_assert(offsetof(tim1_p, tim1_rcr) == 48);
static_assert(offsetof(tim1_p, tim1_ccr1) == 52);
static_assert(offsetof(tim1_p, tim1_ccr2) == 56);
static_assert(offsetof(tim1_p, tim1_ccr3) == 60);
static_assert(offsetof(tim1_p, tim1_ccr4) == 64);
static_assert(offsetof(tim1_p, tim1_bdtr) == 68);
static_assert(offsetof(tim1_p, tim1_ccr5) == 72);
static_assert(offsetof(tim1_p, tim1_ccr6) == 76);
static_assert(offsetof(tim1_p, tim1_ccmr3) == 80);
static_assert(offsetof(tim1_p, tim1_dtr2) == 84);
static_assert(offsetof(tim1_p, tim1_ecr) == 88);
static_assert(offsetof(tim1_p, tim1_tisel) == 92);
static_assert(offsetof(tim1_p, tim1_af1) == 96);
static_assert(offsetof(tim1_p, tim1_af2) == 100);
static_assert(offsetof(tim1_p, tim1_dcr) == 988);
static_assert(offsetof(tim1_p, tim1_dmar) == 992);

inline tim1_p& tim1 = *reinterpret_cast<tim1_p*>(0x40012C00);
inline tim1_p& tim1_s = *reinterpret_cast<tim1_p*>(0x50012C00);

} // STM32H523

