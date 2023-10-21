#include "Character.hpp"

Character::Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		follower[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < 4; i++)
	{
		follower[i] = 0;
		inventory[i] = NULL;
	}
}

Character::Character(const Character& copy)
{
	*this = copy;
}

Character& Character::operator = (const Character& src)
{
	if (this != &src)
	{
		name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			inventory[i] = src.getAMateria(i);
			follower[i] = src.follower[i];
		}
	}
	return (*this);
}

AMateria*	Character::getAMateria(int idx) const
{
	if (idx >= 0 && idx <= 3)
		return (inventory[idx]);
	return (0);
}

std::string const & Character::getName() const
{
	return (name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if (m == inventory[i])
			break;
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			follower[i] = 1;
			break ;
		}
		if (follower[i] == 0)
		{
			delete inventory[i];
			inventory[i] = m;
			follower[i] = 1;
			break ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		inventory[idx] = NULL;
		follower[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (!(idx >= 0 && idx <= 3))
		return ;
	if (inventory[idx])
	{
		inventory[idx]->use(target);
	}
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
	
}
