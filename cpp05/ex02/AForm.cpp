#include "AForm.hpp"


AForm::AForm() :  name("noname"), sign(false), grade_sign(150) ,grade_ex(150), target("none")
{
}

AForm::AForm(std::string name, bool sign, int grade_s, int grade_e, std::string target):name(name), sign(sign),grade_sign(grade_s), grade_ex(grade_e),target(target)
{
	if (grade_e >= 150)
		throw(GradeTooLowException());
	else if (grade_e < 1)
		throw(GradeTooHighException());
	if (grade_s >= 150)
		throw(GradeTooLowException());
	else if (grade_s < 1)
		throw(GradeTooHighException());
		
}

AForm::AForm(const AForm& copy) : grade_sign(150), grade_ex(150)
{
	*this = copy;
}

AForm& AForm::operator = (const AForm& src)
{
	if (this != &src)
	{
		const_cast<std::string&>(this->name) = src.getName();
		const_cast<int&>(this->grade_ex) = src.getGradeToExecute();
		const_cast<int&>(this->grade_sign) = src.getGradeToSign();
		this->sign = src.getSigned();
	}
	return (*this);
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "The grade is too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "The grade is too low";
}

const char * AForm::FormNotSign::what() const throw()
{
	return "The Form isn't sign";
}

const std::string AForm::getTarget() const
{
	return (target);
}

const std::string AForm::getName() const
{
	return (name);
}

bool	AForm::getSigned() const
{
	return (sign);
}

int AForm::getGradeToSign() const
{
	return (grade_sign);
}

int AForm::getGradeToExecute() const
{
	return (grade_ex);
}

void	AForm::beSigned(Bureaucrat a)
{
	try
	{
		if (a.getGrade() >= 1 && a.getGrade() <= this->getGradeToSign())
			sign = true;
		else if (a.getGrade() < 1)
			throw(GradeTooHighException());
		else
			throw(GradeTooLowException());
	}
	catch(const GradeTooHighException& e)
	{
		std::cerr << e.what() << '\n';
	}
	catch(const GradeTooLowException& e)
	{
		std::cerr << e.what() << '\n';
	}
}

AForm::~AForm()
{
}

std::ostream& operator << (std::ostream& out, const AForm& info)
{
	out << "name: "<< info.getName()<<std::endl;
	out<<"grade to sign: "<< info.getGradeToSign()<<std::endl;
	out<<"grade to execute: "<< info.getGradeToExecute()<<std::endl;
	out<< std::boolalpha << "signed: "<< info.getSigned();
	return (out);
}