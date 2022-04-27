#ifndef COMPUTER_H
#define COMPUTER_H
#include "Item.h"


class Computer : public Item
{
	string cpuName;
	bool isLaptop;

public:
	//Constructor
	Computer(int price, string manufacturerName, string cpuName, bool isLaptop);
	// no need for destructor?

	// Getters
	string getCpuName() const;
	bool getIsLaptop() const;
	//Setters
	void setCpuName(const string name);
	void getIsLaptop(const bool isLaptop);
	//Convert-to-string
	virtual operator string();

};


#endif 
