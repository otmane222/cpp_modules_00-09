#include "Animal.hpp"

Animal::Animal(/* args */)
{
	std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::Animal(const Animal& copy)
{
	*this = copy;
}

Animal& Animal::operator=(const Animal& src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

std::string Animal::getType() const
{
	return (type);
}

Animal::~Animal()
{
	std::cout<<"Animal destructor called"<<std::endl;
}