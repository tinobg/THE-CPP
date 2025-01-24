#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
	std::string const _name;
	bool _issigned;
	int const _gradeSign;
	int const _gradeExec;

	public:
	Form();
	Form(std::string const name, int const gradeSign, int const gradeExec);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void 		beSigned(Bureaucrat const &bureaucrat);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &os, const Form &Form);

#endif