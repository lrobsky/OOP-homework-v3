#include "Branch.h"

//Constructors
Branch::Branch(const string& location="~", int capacity = 0)
: location(location), capacity(capacity), sortType(NOT_SORTED)
{
	catalog.reserve(capacity);
}
//Copy constructor
Branch::Branch(Branch& otherBranch)
: capacity(otherBranch.capacity), location(otherBranch.location), sortType(NOT_SORTED) 
{
	catalog.reserve(capacity);
}

//Destructor
Branch::~Branch()
{
	std::vector<Item*>::iterator it;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		delete *it; // free dynamic allocated memory
	}
}

//Getters
int Branch::getCapacity() const
{
	return capacity;
}
const std::vector<Item*>& Branch::getCatalog() const
{
	return catalog;
}
const string& Branch::getLocation() const
{
	return location;
}


//Setters
void Branch::setLocation(const string& location)
{
	this->location = location;
}



//Add new item to array, if array is full we remove the oldest item in the store.
void Branch::addItem(Item* product)
{
	std::vector<Item*>::iterator it;
	if (catalog.size() == catalog.capacity()) // when store is  full
	{
		throw FullCatalogError();
	}
	else // Store is not full, check if product is already in catalog
	{
		it = find(catalog.begin(), catalog.end(), product);
		if (it != catalog.end()) // product already in catalog
		{
			throw ExistingItemError();
		}
		catalog.push_back(product);// insert Item to vector
		sortType = NOT_SORTED;
	}
}

Item* Branch::deleteItem(int id)
{
	std::vector<Item*>::iterator it;
	Item* temp;
	it = find_if(catalog.begin(), catalog.end(), idMatch(id));	
	if (it == catalog.end()) //item with inserted id is not in catalog
	{
		throw NonExistingItemError();
	}
	else
	{
		temp = *it; // save to be removed item
		catalog.erase(it); // remove item from catalog
		return temp; // return pointer to removed item
	}
}
// Return the total cost of all the items in the branch
int Branch::branchValue() const
{
	int sum = 0;
	std::vector<Item*>::const_iterator it;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		sum += (*it)->getPrice();
	}
	return sum;
}

void Branch::print() const
{
	std::vector<Item*>::const_iterator it;
	std::cout << "Printing KSF branch in " << location << std::endl;
	std::cout << "There are " << catalog.size() << " item in the catalog" << std::endl;
	std::cout << "Catalog value is: " << this->branchValue() << std::endl;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		std::cout << string(*(*it)) << std::endl;
	}
}
// Print all the items in the branch, sorted by their id.
void Branch::print_catalog_by_id() 
{
	if (sortType != ID_SORTED) // if catalog is already sorted by id, no need to sort again
	{
		std::stable_sort(catalog.begin(), catalog.end(), idSort());
		sortType = ID_SORTED;
	}
	this->print();
}
// Print all the items in the branch, sorted by their price.
void Branch::print_catalog_by_price()  
{
	if (sortType != PRICE_SORTED) // if catalog is already sorted by price, no need to sort again
	{
		std::stable_sort(catalog.begin(), catalog.end(), priceSort());
		sortType = PRICE_SORTED;
	}
	this->print();
}
