#pragma once

#if __has_include("memory.hpp")
#include "memory.hpp"
#else
#include <utility/memory.hpp>
#endif

namespace STM32H563
{

/**
 * Flexible memory controller
 */
class fmc_p {
public:

/**
 * SRAM/NOR-Flash chip-select control register for bank 1
 */
class fmc_bcr1_r {
public:

/**
 * Memory bank enable bit Enables the memory bank. After reset Bank1 is enabled, all others are disabled. Accessing a disabled bank causes an ERROR on AHB bus.
 */
class mbken_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mbken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address/data multiplexing enable bit When this bit is set, the address and data values are multiplexed on the data bus, valid only with NOR and PSRAM memories:
 */
class muxen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr muxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Memory type Defines the type of external memory attached to the corresponding memory bank.
 */
class mtyp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mtyp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Memory data bus width Defines the external memory device width, valid for all type of memories.
 */
class mwid_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mwid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Flash access enable Enables NOR Flash memory access operations.
 */
class faccen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr faccen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Burst enable bit This bit enables/disables synchronous accesses during read operations. It is valid only for synchronous memories operating in Burst mode.
 */
class bursten_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bursten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait signal polarity bit Defines the polarity of the wait signal from memory used for either in Synchronous or Asynchronous mode.
 */
class waitpol_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait timing configuration The NWAIT signal indicates whether the data from the memory are valid or if a wait state must be inserted when accessing the memory in Synchronous mode. This configuration bit determines if NWAIT is asserted by the memory one clock cycle before the wait state or during the wait state:
 */
class waitcfg_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitcfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write enable bit This bit indicates whether write operations are enabled/disabled in the bank by the FMC.
 */
class wren_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait enable bit This bit enables/disables wait-state insertion via the NWAIT signal when accessing the memory in Synchronous mode.
 */
class waiten_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waiten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Extended mode enable This bit enables the FMC to program the write timings for non multiplexed asynchronous accesses inside the FMC_BWTR register, thus resulting in different timings for read and write operations. Note: When the Extended mode is disabled, the FMC can operate in mode 1 or mode 2 as follows: Mode 1 is the default mode when the SRAM/PSRAM memory type is selected (MTYP = 0x0 or 0x01) Mode 2 is the default mode when the NOR memory type is selected (MTYP = 0x10).
 */
class extmod_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr extmod_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait signal during asynchronous transfers This bit enables/disables the FMC to use the wait signal even during an asynchronous protocol.
 */
class asyncwait_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr asyncwait_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRAM page size These are used for CellularRAM 1.5 which does not allow burst access to cross the address boundaries between pages. When these bits are configured, the FMC controller splits automatically the burst access when the memory page size is reached (refer to memory datasheet for page size). Others: reserved
 */
class cpsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cpsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Write burst enable For PSRAM (CRAM) operating in Burst mode, the bit enables synchronous accesses during write operations. The enable bit for synchronous read accesses is the BURSTEN bit in the FMC_BCRx register.
 */
class cburstrw_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cburstrw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Continuous clock enable This bit enables the FMC_CLK clock output to external memory devices. Note: The CCLKEN bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register. Bank 1 must be configured in Synchronous mode to generate the FMC_CLK continuous clock. Note: If CCLKEN bit is set, the FMC_CLK clock ratio is specified by CLKDIV value in the FMC_BTR1 register. CLKDIV in FMC_BWTR1 is don't care. Note: If the Synchronous mode is used and CCLKEN bit is set, the synchronous memories connected to other banks than Bank 1 are clocked by the same clock (the CLKDIV value in the FMC_BTR2..4 and FMC_BWTR2..4 registers for other banks has no effect.)
 */
class cclken_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cclken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write FIFO disable This bit disables the Write FIFO used by the FMC controller. Note: The WFDIS bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register.
 */
class wfdis_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wfdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Byte lane (NBL) setup These bits configure the NBL setup timing from NBLx low to chip select NEx low.
 */
class nblset_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nblset_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FMC controller enable This bit enables or disables the FMC controller. Note: The FMCEN bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register.
 */
class fmcen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcr1_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcr1_r>() const {return opsy::utility::clear_set<fmc_bcr1_r>(mask, *this);}
	constexpr auto operator|(fmc_bcr1_r other) const -> fmc_bcr1_r { return static_cast<fmc_bcr1_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcr1_r> other) const -> opsy::utility::clear_set<fmc_bcr1_r> {return opsy::utility::clear_set<fmc_bcr1_r>(fmc_bcr1_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mbken() const -> mbken_f {return mbken_f((value_ & mbken_f::mask) != 0);}
	[[nodiscard]] constexpr auto muxen() const -> muxen_f {return muxen_f((value_ & muxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto mtyp() const -> mtyp_f {return mtyp_f(static_cast<uint8_t>(value_ >> mtyp_f::offset));}
	[[nodiscard]] constexpr auto mwid() const -> mwid_f {return mwid_f(static_cast<uint8_t>(value_ >> mwid_f::offset));}
	[[nodiscard]] constexpr auto faccen() const -> faccen_f {return faccen_f((value_ & faccen_f::mask) != 0);}
	[[nodiscard]] constexpr auto bursten() const -> bursten_f {return bursten_f((value_ & bursten_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitpol() const -> waitpol_f {return waitpol_f((value_ & waitpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitcfg() const -> waitcfg_f {return waitcfg_f((value_ & waitcfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto wren() const -> wren_f {return wren_f((value_ & wren_f::mask) != 0);}
	[[nodiscard]] constexpr auto waiten() const -> waiten_f {return waiten_f((value_ & waiten_f::mask) != 0);}
	[[nodiscard]] constexpr auto extmod() const -> extmod_f {return extmod_f((value_ & extmod_f::mask) != 0);}
	[[nodiscard]] constexpr auto asyncwait() const -> asyncwait_f {return asyncwait_f((value_ & asyncwait_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpsize() const -> cpsize_f {return cpsize_f(static_cast<uint8_t>(value_ >> cpsize_f::offset));}
	[[nodiscard]] constexpr auto cburstrw() const -> cburstrw_f {return cburstrw_f((value_ & cburstrw_f::mask) != 0);}
	[[nodiscard]] constexpr auto cclken() const -> cclken_f {return cclken_f((value_ & cclken_f::mask) != 0);}
	[[nodiscard]] constexpr auto wfdis() const -> wfdis_f {return wfdis_f((value_ & wfdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto nblset() const -> nblset_f {return nblset_f(static_cast<uint8_t>(value_ >> nblset_f::offset));}
	[[nodiscard]] constexpr auto fmcen() const -> fmcen_f {return fmcen_f((value_ & fmcen_f::mask) != 0);}

	constexpr fmc_bcr1_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_bcr1_r other) const -> fmc_bcr1_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_bcr1_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000011011011; // 12507 0x30DB

private:
	uint32_t value_;
};

/**
 * SRAM/NOR-Flash chip-select timing register for bank X
 */
class fmc_btrx_r {
public:

/**
 * Address setup phase duration These bits are written by software to define the duration of the address setup phase (refer to Figure 21 to Figure 33), used in SRAMs, ROMs, asynchronous NOR Flash and PSRAM: ... For each access mode address setup phase duration, refer to the respective figure (Figure 21 to Figure 33). Note: In synchronous accesses, this value is don't care. Note: In Muxed mode or mode D, the minimum value for ADDSET is 1. Note: In mode 1 and PSRAM memory, the minimum value for ADDSET is 1.
 */
class addset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr addset_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address-hold phase duration These bits are written by software to define the duration of the address hold phase (refer to Figure 21 to Figure 33), used in mode D or multiplexed accesses: ... For each access mode address-hold phase duration, refer to the respective figure (Figure 21 to Figure 33). Note: In synchronous accesses, this value is not used, the address hold phase is always 1 memory clock period duration.
 */
class addhld_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr addhld_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data-phase duration These bits are written by software to define the duration of the data phase (refer to Figure 21 to Figure 33), used in asynchronous accesses: For each memory type and access mode data-phase duration, refer to the respective figure (Figure 21 to Figure 33). Example: Mode 1, write access, DATAST=1: Data-phase duration= DATAST+1 = 2 HCLK clock cycles. Note: In synchronous accesses, this value is don't care.
 */
class datast_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr datast_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bus turnaround phase duration These bits are written by software to add a delay at the end of current read or write transaction to next transaction on the same bank. This delay allows to match the minimum time between consecutive transactions (tsub EHEL/sub from NEx high to NEx low) and the maximum time needed by the memory to free the data bus after a read access (tsub EHQZ/sub , chip enable high to output Hi-Z). This delay is recommended for mode D and muxed mode. For non-muxed memory, the bus turnaround delay can be set to minimum value. (BUSTURN + 1)HCLK period greater than or equal max(tsub EHEL/sub min, tsub EHQZ/sub max) For FRAM memories, the bus turnaround delay should be configured to match the minimum tPC (precharge time) timings. The bus turnaround delay is inserted between any consecutive transactions on the same bank (read/read, write/write, read/write and write/read) to match the tPC memory timing. The chip select is toggling between any consecutive accesses. (BUSTURN + 1)HCLK period greater than or equal tsub PC/sub min ...
 */
class busturn_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr busturn_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Clock divide ratio (for FMC_CLK signal) Defines the period of FMC_CLK clock output signal, expressed in number of HCLK cycles: In asynchronous NOR Flash, SRAM or PSRAM accesses, this value is don't care. Note: Refer to Section 5.6.5: Synchronous transactions for FMC_CLK divider ratio formula)
 */
class clkdiv_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr clkdiv_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * (see note below bit descriptions): Data latency for synchronous memory For synchronous access with read/write Burst mode enabled (BURSTEN / CBURSTRW bits set), defines the number of memory clock cycles (+2) to issue to the memory before reading/writing the first data: This timing parameter is not expressed in HCLK periods, but in FMC_CLK periods. For asynchronous access, this value is don't care.
 */
class datlat_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datlat_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Access mode Specifies the asynchronous access modes as shown in the timing diagrams. These bits are taken into account only when the EXTMOD bit in the FMC_BCRx register is 1.
 */
class accmod_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr accmod_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data hold phase duration These bits are written by software to define the duration of the data hold phase in HCLK cycles (refer to Figure 21 to Figure 33), used in asynchronous accesses: For read accesses For write accesses
 */
class datahld_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datahld_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_btrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_btrx_r>() const {return opsy::utility::clear_set<fmc_btrx_r>(mask, *this);}
	constexpr auto operator|(fmc_btrx_r other) const -> fmc_btrx_r { return static_cast<fmc_btrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_btrx_r> other) const -> opsy::utility::clear_set<fmc_btrx_r> {return opsy::utility::clear_set<fmc_btrx_r>(fmc_btrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto addset() const -> addset_f {return addset_f(static_cast<uint8_t>(value_ >> addset_f::offset));}
	[[nodiscard]] constexpr auto addhld() const -> addhld_f {return addhld_f(static_cast<uint8_t>(value_ >> addhld_f::offset));}
	[[nodiscard]] constexpr auto datast() const -> datast_f {return datast_f(static_cast<uint8_t>(value_ >> datast_f::offset));}
	[[nodiscard]] constexpr auto busturn() const -> busturn_f {return busturn_f(static_cast<uint8_t>(value_ >> busturn_f::offset));}
	[[nodiscard]] constexpr auto clkdiv() const -> clkdiv_f {return clkdiv_f(static_cast<uint8_t>(value_ >> clkdiv_f::offset));}
	[[nodiscard]] constexpr auto datlat() const -> datlat_f {return datlat_f(static_cast<uint8_t>(value_ >> datlat_f::offset));}
	[[nodiscard]] constexpr auto accmod() const -> accmod_f {return accmod_f(static_cast<uint8_t>(value_ >> accmod_f::offset));}
	[[nodiscard]] constexpr auto datahld() const -> datahld_f {return datahld_f(static_cast<uint8_t>(value_ >> datahld_f::offset));}

	constexpr fmc_btrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_btrx_r other) const -> fmc_btrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_btrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111111111111111; // 268435455 0xFFFFFFF

private:
	uint32_t value_;
};

/**
 * SRAM/NOR-Flash chip-select control register for bank X
 */
class fmc_bcrx_r {
public:

/**
 * Memory bank enable bit Enables the memory bank. After reset Bank1 is enabled, all others are disabled. Accessing a disabled bank causes an ERROR on AHB bus.
 */
class mbken_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr mbken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Address/data multiplexing enable bit When this bit is set, the address and data values are multiplexed on the data bus, valid only with NOR and PSRAM memories:
 */
class muxen_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr muxen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Memory type Defines the type of external memory attached to the corresponding memory bank.
 */
class mtyp_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mtyp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Memory data bus width Defines the external memory device width, valid for all type of memories.
 */
class mwid_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mwid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Flash access enable Enables NOR Flash memory access operations.
 */
class faccen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr faccen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Burst enable bit This bit enables/disables synchronous accesses during read operations. It is valid only for synchronous memories operating in Burst mode.
 */
class bursten_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr bursten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait signal polarity bit Defines the polarity of the wait signal from memory used for either in Synchronous or Asynchronous mode.
 */
class waitpol_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitpol_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait timing configuration The NWAIT signal indicates whether the data from the memory are valid or if a wait state must be inserted when accessing the memory in Synchronous mode. This configuration bit determines if NWAIT is asserted by the memory one clock cycle before the wait state or during the wait state:
 */
class waitcfg_f {
public:
	static constexpr std::size_t offset = 11;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waitcfg_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write enable bit This bit indicates whether write operations are enabled/disabled in the bank by the FMC.
 */
class wren_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait enable bit This bit enables/disables wait-state insertion via the NWAIT signal when accessing the memory in Synchronous mode.
 */
class waiten_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr waiten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Extended mode enable This bit enables the FMC to program the write timings for non multiplexed asynchronous accesses inside the FMC_BWTR register, thus resulting in different timings for read and write operations. Note: When the Extended mode is disabled, the FMC can operate in mode 1 or mode 2 as follows: Mode 1 is the default mode when the SRAM/PSRAM memory type is selected (MTYP = 0x0 or 0x01) Mode 2 is the default mode when the NOR memory type is selected (MTYP = 0x10).
 */
class extmod_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr extmod_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Wait signal during asynchronous transfers This bit enables/disables the FMC to use the wait signal even during an asynchronous protocol.
 */
class asyncwait_f {
public:
	static constexpr std::size_t offset = 15;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr asyncwait_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CRAM page size These are used for CellularRAM 1.5 which does not allow burst access to cross the address boundaries between pages. When these bits are configured, the FMC controller splits automatically the burst access when the memory page size is reached (refer to memory datasheet for page size). Others: reserved
 */
class cpsize_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr cpsize_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Write burst enable For PSRAM (CRAM) operating in Burst mode, the bit enables synchronous accesses during write operations. The enable bit for synchronous read accesses is the BURSTEN bit in the FMC_BCRx register.
 */
class cburstrw_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cburstrw_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Continuous clock enable This bit enables the FMC_CLK clock output to external memory devices. Note: The CCLKEN bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register. Bank 1 must be configured in Synchronous mode to generate the FMC_CLK continuous clock. Note: If CCLKEN bit is set, the FMC_CLK clock ratio is specified by CLKDIV value in the FMC_BTR1 register. CLKDIV in FMC_BWTR1 is don't care. Note: If the Synchronous mode is used and CCLKEN bit is set, the synchronous memories connected to other banks than Bank 1 are clocked by the same clock (the CLKDIV value in the FMC_BTR2..4 and FMC_BWTR2..4 registers for other banks has no effect.)
 */
class cclken_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cclken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Write FIFO disable This bit disables the Write FIFO used by the FMC controller. Note: The WFDIS bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register.
 */
class wfdis_f {
public:
	static constexpr std::size_t offset = 21;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr wfdis_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Byte lane (NBL) setup These bits configure the NBL setup timing from NBLx low to chip select NEx low.
 */
class nblset_f {
public:
	static constexpr std::size_t offset = 22;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr nblset_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * FMC controller enable This bit enables or disables the FMC controller. Note: The FMCEN bit of the FMC_BCR2..4 registers is don't care. It is only enabled through the FMC_BCR1 register.
 */
class fmcen_f {
public:
	static constexpr std::size_t offset = 31;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr fmcen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_bcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_bcrx_r>() const {return opsy::utility::clear_set<fmc_bcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bcrx_r other) const -> fmc_bcrx_r { return static_cast<fmc_bcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bcrx_r> other) const -> opsy::utility::clear_set<fmc_bcrx_r> {return opsy::utility::clear_set<fmc_bcrx_r>(fmc_bcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto mbken() const -> mbken_f {return mbken_f((value_ & mbken_f::mask) != 0);}
	[[nodiscard]] constexpr auto muxen() const -> muxen_f {return muxen_f((value_ & muxen_f::mask) != 0);}
	[[nodiscard]] constexpr auto mtyp() const -> mtyp_f {return mtyp_f(static_cast<uint8_t>(value_ >> mtyp_f::offset));}
	[[nodiscard]] constexpr auto mwid() const -> mwid_f {return mwid_f(static_cast<uint8_t>(value_ >> mwid_f::offset));}
	[[nodiscard]] constexpr auto faccen() const -> faccen_f {return faccen_f((value_ & faccen_f::mask) != 0);}
	[[nodiscard]] constexpr auto bursten() const -> bursten_f {return bursten_f((value_ & bursten_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitpol() const -> waitpol_f {return waitpol_f((value_ & waitpol_f::mask) != 0);}
	[[nodiscard]] constexpr auto waitcfg() const -> waitcfg_f {return waitcfg_f((value_ & waitcfg_f::mask) != 0);}
	[[nodiscard]] constexpr auto wren() const -> wren_f {return wren_f((value_ & wren_f::mask) != 0);}
	[[nodiscard]] constexpr auto waiten() const -> waiten_f {return waiten_f((value_ & waiten_f::mask) != 0);}
	[[nodiscard]] constexpr auto extmod() const -> extmod_f {return extmod_f((value_ & extmod_f::mask) != 0);}
	[[nodiscard]] constexpr auto asyncwait() const -> asyncwait_f {return asyncwait_f((value_ & asyncwait_f::mask) != 0);}
	[[nodiscard]] constexpr auto cpsize() const -> cpsize_f {return cpsize_f(static_cast<uint8_t>(value_ >> cpsize_f::offset));}
	[[nodiscard]] constexpr auto cburstrw() const -> cburstrw_f {return cburstrw_f((value_ & cburstrw_f::mask) != 0);}
	[[nodiscard]] constexpr auto cclken() const -> cclken_f {return cclken_f((value_ & cclken_f::mask) != 0);}
	[[nodiscard]] constexpr auto wfdis() const -> wfdis_f {return wfdis_f((value_ & wfdis_f::mask) != 0);}
	[[nodiscard]] constexpr auto nblset() const -> nblset_f {return nblset_f(static_cast<uint8_t>(value_ >> nblset_f::offset));}
	[[nodiscard]] constexpr auto fmcen() const -> fmcen_f {return fmcen_f((value_ & fmcen_f::mask) != 0);}

	constexpr fmc_bcrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_bcrx_r other) const -> fmc_bcrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_bcrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000011010010; // 12498 0x30D2

private:
	uint32_t value_;
};

/**
 * PSRAM chip select counter register
 */
class fmc_pcscntr_r {
public:

/**
 * Chip select counter. These bits are written by software to define the maximum chip select low pulse duration. It is expressed in FMC_CLK cycles for synchronous accesses and in HCLK cycles for asynchronous accesses. The counter is disabled if the programmed value is 0.
 */
class cscount_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 16;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cscount_f(uint16_t value) : value_(value) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fmc_pcscntr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pcscntr_r>() const {return opsy::utility::clear_set<fmc_pcscntr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return static_cast<fmc_pcscntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcscntr_r> other) const -> opsy::utility::clear_set<fmc_pcscntr_r> {return opsy::utility::clear_set<fmc_pcscntr_r>(fmc_pcscntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * Counter Bank 1 enable This bit enables the chip select counter for PSRAM/NOR Bank 1.
 */
class cntb1en_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cntb1en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcscntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcscntr_r>() const {return opsy::utility::clear_set<fmc_pcscntr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return static_cast<fmc_pcscntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcscntr_r> other) const -> opsy::utility::clear_set<fmc_pcscntr_r> {return opsy::utility::clear_set<fmc_pcscntr_r>(fmc_pcscntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter Bank 2 enable This bit enables the chip select counter for PSRAM/NOR Bank 2.
 */
class cntb2en_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cntb2en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcscntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcscntr_r>() const {return opsy::utility::clear_set<fmc_pcscntr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return static_cast<fmc_pcscntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcscntr_r> other) const -> opsy::utility::clear_set<fmc_pcscntr_r> {return opsy::utility::clear_set<fmc_pcscntr_r>(fmc_pcscntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter Bank 3 enable This bit enables the chip select counter for PSRAM/NOR Bank 3.
 */
class cntb3en_f {
public:
	static constexpr std::size_t offset = 18;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cntb3en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcscntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcscntr_r>() const {return opsy::utility::clear_set<fmc_pcscntr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return static_cast<fmc_pcscntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcscntr_r> other) const -> opsy::utility::clear_set<fmc_pcscntr_r> {return opsy::utility::clear_set<fmc_pcscntr_r>(fmc_pcscntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Counter Bank 4 enable This bit enables the chip select counter for PSRAM/NOR Bank 4.
 */
class cntb4en_f {
public:
	static constexpr std::size_t offset = 19;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr cntb4en_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcscntr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcscntr_r>() const {return opsy::utility::clear_set<fmc_pcscntr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return static_cast<fmc_pcscntr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcscntr_r> other) const -> opsy::utility::clear_set<fmc_pcscntr_r> {return opsy::utility::clear_set<fmc_pcscntr_r>(fmc_pcscntr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cscount() const -> cscount_f {return cscount_f(static_cast<uint16_t>(value_ >> cscount_f::offset));}
	[[nodiscard]] constexpr auto cntb1en() const -> cntb1en_f {return cntb1en_f((value_ & cntb1en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntb2en() const -> cntb2en_f {return cntb2en_f((value_ & cntb2en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntb3en() const -> cntb3en_f {return cntb3en_f((value_ & cntb3en_f::mask) != 0);}
	[[nodiscard]] constexpr auto cntb4en() const -> cntb4en_f {return cntb4en_f((value_ & cntb4en_f::mask) != 0);}

	constexpr fmc_pcscntr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_pcscntr_r other) const -> fmc_pcscntr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_pcscntr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * NAND Flash control registers
 */
class fmc_pcr_r {
public:

/**
 * Wait feature enable bit Enables the Wait feature for the NAND Flash memory bank:
 */
class pwaiten_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pwaiten_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * NAND Flash memory bank enable bit Enables the memory bank. Accessing a disabled memory bank causes an ERROR on AHB bus
 */
class pbken_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr pbken_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Memory type Defines the type of device attached to the corresponding memory bank:
 */
class ptyp_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ptyp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Data bus width Defines the external memory device width.
 */
class pwid_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr pwid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pcr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ECC computation logic enable bit
 */
class eccen_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr eccen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CLE to RE delay Sets time from CLE low to RE low in number of AHB clock cycles (HCLK). Time is t_clr = (TCLR + SET + 2) THCLK where THCLK is the HCLK clock period Note: SET is MEMSET or ATTSET according to the addressed space.
 */
class tclr_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tclr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ALE to RE delay Sets time from ALE low to RE low in number of AHB clock cycles (HCLK). Time is: t_ar = (TAR + SET + 2) THCLK where THCLK is the HCLK clock period Note: SET is MEMSET or ATTSET according to the addressed space.
 */
class tar_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tar_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pcr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * ALE to RE delay Sets time from ALE low to RE low in number of AHB clock cycles (HCLK). Time is: t_ar = (TAR + SET + 2) THCLK where THCLK is the HCLK clock period Note: SET is MEMSET or ATTSET according to the addressed space.
 */
class tar3_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 1;
	static constexpr uint32_t mask = static_cast<uint32_t>(1ULL << offset);

	constexpr tar3_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_pcr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * ECC page size Defines the page size for the extended ECC:
 */
class eccps_f {
public:
	static constexpr std::size_t offset = 17;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr eccps_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pcr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pcr_r>() const {return opsy::utility::clear_set<fmc_pcr_r>(mask, *this);}
	constexpr auto operator|(fmc_pcr_r other) const -> fmc_pcr_r { return static_cast<fmc_pcr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pcr_r> other) const -> opsy::utility::clear_set<fmc_pcr_r> {return opsy::utility::clear_set<fmc_pcr_r>(fmc_pcr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto pwaiten() const -> pwaiten_f {return pwaiten_f((value_ & pwaiten_f::mask) != 0);}
	[[nodiscard]] constexpr auto pbken() const -> pbken_f {return pbken_f((value_ & pbken_f::mask) != 0);}
	[[nodiscard]] constexpr auto ptyp() const -> ptyp_f {return ptyp_f((value_ & ptyp_f::mask) != 0);}
	[[nodiscard]] constexpr auto pwid() const -> pwid_f {return pwid_f(static_cast<uint8_t>(value_ >> pwid_f::offset));}
	[[nodiscard]] constexpr auto eccen() const -> eccen_f {return eccen_f((value_ & eccen_f::mask) != 0);}
	[[nodiscard]] constexpr auto tclr() const -> tclr_f {return tclr_f(static_cast<uint8_t>(value_ >> tclr_f::offset));}
	[[nodiscard]] constexpr auto tar() const -> tar_f {return tar_f(static_cast<uint8_t>(value_ >> tar_f::offset));}
	[[nodiscard]] constexpr auto tar3() const -> tar3_f {return tar3_f((value_ & tar3_f::mask) != 0);}
	[[nodiscard]] constexpr auto eccps() const -> eccps_f {return eccps_f(static_cast<uint8_t>(value_ >> eccps_f::offset));}

	constexpr fmc_pcr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_pcr_r other) const -> fmc_pcr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_pcr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11000; // 24 0x18

private:
	uint32_t value_;
};

/**
 * FIFO status and interrupt register
 */
class fmc_sr_r {
public:

/**
 * Interrupt rising edge status The flag is set by hardware and reset by software. Note: If this bit is written by software to 1 it is set.
 */
class irs_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr irs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt high-level status The flag is set by hardware and reset by software.
 */
class ils_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ils_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt falling edge status The flag is set by hardware and reset by software. Note: If this bit is written by software to 1 it is set.
 */
class ifs_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ifs_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt rising edge detection enable bit
 */
class iren_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr iren_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt high-level detection enable bit
 */
class ilen_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ilen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Interrupt falling edge detection enable bit
 */
class ifen_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ifen_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * FIFO empty Read-only bit that provides the status of the FIFO
 */
class fempt_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr fempt_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sr_r>() const {return opsy::utility::clear_set<fmc_sr_r>(mask, *this);}
	constexpr auto operator|(fmc_sr_r other) const -> fmc_sr_r { return static_cast<fmc_sr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sr_r> other) const -> opsy::utility::clear_set<fmc_sr_r> {return opsy::utility::clear_set<fmc_sr_r>(fmc_sr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto irs() const -> irs_f {return irs_f((value_ & irs_f::mask) != 0);}
	[[nodiscard]] constexpr auto ils() const -> ils_f {return ils_f((value_ & ils_f::mask) != 0);}
	[[nodiscard]] constexpr auto ifs() const -> ifs_f {return ifs_f((value_ & ifs_f::mask) != 0);}
	[[nodiscard]] constexpr auto iren() const -> iren_f {return iren_f((value_ & iren_f::mask) != 0);}
	[[nodiscard]] constexpr auto ilen() const -> ilen_f {return ilen_f((value_ & ilen_f::mask) != 0);}
	[[nodiscard]] constexpr auto ifen() const -> ifen_f {return ifen_f((value_ & ifen_f::mask) != 0);}
	[[nodiscard]] constexpr auto fempt() const -> fempt_f {return fempt_f((value_ & fempt_f::mask) != 0);}

	constexpr fmc_sr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sr_r other) const -> fmc_sr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1000000; // 64 0x40

private:
	uint32_t value_;
};

/**
 * Common memory space timing register
 */
class fmc_pmem_r {
public:

/**
 * Common memory x setup time Defines the number of HCLK (+1) clock cycles to set up the address before the command assertion (NWE, NOE), for NAND Flash read or write access to common memory space on socket x:
 */
class memset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr memset_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pmem_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pmem_r>() const {return opsy::utility::clear_set<fmc_pmem_r>(mask, *this);}
	constexpr auto operator|(fmc_pmem_r other) const -> fmc_pmem_r { return static_cast<fmc_pmem_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pmem_r> other) const -> opsy::utility::clear_set<fmc_pmem_r> {return opsy::utility::clear_set<fmc_pmem_r>(fmc_pmem_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Common memory wait time Defines the minimum number of HCLK (+1) clock cycles to assert the command (NWE, NOE), for NAND Flash read or write access to common memory space on socket. The duration of command assertion is extended if the wait signal (NWAIT) is active (low) at the end of the programmed value of HCLK:
 */
class memwait_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr memwait_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pmem_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pmem_r>() const {return opsy::utility::clear_set<fmc_pmem_r>(mask, *this);}
	constexpr auto operator|(fmc_pmem_r other) const -> fmc_pmem_r { return static_cast<fmc_pmem_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pmem_r> other) const -> opsy::utility::clear_set<fmc_pmem_r> {return opsy::utility::clear_set<fmc_pmem_r>(fmc_pmem_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Common memory hold time Defines the number of HCLK clock cycles for write access and HCLK (+2) clock cycles for read access during which the address is held (and data for write accesses) after the command is deasserted (NWE, NOE), for NAND Flash read or write access to common memory space on socket x:
 */
class memhold_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr memhold_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pmem_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pmem_r>() const {return opsy::utility::clear_set<fmc_pmem_r>(mask, *this);}
	constexpr auto operator|(fmc_pmem_r other) const -> fmc_pmem_r { return static_cast<fmc_pmem_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pmem_r> other) const -> opsy::utility::clear_set<fmc_pmem_r> {return opsy::utility::clear_set<fmc_pmem_r>(fmc_pmem_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Common memory x data bus Hi-Z time Defines the number of HCLK clock cycles during which the data bus is kept Hi-Z after the start of a NAND Flash write access to common memory space on socket. This is only valid for write transactions:
 */
class memhiz_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr memhiz_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_pmem_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_pmem_r>() const {return opsy::utility::clear_set<fmc_pmem_r>(mask, *this);}
	constexpr auto operator|(fmc_pmem_r other) const -> fmc_pmem_r { return static_cast<fmc_pmem_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_pmem_r> other) const -> opsy::utility::clear_set<fmc_pmem_r> {return opsy::utility::clear_set<fmc_pmem_r>(fmc_pmem_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto memset() const -> memset_f {return memset_f(static_cast<uint8_t>(value_ >> memset_f::offset));}
	[[nodiscard]] constexpr auto memwait() const -> memwait_f {return memwait_f(static_cast<uint8_t>(value_ >> memwait_f::offset));}
	[[nodiscard]] constexpr auto memhold() const -> memhold_f {return memhold_f(static_cast<uint8_t>(value_ >> memhold_f::offset));}
	[[nodiscard]] constexpr auto memhiz() const -> memhiz_f {return memhiz_f(static_cast<uint8_t>(value_ >> memhiz_f::offset));}

	constexpr fmc_pmem_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_pmem_r other) const -> fmc_pmem_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_pmem_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111100111111001111110011111100; // 4244438268 0xFCFCFCFC

private:
	uint32_t value_;
};

/**
 * Attribute memory space timing register
 */
class fmc_patt_r {
public:

/**
 * Attribute memory setup time Defines the number of HCLK (+1) clock cycles to set up address before the command assertion (NWE, NOE), for NAND Flash read or write access to attribute memory space on socket:
 */
class attset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr attset_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_patt_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_patt_r>() const {return opsy::utility::clear_set<fmc_patt_r>(mask, *this);}
	constexpr auto operator|(fmc_patt_r other) const -> fmc_patt_r { return static_cast<fmc_patt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_patt_r> other) const -> opsy::utility::clear_set<fmc_patt_r> {return opsy::utility::clear_set<fmc_patt_r>(fmc_patt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Attribute memory wait time Defines the minimum number of HCLK (+1) clock cycles to assert the command (NWE, NOE), for NAND Flash read or write access to attribute memory space on socket x. The duration for command assertion is extended if the wait signal (NWAIT) is active (low) at the end of the programmed value of HCLK:
 */
class attwait_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr attwait_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_patt_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_patt_r>() const {return opsy::utility::clear_set<fmc_patt_r>(mask, *this);}
	constexpr auto operator|(fmc_patt_r other) const -> fmc_patt_r { return static_cast<fmc_patt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_patt_r> other) const -> opsy::utility::clear_set<fmc_patt_r> {return opsy::utility::clear_set<fmc_patt_r>(fmc_patt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Attribute memory hold time Defines the number of HCLK clock cycles for write access and HCLK (+2) clock cycles for read access during which the address is held (and data for write access) after the command deassertion (NWE, NOE), for NAND Flash read or write access to attribute memory space on socket:
 */
class atthold_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atthold_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_patt_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_patt_r>() const {return opsy::utility::clear_set<fmc_patt_r>(mask, *this);}
	constexpr auto operator|(fmc_patt_r other) const -> fmc_patt_r { return static_cast<fmc_patt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_patt_r> other) const -> opsy::utility::clear_set<fmc_patt_r> {return opsy::utility::clear_set<fmc_patt_r>(fmc_patt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Attribute memory data bus Hi-Z time Defines the number of HCLK clock cycles during which the data bus is kept in Hi-Z after the start of a NAND Flash write access to attribute memory space on socket. Only valid for writ transaction:
 */
class atthiz_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr atthiz_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_patt_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_patt_r>() const {return opsy::utility::clear_set<fmc_patt_r>(mask, *this);}
	constexpr auto operator|(fmc_patt_r other) const -> fmc_patt_r { return static_cast<fmc_patt_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_patt_r> other) const -> opsy::utility::clear_set<fmc_patt_r> {return opsy::utility::clear_set<fmc_patt_r>(fmc_patt_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto attset() const -> attset_f {return attset_f(static_cast<uint8_t>(value_ >> attset_f::offset));}
	[[nodiscard]] constexpr auto attwait() const -> attwait_f {return attwait_f(static_cast<uint8_t>(value_ >> attwait_f::offset));}
	[[nodiscard]] constexpr auto atthold() const -> atthold_f {return atthold_f(static_cast<uint8_t>(value_ >> atthold_f::offset));}
	[[nodiscard]] constexpr auto atthiz() const -> atthiz_f {return atthiz_f(static_cast<uint8_t>(value_ >> atthiz_f::offset));}

	constexpr fmc_patt_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_patt_r other) const -> fmc_patt_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_patt_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b11111100111111001111110011111100; // 4244438268 0xFCFCFCFC

private:
	uint32_t value_;
};

/**
 * ECC result registers
 */
class fmc_eccr_r {
public:

/**
 * ECC result This field contains the value computed by the ECC computation logic. Table 99 describes the contents of these bitfields.
 */
class ecc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 32;
	static constexpr uint32_t range = static_cast<uint32_t>(0b11111111111111111111111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr ecc_f(uint32_t value) : value_(value) {}
	constexpr operator uint32_t() const {return value_;}
	constexpr operator fmc_eccr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_eccr_r>() const {return opsy::utility::clear_set<fmc_eccr_r>(mask, *this);}
	constexpr auto operator|(fmc_eccr_r other) const -> fmc_eccr_r { return static_cast<fmc_eccr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_eccr_r> other) const -> opsy::utility::clear_set<fmc_eccr_r> {return opsy::utility::clear_set<fmc_eccr_r>(fmc_eccr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint32_t value_;
};

	[[nodiscard]] constexpr auto ecc() const -> ecc_f {return ecc_f(static_cast<uint32_t>(value_ >> ecc_f::offset));}

	constexpr fmc_eccr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_eccr_r other) const -> fmc_eccr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_eccr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SRAM/NOR-Flash write timing registers X
 */
class fmc_bwtrx_r {
public:

/**
 * Address setup phase duration. These bits are written by software to define the duration of the address setup phase in HCLK cycles (refer to Figure 21 to Figure 33), used in asynchronous accesses: ... Note: In synchronous accesses, this value is not used, the address setup phase is always 1 Flash clock period duration. In muxed mode, the minimum ADDSET value is 1.
 */
class addset_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr addset_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Address-hold phase duration. These bits are written by software to define the duration of the address hold phase (refer to Figure 30 to Figure 33), used in asynchronous multiplexed accesses: ... Note: In synchronous NOR Flash accesses, this value is not used, the address hold phase is always 1 Flash clock period duration.
 */
class addhld_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr addhld_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data-phase duration. These bits are written by software to define the duration of the data phase (refer to Figure 21 to Figure 33), used in asynchronous SRAM, PSRAM and NOR Flash memory accesses: ...
 */
class datast_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 8;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr datast_f(uint8_t value) : value_(value) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Bus turnaround phase duration These bits are written by software to add a delay at the end of current write transaction to next transaction on the same bank. For FRAM memories, the bus turnaround delay should be configured to match the minimum tsub PC/sub (precharge time) timings. The bus turnaround delay is inserted between any consecutive transactions on the same bank (read/read, write/write, read/write and write/read). The chip select is toggling between any consecutive accesses. (BUSTURN + 1)HCLK period greater than or equal tPC min ...
 */
class busturn_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr busturn_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Access mode. Specifies the asynchronous access modes as shown in the next timing diagrams.These bits are taken into account only when the EXTMOD bit in the FMC_BCRx register is 1.
 */
class accmod_f {
public:
	static constexpr std::size_t offset = 28;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr accmod_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Data hold phase duration These bits are written by software to define the duration of the data hold phase in HCLK cycles (refer to Figure 21 to Figure 33), used in asynchronous write accesses:
 */
class datahld_f {
public:
	static constexpr std::size_t offset = 30;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr datahld_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_bwtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_bwtrx_r>() const {return opsy::utility::clear_set<fmc_bwtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return static_cast<fmc_bwtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_bwtrx_r> other) const -> opsy::utility::clear_set<fmc_bwtrx_r> {return opsy::utility::clear_set<fmc_bwtrx_r>(fmc_bwtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto addset() const -> addset_f {return addset_f(static_cast<uint8_t>(value_ >> addset_f::offset));}
	[[nodiscard]] constexpr auto addhld() const -> addhld_f {return addhld_f(static_cast<uint8_t>(value_ >> addhld_f::offset));}
	[[nodiscard]] constexpr auto datast() const -> datast_f {return datast_f(static_cast<uint8_t>(value_ >> datast_f::offset));}
	[[nodiscard]] constexpr auto busturn() const -> busturn_f {return busturn_f(static_cast<uint8_t>(value_ >> busturn_f::offset));}
	[[nodiscard]] constexpr auto accmod() const -> accmod_f {return accmod_f(static_cast<uint8_t>(value_ >> accmod_f::offset));}
	[[nodiscard]] constexpr auto datahld() const -> datahld_f {return datahld_f(static_cast<uint8_t>(value_ >> datahld_f::offset));}

	constexpr fmc_bwtrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_bwtrx_r other) const -> fmc_bwtrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_bwtrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111111111111111; // 268435455 0xFFFFFFF

private:
	uint32_t value_;
};

/**
 * SDRAM control registers X
 */
class fmc_sdcrx_r {
public:

/**
 * Number of column address bits These bits define the number of bits of a column address.
 */
class nc_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of row address bits These bits define the number of bits of a row address.
 */
class nr_f {
public:
	static constexpr std::size_t offset = 2;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr nr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Memory data bus width. These bits define the memory device width.
 */
class mwid_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mwid_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Number of internal banks This bit sets the number of internal banks.
 */
class nb_f {
public:
	static constexpr std::size_t offset = 6;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr nb_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * CAS Latency This bits sets the SDRAM CAS latency in number of memory clock cycles
 */
class cas_f {
public:
	static constexpr std::size_t offset = 7;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr cas_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Write protection This bit enables write mode access to the SDRAM bank.
 */
class wp_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr wp_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * SDRAM clock configuration These bits define the SDRAM clock period for both SDRAM banks and allow disabling the clock before changing the frequency. In this case the SDRAM must be re-initialized. Note: The corresponding bits in the FMC_SDCR2 register are don't care.
 */
class sdclk_f {
public:
	static constexpr std::size_t offset = 10;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr sdclk_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Burst read This bit enables Burst read mode. The SDRAM controller anticipates the next read commands during the CAS latency and stores data in the Read FIFO. Note: The corresponding bit in the FMC_SDCR2 register is don't care.
 */
class rburst_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr rburst_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Read pipe These bits define the delay, in clock cycles, for reading data after CAS latency. Note: The corresponding bits in the FMC_SDCR2 register is read only.
 */
class rpipe_f {
public:
	static constexpr std::size_t offset = 13;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr rpipe_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcrx_r>() const {return opsy::utility::clear_set<fmc_sdcrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return static_cast<fmc_sdcrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcrx_r> other) const -> opsy::utility::clear_set<fmc_sdcrx_r> {return opsy::utility::clear_set<fmc_sdcrx_r>(fmc_sdcrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto nc() const -> nc_f {return nc_f(static_cast<uint8_t>(value_ >> nc_f::offset));}
	[[nodiscard]] constexpr auto nr() const -> nr_f {return nr_f(static_cast<uint8_t>(value_ >> nr_f::offset));}
	[[nodiscard]] constexpr auto mwid() const -> mwid_f {return mwid_f(static_cast<uint8_t>(value_ >> mwid_f::offset));}
	[[nodiscard]] constexpr auto nb() const -> nb_f {return nb_f((value_ & nb_f::mask) != 0);}
	[[nodiscard]] constexpr auto cas() const -> cas_f {return cas_f(static_cast<uint8_t>(value_ >> cas_f::offset));}
	[[nodiscard]] constexpr auto wp() const -> wp_f {return wp_f((value_ & wp_f::mask) != 0);}
	[[nodiscard]] constexpr auto sdclk() const -> sdclk_f {return sdclk_f(static_cast<uint8_t>(value_ >> sdclk_f::offset));}
	[[nodiscard]] constexpr auto rburst() const -> rburst_f {return rburst_f((value_ & rburst_f::mask) != 0);}
	[[nodiscard]] constexpr auto rpipe() const -> rpipe_f {return rpipe_f(static_cast<uint8_t>(value_ >> rpipe_f::offset));}

	constexpr fmc_sdcrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sdcrx_r other) const -> fmc_sdcrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sdcrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1011010000; // 720 0x2D0

private:
	uint32_t value_;
};

/**
 * SDRAM timing registers X
 */
class fmc_sdtrx_r {
public:

/**
 * Load Mode Register to Active These bits define the delay between a Load Mode Register command and an Active or Refresh command in number of memory clock cycles. ....
 */
class tmrd_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr tmrd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Exit Self-refresh delay These bits define the delay from releasing the Self-refresh command to issuing the Activate command in number of memory clock cycles. .... Note: If two SDRAM devices are used, the FMC_SDTR1 and FMC_SDTR2 must be programmed with the same TXSR timing corresponding to the slowest SDRAM device.
 */
class txsr_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr txsr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Self refresh time These bits define the minimum Self-refresh period in number of memory clock cycles. ....
 */
class tras_f {
public:
	static constexpr std::size_t offset = 8;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr tras_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Row cycle delay These bits define the delay between the Refresh command and the Activate command, as well as the delay between two consecutive Refresh commands. It is expressed in number of memory clock cycles. The TRC timing is only configured in the FMC_SDTR1 register. If two SDRAM devices are used, the TRC must be programmed with the timings of the slowest device. .... Note: TRC must match the TRC and TRFC (Auto Refresh period) timings defined in the SDRAM device datasheet. Note: The corresponding bits in the FMC_SDTR2 register are don't care.
 */
class trc_f {
public:
	static constexpr std::size_t offset = 12;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr trc_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Recovery delay These bits define the delay between a Write and a Precharge command in number of memory clock cycles. .... Note: TWR must be programmed to match the write recovery time (tsub WR/sub ) defined in the SDRAM datasheet, and to guarantee that: Note: TWR greater than or equal TRASTRCD and TWR greater than or equalTRCTRCDTRP Note: Example: TRAS= 4 cycles, TRCD= 2 cycles. So, TWR = 2 cycles. TWR must be programmed to 0x1. Note: If two SDRAM devices are used, the FMC_SDTR1 and FMC_SDTR2 must be programmed with the same TWR timing corresponding to the slowest SDRAM device. Note: If only one SDRAM device is used, the TWR timing must be kept at reset value (0xF) for the not used bank.
 */
class twr_f {
public:
	static constexpr std::size_t offset = 16;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr twr_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Row precharge delay These bits define the delay between a Precharge command and another command in number of memory clock cycles. The TRP timing is only configured in the FMC_SDTR1 register. If two SDRAM devices are used, the TRP must be programmed with the timing of the slowest device. .... Note: The corresponding bits in the FMC_SDTR2 register are don't care.
 */
class trp_f {
public:
	static constexpr std::size_t offset = 20;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trp_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Row to column delay These bits define the delay between the Activate command and a Read/Write command in number of memory clock cycles. ....
 */
class trcd_f {
public:
	static constexpr std::size_t offset = 24;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr trcd_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdtrx_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdtrx_r>() const {return opsy::utility::clear_set<fmc_sdtrx_r>(mask, *this);}
	constexpr auto operator|(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return static_cast<fmc_sdtrx_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdtrx_r> other) const -> opsy::utility::clear_set<fmc_sdtrx_r> {return opsy::utility::clear_set<fmc_sdtrx_r>(fmc_sdtrx_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

	[[nodiscard]] constexpr auto tmrd() const -> tmrd_f {return tmrd_f(static_cast<uint8_t>(value_ >> tmrd_f::offset));}
	[[nodiscard]] constexpr auto txsr() const -> txsr_f {return txsr_f(static_cast<uint8_t>(value_ >> txsr_f::offset));}
	[[nodiscard]] constexpr auto tras() const -> tras_f {return tras_f(static_cast<uint8_t>(value_ >> tras_f::offset));}
	[[nodiscard]] constexpr auto trc() const -> trc_f {return trc_f(static_cast<uint8_t>(value_ >> trc_f::offset));}
	[[nodiscard]] constexpr auto twr() const -> twr_f {return twr_f(static_cast<uint8_t>(value_ >> twr_f::offset));}
	[[nodiscard]] constexpr auto trp() const -> trp_f {return trp_f(static_cast<uint8_t>(value_ >> trp_f::offset));}
	[[nodiscard]] constexpr auto trcd() const -> trcd_f {return trcd_f(static_cast<uint8_t>(value_ >> trcd_f::offset));}

	constexpr fmc_sdtrx_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sdtrx_r other) const -> fmc_sdtrx_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sdtrx_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0b1111111111111111111111111111; // 268435455 0xFFFFFFF

private:
	uint32_t value_;
};

/**
 * SDRAM Command Mode register
 */
class fmc_sdcmr_r {
public:

/**
 * Command mode These bits define the command issued to the SDRAM device. Note: When a command is issued, at least one Command Target Bank bit ( CTB1 or CTB2) must be set otherwise the command will be ignored. Note: If two SDRAM banks are used, the Auto-refresh and PALL command must be issued simultaneously to the two devices with CTB1 and CTB2 bits set otherwise the command will be ignored. Note: If only one SDRAM bank is used and a command is issued with it's associated CTB bit set, the other CTB bit of the the unused bank must be kept to 0.
 */
class mode_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 3;
	static constexpr uint8_t range = static_cast<uint8_t>(0b111);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr mode_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcmr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcmr_r>() const {return opsy::utility::clear_set<fmc_sdcmr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return static_cast<fmc_sdcmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcmr_r> other) const -> opsy::utility::clear_set<fmc_sdcmr_r> {return opsy::utility::clear_set<fmc_sdcmr_r>(fmc_sdcmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Command Target Bank 2 This bit indicates whether the command will be issued to SDRAM Bank 2 or not.
 */
class ctb2_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctb2_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdcmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdcmr_r>() const {return opsy::utility::clear_set<fmc_sdcmr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return static_cast<fmc_sdcmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcmr_r> other) const -> opsy::utility::clear_set<fmc_sdcmr_r> {return opsy::utility::clear_set<fmc_sdcmr_r>(fmc_sdcmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Command Target Bank 1 This bit indicates whether the command will be issued to SDRAM Bank 1 or not.
 */
class ctb1_f {
public:
	static constexpr std::size_t offset = 4;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr ctb1_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdcmr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdcmr_r>() const {return opsy::utility::clear_set<fmc_sdcmr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return static_cast<fmc_sdcmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcmr_r> other) const -> opsy::utility::clear_set<fmc_sdcmr_r> {return opsy::utility::clear_set<fmc_sdcmr_r>(fmc_sdcmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Number of Auto-refresh These bits define the number of consecutive Auto-refresh commands issued when MODE = '011'. ....
 */
class nrfs_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 4;
	static constexpr uint8_t range = static_cast<uint8_t>(0b1111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr nrfs_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdcmr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcmr_r>() const {return opsy::utility::clear_set<fmc_sdcmr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return static_cast<fmc_sdcmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcmr_r> other) const -> opsy::utility::clear_set<fmc_sdcmr_r> {return opsy::utility::clear_set<fmc_sdcmr_r>(fmc_sdcmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Mode Register definition This 13-bit field defines the SDRAM Mode Register content. The Mode Register is programmed using the Load Mode Register command.
 */
class mrd_f {
public:
	static constexpr std::size_t offset = 9;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint32_t mask = static_cast<uint32_t>(static_cast<uint32_t>(range) << offset);

	constexpr mrd_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fmc_sdcmr_r() const {return static_cast<uint32_t>(static_cast<uint32_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdcmr_r>() const {return opsy::utility::clear_set<fmc_sdcmr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return static_cast<fmc_sdcmr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdcmr_r> other) const -> opsy::utility::clear_set<fmc_sdcmr_r> {return opsy::utility::clear_set<fmc_sdcmr_r>(fmc_sdcmr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

	[[nodiscard]] constexpr auto mode() const -> mode_f {return mode_f(static_cast<uint8_t>(value_ >> mode_f::offset));}
	[[nodiscard]] constexpr auto ctb2() const -> ctb2_f {return ctb2_f((value_ & ctb2_f::mask) != 0);}
	[[nodiscard]] constexpr auto ctb1() const -> ctb1_f {return ctb1_f((value_ & ctb1_f::mask) != 0);}
	[[nodiscard]] constexpr auto nrfs() const -> nrfs_f {return nrfs_f(static_cast<uint8_t>(value_ >> nrfs_f::offset));}
	[[nodiscard]] constexpr auto mrd() const -> mrd_f {return mrd_f(static_cast<uint16_t>(value_ >> mrd_f::offset));}

	constexpr fmc_sdcmr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sdcmr_r other) const -> fmc_sdcmr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sdcmr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDRAM refresh timer register
 */
class fmc_sdrtr_r {
public:

/**
 * Clear Refresh error flag This bit is used to clear the Refresh Error Flag (RE) in the Status Register.
 */
class cre_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr cre_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdrtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdrtr_r>() const {return opsy::utility::clear_set<fmc_sdrtr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdrtr_r other) const -> fmc_sdrtr_r { return static_cast<fmc_sdrtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdrtr_r> other) const -> opsy::utility::clear_set<fmc_sdrtr_r> {return opsy::utility::clear_set<fmc_sdrtr_r>(fmc_sdrtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Refresh Timer Count This 13-bit field defines the refresh rate of the SDRAM device. It is expressed in number of memory clock cycles. It must be set at least to 41 SDRAM clock cycles (0x29). Refresh rate = (COUNT + 1) x SDRAM frequency clock COUNT = (SDRAM refresh period / Number of rows)20
 */
class count_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 13;
	static constexpr uint16_t range = static_cast<uint16_t>(0b1111111111111);
	static constexpr uint16_t mask = static_cast<uint16_t>(static_cast<uint16_t>(range) << offset);

	constexpr count_f(uint16_t value) : value_(value & range) {}
	constexpr operator uint16_t() const {return value_;}
	constexpr operator fmc_sdrtr_r() const {return static_cast<uint16_t>(static_cast<uint16_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdrtr_r>() const {return opsy::utility::clear_set<fmc_sdrtr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdrtr_r other) const -> fmc_sdrtr_r { return static_cast<fmc_sdrtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdrtr_r> other) const -> opsy::utility::clear_set<fmc_sdrtr_r> {return opsy::utility::clear_set<fmc_sdrtr_r>(fmc_sdrtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint16_t value_;
};

/**
 * RES Interrupt Enable
 */
class reie_f {
public:
	static constexpr std::size_t offset = 14;
	static constexpr std::size_t width = 1;
	static constexpr uint16_t mask = static_cast<uint16_t>(1ULL << offset);

	constexpr reie_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdrtr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdrtr_r>() const {return opsy::utility::clear_set<fmc_sdrtr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdrtr_r other) const -> fmc_sdrtr_r { return static_cast<fmc_sdrtr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdrtr_r> other) const -> opsy::utility::clear_set<fmc_sdrtr_r> {return opsy::utility::clear_set<fmc_sdrtr_r>(fmc_sdrtr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto cre() const -> cre_f {return cre_f((value_ & cre_f::mask) != 0);}
	[[nodiscard]] constexpr auto count() const -> count_f {return count_f(static_cast<uint16_t>(value_ >> count_f::offset));}
	[[nodiscard]] constexpr auto reie() const -> reie_f {return reie_f((value_ & reie_f::mask) != 0);}

	constexpr fmc_sdrtr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sdrtr_r other) const -> fmc_sdrtr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sdrtr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

/**
 * SDRAM status register
 */
class fmc_sdsr_r {
public:

/**
 * Refresh error flag An interrupt is generated if REIE = 1 and RE = 1
 */
class re_f {
public:
	static constexpr std::size_t offset = 0;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr re_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdsr_r>() const {return opsy::utility::clear_set<fmc_sdsr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdsr_r other) const -> fmc_sdsr_r { return static_cast<fmc_sdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdsr_r> other) const -> opsy::utility::clear_set<fmc_sdsr_r> {return opsy::utility::clear_set<fmc_sdsr_r>(fmc_sdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

/**
 * Status Mode for Bank 1 This bit defines the Status Mode of SDRAM Bank 1.
 */
class modes1_f {
public:
	static constexpr std::size_t offset = 1;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr modes1_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdsr_r>() const {return opsy::utility::clear_set<fmc_sdsr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdsr_r other) const -> fmc_sdsr_r { return static_cast<fmc_sdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdsr_r> other) const -> opsy::utility::clear_set<fmc_sdsr_r> {return opsy::utility::clear_set<fmc_sdsr_r>(fmc_sdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Status Mode for Bank 2 This bit defines the Status Mode of SDRAM Bank 2.
 */
class modes2_f {
public:
	static constexpr std::size_t offset = 3;
	static constexpr std::size_t width = 2;
	static constexpr uint8_t range = static_cast<uint8_t>(0b11);
	static constexpr uint8_t mask = static_cast<uint8_t>(static_cast<uint8_t>(range) << offset);

	constexpr modes2_f(uint8_t value) : value_(value & range) {}
	constexpr operator uint8_t() const {return value_;}
	constexpr operator fmc_sdsr_r() const {return static_cast<uint8_t>(static_cast<uint8_t>(value_) << offset);}
	constexpr operator opsy::utility::clear_set<fmc_sdsr_r>() const {return opsy::utility::clear_set<fmc_sdsr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdsr_r other) const -> fmc_sdsr_r { return static_cast<fmc_sdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdsr_r> other) const -> opsy::utility::clear_set<fmc_sdsr_r> {return opsy::utility::clear_set<fmc_sdsr_r>(fmc_sdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 uint8_t value_;
};

/**
 * Busy status This bit defines the status of the SDRAM controller after a Command Mode request 1; SDRAM Controller is not ready to accept a new request
 */
class busy_f {
public:
	static constexpr std::size_t offset = 5;
	static constexpr std::size_t width = 1;
	static constexpr uint8_t mask = static_cast<uint8_t>(1ULL << offset);

	constexpr busy_f(bool value = true) : value_(value) {}
	constexpr operator bool() const {return value_;}
	constexpr operator fmc_sdsr_r() const {return value_ ? mask : 0;}
	constexpr operator opsy::utility::clear_set<fmc_sdsr_r>() const {return opsy::utility::clear_set<fmc_sdsr_r>(mask, *this);}
	constexpr auto operator|(fmc_sdsr_r other) const -> fmc_sdsr_r { return static_cast<fmc_sdsr_r>(*this) | other.value_;}
	constexpr auto operator||(opsy::utility::clear_set<fmc_sdsr_r> other) const -> opsy::utility::clear_set<fmc_sdsr_r> {return opsy::utility::clear_set<fmc_sdsr_r>(fmc_sdsr_r(mask) | other.clear(), *this | other.set()); }

private:
	 bool value_;
};

	[[nodiscard]] constexpr auto re() const -> re_f {return re_f((value_ & re_f::mask) != 0);}
	[[nodiscard]] constexpr auto modes1() const -> modes1_f {return modes1_f(static_cast<uint8_t>(value_ >> modes1_f::offset));}
	[[nodiscard]] constexpr auto modes2() const -> modes2_f {return modes2_f(static_cast<uint8_t>(value_ >> modes2_f::offset));}
	[[nodiscard]] constexpr auto busy() const -> busy_f {return busy_f((value_ & busy_f::mask) != 0);}

	constexpr fmc_sdsr_r(uint32_t value) : value_(value) {}
	constexpr auto operator |(fmc_sdsr_r other) const -> fmc_sdsr_r { return value_ | other.value_; }
	constexpr auto operator ~() const -> fmc_sdsr_r { return ~value_; }
	[[nodiscard]] constexpr auto value() const { return value_; }

	static constexpr uint32_t reset_value = 0; // 0 0x0

private:
	uint32_t value_;
};

	opsy::utility::memory<uint32_t,fmc_bcr1_r> fmc_bcr1;
	opsy::utility::memory<uint32_t,fmc_btrx_r> fmc_btr1;
	opsy::utility::memory<uint32_t,fmc_bcrx_r> fmc_bcr2;
	opsy::utility::memory<uint32_t,fmc_btrx_r> fmc_btr2;
	opsy::utility::memory<uint32_t,fmc_bcrx_r> fmc_bcr3;
	opsy::utility::memory<uint32_t,fmc_btrx_r> fmc_btr3;
	opsy::utility::memory<uint32_t,fmc_bcrx_r> fmc_bcr4;
	opsy::utility::memory<uint32_t,fmc_btrx_r> fmc_btr4;
	opsy::utility::memory<uint32_t,fmc_pcscntr_r> fmc_pcscntr;
	opsy::utility::padding<92> _p0;
	opsy::utility::memory<uint32_t,fmc_pcr_r> fmc_pcr;
	opsy::utility::memory<uint32_t,fmc_sr_r> fmc_sr;
	opsy::utility::memory<uint32_t,fmc_pmem_r> fmc_pmem;
	opsy::utility::memory<uint32_t,fmc_patt_r> fmc_patt;
	opsy::utility::padding<4> _p1;
	opsy::utility::memory<uint32_t,fmc_eccr_r> fmc_eccr;
	opsy::utility::padding<108> _p2;
	opsy::utility::memory<uint32_t,fmc_bwtrx_r> fmc_bwtr1;
	opsy::utility::padding<4> _p3;
	opsy::utility::memory<uint32_t,fmc_bwtrx_r> fmc_bwtr2;
	opsy::utility::padding<4> _p4;
	opsy::utility::memory<uint32_t,fmc_bwtrx_r> fmc_bwtr3;
	opsy::utility::padding<4> _p5;
	opsy::utility::memory<uint32_t,fmc_bwtrx_r> fmc_bwtr4;
	opsy::utility::padding<32> _p6;
	opsy::utility::memory<uint32_t,fmc_sdcrx_r> fmc_sdcr1;
	opsy::utility::memory<uint32_t,fmc_sdcrx_r> fmc_sdcr2;
	opsy::utility::memory<uint32_t,fmc_sdtrx_r> fmc_sdtr1;
	opsy::utility::memory<uint32_t,fmc_sdtrx_r> fmc_sdtr2;
	opsy::utility::memory<uint32_t,fmc_sdcmr_r> fmc_sdcmr;
	opsy::utility::memory<uint32_t,fmc_sdrtr_r> fmc_sdrtr;
	opsy::utility::memory<uint32_t,fmc_sdsr_r> fmc_sdsr;
};

static_assert(std::is_standard_layout_v<fmc_p>);
static_assert(offsetof(fmc_p, fmc_bcr1) == 0);
static_assert(offsetof(fmc_p, fmc_btr1) == 4);
static_assert(offsetof(fmc_p, fmc_bcr2) == 8);
static_assert(offsetof(fmc_p, fmc_btr2) == 12);
static_assert(offsetof(fmc_p, fmc_bcr3) == 16);
static_assert(offsetof(fmc_p, fmc_btr3) == 20);
static_assert(offsetof(fmc_p, fmc_bcr4) == 24);
static_assert(offsetof(fmc_p, fmc_btr4) == 28);
static_assert(offsetof(fmc_p, fmc_pcscntr) == 32);
static_assert(offsetof(fmc_p, fmc_pcr) == 128);
static_assert(offsetof(fmc_p, fmc_sr) == 132);
static_assert(offsetof(fmc_p, fmc_pmem) == 136);
static_assert(offsetof(fmc_p, fmc_patt) == 140);
static_assert(offsetof(fmc_p, fmc_eccr) == 148);
static_assert(offsetof(fmc_p, fmc_bwtr1) == 260);
static_assert(offsetof(fmc_p, fmc_bwtr2) == 268);
static_assert(offsetof(fmc_p, fmc_bwtr3) == 276);
static_assert(offsetof(fmc_p, fmc_bwtr4) == 284);
static_assert(offsetof(fmc_p, fmc_sdcr1) == 320);
static_assert(offsetof(fmc_p, fmc_sdcr2) == 324);
static_assert(offsetof(fmc_p, fmc_sdtr1) == 328);
static_assert(offsetof(fmc_p, fmc_sdtr2) == 332);
static_assert(offsetof(fmc_p, fmc_sdcmr) == 336);
static_assert(offsetof(fmc_p, fmc_sdrtr) == 340);
static_assert(offsetof(fmc_p, fmc_sdsr) == 344);

inline fmc_p& fmc = *reinterpret_cast<fmc_p*>(0x47000400);
inline fmc_p& sec_fmc = *reinterpret_cast<fmc_p*>(0x57000400);

} // STM32H563

