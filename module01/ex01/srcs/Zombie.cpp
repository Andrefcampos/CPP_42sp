/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:05:01 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 09:55:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {};

Zombie::~Zombie(void) {
	std::cout << "Zombie " << _nameZombie << " has been destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _nameZombie << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setNameZombie(std::string &nameZombie) {
	_nameZombie = nameZombie;
}
