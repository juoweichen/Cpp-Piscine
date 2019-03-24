#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>

#include "Form.hpp"

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat(std::string name, unsigned int grade);
		~Bureaucrat(void);

		Bureaucrat & operator=(Bureaucrat const & rhs);

		std::string getName(void) const;
		unsigned int getGrade(void) const;

		void incrementGrade(unsigned int amount);
		void decrementGrade(unsigned int amount);

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
		std::string const _name;
		unsigned int _grade;
};

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );

#endif