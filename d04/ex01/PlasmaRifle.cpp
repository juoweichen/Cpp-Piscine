#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void): AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src): AWeapon(src) {}

PlasmaRifle::~PlasmaRifle(void) {}

PlasmaRifle &	PlasmaRifle::operator=( PlasmaRifle const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_damage = rhs._damage;
		this->_ap_cost = rhs._ap_cost;
	}
	return *this;
}

std::ostream &	operator<<( std::ostream & o, PlasmaRifle const & rhs )
{
	o << "I'm [PlasmaRifle Class] name:" << rhs.getName() << ", damage: "
		<< rhs.getDamage() << ", ap cost: " << rhs.getAPCost() << std::endl;
	return o;
}

void			PlasmaRifle::attack() const
{
	std::cout<< "* piouuu piouuu piouuu *" << std::endl;
}