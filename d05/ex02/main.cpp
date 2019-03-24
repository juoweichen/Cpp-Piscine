#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat person1("Juo", 30);
		Bureaucrat person2("Jack", 3);

		ShrubberyCreationForm form1 = ShrubberyCreationForm("Mr.Chen's yard");
		RobotomyRequestForm form2 = RobotomyRequestForm("Mr.Wong's request");
		PresidentialPardonForm form3 = PresidentialPardonForm("Obama's pardon");

		form1.beSigned(person1);
		form1.execute(person1);

		form2.beSigned(person1);
		form2.execute(person1);

		form3.beSigned(person2);
		form3.execute(person2);

		//will fail
		form3.beSigned(person1);
		form3.execute(person1);
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