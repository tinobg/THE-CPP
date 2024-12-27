#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string& name)
    : name(name), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Claptrap " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap()
    : name("Default"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Default ClapTrap has been created!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if(energyPoints > 0 && hitPoints > 0) {
        std::cout << "ClapTrap " << name << " attacks " << target
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
        energyPoints--;
    }   else {
        std::cout << "ClapTrap " << name << " is out of energy or hit points!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount) {
    hitPoints -= amount;
    if (hitPoints < 0) hitPoints = 0;
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (energyPoints > 0) {
        hitPoints += amount;
        energyPoints--;
        std::cout << "ClapTrap " << name << " repairs itself, recovering "
                  << amount << " hit points!" << std::endl;
    } else {
        std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;    
    }
}