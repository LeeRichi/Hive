#include "Bureaucrat.hpp"
#include "AForm.hpp"

void Bureaucrat::checkGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name) {
	checkGrade(grade);
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {
	checkGrade(other.grade);
	this->grade = other.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		checkGrade(other.grade);
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	checkGrade(grade - 1);
	--grade;
}

void Bureaucrat::decrementGrade() {
	checkGrade(grade + 1);
	++grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << getName() << " signs " << form.getName() << "." << std::endl;
	} catch (const std::exception &e) {
		std::cout << getName() << " couldn't sign " << form.getName() << " because: " << e.what() << std::endl;
		throw; // rethrow to allow outer catch to work
	}
}

void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cout << getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &outstream, const Bureaucrat &buro) {
	outstream << buro.getName() << ", bureaucrat grade " << buro.getGrade() << ".";
	return outstream;
}
