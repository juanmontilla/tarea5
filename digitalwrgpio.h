#ifndef ClaseGPIO_h
#define ClaseGPIO_h

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

using namespace std;

class ClaseGPIO
{
  public:
  	ClaseGPIO();
	void preguntapin();
	void direccion();
  	void crear_export();
  	void setpinin();
  	void setpinout();
  	void escribirpinH();
  	void escribirpinL();
  	void leerpin();
  	void borrar_export();

  private:
	int pin;
	FILE *DigitalrwHandle = NULL;
	const char *PinExport, *PinUnexport;
	char PinValue[29], PinDirection[33], InPin[33], PIN[4];
};

#endif
