#include "ShrubberyCreationForm.hpp"
#include <fstream>

const std::string myTree = R"(
................................:^:..:~~!!7?7~~7!77??77JPPJ??7??7!~^::::::::::::::^^^^^^^^^^^^^^^^^^
............................^~!?JY7^~777JJJJ7????YJJ?J7?7777JJJ?J??7^.............::::::::::::::::::
..........................~?Y?J5?!!?555??JYY?77?Y5PYJ?777Y??77?J?7?JY~::............................
.........................75JJ?77!???7?YJ??JJ55??J5P5?7J??J???77J5J?J?JJ7:...........................
.......................:!55J777J?J?7?7Y55GGJYGP55Y?555JYYYJ?77?JPPPP5??!!:..........................
..................:^!7!JPPG5YYJJJYJ?77?5PY5GPJ??7?!77??JYYJP5JYJJY5J77?7?7!^........................
.................~?JJY5YJ?JY5YY??YJYPJJYP#BBY??777JJJ?7?PGJ5GYJ?YYJ??!7JJJ?77:......................
................!?YJYJ?7??JJJ5PY5GYJ5Y5&@@&YJ??7?7!7YJJ7JGPJ7?!J?77?Y???YJJ?7~......................
...............:!JY5GYJJJ?J??JYGPYP#P5GBBB&GPYJJ5YYY7?J5Y55?7JJJ?7775YYY77JY5J~.....................
...............:~~JB#5JJ5YY7?JJ5#&@&##BGPBBBG55PPYJ5Y?YJGBGY5?JJYJ77JY55JJP?57......................
.................?BBGPY5PJGPYGPG#?!~^?BGGBBBBGBBP5J55YGP5BB5PYJ5J5PYPBBPPYPJ~~......................
................^5PGPBBBP5J7J?7?~.....~PBGGBBBBBG#BJ~?YB#BB??JJPY!7Y@@@@&B5J........................
................:7PBGPJPP7..:..........:JBGPGGGBBBBBB&#BBB5....^:..:7PGJYB5~........................
.................~!7!...:........::....::!GBGPPPGBGPPPPPGP^..............:^.........................
..............................:^7JY??JJJJ7!5#BPP5YY55??5G~ .........................................
.............................~JJ55YJJY?JY?YYJBBGP5J?J5J?YY^.........................................
............................~YYYYYJJ?5YYJYPP7~BBP55Y?7JY7JY~........................................
............................!55YY?JJY5P55JJ?!^~BBPYY5?!?Y7?Y!.......................................
............................:?PP5P55PJJ?JJJ?J^ !#GGYJ5J!JY7?Y7......................................
.............................:?J55YJ5J7?5?J?!:~7GBPGYYP?7JY7?Y!.:::::...............................
................:::::::.::::::::!~~!?YJ?Y7JJJ5GGPG#GPJ5577JJ7JY!.:::::::::::::::::..................
.........:::^~!!7777777!777??7777??????J55Y55PPPPP&BPJYP?7Y5?JYJ~::::::::::::::::::::::::...........
...:..::~77??????????????????????????????JJ5PPPPP5#PY?YPJ?Y5Y?YY?::::::::::::::::::::::::::::::.....
::::^!77???????????????????????7?JJJJJJJJJJ???JJJJGGYYPPYJ555?YYJ^^^^^::::::::::::::::::::::::::::::
::::^7????????????JJJJ???JJJJJJ?JJJJJJJJJJJJ?JJJJYGGGPP555PPYJY5Y~^^^^^^^^^:::::::::::::::::::::::::
:::::::^~7????????7!!7?7?JJJJJJJYYYYYYYYYYYYYYYYYGBGPP55P5PPJYYP5~^^^^^^^^^^^^^:::::::::::::::::::::
::::::::::^^^~~~^^^^7JJJJJYYYYJJJ??JYYYYYYY55555GBGPPPPPPP5YYY5PY~~~~^^^^^^^^^^^^:::::::::::::::::::
::::::::::::::::^^^^^~~!77??JJYYYYYYJYYYY555555PBGPPP55PP5YYYY5PY!~~~~^^^^^^^^^^^^::::::::::::::::::
::::::::::::::^^^^^^^^^^^^^^~~!777?7~!!!!!777JPBBGPPP5GP55YY5Y5P5!!~~^^^^^^^^^^^^:::::::::::::::::::
::::::::::::::::^^^^^^^^^^^^^^^^^^^^~~~~~~~~~!!?YPPP5PGPPP5555P5?!~~^^^^^^^^^^^:::::::::::::::::::::
:::::::::::::::::::::^^^^^^^^^^^^^^^^^^^^^^^~~~~~~!!!77????77!~~^^^^^^^^^^:::::::::::::::::::
)";

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!getIsSigned())
		throw AForm::IsNotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream outfile(target + "_shrubbery");
	if (!outfile.is_open()) {
		throw std::runtime_error("Failed to open file for writing.");
	}

	outfile << myTree;
	outfile.close();
}

