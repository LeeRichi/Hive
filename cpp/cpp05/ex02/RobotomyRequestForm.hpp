#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
			std::string target;
	public:
			RobotomyRequestForm();
			RobotomyRequestForm(const std::string &target);
			RobotomyRequestForm(const RobotomyRequestForm &other);
			RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
			~RobotomyRequestForm();

			void execute(const Bureaucrat &executor) const override;
			// const std::string &getTarget() const;
};
