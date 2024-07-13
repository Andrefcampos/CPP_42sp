/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:08:22 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 02:45:03 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

int main(void) {
  {
    std::cout << "Meus testes " << std::endl;
    ClapTrap blu("hui");
    ScavTrap moi("yer");

    for (unsigned int i = 0; i < 40; i++) {
      blu.attack(moi.getName());
      moi.takeDamage(blu.getAttackDamage());
      moi.attack(blu.getName());
      blu.takeDamage(moi.getAttackDamage());
      blu.beRepaired(static_cast<unsigned int>(i));
      if (!blu.getHitPoints() || !moi.getHitPoints())
        break;
    }
  }
  return (0);
}
