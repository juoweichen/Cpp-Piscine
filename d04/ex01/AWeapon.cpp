#include "AWeapon.hpp"

AWeapon::AWeapon(void): _name(""), _damage(0), _ap_cost(0) {}

AWeapon::AWeapon(AWeapon const & src):
	_name(src._name), _damage(src._damage), _ap_cost(src._ap_cost) {}

AWeapon::AWeapon(std::string const & name, int apcost, int damage):
	_name(name), _damage(damage), _ap_cost(apcost) {}

AWeapon::~AWeapon(void) {}

AWeapon &	AWeapon::operator=( AWeapon const & rhs )
{
	if ( this != &rhs )
	{
		this->_name = rhs._name;
		this->_damage = rhs._damage;
		this->_ap_cost = rhs._ap_cost;
	}
	return *this;
}

std::string	const	AWeapon::getName(void) const
{
	return this->_name;
}

int				AWeapon::getAPCost(void) const
{
	return this->_ap_cost;
}

int				AWeapon::getDamage(void) const
{
	return this->_damage;
}

std::ostream &	operator<<( std::ostream & o, AWeapon const & rhs )
{
	o << "I'm [AWeapon Class] name:" << rhs.getName() << ", damage: "
		<< rhs.getDamage() << ", ap cost: " << rhs.getAPCost() << std::endl;
	return o;
}