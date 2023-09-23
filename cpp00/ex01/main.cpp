#include "phonebook.hpp"

int main(int ac, char **av)
{
	PhoneBook	info;
	std::string	str = "";
	int		i = 0;
	int		flag = 0;

	(void)av;
	if (ac == 0)
		return (0);
	while (str != "EXIT")
	{
		std::cout<<"> ";
		if (!std::getline(std::cin, str))
			break ;
		if (str == "ADD")
		{
			if (i == 8)
				flag = 1;
			i = i % 8;
			info.add(&i);
			i++;
			continue;
		}
		if (str == "SEARCH")
		{
			info.search(i, flag);
		}
		else if (str != "EXIT")
		{
			if (std::cin.eof())
			{
				std::cout<<std::endl;
				break ;
			}
			std::cout << "Try enter ADD, SEARCH, EXIT" << std::endl;
		}
	}
}
