#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");
	ScavTrap scavtrap("Scavvy");
	FragTrap fragtrap("Fraggy");

	std::cout << std::endl;

	claptrap.attack("a random target");
	scavtrap.attack("a random target");
	fragtrap.attack("a random target");

	std::cout << std::endl;

	std::cout << std::endl << "Demonstrating special capabilities: " << std::endl;
	scavtrap.guardGate();
	fragtrap.highFivesGuys();

	std::cout << std::endl << "Dealing damage to all:" << std::endl;
	claptrap.takeDamage(0);
	scavtrap.takeDamage(20);
	fragtrap.takeDamage(30);

	std::cout << std::endl << "Repairing all:" << std::endl;
	claptrap.beRepaired(5);
	scavtrap.beRepaired(10);
	fragtrap.beRepaired(15);

	std::cout << std::endl;
	return 0;
}