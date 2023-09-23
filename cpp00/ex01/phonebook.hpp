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
		Contact	contacts[8];
	public:
		PhoneBook();
		void	add(int *i);
		void	search(int k, int flag);
		~PhoneBook();
};


#endif