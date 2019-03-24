#include "Intern.hpp"

Intern::Intern( void ) {}
Intern::Intern( Intern const &src ) { *this = src; }
Intern::~Intern( void ) {}
Intern &Intern::operator=( Intern const & rhs ) { (void)rhs; return *this; }

Form	*Intern::makeForm( std::string form, std::string target )
{
	if (form == "ShrubberyCreation" || form == "shrubbery creation")
	{
		std::cout << "Intern creates " << form  << " form" << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (form == "RobotomyRequest" || form == "robotomy request")
	{
		std::cout << "Intern creates " << form  << " form" << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (form == "PresidentialPardon" || form == "presidential pardon")
	{
		std::cout << "Intern creates " << form  << " form" << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << "Intern failed to create " << form << " form" << std::endl;
		std::cout << "-> form not found!" << std::endl;
		return NULL;
	}
}