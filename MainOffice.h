#ifndef MAINOFFICE_H
#define MAINOFFICE_H
#include "Branch.h"
#include <map>
#include "HWExceptions.h"

struct ExistingBranchError : std::exception
{
	const char* what() const
	{
		return "Trying to add a branch with an already existing location";
	}
};
struct NonExistingBranchError : std::exception
{
	const char* what() const
	{
		return "Trying to delete a branch with an non existing location";
	}
};

class MainOffice
{
	 std::map<string, Branch*> branches;
	MainOffice();
	MainOffice(MainOffice& other);
	MainOffice(const MainOffice& other);
	~MainOffice();
	MainOffice& operator=(MainOffice& other)=delete; 


public:
	
	const std::map<string, Branch*>& getBranches() const ;
	void addBranch(string location, int capacity);
	void deleteBranch(string location);
	void printByLocation() ;
	static MainOffice& getInstance(); //get singleton

};

#endif 