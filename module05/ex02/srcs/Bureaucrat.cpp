/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:00:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:20:36 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat(void) : _name("unknow"), _grade(150) {
	std::cout << "Bureaucrat default constuctor called" << std::endl;
} 

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : \
	_name(name), _grade(150) {
	std::cout << "Bureaucrat " << getName() << " constructor called" << std::endl;
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &param) : _name(param.getName()), \
	_grade(param.getGrade()) {
	std::cout << "Bureaucrat " << getName() << " copy constructor called" << std::endl;
}

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
	return "Bureaucrat exception: grade too high!";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Bureaucrat exception: grade too low!";
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
		std::cout << getName() << " signed " << param.getName() << std::endl;
	} catch (AForm::GradeTooLowException &e) {
		std::cout << getName() << " couldn’t sign " << param.getName() \
		<< " because: " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &param) {
	try {
		param.execute(*this);
	std::cout << getName() << " executed " << param.getName() << std::endl;
	} catch (const std::exception &e) {
		std::cerr << getName() << " couldn't execute " << param.getName() \
			<< " because: " << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &oS, Bureaucrat const &param) {
	oS << "Bureaucrat: "<< param.getName() << std::endl << "Grade: " \
		<< param.getGrade() << std::endl; 
	return (oS);
}
