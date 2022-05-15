/*
 * funciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: danilovukosich
 */

#ifndef FUNCIONES_C_
#define FUNCIONES_C_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

#define TAM 2000
#define LIBRE 0
#define OCUPADO 1


void GetString(char mensaje[], char string[])
{
	printf("%s",mensaje);
	fpurge(stdin);
	gets(string);
}

float PedirNumero (char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}


#endif /* FUNCIONES_C_ */
