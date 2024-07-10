/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:39:08 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/08 05:34:06 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class	Fixed {
	private:
		int					_val;
		static const int	_frbits;

	public:
		Fixed(void);
		Fixed(Fixed const &param);
		Fixed(int const value);
		Fixed(float const value);
		Fixed &operator=(const Fixed &param);
		~Fixed(void);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream &operator<<(std::ostream &oS, Fixed const &param);

#endif
