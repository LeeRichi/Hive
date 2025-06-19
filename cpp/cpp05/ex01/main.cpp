
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    try
    {
        Form form1("Form1", 50, 100);
        Form form2("Form2", 20, 30);
        Form form3("Form3", 150, 150);

        Bureaucrat b1("Alice", 1);
        Bureaucrat b2("Bob", 150);
        Bureaucrat b3("Charlie", 1);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;

        b1.signForm(form1);
        b2.signForm(form2);
        b3.signForm(form3);

        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;
        std::cout << form3 << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
