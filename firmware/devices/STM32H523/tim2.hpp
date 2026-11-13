#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * TIM2 address block description
 */
class tim2_p {
public:

/**
 * TIM2 control register 1
 */
class tim2_cr1_r {
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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Dithering Enable 
 */
class dithen_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dithen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr1_r>() const {return opsy::utility::clear_set<tim2_cr1_r>(mask, *this);}
	constexpr auto operator|(tim2_cr1_r other) const -> tim2_cr1_r { return static_cast<tim2_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr1_r> other) const -> opsy::utility::clear_set<tim2_cr1_r> {return opsy::utility::clear_set<tim2_cr1_r>(tim2_cr1_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr tim2_cr1_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim2_cr1_r other) const -> tim2_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM2 control register 2
 */
class tim2_cr2_r {
public:

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
	constexpr operator tim2_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr2_r>() const {return opsy::utility::clear_set<tim2_cr2_r>(mask, *this);}
	constexpr auto operator|(tim2_cr2_r other) const -> tim2_cr2_r { return static_cast<tim2_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr2_r> other) const -> opsy::utility::clear_set<tim2_cr2_r> {return opsy::utility::clear_set<tim2_cr2_r>(tim2_cr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_cr2_r>() const {return opsy::utility::clear_set<tim2_cr2_r>(mask, *this);}
	constexpr auto operator|(tim2_cr2_r other) const -> tim2_cr2_r { return static_cast<tim2_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr2_r> other) const -> opsy::utility::clear_set<tim2_cr2_r> {return opsy::utility::clear_set<tim2_cr2_r>(tim2_cr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr2_r>() const {return opsy::utility::clear_set<tim2_cr2_r>(mask, *this);}
	constexpr auto operator|(tim2_cr2_r other) const -> tim2_cr2_r { return static_cast<tim2_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr2_r> other) const -> opsy::utility::clear_set<tim2_cr2_r> {return opsy::utility::clear_set<tim2_cr2_r>(tim2_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
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
	constexpr operator tim2_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cr2_r>() const {return opsy::utility::clear_set<tim2_cr2_r>(mask, *this);}
	constexpr auto operator|(tim2_cr2_r other) const -> tim2_cr2_r { return static_cast<tim2_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cr2_r> other) const -> opsy::utility::clear_set<tim2_cr2_r> {return opsy::utility::clear_set<tim2_cr2_r>(tim2_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ccds() const -> ccds_f {return ccds_f((value_ & ccds_f::mask) != 0);}
	[[nodiscard]] constexpr auto mms() const -> mms_f {return mms_f(static_cast<uint8_t>(value_ >> mms_f::offset));}
	[[nodiscard]] constexpr auto ti1s() const -> ti1s_f {return ti1s_f((value_ & ti1s_f::mask) != 0);}
	[[nodiscard]] constexpr auto mms_1() const -> mms_1_f {return mms_1_f((value_ & mms_1_f::mask) != 0);}

	constexpr tim2_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_cr2_r other) const -> tim2_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 slave mode control register
 */
class tim2_smcr_r {
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
	constexpr operator tim2_smcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Master/Slave mode
 */
class msm_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr msm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_smcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_smcr_r>() const {return opsy::utility::clear_set<tim2_smcr_r>(mask, *this);}
	constexpr auto operator|(tim2_smcr_r other) const -> tim2_smcr_r { return static_cast<tim2_smcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_smcr_r> other) const -> opsy::utility::clear_set<tim2_smcr_r> {return opsy::utility::clear_set<tim2_smcr_r>(tim2_smcr_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr tim2_smcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_smcr_r other) const -> tim2_smcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_smcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 DMA/Interrupt enable register
 */
class tim2_dier_r {
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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 interrupt enable
 */
class cc2ie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 interrupt enable
 */
class cc3ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 interrupt enable
 */
class cc4ie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 1 DMA request enable
 */
class cc1de_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 DMA request enable
 */
class cc2de_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 DMA request enable
 */
class cc3de_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 DMA request enable
 */
class cc4de_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_dier_r>() const {return opsy::utility::clear_set<tim2_dier_r>(mask, *this);}
	constexpr auto operator|(tim2_dier_r other) const -> tim2_dier_r { return static_cast<tim2_dier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dier_r> other) const -> opsy::utility::clear_set<tim2_dier_r> {return opsy::utility::clear_set<tim2_dier_r>(tim2_dier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uie() const -> uie_f {return uie_f((value_ & uie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ie() const -> cc2ie_f {return cc2ie_f((value_ & cc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3ie() const -> cc3ie_f {return cc3ie_f((value_ & cc3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4ie() const -> cc4ie_f {return cc4ie_f((value_ & cc4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tie() const -> tie_f {return tie_f((value_ & tie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ude() const -> ude_f {return ude_f((value_ & ude_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1de() const -> cc1de_f {return cc1de_f((value_ & cc1de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2de() const -> cc2de_f {return cc2de_f((value_ & cc2de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3de() const -> cc3de_f {return cc3de_f((value_ & cc3de_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4de() const -> cc4de_f {return cc4de_f((value_ & cc4de_f::mask) != 0);}
	[[nodiscard]] constexpr auto tde() const -> tde_f {return tde_f((value_ & tde_f::mask) != 0);}
	[[nodiscard]] constexpr auto idxie() const -> idxie_f {return idxie_f((value_ & idxie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dirie() const -> dirie_f {return dirie_f((value_ & dirie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ierrie() const -> ierrie_f {return ierrie_f((value_ & ierrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto terrie() const -> terrie_f {return terrie_f((value_ & terrie_f::mask) != 0);}

	constexpr tim2_dier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_dier_r other) const -> tim2_dier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_dier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 status register
 */
class tim2_sr_r {
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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 interrupt flag 
 */
class cc2if_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 interrupt flag 
 */
class cc3if_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc3if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 interrupt flag 
 */
class cc4if_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc4if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 1 overcapture flag 
 */
class cc1of_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 overcapture flag 
 */
class cc3of_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 overcapture flag 
 */
class cc4of_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_sr_r>() const {return opsy::utility::clear_set<tim2_sr_r>(mask, *this);}
	constexpr auto operator|(tim2_sr_r other) const -> tim2_sr_r { return static_cast<tim2_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_sr_r> other) const -> opsy::utility::clear_set<tim2_sr_r> {return opsy::utility::clear_set<tim2_sr_r>(tim2_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto uif() const -> uif_f {return uif_f((value_ & uif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2if() const -> cc2if_f {return cc2if_f((value_ & cc2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3if() const -> cc3if_f {return cc3if_f((value_ & cc3if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4if() const -> cc4if_f {return cc4if_f((value_ & cc4if_f::mask) != 0);}
	[[nodiscard]] constexpr auto tif() const -> tif_f {return tif_f((value_ & tif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1of() const -> cc1of_f {return cc1of_f((value_ & cc1of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2of() const -> cc2of_f {return cc2of_f((value_ & cc2of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3of() const -> cc3of_f {return cc3of_f((value_ & cc3of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4of() const -> cc4of_f {return cc4of_f((value_ & cc4of_f::mask) != 0);}
	[[nodiscard]] constexpr auto idxf() const -> idxf_f {return idxf_f((value_ & idxf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dirf() const -> dirf_f {return dirf_f((value_ & dirf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ierrf() const -> ierrf_f {return ierrf_f((value_ & ierrf_f::mask) != 0);}
	[[nodiscard]] constexpr auto terrf() const -> terrf_f {return terrf_f((value_ & terrf_f::mask) != 0);}

	constexpr tim2_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_sr_r other) const -> tim2_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 event generation register
 */
class tim2_egr_r {
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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_egr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_egr_r>() const {return opsy::utility::clear_set<tim2_egr_r>(mask, *this);}
	constexpr auto operator|(tim2_egr_r other) const -> tim2_egr_r { return static_cast<tim2_egr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_egr_r> other) const -> opsy::utility::clear_set<tim2_egr_r> {return opsy::utility::clear_set<tim2_egr_r>(tim2_egr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ug() const -> ug_f {return ug_f((value_ & ug_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1g() const -> cc1g_f {return cc1g_f((value_ & cc1g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2g() const -> cc2g_f {return cc2g_f((value_ & cc2g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3g() const -> cc3g_f {return cc3g_f((value_ & cc3g_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4g() const -> cc4g_f {return cc4g_f((value_ & cc4g_f::mask) != 0);}
	[[nodiscard]] constexpr auto tg() const -> tg_f {return tg_f((value_ & tg_f::mask) != 0);}

	constexpr tim2_egr_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim2_egr_r other) const -> tim2_egr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_egr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM2 capture/compare mode register 1
 */
class tim2_ccmr1_r {
public:

/**
 * Capture/Compare 1 selection 
 */
class cc1s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return static_cast<tim2_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_r> {return opsy::utility::clear_set<tim2_ccmr1_r>(tim2_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc1s() const -> cc1s_f {return cc1s_f(static_cast<uint8_t>(value_ >> cc1s_f::offset));}
	[[nodiscard]] constexpr auto ic1psc() const -> ic1psc_f {return ic1psc_f(static_cast<uint8_t>(value_ >> ic1psc_f::offset));}
	[[nodiscard]] constexpr auto ic1f() const -> ic1f_f {return ic1f_f(static_cast<uint8_t>(value_ >> ic1f_f::offset));}
	[[nodiscard]] constexpr auto cc2s() const -> cc2s_f {return cc2s_f(static_cast<uint8_t>(value_ >> cc2s_f::offset));}
	[[nodiscard]] constexpr auto ic2psc() const -> ic2psc_f {return ic2psc_f(static_cast<uint8_t>(value_ >> ic2psc_f::offset));}
	[[nodiscard]] constexpr auto ic2f() const -> ic2f_f {return ic2f_f(static_cast<uint8_t>(value_ >> ic2f_f::offset));}

	constexpr tim2_ccmr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccmr1_r other) const -> tim2_ccmr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccmr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare mode register 1
 */
class tim2_ccmr1_alternate1_r {
public:

/**
 * Capture/Compare 1 selection 
 */
class cc1s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr1_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 selection 
 */
class cc2s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc2s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr1_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr1_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return static_cast<tim2_ccmr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr1_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr1_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr1_alternate1_r>(tim2_ccmr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr tim2_ccmr1_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccmr1_alternate1_r other) const -> tim2_ccmr1_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccmr1_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare mode register 2
 */
class tim2_ccmr2_r {
public:

/**
 * Capture/Compare 3 selection 
 */
class cc3s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc3s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Capture/Compare 4 selection 
 */
class cc4s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc4s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_r>() const {return opsy::utility::clear_set<tim2_ccmr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return static_cast<tim2_ccmr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_r> {return opsy::utility::clear_set<tim2_ccmr2_r>(tim2_ccmr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc3s() const -> cc3s_f {return cc3s_f(static_cast<uint8_t>(value_ >> cc3s_f::offset));}
	[[nodiscard]] constexpr auto ic3psc() const -> ic3psc_f {return ic3psc_f(static_cast<uint8_t>(value_ >> ic3psc_f::offset));}
	[[nodiscard]] constexpr auto ic3f() const -> ic3f_f {return ic3f_f(static_cast<uint8_t>(value_ >> ic3f_f::offset));}
	[[nodiscard]] constexpr auto cc4s() const -> cc4s_f {return cc4s_f(static_cast<uint8_t>(value_ >> cc4s_f::offset));}
	[[nodiscard]] constexpr auto ic4psc() const -> ic4psc_f {return ic4psc_f(static_cast<uint8_t>(value_ >> ic4psc_f::offset));}
	[[nodiscard]] constexpr auto ic4f() const -> ic4f_f {return ic4f_f(static_cast<uint8_t>(value_ >> ic4f_f::offset));}

	constexpr tim2_ccmr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccmr2_r other) const -> tim2_ccmr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccmr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare mode register 2
 */
class tim2_ccmr2_alternate1_r {
public:

/**
 * Capture/Compare 3 selection 
 */
class cc3s_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc3s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr2_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 selection 
 */
class cc4s_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cc4s_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tim2_ccmr2_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ccmr2_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccmr2_alternate1_r>() const {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return static_cast<tim2_ccmr2_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccmr2_alternate1_r> other) const -> opsy::utility::clear_set<tim2_ccmr2_alternate1_r> {return opsy::utility::clear_set<tim2_ccmr2_alternate1_r>(tim2_ccmr2_alternate1_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr tim2_ccmr2_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccmr2_alternate1_r other) const -> tim2_ccmr2_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccmr2_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare enable register
 */
class tim2_ccer_r {
public:

/**
 * Capture/Compare 1 output enable.
 */
class cc1e_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 1 output Polarity.
 */
class cc1p_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 1 output Polarity.
 */
class cc1np_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 output enable.
 */
class cc2e_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 output Polarity.
 */
class cc2p_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 2 output Polarity.
 */
class cc2np_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc2np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 output enable.
 */
class cc3e_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 output Polarity.
 */
class cc3p_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 3 output Polarity.
 */
class cc3np_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc3np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 output enable.
 */
class cc4e_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 output Polarity.
 */
class cc4p_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4p_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/Compare 4 output Polarity.
 */
class cc4np_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc4np_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_ccer_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ccer_r>() const {return opsy::utility::clear_set<tim2_ccer_r>(mask, *this);}
	constexpr auto operator|(tim2_ccer_r other) const -> tim2_ccer_r { return static_cast<tim2_ccer_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccer_r> other) const -> opsy::utility::clear_set<tim2_ccer_r> {return opsy::utility::clear_set<tim2_ccer_r>(tim2_ccer_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1e() const -> cc1e_f {return cc1e_f((value_ & cc1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1p() const -> cc1p_f {return cc1p_f((value_ & cc1p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1np() const -> cc1np_f {return cc1np_f((value_ & cc1np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2e() const -> cc2e_f {return cc2e_f((value_ & cc2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2p() const -> cc2p_f {return cc2p_f((value_ & cc2p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2np() const -> cc2np_f {return cc2np_f((value_ & cc2np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3e() const -> cc3e_f {return cc3e_f((value_ & cc3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3p() const -> cc3p_f {return cc3p_f((value_ & cc3p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc3np() const -> cc3np_f {return cc3np_f((value_ & cc3np_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4e() const -> cc4e_f {return cc4e_f((value_ & cc4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4p() const -> cc4p_f {return cc4p_f((value_ & cc4p_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc4np() const -> cc4np_f {return cc4np_f((value_ & cc4np_f::mask) != 0);}

	constexpr tim2_ccer_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccer_r other) const -> tim2_ccer_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccer_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM2 counter
 */
class tim2_cnt_r {
public:

/**
 * Least significant part of counter value 
 */
class cnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 31;
	static constexpr uint32_t range = static_cast<uint32_t>(0b1111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cnt_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_cnt_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_cnt_r>() const {return opsy::utility::clear_set<tim2_cnt_r>(mask, *this);}
	constexpr auto operator|(tim2_cnt_r other) const -> tim2_cnt_r { return static_cast<tim2_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cnt_r> other) const -> opsy::utility::clear_set<tim2_cnt_r> {return opsy::utility::clear_set<tim2_cnt_r>(tim2_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Value depends on IUFREMAP in TIMx_CR1.
 */
class uifcpy_cnt_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uifcpy_cnt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tim2_cnt_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_cnt_r>() const {return opsy::utility::clear_set<tim2_cnt_r>(mask, *this);}
	constexpr auto operator|(tim2_cnt_r other) const -> tim2_cnt_r { return static_cast<tim2_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_cnt_r> other) const -> opsy::utility::clear_set<tim2_cnt_r> {return opsy::utility::clear_set<tim2_cnt_r>(tim2_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cnt() const -> cnt_f {return cnt_f(static_cast<uint32_t>(value_ >> cnt_f::offset));}
	[[nodiscard]] constexpr auto uifcpy_cnt() const -> uifcpy_cnt_f {return uifcpy_cnt_f((value_ & uifcpy_cnt_f::mask) != 0);}

	constexpr tim2_cnt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_cnt_r other) const -> tim2_cnt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_cnt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 prescaler
 */
class tim2_psc_r {
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
	constexpr operator tim2_psc_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_psc_r>() const {return opsy::utility::clear_set<tim2_psc_r>(mask, *this);}
	constexpr auto operator|(tim2_psc_r other) const -> tim2_psc_r { return static_cast<tim2_psc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_psc_r> other) const -> opsy::utility::clear_set<tim2_psc_r> {return opsy::utility::clear_set<tim2_psc_r>(tim2_psc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto psc() const -> psc_f {return psc_f(static_cast<uint16_t>(value_ >> psc_f::offset));}

	constexpr tim2_psc_r(uint16_t value) : value_(value) {}
	constexpr auto operator |(tim2_psc_r other) const -> tim2_psc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_psc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint16_t reset_value = 0; // 0 0x0

private:
	uint16_t value_;
};

/**
 * TIM2 auto-reload register
 */
class tim2_arr_r {
public:

/**
 * Auto-reload value 
 */
class arr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr arr_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_arr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_arr_r>() const {return opsy::utility::clear_set<tim2_arr_r>(mask, *this);}
	constexpr auto operator|(tim2_arr_r other) const -> tim2_arr_r { return static_cast<tim2_arr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_arr_r> other) const -> opsy::utility::clear_set<tim2_arr_r> {return opsy::utility::clear_set<tim2_arr_r>(tim2_arr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto arr() const -> arr_f {return arr_f(static_cast<uint32_t>(value_ >> arr_f::offset));}

	constexpr tim2_arr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_arr_r other) const -> tim2_arr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_arr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111111111111111111111; // 4294967295 0xFFFFFFFF

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare register 1
 */
class tim2_ccr1_r {
public:

/**
 * Capture/compare 1 value 
 */
class ccr1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_ccr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccr1_r>() const {return opsy::utility::clear_set<tim2_ccr1_r>(mask, *this);}
	constexpr auto operator|(tim2_ccr1_r other) const -> tim2_ccr1_r { return static_cast<tim2_ccr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccr1_r> other) const -> opsy::utility::clear_set<tim2_ccr1_r> {return opsy::utility::clear_set<tim2_ccr1_r>(tim2_ccr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr1() const -> ccr1_f {return ccr1_f(static_cast<uint32_t>(value_ >> ccr1_f::offset));}

	constexpr tim2_ccr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccr1_r other) const -> tim2_ccr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare register 2
 */
class tim2_ccr2_r {
public:

/**
 * Capture/compare 2 value 
 */
class ccr2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_ccr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccr2_r>() const {return opsy::utility::clear_set<tim2_ccr2_r>(mask, *this);}
	constexpr auto operator|(tim2_ccr2_r other) const -> tim2_ccr2_r { return static_cast<tim2_ccr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccr2_r> other) const -> opsy::utility::clear_set<tim2_ccr2_r> {return opsy::utility::clear_set<tim2_ccr2_r>(tim2_ccr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr2() const -> ccr2_f {return ccr2_f(static_cast<uint32_t>(value_ >> ccr2_f::offset));}

	constexpr tim2_ccr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccr2_r other) const -> tim2_ccr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare register 3
 */
class tim2_ccr3_r {
public:

/**
 * Capture/compare 3 value 
 */
class ccr3_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr3_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_ccr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccr3_r>() const {return opsy::utility::clear_set<tim2_ccr3_r>(mask, *this);}
	constexpr auto operator|(tim2_ccr3_r other) const -> tim2_ccr3_r { return static_cast<tim2_ccr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccr3_r> other) const -> opsy::utility::clear_set<tim2_ccr3_r> {return opsy::utility::clear_set<tim2_ccr3_r>(tim2_ccr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr3() const -> ccr3_f {return ccr3_f(static_cast<uint32_t>(value_ >> ccr3_f::offset));}

	constexpr tim2_ccr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccr3_r other) const -> tim2_ccr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 capture/compare register 4
 */
class tim2_ccr4_r {
public:

/**
 * Capture/compare 4 value 
 */
class ccr4_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ccr4_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tim2_ccr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ccr4_r>() const {return opsy::utility::clear_set<tim2_ccr4_r>(mask, *this);}
	constexpr auto operator|(tim2_ccr4_r other) const -> tim2_ccr4_r { return static_cast<tim2_ccr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ccr4_r> other) const -> opsy::utility::clear_set<tim2_ccr4_r> {return opsy::utility::clear_set<tim2_ccr4_r>(tim2_ccr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ccr4() const -> ccr4_f {return ccr4_f(static_cast<uint32_t>(value_ >> ccr4_f::offset));}

	constexpr tim2_ccr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ccr4_r other) const -> tim2_ccr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ccr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 timer encoder control register
 */
class tim2_ecr_r {
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
	constexpr operator tim2_ecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_ecr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_ecr_r>() const {return opsy::utility::clear_set<tim2_ecr_r>(mask, *this);}
	constexpr auto operator|(tim2_ecr_r other) const -> tim2_ecr_r { return static_cast<tim2_ecr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_ecr_r> other) const -> opsy::utility::clear_set<tim2_ecr_r> {return opsy::utility::clear_set<tim2_ecr_r>(tim2_ecr_r(mask) | other.clear(), *this | other.set()); }

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

	constexpr tim2_ecr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_ecr_r other) const -> tim2_ecr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_ecr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 timer input selection register
 */
class tim2_tisel_r {
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
	constexpr operator tim2_tisel_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_tisel_r>() const {return opsy::utility::clear_set<tim2_tisel_r>(mask, *this);}
	constexpr auto operator|(tim2_tisel_r other) const -> tim2_tisel_r { return static_cast<tim2_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_tisel_r> other) const -> opsy::utility::clear_set<tim2_tisel_r> {return opsy::utility::clear_set<tim2_tisel_r>(tim2_tisel_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_tisel_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_tisel_r>() const {return opsy::utility::clear_set<tim2_tisel_r>(mask, *this);}
	constexpr auto operator|(tim2_tisel_r other) const -> tim2_tisel_r { return static_cast<tim2_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_tisel_r> other) const -> opsy::utility::clear_set<tim2_tisel_r> {return opsy::utility::clear_set<tim2_tisel_r>(tim2_tisel_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_tisel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_tisel_r>() const {return opsy::utility::clear_set<tim2_tisel_r>(mask, *this);}
	constexpr auto operator|(tim2_tisel_r other) const -> tim2_tisel_r { return static_cast<tim2_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_tisel_r> other) const -> opsy::utility::clear_set<tim2_tisel_r> {return opsy::utility::clear_set<tim2_tisel_r>(tim2_tisel_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_tisel_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_tisel_r>() const {return opsy::utility::clear_set<tim2_tisel_r>(mask, *this);}
	constexpr auto operator|(tim2_tisel_r other) const -> tim2_tisel_r { return static_cast<tim2_tisel_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_tisel_r> other) const -> opsy::utility::clear_set<tim2_tisel_r> {return opsy::utility::clear_set<tim2_tisel_r>(tim2_tisel_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ti1sel() const -> ti1sel_f {return ti1sel_f(static_cast<uint8_t>(value_ >> ti1sel_f::offset));}
	[[nodiscard]] constexpr auto ti2sel() const -> ti2sel_f {return ti2sel_f(static_cast<uint8_t>(value_ >> ti2sel_f::offset));}
	[[nodiscard]] constexpr auto ti3sel() const -> ti3sel_f {return ti3sel_f(static_cast<uint8_t>(value_ >> ti3sel_f::offset));}
	[[nodiscard]] constexpr auto ti4sel() const -> ti4sel_f {return ti4sel_f(static_cast<uint8_t>(value_ >> ti4sel_f::offset));}

	constexpr tim2_tisel_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_tisel_r other) const -> tim2_tisel_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_tisel_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 alternate function register 1
 */
class tim2_af1_r {
public:

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
	constexpr operator tim2_af1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_af1_r>() const {return opsy::utility::clear_set<tim2_af1_r>(mask, *this);}
	constexpr auto operator|(tim2_af1_r other) const -> tim2_af1_r { return static_cast<tim2_af1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_af1_r> other) const -> opsy::utility::clear_set<tim2_af1_r> {return opsy::utility::clear_set<tim2_af1_r>(tim2_af1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto etrsel() const -> etrsel_f {return etrsel_f(static_cast<uint8_t>(value_ >> etrsel_f::offset));}

	constexpr tim2_af1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_af1_r other) const -> tim2_af1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_af1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 alternate function register 2
 */
class tim2_af2_r {
public:

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
	constexpr operator tim2_af2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_af2_r>() const {return opsy::utility::clear_set<tim2_af2_r>(mask, *this);}
	constexpr auto operator|(tim2_af2_r other) const -> tim2_af2_r { return static_cast<tim2_af2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_af2_r> other) const -> opsy::utility::clear_set<tim2_af2_r> {return opsy::utility::clear_set<tim2_af2_r>(tim2_af2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ocrsel() const -> ocrsel_f {return ocrsel_f(static_cast<uint8_t>(value_ >> ocrsel_f::offset));}

	constexpr tim2_af2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_af2_r other) const -> tim2_af2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_af2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 DMA control register
 */
class tim2_dcr_r {
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
	constexpr operator tim2_dcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_dcr_r>() const {return opsy::utility::clear_set<tim2_dcr_r>(mask, *this);}
	constexpr auto operator|(tim2_dcr_r other) const -> tim2_dcr_r { return static_cast<tim2_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dcr_r> other) const -> opsy::utility::clear_set<tim2_dcr_r> {return opsy::utility::clear_set<tim2_dcr_r>(tim2_dcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_dcr_r>() const {return opsy::utility::clear_set<tim2_dcr_r>(mask, *this);}
	constexpr auto operator|(tim2_dcr_r other) const -> tim2_dcr_r { return static_cast<tim2_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dcr_r> other) const -> opsy::utility::clear_set<tim2_dcr_r> {return opsy::utility::clear_set<tim2_dcr_r>(tim2_dcr_r(mask) | other.clear(), *this | other.set()); }

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
	constexpr operator tim2_dcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_dcr_r>() const {return opsy::utility::clear_set<tim2_dcr_r>(mask, *this);}
	constexpr auto operator|(tim2_dcr_r other) const -> tim2_dcr_r { return static_cast<tim2_dcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dcr_r> other) const -> opsy::utility::clear_set<tim2_dcr_r> {return opsy::utility::clear_set<tim2_dcr_r>(tim2_dcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dba() const -> dba_f {return dba_f(static_cast<uint8_t>(value_ >> dba_f::offset));}
	[[nodiscard]] constexpr auto dbl() const -> dbl_f {return dbl_f(static_cast<uint8_t>(value_ >> dbl_f::offset));}
	[[nodiscard]] constexpr auto dbss() const -> dbss_f {return dbss_f(static_cast<uint8_t>(value_ >> dbss_f::offset));}

	constexpr tim2_dcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_dcr_r other) const -> tim2_dcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_dcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TIM2 DMA address for full transfer
 */
class tim2_dmar_r {
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
	constexpr operator tim2_dmar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tim2_dmar_r>() const {return opsy::utility::clear_set<tim2_dmar_r>(mask, *this);}
	constexpr auto operator|(tim2_dmar_r other) const -> tim2_dmar_r { return static_cast<tim2_dmar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tim2_dmar_r> other) const -> opsy::utility::clear_set<tim2_dmar_r> {return opsy::utility::clear_set<tim2_dmar_r>(tim2_dmar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto dmab() const -> dmab_f {return dmab_f(static_cast<uint32_t>(value_ >> dmab_f::offset));}

	constexpr tim2_dmar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tim2_dmar_r other) const -> tim2_dmar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tim2_dmar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint16_t,tim2_cr1_r> tim2_cr1;
	opsy::utility::padding<2> _p2;
	opsy::utility::memory<uint32_t,tim2_cr2_r> tim2_cr2;
	opsy::utility::memory<uint32_t,tim2_smcr_r> tim2_smcr;
	opsy::utility::memory<uint32_t,tim2_dier_r> tim2_dier;
	opsy::utility::memory<uint32_t,tim2_sr_r> tim2_sr;
	opsy::utility::write_only_memory<uint16_t,tim2_egr_r> tim2_egr;
	opsy::utility::padding<2> _p22;
	union {
		opsy::utility::memory<uint32_t,tim2_ccmr1_r> tim2_ccmr1;
		opsy::utility::memory<uint32_t,tim2_ccmr1_alternate1_r> tim2_ccmr1_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,tim2_ccmr2_r> tim2_ccmr2;
		opsy::utility::memory<uint32_t,tim2_ccmr2_alternate1_r> tim2_ccmr2_alternate1;
	};
	opsy::utility::memory<uint16_t,tim2_ccer_r> tim2_ccer;
	opsy::utility::padding<2> _p34;
	opsy::utility::memory<uint32_t,tim2_cnt_r> tim2_cnt;
	opsy::utility::memory<uint16_t,tim2_psc_r> tim2_psc;
	opsy::utility::padding<2> _p42;
	opsy::utility::memory<uint32_t,tim2_arr_r> tim2_arr;
	opsy::utility::padding<4> _p48;
	opsy::utility::memory<uint32_t,tim2_ccr1_r> tim2_ccr1;
	opsy::utility::memory<uint32_t,tim2_ccr2_r> tim2_ccr2;
	opsy::utility::memory<uint32_t,tim2_ccr3_r> tim2_ccr3;
	opsy::utility::memory<uint32_t,tim2_ccr4_r> tim2_ccr4;
	opsy::utility::padding<20> _p68;
	opsy::utility::memory<uint32_t,tim2_ecr_r> tim2_ecr;
	opsy::utility::memory<uint32_t,tim2_tisel_r> tim2_tisel;
	opsy::utility::memory<uint32_t,tim2_af1_r> tim2_af1;
	opsy::utility::memory<uint32_t,tim2_af2_r> tim2_af2;
	opsy::utility::padding<884> _p104;
	opsy::utility::memory<uint32_t,tim2_dcr_r> tim2_dcr;
	opsy::utility::memory<uint32_t,tim2_dmar_r> tim2_dmar;
};

static_assert(std::is_standard_layout_v<tim2_p>);
static_assert(offsetof(tim2_p, tim2_cr1) == 0);
static_assert(offsetof(tim2_p, tim2_cr2) == 4);
static_assert(offsetof(tim2_p, tim2_smcr) == 8);
static_assert(offsetof(tim2_p, tim2_dier) == 12);
static_assert(offsetof(tim2_p, tim2_sr) == 16);
static_assert(offsetof(tim2_p, tim2_egr) == 20);
static_assert(offsetof(tim2_p, tim2_ccmr1) == 24);
static_assert(offsetof(tim2_p, tim2_ccmr1_alternate1) == 24);
static_assert(offsetof(tim2_p, tim2_ccmr2) == 28);
static_assert(offsetof(tim2_p, tim2_ccmr2_alternate1) == 28);
static_assert(offsetof(tim2_p, tim2_ccer) == 32);
static_assert(offsetof(tim2_p, tim2_cnt) == 36);
static_assert(offsetof(tim2_p, tim2_psc) == 40);
static_assert(offsetof(tim2_p, tim2_arr) == 44);
static_assert(offsetof(tim2_p, tim2_ccr1) == 52);
static_assert(offsetof(tim2_p, tim2_ccr2) == 56);
static_assert(offsetof(tim2_p, tim2_ccr3) == 60);
static_assert(offsetof(tim2_p, tim2_ccr4) == 64);
static_assert(offsetof(tim2_p, tim2_ecr) == 88);
static_assert(offsetof(tim2_p, tim2_tisel) == 92);
static_assert(offsetof(tim2_p, tim2_af1) == 96);
static_assert(offsetof(tim2_p, tim2_af2) == 100);
static_assert(offsetof(tim2_p, tim2_dcr) == 988);
static_assert(offsetof(tim2_p, tim2_dmar) == 992);

inline tim2_p& tim2 = *reinterpret_cast<tim2_p*>(0x40000000);
inline tim2_p& tim2_s = *reinterpret_cast<tim2_p*>(0x50000000);

} // STM32H523

