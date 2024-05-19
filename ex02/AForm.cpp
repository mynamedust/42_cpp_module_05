#include "AForm.hpp"

AForm::AForm() : _name("untitled_form"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

AForm::AForm(const std::string& name, const int signGrade, const int executeGrade)
: _name(name), _isSigned(false) , _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "AForm param constructor called." << std::endl;
	checkGrade(signGrade, 150);
	checkGrade(executeGrade, 150);
}

AForm::AForm(const AForm& other)
: _name(other._name + "_copy"), _isSigned(other._isSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade) {
	std::cout << "AForm copy constructor called." << std::endl;
	checkGrade(this->_signGrade, 150);
	checkGrade(this->_executeGrade, 150);
}

AForm::~AForm() {
	std::cout << "AForm destructor called." << std::endl;
}

AForm &AForm::operator=(const AForm& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
		return _name;
}

bool AForm::getIsSigned() const{
	return _isSigned;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecuteGrade() const {
	return _executeGrade;
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char *AForm::FormAlreadySigned::what() const throw() {
	return "AForm already signed.";
}

const char *AForm::FormNotSigned::what() const throw() {
	return "Form not signed.";
}

std::ostream& operator<<(std::ostream &os, const AForm& form) {
	os << "---------------------------\n" <<"AForm:\n\tname: " << form.getName() << "\n\tsign grade: " << form.getSignGrade() << "\n\texecute grade: " << form.getExecuteGrade() << "\n\tsigned status: "
	<< form.getIsSigned() << "\n---------------------------" << std::endl;
	return os;
}

bool checkGrade(const int grade, int min) {
	if (grade > min)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
	return  false;
}

void AForm::beSigned(Bureaucrat bur) {
	checkGrade(bur.getGrade(), this->getSignGrade());
	if (this->_isSigned)
		throw AForm::FormAlreadySigned();
	this->_isSigned = true;
}