#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ): Form("default RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ):
	Form(src.getName(), 72, 45)
{
	*this = src;
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ): Form(target, 72, 45){}

RobotomyRequestForm::~RobotomyRequestForm( void ) {}

RobotomyRequestForm &	RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int i = 0;

	if (getIsSigned() == true && executor.getGrade() <= getExecuteGrade())
	{
		system("afplay Drill.mp3 &");
		std::cout << "* Zhu Zuh uuuu zzz ...z... *" << std::endl;
		if (i % 2 == 0)
			std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
		else
			std::cout << executor.getName() << " has failed to be robotomized" << std::endl;
		i++;
	}
	else if (getIsSigned() == false)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > getExecuteGrade())
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & o, RobotomyRequestForm const & rhs )
{
	o << "RobotomyRequestForm: " << std::endl
		<< "Name: " << rhs.getName() << std::endl
		<< "Signed grade: " << rhs.getSignGrade() << std::endl
		<< "execute grade: " << rhs.getExecuteGrade() << std::endl;
	if (rhs.getIsSigned())
		o << "RobotomyRequestForm has been signed." << std::endl;
	else
		o << "RobotomyRequestForm has not yet been signed." << std::endl;
	return o;
}