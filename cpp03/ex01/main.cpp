
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ClapTrap claptrap("Clappy");

	std::cout << std::endl;

	claptrap.attack("EnemyBot");
	claptrap.takeDamage(10);
	claptrap.attack("EnemyBot");
	claptrap.beRepaired(5);
	
	std::cout << std::endl;

	ScavTrap scavtrap("Scavvy");

	std::cout << std::endl;

	scavtrap.attack("RivalBot");
	scavtrap.takeDamage(101);
	scavtrap.attack("RivalBot");
	scavtrap.beRepaired(100);
	scavtrap.attack("RivalBot");
	scavtrap.guardGate();

	std::cout << std::endl;

	return 0;
}