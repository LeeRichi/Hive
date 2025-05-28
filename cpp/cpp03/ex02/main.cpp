#include "FragTrap.hpp"

int main()
{
    std::cout << "\n=== Creating FragTrap ===" << std::endl;
    // FragTrap ft1("FT-One");
    FragTrap ft1;

    ft1.attack("TargetX");
    ft1.highFivesGuys();
    ft1.takeDamage(30);
    ft1.beRepaired(20);

    std::cout << "\n=== Copying FragTrap ===" << std::endl;
    FragTrap ft2 = ft1;
    ft2.highFivesGuys();

    std::cout << "\n=== Assigning FragTrap ===" << std::endl;
    FragTrap ft3;
    ft3 = ft1;
    ft3.attack("TargetY");

    std::cout << "\n=== End of main ===" << std::endl;
    return 0;
}
