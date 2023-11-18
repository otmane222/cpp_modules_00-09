#include "Intern.hpp"


Intern::Intern()
{
	
}
Intern::Intern(const Intern &c)
{
	*this = c;
}

Intern & Intern::operator=(const Intern &c)
{
	(void)c;
	return(*this);
}

AForm*	Intern::clonePresidential(std::string name)
{
	return (new PresidentialPardonForm(name));
}

AForm*	Intern::cloneRobotomy(std::string name)
{
	return (new RobotomyRequestForm(name));
}

AForm*	Intern::cloneShrubbery(std::string name)
{
	return (new ShrubberyCreationForm(name));
}


AForm* Intern::makeForm(std::string target, std::string name)
{
	(void)name;
	std::string types[3] = {"robotomy request", "shrubbery request", "presidential request"};
	clone formx[3] = {&Intern::cloneRobotomy, &Intern::cloneShrubbery, &Intern::clonePresidential};

	for (size_t i = 0; i < 3; i++)
	{
		if (target == types[i])
		{
			std::cout<<"Intern creates "<<target<<std::endl;
			return ((this->*formx[i])(name));
		}
	}
	return (NULL);
}

Intern::~Intern()
{
	
}
