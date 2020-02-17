/**
* \file    		template.c
* \author  		Kovalchuk Alexander (roux@yandex.ru)
* \brief   		This file contains the prototypes functions which use for...
*/

/*
 * Copyright (c) year Alexander KOVALCHUK
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
 * AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * This file is part of library_name.
 *
 * Author:          Alexander KOVALCHUK <roux@yandex.ru>
 */
//_____ I N C L U D E S _______________________________________________________
#include "delay.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//#include "plib.h"
//_____ C O N F I G S  ________________________________________________________
//_____ D E F I N I T I O N ___________________________________________________
//_____ M A C R O S ___________________________________________________________
//_____ V A R I A B L E   D E F I N I T I O N  ________________________________
//_____ I N L I N E   F U N C T I O N   D E F I N I T I O N   _________________
//_____ S T A T I C  F U N C T I O N   D E F I N I T I O N   __________________
//_____ F U N C T I O N   D E F I N I T I O N   _______________________________
/**
* This function used to create us time delay.
*
* Public function defined in delay.h
*/
void delay_us(uint32_t us)
{
	uint32_t targetCount;
	uint32_t bakupCount;

	// Assert "us" not zero. This must be caught during debug phase.
	assert(us != 0);
	// backup current count of the core timer.
	bakupCount = ReadCoreTimer();
	// Core timer increments every 2 sys clock cycles.
	// Calculate the counts required to complete "us".
	targetCount = COUNT_PER_USEC * us;
	// Restart core timer.
	WriteCoreTimer(0);
	// Wait till core timer completes the count.
	while(ReadCoreTimer() < targetCount) {};
	// Restore count back.
	WriteCoreTimer(bakupCount + targetCount);
}

/**
* This function used to create ms time delay.
*
* Public function defined in delay.h
*/
void delay_ms(uint32_t ms)
{
	uint32_t targetCount;
	uint32_t bakupCount;

	// Assert "us" not zero. This must be caught during debug phase.
	assert(ms != 0);
	// backup current count of the core timer.
	bakupCount = ReadCoreTimer();
	// Core timer increments every 2 sys clock cycles.
	// Calculate the counts required to complete "us".
	targetCount = COUNT_PER_USEC * ms * 1000 {};
	// Restart core timer.
	WriteCoreTimer(0);
	// Wait till core timer completes the count.
	while(ReadCoreTimer() < targetCount);
	// Restore count back.
	WriteCoreTimer(bakupCount + targetCount);
}
