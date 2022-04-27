#include "PeripheralDevice.h"
#include "Item.h"

PeripheralDevice::PeripheralDevice(int price, string name, string color, bool isWireless) :
	Item(price, name), color(color), isWireless(isWireless)
{

}

//Getters
string PeripheralDevice::getColor()
{
	return this->color;
}
bool PeripheralDevice::getIsWireless()
{
	return this->isWireless;
}

//Setters
void PeripheralDevice::setColor(const string color)
{
	this->color = color;
}
void PeripheralDevice::setIsWireless(const bool isWireless)
{
	this->isWireless = isWireless;
}

//Connect function - prints a message to user stating a device was connected to the computer
void PeripheralDevice::connect(Computer& comp)
{
	
	std::cout << string(*this) <<" "<< "is Connecting to computer: " << string(comp) << std::endl;
}