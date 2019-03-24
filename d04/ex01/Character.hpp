#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
	public:

		Character();
		Character(Character const &);
		Character(std::string const & name);
		~Character();

		Character & operator=(Character const &);

		void				recoverAP();
		void				equip(AWeapon*);
		void				attack(Enemy*);
		std::string const &	getName(void) const;
		int					getAP(void) const ;
		AWeapon *			getWeapon(void) const ;

	private:

		std::string 		_name;
		int					_AP;
		AWeapon	*			_weapon;
};

std::ostream & operator<<(std::ostream & o, Character const & src);

#endif