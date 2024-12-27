#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main() {
    FragTrap frag("Fraggy");

    frag.attack("Enemy");
    frag.takeDamage(50);
    frag.beRepaired(40);

    frag.highFivesGuys();

    return 0;
}
