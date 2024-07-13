/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:33:11 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 00:46:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap(name) {
	std::cout << "ScavTrap name constuctor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	setName(name);
}

ScavTrap::ScavTrap(ScavTrap const &param) : ClapTrap(param) {
	std::cout << "ScavTrap copy constuctor called" << std::endl;
	*this = param;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &param) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &param) {
		setName(param.getName());
		setHitPoints(param.getHitPoints());
		setEnergyPoints(param.getEnergyPoints());
		setAttackDamage(param.getAttackDamage());
	}
	return (*this);
}

void	ScavTrap::attack(const std::string &target) {
	if (target.empty()) {
		std::cout << "ScavTrap " << getName() << " cannot attack unnamed opponent" << std::endl;
	} else if (getEnergyPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	} else {
		std::cout << "ScavTrap " << getName() << " don't attacks " << target << ", because not have energy points" << std::endl;
	}
}

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
