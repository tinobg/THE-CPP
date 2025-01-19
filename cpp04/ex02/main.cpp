#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "===== Abstract Class Tests =====" << std::endl;
    // AAnimal* animal = new AAnimal();  // Uncommenting this should cause a compilation error

    const AAnimal* dog = new Dog();
    const AAnimal* cat = new Cat();

    dog->makeSound();  // Outputs: Woof woof!
    cat->makeSound();  // Outputs: Meow meow!

    delete dog;
    delete cat;

    std::cout << "\n===== Deep Copy Tests =====" << std::endl;
    Dog dog1;
    dog1.makeSound();
    {
        Dog dog2 = dog1;  // Deep copy
        dog2.makeSound();
    }  // dog2 is destroyed here

    std::cout << "\n===== Array of Animals =====" << std::endl;
    const int arraySize = 4;
    AAnimal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < arraySize; ++i) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < arraySize; ++i) {
        delete animals[i];
    }

    std::cout << "\n===== WrongAnimal Tests =====" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    wrongCat->makeSound();  // Outputs: This is a wrong sound!
    delete wrongCat;

    return 0;
}
