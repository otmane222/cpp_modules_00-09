#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	Brain* brain;
	public:
		Dog();
		Dog(const Dog& copy);
		Dog& operator=(const Dog& src);
		virtual ~Dog();
		void	makeSound() const;
};
