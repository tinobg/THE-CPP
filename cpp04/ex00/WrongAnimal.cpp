#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal") {
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	type = other.type;
	std::cout << "Wrong Animal copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other)
		type = other.type;
	std::cout << "Wrong Animal assigment constructor called" << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
	std::cout << "This is a wrong sound!" << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}