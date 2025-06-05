#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

//delete what ever is created btw.

// int main()
// {
// 	const Animal* notSureWhatThisIs = new Animal();
// 	const Animal* dog1 = new Dog();
// 	const Animal* cat1 = new Cat();
// 	std::cout << dog1->getType() << " " << std::endl;
// 	std::cout << cat1->getType() << " " << std::endl;
//     dog1->makeSound();
//     cat1->makeSound();
//     notSureWhatThisIs->makeSound();
// 	return 0;
// }

//<=== from suject ===>
// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// ...
// return 0;
// }

//<=== from suject but with Wrong animal or cat ===>
int main()
{
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const Animal* j = new Dog();
    const WrongAnimal* i = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound! //not anymore
    j->makeSound();
    wrongMeta->makeSound();
    // ...
    return 0;
}
