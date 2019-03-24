#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"


class PowerFist: public AWeapon
{
	public:

		PowerFist(void);
		PowerFist(const PowerFist &src);
		virtual ~PowerFist();

		PowerFist &		operator=(PowerFist const & rhs);
		virtual void	attack(void) const;

	private:
		std::string			_name;
		int					_damage;
		int					_ap_cost;
};

#endif