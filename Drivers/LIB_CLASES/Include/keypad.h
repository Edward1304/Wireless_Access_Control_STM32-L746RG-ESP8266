/*
 * keypad.h
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */

#ifndef INCLUDE_KEYPAD_H_
#define INCLUDE_KEYPAD_H_

#include "main.h"
//Configuración pines del teclado
#define R0_PIN                           LL_GPIO_PIN_12
#define R0_GPIO_PORT                     GPIOA
#define R0_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define R1_PIN                           LL_GPIO_PIN_11
#define R1_GPIO_PORT                     GPIOA
#define R1_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define R2_PIN                           LL_GPIO_PIN_12
#define R2_GPIO_PORT                     GPIOB
#define R2_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define R3_PIN                           LL_GPIO_PIN_11
#define R3_GPIO_PORT                     GPIOB
#define R3_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define C0_PIN                           LL_GPIO_PIN_2
#define C0_GPIO_PORT                     GPIOB
#define C0_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define C1_PIN                           LL_GPIO_PIN_1
#define C1_GPIO_PORT                     GPIOB
#define C1_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define C2_PIN                           LL_GPIO_PIN_15
#define C2_GPIO_PORT                     GPIOB
#define C2_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define C3_PIN                           LL_GPIO_PIN_14
#define C3_GPIO_PORT                     GPIOB
#define C3_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)


//Keypad Scan
void Keypad_Init(void);
uint8_t Keypad_Scan(void);

#endif /* INCLUDE_KEYPAD_H_ */
