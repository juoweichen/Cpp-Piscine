#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class	PresidentialPardonForm : public Form
{
	public:

		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		virtual ~PresidentialPardonForm(void);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &r);

		virtual void	execute(Bureaucrat const &executor) const;
};

std::ostream	&operator<<(std::ostream &o, PresidentialPardonForm const &r);

#endif