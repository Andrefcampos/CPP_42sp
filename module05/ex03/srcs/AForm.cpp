/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:02:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 03:54:07 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("unnamed"), _sign(false), \
		_gradeToSign(150), _gradeToExec(150) {}

AForm::~AForm(void) {}

AForm::AForm(AForm const &param) : _name(param._name), _sign(param._sign), \
	_gradeToSign(param._gradeToSign), _gradeToExec(param._gradeToExec) {}

AForm::AForm(std::string const &name, const int &gradeToSign, const int &gradeToExec) : \
	_name(name), _sign(false), _gradeToSign(150), _gradeToExec(150) {
	if (gradeToSign < 1 || gradeToExec < 1) {
		throw (AForm::GradeTooHighException());
	} else if (gradeToSign > 150 || gradeToExec > 150) {
		throw (AForm::GradeTooLowException());
	} else {
		(int &)_gradeToSign = gradeToSign;
		(int &)_gradeToExec = gradeToExec;
	}
}

AForm	&AForm::operator=(AForm const &param) {
	if (this != &param) {
		(std::string &)_name = param.getName();
		_sign = param.getSign();
		(int &)_gradeToSign = param.getGradeToSign();
		(int &)_gradeToExec = param.getGradeToExec();
	}
	return (*this);
}

const std::string	AForm::getName(void) const {
	return (_name);
}

bool	AForm::getSign(void) const {
	return (_sign);
}

int	AForm::getGradeToSign(void) const {
	return (_gradeToSign);
}

int	AForm::getGradeToExec(void) const {
	return (_gradeToExec);
}

void	AForm::beSigned(Bureaucrat &param) {
	if (param.getGrade() > getGradeToSign()) {
		throw AForm::GradeTooLowException();
	} else {
		_sign = true;
	}
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return (RED"AForm exception: grade too high!"DFT);
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return (RED"AForm exception: grade too low!"DFT);
}

const char	*AForm::FormNotSignedException::what() const throw() {
	return (RED"AForm exception: for not signed!"DFT);
}

std::ostream	&operator<<(std::ostream &oS, AForm const &param) {
	oS << CYAN"Name: "DFT ORANGE << param.getName() << DFT << std::endl;
	oS << CYAN"Signed: "DFT << (param.getSign() == 1 ? GREEN"Yes"DFT : RED"No"DFT) << std::endl;
	oS << CYAN"Grade to Signed: "DFT ORANGE << param.getGradeToSign() << DFT << std::endl;
	oS << CYAN"Grade to Execute: "DFT ORANGE << param.getGradeToExec() << DFT << std::endl;
	return (oS);
}
