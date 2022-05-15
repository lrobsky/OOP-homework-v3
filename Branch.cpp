#include "Branch.h"

Branch::Branch(const string& location): location(location),oldestIndex(0),numOfItems(0), catalog(NULL)
{
	memoryAllocate();
}
Branch::~Branch()
{
	freeMemory();
}

//Getters
Item** Branch::getCatalog(int& size) const
{
	size = numOfItems;// return number of items in branch to user
	return catalog;
}
const string& Branch::getLocation() const
{
	return location;
}
int Branch::getOldestIndex() const
{
	return oldestIndex;
}
int Branch::getNumOfItems() const
{
	return numOfItems;
}

//Setters
void Branch::setLocation(const string& location)
{
	this->location = location;
}

void Branch::setOldestIndex(const int index)
{
	this->oldestIndex = index;
}
void Branch::setNumOfItems(const int size)
{
	this->numOfItems = size;
}

//memory allocation and deallocation
void Branch::memoryAllocate()
{
	catalog = new Item* [STORE_SIZE];
	for (int i = 0; i < STORE_SIZE; i++) 
	{
		catalog[i] = NULL;
	}
}
void Branch::freeMemory()
{
	for (int i = 0; i < numOfItems;i++)
	{
		if (catalog[i] != NULL)
		{
			delete catalog[i];
		}
			
	}
	delete[] catalog;
	
}

//Add new item to array, if array is full we remove the oldest item in the store.
void Branch::addItem(Item* product)
{
	
	if (STORE_SIZE == numOfItems) // when store is  full
	{
		delete catalog[oldestIndex];	// remove oldest item from store
		catalog[oldestIndex] = product; // insert new item
		oldestIndex = (oldestIndex + 1) % (STORE_SIZE-1); // update oldestIndex
	}
	else // when store is not full
	{
		catalog[numOfItems++] = product; 
	}
}