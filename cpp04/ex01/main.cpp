#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::string	str;
	const Animal* zoo[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			zoo[i] = new Dog();
		else
			zoo[i] = new Cat();
	}

	std::cout<<"----------MakeSounds----------"<<std::endl;
	for (int i = 0; i < 10; i++)
	{
		zoo[i]->makeSound();
	}
	std::cout<<"----------Delete--------------"<<std::endl;
	for (int i = 0; i < 10; i++)
	{
		delete zoo[i];
	}

	return 0;
}