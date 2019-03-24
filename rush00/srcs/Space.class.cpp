#include "../includes/Space.class.hpp"

Space::Space(void)
{

}

Space::Space(Space const & src)
{
	*this = src;
}

Space::~Space(void)
{

}

Space & Space::operator=( Space const & rhs )
{
	if ( this != &rhs )
	{
		this->_space = rhs._space;
	}
	return *this;
}

void Space::createSpace(void)
{
	this->_space = new int*[this->getSizeY() + 1];
		
	for(int i = 0; i < this->getSizeY() + 1; ++i)
	{
    	this->_space[i] = new int[this->getSizeX() + 1];
		for (int j = 0; j < this->getSizeX() + 1; j++)
			this->_space[i][j] = 0;
	}
}

void Space::updateSpace(Player & player, Projectile **mag, Alien **alienHorbe)
{
	this->_space[player.getY() - 1][player.getX() - 1] |= PLAYER;

	for (int i = 0; i < AMMO; i++)
		this->_space[mag[i]->getY() - 1][mag[i]->getX() - 1] |= PORJ;

	for (int i = 0; i < HORBE_NUMBER; i++)
		this->_space[alienHorbe[i]->getY() - 1][alienHorbe[i]->getX() - 1] |= ALIEN;
}

void Space::detectCollision(Player & player, Projectile **mag, Alien **alienHorbe)
{
	for (int i = 0; i < this->getSizeY(); i++)
	{
		for (int j = 0; j < this->getSizeX(); j++)
		{
			if (this->_space[i][j] > 4)
			{			
				if (player.getX() - 1 == j && player.getY() - 1 == i)
					player.setAlive(0);

				for (int l = 0; l < AMMO; l++)
					if (mag[l]->getX() - 1 == j && mag[l]->getY() - 1 == i)
						mag[l]->setAlive(0);

				for (int k = 0; k < HORBE_NUMBER; k++)
					if (alienHorbe[k]->getX() - 1 == j && alienHorbe[k]->getY() - 1 == i)
						alienHorbe[k]->setAlive(0);	
			}
			this->_space[i][j] = 0;
		}
	}
}
