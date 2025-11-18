#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName) : name(zombieName)
{
	std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
