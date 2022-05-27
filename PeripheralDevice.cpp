#include "PeripheralDevice.h"
#include "Item.h"

//Constructor
PeripheralDevice::PeripheralDevice(int price, string name, string color, bool isWireless) :
	Item(price, name), color(color), isWireless(isWireless), compConnectedTo(NULL)
	//Call item constructor
{
}

//Destructor
PeripheralDevice::~PeripheralDevice()
{
	disconnect();
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

//Connect function - prints a message to user stating a device was connected to the computer
void PeripheralDevice::connect(Computer* comp)
{
	if (compConnectedTo != NULL)
	{
		if (compConnectedTo = comp)
		{
			return; // trying to connec to computer already connected to
		}
		else
		{
			throw ConnectError(); // already connected to different computer
		}
	}

	if (comp->connectPeripheral(this) == true)
	{
		compConnectedTo = comp; // update compConnectedTo
		std::cout << string(*this) << " " << "is Connecting to computer: " << string(*comp) << std::endl;
	}
	else //capacity overflow or same type error
	{
		throw ConnectError();
	}
}
void PeripheralDevice::disconnect()
{
	if (compConnectedTo == NULL)
	{
		return;
	}
	else
	{
		compConnectedTo->disconnectPeripheral(this);
		compConnectedTo = NULL;
	}
}
