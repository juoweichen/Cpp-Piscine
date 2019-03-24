#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"
#include "SuperTrap.hpp"

int main(void)
{
	// ClapTrap claptrap("claptrap");
	// FragTrap fragtrap("fragtrap");
	ScavTrap scavtrap("scavtrap");
	// NinjaTrap ninjatrap("ninjatrap");
	SuperTrap supertrap("supertrap");
	std::string poorPsycho = "psycho";
/*
	claptrap.status();
	//attack
	claptrap.meleeAttack(poorPsycho);
	claptrap.rangedAttack(poorPsycho);
	//take damage
	claptrap.takeDamage(10);
	//should be dead, can't make anymore move
	claptrap.meleeAttack(poorPsycho);

	fragtrap.status();
	//attack
	fragtrap.meleeAttack(poorPsycho);
	fragtrap.rangedAttack(poorPsycho);
	fragtrap.vaulthunter_dot_exe(poorPsycho);
	//take damage
	fragtrap.takeDamage(10);
	//repair
	fragtrap.beRepaired(100);
	//take lethal damage
	fragtrap.takeDamage(300);
	//should be dead, can't make anymore move
	fragtrap.meleeAttack(poorPsycho);

	scavtrap.status();	
	//attack
	scavtrap.meleeAttack(poorPsycho);
	scavtrap.rangedAttack(poorPsycho);
	scavtrap.challengeNewcomer(poorPsycho);
	//take damage
	scavtrap.takeDamage(10);
	//repair
	scavtrap.beRepaired(100);
	//take lethal damage
	scavtrap.takeDamage(300);
	//should be dead, can't make anymore move
	scavtrap.meleeAttack(poorPsycho);

	ninjatrap.status();
	//attack
	ninjatrap.meleeAttack(poorPsycho);
	ninjatrap.rangedAttack(poorPsycho);
	ninjatrap.ninjaShoebox(claptrap);
	std::cout << std::endl;
	ninjatrap.ninjaShoebox(fragtrap);
	std::cout << std::endl;
	ninjatrap.ninjaShoebox(scavtrap);
	std::cout << std::endl;
	ninjatrap.ninjaShoebox(ninjatrap);
	std::cout << std::endl;
	//take damage
	ninjatrap.takeDamage(10);
	//repair
	ninjatrap.beRepaired(100);
	//take lethal damage
	ninjatrap.takeDamage(300);
	//should be dead, can't make anymore move
	ninjatrap.meleeAttack(poorPsycho);
*/
	supertrap.status();

	supertrap.vaulthunter_dot_exe(poorPsycho);
	supertrap.ninjaShoebox(scavtrap);

	//attack
	supertrap.meleeAttack(poorPsycho);
	supertrap.rangedAttack(poorPsycho);
	//take damage
	supertrap.takeDamage(10);
	//repair
	supertrap.beRepaired(100);
	//take lethal damage
	supertrap.takeDamage(300);
	//should be dead, can't make anymore move
	supertrap.meleeAttack(poorPsycho);

	return 0;
}