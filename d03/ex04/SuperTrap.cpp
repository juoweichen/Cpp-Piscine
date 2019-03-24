#include "SuperTrap.hpp"

//constructor & destructor-----------------------------------------
SuperTrap::SuperTrap(void)
{
	this->_hitPoint = FragTrap::_hitPoint;
	this->_EnergyPoint = NinjaTrap::_EnergyPoint;
	this->_maxHitPoint = FragTrap::_maxHitPoint;;
	this->_maxEnergyPoint = NinjaTrap::_maxEnergyPoint;
	this->_level = 1;
	this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	this->_rangeAttackDamage = FragTrap::_rangeAttackDamage;;
	this->_armorDamageReduction = FragTrap::_armorDamageReduction;
	std::cout << "SuperTrap launch! SUPERRRRRR!" << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src)
{
	*this = src;
	std::cout << "SuperTrap launch! SUPERRRRRR!" << std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = FragTrap::_hitPoint;
	this->_EnergyPoint = NinjaTrap::_EnergyPoint;
	this->_maxHitPoint = FragTrap::_maxHitPoint;;
	this->_maxEnergyPoint = NinjaTrap::_maxEnergyPoint;
	this->_level = 1;
	this->_meleeAttackDamage = NinjaTrap::_meleeAttackDamage;
	this->_rangeAttackDamage = FragTrap::_rangeAttackDamage;;
	this->_armorDamageReduction = FragTrap::_armorDamageReduction;
	std::cout << "SuperTrap launch! SUPERRRRRR!" << std::endl;
}

SuperTrap::~SuperTrap(void)
{
	std::cout << "SuperTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
SuperTrap &	SuperTrap::operator=( SuperTrap const & rhs )
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
