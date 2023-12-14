#pragma once

#include <iostream>

class ClapTrap {
	protected:
		std::string	name;
		int	hitPoints;
		int	energyPoints;
		int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& copy);
		ClapTrap& operator=(const ClapTrap& src);
		~ClapTrap();
		virtual void attack(const std::string& target) = 0;
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};
