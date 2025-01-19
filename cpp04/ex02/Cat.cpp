#include "Cat.hpp"

Cat::Cat() : AAnimal()
{
	brain = new Brain();
	type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other)
{
	brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
	AAnimal::operator=(other);
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow meow!" << std::endl;
}