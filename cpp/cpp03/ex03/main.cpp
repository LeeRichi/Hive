#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n=== Default DiamondTrap ===\n";
    DiamondTrap defaultDt;

    std::cout << "\n=== Params DiamondTrap ===\n";
    DiamondTrap dt("R2D2");

    std::cout << "\n===  Copy Constructor DiamondTrap===\n";
    DiamondTrap copyDt(dt);

    std::cout << "\n=== Copy Assignment DiamondTrap ===\n";
    DiamondTrap assignedDt;
    assignedDt = dt;

    std::cout << "\n=== To Attack ===\n";
    dt.attack("a target");

    std::cout << "\n=== Who Am I===\n";
    dt.whoAmI();
    copyDt.whoAmI();
    assignedDt.whoAmI();
    defaultDt.whoAmI();

    std::cout << "\n=== End of Program ===\n\n";
}


