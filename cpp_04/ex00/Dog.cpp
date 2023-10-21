#include "Dog.hpp"

Dog::Dog()
{
	std::cout<<"Dog default constructor called"<<std::endl;
	type = "Dog";
}

void	Dog::makeSound() const
{
	std::cout<<"Haw Haw GhGhGh"<<std::endl;
}

Dog::Dog(const Dog& copy)
{
	*this = copy;
}

Dog& Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return (*this);

}


Dog::~Dog()
{
	std::cout<<"Dog destructor called"<<std::endl;
}
