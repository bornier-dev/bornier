#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Serial audio interface
 */
class sai_p {
public:

/**
 * SAI global configuration register 
 */
class sai_gcr_r {
public:

/**
 * Synchronization inputs These bits are set and cleared by software. Refer to for information on how to program this field. These bits must be set when both audio blocks (A and B) are disabled. They are meaningful if one of the two audio blocks is defined to operate in synchronous mode with an external SAI (SYNCEN[1:0] = 10 in SAI_ACR1 or in SAI_BCR1 registers).
 */
class syncin_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr syncin_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_gcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_gcr_r>() const {return opsy::utility::clear_set<sai_gcr_r>(mask, *this);}
	constexpr auto operator|(sai_gcr_r other) const -> sai_gcr_r { return static_cast<sai_gcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_gcr_r> other) const -> opsy::utility::clear_set<sai_gcr_r> {return opsy::utility::clear_set<sai_gcr_r>(sai_gcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Synchronization outputs These bits are set and cleared by software.
 */
class syncout_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr syncout_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_gcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_gcr_r>() const {return opsy::utility::clear_set<sai_gcr_r>(mask, *this);}
	constexpr auto operator|(sai_gcr_r other) const -> sai_gcr_r { return static_cast<sai_gcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_gcr_r> other) const -> opsy::utility::clear_set<sai_gcr_r> {return opsy::utility::clear_set<sai_gcr_r>(sai_gcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto syncin() const -> syncin_f {return syncin_f(static_cast<uint8_t>(value_ >> syncin_f::offset));}
	[[nodiscard]] constexpr auto syncout() const -> syncout_f {return syncout_f(static_cast<uint8_t>(value_ >> syncout_f::offset));}

	constexpr sai_gcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_gcr_r other) const -> sai_gcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_gcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI configuration register 1 
 */
class sai_xcr1_r {
public:

/**
 * SAIx audio block mode These bits are set and cleared by software. They must be configured when SAIx audio block is disabled. Note: When the audio block is configured in SPDIF mode, the master transmitter mode is forced (MODE[1:0] = 00).
 */
class mode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Protocol configuration These bits are set and cleared by software. These bits have to be configured when the audio block is disabled.
 */
class prtcfg_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prtcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data size These bits are set and cleared by software. These bits are ignored when the SPDIF protocols are selected (bit PRTCFG[1:0]), because the frame and the data size are fixed in such case. When the companding mode is selected through COMP[1:0] bits, DS[1:0] are ignored since the data size is fixed to 8 bits by the algorithm. These bits must be configured when the audio block is disabled.
 */
class ds_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ds_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Least significant bit first This bit is set and cleared by software. It must be configured when the audio block is disabled. This bit has no meaning in AC'97 audio protocol since AC'97 data are always transferred with the MSB first. This bit has no meaning in SPDIF audio protocol since in SPDIF data are always transferred with LSB first.
 */
class lsbfirst_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lsbfirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock strobing edge This bit is set and cleared by software. It must be configured when the audio block is disabled. This bit has no meaning in SPDIF audio protocol.
 */
class ckstr_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ckstr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Synchronization enable These bits are set and cleared by software. They must be configured when the audio subblock is disabled. Note: The audio subblock should be configured as asynchronous when SPDIF mode is enabled.
 */
class syncen_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr syncen_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Mono mode This bit is set and cleared by software. It is meaningful only when the number of slots is equal to 2. When the mono mode is selected, slot 0 data are duplicated on slot 1 when the audio block operates as a transmitter. In reception mode, the slot1 is discarded and only the data received from slot 0 are stored. Refer to for more details.
 */
class mono_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mono_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Output drive This bit is set and cleared by software. Note: This bit has to be set before enabling the audio block and after the audio block configuration.
 */
class outdriv_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr outdriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Audio block enable This bit is set by software. To switch off the audio block, the application software must program this bit to 0 and poll the bit till it reads back 0, meaning that the block is completely disabled. Before setting this bit to 1, check that it is set to 0, otherwise the enable command is not taken into account. This bit allows controlling the state of the SAI audio block. If it is disabled when an audio frame transfer is ongoing, the ongoing transfer completes and the cell is fully disabled at the end of this audio frame transfer. Note: When the SAI block (A or B) is configured in master mode, the clock must be present on the SAI block input before setting SAIEN bit.
 */
class saien_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr saien_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable This bit is set and cleared by software. Note: Since the audio block defaults to operate as a transmitter after reset, the MODE[1:0] bits must be configured before setting DMAEN to avoid a DMA request in receiver mode.
 */
class dmaen_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * No divider This bit is set and cleared by software.
 */
class nodiv_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nodiv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Master clock divider These bits are set and cleared by software. Otherwise, The master clock frequency is calculated according to the formula given in . These bits have no meaning when the audio block is slave. They have to be configured when the audio block is disabled.
 */
class mckdiv_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mckdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Oversampling ratio for master clock This bit is meaningful only when NODIV bit is set to 0.
 */
class osr_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr osr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Master clock generation enable
 */
class mcken_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr mcken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr1_r>() const {return opsy::utility::clear_set<sai_xcr1_r>(mask, *this);}
	constexpr auto operator|(sai_xcr1_r other) const -> sai_xcr1_r { return static_cast<sai_xcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr1_r> other) const -> opsy::utility::clear_set<sai_xcr1_r> {return opsy::utility::clear_set<sai_xcr1_r>(sai_xcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mode() const -> mode_f {return mode_f(static_cast<uint8_t>(value_ >> mode_f::offset));}
	[[nodiscard]] constexpr auto prtcfg() const -> prtcfg_f {return prtcfg_f(static_cast<uint8_t>(value_ >> prtcfg_f::offset));}
	[[nodiscard]] constexpr auto ds() const -> ds_f {return ds_f(static_cast<uint8_t>(value_ >> ds_f::offset));}
	[[nodiscard]] constexpr auto lsbfirst() const -> lsbfirst_f {return lsbfirst_f((value_ & lsbfirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto ckstr() const -> ckstr_f {return ckstr_f((value_ & ckstr_f::mask) != 0);}
	[[nodiscard]] constexpr auto syncen() const -> syncen_f {return syncen_f(static_cast<uint8_t>(value_ >> syncen_f::offset));}
	[[nodiscard]] constexpr auto mono() const -> mono_f {return mono_f((value_ & mono_f::mask) != 0);}
	[[nodiscard]] constexpr auto outdriv() const -> outdriv_f {return outdriv_f((value_ & outdriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto saien() const -> saien_f {return saien_f((value_ & saien_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaen() const -> dmaen_f {return dmaen_f((value_ & dmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto nodiv() const -> nodiv_f {return nodiv_f((value_ & nodiv_f::mask) != 0);}
	[[nodiscard]] constexpr auto mckdiv() const -> mckdiv_f {return mckdiv_f(static_cast<uint8_t>(value_ >> mckdiv_f::offset));}
	[[nodiscard]] constexpr auto osr() const -> osr_f {return osr_f((value_ & osr_f::mask) != 0);}
	[[nodiscard]] constexpr auto mcken() const -> mcken_f {return mcken_f((value_ & mcken_f::mask) != 0);}

	constexpr sai_xcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xcr1_r other) const -> sai_xcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000; // 64 0x40

private:
	uint32_t value_;
};

/**
 * SAI configuration register 2 
 */
class sai_xcr2_r {
public:

/**
 * FIFO threshold. This bit is set and cleared by software.
 */
class fth_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr fth_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FIFO flush. This bit is set by software. It is always read as 0. This bit should be configured when the SAI is disabled.
 */
class fflush_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fflush_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tristate management on data line. This bit is set and cleared by software. It is meaningful only if the audio block is configured as a transmitter. This bit is not used when the audio block is configured in SPDIF mode. It should be configured when SAI is disabled. Refer to for more details.
 */
class tris_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tris_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute. This bit is set and cleared by software. It is meaningful only when the audio block operates as a transmitter. The MUTE value is linked to value of MUTEVAL if the number of slots is lower or equal to 2, or equal to 0 if it is greater than 2. Refer to for more details. Note: This bit is meaningless and should not be used for SPDIF audio blocks.
 */
class mute_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mute_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute value. This bit is set and cleared by software.It must be written before enabling the audio block: SAIEN. This bit is meaningful only when the audio block operates as a transmitter, the number of slots is lower or equal to 2 and the MUTE bit is set. If more slots are declared, the bit value sent during the transmission in mute mode is equal to 0, whatever the value of MUTEVAL. if the number of slot is lower or equal to 2 and MUTEVAL = 1, the MUTE value transmitted for each slot is the one sent during the previous frame. Refer to for more details. Note: This bit is meaningless and should not be used for SPDIF audio blocks.
 */
class muteval_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr muteval_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute counter. These bits are set and cleared by software. They are used only in reception mode. The value set in these bits is compared to the number of consecutive mute frames detected in reception. When the number of mute frames is equal to this value, the flag MUTEDET is set and an interrupt is generated if bit MUTEDETIE is set. Refer to for more details.
 */
class mutecnt_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr mutecnt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Complement bit. This bit is set and cleared by software. It defines the type of complement to be used for companding mode Note: This bit has effect only when the companding mode is -Law algorithm or A-Law algorithm.
 */
class cpl_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cpl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xcr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Companding mode. These bits are set and cleared by software. The -Law and the A-Law log are a part of the CCITT G.711 recommendation, the type of complement that is used depends on CPL bit. The data expansion or data compression are determined by the state of bit MODE[0]. The data compression is applied if the audio block is configured as a transmitter. The data expansion is automatically applied when the audio block is configured as a receiver. Refer to for more details. Note: Companding mode is applicable only when Free protocol mode is selected.
 */
class comp_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr comp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xcr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xcr2_r>() const {return opsy::utility::clear_set<sai_xcr2_r>(mask, *this);}
	constexpr auto operator|(sai_xcr2_r other) const -> sai_xcr2_r { return static_cast<sai_xcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xcr2_r> other) const -> opsy::utility::clear_set<sai_xcr2_r> {return opsy::utility::clear_set<sai_xcr2_r>(sai_xcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto fth() const -> fth_f {return fth_f(static_cast<uint8_t>(value_ >> fth_f::offset));}
	[[nodiscard]] constexpr auto fflush() const -> fflush_f {return fflush_f((value_ & fflush_f::mask) != 0);}
	[[nodiscard]] constexpr auto tris() const -> tris_f {return tris_f((value_ & tris_f::mask) != 0);}
	[[nodiscard]] constexpr auto mute() const -> mute_f {return mute_f((value_ & mute_f::mask) != 0);}
	[[nodiscard]] constexpr auto muteval() const -> muteval_f {return muteval_f((value_ & muteval_f::mask) != 0);}
	[[nodiscard]] constexpr auto mutecnt() const -> mutecnt_f {return mutecnt_f(static_cast<uint8_t>(value_ >> mutecnt_f::offset));}
	[[nodiscard]] constexpr auto cpl() const -> cpl_f {return cpl_f((value_ & cpl_f::mask) != 0);}
	[[nodiscard]] constexpr auto comp() const -> comp_f {return comp_f(static_cast<uint8_t>(value_ >> comp_f::offset));}

	constexpr sai_xcr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xcr2_r other) const -> sai_xcr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xcr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI frame configuration register 
 */
class sai_xfrcr_r {
public:

/**
 * Frame length. These bits are set and cleared by software. They define the audio frame length expressed in number of SCK clock cycles: the number of bits in the frame is equal to FRL[7:0] + 1. The minimum number of bits to transfer in an audio frame must be equal to 8, otherwise the audio block behaves in an unexpected way. This is the case when the data size is 8 bits and only one slot 0 is defined in NBSLOT[4:0] of SAI_xSLOTR register (NBSLOT[3:0] = 0000). In master mode, if the master clock (available on MCLK_x pin) is used, the frame length should be aligned with a number equal to a power of 2, ranging from 8 to 256. When the master clock is not used (NODIV = 1), it is recommended to program the frame length to an value ranging from 8 to 256. These bits are meaningless and are not used in AC'97 or SPDIF audio block configuration. They must be configured when the audio block is disabled.
 */
class frl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr frl_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xfrcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xfrcr_r>() const {return opsy::utility::clear_set<sai_xfrcr_r>(mask, *this);}
	constexpr auto operator|(sai_xfrcr_r other) const -> sai_xfrcr_r { return static_cast<sai_xfrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xfrcr_r> other) const -> opsy::utility::clear_set<sai_xfrcr_r> {return opsy::utility::clear_set<sai_xfrcr_r>(sai_xfrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Frame synchronization active level length. These bits are set and cleared by software. They specify the length in number of bit clock (SCK) + 1 (FSALL[6:0] + 1) of the active level of the FS signal in the audio frame These bits are meaningless and are not used in AC'97 or SPDIF audio block configuration. They must be configured when the audio block is disabled.
 */
class fsall_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fsall_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xfrcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xfrcr_r>() const {return opsy::utility::clear_set<sai_xfrcr_r>(mask, *this);}
	constexpr auto operator|(sai_xfrcr_r other) const -> sai_xfrcr_r { return static_cast<sai_xfrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xfrcr_r> other) const -> opsy::utility::clear_set<sai_xfrcr_r> {return opsy::utility::clear_set<sai_xfrcr_r>(sai_xfrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Frame synchronization definition. This bit is set and cleared by software. When the bit is set, the number of slots defined in the SAI_xSLOTR register has to be even. It means that half of this number of slots are dedicated to the left channel and the other slots for the right channel (e.g: this bit has to be set for I2S or MSB/LSB-justified protocols...). This bit is meaningless and is not used in AC'97 or SPDIF audio block configuration. It must be configured when the audio block is disabled.
 */
class fsdef_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fsdef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xfrcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xfrcr_r>() const {return opsy::utility::clear_set<sai_xfrcr_r>(mask, *this);}
	constexpr auto operator|(sai_xfrcr_r other) const -> sai_xfrcr_r { return static_cast<sai_xfrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xfrcr_r> other) const -> opsy::utility::clear_set<sai_xfrcr_r> {return opsy::utility::clear_set<sai_xfrcr_r>(sai_xfrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frame synchronization polarity. This bit is set and cleared by software. It is used to configure the level of the start of frame on the FS signal. It is meaningless and is not used in AC'97 or SPDIF audio block configuration. This bit must be configured when the audio block is disabled.
 */
class fspol_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fspol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xfrcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xfrcr_r>() const {return opsy::utility::clear_set<sai_xfrcr_r>(mask, *this);}
	constexpr auto operator|(sai_xfrcr_r other) const -> sai_xfrcr_r { return static_cast<sai_xfrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xfrcr_r> other) const -> opsy::utility::clear_set<sai_xfrcr_r> {return opsy::utility::clear_set<sai_xfrcr_r>(sai_xfrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Frame synchronization offset. This bit is set and cleared by software. It is meaningless and is not used in AC'97 or SPDIF audio block configuration. This bit must be configured when the audio block is disabled.
 */
class fsoff_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fsoff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xfrcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xfrcr_r>() const {return opsy::utility::clear_set<sai_xfrcr_r>(mask, *this);}
	constexpr auto operator|(sai_xfrcr_r other) const -> sai_xfrcr_r { return static_cast<sai_xfrcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xfrcr_r> other) const -> opsy::utility::clear_set<sai_xfrcr_r> {return opsy::utility::clear_set<sai_xfrcr_r>(sai_xfrcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto frl() const -> frl_f {return frl_f(static_cast<uint8_t>(value_ >> frl_f::offset));}
	[[nodiscard]] constexpr auto fsall() const -> fsall_f {return fsall_f(static_cast<uint8_t>(value_ >> fsall_f::offset));}
	[[nodiscard]] constexpr auto fsdef() const -> fsdef_f {return fsdef_f((value_ & fsdef_f::mask) != 0);}
	[[nodiscard]] constexpr auto fspol() const -> fspol_f {return fspol_f((value_ & fspol_f::mask) != 0);}
	[[nodiscard]] constexpr auto fsoff() const -> fsoff_f {return fsoff_f((value_ & fsoff_f::mask) != 0);}

	constexpr sai_xfrcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xfrcr_r other) const -> sai_xfrcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xfrcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b111; // 7 0x7

private:
	uint32_t value_;
};

/**
 * SAI slot register 
 */
class sai_xslotr_r {
public:

/**
 * First bit offset These bits are set and cleared by software. The value set in this bitfield defines the position of the first data transfer bit in the slot. It represents an offset value. In transmission mode, the bits outside the data field are forced to 0. In reception mode, the extra received bits are discarded. These bits must be set when the audio block is disabled. They are ignored in AC'97 or SPDIF mode.
 */
class fboff_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr fboff_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xslotr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xslotr_r>() const {return opsy::utility::clear_set<sai_xslotr_r>(mask, *this);}
	constexpr auto operator|(sai_xslotr_r other) const -> sai_xslotr_r { return static_cast<sai_xslotr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xslotr_r> other) const -> opsy::utility::clear_set<sai_xslotr_r> {return opsy::utility::clear_set<sai_xslotr_r>(sai_xslotr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Slot size This bits is set and cleared by software. The slot size must be higher or equal to the data size. If this condition is not respected, the behavior of the SAI is undetermined. Refer to for information on how to drive SD line. These bits must be set when the audio block is disabled. They are ignored in AC'97 or SPDIF mode.
 */
class slotsz_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr slotsz_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xslotr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xslotr_r>() const {return opsy::utility::clear_set<sai_xslotr_r>(mask, *this);}
	constexpr auto operator|(sai_xslotr_r other) const -> sai_xslotr_r { return static_cast<sai_xslotr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xslotr_r> other) const -> opsy::utility::clear_set<sai_xslotr_r> {return opsy::utility::clear_set<sai_xslotr_r>(sai_xslotr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of slots in an audio frame. These bits are set and cleared by software. The value set in this bitfield represents the number of slots + 1 in the audio frame (including the number of inactive slots). The maximum number of slots is 16. The number of slots should be even if FSDEF bit in the SAI_xFRCR register is set. The number of slots must be configured when the audio block is disabled. They are ignored in AC'97 or SPDIF mode.
 */
class nbslot_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr nbslot_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xslotr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xslotr_r>() const {return opsy::utility::clear_set<sai_xslotr_r>(mask, *this);}
	constexpr auto operator|(sai_xslotr_r other) const -> sai_xslotr_r { return static_cast<sai_xslotr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xslotr_r> other) const -> opsy::utility::clear_set<sai_xslotr_r> {return opsy::utility::clear_set<sai_xslotr_r>(sai_xslotr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Slot enable. These bits are set and cleared by software. Each SLOTEN bit corresponds to a slot position from 0 to 15 (maximum 16 slots). The slot must be enabled when the audio block is disabled. They are ignored in AC'97 or SPDIF mode.
 */
class sloten_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sloten_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator sai_xslotr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xslotr_r>() const {return opsy::utility::clear_set<sai_xslotr_r>(mask, *this);}
	constexpr auto operator|(sai_xslotr_r other) const -> sai_xslotr_r { return static_cast<sai_xslotr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xslotr_r> other) const -> opsy::utility::clear_set<sai_xslotr_r> {return opsy::utility::clear_set<sai_xslotr_r>(sai_xslotr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto fboff() const -> fboff_f {return fboff_f(static_cast<uint8_t>(value_ >> fboff_f::offset));}
	[[nodiscard]] constexpr auto slotsz() const -> slotsz_f {return slotsz_f(static_cast<uint8_t>(value_ >> slotsz_f::offset));}
	[[nodiscard]] constexpr auto nbslot() const -> nbslot_f {return nbslot_f(static_cast<uint8_t>(value_ >> nbslot_f::offset));}
	[[nodiscard]] constexpr auto sloten() const -> sloten_f {return sloten_f(static_cast<uint16_t>(value_ >> sloten_f::offset));}

	constexpr sai_xslotr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xslotr_r other) const -> sai_xslotr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xslotr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI interrupt mask register 
 */
class sai_xim_r {
public:

/**
 * Overrun/underrun interrupt enable. This bit is set and cleared by software. When this bit is set, an interrupt is generated if the OVRUDR bit in the SAI_xSR register is set.
 */
class ovrudrie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovrudrie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute detection interrupt enable. This bit is set and cleared by software. When this bit is set, an interrupt is generated if the MUTEDET bit in the SAI_xSR register is set. This bit has a meaning only if the audio block is configured in receiver mode.
 */
class mutedetie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mutedetie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wrong clock configuration interrupt enable. This bit is set and cleared by software. This bit is taken into account only if the audio block is configured as a master (MODE[1] = 0) and NODIV = 0. It generates an interrupt if the WCKCFG flag in the SAI_xSR register is set. Note: This bit is used only in Free protocol mode and is meaningless in other modes.
 */
class wckcfgie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wckcfgie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO request interrupt enable. This bit is set and cleared by software. When this bit is set, an interrupt is generated if the FREQ bit in the SAI_xSR register is set. Since the audio block defaults to operate as a transmitter after reset, the MODE bit must be configured before setting FREQIE to avoid a parasitic interrupt in receiver mode,
 */
class freqie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr freqie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Codec not ready interrupt enable (AC'97). This bit is set and cleared by software. When the interrupt is enabled, the audio block detects in the slot 0 (tag0) of the AC'97 frame if the Codec connected to this line is ready or not. If it is not ready, the CNRDY flag in the SAI_xSR register is set and an interrupt is generated. This bit has a meaning only if the AC'97 mode is selected through PRTCFG[1:0] bits and the audio block is operates as a receiver.
 */
class cnrdyie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cnrdyie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Anticipated frame synchronization detection interrupt enable. This bit is set and cleared by software. When this bit is set, an interrupt is generated if the AFSDET bit in the SAI_xSR register is set. This bit is meaningless in AC'97, SPDIF mode or when the audio block operates as a master.
 */
class afsdetie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr afsdetie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Late frame synchronization detection interrupt enable. This bit is set and cleared by software. When this bit is set, an interrupt is generated if the LFSDET bit is set in the SAI_xSR register. This bit is meaningless in AC'97, SPDIF mode or when the audio block operates as a master.
 */
class lfsdetie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lfsdetie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xim_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xim_r>() const {return opsy::utility::clear_set<sai_xim_r>(mask, *this);}
	constexpr auto operator|(sai_xim_r other) const -> sai_xim_r { return static_cast<sai_xim_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xim_r> other) const -> opsy::utility::clear_set<sai_xim_r> {return opsy::utility::clear_set<sai_xim_r>(sai_xim_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ovrudrie() const -> ovrudrie_f {return ovrudrie_f((value_ & ovrudrie_f::mask) != 0);}
	[[nodiscard]] constexpr auto mutedetie() const -> mutedetie_f {return mutedetie_f((value_ & mutedetie_f::mask) != 0);}
	[[nodiscard]] constexpr auto wckcfgie() const -> wckcfgie_f {return wckcfgie_f((value_ & wckcfgie_f::mask) != 0);}
	[[nodiscard]] constexpr auto freqie() const -> freqie_f {return freqie_f((value_ & freqie_f::mask) != 0);}
	[[nodiscard]] constexpr auto cnrdyie() const -> cnrdyie_f {return cnrdyie_f((value_ & cnrdyie_f::mask) != 0);}
	[[nodiscard]] constexpr auto afsdetie() const -> afsdetie_f {return afsdetie_f((value_ & afsdetie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lfsdetie() const -> lfsdetie_f {return lfsdetie_f((value_ & lfsdetie_f::mask) != 0);}

	constexpr sai_xim_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xim_r other) const -> sai_xim_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xim_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI status register 
 */
class sai_xsr_r {
public:

/**
 * Overrun / underrun. This bit is read only. The overrun and underrun conditions can occur only when the audio block is configured as a receiver and a transmitter, respectively. It can generate an interrupt if OVRUDRIE bit is set in SAI_xIM register. This flag is cleared when the software sets COVRUDR bit in SAI_xCLRFR register.
 */
class ovrudr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ovrudr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute detection. This bit is read only. This flag is set if consecutive 0 values are received in each slot of a given audio frame and for a consecutive number of audio frames (set in the MUTECNT bit in the SAI_xCR2 register). It can generate an interrupt if MUTEDETIE bit is set in SAI_xIM register. This flag is cleared when the software sets bit CMUTEDET in the SAI_xCLRFR register.
 */
class mutedet_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mutedet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wrong clock configuration flag. This bit is read only. This bit is used only when the audio block operates in master mode (MODE[1] = 0) and NODIV = 0. It can generate an interrupt if WCKCFGIE bit is set in SAI_xIM register. This flag is cleared when the software sets CWCKCFG bit in SAI_xCLRFR register.
 */
class wckcfg_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wckcfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO request. This bit is read only. The request depends on the audio block configuration: If the block is configured in transmission mode, the FIFO request is related to a write request operation in the SAI_xDR. If the block configured in reception, the FIFO request related to a read request operation from the SAI_xDR. This flag can generate an interrupt if FREQIE bit is set in SAI_xIM register.
 */
class freq_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr freq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Codec not ready. This bit is read only. This bit is used only when the AC'97 audio protocol is selected in the SAI_xCR1 register and configured in receiver mode. It can generate an interrupt if CNRDYIE bit is set in SAI_xIM register. This flag is cleared when the software sets CCNRDY bit in SAI_xCLRFR register.
 */
class cnrdy_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cnrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Anticipated frame synchronization detection. This bit is read only. This flag can be set only if the audio block is configured in slave mode. It is not used in AC'97 or SPDIF mode. It can generate an interrupt if AFSDETIE bit is set in SAI_xIM register. This flag is cleared when the software sets CAFSDET bit in SAI_xCLRFR register.
 */
class afsdet_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr afsdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Late frame synchronization detection. This bit is read only. This flag can be set only if the audio block is configured in slave mode. It is not used in AC'97 or SPDIF mode. It can generate an interrupt if LFSDETIE bit is set in the SAI_xIM register. This flag is cleared when the software sets bit CLFSDET in SAI_xCLRFR register
 */
class lfsdet_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lfsdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO level threshold. This bit is read only. The FIFO level threshold flag is managed only by hardware and its setting depends on SAI block configuration (transmitter or receiver mode). Others: Reserved
 */
class flvl_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr flvl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_xsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xsr_r>() const {return opsy::utility::clear_set<sai_xsr_r>(mask, *this);}
	constexpr auto operator|(sai_xsr_r other) const -> sai_xsr_r { return static_cast<sai_xsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xsr_r> other) const -> opsy::utility::clear_set<sai_xsr_r> {return opsy::utility::clear_set<sai_xsr_r>(sai_xsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ovrudr() const -> ovrudr_f {return ovrudr_f((value_ & ovrudr_f::mask) != 0);}
	[[nodiscard]] constexpr auto mutedet() const -> mutedet_f {return mutedet_f((value_ & mutedet_f::mask) != 0);}
	[[nodiscard]] constexpr auto wckcfg() const -> wckcfg_f {return wckcfg_f((value_ & wckcfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto freq() const -> freq_f {return freq_f((value_ & freq_f::mask) != 0);}
	[[nodiscard]] constexpr auto cnrdy() const -> cnrdy_f {return cnrdy_f((value_ & cnrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto afsdet() const -> afsdet_f {return afsdet_f((value_ & afsdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto lfsdet() const -> lfsdet_f {return lfsdet_f((value_ & lfsdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto flvl() const -> flvl_f {return flvl_f(static_cast<uint8_t>(value_ >> flvl_f::offset));}

	constexpr sai_xsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xsr_r other) const -> sai_xsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000; // 8 0x8

private:
	uint32_t value_;
};

/**
 * SAI clear flag register 
 */
class sai_xclrfr_r {
public:

/**
 * Clear overrun / underrun. This bit is write only. Programming this bit to 1 clears the OVRUDR flag in the SAI_xSR register. Reading this bit always returns the value 0.
 */
class covrudr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr covrudr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute detection flag. This bit is write only. Programming this bit to 1 clears the MUTEDET flag in the SAI_xSR register. Reading this bit always returns the value 0.
 */
class cmutedet_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cmutedet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear wrong clock configuration flag. This bit is write only. Programming this bit to 1 clears the WCKCFG flag in the SAI_xSR register. This bit is used only when the audio block is set as master (MODE[1] = 0) and NODIV = 0 in the SAI_xCR1 register. Reading this bit always returns the value 0.
 */
class cwckcfg_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cwckcfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear Codec not ready flag. This bit is write only. Programming this bit to 1 clears the CNRDY flag in the SAI_xSR register. This bit is used only when the AC'97 audio protocol is selected in the SAI_xCR1 register. Reading this bit always returns the value 0.
 */
class ccnrdy_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ccnrdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear anticipated frame synchronization detection flag. This bit is write only. Programming this bit to 1 clears the AFSDET flag in the SAI_xSR register. It is not used in AC'97 or SPDIF mode. Reading this bit always returns the value 0.
 */
class cafsdet_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cafsdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear late frame synchronization detection flag. This bit is write only. Programming this bit to 1 clears the LFSDET flag in the SAI_xSR register. This bit is not used in AC'97 or SPDIF mode Reading this bit always returns the value 0.
 */
class clfsdet_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr clfsdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_xclrfr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_xclrfr_r>() const {return opsy::utility::clear_set<sai_xclrfr_r>(mask, *this);}
	constexpr auto operator|(sai_xclrfr_r other) const -> sai_xclrfr_r { return static_cast<sai_xclrfr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xclrfr_r> other) const -> opsy::utility::clear_set<sai_xclrfr_r> {return opsy::utility::clear_set<sai_xclrfr_r>(sai_xclrfr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto covrudr() const -> covrudr_f {return covrudr_f((value_ & covrudr_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmutedet() const -> cmutedet_f {return cmutedet_f((value_ & cmutedet_f::mask) != 0);}
	[[nodiscard]] constexpr auto cwckcfg() const -> cwckcfg_f {return cwckcfg_f((value_ & cwckcfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto ccnrdy() const -> ccnrdy_f {return ccnrdy_f((value_ & ccnrdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cafsdet() const -> cafsdet_f {return cafsdet_f((value_ & cafsdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto clfsdet() const -> clfsdet_f {return clfsdet_f((value_ & clfsdet_f::mask) != 0);}

	constexpr sai_xclrfr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xclrfr_r other) const -> sai_xclrfr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xclrfr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI data register 
 */
class sai_xdr_r {
public:

/**
 * Data A write to this register loads the FIFO provided the FIFO is not full. A read from this register empties the FIFO if the FIFO is not empty.
 */
class data_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr data_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator sai_xdr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_xdr_r>() const {return opsy::utility::clear_set<sai_xdr_r>(mask, *this);}
	constexpr auto operator|(sai_xdr_r other) const -> sai_xdr_r { return static_cast<sai_xdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_xdr_r> other) const -> opsy::utility::clear_set<sai_xdr_r> {return opsy::utility::clear_set<sai_xdr_r>(sai_xdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto data() const -> data_f {return data_f(static_cast<uint32_t>(value_ >> data_f::offset));}

	constexpr sai_xdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_xdr_r other) const -> sai_xdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_xdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI PDM control register 
 */
class sai_pdmcr_r {
public:

/**
 * PDM enable This bit is set and cleared by software. This bit allows to control the state of the PDM interface block. Make sure that the SAI in already operating in TDM master mode before enabling the PDM interface.
 */
class pdmen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pdmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_pdmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_pdmcr_r>() const {return opsy::utility::clear_set<sai_pdmcr_r>(mask, *this);}
	constexpr auto operator|(sai_pdmcr_r other) const -> sai_pdmcr_r { return static_cast<sai_pdmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmcr_r> other) const -> opsy::utility::clear_set<sai_pdmcr_r> {return opsy::utility::clear_set<sai_pdmcr_r>(sai_pdmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of microphones This bit is set and cleared by software. Note: It is not recommended to configure this field when PDMEN = 1.* The complete set of data lines might not be available for all SAI instances. Refer to for details.
 */
class micnbr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr micnbr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmcr_r>() const {return opsy::utility::clear_set<sai_pdmcr_r>(mask, *this);}
	constexpr auto operator|(sai_pdmcr_r other) const -> sai_pdmcr_r { return static_cast<sai_pdmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmcr_r> other) const -> opsy::utility::clear_set<sai_pdmcr_r> {return opsy::utility::clear_set<sai_pdmcr_r>(sai_pdmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clock enable of bitstream clock number 1 This bit is set and cleared by software. Note: It is not recommended to configure this bit when PDMEN = 1. SAI_CK1 might not be available for all SAI instances. Refer to implementation for details.
 */
class cken1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cken1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_pdmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_pdmcr_r>() const {return opsy::utility::clear_set<sai_pdmcr_r>(mask, *this);}
	constexpr auto operator|(sai_pdmcr_r other) const -> sai_pdmcr_r { return static_cast<sai_pdmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmcr_r> other) const -> opsy::utility::clear_set<sai_pdmcr_r> {return opsy::utility::clear_set<sai_pdmcr_r>(sai_pdmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clock enable of bitstream clock number 2 This bit is set and cleared by software. Note: It is not recommended to configure this bit when PDMEN = 1. SAI_CK2 might not be available for all SAI instances. Refer to implementation for details.
 */
class cken2_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cken2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator sai_pdmcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<sai_pdmcr_r>() const {return opsy::utility::clear_set<sai_pdmcr_r>(mask, *this);}
	constexpr auto operator|(sai_pdmcr_r other) const -> sai_pdmcr_r { return static_cast<sai_pdmcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmcr_r> other) const -> opsy::utility::clear_set<sai_pdmcr_r> {return opsy::utility::clear_set<sai_pdmcr_r>(sai_pdmcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pdmen() const -> pdmen_f {return pdmen_f((value_ & pdmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto micnbr() const -> micnbr_f {return micnbr_f(static_cast<uint8_t>(value_ >> micnbr_f::offset));}
	[[nodiscard]] constexpr auto cken1() const -> cken1_f {return cken1_f((value_ & cken1_f::mask) != 0);}
	[[nodiscard]] constexpr auto cken2() const -> cken2_f {return cken2_f((value_ & cken2_f::mask) != 0);}

	constexpr sai_pdmcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_pdmcr_r other) const -> sai_pdmcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_pdmcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SAI PDM delay register 
 */
class sai_pdmdly_r {
public:

/**
 * Delay line adjust for first microphone of pair 1 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D1 line is available.Refer to to check if it is available.
 */
class dlym1l_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dlym1l_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line adjust for second microphone of pair 1 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D1 line is available.Refer to to check if it is available.
 */
class dlym1r_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dlym1r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for first microphone of pair 2 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D2 line is available.Refer to to check if it is available.
 */
class dlym2l_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dlym2l_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for second microphone of pair 2 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D2 line is available.Refer to to check if it is available.
 */
class dlym2r_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr dlym2r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for first microphone of pair 3 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D3 line is available.Refer to to check if it is available.
 */
class dlym3l_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dlym3l_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for second microphone of pair 3 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D3 line is available.Refer to to check if it is available.
 */
class dlym3r_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dlym3r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for first microphone of pair 4 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D4 line is available.Refer to to check if it is available.
 */
class dlym4l_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dlym4l_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay line for second microphone of pair 4 This bit is set and cleared by software. ... This field can be changed on-the-fly. Note: This field can be used only if D4 line is available.Refer to to check if it is available.
 */
class dlym4r_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dlym4r_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator sai_pdmdly_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<sai_pdmdly_r>() const {return opsy::utility::clear_set<sai_pdmdly_r>(mask, *this);}
	constexpr auto operator|(sai_pdmdly_r other) const -> sai_pdmdly_r { return static_cast<sai_pdmdly_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<sai_pdmdly_r> other) const -> opsy::utility::clear_set<sai_pdmdly_r> {return opsy::utility::clear_set<sai_pdmdly_r>(sai_pdmdly_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dlym1l() const -> dlym1l_f {return dlym1l_f(static_cast<uint8_t>(value_ >> dlym1l_f::offset));}
	[[nodiscard]] constexpr auto dlym1r() const -> dlym1r_f {return dlym1r_f(static_cast<uint8_t>(value_ >> dlym1r_f::offset));}
	[[nodiscard]] constexpr auto dlym2l() const -> dlym2l_f {return dlym2l_f(static_cast<uint8_t>(value_ >> dlym2l_f::offset));}
	[[nodiscard]] constexpr auto dlym2r() const -> dlym2r_f {return dlym2r_f(static_cast<uint8_t>(value_ >> dlym2r_f::offset));}
	[[nodiscard]] constexpr auto dlym3l() const -> dlym3l_f {return dlym3l_f(static_cast<uint8_t>(value_ >> dlym3l_f::offset));}
	[[nodiscard]] constexpr auto dlym3r() const -> dlym3r_f {return dlym3r_f(static_cast<uint8_t>(value_ >> dlym3r_f::offset));}
	[[nodiscard]] constexpr auto dlym4l() const -> dlym4l_f {return dlym4l_f(static_cast<uint8_t>(value_ >> dlym4l_f::offset));}
	[[nodiscard]] constexpr auto dlym4r() const -> dlym4r_f {return dlym4r_f(static_cast<uint8_t>(value_ >> dlym4r_f::offset));}

	constexpr sai_pdmdly_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(sai_pdmdly_r other) const -> sai_pdmdly_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> sai_pdmdly_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,sai_gcr_r> sai_gcr;
	opsy::utility::memory<uint32_t,sai_xcr1_r> sai_acr1;
	opsy::utility::memory<uint32_t,sai_xcr2_r> sai_acr2;
	opsy::utility::memory<uint32_t,sai_xfrcr_r> sai_afrcr;
	opsy::utility::memory<uint32_t,sai_xslotr_r> sai_aslotr;
	opsy::utility::memory<uint32_t,sai_xim_r> sai_aim;
	opsy::utility::memory<uint32_t,sai_xsr_r> sai_asr;
	opsy::utility::memory<uint32_t,sai_xclrfr_r> sai_aclrfr;
	opsy::utility::memory<uint32_t,sai_xdr_r> sai_adr;
	opsy::utility::memory<uint32_t,sai_xcr1_r> sai_bcr1;
	opsy::utility::memory<uint32_t,sai_xcr2_r> sai_bcr2;
	opsy::utility::memory<uint32_t,sai_xfrcr_r> sai_bfrcr;
	opsy::utility::memory<uint32_t,sai_xslotr_r> sai_bslotr;
	opsy::utility::memory<uint32_t,sai_xim_r> sai_bim;
	opsy::utility::memory<uint32_t,sai_xsr_r> sai_bsr;
	opsy::utility::memory<uint32_t,sai_xclrfr_r> sai_bclrfr;
	opsy::utility::memory<uint32_t,sai_xdr_r> sai_bdr;
	opsy::utility::memory<uint32_t,sai_pdmcr_r> sai_pdmcr;
	opsy::utility::memory<uint32_t,sai_pdmdly_r> sai_pdmdly;
};

static_assert(std::is_standard_layout_v<sai_p>);
static_assert(offsetof(sai_p, sai_gcr) == 0);
static_assert(offsetof(sai_p, sai_acr1) == 4);
static_assert(offsetof(sai_p, sai_acr2) == 8);
static_assert(offsetof(sai_p, sai_afrcr) == 12);
static_assert(offsetof(sai_p, sai_aslotr) == 16);
static_assert(offsetof(sai_p, sai_aim) == 20);
static_assert(offsetof(sai_p, sai_asr) == 24);
static_assert(offsetof(sai_p, sai_aclrfr) == 28);
static_assert(offsetof(sai_p, sai_adr) == 32);
static_assert(offsetof(sai_p, sai_bcr1) == 36);
static_assert(offsetof(sai_p, sai_bcr2) == 40);
static_assert(offsetof(sai_p, sai_bfrcr) == 44);
static_assert(offsetof(sai_p, sai_bslotr) == 48);
static_assert(offsetof(sai_p, sai_bim) == 52);
static_assert(offsetof(sai_p, sai_bsr) == 56);
static_assert(offsetof(sai_p, sai_bclrfr) == 60);
static_assert(offsetof(sai_p, sai_bdr) == 64);
static_assert(offsetof(sai_p, sai_pdmcr) == 68);
static_assert(offsetof(sai_p, sai_pdmdly) == 72);

inline sai_p& sai1 = *reinterpret_cast<sai_p*>(0x40015400);
inline sai_p& sai2 = *reinterpret_cast<sai_p*>(0x40015800);
inline sai_p& sec_sai1 = *reinterpret_cast<sai_p*>(0x50015400);
inline sai_p& sec_sai2 = *reinterpret_cast<sai_p*>(0x50015800);

} // STM32H563

