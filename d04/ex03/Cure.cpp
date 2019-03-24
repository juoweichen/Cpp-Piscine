#include "Cure.hpp"

Cure::Cure(void): AMateria("cure") {}
Cure::Cure(std::string const & type): AMateria("Cure")
{
	(void)type;
}

Cure::Cure(Cure const & cpy): AMateria(cpy) {}
Cure::~Cure(void) {}

Cure & Cure::operator=(Cure const & rhs)
{
	(void)rhs;
	return (*this);
}

Cure *	Cure::clone(void) const
{
	Cure *	newice = new Cure("cure");

	return newice;
}

void	Cure::use(ICharacter& target)
{
	this->setXP();
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
