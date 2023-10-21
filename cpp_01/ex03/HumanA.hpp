#pragma once

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon&		a;
		std::string	name;
	public:
		HumanA(std::string name, Weapon& a);
		void	attack(void);
};