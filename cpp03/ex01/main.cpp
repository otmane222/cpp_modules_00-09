#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	Omega("Omega");
	ScavTrap	Kronos("Kronos");

	Omega.attack("Kronos");
	Kronos.takeDamage(20);
	Kronos.beRepaired(15);
	Kronos.attack("Omega");
	Omega.takeDamage(20);
	Omega.beRepaired(26);
	Omega.guardGate();
	return (0);
}