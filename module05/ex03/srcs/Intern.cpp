/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 17:02:51 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 04:48:34 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::~Intern(void) {}

Intern::Intern(Intern const &param) {
	*this = param;
}

Intern	&Intern::operator=(Intern const &param) {
	if (this != &param) {
		*this = param;
	}
	return (*this);
}

const char *Intern::InvalidFormException::what() const throw() {
  return "Invalid form request!";
}

static AForm *robotomyRequest(std::string target) {
  return new RobotomyRequestForm(target);
}

static AForm *shrubberyRequest(std::string target) {
  return new ShrubberyCreationForm(target);
}

static AForm *presidentialRequest(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(std::string const &nameForm, std::string const &target) {
	std::string	names[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm	*(*f[3])(std::string target) = {&robotomyRequest, &shrubberyRequest, &presidentialRequest};

	for (int i = 0; i < 4 ; i++) {
		if (!names[i].compare(nameForm)) {
			std::cout << GREEN "Intern creates " << names[i] << DFT << std::endl;
			return (f[i](target));
		}
	}
	throw Intern::InvalidFormException();
	return (NULL);
}
