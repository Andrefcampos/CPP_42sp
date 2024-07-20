/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/19 21:30:15 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>

Form::Form(void) : _name("unnamed"), _sign(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form default constructor called" << std::endl;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(Form const &param) : _name(param._name), _sign(param._sign), \
	_gradeToSign(param._gradeToSign), _gradeToExec(param._gradeToExec) {
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(std::string const &name, const int &gradeToSign, const int &gradeToExec) : \
	_name(name), _sign(false), _gradeToSign(150), _gradeToExec(150) {
	std::cout << "Form initiate members constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw (Form::GradeTooHighException());
	} else if (gradeToSign > 150 || gradeToExec > 150) {
		throw (Form::GradeTooLowException());
	} else {
		(int &)_gradeToSign = gradeToSign;
		(int &)_gradeToExec = gradeToExec;
	}
}

Form	&Form::operator=(Form const &param) {
	if (this != &param) {
		(std::string &)_name = param.getName();
		_sign = param.getSign();
		(int &)_gradeToSign = param.getGradeToSign();
		(int &)_gradeToExec = param.getGradeToExec();
	}
	return (*this);
}

const std::string	Form::getName(void) const {
	return (_name);
}

bool	Form::getSign(void) const {
	return (_sign);
}

int	Form::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	Form::getGradeToExec(void) const {
	return (_gradeToExec);
}

void	Form::beSigned(Bureaucrat &param) {
	if (param.getGrade() > getGradeToExec()) {
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
	oS << "Form Name: " << param.getName() << std::endl;
	oS << "Signed: " << (param.getSign() == 1 ? "Yes" : "No") << std::endl;
	oS << "Grade to Sign: " << param.getGradeToSign() << std::endl;
	oS << "Grade to Execute: " << param.getGradeToExec() << std::endl;
	return (oS);
}
