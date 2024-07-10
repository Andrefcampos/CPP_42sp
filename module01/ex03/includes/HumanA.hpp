/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:14:14 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:02:39 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA {

	private:
		std::string	_name;
		Weapon	&_weapon;

	public:
		HumanA(std::string name, Weapon &weapon);
		void	attack(void);
};

#endif
