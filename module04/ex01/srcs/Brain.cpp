/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 04:06:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:25:05 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain::Brain(Brain const &param) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = param;
}

Brain	&Brain::operator=(Brain const &param) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &param) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = param._ideas[i];
		}
	}
	return (*this);
}
