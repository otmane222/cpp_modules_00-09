#pragma once

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &c);
		Intern&	operator=(const Intern &c);
		AForm*	makeForm(std::string target, std::string name);
		AForm*	clonePresidential(std::string name);
		AForm*	cloneRobotomy(std::string name);
		AForm*	cloneShrubbery(std::string name);

		~Intern();
};

typedef	AForm* (Intern::*clone)(std::string);