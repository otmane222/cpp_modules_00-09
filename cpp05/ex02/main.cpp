#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


int main()
{

	try
	{
		Bureaucrat	bur("Jax", 160);
		std::cout<< bur<<std::endl;		
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	try
	{
		Bureaucrat	bur("Jax", 1);
		ShrubberyCreationForm Bob("bob");
		AForm* Lux = new RobotomyRequestForm("Lux");
		AForm* Nunu = new PresidentialPardonForm("Nunu");
		bur.signForm(&Bob);
		bur.signForm(Lux);
		bur.signForm(Nunu);
		std::cout<<"––––––––––––––––––––––"<<std::endl;
		std::cout<<Bob<<std::endl;
		std::cout<<"––––––––––––––––––––––––––––"<<std::endl;
		Bob.execute(bur);
		Lux->execute(bur);
		std::cout<<"–––––––––––––––––––––––––––––––––––––––––––"<<std::endl;
		Nunu->execute(bur);
		std::cout<<"–––––––––––––––––––––––––––––––––––––––––––"<<std::endl;
		delete Lux;
		delete Nunu;
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cerr<<e.what()<<std::endl;
	}
	catch(const ShrubberyCreationForm::FormNotSign& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}