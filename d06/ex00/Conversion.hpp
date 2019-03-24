#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <string>
#include <iostream>
#include <exception>
#include <iomanip>

class Conversion
{
	public:
		Conversion(void);
		Conversion(Conversion & src);
		Conversion(std::string input);
		virtual ~Conversion(void);

		Conversion & operator=(Conversion const & rhs);

		operator char(void) const;
		operator int(void) const;
		operator float(void) const;
		operator double(void) const;

		class ConversionErrorException : public std::exception
		{
			public:
				ConversionErrorException(void);
				ConversionErrorException(ConversionErrorException const & src);
				virtual ~ConversionErrorException(void) throw();
				ConversionErrorException & operator=(ConversionErrorException const & rhs);
				virtual const char* what() const throw();
		};

	private:
		std::string _input;
};

#endif