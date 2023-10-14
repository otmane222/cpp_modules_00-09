#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(/* args */)
{
	std::cout<<"Diamond default constructor has been called"<<std::endl;
	name = "noName";
	ClapTrap::name = name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
{
	std::cout<<"Diamond constructor has been called <"<<name<<">"<<std::endl;
	this->name = name;
	ClapTrap::name = this->name + "_clap_name";
	hitPoints = FragTrap::hitPoints;
	energyPoints = ScavTrap::energyPoints;
	attackDamage = FragTrap::attackDamage;
}

void	DiamondTrap::attack(const std::string& name)
{
	ScavTrap::attack(name);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout<<"DiamonTrap name:"<<this->name<<" && ClapTrap name:"<<ClapTrap::name<<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& copy)
{
	std::cout<<"DiamondTrap: copy constructor has been called"<<std::endl;
	this->name = copy.name;
	this->hitPoints = copy.hitPoints;
	this->energyPoints = copy.energyPoints;
	this->attackDamage = copy.attackDamage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& src)
{
	std::cout<<"DiamondTrap: assigment has been called"<<std::endl;
	this->name = src.name;
	this->hitPoints = src.hitPoints;
	this->energyPoints = src.energyPoints;
	this->attackDamage = src.attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
}