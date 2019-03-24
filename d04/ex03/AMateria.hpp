#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	private:

		std::string		type_;
		unsigned int 	xp_;

	public:

		AMateria(void);
		AMateria(std::string const & type);
		AMateria(AMateria const & cpy);
		virtual ~AMateria(void);

		AMateria &	operator=(AMateria const & rhs);

		std::string const &	getType(void) const;
		unsigned int		getXP(void) const;
		void				setXP(void);

		virtual AMateria*	clone(void) const = 0;
		virtual void		use(ICharacter& target);
};

#endif