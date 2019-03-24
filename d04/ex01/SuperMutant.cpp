#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src): Enemy(src)
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(void)
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant &	SuperMutant::operator=( SuperMutant const & rhs )
{
	Enemy::operator=(rhs);
	return *this;
}

void 		SuperMutant::takeDamage(int damage)
{
	return Enemy::takeDamage(damage - 3);
}