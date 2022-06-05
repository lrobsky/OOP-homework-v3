#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string> 
#include "HWExceptions.h"
using std::string;


class Item
{
	int price;
	string manufacturerName;
	const int itemID;
	static int totalItems;

public:
	//Constructor
	Item(int price, string name);
	
	//Destructor
	virtual ~Item();

	//Getters
	int getPrice() const;
	string getManufacturer() const;
	const int getId() const;
	static int getTotalItems() ;
	//Setters
	void setPrice(const int price);
	void setManufacturer(const string name);
	void setTotalItems(const int number);
	//Convert-to-string
	virtual operator string() const =0 ; // pure virtual function - Item is an interface
	

};



#endif 