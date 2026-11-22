/* SPDX-License-Identifier: MPL-2.0 */
/* SPDX-FileCopyrightText: 2026 Thomas Legrand */

/**
 ******************************************************************************
 * @file    ssc_hw.h
 * @author  Thomas Legrand
 * @brief   Hardware access layer of the Beckhoff EtherCAT Slave Stack Code (SSC) on the
 *          Bornier base board
 *
 *          The SSC is not part of this repository: it is licensed separately and generated
 *          with the SSC Tool, and the build points at it (BORNIER_SSC_DIR). The stack includes
 *          this header through its HW_ACCESS_FILE setting, so it is plain C.
 *
 *          The LAN9253 is driven by esc_bus. HW_Init() resets it: it starts in compatibility
 *          mode (PDI 0x80, its straps), where the stack serves the EEPROM emulation through its
 *          CSR command register, then takes the PDI of the SII, EtherCAT Direct Mapped (0x82):
 *          from then on, each access of the stack is one SPI transaction, any address and
 *          length, moved by DMA while the calling task sleeps when longer than a word.
 *
 *          The stack runs from one task: its main loop, and its interrupt routine PDI_Isr() when
 *          ESC_IRQ wakes the task (see esc_irq). Both never run at once, so DISABLE_ESC_INT() and
 *          ENABLE_ESC_INT() are empty.
 *
 *          Timer: one tick per millisecond, from the RTOS clock.
 ******************************************************************************
 */

#ifndef SSC_HW_H
#define SSC_HW_H

#include "ecat_def.h"

#ifdef __cplusplus
extern "C" {
#endif

#define ECAT_TIMER_INC_P_MS 1 /* timer ticks per millisecond */

/* Whether an AL event the stack asked for (AL event mask) is still pending: the stack's interrupt
   routine has more to serve. One read of the AL event request. */
BOOL ssc_hw_event_pending(void);

UINT32 ssc_hw_timer(void);
void ssc_hw_clear_timer(void);

/* Diagnostics: the error codes the stack wrote to the AL status code register (0x0134) since
   start, the master clearing an error before a report could read the register. */
typedef struct
{
	UINT32 count;   /* codes other than 0 written */
	UINT16 last;    /* the last of them */
	UINT32 last_ms; /* when, in milliseconds since start */
} ssc_hw_al_errors_t;
ssc_hw_al_errors_t ssc_hw_al_errors(void);

#define HW_GetTimer()   ssc_hw_timer()
#define HW_ClearTimer() ssc_hw_clear_timer()

#define DISABLE_ESC_INT()
#define ENABLE_ESC_INT()

UINT8  HW_Init(void);
void   HW_Release(void);
UINT16 HW_GetALEventRegister(void);
UINT16 HW_GetALEventRegister_Isr(void);
UINT16 HW_EepromReload(void);

void HW_EscRead(MEM_ADDR *pData, UINT16 Address, UINT16 Len);
void HW_EscReadIsr(MEM_ADDR *pData, UINT16 Address, UINT16 Len);
void HW_EscWrite(MEM_ADDR *pData, UINT16 Address, UINT16 Len);
void HW_EscWriteIsr(MEM_ADDR *pData, UINT16 Address, UINT16 Len);

/* Typed accesses take a variable, not a value: they pass its address. */
#define HW_EscReadByte(Value, Address)     HW_EscRead((MEM_ADDR *)&(Value), (UINT16)(Address), 1)
#define HW_EscReadWord(Value, Address)     HW_EscRead((MEM_ADDR *)&(Value), (UINT16)(Address), 2)
#define HW_EscReadDWord(Value, Address)    HW_EscRead((MEM_ADDR *)&(Value), (UINT16)(Address), 4)
#define HW_EscReadByteIsr(Value, Address)  HW_EscReadIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 1)
#define HW_EscReadWordIsr(Value, Address)  HW_EscReadIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 2)
#define HW_EscReadDWordIsr(Value, Address) HW_EscReadIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 4)
#define HW_EscReadMbxMem(pData, Address, Len) HW_EscRead((MEM_ADDR *)(pData), (UINT16)(Address), (Len))

#define HW_EscWriteByte(Value, Address)     HW_EscWrite((MEM_ADDR *)&(Value), (UINT16)(Address), 1)
#define HW_EscWriteWord(Value, Address)     HW_EscWrite((MEM_ADDR *)&(Value), (UINT16)(Address), 2)
#define HW_EscWriteDWord(Value, Address)    HW_EscWrite((MEM_ADDR *)&(Value), (UINT16)(Address), 4)
#define HW_EscWriteByteIsr(Value, Address)  HW_EscWriteIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 1)
#define HW_EscWriteWordIsr(Value, Address)  HW_EscWriteIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 2)
#define HW_EscWriteDWordIsr(Value, Address) HW_EscWriteIsr((MEM_ADDR *)&(Value), (UINT16)(Address), 4)
#define HW_EscWriteMbxMem(pData, Address, Len) HW_EscWrite((MEM_ADDR *)(pData), (UINT16)(Address), (Len))

#ifdef __cplusplus
}
#endif

#endif /* SSC_HW_H */
