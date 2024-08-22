/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:50:19 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/22 10:50:20 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T *arr, std::size_t len, F func) {

	if (!arr || !func) {
		return ;
	}
	for (std::size_t i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
