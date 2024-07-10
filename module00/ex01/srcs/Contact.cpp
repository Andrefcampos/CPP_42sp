/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 17:34:44 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/03 04:05:54 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.hpp"

Contact::Contact(void){}

Contact::~Contact(void){}

void	Contact::setFirstName(const std::string name)
{
	this->_firstName = name;
}

std::string	Contact::getFirstName(void)
{
	return (this->_firstName);
}

void	Contact::setLastName(const std::string lastName)
{
	this->_lastName = lastName;
}

std::string	Contact::getLastName(void)
{
	return (this->_lastName);
}

void	Contact::setNickName(const std::string nickName)
{
	this->_nickName = nickName;
}

std::string	Contact::getNickName(void)
{
	return (this->_nickName);
}

void	Contact::setPhoneNumber(const std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getPhoneNumber(void)
{
	return (this->_phoneNumber);
}

void	Contact::setDarkstSecret(const std::string darkstSecret)
{
	this->_darkstSecret = darkstSecret;
}

std::string	Contact::getDarkstSecret(void)
{
	return (this->_darkstSecret);
}

void	Contact::display(void) {
	std::cout << ">------------------------------------------------------------<" << std::endl;
	std::cout << ">------------------------- SEARCH: --------------------------<" << std::endl;
	std::cout << ">-------------------- First name:   " << getFirstName() << std::endl;
	std::cout << ">-------------------- Last name:    " << getLastName() << std::endl;
	std::cout << ">-------------------- Nick name:    " << getNickName() << std::endl;
	std::cout << ">-------------------- Phone number: " << getPhoneNumber() << std::endl;
	std::cout << ">------------------------------------------------------------<" << std::endl;
}
