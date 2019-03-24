#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon: public Victim
{

	public:

		Peon(void);
		Peon(Peon const & src);
		Peon(std::string name);
		virtual ~Peon(void);

		Peon &	operator=( Peon const & rhs );
		virtual void	getPolymorphed(void) const;

	private:


};

std::ostream &	operator<<( std::ostream & o, Peon const & rhs );

#endif