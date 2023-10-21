#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::Cure(std::string const & type) : AMateria(type)
{
}

Cure::Cure(const Cure& copy)
{
	*this = copy;
}

Cure& Cure::operator = (const Cure& src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return (*this);
}

void Cure::use(ICharacter& target)
{
	std::cout<<"* heals "<<target.getName()<<"'s wounds *"<<std::endl;
}

AMateria* Cure::clone() const
{
	return (new Cure());
}

Cure::~Cure()
{
}
