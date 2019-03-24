#include "Conversion.hpp"

Conversion::Conversion( void ) {}
Conversion::Conversion( std::string input ): _input(input) {}
Conversion::Conversion( Conversion &src ): _input(src._input) { *this = src; }
Conversion::~Conversion( void ) {}

Conversion	&Conversion::operator=( Conversion const &rhs)
{
	_input = rhs._input;
	return *this;
}

Conversion::operator	char( void ) const
{
	int	result = 0;

	try
	{
		result = std::stoi(_input);
		return (static_cast<char>(result));
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
}

Conversion::operator	int( void ) const
{
	int	result = 0;

	try
	{
		result = std::stoi(_input);
		return (result);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
}

Conversion::operator	float( void ) const
{
	float result = 0.0;

	try
	{
		result = std::stof(_input);
		return (result);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
}

Conversion::operator	double( void ) const
{
	double	result = 0.0;

	try
	{
		result = std::stod(_input);
		return (result);
	}
	catch (const std::exception &e)
	{
		throw (ConversionErrorException());
	}
}

Conversion::ConversionErrorException::ConversionErrorException( void ) {}
Conversion::ConversionErrorException::ConversionErrorException( ConversionErrorException const &src ) { *this = src;}
Conversion::ConversionErrorException::~ConversionErrorException( void ) throw() {}
Conversion::ConversionErrorException &Conversion::ConversionErrorException::operator=( ConversionErrorException const &rhs ) { (void)rhs; return *this; }

const char* Conversion::ConversionErrorException::what() const throw() {
	return "impossible";
}