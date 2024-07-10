/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 04:04:27 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 08:35:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::_frbits = 8;

Fixed::Fixed(void) : _val(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(float const value) : _val(roundf(value * (1 << Fixed::_frbits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _val(value * (1 << Fixed::_frbits)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &param) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed &Fixed::operator=(Fixed const &param) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &param) {
		_val = param.getRawBits();
	}
	return (*this);
}

void	Fixed::setRawBits(int const raw) {_val = raw;}

int	Fixed::getRawBits(void) const {return (_val);}

int	Fixed::toInt(void) const {
	return (_val >> _frbits);
}

float	Fixed::toFloat(void) const {
	return ((float)(this->getRawBits()) / (float)(1 << _frbits));
}

std::ostream &operator<<(std::ostream &oS, Fixed const &param) {
	oS << param.toFloat();
	return (oS);
}
