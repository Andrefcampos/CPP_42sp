/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 04:59:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 03:57:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void) : \
	AForm("PresidentialPardonForm", 25, 5), _target("unknow") {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

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
	if (executor.getGrade() > getGradeToExec()) {
		throw AForm::GradeTooLowException();
	}
	std::cout << ORANGE << _target << DFT GREEN \
		" has been pardoned by Zaphod Beeblebrox.\n" DFT;
}
