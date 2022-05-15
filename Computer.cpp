#include "Computer.h"


//Constructor
Computer::Computer(int price, string manufacturerName, string cpuName, bool isLaptop): Item(price,manufacturerName)
,cpuName(cpuName),isLaptop(isLaptop)
{
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