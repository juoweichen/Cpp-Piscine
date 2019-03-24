#include "../includes/Bomb.class.hpp"

Bomb::Bomb(void)
{

}

Bomb::Bomb(Bomb const & src)
{
	*this = src;
}

Bomb::Bomb(unsigned int x, unsigned int y) : AGameObject(x, y)
{

}

Bomb::~Bomb(void)
{

}

Bomb & Bomb::operator=( Bomb const & rhs )
{
	if ( this != &rhs )
	{
		
	}
	return *this;
}

void Bomb::move(std::string move)
{
	int y = this->getY();

	(void)move;
	if (this->_isfire == 1)
		this->setY(++y);
}

void Bomb::setIsFire(int isFire)
{
	this->_isfire = isFire;
}

int Bomb::getIsFire(void)
{
	return this->_isfire;
}
