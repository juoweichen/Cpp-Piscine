#include "Form.hpp"

Form::Form(void) : _name("uselessPaper"), _isSigned(0), _signGrade(150), _executeGrade(150) { }
Form::Form(Form const & src) :
	_name("uselessPaper"), _isSigned(0), _signGrade(150), _executeGrade(150) { *this = src; }

Form::Form(std::string name, unsigned int signGrade, unsigned int executeGrade) :
	_name(name), _isSigned(0), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form(void) { }

void		Form::beSigned(Bureaucrat & person)
{
	if (person.getGrade() > _signGrade)
	{
		std::cout << person.getName() << " cannot sign " << _name << " becuase ";
		throw Form::GradeTooLowException();
	}
	else
	{
		if (this->_isSigned)
		{
			std::cout << person.getName() << " cannot sign " << _name
			<< " because Form already signed" << std::endl;
		}
		else
		{
			std::cout << person.getName() << " signs " << _name << std::endl;
			signForm();
		}
	}
}

void		Form::signForm( void )
{
	this->_isSigned = true;
}

Form & Form::operator=(Form const & rhs)
{
	if ( this != &rhs )
		this->_isSigned = rhs._isSigned;
	return *this;
}

std::string Form::getName(void) const { return (this->_name); }
bool Form::getIsSign(void) const { return (this->_isSigned); }
unsigned int Form::getSignGrade(void) const { return (this->_signGrade); }
unsigned int Form::getExecuteGrade(void) const { return (this->_executeGrade); }


//exception class---------------------------------------------------------------------------
Form::GradeTooHighException::GradeTooHighException( void ) {}
Form::GradeTooHighException::GradeTooHighException( GradeTooHighException const & src ) { *this = src; }
Form::GradeTooHighException::~GradeTooHighException( void ) throw() {}

Form::GradeTooHighException &	Form::GradeTooHighException::operator=( GradeTooHighException const & src)
{
	(void)src;
	return *this;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Error: Form grade is too high");
}

Form::GradeTooLowException::GradeTooLowException( void ) {}
Form::GradeTooLowException::GradeTooLowException( GradeTooLowException const & src ) { *this = src; }
Form::GradeTooLowException::~GradeTooLowException( void ) throw() {}

Form::GradeTooLowException &	Form::GradeTooLowException::operator=( GradeTooLowException const & src)
{
	(void)src;
	return *this;
}

const char*	Form::GradeTooLowException::what() const throw() 
{
	return ("Error: Form grade is too low");
}