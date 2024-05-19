#include "ShrubberyCreationForm.hpp"
#include <sstream>
#include <iomanip>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) , _target("no_target") {
	std::cout << "ShrubberyCreationForm constructor called. New form name: " << this->getName() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm param constructor called. New form name: " << this->getName() << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm " << this->getName() << " destructor called." << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (!this->getIsSigned())
		throw FormNotSigned();

	std::ofstream outfile (this->getName());
	outfile << createNewASCIITree();
	outfile.close();
}

std::string ShrubberyCreationForm::createNewASCIITree() const {
	std::ostringstream ss;

	int cap = 18;
	int wood = 3;
	int woodCup = 2;

	for (int i = 1; i <= cap; i += 2) {
		std::string wsStr((cap - i) / 2, ' ');
		std::string chrStr(i, '*');

		ss << wsStr << chrStr << wsStr << std::endl;
	}

	for (int i = 0; i < woodCup; i++) {
		std::string wsStr((cap - wood) / 2, ' ');
		std::string chrStr(wood, '|');

		ss << wsStr << chrStr << wsStr << std::endl;
	}

	return ss.str();
}




