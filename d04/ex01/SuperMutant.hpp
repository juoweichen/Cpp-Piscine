#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

# include "Enemy.hpp"
# include <iostream>

class SuperMutant: public Enemy
{
	public:

		SuperMutant(void);
		SuperMutant(const SuperMutant &src);
		virtual ~SuperMutant(void);

		SuperMutant &		operator=(SuperMutant const & rhs);

		virtual void		takeDamage(int damage);

};

#endif