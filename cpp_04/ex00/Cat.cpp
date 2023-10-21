#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat default constructor called"<<std::endl;
	type = "Cat";
}

void	Cat::makeSound() const
{
	std::cout<<"Moewwwwwwww"<<std::endl;
}

Cat::Cat(const Cat& copy)
{
	*this = copy;
}

Cat& Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return (*this);

}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
}
