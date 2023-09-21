#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <cstring>

class contact
{
private:
	std::string	FirstName;
	std::string	LastName;
	std::string	NickName;
	std::string	DarkestSecret;
	std::string	PhoneNumber;
public:
	void	set(void)
	{
		std::cout<<"Enter Your First Name: ";
		std::getline(std::cin, FirstName);
		while (FirstName.empty())
		{
			std::cout<<"Enter Your First Name: ";
			std::getline(std::cin, FirstName);
		}
		
		std::cout<<"Enter Your Last Name: ";
		std::getline(std::cin, LastName);
		while (LastName.empty())
		{
			std::cout<<"Enter Your Last Name: ";
			std::getline(std::cin, LastName);
		}
		
		std::cout<<"Enter Your Nick Name: ";
		std::getline(std::cin, NickName);
		while (NickName.empty())
		{
			std::cout<<"Enter Your Nick Name: ";
			std::getline(std::cin, NickName);
		}
	
		std::cout<<"Enter Your Darkest Secret: ";
		std::getline(std::cin, DarkestSecret);
		while (DarkestSecret.empty())
		{
			std::cout<<"Enter Your Darkest Secret: ";
			std::getline(std::cin, DarkestSecret);
		}

		std::cout<<"Enter Your Phone Number: ";
		std::getline(std::cin, PhoneNumber);
		while (PhoneNumber.empty())
		{
			std::cout<<"Enter Your Phone Number: ";
			std::getline(std::cin, PhoneNumber);
		}
	}
	void	printtable(int i)
	{
		if (i < 0 || i >= 8)
			return ;
		std::string s1;
		std::string s2;
		std::string s3;
		std::string s4;
		
		s1 = PhoneNumber;
		s2 = FirstName;
		s3 = LastName;
		s4 = NickName;
		if (strlen(PhoneNumber.c_str()) > 10)
		{
			s1 = PhoneNumber.substr(0, 10);
			s1 = s1 + ".";
		}
		if (strlen(FirstName.c_str()) > 10)
		{
			s2 = FirstName.substr(0, 10);
			s2 = s2 + ".";
		}
		if (strlen(LastName.c_str()) > 10)
		{
			s3 = LastName.substr(0, 10);
			s3 = s3 + ".";
		}
		if (strlen(NickName.c_str()) > 10)
		{
			s4 = NickName.substr(0, 10);
			s4 = s4 + ".";
		}
		std::cout<<"##	"<<i + 1<<"	|	"<<s2<<"	   |	"<<s3;
		std::cout<<"	  | "<<s4<<"		|	"<<s1;
		std::cout<<"	      ##\n";
	}
	void	printone(int i)
	{
		if (i < 0 || i >= 8)
		{
			std::cout<<"out of range\n";
			return ;
		}
		std::cout<<"First Name: "<<FirstName<<"\n"<<"Last Name: "<<LastName<<"\n"<<"NickName: "<<NickName<<"\n"<<"Phone Number: "<<PhoneNumber<<"\n";
	}
	contact();
	~contact();
};

contact::contact(/* args */)
{
}

contact::~contact()
{
}


#endif