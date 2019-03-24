#ifndef ALIEN_HPP
# define ALIEN_HPP

#include "../includes/AGameObject.class.hpp"

class Alien : public AGameObject
{
	public: 
		Alien(void);
		Alien(Alien const & src);
		Alien(unsigned int x, unsigned int y);
		~Alien(void);

		Alien &	operator=(Alien const & rhs);

		void move(std::string move);
};

#endif