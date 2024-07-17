/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:02:23 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 02:00:42 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal {
	
public:
	Dog(void);
	~Dog(void);
	Dog(Dog const &param);

	Dog	&operator=(Dog const &param);

	void	makeSound(void) const;
};

#endif
