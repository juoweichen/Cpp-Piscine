#include "ScavTrap.hpp"

//constructor & destructor-----------------------------------------
ScavTrap::ScavTrap(void)
{
	this->_hitPoint = 100;
	this->_EnergyPoint = 50;
	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangeAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src)
{
	*this = src;
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoint = 100;
	this->_EnergyPoint = 50;
	this->_maxHitPoint = 100;
	this->_maxEnergyPoint = 50;
	this->_level = 1;
	this->_meleeAttackDamage = 20;
	this->_rangeAttackDamage = 15;
	this->_armorDamageReduction = 3;
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
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
void ScavTrap::challengeNewcomer(std::string const & target)
{
	const int		chalNum = 5;
	int 			index;
	std::string		chals[] = {	"Kill Darksiders 0/20", 
								"Go to secret entrance", 
								"Kill RedBelly", 
								"Meet Jack in Concordia", 
								"Follow CU5TM-TP"};

	if (this->_hitPoint == 0)
	{
		std::cout << "Your TP robot " << this->_name << " died long time ago..." << std::endl;
		return ;
	}
	std::srand(time(NULL));
	index = std::rand() % chalNum;
	std::cout << "SC4V-TP "<< this->_name 
		<< " challange " << target 
		<< " with [" << chals[index] << "]" << std::endl;
}
