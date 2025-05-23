/*
 * Copyright (c) 2021-2025 HPMicro
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 */


#ifndef HPM_LINV2_H
#define HPM_LINV2_H

typedef struct {
    union {
        __RW uint32_t DATA[2];                 /* 0x0 - 0x4: data byte */
        __RW uint8_t  DATA_BYTE[8];            /* 0x0 - 0x7:  */
    };
    __RW uint32_t DATA_LEN_ID;                 /* 0x8: data length and ID register */
    __RW uint32_t CONTROL_STATUS;              /* 0xC: control and status register */
    __RW uint32_t TIMING_CONTROL;              /* 0x10: timing control register */
    __RW uint32_t DMA_CONTROL;                 /* 0x14: dma control register */
} LINV2_Type;


/* Bitfield definition for register: DATA0 */
/*
 * DATA (RW)
 *
 * data
 */
#define LINV2_DATA_DATA_MASK (0xFFFFFFFFUL)
#define LINV2_DATA_DATA_SHIFT (0U)
#define LINV2_DATA_DATA_SET(x) (((uint32_t)(x) << LINV2_DATA_DATA_SHIFT) & LINV2_DATA_DATA_MASK)
#define LINV2_DATA_DATA_GET(x) (((uint32_t)(x) & LINV2_DATA_DATA_MASK) >> LINV2_DATA_DATA_SHIFT)

/* Bitfield definition for register: DATA_BYTE0 */
/*
 * DATA_BYTE (RW)
 *
 * data byte
 */
#define LINV2_DATA_BYTE_DATA_BYTE_MASK (0xFFU)
#define LINV2_DATA_BYTE_DATA_BYTE_SHIFT (0U)
#define LINV2_DATA_BYTE_DATA_BYTE_SET(x) (((uint8_t)(x) << LINV2_DATA_BYTE_DATA_BYTE_SHIFT) & LINV2_DATA_BYTE_DATA_BYTE_MASK)
#define LINV2_DATA_BYTE_DATA_BYTE_GET(x) (((uint8_t)(x) & LINV2_DATA_BYTE_DATA_BYTE_MASK) >> LINV2_DATA_BYTE_DATA_BYTE_SHIFT)

/* Bitfield definition for register: DATA_LEN_ID */
/*
 * CHECKSUM (RO)
 *
 */
#define LINV2_DATA_LEN_ID_CHECKSUM_MASK (0xFF0000UL)
#define LINV2_DATA_LEN_ID_CHECKSUM_SHIFT (16U)
#define LINV2_DATA_LEN_ID_CHECKSUM_GET(x) (((uint32_t)(x) & LINV2_DATA_LEN_ID_CHECKSUM_MASK) >> LINV2_DATA_LEN_ID_CHECKSUM_SHIFT)

/*
 * ID_PARITY (RO)
 *
 */
#define LINV2_DATA_LEN_ID_ID_PARITY_MASK (0xC000U)
#define LINV2_DATA_LEN_ID_ID_PARITY_SHIFT (14U)
#define LINV2_DATA_LEN_ID_ID_PARITY_GET(x) (((uint32_t)(x) & LINV2_DATA_LEN_ID_ID_PARITY_MASK) >> LINV2_DATA_LEN_ID_ID_PARITY_SHIFT)

/*
 * ID (RW)
 *
 * ID register
 */
#define LINV2_DATA_LEN_ID_ID_MASK (0x3F00U)
#define LINV2_DATA_LEN_ID_ID_SHIFT (8U)
#define LINV2_DATA_LEN_ID_ID_SET(x) (((uint32_t)(x) << LINV2_DATA_LEN_ID_ID_SHIFT) & LINV2_DATA_LEN_ID_ID_MASK)
#define LINV2_DATA_LEN_ID_ID_GET(x) (((uint32_t)(x) & LINV2_DATA_LEN_ID_ID_MASK) >> LINV2_DATA_LEN_ID_ID_SHIFT)

/*
 * ENH_CHECK (RW)
 *
 * 1:enhance check mode 0:classical check mode
 */
