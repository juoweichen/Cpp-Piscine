#ifndef SQUAD_HPP
# define SQUAD_HPP

# include "ISpaceMarine.hpp"
# include <iostream>
# include "ISquad.hpp"

class Squad : public ISquad
{
	typedef struct		s_mlist
	{
		ISpaceMarine	*instance;
		s_mlist			*next;
	}					t_mlist;
	public:

		Squad( void );
		Squad( Squad const & src );
		virtual ~Squad( void );

		Squad& operator=(Squad const & rhs);

		int				getCount() const;
		ISpaceMarine*	getUnit( int index ) const;
		int				push( ISpaceMarine* sm );

	private:
		int		_nb_unit;
		t_mlist	*_mlist;
};

#endif