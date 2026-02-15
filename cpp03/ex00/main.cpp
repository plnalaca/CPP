#include "ClapTrap.hpp"

int main()
{
	std::cout << "===== Create Robots =====" << std::endl;
	ClapTrap clap1;
	ClapTrap clap2("robot1");
	ClapTrap clap3(clap2);
	ClapTrap clap4;
	clap4 = clap2;

	std::cout << std::endl << "===== Attack Test (Energy drops) =====" << std::endl;
	std::cout << "Energy before: " << clap2.getEnergyPoints() << std::endl;
	clap2.attack("Pelin");
	std::cout << "Energy after: " << clap2.getEnergyPoints() << std::endl;

	std::cout << std::endl << "===== Take Damage Test =====" << std::endl;
	std::cout << "HP before: " << clap2.getHitPoints() << std::endl;
	clap2.takeDamage(3);
	std::cout << "HP after: " << clap2.getHitPoints() << std::endl;

	std::cout << std::endl << "===== Repair Test (Energy drops, HP rises) =====" << std::endl;
	std::cout << "HP: " << clap2.getHitPoints() << " | Energy: " << clap2.getEnergyPoints() << std::endl;
	clap2.beRepaired(2);
	std::cout << "HP: " << clap2.getHitPoints() << " | Energy: " << clap2.getEnergyPoints() << std::endl;

	std::cout << std::endl << "===== Energy cannot go below 0 =====" << std::endl;
	ClapTrap clap5("EnergyTest");
	std::cout << "Starting energy: " << clap5.getEnergyPoints() << std::endl;
	for (int i = 0; i < 12; i++)
	{
		clap5.attack("palaca");
		std::cout << "Energy: " << clap5.getEnergyPoints() << std::endl;
	}

	std::cout << std::endl << "===== HP cannot go below 0 =====" << std::endl;
	ClapTrap clap6("HPTest");
	std::cout << "Starting HP: " << clap6.getHitPoints() << std::endl;
	clap6.takeDamage(100);
	std::cout << "HP after 100 damage: " << clap6.getHitPoints() << std::endl;
	clap6.takeDamage(50);
	std::cout << "HP after another 50 damage: " << clap6.getHitPoints() << std::endl;
	clap6.attack("Dummy");
	clap6.beRepaired(10);

	std::cout << std::endl << "===== Destruction (reverse order) =====" << std::endl;
	return 0;
}
