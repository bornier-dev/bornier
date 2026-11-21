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
 *          The LAN9253 is driven in SPI indirect mode (PDI 0x80) by esc_bus: registers and
 *          short accesses go through its CSR command register, 1, 2 or 4 aligned bytes at a
 *          time; blocks of the process RAM (more than 4 bytes from 0x1000: mailbox, process
 *          data) go through its FIFOs, by DMA, while the calling task sleeps.
 *
 *          First milestone: the stack runs from its main loop only (INIT and PREOP). No ESC
 *          interrupt is used yet, so DISABLE_ESC_INT() and ENABLE_ESC_INT() are empty.
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

UINT32 ssc_hw_timer(void);
void ssc_hw_clear_timer(void);

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
