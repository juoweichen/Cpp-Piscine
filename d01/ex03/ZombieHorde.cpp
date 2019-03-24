#include "Zombie.hpp"
#include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n): _N(n)
{
    this->_horde = new Zombie[n];

    for (int i = 0; i < this->_N; i += 1)
    {
        this->_horde[i].setType("Horde");
        this->_horde[i].setName(this->randomChump());
    }
    return ;
}

ZombieHorde::ZombieHorde(void)
{
    return ;
}

ZombieHorde::~ZombieHorde(void)
{
    return ;
}

void ZombieHorde::announce(void)
{
	
}

void ZombieHorde::createHorde(void)
{

}
