#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	FragTrap woo("woo");
	ScavTrap hoo("hoo");
	std::string psycho = "psycho";

	woo.status();

	woo.meleeAttack(psycho);
	woo.rangedAttack(psycho);
	woo.vaulthunter_dot_exe(psycho);

	woo.takeDamage(75);
	woo.beRepaired(25);

	hoo.status();

	hoo.meleeAttack(psycho);
	hoo.rangedAttack(psycho);
	hoo.challengeNewcomer(psycho);

	hoo.takeDamage(75);
	hoo.beRepaired(25);

	return 0;
}