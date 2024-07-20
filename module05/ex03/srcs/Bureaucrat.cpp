/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:00:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 03:59:38 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("unknow"), _grade(150) {} 

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : \
	_name(name), _grade(150) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &param) : _name(param.getName()), \
	_grade(param.getGrade()) {}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &param) {
	if (this != &param) {
	const_cast<std::string&>(_name) = param.getName();
	_grade = param.getGrade();
	}
	return (*this);
}

void	Bureaucrat::setGrade(int const &grade) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

const std::string	Bureaucrat::getName(void) const {
	return (_name);
}

int	Bureaucrat::getGrade(void) const {
	return (_grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return (RED"Bureaucrat exception: grade too high!"DFT);
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return (RED"Bureaucrat exception: grade too low!"DFT);
}

void	Bureaucrat::increment(void) {
	if (getGrade() - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		_grade -= 1;
	}
}

void	Bureaucrat::decrement(void) {
	if (getGrade() + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade += 1;
	}
}

void	Bureaucrat::signForm(AForm &param) {
	try {
		param.beSigned(*this);
		std::cout << ORANGE << getName() << DFT \
			GREEN " signed " DFT \
			ORANGE << param.getName() << DFT << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << ORANGE << getName() << DFT \
			RED " couldn’t sign " DFT \
			ORANGE << param.getName() << DFT \
			RED " because: " DFT << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &param) {
	try {
		param.execute(*this);
		std::cout << ORANGE << getName() << DFT \
			GREEN " executed " DFT \
			ORANGE << param.getName() << DFT << std::endl;
	} catch (const std::exception &e) {
		std::cerr << ORANGE << getName() \
			<< DFT RED " couldn't execute " DFT ORANGE \
			<< param.getName() << DFT RED " because: " DFT \
			<< e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &oS, Bureaucrat const &param) {
	oS << CYAN "Bureaucrat: " DFT \
		ORANGE << param.getName() \
		<< DFT << std::endl;
	oS << CYAN "Grade: " DFT \
		ORANGE << param.getGrade() \
		<< DFT << std::endl; 
	return (oS);
}
