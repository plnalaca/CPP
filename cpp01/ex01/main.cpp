#include "Zombie.hpp"

int main(void)
{
	int hordeSize = 5;
	
	std::cout << "=== Creating Zombie Horde ===" << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "HordeZombie");
	
	std::cout << "\n=== Announcing All Zombies ===" << std::endl;
	for (int i = 0; i < hordeSize; i++)
	{
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}
	
	std::cout << "\n=== Destroying Horde ===" << std::endl;
	delete[] horde;
	horde = NULL;
	
	std::cout << "\n=== Test 2: Larger Horde ===" << std::endl;
	Zombie* bigHorde = zombieHorde(10, "BigHorde");
	
	for (int i = 0; i < 10; i++)
	{
		bigHorde[i].announce();
	}
	
	delete[] bigHorde;
	bigHorde = NULL;
	
	std::cout << "\n=== Program Ending ===" << std::endl;
	return 0;
}
