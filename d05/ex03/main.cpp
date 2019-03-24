#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Intern Alen;

		Form *form1 = Alen.makeForm("shrubbery creation", "shrubbery happy");
		if (!form1)
		{
			std::cout << "Form not found! quit" << std::endl;
			return 0;
		}
		std::cout << form1->getName() << std::endl;

		Form *form2 = Alen.makeForm("No such form", "shrubbery happy");
		if (!form2)
		{
			std::cout << "Form not found! quit" << std::endl;
			return 0;
		}
		std::cout << form2->getName() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (ShrubberyCreationForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (RobotomyRequestForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (PresidentialPardonForm::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}