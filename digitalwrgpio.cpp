#include "digitalwrgpio.h"
ClaseGPIO::ClaseGPIO()
{
	PinExport = "/sys/class/gpio/export";
	PinUnexport = "/sys/class/gpio/unexport";
}

void ClaseGPIO::preguntapin()
{
	cout << "Por favor ingrese el pin : " <<endl;
  	cin >> pin;
}

void ClaseGPIO::direccion()
{
	sprintf(PinValue, "/sys/class/gpio/gpio%d/value", pin);
	sprintf(PinDirection, "/sys/class/gpio/gpio%d/direction", pin);
	sprintf(PIN, "%d", pin);
	sprintf(InPin, "%s","cat ");
}

void ClaseGPIO::crear_export()
{
	if ((DigitalrwHandle = fopen(PinExport, "r+")) != NULL)
	{
		fwrite(&PIN,sizeof(char),sizeof(PIN),DigitalrwHandle);
		fclose(DigitalrwHandle);
	}
}

void ClaseGPIO::setpinin()
{
	if ((DigitalrwHandle = fopen(PinDirection, "r+")) != NULL)
	{
		fwrite("in",sizeof(char),2,DigitalrwHandle);
		fclose(DigitalrwHandle);
	}
}

void ClaseGPIO::setpinout()
{
	if ((DigitalrwHandle = fopen(PinDirection, "r+")) != NULL)
	{
		fwrite("out",sizeof(char),3,DigitalrwHandle);
		fclose(DigitalrwHandle);
	}

}

void ClaseGPIO::escribirpinH()
{
	if((DigitalrwHandle = fopen(PinValue, "r+")) != NULL)
	{
		fwrite("1",sizeof(char),1,DigitalrwHandle);
		fclose(DigitalrwHandle);
	}
}

void ClaseGPIO::escribirpinL()
{
	if ((DigitalrwHandle = fopen(PinValue, "r+")) != NULL)
	{
		fwrite("0",sizeof(char),1,DigitalrwHandle);
		fclose(DigitalrwHandle);
	}

}

void ClaseGPIO::leerpin()
{
	if ((DigitalrwHandle = fopen(PinValue, "w+")) != NULL)
	{
		strcat(InPin, PinValue);
		fwrite(&InPin,sizeof(char),sizeof(InPin),DigitalrwHandle);
		fclose(DigitalrwHandle);
	}
}

void ClaseGPIO::borrar_export()
{
	if ((DigitalrwHandle = fopen(PinUnexport, "r+")) != NULL)
	{
		fwrite(&PIN,sizeof(char),sizeof(PIN),DigitalrwHandle);
		fclose(DigitalrwHandle);
	}
}
