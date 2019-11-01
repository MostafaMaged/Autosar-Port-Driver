/******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port_Cfg.h
 *
 * Description: Pre-Compile Configuration Header file for Port Module.
 *
 * Author: Mostafa Maged
 ******************************************************************************/
#ifndef PORT_CFG_H
#define PORT_CFG_H

/*
 * Module Version 1.0.0
 */
#define PORT_CFG_SW_MAJOR_VERSION              (1U)
#define PORT_CFG_SW_MINOR_VERSION              (0U)
#define PORT_CFG_SW_PATCH_VERSION              (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_CFG_AR_RELEASE_MAJOR_VERSION     (4U)
#define PORT_CFG_AR_RELEASE_MINOR_VERSION     (0U)
#define PORT_CFG_AR_RELEASE_PATCH_VERSION     (3U)

/* Pre-compile option for Development Error Detect */
#define PORT_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define PORT_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of Port_SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_API                (STD_ON)

/* Number of the configured Dio Channels */
#define PORT_CONFIGURED_CHANNLES              (32U)

/* PORT configured pins IDs */
#define PORT_A_PIN_0_INDEX			(0U)
#define PORT_A_PIN_1_INDEX			(1U)
#define PORT_A_PIN_2_INDEX			(2U)
#define PORT_A_PIN_3_INDEX			(3U)
#define PORT_A_PIN_4_INDEX			(4U)
#define PORT_A_PIN_5_INDEX			(5U)
#define PORT_A_PIN_6_INDEX			(6U)
#define PORT_A_PIN_7_INDEX			(7U)

#define PORT_B_PIN_0_INDEX			(8U)
#define PORT_B_PIN_1_INDEX			(9U)
#define PORT_B_PIN_2_INDEX			(10U)
#define PORT_B_PIN_3_INDEX			(11U)
#define PORT_B_PIN_4_INDEX			(12U)
#define PORT_B_PIN_5_INDEX			(13U)
#define PORT_B_PIN_6_INDEX			(14U)
#define PORT_B_PIN_7_INDEX			(15U)

#define PORT_C_PIN_0_INDEX			(16U)
#define PORT_C_PIN_1_INDEX			(17U)
#define PORT_C_PIN_2_INDEX			(18U)
#define PORT_C_PIN_3_INDEX			(19U)
#define PORT_C_PIN_4_INDEX			(20U)
#define PORT_C_PIN_5_INDEX			(21U)
#define PORT_C_PIN_6_INDEX			(22U)
#define PORT_C_PIN_7_INDEX			(23U)

#define PORT_D_PIN_0_INDEX			(24U)
#define PORT_D_PIN_1_INDEX			(25U)
#define PORT_D_PIN_2_INDEX			(26U)
#define PORT_D_PIN_3_INDEX			(27U)
#define PORT_D_PIN_4_INDEX			(28U)
#define PORT_D_PIN_5_INDEX			(29U)
#define PORT_D_PIN_6_INDEX			(30U)
#define PORT_D_PIN_7_INDEX			(31U)

#endif



