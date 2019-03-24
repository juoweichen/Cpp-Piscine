#include "../includes/Player.class.hpp"

Player::Player(void)
{

}

Player::Player(Player const & src)
{
	*this = src;
}

Player::Player(unsigned int x, unsigned int y) : AGameObject(x, y)
{

}

Player::~Player(void)
{

}

Player & Player::operator=( Player const & rhs )
{
	if (this != &rhs)
	{

	}
	return *this;
}

void Player::move(std::string move)
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
