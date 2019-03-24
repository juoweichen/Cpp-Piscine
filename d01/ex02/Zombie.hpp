#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	public:
		Zombie(std::string, std::string);
		~Zombie(void);
		std::string announce(void);

	private:
		std::string _type;
		std::string _name;
};

#endif