#include "FragTrap.hpp"


FragTrap::FragTrap(/* args */)
{
	std::cout<<"FragTrap default constructor has been called"<<std::endl;
	this->name = "FragTrap";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout<<"FragTrap constructor has been called <"<<name<<">"<<std::endl;
	this->name = name;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
}

void	FragTrap::highFivesGuys(void)
{
	if (!hitPoints)
		std::cout<<"FragTrap "<<name<<" can't move!"<<std::endl;
	else
		std::cout<<"FragTrap "<<name<<" high fives!"<<std::endl;
}

FragTrap::FragTrap(const FragTrap& copy)
{
	std::cout<<"FragTrap: copy constructor has been called"<<std::endl;
	this->name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& src)
{
	std::cout<<"FragTrap: assigment has been called"<<std::endl;
	this->name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout<<"FragTrap destructor has been called <"<<name<<">"<<std::endl;
}
