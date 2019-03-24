#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{

	public:

		AssaultTerminator( void );
		AssaultTerminator( AssaultTerminator const & src );
		virtual ~AssaultTerminator( void );
		void				battleCry( void ) const;
		void				rangedAttack( void ) const;
		void				meleeAttack( void ) const;
		ISpaceMarine* 		clone( void ) const;

		AssaultTerminator&	operator=(AssaultTerminator const & rhs);
};

#endif