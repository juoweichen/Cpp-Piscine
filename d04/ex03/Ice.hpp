#ifndef ICE_HPP
# define ICE_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const & cpy);
		virtual ~Ice(void);
		Ice &	operator=(Ice const & rhs);

		Ice	*		clone(void) const;
		void		use(ICharacter& target);
};

#endif