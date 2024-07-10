/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 23:38:11 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 09:54:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	private:
		int	_val;
		static const int	_fbits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &orig);
		Fixed &operator=(Fixed const &param);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const val);
};

#endif
