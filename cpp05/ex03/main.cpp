#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "--- Test 1: Intern Creates Valid Forms ---" << std::endl;
    try {
        Intern intern;

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Backyard");
        std::cout << *shrubbery << std::endl;
        delete shrubbery;

        AForm* robotomy = intern.makeForm("robotomy request", "Robot");
        std::cout << *robotomy << std::endl;
        delete robotomy;

        AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *pardon << std::endl;
        delete pardon;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 2: Intern Creates Invalid Form ---" << std::endl;
    try {
        Intern intern;
        AForm* invalidForm = intern.makeForm("unknown form", "Target");
        delete invalidForm; // Shouldn't reach here
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 3: Bureaucrat Uses Forms Created by Intern ---" << std::endl;
    try {
        Intern intern;
        Bureaucrat alice("Alice", 1);

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Garden");
        AForm* robotomy = intern.makeForm("robotomy request", "Robot");
        AForm* pardon = intern.makeForm("presidential pardon", "Zaphod Beeblebrox");

        alice.signForm(*shrubbery);
        alice.executeForm(*shrubbery);

        alice.signForm(*robotomy);
        alice.executeForm(*robotomy);

        alice.signForm(*pardon);
        alice.executeForm(*pardon);

        delete shrubbery;
        delete robotomy;
        delete pardon;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 4: Bureaucrat Fails to Sign and Execute Forms ---" << std::endl;
    try {
        Intern intern;
        Bureaucrat bob("Bob", 150);

        AForm* shrubbery = intern.makeForm("shrubbery creation", "Park");

        bob.signForm(*shrubbery); // Should fail
        bob.executeForm(*shrubbery); // Shouldn't reach here

        delete shrubbery;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "--- Test 5: Polymorphism with Forms from Intern ---" << std::endl;
    try {
        Intern intern;
        Bureaucrat frank("Frank", 10);

        AForm* forms[3] = {
            intern.makeForm("shrubbery creation", "Shrubbery"),
            intern.makeForm("robotomy request", "Robot"),
            intern.makeForm("presidential pardon", "President")
        };

        for (int i = 0; i < 3; i++) {
            frank.signForm(*forms[i]);
            frank.executeForm(*forms[i]);
            delete forms[i];
        }
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
