#include "Enemy.hpp"

Enemy::Enemy(void): _HP(0), _type("") {}

Enemy::Enemy(Enemy const & src): _HP(src._HP), _type(src._type) {}

Enemy::Enemy(int hp, std::string const & type): _HP(hp), _type(type) {}

Enemy::~Enemy(void) {}

Enemy &	Enemy::operator=( Enemy const & rhs )
{
	if ( this != &rhs )
	{
		this->_HP = rhs._HP;
	}
	return *this;
}

std::string	const & Enemy::getType(void) const
{
	return this->_type;
}

int					Enemy::getHP(void) const
{
	return this->_HP;
}

void				Enemy::takeDamage(int damage)
{
	if (this->_HP > 0 && damage > 0)
	{
		if (this->_HP - damage < 0)
			this->_HP = 0;
		else
			this->_HP -= damage;
	}
}

std::ostream &	operator<<( std::ostream & o, Enemy const & rhs )
{
	o << "I'm [Enemy Class] , HP: " << rhs.getHP() << ", type: " << rhs.getType() << std::endl;
	return o;
}