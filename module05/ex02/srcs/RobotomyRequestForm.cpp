/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:59:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:05:28 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : \
	AForm("RobotomyRequestForm", 72, 45), _target("unknow") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm detructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : \
	AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &param) : \
	AForm("RobotomyRequestForm", 72, 45) {
	*this = param;
}

RobotomyRequestForm \
&RobotomyRequestForm::operator=(RobotomyRequestForm const &param) {
	if (this != &param) {
		AForm::operator=(param);
		_target = param._target;
	}
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSign()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << "Bzzzzzzzz... Drrrrrrr... Zzzzzzz..." << std::endl;
	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "Robotomy of " << _target << " failed." << std::endl;
	}
}
