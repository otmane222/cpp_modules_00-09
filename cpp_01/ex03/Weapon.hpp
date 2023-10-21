#pragma once

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		const std::string	&getType(void);
		void	setType(std::string type);
};
