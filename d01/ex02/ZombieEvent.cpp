#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
    return ;
}

ZombieEvent::~ZombieEvent(void) {
    return ;
}

void ZombieEvent::setZombieType(std::string type) {
    this->_type = type;
    return ;
}

std::string ZombieEvent::getZombieType(void) {
    return (this->_type);
}

Zombie *ZombieEvent::newZombie(std::string name) {
    return (new Zombie(this->_type, name));
}

Zombie *ZombieEvent::randomChump(void) {
    int     index;
    int     names_nbr;
    Zombie  *zombie;
    std::string names[] = {"Kim", "Liam", "Hazuki", "Abaraham", "Byran", "Duojee"};

    if (this->_type == "")
        this->setZombieType("Rotten Face");
	std::srand(time(NULL));
    names_nbr = 6;
    index = std::rand() % names_nbr;
    zombie = this->newZombie(names[index]);
    return (zombie);
}