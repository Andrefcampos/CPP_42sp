/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:19:51 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 00:49:13 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>

class	ClapTrap {

private:
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap(void);
	ClapTrap(ClapTrap const &param);
	ClapTrap(std::string const &name);
	~ClapTrap(void);

	ClapTrap &operator=(ClapTrap const &param);

	void	setName(std::string const &name);
	void	setHitPoints(unsigned int const &ammount);
	void	setEnergyPoints(unsigned int const &ammount);
	void	setAttackDamage(unsigned int const &ammount);

	std::string		getName(void) const;
	unsigned int	getHitPoints(void) const;
	unsigned int	getEnergyPoints(void) const;
	unsigned int	getAttackDamage(void) const;

	void	attack(const std::string &target);
	void	takeDamage(unsigned int ammount);
	void	beRepaired(unsigned int ammount);
};

#endif
