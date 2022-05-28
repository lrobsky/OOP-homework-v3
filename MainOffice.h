#include "Branch.h"
#include <map>
#include "HWExceptions.h"
#include "Branch.h"

class MainOffice
{
	static std::map<string, Branch*> branches;

public:
	MainOffice();
	static std::map<string, Branch*> getBranches() ;
	void addBranch(string location, int capacity);
	void deleteBranch(string location);
	void printByLocation();
	static MainOffice& getInstance(); //get singleton

};