#include "Bureaucrat.hpp"

int main()
{

	// try
	// {
	// 	Bureaucrat	bur("Jax", 111);
	// 	try {
	// 		bur.increment();
	// 	}
	// 	catch (Bureaucrat::GradeTooHighException& e)
	// 	{
	// 		std::cerr<<e.what()<<std::endl;
	// 	}
	// 	std::cout<< bur<<std::endl;		
	// }
	// catch (Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr<<e.what()<<std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr<<e.what()<<std::endl;
	// }
	// try
	// {
	// 	Bureaucrat	bur("Bob", 10);

	// 	bur.decrement();
	// 	std::cout<< bur<<std::endl;
	// }
	// catch (Bureaucrat::GradeTooHighException& e)
	// {
	// 	std::cerr<<e.what()<<std::endl;
	// }
	// catch (Bureaucrat::GradeTooLowException& e)
	// {
	// 	std::cerr<<e.what()<<std::endl;
	// }
	Bureaucrat obj;
	try
	{
		obj.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what( ) << '\n';
	}
	
	std::cout<< obj <<std::endl;		

	return (0);
}