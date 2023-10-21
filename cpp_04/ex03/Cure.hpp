#pragma once

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure(/* args */);
		Cure(std::string const & type);
		Cure(const Cure& copy);
		Cure& operator = (const Cure& src);
		void use(ICharacter& target);
		AMateria* clone() const;
		virtual ~Cure();
};
