/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:53:35 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 23:16:54 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*strPTR = &str;
	std::string	&strREF = str;

	std::cout << "The memory address: " << &str << std::endl;
	std::cout << "The memory address: " << strPTR << std::endl;
	std::cout << "The memory address: " << &strREF << std::endl;

	std::cout << "The value pointed: " << str << std::endl;
	std::cout << "The value pointed: " << *strPTR << std::endl;
	std::cout << "The value pointed: " << strREF << std::endl;

	return (0);
}
