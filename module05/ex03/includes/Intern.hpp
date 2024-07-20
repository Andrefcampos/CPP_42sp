/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:00:15 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/18 17:08:56 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <exception>
# include <string>

class	AForm;

class	Intern {
private:


public:
	Intern(void);
	~Intern(void);
	Intern(Intern const &param);

	Intern	&operator=(Intern const &param);

	AForm	*makeForm(std::string const &nameForm, std::string const &target);
	
	class	InvalidFormException : public std::exception {
	public:
		const char *what() const throw();
	};
};

#endif
