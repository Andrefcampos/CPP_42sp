/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 20:22:44 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:32:30 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>

class Animal {

protected:
  std::string _type;

public:
	Animal(void);
	virtual ~Animal(void);
	Animal(Animal const &param);
	
	Animal	&operator=(Animal const &param);

	std::string	getType(void) const;
	void	setType(std::string const &type);
	virtual void	makeSound(void) const;
};

#endif
