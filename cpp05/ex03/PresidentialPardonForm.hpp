#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
		void	execute(Bureaucrat const & executor);
		~PresidentialPardonForm();
};
