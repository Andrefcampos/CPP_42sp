/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:30:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:21:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed {
private:
  int	_fixedValue;
  static const int	_raw = 8;

public:
  Fixed(void);
  ~Fixed(void);
  Fixed(int const &value);
  Fixed(float const &value);
  Fixed(Fixed const &param);
  Fixed	&operator=(Fixed const &param);

  float	toFloat(void) const;
  int	toInt(void) const;

  void	setRawBits(int const raw);
  int	getRawBits(void) const;

  bool	operator>(Fixed const &param) const;
  bool	operator<(Fixed const &param) const;
  bool	operator>=(Fixed const &param) const;
  bool	operator<=(Fixed const &param) const;
  bool	operator==(Fixed const &param) const;
  bool	operator!=(Fixed const &param) const;

  Fixed	operator+(Fixed const &param);
  Fixed	operator-(Fixed const &param);
  Fixed	operator*(Fixed const &param);
  Fixed	operator/(Fixed const &param);
  Fixed	operator++(void);
  Fixed	operator--(void);
  Fixed	operator++(int);
  Fixed	operator--(int);

  static Fixed	&min(Fixed &a, Fixed &b);
  static const Fixed	&min(Fixed const &a, Fixed const &b);
  static Fixed	&max(Fixed &a, Fixed &b);
  static const Fixed	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &oS, const Fixed &param);

#endif // !FIXED_HPP
