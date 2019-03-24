#include "FragTrap.hpp"

//constructor & destructor-----------------------------------------
FragTrap::FragTrap(void) :
	_hitPoint(100),
	_EnergyPoint(100),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(100),
	_name(""),
	_meleeAttackDamage(30),
	_rangeAttackDamage(20),
	_armorDamageReduction(5)
{
	std::cout << "FragTrap launch!" << std::endl;
	std::cout << "Let's get this party started!" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : 
	_hitPoint(100),
	_EnergyPoint(100),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(100),
	_name(src._name),
	_meleeAttackDamage(30),
	_rangeAttackDamage(20),
	_armorDamageReduction(5)
{
	*this = src;
	std::cout << "FragTrap launch! Let's get this party started!" << std::endl;
}

FragTrap::FragTrap(std::string name) : 
	_hitPoint(100),
	_EnergyPoint(100),
	_level(1),
	_maxHitPoint(100),
	_maxEnergyPoint(100),
	_name(name),
	_meleeAttackDamage(30),
	_rangeAttackDamage(20),
	_armorDamageReduction(5)
{
	std::cout << "FragTrap launch! Let's get this party started!" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

//operators------------------------------------------------------------------
FragTrap & FragTrap::operator=(FragTrap const &)
{
	std::cout << "Assignment operator calleds" << std::endl;
	return *this;
}

//methods------------------------------------------------------------------
void FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP "<< this->_name;
	std::cout << " attacks " << target;
	std::cout << " at range, causing " << this->_rangeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP "<< this->_name;
	std::cout << " attacks " << target;
	std::cout << " with melee, causing " << this->_meleeAttackDamage;
	std::cout << " points of damage !" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
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

void FragTrap::beRepaired(unsigned int amount)
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

void FragTrap::status(void)
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

	if (this->_EnergyPoint > energyCost)
	{
		std::srand(time(NULL));
    	index = std::rand() % skillsNum;
		std::cout << "FR4G-TP "<< this->_name 
			<< " attacks " << target 
			<< " by [" << skills[index]
			<< "], causing " << (index + 1) * skillDamageBase
			<< " points of damage !" << std::endl;
		return ;
	}
	std::cout << "out of energy";
}
