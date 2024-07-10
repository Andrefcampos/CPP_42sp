/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:45:41 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:10:31 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int	main(int ac, char **av) {

	if (ac != 4) {
		std::cout << "Most parameters, put only 3 [filename], [old_STR], [new_STR];" << std::endl;
		return (1);
	}
	std::string	s1 = av[2];
	std::string	s2 = av[3];
	std::stringstream	file_name;
	file_name << av[1] << ".replace";
	std::ifstream	infile(av[1]);
	if (!infile) {
		std::cout << "error: Open " << av[1] << " is not possible." << std::endl;
	}
	std::ofstream	outfile(file_name.str().c_str());
	if (!outfile) {
		std::cout << "error: Open " << file_name.str() << " is not possible." << std::endl;
	}
	std::string	line;
	while (std::getline(infile, line)) {

		size_t	pos = 0;
		size_t	occ = 0;
		while ((pos = line.find(s1, occ)) != std::string::npos) {
			outfile << line.substr(occ, pos - occ) << s2;
			occ = pos + s1.length();
		}
		outfile << line.substr(occ) << std::endl;
	}
	infile.close();
	outfile.close();
	return (0);
}
