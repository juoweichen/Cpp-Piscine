#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <iostream>

class Character: public ICharacter
{
	public:

		Character(void);
		Character(std::string name);
		Character(Character const & cpy);
		virtual ~Character(void);
		Character &	operator=(Character const & rhs);

		std::string const &	getName(void) const;
		virtual void		equip(AMateria* m);
		virtual void		unequip(int idx);
		virtual void		use(int idx, ICharacter& target);

	private:

		std::string 	_name;
		AMateria*		_inv[4];

};

#endif