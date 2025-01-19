#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
	type = other.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	if (this != &other)
		type = other.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::makeSound() const
{
	std::cout << "Some animal sound!" << std::endl;
}