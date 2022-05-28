#include "MainOffice.h"
MainOffice::MainOffice()
{
}
std::map<string, Branch*> MainOffice::getBranches() 
{
	return branches;
}

void MainOffice::addBranch(string location, int capacity)
{
	std::map<string, Branch*>::iterator it;
	it = branches.find(location);
	if (it != branches.end()) // key is not in map
	{
		Branch* b1 = new Branch(location, capacity);
		branches[location] = b1;
	}
	else // key already in map
	{
		throw ExistingBranchError();
	}
}
void MainOffice::deleteBranch(string location)
{
	std::map<string, Branch*>::iterator it;
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
void MainOffice::printByLocation()
{
	for (auto& Branch : branches)
	{
		Branch.second->print_catalog_by_id();
	}
}

static MainOffice& getInstance()
{
	static MainOffice* instance = new MainOffice;
	return *instance;
}
	