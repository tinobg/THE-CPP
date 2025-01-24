#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "--- Test 1: Form Creation ---" << std::endl;
    try {
        ShrubberyCreationForm shrubbery("Garden");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 2: Bureaucrat Signs Forms ---" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        ShrubberyCreationForm shrubbery("Park");
        alice.signForm(shrubbery);
        std::cout << shrubbery << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Bureaucrat Fails to Sign Form ---" << std::endl;
    try {
        Bureaucrat bob("Bob", 150);
        ShrubberyCreationForm shrubbery("Forest");
        bob.signForm(shrubbery);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Form Execution ---" << std::endl;
    try {
        Bureaucrat charlie("Charlie", 45);
        RobotomyRequestForm robotomy("Robot");
        charlie.signForm(robotomy);
        charlie.executeForm(robotomy);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 5: Execution Without Signing ---" << std::endl;
    try {
        Bureaucrat dave("Dave", 30);
        PresidentialPardonForm pardon("Ford Prefect");
        dave.executeForm(pardon); // Should throw FormNotSignedException
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 6: Execution with Insufficient Grade ---" << std::endl;
    try {
        Bureaucrat eve("Eve", 150);
        ShrubberyCreationForm shrubbery("Backyard");
        eve.signForm(shrubbery); // Should throw GradeTooLowException for signing
        eve.executeForm(shrubbery); // Shouldn't reach here
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 7: Polymorphism with Forms ---" << std::endl;
    try {
        Bureaucrat frank("Frank", 1);
        AForm* forms[3] = {
            new ShrubberyCreationForm("Shrubbery"),
            new RobotomyRequestForm("Robot"),
            new PresidentialPardonForm("President")
        };

        for (int i = 0; i < 3; i++) {
            frank.signForm(*forms[i]);
            frank.executeForm(*forms[i]);
            delete forms[i];
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
