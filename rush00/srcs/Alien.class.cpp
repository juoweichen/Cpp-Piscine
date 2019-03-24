#include "../includes/Alien.class.hpp"

Alien::Alien(void)
{

}

Alien::Alien(Alien const & src)
{
	*this = src;
}

Alien::Alien(unsigned int x, unsigned int y) : AGameObject(x, y)
{

}

Alien::~Alien(void)
{

}

Alien & Alien::operator=( Alien const & rhs )
{
	if (this != &rhs)
	{

	}
	return *this;
}

void Alien::move(std::string move)
{
	int x = this->getX();
	int y = this->getY();

	if (move.compare("UP") == 0)
		this->setY(--y);
	else if (move.compare("DOWN") == 0)
		this->setY(++y);
	else if (move.compare("RIGHT") == 0)
		this->setX(++x);
	else if (move.compare("LEFT") == 0)
		this->setX(--x);
}