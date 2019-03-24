#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>

class ScavTrap
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
		ScavTrap(void);
		ScavTrap(ScavTrap const &);
		ScavTrap(std::string name);
		~ScavTrap(void);
	
		//operators
		ScavTrap & operator=(ScavTrap const &);

		//methods
		void rangedAttack(std::string const & target) const;
		void meleeAttack(std::string const & target) const;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status(void) const;

		//ScavTrap method
		void challengeNewcomer(std::string const & target);

		//attributes
};

#endif