#ifndef MAINOFFICE_H
#define MAINOFFICE_H

#include "Branch.h"
#include <map>
#include "HWExceptions.h"


class MainOffice
{
	 std::map<string, Branch*> branches;
	MainOffice();
	MainOffice(MainOffice& other);
	MainOffice(const MainOffice& other);
	~MainOffice();
	MainOffice& operator=(MainOffice& other); 
	MainOffice& operator=(const MainOffice& other);

public:
	
	std::map<string, Branch*> getBranches() const;
	void addBranch(string location, int capacity);
	void deleteBranch(string location);
	void printByLocation() const;
	static MainOffice& getInstance(); //get singleton

};

#endif 