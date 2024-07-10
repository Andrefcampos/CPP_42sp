/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 11:56:44 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/03 04:09:15 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>

std::string	prompt(void)
{
	std::cout << ">------------------------------------------------------------<" << std::endl;
	std::cout << ">----------------------- PHONEBOOK --------------------------<" << std::endl;
	std::cout << ">--- Type ADD to add contact to phone book ------------------<" << std::endl;
	std::cout << ">--- Type SEARCH to search for a contact in the phonebook ---<" << std::endl;
	std::cout << ">--- Type EXIT to end the schedule --------------------------<" << std::endl;
	std::cout << ">------------------------------------------------------------<" << std::endl;

	std::string	input;

	while (1) {
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << ">-----------------------> Choose one option: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
		else if (input.empty())
			std::cout << ">--------------------> !!!!! Empty input, try again..." << std::endl;
		else if (input != "ADD" && input != "SEARCH" && input != "EXIT")
			std::cout << ">--------------------> !!!!! Wrong format, try again..." << std::endl;
		else
			break ;
	}
	return (input);
}

int	main(void)
{
	std::string			input;
	static PhoneBook	phonebook;

	while(1)
	{
		input = prompt();
		if (input.empty())
			std::cout << ">-----------------------> Input empty, try again..." << std::endl;
		else if (input == "ADD")
			phonebook.setContact();
		else if (input == "SEARCH")
			phonebook.searchContact();
		else if (input == "EXIT")
			break ;
		input.clear();
	}
	return (0);
}
