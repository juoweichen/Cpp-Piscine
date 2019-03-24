#include "Zombie.hpp"

Zombie::Zombie(std::string t, std::string n): _type(t), _name(n) {
	std::cout << "Zombie " << this->_name << " has awake, run for your life!" << std::endl;
    return ;
}
Zombie::~Zombie(void) {
	std::cout << "Zombie " << this->_name << " has finally dead, again" << std::endl;
    return ;
}

std::string Zombie::announce(void) {
    std::string format;
    std::string message;

    format = "<" + this->_name + " (" + this->_type + ")> ";
    message = "Braiiiiiiinnnssss...";
    return (format + message);
}