#include "Fixed.class.hpp"

/*----------Constructor and Destructor-----------------------*/
Fixed::Fixed( void ) : _FixedPointValue(0)
{
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed::Fixed(const int i)
{
	this->setRawBits(i << this->_fractionalBits);
}

Fixed::Fixed(const float f)
{
	this->setRawBits(roundf(f * (1 << this->_fractionalBits)));
}

Fixed::~Fixed( void )
{
}

/*----------operator------------------------------------------*/
Fixed &	Fixed::operator=( Fixed const & rhs )
{
	this->_FixedPointValue = rhs.getRawBits();
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Fixed const & rhs )
{
	o << rhs.toFloat();
	return o;
}

/*----------comparison operator--------------------------------*/
bool	Fixed::operator>(const Fixed &rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

/*----------arithmetic operator--------------------------------*/
Fixed	Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

/*----------increment and decrement operator--------------------*/
// pre-increment
Fixed	&Fixed::operator++(void)
{
    this->_FixedPointValue += 1;
    return (*this);
}

// pre-decrement
Fixed	&Fixed::operator--(void)
{
    this->_FixedPointValue -= 1;
    return (*this);
}

//post-increment
Fixed	Fixed::operator++(int)
{
    Fixed tmp;

	tmp = (*this);
    this->operator++();
    return (tmp);
}

// post-decrement
Fixed	Fixed::operator--(int)
{
	Fixed tmp;

	tmp = (*this);
    this->operator--();
    return (tmp);
}

/*------------------methodes-----------------------------------*/
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

/*------------------max & min methodes-------------------------*/
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b ? a : b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b ? a : b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b ? a : b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b ? a : b);
}

/*----------------attributes-----------------------------------*/
const int 	Fixed::_fractionalBits = 8;