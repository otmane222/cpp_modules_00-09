#include "ScavTrap.hpp"

ScavTrap::ScavTrap(/* args */) : ClapTrap()
{
	std::cout<<"ScavTrap default constructor has been called"<<std::endl;
	this->name = "Robot";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(std::string target)
{
	std::cout<<"ScavTrap constructor has been called <"<<target<<">"<<std::endl;
	name = target;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->hitPoints || !this->energyPoints)
		std::cout<<"ScavTrap "<<name<<" can't attack"<<std::endl;
	else {
		std::cout<<"ScavTrap "<<this->name<<" attacks "<<target<<", causing a lost of "<<attackDamage;
		std::cout<<" hit point!!"<<std::endl;
		energyPoints--;
	}
}

void	ScavTrap::guardGate()
{
	if (!hitPoints || !energyPoints)
		std::cout<<"ScavTrap "<<name<<" can't enter Gate keeper mode."<<std::endl;
	else
	{
		std::cout<<"ScavTrap "<<this->name<<" is now in Gate keeper mode."<<std::endl;
		energyPoints--;
	}
}

ScavTrap::ScavTrap(const ScavTrap& copy)
{
	std::cout<<"ScavTrap: copy constructor has been called"<<std::endl;
	this->name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& src)
{
	std::cout<<"ScavTrap: assigment has been called"<<std::endl;
	this->name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout<<"ScavTrap destructor has been called <"<<name<<">"<<std::endl;
}
