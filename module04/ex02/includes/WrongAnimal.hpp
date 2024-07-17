/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 01:18:57 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/14 01:58:53 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>

class	WrongAnimal {

protected:
	std::string	_type;

public:
	WrongAnimal(void);
	virtual ~WrongAnimal(void);
	WrongAnimal(WrongAnimal const &param);
	
	WrongAnimal	&operator=(WrongAnimal const &param);
	
	std::string	getType(void) const;
	void	setType(std::string const &type);
	virtual void	makeSound(void) const;
};

#endif
