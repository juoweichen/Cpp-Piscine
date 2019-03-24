#include "FragTrap.hpp"

int main(void)
{
	FragTrap woo("woo");
	std::string psycho = "psycho";

	woo.status();

	woo.meleeAttack(psycho);
	woo.rangedAttack(psycho);
	woo.vaulthunter_dot_exe(psycho);

	woo.takeDamage(75);
	woo.beRepaired(25);

	woo.takeDamage(75);

	woo.beRepaired(25);
	woo.beRepaired(100);

	return 0;
}