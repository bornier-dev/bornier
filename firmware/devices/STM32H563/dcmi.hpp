#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Digital camera interface
 */
class dcmi_p {
public:

/**
 * DCMI control register 
 */
class dcmi_cr_r {
public:

/**
 * Capture enable The camera interface waits for the first start of frame, then a DMA request is generated to transfer the received data into the destination memory. In snapshot mode, the CAPTURE bit is automatically cleared at the end of the first frame received. In continuous grab mode, if the software clears this bit while a capture is ongoing, the bit is effectively cleared after the frame end. Note: The DMA controller and all DCMI configuration registers must be programmed correctly before enabling this bit.
 */
class capture_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr capture_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Capture mode
 */
class cm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Crop feature
 */
class crop_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr crop_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * JPEG format
 */
class jpeg_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr jpeg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Embedded synchronization select Note: Valid only for 8-bit parallel data. HSPOL/VSPOL are ignored when the ESS bit is set. This bit is disabled in JPEG mode.
 */
class ess_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ess_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Pixel clock polarity This bit configures the capture edge of the pixel clock.
 */
class pckpol_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pckpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Horizontal synchronization polarity This bit indicates the level on the DCMI_HSYNC pin when the data are not valid on the parallel interface.
 */
class hspol_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hspol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vertical synchronization polarity This bit indicates the level on the DCMI_VSYNC pin when the data are not valid on the parallel interface.
 */
class vspol_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vspol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frame capture rate control These bits define the frequency of frame capture. They are meaningful only in Continuous grab mode. They are ignored in snapshot mode.
 */
class fcrc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fcrc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Extended data mode
 */
class edm_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr edm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DCMI enable Note: The DCMI configuration registers must be programmed correctly before enabling this bit.
 */
class enable_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr enable_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Byte Select mode Note: This mode only works for EDM[1:0] = 00. For all other EDM values, this field must be programmed to the reset value.
 */
class bsm_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr bsm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Odd/Even Byte Select (Byte Select Start) This bit works in conjunction with BSM field (BSM different 00).
 */
class oebs_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oebs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Line Select mode
 */
class lsm_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lsm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Odd/Even Line Select (Line Select Start) This bit works in conjunction with the LSM field (LSM = 1).
 */
class oels_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr oels_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_cr_r>() const {return opsy::utility::clear_set<dcmi_cr_r>(mask, *this);}
	constexpr auto operator|(dcmi_cr_r other) const -> dcmi_cr_r { return static_cast<dcmi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cr_r> other) const -> opsy::utility::clear_set<dcmi_cr_r> {return opsy::utility::clear_set<dcmi_cr_r>(dcmi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto capture() const -> capture_f {return capture_f((value_ & capture_f::mask) != 0);}
	[[nodiscard]] constexpr auto cm() const -> cm_f {return cm_f((value_ & cm_f::mask) != 0);}
	[[nodiscard]] constexpr auto crop() const -> crop_f {return crop_f((value_ & crop_f::mask) != 0);}
	[[nodiscard]] constexpr auto jpeg() const -> jpeg_f {return jpeg_f((value_ & jpeg_f::mask) != 0);}
	[[nodiscard]] constexpr auto ess() const -> ess_f {return ess_f((value_ & ess_f::mask) != 0);}
	[[nodiscard]] constexpr auto pckpol() const -> pckpol_f {return pckpol_f((value_ & pckpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto hspol() const -> hspol_f {return hspol_f((value_ & hspol_f::mask) != 0);}
	[[nodiscard]] constexpr auto vspol() const -> vspol_f {return vspol_f((value_ & vspol_f::mask) != 0);}
	[[nodiscard]] constexpr auto fcrc() const -> fcrc_f {return fcrc_f(static_cast<uint8_t>(value_ >> fcrc_f::offset));}
	[[nodiscard]] constexpr auto edm() const -> edm_f {return edm_f(static_cast<uint8_t>(value_ >> edm_f::offset));}
	[[nodiscard]] constexpr auto enable() const -> enable_f {return enable_f((value_ & enable_f::mask) != 0);}
	[[nodiscard]] constexpr auto bsm() const -> bsm_f {return bsm_f(static_cast<uint8_t>(value_ >> bsm_f::offset));}
	[[nodiscard]] constexpr auto oebs() const -> oebs_f {return oebs_f((value_ & oebs_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsm() const -> lsm_f {return lsm_f((value_ & lsm_f::mask) != 0);}
	[[nodiscard]] constexpr auto oels() const -> oels_f {return oels_f((value_ & oels_f::mask) != 0);}

	constexpr dcmi_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_cr_r other) const -> dcmi_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI status register 
 */
class dcmi_sr_r {
public:

/**
 * Horizontal synchronization This bit gives the state of the DCMI_HSYNC pin with the correct programmed polarity. When embedded synchronization codes are used, the meaning of this bit is the following: In case of embedded synchronization, this bit is meaningful only if the CAPTURE bit in DCMI_CR is set.
 */
class hsync_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hsync_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_sr_r>() const {return opsy::utility::clear_set<dcmi_sr_r>(mask, *this);}
	constexpr auto operator|(dcmi_sr_r other) const -> dcmi_sr_r { return static_cast<dcmi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_sr_r> other) const -> opsy::utility::clear_set<dcmi_sr_r> {return opsy::utility::clear_set<dcmi_sr_r>(dcmi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vertical synchronization This bit gives the state of the DCMI_VSYNC pin with the correct programmed polarity. When embedded synchronization codes are used, the meaning of this bit is the following: In case of embedded synchronization, this bit is meaningful only if the CAPTURE bit in DCMI_CR is set.
 */
class vsync_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vsync_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_sr_r>() const {return opsy::utility::clear_set<dcmi_sr_r>(mask, *this);}
	constexpr auto operator|(dcmi_sr_r other) const -> dcmi_sr_r { return static_cast<dcmi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_sr_r> other) const -> opsy::utility::clear_set<dcmi_sr_r> {return opsy::utility::clear_set<dcmi_sr_r>(dcmi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO not empty This bit gives the status of the FIFO.
 */
class fne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_sr_r>() const {return opsy::utility::clear_set<dcmi_sr_r>(mask, *this);}
	constexpr auto operator|(dcmi_sr_r other) const -> dcmi_sr_r { return static_cast<dcmi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_sr_r> other) const -> opsy::utility::clear_set<dcmi_sr_r> {return opsy::utility::clear_set<dcmi_sr_r>(dcmi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto hsync() const -> hsync_f {return hsync_f((value_ & hsync_f::mask) != 0);}
	[[nodiscard]] constexpr auto vsync() const -> vsync_f {return vsync_f((value_ & vsync_f::mask) != 0);}
	[[nodiscard]] constexpr auto fne() const -> fne_f {return fne_f((value_ & fne_f::mask) != 0);}

	constexpr dcmi_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_sr_r other) const -> dcmi_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI raw interrupt status register 
 */
class dcmi_ris_r {
public:

/**
 * Capture complete raw interrupt status This bit is set when a frame or window has been captured. In case of a cropped window, this bit is set at the end of line of the last line in the crop. It is set even if the captured frame is empty (e.g. window cropped outside the frame). The bit is cleared by setting the FRAME_ISC bit of the DCMI_ICR register.
 */
class frame_ris_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frame_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ris_r>() const {return opsy::utility::clear_set<dcmi_ris_r>(mask, *this);}
	constexpr auto operator|(dcmi_ris_r other) const -> dcmi_ris_r { return static_cast<dcmi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ris_r> other) const -> opsy::utility::clear_set<dcmi_ris_r> {return opsy::utility::clear_set<dcmi_ris_r>(dcmi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun raw interrupt status The bit is cleared by setting the OVR_ISC bit of the DCMI_ICR register.
 */
class ovr_ris_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ris_r>() const {return opsy::utility::clear_set<dcmi_ris_r>(mask, *this);}
	constexpr auto operator|(dcmi_ris_r other) const -> dcmi_ris_r { return static_cast<dcmi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ris_r> other) const -> opsy::utility::clear_set<dcmi_ris_r> {return opsy::utility::clear_set<dcmi_ris_r>(dcmi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization error raw interrupt status This bit is valid only in the embedded synchronization mode. It is cleared by setting the ERR_ISC bit of the DCMI_ICR register. Note: This bit is available only in embedded synchronization mode.
 */
class err_ris_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr err_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ris_r>() const {return opsy::utility::clear_set<dcmi_ris_r>(mask, *this);}
	constexpr auto operator|(dcmi_ris_r other) const -> dcmi_ris_r { return static_cast<dcmi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ris_r> other) const -> opsy::utility::clear_set<dcmi_ris_r> {return opsy::utility::clear_set<dcmi_ris_r>(dcmi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DCMI_VSYNC raw interrupt status This bit is set when the DCMI_VSYNC signal changes from the inactive state to the active state. In the case of embedded synchronization, this bit is set only if the CAPTURE bit is set in DCMI_CR. It is cleared by setting the VSYNC_ISC bit of the DCMI_ICR register.
 */
class vsync_ris_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vsync_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ris_r>() const {return opsy::utility::clear_set<dcmi_ris_r>(mask, *this);}
	constexpr auto operator|(dcmi_ris_r other) const -> dcmi_ris_r { return static_cast<dcmi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ris_r> other) const -> opsy::utility::clear_set<dcmi_ris_r> {return opsy::utility::clear_set<dcmi_ris_r>(dcmi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Line raw interrupt status This bit gets set when the DCMI_HSYNC signal changes from the inactive state to the active state. It goes high even if the line is not valid. In the case of embedded synchronization, this bit is set only if the CAPTURE bit in DCMI_CR is set. It is cleared by setting the LINE_ISC bit of the DCMI_ICR register.
 */
class line_ris_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr line_ris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ris_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ris_r>() const {return opsy::utility::clear_set<dcmi_ris_r>(mask, *this);}
	constexpr auto operator|(dcmi_ris_r other) const -> dcmi_ris_r { return static_cast<dcmi_ris_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ris_r> other) const -> opsy::utility::clear_set<dcmi_ris_r> {return opsy::utility::clear_set<dcmi_ris_r>(dcmi_ris_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto frame_ris() const -> frame_ris_f {return frame_ris_f((value_ & frame_ris_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_ris() const -> ovr_ris_f {return ovr_ris_f((value_ & ovr_ris_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_ris() const -> err_ris_f {return err_ris_f((value_ & err_ris_f::mask) != 0);}
	[[nodiscard]] constexpr auto vsync_ris() const -> vsync_ris_f {return vsync_ris_f((value_ & vsync_ris_f::mask) != 0);}
	[[nodiscard]] constexpr auto line_ris() const -> line_ris_f {return line_ris_f((value_ & line_ris_f::mask) != 0);}

	constexpr dcmi_ris_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_ris_r other) const -> dcmi_ris_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_ris_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI interrupt enable register 
 */
class dcmi_ier_r {
public:

/**
 * Capture complete interrupt enable
 */
class frame_ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frame_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ier_r>() const {return opsy::utility::clear_set<dcmi_ier_r>(mask, *this);}
	constexpr auto operator|(dcmi_ier_r other) const -> dcmi_ier_r { return static_cast<dcmi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ier_r> other) const -> opsy::utility::clear_set<dcmi_ier_r> {return opsy::utility::clear_set<dcmi_ier_r>(dcmi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun interrupt enable
 */
class ovr_ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ier_r>() const {return opsy::utility::clear_set<dcmi_ier_r>(mask, *this);}
	constexpr auto operator|(dcmi_ier_r other) const -> dcmi_ier_r { return static_cast<dcmi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ier_r> other) const -> opsy::utility::clear_set<dcmi_ier_r> {return opsy::utility::clear_set<dcmi_ier_r>(dcmi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization error interrupt enable Note: This bit is available only in embedded synchronization mode.
 */
class err_ie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr err_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ier_r>() const {return opsy::utility::clear_set<dcmi_ier_r>(mask, *this);}
	constexpr auto operator|(dcmi_ier_r other) const -> dcmi_ier_r { return static_cast<dcmi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ier_r> other) const -> opsy::utility::clear_set<dcmi_ier_r> {return opsy::utility::clear_set<dcmi_ier_r>(dcmi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DCMI_VSYNC interrupt enable The active state of the DCMI_VSYNC signal is defined by the VSPOL bit.
 */
class vsync_ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vsync_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ier_r>() const {return opsy::utility::clear_set<dcmi_ier_r>(mask, *this);}
	constexpr auto operator|(dcmi_ier_r other) const -> dcmi_ier_r { return static_cast<dcmi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ier_r> other) const -> opsy::utility::clear_set<dcmi_ier_r> {return opsy::utility::clear_set<dcmi_ier_r>(dcmi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Line interrupt enable
 */
class line_ie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr line_ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_ier_r>() const {return opsy::utility::clear_set<dcmi_ier_r>(mask, *this);}
	constexpr auto operator|(dcmi_ier_r other) const -> dcmi_ier_r { return static_cast<dcmi_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_ier_r> other) const -> opsy::utility::clear_set<dcmi_ier_r> {return opsy::utility::clear_set<dcmi_ier_r>(dcmi_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto frame_ie() const -> frame_ie_f {return frame_ie_f((value_ & frame_ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_ie() const -> ovr_ie_f {return ovr_ie_f((value_ & ovr_ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_ie() const -> err_ie_f {return err_ie_f((value_ & err_ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto vsync_ie() const -> vsync_ie_f {return vsync_ie_f((value_ & vsync_ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto line_ie() const -> line_ie_f {return line_ie_f((value_ & line_ie_f::mask) != 0);}

	constexpr dcmi_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_ier_r other) const -> dcmi_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI masked interrupt status register 
 */
class dcmi_mis_r {
public:

/**
 * Capture complete masked interrupt status This bit gives the status of the masked capture complete interrupt
 */
class frame_mis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frame_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_mis_r>() const {return opsy::utility::clear_set<dcmi_mis_r>(mask, *this);}
	constexpr auto operator|(dcmi_mis_r other) const -> dcmi_mis_r { return static_cast<dcmi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_mis_r> other) const -> opsy::utility::clear_set<dcmi_mis_r> {return opsy::utility::clear_set<dcmi_mis_r>(dcmi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun masked interrupt status This bit gives the status of the masked overflow interrupt.
 */
class ovr_mis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_mis_r>() const {return opsy::utility::clear_set<dcmi_mis_r>(mask, *this);}
	constexpr auto operator|(dcmi_mis_r other) const -> dcmi_mis_r { return static_cast<dcmi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_mis_r> other) const -> opsy::utility::clear_set<dcmi_mis_r> {return opsy::utility::clear_set<dcmi_mis_r>(dcmi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization error masked interrupt status This bit gives the status of the masked synchronization error interrupt. Note: This bit is available only in embedded synchronization mode.
 */
class err_mis_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr err_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_mis_r>() const {return opsy::utility::clear_set<dcmi_mis_r>(mask, *this);}
	constexpr auto operator|(dcmi_mis_r other) const -> dcmi_mis_r { return static_cast<dcmi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_mis_r> other) const -> opsy::utility::clear_set<dcmi_mis_r> {return opsy::utility::clear_set<dcmi_mis_r>(dcmi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * VSYNC masked interrupt status This bit gives the status of the masked VSYNC interrupt. The active state of the DCMI_VSYNC signal is defined by the VSPOL bit.
 */
class vsync_mis_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vsync_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_mis_r>() const {return opsy::utility::clear_set<dcmi_mis_r>(mask, *this);}
	constexpr auto operator|(dcmi_mis_r other) const -> dcmi_mis_r { return static_cast<dcmi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_mis_r> other) const -> opsy::utility::clear_set<dcmi_mis_r> {return opsy::utility::clear_set<dcmi_mis_r>(dcmi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Line masked interrupt status This bit gives the status of the masked line interrupt.
 */
class line_mis_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr line_mis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_mis_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_mis_r>() const {return opsy::utility::clear_set<dcmi_mis_r>(mask, *this);}
	constexpr auto operator|(dcmi_mis_r other) const -> dcmi_mis_r { return static_cast<dcmi_mis_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_mis_r> other) const -> opsy::utility::clear_set<dcmi_mis_r> {return opsy::utility::clear_set<dcmi_mis_r>(dcmi_mis_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto frame_mis() const -> frame_mis_f {return frame_mis_f((value_ & frame_mis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_mis() const -> ovr_mis_f {return ovr_mis_f((value_ & ovr_mis_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_mis() const -> err_mis_f {return err_mis_f((value_ & err_mis_f::mask) != 0);}
	[[nodiscard]] constexpr auto vsync_mis() const -> vsync_mis_f {return vsync_mis_f((value_ & vsync_mis_f::mask) != 0);}
	[[nodiscard]] constexpr auto line_mis() const -> line_mis_f {return line_mis_f((value_ & line_mis_f::mask) != 0);}

	constexpr dcmi_mis_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_mis_r other) const -> dcmi_mis_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_mis_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI interrupt clear register 
 */
class dcmi_icr_r {
public:

/**
 * Capture complete interrupt status clear Setting this bit clears the FRAME_RIS flag in the DCMI_RIS register.
 */
class frame_isc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frame_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_icr_r>() const {return opsy::utility::clear_set<dcmi_icr_r>(mask, *this);}
	constexpr auto operator|(dcmi_icr_r other) const -> dcmi_icr_r { return static_cast<dcmi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_icr_r> other) const -> opsy::utility::clear_set<dcmi_icr_r> {return opsy::utility::clear_set<dcmi_icr_r>(dcmi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun interrupt status clear Setting this bit clears the OVR_RIS flag in the DCMI_RIS register.
 */
class ovr_isc_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovr_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_icr_r>() const {return opsy::utility::clear_set<dcmi_icr_r>(mask, *this);}
	constexpr auto operator|(dcmi_icr_r other) const -> dcmi_icr_r { return static_cast<dcmi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_icr_r> other) const -> opsy::utility::clear_set<dcmi_icr_r> {return opsy::utility::clear_set<dcmi_icr_r>(dcmi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization error interrupt status clear Setting this bit clears the ERR_RIS flag in the DCMI_RIS register. Note: This bit is available only in embedded synchronization mode.
 */
class err_isc_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr err_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_icr_r>() const {return opsy::utility::clear_set<dcmi_icr_r>(mask, *this);}
	constexpr auto operator|(dcmi_icr_r other) const -> dcmi_icr_r { return static_cast<dcmi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_icr_r> other) const -> opsy::utility::clear_set<dcmi_icr_r> {return opsy::utility::clear_set<dcmi_icr_r>(dcmi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Vertical Synchronization interrupt status clear Setting this bit clears the VSYNC_RIS flag in the DCMI_RIS register.
 */
class vsync_isc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vsync_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_icr_r>() const {return opsy::utility::clear_set<dcmi_icr_r>(mask, *this);}
	constexpr auto operator|(dcmi_icr_r other) const -> dcmi_icr_r { return static_cast<dcmi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_icr_r> other) const -> opsy::utility::clear_set<dcmi_icr_r> {return opsy::utility::clear_set<dcmi_icr_r>(dcmi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * line interrupt status clear Setting this bit clears the LINE_RIS flag in the DCMI_RIS register.
 */
class line_isc_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr line_isc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator dcmi_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<dcmi_icr_r>() const {return opsy::utility::clear_set<dcmi_icr_r>(mask, *this);}
	constexpr auto operator|(dcmi_icr_r other) const -> dcmi_icr_r { return static_cast<dcmi_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_icr_r> other) const -> opsy::utility::clear_set<dcmi_icr_r> {return opsy::utility::clear_set<dcmi_icr_r>(dcmi_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto frame_isc() const -> frame_isc_f {return frame_isc_f((value_ & frame_isc_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovr_isc() const -> ovr_isc_f {return ovr_isc_f((value_ & ovr_isc_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_isc() const -> err_isc_f {return err_isc_f((value_ & err_isc_f::mask) != 0);}
	[[nodiscard]] constexpr auto vsync_isc() const -> vsync_isc_f {return vsync_isc_f((value_ & vsync_isc_f::mask) != 0);}
	[[nodiscard]] constexpr auto line_isc() const -> line_isc_f {return line_isc_f((value_ & line_isc_f::mask) != 0);}

	constexpr dcmi_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_icr_r other) const -> dcmi_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI embedded synchronization code register 
 */
class dcmi_escr_r {
public:

/**
 * Frame start delimiter code This byte specifies the code of the frame start delimiter. The code consists of 4 bytes in the form of 0xFF, 0x00, 0x00, FSC. If FSC is programmed to 0xFF, no frame start delimiter is detected. But, the first occurrence of LSC after an FEC code is interpreted as a start of frame delimiter.
 */
class fsc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr fsc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_escr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_escr_r>() const {return opsy::utility::clear_set<dcmi_escr_r>(mask, *this);}
	constexpr auto operator|(dcmi_escr_r other) const -> dcmi_escr_r { return static_cast<dcmi_escr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_escr_r> other) const -> opsy::utility::clear_set<dcmi_escr_r> {return opsy::utility::clear_set<dcmi_escr_r>(dcmi_escr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Line start delimiter code This byte specifies the code of the line start delimiter. The code consists of 4 bytes in the form of 0xFF, 0x00, 0x00, LSC.
 */
class lsc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lsc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_escr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_escr_r>() const {return opsy::utility::clear_set<dcmi_escr_r>(mask, *this);}
	constexpr auto operator|(dcmi_escr_r other) const -> dcmi_escr_r { return static_cast<dcmi_escr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_escr_r> other) const -> opsy::utility::clear_set<dcmi_escr_r> {return opsy::utility::clear_set<dcmi_escr_r>(dcmi_escr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Line end delimiter code This byte specifies the code of the line end delimiter. The code consists of 4 bytes in the form of 0xFF, 0x00, 0x00, LEC.
 */
class lec_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_escr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_escr_r>() const {return opsy::utility::clear_set<dcmi_escr_r>(mask, *this);}
	constexpr auto operator|(dcmi_escr_r other) const -> dcmi_escr_r { return static_cast<dcmi_escr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_escr_r> other) const -> opsy::utility::clear_set<dcmi_escr_r> {return opsy::utility::clear_set<dcmi_escr_r>(dcmi_escr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Frame end delimiter code This byte specifies the code of the frame end delimiter. The code consists of 4 bytes in the form of 0xFF, 0x00, 0x00, FEC. If FEC is programmed to 0xFF, all the unused codes (0xFF0000XY) are interpreted as frame end delimiters.
 */
class fec_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_escr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_escr_r>() const {return opsy::utility::clear_set<dcmi_escr_r>(mask, *this);}
	constexpr auto operator|(dcmi_escr_r other) const -> dcmi_escr_r { return static_cast<dcmi_escr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_escr_r> other) const -> opsy::utility::clear_set<dcmi_escr_r> {return opsy::utility::clear_set<dcmi_escr_r>(dcmi_escr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto fsc() const -> fsc_f {return fsc_f(static_cast<uint8_t>(value_ >> fsc_f::offset));}
	[[nodiscard]] constexpr auto lsc() const -> lsc_f {return lsc_f(static_cast<uint8_t>(value_ >> lsc_f::offset));}
	[[nodiscard]] constexpr auto lec() const -> lec_f {return lec_f(static_cast<uint8_t>(value_ >> lec_f::offset));}
	[[nodiscard]] constexpr auto fec() const -> fec_f {return fec_f(static_cast<uint8_t>(value_ >> fec_f::offset));}

	constexpr dcmi_escr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_escr_r other) const -> dcmi_escr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_escr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI embedded synchronization unmask register 
 */
class dcmi_esur_r {
public:

/**
 * Frame start delimiter unmask This byte specifies the mask to be applied to the code of the frame start delimiter.
 */
class fsu_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr fsu_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_esur_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_esur_r>() const {return opsy::utility::clear_set<dcmi_esur_r>(mask, *this);}
	constexpr auto operator|(dcmi_esur_r other) const -> dcmi_esur_r { return static_cast<dcmi_esur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_esur_r> other) const -> opsy::utility::clear_set<dcmi_esur_r> {return opsy::utility::clear_set<dcmi_esur_r>(dcmi_esur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Line start delimiter unmask This byte specifies the mask to be applied to the code of the line start delimiter.
 */
class lsu_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lsu_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_esur_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_esur_r>() const {return opsy::utility::clear_set<dcmi_esur_r>(mask, *this);}
	constexpr auto operator|(dcmi_esur_r other) const -> dcmi_esur_r { return static_cast<dcmi_esur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_esur_r> other) const -> opsy::utility::clear_set<dcmi_esur_r> {return opsy::utility::clear_set<dcmi_esur_r>(dcmi_esur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Line end delimiter unmask This byte specifies the mask to be applied to the code of the line end delimiter.
 */
class leu_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr leu_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_esur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_esur_r>() const {return opsy::utility::clear_set<dcmi_esur_r>(mask, *this);}
	constexpr auto operator|(dcmi_esur_r other) const -> dcmi_esur_r { return static_cast<dcmi_esur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_esur_r> other) const -> opsy::utility::clear_set<dcmi_esur_r> {return opsy::utility::clear_set<dcmi_esur_r>(dcmi_esur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Frame end delimiter unmask This byte specifies the mask to be applied to the code of the frame end delimiter.
 */
class feu_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr feu_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_esur_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_esur_r>() const {return opsy::utility::clear_set<dcmi_esur_r>(mask, *this);}
	constexpr auto operator|(dcmi_esur_r other) const -> dcmi_esur_r { return static_cast<dcmi_esur_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_esur_r> other) const -> opsy::utility::clear_set<dcmi_esur_r> {return opsy::utility::clear_set<dcmi_esur_r>(dcmi_esur_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto fsu() const -> fsu_f {return fsu_f(static_cast<uint8_t>(value_ >> fsu_f::offset));}
	[[nodiscard]] constexpr auto lsu() const -> lsu_f {return lsu_f(static_cast<uint8_t>(value_ >> lsu_f::offset));}
	[[nodiscard]] constexpr auto leu() const -> leu_f {return leu_f(static_cast<uint8_t>(value_ >> leu_f::offset));}
	[[nodiscard]] constexpr auto feu() const -> feu_f {return feu_f(static_cast<uint8_t>(value_ >> feu_f::offset));}

	constexpr dcmi_esur_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_esur_r other) const -> dcmi_esur_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_esur_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI crop window start 
 */
class dcmi_cwstrt_r {
public:

/**
 * Horizontal offset count This value gives the number of pixel clocks to count before starting a capture.
 */
class hoffcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr hoffcnt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcmi_cwstrt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cwstrt_r>() const {return opsy::utility::clear_set<dcmi_cwstrt_r>(mask, *this);}
	constexpr auto operator|(dcmi_cwstrt_r other) const -> dcmi_cwstrt_r { return static_cast<dcmi_cwstrt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cwstrt_r> other) const -> opsy::utility::clear_set<dcmi_cwstrt_r> {return opsy::utility::clear_set<dcmi_cwstrt_r>(dcmi_cwstrt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Vertical start line count The image capture starts with this line number. Previous line data are ignored. ....
 */
class vst_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr vst_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcmi_cwstrt_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cwstrt_r>() const {return opsy::utility::clear_set<dcmi_cwstrt_r>(mask, *this);}
	constexpr auto operator|(dcmi_cwstrt_r other) const -> dcmi_cwstrt_r { return static_cast<dcmi_cwstrt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cwstrt_r> other) const -> opsy::utility::clear_set<dcmi_cwstrt_r> {return opsy::utility::clear_set<dcmi_cwstrt_r>(dcmi_cwstrt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto hoffcnt() const -> hoffcnt_f {return hoffcnt_f(static_cast<uint16_t>(value_ >> hoffcnt_f::offset));}
	[[nodiscard]] constexpr auto vst() const -> vst_f {return vst_f(static_cast<uint16_t>(value_ >> vst_f::offset));}

	constexpr dcmi_cwstrt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_cwstrt_r other) const -> dcmi_cwstrt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_cwstrt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI crop window size 
 */
class dcmi_cwsize_r {
public:

/**
 * Capture count This value gives the number of pixel clocks to be captured from the starting point on the same line. It value must corresponds to word-aligned data for different widths of parallel interfaces. 0x0000 = 1 pixel 0x0001 = 2 pixels 0x0002 = 3 pixels ....
 */
class capcnt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr capcnt_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcmi_cwsize_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cwsize_r>() const {return opsy::utility::clear_set<dcmi_cwsize_r>(mask, *this);}
	constexpr auto operator|(dcmi_cwsize_r other) const -> dcmi_cwsize_r { return static_cast<dcmi_cwsize_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cwsize_r> other) const -> opsy::utility::clear_set<dcmi_cwsize_r> {return opsy::utility::clear_set<dcmi_cwsize_r>(dcmi_cwsize_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Vertical line count This value gives the number of lines to be captured from the starting point. ....
 */
class vline_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr vline_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator dcmi_cwsize_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_cwsize_r>() const {return opsy::utility::clear_set<dcmi_cwsize_r>(mask, *this);}
	constexpr auto operator|(dcmi_cwsize_r other) const -> dcmi_cwsize_r { return static_cast<dcmi_cwsize_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_cwsize_r> other) const -> opsy::utility::clear_set<dcmi_cwsize_r> {return opsy::utility::clear_set<dcmi_cwsize_r>(dcmi_cwsize_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto capcnt() const -> capcnt_f {return capcnt_f(static_cast<uint16_t>(value_ >> capcnt_f::offset));}
	[[nodiscard]] constexpr auto vline() const -> vline_f {return vline_f(static_cast<uint16_t>(value_ >> vline_f::offset));}

	constexpr dcmi_cwsize_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_cwsize_r other) const -> dcmi_cwsize_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_cwsize_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * DCMI data register 
 */
class dcmi_dr_r {
public:

/**
 * Data byte 0
 */
class byte0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr byte0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_dr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_dr_r>() const {return opsy::utility::clear_set<dcmi_dr_r>(mask, *this);}
	constexpr auto operator|(dcmi_dr_r other) const -> dcmi_dr_r { return static_cast<dcmi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_dr_r> other) const -> opsy::utility::clear_set<dcmi_dr_r> {return opsy::utility::clear_set<dcmi_dr_r>(dcmi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 1
 */
class byte1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr byte1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_dr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_dr_r>() const {return opsy::utility::clear_set<dcmi_dr_r>(mask, *this);}
	constexpr auto operator|(dcmi_dr_r other) const -> dcmi_dr_r { return static_cast<dcmi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_dr_r> other) const -> opsy::utility::clear_set<dcmi_dr_r> {return opsy::utility::clear_set<dcmi_dr_r>(dcmi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 2
 */
class byte2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr byte2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_dr_r>() const {return opsy::utility::clear_set<dcmi_dr_r>(mask, *this);}
	constexpr auto operator|(dcmi_dr_r other) const -> dcmi_dr_r { return static_cast<dcmi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_dr_r> other) const -> opsy::utility::clear_set<dcmi_dr_r> {return opsy::utility::clear_set<dcmi_dr_r>(dcmi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data byte 3
 */
class byte3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr byte3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator dcmi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<dcmi_dr_r>() const {return opsy::utility::clear_set<dcmi_dr_r>(mask, *this);}
	constexpr auto operator|(dcmi_dr_r other) const -> dcmi_dr_r { return static_cast<dcmi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<dcmi_dr_r> other) const -> opsy::utility::clear_set<dcmi_dr_r> {return opsy::utility::clear_set<dcmi_dr_r>(dcmi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto byte0() const -> byte0_f {return byte0_f(static_cast<uint8_t>(value_ >> byte0_f::offset));}
	[[nodiscard]] constexpr auto byte1() const -> byte1_f {return byte1_f(static_cast<uint8_t>(value_ >> byte1_f::offset));}
	[[nodiscard]] constexpr auto byte2() const -> byte2_f {return byte2_f(static_cast<uint8_t>(value_ >> byte2_f::offset));}
	[[nodiscard]] constexpr auto byte3() const -> byte3_f {return byte3_f(static_cast<uint8_t>(value_ >> byte3_f::offset));}

	constexpr dcmi_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(dcmi_dr_r other) const -> dcmi_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> dcmi_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,dcmi_cr_r> dcmi_cr;
	opsy::utility::memory<uint32_t,dcmi_sr_r> dcmi_sr;
	opsy::utility::memory<uint32_t,dcmi_ris_r> dcmi_ris;
	opsy::utility::memory<uint32_t,dcmi_ier_r> dcmi_ier;
	opsy::utility::memory<uint32_t,dcmi_mis_r> dcmi_mis;
	opsy::utility::memory<uint32_t,dcmi_icr_r> dcmi_icr;
	opsy::utility::memory<uint32_t,dcmi_escr_r> dcmi_escr;
	opsy::utility::memory<uint32_t,dcmi_esur_r> dcmi_esur;
	opsy::utility::memory<uint32_t,dcmi_cwstrt_r> dcmi_cwstrt;
	opsy::utility::memory<uint32_t,dcmi_cwsize_r> dcmi_cwsize;
	opsy::utility::memory<uint32_t,dcmi_dr_r> dcmi_dr;
};

static_assert(std::is_standard_layout_v<dcmi_p>);
static_assert(offsetof(dcmi_p, dcmi_cr) == 0);
static_assert(offsetof(dcmi_p, dcmi_sr) == 4);
static_assert(offsetof(dcmi_p, dcmi_ris) == 8);
static_assert(offsetof(dcmi_p, dcmi_ier) == 12);
static_assert(offsetof(dcmi_p, dcmi_mis) == 16);
static_assert(offsetof(dcmi_p, dcmi_icr) == 20);
static_assert(offsetof(dcmi_p, dcmi_escr) == 24);
static_assert(offsetof(dcmi_p, dcmi_esur) == 28);
static_assert(offsetof(dcmi_p, dcmi_cwstrt) == 32);
static_assert(offsetof(dcmi_p, dcmi_cwsize) == 36);
static_assert(offsetof(dcmi_p, dcmi_dr) == 40);

inline dcmi_p& dcmi = *reinterpret_cast<dcmi_p*>(0x4202C000);
inline dcmi_p& sec_dcmi = *reinterpret_cast<dcmi_p*>(0x5202C000);

} // STM32H563

