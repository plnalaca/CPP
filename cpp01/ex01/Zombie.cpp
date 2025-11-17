#include "Zombie.hpp"

Zombie::Zombie()
{
	name = "Unnamed";
	std::cout << name << " is created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " is destroyed" << std::endl;
}

void Zombie::announce()
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string zombieName)
{
	name = zombieName;
}
