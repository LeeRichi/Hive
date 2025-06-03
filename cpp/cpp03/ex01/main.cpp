#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Default ClapTrap ===" << std::endl;
    ScavTrap rich;
    rich.attack("a noob");
    rich.takeDamage(5);
    rich.beRepaired(3);

    // std::cout << "=== Creating ClapTrap ===" << std::endl;
    // ClapTrap ct1("CT-One");
    // ct1.attack("TargetA");
    // ct1.takeDamage(5);
    // ct1.beRepaired(3);

    // std::cout << "\n=== Creating ScavTrap ===" << std::endl;
    // ScavTrap st1("ST-One");
    // st1.attack("TargetB");
    // st1.guardGate();
    // st1.takeDamage(20);
    // st1.beRepaired(10);

    // std::cout << "\n=== Copying ScavTrap ===" << std::endl;
    // ScavTrap st2 = st1; // copy constructor
    // st2.attack("TargetC");
    // st2.takeDamage(20);
    // st2.beRepaired(10);
    // st2.guardGate();

    // std::cout << "\n=== Assigning ScavTrap ===" << std::endl;
    // ScavTrap st3;
    // st3 = st1; // copy assignment
    // st3.attack("TargetD");
    // st3.takeDamage(20);
    // st3.beRepaired(10);
    
    // st3.guardGate();

    // std::cout << "\n=== End of main ===" << std::endl;
    // return 0;
}
