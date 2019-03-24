#include <list>
#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::list<int>		lst1;

	lst1.push_back(1);
	lst1.push_back(17);
	lst1.push_back(42);
	lst1.push_back(50);
	lst1.push_back(72);

	try 
	{
		if (easyfind(lst1, 129))
			std::cout << "Value found!" << std::endl;
	}
	catch (std::exception & e)
 	{
		 std::cout << "Value not found" << std::endl;
	}
	
	std::vector<int>	v1;
	
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);

	try 
	{
		if (easyfind(v1, 30))
			std::cout << "Value found!" << std::endl;
	}
	catch (std::exception & e)
 	{
		 std::cout << "Value not found" << std::endl;
	}
	return (0);
}