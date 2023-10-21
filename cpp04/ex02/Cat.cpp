#include "Cat.hpp"

Cat::Cat()
{
	std::cout<<"Cat default constructor called"<<std::endl;
	brain = new Brain();
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
		brain = new Brain();
	}
	return (*this);

}

Cat::~Cat()
{
	std::cout<<"Cat destructor called"<<std::endl;
	delete brain;
}
