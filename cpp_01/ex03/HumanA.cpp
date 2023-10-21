#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& a) : name(name), a(a) {}


void	HumanA::attack()
{
	std::cout<<name<<" attacks with their "<<a.getType()<<std::endl;
}