#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is created!" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " is created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap " << _name << " is copied!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << _name << " is destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no hit points and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a high five!" << std::endl;
}
