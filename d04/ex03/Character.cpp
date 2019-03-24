#include "Character.hpp"

Character::Character(void): _name("")
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(std::string name): _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = NULL;
}

Character::Character(Character const & cpy)
{
	*this = cpy;
}

Character::~Character(void)
{
	//delete [] this->_inv;
}

Character & Character::operator=(Character const & rhs)
{
	this->_inv[0] = rhs._inv[0];
	this->_inv[1] = rhs._inv[1];
	this->_inv[2] = rhs._inv[2];
	this->_inv[3] = rhs._inv[3];
	return (*this);
}

std::string const 	&	Character::getName(void) const
{
	return this->_name;
}

void 					Character::equip(AMateria* m)
{
	int	put;

	put = 0;
	for (int i = 0; i < 4; i++)
	{
		if (put == 0 && this->_inv[i] == NULL)
		{
			this->_inv[i] = m;
			put++;
		}
	}
	if (put == 0)
		std::cout << "Inventory full." << std::endl;
}

void 					Character::unequip(int idx)
{
	if (this->_inv[idx] == NULL)
		std::cout << "inventory empty." << std::endl;
	else
		this->_inv[idx] = NULL;
}

void 					Character::use(int idx, ICharacter& target)
{
	if (this->_inv[idx] == NULL || idx < 0 || idx > 3)
	{
		std::cout << "no materia in this slot." << std::endl;
		(void)target;
	}
	else
	{
		this->_inv[idx]->use(target);
		this->_inv[idx] = NULL;
	}
}