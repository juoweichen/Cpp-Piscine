#ifndef CURE_HPP
# define CURE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(Cure const & cpy);
		virtual ~Cure(void);
		Cure &	operator=(Cure const & rhs);

		Cure*		clone(void) const;
		void		use(ICharacter& target);
};

#endif