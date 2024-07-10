/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:11:25 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/04 12:56:51 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string nameZombie) : _nameZombie(nameZombie) {}

void	Zombie::announce(void) const {
	std::cout << _nameZombie << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
