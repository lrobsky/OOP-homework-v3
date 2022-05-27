#ifndef COMPUTER_H
#define COMPUTER_H
#include "Item.h"
#include <vector>
#include <algorithm>

class Computer : public Item
{
	string cpuName;
	bool isLaptop;
	const int numOfUsbPorts;
	std::vector<Item*> connectedDevices;

public:
	//Constructor
	Computer(int price, string manufacturerName, string cpuName, bool isLaptop, int numOfUsbPorts);

	// Getters
	string getCpu() const;
	bool getIsLaptop() const;
	const int getnumOfUsbPorts() const;
	//Setters
	void setCpu(const string name);
	void getIsLaptop(const bool isLaptop);
	//Convert-to-string
	virtual operator string();

	bool connectPeripheral(Item* device);
	void disconnectPeripheral(Item* device);
	void print_connected(); // print all peripheral devices connected to the computer
};


#endif 
