/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:33:29 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 08:21:24 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _fixedValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const &value) : _fixedValue(value * (1 << _raw)) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const &value) : _fixedValue(roundf(value * (1 << _raw))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &param) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Fixed &Fixed::operator=(Fixed const &param) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &param) {
		_fixedValue = param.getRawBits();
	}
	return (*this);
}

void	Fixed::setRawBits(int const raw) {_fixedValue = raw;}

int	Fixed::getRawBits(void) const {return(_fixedValue);}

float	Fixed::toFloat(void) const {return ((float)_fixedValue / (float)(1 << _raw));}

int	Fixed::toInt(void) const {return(_fixedValue >> _raw);}

bool	Fixed::operator>(Fixed const &param) const {
	if (this->getRawBits() > param.getRawBits()) {
		return (true);
	}
	return (false);
}

bool	Fixed::operator<(Fixed const &param) const {
	if (this->getRawBits() < param.getRawBits()) {
		return (true);
	}
	return (false);
}

bool	Fixed::operator>=(Fixed const &param) const {
	if (this->getRawBits() >= param.getRawBits()) {
		return (false);
	}
	return (false);
}

bool	Fixed::operator<=(Fixed const &param) const {
	if (this->getRawBits() <= param.getRawBits()) {
		return (true);
	}
	return (false);
}

bool	Fixed::operator==(Fixed const &param) const {
	if (this->getRawBits() == param.getRawBits()) {
		return (true);
	}
	return (false);
}

bool	Fixed::operator!=(Fixed const &param) const {
	if (this->getRawBits() != param.getRawBits()) {
		return (true);
	}
	return (false);
}

Fixed	Fixed::operator+(Fixed const &param) {
	float	sum = this->toFloat() + param.toFloat();
	return (Fixed(sum));
}

Fixed	Fixed::operator-(Fixed const &param) {
	float	sub = this->toFloat() - param.toFloat();
	return (Fixed(sub));
}
Fixed	Fixed::operator*(Fixed const &param) {
	float	prod = this->toFloat() * param.toFloat();
	return (Fixed(prod));
}
Fixed	Fixed::operator/(Fixed const &param) {
	float	div = 0;

	if (this->getRawBits() == 0 || param.getRawBits() == 0) {
		return (Fixed(div));
	}
	div = this->toFloat() / param.toFloat();
	return (Fixed(div));
}

Fixed	Fixed::operator++(void) {
	_fixedValue += 1;
	return (*this);
}

Fixed	Fixed::operator--(void) {
	_fixedValue -= 1;
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed	temp(_fixedValue * toFloat());
	_fixedValue += 1;
	return (temp);
}
Fixed	Fixed::operator--(int) {
	Fixed	temp(_fixedValue * toFloat());
	_fixedValue -= 1;
	return (temp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}
Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

std::ostream &operator<<(std::ostream &oS, Fixed const &param) {
	oS << param.toFloat();
	return (oS);
}
