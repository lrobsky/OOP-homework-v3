#ifndef MOUSE_H
#define MOUSE_H
#include "PeripheralDevice.h"
class Mouse : public PeripheralDevice
{
	int dpi;

public:
	//Constructor
	Mouse(int price, string name, string color, bool isWireless, int dpi);
	//Getter
	int getDpi() const;

	//Setter
	void setDpi(int size);
	//Convert-to-string
	virtual operator string();

	virtual void connect(Computer& comp);

};

#endif 

