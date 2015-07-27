#include "Arduino.h"
#include "Rat.h"

Rat::Rat(int idDevice, String programName, int maxQuantityPins, int baud)
{
	_maxQuantityPins = maxQuantityPins;
	_baud = baud;
	_idDevice = idDevice;
	_programName = programName;
}

int Rat::Init()
{
	if (SetMemoryPins())
	{
		SetSerial();
		SetPins();
		return 0;
	}
	else
	{
		return -1;
	}
}

boolean Rat::SetMemoryPins()
{
	_pins = new (nothrow) int[_maxQuantityPins];
	if (_pins == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Rat::SetSerial()
{
	Serial.begin(_baud);
}

void Rat::SetPins()
{
	for (int i = 0; i < _maxQuantityPins; i++)
	{
		pinMode(_pins[i], OUTPUT);
	}	
}

String Rat::Information()
{
	String info = "";
	// Program Name
	info += "\n Rat Program: " + _programName;

	// Serial data
	info += "\n Serial is";
	if (Serial.available() > 0)
	{
		info += "available"
	}
	else
	{
		info += "not available";
	}
	
	// Pins used
	return info;
}
