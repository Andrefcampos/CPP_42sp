/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 04:21:22 by andrefil          #+#    #+#             */
/*   Updated: 2024/09/09 22:21:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: ";
		std::cerr << "miss args to sort. ";
		std::cerr << "ex: \"[1]./PmergeMe [2]num1, [3]num2...\"." << std::endl;
		return (1);
	}

	std::vector<std::string> argsVector;
	std::deque<std::string> argsDeque;

	for (int i = 1; i < ac; i++) {
		std::string arg(av[i]);
		argsVector.push_back(arg);
		argsDeque.push_back(arg);
	}
	PmergeMe	sort;

	try {
		sort.setVector(argsVector);
		sort.setDeque(argsDeque);
		sort.resolveSort();
	} catch (std::exception const &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}
