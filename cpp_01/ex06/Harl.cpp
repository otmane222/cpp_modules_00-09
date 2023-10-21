#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout<<"I love having extra bacon for ";
	std::cout<<"my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout<<std::endl;
}

void Harl::info( void )
{
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put";
	std::cout<<"enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout<<std::endl;
}

void Harl::warning( void )
{
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for";
	std::cout<<"years whereas you started working here since last month.";
	std::cout<<std::endl;
}

void Harl::error( void )
{
	std::cout<<"This is unacceptable! I want to speak to the manager now.";
	std::cout<<std::endl;
}

void Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	void	(Harl::*f[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			break ;
	}
	switch (i)
	{
	case (0):
	{
		debug();
	}
	case (1):
	{
		info();
	}
	case (2):
	{
		warning();
	}
	case (3):
	{
		error();
		break ;
	}
	default:
		std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}