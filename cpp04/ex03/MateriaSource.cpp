#include "MateriaSource.hpp"

MateriaSource::MateriaSource(/* args */)
{
	for (size_t i = 0; i < 4; i++)
	{
		inventory[i] = NULL;
	}
}

void MateriaSource::learnMateria(AMateria* a)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = a;
			break ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	if (type == "ice")
		return (new Ice());
	if (type == "cure")
		return (new Cure());
	return (0);
}

MateriaSource::~MateriaSource()
{
}
