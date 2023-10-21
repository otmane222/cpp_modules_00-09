#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	Brain* brain;
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& src);
		virtual ~Cat();
		void	makeSound() const ;
};
