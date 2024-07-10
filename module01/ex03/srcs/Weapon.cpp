/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:17:32 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 15:23:52 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string typeWeapon) {
	setType(typeWeapon);
}

void	Weapon::setType(std::string type) {
	_type = type;
}

std::string	Weapon::getType(void) const{
	return (_type);
}
