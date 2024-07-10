/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:45:28 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/08 04:35:41 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class	Zombie {
	private:

	std::string	_nameZombie;

	public:
		Zombie(std::string nameZombie);

		void	announce(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif // !ZOMBIE_HPP
