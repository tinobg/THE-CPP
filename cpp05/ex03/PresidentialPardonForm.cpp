#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) 
	: AForm(other), _target(other._target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
	AForm::operator=(other);
	if (this != &other)
		this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

std::string const &PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}