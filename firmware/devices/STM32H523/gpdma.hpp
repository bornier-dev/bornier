#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * GPDMA register block
 */
class gpdma_p {
public:

/**
 * GPDMA secure configuration register
 */
class gpdma_seccfgr_r {
public:

/**
 * secure state of channel x
 */
class sec0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * secure state of channel x
 */
class sec7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_seccfgr_r>() const {return opsy::utility::clear_set<gpdma_seccfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return static_cast<gpdma_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_seccfgr_r> other) const -> opsy::utility::clear_set<gpdma_seccfgr_r> {return opsy::utility::clear_set<gpdma_seccfgr_r>(gpdma_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sec0() const -> sec0_f {return sec0_f((value_ & sec0_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec1() const -> sec1_f {return sec1_f((value_ & sec1_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec2() const -> sec2_f {return sec2_f((value_ & sec2_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec3() const -> sec3_f {return sec3_f((value_ & sec3_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec4() const -> sec4_f {return sec4_f((value_ & sec4_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec5() const -> sec5_f {return sec5_f((value_ & sec5_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec6() const -> sec6_f {return sec6_f((value_ & sec6_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec7() const -> sec7_f {return sec7_f((value_ & sec7_f::mask) != 0);}

	constexpr gpdma_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_seccfgr_r other) const -> gpdma_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA privileged configuration register
 */
class gpdma_privcfgr_r {
public:

/**
 * privileged state of channel x
 */
class priv0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * privileged state of channel x
 */
class priv7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_privcfgr_r>() const {return opsy::utility::clear_set<gpdma_privcfgr_r>(mask, *this);}
	constexpr auto operator|(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return static_cast<gpdma_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_privcfgr_r> other) const -> opsy::utility::clear_set<gpdma_privcfgr_r> {return opsy::utility::clear_set<gpdma_privcfgr_r>(gpdma_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto priv0() const -> priv0_f {return priv0_f((value_ & priv0_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv1() const -> priv1_f {return priv1_f((value_ & priv1_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv2() const -> priv2_f {return priv2_f((value_ & priv2_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv3() const -> priv3_f {return priv3_f((value_ & priv3_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv4() const -> priv4_f {return priv4_f((value_ & priv4_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv5() const -> priv5_f {return priv5_f((value_ & priv5_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv6() const -> priv6_f {return priv6_f((value_ & priv6_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv7() const -> priv7_f {return priv7_f((value_ & priv7_f::mask) != 0);}

	constexpr gpdma_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_privcfgr_r other) const -> gpdma_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA configuration lock register
 */
class gpdma_rcfglockr_r {
public:

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * lock the configuration of GPDMA_SECCFGR.
 */
class lock7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_rcfglockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_rcfglockr_r>() const {return opsy::utility::clear_set<gpdma_rcfglockr_r>(mask, *this);}
	constexpr auto operator|(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return static_cast<gpdma_rcfglockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_rcfglockr_r> other) const -> opsy::utility::clear_set<gpdma_rcfglockr_r> {return opsy::utility::clear_set<gpdma_rcfglockr_r>(gpdma_rcfglockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lock0() const -> lock0_f {return lock0_f((value_ & lock0_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock1() const -> lock1_f {return lock1_f((value_ & lock1_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock2() const -> lock2_f {return lock2_f((value_ & lock2_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock3() const -> lock3_f {return lock3_f((value_ & lock3_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock4() const -> lock4_f {return lock4_f((value_ & lock4_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock5() const -> lock5_f {return lock5_f((value_ & lock5_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock6() const -> lock6_f {return lock6_f((value_ & lock6_f::mask) != 0);}
	[[nodiscard]] constexpr auto lock7() const -> lock7_f {return lock7_f((value_ & lock7_f::mask) != 0);}

	constexpr gpdma_rcfglockr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_rcfglockr_r other) const -> gpdma_rcfglockr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_rcfglockr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA nonsecure masked interrupt status register
 */
class gpdma_misr_r {
public:

/**
 * masked interrupt status of channel x
 */
class mis0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * masked interrupt status of channel x
 */
class mis7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mis7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_misr_r>() const {return opsy::utility::clear_set<gpdma_misr_r>(mask, *this);}
	constexpr auto operator|(gpdma_misr_r other) const -> gpdma_misr_r { return static_cast<gpdma_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_misr_r> other) const -> opsy::utility::clear_set<gpdma_misr_r> {return opsy::utility::clear_set<gpdma_misr_r>(gpdma_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mis0() const -> mis0_f {return mis0_f((value_ & mis0_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis1() const -> mis1_f {return mis1_f((value_ & mis1_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis2() const -> mis2_f {return mis2_f((value_ & mis2_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis3() const -> mis3_f {return mis3_f((value_ & mis3_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis4() const -> mis4_f {return mis4_f((value_ & mis4_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis5() const -> mis5_f {return mis5_f((value_ & mis5_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis6() const -> mis6_f {return mis6_f((value_ & mis6_f::mask) != 0);}
	[[nodiscard]] constexpr auto mis7() const -> mis7_f {return mis7_f((value_ & mis7_f::mask) != 0);}

	constexpr gpdma_misr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_misr_r other) const -> gpdma_misr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_misr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X linked-list base address register
 */
class gpdma_cxlbar_r {
public:

/**
 * linked-list base address of GPDMA channel x
 */
class lba_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr lba_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxlbar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxlbar_r>() const {return opsy::utility::clear_set<gpdma_cxlbar_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxlbar_r other) const -> gpdma_cxlbar_r { return static_cast<gpdma_cxlbar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxlbar_r> other) const -> opsy::utility::clear_set<gpdma_cxlbar_r> {return opsy::utility::clear_set<gpdma_cxlbar_r>(gpdma_cxlbar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto lba() const -> lba_f {return lba_f(static_cast<uint16_t>(value_ >> lba_f::offset));}

	constexpr gpdma_cxlbar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxlbar_r other) const -> gpdma_cxlbar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxlbar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X flag clear register
 */
class gpdma_cxfcr_r {
public:

/**
 * transfer complete flag clear
 */
class tcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * half transfer flag clear
 */
class htf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr htf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data transfer error flag clear
 */
class dtef_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dtef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * update link transfer error flag clear
 */
class ulef_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ulef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * user setting error flag clear
 */
class usef_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * completed suspension flag clear
 */
class suspf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trigger overrun flag clear
 */
class tof_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxfcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxfcr_r>() const {return opsy::utility::clear_set<gpdma_cxfcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return static_cast<gpdma_cxfcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxfcr_r> other) const -> opsy::utility::clear_set<gpdma_cxfcr_r> {return opsy::utility::clear_set<gpdma_cxfcr_r>(gpdma_cxfcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tcf() const -> tcf_f {return tcf_f((value_ & tcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto htf() const -> htf_f {return htf_f((value_ & htf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtef() const -> dtef_f {return dtef_f((value_ & dtef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ulef() const -> ulef_f {return ulef_f((value_ & ulef_f::mask) != 0);}
	[[nodiscard]] constexpr auto usef() const -> usef_f {return usef_f((value_ & usef_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspf() const -> suspf_f {return suspf_f((value_ & suspf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tof() const -> tof_f {return tof_f((value_ & tof_f::mask) != 0);}

	constexpr gpdma_cxfcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxfcr_r other) const -> gpdma_cxfcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxfcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X status register
 */
class gpdma_cxsr_r {
public:

/**
 * idle flag 
 */
class idlef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idlef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * transfer complete flag 
 */
class tcf_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * half transfer flag 
 */
class htf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr htf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data transfer error flag
 */
class dtef_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dtef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * update link transfer error flag
 */
class ulef_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ulef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * user setting error flag
 */
class usef_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr usef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * completed suspension flag
 */
class suspf_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trigger overrun flag
 */
class tof_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * monitored FIFO level 
 */
class fifol_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fifol_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxsr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxsr_r>() const {return opsy::utility::clear_set<gpdma_cxsr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return static_cast<gpdma_cxsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsr_r> other) const -> opsy::utility::clear_set<gpdma_cxsr_r> {return opsy::utility::clear_set<gpdma_cxsr_r>(gpdma_cxsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto idlef() const -> idlef_f {return idlef_f((value_ & idlef_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcf() const -> tcf_f {return tcf_f((value_ & tcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto htf() const -> htf_f {return htf_f((value_ & htf_f::mask) != 0);}
	[[nodiscard]] constexpr auto dtef() const -> dtef_f {return dtef_f((value_ & dtef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ulef() const -> ulef_f {return ulef_f((value_ & ulef_f::mask) != 0);}
	[[nodiscard]] constexpr auto usef() const -> usef_f {return usef_f((value_ & usef_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspf() const -> suspf_f {return suspf_f((value_ & suspf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tof() const -> tof_f {return tof_f((value_ & tof_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifol() const -> fifol_f {return fifol_f(static_cast<uint8_t>(value_ >> fifol_f::offset));}

	constexpr gpdma_cxsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxsr_r other) const -> gpdma_cxsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1; // 1 0x1

private:
	uint32_t value_;
};

/**
 * GPDMA channel X control register
 */
class gpdma_cxcr_r {
public:

/**
 * enable 
 */
class en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * reset 
 */
class reset_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr reset_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * suspend 
 */
class susp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr susp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * transfer complete interrupt enable
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * half transfer complete interrupt enable
 */
class htie_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr htie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * data transfer error interrupt enable
 */
class dteie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dteie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * update link transfer error interrupt enable
 */
class uleie_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr uleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * user setting error interrupt enable
 */
class useie_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr useie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * completed suspension interrupt enable
 */
class suspie_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trigger overrun interrupt enable
 */
class toie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr toie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Link step mode 
 */
class lsm_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lsm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * linked-list allocated port 
 */
class lap_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr lap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * priority level of the channel x GPDMA transfer versus others 
 */
class prio_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr prio_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxcr_r>() const {return opsy::utility::clear_set<gpdma_cxcr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return static_cast<gpdma_cxcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxcr_r> other) const -> opsy::utility::clear_set<gpdma_cxcr_r> {return opsy::utility::clear_set<gpdma_cxcr_r>(gpdma_cxcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto reset() const -> reset_f {return reset_f((value_ & reset_f::mask) != 0);}
	[[nodiscard]] constexpr auto susp() const -> susp_f {return susp_f((value_ & susp_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto htie() const -> htie_f {return htie_f((value_ & htie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dteie() const -> dteie_f {return dteie_f((value_ & dteie_f::mask) != 0);}
	[[nodiscard]] constexpr auto uleie() const -> uleie_f {return uleie_f((value_ & uleie_f::mask) != 0);}
	[[nodiscard]] constexpr auto useie() const -> useie_f {return useie_f((value_ & useie_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspie() const -> suspie_f {return suspie_f((value_ & suspie_f::mask) != 0);}
	[[nodiscard]] constexpr auto toie() const -> toie_f {return toie_f((value_ & toie_f::mask) != 0);}
	[[nodiscard]] constexpr auto lsm() const -> lsm_f {return lsm_f((value_ & lsm_f::mask) != 0);}
	[[nodiscard]] constexpr auto lap() const -> lap_f {return lap_f((value_ & lap_f::mask) != 0);}
	[[nodiscard]] constexpr auto prio() const -> prio_f {return prio_f(static_cast<uint8_t>(value_ >> prio_f::offset));}

	constexpr gpdma_cxcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxcr_r other) const -> gpdma_cxcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X transfer register 1
 */
class gpdma_cxtr1_r {
public:

/**
 * binary logarithm of the source data width of a burst in bytes 
 */
class sdw_log2_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr sdw_log2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * source incrementing burst 
 */
class sinc_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sinc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * source burst length minus 1, between 0 and 63 
 */
class sbl_1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sbl_1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * padding/alignment mode 
 */
class pam_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr pam_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * source byte exchange within the unaligned half-word of each source word 
 */
class sbx_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sbx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * source allocated port 
 */
class sap_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * security attribute of the GPDMA transfer from the source 
 */
class ssec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ssec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * binary logarithm of the destination data width of a burst, in bytes 
 */
class ddw_log2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ddw_log2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * destination incrementing burst 
 */
class dinc_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dinc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * destination burst length minus 1, between 0 and 63 
 */
class dbl_1_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dbl_1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * destination byte exchange 
 */
class dbx_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dbx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * destination half-word exchange 
 */
class dhx_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dhx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * destination allocated port 
 */
class dap_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * security attribute of the GPDMA transfer to the destination 
 */
class dsec_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr1_r>() const {return opsy::utility::clear_set<gpdma_cxtr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return static_cast<gpdma_cxtr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr1_r> other) const -> opsy::utility::clear_set<gpdma_cxtr1_r> {return opsy::utility::clear_set<gpdma_cxtr1_r>(gpdma_cxtr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sdw_log2() const -> sdw_log2_f {return sdw_log2_f(static_cast<uint8_t>(value_ >> sdw_log2_f::offset));}
	[[nodiscard]] constexpr auto sinc() const -> sinc_f {return sinc_f((value_ & sinc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbl_1() const -> sbl_1_f {return sbl_1_f(static_cast<uint8_t>(value_ >> sbl_1_f::offset));}
	[[nodiscard]] constexpr auto pam() const -> pam_f {return pam_f(static_cast<uint8_t>(value_ >> pam_f::offset));}
	[[nodiscard]] constexpr auto sbx() const -> sbx_f {return sbx_f((value_ & sbx_f::mask) != 0);}
	[[nodiscard]] constexpr auto sap() const -> sap_f {return sap_f((value_ & sap_f::mask) != 0);}
	[[nodiscard]] constexpr auto ssec() const -> ssec_f {return ssec_f((value_ & ssec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddw_log2() const -> ddw_log2_f {return ddw_log2_f(static_cast<uint8_t>(value_ >> ddw_log2_f::offset));}
	[[nodiscard]] constexpr auto dinc() const -> dinc_f {return dinc_f((value_ & dinc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dbl_1() const -> dbl_1_f {return dbl_1_f(static_cast<uint8_t>(value_ >> dbl_1_f::offset));}
	[[nodiscard]] constexpr auto dbx() const -> dbx_f {return dbx_f((value_ & dbx_f::mask) != 0);}
	[[nodiscard]] constexpr auto dhx() const -> dhx_f {return dhx_f((value_ & dhx_f::mask) != 0);}
	[[nodiscard]] constexpr auto dap() const -> dap_f {return dap_f((value_ & dap_f::mask) != 0);}
	[[nodiscard]] constexpr auto dsec() const -> dsec_f {return dsec_f((value_ & dsec_f::mask) != 0);}

	constexpr gpdma_cxtr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxtr1_r other) const -> gpdma_cxtr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxtr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X transfer register 2
 */
class gpdma_cxtr2_r {
public:

/**
 * GPDMA hardware request selection 
 */
class reqsel_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr reqsel_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * software request 
 */
class swreq_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swreq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * destination hardware request 
 */
class dreq_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dreq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Block hardware request 
 */
class breq_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr breq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Hardware request in peripheral flow control mode 
 */
class pfreq_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pfreq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * trigger mode 
 */
class trigm_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trigm_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * trigger event input selection 
 */
class trigsel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trigsel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * trigger event polarity 
 */
class trigpol_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trigpol_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * transfer complete event mode 
 */
class tcem_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr tcem_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator gpdma_cxtr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr2_r>() const {return opsy::utility::clear_set<gpdma_cxtr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return static_cast<gpdma_cxtr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr2_r> other) const -> opsy::utility::clear_set<gpdma_cxtr2_r> {return opsy::utility::clear_set<gpdma_cxtr2_r>(gpdma_cxtr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto reqsel() const -> reqsel_f {return reqsel_f(static_cast<uint8_t>(value_ >> reqsel_f::offset));}
	[[nodiscard]] constexpr auto swreq() const -> swreq_f {return swreq_f((value_ & swreq_f::mask) != 0);}
	[[nodiscard]] constexpr auto dreq() const -> dreq_f {return dreq_f((value_ & dreq_f::mask) != 0);}
	[[nodiscard]] constexpr auto breq() const -> breq_f {return breq_f((value_ & breq_f::mask) != 0);}
	[[nodiscard]] constexpr auto pfreq() const -> pfreq_f {return pfreq_f((value_ & pfreq_f::mask) != 0);}
	[[nodiscard]] constexpr auto trigm() const -> trigm_f {return trigm_f(static_cast<uint8_t>(value_ >> trigm_f::offset));}
	[[nodiscard]] constexpr auto trigsel() const -> trigsel_f {return trigsel_f(static_cast<uint8_t>(value_ >> trigsel_f::offset));}
	[[nodiscard]] constexpr auto trigpol() const -> trigpol_f {return trigpol_f(static_cast<uint8_t>(value_ >> trigpol_f::offset));}
	[[nodiscard]] constexpr auto tcem() const -> tcem_f {return tcem_f(static_cast<uint8_t>(value_ >> tcem_f::offset));}

	constexpr gpdma_cxtr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxtr2_r other) const -> gpdma_cxtr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxtr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X block register 1
 */
class gpdma_cxbr1_r {
public:

/**
 * block number of data bytes to transfer from the source 
 */
class bndt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr bndt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxbr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxbr1_r other) const -> gpdma_cxbr1_r { return static_cast<gpdma_cxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxbr1_r> {return opsy::utility::clear_set<gpdma_cxbr1_r>(gpdma_cxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto bndt() const -> bndt_f {return bndt_f(static_cast<uint16_t>(value_ >> bndt_f::offset));}

	constexpr gpdma_cxbr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxbr1_r other) const -> gpdma_cxbr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxbr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X source address register
 */
class gpdma_cxsar_r {
public:

/**
 * source address 
 */
class sa_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr sa_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator gpdma_cxsar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxsar_r>() const {return opsy::utility::clear_set<gpdma_cxsar_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxsar_r other) const -> gpdma_cxsar_r { return static_cast<gpdma_cxsar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxsar_r> other) const -> opsy::utility::clear_set<gpdma_cxsar_r> {return opsy::utility::clear_set<gpdma_cxsar_r>(gpdma_cxsar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto sa() const -> sa_f {return sa_f(static_cast<uint32_t>(value_ >> sa_f::offset));}

	constexpr gpdma_cxsar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxsar_r other) const -> gpdma_cxsar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxsar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X destination address register
 */
class gpdma_cxdar_r {
public:

/**
 * destination address 
 */
class da_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr da_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator gpdma_cxdar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxdar_r>() const {return opsy::utility::clear_set<gpdma_cxdar_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxdar_r other) const -> gpdma_cxdar_r { return static_cast<gpdma_cxdar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxdar_r> other) const -> opsy::utility::clear_set<gpdma_cxdar_r> {return opsy::utility::clear_set<gpdma_cxdar_r>(gpdma_cxdar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto da() const -> da_f {return da_f(static_cast<uint32_t>(value_ >> da_f::offset));}

	constexpr gpdma_cxdar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxdar_r other) const -> gpdma_cxdar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxdar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X linked-list address register
 */
class gpdma_cxllr_r {
public:

/**
 * pointer (16-bit low-significant address) to the next linked-list data structure 
 */
class la_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr la_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Update GPDMA_CxLLR register from memory 
 */
class ull_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ull_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxDAR register from memory 
 */
class uda_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uda_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * update GPDMA_CxSAR from memory 
 */
class usa_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxBR1 from memory 
 */
class ub1_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ub1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxTR2 from memory 
 */
class ut2_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ut2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxTR1 from memory 
 */
class ut1_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ut1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxllr_r>() const {return opsy::utility::clear_set<gpdma_cxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return static_cast<gpdma_cxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxllr_r> {return opsy::utility::clear_set<gpdma_cxllr_r>(gpdma_cxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto la() const -> la_f {return la_f(static_cast<uint16_t>(value_ >> la_f::offset));}
	[[nodiscard]] constexpr auto ull() const -> ull_f {return ull_f((value_ & ull_f::mask) != 0);}
	[[nodiscard]] constexpr auto uda() const -> uda_f {return uda_f((value_ & uda_f::mask) != 0);}
	[[nodiscard]] constexpr auto usa() const -> usa_f {return usa_f((value_ & usa_f::mask) != 0);}
	[[nodiscard]] constexpr auto ub1() const -> ub1_f {return ub1_f((value_ & ub1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ut2() const -> ut2_f {return ut2_f((value_ & ut2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ut1() const -> ut1_f {return ut1_f((value_ & ut1_f::mask) != 0);}

	constexpr gpdma_cxllr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxllr_r other) const -> gpdma_cxllr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxllr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X alternate block register 1
 */
class gpdma_cxxbr1_r {
public:

/**
 * block number of data bytes to transfer from the source 
 */
class bndt_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr bndt_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Block repeat counter 
 */
class brc_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr brc_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * source address decrement
 */
class sdec_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sdec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * destination address decrement
 */
class ddec_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Block repeat source address decrement 
 */
class brsdec_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr brsdec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Block repeat destination address decrement 
 */
class brddec_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr brddec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxbr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxbr1_r>() const {return opsy::utility::clear_set<gpdma_cxxbr1_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return static_cast<gpdma_cxxbr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxbr1_r> other) const -> opsy::utility::clear_set<gpdma_cxxbr1_r> {return opsy::utility::clear_set<gpdma_cxxbr1_r>(gpdma_cxxbr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bndt() const -> bndt_f {return bndt_f(static_cast<uint16_t>(value_ >> bndt_f::offset));}
	[[nodiscard]] constexpr auto brc() const -> brc_f {return brc_f(static_cast<uint16_t>(value_ >> brc_f::offset));}
	[[nodiscard]] constexpr auto sdec() const -> sdec_f {return sdec_f((value_ & sdec_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddec() const -> ddec_f {return ddec_f((value_ & ddec_f::mask) != 0);}
	[[nodiscard]] constexpr auto brsdec() const -> brsdec_f {return brsdec_f((value_ & brsdec_f::mask) != 0);}
	[[nodiscard]] constexpr auto brddec() const -> brddec_f {return brddec_f((value_ & brddec_f::mask) != 0);}

	constexpr gpdma_cxxbr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxxbr1_r other) const -> gpdma_cxxbr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxxbr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X transfer register 3
 */
class gpdma_cxtr3_r {
public:

/**
 * source address offset increment 
 */
class sao_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sao_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxtr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr3_r>() const {return opsy::utility::clear_set<gpdma_cxtr3_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr3_r other) const -> gpdma_cxtr3_r { return static_cast<gpdma_cxtr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr3_r> other) const -> opsy::utility::clear_set<gpdma_cxtr3_r> {return opsy::utility::clear_set<gpdma_cxtr3_r>(gpdma_cxtr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * destination address offset increment 
 */
class dao_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dao_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxtr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxtr3_r>() const {return opsy::utility::clear_set<gpdma_cxtr3_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxtr3_r other) const -> gpdma_cxtr3_r { return static_cast<gpdma_cxtr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxtr3_r> other) const -> opsy::utility::clear_set<gpdma_cxtr3_r> {return opsy::utility::clear_set<gpdma_cxtr3_r>(gpdma_cxtr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto sao() const -> sao_f {return sao_f(static_cast<uint16_t>(value_ >> sao_f::offset));}
	[[nodiscard]] constexpr auto dao() const -> dao_f {return dao_f(static_cast<uint16_t>(value_ >> dao_f::offset));}

	constexpr gpdma_cxtr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxtr3_r other) const -> gpdma_cxtr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxtr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X block register 2
 */
class gpdma_cxbr2_r {
public:

/**
 * Block repeated source address offset 
 */
class brsao_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr brsao_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxbr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxbr2_r>() const {return opsy::utility::clear_set<gpdma_cxbr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxbr2_r other) const -> gpdma_cxbr2_r { return static_cast<gpdma_cxbr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxbr2_r> other) const -> opsy::utility::clear_set<gpdma_cxbr2_r> {return opsy::utility::clear_set<gpdma_cxbr2_r>(gpdma_cxbr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Block repeated destination address offset 
 */
class brdao_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr brdao_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxbr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxbr2_r>() const {return opsy::utility::clear_set<gpdma_cxbr2_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxbr2_r other) const -> gpdma_cxbr2_r { return static_cast<gpdma_cxbr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxbr2_r> other) const -> opsy::utility::clear_set<gpdma_cxbr2_r> {return opsy::utility::clear_set<gpdma_cxbr2_r>(gpdma_cxbr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto brsao() const -> brsao_f {return brsao_f(static_cast<uint16_t>(value_ >> brsao_f::offset));}
	[[nodiscard]] constexpr auto brdao() const -> brdao_f {return brdao_f(static_cast<uint16_t>(value_ >> brdao_f::offset));}

	constexpr gpdma_cxbr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxbr2_r other) const -> gpdma_cxbr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxbr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * GPDMA channel X alternate linked-list address register
 */
class gpdma_cxxllr_r {
public:

/**
 * pointer (16-bit low-significant address) to the next linked-list data structure 
 */
class la_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 14;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr la_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Update GPDMA_CxLLR register from memory 
 */
class ull_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ull_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxBR2 from memory 
 */
class ub2_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ub2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxTR3 from memory 
 */
class ut3_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ut3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxDAR register from memory 
 */
class uda_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr uda_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * update GPDMA_CxSAR from memory 
 */
class usa_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr usa_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxBR1 from memory 
 */
class ub1_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ub1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxTR2 from memory 
 */
class ut2_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ut2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Update GPDMA_CxTR1 from memory 
 */
class ut1_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ut1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator gpdma_cxxllr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<gpdma_cxxllr_r>() const {return opsy::utility::clear_set<gpdma_cxxllr_r>(mask, *this);}
	constexpr auto operator|(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return static_cast<gpdma_cxxllr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<gpdma_cxxllr_r> other) const -> opsy::utility::clear_set<gpdma_cxxllr_r> {return opsy::utility::clear_set<gpdma_cxxllr_r>(gpdma_cxxllr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto la() const -> la_f {return la_f(static_cast<uint16_t>(value_ >> la_f::offset));}
	[[nodiscard]] constexpr auto ull() const -> ull_f {return ull_f((value_ & ull_f::mask) != 0);}
	[[nodiscard]] constexpr auto ub2() const -> ub2_f {return ub2_f((value_ & ub2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ut3() const -> ut3_f {return ut3_f((value_ & ut3_f::mask) != 0);}
	[[nodiscard]] constexpr auto uda() const -> uda_f {return uda_f((value_ & uda_f::mask) != 0);}
	[[nodiscard]] constexpr auto usa() const -> usa_f {return usa_f((value_ & usa_f::mask) != 0);}
	[[nodiscard]] constexpr auto ub1() const -> ub1_f {return ub1_f((value_ & ub1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ut2() const -> ut2_f {return ut2_f((value_ & ut2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ut1() const -> ut1_f {return ut1_f((value_ & ut1_f::mask) != 0);}

	constexpr gpdma_cxxllr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(gpdma_cxxllr_r other) const -> gpdma_cxxllr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> gpdma_cxxllr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,gpdma_seccfgr_r> gpdma_seccfgr;
	opsy::utility::memory<uint32_t,gpdma_privcfgr_r> gpdma_privcfgr;
	opsy::utility::memory<uint32_t,gpdma_rcfglockr_r> gpdma_rcfglockr;
	opsy::utility::read_only_memory<uint32_t,gpdma_misr_r> gpdma_misr;
	opsy::utility::read_only_memory<uint32_t,gpdma_misr_r> gpdma_smisr;
	opsy::utility::padding<60> _p20;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c0lbar;
	opsy::utility::padding<8> _p84;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c0fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c0sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c0cr;
	opsy::utility::padding<40> _p104;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c0tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c0tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c0br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c0sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c0dar;
	opsy::utility::padding<40> _p164;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c0llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c1lbar;
	opsy::utility::padding<8> _p212;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c1fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c1sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c1cr;
	opsy::utility::padding<40> _p232;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c1tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c1tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c1br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c1sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c1dar;
	opsy::utility::padding<40> _p292;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c1llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c2lbar;
	opsy::utility::padding<8> _p340;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c2fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c2sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c2cr;
	opsy::utility::padding<40> _p360;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c2tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c2tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c2br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c2sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c2dar;
	opsy::utility::padding<40> _p420;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c2llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c3lbar;
	opsy::utility::padding<8> _p468;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c3fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c3sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c3cr;
	opsy::utility::padding<40> _p488;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c3tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c3tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c3br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c3sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c3dar;
	opsy::utility::padding<40> _p548;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c3llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c4lbar;
	opsy::utility::padding<8> _p596;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c4fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c4sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c4cr;
	opsy::utility::padding<40> _p616;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c4tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c4tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c4br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c4sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c4dar;
	opsy::utility::padding<40> _p676;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c4llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c5lbar;
	opsy::utility::padding<8> _p724;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c5fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c5sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c5cr;
	opsy::utility::padding<40> _p744;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c5tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c5tr2;
	opsy::utility::memory<uint32_t,gpdma_cxbr1_r> gpdma_c5br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c5sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c5dar;
	opsy::utility::padding<40> _p804;
	opsy::utility::memory<uint32_t,gpdma_cxllr_r> gpdma_c5llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c6lbar;
	opsy::utility::padding<8> _p852;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c6fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c6sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c6cr;
	opsy::utility::padding<40> _p872;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c6tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c6tr2;
	opsy::utility::memory<uint32_t,gpdma_cxxbr1_r> gpdma_c6br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c6sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c6dar;
	opsy::utility::memory<uint32_t,gpdma_cxtr3_r> gpdma_c6tr3;
	opsy::utility::memory<uint32_t,gpdma_cxbr2_r> gpdma_c6br2;
	opsy::utility::padding<32> _p940;
	opsy::utility::memory<uint32_t,gpdma_cxxllr_r> gpdma_c6llr;
	opsy::utility::memory<uint32_t,gpdma_cxlbar_r> gpdma_c7lbar;
	opsy::utility::padding<8> _p980;
	opsy::utility::write_only_memory<uint32_t,gpdma_cxfcr_r> gpdma_c7fcr;
	opsy::utility::read_only_memory<uint32_t,gpdma_cxsr_r> gpdma_c7sr;
	opsy::utility::memory<uint32_t,gpdma_cxcr_r> gpdma_c7cr;
	opsy::utility::padding<40> _p1000;
	opsy::utility::memory<uint32_t,gpdma_cxtr1_r> gpdma_c7tr1;
	opsy::utility::memory<uint32_t,gpdma_cxtr2_r> gpdma_c7tr2;
	opsy::utility::memory<uint32_t,gpdma_cxxbr1_r> gpdma_c7br1;
	opsy::utility::memory<uint32_t,gpdma_cxsar_r> gpdma_c7sar;
	opsy::utility::memory<uint32_t,gpdma_cxdar_r> gpdma_c7dar;
	opsy::utility::memory<uint32_t,gpdma_cxtr3_r> gpdma_c7tr3;
	opsy::utility::memory<uint32_t,gpdma_cxbr2_r> gpdma_c7br2;
	opsy::utility::padding<32> _p1068;
	opsy::utility::memory<uint32_t,gpdma_cxxllr_r> gpdma_c7llr;
};

static_assert(std::is_standard_layout_v<gpdma_p>);
static_assert(offsetof(gpdma_p, gpdma_seccfgr) == 0);
static_assert(offsetof(gpdma_p, gpdma_privcfgr) == 4);
static_assert(offsetof(gpdma_p, gpdma_rcfglockr) == 8);
static_assert(offsetof(gpdma_p, gpdma_misr) == 12);
static_assert(offsetof(gpdma_p, gpdma_smisr) == 16);
static_assert(offsetof(gpdma_p, gpdma_c0lbar) == 80);
static_assert(offsetof(gpdma_p, gpdma_c0fcr) == 92);
static_assert(offsetof(gpdma_p, gpdma_c0sr) == 96);
static_assert(offsetof(gpdma_p, gpdma_c0cr) == 100);
static_assert(offsetof(gpdma_p, gpdma_c0tr1) == 144);
static_assert(offsetof(gpdma_p, gpdma_c0tr2) == 148);
static_assert(offsetof(gpdma_p, gpdma_c0br1) == 152);
static_assert(offsetof(gpdma_p, gpdma_c0sar) == 156);
static_assert(offsetof(gpdma_p, gpdma_c0dar) == 160);
static_assert(offsetof(gpdma_p, gpdma_c0llr) == 204);
static_assert(offsetof(gpdma_p, gpdma_c1lbar) == 208);
static_assert(offsetof(gpdma_p, gpdma_c1fcr) == 220);
static_assert(offsetof(gpdma_p, gpdma_c1sr) == 224);
static_assert(offsetof(gpdma_p, gpdma_c1cr) == 228);
static_assert(offsetof(gpdma_p, gpdma_c1tr1) == 272);
static_assert(offsetof(gpdma_p, gpdma_c1tr2) == 276);
static_assert(offsetof(gpdma_p, gpdma_c1br1) == 280);
static_assert(offsetof(gpdma_p, gpdma_c1sar) == 284);
static_assert(offsetof(gpdma_p, gpdma_c1dar) == 288);
static_assert(offsetof(gpdma_p, gpdma_c1llr) == 332);
static_assert(offsetof(gpdma_p, gpdma_c2lbar) == 336);
static_assert(offsetof(gpdma_p, gpdma_c2fcr) == 348);
static_assert(offsetof(gpdma_p, gpdma_c2sr) == 352);
static_assert(offsetof(gpdma_p, gpdma_c2cr) == 356);
static_assert(offsetof(gpdma_p, gpdma_c2tr1) == 400);
static_assert(offsetof(gpdma_p, gpdma_c2tr2) == 404);
static_assert(offsetof(gpdma_p, gpdma_c2br1) == 408);
static_assert(offsetof(gpdma_p, gpdma_c2sar) == 412);
static_assert(offsetof(gpdma_p, gpdma_c2dar) == 416);
static_assert(offsetof(gpdma_p, gpdma_c2llr) == 460);
static_assert(offsetof(gpdma_p, gpdma_c3lbar) == 464);
static_assert(offsetof(gpdma_p, gpdma_c3fcr) == 476);
static_assert(offsetof(gpdma_p, gpdma_c3sr) == 480);
static_assert(offsetof(gpdma_p, gpdma_c3cr) == 484);
static_assert(offsetof(gpdma_p, gpdma_c3tr1) == 528);
static_assert(offsetof(gpdma_p, gpdma_c3tr2) == 532);
static_assert(offsetof(gpdma_p, gpdma_c3br1) == 536);
static_assert(offsetof(gpdma_p, gpdma_c3sar) == 540);
static_assert(offsetof(gpdma_p, gpdma_c3dar) == 544);
static_assert(offsetof(gpdma_p, gpdma_c3llr) == 588);
static_assert(offsetof(gpdma_p, gpdma_c4lbar) == 592);
static_assert(offsetof(gpdma_p, gpdma_c4fcr) == 604);
static_assert(offsetof(gpdma_p, gpdma_c4sr) == 608);
static_assert(offsetof(gpdma_p, gpdma_c4cr) == 612);
static_assert(offsetof(gpdma_p, gpdma_c4tr1) == 656);
static_assert(offsetof(gpdma_p, gpdma_c4tr2) == 660);
static_assert(offsetof(gpdma_p, gpdma_c4br1) == 664);
static_assert(offsetof(gpdma_p, gpdma_c4sar) == 668);
static_assert(offsetof(gpdma_p, gpdma_c4dar) == 672);
static_assert(offsetof(gpdma_p, gpdma_c4llr) == 716);
static_assert(offsetof(gpdma_p, gpdma_c5lbar) == 720);
static_assert(offsetof(gpdma_p, gpdma_c5fcr) == 732);
static_assert(offsetof(gpdma_p, gpdma_c5sr) == 736);
static_assert(offsetof(gpdma_p, gpdma_c5cr) == 740);
static_assert(offsetof(gpdma_p, gpdma_c5tr1) == 784);
static_assert(offsetof(gpdma_p, gpdma_c5tr2) == 788);
static_assert(offsetof(gpdma_p, gpdma_c5br1) == 792);
static_assert(offsetof(gpdma_p, gpdma_c5sar) == 796);
static_assert(offsetof(gpdma_p, gpdma_c5dar) == 800);
static_assert(offsetof(gpdma_p, gpdma_c5llr) == 844);
static_assert(offsetof(gpdma_p, gpdma_c6lbar) == 848);
static_assert(offsetof(gpdma_p, gpdma_c6fcr) == 860);
static_assert(offsetof(gpdma_p, gpdma_c6sr) == 864);
static_assert(offsetof(gpdma_p, gpdma_c6cr) == 868);
static_assert(offsetof(gpdma_p, gpdma_c6tr1) == 912);
static_assert(offsetof(gpdma_p, gpdma_c6tr2) == 916);
static_assert(offsetof(gpdma_p, gpdma_c6br1) == 920);
static_assert(offsetof(gpdma_p, gpdma_c6sar) == 924);
static_assert(offsetof(gpdma_p, gpdma_c6dar) == 928);
static_assert(offsetof(gpdma_p, gpdma_c6tr3) == 932);
static_assert(offsetof(gpdma_p, gpdma_c6br2) == 936);
static_assert(offsetof(gpdma_p, gpdma_c6llr) == 972);
static_assert(offsetof(gpdma_p, gpdma_c7lbar) == 976);
static_assert(offsetof(gpdma_p, gpdma_c7fcr) == 988);
static_assert(offsetof(gpdma_p, gpdma_c7sr) == 992);
static_assert(offsetof(gpdma_p, gpdma_c7cr) == 996);
static_assert(offsetof(gpdma_p, gpdma_c7tr1) == 1040);
static_assert(offsetof(gpdma_p, gpdma_c7tr2) == 1044);
static_assert(offsetof(gpdma_p, gpdma_c7br1) == 1048);
static_assert(offsetof(gpdma_p, gpdma_c7sar) == 1052);
static_assert(offsetof(gpdma_p, gpdma_c7dar) == 1056);
static_assert(offsetof(gpdma_p, gpdma_c7tr3) == 1060);
static_assert(offsetof(gpdma_p, gpdma_c7br2) == 1064);
static_assert(offsetof(gpdma_p, gpdma_c7llr) == 1100);

inline gpdma_p& gpdma = *reinterpret_cast<gpdma_p*>(0x40020000);
inline gpdma_p& gpdma_s = *reinterpret_cast<gpdma_p*>(0x50020000);
inline gpdma_p& gpdma2 = *reinterpret_cast<gpdma_p*>(0x40021000);
inline gpdma_p& gpdma2_s = *reinterpret_cast<gpdma_p*>(0x50021000);

} // STM32H523

