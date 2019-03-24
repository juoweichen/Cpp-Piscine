#include "PowerFist.hpp"

PowerFist::PowerFist(void): AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const & src): AWeapon(src) {}

PowerFist::~PowerFist(void) {}

PowerFist &	PowerFist::operator=( PowerFist const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_damage = rhs._damage;
		this->_ap_cost = rhs._ap_cost;
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, PowerFist const & rhs )
{
	o << "I'm [PowerFist Class] name:" << rhs.getName() << ", damage: "
		<< rhs.getDamage() << ", ap cost: " << rhs.getAPCost() << std::endl;
	return o;
}

void			PowerFist::attack(void) const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}