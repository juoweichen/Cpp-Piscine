#include "Pony.hpp"

Pony *ponyOnTheHeap(char *name, int a, int c) {
	Pony *pony = new Pony(name, a, c);
	return pony;
}

Pony ponyOnTheStack(char *name, int a, int c) {
	Pony pony = Pony(name, a, c);
	return pony;
}

int main(void) {

	Pony *appleJack = ponyOnTheHeap((char *)"applejack", 1, 0);
	Pony pinkyPie = ponyOnTheStack((char *)"pinkypie", 0, 1);

	std::cout << "Your pony: " << appleJack->ponyName << std::endl;
	std::cout << "\tis apple lover? " << (appleJack->isAppleLover == 1? "Yes!" : "Nope..") << std::endl;
	std::cout << "\tis cupcake lover? " << (appleJack->isCupcakeLover == 1? "Yes!" : "Nope..") << std::endl;
	
	std::cout << "Your pony: " << pinkyPie.ponyName << std::endl;
	std::cout << "\tis apple lover? " << (pinkyPie.isAppleLover == 1? "Yes!" : "Nope..") << std::endl;
	std::cout << "\tis cupcake lover? " << (pinkyPie.isCupcakeLover == 1? "Yes!" : "Nope..") << std::endl;
	
	delete appleJack;

	return (0);
}
