#include "Item.h"

//Constructor

Item::Item(int price, string name) : itemID(totalItems++), price(price), manufacturerName(name)
{

}
//Destructor
Item::~Item()
{
	std::cout << "Throwing away an item" << std::endl;
}

//Getters

int Item::getPrice() const
{
	return price;
}
string Item::getManufacturer() const
{
	return manufacturerName;
}

const int Item::getId() const
{
	return itemID;
}
int Item::getTotalItems()
{
	return totalItems;
}

//Setters

void Item::setPrice(const int price)
{
	this->price = price;
}
void Item::setManufacturer(const string name)
{
	this->manufacturerName = name;
}

void Item::setTotalItems(const int number)
{
	totalItems = number;
}

Item::operator string()
{
	string str;
	str = "id " + std::to_string(this->itemID) + ": " + manufacturerName + " " + std::to_string(this->price) + "$";
	return str;
}

int Item::totalItems = 1;