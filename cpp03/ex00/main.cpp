#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	Omega("Omega");
	ClapTrap	Kronos("Kronos");

	Omega.attack("Kronos");
	Kronos.takeDamage(0);
	Kronos.beRepaired(3);
	Kronos.attack("Omega");
	Omega.takeDamage(0);
	Omega.beRepaired(6);
	return (0);
}