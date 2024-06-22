#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	Intern someRandomIntern;
	AForm* robot;
	AForm* shrubbery;
	AForm* presidental;
	Bureaucrat buro1("Solomon", 22);

	robot = someRandomIntern.makeForm("robotomy", "Bender");
	shrubbery = someRandomIntern.makeForm("shrubbery", "Diego");
	presidental = someRandomIntern.makeForm("presidential", "Donald");
	
	buro1.signForm(*robot);
	buro1.executeForm(*robot);

	buro1.signForm(*shrubbery);
	buro1.executeForm(*shrubbery);

	buro1.signForm(*presidental);
	buro1.executeForm(*presidental);

	std::cout << *robot << std::endl;
	std::cout << *shrubbery << std::endl;
	std::cout << *presidental << std::endl;

	delete robot;
	delete shrubbery;
	delete presidental;
}
