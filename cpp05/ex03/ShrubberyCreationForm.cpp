#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other) {
	AForm::operator=(other);
	if (this != &other)
		this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

std::string const &ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw::AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	
	std::ofstream ofs((_target + "_Shrubbery").c_str());

	if (!ofs) {
		throw std::runtime_error("Failed to open file.");
	}
	
	ofs << "       ###\n";
	ofs << "      #o###\n";
	ofs << "    #####o###\n";
	ofs << "   #o#\\#|#/###\n";
	ofs << "    ###\\|/#o#\n";
	ofs << "     # }|{  #\n";
	ofs << "       }|{\n";
	
	ofs.close();
	std::cout << "Shrubbery Creation Form executed by " << executor.getName() << std::endl;
}