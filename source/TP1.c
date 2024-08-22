/*
 * Copyright 2016-2024 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/**
 * @file    TP1.c
 * @brief   Application entry point.
 */
#include "L1/Application.h"
#include "L1/TIME.h"
/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */

int main(void) {

	CONFIG();

	INIT();

	while(1) {
			APP();
    }
    return 0 ;
}



