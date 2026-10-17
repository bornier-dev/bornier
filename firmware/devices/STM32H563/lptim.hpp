#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Low power timer
 */
class lptim_p {
public:

/**
 * LPTIM interrupt and status register 
 */
class lptim_isr_output_r {
public:

/**
 * Compare 1 interrupt flag The CC1IF flag is set by hardware to inform application that LPTIM_CNT register value matches the compare register's value. The CC1IF flag can be cleared by writing 1 to the CC1CF bit in the LPTIM_ICR register.
 */
class cc1if_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match ARRM is set by hardware to inform application that LPTIM_CNT register's value reached the LPTIM_ARR register's value. ARRM flag can be cleared by writing 1 to the ARRMCF bit in the LPTIM_ICR register.
 */
class arrm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger edge event EXTTRIG is set by hardware to inform application that a valid edge on the selected external trigger input has occurred. If the trigger is ignored because the timer has already started, then this flag is not set. EXTTRIG flag can be cleared by writing 1 to the EXTTRIGCF bit in the LPTIM_ICR register.
 */
class exttrig_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK CMP1OK is set by hardware to inform application that the APB bus write operation to the LPTIM_CCR1 register has been successfully completed. CMP1OK flag can be cleared by writing 1 to the CMP1OKCF bit in the LPTIM_ICR register.
 */
class cmp1ok_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1ok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK ARROK is set by hardware to inform application that the APB bus write operation to the LPTIM_ARR register has been successfully completed. ARROK flag can be cleared by writing 1 to the ARROKCF bit in the LPTIM_ICR register.
 */
class arrok_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change down to up In Encoder mode, UP bit is set by hardware to inform application that the counter direction has changed from down to up. UP flag can be cleared by writing 1 to the UPCF bit in the LPTIM_ICR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class up_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr up_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change up to down In Encoder mode, DOWN bit is set by hardware to inform application that the counter direction has changed from up to down. DOWN flag can be cleared by writing 1 to the DOWNCF bit in the LPTIM_ICR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class down_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr down_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM update event occurred UE is set by hardware to inform application that an update event was generated. UE flag can be cleared by writing 1 to the UECF bit in the LPTIM_ICR register.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK REPOK is set by hardware to inform application that the APB bus write operation to the LPTIM_RCR register has been successfully completed. REPOK flag can be cleared by writing 1 to the REPOKCF bit in the LPTIM_ICR register.
 */
class repok_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK DIEROK is set by hardware to inform application that the APB bus write operation to the LPTIM_DIER register has been successfully completed. DIEROK flag can be cleared by writing 1 to the DIEROKCF bit in the LPTIM_ICR register.
 */
class dierok_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_output_r>() const {return opsy::utility::clear_set<lptim_isr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_output_r other) const -> lptim_isr_output_r { return static_cast<lptim_isr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_output_r> other) const -> opsy::utility::clear_set<lptim_isr_output_r> {return opsy::utility::clear_set<lptim_isr_output_r>(lptim_isr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrm() const -> arrm_f {return arrm_f((value_ & arrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrig() const -> exttrig_f {return exttrig_f((value_ & exttrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1ok() const -> cmp1ok_f {return cmp1ok_f((value_ & cmp1ok_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrok() const -> arrok_f {return arrok_f((value_ & arrok_f::mask) != 0);}
	[[nodiscard]] constexpr auto up() const -> up_f {return up_f((value_ & up_f::mask) != 0);}
	[[nodiscard]] constexpr auto down() const -> down_f {return down_f((value_ & down_f::mask) != 0);}
	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto repok() const -> repok_f {return repok_f((value_ & repok_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierok() const -> dierok_f {return dierok_f((value_ & dierok_f::mask) != 0);}

	constexpr lptim_isr_output_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_isr_output_r other) const -> lptim_isr_output_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_isr_output_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM interrupt and status register 
 */
class lptim_isr_intput_r {
public:

/**
 * capture 1 interrupt flag If channel CC1 is configured as input: CC1IF is set by hardware to inform application that the current value of the counter is captured in LPTIM_CCR1 register. The corresponding interrupt or DMA request is generated if enabled. The CC1OF flag is set if the CC1IF flag was already high.
 */
class cc1if_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match ARRM is set by hardware to inform application that LPTIM_CNT register's value reached the LPTIM_ARR register's value. ARRM flag can be cleared by writing 1 to the ARRMCF bit in the LPTIM_ICR register.
 */
class arrm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger edge event EXTTRIG is set by hardware to inform application that a valid edge on the selected external trigger input has occurred. If the trigger is ignored because the timer has already started, then this flag is not set. EXTTRIG flag can be cleared by writing 1 to the EXTTRIGCF bit in the LPTIM_ICR register.
 */
class exttrig_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrig_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK ARROK is set by hardware to inform application that the APB bus write operation to the LPTIM_ARR register has been successfully completed. ARROK flag can be cleared by writing 1 to the ARROKCF bit in the LPTIM_ICR register.
 */
class arrok_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change down to up In Encoder mode, UP bit is set by hardware to inform application that the counter direction has changed from down to up. UP flag can be cleared by writing 1 to the UPCF bit in the LPTIM_ICR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class up_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr up_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter direction change up to down In Encoder mode, DOWN bit is set by hardware to inform application that the counter direction has changed from up to down. DOWN flag can be cleared by writing 1 to the DOWNCF bit in the LPTIM_ICR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class down_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr down_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM update event occurred UE is set by hardware to inform application that an update event was generated. UE flag can be cleared by writing 1 to the UECF bit in the LPTIM_ICR register.
 */
class ue_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK REPOK is set by hardware to inform application that the APB bus write operation to the LPTIM_RCR register has been successfully completed. REPOK flag can be cleared by writing 1 to the REPOKCF bit in the LPTIM_ICR register.
 */
class repok_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 2 interrupt flag If channel CC2 is configured as input: CC2IF is set by hardware to inform application that the current value of the counter is captured in LPTIM_CCR2 register. The corresponding interrupt or DMA request is generated if enabled. The CC2OF flag is set if the CC2IF flag was already high. Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2if_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2if_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 1 over-capture flag This flag is set by hardware only when the corresponding channel is configured in input capture mode. It is cleared by software by writing 1 to the CC1OCF bit in the LPTIM_ICR register. Note: If LPTIM does not implement at least 1 channel this bit is reserved. Please refer to .
 */
class cc1of_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture 2 over-capture flag This flag is set by hardware only when the corresponding channel is configured in input capture mode. It is cleared by software by writing 1 to the CC2OCF bit in the LPTIM_ICR register. Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2of_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2of_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK DIEROK is set by hardware to inform application that the APB bus write operation to the LPTIM_DIER register has been successfully completed. DIEROK flag can be cleared by writing 1 to the DIEROKCF bit in the LPTIM_ICR register.
 */
class dierok_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierok_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_isr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_isr_intput_r>() const {return opsy::utility::clear_set<lptim_isr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return static_cast<lptim_isr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_isr_intput_r> other) const -> opsy::utility::clear_set<lptim_isr_intput_r> {return opsy::utility::clear_set<lptim_isr_intput_r>(lptim_isr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1if() const -> cc1if_f {return cc1if_f((value_ & cc1if_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrm() const -> arrm_f {return arrm_f((value_ & arrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrig() const -> exttrig_f {return exttrig_f((value_ & exttrig_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrok() const -> arrok_f {return arrok_f((value_ & arrok_f::mask) != 0);}
	[[nodiscard]] constexpr auto up() const -> up_f {return up_f((value_ & up_f::mask) != 0);}
	[[nodiscard]] constexpr auto down() const -> down_f {return down_f((value_ & down_f::mask) != 0);}
	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto repok() const -> repok_f {return repok_f((value_ & repok_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2if() const -> cc2if_f {return cc2if_f((value_ & cc2if_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1of() const -> cc1of_f {return cc1of_f((value_ & cc1of_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2of() const -> cc2of_f {return cc2of_f((value_ & cc2of_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierok() const -> dierok_f {return dierok_f((value_ & dierok_f::mask) != 0);}

	constexpr lptim_isr_intput_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_isr_intput_r other) const -> lptim_isr_intput_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_isr_intput_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM interrupt clear register 
 */
class lptim_icr_output_r {
public:

/**
 * Capture/compare 1 clear flag Writing 1 to this bit clears the CC1IF flag in the LPTIM_ISR register.
 */
class cc1cf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match clear flag Writing 1 to this bit clears the ARRM flag in the LPTIM_ISR register
 */
class arrmcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge clear flag Writing 1 to this bit clears the EXTTRIG flag in the LPTIM_ISR register
 */
class exttrigcf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK clear flag Writing 1 to this bit clears the CMP1OK flag in the LPTIM_ISR register.
 */
class cmp1okcf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1okcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK clear flag Writing 1 to this bit clears the ARROK flag in the LPTIM_ISR register
 */
class arrokcf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP clear flag Writing 1 to this bit clear the UP flag in the LPTIM_ISR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class upcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down clear flag Writing 1 to this bit clear the DOWN flag in the LPTIM_ISR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class downcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event clear flag Writing 1 to this bit clear the UE flag in the LPTIM_ISR register.
 */
class uecf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK clear flag Writing 1 to this bit clears the REPOK flag in the LPTIM_ISR register.
 */
class repokcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK clear flag Writing 1 to this bit clears the DIEROK flag in the LPTIM_ISR register.
 */
class dierokcf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_output_r>() const {return opsy::utility::clear_set<lptim_icr_output_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_output_r other) const -> lptim_icr_output_r { return static_cast<lptim_icr_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_output_r> other) const -> opsy::utility::clear_set<lptim_icr_output_r> {return opsy::utility::clear_set<lptim_icr_output_r>(lptim_icr_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1cf() const -> cc1cf_f {return cc1cf_f((value_ & cc1cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmcf() const -> arrmcf_f {return arrmcf_f((value_ & arrmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigcf() const -> exttrigcf_f {return exttrigcf_f((value_ & exttrigcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1okcf() const -> cmp1okcf_f {return cmp1okcf_f((value_ & cmp1okcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokcf() const -> arrokcf_f {return arrokcf_f((value_ & arrokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto upcf() const -> upcf_f {return upcf_f((value_ & upcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto downcf() const -> downcf_f {return downcf_f((value_ & downcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto uecf() const -> uecf_f {return uecf_f((value_ & uecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokcf() const -> repokcf_f {return repokcf_f((value_ & repokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierokcf() const -> dierokcf_f {return dierokcf_f((value_ & dierokcf_f::mask) != 0);}

	constexpr lptim_icr_output_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_icr_output_r other) const -> lptim_icr_output_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_icr_output_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM interrupt clear register 
 */
class lptim_icr_intput_r {
public:

/**
 * Capture/compare 1 clear flag Writing 1 to this bit clears the CC1IF flag in the LPTIM_ISR register.
 */
class cc1cf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match clear flag Writing 1 to this bit clears the ARRM flag in the LPTIM_ISR register
 */
class arrmcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge clear flag Writing 1 to this bit clears the EXTTRIG flag in the LPTIM_ISR register
 */
class exttrigcf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK clear flag Writing 1 to this bit clears the ARROK flag in the LPTIM_ISR register
 */
class arrokcf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP clear flag Writing 1 to this bit clear the UP flag in the LPTIM_ISR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class upcf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down clear flag Writing 1 to this bit clear the DOWN flag in the LPTIM_ISR register. Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class downcf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event clear flag Writing 1 to this bit clear the UE flag in the LPTIM_ISR register.
 */
class uecf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK clear flag Writing 1 to this bit clears the REPOK flag in the LPTIM_ISR register.
 */
class repokcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 clear flag Writing 1 to this bit clears the CC2IF flag in the LPTIM_ISR register. Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2cf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2cf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 over-capture clear flag Writing 1 to this bit clears the CC1OF flag in the LPTIM_ISR register. Note: If LPTIM does not implement at least 1 channel this bit is reserved. Please refer to .
 */
class cc1ocf_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1ocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 over-capture clear flag Writing 1 to this bit clears the CC2OF flag in the LPTIM_ISR register. Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2ocf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2ocf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable register update OK clear flag Writing 1 to this bit clears the DIEROK flag in the LPTIM_ISR register.
 */
class dierokcf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dierokcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_icr_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_icr_intput_r>() const {return opsy::utility::clear_set<lptim_icr_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return static_cast<lptim_icr_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_icr_intput_r> other) const -> opsy::utility::clear_set<lptim_icr_intput_r> {return opsy::utility::clear_set<lptim_icr_intput_r>(lptim_icr_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1cf() const -> cc1cf_f {return cc1cf_f((value_ & cc1cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmcf() const -> arrmcf_f {return arrmcf_f((value_ & arrmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigcf() const -> exttrigcf_f {return exttrigcf_f((value_ & exttrigcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokcf() const -> arrokcf_f {return arrokcf_f((value_ & arrokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto upcf() const -> upcf_f {return upcf_f((value_ & upcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto downcf() const -> downcf_f {return downcf_f((value_ & downcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto uecf() const -> uecf_f {return uecf_f((value_ & uecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokcf() const -> repokcf_f {return repokcf_f((value_ & repokcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2cf() const -> cc2cf_f {return cc2cf_f((value_ & cc2cf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1ocf() const -> cc1ocf_f {return cc1ocf_f((value_ & cc1ocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ocf() const -> cc2ocf_f {return cc2ocf_f((value_ & cc2ocf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dierokcf() const -> dierokcf_f {return dierokcf_f((value_ & dierokcf_f::mask) != 0);}

	constexpr lptim_icr_intput_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_icr_intput_r other) const -> lptim_icr_intput_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_icr_intput_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM interrupt enable register 
 */
class lptim_dier_output_r {
public:

/**
 * Capture/compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match Interrupt Enable
 */
class arrmie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge Interrupt Enable
 */
class exttrigie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Compare register 1 update OK interrupt enable
 */
class cmp1okie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmp1okie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK Interrupt Enable
 */
class arrokie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP Interrupt Enable Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class upie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down Interrupt Enable Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class downie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event interrupt enable
 */
class ueie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ueie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK interrupt Enable
 */
class repokie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_output_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_output_r>() const {return opsy::utility::clear_set<lptim_dier_output_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_output_r other) const -> lptim_dier_output_r { return static_cast<lptim_dier_output_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_output_r> other) const -> opsy::utility::clear_set<lptim_dier_output_r> {return opsy::utility::clear_set<lptim_dier_output_r>(lptim_dier_output_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmie() const -> arrmie_f {return arrmie_f((value_ & arrmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigie() const -> exttrigie_f {return exttrigie_f((value_ & exttrigie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmp1okie() const -> cmp1okie_f {return cmp1okie_f((value_ & cmp1okie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokie() const -> arrokie_f {return arrokie_f((value_ & arrokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto upie() const -> upie_f {return upie_f((value_ & upie_f::mask) != 0);}
	[[nodiscard]] constexpr auto downie() const -> downie_f {return downie_f((value_ & downie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ueie() const -> ueie_f {return ueie_f((value_ & ueie_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokie() const -> repokie_f {return repokie_f((value_ & repokie_f::mask) != 0);}

	constexpr lptim_dier_output_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_dier_output_r other) const -> lptim_dier_output_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_dier_output_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM interrupt enable register 
 */
class lptim_dier_intput_r {
public:

/**
 * Capture/compare 1 interrupt enable
 */
class cc1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload match Interrupt Enable
 */
class arrmie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * External trigger valid edge Interrupt Enable
 */
class exttrigie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr exttrigie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Autoreload register update OK Interrupt Enable
 */
class arrokie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr arrokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to UP Interrupt Enable Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class upie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr upie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Direction change to down Interrupt Enable Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class downie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr downie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event interrupt enable
 */
class ueie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ueie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Repetition register update OK interrupt Enable
 */
class repokie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr repokie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 interrupt enable Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2ie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 over-capture interrupt enable Note: If LPTIM does not implement at least 1 channel this bit is reserved. Please refer to .
 */
class cc1oie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc1oie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 over-capture interrupt enable Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2oie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cc2oie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 DMA request enable Note: If LPTIM does not implement at least 1 channel this bit is reserved. Please refer to .
 */
class cc1de_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc1de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update event DMA request enable Note: If LPTIM does not implement at least 1 channel this bit is reserved. Please refer to .
 */
class uede_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uede_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 DMA request enable Note: If LPTIM does not implement at least 2 channels this bit is reserved. Please refer to .
 */
class cc2de_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2de_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_dier_intput_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_dier_intput_r>() const {return opsy::utility::clear_set<lptim_dier_intput_r>(mask, *this);}
	constexpr auto operator|(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return static_cast<lptim_dier_intput_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_dier_intput_r> other) const -> opsy::utility::clear_set<lptim_dier_intput_r> {return opsy::utility::clear_set<lptim_dier_intput_r>(lptim_dier_intput_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cc1ie() const -> cc1ie_f {return cc1ie_f((value_ & cc1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrmie() const -> arrmie_f {return arrmie_f((value_ & arrmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto exttrigie() const -> exttrigie_f {return exttrigie_f((value_ & exttrigie_f::mask) != 0);}
	[[nodiscard]] constexpr auto arrokie() const -> arrokie_f {return arrokie_f((value_ & arrokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto upie() const -> upie_f {return upie_f((value_ & upie_f::mask) != 0);}
	[[nodiscard]] constexpr auto downie() const -> downie_f {return downie_f((value_ & downie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ueie() const -> ueie_f {return ueie_f((value_ & ueie_f::mask) != 0);}
	[[nodiscard]] constexpr auto repokie() const -> repokie_f {return repokie_f((value_ & repokie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2ie() const -> cc2ie_f {return cc2ie_f((value_ & cc2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1oie() const -> cc1oie_f {return cc1oie_f((value_ & cc1oie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2oie() const -> cc2oie_f {return cc2oie_f((value_ & cc2oie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1de() const -> cc1de_f {return cc1de_f((value_ & cc1de_f::mask) != 0);}
	[[nodiscard]] constexpr auto uede() const -> uede_f {return uede_f((value_ & uede_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2de() const -> cc2de_f {return cc2de_f((value_ & cc2de_f::mask) != 0);}

	constexpr lptim_dier_intput_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_dier_intput_r other) const -> lptim_dier_intput_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_dier_intput_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM configuration register 
 */
class lptim_cfgr_r {
public:

/**
 * Clock selector The CKSEL bit selects which clock source the LPTIM uses:
 */
class cksel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cksel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock Polarity When the LPTIM is clocked by an external clock source, CKPOL bits is used to configure the active edge or edges used by the counter: If the LPTIM is configured in Encoder mode (ENC bit is set), the encoder sub-mode 1 is active. If the LPTIM is configured in Encoder mode (ENC bit is set), the encoder sub-mode 2 is active. Refer to for more details about Encoder mode sub-modes.
 */
class ckpol_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ckpol_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Configurable digital filter for external clock The CKFLT value sets the number of consecutive equal samples that should be detected when a level change occurs on an external clock signal before it is considered as a valid level transition. An internal clock source must be present to use this feature
 */
class ckflt_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ckflt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Configurable digital filter for trigger The TRGFLT value sets the number of consecutive equal samples that should be detected when a level change occurs on an internal trigger before it is considered as a valid level transition. An internal clock source must be present to use this feature
 */
class trgflt_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trgflt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clock prescaler The PRESC bits configure the prescaler division factor. It can be one among the following division factors:
 */
class presc_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr presc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Trigger selector The TRIGSEL bits select the trigger source that serves as a trigger event for the LPTIM among the below 8 available sources: See for details.
 */
class trigsel_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trigsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Trigger enable and polarity The TRIGEN bits controls whether the LPTIM counter is started by an external trigger or not. If the external trigger option is selected, three configurations are possible for the trigger active edge:
 */
class trigen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trigen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Timeout enable The TIMOUT bit controls the Timeout feature
 */
class timout_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr timout_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Waveform shape The WAVE bit controls the output shape
 */
class wave_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wave_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Waveform shape polarity The WAVEPOL bit controls the output polarity Note: If the LPTIM implements at least one capture/compare channel, this bit is reserved. Please refer to .
 */
class wavpol_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wavpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Registers update mode The PRELOAD bit controls the LPTIM_ARR, LPTIM_RCR and the LPTIM_CCRx registers update modality
 */
class preload_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr preload_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * counter mode enabled The COUNTMODE bit selects which clock source is used by the LPTIM to clock the counter:
 */
class countmode_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr countmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Encoder mode enable The ENC bit controls the Encoder mode Note: If the LPTIM does not support encoder mode feature, this bit is reserved. Please refer to .
 */
class enc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr enc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cfgr_r>() const {return opsy::utility::clear_set<lptim_cfgr_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr_r other) const -> lptim_cfgr_r { return static_cast<lptim_cfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr_r> other) const -> opsy::utility::clear_set<lptim_cfgr_r> {return opsy::utility::clear_set<lptim_cfgr_r>(lptim_cfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cksel() const -> cksel_f {return cksel_f((value_ & cksel_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckpol() const -> ckpol_f {return ckpol_f(static_cast<uint8_t>(value_ >> ckpol_f::offset));}
	[[nodiscard]] constexpr auto ckflt() const -> ckflt_f {return ckflt_f(static_cast<uint8_t>(value_ >> ckflt_f::offset));}
	[[nodiscard]] constexpr auto trgflt() const -> trgflt_f {return trgflt_f(static_cast<uint8_t>(value_ >> trgflt_f::offset));}
	[[nodiscard]] constexpr auto presc() const -> presc_f {return presc_f(static_cast<uint8_t>(value_ >> presc_f::offset));}
	[[nodiscard]] constexpr auto trigsel() const -> trigsel_f {return trigsel_f(static_cast<uint8_t>(value_ >> trigsel_f::offset));}
	[[nodiscard]] constexpr auto trigen() const -> trigen_f {return trigen_f(static_cast<uint8_t>(value_ >> trigen_f::offset));}
	[[nodiscard]] constexpr auto timout() const -> timout_f {return timout_f((value_ & timout_f::mask) != 0);}
	[[nodiscard]] constexpr auto wave() const -> wave_f {return wave_f((value_ & wave_f::mask) != 0);}
	[[nodiscard]] constexpr auto wavpol() const -> wavpol_f {return wavpol_f((value_ & wavpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto preload() const -> preload_f {return preload_f((value_ & preload_f::mask) != 0);}
	[[nodiscard]] constexpr auto countmode() const -> countmode_f {return countmode_f((value_ & countmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto enc() const -> enc_f {return enc_f((value_ & enc_f::mask) != 0);}

	constexpr lptim_cfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cfgr_r other) const -> lptim_cfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM control register 
 */
class lptim_cr_r {
public:

/**
 * LPTIM enable The ENABLE bit is set and cleared by software.
 */
class enable_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr enable_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPTIM start in Single mode This bit is set by software and cleared by hardware. In case of software start (TRIGEN[1:0] = '00'), setting this bit starts the LPTIM in single pulse mode. If the software start is disabled (TRIGEN[1:0] different than '00'), setting this bit starts the LPTIM in single pulse mode as soon as an external trigger is detected. If this bit is set when the LPTIM is in continuous counting mode, then the LPTIM stops at the following match between LPTIM_ARR and LPTIM_CNT registers. This bit can only be set when the LPTIM is enabled. It is automatically reset by hardware.
 */
class sngstrt_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sngstrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timer start in Continuous mode This bit is set by software and cleared by hardware. In case of software start (TRIGEN[1:0] = '00'), setting this bit starts the LPTIM in Continuous mode. If the software start is disabled (TRIGEN[1:0] different than '00'), setting this bit starts the timer in Continuous mode as soon as an external trigger is detected. If this bit is set when a single pulse mode counting is ongoing, then the timer does not stop at the next match between the LPTIM_ARR and LPTIM_CNT registers and the LPTIM counter keeps counting in Continuous mode. This bit can be set only when the LPTIM is enabled. It is automatically reset by hardware.
 */
class cntstrt_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cntstrt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter reset This bit is set by software and cleared by hardware. When set to '1' this bit triggers a synchronous reset of the LPTIM_CNT counter register. Due to the synchronous nature of this reset, it only takes place after a synchronization delay of 3 LPTimer core clock cycles (LPTimer core clock may be different from APB clock). This bit can be set only when the LPTIM is enabled. It is automatically reset by hardware. COUNTRST must never be set to '1' by software before it is already cleared to '0' by hardware. Software should consequently check that COUNTRST bit is already cleared to '0' before attempting to set it to '1'.
 */
class countrst_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr countrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reset after read enable This bit is set and cleared by software. When RSTARE is set to '1', any read access to LPTIM_CNT register asynchronously resets LPTIM_CNT register content. This bit can be set only when the LPTIM is enabled.
 */
class rstare_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rstare_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_cr_r>() const {return opsy::utility::clear_set<lptim_cr_r>(mask, *this);}
	constexpr auto operator|(lptim_cr_r other) const -> lptim_cr_r { return static_cast<lptim_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cr_r> other) const -> opsy::utility::clear_set<lptim_cr_r> {return opsy::utility::clear_set<lptim_cr_r>(lptim_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto enable() const -> enable_f {return enable_f((value_ & enable_f::mask) != 0);}
	[[nodiscard]] constexpr auto sngstrt() const -> sngstrt_f {return sngstrt_f((value_ & sngstrt_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntstrt() const -> cntstrt_f {return cntstrt_f((value_ & cntstrt_f::mask) != 0);}
	[[nodiscard]] constexpr auto countrst() const -> countrst_f {return countrst_f((value_ & countrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rstare() const -> rstare_f {return rstare_f((value_ & rstare_f::mask) != 0);}

	constexpr lptim_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cr_r other) const -> lptim_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM compare register 1 
 */
class lptim_ccr1_r {
public:

/**
 * Capture/compare 1 value If channel CC1 is configured as output: CCR1 is the value to be loaded in the capture/compare 1 register. Depending on the PRELOAD option, the CCR1 register is immediately updated if the PRELOAD bit is reset and updated at next LPTIM update event if PREOAD bit is reset. The capture/compare register 1 contains the value to be compared to the counter LPTIM_CNT and signaled on OC1 output. If channel CC1 is configured as input: CCR1 contains the counter value transferred by the last input capture 1 event. The LPTIM_CCR1 register is read-only and cannot be programmed. If LPTIM does not implement any channel: The compare register 1 contains the value to be compared to the counter LPTIM_CNT and signaled on LPTIM output.
 */
class ccr1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ccr1_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_ccr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccr1_r>() const {return opsy::utility::clear_set<lptim_ccr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccr1_r other) const -> lptim_ccr1_r { return static_cast<lptim_ccr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccr1_r> other) const -> opsy::utility::clear_set<lptim_ccr1_r> {return opsy::utility::clear_set<lptim_ccr1_r>(lptim_ccr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ccr1() const -> ccr1_f {return ccr1_f(static_cast<uint16_t>(value_ >> ccr1_f::offset));}

	constexpr lptim_ccr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccr1_r other) const -> lptim_ccr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM autoreload register 
 */
class lptim_arr_r {
public:

/**
 * Auto reload value ARR is the autoreload value for the LPTIM. This value must be strictly greater than the CCRx[15:0] value.
 */
class arr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr arr_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_arr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_arr_r>() const {return opsy::utility::clear_set<lptim_arr_r>(mask, *this);}
	constexpr auto operator|(lptim_arr_r other) const -> lptim_arr_r { return static_cast<lptim_arr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_arr_r> other) const -> opsy::utility::clear_set<lptim_arr_r> {return opsy::utility::clear_set<lptim_arr_r>(lptim_arr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto arr() const -> arr_f {return arr_f(static_cast<uint16_t>(value_ >> arr_f::offset));}

	constexpr lptim_arr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_arr_r other) const -> lptim_arr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_arr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * LPTIM counter register 
 */
class lptim_cnt_r {
public:

/**
 * Counter value When the LPTIM is running with an asynchronous clock, reading the LPTIM_CNT register may return unreliable values. So in this case it is necessary to perform two consecutive read accesses and verify that the two returned values are identical.
 */
class cnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cnt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_cnt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cnt_r>() const {return opsy::utility::clear_set<lptim_cnt_r>(mask, *this);}
	constexpr auto operator|(lptim_cnt_r other) const -> lptim_cnt_r { return static_cast<lptim_cnt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cnt_r> other) const -> opsy::utility::clear_set<lptim_cnt_r> {return opsy::utility::clear_set<lptim_cnt_r>(lptim_cnt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto cnt() const -> cnt_f {return cnt_f(static_cast<uint16_t>(value_ >> cnt_f::offset));}

	constexpr lptim_cnt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cnt_r other) const -> lptim_cnt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cnt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM configuration register 2 
 */
class lptim_cfgr2_r {
public:

/**
 * LPTIM input 1 selection The IN1SEL bits control the LPTIM input 1 multiplexer, which connects LPTIM input 1 to one of the available inputs. For connection details refer to .
 */
class in1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr in1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input 2 selection The IN2SEL bits control the LPTIM input 2 multiplexer, which connects LPTIM input 2 to one of the available inputs. For connection details refer to .
 */
class in2sel_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr in2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input capture 1 selection The IC1SEL bits control the LPTIM Input capture 1 multiplexer, which connects LPTIM Input capture 1 to one of the available inputs. For connection details refer to .
 */
class ic1sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic1sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * LPTIM input capture 2 selection The IC2SEL bits control the LPTIM Input capture 2 multiplexer, which connects LPTIM Input capture 2 to one of the available inputs. For connection details refer to .
 */
class ic2sel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_cfgr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_cfgr2_r>() const {return opsy::utility::clear_set<lptim_cfgr2_r>(mask, *this);}
	constexpr auto operator|(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return static_cast<lptim_cfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_cfgr2_r> other) const -> opsy::utility::clear_set<lptim_cfgr2_r> {return opsy::utility::clear_set<lptim_cfgr2_r>(lptim_cfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto in1sel() const -> in1sel_f {return in1sel_f(static_cast<uint8_t>(value_ >> in1sel_f::offset));}
	[[nodiscard]] constexpr auto in2sel() const -> in2sel_f {return in2sel_f(static_cast<uint8_t>(value_ >> in2sel_f::offset));}
	[[nodiscard]] constexpr auto ic1sel() const -> ic1sel_f {return ic1sel_f(static_cast<uint8_t>(value_ >> ic1sel_f::offset));}
	[[nodiscard]] constexpr auto ic2sel() const -> ic2sel_f {return ic2sel_f(static_cast<uint8_t>(value_ >> ic2sel_f::offset));}

	constexpr lptim_cfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_cfgr2_r other) const -> lptim_cfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_cfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM repetition register 
 */
class lptim_rcr_r {
public:

/**
 * Repetition register value REP is the repetition value for the LPTIM.
 */
class rep_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr rep_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_rcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_rcr_r>() const {return opsy::utility::clear_set<lptim_rcr_r>(mask, *this);}
	constexpr auto operator|(lptim_rcr_r other) const -> lptim_rcr_r { return static_cast<lptim_rcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_rcr_r> other) const -> opsy::utility::clear_set<lptim_rcr_r> {return opsy::utility::clear_set<lptim_rcr_r>(lptim_rcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto rep() const -> rep_f {return rep_f(static_cast<uint8_t>(value_ >> rep_f::offset));}

	constexpr lptim_rcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_rcr_r other) const -> lptim_rcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_rcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM capture/compare mode register 1 
 */
class lptim_ccmr1_r {
public:

/**
 * Capture/compare 1 selection This bitfield defines the direction of the channel input (capture) or output mode.
 */
class cc1sel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 output enable. This bit determines if a capture of the counter value can actually be done into the input capture/compare register 1 (LPTIM_CCR1) or not.
 */
class cc1e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cc1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 1 output polarity. Only bit2 is used to set polarity when output mode is enabled, bit3 is don't care. This field is used to select the IC1 polarity for capture operations.
 */
class cc1p_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr cc1p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 prescaler This bitfield defines the ratio of the prescaler acting on the CC1 input (IC1).
 */
class ic1psc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic1psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 1 filter This bitfield defines the number of consecutive equal samples that should be detected when a level change occurs on an external input capture signal before it is considered as a valid level transition. An internal clock source must be present to use this feature.
 */
class ic1f_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ic1f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Capture/compare 2 selection This bitfield defines the direction of the channel, input (capture) or output mode.
 */
class cc2sel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output enable. This bit determines if a capture of the counter value can actually be done into the input capture/compare register 2 (LPTIM_CCR2) or not.
 */
class cc2e_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cc2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture/compare 2 output polarity. Only bit2 is used to set polarity when output mode is enabled, bit3 is don't care. This field is used to select the IC2 polarity for capture operations.
 */
class cc2p_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cc2p_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 prescaler This bitfield defines the ratio of the prescaler acting on the CC2 input (IC2).
 */
class ic2psc_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2psc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input capture 2 filter This bitfield defines the number of consecutive equal samples that should be detected when a level change occurs on an external input capture signal before it is considered as a valid level transition. An internal clock source must be present to use this feature.
 */
class ic2f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ic2f_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lptim_ccmr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccmr1_r>() const {return opsy::utility::clear_set<lptim_ccmr1_r>(mask, *this);}
	constexpr auto operator|(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return static_cast<lptim_ccmr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccmr1_r> other) const -> opsy::utility::clear_set<lptim_ccmr1_r> {return opsy::utility::clear_set<lptim_ccmr1_r>(lptim_ccmr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto cc1sel() const -> cc1sel_f {return cc1sel_f((value_ & cc1sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1e() const -> cc1e_f {return cc1e_f((value_ & cc1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc1p() const -> cc1p_f {return cc1p_f(static_cast<uint8_t>(value_ >> cc1p_f::offset));}
	[[nodiscard]] constexpr auto ic1psc() const -> ic1psc_f {return ic1psc_f(static_cast<uint8_t>(value_ >> ic1psc_f::offset));}
	[[nodiscard]] constexpr auto ic1f() const -> ic1f_f {return ic1f_f(static_cast<uint8_t>(value_ >> ic1f_f::offset));}
	[[nodiscard]] constexpr auto cc2sel() const -> cc2sel_f {return cc2sel_f((value_ & cc2sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2e() const -> cc2e_f {return cc2e_f((value_ & cc2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto cc2p() const -> cc2p_f {return cc2p_f(static_cast<uint8_t>(value_ >> cc2p_f::offset));}
	[[nodiscard]] constexpr auto ic2psc() const -> ic2psc_f {return ic2psc_f(static_cast<uint8_t>(value_ >> ic2psc_f::offset));}
	[[nodiscard]] constexpr auto ic2f() const -> ic2f_f {return ic2f_f(static_cast<uint8_t>(value_ >> ic2f_f::offset));}

	constexpr lptim_ccmr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccmr1_r other) const -> lptim_ccmr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccmr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPTIM compare register 2 
 */
class lptim_ccr2_r {
public:

/**
 * Capture/compare 2 value If channel CC2 is configured as output: CCR2 is the value to be loaded in the capture/compare 2 register. Depending on the PRELOAD option, the CCR2 register is immediately updated if the PRELOAD bit is reset and updated at next LPTIM update event if PREOAD bit is reset. The capture/compare register 2 contains the value to be compared to the counter LPTIM_CNT and signaled on OC2 output. If channel CC2 is configured as input: CCR2 contains the counter value transferred by the last input capture 2 event. The LPTIM_CCR2 register is read-only and cannot be programmed.
 */
class ccr2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ccr2_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lptim_ccr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lptim_ccr2_r>() const {return opsy::utility::clear_set<lptim_ccr2_r>(mask, *this);}
	constexpr auto operator|(lptim_ccr2_r other) const -> lptim_ccr2_r { return static_cast<lptim_ccr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lptim_ccr2_r> other) const -> opsy::utility::clear_set<lptim_ccr2_r> {return opsy::utility::clear_set<lptim_ccr2_r>(lptim_ccr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ccr2() const -> ccr2_f {return ccr2_f(static_cast<uint16_t>(value_ >> ccr2_f::offset));}

	constexpr lptim_ccr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lptim_ccr2_r other) const -> lptim_ccr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lptim_ccr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,lptim_isr_output_r> lptim_isr_output;
		opsy::utility::memory<uint32_t,lptim_isr_intput_r> lptim_isr_intput;
	};
	union {
		opsy::utility::memory<uint32_t,lptim_icr_output_r> lptim_icr_output;
		opsy::utility::memory<uint32_t,lptim_icr_intput_r> lptim_icr_intput;
	};
	union {
		opsy::utility::memory<uint32_t,lptim_dier_output_r> lptim_dier_output;
		opsy::utility::memory<uint32_t,lptim_dier_intput_r> lptim_dier_intput;
	};
	opsy::utility::memory<uint32_t,lptim_cfgr_r> lptim_cfgr;
	opsy::utility::memory<uint32_t,lptim_cr_r> lptim_cr;
	opsy::utility::memory<uint32_t,lptim_ccr1_r> lptim_ccr1;
	opsy::utility::memory<uint32_t,lptim_arr_r> lptim_arr;
	opsy::utility::memory<uint32_t,lptim_cnt_r> lptim_cnt;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,lptim_cfgr2_r> lptim_cfgr2;
	opsy::utility::memory<uint32_t,lptim_rcr_r> lptim_rcr;
	opsy::utility::memory<uint32_t,lptim_ccmr1_r> lptim_ccmr1;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,lptim_ccr2_r> lptim_ccr2;
};

static_assert(std::is_standard_layout_v<lptim_p>);
static_assert(offsetof(lptim_p, lptim_isr_output) == 0);
static_assert(offsetof(lptim_p, lptim_isr_intput) == 0);
static_assert(offsetof(lptim_p, lptim_icr_output) == 4);
static_assert(offsetof(lptim_p, lptim_icr_intput) == 4);
static_assert(offsetof(lptim_p, lptim_dier_output) == 8);
static_assert(offsetof(lptim_p, lptim_dier_intput) == 8);
static_assert(offsetof(lptim_p, lptim_cfgr) == 12);
static_assert(offsetof(lptim_p, lptim_cr) == 16);
static_assert(offsetof(lptim_p, lptim_ccr1) == 20);
static_assert(offsetof(lptim_p, lptim_arr) == 24);
static_assert(offsetof(lptim_p, lptim_cnt) == 28);
static_assert(offsetof(lptim_p, lptim_cfgr2) == 36);
static_assert(offsetof(lptim_p, lptim_rcr) == 40);
static_assert(offsetof(lptim_p, lptim_ccmr1) == 44);
static_assert(offsetof(lptim_p, lptim_ccr2) == 52);

inline lptim_p& lptim1 = *reinterpret_cast<lptim_p*>(0x44004400);
inline lptim_p& lptim2 = *reinterpret_cast<lptim_p*>(0x40009400);
inline lptim_p& lptim3 = *reinterpret_cast<lptim_p*>(0x44004800);
inline lptim_p& lptim4 = *reinterpret_cast<lptim_p*>(0x44004C00);
inline lptim_p& lptim5 = *reinterpret_cast<lptim_p*>(0x44005000);
inline lptim_p& lptim6 = *reinterpret_cast<lptim_p*>(0x44005400);
inline lptim_p& sec_lptim1 = *reinterpret_cast<lptim_p*>(0x54004400);
inline lptim_p& sec_lptim2 = *reinterpret_cast<lptim_p*>(0x50009400);
inline lptim_p& sec_lptim3 = *reinterpret_cast<lptim_p*>(0x54004800);
inline lptim_p& sec_lptim4 = *reinterpret_cast<lptim_p*>(0x54004C00);
inline lptim_p& sec_lptim5 = *reinterpret_cast<lptim_p*>(0x54005000);
inline lptim_p& sec_lptim6 = *reinterpret_cast<lptim_p*>(0x54005400);

} // STM32H563

