/// @brief Funcion de para pedir un numero
///
/// @param mensaje
/// @return numero
float PedirNumero (char mensaje[]);

/// @brief Funcion para calcular el precio con tarjeta de debito en aerolineas.
///
/// @param y
/// @return resultadoDebito
float CalcularDebitoAerolineas(float y);

/// @brief Funcion para calcular el precio con tarjeta de credito en aerolineas.
///
/// @param y
/// @return resultadoDebito
float CalcularCreditoAerolineas(float y);

/// @brief Funcion para calcular el precion de aerolineas en bitcoin.
///
/// @param y
/// @return resultadoBitcoin
float CalcularBitcoinAerolineas(float y);

/// @brief Funcion para calcular el precio unitario de aerolineas.
///
/// @param y
/// @param x
/// @return precioUnitario
float CalcularUnitarioAerolineas(float y, float x);

/// @brief Funcion para calcular el precio con tarjeta de debito en latam.
///
/// @param y
/// @return resultadoDebito
float CalcularDebitoLatam(float z);

/// @brief Funcion para calcular el precio con tarjeta de credito en latam.
///
/// @param y
/// @return resultadoDebito
float CalcularCreditoLatam(float z);

/// @brief Funcion para calcular el precion de aerolineas en latam.
///
/// @param y
/// @return resultadoBitcoin
float CalcularBitcoinLatam(float z);

/// @brief Funcion para calcular el precio unitario de Latam.
///
/// @param z
/// @param x
/// @return precioUnitario
float CalcularUnitarioLatam(float z, float x);

/// @brief Funcion para calcular la diferencia de precio entre e
///
/// @param y
/// @param z
/// @return diferencia
float CalcularDiferencia(float y, float z);

/// @brief Funcion para la carga forzada de datos para ahorrar lineas de codigo en el main.(aca tambien se utiliza la rucursividad al tener funciones adento de funciones)
///
void CargaForzadaDeDatos(void);

/// @brief Funcion para limpiar la consola y que no se junte el menu.
///
void LimpiarLaConsola (void);









