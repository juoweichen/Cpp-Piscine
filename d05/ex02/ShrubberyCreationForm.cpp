#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : Form("default Shrubbery", 145, 137){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) :
	Form(src.getName(), 145, 137)
{
	*this = src;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ): Form(target, 145, 137){}
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == true && executor.getGrade() <= this->getExecuteGrade())
	{
		std::string		file = getName() + "_shrubbery";
		std::ofstream	ofs(file);

		ofs << "                                                         ." << std::endl
			<< "                                              .         ;  " << std::endl
			<< "                 .              .              ;%     ;;  " << std::endl
			<< "                   ,           ,                :;%  %; " << std::endl
			<< "                    :         ;                   :;%;'     .,  " << std::endl
			<< "           ,.        %;     %;            ;        %;'    ,;" << std::endl
			<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl
			<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl
			<< "               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl
			<< "                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl
			<< "                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl
			<< "                    `:%;.  :;bd%;          %;@%;'" << std::endl
			<< "                      `@%:.  :;%.         ;@@%;'  " << std::endl
			<< "                        `@%.  `;@%.      ;@@%;      " << std::endl
			<< "                          `@%%. `@%%    ;@@%;       " << std::endl
			<< "                            ;@%. :@%%  %@@%;       " << std::endl
			<< "                              %@bd%%%bd%%:;     " << std::endl
			<< "                                #@%%%%%:;;" << std::endl
			<< "                                %@@%%%::;" << std::endl
			<< "                                %@@@%(o);  . '  " << std::endl
			<< "                                %@@@o%;:(.,'   " << std::endl
			<< "                            `.. %@@@o%::;    " << std::endl
			<< "                               `)@@@o%::;   " << std::endl
			<< "                                %@@(o)::;      " << std::endl
			<< "                               .%@@@@%::;      " << std::endl
			<< "                               .%@@@@%::;      " << std::endl
			<< "                              ;%@@@@%%:;;;. " << std::endl
			<< "                          ...;%@@@@@%%:;;;;,..   " << std::endl;
			ofs.close();
		std::cout << "Shrubbery Send" << std::endl;
	}
	else if (this->getIsSigned() == false)
		throw Form::GradeTooLowException();
	else if (executor.getGrade() > this->getExecuteGrade())
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & o, ShrubberyCreationForm const & rhs )
{
	o << "ShrubberyCreationForm: " << std::endl
		<< "Name: " << rhs.getName() << std::endl
		<< "Signed grade: " << rhs.getSignGrade() << std::endl
		<< "execute grade: " << rhs.getSignGrade() << std::endl;
	if (rhs.getSignGrade())
		o << "ShrubberyCreationForm has been signed." << std::endl;
	else
		o << "ShrubberyCreationForm has not yet been signed." << std::endl;
	return o;
}