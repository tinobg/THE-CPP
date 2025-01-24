#include "AForm.hpp"

AForm::AForm() : _name("Default"), _issigned(false), _gradeSign(150), _gradeExec(150) {
}

AForm::AForm(std::string const name, int const gradeSign, int const gradeExec) : _name(name), _issigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
	
}

AForm::AForm(AForm const &other) : _name(other._name), _issigned(other._issigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
	
}

AForm &AForm::operator=(AForm const &other) {
	_issigned = other._issigned;
	return *this;
}

AForm::~AForm() {
}

std::string AForm::getName() const {
	return _name;
}

int AForm::getGradeExec() const {
	return _gradeExec;
}

int AForm::getGradeSign() const {
	return _gradeSign;
}

bool AForm::getSigned() const {
	return _issigned;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form not signed!");
}

void AForm::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeSign)
		_issigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << "Form name: " << AForm.getName()
		<< " - Is signed: " << (AForm.getSigned() ? "Yes" : "No")
		<< " - Grade required to sign: " << AForm.getGradeSign()
		<< " - Grade required to execute: " << AForm.getGradeExec(); 
	return os;
}
