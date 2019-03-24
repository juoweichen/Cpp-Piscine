#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
	private:
		//methods

		//attributes
	
	protected:
		std::string		_name;
		unsigned int	_hitPoint;	
		unsigned int 	_maxHitPoint;
		unsigned int 	_EnergyPoint;
		unsigned int 	_maxEnergyPoint;
		unsigned int 	_level;
		unsigned int 	_meleeAttackDamage;
		unsigned int 	_rangeAttackDamage;
		unsigned int 	_armorDamageReduction;

	public:
		//constructor & destructor
		ClapTrap(void);
		ClapTrap(ClapTrap const &);
		ClapTrap(std::string name);
		~ClapTrap(void);
	
		//operators
		ClapTrap & operator=(ClapTrap const &);

		//methods
		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status(void) const;

		//attributes
};

#endif