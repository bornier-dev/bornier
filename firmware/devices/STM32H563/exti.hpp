#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Extended interrupt and event controller
 */
class exti_p {
public:

/**
 * EXTI rising trigger selection register
 */
class exti_rtsr1_r {
public:

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rt7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rt16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr1_r>() const {return opsy::utility::clear_set<exti_rtsr1_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr1_r other) const -> exti_rtsr1_r { return static_cast<exti_rtsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr1_r> other) const -> opsy::utility::clear_set<exti_rtsr1_r> {return opsy::utility::clear_set<exti_rtsr1_r>(exti_rtsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rt0() const -> rt0_f {return rt0_f((value_ & rt0_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt1() const -> rt1_f {return rt1_f((value_ & rt1_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt2() const -> rt2_f {return rt2_f((value_ & rt2_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt3() const -> rt3_f {return rt3_f((value_ & rt3_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt4() const -> rt4_f {return rt4_f((value_ & rt4_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt5() const -> rt5_f {return rt5_f((value_ & rt5_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt6() const -> rt6_f {return rt6_f((value_ & rt6_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt7() const -> rt7_f {return rt7_f((value_ & rt7_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt8() const -> rt8_f {return rt8_f((value_ & rt8_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt9() const -> rt9_f {return rt9_f((value_ & rt9_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt10() const -> rt10_f {return rt10_f((value_ & rt10_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt11() const -> rt11_f {return rt11_f((value_ & rt11_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt12() const -> rt12_f {return rt12_f((value_ & rt12_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt13() const -> rt13_f {return rt13_f((value_ & rt13_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt14() const -> rt14_f {return rt14_f((value_ & rt14_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt15() const -> rt15_f {return rt15_f((value_ & rt15_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt16() const -> rt16_f {return rt16_f((value_ & rt16_f::mask) != 0);}

	constexpr exti_rtsr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_rtsr1_r other) const -> exti_rtsr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_rtsr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI falling trigger selection register
 */
class exti_ftsr1_r {
public:

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ft7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ft16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr1_r>() const {return opsy::utility::clear_set<exti_ftsr1_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr1_r other) const -> exti_ftsr1_r { return static_cast<exti_ftsr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr1_r> other) const -> opsy::utility::clear_set<exti_ftsr1_r> {return opsy::utility::clear_set<exti_ftsr1_r>(exti_ftsr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ft0() const -> ft0_f {return ft0_f((value_ & ft0_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft1() const -> ft1_f {return ft1_f((value_ & ft1_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft2() const -> ft2_f {return ft2_f((value_ & ft2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft3() const -> ft3_f {return ft3_f((value_ & ft3_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft4() const -> ft4_f {return ft4_f((value_ & ft4_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft5() const -> ft5_f {return ft5_f((value_ & ft5_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft6() const -> ft6_f {return ft6_f((value_ & ft6_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft7() const -> ft7_f {return ft7_f((value_ & ft7_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft8() const -> ft8_f {return ft8_f((value_ & ft8_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft9() const -> ft9_f {return ft9_f((value_ & ft9_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft10() const -> ft10_f {return ft10_f((value_ & ft10_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft11() const -> ft11_f {return ft11_f((value_ & ft11_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft12() const -> ft12_f {return ft12_f((value_ & ft12_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft13() const -> ft13_f {return ft13_f((value_ & ft13_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft14() const -> ft14_f {return ft14_f((value_ & ft14_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft15() const -> ft15_f {return ft15_f((value_ & ft15_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft16() const -> ft16_f {return ft16_f((value_ & ft16_f::mask) != 0);}

	constexpr exti_ftsr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_ftsr1_r other) const -> exti_ftsr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_ftsr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI software interrupt event register
 */
class exti_swier1_r {
public:

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr swi7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swi16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier1_r>() const {return opsy::utility::clear_set<exti_swier1_r>(mask, *this);}
	constexpr auto operator|(exti_swier1_r other) const -> exti_swier1_r { return static_cast<exti_swier1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier1_r> other) const -> opsy::utility::clear_set<exti_swier1_r> {return opsy::utility::clear_set<exti_swier1_r>(exti_swier1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto swi0() const -> swi0_f {return swi0_f((value_ & swi0_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi1() const -> swi1_f {return swi1_f((value_ & swi1_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi2() const -> swi2_f {return swi2_f((value_ & swi2_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi3() const -> swi3_f {return swi3_f((value_ & swi3_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi4() const -> swi4_f {return swi4_f((value_ & swi4_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi5() const -> swi5_f {return swi5_f((value_ & swi5_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi6() const -> swi6_f {return swi6_f((value_ & swi6_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi7() const -> swi7_f {return swi7_f((value_ & swi7_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi8() const -> swi8_f {return swi8_f((value_ & swi8_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi9() const -> swi9_f {return swi9_f((value_ & swi9_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi10() const -> swi10_f {return swi10_f((value_ & swi10_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi11() const -> swi11_f {return swi11_f((value_ & swi11_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi12() const -> swi12_f {return swi12_f((value_ & swi12_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi13() const -> swi13_f {return swi13_f((value_ & swi13_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi14() const -> swi14_f {return swi14_f((value_ & swi14_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi15() const -> swi15_f {return swi15_f((value_ & swi15_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi16() const -> swi16_f {return swi16_f((value_ & swi16_f::mask) != 0);}

	constexpr exti_swier1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_swier1_r other) const -> exti_swier1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_swier1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI rising edge pending register
 */
class exti_rpr1_r {
public:

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpif7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rpif16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr1_r>() const {return opsy::utility::clear_set<exti_rpr1_r>(mask, *this);}
	constexpr auto operator|(exti_rpr1_r other) const -> exti_rpr1_r { return static_cast<exti_rpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr1_r> other) const -> opsy::utility::clear_set<exti_rpr1_r> {return opsy::utility::clear_set<exti_rpr1_r>(exti_rpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rpif0() const -> rpif0_f {return rpif0_f((value_ & rpif0_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif1() const -> rpif1_f {return rpif1_f((value_ & rpif1_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif2() const -> rpif2_f {return rpif2_f((value_ & rpif2_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif3() const -> rpif3_f {return rpif3_f((value_ & rpif3_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif4() const -> rpif4_f {return rpif4_f((value_ & rpif4_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif5() const -> rpif5_f {return rpif5_f((value_ & rpif5_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif6() const -> rpif6_f {return rpif6_f((value_ & rpif6_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif7() const -> rpif7_f {return rpif7_f((value_ & rpif7_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif8() const -> rpif8_f {return rpif8_f((value_ & rpif8_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif9() const -> rpif9_f {return rpif9_f((value_ & rpif9_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif10() const -> rpif10_f {return rpif10_f((value_ & rpif10_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif11() const -> rpif11_f {return rpif11_f((value_ & rpif11_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif12() const -> rpif12_f {return rpif12_f((value_ & rpif12_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif13() const -> rpif13_f {return rpif13_f((value_ & rpif13_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif14() const -> rpif14_f {return rpif14_f((value_ & rpif14_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif15() const -> rpif15_f {return rpif15_f((value_ & rpif15_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif16() const -> rpif16_f {return rpif16_f((value_ & rpif16_f::mask) != 0);}

	constexpr exti_rpr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_rpr1_r other) const -> exti_rpr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_rpr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI falling edge pending register
 */
class exti_fpr1_r {
public:

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fpif7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fpif16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr1_r>() const {return opsy::utility::clear_set<exti_fpr1_r>(mask, *this);}
	constexpr auto operator|(exti_fpr1_r other) const -> exti_fpr1_r { return static_cast<exti_fpr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr1_r> other) const -> opsy::utility::clear_set<exti_fpr1_r> {return opsy::utility::clear_set<exti_fpr1_r>(exti_fpr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fpif0() const -> fpif0_f {return fpif0_f((value_ & fpif0_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif1() const -> fpif1_f {return fpif1_f((value_ & fpif1_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif2() const -> fpif2_f {return fpif2_f((value_ & fpif2_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif3() const -> fpif3_f {return fpif3_f((value_ & fpif3_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif4() const -> fpif4_f {return fpif4_f((value_ & fpif4_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif5() const -> fpif5_f {return fpif5_f((value_ & fpif5_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif6() const -> fpif6_f {return fpif6_f((value_ & fpif6_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif7() const -> fpif7_f {return fpif7_f((value_ & fpif7_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif8() const -> fpif8_f {return fpif8_f((value_ & fpif8_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif9() const -> fpif9_f {return fpif9_f((value_ & fpif9_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif10() const -> fpif10_f {return fpif10_f((value_ & fpif10_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif11() const -> fpif11_f {return fpif11_f((value_ & fpif11_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif12() const -> fpif12_f {return fpif12_f((value_ & fpif12_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif13() const -> fpif13_f {return fpif13_f((value_ & fpif13_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif14() const -> fpif14_f {return fpif14_f((value_ & fpif14_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif15() const -> fpif15_f {return fpif15_f((value_ & fpif15_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif16() const -> fpif16_f {return fpif16_f((value_ & fpif16_f::mask) != 0);}

	constexpr exti_fpr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_fpr1_r other) const -> exti_fpr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_fpr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI security configuration register
 */
class exti_seccfgr1_r {
public:

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr1_r>() const {return opsy::utility::clear_set<exti_seccfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return static_cast<exti_seccfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr1_r> other) const -> opsy::utility::clear_set<exti_seccfgr1_r> {return opsy::utility::clear_set<exti_seccfgr1_r>(exti_seccfgr1_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto sec8() const -> sec8_f {return sec8_f((value_ & sec8_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec9() const -> sec9_f {return sec9_f((value_ & sec9_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec10() const -> sec10_f {return sec10_f((value_ & sec10_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec11() const -> sec11_f {return sec11_f((value_ & sec11_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec12() const -> sec12_f {return sec12_f((value_ & sec12_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec13() const -> sec13_f {return sec13_f((value_ & sec13_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec14() const -> sec14_f {return sec14_f((value_ & sec14_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec15() const -> sec15_f {return sec15_f((value_ & sec15_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec16() const -> sec16_f {return sec16_f((value_ & sec16_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec17() const -> sec17_f {return sec17_f((value_ & sec17_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec18() const -> sec18_f {return sec18_f((value_ & sec18_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec19() const -> sec19_f {return sec19_f((value_ & sec19_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec20() const -> sec20_f {return sec20_f((value_ & sec20_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec21() const -> sec21_f {return sec21_f((value_ & sec21_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec22() const -> sec22_f {return sec22_f((value_ & sec22_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec23() const -> sec23_f {return sec23_f((value_ & sec23_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec24() const -> sec24_f {return sec24_f((value_ & sec24_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec25() const -> sec25_f {return sec25_f((value_ & sec25_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec26() const -> sec26_f {return sec26_f((value_ & sec26_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec27() const -> sec27_f {return sec27_f((value_ & sec27_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec28() const -> sec28_f {return sec28_f((value_ & sec28_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec29() const -> sec29_f {return sec29_f((value_ & sec29_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec30() const -> sec30_f {return sec30_f((value_ & sec30_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec31() const -> sec31_f {return sec31_f((value_ & sec31_f::mask) != 0);}

	constexpr exti_seccfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_seccfgr1_r other) const -> exti_seccfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_seccfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI privilege configuration register
 */
class exti_privcfgr1_r {
public:

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr1_r>() const {return opsy::utility::clear_set<exti_privcfgr1_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return static_cast<exti_privcfgr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr1_r> other) const -> opsy::utility::clear_set<exti_privcfgr1_r> {return opsy::utility::clear_set<exti_privcfgr1_r>(exti_privcfgr1_r(mask) | other.clear(), *this | other.set()); }

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
	[[nodiscard]] constexpr auto priv8() const -> priv8_f {return priv8_f((value_ & priv8_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv9() const -> priv9_f {return priv9_f((value_ & priv9_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv10() const -> priv10_f {return priv10_f((value_ & priv10_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv11() const -> priv11_f {return priv11_f((value_ & priv11_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv12() const -> priv12_f {return priv12_f((value_ & priv12_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv13() const -> priv13_f {return priv13_f((value_ & priv13_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv14() const -> priv14_f {return priv14_f((value_ & priv14_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv15() const -> priv15_f {return priv15_f((value_ & priv15_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv16() const -> priv16_f {return priv16_f((value_ & priv16_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv17() const -> priv17_f {return priv17_f((value_ & priv17_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv18() const -> priv18_f {return priv18_f((value_ & priv18_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv19() const -> priv19_f {return priv19_f((value_ & priv19_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv20() const -> priv20_f {return priv20_f((value_ & priv20_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv21() const -> priv21_f {return priv21_f((value_ & priv21_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv22() const -> priv22_f {return priv22_f((value_ & priv22_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv23() const -> priv23_f {return priv23_f((value_ & priv23_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv24() const -> priv24_f {return priv24_f((value_ & priv24_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv25() const -> priv25_f {return priv25_f((value_ & priv25_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv26() const -> priv26_f {return priv26_f((value_ & priv26_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv27() const -> priv27_f {return priv27_f((value_ & priv27_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv28() const -> priv28_f {return priv28_f((value_ & priv28_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv29() const -> priv29_f {return priv29_f((value_ & priv29_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv30() const -> priv30_f {return priv30_f((value_ & priv30_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv31() const -> priv31_f {return priv31_f((value_ & priv31_f::mask) != 0);}

	constexpr exti_privcfgr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_privcfgr1_r other) const -> exti_privcfgr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_privcfgr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI rising trigger selection register 2
 */
class exti_rtsr2_r {
public:

/**
 * Rising trigger event configuration bit of configurable event input xsup (1)/sup When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rt46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr2_r>() const {return opsy::utility::clear_set<exti_rtsr2_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr2_r other) const -> exti_rtsr2_r { return static_cast<exti_rtsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr2_r> other) const -> opsy::utility::clear_set<exti_rtsr2_r> {return opsy::utility::clear_set<exti_rtsr2_r>(exti_rtsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input xsup (1)/sup When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rt50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr2_r>() const {return opsy::utility::clear_set<exti_rtsr2_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr2_r other) const -> exti_rtsr2_r { return static_cast<exti_rtsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr2_r> other) const -> opsy::utility::clear_set<exti_rtsr2_r> {return opsy::utility::clear_set<exti_rtsr2_r>(exti_rtsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Rising trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, RTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RTx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RTx can only be accessed with privileged access. Unprivileged write to this bit x is discarded, unprivileged read returns 0.
 */
class rt53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rt53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rtsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rtsr2_r>() const {return opsy::utility::clear_set<exti_rtsr2_r>(mask, *this);}
	constexpr auto operator|(exti_rtsr2_r other) const -> exti_rtsr2_r { return static_cast<exti_rtsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rtsr2_r> other) const -> opsy::utility::clear_set<exti_rtsr2_r> {return opsy::utility::clear_set<exti_rtsr2_r>(exti_rtsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rt46() const -> rt46_f {return rt46_f((value_ & rt46_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt50() const -> rt50_f {return rt50_f((value_ & rt50_f::mask) != 0);}
	[[nodiscard]] constexpr auto rt53() const -> rt53_f {return rt53_f((value_ & rt53_f::mask) != 0);}

	constexpr exti_rtsr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_rtsr2_r other) const -> exti_rtsr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_rtsr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI falling trigger selection register 2
 */
class exti_ftsr2_r {
public:

/**
 * Falling trigger event configuration bit of configurable event input x sup (1)/sup When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ft46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr2_r>() const {return opsy::utility::clear_set<exti_ftsr2_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr2_r other) const -> exti_ftsr2_r { return static_cast<exti_ftsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr2_r> other) const -> opsy::utility::clear_set<exti_ftsr2_r> {return opsy::utility::clear_set<exti_ftsr2_r>(exti_ftsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x sup (1)/sup When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ft50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr2_r>() const {return opsy::utility::clear_set<exti_ftsr2_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr2_r other) const -> exti_ftsr2_r { return static_cast<exti_ftsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr2_r> other) const -> opsy::utility::clear_set<exti_ftsr2_r> {return opsy::utility::clear_set<exti_ftsr2_r>(exti_ftsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Falling trigger event configuration bit of configurable event input x When EXTI_SECCFGR.SECx is disabled, FTx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FTx can only be accessed with secure access. Non-secure write to this FTx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FTx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FTx can only be accessed with privileged access. Unprivileged write to this FTx is discarded, unprivileged read returns 0.
 */
class ft53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ft53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_ftsr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_ftsr2_r>() const {return opsy::utility::clear_set<exti_ftsr2_r>(mask, *this);}
	constexpr auto operator|(exti_ftsr2_r other) const -> exti_ftsr2_r { return static_cast<exti_ftsr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_ftsr2_r> other) const -> opsy::utility::clear_set<exti_ftsr2_r> {return opsy::utility::clear_set<exti_ftsr2_r>(exti_ftsr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ft46() const -> ft46_f {return ft46_f((value_ & ft46_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft50() const -> ft50_f {return ft50_f((value_ & ft50_f::mask) != 0);}
	[[nodiscard]] constexpr auto ft53() const -> ft53_f {return ft53_f((value_ & ft53_f::mask) != 0);}

	constexpr exti_ftsr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_ftsr2_r other) const -> exti_ftsr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_ftsr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI software interrupt event register 2
 */
class exti_swier2_r {
public:

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr swi46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier2_r>() const {return opsy::utility::clear_set<exti_swier2_r>(mask, *this);}
	constexpr auto operator|(exti_swier2_r other) const -> exti_swier2_r { return static_cast<exti_swier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier2_r> other) const -> opsy::utility::clear_set<exti_swier2_r> {return opsy::utility::clear_set<exti_swier2_r>(exti_swier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swi50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier2_r>() const {return opsy::utility::clear_set<exti_swier2_r>(mask, *this);}
	constexpr auto operator|(exti_swier2_r other) const -> exti_swier2_r { return static_cast<exti_swier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier2_r> other) const -> opsy::utility::clear_set<exti_swier2_r> {return opsy::utility::clear_set<exti_swier2_r>(exti_swier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Software interrupt on event x When EXTI_SECCFGR.SECx is disabled, SWIx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, SWIx can only be accessed with secure access. Non-secure write to this SWI x is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, SWIx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SWIx can only be accessed with privileged access. Unprivileged write to this SWIx is discarded, unprivileged read returns 0. A software interrupt is generated independent from the setting in EXTI_RTSR and EXTI_FTSR. It always returns 0 when read.
 */
class swi53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr swi53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_swier2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_swier2_r>() const {return opsy::utility::clear_set<exti_swier2_r>(mask, *this);}
	constexpr auto operator|(exti_swier2_r other) const -> exti_swier2_r { return static_cast<exti_swier2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_swier2_r> other) const -> opsy::utility::clear_set<exti_swier2_r> {return opsy::utility::clear_set<exti_swier2_r>(exti_swier2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto swi46() const -> swi46_f {return swi46_f((value_ & swi46_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi50() const -> swi50_f {return swi50_f((value_ & swi50_f::mask) != 0);}
	[[nodiscard]] constexpr auto swi53() const -> swi53_f {return swi53_f((value_ & swi53_f::mask) != 0);}

	constexpr exti_swier2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_swier2_r other) const -> exti_swier2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_swier2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI rising edge pending register 2
 */
class exti_rpr2_r {
public:

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rpif46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr2_r>() const {return opsy::utility::clear_set<exti_rpr2_r>(mask, *this);}
	constexpr auto operator|(exti_rpr2_r other) const -> exti_rpr2_r { return static_cast<exti_rpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr2_r> other) const -> opsy::utility::clear_set<exti_rpr2_r> {return opsy::utility::clear_set<exti_rpr2_r>(exti_rpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rpif50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr2_r>() const {return opsy::utility::clear_set<exti_rpr2_r>(mask, *this);}
	constexpr auto operator|(exti_rpr2_r other) const -> exti_rpr2_r { return static_cast<exti_rpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr2_r> other) const -> opsy::utility::clear_set<exti_rpr2_r> {return opsy::utility::clear_set<exti_rpr2_r>(exti_rpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x rising edge pending bit When EXTI_SECCFGR.SECx is disabled, RPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, RPIFx can only be accessed with secure access. Non-secure write to this RPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, RPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, RPIFx can only be accessed with privileged access. Unprivileged write to this RPIFx is discarded, unprivileged read returns 0. This bit is set when the rising edge event or an EXTI_SWIER software trigger arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class rpif53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr rpif53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_rpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_rpr2_r>() const {return opsy::utility::clear_set<exti_rpr2_r>(mask, *this);}
	constexpr auto operator|(exti_rpr2_r other) const -> exti_rpr2_r { return static_cast<exti_rpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_rpr2_r> other) const -> opsy::utility::clear_set<exti_rpr2_r> {return opsy::utility::clear_set<exti_rpr2_r>(exti_rpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rpif46() const -> rpif46_f {return rpif46_f((value_ & rpif46_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif50() const -> rpif50_f {return rpif50_f((value_ & rpif50_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpif53() const -> rpif53_f {return rpif53_f((value_ & rpif53_f::mask) != 0);}

	constexpr exti_rpr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_rpr2_r other) const -> exti_rpr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_rpr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI falling edge pending register 2
 */
class exti_fpr2_r {
public:

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr fpif46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr2_r>() const {return opsy::utility::clear_set<exti_fpr2_r>(mask, *this);}
	constexpr auto operator|(exti_fpr2_r other) const -> exti_fpr2_r { return static_cast<exti_fpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr2_r> other) const -> opsy::utility::clear_set<exti_fpr2_r> {return opsy::utility::clear_set<exti_fpr2_r>(exti_fpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fpif50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr2_r>() const {return opsy::utility::clear_set<exti_fpr2_r>(mask, *this);}
	constexpr auto operator|(exti_fpr2_r other) const -> exti_fpr2_r { return static_cast<exti_fpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr2_r> other) const -> opsy::utility::clear_set<exti_fpr2_r> {return opsy::utility::clear_set<exti_fpr2_r>(exti_fpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * configurable event inputs x falling edge pending bit When EXTI_SECCFGR.SECx is disabled, FPIFx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, FPIFx can only be accessed with secure access. Non-secure write to this FPIFx is discarded, non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, FPIFx can be accessed with unprivileged and privileged access. When EXTI_PRIVCFGR.PRIVx is enabled, FPIFx can only be accessed with privileged access. Unprivileged write to this FPIFx is discarded, unprivileged read returns 0. This bit is set when the falling edge event arrives on the configurable event line. This bit is cleared by writing 1 to it.
 */
class fpif53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fpif53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_fpr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_fpr2_r>() const {return opsy::utility::clear_set<exti_fpr2_r>(mask, *this);}
	constexpr auto operator|(exti_fpr2_r other) const -> exti_fpr2_r { return static_cast<exti_fpr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_fpr2_r> other) const -> opsy::utility::clear_set<exti_fpr2_r> {return opsy::utility::clear_set<exti_fpr2_r>(exti_fpr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fpif46() const -> fpif46_f {return fpif46_f((value_ & fpif46_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif50() const -> fpif50_f {return fpif50_f((value_ & fpif50_f::mask) != 0);}
	[[nodiscard]] constexpr auto fpif53() const -> fpif53_f {return fpif53_f((value_ & fpif53_f::mask) != 0);}

	constexpr exti_fpr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_fpr2_r other) const -> exti_fpr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_fpr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI security configuration register 2
 */
class exti_seccfgr2_r {
public:

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec32_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec33_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec33_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec34_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec34_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec35_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec35_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec36_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec36_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec37_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec37_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec38_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec38_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec39_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sec39_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec40_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec40_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec41_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec41_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec42_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec42_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec43_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec43_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec44_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec44_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec45_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec45_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec47_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sec47_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec48_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec48_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec49_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec49_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec51_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec51_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec52_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec52_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec54_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec54_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec55_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec55_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec56_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec56_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_PRIVCFGR.PRIVx is disabled, SECx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, SECx can only be written with privileged access. Unprivileged write to this SECx is discarded.
 */
class sec57_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sec57_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_seccfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_seccfgr2_r>() const {return opsy::utility::clear_set<exti_seccfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return static_cast<exti_seccfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_seccfgr2_r> other) const -> opsy::utility::clear_set<exti_seccfgr2_r> {return opsy::utility::clear_set<exti_seccfgr2_r>(exti_seccfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto sec32() const -> sec32_f {return sec32_f((value_ & sec32_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec33() const -> sec33_f {return sec33_f((value_ & sec33_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec34() const -> sec34_f {return sec34_f((value_ & sec34_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec35() const -> sec35_f {return sec35_f((value_ & sec35_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec36() const -> sec36_f {return sec36_f((value_ & sec36_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec37() const -> sec37_f {return sec37_f((value_ & sec37_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec38() const -> sec38_f {return sec38_f((value_ & sec38_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec39() const -> sec39_f {return sec39_f((value_ & sec39_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec40() const -> sec40_f {return sec40_f((value_ & sec40_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec41() const -> sec41_f {return sec41_f((value_ & sec41_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec42() const -> sec42_f {return sec42_f((value_ & sec42_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec43() const -> sec43_f {return sec43_f((value_ & sec43_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec44() const -> sec44_f {return sec44_f((value_ & sec44_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec45() const -> sec45_f {return sec45_f((value_ & sec45_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec46() const -> sec46_f {return sec46_f((value_ & sec46_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec47() const -> sec47_f {return sec47_f((value_ & sec47_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec48() const -> sec48_f {return sec48_f((value_ & sec48_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec49() const -> sec49_f {return sec49_f((value_ & sec49_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec50() const -> sec50_f {return sec50_f((value_ & sec50_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec51() const -> sec51_f {return sec51_f((value_ & sec51_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec52() const -> sec52_f {return sec52_f((value_ & sec52_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec53() const -> sec53_f {return sec53_f((value_ & sec53_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec54() const -> sec54_f {return sec54_f((value_ & sec54_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec55() const -> sec55_f {return sec55_f((value_ & sec55_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec56() const -> sec56_f {return sec56_f((value_ & sec56_f::mask) != 0);}
	[[nodiscard]] constexpr auto sec57() const -> sec57_f {return sec57_f((value_ & sec57_f::mask) != 0);}

	constexpr exti_seccfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_seccfgr2_r other) const -> exti_seccfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_seccfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI privilege configuration register 2
 */
class exti_privcfgr2_r {
public:

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv32_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv33_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv33_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv34_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv34_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv35_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv35_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv36_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv36_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv37_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv37_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv38_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv38_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv39_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr priv39_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv40_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv40_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv41_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv41_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv42_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv42_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv43_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv43_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv44_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv44_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv45_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv45_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv47_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr priv47_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv48_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv48_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv49_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv49_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv51_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv51_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv52_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv52_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv54_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv54_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv55_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv55_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv56_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv56_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Security enable on event input x When EXTI_SECCFGR.SECx is disabled, PRIVx can be accessed with secure and non-secure access. When EXTI_SECCFGR.SECx is enabled, PRIVx can only be written with secure access. Non-secure write to this PRIVx is discarded.
 */
class priv57_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr priv57_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_privcfgr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_privcfgr2_r>() const {return opsy::utility::clear_set<exti_privcfgr2_r>(mask, *this);}
	constexpr auto operator|(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return static_cast<exti_privcfgr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_privcfgr2_r> other) const -> opsy::utility::clear_set<exti_privcfgr2_r> {return opsy::utility::clear_set<exti_privcfgr2_r>(exti_privcfgr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto priv32() const -> priv32_f {return priv32_f((value_ & priv32_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv33() const -> priv33_f {return priv33_f((value_ & priv33_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv34() const -> priv34_f {return priv34_f((value_ & priv34_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv35() const -> priv35_f {return priv35_f((value_ & priv35_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv36() const -> priv36_f {return priv36_f((value_ & priv36_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv37() const -> priv37_f {return priv37_f((value_ & priv37_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv38() const -> priv38_f {return priv38_f((value_ & priv38_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv39() const -> priv39_f {return priv39_f((value_ & priv39_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv40() const -> priv40_f {return priv40_f((value_ & priv40_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv41() const -> priv41_f {return priv41_f((value_ & priv41_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv42() const -> priv42_f {return priv42_f((value_ & priv42_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv43() const -> priv43_f {return priv43_f((value_ & priv43_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv44() const -> priv44_f {return priv44_f((value_ & priv44_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv45() const -> priv45_f {return priv45_f((value_ & priv45_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv46() const -> priv46_f {return priv46_f((value_ & priv46_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv47() const -> priv47_f {return priv47_f((value_ & priv47_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv48() const -> priv48_f {return priv48_f((value_ & priv48_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv49() const -> priv49_f {return priv49_f((value_ & priv49_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv50() const -> priv50_f {return priv50_f((value_ & priv50_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv51() const -> priv51_f {return priv51_f((value_ & priv51_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv52() const -> priv52_f {return priv52_f((value_ & priv52_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv53() const -> priv53_f {return priv53_f((value_ & priv53_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv54() const -> priv54_f {return priv54_f((value_ & priv54_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv55() const -> priv55_f {return priv55_f((value_ & priv55_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv56() const -> priv56_f {return priv56_f((value_ & priv56_f::mask) != 0);}
	[[nodiscard]] constexpr auto priv57() const -> priv57_f {return priv57_f((value_ & priv57_f::mask) != 0);}

	constexpr exti_privcfgr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_privcfgr2_r other) const -> exti_privcfgr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_privcfgr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI external interrupt selection register
 */
class exti_exticr1_r {
public:

/**
 * EXTI0 GPIO port selection These bits are written by software to select the source input for EXTI0 external interrupt. When EXTI_SECCFGR1.SEC0 is disabled, EXTI0 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC0 is enabled, EXTI0 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV0 is disabled, EXTI0 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV0 is enabled, EXTI0 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr exti0_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr1_r>() const {return opsy::utility::clear_set<exti_exticr1_r>(mask, *this);}
	constexpr auto operator|(exti_exticr1_r other) const -> exti_exticr1_r { return static_cast<exti_exticr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr1_r> other) const -> opsy::utility::clear_set<exti_exticr1_r> {return opsy::utility::clear_set<exti_exticr1_r>(exti_exticr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI1 GPIO port selection These bits are written by software to select the source input for EXTI1 external interrupt. When EXTI_SECCFGR1.SEC1 is disabled, EXTI1 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC1 is enabled, EXTI1 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV1 is disabled, EXTI1 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV1 is enabled, EXTI1 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr exti1_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr1_r>() const {return opsy::utility::clear_set<exti_exticr1_r>(mask, *this);}
	constexpr auto operator|(exti_exticr1_r other) const -> exti_exticr1_r { return static_cast<exti_exticr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr1_r> other) const -> opsy::utility::clear_set<exti_exticr1_r> {return opsy::utility::clear_set<exti_exticr1_r>(exti_exticr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI2 GPIO port selection These bits are written by software to select the source input for EXTI2 external interrupt. When EXTI_SECCFGR1.SEC2 is disabled, EXTI2 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC2 is enabled, EXTI2 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV2 is disabled, EXTI2 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV2 is enabled, EXTI2 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti2_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti2_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr1_r>() const {return opsy::utility::clear_set<exti_exticr1_r>(mask, *this);}
	constexpr auto operator|(exti_exticr1_r other) const -> exti_exticr1_r { return static_cast<exti_exticr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr1_r> other) const -> opsy::utility::clear_set<exti_exticr1_r> {return opsy::utility::clear_set<exti_exticr1_r>(exti_exticr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI3 GPIO port selection These bits are written by software to select the source input for EXTI3 external interrupt. When EXTI_SECCFGR1.SEC3 is disabled, EXTI3 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC3 is enabled, EXTI3 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV3 is disabled, EXTI3 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV3 is enabled, EXTI3 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti3_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti3_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr1_r>() const {return opsy::utility::clear_set<exti_exticr1_r>(mask, *this);}
	constexpr auto operator|(exti_exticr1_r other) const -> exti_exticr1_r { return static_cast<exti_exticr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr1_r> other) const -> opsy::utility::clear_set<exti_exticr1_r> {return opsy::utility::clear_set<exti_exticr1_r>(exti_exticr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto exti0() const -> exti0_f {return exti0_f(static_cast<uint8_t>(value_ >> exti0_f::offset));}
	[[nodiscard]] constexpr auto exti1() const -> exti1_f {return exti1_f(static_cast<uint8_t>(value_ >> exti1_f::offset));}
	[[nodiscard]] constexpr auto exti2() const -> exti2_f {return exti2_f(static_cast<uint8_t>(value_ >> exti2_f::offset));}
	[[nodiscard]] constexpr auto exti3() const -> exti3_f {return exti3_f(static_cast<uint8_t>(value_ >> exti3_f::offset));}

	constexpr exti_exticr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_exticr1_r other) const -> exti_exticr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_exticr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI external interrupt selection register
 */
class exti_exticr2_r {
public:

/**
 * EXTI4 GPIO port selection These bits are written by software to select the source input for EXTI4 external interrupt. When EXTI_SECCFGR1.SEC4 is disabled, EXTI4 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC4 is enabled, EXTI4 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV4 is disabled, EXTI4 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV4 is enabled, EXTI4 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti4_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr exti4_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr2_r>() const {return opsy::utility::clear_set<exti_exticr2_r>(mask, *this);}
	constexpr auto operator|(exti_exticr2_r other) const -> exti_exticr2_r { return static_cast<exti_exticr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr2_r> other) const -> opsy::utility::clear_set<exti_exticr2_r> {return opsy::utility::clear_set<exti_exticr2_r>(exti_exticr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI5 GPIO port selection These bits are written by software to select the source input for EXTI5 external interrupt. When EXTI_SECCFGR1.SEC5 is disabled, EXTI5 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC5 is enabled, EXTI5 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV5 is disabled, EXTI5 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV5 is enabled, EXTI5 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti5_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr exti5_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr2_r>() const {return opsy::utility::clear_set<exti_exticr2_r>(mask, *this);}
	constexpr auto operator|(exti_exticr2_r other) const -> exti_exticr2_r { return static_cast<exti_exticr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr2_r> other) const -> opsy::utility::clear_set<exti_exticr2_r> {return opsy::utility::clear_set<exti_exticr2_r>(exti_exticr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI6 GPIO port selection These bits are written by software to select the source input for EXTI6 external interrupt. When EXTI_SECCFGR1.SEC6 is disabled, EXTI6 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC6 is enabled, EXTI6 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV6 is disabled, EXTI6 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV6 is enabled, EXTI6 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti6_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti6_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr2_r>() const {return opsy::utility::clear_set<exti_exticr2_r>(mask, *this);}
	constexpr auto operator|(exti_exticr2_r other) const -> exti_exticr2_r { return static_cast<exti_exticr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr2_r> other) const -> opsy::utility::clear_set<exti_exticr2_r> {return opsy::utility::clear_set<exti_exticr2_r>(exti_exticr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI7 GPIO port selection These bits are written by software to select the source input for EXTI7 external interrupt. When EXTI_SECCFGR1.SEC7 is disabled, EXTI7 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC7 is enabled, EXTI7 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV7 is disabled, EXTI7 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV7 is enabled, EXTI7 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti7_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti7_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr2_r>() const {return opsy::utility::clear_set<exti_exticr2_r>(mask, *this);}
	constexpr auto operator|(exti_exticr2_r other) const -> exti_exticr2_r { return static_cast<exti_exticr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr2_r> other) const -> opsy::utility::clear_set<exti_exticr2_r> {return opsy::utility::clear_set<exti_exticr2_r>(exti_exticr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto exti4() const -> exti4_f {return exti4_f(static_cast<uint8_t>(value_ >> exti4_f::offset));}
	[[nodiscard]] constexpr auto exti5() const -> exti5_f {return exti5_f(static_cast<uint8_t>(value_ >> exti5_f::offset));}
	[[nodiscard]] constexpr auto exti6() const -> exti6_f {return exti6_f(static_cast<uint8_t>(value_ >> exti6_f::offset));}
	[[nodiscard]] constexpr auto exti7() const -> exti7_f {return exti7_f(static_cast<uint8_t>(value_ >> exti7_f::offset));}

	constexpr exti_exticr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_exticr2_r other) const -> exti_exticr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_exticr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI external interrupt selection register
 */
class exti_exticr3_r {
public:

/**
 * EXTI8 GPIO port selection These bits are written by software to select the source input for EXTI8 external interrupt. When EXTI_SECCFGR1.SEC8 is disabled, EXTI8 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC8 is enabled, EXTI8 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV8 is disabled, EXTI8 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV8 is enabled, EXTI8 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti8_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr exti8_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr3_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr3_r>() const {return opsy::utility::clear_set<exti_exticr3_r>(mask, *this);}
	constexpr auto operator|(exti_exticr3_r other) const -> exti_exticr3_r { return static_cast<exti_exticr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr3_r> other) const -> opsy::utility::clear_set<exti_exticr3_r> {return opsy::utility::clear_set<exti_exticr3_r>(exti_exticr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI9 GPIO port selection These bits are written by software to select the source input for EXTI9 external interrupt. When EXTI_SECCFGR1.SEC9 is disabled, EXTI9 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC9 is enabled, EXTI9 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV9 is disabled, EXTI9 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV9 is enabled, EXTI9 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti9_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr exti9_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr3_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr3_r>() const {return opsy::utility::clear_set<exti_exticr3_r>(mask, *this);}
	constexpr auto operator|(exti_exticr3_r other) const -> exti_exticr3_r { return static_cast<exti_exticr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr3_r> other) const -> opsy::utility::clear_set<exti_exticr3_r> {return opsy::utility::clear_set<exti_exticr3_r>(exti_exticr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI10 GPIO port selection These bits are written by software to select the source input for EXTI10 external interrupt. When EXTI_SECCFGR1.SEC10 is disabled, EXTI10 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC10 is enabled, EXTI10 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV10 is disabled, EXTI10 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV10 is enabled, EXTI10 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti10_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti10_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr3_r>() const {return opsy::utility::clear_set<exti_exticr3_r>(mask, *this);}
	constexpr auto operator|(exti_exticr3_r other) const -> exti_exticr3_r { return static_cast<exti_exticr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr3_r> other) const -> opsy::utility::clear_set<exti_exticr3_r> {return opsy::utility::clear_set<exti_exticr3_r>(exti_exticr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI11 GPIO port selection These bits are written by software to select the source input for EXTI11 external interrupt. When EXTI_SECCFGR1.SEC11 is disabled, EXTI11 can be accessed with non-secure and secure access. When EXTI_SECCFGR1.SEC11 is enabled, EXTI11 can only be accessed with secure access. Non-secure write is discarded and non-secure read returns 0. When EXTI_PRIVCFGR1.PRIV11 is disabled, EXTI11 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR1.PRIV11 is enabled, EXTI11 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti11_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti11_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr3_r>() const {return opsy::utility::clear_set<exti_exticr3_r>(mask, *this);}
	constexpr auto operator|(exti_exticr3_r other) const -> exti_exticr3_r { return static_cast<exti_exticr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr3_r> other) const -> opsy::utility::clear_set<exti_exticr3_r> {return opsy::utility::clear_set<exti_exticr3_r>(exti_exticr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto exti8() const -> exti8_f {return exti8_f(static_cast<uint8_t>(value_ >> exti8_f::offset));}
	[[nodiscard]] constexpr auto exti9() const -> exti9_f {return exti9_f(static_cast<uint8_t>(value_ >> exti9_f::offset));}
	[[nodiscard]] constexpr auto exti10() const -> exti10_f {return exti10_f(static_cast<uint8_t>(value_ >> exti10_f::offset));}
	[[nodiscard]] constexpr auto exti11() const -> exti11_f {return exti11_f(static_cast<uint8_t>(value_ >> exti11_f::offset));}

	constexpr exti_exticr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_exticr3_r other) const -> exti_exticr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_exticr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI external interrupt selection register 
 */
class exti_exticr4_r {
public:

/**
 * EXTI12 GPIO port selection These bits are written by software to select the source input for EXTI12 external interrupt. When EXTI_PRIVCFGR.PRIV12 is disabled, EXTI12 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIV12 is enabled, EXTI12 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti12_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr exti12_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr4_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr4_r>() const {return opsy::utility::clear_set<exti_exticr4_r>(mask, *this);}
	constexpr auto operator|(exti_exticr4_r other) const -> exti_exticr4_r { return static_cast<exti_exticr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr4_r> other) const -> opsy::utility::clear_set<exti_exticr4_r> {return opsy::utility::clear_set<exti_exticr4_r>(exti_exticr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI13 GPIO port selection These bits are written by software to select the source input for EXTI13 external interrupt. When EXTI_PRIVCFGR.PRIV13 is disabled, EXTI13 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIV13 is enabled, EXTI13 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti13_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr exti13_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr4_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr4_r>() const {return opsy::utility::clear_set<exti_exticr4_r>(mask, *this);}
	constexpr auto operator|(exti_exticr4_r other) const -> exti_exticr4_r { return static_cast<exti_exticr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr4_r> other) const -> opsy::utility::clear_set<exti_exticr4_r> {return opsy::utility::clear_set<exti_exticr4_r>(exti_exticr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI14 GPIO port selection These bits are written by software to select the source input for EXTI14 external interrupt. When EXTI_PRIVCFGR.PRIV14 is disabled, EXTI14 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIV14 is enabled, EXTI14 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti14_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti14_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr4_r>() const {return opsy::utility::clear_set<exti_exticr4_r>(mask, *this);}
	constexpr auto operator|(exti_exticr4_r other) const -> exti_exticr4_r { return static_cast<exti_exticr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr4_r> other) const -> opsy::utility::clear_set<exti_exticr4_r> {return opsy::utility::clear_set<exti_exticr4_r>(exti_exticr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * EXTI15 GPIO port selection These bits are written by software to select the source input for EXTI15 external interrupt. When EXTI_PRIVCFGR.PRIV15 is disabled, EXTI15 can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIV15 is enabled, EXTI15 can only be accessed with privileged access. Unprivileged write to this bit is discarded. Others: reserved
 */
class exti15_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr exti15_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator exti_exticr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<exti_exticr4_r>() const {return opsy::utility::clear_set<exti_exticr4_r>(mask, *this);}
	constexpr auto operator|(exti_exticr4_r other) const -> exti_exticr4_r { return static_cast<exti_exticr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_exticr4_r> other) const -> opsy::utility::clear_set<exti_exticr4_r> {return opsy::utility::clear_set<exti_exticr4_r>(exti_exticr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto exti12() const -> exti12_f {return exti12_f(static_cast<uint8_t>(value_ >> exti12_f::offset));}
	[[nodiscard]] constexpr auto exti13() const -> exti13_f {return exti13_f(static_cast<uint8_t>(value_ >> exti13_f::offset));}
	[[nodiscard]] constexpr auto exti14() const -> exti14_f {return exti14_f(static_cast<uint8_t>(value_ >> exti14_f::offset));}
	[[nodiscard]] constexpr auto exti15() const -> exti15_f {return exti15_f(static_cast<uint8_t>(value_ >> exti15_f::offset));}

	constexpr exti_exticr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_exticr4_r other) const -> exti_exticr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_exticr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI lock register
 */
class exti_lockr_r {
public:

/**
 * Global security and privilege configuration registers (EXTI_SECCFGR and EXTI_PRIVCFGR) lock This bit is written once after reset.
 */
class lock_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_lockr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_lockr_r>() const {return opsy::utility::clear_set<exti_lockr_r>(mask, *this);}
	constexpr auto operator|(exti_lockr_r other) const -> exti_lockr_r { return static_cast<exti_lockr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_lockr_r> other) const -> opsy::utility::clear_set<exti_lockr_r> {return opsy::utility::clear_set<exti_lockr_r>(exti_lockr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto lock() const -> lock_f {return lock_f((value_ & lock_f::mask) != 0);}

	constexpr exti_lockr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_lockr_r other) const -> exti_lockr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_lockr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI CPU wakeup with interrupt mask register
 */
class exti_imr1_r {
public:

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr1_r>() const {return opsy::utility::clear_set<exti_imr1_r>(mask, *this);}
	constexpr auto operator|(exti_imr1_r other) const -> exti_imr1_r { return static_cast<exti_imr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr1_r> other) const -> opsy::utility::clear_set<exti_imr1_r> {return opsy::utility::clear_set<exti_imr1_r>(exti_imr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto im0() const -> im0_f {return im0_f((value_ & im0_f::mask) != 0);}
	[[nodiscard]] constexpr auto im1() const -> im1_f {return im1_f((value_ & im1_f::mask) != 0);}
	[[nodiscard]] constexpr auto im2() const -> im2_f {return im2_f((value_ & im2_f::mask) != 0);}
	[[nodiscard]] constexpr auto im3() const -> im3_f {return im3_f((value_ & im3_f::mask) != 0);}
	[[nodiscard]] constexpr auto im4() const -> im4_f {return im4_f((value_ & im4_f::mask) != 0);}
	[[nodiscard]] constexpr auto im5() const -> im5_f {return im5_f((value_ & im5_f::mask) != 0);}
	[[nodiscard]] constexpr auto im6() const -> im6_f {return im6_f((value_ & im6_f::mask) != 0);}
	[[nodiscard]] constexpr auto im7() const -> im7_f {return im7_f((value_ & im7_f::mask) != 0);}
	[[nodiscard]] constexpr auto im8() const -> im8_f {return im8_f((value_ & im8_f::mask) != 0);}
	[[nodiscard]] constexpr auto im9() const -> im9_f {return im9_f((value_ & im9_f::mask) != 0);}
	[[nodiscard]] constexpr auto im10() const -> im10_f {return im10_f((value_ & im10_f::mask) != 0);}
	[[nodiscard]] constexpr auto im11() const -> im11_f {return im11_f((value_ & im11_f::mask) != 0);}
	[[nodiscard]] constexpr auto im12() const -> im12_f {return im12_f((value_ & im12_f::mask) != 0);}
	[[nodiscard]] constexpr auto im13() const -> im13_f {return im13_f((value_ & im13_f::mask) != 0);}
	[[nodiscard]] constexpr auto im14() const -> im14_f {return im14_f((value_ & im14_f::mask) != 0);}
	[[nodiscard]] constexpr auto im15() const -> im15_f {return im15_f((value_ & im15_f::mask) != 0);}
	[[nodiscard]] constexpr auto im16() const -> im16_f {return im16_f((value_ & im16_f::mask) != 0);}
	[[nodiscard]] constexpr auto im17() const -> im17_f {return im17_f((value_ & im17_f::mask) != 0);}
	[[nodiscard]] constexpr auto im18() const -> im18_f {return im18_f((value_ & im18_f::mask) != 0);}
	[[nodiscard]] constexpr auto im19() const -> im19_f {return im19_f((value_ & im19_f::mask) != 0);}
	[[nodiscard]] constexpr auto im20() const -> im20_f {return im20_f((value_ & im20_f::mask) != 0);}
	[[nodiscard]] constexpr auto im21() const -> im21_f {return im21_f((value_ & im21_f::mask) != 0);}
	[[nodiscard]] constexpr auto im22() const -> im22_f {return im22_f((value_ & im22_f::mask) != 0);}
	[[nodiscard]] constexpr auto im23() const -> im23_f {return im23_f((value_ & im23_f::mask) != 0);}
	[[nodiscard]] constexpr auto im24() const -> im24_f {return im24_f((value_ & im24_f::mask) != 0);}
	[[nodiscard]] constexpr auto im25() const -> im25_f {return im25_f((value_ & im25_f::mask) != 0);}
	[[nodiscard]] constexpr auto im26() const -> im26_f {return im26_f((value_ & im26_f::mask) != 0);}
	[[nodiscard]] constexpr auto im27() const -> im27_f {return im27_f((value_ & im27_f::mask) != 0);}
	[[nodiscard]] constexpr auto im28() const -> im28_f {return im28_f((value_ & im28_f::mask) != 0);}
	[[nodiscard]] constexpr auto im29() const -> im29_f {return im29_f((value_ & im29_f::mask) != 0);}
	[[nodiscard]] constexpr auto im30() const -> im30_f {return im30_f((value_ & im30_f::mask) != 0);}
	[[nodiscard]] constexpr auto im31() const -> im31_f {return im31_f((value_ & im31_f::mask) != 0);}

	constexpr exti_imr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_imr1_r other) const -> exti_imr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_imr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111111111111100000000000000000; // 4294836224 0xFFFE0000

private:
	uint32_t value_;
};

/**
 * EXTI CPU wakeup with event mask register
 */
class exti_emr1_r {
public:

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em2_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em3_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em4_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em4_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em5_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em5_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em6_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em6_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em7_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em7_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em8_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em8_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em9_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em9_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em10_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em10_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em11_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em11_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em12_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em12_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em13_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em13_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em14_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em14_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em15_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em15_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em16_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em16_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em17_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em17_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em18_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em18_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em19_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em19_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em20_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em20_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em21_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em21_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em22_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em22_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em23_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em23_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em24_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em24_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em25_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em25_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em26_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em26_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em27_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em27_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em28_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em28_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em29_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em29_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em30_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em30_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em31_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em31_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr1_r>() const {return opsy::utility::clear_set<exti_emr1_r>(mask, *this);}
	constexpr auto operator|(exti_emr1_r other) const -> exti_emr1_r { return static_cast<exti_emr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr1_r> other) const -> opsy::utility::clear_set<exti_emr1_r> {return opsy::utility::clear_set<exti_emr1_r>(exti_emr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto em0() const -> em0_f {return em0_f((value_ & em0_f::mask) != 0);}
	[[nodiscard]] constexpr auto em1() const -> em1_f {return em1_f((value_ & em1_f::mask) != 0);}
	[[nodiscard]] constexpr auto em2() const -> em2_f {return em2_f((value_ & em2_f::mask) != 0);}
	[[nodiscard]] constexpr auto em3() const -> em3_f {return em3_f((value_ & em3_f::mask) != 0);}
	[[nodiscard]] constexpr auto em4() const -> em4_f {return em4_f((value_ & em4_f::mask) != 0);}
	[[nodiscard]] constexpr auto em5() const -> em5_f {return em5_f((value_ & em5_f::mask) != 0);}
	[[nodiscard]] constexpr auto em6() const -> em6_f {return em6_f((value_ & em6_f::mask) != 0);}
	[[nodiscard]] constexpr auto em7() const -> em7_f {return em7_f((value_ & em7_f::mask) != 0);}
	[[nodiscard]] constexpr auto em8() const -> em8_f {return em8_f((value_ & em8_f::mask) != 0);}
	[[nodiscard]] constexpr auto em9() const -> em9_f {return em9_f((value_ & em9_f::mask) != 0);}
	[[nodiscard]] constexpr auto em10() const -> em10_f {return em10_f((value_ & em10_f::mask) != 0);}
	[[nodiscard]] constexpr auto em11() const -> em11_f {return em11_f((value_ & em11_f::mask) != 0);}
	[[nodiscard]] constexpr auto em12() const -> em12_f {return em12_f((value_ & em12_f::mask) != 0);}
	[[nodiscard]] constexpr auto em13() const -> em13_f {return em13_f((value_ & em13_f::mask) != 0);}
	[[nodiscard]] constexpr auto em14() const -> em14_f {return em14_f((value_ & em14_f::mask) != 0);}
	[[nodiscard]] constexpr auto em15() const -> em15_f {return em15_f((value_ & em15_f::mask) != 0);}
	[[nodiscard]] constexpr auto em16() const -> em16_f {return em16_f((value_ & em16_f::mask) != 0);}
	[[nodiscard]] constexpr auto em17() const -> em17_f {return em17_f((value_ & em17_f::mask) != 0);}
	[[nodiscard]] constexpr auto em18() const -> em18_f {return em18_f((value_ & em18_f::mask) != 0);}
	[[nodiscard]] constexpr auto em19() const -> em19_f {return em19_f((value_ & em19_f::mask) != 0);}
	[[nodiscard]] constexpr auto em20() const -> em20_f {return em20_f((value_ & em20_f::mask) != 0);}
	[[nodiscard]] constexpr auto em21() const -> em21_f {return em21_f((value_ & em21_f::mask) != 0);}
	[[nodiscard]] constexpr auto em22() const -> em22_f {return em22_f((value_ & em22_f::mask) != 0);}
	[[nodiscard]] constexpr auto em23() const -> em23_f {return em23_f((value_ & em23_f::mask) != 0);}
	[[nodiscard]] constexpr auto em24() const -> em24_f {return em24_f((value_ & em24_f::mask) != 0);}
	[[nodiscard]] constexpr auto em25() const -> em25_f {return em25_f((value_ & em25_f::mask) != 0);}
	[[nodiscard]] constexpr auto em26() const -> em26_f {return em26_f((value_ & em26_f::mask) != 0);}
	[[nodiscard]] constexpr auto em27() const -> em27_f {return em27_f((value_ & em27_f::mask) != 0);}
	[[nodiscard]] constexpr auto em28() const -> em28_f {return em28_f((value_ & em28_f::mask) != 0);}
	[[nodiscard]] constexpr auto em29() const -> em29_f {return em29_f((value_ & em29_f::mask) != 0);}
	[[nodiscard]] constexpr auto em30() const -> em30_f {return em30_f((value_ & em30_f::mask) != 0);}
	[[nodiscard]] constexpr auto em31() const -> em31_f {return em31_f((value_ & em31_f::mask) != 0);}

	constexpr exti_emr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_emr1_r other) const -> exti_emr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_emr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * EXTI CPU wakeup with interrupt mask register 2
 */
class exti_imr2_r {
public:

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im32_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im33_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im33_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im34_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im34_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im35_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im35_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im36_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im36_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im37_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im37_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im38_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im38_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im39_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr im39_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im40_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im40_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im41_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im41_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im42_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im42_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im43_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im43_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im44_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im44_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im45_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im45_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im47_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr im47_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im48_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im48_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im49_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im49_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im51_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im51_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im52_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im52_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im54_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im54_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im55_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im55_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im56_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im56_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with interrupt mask on event input x When EXTI_SECCFGR.SECx is disabled, IMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, IMx can only be accessed with secure access. Non-secure write to this bit is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, IMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, IMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class im57_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr im57_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_imr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_imr2_r>() const {return opsy::utility::clear_set<exti_imr2_r>(mask, *this);}
	constexpr auto operator|(exti_imr2_r other) const -> exti_imr2_r { return static_cast<exti_imr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_imr2_r> other) const -> opsy::utility::clear_set<exti_imr2_r> {return opsy::utility::clear_set<exti_imr2_r>(exti_imr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto im32() const -> im32_f {return im32_f((value_ & im32_f::mask) != 0);}
	[[nodiscard]] constexpr auto im33() const -> im33_f {return im33_f((value_ & im33_f::mask) != 0);}
	[[nodiscard]] constexpr auto im34() const -> im34_f {return im34_f((value_ & im34_f::mask) != 0);}
	[[nodiscard]] constexpr auto im35() const -> im35_f {return im35_f((value_ & im35_f::mask) != 0);}
	[[nodiscard]] constexpr auto im36() const -> im36_f {return im36_f((value_ & im36_f::mask) != 0);}
	[[nodiscard]] constexpr auto im37() const -> im37_f {return im37_f((value_ & im37_f::mask) != 0);}
	[[nodiscard]] constexpr auto im38() const -> im38_f {return im38_f((value_ & im38_f::mask) != 0);}
	[[nodiscard]] constexpr auto im39() const -> im39_f {return im39_f((value_ & im39_f::mask) != 0);}
	[[nodiscard]] constexpr auto im40() const -> im40_f {return im40_f((value_ & im40_f::mask) != 0);}
	[[nodiscard]] constexpr auto im41() const -> im41_f {return im41_f((value_ & im41_f::mask) != 0);}
	[[nodiscard]] constexpr auto im42() const -> im42_f {return im42_f((value_ & im42_f::mask) != 0);}
	[[nodiscard]] constexpr auto im43() const -> im43_f {return im43_f((value_ & im43_f::mask) != 0);}
	[[nodiscard]] constexpr auto im44() const -> im44_f {return im44_f((value_ & im44_f::mask) != 0);}
	[[nodiscard]] constexpr auto im45() const -> im45_f {return im45_f((value_ & im45_f::mask) != 0);}
	[[nodiscard]] constexpr auto im46() const -> im46_f {return im46_f((value_ & im46_f::mask) != 0);}
	[[nodiscard]] constexpr auto im47() const -> im47_f {return im47_f((value_ & im47_f::mask) != 0);}
	[[nodiscard]] constexpr auto im48() const -> im48_f {return im48_f((value_ & im48_f::mask) != 0);}
	[[nodiscard]] constexpr auto im49() const -> im49_f {return im49_f((value_ & im49_f::mask) != 0);}
	[[nodiscard]] constexpr auto im50() const -> im50_f {return im50_f((value_ & im50_f::mask) != 0);}
	[[nodiscard]] constexpr auto im51() const -> im51_f {return im51_f((value_ & im51_f::mask) != 0);}
	[[nodiscard]] constexpr auto im52() const -> im52_f {return im52_f((value_ & im52_f::mask) != 0);}
	[[nodiscard]] constexpr auto im53() const -> im53_f {return im53_f((value_ & im53_f::mask) != 0);}
	[[nodiscard]] constexpr auto im54() const -> im54_f {return im54_f((value_ & im54_f::mask) != 0);}
	[[nodiscard]] constexpr auto im55() const -> im55_f {return im55_f((value_ & im55_f::mask) != 0);}
	[[nodiscard]] constexpr auto im56() const -> im56_f {return im56_f((value_ & im56_f::mask) != 0);}
	[[nodiscard]] constexpr auto im57() const -> im57_f {return im57_f((value_ & im57_f::mask) != 0);}

	constexpr exti_imr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_imr2_r other) const -> exti_imr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_imr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11110110111011111111111111; // 64733183 0x3DBBFFF

private:
	uint32_t value_;
};

/**
 * EXTI CPU wakeup with event mask register 2
 */
class exti_emr2_r {
public:

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em32_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em32_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em33_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em33_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em34_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em34_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em35_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em35_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em36_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em36_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em37_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em37_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em38_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em38_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em39_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr em39_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em40_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em40_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em41_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em41_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em42_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em42_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em43_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em43_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em44_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em44_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em45_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em45_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em46_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em46_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em47_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr em47_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em48_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em48_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em49_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em49_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em50_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em50_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em51_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em51_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em52_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em52_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em53_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em53_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em54_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em54_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em55_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em55_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em56_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em56_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CPU wakeup with event generation mask on event input x When EXTI_SECCFGR.SECx is disabled, EMx can be accessed with non-secure and secure access. When EXTI_SECCFGR.SECx is enabled, EMx can only be accessed with secure access. Non-secure write to this bit x is discarded and non-secure read returns 0. When EXTI_PRIVCFGR.PRIVx is disabled, EMx can be accessed with privileged and unprivileged access. When EXTI_PRIVCFGR.PRIVx is enabled, EMx can only be accessed with privileged access. Unprivileged write to this bit is discarded.
 */
class em57_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr em57_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator exti_emr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<exti_emr2_r>() const {return opsy::utility::clear_set<exti_emr2_r>(mask, *this);}
	constexpr auto operator|(exti_emr2_r other) const -> exti_emr2_r { return static_cast<exti_emr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<exti_emr2_r> other) const -> opsy::utility::clear_set<exti_emr2_r> {return opsy::utility::clear_set<exti_emr2_r>(exti_emr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto em32() const -> em32_f {return em32_f((value_ & em32_f::mask) != 0);}
	[[nodiscard]] constexpr auto em33() const -> em33_f {return em33_f((value_ & em33_f::mask) != 0);}
	[[nodiscard]] constexpr auto em34() const -> em34_f {return em34_f((value_ & em34_f::mask) != 0);}
	[[nodiscard]] constexpr auto em35() const -> em35_f {return em35_f((value_ & em35_f::mask) != 0);}
	[[nodiscard]] constexpr auto em36() const -> em36_f {return em36_f((value_ & em36_f::mask) != 0);}
	[[nodiscard]] constexpr auto em37() const -> em37_f {return em37_f((value_ & em37_f::mask) != 0);}
	[[nodiscard]] constexpr auto em38() const -> em38_f {return em38_f((value_ & em38_f::mask) != 0);}
	[[nodiscard]] constexpr auto em39() const -> em39_f {return em39_f((value_ & em39_f::mask) != 0);}
	[[nodiscard]] constexpr auto em40() const -> em40_f {return em40_f((value_ & em40_f::mask) != 0);}
	[[nodiscard]] constexpr auto em41() const -> em41_f {return em41_f((value_ & em41_f::mask) != 0);}
	[[nodiscard]] constexpr auto em42() const -> em42_f {return em42_f((value_ & em42_f::mask) != 0);}
	[[nodiscard]] constexpr auto em43() const -> em43_f {return em43_f((value_ & em43_f::mask) != 0);}
	[[nodiscard]] constexpr auto em44() const -> em44_f {return em44_f((value_ & em44_f::mask) != 0);}
	[[nodiscard]] constexpr auto em45() const -> em45_f {return em45_f((value_ & em45_f::mask) != 0);}
	[[nodiscard]] constexpr auto em46() const -> em46_f {return em46_f((value_ & em46_f::mask) != 0);}
	[[nodiscard]] constexpr auto em47() const -> em47_f {return em47_f((value_ & em47_f::mask) != 0);}
	[[nodiscard]] constexpr auto em48() const -> em48_f {return em48_f((value_ & em48_f::mask) != 0);}
	[[nodiscard]] constexpr auto em49() const -> em49_f {return em49_f((value_ & em49_f::mask) != 0);}
	[[nodiscard]] constexpr auto em50() const -> em50_f {return em50_f((value_ & em50_f::mask) != 0);}
	[[nodiscard]] constexpr auto em51() const -> em51_f {return em51_f((value_ & em51_f::mask) != 0);}
	[[nodiscard]] constexpr auto em52() const -> em52_f {return em52_f((value_ & em52_f::mask) != 0);}
	[[nodiscard]] constexpr auto em53() const -> em53_f {return em53_f((value_ & em53_f::mask) != 0);}
	[[nodiscard]] constexpr auto em54() const -> em54_f {return em54_f((value_ & em54_f::mask) != 0);}
	[[nodiscard]] constexpr auto em55() const -> em55_f {return em55_f((value_ & em55_f::mask) != 0);}
	[[nodiscard]] constexpr auto em56() const -> em56_f {return em56_f((value_ & em56_f::mask) != 0);}
	[[nodiscard]] constexpr auto em57() const -> em57_f {return em57_f((value_ & em57_f::mask) != 0);}

	constexpr exti_emr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(exti_emr2_r other) const -> exti_emr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> exti_emr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,exti_rtsr1_r> exti_rtsr1;
	opsy::utility::memory<uint32_t,exti_ftsr1_r> exti_ftsr1;
	opsy::utility::memory<uint32_t,exti_swier1_r> exti_swier1;
	opsy::utility::memory<uint32_t,exti_rpr1_r> exti_rpr1;
	opsy::utility::memory<uint32_t,exti_fpr1_r> exti_fpr1;
	opsy::utility::memory<uint32_t,exti_seccfgr1_r> exti_seccfgr1;
	opsy::utility::memory<uint32_t,exti_privcfgr1_r> exti_privcfgr1;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,exti_rtsr2_r> exti_rtsr2;
	opsy::utility::memory<uint32_t,exti_ftsr2_r> exti_ftsr2;
	opsy::utility::memory<uint32_t,exti_swier2_r> exti_swier2;
	opsy::utility::memory<uint32_t,exti_rpr2_r> exti_rpr2;
	opsy::utility::memory<uint32_t,exti_fpr2_r> exti_fpr2;
	opsy::utility::memory<uint32_t,exti_seccfgr2_r> exti_seccfgr2;
	opsy::utility::memory<uint32_t,exti_privcfgr2_r> exti_privcfgr2;
	opsy::utility::padding<36> _p1;
	opsy::utility::memory<uint32_t,exti_exticr1_r> exti_exticr1;
	opsy::utility::memory<uint32_t,exti_exticr2_r> exti_exticr2;
	opsy::utility::memory<uint32_t,exti_exticr3_r> exti_exticr3;
	opsy::utility::memory<uint32_t,exti_exticr4_r> exti_exticr4;
	opsy::utility::memory<uint32_t,exti_lockr_r> exti_lockr;
	opsy::utility::padding<12> _p2;
	opsy::utility::memory<uint32_t,exti_imr1_r> exti_imr1;
	opsy::utility::memory<uint32_t,exti_emr1_r> exti_emr1;
	opsy::utility::padding<8> _p3;
	opsy::utility::memory<uint32_t,exti_imr2_r> exti_imr2;
	opsy::utility::memory<uint32_t,exti_emr2_r> exti_emr2;
};

static_assert(std::is_standard_layout_v<exti_p>);
static_assert(offsetof(exti_p, exti_rtsr1) == 0);
static_assert(offsetof(exti_p, exti_ftsr1) == 4);
static_assert(offsetof(exti_p, exti_swier1) == 8);
static_assert(offsetof(exti_p, exti_rpr1) == 12);
static_assert(offsetof(exti_p, exti_fpr1) == 16);
static_assert(offsetof(exti_p, exti_seccfgr1) == 20);
static_assert(offsetof(exti_p, exti_privcfgr1) == 24);
static_assert(offsetof(exti_p, exti_rtsr2) == 32);
static_assert(offsetof(exti_p, exti_ftsr2) == 36);
static_assert(offsetof(exti_p, exti_swier2) == 40);
static_assert(offsetof(exti_p, exti_rpr2) == 44);
static_assert(offsetof(exti_p, exti_fpr2) == 48);
static_assert(offsetof(exti_p, exti_seccfgr2) == 52);
static_assert(offsetof(exti_p, exti_privcfgr2) == 56);
static_assert(offsetof(exti_p, exti_exticr1) == 96);
static_assert(offsetof(exti_p, exti_exticr2) == 100);
static_assert(offsetof(exti_p, exti_exticr3) == 104);
static_assert(offsetof(exti_p, exti_exticr4) == 108);
static_assert(offsetof(exti_p, exti_lockr) == 112);
static_assert(offsetof(exti_p, exti_imr1) == 128);
static_assert(offsetof(exti_p, exti_emr1) == 132);
static_assert(offsetof(exti_p, exti_imr2) == 144);
static_assert(offsetof(exti_p, exti_emr2) == 148);

inline exti_p& exti = *reinterpret_cast<exti_p*>(0x44022000);
inline exti_p& sec_exti = *reinterpret_cast<exti_p*>(0x54022000);

} // STM32H563

