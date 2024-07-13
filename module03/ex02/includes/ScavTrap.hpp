/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 22:27:54 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 02:49:43 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class	ScavTrap : public ClapTrap {

public:
	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap(ScavTrap const &param);
	ScavTrap(std::string const &name);

	ScavTrap &operator=(ScavTrap const &param);

	void	attack(const std::string &target);
	void	guardGate(void);
};

#endif
