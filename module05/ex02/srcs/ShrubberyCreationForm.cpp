/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:42:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 04:27:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : \
	AForm("ShrubberyCreationForm", 145, 137), \
	_target("unknow"){
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShurubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : \
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & param) : \
	AForm("ShrubberyCreationForm", 145, 137) {
	*this = param;
}

ShrubberyCreationForm \
&ShrubberyCreationForm::operator=(ShrubberyCreationForm const & param) {
	if (this != &param) {
		AForm::operator=(param);
		_target = param._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
	if (!getSign()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > 137) {
		throw GradeTooLowException();
	}
	std::string	fileName(_target + "_shrubbery");
	if (std::ifstream(fileName.c_str())) {
		throw FailedToOpenException();
	}
	std::ofstream	outFile(fileName.c_str());
	if (!outFile) {
		throw FileWriteException();
	}
	outFile <<	"       _-_\n"
				"    /~~   ~~\\\n"
				" /~~         ~~\\\n"
				"{               }\n"
				" \\  _-     -_  /\n"
				"   ~  \\\\ //  ~\n"
				"_- -   | | _- _\n"
				"  _ -  | |   -_\n"
				"      // \\\\\n";
	outFile.close();
}
