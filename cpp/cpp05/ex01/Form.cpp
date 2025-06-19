#include "Form.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150) {}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
	checkGrade(gradeToSign);
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {
	checkGrade(other.gradeToSign);
}

Form &Form::operator=(const Form &other) {
	if (this != &other) {
		checkGrade(other.gradeToSign);
		this->isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {}

const std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

int Form::getGradeToSign() const {
	return gradeToSign;
}

int Form::getGradeToExecute() const {
	return gradeToExecute;
}

void Form::checkGrade(int grade) const {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > gradeToSign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Form grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Form grade too low!";
}

std::ostream &operator<<(std::ostream &outstream, const Form &form) {
	outstream << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Signed" : "Not signed")
	          << ", Grade to sign: " << form.getGradeToSign()
	          << ", Grade to execute: " << form.getGradeToExecute() << ".";
	return outstream;
}

