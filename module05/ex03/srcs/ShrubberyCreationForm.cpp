/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 02:42:31 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/20 03:58:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : \
	AForm("ShrubberyCreationForm", 145, 137), _target("unknow"){}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

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
	if (executor.getGrade() > getGradeToExec()) {
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
	outFile <<	"              * *   \n "
				"           *    *  *\n"
				"      *  *    *     *  *\n"
				"     *     *    *  *    *\n"
				" * *   *    *    *    *   *\n"
				" *     *  *    * * .#  *   *\n"
				" *   *     * #.  .# *   *\n"
				"  *     *#.  #: #* * *    *\n"
				" *   * * *#. ##*  * *  *\n"
				"   *     *   #######\n"
				"      *       #####\n"
				"              :###\n"
				"              ;##:\n"
				"              :##:\n"
				"              :###\n"
				"              ;###.\n"
				"            ,######.\n"
				"          .#########.\n";
	outFile.close();
}

const char	*ShrubberyCreationForm::FileWriteException::what() const throw() {
	return (RED "Failed writing to file." DFT);
}

const char	*ShrubberyCreationForm::FailedToOpenException::what() const throw() {
	return (RED "Failed opening file." DFT);
}
