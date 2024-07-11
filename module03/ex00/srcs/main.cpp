/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:08:22 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 18:19:01 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	andre("andre", 8);

	for (unsigned int i = 0; i < 40; i++)
	{
		andre.attack("joao");
		andre.takeDamage((++i));
		andre.beRepaired(static_cast<unsigned int>(i));
		if (!andre.getHitPoints())
			break;
	}
	return (0);
}
