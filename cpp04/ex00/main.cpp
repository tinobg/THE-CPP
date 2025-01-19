#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    // Polymorphism demonstration
    const Animal* meta = new Animal();  // Base class instance
    const Animal* dog = new Dog();      // Derived class instance
    const Animal* cat = new Cat();      // Derived class instance

    std::cout << "Animal Type: " << meta->getType() << std::endl;
    std::cout << "Dog Type: " << dog->getType() << std::endl;
    std::cout << "Cat Type: " << cat->getType() << std::endl;

    meta->makeSound();  // Calls Animal's makeSound
    dog->makeSound();   // Calls Dog's overridden makeSound
    cat->makeSound();   // Calls Cat's overridden makeSound

    delete meta;
    delete dog;
    delete cat;

    std::cout << "-------------------------------------------" << std::endl;

    // Demonstrating behavior without polymorphism
    const WrongAnimal* wrongMeta = new WrongAnimal();  // Base class instance
    const WrongAnimal* wrongCat = new WrongCat();      // Derived class instance

    std::cout << "WrongAnimal Type: " << wrongMeta->getType() << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << std::endl;

    wrongMeta->makeSound();  // Calls WrongAnimal's makeSound
    wrongCat->makeSound();   // Also calls WrongAnimal's makeSound (not polymorphic)

    delete wrongMeta;
    delete wrongCat;

    return 0;
}