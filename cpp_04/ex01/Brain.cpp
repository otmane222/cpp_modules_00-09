#include "Brain.hpp"

Brain::Brain(/* args */)
{
	std::cout<<"Brain default constructor called"<<std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
}

Brain& Brain::operator = (const Brain& src)
{
	if (this != &src)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = src.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout<<"Brain destructor called"<<std::endl;
}