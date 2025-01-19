#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	type = "Wrong Cat";
	std::cout << "Wrong Cat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "rong Cat copy constructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	if (this != &other)
		type = other.type;
	std::cout << "Wrong Cat assigment constructor called" << std::endl;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Wrong Cat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "Wrong Meow!" << std::endl;
}