#define LINV2_DATA_LEN_ID_ENH_CHECK_MASK (0x80U)
#define LINV2_DATA_LEN_ID_ENH_CHECK_SHIFT (7U)
#define LINV2_DATA_LEN_ID_ENH_CHECK_SET(x) (((uint32_t)(x) << LINV2_DATA_LEN_ID_ENH_CHECK_SHIFT) & LINV2_DATA_LEN_ID_ENH_CHECK_MASK)
#define LINV2_DATA_LEN_ID_ENH_CHECK_GET(x) (((uint32_t)(x) & LINV2_DATA_LEN_ID_ENH_CHECK_MASK) >> LINV2_DATA_LEN_ID_ENH_CHECK_SHIFT)

/*
 * DATA_LEN (RW)
 *
 * payload data length control register。The data length will decoded from ID[5:4] when all 1 is configured: 00-2 01-2 10-4 11-8
 */
#define LINV2_DATA_LEN_ID_DATA_LEN_MASK (0xFU)
#define LINV2_DATA_LEN_ID_DATA_LEN_SHIFT (0U)
#define LINV2_DATA_LEN_ID_DATA_LEN_SET(x) (((uint32_t)(x) << LINV2_DATA_LEN_ID_DATA_LEN_SHIFT) & LINV2_DATA_LEN_ID_DATA_LEN_MASK)
#define LINV2_DATA_LEN_ID_DATA_LEN_GET(x) (((uint32_t)(x) & LINV2_DATA_LEN_ID_DATA_LEN_MASK) >> LINV2_DATA_LEN_ID_DATA_LEN_SHIFT)

/* Bitfield definition for register: CONTROL_STATUS */
/*
 * BREAK_ERR_DIS (RW)
 *
 */
#define LINV2_CONTROL_STATUS_BREAK_ERR_DIS_MASK (0x200000UL)
#define LINV2_CONTROL_STATUS_BREAK_ERR_DIS_SHIFT (21U)
#define LINV2_CONTROL_STATUS_BREAK_ERR_DIS_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_BREAK_ERR_DIS_SHIFT) & LINV2_CONTROL_STATUS_BREAK_ERR_DIS_MASK)
#define LINV2_CONTROL_STATUS_BREAK_ERR_DIS_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_BREAK_ERR_DIS_MASK) >> LINV2_CONTROL_STATUS_BREAK_ERR_DIS_SHIFT)

/*
 * BREAK_ERR (RO)
 *
 */
#define LINV2_CONTROL_STATUS_BREAK_ERR_MASK (0x100000UL)
#define LINV2_CONTROL_STATUS_BREAK_ERR_SHIFT (20U)
#define LINV2_CONTROL_STATUS_BREAK_ERR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_BREAK_ERR_MASK) >> LINV2_CONTROL_STATUS_BREAK_ERR_SHIFT)

/*
 * PARITY_ERROR (RO)
 *
 * slave only. identifier parity error
 */
#define LINV2_CONTROL_STATUS_PARITY_ERROR_MASK (0x80000UL)
#define LINV2_CONTROL_STATUS_PARITY_ERROR_SHIFT (19U)
#define LINV2_CONTROL_STATUS_PARITY_ERROR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_PARITY_ERROR_MASK) >> LINV2_CONTROL_STATUS_PARITY_ERROR_SHIFT)

/*
 * TIME_OUT (RO)
 *
 * timeout error. The master detects a timeout error if it is expecting data from the bus but no slave does respond. The slave detects a timeout error if it is requesting a data acknowledge to the host controller. The slave detects a timeout if it has transmitted a wakeup signal and it detects no sync field within 150ms
 */
#define LINV2_CONTROL_STATUS_TIME_OUT_MASK (0x40000UL)
#define LINV2_CONTROL_STATUS_TIME_OUT_SHIFT (18U)
#define LINV2_CONTROL_STATUS_TIME_OUT_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_TIME_OUT_MASK) >> LINV2_CONTROL_STATUS_TIME_OUT_SHIFT)

/*
 * CHK_ERROR (RO)
 *
 * checksum error
 */
#define LINV2_CONTROL_STATUS_CHK_ERROR_MASK (0x20000UL)
#define LINV2_CONTROL_STATUS_CHK_ERROR_SHIFT (17U)
#define LINV2_CONTROL_STATUS_CHK_ERROR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_CHK_ERROR_MASK) >> LINV2_CONTROL_STATUS_CHK_ERROR_SHIFT)

