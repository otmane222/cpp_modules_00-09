#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(/* args */)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy", 0, 72, 45, target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
{
	*this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	(void)src;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	if (this->getGradeToExecute() < executor.getGrade() || executor.getGrade() < 0)
		throw(GradeTooLowException());
	if (!this->getSigned())
		throw(FormNotSign());

	std::cout<<"Driling noise: drrrrrrrrrr"<<std::endl;
	int b = (time(nullptr) % 2);
	if (b)
	{
		std::cout<<executor.getName()<<" has been robotomized"<<std::endl;
	}
	else
	{
		std::cout<<"The robotomy has been failed"<<std::endl;
	}
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}