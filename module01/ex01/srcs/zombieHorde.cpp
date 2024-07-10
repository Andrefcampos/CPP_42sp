/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:04:40 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/06 10:49:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name) {
	Zombie *zombiehordez = new Zombie[N];
	for (int i = 0; i < N; i++) {
	  zombiehordez[i].setNameZombie(name);
	}
	return (zombiehordez);
}
