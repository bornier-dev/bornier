#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * CORDIC Co-processor
 */
class cordic_p {
public:

/**
 * CORDIC control/status register 
 */
class cordic_csr_r {
public:

/**
 * Function 2: Phase 3: Modulus 4: Arctangent 5: Hyperbolic cosine 6: Hyperbolic sine 7: Arctanh 8: Natural logarithm 9: Square Root
 */
class func_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr func_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator cordic_csr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Precision required (number of iterations) To determine the number of iterations needed for a given accuracy refer to . Note that for most functions, the recommended range for this field is 3 to 6.
 */
class precision_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr precision_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator cordic_csr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Scaling factor The value of this field indicates the scaling factor applied to the arguments and/or results. A value n implies that the arguments have been multiplied by a factor 2-n, and/or the results need to be multiplied by 2n. Refer to for the applicability of the scaling factor for each function and the appropriate range.
 */
class scale_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr scale_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator cordic_csr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable interrupt. This bit is set and cleared by software. A read returns the current state of the bit.
 */
class ien_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable DMA read channel This bit is set and cleared by software. A read returns the current state of the bit.
 */
class dmaren_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Enable DMA write channel This bit is set and cleared by software. A read returns the current state of the bit.
 */
class dmawen_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmawen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of results in the CORDIC_RDATA register Reads return the current state of the bit.
 */
class nres_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nres_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of arguments expected by the CORDIC_WDATA register Reads return the current state of the bit.
 */
class nargs_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nargs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Width of output data RESSIZE selects the number of bits used to represent output data. If 32-bit data is selected, the CORDIC_RDATA register contains results in q1.31 format. If 16-bit data is selected, the least significant half-word of CORDIC_RDATA contains the primary result (RES1) in q1.15 format, and the most significant half-word contains the secondary result (RES2), also in q1.15 format.
 */
class ressize_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ressize_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Width of input data ARGSIZE selects the number of bits used to represent input data. If 32-bit data is selected, the CORDIC_WDATA register expects arguments in q1.31 format. If 16-bit data is selected, the CORDIC_WDATA register expects arguments in q1.15 format. The primary argument (ARG1) is written to the least significant half-word, and the secondary argument (ARG2) to the most significant half-word.
 */
class argsize_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr argsize_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Result ready flag This bit is set by hardware when a CORDIC operation completes. It is reset by hardware when the CORDIC_RDATA register is read (NRES+1) times. When this bit is set, if the IEN bit is also set, the CORDIC interrupt is asserted. If the DMAREN bit is set, a DMA read channel request is generated. While this bit is set, no new calculation is started.
 */
class rrdy_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator cordic_csr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<cordic_csr_r>() const {return opsy::utility::clear_set<cordic_csr_r>(mask, *this);}
	constexpr auto operator|(cordic_csr_r other) const -> cordic_csr_r { return static_cast<cordic_csr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_csr_r> other) const -> opsy::utility::clear_set<cordic_csr_r> {return opsy::utility::clear_set<cordic_csr_r>(cordic_csr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto func() const -> func_f {return func_f(static_cast<uint8_t>(value_ >> func_f::offset));}
	[[nodiscard]] constexpr auto precision() const -> precision_f {return precision_f(static_cast<uint8_t>(value_ >> precision_f::offset));}
	[[nodiscard]] constexpr auto scale() const -> scale_f {return scale_f(static_cast<uint8_t>(value_ >> scale_f::offset));}
	[[nodiscard]] constexpr auto ien() const -> ien_f {return ien_f((value_ & ien_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaren() const -> dmaren_f {return dmaren_f((value_ & dmaren_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmawen() const -> dmawen_f {return dmawen_f((value_ & dmawen_f::mask) != 0);}
	[[nodiscard]] constexpr auto nres() const -> nres_f {return nres_f((value_ & nres_f::mask) != 0);}
	[[nodiscard]] constexpr auto nargs() const -> nargs_f {return nargs_f((value_ & nargs_f::mask) != 0);}
	[[nodiscard]] constexpr auto ressize() const -> ressize_f {return ressize_f((value_ & ressize_f::mask) != 0);}
	[[nodiscard]] constexpr auto argsize() const -> argsize_f {return argsize_f((value_ & argsize_f::mask) != 0);}
	[[nodiscard]] constexpr auto rrdy() const -> rrdy_f {return rrdy_f((value_ & rrdy_f::mask) != 0);}

	constexpr cordic_csr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(cordic_csr_r other) const -> cordic_csr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> cordic_csr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1010000; // 80 0x50

private:
	uint32_t value_;
};

/**
 * CORDIC argument register 
 */
class cordic_wdata_r {
public:

/**
 * Function input arguments This register is programmed with the input arguments for the function selected in the CORDIC_CSR register FUNC field. If 32-bit format is selected (CORDIC_CSR.ARGSIZE = 0) and two input arguments are required (CORDIC_CSR.NARGS = 1), two successive writes are required to this register. The first writes the primary argument (ARG1), the second writes the secondary argument (ARG2). If 32-bit format is selected and only one input argument is required (NARGS = 0), only one write is required to this register, containing the primary argument (ARG1). If 16-bit format is selected (CORDIC_CSR.ARGSIZE = 1), one write to this register contains both arguments. The primary argument (ARG1) is in the lower half, ARG[15:0], and the secondary argument (ARG2) is in the upper half, ARG[31:16]. In this case, NARGS must be set to 0. Refer to for the arguments required by each function, and their permitted range. When the required number of arguments has been written, the CORDIC evaluates the function designated by CORDIC_CSR.FUNC using the supplied input arguments, provided any previous calculation has completed. If a calculation is ongoing, the ARG1 and ARG 2 values are held pending until the calculation is completed and the results read. During this time, a write to the register cancels the pending operation and overwrite the argument data.
 */
class arg_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr arg_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator cordic_wdata_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<cordic_wdata_r>() const {return opsy::utility::clear_set<cordic_wdata_r>(mask, *this);}
	constexpr auto operator|(cordic_wdata_r other) const -> cordic_wdata_r { return static_cast<cordic_wdata_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_wdata_r> other) const -> opsy::utility::clear_set<cordic_wdata_r> {return opsy::utility::clear_set<cordic_wdata_r>(cordic_wdata_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto arg() const -> arg_f {return arg_f(static_cast<uint32_t>(value_ >> arg_f::offset));}

	constexpr cordic_wdata_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(cordic_wdata_r other) const -> cordic_wdata_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> cordic_wdata_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * CORDIC result register 
 */
class cordic_rdata_r {
public:

/**
 * Function result If 32-bit format is selected (CORDIC_CSR.RESSIZE = 0) and two output values are expected (CORDIC_CSR.NRES = 1), this register must be read twice when the RRDY flag is set. The first read fetches the primary result (RES1). The second read fetches the secondary result (RES2) and resets RRDY. If 32-bit format is selected and only one output value is expected (NRES = 0), only one read of this register is required to fetch the primary result (RES1) and reset the RRDY flag. If 16-bit format is selected (CORDIC_CSR.RESSIZE = 1), this register contains the primary result (RES1) in the lower half, RES[15:0], and the secondary result (RES2) in the upper half, RES[31:16]. In this case, NRES must be set to 0, and only one read performed. A read from this register resets the RRDY flag in the CORDIC_CSR register.
 */
class res_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr res_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator cordic_rdata_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<cordic_rdata_r>() const {return opsy::utility::clear_set<cordic_rdata_r>(mask, *this);}
	constexpr auto operator|(cordic_rdata_r other) const -> cordic_rdata_r { return static_cast<cordic_rdata_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<cordic_rdata_r> other) const -> opsy::utility::clear_set<cordic_rdata_r> {return opsy::utility::clear_set<cordic_rdata_r>(cordic_rdata_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto res() const -> res_f {return res_f(static_cast<uint32_t>(value_ >> res_f::offset));}

	constexpr cordic_rdata_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(cordic_rdata_r other) const -> cordic_rdata_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> cordic_rdata_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,cordic_csr_r> cordic_csr;
	opsy::utility::memory<uint32_t,cordic_wdata_r> cordic_wdata;
	opsy::utility::memory<uint32_t,cordic_rdata_r> cordic_rdata;
};

static_assert(std::is_standard_layout_v<cordic_p>);
static_assert(offsetof(cordic_p, cordic_csr) == 0);
static_assert(offsetof(cordic_p, cordic_wdata) == 4);
static_assert(offsetof(cordic_p, cordic_rdata) == 8);

inline cordic_p& cordic = *reinterpret_cast<cordic_p*>(0x40023800);
inline cordic_p& sec_cordic = *reinterpret_cast<cordic_p*>(0x50023800);

} // STM32H563

