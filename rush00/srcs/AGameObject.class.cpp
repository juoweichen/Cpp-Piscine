#include "../includes/AGameObject.class.hpp"

AGameObject::AGameObject(void)
{

}

AGameObject::AGameObject(AGameObject const & src)
{
	*this = src;
}

AGameObject::AGameObject(unsigned int x, unsigned int y) : _x(x), _y(y)
{

}

AGameObject::~AGameObject(void)
{

}

AGameObject & AGameObject::operator=( AGameObject const & rhs )
{
	if ( this != &rhs )
	{
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return *this;
}

void AGameObject::setX(int x)
{
	this->_x = x;
}

int AGameObject::getX(void)
{
	return this->_x;
}

void AGameObject::setY(int y)
{
	this->_y = y;
}

int AGameObject::getY(void)
{
	return this->_y;
}

void AGameObject::setAlive(int alive)
{
	this->_isAlive = alive;
}

int AGameObject::getAlive(void)
{
	return this->_isAlive;
}
