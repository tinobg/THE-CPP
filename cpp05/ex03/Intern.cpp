#include "Intern.hpp"

Intern::Intern() {
	
}

Intern::Intern(Intern const &other) {
	*this = other;
}

Intern &Intern::operator=(Intern const &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
	
}

const char *Intern::UnknownFormException::what() const throw() {
	return "Error: Unknown form requested.";
}

AForm* createShrubberyForm(std::string const &target) {
	return new ShrubberyCreationForm(target);
}

AForm* createRobotomyForm(std::string const &target) {
	return new RobotomyRequestForm(target);
}

AForm* createPardonForm(std::string const &target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string const &formName, std::string const &target) const {
	std::string const formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formCreators[])(const std::string&) = {createShrubberyForm, createRobotomyForm, createPardonForm};

	for (int i = 0; i < 3; ++i) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formNames[i] << " form targeting " << target << std::endl;
			return formCreators[i](target);
		}
	}
	
	throw Intern::UnknownFormException();
}