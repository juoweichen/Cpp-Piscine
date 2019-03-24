#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int main(void)
{
	Zombie *zombie1;
	Zombie *zombie2;
	ZombieEvent event;

	event.setZombieType("sleeper");
	zombie1 = event.randomChump();
	std::cout << zombie1->announce() << std::endl << std::endl;
	
	usleep(1000000);

	event.setZombieType("eater");
	zombie2 = event.randomChump();
	std::cout << zombie2->announce() << std::endl << std::endl;

	delete zombie1;
	delete zombie2;

    return (0);
}