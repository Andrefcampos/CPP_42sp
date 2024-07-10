/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:44:42 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:30:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void) : _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::~Point(void) {
	std::cout << "Destructor called" << std::endl;
}

Point::Point(float const x, float const y) {
	this->_x = Fixed(x);
	this->_y = Fixed(y);
}

Point::Point(Fixed const x, Fixed const y) {
	_x = x;
	_y = y;
}

Point::Point(Point &param) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

Point	&Point::operator=(Point const &param) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &param) {
		this->_x = param._x;
		this->_y = param._y;
	}
	return (*this);
}

Fixed	Point::getFixedPointX(void) const {
	return (_x);
}

Fixed	Point::getFixedPointY(void) const {
	return (_y);
}

//Teste do Produto Cruzado (Cross Product Test)

bool	bsp(Point const a, Point const b, Point const c, Point const point) {

	Point	ab(b.getFixedPointX() - a.getFixedPointX(), b.getFixedPointY() - a.getFixedPointY());
	Point	bc(c.getFixedPointX() - b.getFixedPointX(), c.getFixedPointY() - b.getFixedPointY());
	Point	ca(a.getFixedPointX() - c.getFixedPointX(), a.getFixedPointY() - c.getFixedPointY());

	Point	ap(point.getFixedPointX() - a.getFixedPointX(), point.getFixedPointY() - a.getFixedPointY());
	Point	bp(point.getFixedPointX() - b.getFixedPointX(), point.getFixedPointY() - b.getFixedPointY());
	Point	cp(point.getFixedPointX() - c.getFixedPointX(), point.getFixedPointY() - c.getFixedPointY());

	Fixed	crossABP(ab.getFixedPointX() * ap.getFixedPointY() - ab.getFixedPointY() * ap.getFixedPointX());
	Fixed	crossBCP(bc.getFixedPointX() * bp.getFixedPointY() - bc.getFixedPointY() * bp.getFixedPointX());
	Fixed	crossCAP(ca.getFixedPointX() * cp.getFixedPointY() - ca.getFixedPointY() * cp.getFixedPointX());

	bool	inside = ((crossABP.toFloat() >= 0 && crossBCP.toFloat() >= 0 && crossCAP.toFloat() >= 0) || (crossABP.toFloat() <= 0 && crossBCP.toFloat() <= 0 && crossCAP.toFloat() <= 0));

	return (inside);
}
