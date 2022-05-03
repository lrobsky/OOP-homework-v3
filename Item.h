#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string> 
using std::string;
class Item
{
	int price;
	string manufacturerName;
	int itemID;
	static int totalItems;

public:
	//Constructor
	Item(int price, string name);
	
	//Destructor
	virtual ~Item();

	//Getters
	int getPrice() const;
	string getManufacturer() const;
	int getId() const;
	static int getTotalItems();
	//Setters
	void setPrice(const int price);
	void setManufacturer(const string name);
	void setTotalItems(const int number);
	//Convert-to-string
	virtual operator string()=0; // pure virtual function - Item is an interface
	

};



#endif 