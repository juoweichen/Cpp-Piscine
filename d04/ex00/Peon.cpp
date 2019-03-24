#include "Peon.hpp"

Peon::Peon(void)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src)
{
	*this = src;
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(std::string name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon(void)
{
	std::cout << "Bleuark..." << std::endl;
}

Peon &	Peon::operator=( Peon const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs.getName();
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, Peon const & rhs )
{
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return o;
}

void	Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}