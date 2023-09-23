#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <limits>
#include <iomanip>
#include <cstdlib>

class Contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	DarkestSecret;
	std::string	PhoneNumber;
public:
	void	set(void);
	void	printtable(int i);
	void	printone(int i, int flag, int k);
};


#endif