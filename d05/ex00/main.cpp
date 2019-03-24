#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat dmv("Fremont", 150);

	//increment to 145
	dmv.incrementGrade(5);
	std::cout << dmv.getName() << "'s grade: " << dmv.getGrade() << std::endl;
	//decrement to 149
	dmv.decrementGrade(4);
	std::cout << dmv.getName() << "'s grade: " << dmv.getGrade() << std::endl;
	//grade too low exception
	dmv.decrementGrade(10);
	std::cout << dmv.getName() << "'s grade: " << dmv.getGrade() << std::endl;

	return (0);
}