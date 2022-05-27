#include "Computer.h"


//Constructor
Computer::Computer(int price, string manufacturerName, string cpuName, bool isLaptop,int numOfUsbPorts)
: Item(price,manufacturerName) ,cpuName(cpuName),isLaptop(isLaptop), numOfUsbPorts(numOfUsbPorts)
{
	connectedDevices.reserve(numOfUsbPorts);
}
//Getters
string Computer::getCpu() const
{
	return this->cpuName;
}
bool Computer::getIsLaptop() const
{
	return this->isLaptop;
}
const int Computer::getnumOfUsbPorts() const
{
	return this->numOfUsbPorts;
}
//Setters


void Computer::setCpu(const string name)
{
	this->cpuName = name;
}
void Computer::getIsLaptop(const bool isLaptop)
{
	this->isLaptop = isLaptop;
}
//Convert-to-string
Computer::operator string()
{
	string str;
	string computerType = "Desktop";
	if (isLaptop)
	{
		computerType = "Laptop";
	}
	str = this->Item::operator string() + ", " + computerType + ", " + cpuName;
	return str;
}


bool Computer::connectPeripheral(Item* device)
{
	if (numOfUsbPorts <= connectedDevices.size())
	{
		return false;
	}
	std::vector<Item*>::iterator it;
	for (it = connectedDevices.begin(); it != connectedDevices.end(); it++)
	{
		if (typeid(*(*it)) == typeid(*device)) // from same type
		{
			return false;
		}
	}
	connectedDevices.push_back(device);
	return true;
}

void Computer::disconnectPeripheral(Item* device)
{
	std::vector<Item*>::iterator it;
	it = find(connectedDevices.begin(), connectedDevices.end(), device);
	if (it != connectedDevices.end())
	{
		connectedDevices.erase(it);
	}
}

void Computer::print_connected()
{
	std::vector<Item*>::iterator it;
	std::cout << "There are " << connectedDevices.size() << " connection to "
		<< string(*this) << std::endl;
	for (it = connectedDevices.begin(); it != connectedDevices.end(); ++it)
	{
		std::cout << string(*(*it)) << std::endl;
	}

}