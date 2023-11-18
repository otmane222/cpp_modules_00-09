#include "Form.hpp"


Form::Form() :  name("noname"), sign(false), grade_sign(150) ,grade_ex(150)
{
}

Form::Form(std::string name, bool sign, int grade_s, int grade_e) : name(name), sign(sign), \
				grade_sign(grade_s), grade_ex(grade_e)
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

Form::Form(const Form& copy) : grade_sign(0), grade_ex(0)
{
	*this = copy;
}

Form& Form::operator = (const Form& src)
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


const char * Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low";
}

std::string Form::getName() const
{
	return (name);
}
bool	Form::getSigned() const
{
	return (sign);
}
int Form::getGradeToSign() const
{
	return (grade_sign);
}
int Form::getGradeToExecute() const
{
	return (grade_ex);
}

void	Form::beSigned(Bureaucrat a)
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

Form::~Form()
{
	// std::cout<<"Destructor Called"<<std::endl;
}

std::ostream& operator << (std::ostream& out, const Form& info)
{
	out << "name: "<< info.getName()<<std::endl;
	out<<"grade to sign: "<< info.getGradeToSign()<<std::endl;
	out<<"grade to execute: "<< info.getGradeToExecute()<<std::endl;
	out<< std::boolalpha << "signed: "<< info.getSigned();
	return (out);
}