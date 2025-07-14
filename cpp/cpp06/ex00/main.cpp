// | Cast               | Purpose                                                                    | Safety         | Example Use Case                       |
// | ------------------ | -------------------------------------------------------------------------- | -------------- | -------------------------------------- |
// | `static_cast`      | Compile-time conversions (numeric, upcasting, non-polymorphic downcasting) | **Moderate**   | `int` to `float`, base to derived      |
// | `dynamic_cast`     | Safe downcasting with polymorphism (`virtual` functions involved)          | **High**       | Base class pointer to derived pointer  |
// | `const_cast`       | Adds or removes `const` or `volatile` qualifiers                           | **Low/Tricky** | Removing `const` from a pointer        |
// | `reinterpret_cast` | Bit-level reinterpretation of data types                                   | **Unsafe**     | Casting pointer types, low-level hacks |

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: " << av[0] << " <value>" << std::endl;
        return 1;
    }

    std::string input(av[1]);

    try
    {
        ScalarConverter::convert(input);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
