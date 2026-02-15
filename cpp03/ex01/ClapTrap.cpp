#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << _name << " is created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << _name << " is copied!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << _name << " is destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points and can't attack!" << std::endl;
		return;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return;
	}
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage and is now dead!" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! Remaining HP: " << _hitPoints << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no hit points and can't repair!" << std::endl;
		return;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points and can't repair!" << std::endl;
		return;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " repairs itself, recovering " << amount << " hit points! Current HP: " << _hitPoints << std::endl;
}

std::string ClapTrap::getName() const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}
