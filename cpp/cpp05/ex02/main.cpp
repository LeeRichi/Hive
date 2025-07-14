
// #include "Bureaucrat.hpp"
// #include "AForm.hpp"
// #include "PresidentialPardonForm.hpp"
// #include "RobotomyRequestForm.hpp"
// #include "ShrubberyCreationForm.hpp"

// int main()
// {
//     try
//     {
//         PresidentialPardonForm PresidentForm("PresidentForm");
//         RobotomyRequestForm RobotomyForm("RobotomyForm");
//         ShrubberyCreationForm ShrubberyFrom("ShrubberyFrom");

//         Bureaucrat Alice("Alice", 1);
//         Bureaucrat Bob("Bob", 150);
//         Bureaucrat Charlie("Charlie", 1);

//         //before
//         std::cout << "<-----Before signed----->" << std::endl;
//         std::cout << PresidentForm << std::endl;
//         std::cout << RobotomyForm << std::endl;
//         std::cout << ShrubberyFrom << std::endl;

//         Alice.signForm(PresidentForm);
//         Alice.signForm(RobotomyForm);
//         Alice.signForm(ShrubberyFrom);

//         //after
//         std::cout << "<-----After signed----->" << std::endl;
//         std::cout << PresidentForm << std::endl;
//         std::cout << RobotomyForm << std::endl;
//         std::cout << ShrubberyFrom << std::endl;

//         //execute check
//         std::cout << "<-----Now execute----->" << std::endl;
//         PresidentForm.execute(Alice);
//         RobotomyForm.execute(Alice);
//         ShrubberyFrom.execute(Alice);
//         //execute check with low grade
//         std::cout << "<-----Failure case----->" << std::endl;
//         RobotomyForm.execute(Bob);

//         // std::cout << "\n[TEST] Polymorphism\n";
//         AForm *form = new ShrubberyCreationForm("backyard");
//         try {
//             Alice.signForm(*form);
//             form->execute(Alice);
//         } catch (const std::exception &e) {
//             std::cerr << e.what() << "\n";
//         }
//         delete form;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//         return 1;
//     }
//     return 0;
// }



#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"

void testSigningAndExecution(AForm &form, Bureaucrat &signer, Bureaucrat &executor) {
	std::cout << "\n[TEST] Signing and Executing " << form.getName() << "\n";
	std::cout << "Form info: " << form << "\n";
	std::cout << "Signer: " << signer << "\nExecutor: " << executor << "\n";

	try {
		signer.signForm(form);
		std::cout << "Signed: ✔️\n";
	} catch (const std::exception &e) {
		std::cerr << "Signing failed: " << e.what() << "\n";
	}

	try {
		form.execute(executor);
		std::cout << "Executed: ✔️\n";
	} catch (const std::exception &e) {
		std::cerr << "Execution failed: " << e.what() << "\n";
	}
}

void testGradeBounds() {
	std::cout << "\n[TEST] Bureaucrat Grade Bounds\n";
	try {
		Bureaucrat badHigh("TooHigh", 0);
	} catch (const std::exception &e) {
		std::cerr << "Expected exception for grade 0: " << e.what() << "\n";
	}
	try {
		Bureaucrat badLow("TooLow", 151);
	} catch (const std::exception &e) {
		std::cerr << "Expected exception for grade 151: " << e.what() << "\n";
	}
}

int main() {
	testGradeBounds();

	Bureaucrat Rich("Rich", 1);
	Bureaucrat Lee("Lee", 75);
	Bureaucrat Chi("Chi", 150);

	ShrubberyCreationForm shrubForm("garden");
	RobotomyRequestForm robotForm("target");
	PresidentialPardonForm pardonForm("prisoner");

	// Test with various grades
	testSigningAndExecution(shrubForm, Rich, Rich);    // should pass
	testSigningAndExecution(robotForm, Lee, Lee);    // may fail if mid < gradeToExec
	testSigningAndExecution(pardonForm, Chi, Chi);   // should fail both sign & exec

	// Polymorphism check
	// std::cout << "\n[TEST] Polymorphism\n";
	// AForm *form = new ShrubberyCreationForm("backyard");
	// try {
	// 	Rich.signForm(*form);
	// 	form->execute(Rich);
	// } catch (const std::exception &e) {
	// 	std::cerr << e.what() << "\n";
	// }
	// delete form;

	return 0;
}
