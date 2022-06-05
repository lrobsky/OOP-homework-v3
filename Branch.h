#ifndef BRANCH_H
#define BRANCH_H
#include "Item.h"
#include <vector>
#include <algorithm>
//Temporary place - where should i put this?

struct idMatch
{
	idMatch(int id) : id(id) {}
	bool operator()(Item* item) const
	{
		return (item->getId() == id);
	}
private:
	const int id;
};

class Branch
{
	std::vector<Item*> catalog; // vector that holds a pointer to all the items in the branch
	const int capacity;
	string location;

public:

	//Constructors

	Branch(const string& location, int capacity);
	Branch(Branch& other);

	//Destructor
	~Branch();

	//Getters
	const std::vector<Item*>& getCatalog() const;
	const string& getLocation() const;
	int getCapacity() const;
	//Setters 
	void setLocation(const string& location);


	//Add new item to array, if array is full we remove the oldest item in the store.
	void addItem(Item* product);
	//remove item with given id, if item is not in branch's catalog we throw an exception.
	Item* deleteItem(int id);
	//
	int branchValue() const; // return the total cost of all the items in the branch
	void print_catalog_by_id(); // print all the items in the branch, sorted by their id.
	void print_catalog_by_price();// print all the items in the branch, sorted by their price.

	//return a pointer from 

	template<class T>
	T* retrieveFinest(T* ptr) const
	{
		T* max = NULL;
		Item* temp;
		std::vector<Item*>::const_iterator it;
		for (it = catalog.begin(); it != catalog.end(); ++it)
		{
			if (typeid(*ptr) == typeid(*(*it))) // double dereferencing
			{
				if (max == NULL)
				{
					temp = *it;
					max = dynamic_cast<T*>(temp);
				}
				else if (max->getPrice() < (*it)->getPrice())
				{
					temp = *it;
					max = dynamic_cast<T*>(temp);
				}
			}
		}
		if (max == NULL)
		{
			throw NoneExistingItemTypeError();
		}
		return max;
	}
};

#endif 

