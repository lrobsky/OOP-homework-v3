#include "Branch.h"
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
bool idSort(Item* first, Item* second)
{
	return first->getId() < second->getId();
}
bool priceSort(Item* first, Item* second)
{
	return first->getPrice() < second->getPrice();
}

//Constructors
Branch::Branch(const string& location="~", int capacity = 0) : location(location), capacity(capacity)
{
	catalog.reserve(capacity);
}
Branch::Branch(Branch& otherBranch) : capacity(otherBranch.capacity), location(otherBranch.location) //Copy constructor
{
	catalog.reserve(capacity);
}

//Destructor
Branch::~Branch()
{
	std::vector<Item*>::iterator it;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		delete *it; // free dynamic memory
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
		//catalog.insert(catalog.begin(), product); // insert product at beginning of vector
		catalog.push_back(product);  
	}
}

Item* Branch::deleteItem(int id)
{
	std::vector<Item*>::iterator it;
	Item* temp;
	it = find_if(catalog.begin(), catalog.end(), idMatch(id));	
	if (it == catalog.end())//item with inserted id is not in catalog
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
void Branch::print_catalog_by_id() 
{
	std::vector<Item*>::iterator it;
	std::stable_sort(catalog.begin(), catalog.end(), idSort);
	std::cout << "Printing KSF branch in " << location << std::endl;
	std::cout << "There are " << catalog.size() <<" item in the catalog" << std::endl;
	std::cout << "Catalog value is: " << this->branchValue() <<  std::endl;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		std::cout << string(*(*it)) << std::endl;
	}
}
void Branch::print_catalog_by_price()  
// Code duplication - can export to new function-add enum type
{
	std::vector<Item*>::iterator it;
	std::stable_sort(catalog.begin(), catalog.end(), priceSort);
	std::cout << "Printing KSF branch in " << location << std::endl;
	std::cout << "There are " << catalog.size() << " item in the catalog" << std::endl;
	std::cout << "Catalog value is: " << this->branchValue() << std::endl;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		std::cout << string(*(*it)) << std::endl;
	}
}
Item* Branch::retrieveFinest(Item* ptr) const
{
	std::vector<Item*> temp;
	std::vector<Item*>::const_iterator it ;
	for (it = catalog.begin(); it != catalog.end(); ++it)
	{
		if (typeid(*ptr) == typeid(*it))
		{
			temp.emplace_back(*it);
		}
	}
	if (temp.size() == 0)
	{
		throw NoneExistingItemTypeError();
	}
	return *(std::max_element(temp.begin(), temp.end(), priceSort)); // pricesort- struct?
}