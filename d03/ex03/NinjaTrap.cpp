#include "NinjaTrap.hpp"

//constructor & destructor-----------------------------------------
NinjaTrap::NinjaTrap(void)
{
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_EnergyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangeAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "NinjaTrap launch! Let's get this party started!" << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src)
{
	*this = src;
	std::cout << "NinjaTrap launch! Let's get this party started!" << std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 60;
	this->_maxHitPoint = 60;
	this->_EnergyPoint = 120;
	this->_maxEnergyPoint = 120;
	this->_level = 1;
	this->_meleeAttackDamage = 60;
	this->_rangeAttackDamage = 5;
	this->_armorDamageReduction = 0;
	std::cout << "NinjaTrap launch! Let's get this party started!" << std::endl;
}

NinjaTrap::~NinjaTrap(void)
{
	std::cout << "NinjaTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
NinjaTrap &	NinjaTrap::operator=( NinjaTrap const & rhs )
{
	std::cout << "Recompiling my combat code!" << std::endl;
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_hitPoint = rhs._hitPoint;
		this->_maxHitPoint = rhs._maxHitPoint;
		this->_EnergyPoint = rhs._EnergyPoint;
		this->_maxEnergyPoint = rhs._maxEnergyPoint;
		this->_level = rhs._level;
		this->_meleeAttackDamage = rhs._meleeAttackDamage;
		this->_rangeAttackDamage = rhs._rangeAttackDamage;
		this->_armorDamageReduction = rhs._armorDamageReduction;
	}
	return *this;
}

//methond--------------------------------------------------------------------
void	NinjaTrap::ninjaShoebox(NinjaTrap & target)
{
	std::cout << "\nSHADOW CLONE JUTSU!!!" << std::endl;
	NinjaTrap clone = target;
	(void)clone;
}

void	NinjaTrap::ninjaShoebox(ClapTrap & target)
{
	std::cout << "\nSHADOW CLONE JUTSU!!!" << std::endl;
	ClapTrap clone = target;
	(void)clone;
}

void	NinjaTrap::ninjaShoebox(FragTrap & target)
{
	std::cout << "\nSHADOW CLONE JUTSU!!!" << std::endl;
	FragTrap clone = target;
	(void)clone;
}

void	NinjaTrap::ninjaShoebox(ScavTrap & target)
{
	std::cout << "\nSHADOW CLONE JUTSU!!!" << std::endl;
	ScavTrap clone = target;
	(void)clone;
}
