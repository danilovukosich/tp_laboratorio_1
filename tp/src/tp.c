/*
 ============================================================================
 Name        : TRABAJO PRACTICO NRO1 labo.
 Author      : Danilo vukosich 1B DNI:43034973
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

int main(void) {
	setbuf(stdout, NULL);

	int respuesta;
	float x=0;//Km
	float y=0;//Aerolineas
	float z=0;//Latam
	float precioDebitoAerolineas=0;
	float precioCreditoAerolineas=0;
	float precioBitcoinAerolineas=0;
	float precioUnitarioAerolineas=0;
	//------------------------------//
	float precioDebitoLatam=0;
	float precioCreditoLatam=0;
	float precioBitcoinLatam=0;
	float precioUnitarioLatam=0;
	//------------------------------//
	float diferenciaDePrecio=0;


	do
	{
		printf("1)Ingresar Kilometro: %.2f", x);
		printf("\n2)Ingresar precio vuelos: \n>Aerolineas: $%.2f\n>Latam: $%.2f",y,z);
		printf("\n3)Calcular costos.");
		printf("\n4)Informar resultados.");
		printf("\n\n5)Carga forzada de datos.");
		printf("\n6)SALIR/EXIT\n\n");

		fpurge(stdin);//en macos

		scanf("%d", &respuesta);


		switch(respuesta)
		{
		case 1:
			x = PedirNumero(">Ingrese la cantidad de Km: ");
			LimpiarLaConsola();
			break;

		case 2:
			y = PedirNumero(">Ingrese el precio de Aerolineas: ");
			z = PedirNumero(">Ingrese el precio de Latam: ");
			LimpiarLaConsola();
			break;

		case 3:
			if(x==0 || z==0 || y==0)//validacion
			{
				LimpiarLaConsola();
				printf("No se han ingresado todos los datos, por favor reingreselos.\n\n\n");
			}
			else
			{
				precioDebitoAerolineas=CalcularDebitoAerolineas(y);
				precioCreditoAerolineas=CalcularCreditoAerolineas(y);
				precioBitcoinAerolineas=CalcularBitcoinAerolineas(y);
				precioUnitarioAerolineas=CalcularUnitarioAerolineas(z,x);

				precioDebitoLatam=CalcularDebitoLatam(z);
				precioCreditoLatam=CalcularCreditoLatam(z);
				precioBitcoinLatam=CalcularBitcoinLatam(z);
				precioUnitarioLatam=CalcularUnitarioLatam(z,x);

				diferenciaDePrecio=CalcularDiferencia(y,z);
				LimpiarLaConsola();
			}

			break;

		case 4:
			if(x==0 || z==0 || y==0)//validacion
			{
				LimpiarLaConsola();
				printf("No se han ingresado todos los datos, por favor reingreselos.\n\n\n");

			}
			else
			{
				printf("KMs Ingresados: %.2f",x);

				printf("\nPRECIO AEROLINEAS: $%.2f", y);
				printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoAerolineas);
				printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoAerolineas);
				printf("\nc) Precio pagando con bitcoin: %.2f BTC", precioBitcoinAerolineas);
				printf("\nd) Precio unitario: $%.2f por Km \n", precioUnitarioAerolineas);

				printf("\nPRECIO LATAM: $%.2f", z);
				printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoLatam);
				printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoLatam);
				printf("\nc) Precio pagando con bitcoin : %.2f BTC", precioBitcoinLatam);
				printf("\nd) Precio unitario: $%.2f por Km", precioUnitarioLatam);

				printf("\n\nLa diferencia de precio entre Aerolineas y Latam es de: $%.2f", diferenciaDePrecio);

			}
			break;

		case 5:
			LimpiarLaConsola();
			CargaForzadaDeDatos();
			break;
		case 6:
			LimpiarLaConsola();
			printf("Usted salio del programa...");
			break;

		default:
			LimpiarLaConsola();
			printf("Ingrese una opcion VALIDA sea: 1,2,3,4,5 o 6\n");//validacion
		}



	}while(respuesta!=6);

	return EXIT_SUCCESS;
}






