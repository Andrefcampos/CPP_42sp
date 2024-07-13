/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 21:02:18 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/12 23:40:08 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include <string>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string	_name;

public:
	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap(DiamondTrap const &param);
	DiamondTrap(std::string const &name);

	DiamondTrap	&operator=(DiamondTrap const &param);

	void		setName(std::string const &name);
	std::string	getName(void) const;

	using		ScavTrap::attack;
	void		whoAmI(void);
};

#endif
