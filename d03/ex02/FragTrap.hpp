#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		//constructor & destructor
		FragTrap(void);
		FragTrap(FragTrap const &);
		FragTrap(std::string name);
		~FragTrap(void);
	
		//operators
		FragTrap & operator=(FragTrap const &);

		//methods
		void vaulthunter_dot_exe(std::string const & target);

		//attributes
};

#endif