/*
 * BIT_ERROR (RO)
 *
 * bit error
 */
#define LINV2_CONTROL_STATUS_BIT_ERROR_MASK (0x10000UL)
#define LINV2_CONTROL_STATUS_BIT_ERROR_SHIFT (16U)
#define LINV2_CONTROL_STATUS_BIT_ERROR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_BIT_ERROR_MASK) >> LINV2_CONTROL_STATUS_BIT_ERROR_SHIFT)

/*
 * LIN_ACTIVE (RO)
 *
 * The bit indicates whether the LIN bus is active or not
 */
#define LINV2_CONTROL_STATUS_LIN_ACTIVE_MASK (0x8000U)
#define LINV2_CONTROL_STATUS_LIN_ACTIVE_SHIFT (15U)
#define LINV2_CONTROL_STATUS_LIN_ACTIVE_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_LIN_ACTIVE_MASK) >> LINV2_CONTROL_STATUS_LIN_ACTIVE_SHIFT)

/*
 * BUS_IDLE_TIMEOUT (RO)
 *
 * slave only. This bit is set by LIN core if bit sleep  is not set and no bus activity is detected for 4s
 */
#define LINV2_CONTROL_STATUS_BUS_IDLE_TIMEOUT_MASK (0x4000U)
#define LINV2_CONTROL_STATUS_BUS_IDLE_TIMEOUT_SHIFT (14U)
#define LINV2_CONTROL_STATUS_BUS_IDLE_TIMEOUT_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_BUS_IDLE_TIMEOUT_MASK) >> LINV2_CONTROL_STATUS_BUS_IDLE_TIMEOUT_SHIFT)

/*
 * ABORTED (RO)
 *
 * slave only. This bit is set by LIN core slave if a transmission is aborted after the bneginning of the data field due to a timeout or bit error.
 */
#define LINV2_CONTROL_STATUS_ABORTED_MASK (0x2000U)
#define LINV2_CONTROL_STATUS_ABORTED_SHIFT (13U)
#define LINV2_CONTROL_STATUS_ABORTED_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_ABORTED_MASK) >> LINV2_CONTROL_STATUS_ABORTED_SHIFT)

/*
 * DATA_REQ (RO)
 *
 * slave only. Sets after receiving the identifier and requests an interrupt to the host controller.
 */
#define LINV2_CONTROL_STATUS_DATA_REQ_MASK (0x1000U)
#define LINV2_CONTROL_STATUS_DATA_REQ_SHIFT (12U)
#define LINV2_CONTROL_STATUS_DATA_REQ_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_DATA_REQ_MASK) >> LINV2_CONTROL_STATUS_DATA_REQ_SHIFT)

/*
 * INT (RO)
 *
 * set when request an interrupt. Reset by reset_int
 */
#define LINV2_CONTROL_STATUS_INT_MASK (0x800U)
#define LINV2_CONTROL_STATUS_INT_SHIFT (11U)
#define LINV2_CONTROL_STATUS_INT_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_INT_MASK) >> LINV2_CONTROL_STATUS_INT_SHIFT)

/*
 * ERROR (RO)
 *
 * set when detecte an error, clear by reset_error
 */
#define LINV2_CONTROL_STATUS_ERROR_MASK (0x400U)
#define LINV2_CONTROL_STATUS_ERROR_SHIFT (10U)
#define LINV2_CONTROL_STATUS_ERROR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_ERROR_MASK) >> LINV2_CONTROL_STATUS_ERROR_SHIFT)

/*
 * WAKEUP (RO)
 *
 * set when transmitting a wakeup signal or when received a wakeup signal. Clear when reset_error bit is 1
 */
#define LINV2_CONTROL_STATUS_WAKEUP_MASK (0x200U)
#define LINV2_CONTROL_STATUS_WAKEUP_SHIFT (9U)
#define LINV2_CONTROL_STATUS_WAKEUP_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_WAKEUP_MASK) >> LINV2_CONTROL_STATUS_WAKEUP_SHIFT)

