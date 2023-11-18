#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const	std::string name;
		bool	sign;
		const	int grade_sign;
		const	int grade_ex;
		const	std::string target;
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
		class FormNotSign : public std::exception
		{
			public:
				const char * what() const throw();
		};
		AForm();
		AForm(std::string name, bool sign, int grade_s, int grade_e, std::string target);
		AForm(const AForm& copy);
		AForm& operator = (const AForm& src);
		const std::string getTarget() const;
		const std::string getName() const;
		bool	getSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void	beSigned(Bureaucrat a);
		virtual void	execute(Bureaucrat const & executor) = 0;
		virtual ~AForm();
};

std::ostream& operator << (std::ostream& out, const AForm& a);