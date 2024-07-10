/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:46:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 09:54:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _val(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &param) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed	&Fixed::operator=(Fixed const &param) {
	std::cout << "Copy assigment constructor called" << std::endl;
	if (this != &param) {
		_val = param.getRawBits();
	}
	return (*this);
}

void	Fixed::setRawBits(int const raw) {
	_val = raw;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_val); 
}
