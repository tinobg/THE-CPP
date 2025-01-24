#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	std::cout << "--- Test 1: Default Constructor for Form ---" << std::endl;
	Form defaultForm;
	std::cout << defaultForm << std::endl;
	std::cout << std::endl;

	std::cout << "--- Test 2: Parameterized Constructor for Form ---" << std::endl;
	try {
		Form customForm("CustomForm", 50, 100);
		std::cout << customForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 3: Invalid Form Creation (Grade Too High) ---" << std::endl;
	try {
		Form invalidFormHigh("InvalidHigh", 0, 100);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 4: Invalid Form Creation (Grade Too Low) ---" << std::endl;
	try {
		Form invalidFormLow("InvalidLow", 151, 200);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 5: Bureaucrat Signs a Form ---" << std::endl;
	try {
		Bureaucrat alice("Alice", 50);
		Form formToSign("SignForm", 50, 100);
		alice.signForm(formToSign);
		std::cout << formToSign << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 6: Bureaucrat Fails to Sign a Form ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		Form difficultForm("DifficultForm", 50, 100);
		bob.signForm(difficultForm);
		std::cout << difficultForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 7: Copy Constructor for Form ---" << std::endl;
	try {
		Form originalForm("OriginalForm", 75, 100);
		Form copiedForm(originalForm);
		std::cout << "Original: " << originalForm << std::endl;
		std::cout << "Copy: " << copiedForm << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 8: Assignment Operator for Form ---" << std::endl;
	try {
		Form form1("Form1", 60, 120);
		Form form2("Form2", 90, 150);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "Form1: " << form1 << std::endl;
		std::cout << "Form2: " << form2 << std::endl;

		form2 = form1;

		std::cout << "After assignment:" << std::endl;
		std::cout << "Form1: " << form1 << std::endl;
		std::cout << "Form2: " << form2 << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 9: Increment and Decrement Bureaucrat Grade ---" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 2);
		std::cout << charlie << std::endl;

		charlie.incrementGrade();
		std::cout << "After increment: " << charlie << std::endl;

		charlie.decrementGrade();
		charlie.decrementGrade();
		std::cout << "After two decrements: " << charlie << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 10: Bureaucrat Creates Invalid Grade ---" << std::endl;
	try {
		Bureaucrat invalid("InvalidBureaucrat", 0);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat invalid("InvalidBureaucrat", 200);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
