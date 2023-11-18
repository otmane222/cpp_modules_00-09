#pragma once

#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie (std::string name);
		void	announce(void);
		~Zombie();
};

Zombie	*newZombie(std::string name);
void	randomChump (std::string name);
