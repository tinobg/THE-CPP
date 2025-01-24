#ifndef INTERN_HPP
#define INTERN_HPP
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
	public:
	Intern();
	Intern(Intern const &other);
	Intern &operator=(Intern const &other);
	~Intern();
	AForm* makeForm(std::string const &formName, std::string const &target) const;
	
	class UnknownFormException : public std::exception {
	public:
		const char* what() const throw(); 
	};
};

#endif
