#pragma once

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*a;
		std::string	name;
	public:
		HumanB(std::string name);
		void	setWeapon(Weapon& a);
		void	attack(void);
};