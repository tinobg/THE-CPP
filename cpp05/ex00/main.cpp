#include "Bureaucrat.hpp"

int main() {
	std::cout << "--- Test 1: Default Constructor ---" << std::endl;
	Bureaucrat defaultBureaucrat;
	std::cout << std::endl;

	std::cout << "--- Test 2: Parameterized Constructor ---" << std::endl;
	try {
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 3: Increment and Decrement Grade ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 149);
		std::cout << bob << std::endl;

		bob.decrementGrade(); // Grade becomes 150
		std::cout << "After decrement: " << bob << std::endl;

		bob.incrementGrade(); // Grade becomes 149
		std::cout << "After increment: " << bob << std::endl;
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 4: GradeTooHighException ---" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		std::cout << charlie << std::endl;
		charlie.incrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 5: GradeTooLowException ---" << std::endl;
	try {
		Bureaucrat dave("Dave", 150);
		std::cout << dave << std::endl;
		dave.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 6: Copy Constructor ---" << std::endl;
	try {
		Bureaucrat eve("Eve", 50);
		Bureaucrat copyOfEve(eve);
		std::cout << "Original: " << eve << std::endl;
		std::cout << "Copy: " << copyOfEve << std::endl;
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 7: Assignment Operator ---" << std::endl;
	try {
		Bureaucrat frank("Frank", 100);
		Bureaucrat greg("Greg", 120);
		std::cout << "Before assignment: " << frank << " and " << greg << std::endl;
		frank = greg;
		std::cout << "After assignment: " << frank << std::endl;
		std::cout << std::endl;
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 8: Invalid Constructor (Too High) ---" << std::endl;
	try {
		Bureaucrat invalidHigh("InvalidHigh", 0);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "--- Test 9: Invalid Constructor (Too Low) ---" << std::endl;
	try {
		Bureaucrat invalidLow("InvalidLow", 200);
	} catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
