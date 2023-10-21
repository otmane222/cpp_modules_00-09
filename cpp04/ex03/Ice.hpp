#pragma once

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice(/* args */);
		Ice(std::string const & type);
		Ice(const Ice& copy);
		Ice& operator = (const Ice& src);
		void use(ICharacter& target);
		AMateria* clone() const;
		virtual ~Ice();
};
