#include "../includes/Projectile.class.hpp"

Projectile::Projectile(void)
{

}

Projectile::Projectile(Projectile const & src)
{
	*this = src;
}

Projectile::Projectile(unsigned int x, unsigned int y) : AGameObject(x, y)
{

}

Projectile::~Projectile(void)
{

}

Projectile & Projectile::operator=( Projectile const & rhs )
{
	if ( this != &rhs )
	{
		
	}
	return *this;
}

void Projectile::move(std::string move)
{
	int y = this->getY();

	(void)move;
	if (this->_isfire == 1)
		this->setY(--y);
}

void Projectile::setIsFire(int isFire)
{
	this->_isfire = isFire;
}

int Projectile::getIsFire(void)
{
	return this->_isfire;
}
