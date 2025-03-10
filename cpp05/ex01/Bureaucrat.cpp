#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << "Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	checkGrade(other._grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		this->_grade = other._grade;
		checkGrade(this->_grade);
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destruction constructor called" << std::endl;
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	checkGrade(_grade - 1);
	_grade--;
}

void Bureaucrat::decrementGrade() {
	checkGrade(_grade + 1);
	_grade++;
}

void Bureaucrat::checkGrade(int grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

void Bureaucrat::signForm(Form &form) {
	try
	{
		form.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << _name << " signed " << form.getName() << std::endl;
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bureaucrat) {
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}