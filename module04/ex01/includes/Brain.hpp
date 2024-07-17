/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 04:08:37 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 18:00:02 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain {

private:
	std::string	_ideas[100];

public:
	Brain(void);
	~Brain(void);
	Brain(Brain const &param);

	Brain	&operator=(Brain const &param);
};

#endif
