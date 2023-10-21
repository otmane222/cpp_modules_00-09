#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout<<"WrongCat default constructor called"<<std::endl;
	type = "WrongCat";
}

void	WrongCat::makeSound() const
{
	std::cout<<"Moewwwwwwww"<<std::endl;
}

WrongCat::WrongCat(const WrongCat& copy)
{
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
	{
		type = src.getType();
	}
	return (*this);

}

WrongCat::~WrongCat()
{
	std::cout<<"WrongCat destructor called"<<std::endl;
}
