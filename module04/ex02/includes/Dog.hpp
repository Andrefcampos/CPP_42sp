/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:02:23 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:28:47 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog : public AAnimal {

private:
	Brain	*_brain;

	
public:
	Dog(void);
	~Dog(void);
	Dog(Dog const &param);

	Dog	&operator=(Dog const &param);

	void	makeSound(void) const;
	Brain	*getBrain(void) const;
};

#endif
