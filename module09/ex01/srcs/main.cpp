/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:10:24 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/06 03:57:11 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "input error." << std::endl;
		return (1);
	}

	RPN	calc(av[1]);
	calc.printRPN();

	return (0);
}
