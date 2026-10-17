#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Filter Math Accelerator
 */
class fmac_p {
public:

/**
 * FMAC X1 buffer configuration register 
 */
class fmac_x1bufcfg_r {
public:

/**
 * Base address of X1 buffer
 */
class x1_base_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr x1_base_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_x1bufcfg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_x1bufcfg_r>() const {return opsy::utility::clear_set<fmac_x1bufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_x1bufcfg_r other) const -> fmac_x1bufcfg_r { return static_cast<fmac_x1bufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_x1bufcfg_r> other) const -> opsy::utility::clear_set<fmac_x1bufcfg_r> {return opsy::utility::clear_set<fmac_x1bufcfg_r>(fmac_x1bufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Allocated size of X1 buffer in 16-bit words The minimum buffer size is the number of feed-forward taps in the filter (+ the watermark threshold1).
 */
class x1_buf_size_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr x1_buf_size_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_x1bufcfg_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_x1bufcfg_r>() const {return opsy::utility::clear_set<fmac_x1bufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_x1bufcfg_r other) const -> fmac_x1bufcfg_r { return static_cast<fmac_x1bufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_x1bufcfg_r> other) const -> opsy::utility::clear_set<fmac_x1bufcfg_r> {return opsy::utility::clear_set<fmac_x1bufcfg_r>(fmac_x1bufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Watermark for buffer full flag Defines the threshold for setting the X1 buffer full flag when operating in circular mode. The flag is set if the number of free spaces in the buffer is less than 2FULL_WM. 2: Threshold = 4 3: Threshold = 8 Setting a threshold greater than 1 allows several data to be transferred into the buffer under one interrupt. Threshold should be set to 1 if DMA write requests are enabled (DMAWEN = 1 in FMAC_CR register).
 */
class full_wm_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr full_wm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_x1bufcfg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_x1bufcfg_r>() const {return opsy::utility::clear_set<fmac_x1bufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_x1bufcfg_r other) const -> fmac_x1bufcfg_r { return static_cast<fmac_x1bufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_x1bufcfg_r> other) const -> opsy::utility::clear_set<fmac_x1bufcfg_r> {return opsy::utility::clear_set<fmac_x1bufcfg_r>(fmac_x1bufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto x1_base() const -> x1_base_f {return x1_base_f(static_cast<uint8_t>(value_ >> x1_base_f::offset));}
	[[nodiscard]] constexpr auto x1_buf_size() const -> x1_buf_size_f {return x1_buf_size_f(static_cast<uint8_t>(value_ >> x1_buf_size_f::offset));}
	[[nodiscard]] constexpr auto full_wm() const -> full_wm_f {return full_wm_f(static_cast<uint8_t>(value_ >> full_wm_f::offset));}

	constexpr fmac_x1bufcfg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_x1bufcfg_r other) const -> fmac_x1bufcfg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_x1bufcfg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC X2 buffer configuration register 
 */
class fmac_x2bufcfg_r {
public:

/**
 * Base address of X2 buffer The X2 buffer base address can be modified while START=1, for example to change coefficient values. The filter should be stalled when doing this, since changing the coefficients while a calculation is ongoing affects the result.
 */
class x2_base_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr x2_base_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_x2bufcfg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_x2bufcfg_r>() const {return opsy::utility::clear_set<fmac_x2bufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_x2bufcfg_r other) const -> fmac_x2bufcfg_r { return static_cast<fmac_x2bufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_x2bufcfg_r> other) const -> opsy::utility::clear_set<fmac_x2bufcfg_r> {return opsy::utility::clear_set<fmac_x2bufcfg_r>(fmac_x2bufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Size of X2 buffer in 16-bit words This bitfield can not be modified when a function is ongoing (START = 1).
 */
class x2_buf_size_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr x2_buf_size_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_x2bufcfg_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_x2bufcfg_r>() const {return opsy::utility::clear_set<fmac_x2bufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_x2bufcfg_r other) const -> fmac_x2bufcfg_r { return static_cast<fmac_x2bufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_x2bufcfg_r> other) const -> opsy::utility::clear_set<fmac_x2bufcfg_r> {return opsy::utility::clear_set<fmac_x2bufcfg_r>(fmac_x2bufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto x2_base() const -> x2_base_f {return x2_base_f(static_cast<uint8_t>(value_ >> x2_base_f::offset));}
	[[nodiscard]] constexpr auto x2_buf_size() const -> x2_buf_size_f {return x2_buf_size_f(static_cast<uint8_t>(value_ >> x2_buf_size_f::offset));}

	constexpr fmac_x2bufcfg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_x2bufcfg_r other) const -> fmac_x2bufcfg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_x2bufcfg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC Y buffer configuration register 
 */
class fmac_ybufcfg_r {
public:

/**
 * Base address of Y buffer
 */
class y_base_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr y_base_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_ybufcfg_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_ybufcfg_r>() const {return opsy::utility::clear_set<fmac_ybufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_ybufcfg_r other) const -> fmac_ybufcfg_r { return static_cast<fmac_ybufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_ybufcfg_r> other) const -> opsy::utility::clear_set<fmac_ybufcfg_r> {return opsy::utility::clear_set<fmac_ybufcfg_r>(fmac_ybufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Size of Y buffer in 16-bit words For FIR filters, the minimum buffer size is 1 (+ the watermark threshold). For IIR filters the minimum buffer size is the number of feedback taps (+ the watermark threshold).
 */
class y_buf_size_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr y_buf_size_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_ybufcfg_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_ybufcfg_r>() const {return opsy::utility::clear_set<fmac_ybufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_ybufcfg_r other) const -> fmac_ybufcfg_r { return static_cast<fmac_ybufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_ybufcfg_r> other) const -> opsy::utility::clear_set<fmac_ybufcfg_r> {return opsy::utility::clear_set<fmac_ybufcfg_r>(fmac_ybufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Watermark for buffer empty flag Defines the threshold for setting the Y buffer empty flag when operating in circular mode. The flag is set if the number of unread values in the buffer is less than 2EMPTY_WM. 2: Threshold = 4 3: Threshold = 8 Setting a threshold greater than 1 allows several data to be transferred from the buffer under one interrupt. Threshold should be set to 1 if DMA read requests are enabled (DMAREN = 1 in FMAC_CR register).
 */
class empty_wm_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr empty_wm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_ybufcfg_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_ybufcfg_r>() const {return opsy::utility::clear_set<fmac_ybufcfg_r>(mask, *this);}
	constexpr auto operator|(fmac_ybufcfg_r other) const -> fmac_ybufcfg_r { return static_cast<fmac_ybufcfg_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_ybufcfg_r> other) const -> opsy::utility::clear_set<fmac_ybufcfg_r> {return opsy::utility::clear_set<fmac_ybufcfg_r>(fmac_ybufcfg_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto y_base() const -> y_base_f {return y_base_f(static_cast<uint8_t>(value_ >> y_base_f::offset));}
	[[nodiscard]] constexpr auto y_buf_size() const -> y_buf_size_f {return y_buf_size_f(static_cast<uint8_t>(value_ >> y_buf_size_f::offset));}
	[[nodiscard]] constexpr auto empty_wm() const -> empty_wm_f {return empty_wm_f(static_cast<uint8_t>(value_ >> empty_wm_f::offset));}

	constexpr fmac_ybufcfg_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_ybufcfg_r other) const -> fmac_ybufcfg_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_ybufcfg_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC parameter register 
 */
class fmac_param_r {
public:

/**
 * Input parameter P. The value of this parameter is dependent on the function This bitfield can not be modified when a function is ongoing (START = 1)
 */
class p_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr p_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_param_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_param_r>() const {return opsy::utility::clear_set<fmac_param_r>(mask, *this);}
	constexpr auto operator|(fmac_param_r other) const -> fmac_param_r { return static_cast<fmac_param_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_param_r> other) const -> opsy::utility::clear_set<fmac_param_r> {return opsy::utility::clear_set<fmac_param_r>(fmac_param_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input parameter Q. The value of this parameter is dependent on the function. This bitfield can not be modified when a function is ongoing (START = 1)
 */
class q_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr q_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_param_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_param_r>() const {return opsy::utility::clear_set<fmac_param_r>(mask, *this);}
	constexpr auto operator|(fmac_param_r other) const -> fmac_param_r { return static_cast<fmac_param_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_param_r> other) const -> opsy::utility::clear_set<fmac_param_r> {return opsy::utility::clear_set<fmac_param_r>(fmac_param_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Input parameter R. The value of this parameter is dependent on the function. This bitfield can not be modified when a function is ongoing (START = 1)
 */
class r_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr r_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_param_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_param_r>() const {return opsy::utility::clear_set<fmac_param_r>(mask, *this);}
	constexpr auto operator|(fmac_param_r other) const -> fmac_param_r { return static_cast<fmac_param_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_param_r> other) const -> opsy::utility::clear_set<fmac_param_r> {return opsy::utility::clear_set<fmac_param_r>(fmac_param_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Function 2: Load X2 buffer 3: Load Y buffer 4 to 7: Reserved 8: Convolution (FIR filter) 9: IIR filter (direct form 1) This bitfield can not be modified when a function is ongoing (START = 1)
 */
class func_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr func_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmac_param_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_param_r>() const {return opsy::utility::clear_set<fmac_param_r>(mask, *this);}
	constexpr auto operator|(fmac_param_r other) const -> fmac_param_r { return static_cast<fmac_param_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_param_r> other) const -> opsy::utility::clear_set<fmac_param_r> {return opsy::utility::clear_set<fmac_param_r>(fmac_param_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable execution Setting this bit triggers the execution of the function selected in the FUNC bitfield. Resetting it by software stops any ongoing function. For initialization functions, this bit is reset by hardware.
 */
class start_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr start_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_param_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_param_r>() const {return opsy::utility::clear_set<fmac_param_r>(mask, *this);}
	constexpr auto operator|(fmac_param_r other) const -> fmac_param_r { return static_cast<fmac_param_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_param_r> other) const -> opsy::utility::clear_set<fmac_param_r> {return opsy::utility::clear_set<fmac_param_r>(fmac_param_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto p() const -> p_f {return p_f(static_cast<uint8_t>(value_ >> p_f::offset));}
	[[nodiscard]] constexpr auto q() const -> q_f {return q_f(static_cast<uint8_t>(value_ >> q_f::offset));}
	[[nodiscard]] constexpr auto r() const -> r_f {return r_f(static_cast<uint8_t>(value_ >> r_f::offset));}
	[[nodiscard]] constexpr auto func() const -> func_f {return func_f(static_cast<uint8_t>(value_ >> func_f::offset));}
	[[nodiscard]] constexpr auto start() const -> start_f {return start_f((value_ & start_f::mask) != 0);}

	constexpr fmac_param_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_param_r other) const -> fmac_param_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_param_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC control register 
 */
class fmac_cr_r {
public:

/**
 * Enable read interrupt This bit is set and cleared by software. A read returns the current state of the bit.
 */
class rien_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable write interrupt This bit is set and cleared by software. A read returns the current state of the bit.
 */
class wien_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable overflow error interrupts This bit is set and cleared by software. A read returns the current state of the bit.
 */
class ovflien_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovflien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable underflow error interrupts This bit is set and cleared by software. A read returns the current state of the bit.
 */
class unflien_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr unflien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable saturation error interrupts This bit is set and cleared by software. A read returns the current state of the bit.
 */
class satien_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr satien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable DMA read channel requests This bit can only be modified when START= 0 in the FMAC_PARAM register. A read returns the current state of the bit.
 */
class dmaren_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmaren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable DMA write channel requests This bit can only be modified when START= 0 in the FMAC_PARAM register. A read returns the current state of the bit.
 */
class dmawen_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dmawen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable clipping
 */
class clipen_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr clipen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Reset FMAC unit This resets the write and read pointers, the internal control logic, the FMAC_SR register and the FMAC_PARAM register, including the START bit if active. Other register settings are not affected. This bit is reset by hardware.
 */
class reset_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reset_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_cr_r>() const {return opsy::utility::clear_set<fmac_cr_r>(mask, *this);}
	constexpr auto operator|(fmac_cr_r other) const -> fmac_cr_r { return static_cast<fmac_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_cr_r> other) const -> opsy::utility::clear_set<fmac_cr_r> {return opsy::utility::clear_set<fmac_cr_r>(fmac_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rien() const -> rien_f {return rien_f((value_ & rien_f::mask) != 0);}
	[[nodiscard]] constexpr auto wien() const -> wien_f {return wien_f((value_ & wien_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovflien() const -> ovflien_f {return ovflien_f((value_ & ovflien_f::mask) != 0);}
	[[nodiscard]] constexpr auto unflien() const -> unflien_f {return unflien_f((value_ & unflien_f::mask) != 0);}
	[[nodiscard]] constexpr auto satien() const -> satien_f {return satien_f((value_ & satien_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaren() const -> dmaren_f {return dmaren_f((value_ & dmaren_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmawen() const -> dmawen_f {return dmawen_f((value_ & dmawen_f::mask) != 0);}
	[[nodiscard]] constexpr auto clipen() const -> clipen_f {return clipen_f((value_ & clipen_f::mask) != 0);}
	[[nodiscard]] constexpr auto reset() const -> reset_f {return reset_f((value_ & reset_f::mask) != 0);}

	constexpr fmac_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_cr_r other) const -> fmac_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC status register 
 */
class fmac_sr_r {
public:

/**
 * Y buffer empty flag The buffer is flagged as empty if the number of unread data is less than the EMPTY_WM threshold. The number of unread data is the difference between the read pointer and the current output destination address. This flag is set and cleared by hardware, or by a reset. Note: after the last sample is read from the Y buffer there is a delay of 3 clock cycles before the YEMPTY flag goes high. To avoid any risk of underflow it is recommended to insert a software delay after reading from the Y buffer before reading the FMAC_SR. Alternatively, an EMPTY_WM threshold of 2 can be used.
 */
class yempty_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr yempty_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_sr_r>() const {return opsy::utility::clear_set<fmac_sr_r>(mask, *this);}
	constexpr auto operator|(fmac_sr_r other) const -> fmac_sr_r { return static_cast<fmac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_sr_r> other) const -> opsy::utility::clear_set<fmac_sr_r> {return opsy::utility::clear_set<fmac_sr_r>(fmac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * X1 buffer full flag The buffer is flagged as full if the number of available spaces is less than the FULL_WM threshold. The number of available spaces is the difference between the write pointer and the least recent sample currently in use. This flag is set and cleared by hardware, or by a reset. Note: after the last available space in the X1 buffer is filled there is a delay of 3 clock cycles before the X1FULL flag goes high. To avoid any risk of overflow it is recommended to insert a software delay after writing to the X1 buffer before reading the FMAC_SR. Alternatively, a FULL_WM threshold of 2 can be used.
 */
class x1full_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr x1full_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_sr_r>() const {return opsy::utility::clear_set<fmac_sr_r>(mask, *this);}
	constexpr auto operator|(fmac_sr_r other) const -> fmac_sr_r { return static_cast<fmac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_sr_r> other) const -> opsy::utility::clear_set<fmac_sr_r> {return opsy::utility::clear_set<fmac_sr_r>(fmac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overflow error flag An overflow occurs when a write is made to FMAC_WDATA when no free space is available in the X1 buffer. This flag is cleared by a reset of the unit.
 */
class ovfl_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovfl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_sr_r>() const {return opsy::utility::clear_set<fmac_sr_r>(mask, *this);}
	constexpr auto operator|(fmac_sr_r other) const -> fmac_sr_r { return static_cast<fmac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_sr_r> other) const -> opsy::utility::clear_set<fmac_sr_r> {return opsy::utility::clear_set<fmac_sr_r>(fmac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Underflow error flag An underflow occurs when a read is made from FMAC_RDATA when no valid data is available in the Y buffer. This flag is cleared by a reset of the unit.
 */
class unfl_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr unfl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_sr_r>() const {return opsy::utility::clear_set<fmac_sr_r>(mask, *this);}
	constexpr auto operator|(fmac_sr_r other) const -> fmac_sr_r { return static_cast<fmac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_sr_r> other) const -> opsy::utility::clear_set<fmac_sr_r> {return opsy::utility::clear_set<fmac_sr_r>(fmac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Saturation error flag Saturation occurs when the result of an accumulation exceeds the numeric range of the accumulator. This flag is cleared by a reset of the unit.
 */
class sat_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmac_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmac_sr_r>() const {return opsy::utility::clear_set<fmac_sr_r>(mask, *this);}
	constexpr auto operator|(fmac_sr_r other) const -> fmac_sr_r { return static_cast<fmac_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_sr_r> other) const -> opsy::utility::clear_set<fmac_sr_r> {return opsy::utility::clear_set<fmac_sr_r>(fmac_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto yempty() const -> yempty_f {return yempty_f((value_ & yempty_f::mask) != 0);}
	[[nodiscard]] constexpr auto x1full() const -> x1full_f {return x1full_f((value_ & x1full_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovfl() const -> ovfl_f {return ovfl_f((value_ & ovfl_f::mask) != 0);}
	[[nodiscard]] constexpr auto unfl() const -> unfl_f {return unfl_f((value_ & unfl_f::mask) != 0);}
	[[nodiscard]] constexpr auto sat() const -> sat_f {return sat_f((value_ & sat_f::mask) != 0);}

	constexpr fmac_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_sr_r other) const -> fmac_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * FMAC write data register 
 */
class fmac_wdata_r {
public:

/**
 * Write data When a write access to this register occurs, the write data are transferred to the address offset indicated by the write pointer. The pointer address is automatically incremented after each write access.
 */
class wdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr wdata_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fmac_wdata_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_wdata_r>() const {return opsy::utility::clear_set<fmac_wdata_r>(mask, *this);}
	constexpr auto operator|(fmac_wdata_r other) const -> fmac_wdata_r { return static_cast<fmac_wdata_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_wdata_r> other) const -> opsy::utility::clear_set<fmac_wdata_r> {return opsy::utility::clear_set<fmac_wdata_r>(fmac_wdata_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto wdata() const -> wdata_f {return wdata_f(static_cast<uint16_t>(value_ >> wdata_f::offset));}

	constexpr fmac_wdata_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_wdata_r other) const -> fmac_wdata_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_wdata_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * FMAC read data register 
 */
class fmac_rdata_r {
public:

/**
 * Read data When a read access to this register occurs, the read data are the contents of the Y output buffer at the address offset indicated by the READ pointer. The pointer address is automatically incremented after each read access.
 */
class rdata_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdata_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fmac_rdata_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmac_rdata_r>() const {return opsy::utility::clear_set<fmac_rdata_r>(mask, *this);}
	constexpr auto operator|(fmac_rdata_r other) const -> fmac_rdata_r { return static_cast<fmac_rdata_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmac_rdata_r> other) const -> opsy::utility::clear_set<fmac_rdata_r> {return opsy::utility::clear_set<fmac_rdata_r>(fmac_rdata_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdata() const -> rdata_f {return rdata_f(static_cast<uint16_t>(value_ >> rdata_f::offset));}

	constexpr fmac_rdata_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmac_rdata_r other) const -> fmac_rdata_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmac_rdata_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,fmac_x1bufcfg_r> fmac_x1bufcfg;
	opsy::utility::memory<uint32_t,fmac_x2bufcfg_r> fmac_x2bufcfg;
	opsy::utility::memory<uint32_t,fmac_ybufcfg_r> fmac_ybufcfg;
	opsy::utility::memory<uint32_t,fmac_param_r> fmac_param;
	opsy::utility::memory<uint32_t,fmac_cr_r> fmac_cr;
	opsy::utility::memory<uint32_t,fmac_sr_r> fmac_sr;
	opsy::utility::memory<uint32_t,fmac_wdata_r> fmac_wdata;
	opsy::utility::memory<uint32_t,fmac_rdata_r> fmac_rdata;
};

static_assert(std::is_standard_layout_v<fmac_p>);
static_assert(offsetof(fmac_p, fmac_x1bufcfg) == 0);
static_assert(offsetof(fmac_p, fmac_x2bufcfg) == 4);
static_assert(offsetof(fmac_p, fmac_ybufcfg) == 8);
static_assert(offsetof(fmac_p, fmac_param) == 12);
static_assert(offsetof(fmac_p, fmac_cr) == 16);
static_assert(offsetof(fmac_p, fmac_sr) == 20);
static_assert(offsetof(fmac_p, fmac_wdata) == 24);
static_assert(offsetof(fmac_p, fmac_rdata) == 28);

inline fmac_p& fmac = *reinterpret_cast<fmac_p*>(0x40023C00);
inline fmac_p& sec_fmac = *reinterpret_cast<fmac_p*>(0x50023C00);

} // STM32H563

