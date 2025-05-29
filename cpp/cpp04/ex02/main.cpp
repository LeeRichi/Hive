#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include "Brain.hpp"

int main() {
    // Animal a; // <----test here

    const int arraySize = 10;
    Animal* animals[arraySize];

    std::cout << "\n--- Creating Dogs and Cats ---" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
            // animals[i] = new Animal(); //or here
    }

    std::cout << "\n--- Making Sounds ---" << std::endl;
    for (int i = 0; i < arraySize; ++i)
        animals[i]->makeSound();

    std::cout << "\n--- Deleting Animals ---" << std::endl;
    for (int i = 0; i < arraySize; ++i)
        delete animals[i];

    std::cout << "\n--- Deep Copy Test ---" << std::endl;

    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "I am for sure a original Dog.");

    Dog copiedDog = originalDog; // copy constructor
    copiedDog.getBrain()->setIdea(0, "I guess I am the copy one.");

    std::cout << "Original Dog idea: " << originalDog.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Dog idea:   " << copiedDog.getBrain()->getIdea(0) << std::endl;

    Cat originalCat;
    originalCat.getBrain()->setIdea(0, "Climb the curtain");

    Cat copiedCat;
    copiedCat = originalCat; // copy assignment
    copiedCat.getBrain()->setIdea(0, "Nap in the sun");

    std::cout << "Original Cat idea: " << originalCat.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copied Cat idea:   " << copiedCat.getBrain()->getIdea(0) << std::endl;

    return 0;
}
