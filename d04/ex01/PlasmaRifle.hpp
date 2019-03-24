#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
	public:

		PlasmaRifle(void);
		PlasmaRifle(const PlasmaRifle &src);
		virtual ~PlasmaRifle();

		PlasmaRifle &		operator=(PlasmaRifle const & rhs);

		virtual void		attack() const;

	private:
		std::string			_name;
		int					_damage;
		int					_ap_cost;
};

#endif