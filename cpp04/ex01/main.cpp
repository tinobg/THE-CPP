#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// int main()
// {
// 	// std::cout << std::endl;
// 	// std::cout << "-----------------------------------------------------" << std::endl;
// 	// std::cout << std::endl;

// 	// std::cout << "Basic tests:" << std::endl;
// 	// std::cout << std::endl;
// 	// const Animal* j = new Dog();
// 	// const Animal* i = new Cat();

// 	// std::cout << j->getType() << " makes a sound: ";
// 	// j->makeSound();

// 	// std::cout << i->getType() << " makes a sound: ";
// 	// i->makeSound();

// 	// delete j;
// 	// delete i;

// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------------------" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Deep copy and assignments tests:" << std::endl;
// 	std::cout << std::endl;
	
// 	Dog basic;
// 	{
// 		Dog tmp = basic;
// 	}
	
// 	std::cout << std::endl;
// 	std::cout << "-----------------------------------------------------" << std::endl;
// 	std::cout << std::endl;

// 	std::cout << "Array tests:" << std::endl;
// 	std::cout << std::endl;
	
// 	Animal *animals[4];

// 	std::cout << std::endl;

// 	animals[0] = new Dog();
// 	animals[1] = new Cat();
// 	animals[2] = new Dog();
// 	animals[3] = new Cat();

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++) {
// 		std::cout << animals[i]->getType() << " makes a sound: ";
// 		animals[i]->makeSound();
// 	}

// 	std::cout << std::endl;

// 	for (int i = 0; i < 4; i++)
// 		delete animals[i];

// 	return 0;
// }

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
    std::cout << "========== BASIC TESTS ==========" << std::endl;

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();

    std::cout << cat->getType() << " says: ";
    cat->makeSound();

    delete dog;
    delete cat;

    std::cout << "\n========== DEEP COPY TESTS ==========" << std::endl;

    Dog originalDog;
    originalDog.makeSound();
    
    // Set some ideas in the Dog's Brain (if Brain has get/set methods)
    // Uncomment the following lines if you implement setIdea/getIdea in Brain
    // originalDog.setBrainIdea(0, "I want to play!");
    // originalDog.setBrainIdea(1, "Where's my ball?");

    {
        Dog copiedDog = originalDog;  // Deep copy
        std::cout << "Copied Dog says: ";
        copiedDog.makeSound();

        // Verify the Brain is deeply copied
        // Uncomment the following lines if you implement setIdea/getIdea in Brain
        // std::cout << "Original Dog Idea: " << originalDog.getBrainIdea(0) << std::endl;
        // std::cout << "Copied Dog Idea: " << copiedDog.getBrainIdea(0) << std::endl;

        // Modify copied dog's Brain
        // copiedDog.setBrainIdea(0, "I want food!");
        // std::cout << "After Modification:" << std::endl;
        // std::cout << "Original Dog Idea: " << originalDog.getBrainIdea(0) << std::endl;
        // std::cout << "Copied Dog Idea: " << copiedDog.getBrainIdea(0) << std::endl;
    }

    std::cout << "Temporary copied Dog is destroyed here.\n";

    std::cout << "\n========== ARRAY TESTS ==========" << std::endl;

    Animal* animals[4];
    for (int i = 0; i < 4; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i) {
        delete animals[i];
    }

    std::cout << "\n========== WRONG ANIMAL TESTS ==========" << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << " says: ";
    wrongCat->makeSound();  // Calls WrongAnimal's makeSound due to no virtual keyword

    delete wrongCat;

    std::cout << "\n========== CLEANUP COMPLETE ==========" << std::endl;

    return 0;
}
