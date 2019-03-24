#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ): Form("default PresidentialPardonForm", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ):
	Form(src.getName(), 25, 5)
{
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ): Form(target, 25, 5){}

PresidentialPardonForm::~PresidentialPardonForm( void ) {}

PresidentialPardonForm &	PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	(void)rhs;
	return *this;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == true && executor.getGrade() <= getExecuteGrade())
	{
		std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
	}
	else if (getIsSigned() == false)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > getExecuteGrade())
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & o, PresidentialPardonForm const & rhs )
{
	o << "PresidentialPardonForm: " << std::endl
		<< "Name: " << rhs.getName() << std::endl
		<< "Signed grade: " << rhs.getSignGrade() << std::endl
		<< "execute grade: " << rhs.getExecuteGrade() << std::endl;
	if (rhs.getIsSigned())
		o << "PresidentialPardonForm has been signed." << std::endl;
	else
		o << "PresidentialPardonForm has not yet been signed." << std::endl;
	return o;
}