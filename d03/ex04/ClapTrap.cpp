#include "ClapTrap.hpp"

//constructor & destructor-----------------------------------------
ClapTrap::ClapTrap(void) : 
	_name("mob"),
	_hitPoint(1),
	_maxHitPoint(1),
	_EnergyPoint(1),
	_maxEnergyPoint(1),
	_level(1),
	_meleeAttackDamage(1),
	_rangeAttackDamage(1),
	_armorDamageReduction(1)
{
	std::cout << "ClapTrap launch! This time it'll be awesome, I promise!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src)
{
	*this = src;
	std::cout << "ClapTrap launch! This time it'll be awesome, I promise!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :
	_name(name),
	_hitPoint(1),
	_maxHitPoint(1),
	_EnergyPoint(1),
	_maxEnergyPoint(1),
	_level(1),
	_meleeAttackDamage(1),
	_rangeAttackDamage(1),
	_armorDamageReduction(1)
{
	std::cout << "ClapTrap launch! This time it'll be awesome, I promise!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
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

//methods------------------------------------------------------------------
void ClapTrap::rangedAttack(std::string const & target) const 
{
	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->_rangeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void ClapTrap::meleeAttack(std::string const & target) const
{	
	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	if (this->_hitPoint < amount - this->_armorDamageReduction)
	{
		this->_hitPoint = 0;
		std::cout << "Is it dead? Can, can I open my eyes now?" << std::endl;
		return ;
	}
	std::cout << "Woah! Oh! Jeez!" << std::endl;
	this->_hitPoint -= (amount - this->_armorDamageReduction);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	if (this->_maxHitPoint > amount + this->_hitPoint)
	{
		this->_hitPoint += amount;
		std::cout << "Make my day." << std::endl;
	}
	else
	{
		this->_hitPoint = this->_maxHitPoint;
		std::cout << "Ya feeling lucky, punk?" << std::endl;
	}
}

void ClapTrap::status(void) const
{
	//print out status info
	std::cout << "----------Name: " << this->_name << "----------" <<std::endl;

	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Max Hit Point: " << this->_maxHitPoint << std::endl;
	std::cout << "Energy Point: " << this->_EnergyPoint << std::endl;
	std::cout << "Max Energy point: " << this->_maxEnergyPoint << std::endl;
	std::cout << "Level: " << this->_level << std::endl;
	
	std::cout << "Melee Attack Damage: " << this->_meleeAttackDamage << std::endl;
	std::cout << "Range Attack Damage: " << this->_rangeAttackDamage << std::endl;
	std::cout << "Armor: " << this->_armorDamageReduction << std::endl;
}
