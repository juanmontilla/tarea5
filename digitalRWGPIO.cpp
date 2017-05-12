//Configuración de los puertos de entrada y salida de  tarjetas Beagleboard y Raspberry Pi
//  Presentado por: Deimer Andres Morales Herrera
//                  Juan Camilo Montilla Orjuela
//  Creado para Sistemas Basados en Microcontroladores 
//  Armenia, Quindio 12 de Mayo de 2017
//  #FreeSoftware.

#include "digitalwrgpio.h"
ClaseGPIO pinesGPIO;

int main()
{
	cout << "CONFIGURACION PINES GPIO" << endl;
	string tipo;

	pinesGPIO.preguntapin();
	pinesGPIO.direccion();
	pinesGPIO.crear_export();

	cout << "El pin es de tipo in o out : " <<endl;
	cin >> tipo;
	if(tipo=="in")
		{
			pinesGPIO.setpinin();
			pinesGPIO.leerpin();
		}
	else if(tipo=="out")
		{
			pinesGPIO.setpinout();
			pinesGPIO.escribirpinH();
			pinesGPIO.escribirpinL();
		}
	else
		{
			cout << "No escribio de forma correcta" << endl;
		}
	pinesGPIO.borrar_export();
	cout << "PROCESO TERMINADO" << endl;
}
