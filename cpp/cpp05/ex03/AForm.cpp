#include "AForm.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	checkGrade(gradeToSign);
	checkGrade(gradeToExecute);

}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	checkGrade(other.gradeToSign);
	checkGrade(other.gradeToExecute);
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other) {
		checkGrade(other.gradeToSign);
		checkGrade(other.gradeToExecute);
		this->isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {}

const std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeToSign() const {
	return gradeToSign;
}

int AForm::getGradeToExecute() const {
	return gradeToExecute;
}

void AForm::checkGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low!";
}

const char* AForm::IsNotSignedException::what() const throw() {
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &outstream, const AForm &form) {
	outstream << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Signed" : "Not signed")
	          << ", Grade to sign: " << form.getGradeToSign()
	          << ", Grade to execute: " << form.getGradeToExecute() << ".";
	return outstream;
}

