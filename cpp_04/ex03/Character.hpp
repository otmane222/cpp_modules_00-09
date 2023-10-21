#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		AMateria*	inventory[4];
		int follower[4];
		std::string name;
	public:
		Character();
		Character(std::string name);
		Character(const Character& copy);
		Character& operator = (const Character& src);

		AMateria*	getAMateria(int indx) const;
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
		virtual ~Character();
};