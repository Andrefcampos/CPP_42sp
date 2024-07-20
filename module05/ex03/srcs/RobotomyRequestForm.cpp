/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 03:59:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 03:56:55 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : \
	AForm("RobotomyRequestForm", 72, 45), _target("unknow") {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

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
	if (executor.getGrade() > getGradeToExec()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << GREEN "Bzzzzzzzz... Drrrrrrr... Zzzzzzz...\n" DFT;
	if (std::rand() % 2 == 0) {
		std::cout << ORANGE << _target << \
			DFT GREEN " has been robotomized successfully.\n" DFT;
	} else {
		std::cout << RED << "Robotomy of " DFT ORANGE << _target \
			<< DFT RED " failed.\n" DFT;
	}
}
