#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"


int main()
{
	Intern a;
	AForm *f;
	Bureaucrat	br("John", 19);

	f = a.makeForm("robotomy request", "Bob");
	if (!f)
		return (1);
	br.signForm(f);
	std::cout<<f->getTarget()<<std::endl;
	std::cout<<*f<<std::endl;
	try
	{	
		f->execute(br);

	}
	catch(AForm::GradeTooLowException e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete f;
	return (0);
}
