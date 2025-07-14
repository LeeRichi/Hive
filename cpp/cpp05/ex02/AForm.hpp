#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int gradeToSign;
		const int gradeToExecute;

		void checkGrade(int grade) const;
	public:
		AForm();
		AForm(const std::string &name, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class IsNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		const std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat &bureaucrat);

		virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &outstream, const AForm &buro);

#endif
