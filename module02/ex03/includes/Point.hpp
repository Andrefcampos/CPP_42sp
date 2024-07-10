/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:13:49 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:30:45 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
private:
	Fixed _x;
	Fixed _y;

public:
	Point(void);
	~Point(void);
	Point(float const x, float const y);
	Point(Fixed const x, Fixed const y);
	Point(Point &param);
	Point	&operator=(Point const &param);

	Fixed	getFixedPointX(void) const;
	Fixed	getFixedPointY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
