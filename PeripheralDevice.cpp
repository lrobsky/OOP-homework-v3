#include "PeripheralDevice.h"
#include "Item.h"

//Constructor
PeripheralDevice::PeripheralDevice(int price, string name, string color, bool isWireless) :
	Item(price, name), color(color), isWireless(isWireless) //Call item constructor
{
}

//Destructor
PeripheralDevice::~PeripheralDevice()
{
}

//Getters
string PeripheralDevice::getColor() const
{
	return this->color;
}
bool PeripheralDevice::getIsWireless() const
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
////Convert-to-string 
//PeripheralDevice::operator string()
//{
//	string str=this->Item::operator string();
//	return str;
//}

//Connect function - prints a message to user stating a device was connected to the computer
void PeripheralDevice::connect(Computer& comp)
{
	std::cout << string(*this) <<" "<< "is Connecting to computer: " << string(comp) << std::endl;
}