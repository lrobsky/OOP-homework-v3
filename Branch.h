#ifndef BRANCH_H
#define BRANCH_H
#include "Item.h"
#define STORE_SIZE 10
class Branch
{
	
	Item** catalog;
	string location;
	int oldestIndex;
	int numOfItems;

public:

	//Constructor
	
	Branch(string location);
	
	//Destructor
	~Branch();

	//Getters
	Item** getCatalog(int& size) const;
	string getLocation() const;
	int getOldestIndex() const;
	int getNumOfItems() const;
	//Setters 
	void setLocation(const string location);
	void setOldestIndex(const int index);
	void setNumOfItems(const int size);

	//memory allocation and deallocation
	void memoryAllocate();
	void freeMemory();
	void initArray(Item** arrayOfItems,int count); // for initializing Item* array from another branch

	//Add new item to array, if array is full we remove the oldest item in the store.
	void addItem(Item* product);
	
};

#endif 
