#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>
# include <cmath>

class Fixed {

	public:
		//Constructro and destructor
		Fixed( void );						
		Fixed( Fixed const & src );	
		Fixed( const int i );
		Fixed( const float f );
		~Fixed( void );						

		//operator
		Fixed &	operator=( Fixed const & rhs );
		
		//methods
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		//attributes
		int	_FixedPointValue;
		static const int _fractionalBits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif