#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * TAMP register block
 */
class tamp_p {
public:

/**
 * TAMP control register 1
 */
class tamp_cr1_r {
public:

/**
 * Tamper detection on TAMP_IN1 enable
 */
class tamp1e_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN2 enableless thansup>(1)less than/sup>
 */
class tamp2e_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN3 enableless thansup>(1)less than/sup>
 */
class tamp3e_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN4 enableless thansup>(1)less than/sup>
 */
class tamp4e_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN5 enableless thansup>(1)less than/sup>
 */
class tamp5e_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN6 enableless thansup>(1)less than/sup>
 */
class tamp6e_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN7 enableless thansup>(1)less than/sup>
 */
class tamp7e_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper detection on TAMP_IN8 enableless thansup>(1)less than/sup>
 */
class tamp8e_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 1 enable
 */
class itamp1e_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp1e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 2 enable
 */
class itamp2e_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp2e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 3 enable
 */
class itamp3e_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp3e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 4 enable
 */
class itamp4e_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp4e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 5 enable
 */
class itamp5e_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp5e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 6 enable
 */
class itamp6e_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp6e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 7 enable
 */
class itamp7e_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp7e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 8 enable
 */
class itamp8e_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp8e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 9 enable
 */
class itamp9e_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp9e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 11 enable
 */
class itamp11e_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp11e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 12 enable
 */
class itamp12e_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp12e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 13 enable
 */
class itamp13e_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp13e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 15 enable
 */
class itamp15e_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp15e_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr1_r>() const {return opsy::utility::clear_set<tamp_cr1_r>(mask, *this);}
	constexpr auto operator|(tamp_cr1_r other) const -> tamp_cr1_r { return static_cast<tamp_cr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr1_r> other) const -> opsy::utility::clear_set<tamp_cr1_r> {return opsy::utility::clear_set<tamp_cr1_r>(tamp_cr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1e() const -> tamp1e_f {return tamp1e_f((value_ & tamp1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2e() const -> tamp2e_f {return tamp2e_f((value_ & tamp2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3e() const -> tamp3e_f {return tamp3e_f((value_ & tamp3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4e() const -> tamp4e_f {return tamp4e_f((value_ & tamp4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5e() const -> tamp5e_f {return tamp5e_f((value_ & tamp5e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6e() const -> tamp6e_f {return tamp6e_f((value_ & tamp6e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7e() const -> tamp7e_f {return tamp7e_f((value_ & tamp7e_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8e() const -> tamp8e_f {return tamp8e_f((value_ & tamp8e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp1e() const -> itamp1e_f {return itamp1e_f((value_ & itamp1e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp2e() const -> itamp2e_f {return itamp2e_f((value_ & itamp2e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp3e() const -> itamp3e_f {return itamp3e_f((value_ & itamp3e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp4e() const -> itamp4e_f {return itamp4e_f((value_ & itamp4e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp5e() const -> itamp5e_f {return itamp5e_f((value_ & itamp5e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp6e() const -> itamp6e_f {return itamp6e_f((value_ & itamp6e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp7e() const -> itamp7e_f {return itamp7e_f((value_ & itamp7e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp8e() const -> itamp8e_f {return itamp8e_f((value_ & itamp8e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp9e() const -> itamp9e_f {return itamp9e_f((value_ & itamp9e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp11e() const -> itamp11e_f {return itamp11e_f((value_ & itamp11e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp12e() const -> itamp12e_f {return itamp12e_f((value_ & itamp12e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp13e() const -> itamp13e_f {return itamp13e_f((value_ & itamp13e_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp15e() const -> itamp15e_f {return itamp15e_f((value_ & itamp15e_f::mask) != 0);}

	constexpr tamp_cr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_cr1_r other) const -> tamp_cr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_cr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP control register 2
 */
class tamp_cr2_r {
public:

/**
 * Tamper 1 potential mode
 */
class tamp1pom_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 2 potential mode
 */
class tamp2pom_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 3 potential mode
 */
class tamp3pom_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 4 potential mode
 */
class tamp4pom_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 5 potential mode
 */
class tamp5pom_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 6 potential mode
 */
class tamp6pom_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 7 potential mode
 */
class tamp7pom_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 8 potential mode
 */
class tamp8pom_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 1 mask 
 */
class tamp1msk_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp1msk_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 2 mask 
 */
class tamp2msk_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp2msk_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 3 mask 
 */
class tamp3msk_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp3msk_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup registers and device secretsless thansup>(1)less than/sup> access blocked
 */
class bkblock_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkblock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup registers and device secretsless thansup>(1)less than/sup> erase 
 */
class bkerase_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkerase_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 1 input 
 */
class tamp1trg_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp1trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 2 input 
 */
class tamp2trg_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp2trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 3 input 
 */
class tamp3trg_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp3trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 4 input (active mode disabled) 
 */
class tamp4trg_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp4trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 5 input (active mode disabled) 
 */
class tamp5trg_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp5trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 6 input (active mode disabled) 
 */
class tamp6trg_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp6trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 7 input (active mode disabled) 
 */
class tamp7trg_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp7trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active level for tamper 8 input (active mode disabled) 
 */
class tamp8trg_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamp8trg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr2_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr2_r>() const {return opsy::utility::clear_set<tamp_cr2_r>(mask, *this);}
	constexpr auto operator|(tamp_cr2_r other) const -> tamp_cr2_r { return static_cast<tamp_cr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr2_r> other) const -> opsy::utility::clear_set<tamp_cr2_r> {return opsy::utility::clear_set<tamp_cr2_r>(tamp_cr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1pom() const -> tamp1pom_f {return tamp1pom_f((value_ & tamp1pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2pom() const -> tamp2pom_f {return tamp2pom_f((value_ & tamp2pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3pom() const -> tamp3pom_f {return tamp3pom_f((value_ & tamp3pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4pom() const -> tamp4pom_f {return tamp4pom_f((value_ & tamp4pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5pom() const -> tamp5pom_f {return tamp5pom_f((value_ & tamp5pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6pom() const -> tamp6pom_f {return tamp6pom_f((value_ & tamp6pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7pom() const -> tamp7pom_f {return tamp7pom_f((value_ & tamp7pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8pom() const -> tamp8pom_f {return tamp8pom_f((value_ & tamp8pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp1msk() const -> tamp1msk_f {return tamp1msk_f((value_ & tamp1msk_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2msk() const -> tamp2msk_f {return tamp2msk_f((value_ & tamp2msk_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3msk() const -> tamp3msk_f {return tamp3msk_f((value_ & tamp3msk_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkblock() const -> bkblock_f {return bkblock_f((value_ & bkblock_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkerase() const -> bkerase_f {return bkerase_f((value_ & bkerase_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp1trg() const -> tamp1trg_f {return tamp1trg_f((value_ & tamp1trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2trg() const -> tamp2trg_f {return tamp2trg_f((value_ & tamp2trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3trg() const -> tamp3trg_f {return tamp3trg_f((value_ & tamp3trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4trg() const -> tamp4trg_f {return tamp4trg_f((value_ & tamp4trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5trg() const -> tamp5trg_f {return tamp5trg_f((value_ & tamp5trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6trg() const -> tamp6trg_f {return tamp6trg_f((value_ & tamp6trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7trg() const -> tamp7trg_f {return tamp7trg_f((value_ & tamp7trg_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8trg() const -> tamp8trg_f {return tamp8trg_f((value_ & tamp8trg_f::mask) != 0);}

	constexpr tamp_cr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_cr2_r other) const -> tamp_cr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_cr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP control register 3
 */
class tamp_cr3_r {
public:

/**
 * Internal tamper 1 potential mode
 */
class itamp1pom_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp1pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 2 potential mode
 */
class itamp2pom_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp2pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 3 potential mode
 */
class itamp3pom_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp3pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 4 potential mode
 */
class itamp4pom_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp4pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 5 potential mode
 */
class itamp5pom_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp5pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 6 potential mode
 */
class itamp6pom_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp6pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 7 potential mode
 */
class itamp7pom_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp7pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 8 potential mode
 */
class itamp8pom_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr itamp8pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 9 potential mode
 */
class itamp9pom_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr itamp9pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 11 potential mode
 */
class itamp11pom_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr itamp11pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 12 potential mode
 */
class itamp12pom_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr itamp12pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 13 potential mode
 */
class itamp13pom_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr itamp13pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 15 potential mode
 */
class itamp15pom_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr itamp15pom_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_cr3_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_cr3_r>() const {return opsy::utility::clear_set<tamp_cr3_r>(mask, *this);}
	constexpr auto operator|(tamp_cr3_r other) const -> tamp_cr3_r { return static_cast<tamp_cr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_cr3_r> other) const -> opsy::utility::clear_set<tamp_cr3_r> {return opsy::utility::clear_set<tamp_cr3_r>(tamp_cr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto itamp1pom() const -> itamp1pom_f {return itamp1pom_f((value_ & itamp1pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp2pom() const -> itamp2pom_f {return itamp2pom_f((value_ & itamp2pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp3pom() const -> itamp3pom_f {return itamp3pom_f((value_ & itamp3pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp4pom() const -> itamp4pom_f {return itamp4pom_f((value_ & itamp4pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp5pom() const -> itamp5pom_f {return itamp5pom_f((value_ & itamp5pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp6pom() const -> itamp6pom_f {return itamp6pom_f((value_ & itamp6pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp7pom() const -> itamp7pom_f {return itamp7pom_f((value_ & itamp7pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp8pom() const -> itamp8pom_f {return itamp8pom_f((value_ & itamp8pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp9pom() const -> itamp9pom_f {return itamp9pom_f((value_ & itamp9pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp11pom() const -> itamp11pom_f {return itamp11pom_f((value_ & itamp11pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp12pom() const -> itamp12pom_f {return itamp12pom_f((value_ & itamp12pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp13pom() const -> itamp13pom_f {return itamp13pom_f((value_ & itamp13pom_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp15pom() const -> itamp15pom_f {return itamp15pom_f((value_ & itamp15pom_f::mask) != 0);}

	constexpr tamp_cr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_cr3_r other) const -> tamp_cr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_cr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP filter control register
 */
class tamp_fltcr_r {
public:

/**
 * Tamper sampling frequency 
 */
class tampfreq_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tampfreq_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_fltcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_fltcr_r>() const {return opsy::utility::clear_set<tamp_fltcr_r>(mask, *this);}
	constexpr auto operator|(tamp_fltcr_r other) const -> tamp_fltcr_r { return static_cast<tamp_fltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_fltcr_r> other) const -> opsy::utility::clear_set<tamp_fltcr_r> {return opsy::utility::clear_set<tamp_fltcr_r>(tamp_fltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * TAMP_INx filter count 
 */
class tampflt_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tampflt_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_fltcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_fltcr_r>() const {return opsy::utility::clear_set<tamp_fltcr_r>(mask, *this);}
	constexpr auto operator|(tamp_fltcr_r other) const -> tamp_fltcr_r { return static_cast<tamp_fltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_fltcr_r> other) const -> opsy::utility::clear_set<tamp_fltcr_r> {return opsy::utility::clear_set<tamp_fltcr_r>(tamp_fltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * TAMP_INx precharge duration 
 */
class tampprch_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tampprch_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_fltcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_fltcr_r>() const {return opsy::utility::clear_set<tamp_fltcr_r>(mask, *this);}
	constexpr auto operator|(tamp_fltcr_r other) const -> tamp_fltcr_r { return static_cast<tamp_fltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_fltcr_r> other) const -> opsy::utility::clear_set<tamp_fltcr_r> {return opsy::utility::clear_set<tamp_fltcr_r>(tamp_fltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * TAMP_INx pull-up disable 
 */
class tamppudis_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamppudis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_fltcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_fltcr_r>() const {return opsy::utility::clear_set<tamp_fltcr_r>(mask, *this);}
	constexpr auto operator|(tamp_fltcr_r other) const -> tamp_fltcr_r { return static_cast<tamp_fltcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_fltcr_r> other) const -> opsy::utility::clear_set<tamp_fltcr_r> {return opsy::utility::clear_set<tamp_fltcr_r>(tamp_fltcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tampfreq() const -> tampfreq_f {return tampfreq_f(static_cast<uint8_t>(value_ >> tampfreq_f::offset));}
	[[nodiscard]] constexpr auto tampflt() const -> tampflt_f {return tampflt_f(static_cast<uint8_t>(value_ >> tampflt_f::offset));}
	[[nodiscard]] constexpr auto tampprch() const -> tampprch_f {return tampprch_f(static_cast<uint8_t>(value_ >> tampprch_f::offset));}
	[[nodiscard]] constexpr auto tamppudis() const -> tamppudis_f {return tamppudis_f((value_ & tamppudis_f::mask) != 0);}

	constexpr tamp_fltcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_fltcr_r other) const -> tamp_fltcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_fltcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP active tamper control register 1
 */
class tamp_atcr1_r {
public:

/**
 * Tamper 1 active mode
 */
class tamp1am_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 2 active mode
 */
class tamp2am_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 3 active mode
 */
class tamp3am_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 4 active mode
 */
class tamp4am_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 5 active mode
 */
class tamp5am_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 6 active mode
 */
class tamp6am_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 7 active mode
 */
class tamp7am_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 8 active mode
 */
class tamp8am_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8am_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active tamper shared output 1 selection 
 */
class atosel1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 2 selection 
 */
class atosel2_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 3 selection 
 */
class atosel3_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 4 selection 
 */
class atosel4_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper RTC asynchronous prescaler clock selection 
 */
class atcksel_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atcksel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper output change period 
 */
class atper_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atper_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper output sharing
 */
class atoshare_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr atoshare_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active tamper filter enable
 */
class flten_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr flten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_atcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_atcr1_r>() const {return opsy::utility::clear_set<tamp_atcr1_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr1_r other) const -> tamp_atcr1_r { return static_cast<tamp_atcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr1_r> other) const -> opsy::utility::clear_set<tamp_atcr1_r> {return opsy::utility::clear_set<tamp_atcr1_r>(tamp_atcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1am() const -> tamp1am_f {return tamp1am_f((value_ & tamp1am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2am() const -> tamp2am_f {return tamp2am_f((value_ & tamp2am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3am() const -> tamp3am_f {return tamp3am_f((value_ & tamp3am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4am() const -> tamp4am_f {return tamp4am_f((value_ & tamp4am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5am() const -> tamp5am_f {return tamp5am_f((value_ & tamp5am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6am() const -> tamp6am_f {return tamp6am_f((value_ & tamp6am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7am() const -> tamp7am_f {return tamp7am_f((value_ & tamp7am_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8am() const -> tamp8am_f {return tamp8am_f((value_ & tamp8am_f::mask) != 0);}
	[[nodiscard]] constexpr auto atosel1() const -> atosel1_f {return atosel1_f(static_cast<uint8_t>(value_ >> atosel1_f::offset));}
	[[nodiscard]] constexpr auto atosel2() const -> atosel2_f {return atosel2_f(static_cast<uint8_t>(value_ >> atosel2_f::offset));}
	[[nodiscard]] constexpr auto atosel3() const -> atosel3_f {return atosel3_f(static_cast<uint8_t>(value_ >> atosel3_f::offset));}
	[[nodiscard]] constexpr auto atosel4() const -> atosel4_f {return atosel4_f(static_cast<uint8_t>(value_ >> atosel4_f::offset));}
	[[nodiscard]] constexpr auto atcksel() const -> atcksel_f {return atcksel_f(static_cast<uint8_t>(value_ >> atcksel_f::offset));}
	[[nodiscard]] constexpr auto atper() const -> atper_f {return atper_f(static_cast<uint8_t>(value_ >> atper_f::offset));}
	[[nodiscard]] constexpr auto atoshare() const -> atoshare_f {return atoshare_f((value_ & atoshare_f::mask) != 0);}
	[[nodiscard]] constexpr auto flten() const -> flten_f {return flten_f((value_ & flten_f::mask) != 0);}

	constexpr tamp_atcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_atcr1_r other) const -> tamp_atcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_atcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1110000000000000000; // 458752 0x70000

private:
	uint32_t value_;
};

/**
 * TAMP active tamper seed register
 */
class tamp_atseedr_r {
public:

/**
 * Pseudo-random generator seed value 
 */
class seed_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr seed_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tamp_atseedr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atseedr_r>() const {return opsy::utility::clear_set<tamp_atseedr_r>(mask, *this);}
	constexpr auto operator|(tamp_atseedr_r other) const -> tamp_atseedr_r { return static_cast<tamp_atseedr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atseedr_r> other) const -> opsy::utility::clear_set<tamp_atseedr_r> {return opsy::utility::clear_set<tamp_atseedr_r>(tamp_atseedr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto seed() const -> seed_f {return seed_f(static_cast<uint32_t>(value_ >> seed_f::offset));}

	constexpr tamp_atseedr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_atseedr_r other) const -> tamp_atseedr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_atseedr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP active tamper output register
 */
class tamp_ator_r {
public:

/**
 * Pseudo-random generator value 
 */
class prng_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prng_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_ator_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_ator_r>() const {return opsy::utility::clear_set<tamp_ator_r>(mask, *this);}
	constexpr auto operator|(tamp_ator_r other) const -> tamp_ator_r { return static_cast<tamp_ator_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ator_r> other) const -> opsy::utility::clear_set<tamp_ator_r> {return opsy::utility::clear_set<tamp_ator_r>(tamp_ator_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Seed running flag 
 */
class seedf_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr seedf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ator_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ator_r>() const {return opsy::utility::clear_set<tamp_ator_r>(mask, *this);}
	constexpr auto operator|(tamp_ator_r other) const -> tamp_ator_r { return static_cast<tamp_ator_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ator_r> other) const -> opsy::utility::clear_set<tamp_ator_r> {return opsy::utility::clear_set<tamp_ator_r>(tamp_ator_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Active tamper initialization status 
 */
class inits_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr inits_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ator_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ator_r>() const {return opsy::utility::clear_set<tamp_ator_r>(mask, *this);}
	constexpr auto operator|(tamp_ator_r other) const -> tamp_ator_r { return static_cast<tamp_ator_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ator_r> other) const -> opsy::utility::clear_set<tamp_ator_r> {return opsy::utility::clear_set<tamp_ator_r>(tamp_ator_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto prng() const -> prng_f {return prng_f(static_cast<uint8_t>(value_ >> prng_f::offset));}
	[[nodiscard]] constexpr auto seedf() const -> seedf_f {return seedf_f((value_ & seedf_f::mask) != 0);}
	[[nodiscard]] constexpr auto inits() const -> inits_f {return inits_f((value_ & inits_f::mask) != 0);}

	constexpr tamp_ator_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_ator_r other) const -> tamp_ator_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_ator_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP active tamper control register 2
 */
class tamp_atcr2_r {
public:

/**
 * Active tamper shared output 1 selection 
 */
class atosel1_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 2 selection 
 */
class atosel2_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr atosel2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 3 selection 
 */
class atosel3_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel3_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 4 selection 
 */
class atosel4_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel4_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 5 selection 
 */
class atosel5_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel5_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 6 selection 
 */
class atosel6_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel6_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 7 selection 
 */
class atosel7_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel7_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Active tamper shared output 8 selection 
 */
class atosel8_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atosel8_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_atcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_atcr2_r>() const {return opsy::utility::clear_set<tamp_atcr2_r>(mask, *this);}
	constexpr auto operator|(tamp_atcr2_r other) const -> tamp_atcr2_r { return static_cast<tamp_atcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_atcr2_r> other) const -> opsy::utility::clear_set<tamp_atcr2_r> {return opsy::utility::clear_set<tamp_atcr2_r>(tamp_atcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto atosel1() const -> atosel1_f {return atosel1_f(static_cast<uint8_t>(value_ >> atosel1_f::offset));}
	[[nodiscard]] constexpr auto atosel2() const -> atosel2_f {return atosel2_f(static_cast<uint8_t>(value_ >> atosel2_f::offset));}
	[[nodiscard]] constexpr auto atosel3() const -> atosel3_f {return atosel3_f(static_cast<uint8_t>(value_ >> atosel3_f::offset));}
	[[nodiscard]] constexpr auto atosel4() const -> atosel4_f {return atosel4_f(static_cast<uint8_t>(value_ >> atosel4_f::offset));}
	[[nodiscard]] constexpr auto atosel5() const -> atosel5_f {return atosel5_f(static_cast<uint8_t>(value_ >> atosel5_f::offset));}
	[[nodiscard]] constexpr auto atosel6() const -> atosel6_f {return atosel6_f(static_cast<uint8_t>(value_ >> atosel6_f::offset));}
	[[nodiscard]] constexpr auto atosel7() const -> atosel7_f {return atosel7_f(static_cast<uint8_t>(value_ >> atosel7_f::offset));}
	[[nodiscard]] constexpr auto atosel8() const -> atosel8_f {return atosel8_f(static_cast<uint8_t>(value_ >> atosel8_f::offset));}

	constexpr tamp_atcr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_atcr2_r other) const -> tamp_atcr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_atcr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP secure configuration register
 */
class tamp_seccfgr_r {
public:

/**
 * Backup registers read/write protection offset 
 */
class bkprwsec_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr bkprwsec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_seccfgr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_seccfgr_r>() const {return opsy::utility::clear_set<tamp_seccfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return static_cast<tamp_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_seccfgr_r> other) const -> opsy::utility::clear_set<tamp_seccfgr_r> {return opsy::utility::clear_set<tamp_seccfgr_r>(tamp_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Monotonic counter 1 secure protection
 */
class cnt1sec_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cnt1sec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_seccfgr_r>() const {return opsy::utility::clear_set<tamp_seccfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return static_cast<tamp_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_seccfgr_r> other) const -> opsy::utility::clear_set<tamp_seccfgr_r> {return opsy::utility::clear_set<tamp_seccfgr_r>(tamp_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup registers write protection offset 
 */
class bkpwsec_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr bkpwsec_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_seccfgr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_seccfgr_r>() const {return opsy::utility::clear_set<tamp_seccfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return static_cast<tamp_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_seccfgr_r> other) const -> opsy::utility::clear_set<tamp_seccfgr_r> {return opsy::utility::clear_set<tamp_seccfgr_r>(tamp_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Boot hardware key lock 
 */
class bhklock_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bhklock_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_seccfgr_r>() const {return opsy::utility::clear_set<tamp_seccfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return static_cast<tamp_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_seccfgr_r> other) const -> opsy::utility::clear_set<tamp_seccfgr_r> {return opsy::utility::clear_set<tamp_seccfgr_r>(tamp_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper protection (excluding monotonic counters and backup registers) 
 */
class tampsec_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tampsec_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_seccfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_seccfgr_r>() const {return opsy::utility::clear_set<tamp_seccfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return static_cast<tamp_seccfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_seccfgr_r> other) const -> opsy::utility::clear_set<tamp_seccfgr_r> {return opsy::utility::clear_set<tamp_seccfgr_r>(tamp_seccfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bkprwsec() const -> bkprwsec_f {return bkprwsec_f(static_cast<uint8_t>(value_ >> bkprwsec_f::offset));}
	[[nodiscard]] constexpr auto cnt1sec() const -> cnt1sec_f {return cnt1sec_f((value_ & cnt1sec_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpwsec() const -> bkpwsec_f {return bkpwsec_f(static_cast<uint8_t>(value_ >> bkpwsec_f::offset));}
	[[nodiscard]] constexpr auto bhklock() const -> bhklock_f {return bhklock_f((value_ & bhklock_f::mask) != 0);}
	[[nodiscard]] constexpr auto tampsec() const -> tampsec_f {return tampsec_f((value_ & tampsec_f::mask) != 0);}

	constexpr tamp_seccfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_seccfgr_r other) const -> tamp_seccfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_seccfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP privilege configuration register
 */
class tamp_privcfgr_r {
public:

/**
 * Monotonic counter 1 privilege protection
 */
class cnt1priv_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr cnt1priv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_privcfgr_r>() const {return opsy::utility::clear_set<tamp_privcfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_privcfgr_r other) const -> tamp_privcfgr_r { return static_cast<tamp_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_privcfgr_r> other) const -> opsy::utility::clear_set<tamp_privcfgr_r> {return opsy::utility::clear_set<tamp_privcfgr_r>(tamp_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup registers zone 1 privilege protection
 */
class bkprwpriv_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkprwpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_privcfgr_r>() const {return opsy::utility::clear_set<tamp_privcfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_privcfgr_r other) const -> tamp_privcfgr_r { return static_cast<tamp_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_privcfgr_r> other) const -> opsy::utility::clear_set<tamp_privcfgr_r> {return opsy::utility::clear_set<tamp_privcfgr_r>(tamp_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Backup registers zone 2 privilege protection
 */
class bkpwpriv_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr bkpwpriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_privcfgr_r>() const {return opsy::utility::clear_set<tamp_privcfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_privcfgr_r other) const -> tamp_privcfgr_r { return static_cast<tamp_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_privcfgr_r> other) const -> opsy::utility::clear_set<tamp_privcfgr_r> {return opsy::utility::clear_set<tamp_privcfgr_r>(tamp_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper privilege protection (excluding backup registers) 
 */
class tamppriv_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tamppriv_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_privcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_privcfgr_r>() const {return opsy::utility::clear_set<tamp_privcfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_privcfgr_r other) const -> tamp_privcfgr_r { return static_cast<tamp_privcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_privcfgr_r> other) const -> opsy::utility::clear_set<tamp_privcfgr_r> {return opsy::utility::clear_set<tamp_privcfgr_r>(tamp_privcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cnt1priv() const -> cnt1priv_f {return cnt1priv_f((value_ & cnt1priv_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkprwpriv() const -> bkprwpriv_f {return bkprwpriv_f((value_ & bkprwpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto bkpwpriv() const -> bkpwpriv_f {return bkpwpriv_f((value_ & bkpwpriv_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamppriv() const -> tamppriv_f {return tamppriv_f((value_ & tamppriv_f::mask) != 0);}

	constexpr tamp_privcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_privcfgr_r other) const -> tamp_privcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_privcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP interrupt enable register
 */
class tamp_ier_r {
public:

/**
 * Tamper 1 interrupt enable
 */
class tamp1ie_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 2 interrupt enable
 */
class tamp2ie_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 3 interrupt enable
 */
class tamp3ie_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 4 interrupt enable
 */
class tamp4ie_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 5 interrupt enable
 */
class tamp5ie_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 6 interrupt enable
 */
class tamp6ie_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 7interrupt enable
 */
class tamp7ie_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Tamper 8 interrupt enable
 */
class tamp8ie_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 1 interrupt enable
 */
class itamp1ie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp1ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 2 interrupt enable
 */
class itamp2ie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp2ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 3 interrupt enable
 */
class itamp3ie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp3ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 4 interrupt enable
 */
class itamp4ie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp4ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 5 interrupt enable
 */
class itamp5ie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp5ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 6 interrupt enable
 */
class itamp6ie_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp6ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 7 interrupt enable
 */
class itamp7ie_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp7ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 8 interrupt enable
 */
class itamp8ie_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp8ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 9 interrupt enable
 */
class itamp9ie_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp9ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 11 interrupt enable
 */
class itamp11ie_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp11ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 12 interrupt enable
 */
class itamp12ie_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp12ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 13 interrupt enable
 */
class itamp13ie_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp13ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 15 interrupt enable
 */
class itamp15ie_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp15ie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_ier_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_ier_r>() const {return opsy::utility::clear_set<tamp_ier_r>(mask, *this);}
	constexpr auto operator|(tamp_ier_r other) const -> tamp_ier_r { return static_cast<tamp_ier_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_ier_r> other) const -> opsy::utility::clear_set<tamp_ier_r> {return opsy::utility::clear_set<tamp_ier_r>(tamp_ier_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1ie() const -> tamp1ie_f {return tamp1ie_f((value_ & tamp1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2ie() const -> tamp2ie_f {return tamp2ie_f((value_ & tamp2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3ie() const -> tamp3ie_f {return tamp3ie_f((value_ & tamp3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4ie() const -> tamp4ie_f {return tamp4ie_f((value_ & tamp4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5ie() const -> tamp5ie_f {return tamp5ie_f((value_ & tamp5ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6ie() const -> tamp6ie_f {return tamp6ie_f((value_ & tamp6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7ie() const -> tamp7ie_f {return tamp7ie_f((value_ & tamp7ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8ie() const -> tamp8ie_f {return tamp8ie_f((value_ & tamp8ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp1ie() const -> itamp1ie_f {return itamp1ie_f((value_ & itamp1ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp2ie() const -> itamp2ie_f {return itamp2ie_f((value_ & itamp2ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp3ie() const -> itamp3ie_f {return itamp3ie_f((value_ & itamp3ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp4ie() const -> itamp4ie_f {return itamp4ie_f((value_ & itamp4ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp5ie() const -> itamp5ie_f {return itamp5ie_f((value_ & itamp5ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp6ie() const -> itamp6ie_f {return itamp6ie_f((value_ & itamp6ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp7ie() const -> itamp7ie_f {return itamp7ie_f((value_ & itamp7ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp8ie() const -> itamp8ie_f {return itamp8ie_f((value_ & itamp8ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp9ie() const -> itamp9ie_f {return itamp9ie_f((value_ & itamp9ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp11ie() const -> itamp11ie_f {return itamp11ie_f((value_ & itamp11ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp12ie() const -> itamp12ie_f {return itamp12ie_f((value_ & itamp12ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp13ie() const -> itamp13ie_f {return itamp13ie_f((value_ & itamp13ie_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp15ie() const -> itamp15ie_f {return itamp15ie_f((value_ & itamp15ie_f::mask) != 0);}

	constexpr tamp_ier_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_ier_r other) const -> tamp_ier_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_ier_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP status register
 */
class tamp_sr_r {
public:

/**
 * TAMP1 detection flag 
 */
class tamp1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP2 detection flag 
 */
class tamp2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP3 detection flag 
 */
class tamp3f_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP4 detection flag 
 */
class tamp4f_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP5 detection flag 
 */
class tamp5f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP6 detection flag 
 */
class tamp6f_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP7 detection flag 
 */
class tamp7f_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP8 detection flag 
 */
class tamp8f_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 1 flag 
 */
class itamp1f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 2 flag 
 */
class itamp2f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 3 flag 
 */
class itamp3f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 4 flag 
 */
class itamp4f_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 5 flag 
 */
class itamp5f_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 6 flag 
 */
class itamp6f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 7 flag 
 */
class itamp7f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 8 flag 
 */
class itamp8f_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 9 flag 
 */
class itamp9f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp9f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 11 flag 
 */
class itamp11f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp11f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 12 flag 
 */
class itamp12f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 13 flag 
 */
class itamp13f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp13f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 15 flag 
 */
class itamp15f_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp15f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_sr_r>() const {return opsy::utility::clear_set<tamp_sr_r>(mask, *this);}
	constexpr auto operator|(tamp_sr_r other) const -> tamp_sr_r { return static_cast<tamp_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_sr_r> other) const -> opsy::utility::clear_set<tamp_sr_r> {return opsy::utility::clear_set<tamp_sr_r>(tamp_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1f() const -> tamp1f_f {return tamp1f_f((value_ & tamp1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2f() const -> tamp2f_f {return tamp2f_f((value_ & tamp2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3f() const -> tamp3f_f {return tamp3f_f((value_ & tamp3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4f() const -> tamp4f_f {return tamp4f_f((value_ & tamp4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5f() const -> tamp5f_f {return tamp5f_f((value_ & tamp5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6f() const -> tamp6f_f {return tamp6f_f((value_ & tamp6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7f() const -> tamp7f_f {return tamp7f_f((value_ & tamp7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8f() const -> tamp8f_f {return tamp8f_f((value_ & tamp8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp1f() const -> itamp1f_f {return itamp1f_f((value_ & itamp1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp2f() const -> itamp2f_f {return itamp2f_f((value_ & itamp2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp3f() const -> itamp3f_f {return itamp3f_f((value_ & itamp3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp4f() const -> itamp4f_f {return itamp4f_f((value_ & itamp4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp5f() const -> itamp5f_f {return itamp5f_f((value_ & itamp5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp6f() const -> itamp6f_f {return itamp6f_f((value_ & itamp6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp7f() const -> itamp7f_f {return itamp7f_f((value_ & itamp7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp8f() const -> itamp8f_f {return itamp8f_f((value_ & itamp8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp9f() const -> itamp9f_f {return itamp9f_f((value_ & itamp9f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp11f() const -> itamp11f_f {return itamp11f_f((value_ & itamp11f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp12f() const -> itamp12f_f {return itamp12f_f((value_ & itamp12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp13f() const -> itamp13f_f {return itamp13f_f((value_ & itamp13f_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp15f() const -> itamp15f_f {return itamp15f_f((value_ & itamp15f_f::mask) != 0);}

	constexpr tamp_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_sr_r other) const -> tamp_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP nonsecure masked interrupt status register
 */
class tamp_misr_r {
public:

/**
 * TAMP1 nonsecure interrupt masked flag 
 */
class tamp1mf_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp1mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP2 nonsecure interrupt masked flag 
 */
class tamp2mf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp2mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP3 nonsecure interrupt masked flag 
 */
class tamp3mf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp3mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP4 nonsecure interrupt masked flag 
 */
class tamp4mf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp4mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP5 nonsecure interrupt masked flag 
 */
class tamp5mf_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp5mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP6 nonsecure interrupt masked flag 
 */
class tamp6mf_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp6mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP7 nonsecure interrupt masked flag 
 */
class tamp7mf_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp7mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP8 nonsecure interrupt masked flag 
 */
class tamp8mf_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tamp8mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 1 nonsecure interrupt masked flag 
 */
class itamp1mf_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp1mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 2 nonsecure interrupt masked flag 
 */
class itamp2mf_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp2mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 3 nonsecure interrupt masked flag 
 */
class itamp3mf_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp3mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 4 nonsecure interrupt masked flag 
 */
class itamp4mf_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp4mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 5 nonsecure interrupt masked flag 
 */
class itamp5mf_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp5mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 6 nonsecure interrupt masked flag 
 */
class itamp6mf_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp6mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 7 tamper nonsecure interrupt masked flag 
 */
class itamp7mf_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp7mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Internal tamper 8 nonsecure interrupt masked flag 
 */
class itamp8mf_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp8mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal tamper 9 nonsecure interrupt masked flag 
 */
class itamp9mf_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp9mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal tamper 11 nonsecure interrupt masked flag 
 */
class itamp11mf_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp11mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal tamper 12 nonsecure interrupt masked flag 
 */
class itamp12mf_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp12mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal tamper 13 nonsecure interrupt masked flag 
 */
class itamp13mf_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp13mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * internal tamper 15 nonsecure interrupt masked flag 
 */
class itamp15mf_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr itamp15mf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_misr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_misr_r>() const {return opsy::utility::clear_set<tamp_misr_r>(mask, *this);}
	constexpr auto operator|(tamp_misr_r other) const -> tamp_misr_r { return static_cast<tamp_misr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_misr_r> other) const -> opsy::utility::clear_set<tamp_misr_r> {return opsy::utility::clear_set<tamp_misr_r>(tamp_misr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto tamp1mf() const -> tamp1mf_f {return tamp1mf_f((value_ & tamp1mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp2mf() const -> tamp2mf_f {return tamp2mf_f((value_ & tamp2mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp3mf() const -> tamp3mf_f {return tamp3mf_f((value_ & tamp3mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp4mf() const -> tamp4mf_f {return tamp4mf_f((value_ & tamp4mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp5mf() const -> tamp5mf_f {return tamp5mf_f((value_ & tamp5mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp6mf() const -> tamp6mf_f {return tamp6mf_f((value_ & tamp6mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp7mf() const -> tamp7mf_f {return tamp7mf_f((value_ & tamp7mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tamp8mf() const -> tamp8mf_f {return tamp8mf_f((value_ & tamp8mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp1mf() const -> itamp1mf_f {return itamp1mf_f((value_ & itamp1mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp2mf() const -> itamp2mf_f {return itamp2mf_f((value_ & itamp2mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp3mf() const -> itamp3mf_f {return itamp3mf_f((value_ & itamp3mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp4mf() const -> itamp4mf_f {return itamp4mf_f((value_ & itamp4mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp5mf() const -> itamp5mf_f {return itamp5mf_f((value_ & itamp5mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp6mf() const -> itamp6mf_f {return itamp6mf_f((value_ & itamp6mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp7mf() const -> itamp7mf_f {return itamp7mf_f((value_ & itamp7mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp8mf() const -> itamp8mf_f {return itamp8mf_f((value_ & itamp8mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp9mf() const -> itamp9mf_f {return itamp9mf_f((value_ & itamp9mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp11mf() const -> itamp11mf_f {return itamp11mf_f((value_ & itamp11mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp12mf() const -> itamp12mf_f {return itamp12mf_f((value_ & itamp12mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp13mf() const -> itamp13mf_f {return itamp13mf_f((value_ & itamp13mf_f::mask) != 0);}
	[[nodiscard]] constexpr auto itamp15mf() const -> itamp15mf_f {return itamp15mf_f((value_ & itamp15mf_f::mask) != 0);}

	constexpr tamp_misr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_misr_r other) const -> tamp_misr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_misr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP status clear register
 */
class tamp_scr_r {
public:

/**
 * Clear TAMP1 detection flag 
 */
class ctamp1f_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP2 detection flag 
 */
class ctamp2f_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP3 detection flag 
 */
class ctamp3f_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP4 detection flag 
 */
class ctamp4f_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP5 detection flag 
 */
class ctamp5f_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP6 detection flag 
 */
class ctamp6f_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP7 detection flag 
 */
class ctamp7f_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear TAMP8 detection flag 
 */
class ctamp8f_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctamp8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP1 detection flag 
 */
class citamp1f_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp1f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP2 detection flag 
 */
class citamp2f_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp2f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP3 detection flag 
 */
class citamp3f_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp3f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP4 detection flag 
 */
class citamp4f_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp4f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP5 detection flag 
 */
class citamp5f_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp5f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP6 detection flag 
 */
class citamp6f_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp6f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP7 detection flag 
 */
class citamp7f_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp7f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP8 detection flag 
 */
class citamp8f_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp8f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP9 detection flag 
 */
class citamp9f_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp9f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP11 detection flag 
 */
class citamp11f_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp11f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP12 detection flag 
 */
class citamp12f_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp12f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP13 detection flag 
 */
class citamp13f_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp13f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear ITAMP15 detection flag 
 */
class citamp15f_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr citamp15f_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_scr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_scr_r>() const {return opsy::utility::clear_set<tamp_scr_r>(mask, *this);}
	constexpr auto operator|(tamp_scr_r other) const -> tamp_scr_r { return static_cast<tamp_scr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_scr_r> other) const -> opsy::utility::clear_set<tamp_scr_r> {return opsy::utility::clear_set<tamp_scr_r>(tamp_scr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ctamp1f() const -> ctamp1f_f {return ctamp1f_f((value_ & ctamp1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp2f() const -> ctamp2f_f {return ctamp2f_f((value_ & ctamp2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp3f() const -> ctamp3f_f {return ctamp3f_f((value_ & ctamp3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp4f() const -> ctamp4f_f {return ctamp4f_f((value_ & ctamp4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp5f() const -> ctamp5f_f {return ctamp5f_f((value_ & ctamp5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp6f() const -> ctamp6f_f {return ctamp6f_f((value_ & ctamp6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp7f() const -> ctamp7f_f {return ctamp7f_f((value_ & ctamp7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctamp8f() const -> ctamp8f_f {return ctamp8f_f((value_ & ctamp8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp1f() const -> citamp1f_f {return citamp1f_f((value_ & citamp1f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp2f() const -> citamp2f_f {return citamp2f_f((value_ & citamp2f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp3f() const -> citamp3f_f {return citamp3f_f((value_ & citamp3f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp4f() const -> citamp4f_f {return citamp4f_f((value_ & citamp4f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp5f() const -> citamp5f_f {return citamp5f_f((value_ & citamp5f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp6f() const -> citamp6f_f {return citamp6f_f((value_ & citamp6f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp7f() const -> citamp7f_f {return citamp7f_f((value_ & citamp7f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp8f() const -> citamp8f_f {return citamp8f_f((value_ & citamp8f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp9f() const -> citamp9f_f {return citamp9f_f((value_ & citamp9f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp11f() const -> citamp11f_f {return citamp11f_f((value_ & citamp11f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp12f() const -> citamp12f_f {return citamp12f_f((value_ & citamp12f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp13f() const -> citamp13f_f {return citamp13f_f((value_ & citamp13f_f::mask) != 0);}
	[[nodiscard]] constexpr auto citamp15f() const -> citamp15f_f {return citamp15f_f((value_ & citamp15f_f::mask) != 0);}

	constexpr tamp_scr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_scr_r other) const -> tamp_scr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_scr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP monotonic counter 1 register
 */
class tamp_count1r_r {
public:

/**
 * This register is read-only only and is incremented by one when a write access is done to this register.
 */
class count_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr count_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tamp_count1r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_count1r_r>() const {return opsy::utility::clear_set<tamp_count1r_r>(mask, *this);}
	constexpr auto operator|(tamp_count1r_r other) const -> tamp_count1r_r { return static_cast<tamp_count1r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_count1r_r> other) const -> opsy::utility::clear_set<tamp_count1r_r> {return opsy::utility::clear_set<tamp_count1r_r>(tamp_count1r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto count() const -> count_f {return count_f(static_cast<uint32_t>(value_ >> count_f::offset));}

	constexpr tamp_count1r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_count1r_r other) const -> tamp_count1r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_count1r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP option register
 */
class tamp_or_r {
public:

/**
 * TAMP_OUT3 mapping
 */
class out3_rmp_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr out3_rmp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator tamp_or_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_or_r>() const {return opsy::utility::clear_set<tamp_or_r>(mask, *this);}
	constexpr auto operator|(tamp_or_r other) const -> tamp_or_r { return static_cast<tamp_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_or_r> other) const -> opsy::utility::clear_set<tamp_or_r> {return opsy::utility::clear_set<tamp_or_r>(tamp_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * TAMP_OUT5 mapping
 */
class out5_rmp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr out5_rmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_or_r>() const {return opsy::utility::clear_set<tamp_or_r>(mask, *this);}
	constexpr auto operator|(tamp_or_r other) const -> tamp_or_r { return static_cast<tamp_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_or_r> other) const -> opsy::utility::clear_set<tamp_or_r> {return opsy::utility::clear_set<tamp_or_r>(tamp_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP_IN2 mapping
 */
class in2_rmp_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr in2_rmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_or_r>() const {return opsy::utility::clear_set<tamp_or_r>(mask, *this);}
	constexpr auto operator|(tamp_or_r other) const -> tamp_or_r { return static_cast<tamp_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_or_r> other) const -> opsy::utility::clear_set<tamp_or_r> {return opsy::utility::clear_set<tamp_or_r>(tamp_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP_IN3 mapping
 */
class in3_rmp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr in3_rmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_or_r>() const {return opsy::utility::clear_set<tamp_or_r>(mask, *this);}
	constexpr auto operator|(tamp_or_r other) const -> tamp_or_r { return static_cast<tamp_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_or_r> other) const -> opsy::utility::clear_set<tamp_or_r> {return opsy::utility::clear_set<tamp_or_r>(tamp_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * TAMP_IN4 mapping
 */
class in4_rmp_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr in4_rmp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_or_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_or_r>() const {return opsy::utility::clear_set<tamp_or_r>(mask, *this);}
	constexpr auto operator|(tamp_or_r other) const -> tamp_or_r { return static_cast<tamp_or_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_or_r> other) const -> opsy::utility::clear_set<tamp_or_r> {return opsy::utility::clear_set<tamp_or_r>(tamp_or_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto out3_rmp() const -> out3_rmp_f {return out3_rmp_f(static_cast<uint8_t>(value_ >> out3_rmp_f::offset));}
	[[nodiscard]] constexpr auto out5_rmp() const -> out5_rmp_f {return out5_rmp_f((value_ & out5_rmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto in2_rmp() const -> in2_rmp_f {return in2_rmp_f((value_ & in2_rmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto in3_rmp() const -> in3_rmp_f {return in3_rmp_f((value_ & in3_rmp_f::mask) != 0);}
	[[nodiscard]] constexpr auto in4_rmp() const -> in4_rmp_f {return in4_rmp_f((value_ & in4_rmp_f::mask) != 0);}

	constexpr tamp_or_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_or_r other) const -> tamp_or_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_or_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP resources protection configuration register
 */
class tamp_rpcfgr_r {
public:

/**
 * Configurable resource 0 protection
 */
class rpcfg0_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr rpcfg0_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator tamp_rpcfgr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<tamp_rpcfgr_r>() const {return opsy::utility::clear_set<tamp_rpcfgr_r>(mask, *this);}
	constexpr auto operator|(tamp_rpcfgr_r other) const -> tamp_rpcfgr_r { return static_cast<tamp_rpcfgr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_rpcfgr_r> other) const -> opsy::utility::clear_set<tamp_rpcfgr_r> {return opsy::utility::clear_set<tamp_rpcfgr_r>(tamp_rpcfgr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto rpcfg0() const -> rpcfg0_f {return rpcfg0_f((value_ & rpcfg0_f::mask) != 0);}

	constexpr tamp_rpcfgr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_rpcfgr_r other) const -> tamp_rpcfgr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_rpcfgr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * TAMP backup 0 register
 */
class tamp_bkp0r_r {
public:

/**
 * The application can write or read data to and from these registers.
 */
class bkp_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr bkp_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator tamp_bkp0r_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<tamp_bkp0r_r>() const {return opsy::utility::clear_set<tamp_bkp0r_r>(mask, *this);}
	constexpr auto operator|(tamp_bkp0r_r other) const -> tamp_bkp0r_r { return static_cast<tamp_bkp0r_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<tamp_bkp0r_r> other) const -> opsy::utility::clear_set<tamp_bkp0r_r> {return opsy::utility::clear_set<tamp_bkp0r_r>(tamp_bkp0r_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto bkp() const -> bkp_f {return bkp_f(static_cast<uint32_t>(value_ >> bkp_f::offset));}

	constexpr tamp_bkp0r_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(tamp_bkp0r_r other) const -> tamp_bkp0r_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> tamp_bkp0r_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,tamp_cr1_r> tamp_cr1;
	opsy::utility::memory<uint32_t,tamp_cr2_r> tamp_cr2;
	opsy::utility::memory<uint32_t,tamp_cr3_r> tamp_cr3;
	opsy::utility::memory<uint32_t,tamp_fltcr_r> tamp_fltcr;
	opsy::utility::memory<uint32_t,tamp_atcr1_r> tamp_atcr1;
	opsy::utility::write_only_memory<uint32_t,tamp_atseedr_r> tamp_atseedr;
	opsy::utility::read_only_memory<uint32_t,tamp_ator_r> tamp_ator;
	opsy::utility::memory<uint32_t,tamp_atcr2_r> tamp_atcr2;
	opsy::utility::memory<uint32_t,tamp_seccfgr_r> tamp_seccfgr;
	opsy::utility::memory<uint32_t,tamp_privcfgr_r> tamp_privcfgr;
	opsy::utility::padding<4> _p40;
	opsy::utility::memory<uint32_t,tamp_ier_r> tamp_ier;
	opsy::utility::memory<uint32_t,tamp_sr_r> tamp_sr;
	opsy::utility::read_only_memory<uint32_t,tamp_misr_r> tamp_misr;
	opsy::utility::read_only_memory<uint32_t,tamp_misr_r> tamp_smisr;
	opsy::utility::write_only_memory<uint32_t,tamp_scr_r> tamp_scr;
	opsy::utility::read_only_memory<uint32_t,tamp_count1r_r> tamp_count1r;
	opsy::utility::padding<12> _p68;
	opsy::utility::memory<uint32_t,tamp_or_r> tamp_or;
	opsy::utility::memory<uint32_t,tamp_rpcfgr_r> tamp_rpcfgr;
	opsy::utility::padding<168> _p88;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp0r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp1r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp2r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp3r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp4r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp5r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp6r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp7r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp8r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp9r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp10r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp11r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp12r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp13r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp14r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp15r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp16r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp17r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp18r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp19r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp20r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp21r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp22r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp23r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp24r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp25r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp26r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp27r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp28r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp29r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp30r;
	opsy::utility::memory<uint32_t,tamp_bkp0r_r> tamp_bkp31r;
};

static_assert(std::is_standard_layout_v<tamp_p>);
static_assert(offsetof(tamp_p, tamp_cr1) == 0);
static_assert(offsetof(tamp_p, tamp_cr2) == 4);
static_assert(offsetof(tamp_p, tamp_cr3) == 8);
static_assert(offsetof(tamp_p, tamp_fltcr) == 12);
static_assert(offsetof(tamp_p, tamp_atcr1) == 16);
static_assert(offsetof(tamp_p, tamp_atseedr) == 20);
static_assert(offsetof(tamp_p, tamp_ator) == 24);
static_assert(offsetof(tamp_p, tamp_atcr2) == 28);
static_assert(offsetof(tamp_p, tamp_seccfgr) == 32);
static_assert(offsetof(tamp_p, tamp_privcfgr) == 36);
static_assert(offsetof(tamp_p, tamp_ier) == 44);
static_assert(offsetof(tamp_p, tamp_sr) == 48);
static_assert(offsetof(tamp_p, tamp_misr) == 52);
static_assert(offsetof(tamp_p, tamp_smisr) == 56);
static_assert(offsetof(tamp_p, tamp_scr) == 60);
static_assert(offsetof(tamp_p, tamp_count1r) == 64);
static_assert(offsetof(tamp_p, tamp_or) == 80);
static_assert(offsetof(tamp_p, tamp_rpcfgr) == 84);
static_assert(offsetof(tamp_p, tamp_bkp0r) == 256);
static_assert(offsetof(tamp_p, tamp_bkp1r) == 260);
static_assert(offsetof(tamp_p, tamp_bkp2r) == 264);
static_assert(offsetof(tamp_p, tamp_bkp3r) == 268);
static_assert(offsetof(tamp_p, tamp_bkp4r) == 272);
static_assert(offsetof(tamp_p, tamp_bkp5r) == 276);
static_assert(offsetof(tamp_p, tamp_bkp6r) == 280);
static_assert(offsetof(tamp_p, tamp_bkp7r) == 284);
static_assert(offsetof(tamp_p, tamp_bkp8r) == 288);
static_assert(offsetof(tamp_p, tamp_bkp9r) == 292);
static_assert(offsetof(tamp_p, tamp_bkp10r) == 296);
static_assert(offsetof(tamp_p, tamp_bkp11r) == 300);
static_assert(offsetof(tamp_p, tamp_bkp12r) == 304);
static_assert(offsetof(tamp_p, tamp_bkp13r) == 308);
static_assert(offsetof(tamp_p, tamp_bkp14r) == 312);
static_assert(offsetof(tamp_p, tamp_bkp15r) == 316);
static_assert(offsetof(tamp_p, tamp_bkp16r) == 320);
static_assert(offsetof(tamp_p, tamp_bkp17r) == 324);
static_assert(offsetof(tamp_p, tamp_bkp18r) == 328);
static_assert(offsetof(tamp_p, tamp_bkp19r) == 332);
static_assert(offsetof(tamp_p, tamp_bkp20r) == 336);
static_assert(offsetof(tamp_p, tamp_bkp21r) == 340);
static_assert(offsetof(tamp_p, tamp_bkp22r) == 344);
static_assert(offsetof(tamp_p, tamp_bkp23r) == 348);
static_assert(offsetof(tamp_p, tamp_bkp24r) == 352);
static_assert(offsetof(tamp_p, tamp_bkp25r) == 356);
static_assert(offsetof(tamp_p, tamp_bkp26r) == 360);
static_assert(offsetof(tamp_p, tamp_bkp27r) == 364);
static_assert(offsetof(tamp_p, tamp_bkp28r) == 368);
static_assert(offsetof(tamp_p, tamp_bkp29r) == 372);
static_assert(offsetof(tamp_p, tamp_bkp30r) == 376);
static_assert(offsetof(tamp_p, tamp_bkp31r) == 380);

inline tamp_p& tamp = *reinterpret_cast<tamp_p*>(0x44007C00);
inline tamp_p& tamp_s = *reinterpret_cast<tamp_p*>(0x54007C00);

} // STM32H523

