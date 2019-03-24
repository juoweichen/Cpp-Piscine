#ifndef BOMB_HPP
# define BOMB_HPP

#include "../includes/AGameObject.class.hpp"

class Bomb : public AGameObject
{
	public:
		Bomb(void);
		Bomb(Bomb const & src);
		Bomb(unsigned int x, unsigned int y);
		~Bomb(void);

		Bomb & operator=(Bomb const & rhs);

		void move(std::string move);

		void setIsFire(int isFire);
		int getIsFire(void);

	private:
		int 		_isfire;
};

#endif