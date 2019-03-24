#include "FragTrap.hpp"

//constructor & destructor-----------------------------------------
FragTrap::FragTrap(void)
{
	this->_hitPoint = 100;
	this->_EnergyPoint = 100;
	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangeAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap launch! Let's get this party started!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src)
{
	*this = src;
	std::cout << "FragTrap launch! Let's get this party started!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_EnergyPoint = 100;
	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 100;
	this->_level = 1;
	this->_meleeAttackDamage = 30;
	this->_rangeAttackDamage = 20;
	this->_armorDamageReduction = 5;
	std::cout << "FragTrap launch! Let's get this party started!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
FragTrap &	FragTrap::operator=( FragTrap const & rhs )
{
	std::cout << "Recompiling my combat code!" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_maxHitPoint = rhs._maxHitPoint;
		this->_maxEnergyPoint = rhs._maxEnergyPoint;
		this->_level = rhs._level;
		this->_meleeAttackDamage = rhs._meleeAttackDamage;
		this->_rangeAttackDamage = rhs._rangeAttackDamage;
		this->_armorDamageReduction = rhs._armorDamageReduction;
	}
	return *this;
}

//methond--------------------------------------------------------------------
void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	const int		energyCost = 25;
	const int		skillsNum = 5;
	const int		skillDamageBase = 12;
	int 			index;
	std::string		skills[] = {"Drop the Hammer", 
								"Killbot", 
								"Hyperion Punch", 
								"Start With a Bang", 
								"Livin' Near the Edge"};

	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	if (this->_EnergyPoint > energyCost)
	{
		std::srand(time(NULL));
    	index = std::rand() % skillsNum;
		std::cout << "FR4G-TP "<< this->_name 
			<< " attacks " << target 
			<< " by " << skills[index]
			<< ", causing " << (index + 1) * skillDamageBase
			<< " points of damage !" << std::endl;
		return ;
	}
	std::cout << "out of energy";
}
