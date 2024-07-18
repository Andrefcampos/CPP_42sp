/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 01:37:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 01:55:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main() {
	{
		std::cout << "My tests: " << std::endl;
		try {
		Bureaucrat	a("andre",        30);
		Form		b(a.getName(),            50, a.getGrade());
		b.beSigned(a);

		std::cout << b;
			try {
				a.setGrade(20);
				b.beSigned(a);
				std::cout << b;
			} catch (std::exception &e) {
				std::cout << e.what() << std::endl;
			}
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}

	}
  return 0;
}
