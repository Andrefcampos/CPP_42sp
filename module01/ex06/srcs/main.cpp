/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:15:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 22:33:29 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av) {
	Harl	harl;

	if (ac != 2) {
		std::cout << "Many parameters, try: [./harlFilter], [level]" << std::endl;
	}
	harl.complain(av[1]);
	if (!harl.getAlert()) {
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
