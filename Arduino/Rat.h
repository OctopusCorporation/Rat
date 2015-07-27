#ifndef Rat_h
#define Rat_h

#include "Arduino.h"

class Rat
{
public:
	Rat(int maxQuantityPins, int baud);
	void ReadDataSerial();
	String Information();
	String Init();

private:
	int _maxQuantityPins;
	int _outputPin;
	int _baud;
	int * _pins;
	boolean SetMemoryPins();
	void SetSerial();
	void SetPins();
	void OutputOn();
	void OutputOff();
};

#endif