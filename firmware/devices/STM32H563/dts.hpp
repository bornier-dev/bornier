#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Digital temperature sensor
 */
class dts_p {
public:

/**
 * Temperature sensor configuration register 1
 */
class dts_cfgr1_r {
public:

/**
 * Temperature sensor 1 enable bit This bit is set and cleared by software. Note: Once enabled, the temperature sensor is active after a specific delay time. The TS1_RDY flag will be set when the sensor is ready.
 */
class ts1_en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start frequency measurement on temperature sensor 1 This bit is set and cleared by software.
 */
class ts1_start_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_start_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Input trigger selection bit for temperature sensor 1 These bits are set and cleared by software. They select which input triggers a temperature measurement. Refer to Section 19.3.10: Trigger input.
 */
class ts1_intrig_sel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ts1_intrig_sel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Sampling time for temperature sensor 1 These bits allow increasing the sampling time to improve measurement precision. When the PCLK clock is selected as reference clock (REFCLK_SEL = 0), the measurement will be performed at TS1_SMP_TIME period of CLK_PTAT. When the LSE is selected as reference clock (REFCLK_SEL =1), the measurement will be performed at TS1_SMP_TIME period of LSE.
 */
class ts1_smp_time_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ts1_smp_time_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Reference clock selection bit This bit is set and cleared by software. It indicates whether the reference clock is the high speed clock (PCLK) or the low speed clock (LSE).
 */
class refclk_sel_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr refclk_sel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Quick measurement option bit This bit is set and cleared by software. It is used to increase the measurement speed by suppressing the calibration step. It is effective only when the LSE clock is used as reference clock (REFCLK_SEL=1).
 */
class q_meas_opt_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr q_meas_opt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High speed clock division ratio These bits are set and cleared by software. They can be used to define the division ratio for the main clock in order to obtain the internal frequency lower than 1 MHz required for the calibration. They are applicable only for calibration when PCLK is selected as reference clock (REFCLK_SEL=0). ...
 */
class hsref_clk_div_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hsref_clk_div_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dts_cfgr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_cfgr1_r>() const {return opsy::utility::clear_set<dts_cfgr1_r>(mask, *this);}
	constexpr auto operator|(dts_cfgr1_r other) const -> dts_cfgr1_r { return static_cast<dts_cfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_cfgr1_r> other) const -> opsy::utility::clear_set<dts_cfgr1_r> {return opsy::utility::clear_set<dts_cfgr1_r>(dts_cfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ts1_en() const -> ts1_en_f {return ts1_en_f((value_ & ts1_en_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_start() const -> ts1_start_f {return ts1_start_f((value_ & ts1_start_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_intrig_sel() const -> ts1_intrig_sel_f {return ts1_intrig_sel_f(static_cast<uint8_t>(value_ >> ts1_intrig_sel_f::offset));}
	[[nodiscard]] constexpr auto ts1_smp_time() const -> ts1_smp_time_f {return ts1_smp_time_f(static_cast<uint8_t>(value_ >> ts1_smp_time_f::offset));}
	[[nodiscard]] constexpr auto refclk_sel() const -> refclk_sel_f {return refclk_sel_f((value_ & refclk_sel_f::mask) != 0);}
	[[nodiscard]] constexpr auto q_meas_opt() const -> q_meas_opt_f {return q_meas_opt_f((value_ & q_meas_opt_f::mask) != 0);}
	[[nodiscard]] constexpr auto hsref_clk_div() const -> hsref_clk_div_f {return hsref_clk_div_f(static_cast<uint8_t>(value_ >> hsref_clk_div_f::offset));}

	constexpr dts_cfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_cfgr1_r other) const -> dts_cfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_cfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor T0 value register 1
 */
class dts_t0valr1_r {
public:

/**
 * Engineering value of the frequency measured at T0 for temperature sensor 1 This value is expressed in 0.1 kHz.
 */
class ts1_fmt0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ts1_fmt0_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dts_t0valr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_t0valr1_r>() const {return opsy::utility::clear_set<dts_t0valr1_r>(mask, *this);}
	constexpr auto operator|(dts_t0valr1_r other) const -> dts_t0valr1_r { return static_cast<dts_t0valr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_t0valr1_r> other) const -> opsy::utility::clear_set<dts_t0valr1_r> {return opsy::utility::clear_set<dts_t0valr1_r>(dts_t0valr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Engineering value of the T0 temperature for temperature sensor 1. Others: Reserved, must not be used.
 */
class ts1_t0_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ts1_t0_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dts_t0valr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_t0valr1_r>() const {return opsy::utility::clear_set<dts_t0valr1_r>(mask, *this);}
	constexpr auto operator|(dts_t0valr1_r other) const -> dts_t0valr1_r { return static_cast<dts_t0valr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_t0valr1_r> other) const -> opsy::utility::clear_set<dts_t0valr1_r> {return opsy::utility::clear_set<dts_t0valr1_r>(dts_t0valr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ts1_fmt0() const -> ts1_fmt0_f {return ts1_fmt0_f(static_cast<uint16_t>(value_ >> ts1_fmt0_f::offset));}
	[[nodiscard]] constexpr auto ts1_t0() const -> ts1_t0_f {return ts1_t0_f(static_cast<uint8_t>(value_ >> ts1_t0_f::offset));}

	constexpr dts_t0valr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_t0valr1_r other) const -> dts_t0valr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_t0valr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor ramp value register
 */
class dts_rampvalr_r {
public:

/**
 * Engineering value of the ramp coefficient for the temperature sensor 1. This value is expressed in Hz/C.
 */
class ts1_ramp_coeff_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ts1_ramp_coeff_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dts_rampvalr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_rampvalr_r>() const {return opsy::utility::clear_set<dts_rampvalr_r>(mask, *this);}
	constexpr auto operator|(dts_rampvalr_r other) const -> dts_rampvalr_r { return static_cast<dts_rampvalr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_rampvalr_r> other) const -> opsy::utility::clear_set<dts_rampvalr_r> {return opsy::utility::clear_set<dts_rampvalr_r>(dts_rampvalr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ts1_ramp_coeff() const -> ts1_ramp_coeff_f {return ts1_ramp_coeff_f(static_cast<uint16_t>(value_ >> ts1_ramp_coeff_f::offset));}

	constexpr dts_rampvalr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_rampvalr_r other) const -> dts_rampvalr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_rampvalr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor interrupt threshold register 1
 */
class dts_itr1_r {
public:

/**
 * Low interrupt threshold for temperature sensor 1 These bits are set and cleared by software. They indicate the lowest value than can be reached before raising an interrupt signal.
 */
class ts1_litthd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ts1_litthd_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dts_itr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_itr1_r>() const {return opsy::utility::clear_set<dts_itr1_r>(mask, *this);}
	constexpr auto operator|(dts_itr1_r other) const -> dts_itr1_r { return static_cast<dts_itr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itr1_r> other) const -> opsy::utility::clear_set<dts_itr1_r> {return opsy::utility::clear_set<dts_itr1_r>(dts_itr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * High interrupt threshold for temperature sensor 1 These bits are set and cleared by software. They indicate the highest value than can be reached before raising an interrupt signal.
 */
class ts1_hitthd_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ts1_hitthd_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dts_itr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_itr1_r>() const {return opsy::utility::clear_set<dts_itr1_r>(mask, *this);}
	constexpr auto operator|(dts_itr1_r other) const -> dts_itr1_r { return static_cast<dts_itr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itr1_r> other) const -> opsy::utility::clear_set<dts_itr1_r> {return opsy::utility::clear_set<dts_itr1_r>(dts_itr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ts1_litthd() const -> ts1_litthd_f {return ts1_litthd_f(static_cast<uint16_t>(value_ >> ts1_litthd_f::offset));}
	[[nodiscard]] constexpr auto ts1_hitthd() const -> ts1_hitthd_f {return ts1_hitthd_f(static_cast<uint16_t>(value_ >> ts1_hitthd_f::offset));}

	constexpr dts_itr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_itr1_r other) const -> dts_itr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_itr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor data register
 */
class dts_dr_r {
public:

/**
 * Value of the counter output value for temperature sensor 1
 */
class ts1_mfreq_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr ts1_mfreq_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dts_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dts_dr_r>() const {return opsy::utility::clear_set<dts_dr_r>(mask, *this);}
	constexpr auto operator|(dts_dr_r other) const -> dts_dr_r { return static_cast<dts_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_dr_r> other) const -> opsy::utility::clear_set<dts_dr_r> {return opsy::utility::clear_set<dts_dr_r>(dts_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto ts1_mfreq() const -> ts1_mfreq_f {return ts1_mfreq_f(static_cast<uint16_t>(value_ >> ts1_mfreq_f::offset));}

	constexpr dts_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_dr_r other) const -> dts_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor status register
 */
class dts_sr_r {
public:

/**
 * Interrupt flag for end of measurement on temperature sensor 1, synchronized on PCLK. This bit is set by hardware when a temperature measure is done. It is cleared by software by writing 1 to the TS2_CITEF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_ITEFEN bit is set
 */
class ts1_itef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_itef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt flag for low threshold on temperature sensor 1, synchronized on PCLK. This bit is set by hardware when the low threshold is set and reached. It is cleared by software by writing 1 to the TS1_CITLF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_ITLFEN bit is set
 */
class ts1_itlf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_itlf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt flag for high threshold on temperature sensor 1, synchronized on PCLK This bit is set by hardware when the high threshold is set and reached. It is cleared by software by writing 1 to the TS1_CITHF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_ITHFEN bit is set
 */
class ts1_ithf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_ithf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt flag for end of measure on temperature sensor 1 This bit is set by hardware when a temperature measure is done. It is cleared by software by writing 1 to the TS1_CAITEF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_AITEFEN bit is set
 */
class ts1_aitef_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aitef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt flag for low threshold on temperature sensor 1 This bit is set by hardware when the low threshold is reached. It is cleared by software by writing 1 to the TS1_CAITLF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_AITLFEN bit is set
 */
class ts1_aitlf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aitlf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt flag for high threshold on temperature sensor 1 This bit is set by hardware when the high threshold is reached. It is cleared by software by writing 1 to the TS1_CAITHF bit in the DTS_ICIFR register. Note: This bit is active only when the TS1_AITHFEN bit is set
 */
class ts1_aithf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aithf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Temperature sensor 1 ready flag This bit is set and reset by hardware. It indicates that a measurement is ongoing.
 */
class ts1_rdy_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts1_rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_sr_r>() const {return opsy::utility::clear_set<dts_sr_r>(mask, *this);}
	constexpr auto operator|(dts_sr_r other) const -> dts_sr_r { return static_cast<dts_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_sr_r> other) const -> opsy::utility::clear_set<dts_sr_r> {return opsy::utility::clear_set<dts_sr_r>(dts_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ts1_itef() const -> ts1_itef_f {return ts1_itef_f((value_ & ts1_itef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_itlf() const -> ts1_itlf_f {return ts1_itlf_f((value_ & ts1_itlf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_ithf() const -> ts1_ithf_f {return ts1_ithf_f((value_ & ts1_ithf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aitef() const -> ts1_aitef_f {return ts1_aitef_f((value_ & ts1_aitef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aitlf() const -> ts1_aitlf_f {return ts1_aitlf_f((value_ & ts1_aitlf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aithf() const -> ts1_aithf_f {return ts1_aithf_f((value_ & ts1_aithf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_rdy() const -> ts1_rdy_f {return ts1_rdy_f((value_ & ts1_rdy_f::mask) != 0);}

	constexpr dts_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_sr_r other) const -> dts_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor interrupt enable register
 */
class dts_itenr_r {
public:

/**
 * Interrupt enable flag for end of measurement on temperature sensor 1, synchronized on PCLK. This bit are set and cleared by software. It enables the synchronous interrupt for end of measurement.
 */
class ts1_iteen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_iteen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable flag for low threshold on temperature sensor 1, synchronized on PCLK. This bit are set and cleared by software. It enables the synchronous interrupt when the measure reaches or is below the low threshold.
 */
class ts1_itlen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_itlen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt enable flag for high threshold on temperature sensor 1, synchronized on PCLK. This bit are set and cleared by software. It enables the interrupt when the measure reaches or is above the high threshold.
 */
class ts1_ithen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_ithen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt enable flag for end of measurement on temperature sensor 1 This bit are set and cleared by software. It enables the asynchronous interrupt for end of measurement (only when REFCLK_SEL = 1).
 */
class ts1_aiteen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aiteen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt enable flag for low threshold on temperature sensor 1. This bit are set and cleared by software. It enables the asynchronous interrupt when the temperature is below the low threshold (only when REFCLK_SEL= 1)
 */
class ts1_aitlen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aitlen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt enable flag on high threshold for temperature sensor 1. This bit are set and cleared by software. It enables the asynchronous interrupt when the temperature is above the high threshold (only when REFCLK_SEL= 1'')
 */
class ts1_aithen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_aithen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_itenr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_itenr_r>() const {return opsy::utility::clear_set<dts_itenr_r>(mask, *this);}
	constexpr auto operator|(dts_itenr_r other) const -> dts_itenr_r { return static_cast<dts_itenr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_itenr_r> other) const -> opsy::utility::clear_set<dts_itenr_r> {return opsy::utility::clear_set<dts_itenr_r>(dts_itenr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ts1_iteen() const -> ts1_iteen_f {return ts1_iteen_f((value_ & ts1_iteen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_itlen() const -> ts1_itlen_f {return ts1_itlen_f((value_ & ts1_itlen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_ithen() const -> ts1_ithen_f {return ts1_ithen_f((value_ & ts1_ithen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aiteen() const -> ts1_aiteen_f {return ts1_aiteen_f((value_ & ts1_aiteen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aitlen() const -> ts1_aitlen_f {return ts1_aitlen_f((value_ & ts1_aitlen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_aithen() const -> ts1_aithen_f {return ts1_aithen_f((value_ & ts1_aithen_f::mask) != 0);}

	constexpr dts_itenr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_itenr_r other) const -> dts_itenr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_itenr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor clear interrupt flag register
 */
class dts_icifr_r {
public:

/**
 * Interrupt clear flag for end of measurement on temperature sensor 1 Writing 1 to this bit clears the TS1_ITEF flag in the DTS_SR register.
 */
class ts1_citef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_citef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt clear flag for low threshold on temperature sensor 1 Writing 1 to this bit clears the TS1_ITLF flag in the DTS_SR register.
 */
class ts1_citlf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_citlf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt clear flag for high threshold on temperature sensor 1 Writing this bit to 1 clears the TS1_ITHF flag in the DTS_SR register.
 */
class ts1_cithf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_cithf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write once bit. Clear the asynchronous IT flag for End Of Measure for thermal sensor 1. Writing 1 clears the TS1_AITEF flag of the DTS_SR register.
 */
class ts1_caitef_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_caitef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt clear flag for low threshold on temperature sensor 1 Writing 1 to this bit clears the TS1_AITLF flag in the DTS_SR register.
 */
class ts1_caitlf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_caitlf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Asynchronous interrupt clear flag for high threshold on temperature sensor 1 Writing 1 to this bit clears the TS1_AITHF flag in the DTS_SR register.
 */
class ts1_caithf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts1_caithf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_icifr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_icifr_r>() const {return opsy::utility::clear_set<dts_icifr_r>(mask, *this);}
	constexpr auto operator|(dts_icifr_r other) const -> dts_icifr_r { return static_cast<dts_icifr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_icifr_r> other) const -> opsy::utility::clear_set<dts_icifr_r> {return opsy::utility::clear_set<dts_icifr_r>(dts_icifr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ts1_citef() const -> ts1_citef_f {return ts1_citef_f((value_ & ts1_citef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_citlf() const -> ts1_citlf_f {return ts1_citlf_f((value_ & ts1_citlf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_cithf() const -> ts1_cithf_f {return ts1_cithf_f((value_ & ts1_cithf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_caitef() const -> ts1_caitef_f {return ts1_caitef_f((value_ & ts1_caitef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_caitlf() const -> ts1_caitlf_f {return ts1_caitlf_f((value_ & ts1_caitlf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts1_caithf() const -> ts1_caithf_f {return ts1_caithf_f((value_ & ts1_caithf_f::mask) != 0);}

	constexpr dts_icifr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_icifr_r other) const -> dts_icifr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_icifr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Temperature sensor option register
 */
class dts_or_r {
public:

/**
 * general purpose option bits
 */
class ts_op0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ts_op7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ts_op15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * general purpose option bits
 */
class ts_op31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ts_op31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dts_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dts_or_r>() const {return opsy::utility::clear_set<dts_or_r>(mask, *this);}
	constexpr auto operator|(dts_or_r other) const -> dts_or_r { return static_cast<dts_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dts_or_r> other) const -> opsy::utility::clear_set<dts_or_r> {return opsy::utility::clear_set<dts_or_r>(dts_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ts_op0() const -> ts_op0_f {return ts_op0_f((value_ & ts_op0_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op1() const -> ts_op1_f {return ts_op1_f((value_ & ts_op1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op2() const -> ts_op2_f {return ts_op2_f((value_ & ts_op2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op3() const -> ts_op3_f {return ts_op3_f((value_ & ts_op3_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op4() const -> ts_op4_f {return ts_op4_f((value_ & ts_op4_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op5() const -> ts_op5_f {return ts_op5_f((value_ & ts_op5_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op6() const -> ts_op6_f {return ts_op6_f((value_ & ts_op6_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op7() const -> ts_op7_f {return ts_op7_f((value_ & ts_op7_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op8() const -> ts_op8_f {return ts_op8_f((value_ & ts_op8_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op9() const -> ts_op9_f {return ts_op9_f((value_ & ts_op9_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op10() const -> ts_op10_f {return ts_op10_f((value_ & ts_op10_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op11() const -> ts_op11_f {return ts_op11_f((value_ & ts_op11_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op12() const -> ts_op12_f {return ts_op12_f((value_ & ts_op12_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op13() const -> ts_op13_f {return ts_op13_f((value_ & ts_op13_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op14() const -> ts_op14_f {return ts_op14_f((value_ & ts_op14_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op15() const -> ts_op15_f {return ts_op15_f((value_ & ts_op15_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op16() const -> ts_op16_f {return ts_op16_f((value_ & ts_op16_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op17() const -> ts_op17_f {return ts_op17_f((value_ & ts_op17_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op18() const -> ts_op18_f {return ts_op18_f((value_ & ts_op18_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op19() const -> ts_op19_f {return ts_op19_f((value_ & ts_op19_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op20() const -> ts_op20_f {return ts_op20_f((value_ & ts_op20_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op21() const -> ts_op21_f {return ts_op21_f((value_ & ts_op21_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op22() const -> ts_op22_f {return ts_op22_f((value_ & ts_op22_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op23() const -> ts_op23_f {return ts_op23_f((value_ & ts_op23_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op24() const -> ts_op24_f {return ts_op24_f((value_ & ts_op24_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op25() const -> ts_op25_f {return ts_op25_f((value_ & ts_op25_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op26() const -> ts_op26_f {return ts_op26_f((value_ & ts_op26_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op27() const -> ts_op27_f {return ts_op27_f((value_ & ts_op27_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op28() const -> ts_op28_f {return ts_op28_f((value_ & ts_op28_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op29() const -> ts_op29_f {return ts_op29_f((value_ & ts_op29_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op30() const -> ts_op30_f {return ts_op30_f((value_ & ts_op30_f::mask) != 0);}
	[[nodiscard]] constexpr auto ts_op31() const -> ts_op31_f {return ts_op31_f((value_ & ts_op31_f::mask) != 0);}

	constexpr dts_or_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dts_or_r other) const -> dts_or_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dts_or_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dts_cfgr1_r> dts_cfgr1;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,dts_t0valr1_r> dts_t0valr1;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,dts_rampvalr_r> dts_rampvalr;
	opsy::utility::memory<uint32_t,dts_itr1_r> dts_itr1;
	opsy::utility::padding<4> _p2;
	opsy::utility::memory<uint32_t,dts_dr_r> dts_dr;
	opsy::utility::memory<uint32_t,dts_sr_r> dts_sr;
	opsy::utility::memory<uint32_t,dts_itenr_r> dts_itenr;
	opsy::utility::memory<uint32_t,dts_icifr_r> dts_icifr;
	opsy::utility::memory<uint32_t,dts_or_r> dts_or;
};

static_assert(std::is_standard_layout_v<dts_p>);
static_assert(offsetof(dts_p, dts_cfgr1) == 0);
static_assert(offsetof(dts_p, dts_t0valr1) == 8);
static_assert(offsetof(dts_p, dts_rampvalr) == 16);
static_assert(offsetof(dts_p, dts_itr1) == 20);
static_assert(offsetof(dts_p, dts_dr) == 28);
static_assert(offsetof(dts_p, dts_sr) == 32);
static_assert(offsetof(dts_p, dts_itenr) == 36);
static_assert(offsetof(dts_p, dts_icifr) == 40);
static_assert(offsetof(dts_p, dts_or) == 44);

inline dts_p& dts = *reinterpret_cast<dts_p*>(0x40008C00);
inline dts_p& sec_dts = *reinterpret_cast<dts_p*>(0x50008C00);

} // STM32H563

