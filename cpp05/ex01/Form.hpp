#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const	std::string name;
		bool	sign;
		const	int grade_sign;
		const	int grade_ex;
	public:
		class GradeTooHighException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char * what() const throw();
		};
		Form();
		Form(std::string name, bool sign, int grade_s, int grade_e);
		Form(const Form& copy);
		Form& operator = (const Form& src);
		std::string getName() const;
		bool	getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void	beSigned(Bureaucrat a);
		~Form();
};

std::ostream& operator << (std::ostream& out, const Form& a);