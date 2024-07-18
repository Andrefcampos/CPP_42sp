/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:18:46 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("unnamed"), _sign(false), _signGrade(150), _grade(150) {
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::~AForm(void) {
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(AForm const &param) : _name(param._name), _sign(param._sign), \
	_signGrade(param._signGrade), _grade(param._grade) {
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::AForm(std::string const &name, const int &signGrade, const int &grade) : \
	_name(name), _sign(false), _signGrade(150), _grade(150) {
	if (signGrade < 1 || grade < 1) {
		throw (AForm::GradeTooHighException());
	} else if (signGrade > 150 || grade > 150) {
		throw (AForm::GradeTooLowException());
	} else {
		(int &)_signGrade = signGrade;
		(int &)_grade = grade;
	}
}

AForm	&AForm::operator=(AForm const &param) {
	if (this != &param) {
		(std::string &)_name = param.getName();
		_sign = param.getSign();
		(int &)_signGrade = param.getSignGrade();
		(int &)_grade = param.getGrade();
	}
	return (*this);
}

const std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getSign(void) const {
	return (_sign);
}

int	AForm::getSignGrade(void) const {
	return (_signGrade);
}

int	AForm::getGrade(void) const {
	return (_grade);
}

void	AForm::beSigned(Bureaucrat &param) {
	if (param.getGrade() > getSignGrade()) {
		throw AForm::GradeTooLowException();
	} else {
		_sign = true;
	}
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("AForm exception: grade too high!");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("AForm exception: grade too low!");
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return ("AForm exception: for not signed!");
}

std::ostream	&operator<<(std::ostream &oS, AForm const &param) {
	oS << "Name: " << param.getName() << std::endl;
	oS << "Signed: " << (param.getSign() == 1 ? "Yes" : "No") << std::endl;
	oS << "Signed to grade: " << param.getSignGrade() << std::endl;
	oS << "Grade: " << param.getGrade() << std::endl;
	return (oS);
}
