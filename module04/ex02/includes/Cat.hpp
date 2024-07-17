/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 00:51:13 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 05:27:50 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Cat : public AAnimal {

private:
	Brain	*_brain;

public:
	Cat(void);
	~Cat(void);
	Cat(Cat const &param);

	Cat	&operator=(Cat const &param);

	void	makeSound(void) const;
	Brain	*getBrain(void) const;
};

#endif
