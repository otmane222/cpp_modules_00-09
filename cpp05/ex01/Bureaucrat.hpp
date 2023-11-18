#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int	grade;
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
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator = (const Bureaucrat& src);
		int getGrade() const;
		std::string getName() const;
		void	increment();
		void	decrement();
		void	signForm(Form form) const;
		~Bureaucrat();
};

std::ostream& operator << (std::ostream& out, const Bureaucrat& a);