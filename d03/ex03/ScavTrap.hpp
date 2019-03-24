#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		//constructor & destructor
		ScavTrap(void);
		ScavTrap(ScavTrap const &);
		ScavTrap(std::string name);
		~ScavTrap(void);
	
		//operators
		ScavTrap & operator=(ScavTrap const &);

		//methods
		void challengeNewcomer(std::string const & target);

		//attributes
};

#endif