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
	//string str1;
	string computerType = "Desktop";
	if (isLaptop)
	{
		computerType = "Laptop";
	}
	str = this->Item::operator string() + ", " + computerType + ", " + cpuName;
	
	//std::cout << this->Item::operator string() << std::endl;
	/*str1 = "id " + std::to_string(this->getID()) + ": " + this->getManufacturerName() + " " + std::to_string(this->getPrice()) + "$, "
		+ computerType + ", " + cpuName;
	std::cout << str1 << std::endl;*/
	return str;
}