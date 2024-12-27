#include "ClapTrap.hpp"

int main() {
    ClapTrap robot("RobotWarrior");

    robot.attack("Enemy1");
    robot.takeDamage(5);
    robot.beRepaired(3);
    robot.takeDamage(10);
    robot.attack("Enemy2");
    
    return 0;
}