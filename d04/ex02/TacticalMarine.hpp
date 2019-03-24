#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
	public:

		TacticalMarine( void );
		TacticalMarine( TacticalMarine const & src );
		virtual ~TacticalMarine( void );
		void			battleCry( void ) const;
		void			rangedAttack( void ) const;
		void			meleeAttack( void ) const;
		ISpaceMarine*	clone( void ) const;

		TacticalMarine& operator=(TacticalMarine const & rhs);
};

#endif