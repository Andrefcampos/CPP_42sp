/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:18:57 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form(void) : _name("unnamed"), _sign(false), _signGrade(150), _grade(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &param) : _name(param._name), _sign(param._sign), \
	_signGrade(param._signGrade), _grade(param._grade) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string const &name, const int &signGrade, const int &grade) : \
	_name(name), _sign(false), _signGrade(150), _grade(150) {
	std::cout << "Form initiate members constructor called" << std::endl;
	if (signGrade < 1 || grade < 1) {
		throw (Form::GradeTooHighException());
	} else if (signGrade > 150 || grade > 150) {
		throw (Form::GradeTooLowException());
	} else {
		(int &)_signGrade = signGrade;
		(int &)_grade = grade;
	}
}

Form	&Form::operator=(Form const &param) {
	if (this != &param) {
		(std::string &)_name = param.getName();
		_sign = param.getSign();
		(int &)_signGrade = param.getSignGrade();
		(int &)_grade = param.getGrade();
	}
	return (*this);
}

const std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getSign(void) const {
	return (_sign);
}

int	Form::getSignGrade(void) const {
	return (_signGrade);
}

int	Form::getGrade(void) const {
	return (_grade);
}

void	Form::beSigned(Bureaucrat &param) {
	if (param.getGrade() > getSignGrade()) {
		throw Form::GradeTooLowException();
	} else {
		_sign = true;
	}
}

const char	*Form::GradeTooHighException::what() const throw() {
	return "AForm exception: grade too high!";
}

const char	*Form::GradeTooLowException::what() const throw() {
	return "AForm exception: grade too low!";
}

std::ostream	&operator<<(std::ostream &oS, Form const &param) {
	oS << "Name: " << param.getName() << std::endl;
	oS << "Signed: " << (param.getSign() == 1 ? "Yes" : "No") << std::endl;
	oS << "Signed to grade: " << param.getSignGrade() << std::endl;
	oS << "Grade: " << param.getGrade() << std::endl;
	return (oS);
}
