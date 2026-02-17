#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "========== POLYMORPHISM TEST ==========" << std::endl;
	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << std::endl;
	std::cout << "Dog type: " << d->getType() << std::endl;
	std::cout << "Cat type: " << c->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "Cat makes sound: ";
	c->makeSound();
	std::cout << "Dog makes sound: ";
	d->makeSound();
	std::cout << "Animal makes sound: ";
	a->makeSound();

	std::cout << std::endl;
	delete a;
	delete d;
	delete c;

	std::cout << std::endl;
	std::cout << "========== WRONG ANIMAL TEST ==========" << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << std::endl;
	std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
	std::cout << std::endl;

	std::cout << "WrongCat makes sound (via WrongAnimal pointer): ";
	wrongCat->makeSound();
	std::cout << "WrongAnimal makes sound: ";
	wrongMeta->makeSound();

	std::cout << std::endl;
	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl;
	std::cout << "========== ADDITIONAL TESTS ==========" << std::endl;

	Dog myDog;
	Cat myCat;
	
	std::cout << std::endl;
	std::cout << "Direct Dog sound: ";
	myDog.makeSound();
	std::cout << "Direct Cat sound: ";
	myCat.makeSound();

	std::cout << std::endl;

	Dog copyDog(myDog);
	std::cout << "Copy Dog type: " << copyDog.getType() << std::endl;
	std::cout << "Copy Dog voice: ";
    copyDog.makeSound();

	std::cout << std::endl;

	Cat anotherCat;
	anotherCat = myCat;
	std::cout << "Assigned Cat type: " << anotherCat.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "========== END OF TESTS ==========" << std::endl;

	return 0;
}
