#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	if (N < 0)
	{
		std::cout<<"give a positive number."<<std::endl;
		exit (1);
	}
	Zombie	*z = new (std::nothrow) Zombie[N];
	if (!z)
	{
		std::cout<<"failed new"<<std::endl;
		return (NULL);
	}

	
	for (int i = 0; i < N; i++)
	{
		z[i].setName(name);
	}
	return (z);
}