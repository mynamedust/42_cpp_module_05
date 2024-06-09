#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	Intern someRandomIntern;
	AForm* robot;
	AForm* shrubbery;
	AForm* presidental;
	robot = someRandomIntern.makeForm("robotomy", "Bender");
	shrubbery = someRandomIntern.makeForm("shrubbery", "Diego");
	presidental = someRandomIntern.makeForm("presidential", "Donald");
	
	std::cout << *robot << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *presidental << std::endl;
	robot
}
