#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

class RobotomyRequestForm : public AForm {
	private:
	std::string _target;

	public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);
	RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
	virtual ~RobotomyRequestForm();

	std::string const &getTarget() const;

	virtual void execute(Bureaucrat const &executor) const;
};

#endif