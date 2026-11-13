#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * USBSRAM address block description
 */
class usbsram_p {
public:

/**
 * Channel/endpoint transmit buffer descriptor X
 */
class usbsram_chep_txrxbd_0_r {
public:

/**
 * Transmission buffer address 
 */
class addr_tx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addr_tx_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_r other) const -> usbsram_chep_txrxbd_0_r { return static_cast<usbsram_chep_txrxbd_0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>(usbsram_chep_txrxbd_0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Transmission byte count 
 */
class count_tx_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr count_tx_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_r other) const -> usbsram_chep_txrxbd_0_r { return static_cast<usbsram_chep_txrxbd_0_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_r>(usbsram_chep_txrxbd_0_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto addr_tx() const -> addr_tx_f {return addr_tx_f(static_cast<uint16_t>(value_ >> addr_tx_f::offset));}
	[[nodiscard]] constexpr auto count_tx() const -> count_tx_f {return count_tx_f(static_cast<uint16_t>(value_ >> count_tx_f::offset));}

	constexpr usbsram_chep_txrxbd_0_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usbsram_chep_txrxbd_0_r other) const -> usbsram_chep_txrxbd_0_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usbsram_chep_txrxbd_0_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Channel/endpoint receive buffer descriptor X
 */
class usbsram_chep_txrxbd_0_alternate1_r {
public:

/**
 * Reception buffer address 
 */
class addr_rx_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr addr_rx_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_alternate1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_alternate1_r other) const -> usbsram_chep_txrxbd_0_alternate1_r { return static_cast<usbsram_chep_txrxbd_0_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(usbsram_chep_txrxbd_0_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Reception byte count 
 */
class count_rx_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 10;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr count_rx_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_alternate1_r other) const -> usbsram_chep_txrxbd_0_alternate1_r { return static_cast<usbsram_chep_txrxbd_0_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(usbsram_chep_txrxbd_0_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Number of blocks 
 */
class num_block_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr num_block_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_alternate1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_alternate1_r other) const -> usbsram_chep_txrxbd_0_alternate1_r { return static_cast<usbsram_chep_txrxbd_0_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(usbsram_chep_txrxbd_0_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Block size 
 */
class blsize_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr blsize_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usbsram_chep_txrxbd_0_alternate1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>() const {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(mask, *this);}
	constexpr auto operator|(usbsram_chep_txrxbd_0_alternate1_r other) const -> usbsram_chep_txrxbd_0_alternate1_r { return static_cast<usbsram_chep_txrxbd_0_alternate1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> other) const -> opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r> {return opsy::utility::clear_set<usbsram_chep_txrxbd_0_alternate1_r>(usbsram_chep_txrxbd_0_alternate1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto addr_rx() const -> addr_rx_f {return addr_rx_f(static_cast<uint16_t>(value_ >> addr_rx_f::offset));}
	[[nodiscard]] constexpr auto count_rx() const -> count_rx_f {return count_rx_f(static_cast<uint16_t>(value_ >> count_rx_f::offset));}
	[[nodiscard]] constexpr auto num_block() const -> num_block_f {return num_block_f(static_cast<uint8_t>(value_ >> num_block_f::offset));}
	[[nodiscard]] constexpr auto blsize() const -> blsize_f {return blsize_f((value_ & blsize_f::mask) != 0);}

	constexpr usbsram_chep_txrxbd_0_alternate1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usbsram_chep_txrxbd_0_alternate1_r other) const -> usbsram_chep_txrxbd_0_alternate1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usbsram_chep_txrxbd_0_alternate1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_0;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_0_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_0;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_0_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_1;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_1_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_1;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_1_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_2;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_2_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_2;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_2_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_3;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_3_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_3;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_3_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_4;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_4_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_4;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_4_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_5;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_5_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_5;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_5_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_6;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_6_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_6;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_6_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_txrxbd_7;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_txrxbd_7_alternate1;
	};
	union {
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_alternate1_r> usbsram_chep_rxtxbd_7;
		opsy::utility::memory<uint32_t,usbsram_chep_txrxbd_0_r> usbsram_chep_rxtxbd_7_alternate1;
	};
};

static_assert(std::is_standard_layout_v<usbsram_p>);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_0) == 0);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_0_alternate1) == 0);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_0) == 4);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_0_alternate1) == 4);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_1) == 8);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_1_alternate1) == 8);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_1) == 12);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_1_alternate1) == 12);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_2) == 16);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_2_alternate1) == 16);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_2) == 20);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_2_alternate1) == 20);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_3) == 24);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_3_alternate1) == 24);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_3) == 28);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_3_alternate1) == 28);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_4) == 32);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_4_alternate1) == 32);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_4) == 36);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_4_alternate1) == 36);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_5) == 40);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_5_alternate1) == 40);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_5) == 44);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_5_alternate1) == 44);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_6) == 48);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_6_alternate1) == 48);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_6) == 52);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_6_alternate1) == 52);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_7) == 56);
static_assert(offsetof(usbsram_p, usbsram_chep_txrxbd_7_alternate1) == 56);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_7) == 60);
static_assert(offsetof(usbsram_p, usbsram_chep_rxtxbd_7_alternate1) == 60);

inline usbsram_p& usbsram = *reinterpret_cast<usbsram_p*>(0x40016400);
inline usbsram_p& usbsram_s = *reinterpret_cast<usbsram_p*>(0x50016400);

} // STM32H523

