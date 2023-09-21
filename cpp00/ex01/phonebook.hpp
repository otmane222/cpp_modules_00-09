#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cstdlib>
#include "contact.hpp"

class PhoneBook
{
	private:
		contact	contacts[8];
	public:
		void	start(void)
		{
			std::cout<<"Welcome to the Phonebook\n";
			std::cout<<"Usage\n";
			std::cout<<"ADD: to add a new conatct(limited with 8)\n";
			std::cout<<"SEARCH: to search for a contact\n";
			std::cout<<"EXIT: to exit from the programme\n";
		}
		void	add(int *i)
		{
			contacts[*i].set();
		}
		void	search(void)
		{
			int			i;
			std::string	a;

			i = 0;
			std::cout<<"#######################################################################################\n";
			std::cout<<"##	Index	##  First name     ## 	Last name ## Nickname	##	Phone Number ##\n";
			while (i < 8)
			{
				contacts[i].printtable(i);
				i++;
			}
			std::cout<<"Enter contact index: ";
			std::getline(std::cin, a);
			int	b;
			b = atoi(a.c_str()) - 1;
			contacts[b].printone(b);

		}
		// PhoneBook();
		// ~PhoneBook();
};

// PhoneBook::PhoneBook()
// {
// }

// PhoneBook::~PhoneBook()
// {
// }


#endif