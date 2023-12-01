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
	size_t i = 0;
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = a;
			break ;
		}
	}
	if (i == 4 && inventory[i] != a)
		delete a;
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
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
		{
			delete inventory[i];
		}
	}
}
