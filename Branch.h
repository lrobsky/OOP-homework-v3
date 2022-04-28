#ifndef BRANCH_H
#define BRANCH_H
#include "Item.h"
#define STORE_SIZE 4
class Branch
{
	
	Item** catalog;
	string location;
	int oldestIndex;
	int numOfItems;

public:

	//Constructor
	
	Branch(string location);
	//Copy constructor
	
	Branch(const Branch& otherBranch);
	//Destructor
	~Branch();
	//Assigment operator
	Branch& operator=(const Branch& otherBranch);

	//Getters
	Item** getCatalog(int& size) const;
	string getLocation() const;
	int getOldestIndex() const;
	int getNumOfItems() const;
	//Setters - what about setCatalog/setOldestIndex?
	void setLocation(const string location);

	//memory allocation and deallocation
	void memoryAllocate();
	void freeMemory();
	void initArray(Item** arrayOfItems,int count); // for initializing Item* array from another branch

	//Add new item to array, if array is full we remove the oldest item in the store.
	void addItem(Item* product);
	
};

#endif 
