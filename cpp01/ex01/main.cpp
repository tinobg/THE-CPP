#include "Zombie.hpp"
#include <iostream>

int main() {
	int numberOfZombies = 5;
	Zombie* horde = zombieHorde(numberOfZombies, "HordeZombie");

	if (!horde) {
		std::cerr << "Failed to create the zombie horde!" << std::endl;
		return 1;
	}
	for (int i = 0; i < numberOfZombies; ++i) {
		horde[i].announce();
	}
	delete[] horde;
	return 0;
}