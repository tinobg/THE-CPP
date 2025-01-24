#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
	std::string const _name;
	bool _issigned;
	int const _gradeSign;
	int const _gradeExec;

	public:
	AForm();
	AForm(std::string const name, int const gradeSign, int const gradeExec);
	AForm(AForm const &other);
	AForm &operator=(AForm const &other);
	virtual ~AForm();

	std::string getName() const;
	bool		getSigned() const;
	int			getGradeSign() const;
	int			getGradeExec() const;
	void 		beSigned(Bureaucrat const &bureaucrat);

	virtual void execute(Bureaucrat const &executor) const = 0;

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
	
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &AForm);

#endif