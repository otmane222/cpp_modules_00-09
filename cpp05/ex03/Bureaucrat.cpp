#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(/* args */)
{
}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade < 1)
		throw(GradeTooHighException());
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& src)
{	
	if (this != &src)
	{
		const_cast<std::string&>(this->name) = src.getName();
		this->grade = src.getGrade();
	}
	return (*this);
}

int Bureaucrat::getGrade() const
{
	return (grade);
}

std::string Bureaucrat::getName() const
{
	return (name);
}

void	Bureaucrat::increment()
{
	if (grade <= 1)
		throw(GradeTooHighException());
	if (grade > 150)
		throw(GradeTooLowException());
	if (grade - 1 > 0)
		grade -= 1;
	
}
void	Bureaucrat::decrement()
{
	if (grade < 1)
		throw(GradeTooHighException());
	if (grade >= 150)
		throw(GradeTooLowException());
	if (grade + 1 <= 150)
		grade += 1;
}

void	Bureaucrat::signForm(AForm *form) const
{
	form->beSigned(*this);
	if (form->getSigned())
		std::cout<< this->getName()<<" signed "<< form->getName() <<std::endl;
	else
		std::cout<< this->getName()<<" couldn’t sign "<< form->getName()<<" because grade wasn't high enough"<<std::endl;

}

Bureaucrat::~Bureaucrat()
{}

std::ostream& operator << (std::ostream& out, const Bureaucrat& a)
{
	out<<a.getName() << ", bureaucrat grade "<<a.getGrade()<<".";
	return (out);
}