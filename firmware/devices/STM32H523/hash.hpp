#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
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
 * Initialize message digest calculation 
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
 * DMA enable 
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
 * Data type selection 
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
 * Mode selection 
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
 * Number of words already pushed 
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
 * DIN not empty 
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
 * Multiple DMA transfers 
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
 * Long key selection 
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
 * Algorithm selection 
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
 * Data input 
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
 * Number of valid bits in the last word 
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
 * Digest calculation 
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
 * Hash data x 
 */
class h0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra0_r>() const {return opsy::utility::clear_set<hash_hra0_r>(mask, *this);}
	constexpr auto operator|(hash_hra0_r other) const -> hash_hra0_r { return static_cast<hash_hra0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra0_r> other) const -> opsy::utility::clear_set<hash_hra0_r> {return opsy::utility::clear_set<hash_hra0_r>(hash_hra0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h0() const -> h0_f {return h0_f(static_cast<uint32_t>(value_ >> h0_f::offset));}

	constexpr hash_hra0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra0_r other) const -> hash_hra0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH aliased digest register 1
 */
class hash_hra1_r {
public:

/**
 * Hash data x 
 */
class h1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra1_r>() const {return opsy::utility::clear_set<hash_hra1_r>(mask, *this);}
	constexpr auto operator|(hash_hra1_r other) const -> hash_hra1_r { return static_cast<hash_hra1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra1_r> other) const -> opsy::utility::clear_set<hash_hra1_r> {return opsy::utility::clear_set<hash_hra1_r>(hash_hra1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h1() const -> h1_f {return h1_f(static_cast<uint32_t>(value_ >> h1_f::offset));}

	constexpr hash_hra1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra1_r other) const -> hash_hra1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH aliased digest register 2
 */
class hash_hra2_r {
public:

/**
 * Hash data x 
 */
class h2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra2_r>() const {return opsy::utility::clear_set<hash_hra2_r>(mask, *this);}
	constexpr auto operator|(hash_hra2_r other) const -> hash_hra2_r { return static_cast<hash_hra2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra2_r> other) const -> opsy::utility::clear_set<hash_hra2_r> {return opsy::utility::clear_set<hash_hra2_r>(hash_hra2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h2() const -> h2_f {return h2_f(static_cast<uint32_t>(value_ >> h2_f::offset));}

	constexpr hash_hra2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra2_r other) const -> hash_hra2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH aliased digest register 3
 */
class hash_hra3_r {
public:

/**
 * Hash data x 
 */
class h3_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h3_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra3_r>() const {return opsy::utility::clear_set<hash_hra3_r>(mask, *this);}
	constexpr auto operator|(hash_hra3_r other) const -> hash_hra3_r { return static_cast<hash_hra3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra3_r> other) const -> opsy::utility::clear_set<hash_hra3_r> {return opsy::utility::clear_set<hash_hra3_r>(hash_hra3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h3() const -> h3_f {return h3_f(static_cast<uint32_t>(value_ >> h3_f::offset));}

	constexpr hash_hra3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra3_r other) const -> hash_hra3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH aliased digest register 4
 */
class hash_hra4_r {
public:

/**
 * Hash data x 
 */
class h4_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h4_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hra4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hra4_r>() const {return opsy::utility::clear_set<hash_hra4_r>(mask, *this);}
	constexpr auto operator|(hash_hra4_r other) const -> hash_hra4_r { return static_cast<hash_hra4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hra4_r> other) const -> opsy::utility::clear_set<hash_hra4_r> {return opsy::utility::clear_set<hash_hra4_r>(hash_hra4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h4() const -> h4_f {return h4_f(static_cast<uint32_t>(value_ >> h4_f::offset));}

	constexpr hash_hra4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hra4_r other) const -> hash_hra4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hra4_r { return ~value_; }
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
 * Data input interrupt status 
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
 * Digest calculation completion interrupt status 
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
 * DMA Status 
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
 * Number of words already pushed 
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
 * DIN not empty 
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
 * Number of words expected 
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
 * Context swap x 
 */
class cs0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs0_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr0_r>() const {return opsy::utility::clear_set<hash_csr0_r>(mask, *this);}
	constexpr auto operator|(hash_csr0_r other) const -> hash_csr0_r { return static_cast<hash_csr0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr0_r> other) const -> opsy::utility::clear_set<hash_csr0_r> {return opsy::utility::clear_set<hash_csr0_r>(hash_csr0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs0() const -> cs0_f {return cs0_f(static_cast<uint32_t>(value_ >> cs0_f::offset));}

	constexpr hash_csr0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr0_r other) const -> hash_csr0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 1
 */
class hash_csr1_r {
public:

/**
 * Context swap x 
 */
class cs1_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs1_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr1_r>() const {return opsy::utility::clear_set<hash_csr1_r>(mask, *this);}
	constexpr auto operator|(hash_csr1_r other) const -> hash_csr1_r { return static_cast<hash_csr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr1_r> other) const -> opsy::utility::clear_set<hash_csr1_r> {return opsy::utility::clear_set<hash_csr1_r>(hash_csr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs1() const -> cs1_f {return cs1_f(static_cast<uint32_t>(value_ >> cs1_f::offset));}

	constexpr hash_csr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr1_r other) const -> hash_csr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 2
 */
class hash_csr2_r {
public:

/**
 * Context swap x 
 */
class cs2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs2_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr2_r>() const {return opsy::utility::clear_set<hash_csr2_r>(mask, *this);}
	constexpr auto operator|(hash_csr2_r other) const -> hash_csr2_r { return static_cast<hash_csr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr2_r> other) const -> opsy::utility::clear_set<hash_csr2_r> {return opsy::utility::clear_set<hash_csr2_r>(hash_csr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs2() const -> cs2_f {return cs2_f(static_cast<uint32_t>(value_ >> cs2_f::offset));}

	constexpr hash_csr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr2_r other) const -> hash_csr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 3
 */
class hash_csr3_r {
public:

/**
 * Context swap x 
 */
class cs3_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs3_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr3_r>() const {return opsy::utility::clear_set<hash_csr3_r>(mask, *this);}
	constexpr auto operator|(hash_csr3_r other) const -> hash_csr3_r { return static_cast<hash_csr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr3_r> other) const -> opsy::utility::clear_set<hash_csr3_r> {return opsy::utility::clear_set<hash_csr3_r>(hash_csr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs3() const -> cs3_f {return cs3_f(static_cast<uint32_t>(value_ >> cs3_f::offset));}

	constexpr hash_csr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr3_r other) const -> hash_csr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 4
 */
class hash_csr4_r {
public:

/**
 * Context swap x 
 */
class cs4_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs4_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr4_r>() const {return opsy::utility::clear_set<hash_csr4_r>(mask, *this);}
	constexpr auto operator|(hash_csr4_r other) const -> hash_csr4_r { return static_cast<hash_csr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr4_r> other) const -> opsy::utility::clear_set<hash_csr4_r> {return opsy::utility::clear_set<hash_csr4_r>(hash_csr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs4() const -> cs4_f {return cs4_f(static_cast<uint32_t>(value_ >> cs4_f::offset));}

	constexpr hash_csr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr4_r other) const -> hash_csr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 5
 */
class hash_csr5_r {
public:

/**
 * Context swap x 
 */
class cs5_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs5_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr5_r>() const {return opsy::utility::clear_set<hash_csr5_r>(mask, *this);}
	constexpr auto operator|(hash_csr5_r other) const -> hash_csr5_r { return static_cast<hash_csr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr5_r> other) const -> opsy::utility::clear_set<hash_csr5_r> {return opsy::utility::clear_set<hash_csr5_r>(hash_csr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs5() const -> cs5_f {return cs5_f(static_cast<uint32_t>(value_ >> cs5_f::offset));}

	constexpr hash_csr5_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr5_r other) const -> hash_csr5_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr5_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 6
 */
class hash_csr6_r {
public:

/**
 * Context swap x 
 */
class cs6_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs6_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr6_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr6_r>() const {return opsy::utility::clear_set<hash_csr6_r>(mask, *this);}
	constexpr auto operator|(hash_csr6_r other) const -> hash_csr6_r { return static_cast<hash_csr6_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr6_r> other) const -> opsy::utility::clear_set<hash_csr6_r> {return opsy::utility::clear_set<hash_csr6_r>(hash_csr6_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs6() const -> cs6_f {return cs6_f(static_cast<uint32_t>(value_ >> cs6_f::offset));}

	constexpr hash_csr6_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr6_r other) const -> hash_csr6_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr6_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 7
 */
class hash_csr7_r {
public:

/**
 * Context swap x 
 */
class cs7_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs7_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr7_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr7_r>() const {return opsy::utility::clear_set<hash_csr7_r>(mask, *this);}
	constexpr auto operator|(hash_csr7_r other) const -> hash_csr7_r { return static_cast<hash_csr7_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr7_r> other) const -> opsy::utility::clear_set<hash_csr7_r> {return opsy::utility::clear_set<hash_csr7_r>(hash_csr7_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs7() const -> cs7_f {return cs7_f(static_cast<uint32_t>(value_ >> cs7_f::offset));}

	constexpr hash_csr7_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr7_r other) const -> hash_csr7_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr7_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 8
 */
class hash_csr8_r {
public:

/**
 * Context swap x 
 */
class cs8_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs8_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr8_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr8_r>() const {return opsy::utility::clear_set<hash_csr8_r>(mask, *this);}
	constexpr auto operator|(hash_csr8_r other) const -> hash_csr8_r { return static_cast<hash_csr8_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr8_r> other) const -> opsy::utility::clear_set<hash_csr8_r> {return opsy::utility::clear_set<hash_csr8_r>(hash_csr8_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs8() const -> cs8_f {return cs8_f(static_cast<uint32_t>(value_ >> cs8_f::offset));}

	constexpr hash_csr8_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr8_r other) const -> hash_csr8_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr8_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 9
 */
class hash_csr9_r {
public:

/**
 * Context swap x 
 */
class cs9_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs9_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr9_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr9_r>() const {return opsy::utility::clear_set<hash_csr9_r>(mask, *this);}
	constexpr auto operator|(hash_csr9_r other) const -> hash_csr9_r { return static_cast<hash_csr9_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr9_r> other) const -> opsy::utility::clear_set<hash_csr9_r> {return opsy::utility::clear_set<hash_csr9_r>(hash_csr9_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs9() const -> cs9_f {return cs9_f(static_cast<uint32_t>(value_ >> cs9_f::offset));}

	constexpr hash_csr9_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr9_r other) const -> hash_csr9_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr9_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 10
 */
class hash_csr10_r {
public:

/**
 * Context swap x 
 */
class cs10_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs10_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr10_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr10_r>() const {return opsy::utility::clear_set<hash_csr10_r>(mask, *this);}
	constexpr auto operator|(hash_csr10_r other) const -> hash_csr10_r { return static_cast<hash_csr10_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr10_r> other) const -> opsy::utility::clear_set<hash_csr10_r> {return opsy::utility::clear_set<hash_csr10_r>(hash_csr10_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs10() const -> cs10_f {return cs10_f(static_cast<uint32_t>(value_ >> cs10_f::offset));}

	constexpr hash_csr10_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr10_r other) const -> hash_csr10_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr10_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 11
 */
class hash_csr11_r {
public:

/**
 * Context swap x 
 */
class cs11_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs11_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr11_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr11_r>() const {return opsy::utility::clear_set<hash_csr11_r>(mask, *this);}
	constexpr auto operator|(hash_csr11_r other) const -> hash_csr11_r { return static_cast<hash_csr11_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr11_r> other) const -> opsy::utility::clear_set<hash_csr11_r> {return opsy::utility::clear_set<hash_csr11_r>(hash_csr11_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs11() const -> cs11_f {return cs11_f(static_cast<uint32_t>(value_ >> cs11_f::offset));}

	constexpr hash_csr11_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr11_r other) const -> hash_csr11_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr11_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 12
 */
class hash_csr12_r {
public:

/**
 * Context swap x 
 */
class cs12_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs12_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr12_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr12_r>() const {return opsy::utility::clear_set<hash_csr12_r>(mask, *this);}
	constexpr auto operator|(hash_csr12_r other) const -> hash_csr12_r { return static_cast<hash_csr12_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr12_r> other) const -> opsy::utility::clear_set<hash_csr12_r> {return opsy::utility::clear_set<hash_csr12_r>(hash_csr12_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs12() const -> cs12_f {return cs12_f(static_cast<uint32_t>(value_ >> cs12_f::offset));}

	constexpr hash_csr12_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr12_r other) const -> hash_csr12_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr12_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 13
 */
class hash_csr13_r {
public:

/**
 * Context swap x 
 */
class cs13_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs13_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr13_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr13_r>() const {return opsy::utility::clear_set<hash_csr13_r>(mask, *this);}
	constexpr auto operator|(hash_csr13_r other) const -> hash_csr13_r { return static_cast<hash_csr13_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr13_r> other) const -> opsy::utility::clear_set<hash_csr13_r> {return opsy::utility::clear_set<hash_csr13_r>(hash_csr13_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs13() const -> cs13_f {return cs13_f(static_cast<uint32_t>(value_ >> cs13_f::offset));}

	constexpr hash_csr13_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr13_r other) const -> hash_csr13_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr13_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 14
 */
class hash_csr14_r {
public:

/**
 * Context swap x 
 */
class cs14_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs14_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr14_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr14_r>() const {return opsy::utility::clear_set<hash_csr14_r>(mask, *this);}
	constexpr auto operator|(hash_csr14_r other) const -> hash_csr14_r { return static_cast<hash_csr14_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr14_r> other) const -> opsy::utility::clear_set<hash_csr14_r> {return opsy::utility::clear_set<hash_csr14_r>(hash_csr14_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs14() const -> cs14_f {return cs14_f(static_cast<uint32_t>(value_ >> cs14_f::offset));}

	constexpr hash_csr14_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr14_r other) const -> hash_csr14_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr14_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 15
 */
class hash_csr15_r {
public:

/**
 * Context swap x 
 */
class cs15_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs15_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr15_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr15_r>() const {return opsy::utility::clear_set<hash_csr15_r>(mask, *this);}
	constexpr auto operator|(hash_csr15_r other) const -> hash_csr15_r { return static_cast<hash_csr15_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr15_r> other) const -> opsy::utility::clear_set<hash_csr15_r> {return opsy::utility::clear_set<hash_csr15_r>(hash_csr15_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs15() const -> cs15_f {return cs15_f(static_cast<uint32_t>(value_ >> cs15_f::offset));}

	constexpr hash_csr15_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr15_r other) const -> hash_csr15_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr15_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 16
 */
class hash_csr16_r {
public:

/**
 * Context swap x 
 */
class cs16_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs16_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr16_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr16_r>() const {return opsy::utility::clear_set<hash_csr16_r>(mask, *this);}
	constexpr auto operator|(hash_csr16_r other) const -> hash_csr16_r { return static_cast<hash_csr16_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr16_r> other) const -> opsy::utility::clear_set<hash_csr16_r> {return opsy::utility::clear_set<hash_csr16_r>(hash_csr16_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs16() const -> cs16_f {return cs16_f(static_cast<uint32_t>(value_ >> cs16_f::offset));}

	constexpr hash_csr16_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr16_r other) const -> hash_csr16_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr16_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 17
 */
class hash_csr17_r {
public:

/**
 * Context swap x 
 */
class cs17_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs17_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr17_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr17_r>() const {return opsy::utility::clear_set<hash_csr17_r>(mask, *this);}
	constexpr auto operator|(hash_csr17_r other) const -> hash_csr17_r { return static_cast<hash_csr17_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr17_r> other) const -> opsy::utility::clear_set<hash_csr17_r> {return opsy::utility::clear_set<hash_csr17_r>(hash_csr17_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs17() const -> cs17_f {return cs17_f(static_cast<uint32_t>(value_ >> cs17_f::offset));}

	constexpr hash_csr17_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr17_r other) const -> hash_csr17_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr17_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 18
 */
class hash_csr18_r {
public:

/**
 * Context swap x 
 */
class cs18_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs18_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr18_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr18_r>() const {return opsy::utility::clear_set<hash_csr18_r>(mask, *this);}
	constexpr auto operator|(hash_csr18_r other) const -> hash_csr18_r { return static_cast<hash_csr18_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr18_r> other) const -> opsy::utility::clear_set<hash_csr18_r> {return opsy::utility::clear_set<hash_csr18_r>(hash_csr18_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs18() const -> cs18_f {return cs18_f(static_cast<uint32_t>(value_ >> cs18_f::offset));}

	constexpr hash_csr18_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr18_r other) const -> hash_csr18_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr18_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 19
 */
class hash_csr19_r {
public:

/**
 * Context swap x 
 */
class cs19_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs19_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr19_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr19_r>() const {return opsy::utility::clear_set<hash_csr19_r>(mask, *this);}
	constexpr auto operator|(hash_csr19_r other) const -> hash_csr19_r { return static_cast<hash_csr19_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr19_r> other) const -> opsy::utility::clear_set<hash_csr19_r> {return opsy::utility::clear_set<hash_csr19_r>(hash_csr19_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs19() const -> cs19_f {return cs19_f(static_cast<uint32_t>(value_ >> cs19_f::offset));}

	constexpr hash_csr19_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr19_r other) const -> hash_csr19_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr19_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 20
 */
class hash_csr20_r {
public:

/**
 * Context swap x 
 */
class cs20_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs20_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr20_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr20_r>() const {return opsy::utility::clear_set<hash_csr20_r>(mask, *this);}
	constexpr auto operator|(hash_csr20_r other) const -> hash_csr20_r { return static_cast<hash_csr20_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr20_r> other) const -> opsy::utility::clear_set<hash_csr20_r> {return opsy::utility::clear_set<hash_csr20_r>(hash_csr20_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs20() const -> cs20_f {return cs20_f(static_cast<uint32_t>(value_ >> cs20_f::offset));}

	constexpr hash_csr20_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr20_r other) const -> hash_csr20_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr20_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 21
 */
class hash_csr21_r {
public:

/**
 * Context swap x 
 */
class cs21_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs21_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr21_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr21_r>() const {return opsy::utility::clear_set<hash_csr21_r>(mask, *this);}
	constexpr auto operator|(hash_csr21_r other) const -> hash_csr21_r { return static_cast<hash_csr21_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr21_r> other) const -> opsy::utility::clear_set<hash_csr21_r> {return opsy::utility::clear_set<hash_csr21_r>(hash_csr21_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs21() const -> cs21_f {return cs21_f(static_cast<uint32_t>(value_ >> cs21_f::offset));}

	constexpr hash_csr21_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr21_r other) const -> hash_csr21_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr21_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 22
 */
class hash_csr22_r {
public:

/**
 * Context swap x 
 */
class cs22_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs22_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr22_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr22_r>() const {return opsy::utility::clear_set<hash_csr22_r>(mask, *this);}
	constexpr auto operator|(hash_csr22_r other) const -> hash_csr22_r { return static_cast<hash_csr22_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr22_r> other) const -> opsy::utility::clear_set<hash_csr22_r> {return opsy::utility::clear_set<hash_csr22_r>(hash_csr22_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs22() const -> cs22_f {return cs22_f(static_cast<uint32_t>(value_ >> cs22_f::offset));}

	constexpr hash_csr22_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr22_r other) const -> hash_csr22_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr22_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 23
 */
class hash_csr23_r {
public:

/**
 * Context swap x 
 */
class cs23_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs23_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr23_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr23_r>() const {return opsy::utility::clear_set<hash_csr23_r>(mask, *this);}
	constexpr auto operator|(hash_csr23_r other) const -> hash_csr23_r { return static_cast<hash_csr23_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr23_r> other) const -> opsy::utility::clear_set<hash_csr23_r> {return opsy::utility::clear_set<hash_csr23_r>(hash_csr23_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs23() const -> cs23_f {return cs23_f(static_cast<uint32_t>(value_ >> cs23_f::offset));}

	constexpr hash_csr23_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr23_r other) const -> hash_csr23_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr23_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 24
 */
class hash_csr24_r {
public:

/**
 * Context swap x 
 */
class cs24_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs24_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr24_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr24_r>() const {return opsy::utility::clear_set<hash_csr24_r>(mask, *this);}
	constexpr auto operator|(hash_csr24_r other) const -> hash_csr24_r { return static_cast<hash_csr24_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr24_r> other) const -> opsy::utility::clear_set<hash_csr24_r> {return opsy::utility::clear_set<hash_csr24_r>(hash_csr24_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs24() const -> cs24_f {return cs24_f(static_cast<uint32_t>(value_ >> cs24_f::offset));}

	constexpr hash_csr24_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr24_r other) const -> hash_csr24_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr24_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 25
 */
class hash_csr25_r {
public:

/**
 * Context swap x 
 */
class cs25_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs25_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr25_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr25_r>() const {return opsy::utility::clear_set<hash_csr25_r>(mask, *this);}
	constexpr auto operator|(hash_csr25_r other) const -> hash_csr25_r { return static_cast<hash_csr25_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr25_r> other) const -> opsy::utility::clear_set<hash_csr25_r> {return opsy::utility::clear_set<hash_csr25_r>(hash_csr25_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs25() const -> cs25_f {return cs25_f(static_cast<uint32_t>(value_ >> cs25_f::offset));}

	constexpr hash_csr25_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr25_r other) const -> hash_csr25_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr25_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 26
 */
class hash_csr26_r {
public:

/**
 * Context swap x 
 */
class cs26_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs26_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr26_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr26_r>() const {return opsy::utility::clear_set<hash_csr26_r>(mask, *this);}
	constexpr auto operator|(hash_csr26_r other) const -> hash_csr26_r { return static_cast<hash_csr26_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr26_r> other) const -> opsy::utility::clear_set<hash_csr26_r> {return opsy::utility::clear_set<hash_csr26_r>(hash_csr26_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs26() const -> cs26_f {return cs26_f(static_cast<uint32_t>(value_ >> cs26_f::offset));}

	constexpr hash_csr26_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr26_r other) const -> hash_csr26_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr26_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 27
 */
class hash_csr27_r {
public:

/**
 * Context swap x 
 */
class cs27_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs27_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr27_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr27_r>() const {return opsy::utility::clear_set<hash_csr27_r>(mask, *this);}
	constexpr auto operator|(hash_csr27_r other) const -> hash_csr27_r { return static_cast<hash_csr27_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr27_r> other) const -> opsy::utility::clear_set<hash_csr27_r> {return opsy::utility::clear_set<hash_csr27_r>(hash_csr27_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs27() const -> cs27_f {return cs27_f(static_cast<uint32_t>(value_ >> cs27_f::offset));}

	constexpr hash_csr27_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr27_r other) const -> hash_csr27_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr27_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 28
 */
class hash_csr28_r {
public:

/**
 * Context swap x 
 */
class cs28_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs28_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr28_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr28_r>() const {return opsy::utility::clear_set<hash_csr28_r>(mask, *this);}
	constexpr auto operator|(hash_csr28_r other) const -> hash_csr28_r { return static_cast<hash_csr28_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr28_r> other) const -> opsy::utility::clear_set<hash_csr28_r> {return opsy::utility::clear_set<hash_csr28_r>(hash_csr28_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs28() const -> cs28_f {return cs28_f(static_cast<uint32_t>(value_ >> cs28_f::offset));}

	constexpr hash_csr28_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr28_r other) const -> hash_csr28_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr28_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 29
 */
class hash_csr29_r {
public:

/**
 * Context swap x 
 */
class cs29_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs29_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr29_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr29_r>() const {return opsy::utility::clear_set<hash_csr29_r>(mask, *this);}
	constexpr auto operator|(hash_csr29_r other) const -> hash_csr29_r { return static_cast<hash_csr29_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr29_r> other) const -> opsy::utility::clear_set<hash_csr29_r> {return opsy::utility::clear_set<hash_csr29_r>(hash_csr29_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs29() const -> cs29_f {return cs29_f(static_cast<uint32_t>(value_ >> cs29_f::offset));}

	constexpr hash_csr29_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr29_r other) const -> hash_csr29_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr29_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 30
 */
class hash_csr30_r {
public:

/**
 * Context swap x 
 */
class cs30_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs30_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr30_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr30_r>() const {return opsy::utility::clear_set<hash_csr30_r>(mask, *this);}
	constexpr auto operator|(hash_csr30_r other) const -> hash_csr30_r { return static_cast<hash_csr30_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr30_r> other) const -> opsy::utility::clear_set<hash_csr30_r> {return opsy::utility::clear_set<hash_csr30_r>(hash_csr30_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs30() const -> cs30_f {return cs30_f(static_cast<uint32_t>(value_ >> cs30_f::offset));}

	constexpr hash_csr30_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr30_r other) const -> hash_csr30_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr30_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 31
 */
class hash_csr31_r {
public:

/**
 * Context swap x 
 */
class cs31_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs31_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr31_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr31_r>() const {return opsy::utility::clear_set<hash_csr31_r>(mask, *this);}
	constexpr auto operator|(hash_csr31_r other) const -> hash_csr31_r { return static_cast<hash_csr31_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr31_r> other) const -> opsy::utility::clear_set<hash_csr31_r> {return opsy::utility::clear_set<hash_csr31_r>(hash_csr31_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs31() const -> cs31_f {return cs31_f(static_cast<uint32_t>(value_ >> cs31_f::offset));}

	constexpr hash_csr31_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr31_r other) const -> hash_csr31_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr31_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 32
 */
class hash_csr32_r {
public:

/**
 * Context swap x 
 */
class cs32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs32_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr32_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr32_r>() const {return opsy::utility::clear_set<hash_csr32_r>(mask, *this);}
	constexpr auto operator|(hash_csr32_r other) const -> hash_csr32_r { return static_cast<hash_csr32_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr32_r> other) const -> opsy::utility::clear_set<hash_csr32_r> {return opsy::utility::clear_set<hash_csr32_r>(hash_csr32_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs32() const -> cs32_f {return cs32_f(static_cast<uint32_t>(value_ >> cs32_f::offset));}

	constexpr hash_csr32_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr32_r other) const -> hash_csr32_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr32_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 33
 */
class hash_csr33_r {
public:

/**
 * Context swap x 
 */
class cs33_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs33_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr33_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr33_r>() const {return opsy::utility::clear_set<hash_csr33_r>(mask, *this);}
	constexpr auto operator|(hash_csr33_r other) const -> hash_csr33_r { return static_cast<hash_csr33_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr33_r> other) const -> opsy::utility::clear_set<hash_csr33_r> {return opsy::utility::clear_set<hash_csr33_r>(hash_csr33_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs33() const -> cs33_f {return cs33_f(static_cast<uint32_t>(value_ >> cs33_f::offset));}

	constexpr hash_csr33_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr33_r other) const -> hash_csr33_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr33_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 34
 */
class hash_csr34_r {
public:

/**
 * Context swap x 
 */
class cs34_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs34_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr34_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr34_r>() const {return opsy::utility::clear_set<hash_csr34_r>(mask, *this);}
	constexpr auto operator|(hash_csr34_r other) const -> hash_csr34_r { return static_cast<hash_csr34_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr34_r> other) const -> opsy::utility::clear_set<hash_csr34_r> {return opsy::utility::clear_set<hash_csr34_r>(hash_csr34_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs34() const -> cs34_f {return cs34_f(static_cast<uint32_t>(value_ >> cs34_f::offset));}

	constexpr hash_csr34_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr34_r other) const -> hash_csr34_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr34_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 35
 */
class hash_csr35_r {
public:

/**
 * Context swap x 
 */
class cs35_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs35_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr35_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr35_r>() const {return opsy::utility::clear_set<hash_csr35_r>(mask, *this);}
	constexpr auto operator|(hash_csr35_r other) const -> hash_csr35_r { return static_cast<hash_csr35_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr35_r> other) const -> opsy::utility::clear_set<hash_csr35_r> {return opsy::utility::clear_set<hash_csr35_r>(hash_csr35_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs35() const -> cs35_f {return cs35_f(static_cast<uint32_t>(value_ >> cs35_f::offset));}

	constexpr hash_csr35_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr35_r other) const -> hash_csr35_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr35_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 36
 */
class hash_csr36_r {
public:

/**
 * Context swap x 
 */
class cs36_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs36_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr36_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr36_r>() const {return opsy::utility::clear_set<hash_csr36_r>(mask, *this);}
	constexpr auto operator|(hash_csr36_r other) const -> hash_csr36_r { return static_cast<hash_csr36_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr36_r> other) const -> opsy::utility::clear_set<hash_csr36_r> {return opsy::utility::clear_set<hash_csr36_r>(hash_csr36_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs36() const -> cs36_f {return cs36_f(static_cast<uint32_t>(value_ >> cs36_f::offset));}

	constexpr hash_csr36_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr36_r other) const -> hash_csr36_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr36_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 37
 */
class hash_csr37_r {
public:

/**
 * Context swap x 
 */
class cs37_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs37_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr37_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr37_r>() const {return opsy::utility::clear_set<hash_csr37_r>(mask, *this);}
	constexpr auto operator|(hash_csr37_r other) const -> hash_csr37_r { return static_cast<hash_csr37_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr37_r> other) const -> opsy::utility::clear_set<hash_csr37_r> {return opsy::utility::clear_set<hash_csr37_r>(hash_csr37_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs37() const -> cs37_f {return cs37_f(static_cast<uint32_t>(value_ >> cs37_f::offset));}

	constexpr hash_csr37_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr37_r other) const -> hash_csr37_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr37_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 38
 */
class hash_csr38_r {
public:

/**
 * Context swap x 
 */
class cs38_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs38_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr38_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr38_r>() const {return opsy::utility::clear_set<hash_csr38_r>(mask, *this);}
	constexpr auto operator|(hash_csr38_r other) const -> hash_csr38_r { return static_cast<hash_csr38_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr38_r> other) const -> opsy::utility::clear_set<hash_csr38_r> {return opsy::utility::clear_set<hash_csr38_r>(hash_csr38_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs38() const -> cs38_f {return cs38_f(static_cast<uint32_t>(value_ >> cs38_f::offset));}

	constexpr hash_csr38_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr38_r other) const -> hash_csr38_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr38_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 39
 */
class hash_csr39_r {
public:

/**
 * Context swap x 
 */
class cs39_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs39_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr39_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr39_r>() const {return opsy::utility::clear_set<hash_csr39_r>(mask, *this);}
	constexpr auto operator|(hash_csr39_r other) const -> hash_csr39_r { return static_cast<hash_csr39_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr39_r> other) const -> opsy::utility::clear_set<hash_csr39_r> {return opsy::utility::clear_set<hash_csr39_r>(hash_csr39_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs39() const -> cs39_f {return cs39_f(static_cast<uint32_t>(value_ >> cs39_f::offset));}

	constexpr hash_csr39_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr39_r other) const -> hash_csr39_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr39_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 40
 */
class hash_csr40_r {
public:

/**
 * Context swap x 
 */
class cs40_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs40_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr40_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr40_r>() const {return opsy::utility::clear_set<hash_csr40_r>(mask, *this);}
	constexpr auto operator|(hash_csr40_r other) const -> hash_csr40_r { return static_cast<hash_csr40_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr40_r> other) const -> opsy::utility::clear_set<hash_csr40_r> {return opsy::utility::clear_set<hash_csr40_r>(hash_csr40_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs40() const -> cs40_f {return cs40_f(static_cast<uint32_t>(value_ >> cs40_f::offset));}

	constexpr hash_csr40_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr40_r other) const -> hash_csr40_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr40_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 41
 */
class hash_csr41_r {
public:

/**
 * Context swap x 
 */
class cs41_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs41_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr41_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr41_r>() const {return opsy::utility::clear_set<hash_csr41_r>(mask, *this);}
	constexpr auto operator|(hash_csr41_r other) const -> hash_csr41_r { return static_cast<hash_csr41_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr41_r> other) const -> opsy::utility::clear_set<hash_csr41_r> {return opsy::utility::clear_set<hash_csr41_r>(hash_csr41_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs41() const -> cs41_f {return cs41_f(static_cast<uint32_t>(value_ >> cs41_f::offset));}

	constexpr hash_csr41_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr41_r other) const -> hash_csr41_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr41_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 42
 */
class hash_csr42_r {
public:

/**
 * Context swap x 
 */
class cs42_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs42_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr42_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr42_r>() const {return opsy::utility::clear_set<hash_csr42_r>(mask, *this);}
	constexpr auto operator|(hash_csr42_r other) const -> hash_csr42_r { return static_cast<hash_csr42_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr42_r> other) const -> opsy::utility::clear_set<hash_csr42_r> {return opsy::utility::clear_set<hash_csr42_r>(hash_csr42_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs42() const -> cs42_f {return cs42_f(static_cast<uint32_t>(value_ >> cs42_f::offset));}

	constexpr hash_csr42_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr42_r other) const -> hash_csr42_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr42_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 43
 */
class hash_csr43_r {
public:

/**
 * Context swap x 
 */
class cs43_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs43_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr43_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr43_r>() const {return opsy::utility::clear_set<hash_csr43_r>(mask, *this);}
	constexpr auto operator|(hash_csr43_r other) const -> hash_csr43_r { return static_cast<hash_csr43_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr43_r> other) const -> opsy::utility::clear_set<hash_csr43_r> {return opsy::utility::clear_set<hash_csr43_r>(hash_csr43_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs43() const -> cs43_f {return cs43_f(static_cast<uint32_t>(value_ >> cs43_f::offset));}

	constexpr hash_csr43_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr43_r other) const -> hash_csr43_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr43_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 44
 */
class hash_csr44_r {
public:

/**
 * Context swap x 
 */
class cs44_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs44_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr44_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr44_r>() const {return opsy::utility::clear_set<hash_csr44_r>(mask, *this);}
	constexpr auto operator|(hash_csr44_r other) const -> hash_csr44_r { return static_cast<hash_csr44_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr44_r> other) const -> opsy::utility::clear_set<hash_csr44_r> {return opsy::utility::clear_set<hash_csr44_r>(hash_csr44_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs44() const -> cs44_f {return cs44_f(static_cast<uint32_t>(value_ >> cs44_f::offset));}

	constexpr hash_csr44_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr44_r other) const -> hash_csr44_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr44_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 45
 */
class hash_csr45_r {
public:

/**
 * Context swap x 
 */
class cs45_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs45_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr45_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr45_r>() const {return opsy::utility::clear_set<hash_csr45_r>(mask, *this);}
	constexpr auto operator|(hash_csr45_r other) const -> hash_csr45_r { return static_cast<hash_csr45_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr45_r> other) const -> opsy::utility::clear_set<hash_csr45_r> {return opsy::utility::clear_set<hash_csr45_r>(hash_csr45_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs45() const -> cs45_f {return cs45_f(static_cast<uint32_t>(value_ >> cs45_f::offset));}

	constexpr hash_csr45_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr45_r other) const -> hash_csr45_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr45_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 46
 */
class hash_csr46_r {
public:

/**
 * Context swap x 
 */
class cs46_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs46_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr46_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr46_r>() const {return opsy::utility::clear_set<hash_csr46_r>(mask, *this);}
	constexpr auto operator|(hash_csr46_r other) const -> hash_csr46_r { return static_cast<hash_csr46_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr46_r> other) const -> opsy::utility::clear_set<hash_csr46_r> {return opsy::utility::clear_set<hash_csr46_r>(hash_csr46_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs46() const -> cs46_f {return cs46_f(static_cast<uint32_t>(value_ >> cs46_f::offset));}

	constexpr hash_csr46_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr46_r other) const -> hash_csr46_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr46_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 47
 */
class hash_csr47_r {
public:

/**
 * Context swap x 
 */
class cs47_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs47_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr47_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr47_r>() const {return opsy::utility::clear_set<hash_csr47_r>(mask, *this);}
	constexpr auto operator|(hash_csr47_r other) const -> hash_csr47_r { return static_cast<hash_csr47_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr47_r> other) const -> opsy::utility::clear_set<hash_csr47_r> {return opsy::utility::clear_set<hash_csr47_r>(hash_csr47_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs47() const -> cs47_f {return cs47_f(static_cast<uint32_t>(value_ >> cs47_f::offset));}

	constexpr hash_csr47_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr47_r other) const -> hash_csr47_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr47_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 48
 */
class hash_csr48_r {
public:

/**
 * Context swap x 
 */
class cs48_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs48_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr48_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr48_r>() const {return opsy::utility::clear_set<hash_csr48_r>(mask, *this);}
	constexpr auto operator|(hash_csr48_r other) const -> hash_csr48_r { return static_cast<hash_csr48_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr48_r> other) const -> opsy::utility::clear_set<hash_csr48_r> {return opsy::utility::clear_set<hash_csr48_r>(hash_csr48_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs48() const -> cs48_f {return cs48_f(static_cast<uint32_t>(value_ >> cs48_f::offset));}

	constexpr hash_csr48_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr48_r other) const -> hash_csr48_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr48_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 49
 */
class hash_csr49_r {
public:

/**
 * Context swap x 
 */
class cs49_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs49_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr49_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr49_r>() const {return opsy::utility::clear_set<hash_csr49_r>(mask, *this);}
	constexpr auto operator|(hash_csr49_r other) const -> hash_csr49_r { return static_cast<hash_csr49_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr49_r> other) const -> opsy::utility::clear_set<hash_csr49_r> {return opsy::utility::clear_set<hash_csr49_r>(hash_csr49_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs49() const -> cs49_f {return cs49_f(static_cast<uint32_t>(value_ >> cs49_f::offset));}

	constexpr hash_csr49_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr49_r other) const -> hash_csr49_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr49_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 50
 */
class hash_csr50_r {
public:

/**
 * Context swap x 
 */
class cs50_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs50_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr50_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr50_r>() const {return opsy::utility::clear_set<hash_csr50_r>(mask, *this);}
	constexpr auto operator|(hash_csr50_r other) const -> hash_csr50_r { return static_cast<hash_csr50_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr50_r> other) const -> opsy::utility::clear_set<hash_csr50_r> {return opsy::utility::clear_set<hash_csr50_r>(hash_csr50_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs50() const -> cs50_f {return cs50_f(static_cast<uint32_t>(value_ >> cs50_f::offset));}

	constexpr hash_csr50_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr50_r other) const -> hash_csr50_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr50_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 51
 */
class hash_csr51_r {
public:

/**
 * Context swap x 
 */
class cs51_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs51_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr51_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr51_r>() const {return opsy::utility::clear_set<hash_csr51_r>(mask, *this);}
	constexpr auto operator|(hash_csr51_r other) const -> hash_csr51_r { return static_cast<hash_csr51_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr51_r> other) const -> opsy::utility::clear_set<hash_csr51_r> {return opsy::utility::clear_set<hash_csr51_r>(hash_csr51_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs51() const -> cs51_f {return cs51_f(static_cast<uint32_t>(value_ >> cs51_f::offset));}

	constexpr hash_csr51_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr51_r other) const -> hash_csr51_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr51_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 52
 */
class hash_csr52_r {
public:

/**
 * Context swap x 
 */
class cs52_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs52_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr52_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr52_r>() const {return opsy::utility::clear_set<hash_csr52_r>(mask, *this);}
	constexpr auto operator|(hash_csr52_r other) const -> hash_csr52_r { return static_cast<hash_csr52_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr52_r> other) const -> opsy::utility::clear_set<hash_csr52_r> {return opsy::utility::clear_set<hash_csr52_r>(hash_csr52_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs52() const -> cs52_f {return cs52_f(static_cast<uint32_t>(value_ >> cs52_f::offset));}

	constexpr hash_csr52_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr52_r other) const -> hash_csr52_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr52_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 53
 */
class hash_csr53_r {
public:

/**
 * Context swap x 
 */
class cs53_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs53_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr53_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr53_r>() const {return opsy::utility::clear_set<hash_csr53_r>(mask, *this);}
	constexpr auto operator|(hash_csr53_r other) const -> hash_csr53_r { return static_cast<hash_csr53_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr53_r> other) const -> opsy::utility::clear_set<hash_csr53_r> {return opsy::utility::clear_set<hash_csr53_r>(hash_csr53_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs53() const -> cs53_f {return cs53_f(static_cast<uint32_t>(value_ >> cs53_f::offset));}

	constexpr hash_csr53_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr53_r other) const -> hash_csr53_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr53_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 54
 */
class hash_csr54_r {
public:

/**
 * Context swap x 
 */
class cs54_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs54_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr54_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr54_r>() const {return opsy::utility::clear_set<hash_csr54_r>(mask, *this);}
	constexpr auto operator|(hash_csr54_r other) const -> hash_csr54_r { return static_cast<hash_csr54_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr54_r> other) const -> opsy::utility::clear_set<hash_csr54_r> {return opsy::utility::clear_set<hash_csr54_r>(hash_csr54_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs54() const -> cs54_f {return cs54_f(static_cast<uint32_t>(value_ >> cs54_f::offset));}

	constexpr hash_csr54_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr54_r other) const -> hash_csr54_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr54_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 55
 */
class hash_csr55_r {
public:

/**
 * Context swap x 
 */
class cs55_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs55_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr55_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr55_r>() const {return opsy::utility::clear_set<hash_csr55_r>(mask, *this);}
	constexpr auto operator|(hash_csr55_r other) const -> hash_csr55_r { return static_cast<hash_csr55_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr55_r> other) const -> opsy::utility::clear_set<hash_csr55_r> {return opsy::utility::clear_set<hash_csr55_r>(hash_csr55_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs55() const -> cs55_f {return cs55_f(static_cast<uint32_t>(value_ >> cs55_f::offset));}

	constexpr hash_csr55_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr55_r other) const -> hash_csr55_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr55_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 56
 */
class hash_csr56_r {
public:

/**
 * Context swap x 
 */
class cs56_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs56_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr56_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr56_r>() const {return opsy::utility::clear_set<hash_csr56_r>(mask, *this);}
	constexpr auto operator|(hash_csr56_r other) const -> hash_csr56_r { return static_cast<hash_csr56_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr56_r> other) const -> opsy::utility::clear_set<hash_csr56_r> {return opsy::utility::clear_set<hash_csr56_r>(hash_csr56_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs56() const -> cs56_f {return cs56_f(static_cast<uint32_t>(value_ >> cs56_f::offset));}

	constexpr hash_csr56_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr56_r other) const -> hash_csr56_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr56_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 57
 */
class hash_csr57_r {
public:

/**
 * Context swap x 
 */
class cs57_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs57_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr57_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr57_r>() const {return opsy::utility::clear_set<hash_csr57_r>(mask, *this);}
	constexpr auto operator|(hash_csr57_r other) const -> hash_csr57_r { return static_cast<hash_csr57_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr57_r> other) const -> opsy::utility::clear_set<hash_csr57_r> {return opsy::utility::clear_set<hash_csr57_r>(hash_csr57_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs57() const -> cs57_f {return cs57_f(static_cast<uint32_t>(value_ >> cs57_f::offset));}

	constexpr hash_csr57_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr57_r other) const -> hash_csr57_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr57_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 58
 */
class hash_csr58_r {
public:

/**
 * Context swap x 
 */
class cs58_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs58_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr58_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr58_r>() const {return opsy::utility::clear_set<hash_csr58_r>(mask, *this);}
	constexpr auto operator|(hash_csr58_r other) const -> hash_csr58_r { return static_cast<hash_csr58_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr58_r> other) const -> opsy::utility::clear_set<hash_csr58_r> {return opsy::utility::clear_set<hash_csr58_r>(hash_csr58_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs58() const -> cs58_f {return cs58_f(static_cast<uint32_t>(value_ >> cs58_f::offset));}

	constexpr hash_csr58_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr58_r other) const -> hash_csr58_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr58_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 59
 */
class hash_csr59_r {
public:

/**
 * Context swap x 
 */
class cs59_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs59_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr59_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr59_r>() const {return opsy::utility::clear_set<hash_csr59_r>(mask, *this);}
	constexpr auto operator|(hash_csr59_r other) const -> hash_csr59_r { return static_cast<hash_csr59_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr59_r> other) const -> opsy::utility::clear_set<hash_csr59_r> {return opsy::utility::clear_set<hash_csr59_r>(hash_csr59_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs59() const -> cs59_f {return cs59_f(static_cast<uint32_t>(value_ >> cs59_f::offset));}

	constexpr hash_csr59_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr59_r other) const -> hash_csr59_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr59_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 60
 */
class hash_csr60_r {
public:

/**
 * Context swap x 
 */
class cs60_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs60_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr60_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr60_r>() const {return opsy::utility::clear_set<hash_csr60_r>(mask, *this);}
	constexpr auto operator|(hash_csr60_r other) const -> hash_csr60_r { return static_cast<hash_csr60_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr60_r> other) const -> opsy::utility::clear_set<hash_csr60_r> {return opsy::utility::clear_set<hash_csr60_r>(hash_csr60_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs60() const -> cs60_f {return cs60_f(static_cast<uint32_t>(value_ >> cs60_f::offset));}

	constexpr hash_csr60_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr60_r other) const -> hash_csr60_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr60_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 61
 */
class hash_csr61_r {
public:

/**
 * Context swap x 
 */
class cs61_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs61_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr61_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr61_r>() const {return opsy::utility::clear_set<hash_csr61_r>(mask, *this);}
	constexpr auto operator|(hash_csr61_r other) const -> hash_csr61_r { return static_cast<hash_csr61_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr61_r> other) const -> opsy::utility::clear_set<hash_csr61_r> {return opsy::utility::clear_set<hash_csr61_r>(hash_csr61_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs61() const -> cs61_f {return cs61_f(static_cast<uint32_t>(value_ >> cs61_f::offset));}

	constexpr hash_csr61_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr61_r other) const -> hash_csr61_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr61_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 62
 */
class hash_csr62_r {
public:

/**
 * Context swap x 
 */
class cs62_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs62_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr62_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr62_r>() const {return opsy::utility::clear_set<hash_csr62_r>(mask, *this);}
	constexpr auto operator|(hash_csr62_r other) const -> hash_csr62_r { return static_cast<hash_csr62_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr62_r> other) const -> opsy::utility::clear_set<hash_csr62_r> {return opsy::utility::clear_set<hash_csr62_r>(hash_csr62_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs62() const -> cs62_f {return cs62_f(static_cast<uint32_t>(value_ >> cs62_f::offset));}

	constexpr hash_csr62_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr62_r other) const -> hash_csr62_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr62_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 63
 */
class hash_csr63_r {
public:

/**
 * Context swap x 
 */
class cs63_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs63_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr63_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr63_r>() const {return opsy::utility::clear_set<hash_csr63_r>(mask, *this);}
	constexpr auto operator|(hash_csr63_r other) const -> hash_csr63_r { return static_cast<hash_csr63_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr63_r> other) const -> opsy::utility::clear_set<hash_csr63_r> {return opsy::utility::clear_set<hash_csr63_r>(hash_csr63_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs63() const -> cs63_f {return cs63_f(static_cast<uint32_t>(value_ >> cs63_f::offset));}

	constexpr hash_csr63_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr63_r other) const -> hash_csr63_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr63_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 64
 */
class hash_csr64_r {
public:

/**
 * Context swap x 
 */
class cs64_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs64_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr64_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr64_r>() const {return opsy::utility::clear_set<hash_csr64_r>(mask, *this);}
	constexpr auto operator|(hash_csr64_r other) const -> hash_csr64_r { return static_cast<hash_csr64_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr64_r> other) const -> opsy::utility::clear_set<hash_csr64_r> {return opsy::utility::clear_set<hash_csr64_r>(hash_csr64_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs64() const -> cs64_f {return cs64_f(static_cast<uint32_t>(value_ >> cs64_f::offset));}

	constexpr hash_csr64_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr64_r other) const -> hash_csr64_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr64_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 65
 */
class hash_csr65_r {
public:

/**
 * Context swap x 
 */
class cs65_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs65_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr65_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr65_r>() const {return opsy::utility::clear_set<hash_csr65_r>(mask, *this);}
	constexpr auto operator|(hash_csr65_r other) const -> hash_csr65_r { return static_cast<hash_csr65_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr65_r> other) const -> opsy::utility::clear_set<hash_csr65_r> {return opsy::utility::clear_set<hash_csr65_r>(hash_csr65_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs65() const -> cs65_f {return cs65_f(static_cast<uint32_t>(value_ >> cs65_f::offset));}

	constexpr hash_csr65_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr65_r other) const -> hash_csr65_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr65_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 66
 */
class hash_csr66_r {
public:

/**
 * Context swap x 
 */
class cs66_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs66_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr66_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr66_r>() const {return opsy::utility::clear_set<hash_csr66_r>(mask, *this);}
	constexpr auto operator|(hash_csr66_r other) const -> hash_csr66_r { return static_cast<hash_csr66_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr66_r> other) const -> opsy::utility::clear_set<hash_csr66_r> {return opsy::utility::clear_set<hash_csr66_r>(hash_csr66_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs66() const -> cs66_f {return cs66_f(static_cast<uint32_t>(value_ >> cs66_f::offset));}

	constexpr hash_csr66_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr66_r other) const -> hash_csr66_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr66_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 67
 */
class hash_csr67_r {
public:

/**
 * Context swap x 
 */
class cs67_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs67_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr67_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr67_r>() const {return opsy::utility::clear_set<hash_csr67_r>(mask, *this);}
	constexpr auto operator|(hash_csr67_r other) const -> hash_csr67_r { return static_cast<hash_csr67_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr67_r> other) const -> opsy::utility::clear_set<hash_csr67_r> {return opsy::utility::clear_set<hash_csr67_r>(hash_csr67_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs67() const -> cs67_f {return cs67_f(static_cast<uint32_t>(value_ >> cs67_f::offset));}

	constexpr hash_csr67_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr67_r other) const -> hash_csr67_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr67_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 68
 */
class hash_csr68_r {
public:

/**
 * Context swap x 
 */
class cs68_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs68_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr68_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr68_r>() const {return opsy::utility::clear_set<hash_csr68_r>(mask, *this);}
	constexpr auto operator|(hash_csr68_r other) const -> hash_csr68_r { return static_cast<hash_csr68_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr68_r> other) const -> opsy::utility::clear_set<hash_csr68_r> {return opsy::utility::clear_set<hash_csr68_r>(hash_csr68_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs68() const -> cs68_f {return cs68_f(static_cast<uint32_t>(value_ >> cs68_f::offset));}

	constexpr hash_csr68_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr68_r other) const -> hash_csr68_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr68_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 69
 */
class hash_csr69_r {
public:

/**
 * Context swap x 
 */
class cs69_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs69_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr69_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr69_r>() const {return opsy::utility::clear_set<hash_csr69_r>(mask, *this);}
	constexpr auto operator|(hash_csr69_r other) const -> hash_csr69_r { return static_cast<hash_csr69_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr69_r> other) const -> opsy::utility::clear_set<hash_csr69_r> {return opsy::utility::clear_set<hash_csr69_r>(hash_csr69_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs69() const -> cs69_f {return cs69_f(static_cast<uint32_t>(value_ >> cs69_f::offset));}

	constexpr hash_csr69_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr69_r other) const -> hash_csr69_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr69_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 70
 */
class hash_csr70_r {
public:

/**
 * Context swap x 
 */
class cs70_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs70_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr70_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr70_r>() const {return opsy::utility::clear_set<hash_csr70_r>(mask, *this);}
	constexpr auto operator|(hash_csr70_r other) const -> hash_csr70_r { return static_cast<hash_csr70_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr70_r> other) const -> opsy::utility::clear_set<hash_csr70_r> {return opsy::utility::clear_set<hash_csr70_r>(hash_csr70_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs70() const -> cs70_f {return cs70_f(static_cast<uint32_t>(value_ >> cs70_f::offset));}

	constexpr hash_csr70_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr70_r other) const -> hash_csr70_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr70_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 71
 */
class hash_csr71_r {
public:

/**
 * Context swap x 
 */
class cs71_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs71_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr71_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr71_r>() const {return opsy::utility::clear_set<hash_csr71_r>(mask, *this);}
	constexpr auto operator|(hash_csr71_r other) const -> hash_csr71_r { return static_cast<hash_csr71_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr71_r> other) const -> opsy::utility::clear_set<hash_csr71_r> {return opsy::utility::clear_set<hash_csr71_r>(hash_csr71_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs71() const -> cs71_f {return cs71_f(static_cast<uint32_t>(value_ >> cs71_f::offset));}

	constexpr hash_csr71_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr71_r other) const -> hash_csr71_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr71_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 72
 */
class hash_csr72_r {
public:

/**
 * Context swap x 
 */
class cs72_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs72_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr72_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr72_r>() const {return opsy::utility::clear_set<hash_csr72_r>(mask, *this);}
	constexpr auto operator|(hash_csr72_r other) const -> hash_csr72_r { return static_cast<hash_csr72_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr72_r> other) const -> opsy::utility::clear_set<hash_csr72_r> {return opsy::utility::clear_set<hash_csr72_r>(hash_csr72_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs72() const -> cs72_f {return cs72_f(static_cast<uint32_t>(value_ >> cs72_f::offset));}

	constexpr hash_csr72_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr72_r other) const -> hash_csr72_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr72_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 73
 */
class hash_csr73_r {
public:

/**
 * Context swap x 
 */
class cs73_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs73_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr73_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr73_r>() const {return opsy::utility::clear_set<hash_csr73_r>(mask, *this);}
	constexpr auto operator|(hash_csr73_r other) const -> hash_csr73_r { return static_cast<hash_csr73_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr73_r> other) const -> opsy::utility::clear_set<hash_csr73_r> {return opsy::utility::clear_set<hash_csr73_r>(hash_csr73_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs73() const -> cs73_f {return cs73_f(static_cast<uint32_t>(value_ >> cs73_f::offset));}

	constexpr hash_csr73_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr73_r other) const -> hash_csr73_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr73_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 74
 */
class hash_csr74_r {
public:

/**
 * Context swap x 
 */
class cs74_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs74_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr74_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr74_r>() const {return opsy::utility::clear_set<hash_csr74_r>(mask, *this);}
	constexpr auto operator|(hash_csr74_r other) const -> hash_csr74_r { return static_cast<hash_csr74_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr74_r> other) const -> opsy::utility::clear_set<hash_csr74_r> {return opsy::utility::clear_set<hash_csr74_r>(hash_csr74_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs74() const -> cs74_f {return cs74_f(static_cast<uint32_t>(value_ >> cs74_f::offset));}

	constexpr hash_csr74_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr74_r other) const -> hash_csr74_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr74_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 75
 */
class hash_csr75_r {
public:

/**
 * Context swap x 
 */
class cs75_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs75_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr75_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr75_r>() const {return opsy::utility::clear_set<hash_csr75_r>(mask, *this);}
	constexpr auto operator|(hash_csr75_r other) const -> hash_csr75_r { return static_cast<hash_csr75_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr75_r> other) const -> opsy::utility::clear_set<hash_csr75_r> {return opsy::utility::clear_set<hash_csr75_r>(hash_csr75_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs75() const -> cs75_f {return cs75_f(static_cast<uint32_t>(value_ >> cs75_f::offset));}

	constexpr hash_csr75_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr75_r other) const -> hash_csr75_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr75_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 76
 */
class hash_csr76_r {
public:

/**
 * Context swap x 
 */
class cs76_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs76_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr76_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr76_r>() const {return opsy::utility::clear_set<hash_csr76_r>(mask, *this);}
	constexpr auto operator|(hash_csr76_r other) const -> hash_csr76_r { return static_cast<hash_csr76_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr76_r> other) const -> opsy::utility::clear_set<hash_csr76_r> {return opsy::utility::clear_set<hash_csr76_r>(hash_csr76_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs76() const -> cs76_f {return cs76_f(static_cast<uint32_t>(value_ >> cs76_f::offset));}

	constexpr hash_csr76_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr76_r other) const -> hash_csr76_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr76_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 77
 */
class hash_csr77_r {
public:

/**
 * Context swap x 
 */
class cs77_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs77_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr77_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr77_r>() const {return opsy::utility::clear_set<hash_csr77_r>(mask, *this);}
	constexpr auto operator|(hash_csr77_r other) const -> hash_csr77_r { return static_cast<hash_csr77_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr77_r> other) const -> opsy::utility::clear_set<hash_csr77_r> {return opsy::utility::clear_set<hash_csr77_r>(hash_csr77_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs77() const -> cs77_f {return cs77_f(static_cast<uint32_t>(value_ >> cs77_f::offset));}

	constexpr hash_csr77_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr77_r other) const -> hash_csr77_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr77_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 78
 */
class hash_csr78_r {
public:

/**
 * Context swap x 
 */
class cs78_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs78_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr78_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr78_r>() const {return opsy::utility::clear_set<hash_csr78_r>(mask, *this);}
	constexpr auto operator|(hash_csr78_r other) const -> hash_csr78_r { return static_cast<hash_csr78_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr78_r> other) const -> opsy::utility::clear_set<hash_csr78_r> {return opsy::utility::clear_set<hash_csr78_r>(hash_csr78_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs78() const -> cs78_f {return cs78_f(static_cast<uint32_t>(value_ >> cs78_f::offset));}

	constexpr hash_csr78_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr78_r other) const -> hash_csr78_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr78_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 79
 */
class hash_csr79_r {
public:

/**
 * Context swap x 
 */
class cs79_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs79_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr79_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr79_r>() const {return opsy::utility::clear_set<hash_csr79_r>(mask, *this);}
	constexpr auto operator|(hash_csr79_r other) const -> hash_csr79_r { return static_cast<hash_csr79_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr79_r> other) const -> opsy::utility::clear_set<hash_csr79_r> {return opsy::utility::clear_set<hash_csr79_r>(hash_csr79_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs79() const -> cs79_f {return cs79_f(static_cast<uint32_t>(value_ >> cs79_f::offset));}

	constexpr hash_csr79_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr79_r other) const -> hash_csr79_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr79_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 80
 */
class hash_csr80_r {
public:

/**
 * Context swap x 
 */
class cs80_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs80_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr80_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr80_r>() const {return opsy::utility::clear_set<hash_csr80_r>(mask, *this);}
	constexpr auto operator|(hash_csr80_r other) const -> hash_csr80_r { return static_cast<hash_csr80_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr80_r> other) const -> opsy::utility::clear_set<hash_csr80_r> {return opsy::utility::clear_set<hash_csr80_r>(hash_csr80_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs80() const -> cs80_f {return cs80_f(static_cast<uint32_t>(value_ >> cs80_f::offset));}

	constexpr hash_csr80_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr80_r other) const -> hash_csr80_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr80_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 81
 */
class hash_csr81_r {
public:

/**
 * Context swap x 
 */
class cs81_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs81_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr81_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr81_r>() const {return opsy::utility::clear_set<hash_csr81_r>(mask, *this);}
	constexpr auto operator|(hash_csr81_r other) const -> hash_csr81_r { return static_cast<hash_csr81_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr81_r> other) const -> opsy::utility::clear_set<hash_csr81_r> {return opsy::utility::clear_set<hash_csr81_r>(hash_csr81_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs81() const -> cs81_f {return cs81_f(static_cast<uint32_t>(value_ >> cs81_f::offset));}

	constexpr hash_csr81_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr81_r other) const -> hash_csr81_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr81_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 82
 */
class hash_csr82_r {
public:

/**
 * Context swap x 
 */
class cs82_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs82_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr82_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr82_r>() const {return opsy::utility::clear_set<hash_csr82_r>(mask, *this);}
	constexpr auto operator|(hash_csr82_r other) const -> hash_csr82_r { return static_cast<hash_csr82_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr82_r> other) const -> opsy::utility::clear_set<hash_csr82_r> {return opsy::utility::clear_set<hash_csr82_r>(hash_csr82_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs82() const -> cs82_f {return cs82_f(static_cast<uint32_t>(value_ >> cs82_f::offset));}

	constexpr hash_csr82_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr82_r other) const -> hash_csr82_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr82_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 83
 */
class hash_csr83_r {
public:

/**
 * Context swap x 
 */
class cs83_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs83_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr83_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr83_r>() const {return opsy::utility::clear_set<hash_csr83_r>(mask, *this);}
	constexpr auto operator|(hash_csr83_r other) const -> hash_csr83_r { return static_cast<hash_csr83_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr83_r> other) const -> opsy::utility::clear_set<hash_csr83_r> {return opsy::utility::clear_set<hash_csr83_r>(hash_csr83_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs83() const -> cs83_f {return cs83_f(static_cast<uint32_t>(value_ >> cs83_f::offset));}

	constexpr hash_csr83_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr83_r other) const -> hash_csr83_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr83_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 84
 */
class hash_csr84_r {
public:

/**
 * Context swap x 
 */
class cs84_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs84_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr84_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr84_r>() const {return opsy::utility::clear_set<hash_csr84_r>(mask, *this);}
	constexpr auto operator|(hash_csr84_r other) const -> hash_csr84_r { return static_cast<hash_csr84_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr84_r> other) const -> opsy::utility::clear_set<hash_csr84_r> {return opsy::utility::clear_set<hash_csr84_r>(hash_csr84_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs84() const -> cs84_f {return cs84_f(static_cast<uint32_t>(value_ >> cs84_f::offset));}

	constexpr hash_csr84_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr84_r other) const -> hash_csr84_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr84_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 85
 */
class hash_csr85_r {
public:

/**
 * Context swap x 
 */
class cs85_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs85_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr85_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr85_r>() const {return opsy::utility::clear_set<hash_csr85_r>(mask, *this);}
	constexpr auto operator|(hash_csr85_r other) const -> hash_csr85_r { return static_cast<hash_csr85_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr85_r> other) const -> opsy::utility::clear_set<hash_csr85_r> {return opsy::utility::clear_set<hash_csr85_r>(hash_csr85_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs85() const -> cs85_f {return cs85_f(static_cast<uint32_t>(value_ >> cs85_f::offset));}

	constexpr hash_csr85_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr85_r other) const -> hash_csr85_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr85_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 86
 */
class hash_csr86_r {
public:

/**
 * Context swap x 
 */
class cs86_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs86_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr86_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr86_r>() const {return opsy::utility::clear_set<hash_csr86_r>(mask, *this);}
	constexpr auto operator|(hash_csr86_r other) const -> hash_csr86_r { return static_cast<hash_csr86_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr86_r> other) const -> opsy::utility::clear_set<hash_csr86_r> {return opsy::utility::clear_set<hash_csr86_r>(hash_csr86_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs86() const -> cs86_f {return cs86_f(static_cast<uint32_t>(value_ >> cs86_f::offset));}

	constexpr hash_csr86_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr86_r other) const -> hash_csr86_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr86_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 87
 */
class hash_csr87_r {
public:

/**
 * Context swap x 
 */
class cs87_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs87_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr87_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr87_r>() const {return opsy::utility::clear_set<hash_csr87_r>(mask, *this);}
	constexpr auto operator|(hash_csr87_r other) const -> hash_csr87_r { return static_cast<hash_csr87_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr87_r> other) const -> opsy::utility::clear_set<hash_csr87_r> {return opsy::utility::clear_set<hash_csr87_r>(hash_csr87_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs87() const -> cs87_f {return cs87_f(static_cast<uint32_t>(value_ >> cs87_f::offset));}

	constexpr hash_csr87_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr87_r other) const -> hash_csr87_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr87_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 88
 */
class hash_csr88_r {
public:

/**
 * Context swap x 
 */
class cs88_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs88_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr88_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr88_r>() const {return opsy::utility::clear_set<hash_csr88_r>(mask, *this);}
	constexpr auto operator|(hash_csr88_r other) const -> hash_csr88_r { return static_cast<hash_csr88_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr88_r> other) const -> opsy::utility::clear_set<hash_csr88_r> {return opsy::utility::clear_set<hash_csr88_r>(hash_csr88_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs88() const -> cs88_f {return cs88_f(static_cast<uint32_t>(value_ >> cs88_f::offset));}

	constexpr hash_csr88_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr88_r other) const -> hash_csr88_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr88_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 89
 */
class hash_csr89_r {
public:

/**
 * Context swap x 
 */
class cs89_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs89_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr89_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr89_r>() const {return opsy::utility::clear_set<hash_csr89_r>(mask, *this);}
	constexpr auto operator|(hash_csr89_r other) const -> hash_csr89_r { return static_cast<hash_csr89_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr89_r> other) const -> opsy::utility::clear_set<hash_csr89_r> {return opsy::utility::clear_set<hash_csr89_r>(hash_csr89_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs89() const -> cs89_f {return cs89_f(static_cast<uint32_t>(value_ >> cs89_f::offset));}

	constexpr hash_csr89_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr89_r other) const -> hash_csr89_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr89_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 90
 */
class hash_csr90_r {
public:

/**
 * Context swap x 
 */
class cs90_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs90_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr90_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr90_r>() const {return opsy::utility::clear_set<hash_csr90_r>(mask, *this);}
	constexpr auto operator|(hash_csr90_r other) const -> hash_csr90_r { return static_cast<hash_csr90_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr90_r> other) const -> opsy::utility::clear_set<hash_csr90_r> {return opsy::utility::clear_set<hash_csr90_r>(hash_csr90_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs90() const -> cs90_f {return cs90_f(static_cast<uint32_t>(value_ >> cs90_f::offset));}

	constexpr hash_csr90_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr90_r other) const -> hash_csr90_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr90_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 91
 */
class hash_csr91_r {
public:

/**
 * Context swap x 
 */
class cs91_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs91_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr91_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr91_r>() const {return opsy::utility::clear_set<hash_csr91_r>(mask, *this);}
	constexpr auto operator|(hash_csr91_r other) const -> hash_csr91_r { return static_cast<hash_csr91_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr91_r> other) const -> opsy::utility::clear_set<hash_csr91_r> {return opsy::utility::clear_set<hash_csr91_r>(hash_csr91_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs91() const -> cs91_f {return cs91_f(static_cast<uint32_t>(value_ >> cs91_f::offset));}

	constexpr hash_csr91_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr91_r other) const -> hash_csr91_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr91_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 92
 */
class hash_csr92_r {
public:

/**
 * Context swap x 
 */
class cs92_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs92_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr92_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr92_r>() const {return opsy::utility::clear_set<hash_csr92_r>(mask, *this);}
	constexpr auto operator|(hash_csr92_r other) const -> hash_csr92_r { return static_cast<hash_csr92_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr92_r> other) const -> opsy::utility::clear_set<hash_csr92_r> {return opsy::utility::clear_set<hash_csr92_r>(hash_csr92_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs92() const -> cs92_f {return cs92_f(static_cast<uint32_t>(value_ >> cs92_f::offset));}

	constexpr hash_csr92_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr92_r other) const -> hash_csr92_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr92_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 93
 */
class hash_csr93_r {
public:

/**
 * Context swap x 
 */
class cs93_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs93_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr93_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr93_r>() const {return opsy::utility::clear_set<hash_csr93_r>(mask, *this);}
	constexpr auto operator|(hash_csr93_r other) const -> hash_csr93_r { return static_cast<hash_csr93_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr93_r> other) const -> opsy::utility::clear_set<hash_csr93_r> {return opsy::utility::clear_set<hash_csr93_r>(hash_csr93_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs93() const -> cs93_f {return cs93_f(static_cast<uint32_t>(value_ >> cs93_f::offset));}

	constexpr hash_csr93_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr93_r other) const -> hash_csr93_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr93_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 94
 */
class hash_csr94_r {
public:

/**
 * Context swap x 
 */
class cs94_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs94_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr94_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr94_r>() const {return opsy::utility::clear_set<hash_csr94_r>(mask, *this);}
	constexpr auto operator|(hash_csr94_r other) const -> hash_csr94_r { return static_cast<hash_csr94_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr94_r> other) const -> opsy::utility::clear_set<hash_csr94_r> {return opsy::utility::clear_set<hash_csr94_r>(hash_csr94_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs94() const -> cs94_f {return cs94_f(static_cast<uint32_t>(value_ >> cs94_f::offset));}

	constexpr hash_csr94_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr94_r other) const -> hash_csr94_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr94_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 95
 */
class hash_csr95_r {
public:

/**
 * Context swap x 
 */
class cs95_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs95_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr95_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr95_r>() const {return opsy::utility::clear_set<hash_csr95_r>(mask, *this);}
	constexpr auto operator|(hash_csr95_r other) const -> hash_csr95_r { return static_cast<hash_csr95_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr95_r> other) const -> opsy::utility::clear_set<hash_csr95_r> {return opsy::utility::clear_set<hash_csr95_r>(hash_csr95_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs95() const -> cs95_f {return cs95_f(static_cast<uint32_t>(value_ >> cs95_f::offset));}

	constexpr hash_csr95_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr95_r other) const -> hash_csr95_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr95_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 96
 */
class hash_csr96_r {
public:

/**
 * Context swap x 
 */
class cs96_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs96_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr96_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr96_r>() const {return opsy::utility::clear_set<hash_csr96_r>(mask, *this);}
	constexpr auto operator|(hash_csr96_r other) const -> hash_csr96_r { return static_cast<hash_csr96_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr96_r> other) const -> opsy::utility::clear_set<hash_csr96_r> {return opsy::utility::clear_set<hash_csr96_r>(hash_csr96_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs96() const -> cs96_f {return cs96_f(static_cast<uint32_t>(value_ >> cs96_f::offset));}

	constexpr hash_csr96_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr96_r other) const -> hash_csr96_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr96_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 97
 */
class hash_csr97_r {
public:

/**
 * Context swap x 
 */
class cs97_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs97_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr97_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr97_r>() const {return opsy::utility::clear_set<hash_csr97_r>(mask, *this);}
	constexpr auto operator|(hash_csr97_r other) const -> hash_csr97_r { return static_cast<hash_csr97_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr97_r> other) const -> opsy::utility::clear_set<hash_csr97_r> {return opsy::utility::clear_set<hash_csr97_r>(hash_csr97_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs97() const -> cs97_f {return cs97_f(static_cast<uint32_t>(value_ >> cs97_f::offset));}

	constexpr hash_csr97_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr97_r other) const -> hash_csr97_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr97_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 98
 */
class hash_csr98_r {
public:

/**
 * Context swap x 
 */
class cs98_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs98_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr98_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr98_r>() const {return opsy::utility::clear_set<hash_csr98_r>(mask, *this);}
	constexpr auto operator|(hash_csr98_r other) const -> hash_csr98_r { return static_cast<hash_csr98_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr98_r> other) const -> opsy::utility::clear_set<hash_csr98_r> {return opsy::utility::clear_set<hash_csr98_r>(hash_csr98_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs98() const -> cs98_f {return cs98_f(static_cast<uint32_t>(value_ >> cs98_f::offset));}

	constexpr hash_csr98_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr98_r other) const -> hash_csr98_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr98_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 99
 */
class hash_csr99_r {
public:

/**
 * Context swap x 
 */
class cs99_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs99_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr99_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr99_r>() const {return opsy::utility::clear_set<hash_csr99_r>(mask, *this);}
	constexpr auto operator|(hash_csr99_r other) const -> hash_csr99_r { return static_cast<hash_csr99_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr99_r> other) const -> opsy::utility::clear_set<hash_csr99_r> {return opsy::utility::clear_set<hash_csr99_r>(hash_csr99_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs99() const -> cs99_f {return cs99_f(static_cast<uint32_t>(value_ >> cs99_f::offset));}

	constexpr hash_csr99_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr99_r other) const -> hash_csr99_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr99_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 100
 */
class hash_csr100_r {
public:

/**
 * Context swap x 
 */
class cs100_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs100_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr100_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr100_r>() const {return opsy::utility::clear_set<hash_csr100_r>(mask, *this);}
	constexpr auto operator|(hash_csr100_r other) const -> hash_csr100_r { return static_cast<hash_csr100_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr100_r> other) const -> opsy::utility::clear_set<hash_csr100_r> {return opsy::utility::clear_set<hash_csr100_r>(hash_csr100_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs100() const -> cs100_f {return cs100_f(static_cast<uint32_t>(value_ >> cs100_f::offset));}

	constexpr hash_csr100_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr100_r other) const -> hash_csr100_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr100_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 101
 */
class hash_csr101_r {
public:

/**
 * Context swap x 
 */
class cs101_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs101_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr101_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr101_r>() const {return opsy::utility::clear_set<hash_csr101_r>(mask, *this);}
	constexpr auto operator|(hash_csr101_r other) const -> hash_csr101_r { return static_cast<hash_csr101_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr101_r> other) const -> opsy::utility::clear_set<hash_csr101_r> {return opsy::utility::clear_set<hash_csr101_r>(hash_csr101_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs101() const -> cs101_f {return cs101_f(static_cast<uint32_t>(value_ >> cs101_f::offset));}

	constexpr hash_csr101_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr101_r other) const -> hash_csr101_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr101_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH context swap register 102
 */
class hash_csr102_r {
public:

/**
 * Context swap x 
 */
class cs102_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cs102_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_csr102_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_csr102_r>() const {return opsy::utility::clear_set<hash_csr102_r>(mask, *this);}
	constexpr auto operator|(hash_csr102_r other) const -> hash_csr102_r { return static_cast<hash_csr102_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_csr102_r> other) const -> opsy::utility::clear_set<hash_csr102_r> {return opsy::utility::clear_set<hash_csr102_r>(hash_csr102_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto cs102() const -> cs102_f {return cs102_f(static_cast<uint32_t>(value_ >> cs102_f::offset));}

	constexpr hash_csr102_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_csr102_r other) const -> hash_csr102_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_csr102_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 5
 */
class hash_hr5_r {
public:

/**
 * Hash data x 
 */
class h5_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h5_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr5_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr5_r>() const {return opsy::utility::clear_set<hash_hr5_r>(mask, *this);}
	constexpr auto operator|(hash_hr5_r other) const -> hash_hr5_r { return static_cast<hash_hr5_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr5_r> other) const -> opsy::utility::clear_set<hash_hr5_r> {return opsy::utility::clear_set<hash_hr5_r>(hash_hr5_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h5() const -> h5_f {return h5_f(static_cast<uint32_t>(value_ >> h5_f::offset));}

	constexpr hash_hr5_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr5_r other) const -> hash_hr5_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr5_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 6
 */
class hash_hr6_r {
public:

/**
 * Hash data x 
 */
class h6_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h6_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr6_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr6_r>() const {return opsy::utility::clear_set<hash_hr6_r>(mask, *this);}
	constexpr auto operator|(hash_hr6_r other) const -> hash_hr6_r { return static_cast<hash_hr6_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr6_r> other) const -> opsy::utility::clear_set<hash_hr6_r> {return opsy::utility::clear_set<hash_hr6_r>(hash_hr6_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h6() const -> h6_f {return h6_f(static_cast<uint32_t>(value_ >> h6_f::offset));}

	constexpr hash_hr6_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr6_r other) const -> hash_hr6_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr6_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 7
 */
class hash_hr7_r {
public:

/**
 * Hash data x 
 */
class h7_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h7_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr7_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr7_r>() const {return opsy::utility::clear_set<hash_hr7_r>(mask, *this);}
	constexpr auto operator|(hash_hr7_r other) const -> hash_hr7_r { return static_cast<hash_hr7_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr7_r> other) const -> opsy::utility::clear_set<hash_hr7_r> {return opsy::utility::clear_set<hash_hr7_r>(hash_hr7_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h7() const -> h7_f {return h7_f(static_cast<uint32_t>(value_ >> h7_f::offset));}

	constexpr hash_hr7_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr7_r other) const -> hash_hr7_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr7_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 8
 */
class hash_hr8_r {
public:

/**
 * Hash data x 
 */
class h8_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h8_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr8_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr8_r>() const {return opsy::utility::clear_set<hash_hr8_r>(mask, *this);}
	constexpr auto operator|(hash_hr8_r other) const -> hash_hr8_r { return static_cast<hash_hr8_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr8_r> other) const -> opsy::utility::clear_set<hash_hr8_r> {return opsy::utility::clear_set<hash_hr8_r>(hash_hr8_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h8() const -> h8_f {return h8_f(static_cast<uint32_t>(value_ >> h8_f::offset));}

	constexpr hash_hr8_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr8_r other) const -> hash_hr8_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr8_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 9
 */
class hash_hr9_r {
public:

/**
 * Hash data x 
 */
class h9_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h9_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr9_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr9_r>() const {return opsy::utility::clear_set<hash_hr9_r>(mask, *this);}
	constexpr auto operator|(hash_hr9_r other) const -> hash_hr9_r { return static_cast<hash_hr9_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr9_r> other) const -> opsy::utility::clear_set<hash_hr9_r> {return opsy::utility::clear_set<hash_hr9_r>(hash_hr9_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h9() const -> h9_f {return h9_f(static_cast<uint32_t>(value_ >> h9_f::offset));}

	constexpr hash_hr9_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr9_r other) const -> hash_hr9_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr9_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 10
 */
class hash_hr10_r {
public:

/**
 * Hash data x 
 */
class h10_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h10_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr10_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr10_r>() const {return opsy::utility::clear_set<hash_hr10_r>(mask, *this);}
	constexpr auto operator|(hash_hr10_r other) const -> hash_hr10_r { return static_cast<hash_hr10_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr10_r> other) const -> opsy::utility::clear_set<hash_hr10_r> {return opsy::utility::clear_set<hash_hr10_r>(hash_hr10_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h10() const -> h10_f {return h10_f(static_cast<uint32_t>(value_ >> h10_f::offset));}

	constexpr hash_hr10_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr10_r other) const -> hash_hr10_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr10_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 11
 */
class hash_hr11_r {
public:

/**
 * Hash data x 
 */
class h11_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h11_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr11_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr11_r>() const {return opsy::utility::clear_set<hash_hr11_r>(mask, *this);}
	constexpr auto operator|(hash_hr11_r other) const -> hash_hr11_r { return static_cast<hash_hr11_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr11_r> other) const -> opsy::utility::clear_set<hash_hr11_r> {return opsy::utility::clear_set<hash_hr11_r>(hash_hr11_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h11() const -> h11_f {return h11_f(static_cast<uint32_t>(value_ >> h11_f::offset));}

	constexpr hash_hr11_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr11_r other) const -> hash_hr11_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr11_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 12
 */
class hash_hr12_r {
public:

/**
 * Hash data x 
 */
class h12_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h12_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr12_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr12_r>() const {return opsy::utility::clear_set<hash_hr12_r>(mask, *this);}
	constexpr auto operator|(hash_hr12_r other) const -> hash_hr12_r { return static_cast<hash_hr12_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr12_r> other) const -> opsy::utility::clear_set<hash_hr12_r> {return opsy::utility::clear_set<hash_hr12_r>(hash_hr12_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h12() const -> h12_f {return h12_f(static_cast<uint32_t>(value_ >> h12_f::offset));}

	constexpr hash_hr12_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr12_r other) const -> hash_hr12_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr12_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 13
 */
class hash_hr13_r {
public:

/**
 * Hash data x 
 */
class h13_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h13_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr13_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr13_r>() const {return opsy::utility::clear_set<hash_hr13_r>(mask, *this);}
	constexpr auto operator|(hash_hr13_r other) const -> hash_hr13_r { return static_cast<hash_hr13_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr13_r> other) const -> opsy::utility::clear_set<hash_hr13_r> {return opsy::utility::clear_set<hash_hr13_r>(hash_hr13_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h13() const -> h13_f {return h13_f(static_cast<uint32_t>(value_ >> h13_f::offset));}

	constexpr hash_hr13_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr13_r other) const -> hash_hr13_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr13_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 14
 */
class hash_hr14_r {
public:

/**
 * Hash data x 
 */
class h14_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h14_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr14_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr14_r>() const {return opsy::utility::clear_set<hash_hr14_r>(mask, *this);}
	constexpr auto operator|(hash_hr14_r other) const -> hash_hr14_r { return static_cast<hash_hr14_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr14_r> other) const -> opsy::utility::clear_set<hash_hr14_r> {return opsy::utility::clear_set<hash_hr14_r>(hash_hr14_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h14() const -> h14_f {return h14_f(static_cast<uint32_t>(value_ >> h14_f::offset));}

	constexpr hash_hr14_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr14_r other) const -> hash_hr14_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr14_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * HASH supplementary digest register 15
 */
class hash_hr15_r {
public:

/**
 * Hash data x 
 */
class h15_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr h15_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator hash_hr15_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<hash_hr15_r>() const {return opsy::utility::clear_set<hash_hr15_r>(mask, *this);}
	constexpr auto operator|(hash_hr15_r other) const -> hash_hr15_r { return static_cast<hash_hr15_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<hash_hr15_r> other) const -> opsy::utility::clear_set<hash_hr15_r> {return opsy::utility::clear_set<hash_hr15_r>(hash_hr15_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto h15() const -> h15_f {return h15_f(static_cast<uint32_t>(value_ >> h15_f::offset));}

	constexpr hash_hr15_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(hash_hr15_r other) const -> hash_hr15_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> hash_hr15_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,hash_cr_r> hash_cr;
	opsy::utility::write_only_memory<uint32_t,hash_din_r> hash_din;
	opsy::utility::memory<uint32_t,hash_str_r> hash_str;
	opsy::utility::read_only_memory<uint32_t,hash_hra0_r> hash_hra0;
	opsy::utility::read_only_memory<uint32_t,hash_hra1_r> hash_hra1;
	opsy::utility::read_only_memory<uint32_t,hash_hra2_r> hash_hra2;
	opsy::utility::read_only_memory<uint32_t,hash_hra3_r> hash_hra3;
	opsy::utility::read_only_memory<uint32_t,hash_hra4_r> hash_hra4;
	opsy::utility::memory<uint32_t,hash_imr_r> hash_imr;
	opsy::utility::memory<uint32_t,hash_sr_r> hash_sr;
	opsy::utility::padding<208> _p40;
	opsy::utility::memory<uint32_t,hash_csr0_r> hash_csr0;
	opsy::utility::memory<uint32_t,hash_csr1_r> hash_csr1;
	opsy::utility::memory<uint32_t,hash_csr2_r> hash_csr2;
	opsy::utility::memory<uint32_t,hash_csr3_r> hash_csr3;
	opsy::utility::memory<uint32_t,hash_csr4_r> hash_csr4;
	opsy::utility::memory<uint32_t,hash_csr5_r> hash_csr5;
	opsy::utility::memory<uint32_t,hash_csr6_r> hash_csr6;
	opsy::utility::memory<uint32_t,hash_csr7_r> hash_csr7;
	opsy::utility::memory<uint32_t,hash_csr8_r> hash_csr8;
	opsy::utility::memory<uint32_t,hash_csr9_r> hash_csr9;
	opsy::utility::memory<uint32_t,hash_csr10_r> hash_csr10;
	opsy::utility::memory<uint32_t,hash_csr11_r> hash_csr11;
	opsy::utility::memory<uint32_t,hash_csr12_r> hash_csr12;
	opsy::utility::memory<uint32_t,hash_csr13_r> hash_csr13;
	opsy::utility::memory<uint32_t,hash_csr14_r> hash_csr14;
	opsy::utility::memory<uint32_t,hash_csr15_r> hash_csr15;
	opsy::utility::memory<uint32_t,hash_csr16_r> hash_csr16;
	opsy::utility::memory<uint32_t,hash_csr17_r> hash_csr17;
	opsy::utility::memory<uint32_t,hash_csr18_r> hash_csr18;
	opsy::utility::memory<uint32_t,hash_csr19_r> hash_csr19;
	opsy::utility::memory<uint32_t,hash_csr20_r> hash_csr20;
	opsy::utility::memory<uint32_t,hash_csr21_r> hash_csr21;
	opsy::utility::memory<uint32_t,hash_csr22_r> hash_csr22;
	opsy::utility::memory<uint32_t,hash_csr23_r> hash_csr23;
	opsy::utility::memory<uint32_t,hash_csr24_r> hash_csr24;
	opsy::utility::memory<uint32_t,hash_csr25_r> hash_csr25;
	opsy::utility::memory<uint32_t,hash_csr26_r> hash_csr26;
	opsy::utility::memory<uint32_t,hash_csr27_r> hash_csr27;
	opsy::utility::memory<uint32_t,hash_csr28_r> hash_csr28;
	opsy::utility::memory<uint32_t,hash_csr29_r> hash_csr29;
	opsy::utility::memory<uint32_t,hash_csr30_r> hash_csr30;
	opsy::utility::memory<uint32_t,hash_csr31_r> hash_csr31;
	opsy::utility::memory<uint32_t,hash_csr32_r> hash_csr32;
	opsy::utility::memory<uint32_t,hash_csr33_r> hash_csr33;
	opsy::utility::memory<uint32_t,hash_csr34_r> hash_csr34;
	opsy::utility::memory<uint32_t,hash_csr35_r> hash_csr35;
	opsy::utility::memory<uint32_t,hash_csr36_r> hash_csr36;
	opsy::utility::memory<uint32_t,hash_csr37_r> hash_csr37;
	opsy::utility::memory<uint32_t,hash_csr38_r> hash_csr38;
	opsy::utility::memory<uint32_t,hash_csr39_r> hash_csr39;
	opsy::utility::memory<uint32_t,hash_csr40_r> hash_csr40;
	opsy::utility::memory<uint32_t,hash_csr41_r> hash_csr41;
	opsy::utility::memory<uint32_t,hash_csr42_r> hash_csr42;
	opsy::utility::memory<uint32_t,hash_csr43_r> hash_csr43;
	opsy::utility::memory<uint32_t,hash_csr44_r> hash_csr44;
	opsy::utility::memory<uint32_t,hash_csr45_r> hash_csr45;
	opsy::utility::memory<uint32_t,hash_csr46_r> hash_csr46;
	opsy::utility::memory<uint32_t,hash_csr47_r> hash_csr47;
	opsy::utility::memory<uint32_t,hash_csr48_r> hash_csr48;
	opsy::utility::memory<uint32_t,hash_csr49_r> hash_csr49;
	opsy::utility::memory<uint32_t,hash_csr50_r> hash_csr50;
	opsy::utility::memory<uint32_t,hash_csr51_r> hash_csr51;
	opsy::utility::memory<uint32_t,hash_csr52_r> hash_csr52;
	opsy::utility::memory<uint32_t,hash_csr53_r> hash_csr53;
	opsy::utility::memory<uint32_t,hash_csr54_r> hash_csr54;
	opsy::utility::memory<uint32_t,hash_csr55_r> hash_csr55;
	opsy::utility::memory<uint32_t,hash_csr56_r> hash_csr56;
	opsy::utility::memory<uint32_t,hash_csr57_r> hash_csr57;
	opsy::utility::memory<uint32_t,hash_csr58_r> hash_csr58;
	opsy::utility::memory<uint32_t,hash_csr59_r> hash_csr59;
	opsy::utility::memory<uint32_t,hash_csr60_r> hash_csr60;
	opsy::utility::memory<uint32_t,hash_csr61_r> hash_csr61;
	opsy::utility::memory<uint32_t,hash_csr62_r> hash_csr62;
	opsy::utility::memory<uint32_t,hash_csr63_r> hash_csr63;
	opsy::utility::memory<uint32_t,hash_csr64_r> hash_csr64;
	opsy::utility::memory<uint32_t,hash_csr65_r> hash_csr65;
	opsy::utility::memory<uint32_t,hash_csr66_r> hash_csr66;
	opsy::utility::memory<uint32_t,hash_csr67_r> hash_csr67;
	opsy::utility::memory<uint32_t,hash_csr68_r> hash_csr68;
	opsy::utility::memory<uint32_t,hash_csr69_r> hash_csr69;
	opsy::utility::memory<uint32_t,hash_csr70_r> hash_csr70;
	opsy::utility::memory<uint32_t,hash_csr71_r> hash_csr71;
	opsy::utility::memory<uint32_t,hash_csr72_r> hash_csr72;
	opsy::utility::memory<uint32_t,hash_csr73_r> hash_csr73;
	opsy::utility::memory<uint32_t,hash_csr74_r> hash_csr74;
	opsy::utility::memory<uint32_t,hash_csr75_r> hash_csr75;
	opsy::utility::memory<uint32_t,hash_csr76_r> hash_csr76;
	opsy::utility::memory<uint32_t,hash_csr77_r> hash_csr77;
	opsy::utility::memory<uint32_t,hash_csr78_r> hash_csr78;
	opsy::utility::memory<uint32_t,hash_csr79_r> hash_csr79;
	opsy::utility::memory<uint32_t,hash_csr80_r> hash_csr80;
	opsy::utility::memory<uint32_t,hash_csr81_r> hash_csr81;
	opsy::utility::memory<uint32_t,hash_csr82_r> hash_csr82;
	opsy::utility::memory<uint32_t,hash_csr83_r> hash_csr83;
	opsy::utility::memory<uint32_t,hash_csr84_r> hash_csr84;
	opsy::utility::memory<uint32_t,hash_csr85_r> hash_csr85;
	opsy::utility::memory<uint32_t,hash_csr86_r> hash_csr86;
	opsy::utility::memory<uint32_t,hash_csr87_r> hash_csr87;
	opsy::utility::memory<uint32_t,hash_csr88_r> hash_csr88;
	opsy::utility::memory<uint32_t,hash_csr89_r> hash_csr89;
	opsy::utility::memory<uint32_t,hash_csr90_r> hash_csr90;
	opsy::utility::memory<uint32_t,hash_csr91_r> hash_csr91;
	opsy::utility::memory<uint32_t,hash_csr92_r> hash_csr92;
	opsy::utility::memory<uint32_t,hash_csr93_r> hash_csr93;
	opsy::utility::memory<uint32_t,hash_csr94_r> hash_csr94;
	opsy::utility::memory<uint32_t,hash_csr95_r> hash_csr95;
	opsy::utility::memory<uint32_t,hash_csr96_r> hash_csr96;
	opsy::utility::memory<uint32_t,hash_csr97_r> hash_csr97;
	opsy::utility::memory<uint32_t,hash_csr98_r> hash_csr98;
	opsy::utility::memory<uint32_t,hash_csr99_r> hash_csr99;
	opsy::utility::memory<uint32_t,hash_csr100_r> hash_csr100;
	opsy::utility::memory<uint32_t,hash_csr101_r> hash_csr101;
	opsy::utility::memory<uint32_t,hash_csr102_r> hash_csr102;
	opsy::utility::padding<124> _p660;
	opsy::utility::read_only_memory<uint32_t,hash_hra0_r> hash_hr0;
	opsy::utility::read_only_memory<uint32_t,hash_hra1_r> hash_hr1;
	opsy::utility::read_only_memory<uint32_t,hash_hra2_r> hash_hr2;
	opsy::utility::read_only_memory<uint32_t,hash_hra3_r> hash_hr3;
	opsy::utility::read_only_memory<uint32_t,hash_hra4_r> hash_hr4;
	opsy::utility::read_only_memory<uint32_t,hash_hr5_r> hash_hr5;
	opsy::utility::read_only_memory<uint32_t,hash_hr6_r> hash_hr6;
	opsy::utility::read_only_memory<uint32_t,hash_hr7_r> hash_hr7;
	opsy::utility::read_only_memory<uint32_t,hash_hr8_r> hash_hr8;
	opsy::utility::read_only_memory<uint32_t,hash_hr9_r> hash_hr9;
	opsy::utility::read_only_memory<uint32_t,hash_hr10_r> hash_hr10;
	opsy::utility::read_only_memory<uint32_t,hash_hr11_r> hash_hr11;
	opsy::utility::read_only_memory<uint32_t,hash_hr12_r> hash_hr12;
	opsy::utility::read_only_memory<uint32_t,hash_hr13_r> hash_hr13;
	opsy::utility::read_only_memory<uint32_t,hash_hr14_r> hash_hr14;
	opsy::utility::read_only_memory<uint32_t,hash_hr15_r> hash_hr15;
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
inline hash_p& hash_s = *reinterpret_cast<hash_p*>(0x520C0400);

} // STM32H523

