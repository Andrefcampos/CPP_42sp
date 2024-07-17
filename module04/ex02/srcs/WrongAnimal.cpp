/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:18:51 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:55:04 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &param) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = param;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &param) {
	std::cout << "WrongAnimal copy assignment called" << std::endl;
	if (this != &param) {
		setType(param.getType());
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const {
	return (_type);
}

void	WrongAnimal::setType(std::string const &type) {
	_type = type;
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "Wrong animal sound" << std::endl;
}
