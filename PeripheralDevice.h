#ifndef PeripheralDevice_H
#define PeripheralDevice_H
#include "Item.h"
#include "Computer.h"
class PeripheralDevice : public Item
{
	string color;
	bool isWireless;

public:
	//Constructor
	PeripheralDevice(int price, string name, string color, bool isWireless);

	//Getters
	string getColor();
	bool getIsWireless();

	//Setters
	void setColor(const string color);
	void setIsWireless(const bool isWireless);

	//Connect function - prints a message to user stating a device was connected to the computer
	virtual void connect(Computer& comp);

};

#endif 
