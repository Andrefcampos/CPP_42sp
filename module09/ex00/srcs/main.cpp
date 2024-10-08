/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 00:14:49 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/06 04:18:18 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <iostream>

int	main(int ac, char **av) {

	if (ac != 2) {
		std::cerr << RED "Error: wrong numbers of arguments." \
			<< "\"[1]./btc [2] ./validInputFile.csv/txt...\"." DFT << std::endl;
		return (1);
	}

	try {
		BitcoinExchange	data("./data.csv");
		data.printFile(      av[1]);
	} catch (const std::exception &e) {
		std::cerr << RED "Error: " << e.what() << DFT << std::endl;
	}

	return (0);
}
