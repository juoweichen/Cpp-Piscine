#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <string>
#include <iostream>

class FragTrap
{
	private:
		//methods
		
		//attributes
		unsigned int		_hitPoint;	
		unsigned int 		_EnergyPoint;
		unsigned int 		_level;

		const unsigned int 	_maxHitPoint;
		const unsigned int 	_maxEnergyPoint;
		const std::string	_name;
		const unsigned int 	_meleeAttackDamage;
		const unsigned int 	_rangeAttackDamage;
		const unsigned int 	_armorDamageReduction;

	public:
		//constructor & destructor
		FragTrap(void);
		FragTrap(FragTrap const &);
		FragTrap(std::string name);
		~FragTrap(void);
	
		//operators
		FragTrap & operator=(FragTrap const &);

		//methods
		void rangedAttack(std::string const & target);
		void meleeAttack(std::string const & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void vaulthunter_dot_exe(std::string const & target);
		void status(void);

		//attributes
};

#endif