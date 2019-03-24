#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main(void)
{
	ClapTrap foo("foo");
	FragTrap woo("woo");
	ScavTrap hoo("hoo");
	NinjaTrap yoo("yoo");
	std::string poorPsycho = "psycho";

	foo.status();
	//attack
	foo.meleeAttack(poorPsycho);
	foo.rangedAttack(poorPsycho);
	//take damage
	foo.takeDamage(10);
	//should be dead, can't make anymore move
	foo.meleeAttack(poorPsycho);

	woo.status();
	//attack
	woo.meleeAttack(poorPsycho);
	woo.rangedAttack(poorPsycho);
	woo.vaulthunter_dot_exe(poorPsycho);
	//take damage
	woo.takeDamage(10);
	//repair
	woo.beRepaired(100);
	//take lethal damage
	woo.takeDamage(300);
	//should be dead, can't make anymore move
	woo.meleeAttack(poorPsycho);

	hoo.status();	
	//attack
	hoo.meleeAttack(poorPsycho);
	hoo.rangedAttack(poorPsycho);
	hoo.challengeNewcomer(poorPsycho);
	//take damage
	hoo.takeDamage(10);
	//repair
	hoo.beRepaired(100);
	//take lethal damage
	hoo.takeDamage(300);
	//should be dead, can't make anymore move
	hoo.meleeAttack(poorPsycho);

	yoo.status();
	//attack
	yoo.meleeAttack(poorPsycho);
	yoo.rangedAttack(poorPsycho);
	yoo.ninjaShoebox(foo);
	std::cout << std::endl;
	yoo.ninjaShoebox(woo);
	std::cout << std::endl;
	yoo.ninjaShoebox(hoo);
	std::cout << std::endl;
	yoo.ninjaShoebox(yoo);
	std::cout << std::endl;
	//take damage
	yoo.takeDamage(10);
	//repair
	yoo.beRepaired(100);
	//take lethal damage
	yoo.takeDamage(300);
	//should be dead, can't make anymore move
	yoo.meleeAttack(poorPsycho);

	return 0;
}