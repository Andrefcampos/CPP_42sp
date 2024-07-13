/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 15:32:30 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/13 02:49:33 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap {

	public:
		FragTrap(void);
		~FragTrap(void);
		FragTrap(FragTrap const &param);
		FragTrap(std::string const &name);

		FragTrap	&operator=(FragTrap const &param);

		void	highFivesGuys(void);
};

#endif
