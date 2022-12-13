/*
 * mf_shield.h
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */

#ifndef INCLUDE_MF_SHIELD_H_
#define INCLUDE_MF_SHIELD_H_

#include "main.h"

#define S1_PIN                           LL_GPIO_PIN_1
#define S1_GPIO_PORT                     GPIOA
#define S1_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define S2_PIN                           LL_GPIO_PIN_4
#define S2_GPIO_PORT                     GPIOA
#define S2_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define S3_PIN                           LL_GPIO_PIN_0
#define S3_GPIO_PORT                     GPIOB
#define S3_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define D1_PIN                           LL_GPIO_PIN_5
#define D1_GPIO_PORT                     GPIOA
#define D1_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define D2_PIN                           LL_GPIO_PIN_6
#define D2_GPIO_PORT                     GPIOA
#define D2_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define D3_PIN                           LL_GPIO_PIN_7
#define D3_GPIO_PORT                     GPIOA
#define D3_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define D4_PIN                           LL_GPIO_PIN_6
#define D4_GPIO_PORT                     GPIOB
#define D4_GPIO_CLK_ENABLE()             LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)


#define LCLK_PIN 						LL_GPIO_PIN_5
#define LCLK_GPIO_PORT 					GPIOB
#define LCLK_GPIO_CLK_ENABLE()          LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOB)

#define SRCLK_PIN 						LL_GPIO_PIN_8
#define SRCLK_GPIO_PORT					GPIOA
#define SRCLK_GPIO_CLK_ENABLE()         LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

#define SER_PIN 						LL_GPIO_PIN_9
#define SER_GPIO_PORT					GPIOA
#define SER_GPIO_CLK_ENABLE()           LL_AHB2_GRP1_EnableClock(LL_AHB2_GRP1_PERIPH_GPIOA)

void FSM_D4_Blink(void);

void Sx_Init();
uint32_t S1_Scan(void);
uint32_t S2_Scan(void);
uint32_t S3_Scan(void);

void Dx_Init(void);
void D1_On(void);
void D2_On(void);
void D3_On(void);
void D4_On(void);
void D1_Off(void);
void D2_Off(void);
void D3_Off(void);
void D4_Off(void);
void D1_Toggle(void);
void D2_Toggle(void);
void D3_Toggle(void);
void D4_Toggle(void);


void Display_Init(void);
void Test_Display_Off(void);
void Test_Display_On(void);
void FSM_Write_D4( uint8_t *Msg);
void Write_ASCII_D4( uint8_t letter, uint8_t Digit,const uint8_t *Data );









#endif /* INCLUDE_MF_SHIELD_H_ */
