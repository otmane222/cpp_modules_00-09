#include "AMateria.hpp"

AMateria::AMateria(/* args */)
{
}

AMateria::AMateria(std::string const & type) : type(type) {}

std::string const & AMateria::getType() const
{
	return (type);
}

AMateria::AMateria(const AMateria& copy)
{
	(void)copy;
}

AMateria& AMateria::operator = (const AMateria& src)
{
	(void)src;
	return (*this);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}

AMateria::~AMateria()
{
}