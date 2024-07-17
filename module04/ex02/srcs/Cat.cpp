/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:53:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 17:43:37 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : AAnimal() {
	std::cout << "Cat defaut constructor called" << std::endl;
	try {
		_brain = new Brain();
	}
	catch (const std::bad_alloc &strerr) {
		std:: cout << "Cat Brain memory allocation failed: " << strerr.what() << std::endl;
	}
	setType("Cat");
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(Cat const &param) : AAnimal(param) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain(*param.getBrain());
	setType("Cat");
}

Cat	&Cat::operator=(Cat const &param) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &param) {
		delete _brain;
		_brain = new Brain(*param.getBrain());
		setType(param.getType());
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuuuu...." << std::endl;
}

Brain	*Cat::getBrain(void) const {
	return (_brain);
}
