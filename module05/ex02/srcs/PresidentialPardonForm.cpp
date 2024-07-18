/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 04:59:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:14:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : \
	AForm("PresidentialPardonForm", 25, 5), \
	_target("unknow") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : \
	AForm("PresidentialPardonForm", 25, 5), \
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &param) : \
	AForm("PresidentialPardonForm", 25, 5) {
	*this = param;
}

PresidentialPardonForm \
&PresidentialPardonForm::operator=(PresidentialPardonForm const &param) {
	if (this != &param) {
		AForm::operator=(param);
		_target = param._target;
	}
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSign()) {
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGrade()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
