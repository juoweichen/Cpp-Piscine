#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class	RobotomyRequestForm : public Form
{
	public:

		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm const &src);
		virtual ~RobotomyRequestForm(void);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &r);

		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &o, RobotomyRequestForm const &r);

#endif