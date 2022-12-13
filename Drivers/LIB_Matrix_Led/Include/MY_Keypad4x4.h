/*
Library:						4x4 Keypad drive for STM32 MCUs
Written by:					Mohamed Yaqoob
Date written:				03/04/2018
Description:				The MY_Keypad4x4 library consists of the following public functions
										Function(1)- Keypad4x4_Init
										Function(2)- Keypad4x4_ReadKeypad
										Function(3)- Keypad4x4_GetChar
*/

//Header files
#include "stm32l4xx_hal.h"
#include <stdbool.h>

//***** Constant variables and typedefs *****//

uint8_t fix;
char* fixedC;

typedef enum KeyNum
{
	KEY1 = 0,
	KEY2 = 1,
	KEY3 = 2,
	KEYA = 3,
	KEY4 = 4,
	KEY5 = 5,
	KEY6 = 6,
	KEYB = 7,
	KEY7 = 8,
	KEY8 = 9,
	KEY9 = 10,
	KEYC = 11,
	KEY_STAR = 12,
	KEY0 = 13,
	KEY_POUND = 14,
	KEYD = 15,

}KEYNUM;





typedef struct
{
	GPIO_TypeDef* IN0_Port;
	GPIO_TypeDef* IN1_Port;
	GPIO_TypeDef* IN2_Port;
	GPIO_TypeDef* IN3_Port;
	GPIO_TypeDef* OUT0_Port;
	GPIO_TypeDef* OUT1_Port;
	GPIO_TypeDef* OUT2_Port;
	GPIO_TypeDef* OUT3_Port;

	uint16_t	IN0pin;
	uint16_t	IN1pin;
	uint16_t	IN2pin;
	uint16_t	IN3pin;
	uint16_t	OUT0pin;
	uint16_t	OUT1pin;
	uint16_t	OUT2pin;
	uint16_t	OUT3pin;
}Keypad_WiresTypeDef;

//List of keys as chars


//***** Functions prototype *****//
//Function(1): Set Keypad pins and ports
void Keypad4x4_Init(Keypad_WiresTypeDef  *KeypadWiringStruct);

//Function(4): Read active keypad button
void Keypad4x4_ReadKeypad(bool keys[16]);
//Function(5): Get character
char* Keypad4x4_GetChar(KEYNUM key);

/*Funcion para corregir el comportamiento de la matriz
 * siendo este predecible.
 */
char* FIXED_GetChar(bool keys[16]);



