#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	a = NULL;
	this->name = name;
}

void	HumanB::setWeapon(Weapon& a)
{
	this->a = &a;
}

void	HumanB::attack()
{
	if (!a)
		std::cout<<name<<" attacks with their "<<std::endl;
	else if (a)
		std::cout<<name<<" attacks with their "<<a->getType()<<std::endl;
}