/*
 * Copyright (c) 2015 - 2016, Freescale Semiconductor, Inc.
 * Copyright 2016 - 2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 * Demo OKDO E1 for Robot biere Projet LCP55S69
 * Auteur : Baptiste FRITOT
 * Version 1.0
 *
 * Demo Interrupt SW202 and SW203
 *
 */

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "board.h"

// IMPORTANT : Use it for interrupt event :
#include "fsl_gint.h"

#include "fsl_common.h"
#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
// Definition port :  0 and 1
#define BOARD_PORT_GPIO_0 kGINT_Port0		// SW203
#define BOARD_PORT_GPIO_1 kGINT_Port1		// SW202

// Definition SWITCH SW203
#ifndef BOARD_SWITCH_SW203_GPIO
#define BOARD_SWITCH_SW203_GPIO GPIO
#endif
#define BOARD_SWITCH_SW203_GPIO_PORT 0U
#ifndef BOARD_SWITCH_SW203_GPIO_PORT_GPIO_PIN
#define BOARD_SWITCH_SW203_GPIO_PORT_GPIO_PIN 5U
#endif

// Definition SWITCH SW202
#ifndef BOARD_SWITCH_SW202_GPIO
#define BOARD_SWITCH_SW202_GPIO GPIO
#endif
#define BOARD_SWITCH_SW202_GPIO_PORT 1U
#ifndef BOARD_SWITCH_SW202_GPIO_PORT_GPIO_PIN
#define BOARD_SWITCH_SW202_GPIO_PORT_GPIO_PIN 9U
#endif

/* Select one input, active low for INT_SW203 */
#define INT_SW203_POL_MASK ~(1U << BOARD_SWITCH_SW203_GPIO_PORT_GPIO_PIN)
#define INT_SW203_ENA_MASK (1U << BOARD_SWITCH_SW203_GPIO_PORT_GPIO_PIN)

/* Select two inputs, active low for INT_SW202. SW2 & SW3 must be connected to the same port */
#define INT_SW202_POL_MASK ~( 1U << BOARD_SWITCH_SW202_GPIO_PORT_GPIO_PIN)
#define INT_SW202_ENA_MASK (1U << BOARD_SWITCH_SW202_GPIO_PORT_GPIO_PIN)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void callback_interrupt_sw203(void);
void callback_interrupt_sw202(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/

/*******************************************************************************
 * Code
 ******************************************************************************/
/*
 * Interruption SW203
 */
void callback_interrupt_sw203(void) {
	PRINTF("Interrupt SW203 detected :)\r\n");
}

/*
 * Interruption SW202
 */
void callback_interrupt_sw202(void) {
	PRINTF("Interrupt SW202 detected :)\r\n");
}

/*
 * Main
 */
int main(void)
{
	/********* Start init *********/

	POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
	/* attach 12 MHz clock to FLEXCOMM0 (debug console) */
	CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitDebugConsole();

	PRINTF("---------------------------------------------\r\n");
	PRINTF("Robot Biere : Test Interruption SW203 & SW202\r\n");
	PRINTF("---------------------------------------------\r\n");
	PRINTF("Press SW203 OR SW202\r\n");

	/* Initialise ports 0 and 1 for interrupt */
	GINT_Init(GINT0);
	GINT_Init(GINT1);

	/* Setup INT_SW203 for edge trigger, "OR" mode */
	//    kGINT_CombineOr  = 0U, /*!< A grouped interrupt is generated when any one of the enabled inputs is active */
	// 	  kGINT_CombineAnd = 1U  /*!< A grouped interrupt is generated when all enabled inputs are active */
	//    kGINT_TrigEdge  = 0U, /*!< Edge triggered based on polarity */
	//    kGINT_TrigLevel = 1U  /*!< Level triggered based on polarity */
	GINT_SetCtrl(GINT0, kGINT_CombineOr, kGINT_TrigEdge, callback_interrupt_sw203);
	GINT_SetCtrl(GINT1, kGINT_CombineAnd, kGINT_TrigEdge, callback_interrupt_sw202);

	/* Select pins & polarity for INT_SW203 */
	GINT_ConfigPins(GINT0, BOARD_PORT_GPIO_0, INT_SW203_POL_MASK, INT_SW203_ENA_MASK);

	/* Select pins & polarity for GINT1 */
	GINT_ConfigPins(GINT1, BOARD_PORT_GPIO_1, INT_SW202_POL_MASK, INT_SW202_ENA_MASK);

	/* Enable callbacks for INT_SW203 & GINT1 */
	GINT_EnableCallback(GINT0);
	GINT_EnableCallback(GINT1);

	/********* End init *********/

	while (1)
	{
		__WFI();
	}
}
