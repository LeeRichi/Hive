#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    FragTrap ft1;

    ft1.attack("TargetX");
    ft1.highFivesGuys();
    ft1.takeDamage(1);
    ft1.beRepaired(20);
    ft1.highFivesGuys();


    std::cout << "\n=== Copying FragTrap ===" << std::endl;
    FragTrap ft2 = ft1;
    ft2.highFivesGuys();
    ft2.beRepaired(5);  

    std::cout << "\n=== Assigning FragTrap ===" << std::endl;
    FragTrap ft3;
    ft3 = ft1;
    ft3.attack("TargetY");
    ft3.takeDamage(2);


    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
