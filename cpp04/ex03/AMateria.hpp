#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria(/* args */);
		AMateria(std::string const & type);
		AMateria(const AMateria& copy);
		AMateria& operator = (const AMateria& src);

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		virtual ~AMateria();
};
