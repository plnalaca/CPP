#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "===== Create Robots =====" << std::endl;
	ClapTrap c1("c1");
	ScavTrap s1("s1");
	FragTrap f1("f1");

	std::cout << std::endl << "===== Stats Comparison =====" << std::endl;
	std::cout << "ClapTrap c1 - HP: " << c1.getHitPoints() << " | Energy: " << c1.getEnergyPoints() << " | Attack: " << c1.getAttackDamage() << std::endl;
	std::cout << "ScavTrap s1 - HP: " << s1.getHitPoints() << " | Energy: " << s1.getEnergyPoints() << " | Attack: " << s1.getAttackDamage() << std::endl;
	std::cout << "FragTrap f1 - HP: " << f1.getHitPoints() << " | Energy: " << f1.getEnergyPoints() << " | Attack: " << f1.getAttackDamage() << std::endl;

	std::cout << std::endl << "===== Attack Comparison =====" << std::endl;
	c1.attack("target");
	s1.attack("target");
	f1.attack("target");

	std::cout << std::endl << "===== FragTrap Inherited Functions =====" << std::endl;
	f1.takeDamage(30);
	std::cout << "HP after damage: " << f1.getHitPoints() << std::endl;
	f1.beRepaired(10);
	std::cout << "HP after repair: " << f1.getHitPoints() << std::endl;

	std::cout << std::endl << "===== Special Abilities =====" << std::endl;
	s1.guardGate();
	f1.highFivesGuys();

	std::cout << std::endl << "===== Destruction Order =====" << std::endl;
	return 0;
}
