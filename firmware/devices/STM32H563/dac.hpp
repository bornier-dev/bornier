#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Digital to analog converter
 */
class dac_p {
public:

/**
 * DAC control register 
 */
class dac_cr_r {
public:

/**
 * DAC channel1 enable This bit is set and cleared by software to enable/disable DAC channel1.
 */
class en1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 trigger enable This bit is set and cleared by software to enable/disable DAC channel1 trigger. Note: When software trigger is selected, the transfer from the DAC_DHR1 register to the DAC_DOR1 register takes only one dac_hclk clock cycle.
 */
class ten1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ten1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 trigger selection These bits select the external event used to trigger DAC channel1 ... Refer to the trigger selection tables in for details on trigger configuration and mapping. Note: Only used if bit TEN1 = 1 (DAC channel1 trigger enabled).
 */
class tsel1_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tsel1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel1 noise/triangle wave generation enable These bits are set and cleared by software. 1x: Triangle wave generation enabled Only used if bit TEN1 = 1 (DAC channel1 trigger enabled).
 */
class wave1_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr wave1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel1 mask/amplitude selector These bits are written by software to select mask in wave generation mode or amplitude in triangle generation mode. greater than or equal 1011: Unmask bits[11:0] of LFSR/ triangle amplitude equal to 4095
 */
class mamp1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mamp1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel1 DMA enable This bit is set and cleared by software.
 */
class dmaen1_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmaen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 DMA Underrun Interrupt enable This bit is set and cleared by software.
 */
class dmaudrie1_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmaudrie1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 calibration enable This bit is set and cleared by software to enable/disable DAC channel1 calibration, it can be written only if bit EN1 = 0 into DAC_CR (the calibration mode can be entered/exit only when the DAC channel is disabled) Otherwise, the write operation is ignored.
 */
class cen1_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cen1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 enable This bit is set and cleared by software to enable/disable DAC channel2. Note: These bits are available only on dual-channel DACs. Refer to implementation.
 */
class en2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr en2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 trigger enable This bit is set and cleared by software to enable/disable DAC channel2 trigger Note: When software trigger is selected, the transfer from the DAC_DHR2 register to the DAC_DOR2 register takes only one dac_hclk clock cycle. These bits are available only on dual-channel DACs. Refer to implementation.
 */
class ten2_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ten2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 trigger selection These bits select the external event used to trigger DAC channel2 ... Refer to the trigger selection tables in for details on trigger configuration and mapping. Note: Only used if bit TEN2 = 1 (DAC channel2 trigger enabled). These bits are available only on dual-channel DACs. Refer to implementation.
 */
class tsel2_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tsel2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 noise/triangle wave generation enable These bits are set/reset by software. 1x: Triangle wave generation enabled Note: Only used if bit TEN2 = 1 (DAC channel2 trigger enabled) These bits are available only on dual-channel DACs. Refer to implementation.
 */
class wave2_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wave2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 mask/amplitude selector These bits are written by software to select mask in wave generation mode or amplitude in triangle generation mode. greater than or equal 1011: Unmask bits[11:0] of LFSR/ triangle amplitude equal to 4095 Note: These bits are available only on dual-channel DACs. Refer to implementation.
 */
class mamp2_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mamp2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 DMA enable This bit is set and cleared by software. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dmaen2_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaen2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 DMA underrun interrupt enable This bit is set and cleared by software. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dmaudrie2_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaudrie2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 calibration enable This bit is set and cleared by software to enable/disable DAC channel2 calibration, it can be written only if EN2 bit is set to 0 into DAC_CR (the calibration mode can be entered/exit only when the DAC channel is disabled) Otherwise, the write operation is ignored. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class cen2_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cen2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_cr_r>() const {return opsy::utility::clear_set<dac_cr_r>(mask, *this);}
	constexpr auto operator|(dac_cr_r other) const -> dac_cr_r { return static_cast<dac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_cr_r> other) const -> opsy::utility::clear_set<dac_cr_r> {return opsy::utility::clear_set<dac_cr_r>(dac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto en1() const -> en1_f {return en1_f((value_ & en1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ten1() const -> ten1_f {return ten1_f((value_ & ten1_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsel1() const -> tsel1_f {return tsel1_f(static_cast<uint8_t>(value_ >> tsel1_f::offset));}
	[[nodiscard]] constexpr auto wave1() const -> wave1_f {return wave1_f(static_cast<uint8_t>(value_ >> wave1_f::offset));}
	[[nodiscard]] constexpr auto mamp1() const -> mamp1_f {return mamp1_f(static_cast<uint8_t>(value_ >> mamp1_f::offset));}
	[[nodiscard]] constexpr auto dmaen1() const -> dmaen1_f {return dmaen1_f((value_ & dmaen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaudrie1() const -> dmaudrie1_f {return dmaudrie1_f((value_ & dmaudrie1_f::mask) != 0);}
	[[nodiscard]] constexpr auto cen1() const -> cen1_f {return cen1_f((value_ & cen1_f::mask) != 0);}
	[[nodiscard]] constexpr auto en2() const -> en2_f {return en2_f((value_ & en2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ten2() const -> ten2_f {return ten2_f((value_ & ten2_f::mask) != 0);}
	[[nodiscard]] constexpr auto tsel2() const -> tsel2_f {return tsel2_f(static_cast<uint8_t>(value_ >> tsel2_f::offset));}
	[[nodiscard]] constexpr auto wave2() const -> wave2_f {return wave2_f(static_cast<uint8_t>(value_ >> wave2_f::offset));}
	[[nodiscard]] constexpr auto mamp2() const -> mamp2_f {return mamp2_f(static_cast<uint8_t>(value_ >> mamp2_f::offset));}
	[[nodiscard]] constexpr auto dmaen2() const -> dmaen2_f {return dmaen2_f((value_ & dmaen2_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaudrie2() const -> dmaudrie2_f {return dmaudrie2_f((value_ & dmaudrie2_f::mask) != 0);}
	[[nodiscard]] constexpr auto cen2() const -> cen2_f {return cen2_f((value_ & cen2_f::mask) != 0);}

	constexpr dac_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_cr_r other) const -> dac_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC software trigger register 
 */
class dac_swtrgr_r {
public:

/**
 * DAC channel1 software trigger This bit is set by software to trigger the DAC in software trigger mode. Note: This bit is cleared by hardware (one dac_hclk clock cycle later) once the DAC_DHR1 register value has been loaded into the DAC_DOR1 register.
 */
class swtrig1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swtrig1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_swtrgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_swtrgr_r>() const {return opsy::utility::clear_set<dac_swtrgr_r>(mask, *this);}
	constexpr auto operator|(dac_swtrgr_r other) const -> dac_swtrgr_r { return static_cast<dac_swtrgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_swtrgr_r> other) const -> opsy::utility::clear_set<dac_swtrgr_r> {return opsy::utility::clear_set<dac_swtrgr_r>(dac_swtrgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 software trigger This bit is set by software to trigger the DAC in software trigger mode. Note: This bit is cleared by hardware (one dac_hclk clock cycle later) once the DAC_DHR2 register value has been loaded into the DAC_DOR2 register. This bit is available only on dual-channel DACs. Refer to implementation.
 */
class swtrig2_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swtrig2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_swtrgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_swtrgr_r>() const {return opsy::utility::clear_set<dac_swtrgr_r>(mask, *this);}
	constexpr auto operator|(dac_swtrgr_r other) const -> dac_swtrgr_r { return static_cast<dac_swtrgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_swtrgr_r> other) const -> opsy::utility::clear_set<dac_swtrgr_r> {return opsy::utility::clear_set<dac_swtrgr_r>(dac_swtrgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto swtrig1() const -> swtrig1_f {return swtrig1_f((value_ & swtrig1_f::mask) != 0);}
	[[nodiscard]] constexpr auto swtrig2() const -> swtrig2_f {return swtrig2_f((value_ & swtrig2_f::mask) != 0);}

	constexpr dac_swtrgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_swtrgr_r other) const -> dac_swtrgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_swtrgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel1 12-bit right-aligned data holding register 
 */
class dac_dhr12r1_r {
public:

/**
 * DAC channel1 12-bit right-aligned data These bits are written by software. They specify 12-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12r1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12r1_r>() const {return opsy::utility::clear_set<dac_dhr12r1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12r1_r other) const -> dac_dhr12r1_r { return static_cast<dac_dhr12r1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12r1_r> other) const -> opsy::utility::clear_set<dac_dhr12r1_r> {return opsy::utility::clear_set<dac_dhr12r1_r>(dac_dhr12r1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel1 12-bit right-aligned data B These bits are written by software. They specify 12-bit data for DAC channel1 when the DAC operates in Double data mode.
 */
class dacc1dhrb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc1dhrb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12r1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12r1_r>() const {return opsy::utility::clear_set<dac_dhr12r1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12r1_r other) const -> dac_dhr12r1_r { return static_cast<dac_dhr12r1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12r1_r> other) const -> opsy::utility::clear_set<dac_dhr12r1_r> {return opsy::utility::clear_set<dac_dhr12r1_r>(dac_dhr12r1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint16_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc1dhrb() const -> dacc1dhrb_f {return dacc1dhrb_f(static_cast<uint16_t>(value_ >> dacc1dhrb_f::offset));}

	constexpr dac_dhr12r1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12r1_r other) const -> dac_dhr12r1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12r1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel1 12-bit left aligned data holding register 
 */
class dac_dhr12l1_r {
public:

/**
 * DAC channel1 12-bit left-aligned data These bits are written by software. They specify 12-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12l1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12l1_r>() const {return opsy::utility::clear_set<dac_dhr12l1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12l1_r other) const -> dac_dhr12l1_r { return static_cast<dac_dhr12l1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12l1_r> other) const -> opsy::utility::clear_set<dac_dhr12l1_r> {return opsy::utility::clear_set<dac_dhr12l1_r>(dac_dhr12l1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel1 12-bit left-aligned data B These bits are written by software. They specify 12-bit data for DAC channel1 when the DAC operates in Double data mode.
 */
class dacc1dhrb_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc1dhrb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12l1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12l1_r>() const {return opsy::utility::clear_set<dac_dhr12l1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12l1_r other) const -> dac_dhr12l1_r { return static_cast<dac_dhr12l1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12l1_r> other) const -> opsy::utility::clear_set<dac_dhr12l1_r> {return opsy::utility::clear_set<dac_dhr12l1_r>(dac_dhr12l1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint16_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc1dhrb() const -> dacc1dhrb_f {return dacc1dhrb_f(static_cast<uint16_t>(value_ >> dacc1dhrb_f::offset));}

	constexpr dac_dhr12l1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12l1_r other) const -> dac_dhr12l1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12l1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel1 8-bit right aligned data holding register 
 */
class dac_dhr8r1_r {
public:

/**
 * DAC channel1 8-bit right-aligned data These bits are written by software. They specify 8-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dacc1dhr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8r1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8r1_r>() const {return opsy::utility::clear_set<dac_dhr8r1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8r1_r other) const -> dac_dhr8r1_r { return static_cast<dac_dhr8r1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8r1_r> other) const -> opsy::utility::clear_set<dac_dhr8r1_r> {return opsy::utility::clear_set<dac_dhr8r1_r>(dac_dhr8r1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel1 8-bit right-aligned data These bits are written by software. They specify 8-bit data for DAC channel1 when the DAC operates in Double data mode.
 */
class dacc1dhrb_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dhrb_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8r1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8r1_r>() const {return opsy::utility::clear_set<dac_dhr8r1_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8r1_r other) const -> dac_dhr8r1_r { return static_cast<dac_dhr8r1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8r1_r> other) const -> opsy::utility::clear_set<dac_dhr8r1_r> {return opsy::utility::clear_set<dac_dhr8r1_r>(dac_dhr8r1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint8_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc1dhrb() const -> dacc1dhrb_f {return dacc1dhrb_f(static_cast<uint8_t>(value_ >> dacc1dhrb_f::offset));}

	constexpr dac_dhr8r1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr8r1_r other) const -> dac_dhr8r1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr8r1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel2 12-bit right aligned data holding register 
 */
class dac_dhr12r2_r {
public:

/**
 * DAC channel2 12-bit right-aligned data These bits are written by software. They specify 12-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc2dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12r2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12r2_r>() const {return opsy::utility::clear_set<dac_dhr12r2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12r2_r other) const -> dac_dhr12r2_r { return static_cast<dac_dhr12r2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12r2_r> other) const -> opsy::utility::clear_set<dac_dhr12r2_r> {return opsy::utility::clear_set<dac_dhr12r2_r>(dac_dhr12r2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 12-bit right-aligned data These bits are written by software. They specify 12-bit data for DAC channel2 when the DAC operates in DMA Double data mode.
 */
class dacc2dhrb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc2dhrb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12r2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12r2_r>() const {return opsy::utility::clear_set<dac_dhr12r2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12r2_r other) const -> dac_dhr12r2_r { return static_cast<dac_dhr12r2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12r2_r> other) const -> opsy::utility::clear_set<dac_dhr12r2_r> {return opsy::utility::clear_set<dac_dhr12r2_r>(dac_dhr12r2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint16_t>(value_ >> dacc2dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhrb() const -> dacc2dhrb_f {return dacc2dhrb_f(static_cast<uint16_t>(value_ >> dacc2dhrb_f::offset));}

	constexpr dac_dhr12r2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12r2_r other) const -> dac_dhr12r2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12r2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel2 12-bit left aligned data holding register 
 */
class dac_dhr12l2_r {
public:

/**
 * DAC channel2 12-bit left-aligned data These bits are written by software which specify 12-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc2dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12l2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12l2_r>() const {return opsy::utility::clear_set<dac_dhr12l2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12l2_r other) const -> dac_dhr12l2_r { return static_cast<dac_dhr12l2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12l2_r> other) const -> opsy::utility::clear_set<dac_dhr12l2_r> {return opsy::utility::clear_set<dac_dhr12l2_r>(dac_dhr12l2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 12-bit left-aligned data B These bits are written by software. They specify 12-bit data for DAC channel2 when the DAC operates in Double data mode.
 */
class dacc2dhrb_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc2dhrb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12l2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12l2_r>() const {return opsy::utility::clear_set<dac_dhr12l2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12l2_r other) const -> dac_dhr12l2_r { return static_cast<dac_dhr12l2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12l2_r> other) const -> opsy::utility::clear_set<dac_dhr12l2_r> {return opsy::utility::clear_set<dac_dhr12l2_r>(dac_dhr12l2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint16_t>(value_ >> dacc2dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhrb() const -> dacc2dhrb_f {return dacc2dhrb_f(static_cast<uint16_t>(value_ >> dacc2dhrb_f::offset));}

	constexpr dac_dhr12l2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12l2_r other) const -> dac_dhr12l2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12l2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel2 8-bit right-aligned data holding register 
 */
class dac_dhr8r2_r {
public:

/**
 * DAC channel2 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dacc2dhr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8r2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8r2_r>() const {return opsy::utility::clear_set<dac_dhr8r2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8r2_r other) const -> dac_dhr8r2_r { return static_cast<dac_dhr8r2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8r2_r> other) const -> opsy::utility::clear_set<dac_dhr8r2_r> {return opsy::utility::clear_set<dac_dhr8r2_r>(dac_dhr8r2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 8-bit right-aligned data These bits are written by software. They specify 8-bit data for DAC channel2 when the DAC operates in Double data mode.
 */
class dacc2dhrb_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc2dhrb_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8r2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8r2_r>() const {return opsy::utility::clear_set<dac_dhr8r2_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8r2_r other) const -> dac_dhr8r2_r { return static_cast<dac_dhr8r2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8r2_r> other) const -> opsy::utility::clear_set<dac_dhr8r2_r> {return opsy::utility::clear_set<dac_dhr8r2_r>(dac_dhr8r2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint8_t>(value_ >> dacc2dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhrb() const -> dacc2dhrb_f {return dacc2dhrb_f(static_cast<uint8_t>(value_ >> dacc2dhrb_f::offset));}

	constexpr dac_dhr8r2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr8r2_r other) const -> dac_dhr8r2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr8r2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Dual DAC 12-bit right-aligned data holding register 
 */
class dac_dhr12rd_r {
public:

/**
 * DAC channel1 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12rd_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12rd_r>() const {return opsy::utility::clear_set<dac_dhr12rd_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12rd_r other) const -> dac_dhr12rd_r { return static_cast<dac_dhr12rd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12rd_r> other) const -> opsy::utility::clear_set<dac_dhr12rd_r> {return opsy::utility::clear_set<dac_dhr12rd_r>(dac_dhr12rd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 12-bit right-aligned data These bits are written by software which specifies 12-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc2dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12rd_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12rd_r>() const {return opsy::utility::clear_set<dac_dhr12rd_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12rd_r other) const -> dac_dhr12rd_r { return static_cast<dac_dhr12rd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12rd_r> other) const -> opsy::utility::clear_set<dac_dhr12rd_r> {return opsy::utility::clear_set<dac_dhr12rd_r>(dac_dhr12rd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint16_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint16_t>(value_ >> dacc2dhr_f::offset));}

	constexpr dac_dhr12rd_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12rd_r other) const -> dac_dhr12rd_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12rd_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Dual DAC 12-bit left aligned data holding register 
 */
class dac_dhr12ld_r {
public:

/**
 * DAC channel1 12-bit left-aligned data These bits are written by software which specifies 12-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12ld_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12ld_r>() const {return opsy::utility::clear_set<dac_dhr12ld_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12ld_r other) const -> dac_dhr12ld_r { return static_cast<dac_dhr12ld_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12ld_r> other) const -> opsy::utility::clear_set<dac_dhr12ld_r> {return opsy::utility::clear_set<dac_dhr12ld_r>(dac_dhr12ld_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 12-bit left-aligned data These bits are written by software which specifies 12-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc2dhr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dhr12ld_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr12ld_r>() const {return opsy::utility::clear_set<dac_dhr12ld_r>(mask, *this);}
	constexpr auto operator|(dac_dhr12ld_r other) const -> dac_dhr12ld_r { return static_cast<dac_dhr12ld_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr12ld_r> other) const -> opsy::utility::clear_set<dac_dhr12ld_r> {return opsy::utility::clear_set<dac_dhr12ld_r>(dac_dhr12ld_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint16_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint16_t>(value_ >> dacc2dhr_f::offset));}

	constexpr dac_dhr12ld_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr12ld_r other) const -> dac_dhr12ld_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr12ld_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Dual DAC 8-bit right aligned data holding register 
 */
class dac_dhr8rd_r {
public:

/**
 * DAC channel1 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel1.
 */
class dacc1dhr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dacc1dhr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8rd_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8rd_r>() const {return opsy::utility::clear_set<dac_dhr8rd_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8rd_r other) const -> dac_dhr8rd_r { return static_cast<dac_dhr8rd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8rd_r> other) const -> opsy::utility::clear_set<dac_dhr8rd_r> {return opsy::utility::clear_set<dac_dhr8rd_r>(dac_dhr8rd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 8-bit right-aligned data These bits are written by software which specifies 8-bit data for DAC channel2.
 */
class dacc2dhr_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc2dhr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_dhr8rd_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dhr8rd_r>() const {return opsy::utility::clear_set<dac_dhr8rd_r>(mask, *this);}
	constexpr auto operator|(dac_dhr8rd_r other) const -> dac_dhr8rd_r { return static_cast<dac_dhr8rd_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dhr8rd_r> other) const -> opsy::utility::clear_set<dac_dhr8rd_r> {return opsy::utility::clear_set<dac_dhr8rd_r>(dac_dhr8rd_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dacc1dhr() const -> dacc1dhr_f {return dacc1dhr_f(static_cast<uint8_t>(value_ >> dacc1dhr_f::offset));}
	[[nodiscard]] constexpr auto dacc2dhr() const -> dacc2dhr_f {return dacc2dhr_f(static_cast<uint8_t>(value_ >> dacc2dhr_f::offset));}

	constexpr dac_dhr8rd_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dhr8rd_r other) const -> dac_dhr8rd_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dhr8rd_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel1 data output register 
 */
class dac_dor1_r {
public:

/**
 * DAC channel1 data output These bits are read-only, they contain data output for DAC channel1.
 */
class dacc1dor_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc1dor_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dor1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dor1_r>() const {return opsy::utility::clear_set<dac_dor1_r>(mask, *this);}
	constexpr auto operator|(dac_dor1_r other) const -> dac_dor1_r { return static_cast<dac_dor1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dor1_r> other) const -> opsy::utility::clear_set<dac_dor1_r> {return opsy::utility::clear_set<dac_dor1_r>(dac_dor1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel1 data output These bits are read-only. They contain data output for DAC channel1 B.
 */
class dacc1dorb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc1dorb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dor1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dor1_r>() const {return opsy::utility::clear_set<dac_dor1_r>(mask, *this);}
	constexpr auto operator|(dac_dor1_r other) const -> dac_dor1_r { return static_cast<dac_dor1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dor1_r> other) const -> opsy::utility::clear_set<dac_dor1_r> {return opsy::utility::clear_set<dac_dor1_r>(dac_dor1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc1dor() const -> dacc1dor_f {return dacc1dor_f(static_cast<uint16_t>(value_ >> dacc1dor_f::offset));}
	[[nodiscard]] constexpr auto dacc1dorb() const -> dacc1dorb_f {return dacc1dorb_f(static_cast<uint16_t>(value_ >> dacc1dorb_f::offset));}

	constexpr dac_dor1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dor1_r other) const -> dac_dor1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dor1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel2 data output register 
 */
class dac_dor2_r {
public:

/**
 * DAC channel2 data output These bits are read-only, they contain data output for DAC channel2.
 */
class dacc2dor_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dacc2dor_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dor2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dor2_r>() const {return opsy::utility::clear_set<dac_dor2_r>(mask, *this);}
	constexpr auto operator|(dac_dor2_r other) const -> dac_dor2_r { return static_cast<dac_dor2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dor2_r> other) const -> opsy::utility::clear_set<dac_dor2_r> {return opsy::utility::clear_set<dac_dor2_r>(dac_dor2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 data output These bits are read-only. They contain data output for DAC channel2 B.
 */
class dacc2dorb_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 12;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dacc2dorb_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_dor2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_dor2_r>() const {return opsy::utility::clear_set<dac_dor2_r>(mask, *this);}
	constexpr auto operator|(dac_dor2_r other) const -> dac_dor2_r { return static_cast<dac_dor2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_dor2_r> other) const -> opsy::utility::clear_set<dac_dor2_r> {return opsy::utility::clear_set<dac_dor2_r>(dac_dor2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto dacc2dor() const -> dacc2dor_f {return dacc2dor_f(static_cast<uint16_t>(value_ >> dacc2dor_f::offset));}
	[[nodiscard]] constexpr auto dacc2dorb() const -> dacc2dorb_f {return dacc2dorb_f(static_cast<uint16_t>(value_ >> dacc2dorb_f::offset));}

	constexpr dac_dor2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_dor2_r other) const -> dac_dor2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_dor2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC status register 
 */
class dac_sr_r {
public:

/**
 * DAC channel1 ready status bit This bit is set and cleared by hardware.
 */
class dac1rdy_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dac1rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 output register status bit This bit is set and cleared by hardware. It is applicable only when the DAC operates in Double data mode.
 */
class dorstat1_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dorstat1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 DMA underrun flag This bit is set by hardware and cleared by software (by writing it to 1).
 */
class dmaudr1_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmaudr1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 calibration offset status This bit is set and cleared by hardware
 */
class cal_flag1_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cal_flag1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel1 busy writing sample time flag This bit is systematically set just after Sample and hold mode enable and is set each time the software writes the register DAC_SHSR1, It is cleared by hardware when the write operation of DAC_SHSR1 is complete. (It takes about 3 LSI/LSE periods of synchronization).
 */
class bwst1_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bwst1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 ready status bit This bit is set and cleared by hardware. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dac2rdy_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dac2rdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 output register status bit This bit is set and cleared by hardware. It is applicable only when the DAC operates in Double data mode. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dorstat2_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dorstat2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 DMA underrun flag This bit is set by hardware and cleared by software (by writing it to 1). Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dmaudr2_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaudr2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 calibration offset status This bit is set and cleared by hardware Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class cal_flag2_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cal_flag2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 busy writing sample time flag This bit is systematically set just after Sample and hold mode enable. It is set each time the software writes the register DAC_SHSR2, It is cleared by hardware when the write operation of DAC_SHSR2 is complete. (It takes about 3 LSI/LSE periods of synchronization). Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class bwst2_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bwst2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_sr_r>() const {return opsy::utility::clear_set<dac_sr_r>(mask, *this);}
	constexpr auto operator|(dac_sr_r other) const -> dac_sr_r { return static_cast<dac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_sr_r> other) const -> opsy::utility::clear_set<dac_sr_r> {return opsy::utility::clear_set<dac_sr_r>(dac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dac1rdy() const -> dac1rdy_f {return dac1rdy_f((value_ & dac1rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto dorstat1() const -> dorstat1_f {return dorstat1_f((value_ & dorstat1_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaudr1() const -> dmaudr1_f {return dmaudr1_f((value_ & dmaudr1_f::mask) != 0);}
	[[nodiscard]] constexpr auto cal_flag1() const -> cal_flag1_f {return cal_flag1_f((value_ & cal_flag1_f::mask) != 0);}
	[[nodiscard]] constexpr auto bwst1() const -> bwst1_f {return bwst1_f((value_ & bwst1_f::mask) != 0);}
	[[nodiscard]] constexpr auto dac2rdy() const -> dac2rdy_f {return dac2rdy_f((value_ & dac2rdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto dorstat2() const -> dorstat2_f {return dorstat2_f((value_ & dorstat2_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaudr2() const -> dmaudr2_f {return dmaudr2_f((value_ & dmaudr2_f::mask) != 0);}
	[[nodiscard]] constexpr auto cal_flag2() const -> cal_flag2_f {return cal_flag2_f((value_ & cal_flag2_f::mask) != 0);}
	[[nodiscard]] constexpr auto bwst2() const -> bwst2_f {return bwst2_f((value_ & bwst2_f::mask) != 0);}

	constexpr dac_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_sr_r other) const -> dac_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC calibration control register 
 */
class dac_ccr_r {
public:

/**
 * DAC channel1 offset trimming value
 */
class otrim1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr otrim1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_ccr_r>() const {return opsy::utility::clear_set<dac_ccr_r>(mask, *this);}
	constexpr auto operator|(dac_ccr_r other) const -> dac_ccr_r { return static_cast<dac_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_ccr_r> other) const -> opsy::utility::clear_set<dac_ccr_r> {return opsy::utility::clear_set<dac_ccr_r>(dac_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 offset trimming value These bits are available only on dual-channel DACs. Refer to implementation.
 */
class otrim2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr otrim2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_ccr_r>() const {return opsy::utility::clear_set<dac_ccr_r>(mask, *this);}
	constexpr auto operator|(dac_ccr_r other) const -> dac_ccr_r { return static_cast<dac_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_ccr_r> other) const -> opsy::utility::clear_set<dac_ccr_r> {return opsy::utility::clear_set<dac_ccr_r>(dac_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto otrim1() const -> otrim1_f {return otrim1_f(static_cast<uint8_t>(value_ >> otrim1_f::offset));}
	[[nodiscard]] constexpr auto otrim2() const -> otrim2_f {return otrim2_f(static_cast<uint8_t>(value_ >> otrim2_f::offset));}

	constexpr dac_ccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_ccr_r other) const -> dac_ccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_ccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC mode control register 
 */
class dac_mcr_r {
public:

/**
 * DAC channel1 mode These bits can be written only when the DAC is disabled and not in the calibration mode (when bit EN1 = 0 and bit CEN1 = 0 in the DAC_CR register). If EN1 = 1 or CEN1 = 1 the write operation is ignored. They can be set and cleared by software to select the DAC channel1 mode: DAC channel1 in Normal mode DAC channel1 in sample & hold mode Note: This register can be modified only when EN1 = 0.
 */
class mode1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mode1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_mcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel1 DMA double data mode This bit is set and cleared by software.
 */
class dmadouble1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmadouble1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable signed format for DAC channel1 This bit is set and cleared by software.
 */
class sinformat1_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sinformat1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High frequency interface mode selection
 */
class hfsel0_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hfsel0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * High frequency interface mode selection
 */
class hfsel1_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr hfsel1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DAC channel2 mode These bits can be written only when the DAC is disabled and not in the calibration mode (when bit EN2 = 0 and bit CEN2 = 0 in the DAC_CR register). If EN2 = 1 or CEN2 = 1 the write operation is ignored. They can be set and cleared by software to select the DAC channel2 mode: DAC channel2 in Normal mode DAC channel2 in Sample and hold mode Note: This register can be modified only when EN2 = 0. Refer to for the availability of DAC channel2.
 */
class mode2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mode2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_mcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 DMA double data mode This bit is set and cleared by software. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class dmadouble2_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmadouble2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable signed format for DAC channel2 This bit is set and cleared by software. Note: This bit is available only on dual-channel DACs. Refer to implementation.
 */
class sinformat2_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sinformat2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dac_mcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dac_mcr_r>() const {return opsy::utility::clear_set<dac_mcr_r>(mask, *this);}
	constexpr auto operator|(dac_mcr_r other) const -> dac_mcr_r { return static_cast<dac_mcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_mcr_r> other) const -> opsy::utility::clear_set<dac_mcr_r> {return opsy::utility::clear_set<dac_mcr_r>(dac_mcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mode1() const -> mode1_f {return mode1_f(static_cast<uint8_t>(value_ >> mode1_f::offset));}
	[[nodiscard]] constexpr auto dmadouble1() const -> dmadouble1_f {return dmadouble1_f((value_ & dmadouble1_f::mask) != 0);}
	[[nodiscard]] constexpr auto sinformat1() const -> sinformat1_f {return sinformat1_f((value_ & sinformat1_f::mask) != 0);}
	[[nodiscard]] constexpr auto hfsel0() const -> hfsel0_f {return hfsel0_f((value_ & hfsel0_f::mask) != 0);}
	[[nodiscard]] constexpr auto hfsel1() const -> hfsel1_f {return hfsel1_f((value_ & hfsel1_f::mask) != 0);}
	[[nodiscard]] constexpr auto mode2() const -> mode2_f {return mode2_f(static_cast<uint8_t>(value_ >> mode2_f::offset));}
	[[nodiscard]] constexpr auto dmadouble2() const -> dmadouble2_f {return dmadouble2_f((value_ & dmadouble2_f::mask) != 0);}
	[[nodiscard]] constexpr auto sinformat2() const -> sinformat2_f {return sinformat2_f((value_ & sinformat2_f::mask) != 0);}

	constexpr dac_mcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_mcr_r other) const -> dac_mcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_mcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel1 sample and hold sample time register 
 */
class dac_shsr1_r {
public:

/**
 * DAC channel1 sample time (only valid in Sample and hold mode) These bits can be written when the DAC channel1 is disabled or also during normal operation. in the latter case, the write can be done only when BWST1 of DAC_SR register is low, If BWST1 = 1, the write operation is ignored.
 */
class tsample1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tsample1_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_shsr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shsr1_r>() const {return opsy::utility::clear_set<dac_shsr1_r>(mask, *this);}
	constexpr auto operator|(dac_shsr1_r other) const -> dac_shsr1_r { return static_cast<dac_shsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shsr1_r> other) const -> opsy::utility::clear_set<dac_shsr1_r> {return opsy::utility::clear_set<dac_shsr1_r>(dac_shsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tsample1() const -> tsample1_f {return tsample1_f(static_cast<uint16_t>(value_ >> tsample1_f::offset));}

	constexpr dac_shsr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_shsr1_r other) const -> dac_shsr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_shsr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC channel2 sample and hold sample time register 
 */
class dac_shsr2_r {
public:

/**
 * DAC channel2 sample time (only valid in Sample and hold mode) These bits can be written when the DAC channel2 is disabled or also during normal operation. in the latter case, the write can be done only when BWST2 of DAC_SR register is low, if BWST2 = 1, the write operation is ignored.
 */
class tsample2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tsample2_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_shsr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shsr2_r>() const {return opsy::utility::clear_set<dac_shsr2_r>(mask, *this);}
	constexpr auto operator|(dac_shsr2_r other) const -> dac_shsr2_r { return static_cast<dac_shsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shsr2_r> other) const -> opsy::utility::clear_set<dac_shsr2_r> {return opsy::utility::clear_set<dac_shsr2_r>(dac_shsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tsample2() const -> tsample2_f {return tsample2_f(static_cast<uint16_t>(value_ >> tsample2_f::offset));}

	constexpr dac_shsr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_shsr2_r other) const -> dac_shsr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_shsr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DAC sample and hold time register 
 */
class dac_shhr_r {
public:

/**
 * DAC channel1 hold time (only valid in Sample and hold mode) Hold time = (THOLD[9:0]) x LSI/LSE clock period Note: This register can be modified only when EN1 = 0.
 */
class thold1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr thold1_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_shhr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shhr_r>() const {return opsy::utility::clear_set<dac_shhr_r>(mask, *this);}
	constexpr auto operator|(dac_shhr_r other) const -> dac_shhr_r { return static_cast<dac_shhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shhr_r> other) const -> opsy::utility::clear_set<dac_shhr_r> {return opsy::utility::clear_set<dac_shhr_r>(dac_shhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * DAC channel2 hold time (only valid in Sample and hold mode). Hold time = (THOLD[9:0]) x LSI/LSE clock period Note: This register can be modified only when EN2 = 0. These bits are available only on dual-channel DACs. Refer to implementation.
 */
class thold2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr thold2_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dac_shhr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shhr_r>() const {return opsy::utility::clear_set<dac_shhr_r>(mask, *this);}
	constexpr auto operator|(dac_shhr_r other) const -> dac_shhr_r { return static_cast<dac_shhr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shhr_r> other) const -> opsy::utility::clear_set<dac_shhr_r> {return opsy::utility::clear_set<dac_shhr_r>(dac_shhr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto thold1() const -> thold1_f {return thold1_f(static_cast<uint16_t>(value_ >> thold1_f::offset));}
	[[nodiscard]] constexpr auto thold2() const -> thold2_f {return thold2_f(static_cast<uint16_t>(value_ >> thold2_f::offset));}

	constexpr dac_shhr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_shhr_r other) const -> dac_shhr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_shhr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000001; // 65537 0x10001

private:
	uint32_t value_;
};

/**
 * DAC sample and hold refresh time register 
 */
class dac_shrr_r {
public:

/**
 * DAC channel1 refresh time (only valid in Sample and hold mode) Refresh time = (TREFRESH[7:0]) x LSI/LSE clock period Note: This register can be modified only when EN1 = 0.
 */
class trefresh1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr trefresh1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_shrr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shrr_r>() const {return opsy::utility::clear_set<dac_shrr_r>(mask, *this);}
	constexpr auto operator|(dac_shrr_r other) const -> dac_shrr_r { return static_cast<dac_shrr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shrr_r> other) const -> opsy::utility::clear_set<dac_shrr_r> {return opsy::utility::clear_set<dac_shrr_r>(dac_shrr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DAC channel2 refresh time (only valid in Sample and hold mode) Refresh time = (TREFRESH[7:0]) x LSI/LSE clock period Note: This register can be modified only when EN2 = 0. These bits are available only on dual-channel DACs. Refer to implementation.
 */
class trefresh2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trefresh2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dac_shrr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dac_shrr_r>() const {return opsy::utility::clear_set<dac_shrr_r>(mask, *this);}
	constexpr auto operator|(dac_shrr_r other) const -> dac_shrr_r { return static_cast<dac_shrr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dac_shrr_r> other) const -> opsy::utility::clear_set<dac_shrr_r> {return opsy::utility::clear_set<dac_shrr_r>(dac_shrr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto trefresh1() const -> trefresh1_f {return trefresh1_f(static_cast<uint8_t>(value_ >> trefresh1_f::offset));}
	[[nodiscard]] constexpr auto trefresh2() const -> trefresh2_f {return trefresh2_f(static_cast<uint8_t>(value_ >> trefresh2_f::offset));}

	constexpr dac_shrr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dac_shrr_r other) const -> dac_shrr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dac_shrr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b10000000000000001; // 65537 0x10001

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dac_cr_r> dac_cr;
	opsy::utility::memory<uint32_t,dac_swtrgr_r> dac_swtrgr;
	opsy::utility::memory<uint32_t,dac_dhr12r1_r> dac_dhr12r1;
	opsy::utility::memory<uint32_t,dac_dhr12l1_r> dac_dhr12l1;
	opsy::utility::memory<uint32_t,dac_dhr8r1_r> dac_dhr8r1;
	opsy::utility::memory<uint32_t,dac_dhr12r2_r> dac_dhr12r2;
	opsy::utility::memory<uint32_t,dac_dhr12l2_r> dac_dhr12l2;
	opsy::utility::memory<uint32_t,dac_dhr8r2_r> dac_dhr8r2;
	opsy::utility::memory<uint32_t,dac_dhr12rd_r> dac_dhr12rd;
	opsy::utility::memory<uint32_t,dac_dhr12ld_r> dac_dhr12ld;
	opsy::utility::memory<uint32_t,dac_dhr8rd_r> dac_dhr8rd;
	opsy::utility::memory<uint32_t,dac_dor1_r> dac_dor1;
	opsy::utility::memory<uint32_t,dac_dor2_r> dac_dor2;
	opsy::utility::memory<uint32_t,dac_sr_r> dac_sr;
	opsy::utility::memory<uint32_t,dac_ccr_r> dac_ccr;
	opsy::utility::memory<uint32_t,dac_mcr_r> dac_mcr;
	opsy::utility::memory<uint32_t,dac_shsr1_r> dac_shsr1;
	opsy::utility::memory<uint32_t,dac_shsr2_r> dac_shsr2;
	opsy::utility::memory<uint32_t,dac_shhr_r> dac_shhr;
	opsy::utility::memory<uint32_t,dac_shrr_r> dac_shrr;
};

static_assert(std::is_standard_layout_v<dac_p>);
static_assert(offsetof(dac_p, dac_cr) == 0);
static_assert(offsetof(dac_p, dac_swtrgr) == 4);
static_assert(offsetof(dac_p, dac_dhr12r1) == 8);
static_assert(offsetof(dac_p, dac_dhr12l1) == 12);
static_assert(offsetof(dac_p, dac_dhr8r1) == 16);
static_assert(offsetof(dac_p, dac_dhr12r2) == 20);
static_assert(offsetof(dac_p, dac_dhr12l2) == 24);
static_assert(offsetof(dac_p, dac_dhr8r2) == 28);
static_assert(offsetof(dac_p, dac_dhr12rd) == 32);
static_assert(offsetof(dac_p, dac_dhr12ld) == 36);
static_assert(offsetof(dac_p, dac_dhr8rd) == 40);
static_assert(offsetof(dac_p, dac_dor1) == 44);
static_assert(offsetof(dac_p, dac_dor2) == 48);
static_assert(offsetof(dac_p, dac_sr) == 52);
static_assert(offsetof(dac_p, dac_ccr) == 56);
static_assert(offsetof(dac_p, dac_mcr) == 60);
static_assert(offsetof(dac_p, dac_shsr1) == 64);
static_assert(offsetof(dac_p, dac_shsr2) == 68);
static_assert(offsetof(dac_p, dac_shhr) == 72);
static_assert(offsetof(dac_p, dac_shrr) == 76);

inline dac_p& dac = *reinterpret_cast<dac_p*>(0x42028400);
inline dac_p& sec_dac = *reinterpret_cast<dac_p*>(0x52028400);

} // STM32H563

