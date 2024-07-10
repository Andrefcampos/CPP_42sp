/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:13:59 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:05:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "HumanA.hpp"
# include <string>

class	HumanB {
	private:
		std::string	_name;
		Weapon	*_weapon;

	public:
		HumanB(std::string name);

		void	attack(void);
		void	setWeapon(Weapon &weapon);

};

#endif
