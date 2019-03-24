#ifndef SPACE_HPP
# define SPACE_HPP

#include "../includes/GameMaster.class.hpp"
#include "../includes/Projectile.class.hpp"
#include "../includes/Player.class.hpp"
#include "../includes/Alien.class.hpp"

enum objectType
{
	PLAYER = 1, 
	PORJ = 2,
	PLAYER_PROJ = 3,
	ALIEN = 4,
	PLAYER_ALIEN = 5,
	ALIEN_PORJ = 6,
	ALL = 7
};

class Space : public GameMaster
{
	public:
		Space(void);
		Space(Space const & src);
		~Space(void);

		Space & operator=(Space const & rhs);

		void createSpace(void);
		void updateSpace(Player & player, Projectile **mag, Alien **alienHorbe);
		void detectCollision(Player & player, Projectile **mag, Alien **alienHorbe);

	private:
		int		**_space;
};

#endif