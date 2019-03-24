#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include <string>
#include <iostream>

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
	public:
		//constructor & destructor
		NinjaTrap(void);
		NinjaTrap(NinjaTrap const &);
		NinjaTrap(std::string name);
		~NinjaTrap(void);
	
		//operators
		NinjaTrap & operator=(NinjaTrap const &);

		//methods
		void	ninjaShoebox(NinjaTrap & target);
		void	ninjaShoebox(ClapTrap & target);
		void	ninjaShoebox(FragTrap & target);
		void	ninjaShoebox(ScavTrap & target);

		//attributes
};

#endif
