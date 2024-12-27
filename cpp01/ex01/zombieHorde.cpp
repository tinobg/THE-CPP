#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return NULL;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; ++i) {
		std::ostringstream numberedName;
		numberedName << name << (i + 1);
		horde[i].setName(numberedName.str());
	}
	return horde;
}