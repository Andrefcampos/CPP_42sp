/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:06:18 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 17:54:57 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "AAnimal.hpp"
#include <iostream>
#include <ostream>

Dog::Dog(void) : AAnimal() {
	std::cout << "Dog default constructor called" << std::endl;
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc &strerr) {
		std:: cout << "Dog Brain memory allocation failed: " << strerr.what() << std::endl;
	}
	setType("Dog");
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(Dog const &param) : AAnimal(param) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain(*param.getBrain());
	setType(param.getType());
}

Dog	&Dog::operator=(Dog const &param) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &param) {
		delete _brain;
		_brain = new Brain(*param._brain);
		setType(param.getType());
	}
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Auuuuuu..." << std::endl;
}

Brain	*Dog::getBrain(void) const {
	return (_brain);
}
