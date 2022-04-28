#ifndef KEYBOARD_H
#define KEYBOARD_H
#include "PeripheralDevice.h"
class Keyboard : public PeripheralDevice
{
	int numOfKeys;

public:
	//Constructor
	Keyboard(int price, string name, string color, bool isWireless, int numOfKeys);
	//Getter
	int getNumOfKeys() const;

	//Setter
	void setNumOfKeys(int size);
	//Convert-to-string
	virtual operator string();
		

	virtual void connect(Computer& comp);
};
	
#endif 
