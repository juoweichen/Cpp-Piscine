#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"

class RadScorpion: public Enemy
{
	public:

		RadScorpion(void);
		RadScorpion(const RadScorpion &src);
		virtual ~RadScorpion(void);

		RadScorpion &		operator=(RadScorpion const & rhs);
};

#endif