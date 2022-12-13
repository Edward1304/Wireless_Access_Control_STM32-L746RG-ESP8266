/*
 * Funciones.h
 *
Created on: 14-06-2022
 *      Author: MIGUELON
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include "main.h"


double data1; 	//para guardar el valor del primer potenciometro.
double data2;	//para guardar el valor del segundo potenciometro.
double data3;	//para guardar el valor del tercer potenciometro.
double tshif;   //para el uso del shifteo en la pantalla led

int restar;     //para atenuar el led de la funcion 2
int pan;        //para saber en cual panel escribir
int M9;         //para el cambio de direccion funcion 9
char S9;		//para el cambio de direccion funcion 9
int sps;		//para modificar la rapideZ de shifteo de la funcion 7

			//invocacion a las funciones
void Funcionalidades(int caso, bool detect);
void Exit_F();
void Enter_F(int CASO);
void ccr_cambio();


#endif /* FUNCIONES_H_ */
