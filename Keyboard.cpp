#include "Keyboard.h"

//Constructor
Keyboard::Keyboard(int price, string name, string color, bool isWireless, int numOfKeys):
PeripheralDevice(price,name,color,isWireless),numOfKeys(numOfKeys)
{}

//Getter
int Keyboard::getNumOfKeys() const
{
	return numOfKeys;
}

//Setter
void Keyboard::setNumOfKeys(int size)
{
	this->numOfKeys = numOfKeys;
}
//Convert-to-string
Keyboard::operator string() 
{
	string str;
	string keyboardType = "Wired";
	if (this->getIsWireless())
	{
		keyboardType = "Wireless";
	}
	str = this->Item::operator string() + ", " + keyboardType + ", " + this->getColor()
		+ ", " + "Keyboard with " + std::to_string(numOfKeys) + " keys";
	return str;
}