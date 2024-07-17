/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:01:09 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 02:10:40 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	setType("WrongCat");
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &param) : WrongAnimal(param) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = param;
}

WrongCat	&WrongCat::operator=(WrongCat const &param) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &param) {
		setType(param.getType());
	}
	return (*this);
}

void	WrongCat::makeSound(void) const {
	std::cout << "Wrong cat sound" << std::endl;
}
