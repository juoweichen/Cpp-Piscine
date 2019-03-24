#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim {

	public:

		Victim(void);
		Victim(Victim const & src);
		Victim(std::string name);
		virtual ~Victim(void);

		Victim &	operator=( Victim const & rhs );
		std::string	getName(void) const;
		virtual void		getPolymorphed() const;

	protected:

		std::string	_name;


};

std::ostream &	operator<<( std::ostream & o, Victim const & rhs );

#endif