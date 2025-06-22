#include "AForm.hpp"
#include <stdexcept>

class ShrubberyCreationForm : public AForm
{
	private:
			std::string target;
	public:
			ShrubberyCreationForm();
			ShrubberyCreationForm(const std::string &target);
			ShrubberyCreationForm(const ShrubberyCreationForm &other);
			ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
			~ShrubberyCreationForm();

			void execute(const Bureaucrat &executor) const override;
			// const std::string &getTarget() const;
};