/*
 * COMPLETE (RO)
 *
 * set after a transmission has been successful finished and it will reset at the start of a transmission.
 */
#define LINV2_CONTROL_STATUS_COMPLETE_MASK (0x100U)
#define LINV2_CONTROL_STATUS_COMPLETE_SHIFT (8U)
#define LINV2_CONTROL_STATUS_COMPLETE_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_COMPLETE_MASK) >> LINV2_CONTROL_STATUS_COMPLETE_SHIFT)

/*
 * STOP (WO)
 *
 * slave only. Write 1 when the Host determin do not response to the data request according to a unkown ID
 */
#define LINV2_CONTROL_STATUS_STOP_MASK (0x80U)
#define LINV2_CONTROL_STATUS_STOP_SHIFT (7U)
#define LINV2_CONTROL_STATUS_STOP_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_STOP_SHIFT) & LINV2_CONTROL_STATUS_STOP_MASK)
#define LINV2_CONTROL_STATUS_STOP_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_STOP_MASK) >> LINV2_CONTROL_STATUS_STOP_SHIFT)

/*
 * SLEEP (RW)
 *
 * The bit is used by the LIN core to determine whether the LIN bus is in sleep mode or not. Set this bit after sending or receiving a Sleep Mode frame or if a bus idle timeout interrupt is requested or if after a wakeup request there is no response from the master and a timeout is signaled. The bit will be automatically reset by the LIN core.
 */
#define LINV2_CONTROL_STATUS_SLEEP_MASK (0x40U)
#define LINV2_CONTROL_STATUS_SLEEP_SHIFT (6U)
#define LINV2_CONTROL_STATUS_SLEEP_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_SLEEP_SHIFT) & LINV2_CONTROL_STATUS_SLEEP_MASK)
#define LINV2_CONTROL_STATUS_SLEEP_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_SLEEP_MASK) >> LINV2_CONTROL_STATUS_SLEEP_SHIFT)

/*
 * TRANSMIT (RW)
 *
 * 1: transmit operation 0: receive operation
 */
#define LINV2_CONTROL_STATUS_TRANSMIT_MASK (0x20U)
#define LINV2_CONTROL_STATUS_TRANSMIT_SHIFT (5U)
#define LINV2_CONTROL_STATUS_TRANSMIT_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_TRANSMIT_SHIFT) & LINV2_CONTROL_STATUS_TRANSMIT_MASK)
#define LINV2_CONTROL_STATUS_TRANSMIT_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_TRANSMIT_MASK) >> LINV2_CONTROL_STATUS_TRANSMIT_SHIFT)

/*
 * DATA_ACK (RW)
 *
 * slave only. Write 1 after handling a data request interrupt
 */
#define LINV2_CONTROL_STATUS_DATA_ACK_MASK (0x10U)
#define LINV2_CONTROL_STATUS_DATA_ACK_SHIFT (4U)
#define LINV2_CONTROL_STATUS_DATA_ACK_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_DATA_ACK_SHIFT) & LINV2_CONTROL_STATUS_DATA_ACK_MASK)
#define LINV2_CONTROL_STATUS_DATA_ACK_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_DATA_ACK_MASK) >> LINV2_CONTROL_STATUS_DATA_ACK_SHIFT)

/*
 * RESET_INT (WO)
 *
 * set 1 will clear the int register
 */
#define LINV2_CONTROL_STATUS_RESET_INT_MASK (0x8U)
#define LINV2_CONTROL_STATUS_RESET_INT_SHIFT (3U)
#define LINV2_CONTROL_STATUS_RESET_INT_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_RESET_INT_SHIFT) & LINV2_CONTROL_STATUS_RESET_INT_MASK)
#define LINV2_CONTROL_STATUS_RESET_INT_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_RESET_INT_MASK) >> LINV2_CONTROL_STATUS_RESET_INT_SHIFT)

/*
 * RESET_ERROR (WO)
 *
 * set 1 will clear the error register, and also the timeout/complete/wakeup register
 */
