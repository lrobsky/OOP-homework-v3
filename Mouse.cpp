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
		+ ", " + "Keyboard with " + std::to_string(DPI) + " keys";
	return str;
}