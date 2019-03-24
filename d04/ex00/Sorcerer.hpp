#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <string>
# include <iostream>

# include "Victim.hpp"

class Sorcerer
{
	public:
		Sorcerer(void);
		Sorcerer(Sorcerer const & src);
		Sorcerer(std::string name, std::string title);
		~Sorcerer(void);

		Sorcerer &	operator=( Sorcerer const & rhs );
		std::string	getName(void) const;
		std::string	getTitle(void) const;
		void 		polymorph(Victim const & src) const;

	private:
		std::string	_name;
		std::string _title;

};

std::ostream &	operator<<( std::ostream & o, Sorcerer const & rhs );

#endif