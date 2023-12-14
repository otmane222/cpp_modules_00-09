#include "ScavTrap.hpp"

int	main()
{
	// ScavTrap	Omega("Omega");
	// ScavTrap	Kronos("Kronos");

	// Omega.attack("Kronos");
	// Kronos.takeDamage(20);
	// Kronos.beRepaired(15);
	// Kronos.attack("Omega");
	// Omega.takeDamage(20);
	// Omega.beRepaired(26);
	// Omega.guardGate();
	ScavTrap *c = new ScavTrap("otmane");
	ClapTrap *p = c;
	p->attack("lolo");
	c->attack("lolo");

	return (0);
}