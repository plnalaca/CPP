#include "ScavTrap.hpp"

int main()
{
	std::cout << "===== TEST 1: Construction Chain =====" << std::endl;
	ScavTrap s1("s1");

	std::cout << std::endl << "===== TEST 2: ScavTrap Stats =====" << std::endl;
	std::cout << "HP: " << s1.getHitPoints() << std::endl;
	std::cout << "Energy: " << s1.getEnergyPoints() << std::endl;
	std::cout << "Attack: " << s1.getAttackDamage() << std::endl;

	std::cout << std::endl << "===== TEST 3: Different Attack Messages =====" << std::endl;
	ClapTrap c1("c1");
	c1.attack("target");
	s1.attack("target");

	std::cout << std::endl << "===== TEST 4: Inherited Functions =====" << std::endl;
	s1.takeDamage(30);
	std::cout << "HP after damage: " << s1.getHitPoints() << std::endl;
	s1.beRepaired(10);
	std::cout << "HP after repair: " << s1.getHitPoints() << std::endl;

	std::cout << std::endl << "===== TEST 5: Special Ability =====" << std::endl;
	s1.guardGate();

	std::cout << std::endl << "===== TEST 6: Orthodox Canonical Form =====" << std::endl;
	ScavTrap s2(s1);
	ClapTrap s3;
	s3 = c1;

	std::cout << std::endl << "===== TEST 7: Destruction Chain =====" << std::endl;
	return 0;
}
