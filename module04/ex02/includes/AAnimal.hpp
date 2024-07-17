/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:22:44 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 16:08:07 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include <string>

class AAnimal {

protected:
  std::string _type;

public:
	AAnimal(void);
	virtual ~AAnimal(void);
	AAnimal(AAnimal const &param);
	
	AAnimal	&operator=(AAnimal const &param);

	std::string	getType(void) const;
	void	setType(std::string const &type);
	virtual void	makeSound(void) const = 0;
};

#endif
