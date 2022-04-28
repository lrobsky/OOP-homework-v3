#include "Mouse.h"

//Constructor
Mouse::Mouse(int price, string name, string color, bool isWireless, int DPI) :
	PeripheralDevice(price, name, color, isWireless), DPI(DPI)
{}

//Getter
int Mouse::getDPI() const
{
	return DPI;
}

//Setter
void Mouse::setDPI(int size)
{
	this->DPI = DPI;
}
//Convert-to-string
Mouse::operator string()
{
	string str;
	string keyboardType = "Wired";
	if (this->getIsWireless())
	{
		keyboardType = "Wireless";
	}
	str = this->Item::operator string() + ", " + keyboardType + ", " + this->getColor()
		+ ", " + "Mouse with " + "dpi : " + std::to_string(DPI) ;
	return str;
}

void Mouse::connect(Computer& comp)
{
	std::cout << "Connecting a mouse" << std::endl;
	this->PeripheralDevice::connect(comp);
 }