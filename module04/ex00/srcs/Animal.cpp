/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:28:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:54:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>
#include <ostream>

Animal::Animal(void) : _type("Animal") {
	std::cout << "Animal default constuctor called" << std::endl;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(Animal const &param) {
	std::cout << "Animal copy constuctor called" << std::endl;
	*this = param;
}

Animal	&Animal::operator=(Animal const &param) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &param) {
		_type = param.getType();
	}
	return (*this);
}

std::string	Animal::getType(void) const {
	return (_type);
}

void	Animal::setType(std::string const &type) {
	_type = type;
}

void	Animal::makeSound(void) const {
	std::cout << "Some generic Animal sound" << std::endl;
}
