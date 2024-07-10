/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:05:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/09 16:06:34 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	Point A(0.0, 0.0);
	Point B(4.0, 0.0);
	Point C(2.0, 3.0);
	Point P(2.0, 1.0);

	bool isInside = bsp(A, B, C, P);

	if (isInside) {
		std::cout << "O ponto P está dentro do triângulo ABC." << std::endl;
	} else {
		std::cout << "O ponto P não está dentro do triângulo ABC." << std::endl;
	}
	return 0;
}
