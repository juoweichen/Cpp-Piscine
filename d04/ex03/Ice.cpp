#include "Ice.hpp"

Ice::Ice(void): AMateria("ice") {}
Ice::Ice(std::string const & type): AMateria("ice")
{
	(void)type;
}

Ice::Ice(Ice const & cpy): AMateria(cpy) {}
Ice::~Ice(void) {}

Ice & Ice::operator=(Ice const & rhs)
{
	(void)rhs;
	return (*this);
}

Ice *	Ice::clone(void) const
{
	Ice *	newice = new Ice("ice");

	return newice;
}

void	Ice::use(ICharacter& target)
{
	this->setXP();
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}