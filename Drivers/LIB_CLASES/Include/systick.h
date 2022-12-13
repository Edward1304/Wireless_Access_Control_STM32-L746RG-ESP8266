/*
 * systick.h
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */
#ifndef INCLUDE_SYSTICK_H_
#define INCLUDE_SYSTICK_H_

#include "main.h"

// SysTick Functions
void SysTick_Callback(void);
uint32_t Get_Tick(void);


#endif /* INCLUDE_SYSTICK_H_ */
