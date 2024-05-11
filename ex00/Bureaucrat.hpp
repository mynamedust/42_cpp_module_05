#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
typedef std::string string;

class Bureaucrat {
	const string _name;
	int _grade;
public:
	Bureaucrat();
	Bureaucrat(const string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	const char *operator<<( ,const Bureaucrat &buro);

	string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception{
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception{
		const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream &os, const Bureaucrat& bur);


#endif
