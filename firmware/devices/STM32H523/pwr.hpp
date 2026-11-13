#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * PWR address block description
 */
class pwr_p {
public:

/**
 * PWR power mode control register
 */
class pwr_pmcr_r {
public:

/**
 * low-power mode selection 
 */
class lpms_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpms_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * system Stop mode voltage scaling selection 
 */
class svos_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr svos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * clear Standby and Stop flags (always read as 0) 
 */
class cssf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cssf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * flash memory low-power mode in Stop mode 
 */
class flps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr flps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * analog switch Vless thansub>BOOSTless than/sub> control 
 */
class booste_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr booste_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * analog voltage ready 
 */
class avd_ready_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr avd_ready_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ETHERNET RAM shut-off in Stop mode.
 */
class ethernetso_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ethernetso_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM3 shut-off in Stop mode.
 */
class sram3so_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM2 16-Kbyte shut-off in Stop mode.
 */
class sram2_16so_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2_16so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM2 48-Kbyte shut-off in Stop mode.
 */
class sram2_48so_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2_48so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM1 shut-off in Stop mode
 */
class sram1so_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_r>() const {return opsy::utility::clear_set<pwr_pmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_r other) const -> pwr_pmcr_r { return static_cast<pwr_pmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_r> other) const -> opsy::utility::clear_set<pwr_pmcr_r> {return opsy::utility::clear_set<pwr_pmcr_r>(pwr_pmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lpms() const -> lpms_f {return lpms_f((value_ & lpms_f::mask) != 0);}
	[[nodiscard]] constexpr auto svos() const -> svos_f {return svos_f(static_cast<uint8_t>(value_ >> svos_f::offset));}
	[[nodiscard]] constexpr auto cssf() const -> cssf_f {return cssf_f((value_ & cssf_f::mask) != 0);}
	[[nodiscard]] constexpr auto flps() const -> flps_f {return flps_f((value_ & flps_f::mask) != 0);}
	[[nodiscard]] constexpr auto booste() const -> booste_f {return booste_f((value_ & booste_f::mask) != 0);}
	[[nodiscard]] constexpr auto avd_ready() const -> avd_ready_f {return avd_ready_f((value_ & avd_ready_f::mask) != 0);}
	[[nodiscard]] constexpr auto ethernetso() const -> ethernetso_f {return ethernetso_f((value_ & ethernetso_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3so() const -> sram3so_f {return sram3so_f((value_ & sram3so_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_16so() const -> sram2_16so_f {return sram2_16so_f((value_ & sram2_16so_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_48so() const -> sram2_48so_f {return sram2_48so_f((value_ & sram2_48so_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1so() const -> sram1so_f {return sram1so_f((value_ & sram1so_f::mask) != 0);}

	constexpr pwr_pmcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_pmcr_r other) const -> pwr_pmcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_pmcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1100; // 12 0xC

private:
	uint32_t value_;
};

/**
 * PWR power mode control register
 */
class pwr_pmcr_alternate1_r {
public:

/**
 * low-power mode selection 
 */
class lpms_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpms_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * system Stop mode voltage scaling selection 
 */
class svos_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr svos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * clear Standby and Stop flags (always read as 0) 
 */
class cssf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cssf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * flash memory low-power mode in Stop mode 
 */
class flps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr flps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * analog switch Vless thansub>BOOSTless than/sub> control 
 */
class booste_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr booste_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * analog voltage ready 
 */
class avd_ready_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr avd_ready_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM3 shut-off in Stop mode.
 */
class sram3so_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram3so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM2 low 16-Kbyte shut-off in Stop mode.
 */
class sram2_16lso_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2_16lso_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM2 high 16-Kbyte shut-off in Stop mode.
 */
class sram2_16hso_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2_16hso_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM2 48-Kbyte shut-off in Stop mode.
 */
class sram2_48so_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram2_48so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * AHB SRAM1 shut-off in Stop mode
 */
class sram1so_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sram1so_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmcr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmcr_alternate1_r>() const {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(mask, *this);}
	constexpr auto operator|(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return static_cast<pwr_pmcr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmcr_alternate1_r> other) const -> opsy::utility::clear_set<pwr_pmcr_alternate1_r> {return opsy::utility::clear_set<pwr_pmcr_alternate1_r>(pwr_pmcr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lpms() const -> lpms_f {return lpms_f((value_ & lpms_f::mask) != 0);}
	[[nodiscard]] constexpr auto svos() const -> svos_f {return svos_f(static_cast<uint8_t>(value_ >> svos_f::offset));}
	[[nodiscard]] constexpr auto cssf() const -> cssf_f {return cssf_f((value_ & cssf_f::mask) != 0);}
	[[nodiscard]] constexpr auto flps() const -> flps_f {return flps_f((value_ & flps_f::mask) != 0);}
	[[nodiscard]] constexpr auto booste() const -> booste_f {return booste_f((value_ & booste_f::mask) != 0);}
	[[nodiscard]] constexpr auto avd_ready() const -> avd_ready_f {return avd_ready_f((value_ & avd_ready_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3so() const -> sram3so_f {return sram3so_f((value_ & sram3so_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_16lso() const -> sram2_16lso_f {return sram2_16lso_f((value_ & sram2_16lso_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_16hso() const -> sram2_16hso_f {return sram2_16hso_f((value_ & sram2_16hso_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_48so() const -> sram2_48so_f {return sram2_48so_f((value_ & sram2_48so_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram1so() const -> sram1so_f {return sram1so_f((value_ & sram1so_f::mask) != 0);}

	constexpr pwr_pmcr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_pmcr_alternate1_r other) const -> pwr_pmcr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_pmcr_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1100; // 12 0xC

private:
	uint32_t value_;
};

/**
 * PWR status register
 */
class pwr_pmsr_r {
public:

/**
 * Stop flag 
 */
class stopf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr stopf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmsr_r>() const {return opsy::utility::clear_set<pwr_pmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmsr_r other) const -> pwr_pmsr_r { return static_cast<pwr_pmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmsr_r> other) const -> opsy::utility::clear_set<pwr_pmsr_r> {return opsy::utility::clear_set<pwr_pmsr_r>(pwr_pmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * System standby flag 
 */
class sbf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_pmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_pmsr_r>() const {return opsy::utility::clear_set<pwr_pmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_pmsr_r other) const -> pwr_pmsr_r { return static_cast<pwr_pmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_pmsr_r> other) const -> opsy::utility::clear_set<pwr_pmsr_r> {return opsy::utility::clear_set<pwr_pmsr_r>(pwr_pmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto stopf() const -> stopf_f {return stopf_f((value_ & stopf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbf() const -> sbf_f {return sbf_f((value_ & sbf_f::mask) != 0);}

	constexpr pwr_pmsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_pmsr_r other) const -> pwr_pmsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_pmsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR voltage scaling control register
 */
class pwr_voscr_r {
public:

/**
 * voltage scaling selection according to performance 
 */
class vos_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr vos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_voscr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_voscr_r>() const {return opsy::utility::clear_set<pwr_voscr_r>(mask, *this);}
	constexpr auto operator|(pwr_voscr_r other) const -> pwr_voscr_r { return static_cast<pwr_voscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_voscr_r> other) const -> opsy::utility::clear_set<pwr_voscr_r> {return opsy::utility::clear_set<pwr_voscr_r>(pwr_voscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto vos() const -> vos_f {return vos_f(static_cast<uint8_t>(value_ >> vos_f::offset));}

	constexpr pwr_voscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_voscr_r other) const -> pwr_voscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_voscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR voltage scaling status register
 */
class pwr_vossr_r {
public:

/**
 * Ready bit for Vless thansub>COREless than/sub> voltage scaling output selection.
 */
class vosrdy_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vosrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vossr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vossr_r>() const {return opsy::utility::clear_set<pwr_vossr_r>(mask, *this);}
	constexpr auto operator|(pwr_vossr_r other) const -> pwr_vossr_r { return static_cast<pwr_vossr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vossr_r> other) const -> opsy::utility::clear_set<pwr_vossr_r> {return opsy::utility::clear_set<pwr_vossr_r>(pwr_vossr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Voltage level ready for currently used VOS
 */
class actvosrdy_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr actvosrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vossr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vossr_r>() const {return opsy::utility::clear_set<pwr_vossr_r>(mask, *this);}
	constexpr auto operator|(pwr_vossr_r other) const -> pwr_vossr_r { return static_cast<pwr_vossr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vossr_r> other) const -> opsy::utility::clear_set<pwr_vossr_r> {return opsy::utility::clear_set<pwr_vossr_r>(pwr_vossr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * voltage output scaling currently applied to Vless thansub>COREless than/sub> 
 */
class actvos_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr actvos_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_vossr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_vossr_r>() const {return opsy::utility::clear_set<pwr_vossr_r>(mask, *this);}
	constexpr auto operator|(pwr_vossr_r other) const -> pwr_vossr_r { return static_cast<pwr_vossr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vossr_r> other) const -> opsy::utility::clear_set<pwr_vossr_r> {return opsy::utility::clear_set<pwr_vossr_r>(pwr_vossr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto vosrdy() const -> vosrdy_f {return vosrdy_f((value_ & vosrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto actvosrdy() const -> actvosrdy_f {return actvosrdy_f((value_ & actvosrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto actvos() const -> actvos_f {return actvos_f(static_cast<uint8_t>(value_ >> actvos_f::offset));}

	constexpr pwr_vossr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_vossr_r other) const -> pwr_vossr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_vossr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000001000; // 8200 0x2008

private:
	uint32_t value_;
};

/**
 * PWR Backup domain control register
 */
class pwr_bdcr_r {
public:

/**
 * Backup RAM retention in Standby and Vless thansub>BATless than/sub> modes 
 */
class bren_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdcr_r>() const {return opsy::utility::clear_set<pwr_bdcr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdcr_r other) const -> pwr_bdcr_r { return static_cast<pwr_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdcr_r> other) const -> opsy::utility::clear_set<pwr_bdcr_r> {return opsy::utility::clear_set<pwr_bdcr_r>(pwr_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup domain voltage and temperature monitoring enable
 */
class monen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr monen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdcr_r>() const {return opsy::utility::clear_set<pwr_bdcr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdcr_r other) const -> pwr_bdcr_r { return static_cast<pwr_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdcr_r> other) const -> opsy::utility::clear_set<pwr_bdcr_r> {return opsy::utility::clear_set<pwr_bdcr_r>(pwr_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>BATless than/sub> charging enable 
 */
class vbe_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vbe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdcr_r>() const {return opsy::utility::clear_set<pwr_bdcr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdcr_r other) const -> pwr_bdcr_r { return static_cast<pwr_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdcr_r> other) const -> opsy::utility::clear_set<pwr_bdcr_r> {return opsy::utility::clear_set<pwr_bdcr_r>(pwr_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>BATless than/sub> charging resistor selection
 */
class vbrs_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vbrs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdcr_r>() const {return opsy::utility::clear_set<pwr_bdcr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdcr_r other) const -> pwr_bdcr_r { return static_cast<pwr_bdcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdcr_r> other) const -> opsy::utility::clear_set<pwr_bdcr_r> {return opsy::utility::clear_set<pwr_bdcr_r>(pwr_bdcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bren() const -> bren_f {return bren_f((value_ & bren_f::mask) != 0);}
	[[nodiscard]] constexpr auto monen() const -> monen_f {return monen_f((value_ & monen_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbe() const -> vbe_f {return vbe_f((value_ & vbe_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbrs() const -> vbrs_f {return vbrs_f((value_ & vbrs_f::mask) != 0);}

	constexpr pwr_bdcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_bdcr_r other) const -> pwr_bdcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_bdcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR Backup domain control register
 */
class pwr_dbpcr_r {
public:

/**
 * Disable Backup domain write protection 
 */
class dbp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_dbpcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_dbpcr_r>() const {return opsy::utility::clear_set<pwr_dbpcr_r>(mask, *this);}
	constexpr auto operator|(pwr_dbpcr_r other) const -> pwr_dbpcr_r { return static_cast<pwr_dbpcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_dbpcr_r> other) const -> opsy::utility::clear_set<pwr_dbpcr_r> {return opsy::utility::clear_set<pwr_dbpcr_r>(pwr_dbpcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dbp() const -> dbp_f {return dbp_f((value_ & dbp_f::mask) != 0);}

	constexpr pwr_dbpcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_dbpcr_r other) const -> pwr_dbpcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_dbpcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR Backup domain status register
 */
class pwr_bdsr_r {
public:

/**
 * backup regulator ready 
 */
class brrdy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr brrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdsr_r>() const {return opsy::utility::clear_set<pwr_bdsr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdsr_r other) const -> pwr_bdsr_r { return static_cast<pwr_bdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdsr_r> other) const -> opsy::utility::clear_set<pwr_bdsr_r> {return opsy::utility::clear_set<pwr_bdsr_r>(pwr_bdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>BATless than/sub> level monitoring versus low threshold
 */
class vbatl_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vbatl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdsr_r>() const {return opsy::utility::clear_set<pwr_bdsr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdsr_r other) const -> pwr_bdsr_r { return static_cast<pwr_bdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdsr_r> other) const -> opsy::utility::clear_set<pwr_bdsr_r> {return opsy::utility::clear_set<pwr_bdsr_r>(pwr_bdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>BATless than/sub> level monitoring versus high threshold
 */
class vbath_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vbath_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdsr_r>() const {return opsy::utility::clear_set<pwr_bdsr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdsr_r other) const -> pwr_bdsr_r { return static_cast<pwr_bdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdsr_r> other) const -> opsy::utility::clear_set<pwr_bdsr_r> {return opsy::utility::clear_set<pwr_bdsr_r>(pwr_bdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * temperature level monitoring versus low threshold
 */
class templ_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr templ_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdsr_r>() const {return opsy::utility::clear_set<pwr_bdsr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdsr_r other) const -> pwr_bdsr_r { return static_cast<pwr_bdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdsr_r> other) const -> opsy::utility::clear_set<pwr_bdsr_r> {return opsy::utility::clear_set<pwr_bdsr_r>(pwr_bdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * temperature level monitoring versus high threshold
 */
class temph_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr temph_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_bdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_bdsr_r>() const {return opsy::utility::clear_set<pwr_bdsr_r>(mask, *this);}
	constexpr auto operator|(pwr_bdsr_r other) const -> pwr_bdsr_r { return static_cast<pwr_bdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_bdsr_r> other) const -> opsy::utility::clear_set<pwr_bdsr_r> {return opsy::utility::clear_set<pwr_bdsr_r>(pwr_bdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto brrdy() const -> brrdy_f {return brrdy_f((value_ & brrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbatl() const -> vbatl_f {return vbatl_f((value_ & vbatl_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbath() const -> vbath_f {return vbath_f((value_ & vbath_f::mask) != 0);}
	[[nodiscard]] constexpr auto templ() const -> templ_f {return templ_f((value_ & templ_f::mask) != 0);}
	[[nodiscard]] constexpr auto temph() const -> temph_f {return temph_f((value_ & temph_f::mask) != 0);}

	constexpr pwr_bdsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_bdsr_r other) const -> pwr_bdsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_bdsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR USB Type-C power delivery register
 */
class pwr_ucpdr_r {
public:

/**
 * USB Type-C and power delivery dead battery disable 
 */
class ucpd_dbdis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpd_dbdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_ucpdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_ucpdr_r>() const {return opsy::utility::clear_set<pwr_ucpdr_r>(mask, *this);}
	constexpr auto operator|(pwr_ucpdr_r other) const -> pwr_ucpdr_r { return static_cast<pwr_ucpdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_ucpdr_r> other) const -> opsy::utility::clear_set<pwr_ucpdr_r> {return opsy::utility::clear_set<pwr_ucpdr_r>(pwr_ucpdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB Type-c and Power delivery Standby mode 
 */
class ucpd_stby_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ucpd_stby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_ucpdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_ucpdr_r>() const {return opsy::utility::clear_set<pwr_ucpdr_r>(mask, *this);}
	constexpr auto operator|(pwr_ucpdr_r other) const -> pwr_ucpdr_r { return static_cast<pwr_ucpdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_ucpdr_r> other) const -> opsy::utility::clear_set<pwr_ucpdr_r> {return opsy::utility::clear_set<pwr_ucpdr_r>(pwr_ucpdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ucpd_dbdis() const -> ucpd_dbdis_f {return ucpd_dbdis_f((value_ & ucpd_dbdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ucpd_stby() const -> ucpd_stby_f {return ucpd_stby_f((value_ & ucpd_stby_f::mask) != 0);}

	constexpr pwr_ucpdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_ucpdr_r other) const -> pwr_ucpdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_ucpdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR supply configuration control register
 */
class pwr_sccr_r {
public:

/**
 * power management unit bypass
 */
class bypass_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bypass_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_sccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_sccr_r>() const {return opsy::utility::clear_set<pwr_sccr_r>(mask, *this);}
	constexpr auto operator|(pwr_sccr_r other) const -> pwr_sccr_r { return static_cast<pwr_sccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_sccr_r> other) const -> opsy::utility::clear_set<pwr_sccr_r> {return opsy::utility::clear_set<pwr_sccr_r>(pwr_sccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LDO enable 
 */
class ldoen_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ldoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_sccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_sccr_r>() const {return opsy::utility::clear_set<pwr_sccr_r>(mask, *this);}
	constexpr auto operator|(pwr_sccr_r other) const -> pwr_sccr_r { return static_cast<pwr_sccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_sccr_r> other) const -> opsy::utility::clear_set<pwr_sccr_r> {return opsy::utility::clear_set<pwr_sccr_r>(pwr_sccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SMPS enable 
 */
class smpsen_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr smpsen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_sccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_sccr_r>() const {return opsy::utility::clear_set<pwr_sccr_r>(mask, *this);}
	constexpr auto operator|(pwr_sccr_r other) const -> pwr_sccr_r { return static_cast<pwr_sccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_sccr_r> other) const -> opsy::utility::clear_set<pwr_sccr_r> {return opsy::utility::clear_set<pwr_sccr_r>(pwr_sccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bypass() const -> bypass_f {return bypass_f((value_ & bypass_f::mask) != 0);}
	[[nodiscard]] constexpr auto ldoen() const -> ldoen_f {return ldoen_f((value_ & ldoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto smpsen() const -> smpsen_f {return smpsen_f((value_ & smpsen_f::mask) != 0);}

	constexpr pwr_sccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_sccr_r other) const -> pwr_sccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_sccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000; // 256 0x100

private:
	uint32_t value_;
};

/**
 * PWR voltage monitor control register
 */
class pwr_vmcr_r {
public:

/**
 * PVD enable
 */
class pvde_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pvde_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmcr_r>() const {return opsy::utility::clear_set<pwr_vmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmcr_r other) const -> pwr_vmcr_r { return static_cast<pwr_vmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmcr_r> other) const -> opsy::utility::clear_set<pwr_vmcr_r> {return opsy::utility::clear_set<pwr_vmcr_r>(pwr_vmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programmable voltage detector (PVD) level selection 
 */
class pls_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pls_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_vmcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_vmcr_r>() const {return opsy::utility::clear_set<pwr_vmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmcr_r other) const -> pwr_vmcr_r { return static_cast<pwr_vmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmcr_r> other) const -> opsy::utility::clear_set<pwr_vmcr_r> {return opsy::utility::clear_set<pwr_vmcr_r>(pwr_vmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * peripheral voltage monitor on Vless thansub>DDAless than/sub> enable
 */
class avden_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr avden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmcr_r>() const {return opsy::utility::clear_set<pwr_vmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmcr_r other) const -> pwr_vmcr_r { return static_cast<pwr_vmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmcr_r> other) const -> opsy::utility::clear_set<pwr_vmcr_r> {return opsy::utility::clear_set<pwr_vmcr_r>(pwr_vmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * analog voltage detector (AVD) level selection 
 */
class als_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr als_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_vmcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_vmcr_r>() const {return opsy::utility::clear_set<pwr_vmcr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmcr_r other) const -> pwr_vmcr_r { return static_cast<pwr_vmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmcr_r> other) const -> opsy::utility::clear_set<pwr_vmcr_r> {return opsy::utility::clear_set<pwr_vmcr_r>(pwr_vmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pvde() const -> pvde_f {return pvde_f((value_ & pvde_f::mask) != 0);}
	[[nodiscard]] constexpr auto pls() const -> pls_f {return pls_f(static_cast<uint8_t>(value_ >> pls_f::offset));}
	[[nodiscard]] constexpr auto avden() const -> avden_f {return avden_f((value_ & avden_f::mask) != 0);}
	[[nodiscard]] constexpr auto als() const -> als_f {return als_f(static_cast<uint8_t>(value_ >> als_f::offset));}

	constexpr pwr_vmcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_vmcr_r other) const -> pwr_vmcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_vmcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR USB supply control register
 */
class pwr_usbscr_r {
public:

/**
 * Vless thansub>DDUSBless than/sub> voltage level detector enable
 */
class usb33den_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usb33den_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_usbscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_usbscr_r>() const {return opsy::utility::clear_set<pwr_usbscr_r>(mask, *this);}
	constexpr auto operator|(pwr_usbscr_r other) const -> pwr_usbscr_r { return static_cast<pwr_usbscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_usbscr_r> other) const -> opsy::utility::clear_set<pwr_usbscr_r> {return opsy::utility::clear_set<pwr_usbscr_r>(pwr_usbscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * independent USB supply valid 
 */
class usb33sv_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usb33sv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_usbscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_usbscr_r>() const {return opsy::utility::clear_set<pwr_usbscr_r>(mask, *this);}
	constexpr auto operator|(pwr_usbscr_r other) const -> pwr_usbscr_r { return static_cast<pwr_usbscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_usbscr_r> other) const -> opsy::utility::clear_set<pwr_usbscr_r> {return opsy::utility::clear_set<pwr_usbscr_r>(pwr_usbscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto usb33den() const -> usb33den_f {return usb33den_f((value_ & usb33den_f::mask) != 0);}
	[[nodiscard]] constexpr auto usb33sv() const -> usb33sv_f {return usb33sv_f((value_ & usb33sv_f::mask) != 0);}

	constexpr pwr_usbscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_usbscr_r other) const -> pwr_usbscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_usbscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR voltage monitor status register
 */
class pwr_vmsr_r {
public:

/**
 * analog voltage detector output on Vless thansub>DDAless than/sub> 
 */
class avdo_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr avdo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmsr_r>() const {return opsy::utility::clear_set<pwr_vmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmsr_r other) const -> pwr_vmsr_r { return static_cast<pwr_vmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmsr_r> other) const -> opsy::utility::clear_set<pwr_vmsr_r> {return opsy::utility::clear_set<pwr_vmsr_r>(pwr_vmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * voltage detector output on Vless thansub>DDIO2less than/sub> 
 */
class vddio2rdy_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr vddio2rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmsr_r>() const {return opsy::utility::clear_set<pwr_vmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmsr_r other) const -> pwr_vmsr_r { return static_cast<pwr_vmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmsr_r> other) const -> opsy::utility::clear_set<pwr_vmsr_r> {return opsy::utility::clear_set<pwr_vmsr_r>(pwr_vmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programmable voltage detect output 
 */
class pvdo_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pvdo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmsr_r>() const {return opsy::utility::clear_set<pwr_vmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmsr_r other) const -> pwr_vmsr_r { return static_cast<pwr_vmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmsr_r> other) const -> opsy::utility::clear_set<pwr_vmsr_r> {return opsy::utility::clear_set<pwr_vmsr_r>(pwr_vmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vless thansub>DDUSBless than/sub> ready
 */
class usb33rdy_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usb33rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_vmsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_vmsr_r>() const {return opsy::utility::clear_set<pwr_vmsr_r>(mask, *this);}
	constexpr auto operator|(pwr_vmsr_r other) const -> pwr_vmsr_r { return static_cast<pwr_vmsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_vmsr_r> other) const -> opsy::utility::clear_set<pwr_vmsr_r> {return opsy::utility::clear_set<pwr_vmsr_r>(pwr_vmsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto avdo() const -> avdo_f {return avdo_f((value_ & avdo_f::mask) != 0);}
	[[nodiscard]] constexpr auto vddio2rdy() const -> vddio2rdy_f {return vddio2rdy_f((value_ & vddio2rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto pvdo() const -> pvdo_f {return pvdo_f((value_ & pvdo_f::mask) != 0);}
	[[nodiscard]] constexpr auto usb33rdy() const -> usb33rdy_f {return usb33rdy_f((value_ & usb33rdy_f::mask) != 0);}

	constexpr pwr_vmsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_vmsr_r other) const -> pwr_vmsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_vmsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR wake-up status clear register
 */
class pwr_wuscr_r {
public:

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf2_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf3_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf4_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf5_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf6_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf7_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * clear wake-up pin flag for WUFx (x = 8 to 1) 
 */
class cwuf8_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwuf8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wuscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wuscr_r>() const {return opsy::utility::clear_set<pwr_wuscr_r>(mask, *this);}
	constexpr auto operator|(pwr_wuscr_r other) const -> pwr_wuscr_r { return static_cast<pwr_wuscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wuscr_r> other) const -> opsy::utility::clear_set<pwr_wuscr_r> {return opsy::utility::clear_set<pwr_wuscr_r>(pwr_wuscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cwuf1() const -> cwuf1_f {return cwuf1_f((value_ & cwuf1_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf2() const -> cwuf2_f {return cwuf2_f((value_ & cwuf2_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf3() const -> cwuf3_f {return cwuf3_f((value_ & cwuf3_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf4() const -> cwuf4_f {return cwuf4_f((value_ & cwuf4_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf5() const -> cwuf5_f {return cwuf5_f((value_ & cwuf5_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf6() const -> cwuf6_f {return cwuf6_f((value_ & cwuf6_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf7() const -> cwuf7_f {return cwuf7_f((value_ & cwuf7_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwuf8() const -> cwuf8_f {return cwuf8_f((value_ & cwuf8_f::mask) != 0);}

	constexpr pwr_wuscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_wuscr_r other) const -> pwr_wuscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_wuscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR wake-up status register
 */
class pwr_wusr_r {
public:

/**
 * wake-up pin WUFx flag 
 */
class wuf1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf2_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf3_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf4_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf5_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf6_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf7_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin WUFx flag 
 */
class wuf8_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wuf8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wusr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wusr_r>() const {return opsy::utility::clear_set<pwr_wusr_r>(mask, *this);}
	constexpr auto operator|(pwr_wusr_r other) const -> pwr_wusr_r { return static_cast<pwr_wusr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wusr_r> other) const -> opsy::utility::clear_set<pwr_wusr_r> {return opsy::utility::clear_set<pwr_wusr_r>(pwr_wusr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto wuf1() const -> wuf1_f {return wuf1_f((value_ & wuf1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf2() const -> wuf2_f {return wuf2_f((value_ & wuf2_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf3() const -> wuf3_f {return wuf3_f((value_ & wuf3_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf4() const -> wuf4_f {return wuf4_f((value_ & wuf4_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf5() const -> wuf5_f {return wuf5_f((value_ & wuf5_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf6() const -> wuf6_f {return wuf6_f((value_ & wuf6_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf7() const -> wuf7_f {return wuf7_f((value_ & wuf7_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf8() const -> wuf8_f {return wuf8_f((value_ & wuf8_f::mask) != 0);}

	constexpr pwr_wusr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_wusr_r other) const -> pwr_wusr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_wusr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR wake-up configuration register
 */
class pwr_wucr_r {
public:

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen2_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen3_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen4_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen5_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen6_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen7_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * enable wake-up pin WUPx (x = 8 to 1) 
 */
class wupen8_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wupen8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp2_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp3_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp4_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp5_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp6_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp7_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin polarity bit for WUPx (x = 8 to 1) 
 */
class wupp8_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wupp8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_wucr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd1_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd2_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd3_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd4_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd5_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd5_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd6_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd6_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd7_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd7_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * wake-up pin pull configuration for WKUPx (x = 8 to 1) 
 */
class wuppupd8_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wuppupd8_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator pwr_wucr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<pwr_wucr_r>() const {return opsy::utility::clear_set<pwr_wucr_r>(mask, *this);}
	constexpr auto operator|(pwr_wucr_r other) const -> pwr_wucr_r { return static_cast<pwr_wucr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_wucr_r> other) const -> opsy::utility::clear_set<pwr_wucr_r> {return opsy::utility::clear_set<pwr_wucr_r>(pwr_wucr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto wupen1() const -> wupen1_f {return wupen1_f((value_ & wupen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen2() const -> wupen2_f {return wupen2_f((value_ & wupen2_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen3() const -> wupen3_f {return wupen3_f((value_ & wupen3_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen4() const -> wupen4_f {return wupen4_f((value_ & wupen4_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen5() const -> wupen5_f {return wupen5_f((value_ & wupen5_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen6() const -> wupen6_f {return wupen6_f((value_ & wupen6_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen7() const -> wupen7_f {return wupen7_f((value_ & wupen7_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupen8() const -> wupen8_f {return wupen8_f((value_ & wupen8_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp1() const -> wupp1_f {return wupp1_f((value_ & wupp1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp2() const -> wupp2_f {return wupp2_f((value_ & wupp2_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp3() const -> wupp3_f {return wupp3_f((value_ & wupp3_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp4() const -> wupp4_f {return wupp4_f((value_ & wupp4_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp5() const -> wupp5_f {return wupp5_f((value_ & wupp5_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp6() const -> wupp6_f {return wupp6_f((value_ & wupp6_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp7() const -> wupp7_f {return wupp7_f((value_ & wupp7_f::mask) != 0);}
	[[nodiscard]] constexpr auto wupp8() const -> wupp8_f {return wupp8_f((value_ & wupp8_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuppupd1() const -> wuppupd1_f {return wuppupd1_f(static_cast<uint8_t>(value_ >> wuppupd1_f::offset));}
	[[nodiscard]] constexpr auto wuppupd2() const -> wuppupd2_f {return wuppupd2_f(static_cast<uint8_t>(value_ >> wuppupd2_f::offset));}
	[[nodiscard]] constexpr auto wuppupd3() const -> wuppupd3_f {return wuppupd3_f(static_cast<uint8_t>(value_ >> wuppupd3_f::offset));}
	[[nodiscard]] constexpr auto wuppupd4() const -> wuppupd4_f {return wuppupd4_f(static_cast<uint8_t>(value_ >> wuppupd4_f::offset));}
	[[nodiscard]] constexpr auto wuppupd5() const -> wuppupd5_f {return wuppupd5_f(static_cast<uint8_t>(value_ >> wuppupd5_f::offset));}
	[[nodiscard]] constexpr auto wuppupd6() const -> wuppupd6_f {return wuppupd6_f(static_cast<uint8_t>(value_ >> wuppupd6_f::offset));}
	[[nodiscard]] constexpr auto wuppupd7() const -> wuppupd7_f {return wuppupd7_f(static_cast<uint8_t>(value_ >> wuppupd7_f::offset));}
	[[nodiscard]] constexpr auto wuppupd8() const -> wuppupd8_f {return wuppupd8_f(static_cast<uint8_t>(value_ >> wuppupd8_f::offset));}

	constexpr pwr_wucr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_wucr_r other) const -> pwr_wucr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_wucr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR I/O retention register
 */
class pwr_ioretr_r {
public:

/**
 * IO retention enable 
 */
class ioreten_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ioreten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_ioretr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_ioretr_r>() const {return opsy::utility::clear_set<pwr_ioretr_r>(mask, *this);}
	constexpr auto operator|(pwr_ioretr_r other) const -> pwr_ioretr_r { return static_cast<pwr_ioretr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_ioretr_r> other) const -> opsy::utility::clear_set<pwr_ioretr_r> {return opsy::utility::clear_set<pwr_ioretr_r>(pwr_ioretr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IO retention enable for JTAG IOs 
 */
class jtagioreten_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr jtagioreten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_ioretr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_ioretr_r>() const {return opsy::utility::clear_set<pwr_ioretr_r>(mask, *this);}
	constexpr auto operator|(pwr_ioretr_r other) const -> pwr_ioretr_r { return static_cast<pwr_ioretr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_ioretr_r> other) const -> opsy::utility::clear_set<pwr_ioretr_r> {return opsy::utility::clear_set<pwr_ioretr_r>(pwr_ioretr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ioreten() const -> ioreten_f {return ioreten_f((value_ & ioreten_f::mask) != 0);}
	[[nodiscard]] constexpr auto jtagioreten() const -> jtagioreten_f {return jtagioreten_f((value_ & jtagioreten_f::mask) != 0);}

	constexpr pwr_ioretr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_ioretr_r other) const -> pwr_ioretr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_ioretr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR security configuration register
 */
class pwr_seccfgr_r {
public:

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup1sec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup2sec_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup2sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup3sec_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup3sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup4sec_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup4sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup5sec_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup5sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup6sec_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup6sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup7sec_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup7sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WUPx secure protection (x = 8 to 1)
 */
class wup8sec_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wup8sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * retention secure protection
 */
class retsec_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr retsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * low-power modes secure protection
 */
class lpmsec_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lpmsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * supply configuration and monitoring secure protection.
 */
class scmsec_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr scmsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup domain secure protection
 */
class vbsec_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vbsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * voltage USB secure protection
 */
class vusbsec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vusbsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_seccfgr_r>() const {return opsy::utility::clear_set<pwr_seccfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return static_cast<pwr_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_seccfgr_r> other) const -> opsy::utility::clear_set<pwr_seccfgr_r> {return opsy::utility::clear_set<pwr_seccfgr_r>(pwr_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto wup1sec() const -> wup1sec_f {return wup1sec_f((value_ & wup1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup2sec() const -> wup2sec_f {return wup2sec_f((value_ & wup2sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup3sec() const -> wup3sec_f {return wup3sec_f((value_ & wup3sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup4sec() const -> wup4sec_f {return wup4sec_f((value_ & wup4sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup5sec() const -> wup5sec_f {return wup5sec_f((value_ & wup5sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup6sec() const -> wup6sec_f {return wup6sec_f((value_ & wup6sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup7sec() const -> wup7sec_f {return wup7sec_f((value_ & wup7sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto wup8sec() const -> wup8sec_f {return wup8sec_f((value_ & wup8sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto retsec() const -> retsec_f {return retsec_f((value_ & retsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpmsec() const -> lpmsec_f {return lpmsec_f((value_ & lpmsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto scmsec() const -> scmsec_f {return scmsec_f((value_ & scmsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto vbsec() const -> vbsec_f {return vbsec_f((value_ & vbsec_f::mask) != 0);}
	[[nodiscard]] constexpr auto vusbsec() const -> vusbsec_f {return vusbsec_f((value_ & vusbsec_f::mask) != 0);}

	constexpr pwr_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_seccfgr_r other) const -> pwr_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * PWR privilege configuration register
 */
class pwr_privcfgr_r {
public:

/**
 * PWR secure functions privilege configuration 
 */
class spriv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_privcfgr_r>() const {return opsy::utility::clear_set<pwr_privcfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_privcfgr_r other) const -> pwr_privcfgr_r { return static_cast<pwr_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_privcfgr_r> other) const -> opsy::utility::clear_set<pwr_privcfgr_r> {return opsy::utility::clear_set<pwr_privcfgr_r>(pwr_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PWR non-secure functions privilege configuration 
 */
class nspriv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator pwr_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<pwr_privcfgr_r>() const {return opsy::utility::clear_set<pwr_privcfgr_r>(mask, *this);}
	constexpr auto operator|(pwr_privcfgr_r other) const -> pwr_privcfgr_r { return static_cast<pwr_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<pwr_privcfgr_r> other) const -> opsy::utility::clear_set<pwr_privcfgr_r> {return opsy::utility::clear_set<pwr_privcfgr_r>(pwr_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto spriv() const -> spriv_f {return spriv_f((value_ & spriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto nspriv() const -> nspriv_f {return nspriv_f((value_ & nspriv_f::mask) != 0);}

	constexpr pwr_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(pwr_privcfgr_r other) const -> pwr_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> pwr_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,pwr_pmcr_r> pwr_pmcr;
		opsy::utility::memory<uint32_t,pwr_pmcr_alternate1_r> pwr_pmcr_alternate1;
	};
	opsy::utility::read_only_memory<uint32_t,pwr_pmsr_r> pwr_pmsr;
	opsy::utility::padding<8> _p8;
	opsy::utility::memory<uint32_t,pwr_voscr_r> pwr_voscr;
	opsy::utility::read_only_memory<uint32_t,pwr_vossr_r> pwr_vossr;
	opsy::utility::padding<8> _p24;
	opsy::utility::memory<uint32_t,pwr_bdcr_r> pwr_bdcr;
	opsy::utility::memory<uint32_t,pwr_dbpcr_r> pwr_dbpcr;
	opsy::utility::read_only_memory<uint32_t,pwr_bdsr_r> pwr_bdsr;
	opsy::utility::memory<uint32_t,pwr_ucpdr_r> pwr_ucpdr;
	opsy::utility::memory<uint32_t,pwr_sccr_r> pwr_sccr;
	opsy::utility::memory<uint32_t,pwr_vmcr_r> pwr_vmcr;
	opsy::utility::memory<uint32_t,pwr_usbscr_r> pwr_usbscr;
	opsy::utility::read_only_memory<uint32_t,pwr_vmsr_r> pwr_vmsr;
	opsy::utility::write_only_memory<uint32_t,pwr_wuscr_r> pwr_wuscr;
	opsy::utility::read_only_memory<uint32_t,pwr_wusr_r> pwr_wusr;
	opsy::utility::memory<uint32_t,pwr_wucr_r> pwr_wucr;
	opsy::utility::padding<4> _p76;
	opsy::utility::memory<uint32_t,pwr_ioretr_r> pwr_ioretr;
	opsy::utility::padding<172> _p84;
	opsy::utility::memory<uint32_t,pwr_seccfgr_r> pwr_seccfgr;
	opsy::utility::memory<uint32_t,pwr_privcfgr_r> pwr_privcfgr;
};

static_assert(std::is_standard_layout_v<pwr_p>);
static_assert(offsetof(pwr_p, pwr_pmcr) == 0);
static_assert(offsetof(pwr_p, pwr_pmcr_alternate1) == 0);
static_assert(offsetof(pwr_p, pwr_pmsr) == 4);
static_assert(offsetof(pwr_p, pwr_voscr) == 16);
static_assert(offsetof(pwr_p, pwr_vossr) == 20);
static_assert(offsetof(pwr_p, pwr_bdcr) == 32);
static_assert(offsetof(pwr_p, pwr_dbpcr) == 36);
static_assert(offsetof(pwr_p, pwr_bdsr) == 40);
static_assert(offsetof(pwr_p, pwr_ucpdr) == 44);
static_assert(offsetof(pwr_p, pwr_sccr) == 48);
static_assert(offsetof(pwr_p, pwr_vmcr) == 52);
static_assert(offsetof(pwr_p, pwr_usbscr) == 56);
static_assert(offsetof(pwr_p, pwr_vmsr) == 60);
static_assert(offsetof(pwr_p, pwr_wuscr) == 64);
static_assert(offsetof(pwr_p, pwr_wusr) == 68);
static_assert(offsetof(pwr_p, pwr_wucr) == 72);
static_assert(offsetof(pwr_p, pwr_ioretr) == 80);
static_assert(offsetof(pwr_p, pwr_seccfgr) == 256);
static_assert(offsetof(pwr_p, pwr_privcfgr) == 260);

inline pwr_p& pwr = *reinterpret_cast<pwr_p*>(0x44020800);
inline pwr_p& pwr_s = *reinterpret_cast<pwr_p*>(0x54020800);

} // STM32H523

