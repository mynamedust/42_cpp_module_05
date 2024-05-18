#include "Form.hpp"

Form::Form() : _name("untitled_form"), _isSigned(false), _signGrage(150),  _executeGrade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Form::Form(const std::string& name, const int signGrade, const int executeGrade)
: _name(name), _isSigned(false) , _signGrage(signGrade), _executeGrade(executeGrade) {
	std::cout << "Form param constructor called." << std::endl;
	checkGrade(signGrade, 150);
	checkGrade(executeGrade, 150);
}

Form::Form(const Form& other)
: _name(other._name), _isSigned(other._isSigned), _signGrage(other._signGrage),  _executeGrade(other._executeGrade) {
	std::cout << "Form copy constructor called." << std::endl;
}

Form::~Form() {
	std::cout << "Form destructor called." << std::endl;
}

Form &Form::operator=(const Form& other) {
	if (this != &other) {
		_isSigned = other._isSigned;
	}
	return *this;
}

std::string Form::getName() const {
		return _name;
}

bool Form::getIsSigned() const{
	return _isSigned;
}

int Form::getSignGrade() const {
	return _signGrage;
}

int Form::getExecuteGrade() const {
	return _executeGrade;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low.";
}

const char *Form::FormAlreadySigned::what() const throw() {
	return "Form already signed.";
}

std::ostream& operator<<(std::ostream &os, const Form& form) {
	os << "From: " << form.getName() << ",sign grade: " << form.getSignGrade() << ",execute grade: " << form.getExecuteGrade()
	<< ",signed status: " << form.getIsSigned();
	return os;
}

bool checkGrade(const int grade, int min) {
	if (grade > min)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
	return  false;
}

void Form::beSigned(Bureaucrat bur) {
	checkGrade(bur.getGrade(), this->getSignGrade());
	if (this->_isSigned)
		throw Form::FormAlreadySigned();
	this->_isSigned = true;
}