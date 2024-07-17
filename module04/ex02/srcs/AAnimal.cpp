/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:28:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:31:24 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>
#include <ostream>

AAnimal::AAnimal(void) : _type("AAnimal") {
	std::cout << "AAnimal default constuctor called" << std::endl;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &param) {
	std::cout << "AAnimal copy constuctor called" << std::endl;
	*this = param;
}

AAnimal	&AAnimal::operator=(AAnimal const &param) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &param) {
		_type = param.getType();
	}
	return (*this);
}

std::string	AAnimal::getType(void) const {
	return (_type);
}

void	AAnimal::setType(std::string const &type) {
	_type = type;
}

void	AAnimal::makeSound(void) const {
	std::cout << "Some generic Animal sound" << std::endl;
}
