#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(Form const & src);
		Form(std::string name, unsigned int signGradeunsigned, unsigned int executeGrade);
		~Form(void);

		Form & operator=(Form const & rhs);

		std::string getName(void) const;
		bool getIsSigned(void) const;
		unsigned int getSignGrade(void) const;
		unsigned int getExecuteGrade(void) const;

		void beSigned(Bureaucrat & person);
		void signForm(void);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException( void );
				GradeTooHighException(GradeTooHighException const &);
				~GradeTooHighException( void ) throw();
				GradeTooHighException &	operator=(GradeTooHighException const &);
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException(GradeTooLowException const &);
				~GradeTooLowException() throw();
				GradeTooLowException &	operator=(GradeTooLowException const &);
				virtual const char* what() const throw();
		};

	private:
		std::string const 	_name;
		bool				_isSigned;
		unsigned int const 	_signGrade;
		unsigned int const 	_executeGrade;
};

std::ostream &	operator<<( std::ostream & o, Form const & rhs );

#endif