/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 20:13:43 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:14:17 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int ac, char **av) {
	Harl	harl;
	
	if (ac != 2) {
		std::cout << "Many parameters, try: [./harlFilter], [level]" << std::endl;
		return (1);
	}
	harl.complain(av[1]);
	return (0);
}
