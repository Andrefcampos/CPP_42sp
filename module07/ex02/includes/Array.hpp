/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:57:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/24 01:33:58 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
#include <ostream>

template <typename T>
class	Array {

private:
	T *_data;
	std::size_t _size;

public:
	Array(void);
	~Array(void);
	Array(unsigned int const &num);
	Array(Array const &param);

	Array	&operator=(Array const &param);

  unsigned int size(void) const;

	const T	&operator[](unsigned int const &index) const;
	T	&operator[](unsigned int const &index);
};

template <typename T>
std::ostream	&operator<<(std::ostream &oS, Array<T> const &param);

#endif
