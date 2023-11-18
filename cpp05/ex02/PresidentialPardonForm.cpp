#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) \
										: AForm("Presidential", false, 25, 5, target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
{
	*this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	(void)src;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	if (this->getGradeToExecute() < executor.getGrade() || executor.getGrade() < 0)
		throw(GradeTooLowException());
	if (!this->getSigned())
		throw(FormNotSign());
	std::cout<<executor.getName()<<" has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
