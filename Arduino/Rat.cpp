#include "Arduino.h"
#include "Rat.h"

Rat::Rat(int maxQuantityPins, int baud)
{
	_maxQuantityPins = maxQuantityPins;
	_baud = baud;

}

String Rat::Init()
{
	if (SetMemoryPins())
	{
		SetSerial();
		SetPins();
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

