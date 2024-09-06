/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:10:24 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/06 04:29:07 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << "input error." << std::endl;
		return (1);
	}

	RPN	rpn(av[1]);
	rpn.printRPN();

	return (0);
}
