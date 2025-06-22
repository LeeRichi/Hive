#include "Bureaucrat.hpp"
#include "AForm.hpp"

#pragma once

class Intern {
	public:
			Intern();
			Intern(const Intern &other);
			Intern &operator=(const Intern &other);
			~Intern();

			AForm *makeForm(const std::string &formName, const std::string &target) const;

	private:
			static const std::string formNames[3];
			static AForm *(*formCreators[3])(const std::string &target);
};

