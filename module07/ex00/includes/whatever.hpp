/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:49:33 by andrefil          #+#    #+#             */
/*   Updated: 2024/08/22 10:49:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHEATEVER_HPP
# define WHEATEVER_HPP

template<typename T> 
void	swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
T	min(T &a, T &b) {
	return ((a < b) ? a : b);
}

template<typename T>
T	max(T &a, T &b) {
	return ((a > b) ? a : b);
}

#endif
