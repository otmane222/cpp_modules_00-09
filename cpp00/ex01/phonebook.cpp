#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	std::cout<<"Welcome to the Phonebook\n";
	std::cout<<"Usage\n";
	std::cout<<"ADD: to add a new conatct(limited with 8)\n";
	std::cout<<"SEARCH: to search for a contact\n";
	std::cout<<"EXIT: to exit from the programme\n";
}

void	PhoneBook::add(int *i)
{
	contacts[*i].set();
}

void	PhoneBook::search(int k, int flag)
{
	int			i;
	std::string	a;

	if (flag)
		k = 8;
	i = 0;
	std::cout<<"#############################################\n";
	std::cout<<"#Index     |First name|Last name |Nickname  #\n";
	while (i < k)
	{
		contacts[i].printtable(i);
		i++;
	}
	std::cout<<"Enter contact index: ";
	if (!std::getline(std::cin, a))
		exit (1);;;
	int	b;
	b = atoi(a.c_str()) - 1;
	contacts[b].printone(b, flag, k);

}

PhoneBook::~PhoneBook()
{
	std::cout<<"Thank you for using our services\n";
}