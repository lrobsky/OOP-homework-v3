#ifndef MOUSE_H
#define MOUSE_H
#include "PeripheralDevice.h"
class Mouse : public PeripheralDevice
{
	int DPI;

public:
	//Constructor
	Mouse(int price, string name, string color, bool isWireless, int dpi);
	//Getter
	int getDPI() const;

	//Setter
	void setDPI(int size);
	//Convert-to-string
	virtual operator string();

};

#endif 

