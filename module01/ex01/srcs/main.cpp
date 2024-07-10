/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:05:53 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 10:48:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	*horde = zombieHorde(10, "xuriken");

	for (int i = 0; i < 10; i++) {
		horde[i].announce();
	}
	delete [] horde;
	return (0);
}
