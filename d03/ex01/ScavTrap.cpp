#include "ScavTrap.hpp"

//constructor & destructor-----------------------------------------
ScavTrap::ScavTrap(void) :
	_hitPoint(100),
	_EnergyPoint(50),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(50),
	_name(""),
	_meleeAttackDamage(20),
	_rangeAttackDamage(15),
	_armorDamageReduction(3)
{
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : 
	_hitPoint(100),
	_EnergyPoint(50),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(50),
	_name(""),
	_meleeAttackDamage(20),
	_rangeAttackDamage(15),
	_armorDamageReduction(3)
{
	*this = src;
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : 
	_hitPoint(100),
	_EnergyPoint(50),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(50),
	_name(name),
	_meleeAttackDamage(20),
	_rangeAttackDamage(15),
	_armorDamageReduction(3)
{
	std::cout << "ScavTrap launch! Look out everybody! Things are about to get awesome!" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
ScavTrap & ScavTrap::operator=(ScavTrap const &)
{
	return *this;
}

//methods------------------------------------------------------------------
void ScavTrap::rangedAttack(std::string const & target) const 
{
	std::cout << "SC4V-TP "<< this->_name;
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->_rangeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const & target) const
{
	std::cout << "SC4V-TP "<< this->_name;
	std::cout << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint < amount - this->_armorDamageReduction)
	{
		this->_hitPoint = 0;
		std::cout << "Is it dead? Can, can I open my eyes now?" << std::endl;
		return ;
	}
	std::cout << "Woah! Oh! Jeez!" << std::endl;
	this->_hitPoint -= (amount - this->_armorDamageReduction);
}

void ScavTrap::beRepaired(unsigned int amount)
{
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

void ScavTrap::status(void) const
{
	//print out status info
	std::cout << "Hit Point: " << this->_hitPoint << std::endl;
	std::cout << "Max Hit Point: " << this->_maxHitPoint << std::endl;
	std::cout << "Energy Point: " << this->_EnergyPoint << std::endl;
	std::cout << "Max Energy point: " << this->_maxEnergyPoint << std::endl;
	std::cout << "Level: " << this->_level << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Melee Attack Damage: " << this->_meleeAttackDamage << std::endl;
	std::cout << "Range Attack Damage: " << this->_rangeAttackDamage << std::endl;
	std::cout << "Armor: " << this->_armorDamageReduction << std::endl;
}

void ScavTrap::challengeNewcomer(std::string const & target)
{
	const int		chalNum = 5;
	int 			index;
	std::string		chals[] = {	"Kill Darksiders 0/20", 
								"Go to secret entrance", 
								"Kill RedBelly", 
								"Meet Jack in Concordia", 
								"Follow CU5TM-TP"};

	std::srand(time(NULL));
	index = std::rand() % chalNum;
	std::cout << "SC4V-TP "<< this->_name 
		<< " challange " << target 
		<< " with " << chals[index] << std::endl;
}
