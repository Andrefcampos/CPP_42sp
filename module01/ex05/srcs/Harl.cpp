/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 19:19:36 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:13:33 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl(void) {};

Harl::~Harl(void) {};

void	Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*call[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; i++) {
		if (level == levels[i]) {
			(this->*call[i])();
		}
	}
};
