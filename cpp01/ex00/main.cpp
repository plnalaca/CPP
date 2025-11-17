#include "Zombie.hpp"

int main(void)
{
	std::cout << "=== Test 1: HEAP Allocation (newZombie) ===" << std::endl;
	Zombie* heapZombie = newZombie("Heap Harry");
	heapZombie->announce();
	delete heapZombie;
	heapZombie = NULL;
	
	std::cout << "\n=== Test 2: STACK Allocation (randomChump) ===" << std::endl;
	randomChump("Stack Steve");

	
	std::cout << "\n=== Test 3: Multiple Heap Zombies ===" << std::endl;
	Zombie* z1 = newZombie("Zombie1");
	Zombie* z2 = newZombie("Zombie2");
	Zombie* z3 = newZombie("Zombie3");
	
	z1->announce();
	z2->announce();
	z3->announce();
	
	delete z1;
	z1 = NULL;
	delete z2;
	z2 = NULL;
	delete z3;
	z3 = NULL;
	
	std::cout << "\n=== Test 4: Multiple Stack Zombies ===" << std::endl;
	randomChump("StackZombie1");
	randomChump("StackZombie2");
	randomChump("StackZombie3");
	
	std::cout << "\n=== Test 5: MIXED - Heap and Stack Together ===" << std::endl;
	Zombie* heapMixed1 = newZombie("HeapMixed1");
	
	randomChump("StackMixed1");
	heapMixed1->announce();
	
	Zombie* heapMixed2 = newZombie("HeapMixed2");
	heapMixed2->announce();
	delete heapMixed2;
	heapMixed2 = NULL;

	randomChump("StackMixed2");

	delete heapMixed1;
	heapMixed1 = NULL;
	
	std::cout << "\n=== Program Ending ===" << std::endl;
	return 0;
}
