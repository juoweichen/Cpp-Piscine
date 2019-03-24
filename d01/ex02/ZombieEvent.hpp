#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include <string>
# include <cstdlib>
# include <time.h>
# include <iostream>
# include <unistd.h>
# include "Zombie.hpp"

class ZombieEvent {
	public:
		ZombieEvent(void);
		~ZombieEvent(void);
		void        setZombieType(std::string);
		std::string getZombieType(void);
		Zombie      *newZombie(std::string);
		Zombie      *randomChump(void);

	private:
		std::string  _type;
};

#endif