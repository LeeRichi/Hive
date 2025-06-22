#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
		: AForm("Presidential Pardon Form", 25, 5), target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
		: AForm("Presidential Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
		: AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned()) {
		throw AForm::IsNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

// const std::string &PresidentialPardonForm::getTarget() const {
// 	return target;
// }

// std::ostream &operator<<(std::ostream &outstream, const PresidentialPardonForm &form) {
// 	outstream << "PresidentialPardonForm: " << form.getName()
// 	          << ", Target: " << form.getTarget()
// 	          << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No")
// 	          << ", Grade to Sign: " << form.getGradeToSign()
// 	          << ", Grade to Execute: " << form.getGradeToExecute();
// 	return outstream;
// }
