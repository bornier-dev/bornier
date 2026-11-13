#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H523
{

/**
 * USB address block description
 */
class usb_p {
public:

/**
 * USB endpoint/channel X register
 */
class usb_chepxr_r {
public:

/**
 * endpoint/channel address 
 */
class ea_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr ea_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Status bits, for transmission transfers 
 */
class stattx_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr stattx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data toggle, for transmission transfers 
 */
class dtogtx_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dtogtx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Valid USB transaction transmitted 
 */
class vttx_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr vttx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * endpoint/channel kind 
 */
class epkind_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr epkind_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB type of transaction 
 */
class utype_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr utype_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Setup transaction completed 
 */
class setup_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr setup_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status bits, for reception transfers 
 */
class statrx_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr statrx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data Toggle, for reception transfers 
 */
class dtogrx_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dtogrx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB valid transaction received 
 */
class vtrx_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr vtrx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Host mode 
 */
class devaddr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr devaddr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Host mode 
 */
class nak_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr nak_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low speed endpoint host with HUB only 
 */
class ls_ep_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ls_ep_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received error for an OUT/SETUP transaction 
 */
class err_tx_f {
public:
	static constexpr std::size_t offset = 25;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr err_tx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Received error for an IN transaction 
 */
class err_rx_f {
public:
	static constexpr std::size_t offset = 26;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr err_rx_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_chepxr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Three errors for an OUT or SETUP transaction 
 */
class three_err_tx_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr three_err_tx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Three errors for an IN transaction 
 */
class three_err_rx_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr three_err_rx_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_chepxr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_chepxr_r>() const {return opsy::utility::clear_set<usb_chepxr_r>(mask, *this);}
	constexpr auto operator|(usb_chepxr_r other) const -> usb_chepxr_r { return static_cast<usb_chepxr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_chepxr_r> other) const -> opsy::utility::clear_set<usb_chepxr_r> {return opsy::utility::clear_set<usb_chepxr_r>(usb_chepxr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ea() const -> ea_f {return ea_f(static_cast<uint8_t>(value_ >> ea_f::offset));}
	[[nodiscard]] constexpr auto stattx() const -> stattx_f {return stattx_f(static_cast<uint8_t>(value_ >> stattx_f::offset));}
	[[nodiscard]] constexpr auto dtogtx() const -> dtogtx_f {return dtogtx_f((value_ & dtogtx_f::mask) != 0);}
	[[nodiscard]] constexpr auto vttx() const -> vttx_f {return vttx_f((value_ & vttx_f::mask) != 0);}
	[[nodiscard]] constexpr auto epkind() const -> epkind_f {return epkind_f((value_ & epkind_f::mask) != 0);}
	[[nodiscard]] constexpr auto utype() const -> utype_f {return utype_f(static_cast<uint8_t>(value_ >> utype_f::offset));}
	[[nodiscard]] constexpr auto setup() const -> setup_f {return setup_f((value_ & setup_f::mask) != 0);}
	[[nodiscard]] constexpr auto statrx() const -> statrx_f {return statrx_f(static_cast<uint8_t>(value_ >> statrx_f::offset));}
	[[nodiscard]] constexpr auto dtogrx() const -> dtogrx_f {return dtogrx_f((value_ & dtogrx_f::mask) != 0);}
	[[nodiscard]] constexpr auto vtrx() const -> vtrx_f {return vtrx_f((value_ & vtrx_f::mask) != 0);}
	[[nodiscard]] constexpr auto devaddr() const -> devaddr_f {return devaddr_f(static_cast<uint8_t>(value_ >> devaddr_f::offset));}
	[[nodiscard]] constexpr auto nak() const -> nak_f {return nak_f((value_ & nak_f::mask) != 0);}
	[[nodiscard]] constexpr auto ls_ep() const -> ls_ep_f {return ls_ep_f((value_ & ls_ep_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_tx() const -> err_tx_f {return err_tx_f((value_ & err_tx_f::mask) != 0);}
	[[nodiscard]] constexpr auto err_rx() const -> err_rx_f {return err_rx_f((value_ & err_rx_f::mask) != 0);}
	[[nodiscard]] constexpr auto three_err_tx() const -> three_err_tx_f {return three_err_tx_f(static_cast<uint8_t>(value_ >> three_err_tx_f::offset));}
	[[nodiscard]] constexpr auto three_err_rx() const -> three_err_rx_f {return three_err_rx_f(static_cast<uint8_t>(value_ >> three_err_rx_f::offset));}

	constexpr usb_chepxr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_chepxr_r other) const -> usb_chepxr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_chepxr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB control register
 */
class usb_cntr_r {
public:

/**
 * USB Reset 
 */
class usbrst_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr usbrst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Power down 
 */
class pdwn_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pdwn_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend state effective 
 */
class susprdy_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr susprdy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend state enable 
 */
class suspen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr suspen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * L2 remote wake-up / resume driver 
 */
class l2res_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l2res_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * L1 remote wake-up / resume driver 
 */
class l1res_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1res_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM L1 state request interrupt mask
 */
class l1reqm_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1reqm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected start of frame interrupt mask
 */
class esofm_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr esofm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start of frame interrupt mask
 */
class sofm_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sofm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB reset request (Device mode) or device connect/disconnect (Host mode) interrupt mask
 */
class rst_dconm_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rst_dconm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend mode interrupt mask
 */
class suspm_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr suspm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up interrupt mask
 */
class wkupm_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wkupm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error interrupt mask
 */
class errm_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr errm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Packet memory area over / underrun interrupt mask
 */
class pmaovrm_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pmaovrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Correct transfer interrupt mask
 */
class ctrm_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctrm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 512 byte threshold interrupt mask
 */
class thr512m_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr thr512m_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device disconnection mask 
 */
class ddiscm_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddiscm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * HOST mode 
 */
class host_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr host_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_cntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_cntr_r>() const {return opsy::utility::clear_set<usb_cntr_r>(mask, *this);}
	constexpr auto operator|(usb_cntr_r other) const -> usb_cntr_r { return static_cast<usb_cntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_cntr_r> other) const -> opsy::utility::clear_set<usb_cntr_r> {return opsy::utility::clear_set<usb_cntr_r>(usb_cntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto usbrst() const -> usbrst_f {return usbrst_f((value_ & usbrst_f::mask) != 0);}
	[[nodiscard]] constexpr auto pdwn() const -> pdwn_f {return pdwn_f((value_ & pdwn_f::mask) != 0);}
	[[nodiscard]] constexpr auto susprdy() const -> susprdy_f {return susprdy_f((value_ & susprdy_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspen() const -> suspen_f {return suspen_f((value_ & suspen_f::mask) != 0);}
	[[nodiscard]] constexpr auto l2res() const -> l2res_f {return l2res_f((value_ & l2res_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1res() const -> l1res_f {return l1res_f((value_ & l1res_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1reqm() const -> l1reqm_f {return l1reqm_f((value_ & l1reqm_f::mask) != 0);}
	[[nodiscard]] constexpr auto esofm() const -> esofm_f {return esofm_f((value_ & esofm_f::mask) != 0);}
	[[nodiscard]] constexpr auto sofm() const -> sofm_f {return sofm_f((value_ & sofm_f::mask) != 0);}
	[[nodiscard]] constexpr auto rst_dconm() const -> rst_dconm_f {return rst_dconm_f((value_ & rst_dconm_f::mask) != 0);}
	[[nodiscard]] constexpr auto suspm() const -> suspm_f {return suspm_f((value_ & suspm_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkupm() const -> wkupm_f {return wkupm_f((value_ & wkupm_f::mask) != 0);}
	[[nodiscard]] constexpr auto errm() const -> errm_f {return errm_f((value_ & errm_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmaovrm() const -> pmaovrm_f {return pmaovrm_f((value_ & pmaovrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctrm() const -> ctrm_f {return ctrm_f((value_ & ctrm_f::mask) != 0);}
	[[nodiscard]] constexpr auto thr512m() const -> thr512m_f {return thr512m_f((value_ & thr512m_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddiscm() const -> ddiscm_f {return ddiscm_f((value_ & ddiscm_f::mask) != 0);}
	[[nodiscard]] constexpr auto host() const -> host_f {return host_f((value_ & host_f::mask) != 0);}

	constexpr usb_cntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_cntr_r other) const -> usb_cntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_cntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11; // 3 0x3

private:
	uint32_t value_;
};

/**
 * USB interrupt status register
 */
class usb_istr_r {
public:

/**
 * Device Endpoint / host channel identification number 
 */
class idn_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr idn_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_istr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Direction of transaction 
 */
class dir_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dir_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM L1 state request 
 */
class l1req_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr l1req_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Expected start of frame 
 */
class esof_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr esof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Start of frame 
 */
class sof_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr sof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * USB reset request (Device mode) or device connect/disconnect (Host mode) 
 */
class rst_dcon_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rst_dcon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Suspend mode request 
 */
class susp_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr susp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wake-up 
 */
class wkup_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wkup_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Error 
 */
class err_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr err_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Packet memory area over / underrun 
 */
class pmaovr_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr pmaovr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Completed transfer in host mode 
 */
class ctr_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr ctr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * 512 byte threshold interrupt 
 */
class thr512_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr thr512_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device connection 
 */
class ddisc_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddisc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Device connection status 
 */
class dcon_stat_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dcon_stat_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Low speed device connected 
 */
class ls_dcon_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ls_dcon_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_istr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_istr_r>() const {return opsy::utility::clear_set<usb_istr_r>(mask, *this);}
	constexpr auto operator|(usb_istr_r other) const -> usb_istr_r { return static_cast<usb_istr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_istr_r> other) const -> opsy::utility::clear_set<usb_istr_r> {return opsy::utility::clear_set<usb_istr_r>(usb_istr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto idn() const -> idn_f {return idn_f(static_cast<uint8_t>(value_ >> idn_f::offset));}
	[[nodiscard]] constexpr auto dir() const -> dir_f {return dir_f((value_ & dir_f::mask) != 0);}
	[[nodiscard]] constexpr auto l1req() const -> l1req_f {return l1req_f((value_ & l1req_f::mask) != 0);}
	[[nodiscard]] constexpr auto esof() const -> esof_f {return esof_f((value_ & esof_f::mask) != 0);}
	[[nodiscard]] constexpr auto sof() const -> sof_f {return sof_f((value_ & sof_f::mask) != 0);}
	[[nodiscard]] constexpr auto rst_dcon() const -> rst_dcon_f {return rst_dcon_f((value_ & rst_dcon_f::mask) != 0);}
	[[nodiscard]] constexpr auto susp() const -> susp_f {return susp_f((value_ & susp_f::mask) != 0);}
	[[nodiscard]] constexpr auto wkup() const -> wkup_f {return wkup_f((value_ & wkup_f::mask) != 0);}
	[[nodiscard]] constexpr auto err() const -> err_f {return err_f((value_ & err_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmaovr() const -> pmaovr_f {return pmaovr_f((value_ & pmaovr_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctr() const -> ctr_f {return ctr_f((value_ & ctr_f::mask) != 0);}
	[[nodiscard]] constexpr auto thr512() const -> thr512_f {return thr512_f((value_ & thr512_f::mask) != 0);}
	[[nodiscard]] constexpr auto ddisc() const -> ddisc_f {return ddisc_f((value_ & ddisc_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcon_stat() const -> dcon_stat_f {return dcon_stat_f((value_ & dcon_stat_f::mask) != 0);}
	[[nodiscard]] constexpr auto ls_dcon() const -> ls_dcon_f {return ls_dcon_f((value_ & ls_dcon_f::mask) != 0);}

	constexpr usb_istr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_istr_r other) const -> usb_istr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_istr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB frame number register
 */
class usb_fnr_r {
public:

/**
 * Frame number 
 */
class fn_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 11;
	static constexpr uint16_t range = static_cast<uint16_t>(0b11111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fn_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator usb_fnr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Lost SOF 
 */
class lsof_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr lsof_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_fnr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Locked 
 */
class lck_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr lck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data - line status 
 */
class rxdm_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Receive data + line status 
 */
class rxdp_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rxdp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_fnr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_fnr_r>() const {return opsy::utility::clear_set<usb_fnr_r>(mask, *this);}
	constexpr auto operator|(usb_fnr_r other) const -> usb_fnr_r { return static_cast<usb_fnr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_fnr_r> other) const -> opsy::utility::clear_set<usb_fnr_r> {return opsy::utility::clear_set<usb_fnr_r>(usb_fnr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto fn() const -> fn_f {return fn_f(static_cast<uint16_t>(value_ >> fn_f::offset));}
	[[nodiscard]] constexpr auto lsof() const -> lsof_f {return lsof_f(static_cast<uint8_t>(value_ >> lsof_f::offset));}
	[[nodiscard]] constexpr auto lck() const -> lck_f {return lck_f((value_ & lck_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdm() const -> rxdm_f {return rxdm_f((value_ & rxdm_f::mask) != 0);}
	[[nodiscard]] constexpr auto rxdp() const -> rxdp_f {return rxdp_f((value_ & rxdp_f::mask) != 0);}

	constexpr usb_fnr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_fnr_r other) const -> usb_fnr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_fnr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * USB Device address
 */
class usb_daddr_r {
public:

/**
 * Device address 
 */
class add_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 7;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr add_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_daddr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_daddr_r>() const {return opsy::utility::clear_set<usb_daddr_r>(mask, *this);}
	constexpr auto operator|(usb_daddr_r other) const -> usb_daddr_r { return static_cast<usb_daddr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_daddr_r> other) const -> opsy::utility::clear_set<usb_daddr_r> {return opsy::utility::clear_set<usb_daddr_r>(usb_daddr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Enable function 
 */
class ef_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_daddr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_daddr_r>() const {return opsy::utility::clear_set<usb_daddr_r>(mask, *this);}
	constexpr auto operator|(usb_daddr_r other) const -> usb_daddr_r { return static_cast<usb_daddr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_daddr_r> other) const -> opsy::utility::clear_set<usb_daddr_r> {return opsy::utility::clear_set<usb_daddr_r>(usb_daddr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto add() const -> add_f {return add_f(static_cast<uint8_t>(value_ >> add_f::offset));}
	[[nodiscard]] constexpr auto ef() const -> ef_f {return ef_f((value_ & ef_f::mask) != 0);}

	constexpr usb_daddr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_daddr_r other) const -> usb_daddr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_daddr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * LPM control and status register
 */
class usb_lpmcsr_r {
public:

/**
 * LPM support enable 
 */
class lpmen_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpmen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * LPM token acknowledge enable 
 */
class lpmack_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lpmack_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * bRemoteWake value 
 */
class remwake_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr remwake_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * BESL value 
 */
class besl_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr besl_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator usb_lpmcsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<usb_lpmcsr_r>() const {return opsy::utility::clear_set<usb_lpmcsr_r>(mask, *this);}
	constexpr auto operator|(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return static_cast<usb_lpmcsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_lpmcsr_r> other) const -> opsy::utility::clear_set<usb_lpmcsr_r> {return opsy::utility::clear_set<usb_lpmcsr_r>(usb_lpmcsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lpmen() const -> lpmen_f {return lpmen_f((value_ & lpmen_f::mask) != 0);}
	[[nodiscard]] constexpr auto lpmack() const -> lpmack_f {return lpmack_f((value_ & lpmack_f::mask) != 0);}
	[[nodiscard]] constexpr auto remwake() const -> remwake_f {return remwake_f((value_ & remwake_f::mask) != 0);}
	[[nodiscard]] constexpr auto besl() const -> besl_f {return besl_f(static_cast<uint8_t>(value_ >> besl_f::offset));}

	constexpr usb_lpmcsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_lpmcsr_r other) const -> usb_lpmcsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_lpmcsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * Battery charging detector
 */
class usb_bcdr_r {
public:

/**
 * Battery charging detector (BCD) enable 
 */
class bcden_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr bcden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data contact detection (DCD) mode enable 
 */
class dcden_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Primary detection (PD) mode enable 
 */
class pden_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Secondary detection (SD) mode enable 
 */
class sden_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sden_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data contact detection (DCD) status 
 */
class dcdet_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dcdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Primary detection (PD) status 
 */
class pdet_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Secondary detection (SD) status 
 */
class sdet_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr sdet_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DM pull-up detection status 
 */
class ps2det_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ps2det_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DP pull-up / DPDM pull-down 
 */
class dppu_dpd_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr dppu_dpd_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator usb_bcdr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<usb_bcdr_r>() const {return opsy::utility::clear_set<usb_bcdr_r>(mask, *this);}
	constexpr auto operator|(usb_bcdr_r other) const -> usb_bcdr_r { return static_cast<usb_bcdr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<usb_bcdr_r> other) const -> opsy::utility::clear_set<usb_bcdr_r> {return opsy::utility::clear_set<usb_bcdr_r>(usb_bcdr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto bcden() const -> bcden_f {return bcden_f((value_ & bcden_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcden() const -> dcden_f {return dcden_f((value_ & dcden_f::mask) != 0);}
	[[nodiscard]] constexpr auto pden() const -> pden_f {return pden_f((value_ & pden_f::mask) != 0);}
	[[nodiscard]] constexpr auto sden() const -> sden_f {return sden_f((value_ & sden_f::mask) != 0);}
	[[nodiscard]] constexpr auto dcdet() const -> dcdet_f {return dcdet_f((value_ & dcdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto pdet() const -> pdet_f {return pdet_f((value_ & pdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdet() const -> sdet_f {return sdet_f((value_ & sdet_f::mask) != 0);}
	[[nodiscard]] constexpr auto ps2det() const -> ps2det_f {return ps2det_f((value_ & ps2det_f::mask) != 0);}
	[[nodiscard]] constexpr auto dppu_dpd() const -> dppu_dpd_f {return dppu_dpd_f((value_ & dppu_dpd_f::mask) != 0);}

	constexpr usb_bcdr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(usb_bcdr_r other) const -> usb_bcdr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> usb_bcdr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep0r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep1r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep2r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep3r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep4r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep5r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep6r;
	opsy::utility::memory<uint32_t,usb_chepxr_r> usb_chep7r;
	opsy::utility::padding<32> _p32;
	opsy::utility::memory<uint32_t,usb_cntr_r> usb_cntr;
	opsy::utility::memory<uint32_t,usb_istr_r> usb_istr;
	opsy::utility::read_only_memory<uint32_t,usb_fnr_r> usb_fnr;
	opsy::utility::memory<uint32_t,usb_daddr_r> usb_daddr;
	opsy::utility::padding<4> _p80;
	opsy::utility::memory<uint32_t,usb_lpmcsr_r> usb_lpmcsr;
	opsy::utility::memory<uint32_t,usb_bcdr_r> usb_bcdr;
};

static_assert(std::is_standard_layout_v<usb_p>);
static_assert(offsetof(usb_p, usb_chep0r) == 0);
static_assert(offsetof(usb_p, usb_chep1r) == 4);
static_assert(offsetof(usb_p, usb_chep2r) == 8);
static_assert(offsetof(usb_p, usb_chep3r) == 12);
static_assert(offsetof(usb_p, usb_chep4r) == 16);
static_assert(offsetof(usb_p, usb_chep5r) == 20);
static_assert(offsetof(usb_p, usb_chep6r) == 24);
static_assert(offsetof(usb_p, usb_chep7r) == 28);
static_assert(offsetof(usb_p, usb_cntr) == 64);
static_assert(offsetof(usb_p, usb_istr) == 68);
static_assert(offsetof(usb_p, usb_fnr) == 72);
static_assert(offsetof(usb_p, usb_daddr) == 76);
static_assert(offsetof(usb_p, usb_lpmcsr) == 84);
static_assert(offsetof(usb_p, usb_bcdr) == 88);

inline usb_p& usb = *reinterpret_cast<usb_p*>(0x40016000);
inline usb_p& usb_s = *reinterpret_cast<usb_p*>(0x50016000);

} // STM32H523

