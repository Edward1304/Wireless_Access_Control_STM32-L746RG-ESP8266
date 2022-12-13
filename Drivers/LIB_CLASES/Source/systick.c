/*
 * systick.c
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */

#include "../../LIB_CLASES/Include/systick.h"

static uint32_t msTick = 0;

void SysTick_Handler(void){
	SysTick_Callback();
}

void SysTick_Callback(void){
	msTick++;
}

uint32_t Get_Tick(void){
	return msTick;
}
