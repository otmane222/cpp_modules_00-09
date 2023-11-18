#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery", 0, 145, 137, target)
{
	(void)target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
{
	(void)copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	(void)src;
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if (this->getGradeToExecute() < executor.getGrade() || executor.getGrade() < 0)
		throw(GradeTooLowException());
	if (!this->getSigned())
		throw(FormNotSign());
	std::ofstream	outputFile(executor.getName() + "_shrubbery");
	if (!outputFile)
		std::cerr << "Error: Unable to create file." << std::endl;
	else
	{
		outputFile <<"                                                         ."<<std::endl;
		outputFile <<"                                              .         ;"<<std::endl;
		outputFile <<"                 .              .              ;%     ;;"<<std::endl;
		outputFile <<"                   ,           ,                :;%  %;"<<std::endl;
		outputFile <<"                    :         ;                   :;%;'     .,"<<std::endl;
		outputFile <<"           ,.        %;     %;            ;        %;'    ,;"<<std::endl;
		outputFile <<"             ;       ;%;  %%;        ,     %;    ;%;    ,%'"<<std::endl;
		outputFile <<"              %;       %;%;      ,  ;       %;  ;%;   ,%;'"<<std::endl;
		outputFile <<"               ;%;      %;        ;%;        % ;%;  ,%;'"<<std::endl;
		outputFile <<"                `%;.     ;%;     %;'         `;%%;.%;'"<<std::endl;
		outputFile <<"                 `:;%.    ;%%. %@;        %; ;@%;%'"<<std::endl;
		outputFile <<"                    `:%;.  :;bd%;          %;@%;'"<<std::endl;
		outputFile <<"                      `@%:.  :;%.         ;@@%;'"<<std::endl;
		outputFile <<"                        `@%.  `;@%.      ;@@%;"<<std::endl;
		outputFile <<"                          `@%%. `@%%    ;@@%;"<<std::endl;
		outputFile <<"                            ;@%. :@%%  %@@%;"<<std::endl;
		outputFile <<"                              %@bd%%%bd%%:;"<<std::endl;
		outputFile <<"                                #@%%%%%:;;"<<std::endl;
		outputFile <<"                                %@@%%%::;"<<std::endl;
		outputFile <<"                                %@@@%(o);  . '"<<std::endl;
		outputFile <<"                                %@@@o%;:(.,'"<<std::endl;
		outputFile <<"                            `.. %@@@o%::;"<<std::endl;
		outputFile <<"                               `)@@@o%::;"<<std::endl;
		outputFile <<"                                %@@(o)::;"<<std::endl;
		outputFile <<"                               .%@@@@%::;"<<std::endl;
		outputFile <<"                               ;%@@@@%::;."<<std::endl;
		outputFile <<"                              ;%@@@@%%:;;;."<<std::endl;
		outputFile <<"                          ...;%@@@@@%%:;;;;,."<<std::endl;
		outputFile.close();
	}
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
