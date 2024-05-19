#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class AForm {
	const std::string _name;
	bool  _isSigned;
	const int _signGrade;
	const int _executeGrade;
public:
	AForm();
	AForm(const std::string& name, const int signGrade, const int executeGrade);
	AForm(const AForm& other);
	AForm &operator=(const AForm& other);
	virtual ~AForm();

	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecuteGrade() const;
	void beSigned(class Bureaucrat bur);
	virtual void execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char *what() const throw();
	};

	class FormAlreadySigned : public std::exception{
		const char *what() const throw();
	};

	class FormNotSigned : public std::exception {
		const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, const AForm& form);

bool checkGrade(const int grade, int min);

#endif
