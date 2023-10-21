#include "Zombie.hpp"

int main ()
{
	Zombie *a = zombieHorde(3, "loo");
	if (!a)
		return (1);
	for (int i = 0; i < 3; i++)
	{
		a[i].announce();
	}
	delete [] a;
	return (0);
}