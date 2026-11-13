#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * RAMCFG address block description
 */
class ramcfg_p {
public:

/**
 * RAMCFG memory X control register
 */
class ramcfg_mxcr_r {
public:

/**
 * ECC enable.
 */
class ecce_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ecce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxcr_r>() const {return opsy::utility::clear_set<ramcfg_mxcr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxcr_r other) const -> ramcfg_mxcr_r { return static_cast<ramcfg_mxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxcr_r> other) const -> opsy::utility::clear_set<ramcfg_mxcr_r> {return opsy::utility::clear_set<ramcfg_mxcr_r>(ramcfg_mxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address latch enable 
 */
class ale_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ale_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxcr_r>() const {return opsy::utility::clear_set<ramcfg_mxcr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxcr_r other) const -> ramcfg_mxcr_r { return static_cast<ramcfg_mxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxcr_r> other) const -> opsy::utility::clear_set<ramcfg_mxcr_r> {return opsy::utility::clear_set<ramcfg_mxcr_r>(ramcfg_mxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM erase 
 */
class sramer_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sramer_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxcr_r>() const {return opsy::utility::clear_set<ramcfg_mxcr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxcr_r other) const -> ramcfg_mxcr_r { return static_cast<ramcfg_mxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxcr_r> other) const -> opsy::utility::clear_set<ramcfg_mxcr_r> {return opsy::utility::clear_set<ramcfg_mxcr_r>(ramcfg_mxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ecce() const -> ecce_f {return ecce_f((value_ & ecce_f::mask) != 0);}
	[[nodiscard]] constexpr auto ale() const -> ale_f {return ale_f((value_ & ale_f::mask) != 0);}
	[[nodiscard]] constexpr auto sramer() const -> sramer_f {return sramer_f((value_ & sramer_f::mask) != 0);}

	constexpr ramcfg_mxcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxcr_r other) const -> ramcfg_mxcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory interrupt status register
 */
class ramcfg_mxisr_r {
public:

/**
 * ECC single error detected and corrected 
 */
class sedc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sedc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxisr_r>() const {return opsy::utility::clear_set<ramcfg_mxisr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxisr_r other) const -> ramcfg_mxisr_r { return static_cast<ramcfg_mxisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxisr_r> other) const -> opsy::utility::clear_set<ramcfg_mxisr_r> {return opsy::utility::clear_set<ramcfg_mxisr_r>(ramcfg_mxisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC double error detected 
 */
class ded_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ded_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxisr_r>() const {return opsy::utility::clear_set<ramcfg_mxisr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxisr_r other) const -> ramcfg_mxisr_r { return static_cast<ramcfg_mxisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxisr_r> other) const -> opsy::utility::clear_set<ramcfg_mxisr_r> {return opsy::utility::clear_set<ramcfg_mxisr_r>(ramcfg_mxisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM busy with erase operation 
 */
class srambusy_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr srambusy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxisr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxisr_r>() const {return opsy::utility::clear_set<ramcfg_mxisr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxisr_r other) const -> ramcfg_mxisr_r { return static_cast<ramcfg_mxisr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxisr_r> other) const -> opsy::utility::clear_set<ramcfg_mxisr_r> {return opsy::utility::clear_set<ramcfg_mxisr_r>(ramcfg_mxisr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sedc() const -> sedc_f {return sedc_f((value_ & sedc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ded() const -> ded_f {return ded_f((value_ & ded_f::mask) != 0);}
	[[nodiscard]] constexpr auto srambusy() const -> srambusy_f {return srambusy_f((value_ & srambusy_f::mask) != 0);}

	constexpr ramcfg_mxisr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxisr_r other) const -> ramcfg_mxisr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxisr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory X erase key register
 */
class ramcfg_mxerkeyr_r {
public:

/**
 * Erase write protection key 
 */
class erasekey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr erasekey_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ramcfg_mxerkeyr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ramcfg_mxerkeyr_r>() const {return opsy::utility::clear_set<ramcfg_mxerkeyr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxerkeyr_r other) const -> ramcfg_mxerkeyr_r { return static_cast<ramcfg_mxerkeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxerkeyr_r> other) const -> opsy::utility::clear_set<ramcfg_mxerkeyr_r> {return opsy::utility::clear_set<ramcfg_mxerkeyr_r>(ramcfg_mxerkeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto erasekey() const -> erasekey_f {return erasekey_f(static_cast<uint8_t>(value_ >> erasekey_f::offset));}

	constexpr ramcfg_mxerkeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxerkeyr_r other) const -> ramcfg_mxerkeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxerkeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory X interrupt enable register
 */
class ramcfg_mxier_r {
public:

/**
 * ECC single error interrupt enable
 */
class seie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr seie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxier_r>() const {return opsy::utility::clear_set<ramcfg_mxier_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxier_r other) const -> ramcfg_mxier_r { return static_cast<ramcfg_mxier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxier_r> other) const -> opsy::utility::clear_set<ramcfg_mxier_r> {return opsy::utility::clear_set<ramcfg_mxier_r>(ramcfg_mxier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC double error interrupt enable
 */
class deie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr deie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxier_r>() const {return opsy::utility::clear_set<ramcfg_mxier_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxier_r other) const -> ramcfg_mxier_r { return static_cast<ramcfg_mxier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxier_r> other) const -> opsy::utility::clear_set<ramcfg_mxier_r> {return opsy::utility::clear_set<ramcfg_mxier_r>(ramcfg_mxier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Double error NMI 
 */
class eccnmi_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eccnmi_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxier_r>() const {return opsy::utility::clear_set<ramcfg_mxier_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxier_r other) const -> ramcfg_mxier_r { return static_cast<ramcfg_mxier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxier_r> other) const -> opsy::utility::clear_set<ramcfg_mxier_r> {return opsy::utility::clear_set<ramcfg_mxier_r>(ramcfg_mxier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto seie() const -> seie_f {return seie_f((value_ & seie_f::mask) != 0);}
	[[nodiscard]] constexpr auto deie() const -> deie_f {return deie_f((value_ & deie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eccnmi() const -> eccnmi_f {return eccnmi_f((value_ & eccnmi_f::mask) != 0);}

	constexpr ramcfg_mxier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxier_r other) const -> ramcfg_mxier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory X ECC single error address register
 */
class ramcfg_mxsear_r {
public:

/**
 * ECC single error address 
 */
class esea_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr esea_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator ramcfg_mxsear_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ramcfg_mxsear_r>() const {return opsy::utility::clear_set<ramcfg_mxsear_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxsear_r other) const -> ramcfg_mxsear_r { return static_cast<ramcfg_mxsear_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxsear_r> other) const -> opsy::utility::clear_set<ramcfg_mxsear_r> {return opsy::utility::clear_set<ramcfg_mxsear_r>(ramcfg_mxsear_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto esea() const -> esea_f {return esea_f(static_cast<uint32_t>(value_ >> esea_f::offset));}

	constexpr ramcfg_mxsear_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxsear_r other) const -> ramcfg_mxsear_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxsear_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory X ECC double error address register
 */
class ramcfg_mxdear_r {
public:

/**
 * ECC double error address 
 */
class edea_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr edea_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator ramcfg_mxdear_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ramcfg_mxdear_r>() const {return opsy::utility::clear_set<ramcfg_mxdear_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxdear_r other) const -> ramcfg_mxdear_r { return static_cast<ramcfg_mxdear_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxdear_r> other) const -> opsy::utility::clear_set<ramcfg_mxdear_r> {return opsy::utility::clear_set<ramcfg_mxdear_r>(ramcfg_mxdear_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto edea() const -> edea_f {return edea_f(static_cast<uint32_t>(value_ >> edea_f::offset));}

	constexpr ramcfg_mxdear_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxdear_r other) const -> ramcfg_mxdear_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxdear_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory 2 interrupt clear register 2
 */
class ramcfg_mxicr_r {
public:

/**
 * Clear ECC single error detected and corrected 
 */
class csedc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csedc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxicr_r>() const {return opsy::utility::clear_set<ramcfg_mxicr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxicr_r other) const -> ramcfg_mxicr_r { return static_cast<ramcfg_mxicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxicr_r> other) const -> opsy::utility::clear_set<ramcfg_mxicr_r> {return opsy::utility::clear_set<ramcfg_mxicr_r>(ramcfg_mxicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ECC double error detected 
 */
class cded_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cded_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_mxicr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_mxicr_r>() const {return opsy::utility::clear_set<ramcfg_mxicr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxicr_r other) const -> ramcfg_mxicr_r { return static_cast<ramcfg_mxicr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxicr_r> other) const -> opsy::utility::clear_set<ramcfg_mxicr_r> {return opsy::utility::clear_set<ramcfg_mxicr_r>(ramcfg_mxicr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto csedc() const -> csedc_f {return csedc_f((value_ & csedc_f::mask) != 0);}
	[[nodiscard]] constexpr auto cded() const -> cded_f {return cded_f((value_ & cded_f::mask) != 0);}

	constexpr ramcfg_mxicr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxicr_r other) const -> ramcfg_mxicr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxicr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory 2 write protection register 1
 */
class ramcfg_m2wpr1_r {
public:

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p0wp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p0wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p1wp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p1wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p2wp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p2wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p3wp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p3wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p4wp_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p4wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p5wp_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p5wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p6wp_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p6wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p7wp_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p7wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p8wp_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p8wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p9wp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p9wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p10wp_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p10wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p11wp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p11wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p12wp_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p12wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p13wp_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p13wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p14wp_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p14wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p15wp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p15wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p16wp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p16wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p17wp_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p17wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p18wp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p18wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p19wp_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p19wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p20wp_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p20wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p21wp_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p21wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p22wp_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p22wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p23wp_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p23wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p24wp_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p24wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p25wp_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p25wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p26wp_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p26wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p27wp_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p27wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p28wp_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p28wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p29wp_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p29wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p30wp_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p30wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p31wp_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p31wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr1_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return static_cast<ramcfg_m2wpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr1_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr1_r> {return opsy::utility::clear_set<ramcfg_m2wpr1_r>(ramcfg_m2wpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto p0wp() const -> p0wp_f {return p0wp_f((value_ & p0wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p1wp() const -> p1wp_f {return p1wp_f((value_ & p1wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p2wp() const -> p2wp_f {return p2wp_f((value_ & p2wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p3wp() const -> p3wp_f {return p3wp_f((value_ & p3wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p4wp() const -> p4wp_f {return p4wp_f((value_ & p4wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p5wp() const -> p5wp_f {return p5wp_f((value_ & p5wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p6wp() const -> p6wp_f {return p6wp_f((value_ & p6wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p7wp() const -> p7wp_f {return p7wp_f((value_ & p7wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p8wp() const -> p8wp_f {return p8wp_f((value_ & p8wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p9wp() const -> p9wp_f {return p9wp_f((value_ & p9wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p10wp() const -> p10wp_f {return p10wp_f((value_ & p10wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p11wp() const -> p11wp_f {return p11wp_f((value_ & p11wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p12wp() const -> p12wp_f {return p12wp_f((value_ & p12wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p13wp() const -> p13wp_f {return p13wp_f((value_ & p13wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p14wp() const -> p14wp_f {return p14wp_f((value_ & p14wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p15wp() const -> p15wp_f {return p15wp_f((value_ & p15wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p16wp() const -> p16wp_f {return p16wp_f((value_ & p16wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p17wp() const -> p17wp_f {return p17wp_f((value_ & p17wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p18wp() const -> p18wp_f {return p18wp_f((value_ & p18wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p19wp() const -> p19wp_f {return p19wp_f((value_ & p19wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p20wp() const -> p20wp_f {return p20wp_f((value_ & p20wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p21wp() const -> p21wp_f {return p21wp_f((value_ & p21wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p22wp() const -> p22wp_f {return p22wp_f((value_ & p22wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p23wp() const -> p23wp_f {return p23wp_f((value_ & p23wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p24wp() const -> p24wp_f {return p24wp_f((value_ & p24wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p25wp() const -> p25wp_f {return p25wp_f((value_ & p25wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p26wp() const -> p26wp_f {return p26wp_f((value_ & p26wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p27wp() const -> p27wp_f {return p27wp_f((value_ & p27wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p28wp() const -> p28wp_f {return p28wp_f((value_ & p28wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p29wp() const -> p29wp_f {return p29wp_f((value_ & p29wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p30wp() const -> p30wp_f {return p30wp_f((value_ & p30wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p31wp() const -> p31wp_f {return p31wp_f((value_ & p31wp_f::mask) != 0);}

	constexpr ramcfg_m2wpr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_m2wpr1_r other) const -> ramcfg_m2wpr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_m2wpr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory 2 write protection register 2
 */
class ramcfg_m2wpr2_r {
public:

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p32wp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p32wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p33wp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p33wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p34wp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p34wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p35wp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p35wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p36wp_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p36wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p37wp_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p37wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p38wp_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p38wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p39wp_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p39wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p40wp_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p40wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p41wp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p41wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p42wp_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p42wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p43wp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p43wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p44wp_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p44wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p45wp_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p45wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p46wp_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p46wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p47wp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p47wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p48wp_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p48wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p49wp_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p49wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p50wp_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p50wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p51wp_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p51wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p52wp_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p52wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p53wp_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p53wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p54wp_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p54wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p55wp_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p55wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p56wp_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p56wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p57wp_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p57wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p58wp_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p58wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p59wp_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p59wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p60wp_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p60wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p61wp_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p61wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p62wp_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p62wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p63wp_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr p63wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr2_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return static_cast<ramcfg_m2wpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr2_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr2_r> {return opsy::utility::clear_set<ramcfg_m2wpr2_r>(ramcfg_m2wpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto p32wp() const -> p32wp_f {return p32wp_f((value_ & p32wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p33wp() const -> p33wp_f {return p33wp_f((value_ & p33wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p34wp() const -> p34wp_f {return p34wp_f((value_ & p34wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p35wp() const -> p35wp_f {return p35wp_f((value_ & p35wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p36wp() const -> p36wp_f {return p36wp_f((value_ & p36wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p37wp() const -> p37wp_f {return p37wp_f((value_ & p37wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p38wp() const -> p38wp_f {return p38wp_f((value_ & p38wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p39wp() const -> p39wp_f {return p39wp_f((value_ & p39wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p40wp() const -> p40wp_f {return p40wp_f((value_ & p40wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p41wp() const -> p41wp_f {return p41wp_f((value_ & p41wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p42wp() const -> p42wp_f {return p42wp_f((value_ & p42wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p43wp() const -> p43wp_f {return p43wp_f((value_ & p43wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p44wp() const -> p44wp_f {return p44wp_f((value_ & p44wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p45wp() const -> p45wp_f {return p45wp_f((value_ & p45wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p46wp() const -> p46wp_f {return p46wp_f((value_ & p46wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p47wp() const -> p47wp_f {return p47wp_f((value_ & p47wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p48wp() const -> p48wp_f {return p48wp_f((value_ & p48wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p49wp() const -> p49wp_f {return p49wp_f((value_ & p49wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p50wp() const -> p50wp_f {return p50wp_f((value_ & p50wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p51wp() const -> p51wp_f {return p51wp_f((value_ & p51wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p52wp() const -> p52wp_f {return p52wp_f((value_ & p52wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p53wp() const -> p53wp_f {return p53wp_f((value_ & p53wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p54wp() const -> p54wp_f {return p54wp_f((value_ & p54wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p55wp() const -> p55wp_f {return p55wp_f((value_ & p55wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p56wp() const -> p56wp_f {return p56wp_f((value_ & p56wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p57wp() const -> p57wp_f {return p57wp_f((value_ & p57wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p58wp() const -> p58wp_f {return p58wp_f((value_ & p58wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p59wp() const -> p59wp_f {return p59wp_f((value_ & p59wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p60wp() const -> p60wp_f {return p60wp_f((value_ & p60wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p61wp() const -> p61wp_f {return p61wp_f((value_ & p61wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p62wp() const -> p62wp_f {return p62wp_f((value_ & p62wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p63wp() const -> p63wp_f {return p63wp_f((value_ & p63wp_f::mask) != 0);}

	constexpr ramcfg_m2wpr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_m2wpr2_r other) const -> ramcfg_m2wpr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_m2wpr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory 2 write protection register 3
 */
class ramcfg_m2wpr3_r {
public:

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p64wp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p64wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p65wp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p65wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p66wp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p66wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p67wp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p67wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p68wp_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p68wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p69wp_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p69wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p70wp_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p70wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p71wp_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr p71wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p72wp_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p72wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p73wp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p73wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p74wp_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p74wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p75wp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p75wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p76wp_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p76wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p77wp_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p77wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p78wp_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p78wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 1-Kbyte page y write protection 
 */
class p79wp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr p79wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator ramcfg_m2wpr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<ramcfg_m2wpr3_r>() const {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(mask, *this);}
	constexpr auto operator|(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return static_cast<ramcfg_m2wpr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_m2wpr3_r> other) const -> opsy::utility::clear_set<ramcfg_m2wpr3_r> {return opsy::utility::clear_set<ramcfg_m2wpr3_r>(ramcfg_m2wpr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto p64wp() const -> p64wp_f {return p64wp_f((value_ & p64wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p65wp() const -> p65wp_f {return p65wp_f((value_ & p65wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p66wp() const -> p66wp_f {return p66wp_f((value_ & p66wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p67wp() const -> p67wp_f {return p67wp_f((value_ & p67wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p68wp() const -> p68wp_f {return p68wp_f((value_ & p68wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p69wp() const -> p69wp_f {return p69wp_f((value_ & p69wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p70wp() const -> p70wp_f {return p70wp_f((value_ & p70wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p71wp() const -> p71wp_f {return p71wp_f((value_ & p71wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p72wp() const -> p72wp_f {return p72wp_f((value_ & p72wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p73wp() const -> p73wp_f {return p73wp_f((value_ & p73wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p74wp() const -> p74wp_f {return p74wp_f((value_ & p74wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p75wp() const -> p75wp_f {return p75wp_f((value_ & p75wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p76wp() const -> p76wp_f {return p76wp_f((value_ & p76wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p77wp() const -> p77wp_f {return p77wp_f((value_ & p77wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p78wp() const -> p78wp_f {return p78wp_f((value_ & p78wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto p79wp() const -> p79wp_f {return p79wp_f((value_ & p79wp_f::mask) != 0);}

	constexpr ramcfg_m2wpr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_m2wpr3_r other) const -> ramcfg_m2wpr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_m2wpr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * RAMCFG memory X ECC key register
 */
class ramcfg_mxecckeyr_r {
public:

/**
 * ECC write protection key 
 */
class ecckey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ecckey_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator ramcfg_mxecckeyr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<ramcfg_mxecckeyr_r>() const {return opsy::utility::clear_set<ramcfg_mxecckeyr_r>(mask, *this);}
	constexpr auto operator|(ramcfg_mxecckeyr_r other) const -> ramcfg_mxecckeyr_r { return static_cast<ramcfg_mxecckeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<ramcfg_mxecckeyr_r> other) const -> opsy::utility::clear_set<ramcfg_mxecckeyr_r> {return opsy::utility::clear_set<ramcfg_mxecckeyr_r>(ramcfg_mxecckeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ecckey() const -> ecckey_f {return ecckey_f(static_cast<uint8_t>(value_ >> ecckey_f::offset));}

	constexpr ramcfg_mxecckeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(ramcfg_mxecckeyr_r other) const -> ramcfg_mxecckeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> ramcfg_mxecckeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,ramcfg_mxcr_r> ramcfg_m1cr;
	opsy::utility::padding<4> _p4;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxisr_r> ramcfg_m1isr;
	opsy::utility::padding<28> _p12;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxerkeyr_r> ramcfg_m1erkeyr;
	opsy::utility::padding<20> _p44;
	opsy::utility::memory<uint32_t,ramcfg_mxcr_r> ramcfg_m2cr;
	opsy::utility::memory<uint32_t,ramcfg_mxier_r> ramcfg_m2ier;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxisr_r> ramcfg_m2isr;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxsear_r> ramcfg_m2sear;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxdear_r> ramcfg_m2dear;
	opsy::utility::memory<uint32_t,ramcfg_mxicr_r> ramcfg_m2icr;
	opsy::utility::memory<uint32_t,ramcfg_m2wpr1_r> ramcfg_m2wpr1;
	opsy::utility::memory<uint32_t,ramcfg_m2wpr2_r> ramcfg_m2wpr2;
	opsy::utility::memory<uint32_t,ramcfg_m2wpr3_r> ramcfg_m2wpr3;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxecckeyr_r> ramcfg_m2ecckeyr;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxerkeyr_r> ramcfg_m2erkeyr;
	opsy::utility::padding<20> _p108;
	opsy::utility::memory<uint32_t,ramcfg_mxcr_r> ramcfg_m3cr;
	opsy::utility::memory<uint32_t,ramcfg_mxier_r> ramcfg_m3ier;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxisr_r> ramcfg_m3isr;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxsear_r> ramcfg_m3sear;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxdear_r> ramcfg_m3dear;
	opsy::utility::memory<uint32_t,ramcfg_mxicr_r> ramcfg_m3icr;
	opsy::utility::padding<12> _p152;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxecckeyr_r> ramcfg_m3ecckeyr;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxerkeyr_r> ramcfg_m3erkeyr;
	opsy::utility::padding<60> _p172;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxerkeyr_r> ramcfg_m4erkeyr;
	opsy::utility::padding<20> _p236;
	opsy::utility::memory<uint32_t,ramcfg_mxcr_r> ramcfg_m5cr;
	opsy::utility::memory<uint32_t,ramcfg_mxier_r> ramcfg_m5ier;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxisr_r> ramcfg_m5isr;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxsear_r> ramcfg_m5sear;
	opsy::utility::read_only_memory<uint32_t,ramcfg_mxdear_r> ramcfg_m5dear;
	opsy::utility::memory<uint32_t,ramcfg_mxicr_r> ramcfg_m5icr;
	opsy::utility::padding<12> _p280;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxecckeyr_r> ramcfg_m5ecckeyr;
	opsy::utility::write_only_memory<uint32_t,ramcfg_mxerkeyr_r> ramcfg_m5erkeyr;
};

static_assert(std::is_standard_layout_v<ramcfg_p>);
static_assert(offsetof(ramcfg_p, ramcfg_m1cr) == 0);
static_assert(offsetof(ramcfg_p, ramcfg_m1isr) == 8);
static_assert(offsetof(ramcfg_p, ramcfg_m1erkeyr) == 40);
static_assert(offsetof(ramcfg_p, ramcfg_m2cr) == 64);
static_assert(offsetof(ramcfg_p, ramcfg_m2ier) == 68);
static_assert(offsetof(ramcfg_p, ramcfg_m2isr) == 72);
static_assert(offsetof(ramcfg_p, ramcfg_m2sear) == 76);
static_assert(offsetof(ramcfg_p, ramcfg_m2dear) == 80);
static_assert(offsetof(ramcfg_p, ramcfg_m2icr) == 84);
static_assert(offsetof(ramcfg_p, ramcfg_m2wpr1) == 88);
static_assert(offsetof(ramcfg_p, ramcfg_m2wpr2) == 92);
static_assert(offsetof(ramcfg_p, ramcfg_m2wpr3) == 96);
static_assert(offsetof(ramcfg_p, ramcfg_m2ecckeyr) == 100);
static_assert(offsetof(ramcfg_p, ramcfg_m2erkeyr) == 104);
static_assert(offsetof(ramcfg_p, ramcfg_m3cr) == 128);
static_assert(offsetof(ramcfg_p, ramcfg_m3ier) == 132);
static_assert(offsetof(ramcfg_p, ramcfg_m3isr) == 136);
static_assert(offsetof(ramcfg_p, ramcfg_m3sear) == 140);
static_assert(offsetof(ramcfg_p, ramcfg_m3dear) == 144);
static_assert(offsetof(ramcfg_p, ramcfg_m3icr) == 148);
static_assert(offsetof(ramcfg_p, ramcfg_m3ecckeyr) == 164);
static_assert(offsetof(ramcfg_p, ramcfg_m3erkeyr) == 168);
static_assert(offsetof(ramcfg_p, ramcfg_m4erkeyr) == 232);
static_assert(offsetof(ramcfg_p, ramcfg_m5cr) == 256);
static_assert(offsetof(ramcfg_p, ramcfg_m5ier) == 260);
static_assert(offsetof(ramcfg_p, ramcfg_m5isr) == 264);
static_assert(offsetof(ramcfg_p, ramcfg_m5sear) == 268);
static_assert(offsetof(ramcfg_p, ramcfg_m5dear) == 272);
static_assert(offsetof(ramcfg_p, ramcfg_m5icr) == 276);
static_assert(offsetof(ramcfg_p, ramcfg_m5ecckeyr) == 292);
static_assert(offsetof(ramcfg_p, ramcfg_m5erkeyr) == 296);

inline ramcfg_p& ramcfg = *reinterpret_cast<ramcfg_p*>(0x40026000);
inline ramcfg_p& ramcfg_s = *reinterpret_cast<ramcfg_p*>(0x50026000);

} // STM32H523

