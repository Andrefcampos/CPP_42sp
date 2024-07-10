/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 14:13:42 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:09:59 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class	Weapon {

	private:
		std::string	_type;

	public:
		Weapon(std::string type);

		void	setType(std::string type);
		std::string	getType(void) const;
};

#endif
