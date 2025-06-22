#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

Intern::~Intern() {}

static AForm *createPresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

static AForm *createRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

static AForm *createShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

const std::string Intern::formNames[3] = {
	"presidential pardon",
	"robotomy request",
	"shrubbery creation"
};

AForm *(*Intern::formCreators[3])(const std::string&) = {
	&createPresidentialPardonForm,
	&createRobotomyRequestForm,
	&createShrubberyCreationForm
};


AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
	for (int i = 0; i < 3; i++) {
		if (formNames[i] == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return formCreators[i](target);
		}
	}
	std::cout << "formName not found: " << formName << std::endl;
	return nullptr;
};
