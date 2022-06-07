#ifndef BRANCH_H
#define BRANCH_H
#include "Item.h"
#include <vector>
#include <algorithm>
enum SortedType {NOT_SORTED,ID_SORTED,PRICE_SORTED};
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
struct idSort
{
	bool operator() (const Item* first, const Item* second)
	{
		return first->getId() < second->getId();
	}
}; 

struct priceSort
{
	bool operator() (const Item* first, const Item* second)
	{
		return first->getPrice() < second->getPrice();
	}
};

class Branch
{
	std::vector<Item*> catalog; // vector that holds a pointer to all the items in the branch
	const int capacity;
	string location;
	SortedType sortType; //indicates if the branch is sorted or not

public:

	//Constructors
	Branch();
	Branch(const string& location, int capacity);
	Branch(const Branch& other);

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
	//Remove item with given id, if item is not in branch's catalog we throw an exception.
	Item* deleteItem(int id);
	

	int branchValue() const; // Return the total cost of all the items in the branch
	void print() const; // print all items in the catalog by order
	void print_catalog_by_id();	 // Sort catalog by their id, the call print function	
	void print_catalog_by_price();// Sort catalog by their id, the call print function	

	//We iterate through the Item* vector and search for the highest cost item from the same
	//subclass as the input.
	//If none of the items in the vector are from the same subclass as the given input,we throw
	// an error.
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
					max = dynamic_cast<T*>(temp); // cast max to appropiate pointer type
				}
				else if (max->getPrice() < (*it)->getPrice()) // max is not null, we can call getPrice()
				{
					temp = *it;
					max = dynamic_cast<T*>(temp); // cast max to appropiate pointer type
				}
			}
		}
		if (max == NULL) // vector has no items from the same subclass as the input
		{
			throw NoneExistingItemTypeError(); 
		}
		return max;
	}
};

#endif 

