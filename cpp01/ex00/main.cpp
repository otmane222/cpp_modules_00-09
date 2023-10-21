#include "Zombie.hpp"

int	main()
{
	Zombie	*zombie_in_heap = newZombie("loo");

	randomChump("loo");
	zombie_in_heap->announce();
	delete zombie_in_heap;
	return (0);
}
