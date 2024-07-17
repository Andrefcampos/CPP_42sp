/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:23:20 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 02:00:32 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
class	WrongCat : public WrongAnimal {

public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(WrongCat const &param);

	WrongCat	&operator=(WrongCat const &param);

	void	makeSound(void) const;
};

#endif
