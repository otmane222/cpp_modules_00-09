#include "Zombie.hpp"


Zombie::Zombie (std::string name) {
	this->name = name;
}

void	Zombie::announce(void)
{
	std::cout<<name + ": BraiiiiiiinnnzzzZ..."<<std::endl;
}

Zombie::~Zombie() {
	std::cout<<name<<" has been killed, well done!"<<std::endl;
}