/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:06:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 01:22:25 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name){
	std::cout << "FragTrap name constructor called" << std::endl;
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap const &param) : ClapTrap(param){
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = param;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap const &param) {
	std::cout << "FragTrap copy assignment called" << std::endl;
	if (this != &param) {
		setName(getName());
		setHitPoints(getHitPoints());
		setEnergyPoints(getEnergyPoints());
		setAttackDamage(getAttackDamage());	
	}
	return (*this);
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "High five request has been accepted succefully!" << std::endl;
}
