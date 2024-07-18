/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 05:16:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>

int main() {
	// {
	// 	std::cout << "My tests: " << std::endl;
	// 	try {
	// 	Bureaucrat	a("andre",        30);
	// 	AForm		b(a.getName(),            50, a.getGrade());
	// 	b.beSigned(a);
	//
	// 	std::cout << b;
	// 		try {
	// 			a.setGrade(20);
	// 			b.beSigned(a);
	// 			std::cout << b;
	// 		} catch (std::exception &e) {
	// 			std::cout << e.what() << std::endl;
	// 		}
	// 	} catch (std::exception &e) {
	// 		std::cout << e.what() << std::endl;
	// 	}
	//
	// }
	std::cout << "test ShrubberyCreationForm: \n";
	{
		AForm *a = new ShrubberyCreationForm("home");
		Bureaucrat b("Mico", 150);

		b.signForm(*a);
		b.executeForm(*a);

		delete a;
	}
	std::cout << "test RobotomyRequestForm: \n";
	{
		AForm *a = new RobotomyRequestForm("home");
		Bureaucrat b("Xico", 10);

		b.signForm(*a);
		b.executeForm(*a);
		delete a;
  	}
	{
		std::cout << ("\n\n==== PRESIDENTIAL REQUEST FORM TESTS ====")
			<< std::endl;
		std::cout << ("\n== LOW GRADE TO SIGN FORM ===") << std::endl;
		{
			AForm *a = new PresidentialPardonForm("Renato");
			Bureaucrat b("Claer", 73);

			b.signForm(*a);
			b.executeForm(*a);

			delete a;
		}
		std::cout << ("\n=== LOW GRADE TO EXECUTE FORM ===") << std::endl;
		{
			AForm *a = new PresidentialPardonForm("pardon");
			Bureaucrat b("Sail", 48);

			b.signForm(*a);
			b.executeForm(*a);

			delete a;
		}
		std::cout << ("\n=== CREATING A PRESIDENTIAL REQUEST FORM ===")
			<< std::endl;
		{
			AForm *a = new PresidentialPardonForm("Nattan");
			Bureaucrat b("Bill", 42);
			Bureaucrat c("Noca", 5);

			b.signForm(*a);
			c.executeForm(*a);

			delete a;
		}
	}
	{
		try {
			Bureaucrat bob("Bob", 4);

			ShrubberyCreationForm	form("home");
			form.beSigned(bob);
			form.execute(bob);
		} catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
  return 0;
}
