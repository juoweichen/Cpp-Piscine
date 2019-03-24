#ifndef ENNEMY_HPP
 #define ENNEMY_HPP

# include <string>
# include <iostream>

# include "AWeapon.hpp"

class Enemy
{
	public:
		Enemy(void);
		Enemy(Enemy const &);
		Enemy(int hp, std::string const & type);
		virtual ~Enemy(void);

		Enemy &					operator=(Enemy const &);

		int 					getHP(void) const;
		std::string const &		getType(void) const;
		virtual void 			takeDamage(int);
		
	private:
		int					_HP;
		std::string const	_type;
		
};

std::ostream &	operator<<( std::ostream & o, AWeapon const & rhs );

#endif