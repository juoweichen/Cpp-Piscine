#include "Pony.hpp"

Pony::Pony(char *name, int a, int c) {
	std::cout << "Your pony was born :D" << std::endl;
	this->ponyName = name;
	this->isAppleLover = a;
	this->isCupcakeLover = c;
}

Pony::~Pony(void) {
	std::cout << "Your pony just died :(" << std::endl;
}