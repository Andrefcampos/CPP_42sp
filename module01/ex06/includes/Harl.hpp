/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:00:30 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/10 13:15:19 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>

class Harl {
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

		int	_has_alert;

	public:
		Harl(void);
		~Harl(void);

		void	complain(std::string level);
		int	getAlert(void);
};

#endif
