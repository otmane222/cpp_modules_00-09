#include "Bureaucrat.hpp"
#include "Form.hpp"

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
		Bureaucrat	bur("Jax", 10);
		Form bob("School guide lines", false, 15, 13);
		std::cout<<bob<<std::endl;
		bur.signForm(bob);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << e.what() <<std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}