#include "Intern.hpp"

int main()
{
    try {
        Intern intern;

        AForm *form1 = intern.makeForm("presidential pardon", "Target1");
        AForm *form2 = intern.makeForm("robotomy request", "Target2");
        AForm *form3 = intern.makeForm("shrubbery creation", "Target3");
        AForm *form4 = intern.makeForm("unknown form", "Target4");

        if (form1) {
            std::cout << *form1 << std::endl;
        } else {
            std::cout << "Form1 creation failed." << std::endl;
        }

        if (form2) {
            std::cout << *form2 << std::endl;
        } else {
            std::cout << "Form2 creation failed." << std::endl;
        }

        if (form3) {
            std::cout << *form3 << std::endl;
        } else {
            std::cout << "Form3 creation failed." << std::endl;
        }

        if (form4) {
            std::cout << *form4 << std::endl;
        } else {
            std::cout << "Form4 creation failed." << std::endl;
        }

        delete form1;
        delete form2;
        delete form3;
        delete form4;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
