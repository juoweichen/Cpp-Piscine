#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "../includes/AGameObject.class.hpp"

class Projectile : public AGameObject
{
	public:
		Projectile(void);
		Projectile(Projectile const & src);
		Projectile(unsigned int x, unsigned int y);
		~Projectile(void);

		Projectile & operator=(Projectile const & rhs);

		void move(std::string move);

		void setIsFire(int isFire);
		int getIsFire(void);

	private:
		int 		_isfire;
};

#endif