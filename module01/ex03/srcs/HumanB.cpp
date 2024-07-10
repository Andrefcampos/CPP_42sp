/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:27:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 15:42:10 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name) {}

void	HumanB::attack(void) {
	if (_weapon)
		std::cout << _name << " attack with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
}
