/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:08:22 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 03:31:04 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main(void) {
  {
    std::cout << "Meus testes " << std::endl;
    ClapTrap blu("hui");
    ScavTrap moi("yer");
    FragTrap yu("unc");

    for (unsigned int i = 0; i < 40; i++) {
      blu.attack(moi.getName());
      moi.takeDamage(blu.getAttackDamage());
      moi.attack(blu.getName());
      yu.attack(moi.getName());
      moi.takeDamage(yu.getAttackDamage());
      blu.takeDamage(moi.getAttackDamage());
      blu.beRepaired(static_cast<unsigned int>(i));
      if (!blu.getHitPoints() || !moi.getHitPoints())
        break;
    }
  }
  {
    std::cout << "\nTestes especificos: \n" << std::endl;
    {
      DiamondTrap blep("Monster");

      std::cout << "Messages tests\n" << std::endl;
      std::cout << blep.getName() << std::endl;
      blep.attack("You");
      blep.attack("");
      blep.takeDamage(-1);
      blep.beRepaired(-1);

      std::cout << std::endl;
      std::cout << "Health Points tests" << std::endl;

      blep.takeDamage(1);
      blep.beRepaired(2);
      blep.takeDamage(11);
      blep.takeDamage(1);

      std::cout << std::endl;
      std::cout << "Energy tests" << std::endl;

      /* setuping for energy tests */
      blep.setEnergyPoints(0);
      blep.setHitPoints(10);

      blep.attack("You again");
      blep.beRepaired(1);
      blep.attack("A ghost");
	  std::cout << "\nTestes de metodos especiais:\n" << std::endl;
      blep.guardGate();
      blep.highFivesGuys();
      blep.whoAmI();
      std::cout << std::endl;
    }
  }
  return (0);
}
