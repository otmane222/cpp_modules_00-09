#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */)
{
	std::cout<<"WrongAnimal default constructor called"<<std::endl;
	type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy)
{
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout<<"WrongAnimal makes a generic WrongAnimal sound."<<std::endl;
}

std::string WrongAnimal::getType() const
{
	return (type);
}

WrongAnimal::~WrongAnimal()
{
	std::cout<<"WrongAnimal destructor called"<<std::endl;
}