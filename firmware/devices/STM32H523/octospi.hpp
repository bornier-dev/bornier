#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * OCTOSPI register block
 */
class octospi_p {
public:

/**
 * OCTOSPI control register
 */
class octospi_cr_r {
public:

/**
 * Enable 
 */
class en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Abort request 
 */
class abort_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr abort_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable 
 */
class dmaen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout counter enable 
 */
class tcen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Dual-memory configuration 
 */
class dmm_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External memory select 
 */
class msel_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr msel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold level 
 */
class fthres_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fthres_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transfer error interrupt enable 
 */
class teie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold interrupt enable 
 */
class ftie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status-match interrupt enable 
 */
class smie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout interrupt enable 
 */
class toie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr toie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic status-polling mode stop 
 */
class apms_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr apms_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Polling match mode 
 */
class pmm_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pmm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Functional mode 
 */
class fmode_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto abort() const -> abort_f {return abort_f((value_ & abort_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaen() const -> dmaen_f {return dmaen_f((value_ & dmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcen() const -> tcen_f {return tcen_f((value_ & tcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmm() const -> dmm_f {return dmm_f((value_ & dmm_f::mask) != 0);}
	[[nodiscard]] constexpr auto msel() const -> msel_f {return msel_f((value_ & msel_f::mask) != 0);}
	[[nodiscard]] constexpr auto fthres() const -> fthres_f {return fthres_f(static_cast<uint8_t>(value_ >> fthres_f::offset));}
	[[nodiscard]] constexpr auto teie() const -> teie_f {return teie_f((value_ & teie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ftie() const -> ftie_f {return ftie_f((value_ & ftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto smie() const -> smie_f {return smie_f((value_ & smie_f::mask) != 0);}
	[[nodiscard]] constexpr auto toie() const -> toie_f {return toie_f((value_ & toie_f::mask) != 0);}
	[[nodiscard]] constexpr auto apms() const -> apms_f {return apms_f((value_ & apms_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmm() const -> pmm_f {return pmm_f((value_ & pmm_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmode() const -> fmode_f {return fmode_f(static_cast<uint8_t>(value_ >> fmode_f::offset));}

	constexpr octospi_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_cr_r other) const -> octospi_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 1
 */
class octospi_dcr1_r {
public:

/**
 * Clock mode 0/mode 3 
 */
class ckmode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ckmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Free running clock 
 */
class frck_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Delay block bypass
 */
class dlybyp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dlybyp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Chip-select high time 
 */
class csht_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr csht_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Device size 
 */
class devsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr devsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Memory type 
 */
class mtyp_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mtyp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ckmode() const -> ckmode_f {return ckmode_f((value_ & ckmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto frck() const -> frck_f {return frck_f((value_ & frck_f::mask) != 0);}
	[[nodiscard]] constexpr auto dlybyp() const -> dlybyp_f {return dlybyp_f((value_ & dlybyp_f::mask) != 0);}
	[[nodiscard]] constexpr auto csht() const -> csht_f {return csht_f(static_cast<uint8_t>(value_ >> csht_f::offset));}
	[[nodiscard]] constexpr auto devsize() const -> devsize_f {return devsize_f(static_cast<uint8_t>(value_ >> devsize_f::offset));}
	[[nodiscard]] constexpr auto mtyp() const -> mtyp_f {return mtyp_f(static_cast<uint8_t>(value_ >> mtyp_f::offset));}

	constexpr octospi_dcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr1_r other) const -> octospi_dcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 2
 */
class octospi_dcr2_r {
public:

/**
 * Clock prescaler 
 */
class prescaler_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prescaler_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr2_r>() const {return opsy::utility::clear_set<octospi_dcr2_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr2_r other) const -> octospi_dcr2_r { return static_cast<octospi_dcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr2_r> other) const -> opsy::utility::clear_set<octospi_dcr2_r> {return opsy::utility::clear_set<octospi_dcr2_r>(octospi_dcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Wrap size 
 */
class wrapsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrapsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr2_r>() const {return opsy::utility::clear_set<octospi_dcr2_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr2_r other) const -> octospi_dcr2_r { return static_cast<octospi_dcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr2_r> other) const -> opsy::utility::clear_set<octospi_dcr2_r> {return opsy::utility::clear_set<octospi_dcr2_r>(octospi_dcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prescaler() const -> prescaler_f {return prescaler_f(static_cast<uint8_t>(value_ >> prescaler_f::offset));}
	[[nodiscard]] constexpr auto wrapsize() const -> wrapsize_f {return wrapsize_f(static_cast<uint8_t>(value_ >> wrapsize_f::offset));}

	constexpr octospi_dcr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr2_r other) const -> octospi_dcr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 3
 */
class octospi_dcr3_r {
public:

/**
 * NCS boundary 
 */
class csbound_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr csbound_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr3_r>() const {return opsy::utility::clear_set<octospi_dcr3_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr3_r other) const -> octospi_dcr3_r { return static_cast<octospi_dcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr3_r> other) const -> opsy::utility::clear_set<octospi_dcr3_r> {return opsy::utility::clear_set<octospi_dcr3_r>(octospi_dcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto csbound() const -> csbound_f {return csbound_f(static_cast<uint8_t>(value_ >> csbound_f::offset));}

	constexpr octospi_dcr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr3_r other) const -> octospi_dcr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 4
 */
class octospi_dcr4_r {
public:

/**
 * Refresh rate 
 */
class refresh_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr refresh_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dcr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr4_r>() const {return opsy::utility::clear_set<octospi_dcr4_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr4_r other) const -> octospi_dcr4_r { return static_cast<octospi_dcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr4_r> other) const -> opsy::utility::clear_set<octospi_dcr4_r> {return opsy::utility::clear_set<octospi_dcr4_r>(octospi_dcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto refresh() const -> refresh_f {return refresh_f(static_cast<uint32_t>(value_ >> refresh_f::offset));}

	constexpr octospi_dcr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr4_r other) const -> octospi_dcr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI status register
 */
class octospi_sr_r {
public:

/**
 * Transfer error flag 
 */
class tef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete flag 
 */
class tcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold flag 
 */
class ftf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ftf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status match flag 
 */
class smf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr smf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout flag 
 */
class tof_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO level 
 */
class flevel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr flevel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tef() const -> tef_f {return tef_f((value_ & tef_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcf() const -> tcf_f {return tcf_f((value_ & tcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ftf() const -> ftf_f {return ftf_f((value_ & ftf_f::mask) != 0);}
	[[nodiscard]] constexpr auto smf() const -> smf_f {return smf_f((value_ & smf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tof() const -> tof_f {return tof_f((value_ & tof_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto flevel() const -> flevel_f {return flevel_f(static_cast<uint8_t>(value_ >> flevel_f::offset));}

	constexpr octospi_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_sr_r other) const -> octospi_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI flag clear register
 */
class octospi_fcr_r {
public:

/**
 * Clear transfer error flag 
 */
class ctef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear transfer complete flag 
 */
class ctcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear status match flag 
 */
class csmf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear timeout flag 
 */
class ctof_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ctef() const -> ctef_f {return ctef_f((value_ & ctef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctcf() const -> ctcf_f {return ctcf_f((value_ & ctcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csmf() const -> csmf_f {return csmf_f((value_ & csmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctof() const -> ctof_f {return ctof_f((value_ & ctof_f::mask) != 0);}

	constexpr octospi_fcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_fcr_r other) const -> octospi_fcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_fcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI data length register
 */
class octospi_dlr_r {
public:

/**
 * Data length 
 */
class dl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dl_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dlr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dlr_r>() const {return opsy::utility::clear_set<octospi_dlr_r>(mask, *this);}
	constexpr auto operator|(octospi_dlr_r other) const -> octospi_dlr_r { return static_cast<octospi_dlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dlr_r> other) const -> opsy::utility::clear_set<octospi_dlr_r> {return opsy::utility::clear_set<octospi_dlr_r>(octospi_dlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto dl() const -> dl_f {return dl_f(static_cast<uint32_t>(value_ >> dl_f::offset));}

	constexpr octospi_dlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dlr_r other) const -> octospi_dlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI address register
 */
class octospi_ar_r {
public:

/**
 * Address 
 */
class address_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr address_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_ar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ar_r>() const {return opsy::utility::clear_set<octospi_ar_r>(mask, *this);}
	constexpr auto operator|(octospi_ar_r other) const -> octospi_ar_r { return static_cast<octospi_ar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ar_r> other) const -> opsy::utility::clear_set<octospi_ar_r> {return opsy::utility::clear_set<octospi_ar_r>(octospi_ar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto address() const -> address_f {return address_f(static_cast<uint32_t>(value_ >> address_f::offset));}

	constexpr octospi_ar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ar_r other) const -> octospi_ar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI data register
 */
class octospi_dr_r {
public:

/**
 * Data 
 */
class data_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr data_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dr_r>() const {return opsy::utility::clear_set<octospi_dr_r>(mask, *this);}
	constexpr auto operator|(octospi_dr_r other) const -> octospi_dr_r { return static_cast<octospi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dr_r> other) const -> opsy::utility::clear_set<octospi_dr_r> {return opsy::utility::clear_set<octospi_dr_r>(octospi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto data() const -> data_f {return data_f(static_cast<uint32_t>(value_ >> data_f::offset));}

	constexpr octospi_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dr_r other) const -> octospi_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling status mask register
 */
class octospi_psmkr_r {
public:

/**
 * Status mask 
 */
class mask_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mask_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_psmkr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_psmkr_r>() const {return opsy::utility::clear_set<octospi_psmkr_r>(mask, *this);}
	constexpr auto operator|(octospi_psmkr_r other) const -> octospi_psmkr_r { return static_cast<octospi_psmkr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_psmkr_r> other) const -> opsy::utility::clear_set<octospi_psmkr_r> {return opsy::utility::clear_set<octospi_psmkr_r>(octospi_psmkr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto mask() const -> mask_f {return mask_f(static_cast<uint32_t>(value_ >> mask_f::offset));}

	constexpr octospi_psmkr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_psmkr_r other) const -> octospi_psmkr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_psmkr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling status match register
 */
class octospi_psmar_r {
public:

/**
 * Status match 
 */
class match_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr match_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_psmar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_psmar_r>() const {return opsy::utility::clear_set<octospi_psmar_r>(mask, *this);}
	constexpr auto operator|(octospi_psmar_r other) const -> octospi_psmar_r { return static_cast<octospi_psmar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_psmar_r> other) const -> opsy::utility::clear_set<octospi_psmar_r> {return opsy::utility::clear_set<octospi_psmar_r>(octospi_psmar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto match() const -> match_f {return match_f(static_cast<uint32_t>(value_ >> match_f::offset));}

	constexpr octospi_psmar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_psmar_r other) const -> octospi_psmar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_psmar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling interval register
 */
class octospi_pir_r {
public:

/**
 * Polling interval 
 */
class interval_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr interval_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator octospi_pir_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_pir_r>() const {return opsy::utility::clear_set<octospi_pir_r>(mask, *this);}
	constexpr auto operator|(octospi_pir_r other) const -> octospi_pir_r { return static_cast<octospi_pir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_pir_r> other) const -> opsy::utility::clear_set<octospi_pir_r> {return opsy::utility::clear_set<octospi_pir_r>(octospi_pir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto interval() const -> interval_f {return interval_f(static_cast<uint16_t>(value_ >> interval_f::offset));}

	constexpr octospi_pir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_pir_r other) const -> octospi_pir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_pir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI communication configuration register
 */
class octospi_ccr_r {
public:

/**
 * Instruction mode 
 */
class imode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr imode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Instruction double transfer rate 
 */
class idtr_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Instruction size 
 */
class isize_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr isize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address mode 
 */
class admode_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr admode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address double transfer rate 
 */
class addtr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr addtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address size 
 */
class adsize_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr adsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate-byte mode 
 */
class abmode_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr abmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate- byte double transfer rate 
 */
class abdtr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abdtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alternate-byte size 
 */
class absize_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr absize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data mode 
 */
class dmode_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data double transfer rate 
 */
class ddtr_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DQS enable 
 */
class dqse_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dqse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto imode() const -> imode_f {return imode_f(static_cast<uint8_t>(value_ >> imode_f::offset));}
	[[nodiscard]] constexpr auto idtr() const -> idtr_f {return idtr_f((value_ & idtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto isize() const -> isize_f {return isize_f(static_cast<uint8_t>(value_ >> isize_f::offset));}
	[[nodiscard]] constexpr auto admode() const -> admode_f {return admode_f(static_cast<uint8_t>(value_ >> admode_f::offset));}
	[[nodiscard]] constexpr auto addtr() const -> addtr_f {return addtr_f((value_ & addtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto adsize() const -> adsize_f {return adsize_f(static_cast<uint8_t>(value_ >> adsize_f::offset));}
	[[nodiscard]] constexpr auto abmode() const -> abmode_f {return abmode_f(static_cast<uint8_t>(value_ >> abmode_f::offset));}
	[[nodiscard]] constexpr auto abdtr() const -> abdtr_f {return abdtr_f((value_ & abdtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto absize() const -> absize_f {return absize_f(static_cast<uint8_t>(value_ >> absize_f::offset));}
	[[nodiscard]] constexpr auto dmode() const -> dmode_f {return dmode_f(static_cast<uint8_t>(value_ >> dmode_f::offset));}
	[[nodiscard]] constexpr auto ddtr() const -> ddtr_f {return ddtr_f((value_ & ddtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto dqse() const -> dqse_f {return dqse_f((value_ & dqse_f::mask) != 0);}

	constexpr octospi_ccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ccr_r other) const -> octospi_ccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI timing configuration register
 */
class octospi_tcr_r {
public:

/**
 * Number of dummy cycles 
 */
class dcyc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dcyc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_tcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay hold quarter cycle
 */
class dhqc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dhqc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_tcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Sample shift 
 */
class sshift_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sshift_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_tcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dcyc() const -> dcyc_f {return dcyc_f(static_cast<uint8_t>(value_ >> dcyc_f::offset));}
	[[nodiscard]] constexpr auto dhqc() const -> dhqc_f {return dhqc_f((value_ & dhqc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sshift() const -> sshift_f {return sshift_f((value_ & sshift_f::mask) != 0);}

	constexpr octospi_tcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_tcr_r other) const -> octospi_tcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_tcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI instruction register
 */
class octospi_ir_r {
public:

/**
 * Instruction 
 */
class instruction_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr instruction_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_ir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ir_r>() const {return opsy::utility::clear_set<octospi_ir_r>(mask, *this);}
	constexpr auto operator|(octospi_ir_r other) const -> octospi_ir_r { return static_cast<octospi_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ir_r> other) const -> opsy::utility::clear_set<octospi_ir_r> {return opsy::utility::clear_set<octospi_ir_r>(octospi_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto instruction() const -> instruction_f {return instruction_f(static_cast<uint32_t>(value_ >> instruction_f::offset));}

	constexpr octospi_ir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ir_r other) const -> octospi_ir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI alternate bytes register
 */
class octospi_abr_r {
public:

/**
 * Alternate bytes 
 */
class alternate_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr alternate_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_abr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_abr_r>() const {return opsy::utility::clear_set<octospi_abr_r>(mask, *this);}
	constexpr auto operator|(octospi_abr_r other) const -> octospi_abr_r { return static_cast<octospi_abr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_abr_r> other) const -> opsy::utility::clear_set<octospi_abr_r> {return opsy::utility::clear_set<octospi_abr_r>(octospi_abr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto alternate() const -> alternate_f {return alternate_f(static_cast<uint32_t>(value_ >> alternate_f::offset));}

	constexpr octospi_abr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_abr_r other) const -> octospi_abr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_abr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI low-power timeout register
 */
class octospi_lptr_r {
public:

/**
 * Timeout period 
 */
class timeout_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr timeout_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator octospi_lptr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_lptr_r>() const {return opsy::utility::clear_set<octospi_lptr_r>(mask, *this);}
	constexpr auto operator|(octospi_lptr_r other) const -> octospi_lptr_r { return static_cast<octospi_lptr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_lptr_r> other) const -> opsy::utility::clear_set<octospi_lptr_r> {return opsy::utility::clear_set<octospi_lptr_r>(octospi_lptr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto timeout() const -> timeout_f {return timeout_f(static_cast<uint16_t>(value_ >> timeout_f::offset));}

	constexpr octospi_lptr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_lptr_r other) const -> octospi_lptr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_lptr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI write timing configuration register
 */
class octospi_wtcr_r {
public:

/**
 * Number of dummy cycles 
 */
class dcyc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dcyc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wtcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wtcr_r>() const {return opsy::utility::clear_set<octospi_wtcr_r>(mask, *this);}
	constexpr auto operator|(octospi_wtcr_r other) const -> octospi_wtcr_r { return static_cast<octospi_wtcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wtcr_r> other) const -> opsy::utility::clear_set<octospi_wtcr_r> {return opsy::utility::clear_set<octospi_wtcr_r>(octospi_wtcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dcyc() const -> dcyc_f {return dcyc_f(static_cast<uint8_t>(value_ >> dcyc_f::offset));}

	constexpr octospi_wtcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_wtcr_r other) const -> octospi_wtcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_wtcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI HyperBus latency configuration register
 */
class octospi_hlcr_r {
public:

/**
 * Latency mode 
 */
class lm_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write zero latency 
 */
class wzl_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wzl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Access time 
 */
class tacc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tacc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Read-write minimum recovery time 
 */
class trwr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trwr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lm() const -> lm_f {return lm_f((value_ & lm_f::mask) != 0);}
	[[nodiscard]] constexpr auto wzl() const -> wzl_f {return wzl_f((value_ & wzl_f::mask) != 0);}
	[[nodiscard]] constexpr auto tacc() const -> tacc_f {return tacc_f(static_cast<uint8_t>(value_ >> tacc_f::offset));}
	[[nodiscard]] constexpr auto trwr() const -> trwr_f {return trwr_f(static_cast<uint8_t>(value_ >> trwr_f::offset));}

	constexpr octospi_hlcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_hlcr_r other) const -> octospi_hlcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_hlcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,octospi_cr_r> octospi_cr;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,octospi_dcr1_r> octospi_dcr1;
	opsy::utility::memory<uint32_t,octospi_dcr2_r> octospi_dcr2;
	opsy::utility::memory<uint32_t,octospi_dcr3_r> octospi_dcr3;
	opsy::utility::memory<uint32_t,octospi_dcr4_r> octospi_dcr4;
	opsy::utility::padding<8> _p24;
	opsy::utility::read_only_memory<uint32_t,octospi_sr_r> octospi_sr;
	opsy::utility::write_only_memory<uint32_t,octospi_fcr_r> octospi_fcr;
	opsy::utility::padding<24> _p40;
	opsy::utility::memory<uint32_t,octospi_dlr_r> octospi_dlr;
	opsy::utility::padding<4> _p68;
	opsy::utility::memory<uint32_t,octospi_ar_r> octospi_ar;
	opsy::utility::padding<4> _p76;
	opsy::utility::memory<uint32_t,octospi_dr_r> octospi_dr;
	opsy::utility::padding<44> _p84;
	opsy::utility::memory<uint32_t,octospi_psmkr_r> octospi_psmkr;
	opsy::utility::padding<4> _p132;
	opsy::utility::memory<uint32_t,octospi_psmar_r> octospi_psmar;
	opsy::utility::padding<4> _p140;
	opsy::utility::memory<uint32_t,octospi_pir_r> octospi_pir;
	opsy::utility::padding<108> _p148;
	opsy::utility::memory<uint32_t,octospi_ccr_r> octospi_ccr;
	opsy::utility::padding<4> _p260;
	opsy::utility::memory<uint32_t,octospi_tcr_r> octospi_tcr;
	opsy::utility::padding<4> _p268;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_ir;
	opsy::utility::padding<12> _p276;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_abr;
	opsy::utility::padding<12> _p292;
	opsy::utility::memory<uint32_t,octospi_lptr_r> octospi_lptr;
	opsy::utility::padding<12> _p308;
	opsy::utility::memory<uint32_t,octospi_ccr_r> octospi_wpccr;
	opsy::utility::padding<4> _p324;
	opsy::utility::memory<uint32_t,octospi_tcr_r> octospi_wptcr;
	opsy::utility::padding<4> _p332;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_wpir;
	opsy::utility::padding<12> _p340;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_wpabr;
	opsy::utility::padding<28> _p356;
	opsy::utility::memory<uint32_t,octospi_ccr_r> octospi_wccr;
	opsy::utility::padding<4> _p388;
	opsy::utility::memory<uint32_t,octospi_wtcr_r> octospi_wtcr;
	opsy::utility::padding<4> _p396;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_wir;
	opsy::utility::padding<12> _p404;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_wabr;
	opsy::utility::padding<92> _p420;
	opsy::utility::memory<uint32_t,octospi_hlcr_r> octospi_hlcr;
};

static_assert(std::is_standard_layout_v<octospi_p>);
static_assert(offsetof(octospi_p, octospi_cr) == 0);
static_assert(offsetof(octospi_p, octospi_dcr1) == 8);
static_assert(offsetof(octospi_p, octospi_dcr2) == 12);
static_assert(offsetof(octospi_p, octospi_dcr3) == 16);
static_assert(offsetof(octospi_p, octospi_dcr4) == 20);
static_assert(offsetof(octospi_p, octospi_sr) == 32);
static_assert(offsetof(octospi_p, octospi_fcr) == 36);
static_assert(offsetof(octospi_p, octospi_dlr) == 64);
static_assert(offsetof(octospi_p, octospi_ar) == 72);
static_assert(offsetof(octospi_p, octospi_dr) == 80);
static_assert(offsetof(octospi_p, octospi_psmkr) == 128);
static_assert(offsetof(octospi_p, octospi_psmar) == 136);
static_assert(offsetof(octospi_p, octospi_pir) == 144);
static_assert(offsetof(octospi_p, octospi_ccr) == 256);
static_assert(offsetof(octospi_p, octospi_tcr) == 264);
static_assert(offsetof(octospi_p, octospi_ir) == 272);
static_assert(offsetof(octospi_p, octospi_abr) == 288);
static_assert(offsetof(octospi_p, octospi_lptr) == 304);
static_assert(offsetof(octospi_p, octospi_wpccr) == 320);
static_assert(offsetof(octospi_p, octospi_wptcr) == 328);
static_assert(offsetof(octospi_p, octospi_wpir) == 336);
static_assert(offsetof(octospi_p, octospi_wpabr) == 352);
static_assert(offsetof(octospi_p, octospi_wccr) == 384);
static_assert(offsetof(octospi_p, octospi_wtcr) == 392);
static_assert(offsetof(octospi_p, octospi_wir) == 400);
static_assert(offsetof(octospi_p, octospi_wabr) == 416);
static_assert(offsetof(octospi_p, octospi_hlcr) == 512);

inline octospi_p& octospi = *reinterpret_cast<octospi_p*>(0x47001400);
inline octospi_p& octospi_s = *reinterpret_cast<octospi_p*>(0x57001400);

} // STM32H523

