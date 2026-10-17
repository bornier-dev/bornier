#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Octo-SPI interface
 */
class octospi_p {
public:

/**
 * OCTOSPI control register 
 */
class octospi_cr_r {
public:

/**
 * Enable This bit enables the OCTOSPI. Note: The DMA request can be aborted without having received the ACK in case this EN bit is cleared during the operation. In case this bit is set to 0 during a DMA transfer, the REQ signal to DMA returns to inactive state without waiting for the ACK signal from DMA to be active.
 */
class en_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Abort request This bit aborts the ongoing command sequence. It is automatically reset once the abort is completed. This bit stops the current transfer. Note: This bit is always read as 0.
 */
class abort_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr abort_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DMA enable In Indirect mode, the DMA can be used to input or output data via OCTOSPI_DR. DMA transfers are initiated when FTF is set. Note: Resetting the DMAEN bit while a DMA transfer is ongoing, breaks the handshake with the DMA. Do not write this bit during DMA operation.
 */
class dmaen_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmaen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout counter enable This bit is valid only when the Memory-mapped mode (FMODE[1:0] = 11) is selected. This bit enables the timeout counter.
 */
class tcen_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Dual-memory configuration This bit activates the dual-memory configuration, where two external devices are used simultaneously to double the throughput and the capacity
 */
class dmm_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dmm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Flash select This bit selects the Flash memory to be addressed in Single-, Dual-, Quad-SPI mode in single-memory configuration (when DMM = 0). This bit is ignored when DMM = 1 or when Octal-SPI mode is selected.
 */
class fsel_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fsel_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold level This field defines, in Indirect mode, the threshold number of bytes in the FIFO that causes the FIFO threshold flag FTF in OCTOSPI_SR, to be set. ... Note: If DMAEN = 1, the DMA controller for the corresponding channel must be disabled before changing the FTHRES[4:0] value.
 */
class fthres_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr fthres_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_cr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Transfer error interrupt enable This bit enables the transfer error interrupt.
 */
class teie_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr teie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete interrupt enable This bit enables the transfer complete interrupt.
 */
class tcie_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tcie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold interrupt enable This bit enables the FIFO threshold interrupt.
 */
class ftie_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ftie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status match interrupt enable This bit enables the status match interrupt.
 */
class smie_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr smie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout interrupt enable This bit enables the timeout interrupt.
 */
class toie_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr toie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Automatic status-polling mode stop This bit determines if the Automatic status-polling mode is stopped after a match.
 */
class apms_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr apms_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Polling match mode This bit indicates which method must be used to determine a match during the Automatic status-polling mode.
 */
class pmm_f {
public:
	static constexpr std::size_t offset = 23;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr pmm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_cr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Functional mode This field defines the OCTOSPI functional mode of operation. If DMAEN = 1 already, then the DMA controller for the corresponding channel must be disabled before changing the FMODE[1:0] value. If FMODE[1:0] and FTHRES[4:0] are wrongly updated while DMAEN = 1, the DMA request signal automatically goes to inactive state.
 */
class fmode_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr fmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_cr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_cr_r>() const {return opsy::utility::clear_set<octospi_cr_r>(mask, *this);}
	constexpr auto operator|(octospi_cr_r other) const -> octospi_cr_r { return static_cast<octospi_cr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_cr_r> other) const -> opsy::utility::clear_set<octospi_cr_r> {return opsy::utility::clear_set<octospi_cr_r>(octospi_cr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto en() const -> en_f {return en_f((value_ & en_f::mask) != 0);}
	[[nodiscard]] constexpr auto abort() const -> abort_f {return abort_f((value_ & abort_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmaen() const -> dmaen_f {return dmaen_f((value_ & dmaen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcen() const -> tcen_f {return tcen_f((value_ & tcen_f::mask) != 0);}
	[[nodiscard]] constexpr auto dmm() const -> dmm_f {return dmm_f((value_ & dmm_f::mask) != 0);}
	[[nodiscard]] constexpr auto fsel() const -> fsel_f {return fsel_f((value_ & fsel_f::mask) != 0);}
	[[nodiscard]] constexpr auto fthres() const -> fthres_f {return fthres_f(static_cast<uint8_t>(value_ >> fthres_f::offset));}
	[[nodiscard]] constexpr auto teie() const -> teie_f {return teie_f((value_ & teie_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcie() const -> tcie_f {return tcie_f((value_ & tcie_f::mask) != 0);}
	[[nodiscard]] constexpr auto ftie() const -> ftie_f {return ftie_f((value_ & ftie_f::mask) != 0);}
	[[nodiscard]] constexpr auto smie() const -> smie_f {return smie_f((value_ & smie_f::mask) != 0);}
	[[nodiscard]] constexpr auto toie() const -> toie_f {return toie_f((value_ & toie_f::mask) != 0);}
	[[nodiscard]] constexpr auto apms() const -> apms_f {return apms_f((value_ & apms_f::mask) != 0);}
	[[nodiscard]] constexpr auto pmm() const -> pmm_f {return pmm_f((value_ & pmm_f::mask) != 0);}
	[[nodiscard]] constexpr auto fmode() const -> fmode_f {return fmode_f(static_cast<uint8_t>(value_ >> fmode_f::offset));}

	constexpr octospi_cr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_cr_r other) const -> octospi_cr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_cr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 1 
 */
class octospi_dcr1_r {
public:

/**
 * Mode 0/Mode 3 This bit indicates the level taken by the CLK between commands (when NCS = 1).
 */
class ckmode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ckmode_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Free running clock This bit configures the free running clock.
 */
class frck_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr frck_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Delay block bypass
 */
class dlybyp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr dlybyp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Chip-select high time CSHT + 1 defines the minimum number of CLK cycles where the chip-select (NCS) must remain high between commands issued to the external device. ...
 */
class csht_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr csht_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Device size This field defines the size of the external device using the following formula: Number of bytes in device = 2[DEVSIZE+1]. DEVSIZE+1 is effectively the number of address bits required to address the external device. The device capacity can be up to 4 Gbytes (addressed using 32-bits) in Indirect mode, but the addressable space in Memory-mapped mode is limited to 256 Mbytes. In Regular-command protocol, if DMM = 1, DEVSIZE[4:0] indicates the total capacity of the two devices together.
 */
class devsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr devsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Memory type This bit indicates the type of memory to be supported. Note: In this mode, DQS signal polarity is inverted with respect to the memory clock signal. This is the default value and care must be taken to change MTYP[2:0] for memories different from Micron. Others: Reserved
 */
class mtyp_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mtyp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr1_r>() const {return opsy::utility::clear_set<octospi_dcr1_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr1_r other) const -> octospi_dcr1_r { return static_cast<octospi_dcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr1_r> other) const -> opsy::utility::clear_set<octospi_dcr1_r> {return opsy::utility::clear_set<octospi_dcr1_r>(octospi_dcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto ckmode() const -> ckmode_f {return ckmode_f((value_ & ckmode_f::mask) != 0);}
	[[nodiscard]] constexpr auto frck() const -> frck_f {return frck_f((value_ & frck_f::mask) != 0);}
	[[nodiscard]] constexpr auto dlybyp() const -> dlybyp_f {return dlybyp_f((value_ & dlybyp_f::mask) != 0);}
	[[nodiscard]] constexpr auto csht() const -> csht_f {return csht_f(static_cast<uint8_t>(value_ >> csht_f::offset));}
	[[nodiscard]] constexpr auto devsize() const -> devsize_f {return devsize_f(static_cast<uint8_t>(value_ >> devsize_f::offset));}
	[[nodiscard]] constexpr auto mtyp() const -> mtyp_f {return mtyp_f(static_cast<uint8_t>(value_ >> mtyp_f::offset));}

	constexpr octospi_dcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr1_r other) const -> octospi_dcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 2 
 */
class octospi_dcr2_r {
public:

/**
 * Clock prescaler This field defines the scaler factor for generating the CLK based on the kernel clock (value + 1). 2: FCLK = FKERNEL/3 ... 255: FCLK = FKERNEL/256 For odd clock division factors, the CLK duty cycle is not 50 %. The clock signal remains low one cycle longer than it stays high.
 */
class prescaler_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr prescaler_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr2_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr2_r>() const {return opsy::utility::clear_set<octospi_dcr2_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr2_r other) const -> octospi_dcr2_r { return static_cast<octospi_dcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr2_r> other) const -> opsy::utility::clear_set<octospi_dcr2_r> {return opsy::utility::clear_set<octospi_dcr2_r>(octospi_dcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Wrap size This field indicates the wrap size to which the memory is configured. For memories which have a separate command for wrapped instructions, this field indicates the wrap-size associated with the command held in the OCTOSPI1_WPIR register. 110-111: Reserved
 */
class wrapsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr wrapsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr2_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr2_r>() const {return opsy::utility::clear_set<octospi_dcr2_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr2_r other) const -> octospi_dcr2_r { return static_cast<octospi_dcr2_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr2_r> other) const -> opsy::utility::clear_set<octospi_dcr2_r> {return opsy::utility::clear_set<octospi_dcr2_r>(octospi_dcr2_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto prescaler() const -> prescaler_f {return prescaler_f(static_cast<uint8_t>(value_ >> prescaler_f::offset));}
	[[nodiscard]] constexpr auto wrapsize() const -> wrapsize_f {return wrapsize_f(static_cast<uint8_t>(value_ >> wrapsize_f::offset));}

	constexpr octospi_dcr2_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr2_r other) const -> octospi_dcr2_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr2_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 3 
 */
class octospi_dcr3_r {
public:

/**
 * NCS boundary This field enables the transaction boundary feature. When active, a minimum value of 3 is recommended. The NCS is released on each boundary of 2CSBOUND bytes. others: NCS boundary set to 2CSBOUND bytes
 */
class csbound_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr csbound_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_dcr3_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr3_r>() const {return opsy::utility::clear_set<octospi_dcr3_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr3_r other) const -> octospi_dcr3_r { return static_cast<octospi_dcr3_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr3_r> other) const -> opsy::utility::clear_set<octospi_dcr3_r> {return opsy::utility::clear_set<octospi_dcr3_r>(octospi_dcr3_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto csbound() const -> csbound_f {return csbound_f(static_cast<uint8_t>(value_ >> csbound_f::offset));}

	constexpr octospi_dcr3_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr3_r other) const -> octospi_dcr3_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr3_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI device configuration register 4 
 */
class octospi_dcr4_r {
public:

/**
 * Refresh rate This field enables the refresh rate feature. The NCS is released every REFRESH + 1 clock cycles for writes, and REFRESH + 4 clock cycles for reads. Note: These two values can be extended with few clock cycles when refresh occurs during a byte transmission in Single-, Dual- or Quad-SPI mode, because the byte transmission must be completed. others: Maximum communication length is set to REFRESH + 1 clock cycles.
 */
class refresh_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr refresh_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dcr4_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dcr4_r>() const {return opsy::utility::clear_set<octospi_dcr4_r>(mask, *this);}
	constexpr auto operator|(octospi_dcr4_r other) const -> octospi_dcr4_r { return static_cast<octospi_dcr4_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dcr4_r> other) const -> opsy::utility::clear_set<octospi_dcr4_r> {return opsy::utility::clear_set<octospi_dcr4_r>(octospi_dcr4_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto refresh() const -> refresh_f {return refresh_f(static_cast<uint32_t>(value_ >> refresh_f::offset));}

	constexpr octospi_dcr4_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dcr4_r other) const -> octospi_dcr4_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dcr4_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI status register 
 */
class octospi_sr_r {
public:

/**
 * Transfer error flag This bit is set in Indirect mode when an invalid address is being accessed in Indirect mode. It is cleared by writing 1 to CTEF.
 */
class tef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Transfer complete flag This bit is set in Indirect mode when the programmed number of data has been transferred or in any mode when the transfer has been aborted.It is cleared by writing 1 to CTCF.
 */
class tcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO threshold flag In Indirect mode, this bit is set when the FIFO threshold has been reached, or if there is any data left in the FIFO after the reads from the external device are complete. It is cleared automatically as soon as the threshold condition is no longer true. In Automatic status-polling mode, this bit is set every time the status register is read, and the bit is cleared when the data register is read.
 */
class ftf_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ftf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status match flag This bit is set in Automatic status-polling mode when the unmasked received data matches the corresponding bits in the match register (OCTOSPI_PSMAR). It is cleared by writing 1 to CSMF.
 */
class smf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr smf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Timeout flag This bit is set when timeout occurs. It is cleared by writing 1 to CTOF.
 */
class tof_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr tof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Busy This bit is set when an operation is ongoing. It is cleared automatically when the operation with the external device is finished and the FIFO is empty.
 */
class busy_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO level This field gives the number of valid bytes that are being held in the FIFO. FLEVEL = 0 when the FIFO is empty, and 32 when it is full. In Automatic status-polling mode, FLEVEL is zero.
 */
class flevel_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 6;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr flevel_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_sr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_sr_r>() const {return opsy::utility::clear_set<octospi_sr_r>(mask, *this);}
	constexpr auto operator|(octospi_sr_r other) const -> octospi_sr_r { return static_cast<octospi_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_sr_r> other) const -> opsy::utility::clear_set<octospi_sr_r> {return opsy::utility::clear_set<octospi_sr_r>(octospi_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tef() const -> tef_f {return tef_f((value_ & tef_f::mask) != 0);}
	[[nodiscard]] constexpr auto tcf() const -> tcf_f {return tcf_f((value_ & tcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ftf() const -> ftf_f {return ftf_f((value_ & ftf_f::mask) != 0);}
	[[nodiscard]] constexpr auto smf() const -> smf_f {return smf_f((value_ & smf_f::mask) != 0);}
	[[nodiscard]] constexpr auto tof() const -> tof_f {return tof_f((value_ & tof_f::mask) != 0);}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}
	[[nodiscard]] constexpr auto flevel() const -> flevel_f {return flevel_f(static_cast<uint8_t>(value_ >> flevel_f::offset));}

	constexpr octospi_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_sr_r other) const -> octospi_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI flag clear register 
 */
class octospi_fcr_r {
public:

/**
 * Clear transfer error flag Writing 1 clears the TEF flag in the OCTOSPI_SR register.
 */
class ctef_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctef_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear transfer complete flag Writing 1 clears the TCF flag in the OCTOSPI_SR register.
 */
class ctcf_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctcf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear status match flag Writing 1 clears the SMF flag in the OCTOSPI_SR register.
 */
class csmf_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr csmf_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Clear timeout flag Writing 1 clears the TOF flag in the OCTOSPI_SR register.
 */
class ctof_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctof_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_fcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_fcr_r>() const {return opsy::utility::clear_set<octospi_fcr_r>(mask, *this);}
	constexpr auto operator|(octospi_fcr_r other) const -> octospi_fcr_r { return static_cast<octospi_fcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_fcr_r> other) const -> opsy::utility::clear_set<octospi_fcr_r> {return opsy::utility::clear_set<octospi_fcr_r>(octospi_fcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto ctef() const -> ctef_f {return ctef_f((value_ & ctef_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctcf() const -> ctcf_f {return ctcf_f((value_ & ctcf_f::mask) != 0);}
	[[nodiscard]] constexpr auto csmf() const -> csmf_f {return csmf_f((value_ & csmf_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctof() const -> ctof_f {return ctof_f((value_ & ctof_f::mask) != 0);}

	constexpr octospi_fcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_fcr_r other) const -> octospi_fcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_fcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI data length register 
 */
class octospi_dlr_r {
public:

/**
 * [31: 0]: Data length Number of data to be retrieved (value+1) in Indirect and Automatic status-polling modes. A value not greater than three (indicating 4 bytes) must be used for Automatic status-polling mode. All 1's in Indirect mode means undefined length, where OCTOSPI continues until the end of the memory, as defined by DEVSIZE. 0x0000_0000: 1 byte is to be transferred. 0x0000_0001: 2 bytes are to be transferred. 0x0000_0002: 3 bytes are to be transferred. 0x0000_0003: 4 bytes are to be transferred. ... 0xFFFF_FFFD: 4,294,967,294 (4G-2) bytes are to be transferred. 0xFFFF_FFFE: 4,294,967,295 (4G-1) bytes are to be transferred. 0xFFFF_FFFF: undefined length; all bytes, until the end of the external device, (as defined by DEVSIZE) are to be transferred. Continue reading indefinitely if DEVSIZE = 0x1F. DL[0] is stuck at 1 in dual-memory configuration (DMM = 1) even when 0 is written to this bit, thus assuring that each access transfers an even number of bytes. This field has no effect in Memory-mapped mode.
 */
class dl_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dl_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dlr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dlr_r>() const {return opsy::utility::clear_set<octospi_dlr_r>(mask, *this);}
	constexpr auto operator|(octospi_dlr_r other) const -> octospi_dlr_r { return static_cast<octospi_dlr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dlr_r> other) const -> opsy::utility::clear_set<octospi_dlr_r> {return opsy::utility::clear_set<octospi_dlr_r>(octospi_dlr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto dl() const -> dl_f {return dl_f(static_cast<uint32_t>(value_ >> dl_f::offset));}

	constexpr octospi_dlr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dlr_r other) const -> octospi_dlr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dlr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI address register 
 */
class octospi_ar_r {
public:

/**
 * Address Address to be sent to the external device. In HyperBus protocol, this field must be even as this protocol is 16-bit word oriented. In dual-memory configuration, AR[0] is forced to 1. Writes to this field are ignored when BUSY = 1 or when FMODE = 11 (Memory-mapped mode).
 */
class address_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr address_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_ar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ar_r>() const {return opsy::utility::clear_set<octospi_ar_r>(mask, *this);}
	constexpr auto operator|(octospi_ar_r other) const -> octospi_ar_r { return static_cast<octospi_ar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ar_r> other) const -> opsy::utility::clear_set<octospi_ar_r> {return opsy::utility::clear_set<octospi_ar_r>(octospi_ar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto address() const -> address_f {return address_f(static_cast<uint32_t>(value_ >> address_f::offset));}

	constexpr octospi_ar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ar_r other) const -> octospi_ar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI data register 
 */
class octospi_dr_r {
public:

/**
 * [31: 0]: Data Data to be sent/received to/from the external SPI device In Indirect-write mode, data written to this register is stored on the FIFO before it is sent to the external device during the data phase. If the FIFO is too full, a write operation is stalled until the FIFO has enough space to accept the amount of data being written. In Indirect-read mode, reading this register gives (via the FIFO) the data that was received from the external device. If the FIFO does not have as many bytes as requested by the read operation and if BUSY = 1, the read operation is stalled until enough data is present or until the transfer is complete, whichever happens first. In Automatic status-polling mode, this register contains the last data read from the external device (without masking). Word, half-word, and byte accesses to this register are supported. In Indirect-write mode, a byte write adds 1 byte to the FIFO, a half-word write 2 bytes, and a word write 4 bytes. Similarly, in Indirect-read mode, a byte read removes 1 byte from the FIFO, a halfword read 2 bytes, and a word read 4 bytes. Accesses in Indirect mode must be aligned to the bottom of this register: A byte read must read DATA[7:0] and a half-word read must read DATA[15:0].
 */
class data_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr data_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_dr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_dr_r>() const {return opsy::utility::clear_set<octospi_dr_r>(mask, *this);}
	constexpr auto operator|(octospi_dr_r other) const -> octospi_dr_r { return static_cast<octospi_dr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_dr_r> other) const -> opsy::utility::clear_set<octospi_dr_r> {return opsy::utility::clear_set<octospi_dr_r>(octospi_dr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto data() const -> data_f {return data_f(static_cast<uint32_t>(value_ >> data_f::offset));}

	constexpr octospi_dr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_dr_r other) const -> octospi_dr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_dr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling status mask register 
 */
class octospi_psmkr_r {
public:

/**
 * Status mask Mask to be applied to the status bytes received in Automatic status-polling mode For bit n:
 */
class mask_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mask_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_psmkr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_psmkr_r>() const {return opsy::utility::clear_set<octospi_psmkr_r>(mask, *this);}
	constexpr auto operator|(octospi_psmkr_r other) const -> octospi_psmkr_r { return static_cast<octospi_psmkr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_psmkr_r> other) const -> opsy::utility::clear_set<octospi_psmkr_r> {return opsy::utility::clear_set<octospi_psmkr_r>(octospi_psmkr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto mask() const -> mask_f {return mask_f(static_cast<uint32_t>(value_ >> mask_f::offset));}

	constexpr octospi_psmkr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_psmkr_r other) const -> octospi_psmkr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_psmkr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling status match register 
 */
class octospi_psmar_r {
public:

/**
 * [31: 0]: Status match Value to be compared with the masked status register to get a match
 */
class match_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr match_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_psmar_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_psmar_r>() const {return opsy::utility::clear_set<octospi_psmar_r>(mask, *this);}
	constexpr auto operator|(octospi_psmar_r other) const -> octospi_psmar_r { return static_cast<octospi_psmar_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_psmar_r> other) const -> opsy::utility::clear_set<octospi_psmar_r> {return opsy::utility::clear_set<octospi_psmar_r>(octospi_psmar_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto match() const -> match_f {return match_f(static_cast<uint32_t>(value_ >> match_f::offset));}

	constexpr octospi_psmar_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_psmar_r other) const -> octospi_psmar_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_psmar_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI polling interval register 
 */
class octospi_pir_r {
public:

/**
 * [15: 0]: Polling interval Number of CLK cycle between a read during the Automatic status-polling phases
 */
class interval_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr interval_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator octospi_pir_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_pir_r>() const {return opsy::utility::clear_set<octospi_pir_r>(mask, *this);}
	constexpr auto operator|(octospi_pir_r other) const -> octospi_pir_r { return static_cast<octospi_pir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_pir_r> other) const -> opsy::utility::clear_set<octospi_pir_r> {return opsy::utility::clear_set<octospi_pir_r>(octospi_pir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto interval() const -> interval_f {return interval_f(static_cast<uint16_t>(value_ >> interval_f::offset));}

	constexpr octospi_pir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_pir_r other) const -> octospi_pir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_pir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI communication configuration register 
 */
class octospi_ccr_r {
public:

/**
 * Instruction mode This field defines the instruction phase mode of operation. 101-111: Reserved
 */
class imode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr imode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Instruction double transfer rate This bit sets the DTR mode for the instruction phase.
 */
class idtr_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Instruction size This bit defines instruction size.
 */
class isize_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr isize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address mode This field defines the address phase mode of operation. 101-111: Reserved
 */
class admode_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr admode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address double transfer rate This bit sets the DTR mode for the address phase.
 */
class addtr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr addtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address size This field defines address size.
 */
class adsize_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr adsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate-byte mode This field defines the alternate-byte phase mode of operation. 101-111: Reserved
 */
class abmode_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr abmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate bytes double transfer rate This bit sets the DTR mode for the alternate bytes phase. This field can be written only when BUSY = 0.
 */
class abdtr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abdtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alternate bytes size This bit defines alternate bytes size.
 */
class absize_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr absize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data mode This field defines the data phase mode of operation. 101-111: Reserved
 */
class dmode_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_ccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data double transfer rate This bit sets the DTR mode for the data phase.
 */
class ddtr_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DQS enable This bit enables the data strobe management.
 */
class dqse_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dqse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Send instruction only once mode This bit has no effect when IMODE = 00 (see ).
 */
class sioo_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sioo_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_ccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_ccr_r>() const {return opsy::utility::clear_set<octospi_ccr_r>(mask, *this);}
	constexpr auto operator|(octospi_ccr_r other) const -> octospi_ccr_r { return static_cast<octospi_ccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ccr_r> other) const -> opsy::utility::clear_set<octospi_ccr_r> {return opsy::utility::clear_set<octospi_ccr_r>(octospi_ccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto imode() const -> imode_f {return imode_f(static_cast<uint8_t>(value_ >> imode_f::offset));}
	[[nodiscard]] constexpr auto idtr() const -> idtr_f {return idtr_f((value_ & idtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto isize() const -> isize_f {return isize_f(static_cast<uint8_t>(value_ >> isize_f::offset));}
	[[nodiscard]] constexpr auto admode() const -> admode_f {return admode_f(static_cast<uint8_t>(value_ >> admode_f::offset));}
	[[nodiscard]] constexpr auto addtr() const -> addtr_f {return addtr_f((value_ & addtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto adsize() const -> adsize_f {return adsize_f(static_cast<uint8_t>(value_ >> adsize_f::offset));}
	[[nodiscard]] constexpr auto abmode() const -> abmode_f {return abmode_f(static_cast<uint8_t>(value_ >> abmode_f::offset));}
	[[nodiscard]] constexpr auto abdtr() const -> abdtr_f {return abdtr_f((value_ & abdtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto absize() const -> absize_f {return absize_f(static_cast<uint8_t>(value_ >> absize_f::offset));}
	[[nodiscard]] constexpr auto dmode() const -> dmode_f {return dmode_f(static_cast<uint8_t>(value_ >> dmode_f::offset));}
	[[nodiscard]] constexpr auto ddtr() const -> ddtr_f {return ddtr_f((value_ & ddtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto dqse() const -> dqse_f {return dqse_f((value_ & dqse_f::mask) != 0);}
	[[nodiscard]] constexpr auto sioo() const -> sioo_f {return sioo_f((value_ & sioo_f::mask) != 0);}

	constexpr octospi_ccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ccr_r other) const -> octospi_ccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI timing configuration register 
 */
class octospi_tcr_r {
public:

/**
 * Number of dummy cycles This field defines the duration of the dummy phase. In both SDR and DTR modes, it specifies a number of CLK cycles (0-31). It is recommended to have at least six dummy cycles when using memories with DQS activated.
 */
class dcyc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dcyc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_tcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Delay hold quarter cycle
 */
class dhqc_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dhqc_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_tcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Sample shift By default, the OCTOSPI samples data 1/2 of a CLK cycle after the data is driven by the external device. This bit allows the data to be sampled later in order to consider the external signal delays. The software must ensure that SSHIFT = 0 when the data phase is configured in DTR mode (when DDTR = 1.)
 */
class sshift_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr sshift_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_tcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_tcr_r>() const {return opsy::utility::clear_set<octospi_tcr_r>(mask, *this);}
	constexpr auto operator|(octospi_tcr_r other) const -> octospi_tcr_r { return static_cast<octospi_tcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_tcr_r> other) const -> opsy::utility::clear_set<octospi_tcr_r> {return opsy::utility::clear_set<octospi_tcr_r>(octospi_tcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto dcyc() const -> dcyc_f {return dcyc_f(static_cast<uint8_t>(value_ >> dcyc_f::offset));}
	[[nodiscard]] constexpr auto dhqc() const -> dhqc_f {return dhqc_f((value_ & dhqc_f::mask) != 0);}
	[[nodiscard]] constexpr auto sshift() const -> sshift_f {return sshift_f((value_ & sshift_f::mask) != 0);}

	constexpr octospi_tcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_tcr_r other) const -> octospi_tcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_tcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI instruction register 
 */
class octospi_ir_r {
public:

/**
 * Instruction Instruction to be sent to the external SPI device
 */
class instruction_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr instruction_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_ir_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_ir_r>() const {return opsy::utility::clear_set<octospi_ir_r>(mask, *this);}
	constexpr auto operator|(octospi_ir_r other) const -> octospi_ir_r { return static_cast<octospi_ir_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_ir_r> other) const -> opsy::utility::clear_set<octospi_ir_r> {return opsy::utility::clear_set<octospi_ir_r>(octospi_ir_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto instruction() const -> instruction_f {return instruction_f(static_cast<uint32_t>(value_ >> instruction_f::offset));}

	constexpr octospi_ir_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_ir_r other) const -> octospi_ir_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_ir_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI alternate bytes register 
 */
class octospi_abr_r {
public:

/**
 * [31: 0]: Alternate bytes Optional data to be sent to the external SPI device right after the address.
 */
class alternate_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr alternate_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator octospi_abr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_abr_r>() const {return opsy::utility::clear_set<octospi_abr_r>(mask, *this);}
	constexpr auto operator|(octospi_abr_r other) const -> octospi_abr_r { return static_cast<octospi_abr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_abr_r> other) const -> opsy::utility::clear_set<octospi_abr_r> {return opsy::utility::clear_set<octospi_abr_r>(octospi_abr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto alternate() const -> alternate_f {return alternate_f(static_cast<uint32_t>(value_ >> alternate_f::offset));}

	constexpr octospi_abr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_abr_r other) const -> octospi_abr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_abr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI low-power timeout register 
 */
class octospi_lptr_r {
public:

/**
 * [15: 0]: Timeout period After each access in Memory-mapped mode, the OCTOSPI prefetches the subsequent bytes and hold them in the FIFO. This field indicates how many CLK cycles the OCTOSPI waits after the clock becomes inactive and until it raises the NCS, putting the external device in a lower-consumption state.
 */
class timeout_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr timeout_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator octospi_lptr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_lptr_r>() const {return opsy::utility::clear_set<octospi_lptr_r>(mask, *this);}
	constexpr auto operator|(octospi_lptr_r other) const -> octospi_lptr_r { return static_cast<octospi_lptr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_lptr_r> other) const -> opsy::utility::clear_set<octospi_lptr_r> {return opsy::utility::clear_set<octospi_lptr_r>(octospi_lptr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto timeout() const -> timeout_f {return timeout_f(static_cast<uint16_t>(value_ >> timeout_f::offset));}

	constexpr octospi_lptr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_lptr_r other) const -> octospi_lptr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_lptr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI wrap communication configuration register 
 */
class octospi_wpccr_r {
public:

/**
 * Instruction mode This field defines the instruction phase mode of operation. 101-111: Reserved
 */
class imode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr imode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Instruction double transfer rate This bit sets the DTR mode for the instruction phase.
 */
class idtr_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr idtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Instruction size This field defines instruction size.
 */
class isize_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr isize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address mode This field defines the address phase mode of operation. 101-111: Reserved
 */
class admode_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr admode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address double transfer rate This bit sets the DTR mode for the address phase.
 */
class addtr_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr addtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address size This field defines address size.
 */
class adsize_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr adsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate-byte mode This field defines the alternate byte phase mode of operation. 101-111: Reserved
 */
class abmode_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr abmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Alternate bytes double transfer rate This bit sets the DTR mode for the alternate bytes phase.
 */
class abdtr_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr abdtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Alternate bytes size This bit defines alternate bytes size.
 */
class absize_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr absize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data mode This field defines the data phase mode of operation. 101-111: Reserved
 */
class dmode_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr dmode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data double transfer rate This bit sets the DTR mode for the data phase.
 */
class ddtr_f {
public:
	static constexpr std::size_t offset = 27;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr ddtr_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * DQS enable This bit enables the data strobe management.
 */
class dqse_f {
public:
	static constexpr std::size_t offset = 29;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr dqse_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_wpccr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_wpccr_r>() const {return opsy::utility::clear_set<octospi_wpccr_r>(mask, *this);}
	constexpr auto operator|(octospi_wpccr_r other) const -> octospi_wpccr_r { return static_cast<octospi_wpccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wpccr_r> other) const -> opsy::utility::clear_set<octospi_wpccr_r> {return opsy::utility::clear_set<octospi_wpccr_r>(octospi_wpccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto imode() const -> imode_f {return imode_f(static_cast<uint8_t>(value_ >> imode_f::offset));}
	[[nodiscard]] constexpr auto idtr() const -> idtr_f {return idtr_f((value_ & idtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto isize() const -> isize_f {return isize_f(static_cast<uint8_t>(value_ >> isize_f::offset));}
	[[nodiscard]] constexpr auto admode() const -> admode_f {return admode_f(static_cast<uint8_t>(value_ >> admode_f::offset));}
	[[nodiscard]] constexpr auto addtr() const -> addtr_f {return addtr_f((value_ & addtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto adsize() const -> adsize_f {return adsize_f(static_cast<uint8_t>(value_ >> adsize_f::offset));}
	[[nodiscard]] constexpr auto abmode() const -> abmode_f {return abmode_f(static_cast<uint8_t>(value_ >> abmode_f::offset));}
	[[nodiscard]] constexpr auto abdtr() const -> abdtr_f {return abdtr_f((value_ & abdtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto absize() const -> absize_f {return absize_f(static_cast<uint8_t>(value_ >> absize_f::offset));}
	[[nodiscard]] constexpr auto dmode() const -> dmode_f {return dmode_f(static_cast<uint8_t>(value_ >> dmode_f::offset));}
	[[nodiscard]] constexpr auto ddtr() const -> ddtr_f {return ddtr_f((value_ & ddtr_f::mask) != 0);}
	[[nodiscard]] constexpr auto dqse() const -> dqse_f {return dqse_f((value_ & dqse_f::mask) != 0);}

	constexpr octospi_wpccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_wpccr_r other) const -> octospi_wpccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_wpccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI write timing configuration register 
 */
class octospi_wtcr_r {
public:

/**
 * Number of dummy cycles This field defines the duration of the dummy phase. In both SDR and DTR modes, it specifies a number of CLK cycles (0-31). It is recommended to have at least 5 dummy cycles when using memories with DQS activated.
 */
class dcyc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 5;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr dcyc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_wtcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_wtcr_r>() const {return opsy::utility::clear_set<octospi_wtcr_r>(mask, *this);}
	constexpr auto operator|(octospi_wtcr_r other) const -> octospi_wtcr_r { return static_cast<octospi_wtcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_wtcr_r> other) const -> opsy::utility::clear_set<octospi_wtcr_r> {return opsy::utility::clear_set<octospi_wtcr_r>(octospi_wtcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto dcyc() const -> dcyc_f {return dcyc_f(static_cast<uint8_t>(value_ >> dcyc_f::offset));}

	constexpr octospi_wtcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_wtcr_r other) const -> octospi_wtcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_wtcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * OCTOSPI HyperBus latency configuration register 
 */
class octospi_hlcr_r {
public:

/**
 * Latency mode This bit selects the Latency mode.
 */
class lm_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr lm_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write zero latency This bit enables zero latency on write operations.
 */
class wzl_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr wzl_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * [7: 0]: Access time Device access time expressed in number of communication clock cycles
 */
class tacc_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tacc_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Read write recovery time Device read write recovery time expressed in number of communication clock cycles
 */
class trwr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trwr_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator octospi_hlcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<octospi_hlcr_r>() const {return opsy::utility::clear_set<octospi_hlcr_r>(mask, *this);}
	constexpr auto operator|(octospi_hlcr_r other) const -> octospi_hlcr_r { return static_cast<octospi_hlcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<octospi_hlcr_r> other) const -> opsy::utility::clear_set<octospi_hlcr_r> {return opsy::utility::clear_set<octospi_hlcr_r>(octospi_hlcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto lm() const -> lm_f {return lm_f((value_ & lm_f::mask) != 0);}
	[[nodiscard]] constexpr auto wzl() const -> wzl_f {return wzl_f((value_ & wzl_f::mask) != 0);}
	[[nodiscard]] constexpr auto tacc() const -> tacc_f {return tacc_f(static_cast<uint8_t>(value_ >> tacc_f::offset));}
	[[nodiscard]] constexpr auto trwr() const -> trwr_f {return trwr_f(static_cast<uint8_t>(value_ >> trwr_f::offset));}

	constexpr octospi_hlcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(octospi_hlcr_r other) const -> octospi_hlcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> octospi_hlcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,octospi_cr_r> octospi_cr;
	opsy::utility::padding<4> _p0;
	opsy::utility::memory<uint32_t,octospi_dcr1_r> octospi_dcr1;
	opsy::utility::memory<uint32_t,octospi_dcr2_r> octospi_dcr2;
	opsy::utility::memory<uint32_t,octospi_dcr3_r> octospi_dcr3;
	opsy::utility::memory<uint32_t,octospi_dcr4_r> octospi_dcr4;
	opsy::utility::padding<8> _p1;
	opsy::utility::memory<uint32_t,octospi_sr_r> octospi_sr;
	opsy::utility::memory<uint32_t,octospi_fcr_r> octospi_fcr;
	opsy::utility::padding<24> _p2;
	opsy::utility::memory<uint32_t,octospi_dlr_r> octospi_dlr;
	opsy::utility::padding<4> _p3;
	opsy::utility::memory<uint32_t,octospi_ar_r> octospi_ar;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,octospi_dr_r> octospi_dr;
	opsy::utility::padding<44> _p5;
	opsy::utility::memory<uint32_t,octospi_psmkr_r> octospi_psmkr;
	opsy::utility::padding<4> _p6;
	opsy::utility::memory<uint32_t,octospi_psmar_r> octospi_psmar;
	opsy::utility::padding<4> _p7;
	opsy::utility::memory<uint32_t,octospi_pir_r> octospi_pir;
	opsy::utility::padding<108> _p8;
	opsy::utility::memory<uint32_t,octospi_ccr_r> octospi_ccr;
	opsy::utility::padding<4> _p9;
	opsy::utility::memory<uint32_t,octospi_tcr_r> octospi_tcr;
	opsy::utility::padding<4> _p10;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_ir;
	opsy::utility::padding<12> _p11;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_abr;
	opsy::utility::padding<12> _p12;
	opsy::utility::memory<uint32_t,octospi_lptr_r> octospi_lptr;
	opsy::utility::padding<12> _p13;
	opsy::utility::memory<uint32_t,octospi_wpccr_r> octospi_wpccr;
	opsy::utility::padding<4> _p14;
	opsy::utility::memory<uint32_t,octospi_tcr_r> octospi_wptcr;
	opsy::utility::padding<4> _p15;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_wpir;
	opsy::utility::padding<12> _p16;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_wpabr;
	opsy::utility::padding<28> _p17;
	opsy::utility::memory<uint32_t,octospi_wpccr_r> octospi_wccr;
	opsy::utility::padding<4> _p18;
	opsy::utility::memory<uint32_t,octospi_wtcr_r> octospi_wtcr;
	opsy::utility::padding<4> _p19;
	opsy::utility::memory<uint32_t,octospi_ir_r> octospi_wir;
	opsy::utility::padding<12> _p20;
	opsy::utility::memory<uint32_t,octospi_abr_r> octospi_wabr;
	opsy::utility::padding<92> _p21;
	opsy::utility::memory<uint32_t,octospi_hlcr_r> octospi_hlcr;
};

static_assert(std::is_standard_layout_v<octospi_p>);
static_assert(offsetof(octospi_p, octospi_cr) == 0);
static_assert(offsetof(octospi_p, octospi_dcr1) == 8);
static_assert(offsetof(octospi_p, octospi_dcr2) == 12);
static_assert(offsetof(octospi_p, octospi_dcr3) == 16);
static_assert(offsetof(octospi_p, octospi_dcr4) == 20);
static_assert(offsetof(octospi_p, octospi_sr) == 32);
static_assert(offsetof(octospi_p, octospi_fcr) == 36);
static_assert(offsetof(octospi_p, octospi_dlr) == 64);
static_assert(offsetof(octospi_p, octospi_ar) == 72);
static_assert(offsetof(octospi_p, octospi_dr) == 80);
static_assert(offsetof(octospi_p, octospi_psmkr) == 128);
static_assert(offsetof(octospi_p, octospi_psmar) == 136);
static_assert(offsetof(octospi_p, octospi_pir) == 144);
static_assert(offsetof(octospi_p, octospi_ccr) == 256);
static_assert(offsetof(octospi_p, octospi_tcr) == 264);
static_assert(offsetof(octospi_p, octospi_ir) == 272);
static_assert(offsetof(octospi_p, octospi_abr) == 288);
static_assert(offsetof(octospi_p, octospi_lptr) == 304);
static_assert(offsetof(octospi_p, octospi_wpccr) == 320);
static_assert(offsetof(octospi_p, octospi_wptcr) == 328);
static_assert(offsetof(octospi_p, octospi_wpir) == 336);
static_assert(offsetof(octospi_p, octospi_wpabr) == 352);
static_assert(offsetof(octospi_p, octospi_wccr) == 384);
static_assert(offsetof(octospi_p, octospi_wtcr) == 392);
static_assert(offsetof(octospi_p, octospi_wir) == 400);
static_assert(offsetof(octospi_p, octospi_wabr) == 416);
static_assert(offsetof(octospi_p, octospi_hlcr) == 512);

inline octospi_p& octospi = *reinterpret_cast<octospi_p*>(0x47001400);
inline octospi_p& sec_octospi = *reinterpret_cast<octospi_p*>(0x57001400);

} // STM32H563

