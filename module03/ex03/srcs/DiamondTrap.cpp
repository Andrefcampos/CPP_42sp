/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:02:34 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 19:11:21 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define SUFF "_clap_name"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap() {
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::setName(std::string("unnamed") + SUFF);
	setName(std::string("unnamed") + SUFF);
	setEnergyPoints(50);
	setHitPoints(100);
	setAttackDamage(30);
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string const &name) : ClapTrap(name + SUFF), ScavTrap(name + SUFF), FragTrap(name + SUFF) {
	std::cout << "DiamondTrap name constructor called" << std::endl;
	setName(name + SUFF);
	setEnergyPoints(50);
	setHitPoints(100);
	setAttackDamage(30);
}

DiamondTrap::DiamondTrap(DiamondTrap const &param) : ClapTrap(param), ScavTrap(param), FragTrap(param) {
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = param;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &param) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &param) {
		setName(param.getName());
		setEnergyPoints(param.getEnergyPoints());
		setHitPoints(param.getHitPoints());
		setAttackDamage(param.getAttackDamage());
	}
	return (*this);
}

void	DiamondTrap::setName(std::string const &name) {_name = name;}

std::string	DiamondTrap::getName(void) const {return (_name);}

void	DiamondTrap::whoAmI(void) {
	std::cout << "I am a DiamondTrap named: " << getName() << ", ClapTrap name: " << ClapTrap::getName() << std::endl;
}
