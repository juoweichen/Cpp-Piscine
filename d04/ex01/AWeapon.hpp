#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>

class AWeapon
{
	public:

		AWeapon(void);
		AWeapon(const AWeapon &src);
		AWeapon(std::string const & name, int apcost, int damage);
		virtual ~AWeapon();

		AWeapon &			operator=(AWeapon const & rhs);

		std::string const	getName(void) const;
		int 				getAPCost(void) const;
		int					getDamage(void) const;
		virtual void		attack(void) const = 0;

	private:
		std::string			_name;
		int					_damage;
		int					_ap_cost;
};

std::ostream &	operator<<( std::ostream & o, AWeapon const & rhs );

#endif