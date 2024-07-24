/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 05:57:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/24 01:19:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstddef>
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

};

#endif
