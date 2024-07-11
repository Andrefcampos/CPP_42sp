/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:32:50 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 17:49:16 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default constuctor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &param) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Copy constructor called" << std::endl;
	*this = param;
}

ClapTrap::ClapTrap(std::string const &name) : _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	setName(name);
}

ClapTrap::ClapTrap(std::string const &name, unsigned int const &damage) : _hitPoints(10), _energyPoints(10) {
	std::cout << "String and unsigned int constuctor called" << std::endl;
	setName(name);
	setAttackDamage(damage);
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &param) {
	std::cout << "Copy assignment called" << std::endl;
	if (this != &param) {
		setName(param._name);
		setHitPoints(param._hitPoints);
		setEnergyPoints(param._energyPoints);
		setAttackDamage(param._attackDamage);
	}
	return (*this);
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called" << std::endl;
}

std::string	ClapTrap::getName(void) const {return (_name);}

unsigned int	ClapTrap::getHitPoints(void) const {return (_hitPoints);}

unsigned int	ClapTrap::getEnergyPoints(void) const {return (_energyPoints);}

unsigned int	ClapTrap::getAttackDamage(void) const {return (_attackDamage);}

void	ClapTrap::setName(std::string const &name) {_name = name;}

void	ClapTrap::setHitPoints(unsigned int const &ammount) {_hitPoints = ammount;}

void	ClapTrap::setEnergyPoints(unsigned int const &ammount) {_energyPoints = ammount;}

void	ClapTrap::setAttackDamage(unsigned int const &ammount) {_attackDamage = ammount;}

void	ClapTrap::attack(const std::string &target) {
	if (getEnergyPoints() > 0) {
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	} else {
		std::cout << "ClapTrap " << getName() << " don't attacks " << target << ", because not have energy points" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int ammount) {
	if (ammount <= getHitPoints() && getHitPoints() - ammount >= 0) {
		setHitPoints(getHitPoints() - ammount);
		std::cout << "ClapTrap " << getName() << " takes " << ammount << " hit points of damage (" << getHitPoints() << ")!" << std::endl;
	}
	else {
		setHitPoints(0);
		std::cout << "ClapTrap " << getName() << " can't take " << ammount << " damage because it is already "<< getHitPoints() << " hit points!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int ammount) {
	if (getEnergyPoints() > 0) {
		setHitPoints(getHitPoints() + ammount);
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ClapTrap " << getName() << " repairs itself, recovering " << ammount << " hit points(" << getHitPoints() << ")!" << std::endl;
	} else {
		std::cout << "ClapTrap " << getName() << " can't repair itself because it has no energy points left (" << getEnergyPoints() << ")!" << std::endl;
	}
}
