#ifndef HWEXCEPTIONS_H
#define HWEXCEPTIONS_H
#include <exception>

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
struct ExistingItemError : std::exception
{
	const char* what() const
	{
		return "Trying to add an item with an id already in the catalog";
	}
};

struct FullCatalogError : std::exception
{
	const char* what() const
	{
		return "Trying to add an item to a full catalog";
	}
};

struct NonExistingItemError : std::exception
{
	const char* what() const
	{
		return "Trying to delete an item with a non existing id";
	}
};

struct NoneExistingItemTypeError : std::exception
{
	const char* what() const
	{
		return "Trying to get an item with a non existing type";
	}
};

struct ConnectError : std::exception
{
	const char* what() const
	{
		return "Failed connection attempt";
	}
};

#endif