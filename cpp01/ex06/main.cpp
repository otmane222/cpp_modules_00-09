#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Usage: "<<av[0]<<" \"DEBUG || INFO || WARNING || ERROR\""<<std::endl;
		return (1);
	}
	Harl		h;
	std::string	level = av[1];

	h.complain(level);
	return (0);
}