#include "ClapTrap.hpp"

int main() {
    ClapTrap a("Alpha");
    ClapTrap b(a);
    ClapTrap c;
    c = b;

    a.attack("Target");
    b.takeDamage(-5);
    c.beRepaired(3333333);

    return 0;
}
