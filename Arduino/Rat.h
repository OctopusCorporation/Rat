#ifndef Rat_h
#define Rat_h

#include "Arduino.h"

class Rat
{
public:
	Rat(int idDevice, String programName, int maxQuantityPins, int baud);
	void ReadDataSerial();
	String Information();
	int Init();

private:
	int _idDevice;
	int _maxQuantityPins;
	int _baud;
	int * _pins;
	String _programName;

	boolean SetMemoryPins();
	void SetSerial();
	void SetPins();
	void OutputOn();
	void OutputOff();
};

#endif