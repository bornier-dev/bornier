#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * HASH register bank
 */
class hash_p {
public:

/**
 * HASH control register 
 */
class hash_cr_r {
public:

/**
 * Initialize message digest calculation Writing this bit to 1 resets the hash processor core, so that the HASH is ready to compute the message digest of a new message. Writing this bit to 0 has no effect. Reading this bit always returns 0.
 */
class init_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr init_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable After this bit is set, it is cleared by hardware while the last data of the message is written into the hash processor. Setting this bit to 0 while a DMA transfer is ongoing does not abort the current transfer. Instead, the DMA interface of the HASH remains internally enabled until the transfer is completed or INIT is written to 1. Setting INIT bit to 1 does not clear DMAE bit.
 */
class dmae_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmae_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data type selection This bitfield defines the format of the data entered into the HASH_DIN register:
 */
class datatype_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr datatype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_cr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Mode selection This bit selects the normal or the keyed HMAC mode for the selected algorithm: This selection is only taken into account when the INIT bit is set. Changing this bit during a computation has no effect.
 */
class mode_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of words already pushed Refer to NBWP[3:0] bitfield of HASH_SR for a description of NBW[3:0] bitfield. This bit is read-only.
 */
class nbw_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr nbw_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DIN not empty Refer to DINNE bit of HASH_SR for a description of DINNE bit. This bit is read-only.
 */
class dinne_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dinne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Multiple DMA transfers This bit is set when hashing large files when multiple DMA transfers are needed.
 */
class mdmat_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mdmat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Long key selection The application must set this bit if the HMAC key is greater than the block size corresponding to the hash algorithm (see algorithms for details). For example the block size is 64 bytes for SHA2-256. This selection is only taken into account when the INIT and MODE bits are set (HMAC mode selected). Changing this bit during a computation has no effect.
 */
class lkey_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lkey_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Algorithm selection These bits select the hash algorithm: This selection is only taken into account when the INIT bit is set. Changing this bitfield during a computation has no effect. When the ALGO bitfield is updated and INIT bit is set, NBWE in HASH_SR is automatically updated to 0x11.
 */
class algo_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr algo_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_cr_r>() const {return opsy::utility::clear_set<hash_cr_r>(mask, *this);}
	constexpr auto operator|(hash_cr_r other) const -> hash_cr_r { return static_cast<hash_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_cr_r> other) const -> opsy::utility::clear_set<hash_cr_r> {return opsy::utility::clear_set<hash_cr_r>(hash_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto init() const -> init_f {return init_f((value_ & init_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmae() const -> dmae_f {return dmae_f((value_ & dmae_f::mask) != 0);}
	[[nodiscard]] constexpr auto datatype() const -> datatype_f {return datatype_f(static_cast<uint8_t>(value_ >> datatype_f::offset));}
	[[nodiscard]] constexpr auto mode() const -> mode_f {return mode_f((value_ & mode_f::mask) != 0);}
	[[nodiscard]] constexpr auto nbw() const -> nbw_f {return nbw_f(static_cast<uint8_t>(value_ >> nbw_f::offset));}
	[[nodiscard]] constexpr auto dinne() const -> dinne_f {return dinne_f((value_ & dinne_f::mask) != 0);}
	[[nodiscard]] constexpr auto mdmat() const -> mdmat_f {return mdmat_f((value_ & mdmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto lkey() const -> lkey_f {return lkey_f((value_ & lkey_f::mask) != 0);}
	[[nodiscard]] constexpr auto algo() const -> algo_f {return algo_f(static_cast<uint8_t>(value_ >> algo_f::offset));}

	constexpr hash_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_cr_r other) const -> hash_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH data input register 
 */
class hash_din_r {
public:

/**
 * Data input Writing this register pushes the current register content into the FIFO, and the register takes the new value presented on the AHB bus. Reading this register returns zeros.
 */
class datain_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datain_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_din_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_din_r>() const {return opsy::utility::clear_set<hash_din_r>(mask, *this);}
	constexpr auto operator|(hash_din_r other) const -> hash_din_r { return static_cast<hash_din_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_din_r> other) const -> opsy::utility::clear_set<hash_din_r> {return opsy::utility::clear_set<hash_din_r>(hash_din_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto datain() const -> datain_f {return datain_f(static_cast<uint32_t>(value_ >> datain_f::offset));}

	constexpr hash_din_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_din_r other) const -> hash_din_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_din_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH start register 
 */
class hash_str_r {
public:

/**
 * Number of valid bits in the last word When the last word of the message bit string is written to HASH_DIN register, the hash processor takes only the valid bits, specified as below, after internal data swapping: ... The above mechanism is valid only if DCAL = 0. If NBLW bits are written while DCAL is set to 1, the NBLW bitfield remains unchanged. In other words it is not possible to configure NBLW and set DCAL at the same time. Reading NBLW bits returns the last value written to NBLW.
 */
class nblw_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nblw_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_str_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_str_r>() const {return opsy::utility::clear_set<hash_str_r>(mask, *this);}
	constexpr auto operator|(hash_str_r other) const -> hash_str_r { return static_cast<hash_str_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_str_r> other) const -> opsy::utility::clear_set<hash_str_r> {return opsy::utility::clear_set<hash_str_r>(hash_str_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Digest calculation Writing this bit to 1 starts the message padding using the previously written value of NBLW, and starts the calculation of the final message digest with all the data words written to the input FIFO since the INIT bit was last written to 1. Reading this bit returns 0.
 */
class dcal_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dcal_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_str_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_str_r>() const {return opsy::utility::clear_set<hash_str_r>(mask, *this);}
	constexpr auto operator|(hash_str_r other) const -> hash_str_r { return static_cast<hash_str_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_str_r> other) const -> opsy::utility::clear_set<hash_str_r> {return opsy::utility::clear_set<hash_str_r>(hash_str_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto nblw() const -> nblw_f {return nblw_f(static_cast<uint8_t>(value_ >> nblw_f::offset));}
	[[nodiscard]] constexpr auto dcal() const -> dcal_f {return dcal_f((value_ & dcal_f::mask) != 0);}

	constexpr hash_str_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_str_r other) const -> hash_str_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_str_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH aliased digest register 0
 */
class hash_hra0_r {
public:

/**
 * Hash data x Refer to introduction.
 */
class hx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr hx_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra0_r>() const {return opsy::utility::clear_set<hash_hra0_r>(mask, *this);}
	constexpr auto operator|(hash_hra0_r other) const -> hash_hra0_r { return static_cast<hash_hra0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra0_r> other) const -> opsy::utility::clear_set<hash_hra0_r> {return opsy::utility::clear_set<hash_hra0_r>(hash_hra0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto hx() const -> hx_f {return hx_f(static_cast<uint32_t>(value_ >> hx_f::offset));}

	constexpr hash_hra0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra0_r other) const -> hash_hra0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH interrupt enable register 
 */
class hash_imr_r {
public:

/**
 * Data input interrupt enable
 */
class dinie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dinie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_imr_r>() const {return opsy::utility::clear_set<hash_imr_r>(mask, *this);}
	constexpr auto operator|(hash_imr_r other) const -> hash_imr_r { return static_cast<hash_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_imr_r> other) const -> opsy::utility::clear_set<hash_imr_r> {return opsy::utility::clear_set<hash_imr_r>(hash_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Digest calculation completion interrupt enable
 */
class dcie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_imr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_imr_r>() const {return opsy::utility::clear_set<hash_imr_r>(mask, *this);}
	constexpr auto operator|(hash_imr_r other) const -> hash_imr_r { return static_cast<hash_imr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_imr_r> other) const -> opsy::utility::clear_set<hash_imr_r> {return opsy::utility::clear_set<hash_imr_r>(hash_imr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dinie() const -> dinie_f {return dinie_f((value_ & dinie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcie() const -> dcie_f {return dcie_f((value_ & dcie_f::mask) != 0);}

	constexpr hash_imr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_imr_r other) const -> hash_imr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_imr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH status register 
 */
class hash_sr_r {
public:

/**
 * Data input interrupt status This bit is set by hardware when the FIFO is ready to get a new block (16 locations are free). It is cleared by writing it to 0 or by writing the HASH_DIN register. When DINIS = 0, HASH_CSRx registers reads as zero.
 */
class dinis_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dinis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Digest calculation completion interrupt status This bit is set by hardware when a digest becomes ready (the whole message has been processed). It is cleared by writing it to 0 or by writing the INIT bit to 1 in the HASH_CR register.
 */
class dcis_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Status This bit provides information on the DMA interface activity. It is set with DMAE and cleared when DMAE = 0 and no DMA transfer is ongoing. No interrupt is associated with this bit.
 */
class dmas_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmas_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy bit
 */
class busy_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of words already pushed This bitfield is the exact number of words in the message that have already been pushed into the FIFO. NBWP is incremented by 1 when a write access is performed to the HASH_DIN register. When a digest calculation starts, NBWP is updated to NBWP- block size (in words), and NBWP goes to zero when the INIT bit is written to 1.
 */
class nbwp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr nbwp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * DIN not empty This bit is set when the HASH_DIN register holds valid data (that is after being written at least once). It is cleared when either the INIT bit (initialization) or the DCAL bit (completion of the previous message processing) is written to 1.
 */
class dinne_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dinne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator hash_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of words expected This bitfield reflects the number of words in the message that must be pushed into the FIFO to trigger a partial computation. NBWE is decremented by 1 when a write access is performed to the HASH_DIN register. NBWE is set to the expected block size +1 in words (0x11) when INIT bit is set in HASH_CR. It is set to the expected block size (0x10) when the partial digest calculation ends.
 */
class nbwe_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nbwe_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator hash_sr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_sr_r>() const {return opsy::utility::clear_set<hash_sr_r>(mask, *this);}
	constexpr auto operator|(hash_sr_r other) const -> hash_sr_r { return static_cast<hash_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_sr_r> other) const -> opsy::utility::clear_set<hash_sr_r> {return opsy::utility::clear_set<hash_sr_r>(hash_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dinis() const -> dinis_f {return dinis_f((value_ & dinis_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcis() const -> dcis_f {return dcis_f((value_ & dcis_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmas() const -> dmas_f {return dmas_f((value_ & dmas_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto nbwp() const -> nbwp_f {return nbwp_f(static_cast<uint8_t>(value_ >> nbwp_f::offset));}
	[[nodiscard]] constexpr auto dinne() const -> dinne_f {return dinne_f((value_ & dinne_f::mask) != 0);}
	[[nodiscard]] constexpr auto nbwe() const -> nbwe_f {return nbwe_f(static_cast<uint8_t>(value_ >> nbwe_f::offset));}

	constexpr hash_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_sr_r other) const -> hash_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100010000000000000001; // 1114113 0x110001

private:
	uint32_t value_;
};

/**
 * HASH context swap register 0
 */
class hash_csr0_r {
public:

/**
 * Context swap 0 Refer to introduction.
 */
class csx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr csx_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr0_r>() const {return opsy::utility::clear_set<hash_csr0_r>(mask, *this);}
	constexpr auto operator|(hash_csr0_r other) const -> hash_csr0_r { return static_cast<hash_csr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr0_r> other) const -> opsy::utility::clear_set<hash_csr0_r> {return opsy::utility::clear_set<hash_csr0_r>(hash_csr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto csx() const -> csx_f {return csx_f(static_cast<uint32_t>(value_ >> csx_f::offset));}

	constexpr hash_csr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr0_r other) const -> hash_csr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000100000000000000010; // 2228226 0x220002

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,hash_cr_r> hash_cr;
	opsy::utility::memory<uint32_t,hash_din_r> hash_din;
	opsy::utility::memory<uint32_t,hash_str_r> hash_str;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hra0;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hra1;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hra2;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hra3;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hra4;
	opsy::utility::memory<uint32_t,hash_imr_r> hash_imr;
	opsy::utility::memory<uint32_t,hash_sr_r> hash_sr;
	opsy::utility::padding<208> _p0;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr0;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr1;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr2;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr3;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr4;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr5;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr6;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr7;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr8;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr9;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr10;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr11;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr12;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr13;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr14;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr15;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr16;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr17;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr18;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr19;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr20;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr21;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr22;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr23;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr24;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr25;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr26;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr27;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr28;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr29;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr30;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr31;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr32;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr33;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr34;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr35;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr36;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr37;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr38;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr39;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr40;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr41;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr42;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr43;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr44;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr45;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr46;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr47;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr48;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr49;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr50;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr51;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr52;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr53;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr54;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr55;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr56;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr57;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr58;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr59;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr60;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr61;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr62;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr63;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr64;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr65;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr66;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr67;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr68;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr69;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr70;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr71;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr72;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr73;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr74;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr75;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr76;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr77;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr78;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr79;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr80;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr81;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr82;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr83;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr84;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr85;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr86;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr87;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr88;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr89;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr90;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr91;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr92;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr93;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr94;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr95;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr96;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr97;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr98;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr99;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr100;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr101;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr102;
	opsy::utility::padding<124> _p1;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr0;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr1;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr2;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr3;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr4;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr5;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr6;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr7;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr8;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr9;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr10;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr11;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr12;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr13;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr14;
	opsy::utility::memory<uint32_t,hash_hra0_r> hash_hr15;
};

static_assert(std::is_standard_layout_v<hash_p>);
static_assert(offsetof(hash_p, hash_cr) == 0);
static_assert(offsetof(hash_p, hash_din) == 4);
static_assert(offsetof(hash_p, hash_str) == 8);
static_assert(offsetof(hash_p, hash_hra0) == 12);
static_assert(offsetof(hash_p, hash_hra1) == 16);
static_assert(offsetof(hash_p, hash_hra2) == 20);
static_assert(offsetof(hash_p, hash_hra3) == 24);
static_assert(offsetof(hash_p, hash_hra4) == 28);
static_assert(offsetof(hash_p, hash_imr) == 32);
static_assert(offsetof(hash_p, hash_sr) == 36);
static_assert(offsetof(hash_p, hash_csr0) == 248);
static_assert(offsetof(hash_p, hash_csr1) == 252);
static_assert(offsetof(hash_p, hash_csr2) == 256);
static_assert(offsetof(hash_p, hash_csr3) == 260);
static_assert(offsetof(hash_p, hash_csr4) == 264);
static_assert(offsetof(hash_p, hash_csr5) == 268);
static_assert(offsetof(hash_p, hash_csr6) == 272);
static_assert(offsetof(hash_p, hash_csr7) == 276);
static_assert(offsetof(hash_p, hash_csr8) == 280);
static_assert(offsetof(hash_p, hash_csr9) == 284);
static_assert(offsetof(hash_p, hash_csr10) == 288);
static_assert(offsetof(hash_p, hash_csr11) == 292);
static_assert(offsetof(hash_p, hash_csr12) == 296);
static_assert(offsetof(hash_p, hash_csr13) == 300);
static_assert(offsetof(hash_p, hash_csr14) == 304);
static_assert(offsetof(hash_p, hash_csr15) == 308);
static_assert(offsetof(hash_p, hash_csr16) == 312);
static_assert(offsetof(hash_p, hash_csr17) == 316);
static_assert(offsetof(hash_p, hash_csr18) == 320);
static_assert(offsetof(hash_p, hash_csr19) == 324);
static_assert(offsetof(hash_p, hash_csr20) == 328);
static_assert(offsetof(hash_p, hash_csr21) == 332);
static_assert(offsetof(hash_p, hash_csr22) == 336);
static_assert(offsetof(hash_p, hash_csr23) == 340);
static_assert(offsetof(hash_p, hash_csr24) == 344);
static_assert(offsetof(hash_p, hash_csr25) == 348);
static_assert(offsetof(hash_p, hash_csr26) == 352);
static_assert(offsetof(hash_p, hash_csr27) == 356);
static_assert(offsetof(hash_p, hash_csr28) == 360);
static_assert(offsetof(hash_p, hash_csr29) == 364);
static_assert(offsetof(hash_p, hash_csr30) == 368);
static_assert(offsetof(hash_p, hash_csr31) == 372);
static_assert(offsetof(hash_p, hash_csr32) == 376);
static_assert(offsetof(hash_p, hash_csr33) == 380);
static_assert(offsetof(hash_p, hash_csr34) == 384);
static_assert(offsetof(hash_p, hash_csr35) == 388);
static_assert(offsetof(hash_p, hash_csr36) == 392);
static_assert(offsetof(hash_p, hash_csr37) == 396);
static_assert(offsetof(hash_p, hash_csr38) == 400);
static_assert(offsetof(hash_p, hash_csr39) == 404);
static_assert(offsetof(hash_p, hash_csr40) == 408);
static_assert(offsetof(hash_p, hash_csr41) == 412);
static_assert(offsetof(hash_p, hash_csr42) == 416);
static_assert(offsetof(hash_p, hash_csr43) == 420);
static_assert(offsetof(hash_p, hash_csr44) == 424);
static_assert(offsetof(hash_p, hash_csr45) == 428);
static_assert(offsetof(hash_p, hash_csr46) == 432);
static_assert(offsetof(hash_p, hash_csr47) == 436);
static_assert(offsetof(hash_p, hash_csr48) == 440);
static_assert(offsetof(hash_p, hash_csr49) == 444);
static_assert(offsetof(hash_p, hash_csr50) == 448);
static_assert(offsetof(hash_p, hash_csr51) == 452);
static_assert(offsetof(hash_p, hash_csr52) == 456);
static_assert(offsetof(hash_p, hash_csr53) == 460);
static_assert(offsetof(hash_p, hash_csr54) == 464);
static_assert(offsetof(hash_p, hash_csr55) == 468);
static_assert(offsetof(hash_p, hash_csr56) == 472);
static_assert(offsetof(hash_p, hash_csr57) == 476);
static_assert(offsetof(hash_p, hash_csr58) == 480);
static_assert(offsetof(hash_p, hash_csr59) == 484);
static_assert(offsetof(hash_p, hash_csr60) == 488);
static_assert(offsetof(hash_p, hash_csr61) == 492);
static_assert(offsetof(hash_p, hash_csr62) == 496);
static_assert(offsetof(hash_p, hash_csr63) == 500);
static_assert(offsetof(hash_p, hash_csr64) == 504);
static_assert(offsetof(hash_p, hash_csr65) == 508);
static_assert(offsetof(hash_p, hash_csr66) == 512);
static_assert(offsetof(hash_p, hash_csr67) == 516);
static_assert(offsetof(hash_p, hash_csr68) == 520);
static_assert(offsetof(hash_p, hash_csr69) == 524);
static_assert(offsetof(hash_p, hash_csr70) == 528);
static_assert(offsetof(hash_p, hash_csr71) == 532);
static_assert(offsetof(hash_p, hash_csr72) == 536);
static_assert(offsetof(hash_p, hash_csr73) == 540);
static_assert(offsetof(hash_p, hash_csr74) == 544);
static_assert(offsetof(hash_p, hash_csr75) == 548);
static_assert(offsetof(hash_p, hash_csr76) == 552);
static_assert(offsetof(hash_p, hash_csr77) == 556);
static_assert(offsetof(hash_p, hash_csr78) == 560);
static_assert(offsetof(hash_p, hash_csr79) == 564);
static_assert(offsetof(hash_p, hash_csr80) == 568);
static_assert(offsetof(hash_p, hash_csr81) == 572);
static_assert(offsetof(hash_p, hash_csr82) == 576);
static_assert(offsetof(hash_p, hash_csr83) == 580);
static_assert(offsetof(hash_p, hash_csr84) == 584);
static_assert(offsetof(hash_p, hash_csr85) == 588);
static_assert(offsetof(hash_p, hash_csr86) == 592);
static_assert(offsetof(hash_p, hash_csr87) == 596);
static_assert(offsetof(hash_p, hash_csr88) == 600);
static_assert(offsetof(hash_p, hash_csr89) == 604);
static_assert(offsetof(hash_p, hash_csr90) == 608);
static_assert(offsetof(hash_p, hash_csr91) == 612);
static_assert(offsetof(hash_p, hash_csr92) == 616);
static_assert(offsetof(hash_p, hash_csr93) == 620);
static_assert(offsetof(hash_p, hash_csr94) == 624);
static_assert(offsetof(hash_p, hash_csr95) == 628);
static_assert(offsetof(hash_p, hash_csr96) == 632);
static_assert(offsetof(hash_p, hash_csr97) == 636);
static_assert(offsetof(hash_p, hash_csr98) == 640);
static_assert(offsetof(hash_p, hash_csr99) == 644);
static_assert(offsetof(hash_p, hash_csr100) == 648);
static_assert(offsetof(hash_p, hash_csr101) == 652);
static_assert(offsetof(hash_p, hash_csr102) == 656);
static_assert(offsetof(hash_p, hash_hr0) == 784);
static_assert(offsetof(hash_p, hash_hr1) == 788);
static_assert(offsetof(hash_p, hash_hr2) == 792);
static_assert(offsetof(hash_p, hash_hr3) == 796);
static_assert(offsetof(hash_p, hash_hr4) == 800);
static_assert(offsetof(hash_p, hash_hr5) == 804);
static_assert(offsetof(hash_p, hash_hr6) == 808);
static_assert(offsetof(hash_p, hash_hr7) == 812);
static_assert(offsetof(hash_p, hash_hr8) == 816);
static_assert(offsetof(hash_p, hash_hr9) == 820);
static_assert(offsetof(hash_p, hash_hr10) == 824);
static_assert(offsetof(hash_p, hash_hr11) == 828);
static_assert(offsetof(hash_p, hash_hr12) == 832);
static_assert(offsetof(hash_p, hash_hr13) == 836);
static_assert(offsetof(hash_p, hash_hr14) == 840);
static_assert(offsetof(hash_p, hash_hr15) == 844);

inline hash_p& hash = *reinterpret_cast<hash_p*>(0x420C0400);
inline hash_p& sec_hash = *reinterpret_cast<hash_p*>(0x520C0400);

} // STM32H563

