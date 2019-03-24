#ifndef PONY_HPP
# define PONY_HPP

#include <iostream>

class Pony {
	public:
		char *ponyName;
		int isAppleLover;
		int isCupcakeLover;

		Pony(char *ponyName, int a, int c);
		~Pony(void);
};

#endif

