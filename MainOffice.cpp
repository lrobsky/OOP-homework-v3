#include "MainOffice.h"
MainOffice::MainOffice()
{
}

MainOffice::~MainOffice() //Destructor - also frees memory of allocated branches
{
	std::cout << "MainOffice destructor" << std::endl;
	for (auto& Branch : branches)
	{
		delete &Branch.second;
	}
}

//Getter
std::map<string, Branch>& MainOffice::getBranches() 
{
	return branches;
}
//Creates new branch with inputed location&capacy.
//if MainOffice already has a branch with the same location, throw error.
void MainOffice::addBranch(string location, int capacity)
{
	std::map<string, Branch>::iterator it;
	it = branches.find(location);
	if (it == branches.end()) // key is not in map
	{
		branches.emplace(std::pair<string, Branch>(location,Branch(location, capacity)));
		/*branches.insert(make_pair(location,Branch(location, capacity)));*/
			
	}
	else // key already in map
	{
		throw ExistingBranchError();
	}
}
//Remove branch with inputed location from map/MainOffice
//If branch with inserted location does not exist, throw error.
void MainOffice::deleteBranch(string location)
{
	std::map<string, Branch>::iterator it;
	it = branches.find(location);
	if (it == branches.end()) // branch is not in map
	{
		throw NonExistingBranchError();
	}
	else
	{
		branches.erase(location);
	}
}
//iterate through map container, and print every item in each branch by its id.
//Because our key is the location,the map is already sorted.
void MainOffice::printByLocation() 
{
	std::cout << "There are " << branches.size() << " KSP branches" << std::endl;
	for (auto& Branch : branches)
	{
		Branch.second.print_catalog_by_id();
	}
}

//Return singelton instance of MainOffice.
//If singelton of MainOffice hasnt been initialized yet we create one.
  MainOffice& MainOffice::getInstance()
{
	static MainOffice* instance = new MainOffice;
	return *instance;
}