#include "phonebook.hpp"

int main(int ac, char **av)
{
	PhoneBook	info;
	std::string	str = "";
	int		i = 0;

	(void)av;
	if (ac == 0)
		return (0);
	info.start();
	while (str.compare("EXIT"))
	{
		std::cout<<"> ";
		if (!std::getline(std::cin, str))
			exit (1);
		if (str == "ADD")
		{
			i = i % 8;
			info.add(&i);
			i++;
		}
		if (str == "SEARCH")
		{
			info.search();
		}
	}
}
