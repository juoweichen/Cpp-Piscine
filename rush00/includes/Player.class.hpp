#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "../includes/AGameObject.class.hpp"

class Player : public AGameObject
{
	public: 
		Player(void);
		Player(Player const & src);
		Player(unsigned int x, unsigned int y);
		~Player(void);

		Player &	operator=(Player const & rhs);

		void move(std::string move);
		void init(void);
};

#endif