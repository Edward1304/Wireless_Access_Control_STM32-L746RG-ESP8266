/*
 * keypad.c
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */
#include "../../LIB_CLASES/Include/keypad.h"



void Keypad_Init(void){
	R0_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(R0_GPIO_PORT, R0_PIN, LL_GPIO_MODE_INPUT);
		LL_GPIO_SetPinPull(R0_GPIO_PORT, R0_PIN, LL_GPIO_PULL_UP);

		R1_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(R1_GPIO_PORT, R1_PIN, LL_GPIO_MODE_INPUT);
		LL_GPIO_SetPinPull(R1_GPIO_PORT, R1_PIN, LL_GPIO_PULL_UP);

		R2_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(R2_GPIO_PORT, R2_PIN, LL_GPIO_MODE_INPUT);
		LL_GPIO_SetPinPull(R2_GPIO_PORT, R2_PIN, LL_GPIO_PULL_UP);

		R3_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(R3_GPIO_PORT, R3_PIN, LL_GPIO_MODE_INPUT);
		LL_GPIO_SetPinPull(R3_GPIO_PORT, R3_PIN, LL_GPIO_PULL_UP);

		C0_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(C0_GPIO_PORT, C0_PIN, LL_GPIO_MODE_OUTPUT);

		C1_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(C1_GPIO_PORT, C1_PIN, LL_GPIO_MODE_OUTPUT);

		C2_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(C2_GPIO_PORT, C2_PIN, LL_GPIO_MODE_OUTPUT);

		C3_GPIO_CLK_ENABLE();
		LL_GPIO_SetPinMode(C3_GPIO_PORT, C3_PIN, LL_GPIO_MODE_OUTPUT);


}

uint8_t Keypad_Scan(void){

	LL_GPIO_ResetOutputPin(C0_GPIO_PORT, C0_PIN);
	LL_GPIO_SetOutputPin(C1_GPIO_PORT, C1_PIN);
	LL_GPIO_SetOutputPin(C2_GPIO_PORT, C2_PIN);
	LL_GPIO_SetOutputPin(C3_GPIO_PORT, C3_PIN);

		//LL_GPIO_IsInputPinSet(GPIOx, PinMask)
	if ((LL_GPIO_ReadInputPort(R0_GPIO_PORT) & R0_PIN) == 0 )
		return '1';

	if ((LL_GPIO_ReadInputPort(R1_GPIO_PORT) & R1_PIN) == 0 )
		return '4';

	if ((LL_GPIO_ReadInputPort(R2_GPIO_PORT) & R2_PIN) == 0 )
		return '7';

	if ((LL_GPIO_ReadInputPort(R3_GPIO_PORT) & R3_PIN) == 0 )
		return '*';


	LL_GPIO_SetOutputPin(C0_GPIO_PORT, C0_PIN);
	LL_GPIO_ResetOutputPin(C1_GPIO_PORT, C1_PIN);
	LL_GPIO_SetOutputPin(C2_GPIO_PORT, C2_PIN);
	LL_GPIO_SetOutputPin(C3_GPIO_PORT, C3_PIN);

	if ((LL_GPIO_ReadInputPort(R0_GPIO_PORT) & R0_PIN) == 0 )
		return '2';

	if ((LL_GPIO_ReadInputPort(R1_GPIO_PORT) & R1_PIN) == 0 )
		return '5';

	if ((LL_GPIO_ReadInputPort(R2_GPIO_PORT) & R2_PIN) == 0 )
		return '8';

	if ((LL_GPIO_ReadInputPort(R3_GPIO_PORT) & R3_PIN) == 0 )
		return '0';



	LL_GPIO_SetOutputPin(C0_GPIO_PORT, C0_PIN);
	LL_GPIO_SetOutputPin(C1_GPIO_PORT, C1_PIN);
	LL_GPIO_ResetOutputPin(C2_GPIO_PORT, C2_PIN);
	LL_GPIO_SetOutputPin(C3_GPIO_PORT, C3_PIN);

	if ((LL_GPIO_ReadInputPort(R0_GPIO_PORT) & R0_PIN) == 0 )
		return '3';

	if ((LL_GPIO_ReadInputPort(R1_GPIO_PORT) & R1_PIN) == 0 )
		return '6';

	if ((LL_GPIO_ReadInputPort(R2_GPIO_PORT) & R2_PIN) == 0 )
		return '9';

	if ((LL_GPIO_ReadInputPort(R3_GPIO_PORT) & R3_PIN) == 0 )
		return '#';

	LL_GPIO_SetOutputPin(C0_GPIO_PORT, C0_PIN);
	LL_GPIO_SetOutputPin(C1_GPIO_PORT, C1_PIN);
	LL_GPIO_SetOutputPin(C2_GPIO_PORT, C2_PIN);
	LL_GPIO_ResetOutputPin(C3_GPIO_PORT, C3_PIN);

	if ((LL_GPIO_ReadInputPort(R0_GPIO_PORT) & R0_PIN) == 0 )
		return 'A';

	if ((LL_GPIO_ReadInputPort(R1_GPIO_PORT) & R1_PIN) == 0 )
		return 'B';

	if ((LL_GPIO_ReadInputPort(R2_GPIO_PORT) & R2_PIN) == 0 )
		return 'C';

	if ((LL_GPIO_ReadInputPort(R3_GPIO_PORT) & R3_PIN) == 0 )
		return 'D';


	return 0;
}
