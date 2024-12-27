#include <iostream>
#include <string>

int main() {
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "Address of brain:     " << &brain << std::endl;
	std::cout << "Address by stringPTR: " << stringPTR << std::endl;
	std::cout << "Address by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of brain:     " << brain << std::endl;
	std::cout << "Value by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value by stringREF: " << stringREF << std::endl;
}