#define LINV2_CONTROL_STATUS_RESET_ERROR_MASK (0x4U)
#define LINV2_CONTROL_STATUS_RESET_ERROR_SHIFT (2U)
#define LINV2_CONTROL_STATUS_RESET_ERROR_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_RESET_ERROR_SHIFT) & LINV2_CONTROL_STATUS_RESET_ERROR_MASK)
#define LINV2_CONTROL_STATUS_RESET_ERROR_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_RESET_ERROR_MASK) >> LINV2_CONTROL_STATUS_RESET_ERROR_SHIFT)

/*
 * WAKEUP_REQ (RW)
 *
 * set 1 will make LIN bus exit sleep mode,  the bit auto cleared after a wakeup signal has been complete
 */
#define LINV2_CONTROL_STATUS_WAKEUP_REQ_MASK (0x2U)
#define LINV2_CONTROL_STATUS_WAKEUP_REQ_SHIFT (1U)
#define LINV2_CONTROL_STATUS_WAKEUP_REQ_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_WAKEUP_REQ_SHIFT) & LINV2_CONTROL_STATUS_WAKEUP_REQ_MASK)
#define LINV2_CONTROL_STATUS_WAKEUP_REQ_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_WAKEUP_REQ_MASK) >> LINV2_CONTROL_STATUS_WAKEUP_REQ_SHIFT)

/*
 * START_REQ (RW)
 *
 * master only. Set 1 will start lin transmission, the bit will be auto cleared when an error occur or the transmission complete
 */
#define LINV2_CONTROL_STATUS_START_REQ_MASK (0x1U)
#define LINV2_CONTROL_STATUS_START_REQ_SHIFT (0U)
#define LINV2_CONTROL_STATUS_START_REQ_SET(x) (((uint32_t)(x) << LINV2_CONTROL_STATUS_START_REQ_SHIFT) & LINV2_CONTROL_STATUS_START_REQ_MASK)
#define LINV2_CONTROL_STATUS_START_REQ_GET(x) (((uint32_t)(x) & LINV2_CONTROL_STATUS_START_REQ_MASK) >> LINV2_CONTROL_STATUS_START_REQ_SHIFT)

/* Bitfield definition for register: TIMING_CONTROL */
/*
 * WAKE_LEN (RW)
 *
 */
#define LINV2_TIMING_CONTROL_WAKE_LEN_MASK (0x38000000UL)
#define LINV2_TIMING_CONTROL_WAKE_LEN_SHIFT (27U)
#define LINV2_TIMING_CONTROL_WAKE_LEN_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_WAKE_LEN_SHIFT) & LINV2_TIMING_CONTROL_WAKE_LEN_MASK)
#define LINV2_TIMING_CONTROL_WAKE_LEN_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_WAKE_LEN_MASK) >> LINV2_TIMING_CONTROL_WAKE_LEN_SHIFT)

/*
 * BRK_LEN (RW)
 *
 */
#define LINV2_TIMING_CONTROL_BRK_LEN_MASK (0x7000000UL)
#define LINV2_TIMING_CONTROL_BRK_LEN_SHIFT (24U)
#define LINV2_TIMING_CONTROL_BRK_LEN_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_BRK_LEN_SHIFT) & LINV2_TIMING_CONTROL_BRK_LEN_MASK)
#define LINV2_TIMING_CONTROL_BRK_LEN_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_BRK_LEN_MASK) >> LINV2_TIMING_CONTROL_BRK_LEN_SHIFT)

/*
 * LINBUSDISABLE (RW)
 *
 * 1：lin rx is disable
 */
#define LINV2_TIMING_CONTROL_LINBUSDISABLE_MASK (0x400000UL)
#define LINV2_TIMING_CONTROL_LINBUSDISABLE_SHIFT (22U)
#define LINV2_TIMING_CONTROL_LINBUSDISABLE_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_LINBUSDISABLE_SHIFT) & LINV2_TIMING_CONTROL_LINBUSDISABLE_MASK)
#define LINV2_TIMING_CONTROL_LINBUSDISABLE_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_LINBUSDISABLE_MASK) >> LINV2_TIMING_CONTROL_LINBUSDISABLE_SHIFT)

/*
 * LIN_INITIAL (RW)
 *
 * 1:initial lin controller
 */
