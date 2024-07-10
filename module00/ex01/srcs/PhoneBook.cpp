/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 01:28:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/04 13:28:49 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <cctype>

#define MAX_CTTS 8

PhoneBook::PhoneBook(void) : _index(0), _max(0) {}

PhoneBook::~PhoneBook(void) {}

std::string	getFormatter(const std::string &att) {
	if (att.length() > 10)
		return (att.substr(0,9) + ".");
	return (att);
}

bool	checkIsNumber(const std::string &input) {
	for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

void	setField(const char *message, std::string &input) {
	while (1) {
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << message;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
		else if (input.empty())
			std::cout << ">--------------------> !!!!! Empty input, try again..." << std::endl;
		else if (checkIsNumber(input) || input.length() < 2)
			std::cout << ">--------------------> !!!!! Wrong formatting, try again..." << std::endl;
		else
			break ;
	}
}

void	setFieldNumber(std::string &input) {
	while (1) {
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << ">-----------------------> Phone number: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
		else if (input.empty())
			std::cout << ">--------------------> !!!!! Empty input, try again..." << std::endl;
		else if (!checkIsNumber(input) || (input.size() < 7 || input.size() > 14))
			std::cout << ">--------------------> !!!!! Wrong formatting, try again..." << std::endl;
		else
			break ;
	}
}

void	PhoneBook::setContact(void)
{
	Contact	contact;
	std::string	input;

	std::cout << ">------------------------------------------------------------<" << std::endl;
	std::cout << ">--------------------------- ADD: ---------------------------<" << std::endl;
	setField(">-----------------------> First name: ", input);
	contact.setFirstName(input);
	input.clear();

	setField(">-----------------------> Last name: ", input);
	contact.setLastName(input);
	input.clear();

	setField(">-----------------------> Nick name: ", input);
	contact.setNickName(input);
	input.clear();

	setFieldNumber(input);
	contact.setPhoneNumber(input);
	input.clear();

	std::cout << ">------------------------------------------------------------<" << std::endl;
	std::cout << "> Don't worry, this will be the only time you see this message" << std::endl;
	std::cout << ">------------------------------------------------------------<" << std::endl;
	setField(">-----------------------> Darkst secret message: ", input);
	contact.setDarkstSecret(input);
	std::cout << ">------------------------------------------------------------<" << std::endl;
	input.clear();

	_contacts[_index++] = contact;

	if (_max < MAX_CTTS)
		_max++;
	if (_index >= MAX_CTTS)
		_index = 0;
}

void	PhoneBook::searchContact(void)
{
	if (_max == 0) {
		std::cout << ">-----------------------> !!!!! Phone Book is empty.\n" << std::endl;
		return ;
	}
	std::cout << ">------------------------------------------------------------<" << std::endl;
	std::cout << ">----------------------- PHONE BOOK: ------------------------<" << std::endl;
	std::cout << ">------ |     Index|First Name| Last Name|  Nickname| -------<" << std::endl;
	for (size_t i = 0; i < _max; i++) {
		std::cout << ">------ |" << std::right << std::setw(10) << i << "|";
		std::cout << std::right << std::setw(10) << getFormatter(_contacts[i].getFirstName()) << "|" ;
		std::cout << std::right << std::setw(10) << getFormatter(_contacts[i].getLastName()) << "|";
		std::cout << std::right << std::setw(10) << getFormatter(_contacts[i].getNickName()) << "| -------<";
		std::cout << std::endl;
	}
	std::cout << ">------------------------------------------------------------<" << std::endl;
	while (1) {
		std::clearerr(stdin);
		std::cin.clear();
		std::cout << ">-----------------------> Type index want you find: ";
		std::string	input;
		std::getline(std::cin, input);
		if (std::cin.eof())
			std::cout << std::endl;
		if (input.empty())
			std::cout << ">--------------------> !!!!! Empty input, try again..." << std::endl;
		else if (!checkIsNumber(input) || std::atoi(input.c_str()) >= static_cast<int>(_max) || std::atoi(input.c_str()) < 0)
			std::cout << ">--------------------> !!!!! Invalid index, try again..." << std::endl;
		else {
			_contacts[std::atoi(input.c_str())].display();
			input.clear();
			break ;
		}
	}
}
