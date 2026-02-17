#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ARRAY_SIZE 10

int main()
{
	std::cout << "========== BASIC TEST (from subject) ==========" << std::endl;
	const Animal* d = new Dog();
	const Animal* c = new Cat();
	const Animal* meta = new Animal();

	delete d;
	delete c;
	delete meta;

	std::cout << std::endl;
	std::cout << "========== ANIMAL ARRAY TEST ==========" << std::endl;
	Animal* animals[ARRAY_SIZE];

	std::cout << "--- Creating animals ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		if (i < ARRAY_SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "--- Animal sounds ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << animals[i]->getType() << ": ";
		animals[i]->makeSound();
	}

	std::cout << std::endl;
	std::cout << "--- Deleting animals ---" << std::endl;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << "========== DEEP COPY TEST ==========" << std::endl;
	std::cout << "--- Creating original Dog ---" << std::endl;
	Dog* originalDog = new Dog();
	originalDog->getBrain()->setIdea(0, "I want to chase the ball!");
	originalDog->getBrain()->setIdea(1, "I love my owner!");

	std::cout << std::endl;
	std::cout << "--- Creating copy Dog (copy constructor) ---" << std::endl;
	Dog* copyDog = new Dog(*originalDog);

	std::cout << std::endl;
	std::cout << "Original Dog ideas:" << std::endl;
	std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "Copy Dog ideas:" << std::endl;
	std::cout << "  Idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << "--- Modifying copy Dog's ideas ---" << std::endl;
	copyDog->getBrain()->setIdea(0, "I want to sleep!");
	copyDog->getBrain()->setIdea(1, "Give me treats!");

	std::cout << "Original Dog ideas (should be unchanged):" << std::endl;
	std::cout << "  Idea 0: " << originalDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << originalDog->getBrain()->getIdea(1) << std::endl;

	std::cout << "Copy Dog ideas (modified):" << std::endl;
	std::cout << "  Idea 0: " << copyDog->getBrain()->getIdea(0) << std::endl;
	std::cout << "  Idea 1: " << copyDog->getBrain()->getIdea(1) << std::endl;

	std::cout << std::endl;
	std::cout << "--- Deleting dogs ---" << std::endl;
	delete originalDog;
	delete copyDog;

	std::cout << std::endl;
	std::cout << "========== ASSIGNMENT OPERATOR TEST ==========" << std::endl;
	std::cout << "--- Creating cats ---" << std::endl;
	Cat cat1;
	cat1.getBrain()->setIdea(0, "I want fish!");

	std::cout << std::endl;
	Cat cat2;
	cat2.getBrain()->setIdea(0, "I want to nap!");

	std::cout << std::endl;
	std::cout << "Before assignment:" << std::endl;
	std::cout << "  Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "--- Assigning cat1 = cat2 ---" << std::endl;
	cat1 = cat2;

	std::cout << std::endl;
	std::cout << "After assignment:" << std::endl;
	std::cout << "  Cat1 idea 0: " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "  Cat2 idea 0: " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "--- Modifying cat2's idea ---" << std::endl;
	cat2.getBrain()->setIdea(0, "I changed my mind!");

	std::cout << "Cat1 idea 0 (should be unchanged): " << cat1.getBrain()->getIdea(0) << std::endl;
	std::cout << "Cat2 idea 0 (modified): " << cat2.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "========== END OF TESTS ==========" << std::endl;

	return 0;
}
