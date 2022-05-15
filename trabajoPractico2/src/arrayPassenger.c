/*
 * arrayPassenger.c
 *
 *  Created on: 13 may. 2022
 *      Author: danilovukosich
 */

#ifndef ARRAYPASSENGER_C_
#define ARRAYPASSENGER_C_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "arrayPassenger.h"
#include "funciones.h"
#define LIBRE 0
#define OCUPADO 1


int BuscarEspacioLibre(sPassenger list[], int len)
{
	int index=-1;

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == LIBRE)
		{
			index = i;
			break;
		}
	}

	return index;
}

//////////////////////////////////////////////////////////////////

int InitPassenger(sPassenger list[], int len)
{
	for (int i = 0; i<len; i++)
	{
		list[i].isEmpty = LIBRE;
	}
	return 0;

}

//////////////////////////////////////////////////////////////////

int AddPassenger(sPassenger list[], int len, int id, char name[], char lastName[], float price, int typePassenger, char flyCode[], int statusFlight)
{
	sPassenger p;

	p.id = id;
	strcpy(p.name, name);
	strcpy(p.lastname, lastName);
	p.price = price;
	p.typePassenger = typePassenger;
	strcpy(p.flycode, flyCode);
	p.isEmpty = OCUPADO;
	p.statusFlight=statusFlight;


	int flag = 1;
	int pos;
	int i = 0;
	int response = 0;



	while(flag == 1)
	{
		if(list[i].isEmpty == LIBRE)
		{
			pos = i;
			flag = 0;
			response = 1;
		}
		i++;
	}
	list[pos] = p;


	return response;
}

//////////////////////////////////////////////////////////////////

int FindPassengerById(sPassenger list[], int len, int id)
{
	sPassenger p;
	int flag = 1;
	int response = 0;
	int i = 0;

	while(flag == 1 && i<len)
	{
		if(list[i].id == id)
		{
					p = list[i];
					flag = 0;
					response = 1;
				}
				i++;

	}

	printf("\nID: %i", p.id);
	printf("\nNOMBRE Y APELLIDO: %s %s\n", p.name,p.lastname);

	return response;
}


///////////////////////////////////////////////////////////////////

int RemovePassenger(sPassenger list[], int len)
{

	int id;
	int aux;
	int retorno=0;

	id=PedirNumero("ingrese el id del pasajero a modificar: ");
	aux=FindPassengerById(list, len, id);
	if(aux == 1)
	{
		printf("\nUSUARIO ENCONTRADO\n");
	}
	else
	{
		printf("\nERROR\n");
	}

	for(int i = 0; i<len ; i++)
	{
		if(list[i].id == id)
		{
			list[i].isEmpty = LIBRE;
			retorno = 1;
			break;
		}

	}

	return retorno;
}

////////////////////////////////////////////////////////////////////

void SortPassengers(sPassenger list[], int len)
{
	sPassenger aux;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
			if(strcmp(list[i].lastname,list[j].lastname)<0)
			{
				aux = list[i];
				list[i] = list[j];
				list[j] = aux;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////
void ShowPassenger(sPassenger passenger)
{

	printf("\n%4d %10s %10s %4.2f %10s %4d %4d\n",passenger.id, passenger.name, passenger.lastname, passenger.price, passenger.flycode, passenger.typePassenger, passenger.statusFlight);

}
void ShowPassengersList(sPassenger list[], int len)
{
	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			ShowPassenger(list[i]);
		}
	}

}

////////////////////////////////////////////////////////////////////

void CargaForzada(sPassenger list[])
{

	sPassenger aux[TAM]={{1,"pepe","fernandez",55000,"jks8sdf3j3",1,0,OCUPADO},
					     {2,"juan","dominguez",76000,"ykg8sfu7j3",2,1,OCUPADO},
					     {3,"joaqun","mendez",120000,"divn8sl03n",3,1,OCUPADO},
					     {4,"nicolas","boullon",47800,"3jdiv0642p",2,0,OCUPADO},
					     {5,"sanitiago","aurelio",130000,"1jdos5484l",1,1,OCUPADO}};

	for(int i=0;i<5;i++)
	{
		list[i]=aux[i];
	}
}

////////////////////////////////////////////////////////////////////

int ModificarPassenger(sPassenger list[], int len)
{
	int id;
	int aux;
	int retorno=-1;
	if(list!=NULL && len>0)
	{
		id=PedirNumero("ingrese el id del pasajero a modificar: ");
		aux=FindPassengerById(list, len, id);
		if(aux == 1)
		{
			printf("\nUSUARIO ENCONTRADO\n");
		}
		else
		{
			printf("\nERROR\n");
		}
	}

	for(int i=0; i<len; i++)
	{
		if(list[i].isEmpty==OCUPADO && list[i].id==id)
		{
			int opcion=0;
			do
			{
				printf("\n1)Modificar nombre.\n"
						"2)Modificar apellido.\n"
						"3)Modificar precio del vuelo.\n"
						"4)Modificar tipo de pasajero.\n"
						"5)Modificar codigo de vuelo.\n"
						"6)No deseo modificar nada.\n"
						">Ingrese una opcion: ");
				switch(opcion)
				{
				case 1:
					GetString("Ingrese un nuevo nombre: ", list[aux].name);

					break;
				case 2:
					GetString("Ingrese un nuevo apellido: ", list[aux].lastname);

					break;
				case 3:
					list[aux].price=PedirNumero ("ingrese el precio nuevo: ");

					break;
				case 4:
					list[aux].typePassenger=PedirNumero ("ingrese el tipo de pasajero nuevo: ");

					break;
				case 5:
					GetString("Ingrese un nuevo codigo de vuelo: ", list[aux].flycode);

					break;
				case 6:
					printf("Usted salio del menu de modificaciones.");
					break;
				default:
					printf("opcion invalida.");
					break;
				}
			}while(opcion!=6);





			retorno = 1;
			break;
		}
	}


	return retorno;
}

////////////////////////////////////////////////////////////////////

void Promedios(sPassenger list[], int len)
{
	int contador=0;
	int acumulador=0;
	float promedio=0;
	int arribaPromedio=0;

	for(int i=0; i<len;i++)
	{
		if(list[i].isEmpty==OCUPADO)
		{
			contador++;
			acumulador+=list[i].price;

		}

	}

	promedio=acumulador/contador;

	for(int i=0; i<len;i++)
	{
		if(list[i].isEmpty==OCUPADO && list[i].price>promedio)
		{
			arribaPromedio++;

		}

	}
	printf("\nEl total de los pasajes es: %d\n", acumulador);
	printf("El promdeio es: %2.f\n", promedio);
	printf("La cantidad de pasajeros que superan el promedio es de: %d\n",arribaPromedio);

}

////////////////////////////////////////////////////////////////////


void SortPassengersByFlyCode(sPassenger list[], int len)
{
	sPassenger aux;
	for(int i = 0; i < len-1; i++)
	{
		for(int j = i+1; j<len; j++)
		{
			if(list[i].statusFlight==1)
			{
				if(strcmp(list[i].flycode,list[j].flycode)<0)
				{
					aux = list[i];
					list[i] = list[j];
					list[j] = aux;
				}
			}

		}
	}
}

#endif /* ARRAYPASSENGER_C_ */





