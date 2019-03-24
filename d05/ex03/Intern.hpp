#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class	Intern
{
	public:

		Intern( void );
		Intern( Intern const &src );
		virtual ~Intern( void );
		Intern &operator=( Intern const &rhs );

		Form	*makeForm( std::string form, std::string target );
};

#endif