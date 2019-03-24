#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include <string>
#include <iostream>

#include "NinjaTrap.hpp"
#include "FragTrap.hpp"

class SuperTrap : public FragTrap, public NinjaTrap
{
	public:
		//constructor & destructor
		SuperTrap(void);
		SuperTrap(SuperTrap const &);
		SuperTrap(std::string name);
		~SuperTrap(void);
	
		//operators
		SuperTrap & operator=(SuperTrap const &);

		//methods

		//attributes
};

#endif