#include "Fixed.class.hpp"

/*----------Constructor and Destructor-----------------------*/
Fixed::Fixed( void ) : _FixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(i << this->_fractionalBits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(roundf(f * (1 << this->_fractionalBits)));
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

/*----------operator------------------------------------------*/
Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignment operator called" << std::endl;

	this->_FixedPointValue = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}

/*----------Class methodes-----------------------------------*/
int		Fixed::getRawBits( void ) const
{
	return this->_FixedPointValue;
}

void	Fixed::setRawBits( int const raw )
{
	this->_FixedPointValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->getRawBits() / (1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractionalBits);
}

/*----------Class attributes-----------------------------------*/
const int 	Fixed::_fractionalBits = 8;