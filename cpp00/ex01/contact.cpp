#include "contact.hpp"

void	Contact::set(void)
{
	std::cout<<"Enter Your First Name: ";
	if (!std::getline(std::cin, FirstName))
		return ;
	while (FirstName.empty())
	{
		std::cout<<"Enter Your First Name: ";
		if (!std::getline(std::cin, FirstName))
			return ;
	}
	
	std::cout<<"Enter Your Last Name: ";
	if (!std::getline(std::cin, LastName))
		return ;
	while (LastName.empty())
	{
		std::cout<<"Enter Your Last Name: ";
		if (!std::getline(std::cin, LastName))
			return ;
	}
	
	std::cout<<"Enter Your Nick Name: ";
	if (!std::getline(std::cin, NickName))
		return ;
	while (NickName.empty())
	{
		std::cout<<"Enter Your Nick Name: ";
		if (!std::getline(std::cin, NickName))
			return ;
	}

	std::cout<<"Enter Your Darkest Secret: ";
	if (!std::getline(std::cin, DarkestSecret))
		return ;
	while (DarkestSecret.empty())
	{
		std::cout<<"Enter Your Darkest Secret: ";
		if (!std::getline(std::cin, DarkestSecret))
			return ;
	}

	std::cout<<"Enter Your Phone Number: ";
	if (!std::getline(std::cin, PhoneNumber))
		return ;
	while (PhoneNumber.empty())
	{
		std::cout<<"Enter Your Phone Number: ";
		if (!std::getline(std::cin, PhoneNumber))
			return ;
	}
}
void	Contact::printtable(int i)
{
	if (i < 0 || i >= 8)
		return ;
	std::string s2;
	std::string s3;
	std::string s4;
	
	s2 = FirstName;
	s3 = LastName;
	s4 = NickName;
	if (strlen(FirstName.c_str()) > 10)
	{
		s2 = FirstName.substr(0, 9);
		s2 = s2 + ".";
	}
	if (strlen(LastName.c_str()) > 10)
	{
		s3 = LastName.substr(0, 9);
		s3 = s3 + ".";
	}
	if (strlen(NickName.c_str()) > 10)
	{
		s4 = NickName.substr(0, 9);
		s4 = s4 + ".";
	}
	std::cout<<"#"<<std::setw(10)<<i + 1<<"|";
	std::cout<<std::setw(10)<<s2<<"|";
	std::cout<<std::setw(10)<<s3<<"|";
	std::cout<<std::setw(10)<<s4<<"#\n";
}
void	Contact::printone(int i, int flag, int k)
{
	if (i < 0 || (i >= k && !flag))
	{
		std::cout<<"out of range\n";
		return ;
	}
	std::cout<<"First Name: "<<FirstName<<"\n"<<"Last Name: "<<LastName<<"\n"<<"NickName: "<<NickName<<"\n"<<"Phone Number: "<<PhoneNumber<<"\n";
}