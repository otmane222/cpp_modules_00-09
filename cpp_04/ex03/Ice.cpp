#include "Ice.hpp"

Ice::Ice()
{
	type = "ice";
}

Ice::Ice(std::string const & type) : AMateria(type)
{
}

Ice::Ice(const Ice& copy)
{
	*this = copy;
}

Ice& Ice::operator = (const Ice& src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Ice::use(ICharacter& target)
{
	std::cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<std::endl;
}

AMateria* Ice::clone() const
{
	return (new Ice());
}

Ice::~Ice()
{
}
