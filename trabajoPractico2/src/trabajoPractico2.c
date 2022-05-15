/*
 ============================================================================
 Name        : tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "funciones.h"
#include "arrayPassenger.h"
#define TAM 2000
#define LIBRE 0
#define OCUPADO 1

int main(void) {
	setbuf(stdout, NULL);

	sPassenger passengerList[TAM];
	int opcion=0;
	int initPassenger;
	int id=0;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlyght;
	int aux;
	int index;

	initPassenger = InitPassenger(passengerList, TAM);


	do
	{
		printf("\n1)ATLAS\n"
				"2)MODIFICAR\n"
				"3)BAJA\n"
				"4)INFORMAR\n"
				"5)CARGA FORZADA\n"
				"6)SALIR\n"
				">Ingrese una opcion: ");
		scanf("%d",&opcion);

		switch(opcion)
		{
		case 1:
			index=BuscarEspacioLibre(passengerList, TAM);
			if(index!=-1)
			{
				id=PedirNumero ("ingrese el id: ");
				GetString("ingrese su nombre: ", name);
				GetString("ingrese su apellido: ", lastName);
				price=PedirNumero ("ingrese el precio: ");
				typePassenger=PedirNumero ("ingrese el tipo de pasajero: ");
				GetString("ingrese su codigo de vuelo: ", flyCode);
				statusFlyght=PedirNumero ("ingrese el estado: ");

				aux= AddPassenger(passengerList, TAM, id, name, lastName, price,typePassenger, flyCode, statusFlyght);
				if(aux == 1)
				{
					printf("USUARIO AGREGADO CORRECTAMENTE");
				}
				else
				{
					printf("ERROR");
				}
			}

		break;

		case 2:
			aux = ModificarPassenger(passengerList, TAM);
			if(aux == 1)
			{
				printf("\nUSUARIO MODIFICADO CORRECTAMENTE\n");
			}
			else
			{
				printf("ERROR\n");
			}

		break;

		case 3:
			aux = RemovePassenger(passengerList, TAM);
			if(aux == 1)
			{
				printf("\nUSUARIO ELIMINADO CORRECTAMENTE\n");
			}
			else
			{
				printf("ERROR\n");
			}

		break;

		case 4:

			do
			{
				printf("\n1)Lisnta de pasajeros por apellido.\n"
						"2)Lista de promedios.\n"
						"3)Lista de pasajeros por codigo de vuelo.\n"
						"4)SALIR\n"
						">Ingrese una opcion: ");
				scanf("%d",&opcion);
				switch(opcion)
				{
				case 1:
					SortPassengers(passengerList, TAM);
					ShowPassengersList(passengerList, TAM);
					break;
				case 2:
					Promedios(passengerList, TAM);
					break;
				case 3:
					SortPassengersByFlyCode(passengerList, TAM);
					ShowPassengersList(passengerList, TAM);
					break;


				}

			}while(opcion!=4);


		break;
		case 5:
			CargaForzada(passengerList);
		break;


		}
	}while(opcion!=6);







	return EXIT_SUCCESS;
}