#define LINV2_TIMING_CONTROL_LIN_INITIAL_MASK (0x200000UL)
#define LINV2_TIMING_CONTROL_LIN_INITIAL_SHIFT (21U)
#define LINV2_TIMING_CONTROL_LIN_INITIAL_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_LIN_INITIAL_SHIFT) & LINV2_TIMING_CONTROL_LIN_INITIAL_MASK)
#define LINV2_TIMING_CONTROL_LIN_INITIAL_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_LIN_INITIAL_MASK) >> LINV2_TIMING_CONTROL_LIN_INITIAL_SHIFT)

/*
 * MASTER_MODE (RW)
 *
 * 1：master mode
 */
#define LINV2_TIMING_CONTROL_MASTER_MODE_MASK (0x100000UL)
#define LINV2_TIMING_CONTROL_MASTER_MODE_SHIFT (20U)
#define LINV2_TIMING_CONTROL_MASTER_MODE_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_MASTER_MODE_SHIFT) & LINV2_TIMING_CONTROL_MASTER_MODE_MASK)
#define LINV2_TIMING_CONTROL_MASTER_MODE_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_MASTER_MODE_MASK) >> LINV2_TIMING_CONTROL_MASTER_MODE_SHIFT)

/*
 * BUS_INACTIVE_TIME (RW)
 *
 * slave only. LIN bus idle timeout register： 00-4s  01-6s  10-8s  11-10s
 */
#define LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_MASK (0xC0000UL)
#define LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_SHIFT (18U)
#define LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_SHIFT) & LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_MASK)
#define LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_MASK) >> LINV2_TIMING_CONTROL_BUS_INACTIVE_TIME_SHIFT)

/*
 * WUP_REPEAT_TIME (RW)
 *
 * slave only. wakeup repeat interval time  00-180ms  01-200ms 10-220ms 11-240ms
 */
#define LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_MASK (0x30000UL)
#define LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_SHIFT (16U)
#define LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_SHIFT) & LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_MASK)
#define LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_MASK) >> LINV2_TIMING_CONTROL_WUP_REPEAT_TIME_SHIFT)

/*
 * PRESCL (RW)
 *
 * prescl register
 */
#define LINV2_TIMING_CONTROL_PRESCL_MASK (0xC000U)
#define LINV2_TIMING_CONTROL_PRESCL_SHIFT (14U)
#define LINV2_TIMING_CONTROL_PRESCL_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_PRESCL_SHIFT) & LINV2_TIMING_CONTROL_PRESCL_MASK)
#define LINV2_TIMING_CONTROL_PRESCL_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_PRESCL_MASK) >> LINV2_TIMING_CONTROL_PRESCL_SHIFT)

/*
 * BT_MUL (RW)
 *
 * bt_mul register
 */
#define LINV2_TIMING_CONTROL_BT_MUL_MASK (0x3E00U)
#define LINV2_TIMING_CONTROL_BT_MUL_SHIFT (9U)
#define LINV2_TIMING_CONTROL_BT_MUL_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_BT_MUL_SHIFT) & LINV2_TIMING_CONTROL_BT_MUL_MASK)
#define LINV2_TIMING_CONTROL_BT_MUL_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_BT_MUL_MASK) >> LINV2_TIMING_CONTROL_BT_MUL_SHIFT)

/*
 * BT_DIV (RW)
 *
 * bt_div register
 */
#define LINV2_TIMING_CONTROL_BT_DIV_MASK (0x1FFU)
#define LINV2_TIMING_CONTROL_BT_DIV_SHIFT (0U)
#define LINV2_TIMING_CONTROL_BT_DIV_SET(x) (((uint32_t)(x) << LINV2_TIMING_CONTROL_BT_DIV_SHIFT) & LINV2_TIMING_CONTROL_BT_DIV_MASK)
#define LINV2_TIMING_CONTROL_BT_DIV_GET(x) (((uint32_t)(x) & LINV2_TIMING_CONTROL_BT_DIV_MASK) >> LINV2_TIMING_CONTROL_BT_DIV_SHIFT)

/* Bitfield definition for register: DMA_CONTROL */
/*
 * DMA_REQ_ENH_CHK (RW)
 *
 * payload data checksum type for dma operation
 */
