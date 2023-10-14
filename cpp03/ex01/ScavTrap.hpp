#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string target);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& src);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};
