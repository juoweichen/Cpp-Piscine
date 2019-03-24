#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("dumpAndFatBureaucrat"), _grade(150) { }
Bureaucrat::Bureaucrat(Bureaucrat const & src) { *this = src; }

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void) { }

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if ( this != &rhs )
	{
		this->_grade = rhs.getGrade();
	}
	return *this;
}

std::string Bureaucrat::getName(void) const { return (this->_name); }
unsigned int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::incrementGrade(unsigned int amount)
{
	if (this->_grade - amount <= 0)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= amount;
}

void Bureaucrat::decrementGrade(unsigned int amount)
{	
	if (this->_grade + amount > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += amount;
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}

//exception class---------------------------------------------------------------------------
Bureaucrat::GradeTooHighException::GradeTooHighException( void ) {}
Bureaucrat::GradeTooHighException::GradeTooHighException( GradeTooHighException const & src ) { *this = src; }
Bureaucrat::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Bureaucrat::GradeTooHighException &	Bureaucrat::GradeTooHighException::operator=( GradeTooHighException const & src)
{
	(void)src;
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Bureaucrat grade is too high");
}

Bureaucrat::GradeTooLowException::GradeTooLowException( void ) {}
Bureaucrat::GradeTooLowException::GradeTooLowException( GradeTooLowException const & src ) { *this = src; }
Bureaucrat::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Bureaucrat::GradeTooLowException &	Bureaucrat::GradeTooLowException::operator=( GradeTooLowException const & src)
{
	(void)src;
	return *this;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() 
{
	return ("Error: Bureaucrat grade is too low");
}