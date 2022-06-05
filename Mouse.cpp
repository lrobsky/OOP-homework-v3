#include "Mouse.h"

//Constructor
Mouse::Mouse(int price, string name, string color, bool isWireless, int dpi) :
	PeripheralDevice(price, name, color, isWireless), dpi(dpi)
{}

//Getter
int Mouse::getDpi() const
{
	return dpi;
}

//Setter
void Mouse::setDpi(int dpi)
{
	this->dpi = dpi;
}
//Convert-to-string
Mouse::operator string() const
{
	string str;
	string mouseType = "Wired";
	if (this->getIsWireless())
	{
		mouseType = "Wireless";
	}
	str = this->Item::operator string() + ", " + mouseType + ", " + this->getColor()
		+ ", " + "Mouse with " + "dpi : " + std::to_string(dpi) ;
	return str;
}

void Mouse::connect(Computer* comp)
{
	std::cout << "Connecting a mouse" << std::endl;
	this->PeripheralDevice::connect(comp);
 }