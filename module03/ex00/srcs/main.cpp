/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:08:22 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 02:42:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void) {
  {
		std::cout << "Meus testes:\n " << std::endl;
    ClapTrap blu("hui");

    for (unsigned int i = 0; i < 40; i++) {
      blu.attack("monster");
      blu.takeDamage(i + 2);
      blu.beRepaired(static_cast<unsigned int>(i));
      if (!blu.getHitPoints())
        break;
    }
  }
  return (0);
}
