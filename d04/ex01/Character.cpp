#include "Character.hpp"

Character::Character(void): _name(""), _AP(40), _weapon(NULL) {}

Character::Character(Character const & src): _name(src._name), _AP(src._AP), _weapon(src._weapon) {}

Character::Character(std::string const & name): _name(name), _AP(40), _weapon(NULL) {}

Character::~Character(void) {}

Character &	Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->_AP = rhs._AP;
		this->_weapon = rhs._weapon;
	}
	return *this;
}

void			Character::recoverAP(void)
{
	if (this->_AP + 10 > 40)
		this->_AP = 40;
	else
		this->_AP += 10;
}

void			Character::equip(AWeapon* weapon)
{
	this->_weapon = weapon;
}

void			Character::attack(Enemy* enemy)
{
	if (this->_AP >= this->_weapon->getAPCost())
	{
		this->_AP -= this->_weapon->getAPCost();
		enemy->takeDamage(this->_weapon->getDamage());
		std::cout << this->_name << " attacks " << enemy->getType()
				<< " with a " << this->_weapon->getName() << std::endl;
		this->_weapon->attack();
		if (enemy->getHP() == 0)
			delete enemy;
	}
}

std::string  const &	Character::getName(void) const
{
	return this->_name;
}

int				Character::getAP(void) const
{
	return this->_AP;
}

AWeapon *		Character::getWeapon(void) const
{
	return this->_weapon;
}

std::ostream &	operator<<( std::ostream & o, Character const & rhs )
{
	if (rhs.getWeapon())
		o << rhs.getName() << " has " << rhs.getAP() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
	else
		o << rhs.getName() << " has " << rhs.getAP() << " AP and is unarmed" << std::endl;
	return o;
}