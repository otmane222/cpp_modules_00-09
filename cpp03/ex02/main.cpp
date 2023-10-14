#include "FragTrap.hpp"

int	main()
{
	ScavTrap	Omega("Omega");
	ScavTrap	Kronos("Kronos");
	FragTrap	Piper("Piper");

	Omega.attack("Kronos");
	Kronos.takeDamage(20);
	Kronos.beRepaired(15);
	Kronos.attack("Omega");
	Omega.takeDamage(20);
	Omega.beRepaired(26);
	Omega.guardGate();
	Piper.attack("Kronos");
	Kronos.takeDamage(30);
	Piper.highFivesGuys();
	return (0);
}