/*
 * main.h
 *
 *  Created on: Dec 2, 2022
 *      Author: Edward Fabian
 */

#ifndef INCLUDE_MAIN_H_
#define INCLUDE_MAIN_H_

#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_gpio.h"


#include "keypad.h"
#include "syslimits.h"
#include "liquidcrystal_i2c.h"
#include "Funciones.h"
#include "max_matrix_stm32.h"
#include "MY_Keypad4x4.h"


extern void App_Init(void);
extern void Inputs_Update(void);
extern void Outputs_Update(void);
void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void lcd_send_string (char *str);  // send string to the lcd

void lcd_clear (void);





#endif /* INCLUDE_MAIN_H_ */
