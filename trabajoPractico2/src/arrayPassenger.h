/*
 * arrayPassenger.h
 *
 *  Created on: 13 may. 2022
 *      Author: danilovukosich
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#define TAM 2000
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char name[51];
	char lastname[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;

}sPassenger;
/// @brief inicia el array
///
/// @param list
/// @param len
/// @return 0
int InitPassenger(sPassenger list[], int len);
/// @brief busca espacio libre en el array
///
/// @param list
/// @param len
/// @return index
int BuscarEspacioLibre(sPassenger list[], int len);
/// @brief añade un pasajero
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param typePassenger
/// @param flyCode
/// @param statusFlight
/// @return responce
int AddPassenger(sPassenger list[],int len,int id,char name[],char lastName[],float price,int typePassenger,char flyCode[], int statusFlight);
/// @brief funcion par abuscar un pasajero
///
/// @param list
/// @param len
/// @param id
/// @return responce
int FindPassengerById(sPassenger list[],int len, int id);
/// @brief funcion que elimina un pasajero.
///
/// @param list
/// @param len
/// @return retorno
int RemovePassenger(sPassenger list[], int len);
/// @brief
///
/// @param list
/// @param len
void SortPassengers(sPassenger list[], int len);
/// @brief funcion para mostrar un pasajero
///
/// @param passenger
void ShowPassenger(sPassenger passenger);
/// @brief funcion para mostrar una lista de pasajeros
///
/// @param list
/// @param len
void ShowPassengersList(sPassenger list[], int len);
/// @brief funcion que realiza una carga forzada de datos
///
/// @param list
void CargaForzada(sPassenger list[]);
/// @brief funcion que modifica a un pasajero
///
/// @param list
/// @param len
/// @return retorno
int ModificarPassenger(sPassenger list[], int len);
/// @brief funcion que calcuala los promedios.
///
/// @param list
/// @param len
void Promedios(sPassenger list[], int len);
/// @brief funcion que ordena los pasajeros por codigo.
///
/// @param list
/// @param len
void SortPassengersByFlyCode(sPassenger list[], int len);
#endif /* ARRAYPASSENGER_H_ */
