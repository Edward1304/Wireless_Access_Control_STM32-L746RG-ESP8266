/*
 * mf_shield.c
 *
 *  Created on: Nov 2, 2022
 *      Author: gosor
 */
#include "../../LIB_CLASES/Include/mf_shield.h"

const uint8_t seven_seg_digits_decode_abcdefg[75]= {
		/*  0     1     2     3     4     5     6     7     8     9     :     ;     */
		0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B, 0x40, 0x20,
		/*  <     =     >     ?     @     A     B     C     D     E     F     G     */
		0x10, 0x40, 0x04, 0x02, 0x00, 0x77, 0x1F, 0x4E, 0x3D, 0x4F, 0x47, 0x5E,
		/*  H     I     J     K     L     M     N     O     P     Q     R     S     */
		0x37, 0x06, 0x3C, 0x57, 0x0E, 0x55, 0x15, 0x7E, 0x67, 0x73, 0x05, 0x5B,
		/*  T     U     V     W     X     Y     Z     [     \     ]     ^     _     */
		0x0F, 0x3E, 0x1C, 0x5C, 0x13, 0x3B, 0x6D, 0x02, 0x04, 0x08, 0x10, 0x08,
		/*  `     a     b     c     d     e     f     g     h     i     j     k     */
		0x40, 0x77, 0x1F, 0x4E, 0x3D, 0x4F, 0x47, 0x5E, 0x37, 0x06, 0x3C, 0x57,
		/*  l     m     n     o     p     q     r     s     t     u     v     w     */
		0x0E, 0x55, 0x15, 0x1D, 0x67, 0x73, 0x05, 0x5B, 0x0F, 0x3E, 0x1C, 0x5C,
		/*  x     y     z     */
		0x13, 0x3B, 0x6D
};

void FSM_D4_Blink(void){
	static uint32_t last_tick = 0;
	uint32_t current_tick;
	static uint8_t estado = 0;

	current_tick = Get_Tick();
	if (current_tick-last_tick >= 500){
		last_tick = current_tick;

		switch(estado){
		case 0:
			estado = 1;
			LL_GPIO_SetOutputPin(D4_GPIO_PORT, D4_PIN);
			//Test_Display_On();
			break;
		case 1:
			estado = 0;
			LL_GPIO_ResetOutputPin(D4_GPIO_PORT, D4_PIN);
			//Test_Display_Off();
			break;
		}
	}
}


void Sx_Init(void){
	S1_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(S1_GPIO_PORT, S1_PIN, LL_GPIO_MODE_INPUT);
	S2_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(S2_GPIO_PORT, S2_PIN, LL_GPIO_MODE_INPUT);
	S3_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(S3_GPIO_PORT, S3_PIN, LL_GPIO_MODE_INPUT);
}



uint32_t S1_Scan(void){
	return !LL_GPIO_IsInputPinSet(S1_GPIO_PORT, S1_PIN);
}
uint32_t S2_Scan(void){
	return !LL_GPIO_IsInputPinSet(S2_GPIO_PORT, S2_PIN);
}
uint32_t S3_Scan(void){
	return !LL_GPIO_IsInputPinSet(S3_GPIO_PORT, S3_PIN);
}

void Dx_Init(void){
	D1_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(D1_GPIO_PORT, D1_PIN, LL_GPIO_MODE_OUTPUT);
	D2_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(D2_GPIO_PORT, D2_PIN, LL_GPIO_MODE_OUTPUT);
	D3_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(D3_GPIO_PORT, D3_PIN, LL_GPIO_MODE_OUTPUT);
	D4_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(D4_GPIO_PORT, D4_PIN, LL_GPIO_MODE_OUTPUT);
}

void D1_On(void){
	LL_GPIO_ResetOutputPin(D1_GPIO_PORT, D1_PIN);
}
void D2_On(void){
	LL_GPIO_ResetOutputPin(D2_GPIO_PORT, D2_PIN);
}
void D3_On(void){
	LL_GPIO_ResetOutputPin(D3_GPIO_PORT, D3_PIN);
}
void D4_On(void){
	LL_GPIO_ResetOutputPin(D3_GPIO_PORT, D3_PIN);
}

