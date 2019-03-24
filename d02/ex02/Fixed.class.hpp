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
		Fixed &	operator=( const Fixed  & rhs );

		// comparision operator
		bool	operator>( const Fixed  & rhs ) const ;
		bool	operator<( const Fixed  & rhs ) const ;
		bool	operator>=( const Fixed  & rhs ) const ;
		bool	operator<=( const Fixed  & rhs ) const ;
		bool	operator==( const Fixed  & rhs ) const ;
		bool	operator!=( const Fixed  & rhs ) const ;
		
		// arithmetic operator
		Fixed	operator+( const Fixed  & rhs ) const;
		Fixed	operator-( const Fixed  & rhs ) const;
		Fixed	operator*( const Fixed  & rhs ) const;
		Fixed	operator/( const Fixed  & rhs ) const;
		
		// increment & decrement
		Fixed &	operator++( void );
		Fixed &	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		//methods
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

		//max & min
		static Fixed	&min( Fixed & a, Fixed & b );
		static const Fixed	&min( const Fixed & a, const Fixed & b );
		static Fixed	&max( Fixed & a, Fixed & b );
		static const Fixed	&max( const Fixed & a, const Fixed & b );

	private:

		int	_FixedPointValue;
		static const int _fractionalBits;
};

std::ostream &	operator<<( std::ostream & o, Fixed const & i );

#endif