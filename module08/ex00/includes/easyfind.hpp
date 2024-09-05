/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 23:46:23 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/24 23:46:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <algorithm>
# include <stdexcept>

template <typename T>
int	easyfind(T &container, int value) {
	typename T::iterator	it;

	it = std::find(container.begin(), container.end(), value);

	if (it == container.end()) {
		throw std::runtime_error("Value not found in container.");
	}

	return (*it);
}

#endif