void D1_Off(void){
	LL_GPIO_SetOutputPin(D1_GPIO_PORT, D1_PIN);
}
void D2_Off(void){
	LL_GPIO_SetOutputPin(D2_GPIO_PORT, D2_PIN);
}
void D3_Off(void){
	LL_GPIO_SetOutputPin(D3_GPIO_PORT, D3_PIN);
}
void D4_Off(void){
	LL_GPIO_SetOutputPin(D4_GPIO_PORT, D4_PIN);
}
void D1_Toggle(void){
	LL_GPIO_TogglePin(D1_GPIO_PORT, D1_PIN);
}
void D2_Toggle(void){
	LL_GPIO_TogglePin(D2_GPIO_PORT, D2_PIN);
}
void D3_Toggle(void){
	LL_GPIO_TogglePin(D3_GPIO_PORT, D3_PIN);
}
void D4_Toggle(void){
	LL_GPIO_TogglePin(D4_GPIO_PORT, D4_PIN);
}




void Display_Init(void){
	LCLK_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(LCLK_GPIO_PORT, LCLK_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_ResetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

	SRCLK_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(SRCLK_GPIO_PORT, SRCLK_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_ResetOutputPin(SRCLK_GPIO_PORT, SRCLK_PIN);

	SER_GPIO_CLK_ENABLE();
	LL_GPIO_SetPinMode(SER_GPIO_PORT, SER_PIN, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_ResetOutputPin(SER_GPIO_PORT, SER_PIN);
}


void Test_Display_On(void){

	LL_GPIO_ResetOutputPin(SRCLK_GPIO_PORT, SRCLK_PIN);
	LL_GPIO_ResetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

	LL_GPIO_ResetOutputPin(SER_GPIO_PORT, SER_PIN);

	for (uint8_t i=0;i<8;i++){
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	}

	LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);

	for (uint8_t i=0;i<8;i++){
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	}

	LL_GPIO_SetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

}

void Test_Display_Off(void){

	LL_GPIO_ResetOutputPin(SRCLK_GPIO_PORT, SRCLK_PIN);
	LL_GPIO_ResetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

	LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);

	for (uint8_t i=0;i<8;i++){
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	}

	LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);

	for (uint8_t i=0;i<8;i++){
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	}

	LL_GPIO_SetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

}



void FSM_Write_D4( uint8_t *Msg){
	static uint32_t  last_tick = 0;
	static uint32_t state = 0, next_state = 0;

	static uint8_t i = 0;


	if (  Get_Tick() - last_tick >= 1){
		if (state == 0){
			Write_ASCII_D4((Msg[i]- 0x30), 4, seven_seg_digits_decode_abcdefg);
			next_state = state+1;
		}
		if (state == 1){
			Write_ASCII_D4((Msg[i+1]- 0x30), 3, seven_seg_digits_decode_abcdefg);
			next_state = state+1;
		}
		if (state == 2){
			Write_ASCII_D4(Msg[i+2]- 0x30, 2, seven_seg_digits_decode_abcdefg);
			next_state = state+1;
		}
		if (state == 3){
			Write_ASCII_D4(Msg[i+3]- 0x30, 1, seven_seg_digits_decode_abcdefg);
			next_state = 0;
		}
		state = next_state;
		last_tick = Get_Tick();
	}
}

void Write_ASCII_D4( uint8_t letter, uint8_t Digit,const uint8_t *Data ){

	//  LCLK (PB5) -
	LL_GPIO_ResetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

	// SRCLK (PA8) - 16 clock cycles
	LL_GPIO_ResetOutputPin(SRCLK_GPIO_PORT, SRCLK_PIN);
	// Dot is set to turn it off
	LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);
	LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	for (int i = 0; i < 7; i++){
		// SER (PA9) - set
		//HAL_GPIO_WritePin(SER_GPIO_PORT, SER_PIN,~(Data[letter]>>i)&(1));
		if ((~(Data[letter]>>i)&(1))==1){
			LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);
		}
		else{
			LL_GPIO_ResetOutputPin(SER_GPIO_PORT, SER_PIN);
		}
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	}

	// All the displays are enable
	LL_GPIO_ResetOutputPin(SER_GPIO_PORT, SER_PIN);
	for (int i = 0; i < 8; i++){
		if (i == Digit+3){
			LL_GPIO_SetOutputPin(SER_GPIO_PORT, SER_PIN);
		}else{
			LL_GPIO_ResetOutputPin(SER_GPIO_PORT, SER_PIN);
		}
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
		LL_GPIO_TogglePin(SRCLK_GPIO_PORT, SRCLK_PIN);
	};
	//  LCLK (PB5) -
	LL_GPIO_SetOutputPin(LCLK_GPIO_PORT, LCLK_PIN);

}

