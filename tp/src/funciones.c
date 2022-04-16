#include <stdio.h>
#include <stdlib.h>

#include "funciones.h"

#define BITCOIN 4606954.55


//pedir numero
float PedirNumero (char mensaje[])
{
	float numero;

	printf("%s", mensaje);
	scanf("%f", &numero);

	return numero;
}
//---------------------------------------------------//
//calcular precio con debito para aerolineas.
float CalcularDebitoAerolineas(float y)
{
	float descuento=0.9;
	float resultadoDebito;

	resultadoDebito= y * descuento;

	return resultadoDebito;
}
//calcular precio con credito para aerolineas.
float CalcularCreditoAerolineas(float y)
{
	float aumento=1.10;
	float resultadoCredito;

	resultadoCredito= y * aumento;

	return resultadoCredito;
}
//calcular precio en bitcoin para aerloineas.
float CalcularBitcoinAerolineas(float y)
{
	float resultadoBitcoin;

	resultadoBitcoin =  y / BITCOIN;

	return resultadoBitcoin;
}
//calcular precio unitario de aerolineas.
float CalcularUnitarioAerolineas(float y, float x)
{
	float precioUnitario;
	precioUnitario=y/x;

	return precioUnitario;
}
//--------------------------------------------//
//clacular precio con debito para latam.
float CalcularDebitoLatam(float z)
{
	float descuento=0.9;
	float resultadoDebito;

	resultadoDebito= z * descuento;

	return resultadoDebito;
}
//calcular precio con credito para latam.
float CalcularCreditoLatam(float z)
{
	float aumento=1.10;
	float resultadoCredito;

	resultadoCredito= z * aumento;

	return resultadoCredito;
}
//calcular precio en bitcoin para latam.
float CalcularBitcoinLatam(float z)
{
	float resultadoBitcoin;

	resultadoBitcoin =  z / BITCOIN;

	return resultadoBitcoin;
}
//calcular precio unitario de latam.
float CalcularUnitarioLatam(float z, float x)
{
	float precioUnitario;
	precioUnitario=z/x;

	return precioUnitario;
}

//---------------------------------//
//calcular diferencia entre aerolineas(y) y latam(z).
float CalcularDiferencia(float y, float z)
{
	float diferencia;

	diferencia=y-z;

	return diferencia;
}

//---------------------------------//

void CargaForzadaDeDatos(void)
{
	float x=7090;//Km
	float y=162965;//Aerolineas
	float z=159339;//Latam
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

	precioDebitoAerolineas=CalcularDebitoAerolineas(y);
	precioCreditoAerolineas=CalcularCreditoAerolineas(y);
	precioBitcoinAerolineas=CalcularBitcoinAerolineas(y);
	precioUnitarioAerolineas=CalcularUnitarioAerolineas(z,x);

	precioDebitoLatam=CalcularDebitoLatam(z);
	precioCreditoLatam=CalcularCreditoLatam(z);
	precioBitcoinLatam=CalcularBitcoinLatam(z);
	precioUnitarioLatam=CalcularUnitarioLatam(z,x);
	diferenciaDePrecio=CalcularDiferencia(y,z);

	printf("KMs Ingresados: %.2f",x);

	printf("\nPRECIO AEROLINEAS: $%.2f", y);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoAerolineas);
	printf("\nb) Precio con tarjeta de crédito:$%.2f", precioCreditoAerolineas);
	printf("\nc) Precio pagando con bitcoin: %.2f BTC", precioBitcoinAerolineas);
	printf("\nd) Precio unitario: $%.2f por Km\n", precioUnitarioAerolineas);

	printf("\nLATAM: LATAM: $%.2f", z);
	printf("\na) Precio con tarjeta de débito: $%.2f", precioDebitoLatam);
	printf("\nb) Precio con tarjeta de crédito: $%.2f", precioCreditoLatam);
	printf("\nc) Precio pagando con bitcoin : %.2f BTC", precioBitcoinLatam);
	printf("\nd) Precio unitario: $%.2f por Km", precioUnitarioLatam);

	printf("\n\nLa diferencia de precio entre Aerolineas y Latam es de: $%.2f \n\n", diferenciaDePrecio);
}


void LimpiarLaConsola (void)
{
	printf("\n\n\n\n\n");
}





