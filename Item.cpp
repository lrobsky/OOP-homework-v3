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
string Item::getManufacturerName() const
{
	return manufacturerName;
}

int Item::getID() const
{
	return itemID;
}

//Setters

void Item::setPrice(const int price)
{
	this->price = price;
}
void Item::setManufacturerName(const string name)
{
	this->manufacturerName = name;
}

void Item::setID(const int id)
{
	this->itemID = id;
}

Item::operator string()
{
	string str;
	str = "id " + std::to_string(this->itemID) + ": " + manufacturerName + " " + std::to_string(this->price) + "$";
	return str;
}

int Item::totalItems = 1;