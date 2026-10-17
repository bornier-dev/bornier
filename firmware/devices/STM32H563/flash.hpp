#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * FLASH address block description
 */
class flash_p {
public:

/**
 * FLASH access control register
 */
class flash_acr_r {
public:

/**
 * Read latency These bits are used to control the number of wait states used during read operations on both nonvolatile memory banks. The application software has to program them to the correct value depending on the embedded flash memory interface frequency and voltage conditions. ... Note: No check is performed by hardware to verify that the configuration is correct.
 */
class latency_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr latency_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_acr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_acr_r>() const {return opsy::utility::clear_set<flash_acr_r>(mask, *this);}
	constexpr auto operator|(flash_acr_r other) const -> flash_acr_r { return static_cast<flash_acr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_acr_r> other) const -> opsy::utility::clear_set<flash_acr_r> {return opsy::utility::clear_set<flash_acr_r>(flash_acr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Flash signal delay These bits are used to control the delay between nonvolatile memory signals during programming operations. Application software has to program them to the correct value depending on the embedded flash memory interface frequency. Please refer to Table44 for details. Note: No check is performed to verify that the configuration is correct. Note: Two WRHIGHFREQ values can be selected for some frequencies.
 */
class wrhighfreq_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr wrhighfreq_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_acr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_acr_r>() const {return opsy::utility::clear_set<flash_acr_r>(mask, *this);}
	constexpr auto operator|(flash_acr_r other) const -> flash_acr_r { return static_cast<flash_acr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_acr_r> other) const -> opsy::utility::clear_set<flash_acr_r> {return opsy::utility::clear_set<flash_acr_r>(flash_acr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Prefetch enable. When bit value is modified, user must read back ACR register to be sure PRFTEN has been taken into account. Bits used to control the prefetch.
 */
class prften_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr prften_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_acr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_acr_r>() const {return opsy::utility::clear_set<flash_acr_r>(mask, *this);}
	constexpr auto operator|(flash_acr_r other) const -> flash_acr_r { return static_cast<flash_acr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_acr_r> other) const -> opsy::utility::clear_set<flash_acr_r> {return opsy::utility::clear_set<flash_acr_r>(flash_acr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto latency() const -> latency_f {return latency_f(static_cast<uint8_t>(value_ >> latency_f::offset));}
	[[nodiscard]] constexpr auto wrhighfreq() const -> wrhighfreq_f {return wrhighfreq_f(static_cast<uint8_t>(value_ >> wrhighfreq_f::offset));}
	[[nodiscard]] constexpr auto prften() const -> prften_f {return prften_f((value_ & prften_f::mask) != 0);}

	constexpr flash_acr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_acr_r other) const -> flash_acr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_acr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10011; // 19 0x13

private:
	uint32_t value_;
};

/**
 * FLASH non-secure key register
 */
class flash_nskeyr_r {
public:

/**
 * Non-volatile memory non-secure configuration access unlock key
 */
class nskey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nskey_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_nskeyr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nskeyr_r>() const {return opsy::utility::clear_set<flash_nskeyr_r>(mask, *this);}
	constexpr auto operator|(flash_nskeyr_r other) const -> flash_nskeyr_r { return static_cast<flash_nskeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nskeyr_r> other) const -> opsy::utility::clear_set<flash_nskeyr_r> {return opsy::utility::clear_set<flash_nskeyr_r>(flash_nskeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto nskey() const -> nskey_f {return nskey_f(static_cast<uint32_t>(value_ >> nskey_f::offset));}

	constexpr flash_nskeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nskeyr_r other) const -> flash_nskeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nskeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure key register
 */
class flash_seckeyr_r {
public:

/**
 * Non-volatile memory secure configuration access unlock key
 */
class seckey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr seckey_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_seckeyr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_seckeyr_r>() const {return opsy::utility::clear_set<flash_seckeyr_r>(mask, *this);}
	constexpr auto operator|(flash_seckeyr_r other) const -> flash_seckeyr_r { return static_cast<flash_seckeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seckeyr_r> other) const -> opsy::utility::clear_set<flash_seckeyr_r> {return opsy::utility::clear_set<flash_seckeyr_r>(flash_seckeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto seckey() const -> seckey_f {return seckey_f(static_cast<uint32_t>(value_ >> seckey_f::offset));}

	constexpr flash_seckeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_seckeyr_r other) const -> flash_seckeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_seckeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option key register
 */
class flash_optkeyr_r {
public:

/**
 * FLASH option bytes control access unlock key
 */
class optkey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr optkey_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_optkeyr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optkeyr_r>() const {return opsy::utility::clear_set<flash_optkeyr_r>(mask, *this);}
	constexpr auto operator|(flash_optkeyr_r other) const -> flash_optkeyr_r { return static_cast<flash_optkeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optkeyr_r> other) const -> opsy::utility::clear_set<flash_optkeyr_r> {return opsy::utility::clear_set<flash_optkeyr_r>(flash_optkeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto optkey() const -> optkey_f {return optkey_f(static_cast<uint32_t>(value_ >> optkey_f::offset));}

	constexpr flash_optkeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optkeyr_r other) const -> flash_optkeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optkeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure OBK key register
 */
class flash_nsobkkeyr_r {
public:

/**
 * FLASH non-secure option bytes keys control access unlock key
 */
class nsobkkey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nsobkkey_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_nsobkkeyr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsobkkeyr_r>() const {return opsy::utility::clear_set<flash_nsobkkeyr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkkeyr_r other) const -> flash_nsobkkeyr_r { return static_cast<flash_nsobkkeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkkeyr_r> other) const -> opsy::utility::clear_set<flash_nsobkkeyr_r> {return opsy::utility::clear_set<flash_nsobkkeyr_r>(flash_nsobkkeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto nsobkkey() const -> nsobkkey_f {return nsobkkey_f(static_cast<uint32_t>(value_ >> nsobkkey_f::offset));}

	constexpr flash_nsobkkeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsobkkeyr_r other) const -> flash_nsobkkeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsobkkeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure OBK key register
 */
class flash_secobkkeyr_r {
public:

/**
 * FLASH secure option bytes keys control access unlock key
 */
class secobkkey_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secobkkey_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_secobkkeyr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secobkkeyr_r>() const {return opsy::utility::clear_set<flash_secobkkeyr_r>(mask, *this);}
	constexpr auto operator|(flash_secobkkeyr_r other) const -> flash_secobkkeyr_r { return static_cast<flash_secobkkeyr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secobkkeyr_r> other) const -> opsy::utility::clear_set<flash_secobkkeyr_r> {return opsy::utility::clear_set<flash_secobkkeyr_r>(flash_secobkkeyr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto secobkkey() const -> secobkkey_f {return secobkkey_f(static_cast<uint32_t>(value_ >> secobkkey_f::offset));}

	constexpr flash_secobkkeyr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secobkkeyr_r other) const -> flash_secobkkeyr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secobkkeyr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH operation status register
 */
class flash_opsr_r {
public:

/**
 * Interrupted operation address
 */
class addr_op_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr addr_op_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_opsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

/**
 * Flash high-cycle data area operation interrupted It indicates if flash high-cycle data area is concerned by operation.
 */
class data_op_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr data_op_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_opsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupted operation bank It indicates which bank was concerned by operation.
 */
class bk_op_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk_op_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_opsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Operation in system flash memory interrupted Indicates that reset interrupted an ongoing operation in system flash.
 */
class sysf_op_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sysf_op_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_opsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OTP operation interrupted Indicates that reset interrupted an ongoing operation in OTP area (or OBKeys area).
 */
class otp_op_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr otp_op_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_opsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Flash memory operation code
 */
class code_op_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr code_op_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_opsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_opsr_r>() const {return opsy::utility::clear_set<flash_opsr_r>(mask, *this);}
	constexpr auto operator|(flash_opsr_r other) const -> flash_opsr_r { return static_cast<flash_opsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_opsr_r> other) const -> opsy::utility::clear_set<flash_opsr_r> {return opsy::utility::clear_set<flash_opsr_r>(flash_opsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto addr_op() const -> addr_op_f {return addr_op_f(static_cast<uint32_t>(value_ >> addr_op_f::offset));}
	[[nodiscard]] constexpr auto data_op() const -> data_op_f {return data_op_f((value_ & data_op_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk_op() const -> bk_op_f {return bk_op_f((value_ & bk_op_f::mask) != 0);}
	[[nodiscard]] constexpr auto sysf_op() const -> sysf_op_f {return sysf_op_f((value_ & sysf_op_f::mask) != 0);}
	[[nodiscard]] constexpr auto otp_op() const -> otp_op_f {return otp_op_f((value_ & otp_op_f::mask) != 0);}
	[[nodiscard]] constexpr auto code_op() const -> code_op_f {return code_op_f(static_cast<uint8_t>(value_ >> code_op_f::offset));}

	constexpr flash_opsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_opsr_r other) const -> flash_opsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_opsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option control register
 */
class flash_optcr_r {
public:

/**
 * FLASH_OPTCR lock option configuration bit The OPTLOCK bit locks the FLASH_OPTCR register as well as all _PRG registers. The correct write sequence to FLASH_OPTKEYR register unlocks this bit. If a wrong sequence is executed, or the unlock sequence to FLASH_OPTKEYR is performed twice, this bit remains locked until next system reset. It is possible to set OPTLOCK by programming it to 1. When set to 1, a new unlock sequence is mandatory to unlock it. When OPTLOCK changes from 0 to 1, the others bits of FLASH_OPTCR register do not change.
 */
class optlock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr optlock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optcr_r>() const {return opsy::utility::clear_set<flash_optcr_r>(mask, *this);}
	constexpr auto operator|(flash_optcr_r other) const -> flash_optcr_r { return static_cast<flash_optcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optcr_r> other) const -> opsy::utility::clear_set<flash_optcr_r> {return opsy::utility::clear_set<flash_optcr_r>(flash_optcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Option byte start change option configuration bit OPTSTRT triggers an option byte change operation. The user can set OPTSTRT only when the OPTLOCK bit is cleared to 0. It is set only by Software and cleared when the option byte change is completed or an error occurs (PGSERR or OPTCHANGEERR). It is reseted at the same time as BSY bit. The user application cannot modify any FLASH_XXX_PRG flash interface register until the option change operation has been completed. Before setting this bit, the user has to write the required values in the FLASH_XXX_PRG registers. The FLASH_XXX_PRG registers are locked until the option byte change operation has been executed in nonvolatile memory.
 */
class optstrt_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr optstrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optcr_r>() const {return opsy::utility::clear_set<flash_optcr_r>(mask, *this);}
	constexpr auto operator|(flash_optcr_r other) const -> flash_optcr_r { return static_cast<flash_optcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optcr_r> other) const -> opsy::utility::clear_set<flash_optcr_r> {return opsy::utility::clear_set<flash_optcr_r>(flash_optcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bank swapping option configuration bit SWAP_BANK controls whether Bank1 and Bank2 are swapped or not. This bit is loaded with the SWAP_BANK bit of FLASH_OPTSR_CUR register only after reset or POR.
 */
class swap_bank_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swap_bank_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optcr_r>() const {return opsy::utility::clear_set<flash_optcr_r>(mask, *this);}
	constexpr auto operator|(flash_optcr_r other) const -> flash_optcr_r { return static_cast<flash_optcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optcr_r> other) const -> opsy::utility::clear_set<flash_optcr_r> {return opsy::utility::clear_set<flash_optcr_r>(flash_optcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto optlock() const -> optlock_f {return optlock_f((value_ & optlock_f::mask) != 0);}
	[[nodiscard]] constexpr auto optstrt() const -> optstrt_f {return optstrt_f((value_ & optstrt_f::mask) != 0);}
	[[nodiscard]] constexpr auto swap_bank() const -> swap_bank_f {return swap_bank_f((value_ & swap_bank_f::mask) != 0);}

	constexpr flash_optcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optcr_r other) const -> flash_optcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * FLASH non-secure status register
 */
class flash_nssr_r {
public:

/**
 * busy flag BSY flag indicates that a flash memory is busy by an operation (write, erase, option byte change, OBK operation). It is set at the beginning of a flash memory operation and cleared when the operation finishes, or an error occurs.
 */
class bsy_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write buffer not empty flag WBNE flag is set when the flash interface is waiting for new data to complete the write buffer. In this state, the write buffer is not empty. WBNE is reset by hardware each time the write buffer is complete or the write buffer is emptied following one of the event below: the application software forces the write operation using FW bit in FLASH_NSCR the embedded flash memory detects an error that involves data loss This bit cannot be reset by software writing 0 directly. To reset it, clear the write buffer by performing any of the above listed actions, or send the missing data.
 */
class wbne_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wbne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data buffer not empty flag DBNE flag is set when the flash interface is processing 6-bits ECC data in dedicated buffer. This bit cannot be set to 0 by software. The hardware resets it once the buffer is free.
 */
class dbne_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of operation flag EOP flag is set when a operation (program/erase) completes. An interrupt is generated if the EOPIE is set to 1. It is not necessary to reset EOP before starting a new operation. EOP bit is cleared by writing 1 to CLR_EOP bit in FLASH_NSCCR register.
 */
class eop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write protection error flag WRPERR flag is raised when a protection error occurs during a program operation. An interrupt is also generated if the WRPERRIE is set to 1. Writing 1 to CLR_WRPERR bit in FLASH_NSCCR register clears WRPERR.
 */
class wrperr_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wrperr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming sequence error flag PGSERR flag is raised when a sequence error occurs. An interrupt is generated if the PGSERRIE bit is set to 1. Writing 1 to CLR_PGSERR bit in FLASH_NSCCR register clears PGSERR.
 */
class pgserr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pgserr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * strobe error flag STRBERR flag is raised when a strobe error occurs (when the master attempts to write several times the same byte in the write buffer). An interrupt is generated if the STRBERRIE bit is set to 1. Writing 1 to CLR_STRBERR bit in FLASH_NSCCR register clears STRBERR.
 */
class strberr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr strberr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * inconsistency error flag NSINCERR flag is raised when a inconsistency error occurs. An interrupt is generated if INCERRIE is set to 1. Writing 1 to CLR_INCERR bit in the FLASH_NSCCR register clears NSINCERR.
 */
class incerr_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr incerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK general error flag OBKERR flag is raised when the OBK-HDPL signal from the SBS does not match the HDPL value associated with the key slot during access to the key location. Alternatively also when the ALT_SECT is unexpectedly changed while the write buffer is being filled.
 */
class obkerr_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK write error flag OBKWERR flag is raised when the address is not virgin on a write access to the OBK storage. Alternatively also when the OBK selector in the alternate sector is not virgin during a swap operation.
 */
class obkwerr_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkwerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Option byte change error flag OPTCHANGEERR flag indicates that an error occurred during an option byte change operation. When OPTCHANGEERR is set to 1, the option byte change operation did not successfully complete. An interrupt is generated when this flag is raised if the OPTCHANGEERRIE bit of FLASH_NSCR register is set to 1. Writing 1 to CLR_OPTCHANGEERR of register FLASH_NSCCR clears OPTCHANGEERR. Note: The OPTSTRT bit in FLASH_OPTCR cannot be set while OPTCHANGEERR is set.
 */
class optchangeerr_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr optchangeerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nssr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nssr_r>() const {return opsy::utility::clear_set<flash_nssr_r>(mask, *this);}
	constexpr auto operator|(flash_nssr_r other) const -> flash_nssr_r { return static_cast<flash_nssr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nssr_r> other) const -> opsy::utility::clear_set<flash_nssr_r> {return opsy::utility::clear_set<flash_nssr_r>(flash_nssr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bsy() const -> bsy_f {return bsy_f((value_ & bsy_f::mask) != 0);}
	[[nodiscard]] constexpr auto wbne() const -> wbne_f {return wbne_f((value_ & wbne_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbne() const -> dbne_f {return dbne_f((value_ & dbne_f::mask) != 0);}
	[[nodiscard]] constexpr auto eop() const -> eop_f {return eop_f((value_ & eop_f::mask) != 0);}
	[[nodiscard]] constexpr auto wrperr() const -> wrperr_f {return wrperr_f((value_ & wrperr_f::mask) != 0);}
	[[nodiscard]] constexpr auto pgserr() const -> pgserr_f {return pgserr_f((value_ & pgserr_f::mask) != 0);}
	[[nodiscard]] constexpr auto strberr() const -> strberr_f {return strberr_f((value_ & strberr_f::mask) != 0);}
	[[nodiscard]] constexpr auto incerr() const -> incerr_f {return incerr_f((value_ & incerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkerr() const -> obkerr_f {return obkerr_f((value_ & obkerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkwerr() const -> obkwerr_f {return obkwerr_f((value_ & obkwerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto optchangeerr() const -> optchangeerr_f {return optchangeerr_f((value_ & optchangeerr_f::mask) != 0);}

	constexpr flash_nssr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nssr_r other) const -> flash_nssr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nssr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure status register
 */
class flash_secsr_r {
public:

/**
 * busy flag BSY flag indicates that a FLASH memory is busy (write, erase, option byte change, OBK operations). It is set at the beginning of a flash memory operation and cleared when the operation finishes or an error occurs.
 */
class bsy_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bsy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write buffer not empty flag WBNE flag is set when the flash interface is waiting for new data to complete the write buffer. In this state, the write buffer is not empty. WBNE is reset by hardware each time the write buffer is complete or the write buffer is emptied following one of the event below: the application software forces the write operation using FW bit in FLASH_SECCR the flash interface detects an error that involves data loss This bit cannot be reset by writing 0 directly by software. To reset it, clear the write buffer by performing any of the above listed actions, or send the missing data.
 */
class wbne_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wbne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data buffer not empty flag DBNE flag is set when the embedded flash memory interface is processing 6-bits ECC data in dedicated buffer. This bit cannot be set to 0 by software. The hardware resets it once the buffer is free.
 */
class dbne_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dbne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of operation flag EOP flag is set when a operation (program/erase) completes. An interrupt is generated if the EOPIE is set to. It is not necessary to reset EOP before starting a new operation. EOP bit is cleared by writing 1 to CLR_EOP bit in FLASH_SECCCR register.
 */
class eop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write protection error flag WRPERR flag is raised when a protection error occurs during a program operation. An interrupt is also generated if the WRPERRIE is set to 1. Writing 1 to CLR_WRPERR bit in FLASH_SECCCR register clears WRPERR.
 */
class wrperr_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wrperr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming sequence error flag PGSERR flag is raised when a sequence error occurs. An interrupt is generated if the PGSERRIE bit is set to 1. Writing 1 to CLR_PGSERR bit in FLASH_SECCCR register clears PGSERR.
 */
class pgserr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pgserr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * strobe error flag STRBERR flag is raised when a strobe error occurs (when the master attempts to write several times the same byte in the write buffer). An interrupt is generated if the STRBERRIE bit is set to 1. Writing 1 to CLR_STRBERR bit in FLASH_SECCCR register clears STRBERR.
 */
class strberr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr strberr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * inconsistency error flag INCERR flag is raised when a inconsistency error occurs. An interrupt is generated if INCERRIE is set to 1. Writing 1 to CLR_INCERR bit in the FLASH_SECCCR register clears INCERR.
 */
class incerr_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr incerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK general error flag OBKERR flag is raised when the OBK-HDPL signal from the SBS does not match the HDPL value associated with the key slot during access to the key location. Alternatively also when the ALT_SECT is unexpectedly changed while the write buffer is being filled.
 */
class obkerr_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK write error flag OBKWERR flag is raised when the address is not virgin on a write access to the OBK storage. Alternatively also when the OBK selector in the alternate sector is not virgin during a swap operation.
 */
class obkwerr_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkwerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secsr_r>() const {return opsy::utility::clear_set<flash_secsr_r>(mask, *this);}
	constexpr auto operator|(flash_secsr_r other) const -> flash_secsr_r { return static_cast<flash_secsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secsr_r> other) const -> opsy::utility::clear_set<flash_secsr_r> {return opsy::utility::clear_set<flash_secsr_r>(flash_secsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bsy() const -> bsy_f {return bsy_f((value_ & bsy_f::mask) != 0);}
	[[nodiscard]] constexpr auto wbne() const -> wbne_f {return wbne_f((value_ & wbne_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbne() const -> dbne_f {return dbne_f((value_ & dbne_f::mask) != 0);}
	[[nodiscard]] constexpr auto eop() const -> eop_f {return eop_f((value_ & eop_f::mask) != 0);}
	[[nodiscard]] constexpr auto wrperr() const -> wrperr_f {return wrperr_f((value_ & wrperr_f::mask) != 0);}
	[[nodiscard]] constexpr auto pgserr() const -> pgserr_f {return pgserr_f((value_ & pgserr_f::mask) != 0);}
	[[nodiscard]] constexpr auto strberr() const -> strberr_f {return strberr_f((value_ & strberr_f::mask) != 0);}
	[[nodiscard]] constexpr auto incerr() const -> incerr_f {return incerr_f((value_ & incerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkerr() const -> obkerr_f {return obkerr_f((value_ & obkerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkwerr() const -> obkwerr_f {return obkwerr_f((value_ & obkwerr_f::mask) != 0);}

	constexpr flash_secsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secsr_r other) const -> flash_secsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure control register
 */
class flash_nscr_r {
public:

/**
 * configuration lock bit This bit locks the FLASH_NSCR register. The correct write sequence to FLASH_NSKEYR register unlocks this bit. If a wrong sequence is executed, or if the unlock sequence to FLASH_NSKEYR is performed twice, this bit remains locked until the next system reset. LOCK can be set by programming it to 1. When set to 1, a new unlock sequence is mandatory to unlock it. When LOCK changes from 0 to 1, the other bits of FLASH_NSCR register do not change.
 */
class lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming control bit PG can be programmed only when LOCK is cleared to 0. PG allows programming in Bank1 and Bank2.
 */
class pg_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * sector erase request Setting SER bit to 1 requests a sector erase. SER can be programmed only when LOCK is cleared to 0. If MER and SER are also set, a PGSERR is raised.
 */
class ser_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ser_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * erase request Setting BER bit to 1 requests a bank erase operation (user flash memory only). BER can be programmed only when LOCK is cleared to 0. If MER and SER are also set, a PGSERR is raised. Note: Write protection error is triggered when a bank erase is required and some sectors are protected.
 */
class ber_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ber_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write forcing control bit FW forces a write operation even if the write buffer is not full. In this case all bits not written are set to 1 by hardware. FW can be programmed only when LOCK is cleared to 0. The embedded flash memory resets FW when the corresponding operation has been acknowledged. Note: Using a force-write operation prevents the application from updating later the missing bits with something else than 1, because it is likely that it leads to permanent ECC error. Write forcing is effective only if the write buffer is not empty and was filled by non-secure access (in particular, FW does not start several write operations when the force-write operations are performed consecutively). Since there is just one write buffer, FW can force a write in bank1 or bank2.
 */
class fw_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * erase start control bit STRT bit is used to start a sector erase or a bank erase operation. STRT can be programmed only when LOCK is cleared to 0. STRT is reset at the end of the operation or when an error occurs. It cannot be reseted by software.
 */
class strt_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr strt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * sector erase selection number These bits are used to select the target sector for an erase operation (they are unused otherwise). SNB can be programmed only when LOCK is cleared to 0. ..
 */
class snb_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr snb_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_nscr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Mass erase request Setting MER bit to 1 requests a mass erase operation (user flash memory only). MER can be programmed only when LOCK is cleared to 0. If BER or SER are both set, a PGSERR is raised. Error is triggered when a mass erase is required and some sectors are protected.
 */
class mer_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mer_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of operation interrupt control bit Setting EOPIE bit to 1 enables the generation of an interrupt at the end of a program or erase operation. EOPIE can be programmed only when LOCK is cleared to 0.
 */
class eopie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eopie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write protection error interrupt enable bit When this bit is set to 1, an interrupt is generated when a protection error occurs during a program operation. WRPERRIE can be programmed only when LOCK is cleared to 0.
 */
class wrperrie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wrperrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming sequence error interrupt enable bit When this bit is set to 1, an interrupt is generated when a sequence error occurs during a program operation. PGSERRIE can be programmed only when LOCK is cleared to 0.
 */
class pgserrie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pgserrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * strobe error interrupt enable bit When STRBERRIE bit is set to 1, an interrupt is generated when a strobe error occurs (the master programs several times the same byte in the write buffer) during a write operation. STRBERRIE can be programmed only when LOCK is cleared to 0.
 */
class strberrie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr strberrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * inconsistency error interrupt enable bit When INCERRIE bit is set to 1, an interrupt is generated when an inconsistency error occurs during a write operation. INCERRIE can be programmed only when LOCK is cleared to 0.
 */
class incerrie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr incerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK general error interrupt enable bit OBKERRIE enables generating an interrupt in case of OBK specific access error. This bit can be programmed only when LOCK bit is cleared to 0.
 */
class obkerrie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK write error interrupt enable bit OBKWERRIE enables generation of interrupt in case of OBK specific write error. This bit can be programmed only when LOCK bit is cleared to 0.
 */
class obkwerrie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkwerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Option byte change error interrupt enable bit This bit controls if an interrupt must be generated when an error occurs during an option byte change. It can be programmed only when LOCK bit is cleared to 0.
 */
class optchangeerrie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr optchangeerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Bank selector bit BKSEL can only be programmed when LOCK is cleared to 0. The bit selects physical bank, SWAP_BANK setting is ignored.
 */
class bksel_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nscr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nscr_r>() const {return opsy::utility::clear_set<flash_nscr_r>(mask, *this);}
	constexpr auto operator|(flash_nscr_r other) const -> flash_nscr_r { return static_cast<flash_nscr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nscr_r> other) const -> opsy::utility::clear_set<flash_nscr_r> {return opsy::utility::clear_set<flash_nscr_r>(flash_nscr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lock() const -> lock_f {return lock_f((value_ & lock_f::mask) != 0);}
	[[nodiscard]] constexpr auto pg() const -> pg_f {return pg_f((value_ & pg_f::mask) != 0);}
	[[nodiscard]] constexpr auto ser() const -> ser_f {return ser_f((value_ & ser_f::mask) != 0);}
	[[nodiscard]] constexpr auto ber() const -> ber_f {return ber_f((value_ & ber_f::mask) != 0);}
	[[nodiscard]] constexpr auto fw() const -> fw_f {return fw_f((value_ & fw_f::mask) != 0);}
	[[nodiscard]] constexpr auto strt() const -> strt_f {return strt_f((value_ & strt_f::mask) != 0);}
	[[nodiscard]] constexpr auto snb() const -> snb_f {return snb_f(static_cast<uint8_t>(value_ >> snb_f::offset));}
	[[nodiscard]] constexpr auto mer() const -> mer_f {return mer_f((value_ & mer_f::mask) != 0);}
	[[nodiscard]] constexpr auto eopie() const -> eopie_f {return eopie_f((value_ & eopie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wrperrie() const -> wrperrie_f {return wrperrie_f((value_ & wrperrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pgserrie() const -> pgserrie_f {return pgserrie_f((value_ & pgserrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto strberrie() const -> strberrie_f {return strberrie_f((value_ & strberrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto incerrie() const -> incerrie_f {return incerrie_f((value_ & incerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkerrie() const -> obkerrie_f {return obkerrie_f((value_ & obkerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkwerrie() const -> obkwerrie_f {return obkwerrie_f((value_ & obkwerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto optchangeerrie() const -> optchangeerrie_f {return optchangeerrie_f((value_ & optchangeerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto bksel() const -> bksel_f {return bksel_f((value_ & bksel_f::mask) != 0);}

	constexpr flash_nscr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nscr_r other) const -> flash_nscr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nscr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * FLASH secure control register
 */
class flash_seccr_r {
public:

/**
 * configuration lock bit This bit locks the FLASH_SECCR register. The correct write sequence to FLASH_SECKEYR register unlocks this bit. If a wrong sequence is executed, or if the unlock sequence to FLASH_NSKEYR is performed twice, this bit remains locked until the next system reset. LOCK can be set by programming it to 1. When set to 1, a new unlock sequence is mandatory to unlock it. When LOCK changes from 0 to 1, the other bits of FLASH_SECCR register do not change.
 */
class lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming control bit PG can be programmed only when LOCK is cleared to 0. PG allows programming in Bank1 and Bank2.
 */
class pg_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * sector erase request Setting SER bit to 1 requests a sector erase. SER can be programmed only when LOCK is cleared to 0. If BER and MER are also set, a PGSERR is raised.
 */
class ser_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ser_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * erase request Setting BER bit to 1 requests a bank erase operation (user flash memory only). BER can be programmed only when LOCK is cleared to 0. If MER and SER are also set, a PGSERR is raised. Note: Write protection error is triggered when a bank erase is required and some sectors are protected.
 */
class ber_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ber_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write forcing control bit FW forces a write operation even if the write buffer is not full. In this case all bits not written are set to 1 by hardware. FW can be programmed only when LOCK is cleared to 0. The embedded flash memory resets FW when the corresponding operation has been acknowledged. Note: Using a force-write operation prevents the application from updating later the missing bits with something else than 1, because it is likely that it leads to permanent ECC error. Write forcing is effective only if the write buffer is not empty and was filled by secure access (in particular, FW does not start several write operations when the force-write operations are performed consecutively). Since there is just one write buffer, FW can force a write in bank1 or bank2.
 */
class fw_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * erase start control bit STRT bit is used to start a sector erase or a bank erase operation. STRT can be programmed only when LOCK is cleared to 0. STRT is reseted at the end of the operation or when an error occurs. It cannot be reset by software.
 */
class strt_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr strt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * sector erase selection number These bits are used to select the target sector for an erase operation (they are unused otherwise). SNB can be programmed only when LOCK is cleared to 0. ..
 */
class snb_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr snb_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_seccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * mass erase request Setting MER bit to 1 requests a mass erase operation (user flash memory only). MER can be programmed only when LOCK is cleared to 0. If BER or SER are also set, a PGSERR is raised. Error is triggered when a mass erase is required and some sectors are protected.
 */
class mer_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mer_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * end of operation interrupt control bit Setting EOPIE bit to 1 enables the generation of an interrupt at the end of a program/erase operation. EOPIE can be programmed only when LOCK is cleared to 0.
 */
class eopie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eopie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * write protection error interrupt enable bit When WRPERRIE bit is set to 1, an interrupt is generated when a protection error occurs during a program operation. WRPERRIE can be programmed only when LOCK is cleared to 0.
 */
class wrperrie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wrperrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * programming sequence error interrupt enable bit When PGSERRIE bit is set to 1, an interrupt is generated when a sequence error occurs during a program operation. PGSERRIE can be programmed only when LOCK is cleared to 0.
 */
class pgserrie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pgserrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * strobe error interrupt enable bit When STRBERRIE bit is set to 1, an interrupt is generated when a strobe error occurs (the master programs several times the same byte in the write buffer) during a write operation. STRBERRIE can be programmed only when LOCK is cleared to 0.
 */
class strberrie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr strberrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * inconsistency error interrupt enable bit When INCERRIE bit is set to 1, an interrupt is generated when an inconsistency error occurs during a write operation. INCERRIE can be programmed only when LOCK is cleared to 0.
 */
class incerrie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr incerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK general error interrupt enable bit OBKERRIE enables generating an interrupt in case of OBK specific access error. OBKERRIE can be programmed only when LOCK is cleared to 0.
 */
class obkerrie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK write error interrupt enable bit OBKWERRIE enables generation of interrupt in case of OBK specific write error. OBKWERRIE can be programmed only when LOCK is cleared to 0.
 */
class obkwerrie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obkwerrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Flash memory security state invert. This bit inverts the flash memory security state.
 */
class inv_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr inv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * bank selector bit BKSEL can only be programmed when LOCK is cleared to 0. The bit selects physical bank, SWAP_BANK setting is ignored.
 */
class bksel_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_seccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_seccr_r>() const {return opsy::utility::clear_set<flash_seccr_r>(mask, *this);}
	constexpr auto operator|(flash_seccr_r other) const -> flash_seccr_r { return static_cast<flash_seccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_seccr_r> other) const -> opsy::utility::clear_set<flash_seccr_r> {return opsy::utility::clear_set<flash_seccr_r>(flash_seccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lock() const -> lock_f {return lock_f((value_ & lock_f::mask) != 0);}
	[[nodiscard]] constexpr auto pg() const -> pg_f {return pg_f((value_ & pg_f::mask) != 0);}
	[[nodiscard]] constexpr auto ser() const -> ser_f {return ser_f((value_ & ser_f::mask) != 0);}
	[[nodiscard]] constexpr auto ber() const -> ber_f {return ber_f((value_ & ber_f::mask) != 0);}
	[[nodiscard]] constexpr auto fw() const -> fw_f {return fw_f((value_ & fw_f::mask) != 0);}
	[[nodiscard]] constexpr auto strt() const -> strt_f {return strt_f((value_ & strt_f::mask) != 0);}
	[[nodiscard]] constexpr auto snb() const -> snb_f {return snb_f(static_cast<uint8_t>(value_ >> snb_f::offset));}
	[[nodiscard]] constexpr auto mer() const -> mer_f {return mer_f((value_ & mer_f::mask) != 0);}
	[[nodiscard]] constexpr auto eopie() const -> eopie_f {return eopie_f((value_ & eopie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wrperrie() const -> wrperrie_f {return wrperrie_f((value_ & wrperrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto pgserrie() const -> pgserrie_f {return pgserrie_f((value_ & pgserrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto strberrie() const -> strberrie_f {return strberrie_f((value_ & strberrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto incerrie() const -> incerrie_f {return incerrie_f((value_ & incerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkerrie() const -> obkerrie_f {return obkerrie_f((value_ & obkerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto obkwerrie() const -> obkwerrie_f {return obkwerrie_f((value_ & obkwerrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto inv() const -> inv_f {return inv_f((value_ & inv_f::mask) != 0);}
	[[nodiscard]] constexpr auto bksel() const -> bksel_f {return bksel_f((value_ & bksel_f::mask) != 0);}

	constexpr flash_seccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_seccr_r other) const -> flash_seccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_seccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * FLASH non-secure clear control register
 */
class flash_nsccr_r {
public:

/**
 * EOP flag clear bit Setting this bit to 1 resets to 0 EOP flag in FLASH_NSSR register.
 */
class clr_eop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_eop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WRPERR flag clear bit Setting this bit to 1 resets to 0 WRPERR flag in FLASH_NSSR register.
 */
class clr_wrperr_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_wrperr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PGSERR flag clear bit Setting this bit to 1 resets to 0 PGSERR flag in FLASH_NSSR register.
 */
class clr_pgserr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_pgserr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STRBERR flag clear bit Setting this bit to 1 resets to 0 STRBERR flag in FLASH_NSSR register.
 */
class clr_strberr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_strberr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * INCERR flag clear bit Setting this bit to 1 resets to 0 INCERR flag in FLASH_NSSR register.
 */
class clr_incerr_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_incerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBKERR flag clear bit. Setting this bit to 1 resets to 0 OBKERR flag in FLASH_NSSR register.
 */
class clr_obkerr_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_obkerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBKWERR flag clear bit. Setting this bit to 1 resets to 0 OBKWERR flag in FLASH_NSSR register.
 */
class clr_obkwerr_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_obkwerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear the flag corresponding flag in FLASH_NSSR by writing this bit.
 */
class clr_optchangeerr_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_optchangeerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsccr_r>() const {return opsy::utility::clear_set<flash_nsccr_r>(mask, *this);}
	constexpr auto operator|(flash_nsccr_r other) const -> flash_nsccr_r { return static_cast<flash_nsccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsccr_r> other) const -> opsy::utility::clear_set<flash_nsccr_r> {return opsy::utility::clear_set<flash_nsccr_r>(flash_nsccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto clr_eop() const -> clr_eop_f {return clr_eop_f((value_ & clr_eop_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_wrperr() const -> clr_wrperr_f {return clr_wrperr_f((value_ & clr_wrperr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_pgserr() const -> clr_pgserr_f {return clr_pgserr_f((value_ & clr_pgserr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_strberr() const -> clr_strberr_f {return clr_strberr_f((value_ & clr_strberr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_incerr() const -> clr_incerr_f {return clr_incerr_f((value_ & clr_incerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_obkerr() const -> clr_obkerr_f {return clr_obkerr_f((value_ & clr_obkerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_obkwerr() const -> clr_obkwerr_f {return clr_obkwerr_f((value_ & clr_obkwerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_optchangeerr() const -> clr_optchangeerr_f {return clr_optchangeerr_f((value_ & clr_optchangeerr_f::mask) != 0);}

	constexpr flash_nsccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsccr_r other) const -> flash_nsccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure clear control register
 */
class flash_secccr_r {
public:

/**
 * EOP flag clear bit Setting this bit to 1 resets to 0 EOP flag in FLASH_SECSR register.
 */
class clr_eop_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_eop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WRPERR flag clear bit Setting this bit to 1 resets to 0 WRPERR flag in FLASH_SECSR register.
 */
class clr_wrperr_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_wrperr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PGSERR flag clear bit Setting this bit to 1 resets to 0 PGSERR flag in FLASH_SECSR register.
 */
class clr_pgserr_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_pgserr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STRBERR flag clear bit Setting this bit to 1 resets to 0 STRBERR flag in FLASH_SECSR register.
 */
class clr_strberr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_strberr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * INCERR flag clear bit Setting this bit to 1 resets to 0 INCERR flag in FLASH_SECSR register.
 */
class clr_incerr_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_incerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBKWERR flag clear bit Setting this bit to 1 resets to 0 OBKWERR flag in FLASH_SECSR register.
 */
class clr_obkerr_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_obkerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBKWERR flag clear bit Setting this bit to 1 resets to 0 OBKWERR flag in FLASH_SECSR register.
 */
class clr_obkwerr_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr clr_obkwerr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_secccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_secccr_r>() const {return opsy::utility::clear_set<flash_secccr_r>(mask, *this);}
	constexpr auto operator|(flash_secccr_r other) const -> flash_secccr_r { return static_cast<flash_secccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secccr_r> other) const -> opsy::utility::clear_set<flash_secccr_r> {return opsy::utility::clear_set<flash_secccr_r>(flash_secccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto clr_eop() const -> clr_eop_f {return clr_eop_f((value_ & clr_eop_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_wrperr() const -> clr_wrperr_f {return clr_wrperr_f((value_ & clr_wrperr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_pgserr() const -> clr_pgserr_f {return clr_pgserr_f((value_ & clr_pgserr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_strberr() const -> clr_strberr_f {return clr_strberr_f((value_ & clr_strberr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_incerr() const -> clr_incerr_f {return clr_incerr_f((value_ & clr_incerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_obkerr() const -> clr_obkerr_f {return clr_obkerr_f((value_ & clr_obkerr_f::mask) != 0);}
	[[nodiscard]] constexpr auto clr_obkwerr() const -> clr_obkwerr_f {return clr_obkwerr_f((value_ & clr_obkwerr_f::mask) != 0);}

	constexpr flash_secccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secccr_r other) const -> flash_secccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH privilege configuration register
 */
class flash_privcfgr_r {
public:

/**
 * privilege attribute for secure registers
 */
class spriv_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr spriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_privcfgr_r>() const {return opsy::utility::clear_set<flash_privcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_privcfgr_r other) const -> flash_privcfgr_r { return static_cast<flash_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_privcfgr_r> other) const -> opsy::utility::clear_set<flash_privcfgr_r> {return opsy::utility::clear_set<flash_privcfgr_r>(flash_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privilege attribute for non secure registers
 */
class nspriv_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nspriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_privcfgr_r>() const {return opsy::utility::clear_set<flash_privcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_privcfgr_r other) const -> flash_privcfgr_r { return static_cast<flash_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_privcfgr_r> other) const -> opsy::utility::clear_set<flash_privcfgr_r> {return opsy::utility::clear_set<flash_privcfgr_r>(flash_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto spriv() const -> spriv_f {return spriv_f((value_ & spriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto nspriv() const -> nspriv_f {return nspriv_f((value_ & nspriv_f::mask) != 0);}

	constexpr flash_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_privcfgr_r other) const -> flash_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure OBK configuration register
 */
class flash_nsobkcfgr_r {
public:

/**
 * OBKCFGR lock option configuration bit This bit locks the FLASH_NSOBKCFGR register. The correct write sequence to FLASH_NSOBKKEYR register unlocks this bit. If a wrong sequence is executed, or if the unlock sequence to FLASH_NSOBKKEYR is performed twice, this bit remains locked until the next system reset. LOCK can be set by programming it to 1. When set to 1, a new unlock sequence is mandatory to unlock it. When LOCK changes from 0 to 1, the other bits of FLASH_NSCR register do not change.
 */
class lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsobkcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsobkcfgr_r>() const {return opsy::utility::clear_set<flash_nsobkcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return static_cast<flash_nsobkcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkcfgr_r> other) const -> opsy::utility::clear_set<flash_nsobkcfgr_r> {return opsy::utility::clear_set<flash_nsobkcfgr_r>(flash_nsobkcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OBK swap sector request bit When set, all the OBKs which have not been updated in the alternate sector is copied from current sector to alternate one. The SWAP_OFFSET value must be a certain minimum value in order for the swap to be launched in OBK-HDPLdifferent 0. Minimum value is 16 for OBK-HDPL=1, 144 for OBK-HDPL=2 and192 for OBK-HDPL=3.
 */
class swap_sect_req_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swap_sect_req_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsobkcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsobkcfgr_r>() const {return opsy::utility::clear_set<flash_nsobkcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return static_cast<flash_nsobkcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkcfgr_r> other) const -> opsy::utility::clear_set<flash_nsobkcfgr_r> {return opsy::utility::clear_set<flash_nsobkcfgr_r>(flash_nsobkcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * alternate sector bit This bit must not change while filling the write buffer, otherwise an error (OBKERR) is generated
 */
class alt_sect_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alt_sect_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsobkcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsobkcfgr_r>() const {return opsy::utility::clear_set<flash_nsobkcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return static_cast<flash_nsobkcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkcfgr_r> other) const -> opsy::utility::clear_set<flash_nsobkcfgr_r> {return opsy::utility::clear_set<flash_nsobkcfgr_r>(flash_nsobkcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * alternate sector erase bit When ALT_SECT bit is set, use this bit to generate an erase command for the OBK alternate sector. It is set only by Software and cleared when the OBK swap operation is completed or an error occurs (PGSERR). It is reseted at the same time as BUSY bit.
 */
class alt_sect_erase_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr alt_sect_erase_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_nsobkcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_nsobkcfgr_r>() const {return opsy::utility::clear_set<flash_nsobkcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return static_cast<flash_nsobkcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkcfgr_r> other) const -> opsy::utility::clear_set<flash_nsobkcfgr_r> {return opsy::utility::clear_set<flash_nsobkcfgr_r>(flash_nsobkcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Key index (offset /16 bits) pointing for next swap. 0x01 means that only the first OBK data (128 bits) is copied from current to alternate OBK sector 0x02 means that the two first OBK data is copied 
 */
class swap_offset_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr swap_offset_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator flash_nsobkcfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsobkcfgr_r>() const {return opsy::utility::clear_set<flash_nsobkcfgr_r>(mask, *this);}
	constexpr auto operator|(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return static_cast<flash_nsobkcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsobkcfgr_r> other) const -> opsy::utility::clear_set<flash_nsobkcfgr_r> {return opsy::utility::clear_set<flash_nsobkcfgr_r>(flash_nsobkcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto lock() const -> lock_f {return lock_f((value_ & lock_f::mask) != 0);}
	[[nodiscard]] constexpr auto swap_sect_req() const -> swap_sect_req_f {return swap_sect_req_f((value_ & swap_sect_req_f::mask) != 0);}
	[[nodiscard]] constexpr auto alt_sect() const -> alt_sect_f {return alt_sect_f((value_ & alt_sect_f::mask) != 0);}
	[[nodiscard]] constexpr auto alt_sect_erase() const -> alt_sect_erase_f {return alt_sect_erase_f((value_ & alt_sect_erase_f::mask) != 0);}
	[[nodiscard]] constexpr auto swap_offset() const -> swap_offset_f {return swap_offset_f(static_cast<uint16_t>(value_ >> swap_offset_f::offset));}

	constexpr flash_nsobkcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsobkcfgr_r other) const -> flash_nsobkcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsobkcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111110000000000000000; // 33488896 0x1FF0000

private:
	uint32_t value_;
};

/**
 * FLASH HDP extension register
 */
class flash_hdpextr_r {
public:

/**
 * HDP area extension in 8Kbytes sectors in Bank1. Extension is added after the HDP1_END sector (included).
 */
class hdp1_ext_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdp1_ext_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdpextr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdpextr_r>() const {return opsy::utility::clear_set<flash_hdpextr_r>(mask, *this);}
	constexpr auto operator|(flash_hdpextr_r other) const -> flash_hdpextr_r { return static_cast<flash_hdpextr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdpextr_r> other) const -> opsy::utility::clear_set<flash_hdpextr_r> {return opsy::utility::clear_set<flash_hdpextr_r>(flash_hdpextr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HDP area extension in 8Kbytes sectors in bank 2. Extension is added after the HDP2_END sector (included).
 */
class hdp2_ext_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hdp2_ext_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdpextr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdpextr_r>() const {return opsy::utility::clear_set<flash_hdpextr_r>(mask, *this);}
	constexpr auto operator|(flash_hdpextr_r other) const -> flash_hdpextr_r { return static_cast<flash_hdpextr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdpextr_r> other) const -> opsy::utility::clear_set<flash_hdpextr_r> {return opsy::utility::clear_set<flash_hdpextr_r>(flash_hdpextr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdp1_ext() const -> hdp1_ext_f {return hdp1_ext_f(static_cast<uint8_t>(value_ >> hdp1_ext_f::offset));}
	[[nodiscard]] constexpr auto hdp2_ext() const -> hdp2_ext_f {return hdp2_ext_f(static_cast<uint8_t>(value_ >> hdp2_ext_f::offset));}

	constexpr flash_hdpextr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_hdpextr_r other) const -> flash_hdpextr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_hdpextr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option status register
 */
class flash_optsr_cur_r {
public:

/**
 * Brownout level option status bit These bits reflects the power level that generates a system reset. 00 or 11: BOR Level 1, the threshold level is low (around 2.1V)
 */
class bor_lev_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr bor_lev_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Brownout high enable
 */
class borh_en_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr borh_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG control mode option status bit
 */
class iwdg_sw_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr iwdg_sw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WWDG control mode option status bit
 */
class wwdg_sw_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wwdg_sw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Core domain Stop entry reset option status bit
 */
class nrst_stop_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nrst_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Core domain Standby entry reset option status bit
 */
class nrst_stdby_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nrst_stdby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Life state code (based on Hamming 8,4). More information in Section7.6.11: Product state transitions.
 */
class product_state_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr product_state_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * High-speed IO at low Vsub DD/sub voltage configuration bit. This bit can be set only with Vsub DD/sub below 2.7V.
 */
class io_vdd_hslv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr io_vdd_hslv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High-speed IO at low Vsub DDIO2/sub voltage configuration bit. This bit can be set only with Vsub DDIO2/sub below 2.7V.
 */
class io_vddio2_hslv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr io_vddio2_hslv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG Stop mode freeze option status bit When set the independent watchdog IWDG is in system Stop mode.
 */
class iwdg_stop_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iwdg_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG Standby mode freeze option status bit When set the independent watchdog IWDG is frozen in system Standby mode.
 */
class iwdg_stdby_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iwdg_stdby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Available only on cryptography enabled devices. Unique boot entry control, selects either ST or OEM iRoT for secure boot.
 */
class boot_ube_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr boot_ube_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank swapping option status bit SWAP_BANK reflects whether Bank1 and Bank2 are swapped or not. SWAP_BANK is loaded to SWAP_BANK of FLASH_OPTCR after a reset.
 */
class swap_bank_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swap_bank_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_cur_r>() const {return opsy::utility::clear_set<flash_optsr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return static_cast<flash_optsr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_cur_r> other) const -> opsy::utility::clear_set<flash_optsr_cur_r> {return opsy::utility::clear_set<flash_optsr_cur_r>(flash_optsr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bor_lev() const -> bor_lev_f {return bor_lev_f(static_cast<uint8_t>(value_ >> bor_lev_f::offset));}
	[[nodiscard]] constexpr auto borh_en() const -> borh_en_f {return borh_en_f((value_ & borh_en_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_sw() const -> iwdg_sw_f {return iwdg_sw_f((value_ & iwdg_sw_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdg_sw() const -> wwdg_sw_f {return wwdg_sw_f((value_ & wwdg_sw_f::mask) != 0);}
	[[nodiscard]] constexpr auto nrst_stop() const -> nrst_stop_f {return nrst_stop_f((value_ & nrst_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto nrst_stdby() const -> nrst_stdby_f {return nrst_stdby_f((value_ & nrst_stdby_f::mask) != 0);}
	[[nodiscard]] constexpr auto product_state() const -> product_state_f {return product_state_f(static_cast<uint8_t>(value_ >> product_state_f::offset));}
	[[nodiscard]] constexpr auto io_vdd_hslv() const -> io_vdd_hslv_f {return io_vdd_hslv_f((value_ & io_vdd_hslv_f::mask) != 0);}
	[[nodiscard]] constexpr auto io_vddio2_hslv() const -> io_vddio2_hslv_f {return io_vddio2_hslv_f((value_ & io_vddio2_hslv_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_stop() const -> iwdg_stop_f {return iwdg_stop_f((value_ & iwdg_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_stdby() const -> iwdg_stdby_f {return iwdg_stdby_f((value_ & iwdg_stdby_f::mask) != 0);}
	[[nodiscard]] constexpr auto boot_ube() const -> boot_ube_f {return boot_ube_f(static_cast<uint8_t>(value_ >> boot_ube_f::offset));}
	[[nodiscard]] constexpr auto swap_bank() const -> swap_bank_f {return swap_bank_f((value_ & swap_bank_f::mask) != 0);}

	constexpr flash_optsr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optsr_cur_r other) const -> flash_optsr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optsr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option status register
 */
class flash_optsr_prg_r {
public:

/**
 * Brownout level option configuration bit These bits reflects the power level that generates a system reset. 00 or 11: BOR Level 1, the threshold level is low (around 2.1 V)
 */
class bor_lev_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr bor_lev_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Brownout high enable configuration bit
 */
class borh_en_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr borh_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG control mode option configuration bit
 */
class iwdg_sw_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr iwdg_sw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * WWDG control mode option configuration bit
 */
class wwdg_sw_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wwdg_sw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Core domain Stop entry reset option configuration bit
 */
class nrst_stop_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nrst_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Core domain Standby entry reset option configuration bit
 */
class nrst_stdby_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nrst_stdby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Life state code (based on Hamming 8,4). More information in Section7.6.11: Product state transitions.
 */
class product_state_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr product_state_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * High-speed IO at low VDD voltage configuration bit. This bit can be set only with VDD below 2.7V.
 */
class io_vdd_hslv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr io_vdd_hslv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High-speed IO at low VDDIO2 voltage configuration bit. This bit can be set only with VDDIO2 below 2.7V.
 */
class io_vddio2_hslv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr io_vddio2_hslv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG Stop mode freeze option status bit When set the independent watchdog IWDG is in system Stop mode.
 */
class iwdg_stop_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iwdg_stop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IWDG Standby mode freeze option status bit When set the independent watchdog IWDG is frozen in system Standby mode.
 */
class iwdg_stdby_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr iwdg_stdby_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Available only on cryptography enabled devices. Unique boot entry control, selects either ST or OEM iRoT for secure boot. In Open PRODUCT_STATE this value selects bootloader. Defaut value.
 */
class boot_ube_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr boot_ube_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank swapping option configuration bit SWAP_BANK option bit is used to configure whether the Bank1 and Bank2 are swapped or not. This bit is loaded with the SWAP_BANK bit of FLASH_OPTSR_CUR register after a reset.
 */
class swap_bank_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swap_bank_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr_prg_r>() const {return opsy::utility::clear_set<flash_optsr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return static_cast<flash_optsr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr_prg_r> other) const -> opsy::utility::clear_set<flash_optsr_prg_r> {return opsy::utility::clear_set<flash_optsr_prg_r>(flash_optsr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bor_lev() const -> bor_lev_f {return bor_lev_f(static_cast<uint8_t>(value_ >> bor_lev_f::offset));}
	[[nodiscard]] constexpr auto borh_en() const -> borh_en_f {return borh_en_f((value_ & borh_en_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_sw() const -> iwdg_sw_f {return iwdg_sw_f((value_ & iwdg_sw_f::mask) != 0);}
	[[nodiscard]] constexpr auto wwdg_sw() const -> wwdg_sw_f {return wwdg_sw_f((value_ & wwdg_sw_f::mask) != 0);}
	[[nodiscard]] constexpr auto nrst_stop() const -> nrst_stop_f {return nrst_stop_f((value_ & nrst_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto nrst_stdby() const -> nrst_stdby_f {return nrst_stdby_f((value_ & nrst_stdby_f::mask) != 0);}
	[[nodiscard]] constexpr auto product_state() const -> product_state_f {return product_state_f(static_cast<uint8_t>(value_ >> product_state_f::offset));}
	[[nodiscard]] constexpr auto io_vdd_hslv() const -> io_vdd_hslv_f {return io_vdd_hslv_f((value_ & io_vdd_hslv_f::mask) != 0);}
	[[nodiscard]] constexpr auto io_vddio2_hslv() const -> io_vddio2_hslv_f {return io_vddio2_hslv_f((value_ & io_vddio2_hslv_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_stop() const -> iwdg_stop_f {return iwdg_stop_f((value_ & iwdg_stop_f::mask) != 0);}
	[[nodiscard]] constexpr auto iwdg_stdby() const -> iwdg_stdby_f {return iwdg_stdby_f((value_ & iwdg_stdby_f::mask) != 0);}
	[[nodiscard]] constexpr auto boot_ube() const -> boot_ube_f {return boot_ube_f(static_cast<uint8_t>(value_ >> boot_ube_f::offset));}
	[[nodiscard]] constexpr auto swap_bank() const -> swap_bank_f {return swap_bank_f((value_ & swap_bank_f::mask) != 0);}

	constexpr flash_optsr_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optsr_prg_r other) const -> flash_optsr_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optsr_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure EPOCH register
 */
class flash_nsepochr_cur_r {
public:

/**
 * Non-volatile non-secure EPOCH counter
 */
class ns_epoch_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ns_epoch_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_nsepochr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsepochr_cur_r>() const {return opsy::utility::clear_set<flash_nsepochr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_nsepochr_cur_r other) const -> flash_nsepochr_cur_r { return static_cast<flash_nsepochr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsepochr_cur_r> other) const -> opsy::utility::clear_set<flash_nsepochr_cur_r> {return opsy::utility::clear_set<flash_nsepochr_cur_r>(flash_nsepochr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ns_epoch() const -> ns_epoch_f {return ns_epoch_f(static_cast<uint32_t>(value_ >> ns_epoch_f::offset));}

	constexpr flash_nsepochr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsepochr_cur_r other) const -> flash_nsepochr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsepochr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure EPOCH register
 */
class flash_secepochr_cur_r {
public:

/**
 * Non-volatile secure EPOCH counter
 */
class sec_epoch_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sec_epoch_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_secepochr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secepochr_cur_r>() const {return opsy::utility::clear_set<flash_secepochr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secepochr_cur_r other) const -> flash_secepochr_cur_r { return static_cast<flash_secepochr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secepochr_cur_r> other) const -> opsy::utility::clear_set<flash_secepochr_cur_r> {return opsy::utility::clear_set<flash_secepochr_cur_r>(flash_secepochr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto sec_epoch() const -> sec_epoch_f {return sec_epoch_f(static_cast<uint32_t>(value_ >> sec_epoch_f::offset));}

	constexpr flash_secepochr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secepochr_cur_r other) const -> flash_secepochr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secepochr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option status register 2
 */
class flash_optsr2_cur_r {
public:

/**
 * SRAM1 and SRAM3 erase upon system reset
 */
class sram13_rst_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram13_rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 erase when system reset
 */
class sram2_rst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram2_rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup RAM ECC detection and correction disable
 */
class bkpram_ecc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkpram_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM3 ECC detection and correction disable
 */
class sram3_ecc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram3_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 ECC detection and correction disable
 */
class sram2_ecc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram2_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB power delivery configuration option bit
 */
class usbpd_dis_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usbpd_dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TrustZone enable configuration bits This bit enables the device is in TrustZone mode during an option byte change.
 */
class tzen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tzen_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr2_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr2_cur_r>() const {return opsy::utility::clear_set<flash_optsr2_cur_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return static_cast<flash_optsr2_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_cur_r> other) const -> opsy::utility::clear_set<flash_optsr2_cur_r> {return opsy::utility::clear_set<flash_optsr2_cur_r>(flash_optsr2_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sram13_rst() const -> sram13_rst_f {return sram13_rst_f((value_ & sram13_rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_rst() const -> sram2_rst_f {return sram2_rst_f((value_ & sram2_rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpram_ecc() const -> bkpram_ecc_f {return bkpram_ecc_f((value_ & bkpram_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3_ecc() const -> sram3_ecc_f {return sram3_ecc_f((value_ & sram3_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_ecc() const -> sram2_ecc_f {return sram2_ecc_f((value_ & sram2_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbpd_dis() const -> usbpd_dis_f {return usbpd_dis_f((value_ & usbpd_dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzen() const -> tzen_f {return tzen_f(static_cast<uint8_t>(value_ >> tzen_f::offset));}

	constexpr flash_optsr2_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optsr2_cur_r other) const -> flash_optsr2_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optsr2_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH option status register 2
 */
class flash_optsr2_prg_r {
public:

/**
 * SRAM1 and SRAM3 erase upon system reset Note: SRAM erase is triggered by option byte change operation, when enabling this feature.
 */
class sram1_3_rst_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram1_3_rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 erase when system reset Note: SRAM erase is triggered by option byte change operation, when enabling this feature.
 */
class sram2_rst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram2_rst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup RAM ECC detection and correction disable
 */
class bkpram_ecc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bkpram_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM3 ECC detection and correction disable
 */
class sram3_ecc_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram3_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SRAM2 ECC detection and correction disable
 */
class sram2_ecc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sram2_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB power delivery configuration option bit
 */
class usbpd_dis_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usbpd_dis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TrustZone enable configuration bits This bit enables the device is in TrustZone mode during an option byte change.
 */
class tzen_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tzen_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_optsr2_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_optsr2_prg_r>() const {return opsy::utility::clear_set<flash_optsr2_prg_r>(mask, *this);}
	constexpr auto operator|(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return static_cast<flash_optsr2_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_optsr2_prg_r> other) const -> opsy::utility::clear_set<flash_optsr2_prg_r> {return opsy::utility::clear_set<flash_optsr2_prg_r>(flash_optsr2_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto sram1_3_rst() const -> sram1_3_rst_f {return sram1_3_rst_f((value_ & sram1_3_rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_rst() const -> sram2_rst_f {return sram2_rst_f((value_ & sram2_rst_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpram_ecc() const -> bkpram_ecc_f {return bkpram_ecc_f((value_ & bkpram_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram3_ecc() const -> sram3_ecc_f {return sram3_ecc_f((value_ & sram3_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sram2_ecc() const -> sram2_ecc_f {return sram2_ecc_f((value_ & sram2_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto usbpd_dis() const -> usbpd_dis_f {return usbpd_dis_f((value_ & usbpd_dis_f::mask) != 0);}
	[[nodiscard]] constexpr auto tzen() const -> tzen_f {return tzen_f(static_cast<uint8_t>(value_ >> tzen_f::offset));}

	constexpr flash_optsr2_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_optsr2_prg_r other) const -> flash_optsr2_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_optsr2_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure boot register
 */
class flash_nsbootr_cur_r {
public:

/**
 * A field locking the values of SWAP_BANK, and NSBOOTADD settings.
 */
class nsboot_lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nsboot_lock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_nsbootr_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsbootr_cur_r>() const {return opsy::utility::clear_set<flash_nsbootr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_nsbootr_cur_r other) const -> flash_nsbootr_cur_r { return static_cast<flash_nsbootr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsbootr_cur_r> other) const -> opsy::utility::clear_set<flash_nsbootr_cur_r> {return opsy::utility::clear_set<flash_nsbootr_cur_r>(flash_nsbootr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Non secure unique boot entry address These bits reflect the Non secure UBE address
 */
class nsbootadd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nsbootadd_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_nsbootr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsbootr_cur_r>() const {return opsy::utility::clear_set<flash_nsbootr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_nsbootr_cur_r other) const -> flash_nsbootr_cur_r { return static_cast<flash_nsbootr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsbootr_cur_r> other) const -> opsy::utility::clear_set<flash_nsbootr_cur_r> {return opsy::utility::clear_set<flash_nsbootr_cur_r>(flash_nsbootr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto nsboot_lock() const -> nsboot_lock_f {return nsboot_lock_f(static_cast<uint8_t>(value_ >> nsboot_lock_f::offset));}
	[[nodiscard]] constexpr auto nsbootadd() const -> nsbootadd_f {return nsbootadd_f(static_cast<uint32_t>(value_ >> nsbootadd_f::offset));}

	constexpr flash_nsbootr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsbootr_cur_r other) const -> flash_nsbootr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsbootr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure boot register
 */
class flash_nsbootr_prg_r {
public:

/**
 * A field locking the values of SWAP_ BANK, and NSBOOTADD settings.
 */
class nsboot_lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nsboot_lock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_nsbootr_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsbootr_prg_r>() const {return opsy::utility::clear_set<flash_nsbootr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_nsbootr_prg_r other) const -> flash_nsbootr_prg_r { return static_cast<flash_nsbootr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsbootr_prg_r> other) const -> opsy::utility::clear_set<flash_nsbootr_prg_r> {return opsy::utility::clear_set<flash_nsbootr_prg_r>(flash_nsbootr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Non secure unique boot entry address These bits allow configuring the Non secure BOOT address
 */
class nsbootadd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nsbootadd_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_nsbootr_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_nsbootr_prg_r>() const {return opsy::utility::clear_set<flash_nsbootr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_nsbootr_prg_r other) const -> flash_nsbootr_prg_r { return static_cast<flash_nsbootr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_nsbootr_prg_r> other) const -> opsy::utility::clear_set<flash_nsbootr_prg_r> {return opsy::utility::clear_set<flash_nsbootr_prg_r>(flash_nsbootr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto nsboot_lock() const -> nsboot_lock_f {return nsboot_lock_f(static_cast<uint8_t>(value_ >> nsboot_lock_f::offset));}
	[[nodiscard]] constexpr auto nsbootadd() const -> nsbootadd_f {return nsbootadd_f(static_cast<uint32_t>(value_ >> nsbootadd_f::offset));}

	constexpr flash_nsbootr_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_nsbootr_prg_r other) const -> flash_nsbootr_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_nsbootr_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure boot register
 */
class flash_secbootr_cur_r {
public:

/**
 * A field locking the values of UBE, SWAP_BANK, and SECBOOTADD settings.
 */
class secboot_lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secboot_lock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secbootr_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secbootr_cur_r>() const {return opsy::utility::clear_set<flash_secbootr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secbootr_cur_r other) const -> flash_secbootr_cur_r { return static_cast<flash_secbootr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secbootr_cur_r> other) const -> opsy::utility::clear_set<flash_secbootr_cur_r> {return opsy::utility::clear_set<flash_secbootr_cur_r>(flash_secbootr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Unique boot entry secure address These bits reflect the Secure UBE address
 */
class secbootadd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secbootadd_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_secbootr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secbootr_cur_r>() const {return opsy::utility::clear_set<flash_secbootr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secbootr_cur_r other) const -> flash_secbootr_cur_r { return static_cast<flash_secbootr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secbootr_cur_r> other) const -> opsy::utility::clear_set<flash_secbootr_cur_r> {return opsy::utility::clear_set<flash_secbootr_cur_r>(flash_secbootr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto secboot_lock() const -> secboot_lock_f {return secboot_lock_f(static_cast<uint8_t>(value_ >> secboot_lock_f::offset));}
	[[nodiscard]] constexpr auto secbootadd() const -> secbootadd_f {return secbootadd_f(static_cast<uint32_t>(value_ >> secbootadd_f::offset));}

	constexpr flash_secbootr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secbootr_cur_r other) const -> flash_secbootr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secbootr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure boot register
 */
class flash_bootr_prg_r {
public:

/**
 * A field locking the values of UBE, SWAP_ BANK, and SECBOOTADD setting.
 */
class secboot_lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secboot_lock_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_bootr_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_bootr_prg_r>() const {return opsy::utility::clear_set<flash_bootr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_bootr_prg_r other) const -> flash_bootr_prg_r { return static_cast<flash_bootr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_bootr_prg_r> other) const -> opsy::utility::clear_set<flash_bootr_prg_r> {return opsy::utility::clear_set<flash_bootr_prg_r>(flash_bootr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Secure unique boot entry address. These bits allow configuring the secure UBE address.
 */
class secbootadd_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 24;
	static constexpr uint32_t range = static_cast<uint32_t>(0b111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secbootadd_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_bootr_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_bootr_prg_r>() const {return opsy::utility::clear_set<flash_bootr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_bootr_prg_r other) const -> flash_bootr_prg_r { return static_cast<flash_bootr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_bootr_prg_r> other) const -> opsy::utility::clear_set<flash_bootr_prg_r> {return opsy::utility::clear_set<flash_bootr_prg_r>(flash_bootr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto secboot_lock() const -> secboot_lock_f {return secboot_lock_f(static_cast<uint8_t>(value_ >> secboot_lock_f::offset));}
	[[nodiscard]] constexpr auto secbootadd() const -> secbootadd_f {return secbootadd_f(static_cast<uint32_t>(value_ >> secbootadd_f::offset));}

	constexpr flash_bootr_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_bootr_prg_r other) const -> flash_bootr_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_bootr_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure OTP block lock
 */
class flash_otpblr_cur_r {
public:

/**
 * OTP block lock Block n corresponds to OTP 16-bit word 32 x n to 32 x n + 31. LOCKBL[n] = 1 indicates that all OTP 16-bit words in OTP Block n are locked and attempt to program them results in WRPERR. LOCKBL[n] = 0 indicates that all OTP 16-bit words in OTP Block n are not locked. When one block is locked, it's not possible to remove the write protection. Also if not locked, it is not possible to erase OTP words.
 */
class lockbl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lockbl_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_otpblr_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_otpblr_cur_r>() const {return opsy::utility::clear_set<flash_otpblr_cur_r>(mask, *this);}
	constexpr auto operator|(flash_otpblr_cur_r other) const -> flash_otpblr_cur_r { return static_cast<flash_otpblr_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_otpblr_cur_r> other) const -> opsy::utility::clear_set<flash_otpblr_cur_r> {return opsy::utility::clear_set<flash_otpblr_cur_r>(flash_otpblr_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto lockbl() const -> lockbl_f {return lockbl_f(static_cast<uint32_t>(value_ >> lockbl_f::offset));}

	constexpr flash_otpblr_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_otpblr_cur_r other) const -> flash_otpblr_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_otpblr_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH non-secure OTP block lock
 */
class flash_otpblr_prg_r {
public:

/**
 * OTP block lock Block n corresponds to OTP 16-bit word 32 x n to 32 x n + 31. LOCKBL[n] = 1 indicates that all OTP 16-bit words in OTP Block n are locked and attempt to program them results in WRPERR. LOCKBL[n] = 0 indicates that all OTP 16-bit words in OTP Block n are not locked. When one block is locked, it is not possible to remove the write protection. LOCKBL bits can be set if the corresponding bit in FLASH_OTPBLR_CUR is cleared.
 */
class lockbl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lockbl_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_otpblr_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_otpblr_prg_r>() const {return opsy::utility::clear_set<flash_otpblr_prg_r>(mask, *this);}
	constexpr auto operator|(flash_otpblr_prg_r other) const -> flash_otpblr_prg_r { return static_cast<flash_otpblr_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_otpblr_prg_r> other) const -> opsy::utility::clear_set<flash_otpblr_prg_r> {return opsy::utility::clear_set<flash_otpblr_prg_r>(flash_otpblr_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto lockbl() const -> lockbl_f {return lockbl_f(static_cast<uint32_t>(value_ >> lockbl_f::offset));}

	constexpr flash_otpblr_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_otpblr_prg_r other) const -> flash_otpblr_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_otpblr_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure block based register for Bank 1
 */
class flash_secbb1rx_r {
public:

/**
 * Secure/non-secure 8Kbytes flash Bank 1 sector attributes
 */
class secbb1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secbb1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_secbb1rx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secbb1rx_r>() const {return opsy::utility::clear_set<flash_secbb1rx_r>(mask, *this);}
	constexpr auto operator|(flash_secbb1rx_r other) const -> flash_secbb1rx_r { return static_cast<flash_secbb1rx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secbb1rx_r> other) const -> opsy::utility::clear_set<flash_secbb1rx_r> {return opsy::utility::clear_set<flash_secbb1rx_r>(flash_secbb1rx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto secbb1() const -> secbb1_f {return secbb1_f(static_cast<uint32_t>(value_ >> secbb1_f::offset));}

	constexpr flash_secbb1rx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secbb1rx_r other) const -> flash_secbb1rx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secbb1rx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH privilege block based register for Bank 1
 */
class flash_privbb1rx_r {
public:

/**
 * Privileged/unprivileged 8-Kbyte flash Bank 1 sector attribute
 */
class privbb1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr privbb1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_privbb1rx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_privbb1rx_r>() const {return opsy::utility::clear_set<flash_privbb1rx_r>(mask, *this);}
	constexpr auto operator|(flash_privbb1rx_r other) const -> flash_privbb1rx_r { return static_cast<flash_privbb1rx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_privbb1rx_r> other) const -> opsy::utility::clear_set<flash_privbb1rx_r> {return opsy::utility::clear_set<flash_privbb1rx_r>(flash_privbb1rx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto privbb1() const -> privbb1_f {return privbb1_f(static_cast<uint32_t>(value_ >> privbb1_f::offset));}

	constexpr flash_privbb1rx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_privbb1rx_r other) const -> flash_privbb1rx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_privbb1rx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH security watermark for Bank 1
 */
class flash_secwm1r_cur_r {
public:

/**
 * Bank1 security WM area 1 start sector
 */
class secwm1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secwm1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm1r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm1r_cur_r>() const {return opsy::utility::clear_set<flash_secwm1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secwm1r_cur_r other) const -> flash_secwm1r_cur_r { return static_cast<flash_secwm1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm1r_cur_r> other) const -> opsy::utility::clear_set<flash_secwm1r_cur_r> {return opsy::utility::clear_set<flash_secwm1r_cur_r>(flash_secwm1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank1 security WM area 1 end sector
 */
class secwm1_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secwm1_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm1r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm1r_cur_r>() const {return opsy::utility::clear_set<flash_secwm1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secwm1r_cur_r other) const -> flash_secwm1r_cur_r { return static_cast<flash_secwm1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm1r_cur_r> other) const -> opsy::utility::clear_set<flash_secwm1r_cur_r> {return opsy::utility::clear_set<flash_secwm1r_cur_r>(flash_secwm1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto secwm1_strt() const -> secwm1_strt_f {return secwm1_strt_f(static_cast<uint8_t>(value_ >> secwm1_strt_f::offset));}
	[[nodiscard]] constexpr auto secwm1_end() const -> secwm1_end_f {return secwm1_end_f(static_cast<uint8_t>(value_ >> secwm1_end_f::offset));}

	constexpr flash_secwm1r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secwm1r_cur_r other) const -> flash_secwm1r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secwm1r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH security watermark for Bank 1
 */
class flash_secwm1r_prg_r {
public:

/**
 * Bank1 security WM area 1 start sector
 */
class secwm1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secwm1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm1r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm1r_prg_r>() const {return opsy::utility::clear_set<flash_secwm1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_secwm1r_prg_r other) const -> flash_secwm1r_prg_r { return static_cast<flash_secwm1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm1r_prg_r> other) const -> opsy::utility::clear_set<flash_secwm1r_prg_r> {return opsy::utility::clear_set<flash_secwm1r_prg_r>(flash_secwm1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank1 security WM area 1 end sector
 */
class secwm1_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secwm1_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm1r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm1r_prg_r>() const {return opsy::utility::clear_set<flash_secwm1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_secwm1r_prg_r other) const -> flash_secwm1r_prg_r { return static_cast<flash_secwm1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm1r_prg_r> other) const -> opsy::utility::clear_set<flash_secwm1r_prg_r> {return opsy::utility::clear_set<flash_secwm1r_prg_r>(flash_secwm1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto secwm1_strt() const -> secwm1_strt_f {return secwm1_strt_f(static_cast<uint8_t>(value_ >> secwm1_strt_f::offset));}
	[[nodiscard]] constexpr auto secwm1_end() const -> secwm1_end_f {return secwm1_end_f(static_cast<uint8_t>(value_ >> secwm1_end_f::offset));}

	constexpr flash_secwm1r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secwm1r_prg_r other) const -> flash_secwm1r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secwm1r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH write sector group protection for Bank 1
 */
class flash_wrp1r_cur_r {
public:

/**
 * Bank 1 sector group protection option status byte Each FLASH_WRP1R_CUR bit reflects the write protection status of the corresponding group of four consecutive sectors in bank 1 (0: the group is write protected; 1: the group is not write protected) Bit 0: Group embedding sectors 0 to 3 Bit 1: Group embedding sectors 4 to 7 Bit N: Group embedding sectors 4 x N to 4 x N + 3 Bit 31: Group embedding sectors 124 to 127
 */
class wrpsg1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrpsg1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_wrp1r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_wrp1r_cur_r>() const {return opsy::utility::clear_set<flash_wrp1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_wrp1r_cur_r other) const -> flash_wrp1r_cur_r { return static_cast<flash_wrp1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_wrp1r_cur_r> other) const -> opsy::utility::clear_set<flash_wrp1r_cur_r> {return opsy::utility::clear_set<flash_wrp1r_cur_r>(flash_wrp1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto wrpsg1() const -> wrpsg1_f {return wrpsg1_f(static_cast<uint32_t>(value_ >> wrpsg1_f::offset));}

	constexpr flash_wrp1r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_wrp1r_cur_r other) const -> flash_wrp1r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_wrp1r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH write sector group protection for Bank 1
 */
class flash_wrp1r_prg_r {
public:

/**
 * Bank1 sector group protection option status byte Setting WRPSG1 bits to 0 write protects the corresponding group of four consecutive sectors in bank 1 (0: the group is write protected; 1: the group is not write protected) Bit 0: Group embedding sectors 0 to 3 Bit 1: Group embedding sectors 4 to 7 Bit N: Group embedding sectors 4 x N to 4 x N + 3 Bit 31: Group embedding sectors 124 to 127
 */
class wrpsg1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrpsg1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_wrp1r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_wrp1r_prg_r>() const {return opsy::utility::clear_set<flash_wrp1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_wrp1r_prg_r other) const -> flash_wrp1r_prg_r { return static_cast<flash_wrp1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_wrp1r_prg_r> other) const -> opsy::utility::clear_set<flash_wrp1r_prg_r> {return opsy::utility::clear_set<flash_wrp1r_prg_r>(flash_wrp1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto wrpsg1() const -> wrpsg1_f {return wrpsg1_f(static_cast<uint32_t>(value_ >> wrpsg1_f::offset));}

	constexpr flash_wrp1r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_wrp1r_prg_r other) const -> flash_wrp1r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_wrp1r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH data sector configuration Bank 1
 */
class flash_edata1r_cur_r {
public:

/**
 * EDATA1_STRT contains the start sectors of the flash high-cycle data area in Bank1 There is no hardware effect to those bits. They shall be managed by ST tools in Flasher. ...
 */
class edata1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr edata1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_edata1r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_edata1r_cur_r>() const {return opsy::utility::clear_set<flash_edata1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_edata1r_cur_r other) const -> flash_edata1r_cur_r { return static_cast<flash_edata1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata1r_cur_r> other) const -> opsy::utility::clear_set<flash_edata1r_cur_r> {return opsy::utility::clear_set<flash_edata1r_cur_r>(flash_edata1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank1 flash high-cycle data enable
 */
class edata1_en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr edata1_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_edata1r_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_edata1r_cur_r>() const {return opsy::utility::clear_set<flash_edata1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_edata1r_cur_r other) const -> flash_edata1r_cur_r { return static_cast<flash_edata1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata1r_cur_r> other) const -> opsy::utility::clear_set<flash_edata1r_cur_r> {return opsy::utility::clear_set<flash_edata1r_cur_r>(flash_edata1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto edata1_strt() const -> edata1_strt_f {return edata1_strt_f(static_cast<uint8_t>(value_ >> edata1_strt_f::offset));}
	[[nodiscard]] constexpr auto edata1_en() const -> edata1_en_f {return edata1_en_f((value_ & edata1_en_f::mask) != 0);}

	constexpr flash_edata1r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_edata1r_cur_r other) const -> flash_edata1r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_edata1r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH data sector configuration Bank 1
 */
class flash_edata1r_prg_r {
public:

/**
 * EDATA1_STRT contains the start sectors of the flash high-cycle data area in Bank 1 There is no hardware effect to those bits. They shall be managed by ST tools in Flasher. ... Note: 111: The eight last sectors of the Bank 1 are reserved for flash high-cycle data
 */
class edata1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr edata1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_edata1r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_edata1r_prg_r>() const {return opsy::utility::clear_set<flash_edata1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_edata1r_prg_r other) const -> flash_edata1r_prg_r { return static_cast<flash_edata1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata1r_prg_r> other) const -> opsy::utility::clear_set<flash_edata1r_prg_r> {return opsy::utility::clear_set<flash_edata1r_prg_r>(flash_edata1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank 1 flash high-cycle data enable
 */
class edata1_en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr edata1_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_edata1r_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_edata1r_prg_r>() const {return opsy::utility::clear_set<flash_edata1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_edata1r_prg_r other) const -> flash_edata1r_prg_r { return static_cast<flash_edata1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata1r_prg_r> other) const -> opsy::utility::clear_set<flash_edata1r_prg_r> {return opsy::utility::clear_set<flash_edata1r_prg_r>(flash_edata1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto edata1_strt() const -> edata1_strt_f {return edata1_strt_f(static_cast<uint8_t>(value_ >> edata1_strt_f::offset));}
	[[nodiscard]] constexpr auto edata1_en() const -> edata1_en_f {return edata1_en_f((value_ & edata1_en_f::mask) != 0);}

	constexpr flash_edata1r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_edata1r_prg_r other) const -> flash_edata1r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_edata1r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH HDP Bank 1 configuration
 */
class flash_hdp1r_cur_r {
public:

/**
 * HDPL barrier start set in number of 8-Kbyte sectors
 */
class hdp1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdp1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp1r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp1r_cur_r>() const {return opsy::utility::clear_set<flash_hdp1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_hdp1r_cur_r other) const -> flash_hdp1r_cur_r { return static_cast<flash_hdp1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp1r_cur_r> other) const -> opsy::utility::clear_set<flash_hdp1r_cur_r> {return opsy::utility::clear_set<flash_hdp1r_cur_r>(flash_hdp1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HDPL barrier end set in number of 8-Kbyte sectors
 */
class hdp1_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hdp1_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp1r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp1r_cur_r>() const {return opsy::utility::clear_set<flash_hdp1r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_hdp1r_cur_r other) const -> flash_hdp1r_cur_r { return static_cast<flash_hdp1r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp1r_cur_r> other) const -> opsy::utility::clear_set<flash_hdp1r_cur_r> {return opsy::utility::clear_set<flash_hdp1r_cur_r>(flash_hdp1r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdp1_strt() const -> hdp1_strt_f {return hdp1_strt_f(static_cast<uint8_t>(value_ >> hdp1_strt_f::offset));}
	[[nodiscard]] constexpr auto hdp1_end() const -> hdp1_end_f {return hdp1_end_f(static_cast<uint8_t>(value_ >> hdp1_end_f::offset));}

	constexpr flash_hdp1r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_hdp1r_cur_r other) const -> flash_hdp1r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_hdp1r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH HDP Bank 1 configuration
 */
class flash_hdp1r_prg_r {
public:

/**
 * HDPL barrier start set in number of 8-Kbyte sectors
 */
class hdp1_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdp1_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp1r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp1r_prg_r>() const {return opsy::utility::clear_set<flash_hdp1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_hdp1r_prg_r other) const -> flash_hdp1r_prg_r { return static_cast<flash_hdp1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp1r_prg_r> other) const -> opsy::utility::clear_set<flash_hdp1r_prg_r> {return opsy::utility::clear_set<flash_hdp1r_prg_r>(flash_hdp1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HDPL barrier end set in number of 8-Kbyte sectors
 */
class hdp1_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hdp1_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp1r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp1r_prg_r>() const {return opsy::utility::clear_set<flash_hdp1r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_hdp1r_prg_r other) const -> flash_hdp1r_prg_r { return static_cast<flash_hdp1r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp1r_prg_r> other) const -> opsy::utility::clear_set<flash_hdp1r_prg_r> {return opsy::utility::clear_set<flash_hdp1r_prg_r>(flash_hdp1r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdp1_strt() const -> hdp1_strt_f {return hdp1_strt_f(static_cast<uint8_t>(value_ >> hdp1_strt_f::offset));}
	[[nodiscard]] constexpr auto hdp1_end() const -> hdp1_end_f {return hdp1_end_f(static_cast<uint8_t>(value_ >> hdp1_end_f::offset));}

	constexpr flash_hdp1r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_hdp1r_prg_r other) const -> flash_hdp1r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_hdp1r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH ECC correction register
 */
class flash_ecccorr_r {
public:

/**
 * ECC error address When an ECC error occurs (for single correction) during a read operation, the ADDR_ECC contains the address that generated the error. ADDR_ECC is reset when the flag error is reset. The flash interface programs the address in this register only when no ECC error flags are set. This means that only the first address that generated an ECC error is saved. The address in ADDR_ECC is relative to the flash memory area where the error occurred (user flash memory, system flash memory, data area, read-only/OTP area).
 */
class addr_ecc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addr_ecc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Single ECC error corrected in flash OB Keys storage area. It indicates the OBK storage concerned by ECC error.
 */
class obk_ecc_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obk_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail for corrected ECC error in flash high-cycle data area It indicates if flash high-cycle data area is concerned by ECC error.
 */
class edata_ecc_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr edata_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail bank for corrected ECC error It indicates which bank is concerned by ECC error
 */
class bk_ecc_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail for corrected ECC error in system flash memory It indicates if system flash memory is concerned by ECC error.
 */
class sysf_ecc_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sysf_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OTP ECC error bit This bit is set to 1 when one single ECC correction occurred during the last successful read operation from the read-only/ OTP area. The address of the ECC error is available in ADDR_ECC bitfield.
 */
class otp_ecc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr otp_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC single correction error interrupt enable bit When ECCCIE bit is set to 1, an interrupt is generated when an ECC single correction error occurs during a read operation.
 */
class ecccie_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ecccie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC correction set by hardware when single ECC error has been detected and corrected. Cleared by writing 1.
 */
class eccc_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eccc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_ecccorr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_ecccorr_r>() const {return opsy::utility::clear_set<flash_ecccorr_r>(mask, *this);}
	constexpr auto operator|(flash_ecccorr_r other) const -> flash_ecccorr_r { return static_cast<flash_ecccorr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_ecccorr_r> other) const -> opsy::utility::clear_set<flash_ecccorr_r> {return opsy::utility::clear_set<flash_ecccorr_r>(flash_ecccorr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addr_ecc() const -> addr_ecc_f {return addr_ecc_f(static_cast<uint16_t>(value_ >> addr_ecc_f::offset));}
	[[nodiscard]] constexpr auto obk_ecc() const -> obk_ecc_f {return obk_ecc_f((value_ & obk_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto edata_ecc() const -> edata_ecc_f {return edata_ecc_f((value_ & edata_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk_ecc() const -> bk_ecc_f {return bk_ecc_f((value_ & bk_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sysf_ecc() const -> sysf_ecc_f {return sysf_ecc_f((value_ & sysf_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto otp_ecc() const -> otp_ecc_f {return otp_ecc_f((value_ & otp_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ecccie() const -> ecccie_f {return ecccie_f((value_ & ecccie_f::mask) != 0);}
	[[nodiscard]] constexpr auto eccc() const -> eccc_f {return eccc_f((value_ & eccc_f::mask) != 0);}

	constexpr flash_ecccorr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_ecccorr_r other) const -> flash_ecccorr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_ecccorr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH ECC detection register
 */
class flash_eccdetr_r {
public:

/**
 * ECC error address When an ECC error occurs (double detection) during a read operation, the ADDR_ECC contains the address that generated the error. ADDR_ECC is reset when the flag error is reset. The flash interface programs the address in this register only when no ECC error flags are set. This means that only the first address that generated an double ECC error is saved. The address in ADDR_ECC is relative to the flash memory area where the error occurred (user flash memory, system flash memory, data area, read-only/OTP area).
 */
class addr_ecc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addr_ecc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * ECC fail double ECC error in flash OB Keys storage area. It indicates the OBK storage concerned by ECC error.
 */
class obk_ecc_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr obk_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail double ECC error in flash high-cycle data area It indicates if flash high-cycle data area is concerned by ECC error.
 */
class edata_ecc_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr edata_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail bank for double ECC error It indicates which bank is concerned by ECC error
 */
class bk_ecc_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bk_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC fail for double ECC error in system flash memory It indicates if system flash memory is concerned by ECC error.
 */
class sysf_ecc_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sysf_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * OTP ECC error bit This bit is set to 1 when double ECC detection occurred during the last read operation from the read-only/ OTP area. The address of the ECC error is available in ADDR_ECC bitfield.
 */
class otp_ecc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr otp_ecc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC detection Set by hardware when two ECC error has been detected. When this bit is set, a NMI is generated. Cleared by writing 1. Needs to be cleared in order to detect subsequent double ECC errors.
 */
class eccd_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr eccd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_eccdetr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_eccdetr_r>() const {return opsy::utility::clear_set<flash_eccdetr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdetr_r other) const -> flash_eccdetr_r { return static_cast<flash_eccdetr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdetr_r> other) const -> opsy::utility::clear_set<flash_eccdetr_r> {return opsy::utility::clear_set<flash_eccdetr_r>(flash_eccdetr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addr_ecc() const -> addr_ecc_f {return addr_ecc_f(static_cast<uint16_t>(value_ >> addr_ecc_f::offset));}
	[[nodiscard]] constexpr auto obk_ecc() const -> obk_ecc_f {return obk_ecc_f((value_ & obk_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto edata_ecc() const -> edata_ecc_f {return edata_ecc_f((value_ & edata_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto bk_ecc() const -> bk_ecc_f {return bk_ecc_f((value_ & bk_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sysf_ecc() const -> sysf_ecc_f {return sysf_ecc_f((value_ & sysf_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto otp_ecc() const -> otp_ecc_f {return otp_ecc_f((value_ & otp_ecc_f::mask) != 0);}
	[[nodiscard]] constexpr auto eccd() const -> eccd_f {return eccd_f((value_ & eccd_f::mask) != 0);}

	constexpr flash_eccdetr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_eccdetr_r other) const -> flash_eccdetr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_eccdetr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH ECC data
 */
class flash_eccdr_r {
public:

/**
 * ECC error data When an double detection ECC error occurs on special areas with 6-bit ECC on 16-bit data (data area, read-only/OTP area), the failing data is read to this register. By checking if it is possible to determine whether the failure was on a real data, or due to access to uninitialized memory.
 */
class data_ecc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr data_ecc_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator flash_eccdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_eccdr_r>() const {return opsy::utility::clear_set<flash_eccdr_r>(mask, *this);}
	constexpr auto operator|(flash_eccdr_r other) const -> flash_eccdr_r { return static_cast<flash_eccdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_eccdr_r> other) const -> opsy::utility::clear_set<flash_eccdr_r> {return opsy::utility::clear_set<flash_eccdr_r>(flash_eccdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto data_ecc() const -> data_ecc_f {return data_ecc_f(static_cast<uint16_t>(value_ >> data_ecc_f::offset));}

	constexpr flash_eccdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_eccdr_r other) const -> flash_eccdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_eccdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH secure block-based register for Bank 2
 */
class flash_secbb2rx_r {
public:

/**
 * Secure/non-secure flash Bank 2 sector attribute
 */
class secbb2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secbb2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_secbb2rx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secbb2rx_r>() const {return opsy::utility::clear_set<flash_secbb2rx_r>(mask, *this);}
	constexpr auto operator|(flash_secbb2rx_r other) const -> flash_secbb2rx_r { return static_cast<flash_secbb2rx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secbb2rx_r> other) const -> opsy::utility::clear_set<flash_secbb2rx_r> {return opsy::utility::clear_set<flash_secbb2rx_r>(flash_secbb2rx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto secbb2() const -> secbb2_f {return secbb2_f(static_cast<uint32_t>(value_ >> secbb2_f::offset));}

	constexpr flash_secbb2rx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secbb2rx_r other) const -> flash_secbb2rx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secbb2rx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH privilege block-based register for Bank 2
 */
class flash_privbb2rx_r {
public:

/**
 * Privileged / non-privileged 8-Kbyte flash Bank 2 sector attribute
 */
class privbb2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr privbb2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_privbb2rx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_privbb2rx_r>() const {return opsy::utility::clear_set<flash_privbb2rx_r>(mask, *this);}
	constexpr auto operator|(flash_privbb2rx_r other) const -> flash_privbb2rx_r { return static_cast<flash_privbb2rx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_privbb2rx_r> other) const -> opsy::utility::clear_set<flash_privbb2rx_r> {return opsy::utility::clear_set<flash_privbb2rx_r>(flash_privbb2rx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto privbb2() const -> privbb2_f {return privbb2_f(static_cast<uint32_t>(value_ >> privbb2_f::offset));}

	constexpr flash_privbb2rx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_privbb2rx_r other) const -> flash_privbb2rx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_privbb2rx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH security watermark for Bank 2
 */
class flash_secwm2r_cur_r {
public:

/**
 * Bank2 security WM area start sector
 */
class secwm_strt2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secwm_strt2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm2r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm2r_cur_r>() const {return opsy::utility::clear_set<flash_secwm2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secwm2r_cur_r other) const -> flash_secwm2r_cur_r { return static_cast<flash_secwm2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm2r_cur_r> other) const -> opsy::utility::clear_set<flash_secwm2r_cur_r> {return opsy::utility::clear_set<flash_secwm2r_cur_r>(flash_secwm2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank2 security WM end sector
 */
class secwm_end2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secwm_end2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm2r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm2r_cur_r>() const {return opsy::utility::clear_set<flash_secwm2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_secwm2r_cur_r other) const -> flash_secwm2r_cur_r { return static_cast<flash_secwm2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm2r_cur_r> other) const -> opsy::utility::clear_set<flash_secwm2r_cur_r> {return opsy::utility::clear_set<flash_secwm2r_cur_r>(flash_secwm2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto secwm_strt2() const -> secwm_strt2_f {return secwm_strt2_f(static_cast<uint8_t>(value_ >> secwm_strt2_f::offset));}
	[[nodiscard]] constexpr auto secwm_end2() const -> secwm_end2_f {return secwm_end2_f(static_cast<uint8_t>(value_ >> secwm_end2_f::offset));}

	constexpr flash_secwm2r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secwm2r_cur_r other) const -> flash_secwm2r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secwm2r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH security watermark for Bank 2
 */
class flash_secwm2r_prg_r {
public:

/**
 * Bank 2 security WM area start sector
 */
class secwm_strt2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr secwm_strt2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm2r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm2r_prg_r>() const {return opsy::utility::clear_set<flash_secwm2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_secwm2r_prg_r other) const -> flash_secwm2r_prg_r { return static_cast<flash_secwm2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm2r_prg_r> other) const -> opsy::utility::clear_set<flash_secwm2r_prg_r> {return opsy::utility::clear_set<flash_secwm2r_prg_r>(flash_secwm2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank 2 security WM area end sector
 */
class secwm_end2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr secwm_end2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_secwm2r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_secwm2r_prg_r>() const {return opsy::utility::clear_set<flash_secwm2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_secwm2r_prg_r other) const -> flash_secwm2r_prg_r { return static_cast<flash_secwm2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_secwm2r_prg_r> other) const -> opsy::utility::clear_set<flash_secwm2r_prg_r> {return opsy::utility::clear_set<flash_secwm2r_prg_r>(flash_secwm2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto secwm_strt2() const -> secwm_strt2_f {return secwm_strt2_f(static_cast<uint8_t>(value_ >> secwm_strt2_f::offset));}
	[[nodiscard]] constexpr auto secwm_end2() const -> secwm_end2_f {return secwm_end2_f(static_cast<uint8_t>(value_ >> secwm_end2_f::offset));}

	constexpr flash_secwm2r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_secwm2r_prg_r other) const -> flash_secwm2r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_secwm2r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH write sector group protection for Bank 2
 */
class flash_wrp2r_cur_r {
public:

/**
 * Bank2 sector group protection option status byte Each FLASH_WRP2R_CUR bit reflects the write protection status of the corresponding group of 4 consecutive sectors in bank 2 (0: group is write protected; 1: group is not write protected) Bit 0: Group embedding sectors 0 to 3 Bit 1: Group embedding sectors 4 to 7 Bit N: Group embedding sectors 4 x N to 4 x N + 3 Bit 31: Group embedding sectors 124 to 127
 */
class wrpsg2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrpsg2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_wrp2r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_wrp2r_cur_r>() const {return opsy::utility::clear_set<flash_wrp2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_wrp2r_cur_r other) const -> flash_wrp2r_cur_r { return static_cast<flash_wrp2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_wrp2r_cur_r> other) const -> opsy::utility::clear_set<flash_wrp2r_cur_r> {return opsy::utility::clear_set<flash_wrp2r_cur_r>(flash_wrp2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto wrpsg2() const -> wrpsg2_f {return wrpsg2_f(static_cast<uint32_t>(value_ >> wrpsg2_f::offset));}

	constexpr flash_wrp2r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_wrp2r_cur_r other) const -> flash_wrp2r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_wrp2r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH write sector group protection for Bank 2
 */
class flash_wrp2r_prg_r {
public:

/**
 * Bank 2 sector group protection option status byte Setting WRPSGn2 bits to 0 write protects the corresponding group of four consecutive sectors in Bank 2 (0: group is write protected; 1: group is not write protected) Bit 0: Group embedding sectors 0 to 3 Bit 1: Group embedding sectors 4 to 7 Bit N: Group embedding sectors 4 x N to 4 x N + 3 Bit 31: Group embedding sectors 124 to 127
 */
class wrpsg2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrpsg2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator flash_wrp2r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_wrp2r_prg_r>() const {return opsy::utility::clear_set<flash_wrp2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_wrp2r_prg_r other) const -> flash_wrp2r_prg_r { return static_cast<flash_wrp2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_wrp2r_prg_r> other) const -> opsy::utility::clear_set<flash_wrp2r_prg_r> {return opsy::utility::clear_set<flash_wrp2r_prg_r>(flash_wrp2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto wrpsg2() const -> wrpsg2_f {return wrpsg2_f(static_cast<uint32_t>(value_ >> wrpsg2_f::offset));}

	constexpr flash_wrp2r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_wrp2r_prg_r other) const -> flash_wrp2r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_wrp2r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH data sectors configuration Bank 2
 */
class flash_edata2r_cur_r {
public:

/**
 * EDATA2_STRT contains the start sectors of the flash high-cycle data area in Bank 2 There is no hardware effect to those bits. They shall be managed by ST tools in Flasher. ... Note: 111: The eight last sectors of the Bank 2 are reserved for flash high-cycle data
 */
class edata2_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr edata2_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_edata2r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_edata2r_cur_r>() const {return opsy::utility::clear_set<flash_edata2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_edata2r_cur_r other) const -> flash_edata2r_cur_r { return static_cast<flash_edata2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata2r_cur_r> other) const -> opsy::utility::clear_set<flash_edata2r_cur_r> {return opsy::utility::clear_set<flash_edata2r_cur_r>(flash_edata2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank2 flash high-cycle data enable
 */
class edata2_en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr edata2_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_edata2r_cur_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_edata2r_cur_r>() const {return opsy::utility::clear_set<flash_edata2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_edata2r_cur_r other) const -> flash_edata2r_cur_r { return static_cast<flash_edata2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata2r_cur_r> other) const -> opsy::utility::clear_set<flash_edata2r_cur_r> {return opsy::utility::clear_set<flash_edata2r_cur_r>(flash_edata2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto edata2_strt() const -> edata2_strt_f {return edata2_strt_f(static_cast<uint8_t>(value_ >> edata2_strt_f::offset));}
	[[nodiscard]] constexpr auto edata2_en() const -> edata2_en_f {return edata2_en_f((value_ & edata2_en_f::mask) != 0);}

	constexpr flash_edata2r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_edata2r_cur_r other) const -> flash_edata2r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_edata2r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH data sector configuration Bank 2
 */
class flash_edata2r_prg_r {
public:

/**
 * EDATA2_STRT contains the start sectors of the flash high-cycle data area in Bank 2 There is no hardware effect to those bits. They shall be managed by ST tools in Flasher. ... Note: 111: The eight last sectors of the Bank 2 are reserved for flash high-cycle data.
 */
class edata2_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr edata2_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_edata2r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_edata2r_prg_r>() const {return opsy::utility::clear_set<flash_edata2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_edata2r_prg_r other) const -> flash_edata2r_prg_r { return static_cast<flash_edata2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata2r_prg_r> other) const -> opsy::utility::clear_set<flash_edata2r_prg_r> {return opsy::utility::clear_set<flash_edata2r_prg_r>(flash_edata2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bank 2 flash high-cycle data enable
 */
class edata2_en_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr edata2_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator flash_edata2r_prg_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<flash_edata2r_prg_r>() const {return opsy::utility::clear_set<flash_edata2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_edata2r_prg_r other) const -> flash_edata2r_prg_r { return static_cast<flash_edata2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_edata2r_prg_r> other) const -> opsy::utility::clear_set<flash_edata2r_prg_r> {return opsy::utility::clear_set<flash_edata2r_prg_r>(flash_edata2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto edata2_strt() const -> edata2_strt_f {return edata2_strt_f(static_cast<uint8_t>(value_ >> edata2_strt_f::offset));}
	[[nodiscard]] constexpr auto edata2_en() const -> edata2_en_f {return edata2_en_f((value_ & edata2_en_f::mask) != 0);}

	constexpr flash_edata2r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_edata2r_prg_r other) const -> flash_edata2r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_edata2r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH HDP Bank 2 configuration
 */
class flash_hdp2r_cur_r {
public:

/**
 * HDPL barrier start set in number of 8-Kbyte sectors
 */
class hdp2_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdp2_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp2r_cur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp2r_cur_r>() const {return opsy::utility::clear_set<flash_hdp2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_hdp2r_cur_r other) const -> flash_hdp2r_cur_r { return static_cast<flash_hdp2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp2r_cur_r> other) const -> opsy::utility::clear_set<flash_hdp2r_cur_r> {return opsy::utility::clear_set<flash_hdp2r_cur_r>(flash_hdp2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HDPL barrier end set in number of 8-Kbyte sectors
 */
class hdp2_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hdp2_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp2r_cur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp2r_cur_r>() const {return opsy::utility::clear_set<flash_hdp2r_cur_r>(mask, *this);}
	constexpr auto operator|(flash_hdp2r_cur_r other) const -> flash_hdp2r_cur_r { return static_cast<flash_hdp2r_cur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp2r_cur_r> other) const -> opsy::utility::clear_set<flash_hdp2r_cur_r> {return opsy::utility::clear_set<flash_hdp2r_cur_r>(flash_hdp2r_cur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdp2_strt() const -> hdp2_strt_f {return hdp2_strt_f(static_cast<uint8_t>(value_ >> hdp2_strt_f::offset));}
	[[nodiscard]] constexpr auto hdp2_end() const -> hdp2_end_f {return hdp2_end_f(static_cast<uint8_t>(value_ >> hdp2_end_f::offset));}

	constexpr flash_hdp2r_cur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_hdp2r_cur_r other) const -> flash_hdp2r_cur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_hdp2r_cur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FLASH HDP Bank 2 configuration
 */
class flash_hdp2r_prg_r {
public:

/**
 * HDPL barrier start set in number of 8-Kbyte sectors
 */
class hdp2_strt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr hdp2_strt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp2r_prg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp2r_prg_r>() const {return opsy::utility::clear_set<flash_hdp2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_hdp2r_prg_r other) const -> flash_hdp2r_prg_r { return static_cast<flash_hdp2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp2r_prg_r> other) const -> opsy::utility::clear_set<flash_hdp2r_prg_r> {return opsy::utility::clear_set<flash_hdp2r_prg_r>(flash_hdp2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * HDPL barrier end set in number of 8-Kbyte sectors
 */
class hdp2_end_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hdp2_end_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator flash_hdp2r_prg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<flash_hdp2r_prg_r>() const {return opsy::utility::clear_set<flash_hdp2r_prg_r>(mask, *this);}
	constexpr auto operator|(flash_hdp2r_prg_r other) const -> flash_hdp2r_prg_r { return static_cast<flash_hdp2r_prg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<flash_hdp2r_prg_r> other) const -> opsy::utility::clear_set<flash_hdp2r_prg_r> {return opsy::utility::clear_set<flash_hdp2r_prg_r>(flash_hdp2r_prg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto hdp2_strt() const -> hdp2_strt_f {return hdp2_strt_f(static_cast<uint8_t>(value_ >> hdp2_strt_f::offset));}
	[[nodiscard]] constexpr auto hdp2_end() const -> hdp2_end_f {return hdp2_end_f(static_cast<uint8_t>(value_ >> hdp2_end_f::offset));}

	constexpr flash_hdp2r_prg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(flash_hdp2r_prg_r other) const -> flash_hdp2r_prg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> flash_hdp2r_prg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,flash_acr_r> flash_acr;
	opsy::utility::memory<uint32_t,flash_nskeyr_r> flash_nskeyr;
	opsy::utility::memory<uint32_t,flash_seckeyr_r> flash_seckeyr;
	opsy::utility::memory<uint32_t,flash_optkeyr_r> flash_optkeyr;
	opsy::utility::memory<uint32_t,flash_nsobkkeyr_r> flash_nsobkkeyr;
	opsy::utility::memory<uint32_t,flash_secobkkeyr_r> flash_secobkkeyr;
	opsy::utility::memory<uint32_t,flash_opsr_r> flash_opsr;
	opsy::utility::memory<uint32_t,flash_optcr_r> flash_optcr;
	opsy::utility::memory<uint32_t,flash_nssr_r> flash_nssr;
	opsy::utility::memory<uint32_t,flash_secsr_r> flash_secsr;
	opsy::utility::memory<uint32_t,flash_nscr_r> flash_nscr;
	opsy::utility::memory<uint32_t,flash_seccr_r> flash_seccr;
	opsy::utility::memory<uint32_t,flash_nsccr_r> flash_nsccr;
	opsy::utility::memory<uint32_t,flash_secccr_r> flash_secccr;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,flash_privcfgr_r> flash_privcfgr;
	opsy::utility::memory<uint32_t,flash_nsobkcfgr_r> flash_nsobkcfgr;
	opsy::utility::memory<uint32_t,flash_nsobkcfgr_r> flash_secobkcfgr;
	opsy::utility::memory<uint32_t,flash_hdpextr_r> flash_hdpextr;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,flash_optsr_cur_r> flash_optsr_cur;
	opsy::utility::memory<uint32_t,flash_optsr_prg_r> flash_optsr_prg;
	opsy::utility::padding<8> _p2;
	opsy::utility::memory<uint32_t,flash_nsepochr_cur_r> flash_nsepochr_cur;
	opsy::utility::padding<4> _p3;
	opsy::utility::memory<uint32_t,flash_secepochr_cur_r> flash_secepochr_cur;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,flash_optsr2_cur_r> flash_optsr2_cur;
	opsy::utility::memory<uint32_t,flash_optsr2_prg_r> flash_optsr2_prg;
	opsy::utility::padding<8> _p5;
	opsy::utility::memory<uint32_t,flash_nsbootr_cur_r> flash_nsbootr_cur;
	opsy::utility::memory<uint32_t,flash_nsbootr_prg_r> flash_nsbootr_prg;
	opsy::utility::memory<uint32_t,flash_secbootr_cur_r> flash_secbootr_cur;
	opsy::utility::memory<uint32_t,flash_bootr_prg_r> flash_bootr_prg;
	opsy::utility::memory<uint32_t,flash_otpblr_cur_r> flash_otpblr_cur;
	opsy::utility::memory<uint32_t,flash_otpblr_prg_r> flash_otpblr_prg;
	opsy::utility::padding<8> _p6;
	opsy::utility::memory<uint32_t,flash_secbb1rx_r> flash_secbb1r1;
	opsy::utility::memory<uint32_t,flash_secbb1rx_r> flash_secbb1r2;
	opsy::utility::memory<uint32_t,flash_secbb1rx_r> flash_secbb1r3;
	opsy::utility::memory<uint32_t,flash_secbb1rx_r> flash_secbb1r4;
	opsy::utility::padding<16> _p7;
	opsy::utility::memory<uint32_t,flash_privbb1rx_r> flash_privbb1r1;
	opsy::utility::memory<uint32_t,flash_privbb1rx_r> flash_privbb1r2;
	opsy::utility::memory<uint32_t,flash_privbb1rx_r> flash_privbb1r3;
	opsy::utility::memory<uint32_t,flash_privbb1rx_r> flash_privbb1r4;
	opsy::utility::padding<16> _p8;
	opsy::utility::memory<uint32_t,flash_secwm1r_cur_r> flash_secwm1r_cur;
	opsy::utility::memory<uint32_t,flash_secwm1r_prg_r> flash_secwm1r_prg;
	opsy::utility::memory<uint32_t,flash_wrp1r_cur_r> flash_wrp1r_cur;
	opsy::utility::memory<uint32_t,flash_wrp1r_prg_r> flash_wrp1r_prg;
	opsy::utility::memory<uint32_t,flash_edata1r_cur_r> flash_edata1r_cur;
	opsy::utility::memory<uint32_t,flash_edata1r_prg_r> flash_edata1r_prg;
	opsy::utility::memory<uint32_t,flash_hdp1r_cur_r> flash_hdp1r_cur;
	opsy::utility::memory<uint32_t,flash_hdp1r_prg_r> flash_hdp1r_prg;
	opsy::utility::memory<uint32_t,flash_ecccorr_r> flash_ecccorr;
	opsy::utility::memory<uint32_t,flash_eccdetr_r> flash_eccdetr;
	opsy::utility::memory<uint32_t,flash_eccdr_r> flash_eccdr;
	opsy::utility::padding<148> _p9;
	opsy::utility::memory<uint32_t,flash_secbb2rx_r> flash_secbb2r1;
	opsy::utility::memory<uint32_t,flash_secbb2rx_r> flash_secbb2r2;
	opsy::utility::memory<uint32_t,flash_secbb2rx_r> flash_secbb2r3;
	opsy::utility::memory<uint32_t,flash_secbb2rx_r> flash_secbb2r4;
	opsy::utility::padding<16> _p10;
	opsy::utility::memory<uint32_t,flash_privbb2rx_r> flash_privbb2r1;
	opsy::utility::memory<uint32_t,flash_privbb2rx_r> flash_privbb2r2;
	opsy::utility::memory<uint32_t,flash_privbb2rx_r> flash_privbb2r3;
	opsy::utility::memory<uint32_t,flash_privbb2rx_r> flash_privbb2r4;
	opsy::utility::padding<16> _p11;
	opsy::utility::memory<uint32_t,flash_secwm2r_cur_r> flash_secwm2r_cur;
	opsy::utility::memory<uint32_t,flash_secwm2r_prg_r> flash_secwm2r_prg;
	opsy::utility::memory<uint32_t,flash_wrp2r_cur_r> flash_wrp2r_cur;
	opsy::utility::memory<uint32_t,flash_wrp2r_prg_r> flash_wrp2r_prg;
	opsy::utility::memory<uint32_t,flash_edata2r_cur_r> flash_edata2r_cur;
	opsy::utility::memory<uint32_t,flash_edata2r_prg_r> flash_edata2r_prg;
	opsy::utility::memory<uint32_t,flash_hdp2r_cur_r> flash_hdp2r_cur;
	opsy::utility::memory<uint32_t,flash_hdp2r_prg_r> flash_hdp2r_prg;
};

static_assert(std::is_standard_layout_v<flash_p>);
static_assert(offsetof(flash_p, flash_acr) == 0);
static_assert(offsetof(flash_p, flash_nskeyr) == 4);
static_assert(offsetof(flash_p, flash_seckeyr) == 8);
static_assert(offsetof(flash_p, flash_optkeyr) == 12);
static_assert(offsetof(flash_p, flash_nsobkkeyr) == 16);
static_assert(offsetof(flash_p, flash_secobkkeyr) == 20);
static_assert(offsetof(flash_p, flash_opsr) == 24);
static_assert(offsetof(flash_p, flash_optcr) == 28);
static_assert(offsetof(flash_p, flash_nssr) == 32);
static_assert(offsetof(flash_p, flash_secsr) == 36);
static_assert(offsetof(flash_p, flash_nscr) == 40);
static_assert(offsetof(flash_p, flash_seccr) == 44);
static_assert(offsetof(flash_p, flash_nsccr) == 48);
static_assert(offsetof(flash_p, flash_secccr) == 52);
static_assert(offsetof(flash_p, flash_privcfgr) == 60);
static_assert(offsetof(flash_p, flash_nsobkcfgr) == 64);
static_assert(offsetof(flash_p, flash_secobkcfgr) == 68);
static_assert(offsetof(flash_p, flash_hdpextr) == 72);
static_assert(offsetof(flash_p, flash_optsr_cur) == 80);
static_assert(offsetof(flash_p, flash_optsr_prg) == 84);
static_assert(offsetof(flash_p, flash_nsepochr_cur) == 96);
static_assert(offsetof(flash_p, flash_secepochr_cur) == 104);
static_assert(offsetof(flash_p, flash_optsr2_cur) == 112);
static_assert(offsetof(flash_p, flash_optsr2_prg) == 116);
static_assert(offsetof(flash_p, flash_nsbootr_cur) == 128);
static_assert(offsetof(flash_p, flash_nsbootr_prg) == 132);
static_assert(offsetof(flash_p, flash_secbootr_cur) == 136);
static_assert(offsetof(flash_p, flash_bootr_prg) == 140);
static_assert(offsetof(flash_p, flash_otpblr_cur) == 144);
static_assert(offsetof(flash_p, flash_otpblr_prg) == 148);
static_assert(offsetof(flash_p, flash_secbb1r1) == 160);
static_assert(offsetof(flash_p, flash_secbb1r2) == 164);
static_assert(offsetof(flash_p, flash_secbb1r3) == 168);
static_assert(offsetof(flash_p, flash_secbb1r4) == 172);
static_assert(offsetof(flash_p, flash_privbb1r1) == 192);
static_assert(offsetof(flash_p, flash_privbb1r2) == 196);
static_assert(offsetof(flash_p, flash_privbb1r3) == 200);
static_assert(offsetof(flash_p, flash_privbb1r4) == 204);
static_assert(offsetof(flash_p, flash_secwm1r_cur) == 224);
static_assert(offsetof(flash_p, flash_secwm1r_prg) == 228);
static_assert(offsetof(flash_p, flash_wrp1r_cur) == 232);
static_assert(offsetof(flash_p, flash_wrp1r_prg) == 236);
static_assert(offsetof(flash_p, flash_edata1r_cur) == 240);
static_assert(offsetof(flash_p, flash_edata1r_prg) == 244);
static_assert(offsetof(flash_p, flash_hdp1r_cur) == 248);
static_assert(offsetof(flash_p, flash_hdp1r_prg) == 252);
static_assert(offsetof(flash_p, flash_ecccorr) == 256);
static_assert(offsetof(flash_p, flash_eccdetr) == 260);
static_assert(offsetof(flash_p, flash_eccdr) == 264);
static_assert(offsetof(flash_p, flash_secbb2r1) == 416);
static_assert(offsetof(flash_p, flash_secbb2r2) == 420);
static_assert(offsetof(flash_p, flash_secbb2r3) == 424);
static_assert(offsetof(flash_p, flash_secbb2r4) == 428);
static_assert(offsetof(flash_p, flash_privbb2r1) == 448);
static_assert(offsetof(flash_p, flash_privbb2r2) == 452);
static_assert(offsetof(flash_p, flash_privbb2r3) == 456);
static_assert(offsetof(flash_p, flash_privbb2r4) == 460);
static_assert(offsetof(flash_p, flash_secwm2r_cur) == 480);
static_assert(offsetof(flash_p, flash_secwm2r_prg) == 484);
static_assert(offsetof(flash_p, flash_wrp2r_cur) == 488);
static_assert(offsetof(flash_p, flash_wrp2r_prg) == 492);
static_assert(offsetof(flash_p, flash_edata2r_cur) == 496);
static_assert(offsetof(flash_p, flash_edata2r_prg) == 500);
static_assert(offsetof(flash_p, flash_hdp2r_cur) == 504);
static_assert(offsetof(flash_p, flash_hdp2r_prg) == 508);

inline flash_p& flash = *reinterpret_cast<flash_p*>(0x40022000);
inline flash_p& sec_flash = *reinterpret_cast<flash_p*>(0x50022000);

} // STM32H563

