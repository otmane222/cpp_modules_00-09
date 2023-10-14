#include "ClapTrap.hpp"

ClapTrap::ClapTrap(/* args */)
{
	std::cout<<"ClapTrap default constructor has been called"<<std::endl;
	this->name = "player";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout<<"ClapTrap constructor has been called <"<<name<<">"<<std::endl;
	this->name = name;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& copy)
{
	std::cout<<"ClapTrap copy constructor has been called"<<std::endl;
	this->name = copy.name;
	hitPoints = copy.hitPoints;
	energyPoints = copy.energyPoints;
	attackDamage = copy.attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (!this->hitPoints || !this->energyPoints)
	{
		if (!this->energyPoints)
			std::cout<<"ClapTrap "<<name<<" can't attack cause no energyPoints left"<<std::endl;
		else
			std::cout<<"ClapTrap "<<name<<" can't attack cause no hitPoints left"<<std::endl;
	}
	else {
		std::cout<<"ClapTrap "<<this->name<<" attacks "<<target<<", causing "<<attackDamage;
		std::cout<<" points of damage!"<<std::endl;
		energyPoints--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout<<"ClapTrap "<<name<<" has take "<<amount<<" of damage"<<std::endl;
	if (amount >= (unsigned int)hitPoints)
		std::cout<<"ClapTrap "<<name<<" can't move!"<<std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->hitPoints || !this->energyPoints)
	{
		std::cout<<"ClapTrap "<<name<<" can't move!"<<std::endl;
	}
	else
	{
		energyPoints--;
		std::cout<<"ClapTrap "<<name<<" added "<<amount<<" hitpoints "<<std::endl;
		hitPoints += amount;
	}
}

ClapTrap& ClapTrap::operator=(const ClapTrap& src)
{
	std::cout<<"ClapTrap assigment has been called"<<std::endl;
	this->name = src.name;
	hitPoints = src.hitPoints;
	energyPoints = src.energyPoints;
	attackDamage = src.attackDamage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout<<"ClapTrap destructor has been called <"<<name<<">"<<std::endl;
}