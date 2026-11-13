#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * LPUART address block description
 */
class lpuart_p {
public:

/**
 * LPUART control register 1
 */
class lpuart_cr1_r {
public:

/**
 * LPUART enable 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART enable in low-power mode 
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable 
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable 
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable 
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty interrupt enable 
 */
class rxfneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full interrupt enable 
 */
class txfnfie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnfie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable 
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection 
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable 
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up method 
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable 
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable 
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time 
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time 
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Word length 
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable 
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO empty interrupt enable 
 */
class txfeie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full interrupt enable 
 */
class rxffie_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxffie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_r>() const {return opsy::utility::clear_set<lpuart_cr1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_r other) const -> lpuart_cr1_r { return static_cast<lpuart_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_r> {return opsy::utility::clear_set<lpuart_cr1_r>(lpuart_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto uesm() const -> uesm_f {return uesm_f((value_ & uesm_f::mask) != 0);}
	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto te() const -> te_f {return te_f((value_ & te_f::mask) != 0);}
	[[nodiscard]] constexpr auto idleie() const -> idleie_f {return idleie_f((value_ & idleie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfneie() const -> rxfneie_f {return rxfneie_f((value_ & rxfneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnfie() const -> txfnfie_f {return txfnfie_f((value_ & txfnfie_f::mask) != 0);}
	[[nodiscard]] constexpr auto peie() const -> peie_f {return peie_f((value_ & peie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps() const -> ps_f {return ps_f((value_ & ps_f::mask) != 0);}
	[[nodiscard]] constexpr auto pce() const -> pce_f {return pce_f((value_ & pce_f::mask) != 0);}
	[[nodiscard]] constexpr auto wake() const -> wake_f {return wake_f((value_ & wake_f::mask) != 0);}
	[[nodiscard]] constexpr auto m0() const -> m0_f {return m0_f((value_ & m0_f::mask) != 0);}
	[[nodiscard]] constexpr auto mme() const -> mme_f {return mme_f((value_ & mme_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmie() const -> cmie_f {return cmie_f((value_ & cmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfeie() const -> txfeie_f {return txfeie_f((value_ & txfeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxffie() const -> rxffie_f {return rxffie_f((value_ & rxffie_f::mask) != 0);}

	constexpr lpuart_cr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr1_r other) const -> lpuart_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 1
 */
class lpuart_cr1_alternate1_r {
public:

/**
 * LPUART enable 
 */
class ue_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ue_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPUART enable in low-power mode 
 */
class uesm_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr uesm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver enable 
 */
class re_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmitter enable 
 */
class te_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr te_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * IDLE interrupt enable 
 */
class idleie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idleie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data register not empty 
 */
class rxneie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxneie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete interrupt enable 
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty 
 */
class txeie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txeie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * PE interrupt enable 
 */
class peie_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr peie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity selection 
 */
class ps_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ps_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Parity control enable 
 */
class pce_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pce_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up method 
 */
class wake_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Word length 
 */
class m0_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr m0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode enable 
 */
class mme_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr mme_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match interrupt enable 
 */
class cmie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cmie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver Enable deassertion time 
 */
class dedt_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dedt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Driver Enable assertion time 
 */
class deat_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr deat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Word length 
 */
class m1_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr m1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO mode enable 
 */
class fifoen_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fifoen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr1_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr1_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return static_cast<lpuart_cr1_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr1_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr1_alternate1_r> {return opsy::utility::clear_set<lpuart_cr1_alternate1_r>(lpuart_cr1_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ue() const -> ue_f {return ue_f((value_ & ue_f::mask) != 0);}
	[[nodiscard]] constexpr auto uesm() const -> uesm_f {return uesm_f((value_ & uesm_f::mask) != 0);}
	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto te() const -> te_f {return te_f((value_ & te_f::mask) != 0);}
	[[nodiscard]] constexpr auto idleie() const -> idleie_f {return idleie_f((value_ & idleie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxneie() const -> rxneie_f {return rxneie_f((value_ & rxneie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txeie() const -> txeie_f {return txeie_f((value_ & txeie_f::mask) != 0);}
	[[nodiscard]] constexpr auto peie() const -> peie_f {return peie_f((value_ & peie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps() const -> ps_f {return ps_f((value_ & ps_f::mask) != 0);}
	[[nodiscard]] constexpr auto pce() const -> pce_f {return pce_f((value_ & pce_f::mask) != 0);}
	[[nodiscard]] constexpr auto wake() const -> wake_f {return wake_f((value_ & wake_f::mask) != 0);}
	[[nodiscard]] constexpr auto m0() const -> m0_f {return m0_f((value_ & m0_f::mask) != 0);}
	[[nodiscard]] constexpr auto mme() const -> mme_f {return mme_f((value_ & mme_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmie() const -> cmie_f {return cmie_f((value_ & cmie_f::mask) != 0);}
	[[nodiscard]] constexpr auto dedt() const -> dedt_f {return dedt_f(static_cast<uint8_t>(value_ >> dedt_f::offset));}
	[[nodiscard]] constexpr auto deat() const -> deat_f {return deat_f(static_cast<uint8_t>(value_ >> deat_f::offset));}
	[[nodiscard]] constexpr auto m1() const -> m1_f {return m1_f((value_ & m1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fifoen() const -> fifoen_f {return fifoen_f((value_ & fifoen_f::mask) != 0);}

	constexpr lpuart_cr1_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr1_alternate1_r other) const -> lpuart_cr1_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr1_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 2
 */
class lpuart_cr2_r {
public:

/**
 * 7-bit Address Detection/4-bit Address Detection 
 */
class addm7_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr addm7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * STOP bits 
 */
class stop_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr stop_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Swap TX/RX pins 
 */
class swap_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swap_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RX pin active level inversion 
 */
class rxinv_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TX pin active level inversion 
 */
class txinv_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txinv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Binary data inversion 
 */
class datainv_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr datainv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Most significant bit first 
 */
class msbfirst_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr msbfirst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address of the LPUART node 
 */
class add_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr2_r>() const {return opsy::utility::clear_set<lpuart_cr2_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr2_r other) const -> lpuart_cr2_r { return static_cast<lpuart_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr2_r> other) const -> opsy::utility::clear_set<lpuart_cr2_r> {return opsy::utility::clear_set<lpuart_cr2_r>(lpuart_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto addm7() const -> addm7_f {return addm7_f((value_ & addm7_f::mask) != 0);}
	[[nodiscard]] constexpr auto stop() const -> stop_f {return stop_f(static_cast<uint8_t>(value_ >> stop_f::offset));}
	[[nodiscard]] constexpr auto swap() const -> swap_f {return swap_f((value_ & swap_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxinv() const -> rxinv_f {return rxinv_f((value_ & rxinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto txinv() const -> txinv_f {return txinv_f((value_ & txinv_f::mask) != 0);}
	[[nodiscard]] constexpr auto datainv() const -> datainv_f {return datainv_f((value_ & datainv_f::mask) != 0);}
	[[nodiscard]] constexpr auto msbfirst() const -> msbfirst_f {return msbfirst_f((value_ & msbfirst_f::mask) != 0);}
	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}

	constexpr lpuart_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr2_r other) const -> lpuart_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 3
 */
class lpuart_cr3_r {
public:

/**
 * Error interrupt enable 
 */
class eie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex selection 
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable receiver 
 */
class dmar_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmar_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable transmitter 
 */
class dmat_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTS enable 
 */
class rtse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS enable 
 */
class ctse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt enable
 */
class ctsie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun Disable 
 */
class ovrdis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Disable on reception Error 
 */
class ddre_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ddre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable mode 
 */
class dem_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dem_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable polarity selection 
 */
class dep_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt enable 
 */
class wufie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold interrupt enable 
 */
class txftie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive FIFO threshold configuration 
 */
class rxftcfg_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr rxftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * RXFIFO threshold interrupt enable 
 */
class rxftie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold configuration 
 */
class txftcfg_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr txftcfg_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_cr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_r>() const {return opsy::utility::clear_set<lpuart_cr3_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_r other) const -> lpuart_cr3_r { return static_cast<lpuart_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_r> other) const -> opsy::utility::clear_set<lpuart_cr3_r> {return opsy::utility::clear_set<lpuart_cr3_r>(lpuart_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto eie() const -> eie_f {return eie_f((value_ & eie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmar() const -> dmar_f {return dmar_f((value_ & dmar_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmat() const -> dmat_f {return dmat_f((value_ & dmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtse() const -> rtse_f {return rtse_f((value_ & rtse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctse() const -> ctse_f {return ctse_f((value_ & ctse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsie() const -> ctsie_f {return ctsie_f((value_ & ctsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrdis() const -> ovrdis_f {return ovrdis_f((value_ & ovrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddre() const -> ddre_f {return ddre_f((value_ & ddre_f::mask) != 0);}
	[[nodiscard]] constexpr auto dem() const -> dem_f {return dem_f((value_ & dem_f::mask) != 0);}
	[[nodiscard]] constexpr auto dep() const -> dep_f {return dep_f((value_ & dep_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus0() const -> wus0_f {return wus0_f((value_ & wus0_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus1() const -> wus1_f {return wus1_f((value_ & wus1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wufie() const -> wufie_f {return wufie_f((value_ & wufie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftie() const -> txftie_f {return txftie_f((value_ & txftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxftcfg() const -> rxftcfg_f {return rxftcfg_f(static_cast<uint8_t>(value_ >> rxftcfg_f::offset));}
	[[nodiscard]] constexpr auto rxftie() const -> rxftie_f {return rxftie_f((value_ & rxftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto txftcfg() const -> txftcfg_f {return txftcfg_f(static_cast<uint8_t>(value_ >> txftcfg_f::offset));}

	constexpr lpuart_cr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr3_r other) const -> lpuart_cr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART control register 3
 */
class lpuart_cr3_alternate1_r {
public:

/**
 * Error interrupt enable 
 */
class eie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Half-duplex selection 
 */
class hdsel_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr hdsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable receiver 
 */
class dmar_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmar_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable transmitter 
 */
class dmat_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RTS enable 
 */
class rtse_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rtse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS enable 
 */
class ctse_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt enable
 */
class ctsie_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun Disable 
 */
class ovrdis_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ovrdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA Disable on reception Error 
 */
class ddre_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ddre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable mode 
 */
class dem_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dem_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Driver enable polarity selection 
 */
class dep_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus0_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt flag selection 
 */
class wus1_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wus1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode interrupt enable 
 */
class wufie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wufie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_cr3_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_cr3_alternate1_r>() const {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return static_cast<lpuart_cr3_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_cr3_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_cr3_alternate1_r> {return opsy::utility::clear_set<lpuart_cr3_alternate1_r>(lpuart_cr3_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto eie() const -> eie_f {return eie_f((value_ & eie_f::mask) != 0);}
	[[nodiscard]] constexpr auto hdsel() const -> hdsel_f {return hdsel_f((value_ & hdsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmar() const -> dmar_f {return dmar_f((value_ & dmar_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmat() const -> dmat_f {return dmat_f((value_ & dmat_f::mask) != 0);}
	[[nodiscard]] constexpr auto rtse() const -> rtse_f {return rtse_f((value_ & rtse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctse() const -> ctse_f {return ctse_f((value_ & ctse_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsie() const -> ctsie_f {return ctsie_f((value_ & ctsie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ovrdis() const -> ovrdis_f {return ovrdis_f((value_ & ovrdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddre() const -> ddre_f {return ddre_f((value_ & ddre_f::mask) != 0);}
	[[nodiscard]] constexpr auto dem() const -> dem_f {return dem_f((value_ & dem_f::mask) != 0);}
	[[nodiscard]] constexpr auto dep() const -> dep_f {return dep_f((value_ & dep_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus0() const -> wus0_f {return wus0_f((value_ & wus0_f::mask) != 0);}
	[[nodiscard]] constexpr auto wus1() const -> wus1_f {return wus1_f((value_ & wus1_f::mask) != 0);}
	[[nodiscard]] constexpr auto wufie() const -> wufie_f {return wufie_f((value_ & wufie_f::mask) != 0);}

	constexpr lpuart_cr3_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_cr3_alternate1_r other) const -> lpuart_cr3_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_cr3_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART baud rate register
 */
class lpuart_brr_r {
public:

/**
 * LPUART baud rate division (LPUARTDIV)
 */
class brr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 20;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr brr_f(uint32_t value) : value_(value & range) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator lpuart_brr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_brr_r>() const {return opsy::utility::clear_set<lpuart_brr_r>(mask, *this);}
	constexpr auto operator|(lpuart_brr_r other) const -> lpuart_brr_r { return static_cast<lpuart_brr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_brr_r> other) const -> opsy::utility::clear_set<lpuart_brr_r> {return opsy::utility::clear_set<lpuart_brr_r>(lpuart_brr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto brr() const -> brr_f {return brr_f(static_cast<uint32_t>(value_ >> brr_f::offset));}

	constexpr lpuart_brr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_brr_r other) const -> lpuart_brr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_brr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART request register
 */
class lpuart_rqr_r {
public:

/**
 * Send break request 
 */
class sbkrq_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sbkrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Mute mode request 
 */
class mmrq_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mmrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data flush request 
 */
class rxfrq_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data flush request 
 */
class txfrq_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfrq_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_rqr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_rqr_r>() const {return opsy::utility::clear_set<lpuart_rqr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rqr_r other) const -> lpuart_rqr_r { return static_cast<lpuart_rqr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rqr_r> other) const -> opsy::utility::clear_set<lpuart_rqr_r> {return opsy::utility::clear_set<lpuart_rqr_r>(lpuart_rqr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sbkrq() const -> sbkrq_f {return sbkrq_f((value_ & sbkrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto mmrq() const -> mmrq_f {return mmrq_f((value_ & mmrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfrq() const -> rxfrq_f {return rxfrq_f((value_ & rxfrq_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfrq() const -> txfrq_f {return txfrq_f((value_ & txfrq_f::mask) != 0);}

	constexpr lpuart_rqr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_rqr_r other) const -> lpuart_rqr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_rqr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt and status register
 */
class lpuart_isr_r {
public:

/**
 * Parity error 
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error 
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start bit noise detection flag 
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error 
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected 
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO not empty 
 */
class rxfne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxfne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete 
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO not full 
 */
class txfnf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txfnf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag 
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag 
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag 
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag 
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up from mute mode 
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode flag 
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag 
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag 
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO Empty 
 */
class txfe_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txfe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO Full 
 */
class rxff_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxff_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * RXFIFO threshold flag 
 */
class rxft_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rxft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TXFIFO threshold flag 
 */
class txft_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr txft_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_r>() const {return opsy::utility::clear_set<lpuart_isr_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_r other) const -> lpuart_isr_r { return static_cast<lpuart_isr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_r> other) const -> opsy::utility::clear_set<lpuart_isr_r> {return opsy::utility::clear_set<lpuart_isr_r>(lpuart_isr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pe() const -> pe_f {return pe_f((value_ & pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto fe() const -> fe_f {return fe_f((value_ & fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ne() const -> ne_f {return ne_f((value_ & ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto ore() const -> ore_f {return ore_f((value_ & ore_f::mask) != 0);}
	[[nodiscard]] constexpr auto idle() const -> idle_f {return idle_f((value_ & idle_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxfne() const -> rxfne_f {return rxfne_f((value_ & rxfne_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfnf() const -> txfnf_f {return txfnf_f((value_ & txfnf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}
	[[nodiscard]] constexpr auto txfe() const -> txfe_f {return txfe_f((value_ & txfe_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxff() const -> rxff_f {return rxff_f((value_ & rxff_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxft() const -> rxft_f {return rxft_f((value_ & rxft_f::mask) != 0);}
	[[nodiscard]] constexpr auto txft() const -> txft_f {return txft_f((value_ & txft_f::mask) != 0);}

	constexpr lpuart_isr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_isr_r other) const -> lpuart_isr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_isr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b100000000000000011000000; // 8388800 0x8000C0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt and status register
 */
class lpuart_isr_alternate1_r {
public:

/**
 * Parity error 
 */
class pe_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error 
 */
class fe_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start bit noise detection flag 
 */
class ne_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error 
 */
class ore_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ore_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected 
 */
class idle_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idle_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read data register not empty 
 */
class rxne_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rxne_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete 
 */
class tc_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit data register empty 
 */
class txe_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr txe_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS interrupt flag 
 */
class ctsif_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctsif_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS flag 
 */
class cts_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cts_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy flag 
 */
class busy_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match flag 
 */
class cmf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send break flag 
 */
class sbkf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sbkf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receiver wake-up from mute mode 
 */
class rwu_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rwu_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode flag 
 */
class wuf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wuf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmit enable acknowledge flag 
 */
class teack_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive enable acknowledge flag 
 */
class reack_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr reack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_isr_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_isr_alternate1_r>() const {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(mask, *this);}
	constexpr auto operator|(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return static_cast<lpuart_isr_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_isr_alternate1_r> other) const -> opsy::utility::clear_set<lpuart_isr_alternate1_r> {return opsy::utility::clear_set<lpuart_isr_alternate1_r>(lpuart_isr_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pe() const -> pe_f {return pe_f((value_ & pe_f::mask) != 0);}
	[[nodiscard]] constexpr auto fe() const -> fe_f {return fe_f((value_ & fe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ne() const -> ne_f {return ne_f((value_ & ne_f::mask) != 0);}
	[[nodiscard]] constexpr auto ore() const -> ore_f {return ore_f((value_ & ore_f::mask) != 0);}
	[[nodiscard]] constexpr auto idle() const -> idle_f {return idle_f((value_ & idle_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxne() const -> rxne_f {return rxne_f((value_ & rxne_f::mask) != 0);}
	[[nodiscard]] constexpr auto tc() const -> tc_f {return tc_f((value_ & tc_f::mask) != 0);}
	[[nodiscard]] constexpr auto txe() const -> txe_f {return txe_f((value_ & txe_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctsif() const -> ctsif_f {return ctsif_f((value_ & ctsif_f::mask) != 0);}
	[[nodiscard]] constexpr auto cts() const -> cts_f {return cts_f((value_ & cts_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmf() const -> cmf_f {return cmf_f((value_ & cmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto sbkf() const -> sbkf_f {return sbkf_f((value_ & sbkf_f::mask) != 0);}
	[[nodiscard]] constexpr auto rwu() const -> rwu_f {return rwu_f((value_ & rwu_f::mask) != 0);}
	[[nodiscard]] constexpr auto wuf() const -> wuf_f {return wuf_f((value_ & wuf_f::mask) != 0);}
	[[nodiscard]] constexpr auto teack() const -> teack_f {return teack_f((value_ & teack_f::mask) != 0);}
	[[nodiscard]] constexpr auto reack() const -> reack_f {return reack_f((value_ & reack_f::mask) != 0);}

	constexpr lpuart_isr_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_isr_alternate1_r other) const -> lpuart_isr_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_isr_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000000; // 192 0xC0

private:
	uint32_t value_;
};

/**
 * LPUART interrupt flag clear register
 */
class lpuart_icr_r {
public:

/**
 * Parity error clear flag 
 */
class pecf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Framing error clear flag 
 */
class fecf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Noise detected clear flag 
 */
class necf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr necf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Overrun error clear flag 
 */
class orecf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr orecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Idle line detected clear flag 
 */
class idlecf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idlecf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transmission complete clear flag 
 */
class tccf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tccf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CTS clear flag 
 */
class ctscf_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctscf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Character match clear flag 
 */
class cmcf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cmcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up from low-power mode clear flag 
 */
class wucf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wucf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator lpuart_icr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<lpuart_icr_r>() const {return opsy::utility::clear_set<lpuart_icr_r>(mask, *this);}
	constexpr auto operator|(lpuart_icr_r other) const -> lpuart_icr_r { return static_cast<lpuart_icr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_icr_r> other) const -> opsy::utility::clear_set<lpuart_icr_r> {return opsy::utility::clear_set<lpuart_icr_r>(lpuart_icr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto pecf() const -> pecf_f {return pecf_f((value_ & pecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto fecf() const -> fecf_f {return fecf_f((value_ & fecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto necf() const -> necf_f {return necf_f((value_ & necf_f::mask) != 0);}
	[[nodiscard]] constexpr auto orecf() const -> orecf_f {return orecf_f((value_ & orecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto idlecf() const -> idlecf_f {return idlecf_f((value_ & idlecf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tccf() const -> tccf_f {return tccf_f((value_ & tccf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctscf() const -> ctscf_f {return ctscf_f((value_ & ctscf_f::mask) != 0);}
	[[nodiscard]] constexpr auto cmcf() const -> cmcf_f {return cmcf_f((value_ & cmcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto wucf() const -> wucf_f {return wucf_f((value_ & wucf_f::mask) != 0);}

	constexpr lpuart_icr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_icr_r other) const -> lpuart_icr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_icr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART receive data register
 */
class lpuart_rdr_r {
public:

/**
 * Receive data value 
 */
class rdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rdr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lpuart_rdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_rdr_r>() const {return opsy::utility::clear_set<lpuart_rdr_r>(mask, *this);}
	constexpr auto operator|(lpuart_rdr_r other) const -> lpuart_rdr_r { return static_cast<lpuart_rdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_rdr_r> other) const -> opsy::utility::clear_set<lpuart_rdr_r> {return opsy::utility::clear_set<lpuart_rdr_r>(lpuart_rdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto rdr() const -> rdr_f {return rdr_f(static_cast<uint16_t>(value_ >> rdr_f::offset));}

	constexpr lpuart_rdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_rdr_r other) const -> lpuart_rdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_rdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART transmit data register
 */
class lpuart_tdr_r {
public:

/**
 * Transmit data value 
 */
class tdr_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 9;
	static constexpr uint16_t range = static_cast<uint16_t>(0b111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tdr_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator lpuart_tdr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_tdr_r>() const {return opsy::utility::clear_set<lpuart_tdr_r>(mask, *this);}
	constexpr auto operator|(lpuart_tdr_r other) const -> lpuart_tdr_r { return static_cast<lpuart_tdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_tdr_r> other) const -> opsy::utility::clear_set<lpuart_tdr_r> {return opsy::utility::clear_set<lpuart_tdr_r>(lpuart_tdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto tdr() const -> tdr_f {return tdr_f(static_cast<uint16_t>(value_ >> tdr_f::offset));}

	constexpr lpuart_tdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_tdr_r other) const -> lpuart_tdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_tdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPUART prescaler register
 */
class lpuart_presc_r {
public:

/**
 * Clock prescaler 
 */
class prescaler_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prescaler_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator lpuart_presc_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<lpuart_presc_r>() const {return opsy::utility::clear_set<lpuart_presc_r>(mask, *this);}
	constexpr auto operator|(lpuart_presc_r other) const -> lpuart_presc_r { return static_cast<lpuart_presc_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<lpuart_presc_r> other) const -> opsy::utility::clear_set<lpuart_presc_r> {return opsy::utility::clear_set<lpuart_presc_r>(lpuart_presc_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prescaler() const -> prescaler_f {return prescaler_f(static_cast<uint8_t>(value_ >> prescaler_f::offset));}

	constexpr lpuart_presc_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(lpuart_presc_r other) const -> lpuart_presc_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> lpuart_presc_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,lpuart_cr1_r> lpuart_cr1;
		opsy::utility::memory<uint32_t,lpuart_cr1_alternate1_r> lpuart_cr1_alternate1;
	};
	opsy::utility::memory<uint32_t,lpuart_cr2_r> lpuart_cr2;
	union {
		opsy::utility::memory<uint32_t,lpuart_cr3_r> lpuart_cr3;
		opsy::utility::memory<uint32_t,lpuart_cr3_alternate1_r> lpuart_cr3_alternate1;
	};
	opsy::utility::memory<uint32_t,lpuart_brr_r> lpuart_brr;
	opsy::utility::padding<8> _p16;
	opsy::utility::write_only_memory<uint32_t,lpuart_rqr_r> lpuart_rqr;
	union {
		opsy::utility::read_only_memory<uint32_t,lpuart_isr_r> lpuart_isr;
		opsy::utility::read_only_memory<uint32_t,lpuart_isr_alternate1_r> lpuart_isr_alternate1;
	};
	opsy::utility::write_only_memory<uint32_t,lpuart_icr_r> lpuart_icr;
	opsy::utility::read_only_memory<uint32_t,lpuart_rdr_r> lpuart_rdr;
	opsy::utility::memory<uint32_t,lpuart_tdr_r> lpuart_tdr;
	opsy::utility::memory<uint32_t,lpuart_presc_r> lpuart_presc;
};

static_assert(std::is_standard_layout_v<lpuart_p>);
static_assert(offsetof(lpuart_p, lpuart_cr1) == 0);
static_assert(offsetof(lpuart_p, lpuart_cr1_alternate1) == 0);
static_assert(offsetof(lpuart_p, lpuart_cr2) == 4);
static_assert(offsetof(lpuart_p, lpuart_cr3) == 8);
static_assert(offsetof(lpuart_p, lpuart_cr3_alternate1) == 8);
static_assert(offsetof(lpuart_p, lpuart_brr) == 12);
static_assert(offsetof(lpuart_p, lpuart_rqr) == 24);
static_assert(offsetof(lpuart_p, lpuart_isr) == 28);
static_assert(offsetof(lpuart_p, lpuart_isr_alternate1) == 28);
static_assert(offsetof(lpuart_p, lpuart_icr) == 32);
static_assert(offsetof(lpuart_p, lpuart_rdr) == 36);
static_assert(offsetof(lpuart_p, lpuart_tdr) == 40);
static_assert(offsetof(lpuart_p, lpuart_presc) == 44);

inline lpuart_p& lpuart = *reinterpret_cast<lpuart_p*>(0x44002400);
inline lpuart_p& lpuart_s = *reinterpret_cast<lpuart_p*>(0x54002400);

} // STM32H523

