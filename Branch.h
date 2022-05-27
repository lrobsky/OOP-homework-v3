#ifndef BRANCH_H
#define BRANCH_H
#include "Item.h"
#include <vector>
#include <algorithm>
//Temporary place - where should i put this?


class Branch
{

	std::vector<Item*> catalog;
	const int capacity;
	string location;

public:

	//Constructors
	
	Branch(const string& location,int capacity);
	Branch(Branch& other);
	
	//Destructor
	~Branch();

	//Getters
	const std::vector<Item*>& getCatalog() const;
	const string& getLocation() const;
	const int getCapacity() const;
	//Setters 
	void setLocation(const string& location);


	//Add new item to array, if array is full we remove the oldest item in the store.
	void addItem(Item* product);
	//remove item with given id, if item is not in branch's catalog we throw an exception.
	Item* deleteItem(int id);

	int branchValue() const;
	void print_catalog_by_id();
	void print_catalog_by_price();
	Item* retrieveFinest(Item* ptr) const;
	
};

#endif 
