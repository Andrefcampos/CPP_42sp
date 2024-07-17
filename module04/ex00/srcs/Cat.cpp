/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:53:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:17:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void) : Animal() {
	std::cout << "Cat defaut constructor called" << std::endl;
	setType("Cat");
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(Cat const &param) : Animal(param) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = param;
}

Cat	&Cat::operator=(Cat const &param) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &param) {
		setType(param.getType());
	}
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Miauuuuuu...." << std::endl;
}