#define LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_MASK (0x1000U)
#define LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_SHIFT (12U)
#define LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_SET(x) (((uint32_t)(x) << LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_SHIFT) & LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_MASK)
#define LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_GET(x) (((uint32_t)(x) & LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_MASK) >> LINV2_DMA_CONTROL_DMA_REQ_ENH_CHK_SHIFT)

/*
 * DMA_REQ_LEN (RW)
 *
 * paylaod length for dma request
 */
#define LINV2_DMA_CONTROL_DMA_REQ_LEN_MASK (0xF00U)
#define LINV2_DMA_CONTROL_DMA_REQ_LEN_SHIFT (8U)
#define LINV2_DMA_CONTROL_DMA_REQ_LEN_SET(x) (((uint32_t)(x) << LINV2_DMA_CONTROL_DMA_REQ_LEN_SHIFT) & LINV2_DMA_CONTROL_DMA_REQ_LEN_MASK)
#define LINV2_DMA_CONTROL_DMA_REQ_LEN_GET(x) (((uint32_t)(x) & LINV2_DMA_CONTROL_DMA_REQ_LEN_MASK) >> LINV2_DMA_CONTROL_DMA_REQ_LEN_SHIFT)

/*
 * DMA_REQ_ID_TYPE (RW)
 *
 * 1：transmite  0：receive
 */
#define LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_MASK (0x80U)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_SHIFT (7U)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_SET(x) (((uint32_t)(x) << LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_SHIFT) & LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_MASK)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_GET(x) (((uint32_t)(x) & LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_MASK) >> LINV2_DMA_CONTROL_DMA_REQ_ID_TYPE_SHIFT)

/*
 * DMA_REQ_ID (RW)
 *
 * dma_req_id register
 */
#define LINV2_DMA_CONTROL_DMA_REQ_ID_MASK (0x7EU)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_SHIFT (1U)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_SET(x) (((uint32_t)(x) << LINV2_DMA_CONTROL_DMA_REQ_ID_SHIFT) & LINV2_DMA_CONTROL_DMA_REQ_ID_MASK)
#define LINV2_DMA_CONTROL_DMA_REQ_ID_GET(x) (((uint32_t)(x) & LINV2_DMA_CONTROL_DMA_REQ_ID_MASK) >> LINV2_DMA_CONTROL_DMA_REQ_ID_SHIFT)

/*
 * DMA_REQ_ENABLE (RW)
 *
 * slave mode only. 1: enable dma request for data request ID equal dma_req_id
 */
#define LINV2_DMA_CONTROL_DMA_REQ_ENABLE_MASK (0x1U)
#define LINV2_DMA_CONTROL_DMA_REQ_ENABLE_SHIFT (0U)
#define LINV2_DMA_CONTROL_DMA_REQ_ENABLE_SET(x) (((uint32_t)(x) << LINV2_DMA_CONTROL_DMA_REQ_ENABLE_SHIFT) & LINV2_DMA_CONTROL_DMA_REQ_ENABLE_MASK)
#define LINV2_DMA_CONTROL_DMA_REQ_ENABLE_GET(x) (((uint32_t)(x) & LINV2_DMA_CONTROL_DMA_REQ_ENABLE_MASK) >> LINV2_DMA_CONTROL_DMA_REQ_ENABLE_SHIFT)



/* DATA register group index macro definition */
#define LINV2_DATA_DATA0 (0UL)
#define LINV2_DATA_DATA1 (1UL)

/* DATA_BYTE register group index macro definition */
#define LINV2_DATA_BYTE_DATA_BYTE0 (0UL)
#define LINV2_DATA_BYTE_DATA_BYTE1 (1UL)
#define LINV2_DATA_BYTE_DATA_BYTE2 (2UL)
#define LINV2_DATA_BYTE_DATA_BYTE3 (3UL)
#define LINV2_DATA_BYTE_DATA_BYTE4 (4UL)
#define LINV2_DATA_BYTE_DATA_BYTE5 (5UL)
#define LINV2_DATA_BYTE_DATA_BYTE6 (6UL)
#define LINV2_DATA_BYTE_DATA_BYTE7 (7UL)


#endif /* HPM_LINV2_H */
