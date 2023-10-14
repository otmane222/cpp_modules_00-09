#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string target);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& src);
		~FragTrap();
		void	highFivesGuys(void);
};
