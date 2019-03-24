#include "AMateria.hpp"

AMateria::AMateria(void): type_(""), xp_(0) {}

AMateria::AMateria(std::string const & type): type_(type), xp_(0) {}

AMateria::AMateria(AMateria const & cpy)
{
	*this = cpy;
}

AMateria::~AMateria() {}

AMateria &	AMateria::operator=(AMateria const & rhs)
{
	xp_ = rhs.getXP();
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (this->type_);
}

unsigned int		AMateria::getXP() const
{
	return (this->xp_);
}

void				AMateria::setXP()
{
	this->xp_ += 10;
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
	this->setXP();
}