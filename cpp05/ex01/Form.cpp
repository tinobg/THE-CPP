#include "Form.hpp"

Form::Form() : _name("Default"), _issigned(false), _gradeSign(150), _gradeExec(150) {
	std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string const name, int const gradeSign, int const gradeExec)
    : _name(name), _issigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (gradeSign < 1 || gradeExec < 1)
        throw GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(Form const &other) : _name(other._name), _issigned(other._issigned), _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
	std::cout << "Form copy constructor called for: " << other._name << std::endl;
}


Form &Form::operator=(Form const &other) {
	if (this != &other) {
		_issigned = other._issigned;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Destruction constructor called" << std::endl;
}

std::string Form::getName() const {
	return _name;
}

int Form::getGradeExec() const {
	return _gradeExec;
}

int Form::getGradeSign() const {
	return _gradeSign;
}

bool Form::getSigned() const {
	return _issigned;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Form::beSigned(Bureaucrat const &bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeSign)
		_issigned = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
    os	<< "Form name: " << form.getName()
		<< " - Is signed: " << (form.getSigned() ? "Yes" : "No")
		<< " - Grade required to sign: " << form.getGradeSign()
		<< " - Grade required to execute: " << form.getGradeExec();
	return os;
}
