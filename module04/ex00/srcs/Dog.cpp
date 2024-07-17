/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:06:18 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:17:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>
#include <ostream>

Dog::Dog(void) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	setType("Dog");
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(Dog const &param) : Animal(param) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = param;
}

Dog	&Dog::operator=(Dog const &param) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &param) {
		setType(param.getType());
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Auuuuuu..." << std::endl;
}
