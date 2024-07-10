/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:04:18 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/08 04:38:14 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class	Zombie {
	private:
		std::string	_nameZombie;

	public:
		Zombie(void);
		~Zombie(void);

		void	announce(void);
		void	setNameZombie(std::string &nameZombie);
};

Zombie	*zombieHorde(int N, std::string name);

#endif
